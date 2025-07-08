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

#ifndef __MIPI_DSI_H
#define __MIPI_DSI_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdint.h>
#include <stddef.h>

/*
 * A MIPI DSI slave supports multiple standard MIPI
 * commands. These commands may have arguments, making
 * the associated transaction type variating (short write,
 * short write with 1 arg, long write, and so on).
 *
 * These standard MIPI_DSI DCS commands are the following:
 */
typedef enum mipi_dsi_dcs_cmd {
    MIPI_DCS_NOP                   = 0x00,
    MIPI_DCS_SOFT_RESET            = 0x01,
    MIPI_DCS_GET_DISPLAY_ID        = 0x04,
    MIPI_DCS_GET_RED_CHANNEL       = 0x06,
    MIPI_DCS_GET_GREEN_CHANNEL     = 0x07,
    MIPI_DCS_GET_BLUE_CHANNEL      = 0x08,
    MIPI_DCS_GET_DISPLAY_STATUS    = 0x09,
    MIPI_DCS_GET_POWER_MODE        = 0x0A,
    MIPI_DCS_GET_ADDRESS_MODE      = 0x0B,
    MIPI_DCS_GET_PIXEL_FORMAT      = 0x0C,
    MIPI_DCS_GET_DISPLAY_MODE      = 0x0D,
    MIPI_DCS_GET_SIGNAL_MODE       = 0x0E,
    MIPI_DCS_GET_DIAGNOSTIC_RESULT = 0x0F,
    MIPI_DCS_ENTER_SLEEP_MODE      = 0x10,
    MIPI_DCS_EXIT_SLEEP_MODE       = 0x11,
    MIPI_DCS_ENTER_PARTIAL_MODE    = 0x12,
    MIPI_DCS_ENTER_NORMAL_MODE     = 0x13,
    MIPI_DCS_EXIT_INVERT_MODE      = 0x20,
    MIPI_DCS_ENTER_INVERT_MODE     = 0x21,
    MIPI_DCS_SET_GAMMA_CURVE       = 0x26,
    MIPI_DCS_SET_DISPLAY_OFF       = 0x28,
    MIPI_DCS_SET_DISPLAY_ON        = 0x29,
    MIPI_DCS_SET_COLUMN_ADDRESS    = 0x2A,
    MIPI_DCS_SET_PAGE_ADDRESS      = 0x2B,
    MIPI_DCS_WRITE_MEMORY_START    = 0x2C,
    MIPI_DCS_WRITE_LUT             = 0x2D,
    MIPI_DCS_READ_MEMORY_START     = 0x2E,
    MIPI_DCS_SET_PARTIAL_AREA      = 0x30,
    MIPI_DCS_SET_SCROLL_AREA       = 0x33,
    MIPI_DCS_SET_TEAR_OFF          = 0x34,
    MIPI_DCS_SET_TEAR_ON           = 0x35,
    MIPI_DCS_SET_ADDRESS_MODE      = 0x36,
    MIPI_DCS_SET_SCROLL_START      = 0x37,
    MIPI_DCS_EXIT_IDLE_MODE        = 0x38,
    MIPI_DCS_ENTER_IDLE_MODE       = 0x39,
    MIPI_DCS_SET_PIXEL_FORMAT      = 0x3A,
    MIPI_DCS_WRITE_MEMORY_CONTINUE = 0x3C,
    MIPI_DCS_READ_MEMORY_CONTINUE  = 0x3E,
    MIPI_DCS_SET_TEAR_SCANLINE     = 0x44,
    MIPI_DCS_GET_SCANLINE          = 0x45,
    /* starting at MIPI DCS 1.3 specifications */
    MIPI_DCS_SET_DISPLAY_BRIGHTNESS  = 0x51,
    MIPI_DCS_GET_DISPLAY_BRIGHTNESS  = 0x52,
    MIPI_DCS_WRITE_CONTROL_DISPLAY   = 0x53,
    MIPI_DCS_GET_CONTROL_DISPLAY     = 0x54,
    MIPI_DCS_WRITE_POWER_SAVE        = 0x55,
    MIPI_DCS_GET_POWER_SAVE          = 0x56,
    MIPI_DCS_SET_CABC_MIN_BRIGHTNESS = 0x5E,
    MIPI_DCS_GET_CABC_MIN_BRIGHTNESS = 0x5F,
    MIPI_DCS_READ_DDB_START          = 0xA1,
    MIPI_DCS_READ_DDB_CONTINUE       = 0xA8,
} mipi_dsi_dcs_cmd_t;

/*
 * Transactions between MIPI master and slaves are typed.
 * There are various types that define the transaction size
 * and structure.
 * These types are defined in the following enumerate.
 */
typedef enum mipi_dsi_transaction_type {
    MIPI_DSI_V_SYNC_START                        = 0x01,
    MIPI_DSI_V_SYNC_END                          = 0x11,
    MIPI_DSI_H_SYNC_START                        = 0x21,
    MIPI_DSI_H_SYNC_END                          = 0x31,
    MIPI_DSI_COLOR_MODE_OFF                      = 0x02,
    MIPI_DSI_COLOR_MODE_ON                       = 0x12,
    MIPI_DSI_SHUTDOWN_PERIPHERAL                 = 0x22,
    MIPI_DSI_TURN_ON_PERIPHERAL                  = 0x32,
    MIPI_DSI_GENERIC_SHORT_WRITE_0_PARAM         = 0x03,
    MIPI_DSI_GENERIC_SHORT_WRITE_1_PARAM         = 0x13,
    MIPI_DSI_GENERIC_SHORT_WRITE_2_PARAM         = 0x23,
    MIPI_DSI_GENERIC_READ_REQUEST_0_PARAM        = 0x04,
    MIPI_DSI_GENERIC_READ_REQUEST_1_PARAM        = 0x14,
    MIPI_DSI_GENERIC_READ_REQUEST_2_PARAM        = 0x24,
    MIPI_DSI_DCS_SHORT_WRITE                     = 0x05,
    MIPI_DSI_DCS_SHORT_WRITE_PARAM               = 0x15,
    MIPI_DSI_DCS_READ                            = 0x06,
    MIPI_DSI_DCS_COMPRESSION_MODE                = 0x07,
    MIPI_DSI_PPS_LONG_WRITE                      = 0x0A,
    MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE      = 0x37,
    MIPI_DSI_END_OF_TRANSMISSION                 = 0x08,
    MIPI_DSI_NULL_PACKET                         = 0x09,
    MIPI_DSI_BLANKING_PACKET                     = 0x19,
    MIPI_DSI_GENERIC_LONG_WRITE                  = 0x29,
    MIPI_DSI_DCS_LONG_WRITE                      = 0x39,
    MIPI_DSI_LOOSELY_PACKED_PIXEL_STREAM_YCBCR20 = 0x0c,
    MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR24         = 0x1c,
    MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR16         = 0x2c,
    MIPI_DSI_PACKED_PIXEL_STREAM_30              = 0x0d,
    MIPI_DSI_PACKED_PIXEL_STREAM_36              = 0x1d,
    MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR12         = 0x3d,
    MIPI_DSI_PACKED_PIXEL_STREAM_16              = 0x0e,
    MIPI_DSI_PACKED_PIXEL_STREAM_18              = 0x1e,
    MIPI_DSI_PIXEL_STREAM_3BYTE_18               = 0x2e,
    MIPI_DSI_PACKED_PIXEL_STREAM_24              = 0x3e,
} mipi_dsi_cmd_type_t;

typedef enum mipi_dsi_rx_transaction_type {
    MIPI_DSI_RX_ACKNOWLEDGE_AND_ERROR_REPORT      = 0x02,
    MIPI_DSI_RX_END_OF_TRANSMISSION               = 0x08,
    MIPI_DSI_RX_GENERIC_SHORT_READ_RESPONSE_1BYTE = 0x11,
    MIPI_DSI_RX_GENERIC_SHORT_READ_RESPONSE_2BYTE = 0x12,
    MIPI_DSI_RX_GENERIC_LONG_READ_RESPONSE        = 0x1a,
    MIPI_DSI_RX_DCS_LONG_READ_RESPONSE            = 0x1c,
    MIPI_DSI_RX_DCS_SHORT_READ_RESPONSE_1BYTE     = 0x21,
    MIPI_DSI_RX_DCS_SHORT_READ_RESPONSE_2BYTE     = 0x22,
} mipi_dsi_rx_msg_type_t;

typedef struct mipi_bus_config {
    uint32_t bpp;       /**< bit per pixel in mipi transfer */
    uint32_t lanes;     /**< number of mipi lane */
    uint32_t bitclock;  /**< bit clock frequency (kHz) */
} mipi_bus_config_t;

/**
 * mipi_dsi_map() - Maps MIPI-DSI device in the task address space
 *
 * @param[in] mipi_dsi_id: the MIPI-DSI controller id to work on, with the generated ID from DTS
 *
 * The MIPI-DSI controller identifier is using the DEV_ID_<controller_name> terminology,
 * such as DEV_ID_MIPI_DSIn for for querying the MIPI-DSI n instance of the bus on the
 * platform. controller_name field is based on the dts node label.
 *
 * Return: 0 if device mapping is done, or -1
 */
int mipi_dsi_map(const uint8_t mipi_dsi_id);

/**
 * mipi_dsi_unmap() - Unmaps MIPI-DSI device in the task address space
 *
 * @param[in] mipi_dsi_id: the MIPI-DSI controller id to work on, with the generated ID from DTS
 *
 * The MIPI-DSI controller identifier is using the DEV_ID_<controller_name> terminology,
 * such as DEV_ID_MIPI_DSIn for for querying the MIPI-DSI n instance of the bus on the
 * platform. controller_name field is based on the dts node label.
 *
 * Return: 0 if device is unmapped properly, or -1
 */
int mipi_dsi_unmap(const uint8_t mipi_dsi_id);

/**
 * mipi_dsi_probe() - Probe and configure the given i2c bus
 *
 * The MIPI-DSI controller identifier is using the DEV_ID_<controller_name> terminology,
 * such as DEV_ID_MIPI_DSIn for for querying the MIPI-DSI n instance of the bus on the
 * platform. controller_name field is based on the dts node label.
 *
 * FIXME: by now, controller configuration is partially hard-coded
 *
 * Return: 0 if device is probed properly, or -1
 */
int mipi_dsi_probe(const uint8_t mipi_dsi_id);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* __MIPI_DSI_H */
