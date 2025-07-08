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

#ifndef __MIPI_DPHY_H
#define __MIPI_DPHY_H

#include "mipi_dsi_defs.h"
#include "mipi_dsi_priv.h"

static inline void mipi_dphy_band_control(const devinfo_t *dev)
{
    /*
     * XXX: Hardcoded (i.e. bus bitclock: 396MHz)
     *
     * 00000: 80 to 100 MHz
     * 00001: 100 to 120 MHz
     * 00010: 120 to 160 MHz
     * 00011: 160 to 200 MHz
     * 00100: 200 to 240 MHz
     * 00101: 240 to 320 MHz
     * 00110: 320 to 390 MHz
     * 00111: 390 to 450 MHz
     * 01000: 450 to 510 MHz
     */
    uint32_t band_control = 0x8UL;
    mipi_dsi_register_write(dev, DSI_DPCBCR_REG, (band_control << DSI_DPCBCR_BC_SHIFT) & DSI_DPCBCR_BC_MASK);
    mipi_dsi_register_write(dev, DSI_DPDL0BCR_REG, band_control);
    mipi_dsi_register_write(dev, DSI_DPDL1BCR_REG, band_control);
}

static inline void mipi_dphy_slew_rate(const devinfo_t *dev)
{
    uint32_t slew_rate = 0xeUL; /* this is the only defined value */
    mipi_dsi_register_write(dev, DSI_DPCSRCR_REG, slew_rate);
    mipi_dsi_register_write(dev, DSI_DPDL0SRCR_REG, slew_rate);
    mipi_dsi_register_write(dev, DSI_DPDL1SRCR_REG, slew_rate);
}

/*
 * XXX:
 * Missing registers description in SVD
 */

#define DSI_DPDL0HSOCR_REG 0xc5cUL
#define DSI_DPDL0LPXOCR_REG 0xc60UL
#define DSI_DPDL1HSOCR_REG 0xcf4UL
#define DSI_DPDL1LPXOCR_REG 0xcf8UL

static inline void mipi_dphy_offset(const devinfo_t *dev)
{
    uint32_t hsp_offset = 0x2;
    uint32_t lxp_offset = 0x4;

    mipi_dsi_register_write(dev, DSI_DPDL0HSOCR_REG, hsp_offset << 4);
    mipi_dsi_register_write(dev, DSI_DPDL0LPXOCR_REG, lxp_offset);

    mipi_dsi_register_write(dev, DSI_DPDL1HSOCR_REG, hsp_offset << 4);
    mipi_dsi_register_write(dev, DSI_DPDL1LPXOCR_REG, lxp_offset);
}

static inline void mipi_dphy_configure_clock_fine_tunning(const devinfo_t *dev)
{
    mipi_dphy_band_control(dev);
    mipi_dphy_slew_rate(dev);
    mipi_dphy_offset(dev);
}

#endif /* __MIPI_DPHY_H */
