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

#ifndef __MIPI_DSI_BIAS_H
#define __MIPI_DSI_BIAS_H

#include "mipi_dsi_defs.h"
#include "mipi_dsi_priv.h"

static inline bool mipi_dsi_bias_is_powered_up(const devinfo_t *dev)
{
    return mipi_dsi_register_read(dev, DSI_BCFGR_REG) & DSI_BCFGR_PWRUP;
}

static inline void mipi_dsi_bias_powerup(const devinfo_t *dev)
{
    mipi_dsi_register_write(dev, DSI_BCFGR_REG, DSI_BCFGR_PWRUP);
}

static inline void mipi_dsi_bias_powerdown(const devinfo_t *dev)
{
    mipi_dsi_register_write(dev, DSI_BCFGR_REG, 0);
}

#endif /* __MIPI_DSI_BIAS_H */
