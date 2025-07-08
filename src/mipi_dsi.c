// SPDX-FileCopyrightText: 2024 Ledger SAS
// SPDX-License-Identifier: Apache-2.0

/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <sys/cdefs.h>
#include <stdio.h>

#include <uapi.h>
#include <mipi/mipi_dsi.h>

#include "mipi_dphy.h"
#include "mipi_dsi_bias.h"
#include "mipi_dsi_defs.h"
#include "mipi_dsi_priv.h"
#include "mipi_dsi_wrapper.h"

static inline int __mipi_dsi_map(const mipi_dsi_device_t *mipi_dsi)
{
    int ret = -1;
    devh_t handle;
    enum Status status;

    /* Fixme: wrap these in libshield */
    status = sys_get_device_handle(mipi_dsi->dev.id);
    if (status != STATUS_OK) {
        goto err;
    }
    copy_to_user((uint8_t*)&handle, sizeof(devh_t));
    if (sys_map_dev(handle) == STATUS_OK) {
        ret = 0;
    }

err:
    return ret;
}

static inline int __mipi_dsi_unmap(const mipi_dsi_device_t *mipi_dsi)
{
    int ret = -1;
    devh_t handle;
    enum Status status;

    /* Fixme: wrap these in libshield */
    status = sys_get_device_handle(mipi_dsi->dev.id);
    if (status != STATUS_OK) {
        goto err;
    }
    copy_to_user((uint8_t*)&handle, sizeof(devh_t));
    if (sys_unmap_dev(handle) == STATUS_OK) {
        ret = 0;
    }

err:
    return ret;
}

static inline uint32_t mipi_dsi_host_version(const devinfo_t *dev)
{
    return mipi_dsi_register_read(dev, DSI_VR_REG);
}

static inline void mipi_dsi_host_enable(const devinfo_t *dev)
{
    mipi_dsi_register_write(dev, DSI_CR_REG, DSI_CR_EN);
    mipi_dsi_register_read(dev, DSI_CR_REG);
}

static inline void mipi_dsi_host_disable(const devinfo_t *dev)
{
    mipi_dsi_register_write(dev, DSI_CR_REG, 0);
    mipi_dsi_register_read(dev, DSI_CR_REG);
}

/*
 * XXX:
 * Yet another hardcoded values set
 */
static inline void mipi_dsi_host_dphy_timing(const devinfo_t *dev)
{
/*
 * XXX:
 *  see Ref manual table 441
 *  LP2HS and HS2LP is defined according to DPhy frequency band and LXP offset
 *
 * Warning: see comment below from ST HAL
 */
#define CHS2LPTIME  11
#define CLP2HSTIME  40
#define DHS2LPTIME 12
#define DLP2HSTIME 23
#define STOPWAIT 7
#define DSI_2LINES 1
/*
 * In Automatic Clock Lane control mode, the DSI Host can turn off the clock lane between two
 * High-Speed transmission.
 * To do so, the DSI Host calculates the time required for the clock lane to change from HighSpeed
 * to Low-Power and from Low-Power to High-Speed.
 * This timings are configured by the HS2LP_TIME and LP2HS_TIME in the DSI Host Clock Lane Timer Configuration
 * Register (DSI_CLTCR).
 * But the DSI Host is not calculating LP2HS_TIME + HS2LP_TIME but 2 x HS2LP_TIME.
 *
 * Workaround : Configure HS2LP_TIME and LP2HS_TIME with the same value being the max of HS2LP_TIME or LP2HS_TIME.
 */

    uint32_t cltcr = ((CLP2HSTIME << DSI_CLTCR_LP2HS_TIME_SHIFT) & DSI_CLTCR_LP2HS_TIME_MASK)
                   | ((CLP2HSTIME << DSI_CLTCR_HS2LP_TIME_SHIFT) & DSI_CLTCR_HS2LP_TIME_MASK);

    uint32_t dltcr = ((DHS2LPTIME << DSI_DLTCR_HS2LP_TIME_SHIFT) & DSI_DLTCR_HS2LP_TIME_MASK)
                   | ((DLP2HSTIME << DSI_DLTCR_LP2HS_TIME_SHIFT) & DSI_DLTCR_LP2HS_TIME_MASK);

    uint32_t pconfr = ((STOPWAIT << DSI_PCONFR_SW_TIME_SHIFT) & DSI_PCONFR_SW_TIME_MASK)
                    | ((DSI_2LINES << DSI_PCONFR_NL_SHIFT) & DSI_PCONFR_NL_MASK);


    /* enable clock lane and digital module */
    /* XXX might be set at step 12/13 instead */
    mipi_dsi_register_write(dev, DSI_PCTLR_REG, DSI_PCTLR_DEN | DSI_PCTLR_CKE);
    /* clock lane in HighSpeed mode, automatic clock lane control disabled */
    mipi_dsi_register_write(dev, DSI_CLCR_REG, /*DSI_CLCR_ACR |*/ DSI_CLCR_DPCC);

    /* MIPI 2 lanes, stopwait time == 7 */
    mipi_dsi_register_write(dev, DSI_PCONFR_REG, pconfr);
    /* lp2hs and hs2lp clock and data timing see above */
    mipi_dsi_register_write(dev, DSI_CLTCR_REG, cltcr);
    mipi_dsi_register_write(dev, DSI_DLTCR_REG, dltcr);
}

static inline void mipi_dsi_host_timing(const devinfo_t *dev)
{
    #define TXESC 4 /* escape prescaler for LPM command mode, 3 seems to be a best bet !? */
    mipi_dsi_register_write(dev, DSI_CCR_REG, (TXESC << DSI_CCR_TXECKDIV_SHIFT) & DSI_CCR_TXECKDIV_MASK);
    /* TOCKDIV ? */
}

static inline void mipi_dsi_host_flow_control(const devinfo_t *dev)
{
    /* XXX */
    mipi_dsi_register_write(dev, DSI_PCR_REG, DSI_PCR_BTAE);
}

static inline void mipi_dsi_host_configure_command_mode(const devinfo_t *dev)
{
    /* XXX hardcoded, all cmd type in LP w/o ack */
    uint32_t cmcr = DSI_CMCR_GSW0TX
                  | DSI_CMCR_GSW1TX
                  | DSI_CMCR_GSW2TX
                  | DSI_CMCR_GSR0TX
                  | DSI_CMCR_GSR1TX
                  | DSI_CMCR_GSR2TX
                  | DSI_CMCR_DSW0TX
                  | DSI_CMCR_DSW1TX
                  | DSI_CMCR_DSR0TX
                  | DSI_CMCR_GLWTX
                  | DSI_CMCR_DLWTX;
    /* MRDP: 0, Ack request: 0, tear effect ack request: 0 */

    mipi_dsi_register_write(dev, DSI_CMCR_REG, cmcr);
}

/*
 * Fixme:
 *  Add binding mechanism between LCD engine, MIPI bridge and Panel
 *  Move this to bound panel setup.
 *  this is yet another hardcoded setting for demo purpose.
 *
 * Note: This is backported from FW4HW PoC and thus does not fit our coding rules.
 */
static inline void mipi_dsi_host_configure_panel(const devinfo_t *dev)
{
    SleepDuration duration = { .tag = SLEEP_DURATION_ARBITRARY_MS };

    const uint8_t InitParam0[]    = { 0xff, 0x77, 0x01, 0x00, 0x00, 0x13 };
    const uint8_t InitParam1[]    = { 0xff, 0x77, 0x01, 0x00, 0x00, 0x10 };
    const uint8_t InitParam2[]    = { 0xc0, 0x63, 0x00 };
    const uint8_t InitParam3[]    = { 0xc1, 0x14, 0x0C };
    const uint8_t InitParam4[]    = { 0xc2, 0x37, 0x02 };
    const uint8_t InitParam5[]    = { 0xcc, 0x10 };
    const uint8_t InitParam6[]    = { 0xB0, 0x06, 0x10, 0x16, 0x0D, 0x11, 0x06, 0x08, 0x07, 0x08, 0x22, 0x04, 0x14, 0x0F, 0x29, 0x2F, 0x1F };
    const uint8_t InitParam7[]    = { 0xB1, 0x0F, 0x18, 0x1E, 0x0C, 0x0F, 0x06, 0x08, 0x0A, 0x09, 0x24, 0x05, 0x10, 0x11, 0x2A, 0x34, 0x1F };
    const uint8_t InitParam8[]    = { 0xff, 0x77, 0x01, 0x00, 0x00, 0x11 };
    const uint8_t InitParam9[]    = { 0xb0, 0x4D };
    const uint8_t InitParam10[]   = { 0xb1, 0x4D };
    const uint8_t InitParam11[]   = { 0xb2, 0x81 };
    const uint8_t InitParam12[]   = { 0xb3, 0x80 };
    const uint8_t InitParam13[]   = { 0xb5, 0x4E };
    const uint8_t InitParam14[]   = { 0xb7, 0x85 };
    const uint8_t InitParam15[]   = { 0xb8, 0x32 };
    const uint8_t InitParam16[]   = { 0xBB, 0x03 };
    const uint8_t InitParam17[]   = { 0xc1, 0x08 };
    const uint8_t InitParam18[]   = { 0xc2, 0x08 };
    const uint8_t InitParam19[]   = { 0xd0, 0x88 };
    const uint8_t InitParam20[]   = { 0xe0, 0x00, 0x00, 0x02 };
    const uint8_t InitParam21[]   = { 0xE1, 0x06, 0x28, 0x08, 0x28, 0x05, 0x28, 0x07, 0x28, 0x0E, 0x33, 0x33 };
    const uint8_t InitParam22[]   = { 0xE2, 0x30, 0x30, 0x33, 0x33, 0x34, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00 };
    const uint8_t InitParam23[]   = { 0xe3, 0x00, 0x00, 0x33, 0x33 };
    const uint8_t InitParam24[]   = { 0xe4, 0x44, 0x44 };
    const uint8_t InitParam25[]   = { 0xE5, 0x09, 0x2F, 0x2C, 0x8C, 0x0B, 0x31, 0x2C, 0x8C, 0x0D, 0x33, 0x2C, 0x8C, 0x0F, 0x35, 0x2C, 0x8C };
    const uint8_t InitParam26[]   = { 0xE6, 0x00, 0x00, 0x33, 0x33 };
    const uint8_t InitParam27[]   = { 0xE7, 0x44, 0x44 };
    const uint8_t InitParam28[]   = { 0xE8, 0x08, 0x2E, 0x2C, 0x8C, 0x0A, 0x30, 0x2C, 0x8C, 0x0C, 0x32, 0x2C, 0x8C, 0x0E, 0x34, 0x2C, 0x8C };
    const uint8_t InitParam29[]   = { 0xE9, 0x36, 0x00 };
    const uint8_t InitParam30[]   = { 0xEB, 0x00, 0x01, 0xE4, 0xE4, 0x44, 0x88, 0x40 };
    const uint8_t InitParam31[]   = { 0xED, 0xFF, 0xFC, 0xB2, 0x45, 0x67, 0xFA, 0x01, 0xFF, 0xFF, 0x10, 0xAF, 0x76, 0x54, 0x2B, 0xCF, 0xFF };
    const uint8_t InitParam32[]   = { 0xef, 0x08, 0x08, 0x08, 0x45, 0x3f, 0x54 };
    const uint8_t InitParam33[]   = { 0xff, 0x77, 0x01, 0x00, 0x00, 0x13 };
    const uint8_t InitParam34[]   = { 0xe8, 0x00, 0x0e };
    const uint8_t InitParam35[]   = { 0xff, 0x77, 0x01, 0x00, 0x00, 0x00 };
    const uint8_t ShortRegData1[] = { 0x11 };
    const uint8_t InitParam36[]   = { 0xff, 0x77, 0x01, 0x00, 0x00, 0x13 };
    const uint8_t InitParam37[]   = { 0xe8, 0x00, 0x0c };
    const uint8_t InitParam38[]   = { 0xe8, 0x00, 0x00 };
    const uint8_t InitParam39[]   = { 0xff, 0x77, 0x01, 0x00, 0x00, 0x00 };
    const uint8_t InitParam40[]   = { 0x35, 0x00 }; // Tearing Effect On
    const uint8_t InitParam41[]   = { 0x36, 0x00 };
    const uint8_t InitParam42[]   = { 0x3A, 0x05 }; // Interface Pixel Format  // 0x05 set to rgb565 ,0x07 set to RGB888
    const uint8_t ShortRegData2[] = { 0x29 };
    const uint8_t InitParam43[]   = { 0xff, 0x77, 0x01, 0x00, 0x00, 0x10 };
    const uint8_t InitParam44[]   = { 0xe5, 0x00, 0x00 };

    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam0, ARRAY_SIZE(InitParam0));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam1, ARRAY_SIZE(InitParam1));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam2, ARRAY_SIZE(InitParam2));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam3, ARRAY_SIZE(InitParam3));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam4, ARRAY_SIZE(InitParam4));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam5, ARRAY_SIZE(InitParam5));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam6, ARRAY_SIZE(InitParam6));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam7, ARRAY_SIZE(InitParam7));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam8, ARRAY_SIZE(InitParam8));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam9, ARRAY_SIZE(InitParam9));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam10, ARRAY_SIZE(InitParam10));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam11, ARRAY_SIZE(InitParam11));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam12, ARRAY_SIZE(InitParam12));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam13, ARRAY_SIZE(InitParam13));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam14, ARRAY_SIZE(InitParam14));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam15, ARRAY_SIZE(InitParam15));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam16, ARRAY_SIZE(InitParam16));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam17, ARRAY_SIZE(InitParam17));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam18, ARRAY_SIZE(InitParam18));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam19, ARRAY_SIZE(InitParam19));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam20, ARRAY_SIZE(InitParam20));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam21, ARRAY_SIZE(InitParam21));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam22, ARRAY_SIZE(InitParam22));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam23, ARRAY_SIZE(InitParam23));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam24, ARRAY_SIZE(InitParam24));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam25, ARRAY_SIZE(InitParam25));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam26, ARRAY_SIZE(InitParam26));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam27, ARRAY_SIZE(InitParam27));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam28, ARRAY_SIZE(InitParam28));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam29, ARRAY_SIZE(InitParam29));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam30, ARRAY_SIZE(InitParam30));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam31, ARRAY_SIZE(InitParam31));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam32, ARRAY_SIZE(InitParam32));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam33, ARRAY_SIZE(InitParam33));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam34, ARRAY_SIZE(InitParam34));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam35, ARRAY_SIZE(InitParam35));
    __mipi_dsi_host_write_short_packet(dev, MIPI_DSI_DCS_SHORT_WRITE, 0, ShortRegData1[0], 0);

    duration.arbitrary_ms = 120;
    sys_sleep(duration, SLEEP_MODE_DEEP);

    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam36, ARRAY_SIZE(InitParam36));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam37, ARRAY_SIZE(InitParam37));

    duration.arbitrary_ms = 10;
    sys_sleep(duration, SLEEP_MODE_DEEP);

    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam38, ARRAY_SIZE(InitParam38));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam39, ARRAY_SIZE(InitParam39));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam40, ARRAY_SIZE(InitParam40));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam41, ARRAY_SIZE(InitParam41));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam42, ARRAY_SIZE(InitParam42));
    __mipi_dsi_host_write_short_packet(dev, MIPI_DSI_DCS_SHORT_WRITE, 0, ShortRegData2[0], 0);

    duration.arbitrary_ms = 20;
    sys_sleep(duration, SLEEP_MODE_DEEP);

    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam43, ARRAY_SIZE(InitParam43));
    __mipi_dsi_host_write_long_packet(dev, MIPI_DSI_DCS_LONG_WRITE, 0, InitParam44, ARRAY_SIZE(InitParam44));
}

/*
 * Fixme:
 *  Hardcoded video mode
 *  This might be feed by MIPI DTS node and Panel child node
 *
 * Todo:
 *  Add LPCMD support in DSI video mode
 */
static inline void mipi_dsi_host_configure_video_mode(const devinfo_t *dev)
{
    uint32_t reg;
    const mipi_dsi_device_t* mipi = __containerof(dev, mipi_dsi_device_t, dev);
    const videomode_t* videomode = &mipi->videomode;

    /* DSI host in videomode (DSI is cmd mode at POR) */
    mipi_dsi_register_write(dev, DSI_MCR_REG, 0);
    mipi_dsiw_set_videomode(dev);

    /* Configure Burst Mode */
    reg = mipi_dsi_register_read(dev, DSI_VMCR_REG);
    reg &= ~DSI_VMCR_VMT_MASK;
    reg |= (0x2 << DSI_VMCR_VMT_SHIFT) & DSI_VMCR_VMT_MASK;
    mipi_dsi_register_write(dev, DSI_VMCR_REG, reg);

    /* Config packet size, in burst mode, packet size is a full line, in pixel */
    mipi_dsi_register_write(dev, DSI_VPCR_REG, videomode->hactive);

    /* Number of chunk == 0 in burst mode */
    mipi_dsi_register_write(dev, DSI_VCCR_REG, 0);
    mipi_dsi_register_write(dev, DSI_VNPCR_REG, 0);

    /* LDTC channel ID 0 */
    mipi_dsi_register_write(dev, DSI_LVCIDR_REG, 0);

    /*
     * LDTC Polarity
     *  VSync Active High (bit clear)
     *  HSync Active High (bit clear)
     *  Data Enable Active High (bit set)
     */
    mipi_dsi_register_write(dev, DSI_LPCR_REG, 0 /*DSI_LPCR_DEP*/);

    /* Color space configuration: RGB565, 16bpp, Loosely pkt disable */
    mipi_dsi_register_write(dev, DSI_LCOLCR_REG, 2);
    mipi_dsiw_set_color_space(dev, 2);

    /* set screen timing */

    /* Horizontal sync active */
    mipi_dsi_register_write(dev, DSI_VHSACR_REG, ((videomode->hsync_len * MIPI_DSIW_LANE_BYTE_CLOCK_KHZ) / videomode->pixelclock));
    /* Horizontal back porch */
    mipi_dsi_register_write(dev, DSI_VHBPCR_REG, ((videomode->hback_porch * MIPI_DSIW_LANE_BYTE_CLOCK_KHZ) / videomode->pixelclock));
    /* Horizontal total (i.e. HSA + HFP + HAct + HBP) */
    mipi_dsi_register_write(dev, DSI_VLCR_REG, ((videomode->hback_porch
                                             + videomode->hactive
                                             + videomode->hfront_porch
                                             + videomode->hsync_len) * MIPI_DSIW_LANE_BYTE_CLOCK_KHZ) / videomode->pixelclock);

    /* Vertical sync active */
    mipi_dsi_register_write(dev, DSI_VVSACR_REG, videomode->vsync_len);
    /* Vertical back porch */
    mipi_dsi_register_write(dev, DSI_VVBPCR_REG, videomode->vback_porch);
    /* Vertical front porch */
    mipi_dsi_register_write(dev, DSI_VVFPCR_REG, videomode->vfront_porch);
    /* Vertical active */
    mipi_dsi_register_write(dev, DSI_VVACR_REG, videomode->vactive);

    /*
     * Disable LPCMD mode
     *
     * Note to ourselves, Why ?
     */
    reg = mipi_dsi_register_read(dev, DSI_VMCR_REG);
    reg &= ~DSI_VMCR_LPCE_MASK;
    mipi_dsi_register_write(dev, DSI_VMCR_REG, reg);

    /*
     * LP and LPVACT max packet size zeroed
     *  Fixme:
     *   to be computed according to escape clock and screen timing.
     *   This will defined which type of command can be sent in LPMODE during
     *   horizontal and vertical blanking in Low power.
     */
    mipi_dsi_register_write(dev, DSI_LPMCR_REG, 0);

    /* Enable HFP/HBP/VFP/VHP/VACT/VSYNC in LP */
    reg = mipi_dsi_register_read(dev, DSI_VMCR_REG);
    /* set all LP flags */
    reg |= (DSI_VMCR_LPHBPE
           | DSI_VMCR_LPHFPE
           | DSI_VMCR_LPVBPE
           | DSI_VMCR_LPVFPE
           | DSI_VMCR_LPVAE
           | DSI_VMCR_LPVSAE);
    mipi_dsi_register_write(dev, DSI_VMCR_REG, reg);
}

static inline void mipi_dsi_host_enable_pattern_gen(const devinfo_t *dev)
{
    uint32_t vmcr = mipi_dsi_register_read(dev, DSI_VMCR_REG);
    vmcr |= DSI_VMCR_PGE;
    mipi_dsi_register_write(dev, DSI_VMCR_REG, vmcr);
}

int mipi_dsi_map(const uint8_t id)
{
    const mipi_dsi_device_t *mipi_dsi = mipi_dsi_get_device(id);

    if (unlikely(mipi_dsi == NULL)) {
        return -1;
    }

    return __mipi_dsi_map(mipi_dsi);
}

int mipi_dsi_unmap(const uint8_t id)
{
    const mipi_dsi_device_t *mipi_dsi = mipi_dsi_get_device(id);

    if (unlikely(mipi_dsi == NULL)) {
        return -1;
    }

    return __mipi_dsi_unmap(mipi_dsi);
}

int mipi_dsi_probe(const uint8_t id)
{
    int ret = -1;
    const mipi_dsi_device_t *mipi_dsi = mipi_dsi_get_device(id);
    const devinfo_t *dev = NULL;
    SleepDuration duration = { .tag = SLEEP_DURATION_ARBITRARY_MS };

    if (unlikely(mipi_dsi == NULL)) {
        goto err;
    }

    /*
     * The programming procedure for video mode or adapted command mode must respect the
     * following order:
     * 1. Configure the RCC (refer to the RCC chapter)
     *  – Enable clock for DSI and LTDC
     *  – Configure LTDC PLL, turn it ON and wait for its lock
     * 2. Optionally configure the GPIO (if tearing effect requires GPIO usage for example)
     * 3. Optionally valid the ISR
     * 4. Configure the LTDC (refer to the LTDC chapter)
     *  – Program the panel timings
     *  – Enable the relevant layers
     * 5. Turn on the DSI bias
     * 6. Configure the DSI PLL, turn it ON and wait for its lock as described in Section 44.12.4
     * 7. Configure the D-PHY parameters in the DSI Host, DSI D_PHY and the DSI Wrapper to
     * define D-PHY configuration and timing as detailed in Section 44.14.2
     * 8. Configure the DSI Host timings as detailed in Section 44.14.3
     * 9. Configure the DSI Host flow control and DBI interface as detailed in Section 44.14.4
     * 10. Configure the DSI Host LTDC interface as detailed in Section 44.14.5
     * 11. Configure the DSI Host for video mode as detailed in Section 44.14.6 or adapted
     * command mode as detailed in Section 44.14.7
     * 12. Enable the D-PHY setting the DEN bit of the DSI_PCTLR
     * 13. Enable the D-PHY clock lane setting the CKEN bit of the DSI_PCTLR
     * 14. Enable the DSI Host setting the EN bit of the DSI_CR
     * 15. Enable the DSI Wrapper setting the DSIEN bit of the DSI_WCR
     * 16. Optionally send DCS commands through the APB generic interface to configure the
     * display
     * 17. Enable the LTDC in the LTDC
     * 18. Start the LTDC flow through the DSI Wrapper (CR.LTDCEN = 1)
     * In video mode, the data streaming starts as soon as the LTDC is enabled.
     * In adapted command mode, the frame buffer update is launched as soon as the
     * CR.LTDCEN bit is set.
     */

    /* step 1: done by kerne in sys_map */
    ret = __mipi_dsi_map(mipi_dsi);
    if (unlikely(ret == -1)) {
        goto err;
    }

    dev = &mipi_dsi->dev;

    printf("MIPI-DSI host revision 0x%08lx", mipi_dsi_host_version(dev));

    /* step 2/3 => N/A */

    /* step 4 */
    /* TODO configure LTDC if enabled */

    /* step 5 */
    mipi_dsi_bias_powerup(dev);
    duration.arbitrary_ms = 2;
    sys_sleep(duration, SLEEP_MODE_DEEP);

    bool bias_pwrd = mipi_dsi_bias_is_powered_up(dev);
    printf("MIPI-DSI bias powered %s", bias_pwrd ? "yes" : "nope");

    /* tempo ? */

    /* step 6 */
    mipi_dsiw_configure_pll(dev);

    /* step 7 */
    mipi_dphy_configure_clock_fine_tunning(dev);
    mipi_dsi_host_timing(dev);

    /* XXX: configure dphy fine tunning and host timing before enabling PLL */
    mipi_dsiw_start_pll(dev);
    mipi_dsi_host_dphy_timing(dev);

    /* step 8 */

    /* step 9 */
    mipi_dsi_host_flow_control(dev);

    /*
     * XXX:
     *  Starting from here, configuration follows FW4HW PoC based on ST HAL and Drivers
     *  This is not the exact same program flow that is the reference manual.
     *
     *  Steps are the following:
     *   - Configure command mode
     *   - dsi host start
     *   - send DCS command to panel
     *   - dsi host stop
     *   - setup video mode
     *   - ltdc init
     *   - dsi host start
     *   - ltdc start
     *   - ltdv enable
     *   - dsi wrapper start
     *
     *  To be fixed later
     */

    mipi_dsi_host_configure_command_mode(dev);

    /* XXX */
    mipi_dsi_register_write(dev, DSI_PCTLR_REG, DSI_PCTLR_DEN);
    mipi_dsi_register_write(dev, DSI_PCTLR_REG, DSI_PCTLR_DEN | DSI_PCTLR_CKE);

    /*
     * XXX:
     *  At this point we are in cmd mode with low power, need pll3p clock as clock source
     *  for panel configuration.
     */
    mipi_dsi_host_enable(dev);
    mipi_dsi_host_configure_panel(dev);
    mipi_dsi_host_disable(dev);

    // set LTDC video mode
    // if configured, enable pattern generator
    // set MIPI video mode
    mipi_dsi_host_configure_video_mode(dev);

    /*
     * XXX:
     *  For videomode, PLL D-Phy must be selected as clock source
     *  Otherwise Data lane 0 is stuck in stop mode.
     *
     * In further version, we might need to select manually the clock source while
     * switching between video/cmd mode.
     *
     * This hardcoded at this time, we need a dedicated syscall for regmap/sysconf usage.
     * It's quite common to have generic heterogeneous multi prupose register.
     * A given driver might take ownership on a reduce set of bit only, not the whole IP
     * and/or register.
     */
    sys_pm_set_clock(0xe4, 0x00008000, 1);

    mipi_dsi_host_enable(dev);
    // ltdc start
    // ltdc en
    mipi_dsiw_enable_wrapper(dev);

    duration.arbitrary_ms = 5;
    sys_sleep(duration, SLEEP_MODE_DEEP);

#if defined(CONFIG_WITH_VIDEO_PATTERN_GENERATOR)
    mipi_dsi_host_enable_pattern_gen(dev);
#endif /* defined(CONFIG_WITH_VIDEO_PATTERN_GENERATOR) */

    // __mipi_dsi_unmap(mipi_dsi);
err:
    return ret;
}
