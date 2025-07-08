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

#ifndef __MIPI_DSI_WRAPPER_H
#define __MIPI_DSI_WRAPPER_H

#include "mipi_dsi_defs.h"
#include "mipi_dsi_priv.h"

/* XXX:
 *  Hardcoded PLL, param might come from DTS computation at build time
 *
 * D-Phy PLL:
 *  - pll_in = 16MHz (HSE)
 *  - vco_in: pll_in / IDF = 16 / 4 = 4MHz
 *  - vco_out: vco_in * 2 * NDIV = 4 * 2 * 99 = 792MHz
 *  - pll_out: vco_out / ODF = 792 / 2 = 396MHz
 *
 *  Note:
 *  - bus bitclock: 396MHz
 *  - lane byte clock 49.5MHz
 *  - lane_byte_clock_cycle  ~20.2ns (round to upper ns ?)
 *
 *  Warning:
 *  - bus clock is too high, this is the configuration for 24bpp color mode configuration instead
 *  of 16bpp (i.e. RGB565). We are aware that this need to be refined but all hardware test has
 *  been done with this exact setting.
 */
#define MIPI_DSIW_PLL_NDIV 99
#define MIPI_DSIW_PLL_IDF 4
#define MIPI_DSIW_PLL_ODF 2
#define MIPI_DSIW_LANE_BYTE_CLOCK_KHZ 49500
#define MIPI_DSIW_LANE_BYTE_CLOCK_CYCLE_NS 21 /* round(20.2) */

#define MIPI_DSIW_PLL_BC 1 /* band control = 1 ==> vco_out ∈ [500, 1000]MHz */

/* XXX:
 *  missing register from SVD (...)
 */
#define DSI_WRPCR_BC_SHIFT 29UL
#define DSI_WRPCR_BC_MASK  (((1UL << 2UL) - 1UL) << DSI_WRPCR_BC_SHIFT)

#define DSI_WPTR_REG 0x434
#define DSI_WPTR_REG_VALUE 0x0

static inline void mipi_dsiw_reset_event(const devinfo_t *dev)
{
    mipi_dsi_register_write(dev, DSI_WIFCR_REG, DSI_WIFCR_CPLLUIF | DSI_WIFCR_CPLLLIF | DSI_WIFCR_CERIF | DSI_WIFCR_CTEIF);
}

static inline void mipi_dsiw_wait_pll_locked(const devinfo_t *dev)
{
    while(!(mipi_dsi_register_read(dev, DSI_WISR_REG) & DSI_WISR_PLLLS));
    mipi_dsiw_reset_event(dev);
}

static inline void mipi_dsiw_configure_pll(const devinfo_t *dev)
{
    uint32_t wrpcr = mipi_dsi_register_read(dev, DSI_WRPCR_REG);

    mipi_dsiw_reset_event(dev);

    wrpcr = ((MIPI_DSIW_PLL_NDIV << DSI_WRPCR_NDIV_SHIFT) & DSI_WRPCR_NDIV_MASK)
          | ((MIPI_DSIW_PLL_IDF << DSI_WRPCR_IDF_SHIFT) & DSI_WRPCR_IDF_MASK)
          | ((MIPI_DSIW_PLL_ODF << DSI_WRPCR_ODF_SHIFT) & DSI_WRPCR_ODF_MASK)
          | ((MIPI_DSIW_PLL_BC << DSI_WRPCR_BC_SHIFT) & DSI_WRPCR_BC_MASK);

    mipi_dsi_register_write(dev, DSI_WRPCR_REG, wrpcr);

    /*
     * XXX:
     *  Pll tuning == 0
     *  To be set according to Fpfd, here 4MHz, filter and pump charge set to 0
     */
    mipi_dsi_register_write(dev, DSI_WPTR_REG, DSI_WPTR_REG_VALUE);
}

static inline void mipi_dsiw_start_pll(const devinfo_t *dev)
{
    SleepDuration duration = { .tag = SLEEP_DURATION_ARBITRARY_MS };
    uint32_t wrpcr = mipi_dsi_register_read(dev, DSI_WRPCR_REG);

    wrpcr |= DSI_WRPCR_PLLEN;
    mipi_dsi_register_write(dev, DSI_WRPCR_REG, wrpcr);
    duration.arbitrary_ms = 1;
    sys_sleep(duration, SLEEP_MODE_DEEP);
    mipi_dsiw_wait_pll_locked(dev);
}

static inline void mipi_dsiw_set_videomode(const devinfo_t *dev)
{
    uint32_t wcfgr = mipi_dsi_register_read(dev, DSI_WCFGR_REG);
    wcfgr &= ~DSI_WCFGR_DSIM;
    mipi_dsi_register_write(dev, DSI_WCFGR_REG, wcfgr);
}

static inline void mipi_dsiw_set_adapted_cmdmode(const devinfo_t *dev)
{
    uint32_t wcfgr = mipi_dsi_register_read(dev, DSI_WCFGR_REG);
    wcfgr |= DSI_WCFGR_DSIM;
    mipi_dsi_register_write(dev, DSI_WCFGR_REG, wcfgr);
}

static inline void mipi_dsiw_set_color_space(const devinfo_t *dev, uint8_t color)
{
    uint32_t wcfgr = mipi_dsi_register_read(dev, DSI_WCFGR_REG);
    wcfgr &= ~DSI_WCFGR_COLMUX_MASK;
    wcfgr |= (color << DSI_WCFGR_COLMUX_SHIFT) & DSI_WCFGR_COLMUX_MASK;
    mipi_dsi_register_write(dev, DSI_WCFGR_REG, wcfgr);
}

static inline void mipi_dsiw_enable_wrapper(const devinfo_t *dev)
{
    uint32_t wcr = mipi_dsi_register_read(dev, DSI_WCR_REG);
    wcr |= DSI_WCR_DSIEN;
    mipi_dsi_register_write(dev, DSI_WCR_REG, wcr);
    mipi_dsi_register_read(dev, DSI_WCR_REG);
}

static inline void mipi_dsiw_disable_wrapper(const devinfo_t *dev)
{
    uint32_t wcr = mipi_dsi_register_read(dev, DSI_WCR_REG);
    wcr &= ~DSI_WCR_DSIEN;
    mipi_dsi_register_write(dev, DSI_WCR_REG, wcr);
}

static inline void mipi_dsiw_enable_ltdc(const devinfo_t *dev)
{
    uint32_t wcr = mipi_dsi_register_read(dev, DSI_WCR_REG);
    wcr |= DSI_WCR_LTDCEN;
    mipi_dsi_register_write(dev, DSI_WCR_REG, wcr);
}

static inline void mipi_dsiw_disable_ltdc(const devinfo_t *dev)
{
    uint32_t wcr = mipi_dsi_register_read(dev, DSI_WCR_REG);
    wcr &= ~DSI_WCR_LTDCEN;
    mipi_dsi_register_write(dev, DSI_WCR_REG, wcr);
}

#endif /* __MIPI_DSI_WRAPPER_H */
