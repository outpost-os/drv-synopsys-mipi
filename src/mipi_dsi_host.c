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

#include <mipi/mipi_dsi.h>
#include <mipi/mipi_dsi_host.h>

#include "mipi_dsi_defs.h"
#include "mipi_dsi_priv.h"

/* XXX */
#define MIN(a,b) ((a) < (b) ? (a) : (b))

static inline void mipi_dsi_host_wait_cmdfifo_empty(const devinfo_t *dev)
{
    while(!(mipi_dsi_register_read(dev, DSI_GPSR_REG) & DSI_GPSR_CMDFE));
}

static inline void mipi_dsi_host_wait_payloadfifo_empty(const devinfo_t *dev)
{
    while(!(mipi_dsi_register_read(dev, DSI_GPSR_REG) & DSI_GPSR_PWRFE));
}

static inline void mipi_dsi_host_write_cmd_header(const devinfo_t *dev, uint32_t header)
{
    mipi_dsi_register_write(dev, DSI_GHCR_REG, header);
}

static inline void mipi_dsi_host_write_cmd_payload(const devinfo_t *dev, const uint8_t *payload, size_t size)
{
    uint32_t chunk;
    size_t chunk_size;
    size_t remaining = size;

    /* No error handling in devel, fixed that later */
    if (size == 0) {
        return;
    }

    while(remaining > 0) {
        chunk_size = MIN(remaining, sizeof(uint32_t));
        chunk = 0;

        switch(chunk_size) {
        case 4:
            chunk |= payload[3] << 24;
            [[ fallthrough ]];
        case 3:
            chunk |= payload[2] << 16;
            [[ fallthrough ]];
        case 2:
            chunk |= payload[1] << 8;
            [[ fallthrough ]];
        case 1:
            chunk |= payload[0];
            mipi_dsi_register_write(dev, DSI_GPDR_REG, chunk);
            break;
        }

        remaining -= chunk_size;
        payload += chunk_size;
    }
}

void __mipi_dsi_host_write_long_packet(
    const devinfo_t *dev, uint8_t type, uint8_t channel_id, const uint8_t *payload, size_t size
)
{
    uint32_t header = ((type << DSI_GHCR_DT_SHIFT) & DSI_GHCR_DT_MASK)
                    | ((channel_id << DSI_GHCR_VCID_SHIFT) & DSI_GHCR_VCID_MASK)
                    | ((size << DSI_GHCR_WCLSB_SHIFT) & (DSI_GHCR_WCLSB_MASK | DSI_GHCR_WCMSB_MASK));

    mipi_dsi_host_wait_cmdfifo_empty(dev);
    mipi_dsi_host_write_cmd_payload(dev, payload, size);
    mipi_dsi_host_write_cmd_header(dev, header);
    //mipi_dsi_host_wait_payloadfifo_empty(dev);
}

void __mipi_dsi_host_write_short_packet(
    const devinfo_t *dev, uint8_t type, uint8_t channel_id, uint8_t arg0, uint8_t arg1
)
{
    uint32_t header = ((type << DSI_GHCR_DT_SHIFT) & DSI_GHCR_DT_MASK)
                    | ((channel_id << DSI_GHCR_VCID_SHIFT) & DSI_GHCR_VCID_MASK)
                    | ((arg0 << DSI_GHCR_WCLSB_SHIFT) & DSI_GHCR_WCLSB_MASK)
                    | ((arg1 << DSI_GHCR_WCMSB_SHIFT) & DSI_GHCR_WCMSB_MASK);

    mipi_dsi_host_wait_cmdfifo_empty(dev);
    mipi_dsi_host_write_cmd_header(dev, header);
    //mipi_dsi_host_wait_cmdfifo_empty(dev);
}
