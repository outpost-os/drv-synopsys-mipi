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

#ifndef __MIPI_DSI_PRIV_H
#define __MIPI_DSI_PRIV_H

#include <handle.h>
#include <device.h>

#include <lcd/lcd.h>

/* FIXME: export those through libshield */

/**
 * @brief  ARM asm implementation of iowrite32
 *
 * @param addr destination address
 * @param val word to write
 *
 * @note there is a compiler barrier in order to prevent compiler to reorder memory access.
 *
 * @note this function is always inline
 */
__attribute__((always_inline))
static inline void iowrite32(size_t addr, uint32_t val)
{
    asm volatile(
        "str %1, %0" : : "Qo" (*(volatile uint32_t *)addr), "r" (val) : "memory"
    );
}

/**
 * @brief  ARM asm implementation of ioread32
 *
 * @param addr source address
 * @return readden word
 *
 * @note there is a compiler barrier in order to prevent compiler to reorder memory access.
 *
 * @note this function is always inline
 */
__attribute__((always_inline))
static inline uint32_t ioread32(size_t addr)
{
    uint32_t val;

    asm volatile(
        "ldr %0, %1" : "=r" (val) : "Qo" (*(volatile uint32_t *)addr) : "memory"
    );

    return val;
}

typedef struct mipi_dsi_device {
    devinfo_t dev;
    /* Videomode might be a config property from chosen panel */
    videomode_t videomode;
    mipi_bus_config_t bus_config;
    /*
     * TODO:
     *  - add panel device id
     *  - add LTDC device id
     */
} mipi_dsi_device_t;


__attribute__((always_inline))
static inline uint32_t mipi_dsi_register_read(const devinfo_t *dev, size_t reg_offset)
{
    return ioread32(dev->baseaddr + reg_offset);
}

__attribute__((always_inline))
static inline void mipi_dsi_register_write(const devinfo_t *dev, size_t reg_offset, uint32_t value)
{
    iowrite32(dev->baseaddr + reg_offset, value);
}

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

#define unlikely(x) __builtin_expect(!!(x), 0)
#define likely(x)   __builtin_expect(!!(x), 1)

const mipi_dsi_device_t *mipi_dsi_get_device(const uint8_t id);

void __mipi_dsi_host_write_long_packet(
    const devinfo_t *dev, uint8_t type, uint8_t channel_id, const uint8_t *payload, size_t size
);

void __mipi_dsi_host_write_short_packet(
    const devinfo_t *dev, uint8_t type, uint8_t channel_id, uint8_t arg0, uint8_t arg1
);

#endif /* __MIPI_DSI_PRIV_H */
