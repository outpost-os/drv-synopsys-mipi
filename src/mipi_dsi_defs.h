// SPDX-License-Identifier: Apache-2.0

/*
 * Copyright 2023 Ledger SAS
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * XXX:
 *  !!!! Generated header, DO NOT EDIT !!!!
 */
#ifndef __STM32U599_DSI_DEFS_H
#define __STM32U599_DSI_DEFS_H

#include <assert.h>
#include <inttypes.h>

/**
 *  @brief DSI VR register
 *
 * DSI Host version register
 *
 *  @note offset: 0x0UL
 *        width:  32 bits
 */
#define DSI_VR_REG  0x0UL

/**
 * @brief DSI VR VERSION field
 *
 * Version of the DSI Host This read-only register contains the version of the DSI Host
 *
 * @note offset: 0x0UL
 *       width:  32
 *       access: read-only
 */
#define DSI_VR_VERSION_SHIFT 0x0UL
#define DSI_VR_VERSION_MASK (((1ULL << 32) - 1) << DSI_VR_VERSION_SHIFT)


struct dsi_vr {
    uint32_t version:32;
    };

typedef struct dsi_vr dsi_vr_t;
static_assert(sizeof(dsi_vr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI CR register
 *
 * DSI Host control register
 *
 *  @note offset: 0x4UL
 *        width:  32 bits
 */
#define DSI_CR_REG  0x4UL

/**
 * @brief DSI CR EN field
 *
 * Enable This bit configures the DSI Host in either power-up mode or to reset.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_CR_EN (1UL << 0x0UL)
#define DSI_CR_EN_SHIFT 0x0UL
#define DSI_CR_EN_MASK (((1ULL << 1) - 1) << DSI_CR_EN_SHIFT)


struct dsi_cr {
    uint32_t en:1;
    };

typedef struct dsi_cr dsi_cr_t;
static_assert(sizeof(dsi_cr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI CCR register
 *
 * DSI Host clock control register
 *
 *  @note offset: 0x8UL
 *        width:  32 bits
 */
#define DSI_CCR_REG  0x8UL

/**
 * @brief DSI CCR TXECKDIV field
 *
 * TX escape clock division This field indicates the division factor for the TX escape clock source (lanebyteclk). The values 0 and 1 stop the TX_ESC clock generation.
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define DSI_CCR_TXECKDIV_SHIFT 0x0UL
#define DSI_CCR_TXECKDIV_MASK (((1ULL << 8) - 1) << DSI_CCR_TXECKDIV_SHIFT)
/**
 * @brief DSI CCR TOCKDIV field
 *
 * Timeout clock division This field indicates the division factor for the timeout clock used as the timing unit in the configuration of HS to LP and LP to HS transition error.
 *
 * @note offset: 0x8UL
 *       width:  8
 *       access: read-write
 */
#define DSI_CCR_TOCKDIV_SHIFT 0x8UL
#define DSI_CCR_TOCKDIV_MASK (((1ULL << 8) - 1) << DSI_CCR_TOCKDIV_SHIFT)


struct dsi_ccr {
    uint32_t txeckdiv:8;
    uint32_t tockdiv:8;
    };

typedef struct dsi_ccr dsi_ccr_t;
static_assert(sizeof(dsi_ccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI LVCIDR register
 *
 * DSI Host LTDC VCID register
 *
 *  @note offset: 0xcUL
 *        width:  32 bits
 */
#define DSI_LVCIDR_REG  0xcUL

/**
 * @brief DSI LVCIDR VCID field
 *
 * Virtual channel ID These bits configure the virtual channel ID for the LTDC interface traffic.
 *
 * @note offset: 0x0UL
 *       width:  2
 *       access: read-write
 */
#define DSI_LVCIDR_VCID_SHIFT 0x0UL
#define DSI_LVCIDR_VCID_MASK (((1ULL << 2) - 1) << DSI_LVCIDR_VCID_SHIFT)


struct dsi_lvcidr {
    uint32_t vcid:2;
    };

typedef struct dsi_lvcidr dsi_lvcidr_t;
static_assert(sizeof(dsi_lvcidr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI LCOLCR register
 *
 * DSI Host LTDC color coding register
 *
 *  @note offset: 0x10UL
 *        width:  32 bits
 */
#define DSI_LCOLCR_REG  0x10UL

/**
 * @brief DSI LCOLCR COLC field
 *
 * Color coding This field configures the DPI color coding. Others: Reserved
 *
 * @note offset: 0x0UL
 *       width:  4
 *       access: read-write
 */
#define DSI_LCOLCR_COLC_SHIFT 0x0UL
#define DSI_LCOLCR_COLC_MASK (((1ULL << 4) - 1) << DSI_LCOLCR_COLC_SHIFT)
/**
 * @brief DSI LCOLCR LPE field
 *
 * Loosely packet enable This bit enables the loosely packed variant to 18-bit configuration
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-write
 */
#define DSI_LCOLCR_LPE (1UL << 0x8UL)
#define DSI_LCOLCR_LPE_SHIFT 0x8UL
#define DSI_LCOLCR_LPE_MASK (((1ULL << 1) - 1) << DSI_LCOLCR_LPE_SHIFT)


struct dsi_lcolcr {
    uint32_t colc:4;
    uint32_t reserved0:4;
    uint32_t lpe:1;
    };

typedef struct dsi_lcolcr dsi_lcolcr_t;
static_assert(sizeof(dsi_lcolcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI LPCR register
 *
 * DSI Host LTDC polarity configuration register
 *
 *  @note offset: 0x14UL
 *        width:  32 bits
 */
#define DSI_LPCR_REG  0x14UL

/**
 * @brief DSI LPCR DEP field
 *
 * Data enable polarity This bit configures the polarity of data enable pin.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_LPCR_DEP (1UL << 0x0UL)
#define DSI_LPCR_DEP_SHIFT 0x0UL
#define DSI_LPCR_DEP_MASK (((1ULL << 1) - 1) << DSI_LPCR_DEP_SHIFT)
/**
 * @brief DSI LPCR VSP field
 *
 * VSYNC polarity This bit configures the polarity of VSYNC pin.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define DSI_LPCR_VSP (1UL << 0x1UL)
#define DSI_LPCR_VSP_SHIFT 0x1UL
#define DSI_LPCR_VSP_MASK (((1ULL << 1) - 1) << DSI_LPCR_VSP_SHIFT)
/**
 * @brief DSI LPCR HSP field
 *
 * HSYNC polarity This bit configures the polarity of HSYNC pin.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-write
 */
#define DSI_LPCR_HSP (1UL << 0x2UL)
#define DSI_LPCR_HSP_SHIFT 0x2UL
#define DSI_LPCR_HSP_MASK (((1ULL << 1) - 1) << DSI_LPCR_HSP_SHIFT)


struct dsi_lpcr {
    uint32_t dep:1;
    uint32_t vsp:1;
    uint32_t hsp:1;
    };

typedef struct dsi_lpcr dsi_lpcr_t;
static_assert(sizeof(dsi_lpcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI LPMCR register
 *
 * DSI Host low-power mode configuration register
 *
 *  @note offset: 0x18UL
 *        width:  32 bits
 */
#define DSI_LPMCR_REG  0x18UL

/**
 * @brief DSI LPMCR VLPSIZE field
 *
 * VACT largest packet size This field is used for the transmission of commands in low-power mode. It defines the size, in bytes, of the largest packet that can fit in a line during VACT regions.
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define DSI_LPMCR_VLPSIZE_SHIFT 0x0UL
#define DSI_LPMCR_VLPSIZE_MASK (((1ULL << 8) - 1) << DSI_LPMCR_VLPSIZE_SHIFT)
/**
 * @brief DSI LPMCR LPSIZE field
 *
 * Largest packet size This field is used for the transmission of commands in low-power mode. It defines the size, in bytes, of the largest packet that can fit in a line during VSA, VBP and VFP regions.
 *
 * @note offset: 0x10UL
 *       width:  8
 *       access: read-write
 */
#define DSI_LPMCR_LPSIZE_SHIFT 0x10UL
#define DSI_LPMCR_LPSIZE_MASK (((1ULL << 8) - 1) << DSI_LPMCR_LPSIZE_SHIFT)


struct dsi_lpmcr {
    uint32_t vlpsize:8;
    uint32_t reserved0:8;
    uint32_t lpsize:8;
    };

typedef struct dsi_lpmcr dsi_lpmcr_t;
static_assert(sizeof(dsi_lpmcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI PCR register
 *
 * DSI Host protocol configuration register
 *
 *  @note offset: 0x2cUL
 *        width:  32 bits
 */
#define DSI_PCR_REG  0x2cUL

/**
 * @brief DSI PCR ETTXE field
 *
 * EoTp transmission enable This bit enables the EoTP transmission.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_PCR_ETTXE (1UL << 0x0UL)
#define DSI_PCR_ETTXE_SHIFT 0x0UL
#define DSI_PCR_ETTXE_MASK (((1ULL << 1) - 1) << DSI_PCR_ETTXE_SHIFT)
/**
 * @brief DSI PCR ETRXE field
 *
 * EoTp reception enable This bit enables the EoTp reception.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define DSI_PCR_ETRXE (1UL << 0x1UL)
#define DSI_PCR_ETRXE_SHIFT 0x1UL
#define DSI_PCR_ETRXE_MASK (((1ULL << 1) - 1) << DSI_PCR_ETRXE_SHIFT)
/**
 * @brief DSI PCR BTAE field
 *
 * Bus-turn-around enable This bit enables the bus-turn-around (BTA) request.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-write
 */
#define DSI_PCR_BTAE (1UL << 0x2UL)
#define DSI_PCR_BTAE_SHIFT 0x2UL
#define DSI_PCR_BTAE_MASK (((1ULL << 1) - 1) << DSI_PCR_BTAE_SHIFT)
/**
 * @brief DSI PCR ECCRXE field
 *
 * ECC reception enable This bit enables the ECC reception, error correction and reporting.
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-write
 */
#define DSI_PCR_ECCRXE (1UL << 0x3UL)
#define DSI_PCR_ECCRXE_SHIFT 0x3UL
#define DSI_PCR_ECCRXE_MASK (((1ULL << 1) - 1) << DSI_PCR_ECCRXE_SHIFT)
/**
 * @brief DSI PCR CRCRXE field
 *
 * CRC reception enable This bit enables the CRC reception and error reporting.
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: read-write
 */
#define DSI_PCR_CRCRXE (1UL << 0x4UL)
#define DSI_PCR_CRCRXE_SHIFT 0x4UL
#define DSI_PCR_CRCRXE_MASK (((1ULL << 1) - 1) << DSI_PCR_CRCRXE_SHIFT)
/**
 * @brief DSI PCR ETTXLPE field
 *
 * EoTp transmission in low-power enable This bit enables the EoTP transmission in low-power.
 *
 * @note offset: 0x5UL
 *       width:  1
 *       access: read-write
 */
#define DSI_PCR_ETTXLPE (1UL << 0x5UL)
#define DSI_PCR_ETTXLPE_SHIFT 0x5UL
#define DSI_PCR_ETTXLPE_MASK (((1ULL << 1) - 1) << DSI_PCR_ETTXLPE_SHIFT)


struct dsi_pcr {
    uint32_t ettxe:1;
    uint32_t etrxe:1;
    uint32_t btae:1;
    uint32_t eccrxe:1;
    uint32_t crcrxe:1;
    uint32_t ettxlpe:1;
    };

typedef struct dsi_pcr dsi_pcr_t;
static_assert(sizeof(dsi_pcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI GVCIDR register
 *
 * DSI Host generic VCID register
 *
 *  @note offset: 0x30UL
 *        width:  32 bits
 */
#define DSI_GVCIDR_REG  0x30UL

/**
 * @brief DSI GVCIDR VCIDRX field
 *
 * Virtual channel ID for reception This field indicates the generic interface read-back virtual channel identification.
 *
 * @note offset: 0x0UL
 *       width:  2
 *       access: read-write
 */
#define DSI_GVCIDR_VCIDRX_SHIFT 0x0UL
#define DSI_GVCIDR_VCIDRX_MASK (((1ULL << 2) - 1) << DSI_GVCIDR_VCIDRX_SHIFT)
/**
 * @brief DSI GVCIDR VCIDTX field
 *
 * Virtual channel ID for transmission This field indicates the generic interface virtual channel identification where the generic packet is automatically generated and transmitted.
 *
 * @note offset: 0x10UL
 *       width:  2
 *       access: read-write
 */
#define DSI_GVCIDR_VCIDTX_SHIFT 0x10UL
#define DSI_GVCIDR_VCIDTX_MASK (((1ULL << 2) - 1) << DSI_GVCIDR_VCIDTX_SHIFT)


struct dsi_gvcidr {
    uint32_t vcidrx:2;
    uint32_t reserved0:14;
    uint32_t vcidtx:2;
    };

typedef struct dsi_gvcidr dsi_gvcidr_t;
static_assert(sizeof(dsi_gvcidr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI MCR register
 *
 * DSI Host mode configuration register
 *
 *  @note offset: 0x34UL
 *        width:  32 bits
 */
#define DSI_MCR_REG  0x34UL

/**
 * @brief DSI MCR CMDM field
 *
 * Command mode This bit configures the DSI Host in either video or command mode.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_MCR_CMDM (1UL << 0x0UL)
#define DSI_MCR_CMDM_SHIFT 0x0UL
#define DSI_MCR_CMDM_MASK (((1ULL << 1) - 1) << DSI_MCR_CMDM_SHIFT)


struct dsi_mcr {
    uint32_t cmdm:1;
    };

typedef struct dsi_mcr dsi_mcr_t;
static_assert(sizeof(dsi_mcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VMCR register
 *
 * DSI Host video mode configuration register
 *
 *  @note offset: 0x38UL
 *        width:  32 bits
 */
#define DSI_VMCR_REG  0x38UL

/**
 * @brief DSI VMCR VMT field
 *
 * Video mode type This field configures the video mode transmission type : 1x: Burst mode
 *
 * @note offset: 0x0UL
 *       width:  2
 *       access: read-write
 */
#define DSI_VMCR_VMT_SHIFT 0x0UL
#define DSI_VMCR_VMT_MASK (((1ULL << 2) - 1) << DSI_VMCR_VMT_SHIFT)
/**
 * @brief DSI VMCR LPVSAE field
 *
 * Low-power vertical sync active enable This bit enables to return to low-power inside the vertical sync time (VSA) period when timing allows.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-write
 */
#define DSI_VMCR_LPVSAE (1UL << 0x8UL)
#define DSI_VMCR_LPVSAE_SHIFT 0x8UL
#define DSI_VMCR_LPVSAE_MASK (((1ULL << 1) - 1) << DSI_VMCR_LPVSAE_SHIFT)
/**
 * @brief DSI VMCR LPVBPE field
 *
 * Low-power vertical back-porch enable This bit enables to return to low-power inside the vertical back-porch (VBP) period when timing allows.
 *
 * @note offset: 0x9UL
 *       width:  1
 *       access: read-write
 */
#define DSI_VMCR_LPVBPE (1UL << 0x9UL)
#define DSI_VMCR_LPVBPE_SHIFT 0x9UL
#define DSI_VMCR_LPVBPE_MASK (((1ULL << 1) - 1) << DSI_VMCR_LPVBPE_SHIFT)
/**
 * @brief DSI VMCR LPVFPE field
 *
 * Low-power vertical front-porch enable This bit enables to return to low-power inside the vertical front-porch (VFP) period when timing allows.
 *
 * @note offset: 0xaUL
 *       width:  1
 *       access: read-write
 */
#define DSI_VMCR_LPVFPE (1UL << 0xaUL)
#define DSI_VMCR_LPVFPE_SHIFT 0xaUL
#define DSI_VMCR_LPVFPE_MASK (((1ULL << 1) - 1) << DSI_VMCR_LPVFPE_SHIFT)
/**
 * @brief DSI VMCR LPVAE field
 *
 * Low-power vertical active enable This bit enables to return to low-power inside the vertical active (VACT) period when timing allows.
 *
 * @note offset: 0xbUL
 *       width:  1
 *       access: read-write
 */
#define DSI_VMCR_LPVAE (1UL << 0xbUL)
#define DSI_VMCR_LPVAE_SHIFT 0xbUL
#define DSI_VMCR_LPVAE_MASK (((1ULL << 1) - 1) << DSI_VMCR_LPVAE_SHIFT)
/**
 * @brief DSI VMCR LPHBPE field
 *
 * Low-power horizontal back-porch enable This bit enables the return to low-power inside the horizontal back-porch (HBP) period when timing allows.
 *
 * @note offset: 0xcUL
 *       width:  1
 *       access: read-write
 */
#define DSI_VMCR_LPHBPE (1UL << 0xcUL)
#define DSI_VMCR_LPHBPE_SHIFT 0xcUL
#define DSI_VMCR_LPHBPE_MASK (((1ULL << 1) - 1) << DSI_VMCR_LPHBPE_SHIFT)
/**
 * @brief DSI VMCR LPHFPE field
 *
 * Low-power horizontal front-porch enable This bit enables the return to low-power inside the horizontal front-porch (HFP) period when timing allows.
 *
 * @note offset: 0xdUL
 *       width:  1
 *       access: read-write
 */
#define DSI_VMCR_LPHFPE (1UL << 0xdUL)
#define DSI_VMCR_LPHFPE_SHIFT 0xdUL
#define DSI_VMCR_LPHFPE_MASK (((1ULL << 1) - 1) << DSI_VMCR_LPHFPE_SHIFT)
/**
 * @brief DSI VMCR FBTAAE field
 *
 * Frame bus-turn-around acknowledge enable This bit enables the request for an acknowledge response at the end of a frame.
 *
 * @note offset: 0xeUL
 *       width:  1
 *       access: read-write
 */
#define DSI_VMCR_FBTAAE (1UL << 0xeUL)
#define DSI_VMCR_FBTAAE_SHIFT 0xeUL
#define DSI_VMCR_FBTAAE_MASK (((1ULL << 1) - 1) << DSI_VMCR_FBTAAE_SHIFT)
/**
 * @brief DSI VMCR LPCE field
 *
 * Low-power command enable This bit enables the command transmission only in low-power mode.
 *
 * @note offset: 0xfUL
 *       width:  1
 *       access: read-write
 */
#define DSI_VMCR_LPCE (1UL << 0xfUL)
#define DSI_VMCR_LPCE_SHIFT 0xfUL
#define DSI_VMCR_LPCE_MASK (((1ULL << 1) - 1) << DSI_VMCR_LPCE_SHIFT)
/**
 * @brief DSI VMCR PGE field
 *
 * Pattern generator enable This bit enables the video mode pattern generator.
 *
 * @note offset: 0x10UL
 *       width:  1
 *       access: read-write
 */
#define DSI_VMCR_PGE (1UL << 0x10UL)
#define DSI_VMCR_PGE_SHIFT 0x10UL
#define DSI_VMCR_PGE_MASK (((1ULL << 1) - 1) << DSI_VMCR_PGE_SHIFT)
/**
 * @brief DSI VMCR PGM field
 *
 * Pattern generator mode This bit configures the pattern generator mode.
 *
 * @note offset: 0x14UL
 *       width:  1
 *       access: read-write
 */
#define DSI_VMCR_PGM (1UL << 0x14UL)
#define DSI_VMCR_PGM_SHIFT 0x14UL
#define DSI_VMCR_PGM_MASK (((1ULL << 1) - 1) << DSI_VMCR_PGM_SHIFT)
/**
 * @brief DSI VMCR PGO field
 *
 * Pattern generator orientation This bit configures the color bar orientation.
 *
 * @note offset: 0x18UL
 *       width:  1
 *       access: read-write
 */
#define DSI_VMCR_PGO (1UL << 0x18UL)
#define DSI_VMCR_PGO_SHIFT 0x18UL
#define DSI_VMCR_PGO_MASK (((1ULL << 1) - 1) << DSI_VMCR_PGO_SHIFT)


struct dsi_vmcr {
    uint32_t vmt:2;
    uint32_t reserved0:6;
    uint32_t lpvsae:1;
    uint32_t lpvbpe:1;
    uint32_t lpvfpe:1;
    uint32_t lpvae:1;
    uint32_t lphbpe:1;
    uint32_t lphfpe:1;
    uint32_t fbtaae:1;
    uint32_t lpce:1;
    uint32_t pge:1;
    uint32_t reserved1:3;
    uint32_t pgm:1;
    uint32_t reserved2:3;
    uint32_t pgo:1;
    };

typedef struct dsi_vmcr dsi_vmcr_t;
static_assert(sizeof(dsi_vmcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VPCR register
 *
 * DSI Host video packet configuration register
 *
 *  @note offset: 0x3cUL
 *        width:  32 bits
 */
#define DSI_VPCR_REG  0x3cUL

/**
 * @brief DSI VPCR VPSIZE field
 *
 * Video packet size This field configures the number of pixels in a single video packet. For 18-bit not loosely packed data types, this number must be a multiple of 4. For YCbCr data types, it must be a multiple of 2 as described in the DSI specification.
 *
 * @note offset: 0x0UL
 *       width:  14
 *       access: read-write
 */
#define DSI_VPCR_VPSIZE_SHIFT 0x0UL
#define DSI_VPCR_VPSIZE_MASK (((1ULL << 14) - 1) << DSI_VPCR_VPSIZE_SHIFT)


struct dsi_vpcr {
    uint32_t vpsize:14;
    };

typedef struct dsi_vpcr dsi_vpcr_t;
static_assert(sizeof(dsi_vpcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VCCR register
 *
 * DSI Host video chunks configuration register
 *
 *  @note offset: 0x40UL
 *        width:  32 bits
 */
#define DSI_VCCR_REG  0x40UL

/**
 * @brief DSI VCCR NUMC field
 *
 * Number of chunks This register configures the number of chunks to be transmitted during a line period (a chunk consists of a video packet and a null packet). If set to 0 or 1, the video line is transmitted in a single packet. If set to 1, the packet is part of a chunk, so a null packet follows it if NPSIZE > 0. Otherwise, multiple chunks are used to transmit each video line.
 *
 * @note offset: 0x0UL
 *       width:  13
 *       access: read-write
 */
#define DSI_VCCR_NUMC_SHIFT 0x0UL
#define DSI_VCCR_NUMC_MASK (((1ULL << 13) - 1) << DSI_VCCR_NUMC_SHIFT)


struct dsi_vccr {
    uint32_t numc:13;
    };

typedef struct dsi_vccr dsi_vccr_t;
static_assert(sizeof(dsi_vccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VNPCR register
 *
 * DSI Host video null packet configuration register
 *
 *  @note offset: 0x44UL
 *        width:  32 bits
 */
#define DSI_VNPCR_REG  0x44UL

/**
 * @brief DSI VNPCR NPSIZE field
 *
 * Null packet size This field configures the number of bytes inside a null packet. Setting to 0 disables the null packets.
 *
 * @note offset: 0x0UL
 *       width:  13
 *       access: read-write
 */
#define DSI_VNPCR_NPSIZE_SHIFT 0x0UL
#define DSI_VNPCR_NPSIZE_MASK (((1ULL << 13) - 1) << DSI_VNPCR_NPSIZE_SHIFT)


struct dsi_vnpcr {
    uint32_t npsize:13;
    };

typedef struct dsi_vnpcr dsi_vnpcr_t;
static_assert(sizeof(dsi_vnpcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VHSACR register
 *
 * DSI Host video HSA configuration register
 *
 *  @note offset: 0x48UL
 *        width:  32 bits
 */
#define DSI_VHSACR_REG  0x48UL

/**
 * @brief DSI VHSACR HSA field
 *
 * Horizontal synchronism active duration This fields configures the horizontal synchronism active period in lane byte clock cycles.
 *
 * @note offset: 0x0UL
 *       width:  12
 *       access: read-write
 */
#define DSI_VHSACR_HSA_SHIFT 0x0UL
#define DSI_VHSACR_HSA_MASK (((1ULL << 12) - 1) << DSI_VHSACR_HSA_SHIFT)


struct dsi_vhsacr {
    uint32_t hsa:12;
    };

typedef struct dsi_vhsacr dsi_vhsacr_t;
static_assert(sizeof(dsi_vhsacr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VHBPCR register
 *
 * DSI Host video HBP configuration register
 *
 *  @note offset: 0x4cUL
 *        width:  32 bits
 */
#define DSI_VHBPCR_REG  0x4cUL

/**
 * @brief DSI VHBPCR HBP field
 *
 * Horizontal back-porch duration This fields configures the horizontal back-porch period in lane byte clock cycles.
 *
 * @note offset: 0x0UL
 *       width:  12
 *       access: read-write
 */
#define DSI_VHBPCR_HBP_SHIFT 0x0UL
#define DSI_VHBPCR_HBP_MASK (((1ULL << 12) - 1) << DSI_VHBPCR_HBP_SHIFT)


struct dsi_vhbpcr {
    uint32_t hbp:12;
    };

typedef struct dsi_vhbpcr dsi_vhbpcr_t;
static_assert(sizeof(dsi_vhbpcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VLCR register
 *
 * DSI Host video line configuration register
 *
 *  @note offset: 0x50UL
 *        width:  32 bits
 */
#define DSI_VLCR_REG  0x50UL

/**
 * @brief DSI VLCR HLINE field
 *
 * Horizontal line duration This fields configures the total of the horizontal line period (HSA+HBP+HACT+HFP) counted in lane byte clock cycles.
 *
 * @note offset: 0x0UL
 *       width:  15
 *       access: read-write
 */
#define DSI_VLCR_HLINE_SHIFT 0x0UL
#define DSI_VLCR_HLINE_MASK (((1ULL << 15) - 1) << DSI_VLCR_HLINE_SHIFT)


struct dsi_vlcr {
    uint32_t hline:15;
    };

typedef struct dsi_vlcr dsi_vlcr_t;
static_assert(sizeof(dsi_vlcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VVSACR register
 *
 * DSI Host video VSA configuration register
 *
 *  @note offset: 0x54UL
 *        width:  32 bits
 */
#define DSI_VVSACR_REG  0x54UL

/**
 * @brief DSI VVSACR VSA field
 *
 * Vertical synchronism active duration This fields configures the vertical synchronism active period measured in number of horizontal lines.
 *
 * @note offset: 0x0UL
 *       width:  10
 *       access: read-write
 */
#define DSI_VVSACR_VSA_SHIFT 0x0UL
#define DSI_VVSACR_VSA_MASK (((1ULL << 10) - 1) << DSI_VVSACR_VSA_SHIFT)


struct dsi_vvsacr {
    uint32_t vsa:10;
    };

typedef struct dsi_vvsacr dsi_vvsacr_t;
static_assert(sizeof(dsi_vvsacr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VVBPCR register
 *
 * DSI Host video VBP configuration register
 *
 *  @note offset: 0x58UL
 *        width:  32 bits
 */
#define DSI_VVBPCR_REG  0x58UL

/**
 * @brief DSI VVBPCR VBP field
 *
 * Vertical back-porch duration This fields configures the vertical back-porch period measured in number of horizontal lines.
 *
 * @note offset: 0x0UL
 *       width:  10
 *       access: read-write
 */
#define DSI_VVBPCR_VBP_SHIFT 0x0UL
#define DSI_VVBPCR_VBP_MASK (((1ULL << 10) - 1) << DSI_VVBPCR_VBP_SHIFT)


struct dsi_vvbpcr {
    uint32_t vbp:10;
    };

typedef struct dsi_vvbpcr dsi_vvbpcr_t;
static_assert(sizeof(dsi_vvbpcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VVFPCR register
 *
 * DSI Host video VFP configuration register
 *
 *  @note offset: 0x5cUL
 *        width:  32 bits
 */
#define DSI_VVFPCR_REG  0x5cUL

/**
 * @brief DSI VVFPCR VFP field
 *
 * Vertical front-porch duration This fields configures the vertical front-porch period measured in number of horizontal lines.
 *
 * @note offset: 0x0UL
 *       width:  10
 *       access: read-write
 */
#define DSI_VVFPCR_VFP_SHIFT 0x0UL
#define DSI_VVFPCR_VFP_MASK (((1ULL << 10) - 1) << DSI_VVFPCR_VFP_SHIFT)


struct dsi_vvfpcr {
    uint32_t vfp:10;
    };

typedef struct dsi_vvfpcr dsi_vvfpcr_t;
static_assert(sizeof(dsi_vvfpcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VVACR register
 *
 * DSI Host video VA configuration register
 *
 *  @note offset: 0x60UL
 *        width:  32 bits
 */
#define DSI_VVACR_REG  0x60UL

/**
 * @brief DSI VVACR VA field
 *
 * Vertical active duration This fields configures the vertical active period measured in number of horizontal lines.
 *
 * @note offset: 0x0UL
 *       width:  14
 *       access: read-write
 */
#define DSI_VVACR_VA_SHIFT 0x0UL
#define DSI_VVACR_VA_MASK (((1ULL << 14) - 1) << DSI_VVACR_VA_SHIFT)


struct dsi_vvacr {
    uint32_t va:14;
    };

typedef struct dsi_vvacr dsi_vvacr_t;
static_assert(sizeof(dsi_vvacr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI LCCR register
 *
 * DSI Host LTDC command configuration register
 *
 *  @note offset: 0x64UL
 *        width:  32 bits
 */
#define DSI_LCCR_REG  0x64UL

/**
 * @brief DSI LCCR CMDSIZE field
 *
 * Command size This field configures the maximum allowed size for an LTDC write memory command, measured in pixels. Automatic partitioning of data obtained from LTDC is permanently enabled.
 *
 * @note offset: 0x0UL
 *       width:  16
 *       access: read-write
 */
#define DSI_LCCR_CMDSIZE_SHIFT 0x0UL
#define DSI_LCCR_CMDSIZE_MASK (((1ULL << 16) - 1) << DSI_LCCR_CMDSIZE_SHIFT)


struct dsi_lccr {
    uint32_t cmdsize:16;
    };

typedef struct dsi_lccr dsi_lccr_t;
static_assert(sizeof(dsi_lccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI CMCR register
 *
 * DSI Host command mode configuration register
 *
 *  @note offset: 0x68UL
 *        width:  32 bits
 */
#define DSI_CMCR_REG  0x68UL

/**
 * @brief DSI CMCR TEARE field
 *
 * Tearing effect acknowledge request enable This bit enables the tearing effect acknowledge request:
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_TEARE (1UL << 0x0UL)
#define DSI_CMCR_TEARE_SHIFT 0x0UL
#define DSI_CMCR_TEARE_MASK (((1ULL << 1) - 1) << DSI_CMCR_TEARE_SHIFT)
/**
 * @brief DSI CMCR ARE field
 *
 * Acknowledge request enable This bit enables the acknowledge request after each packet transmission:
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_ARE (1UL << 0x1UL)
#define DSI_CMCR_ARE_SHIFT 0x1UL
#define DSI_CMCR_ARE_MASK (((1ULL << 1) - 1) << DSI_CMCR_ARE_SHIFT)
/**
 * @brief DSI CMCR GSW0TX field
 *
 * Generic short write zero parameters transmission This bit configures the generic short write packet with zero parameters command transmission type:
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_GSW0TX (1UL << 0x8UL)
#define DSI_CMCR_GSW0TX_SHIFT 0x8UL
#define DSI_CMCR_GSW0TX_MASK (((1ULL << 1) - 1) << DSI_CMCR_GSW0TX_SHIFT)
/**
 * @brief DSI CMCR GSW1TX field
 *
 * Generic short write one parameters transmission This bit configures the generic short write packet with one parameters command transmission type:
 *
 * @note offset: 0x9UL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_GSW1TX (1UL << 0x9UL)
#define DSI_CMCR_GSW1TX_SHIFT 0x9UL
#define DSI_CMCR_GSW1TX_MASK (((1ULL << 1) - 1) << DSI_CMCR_GSW1TX_SHIFT)
/**
 * @brief DSI CMCR GSW2TX field
 *
 * Generic short write two parameters transmission This bit configures the generic short write packet with two parameters command transmission type:
 *
 * @note offset: 0xaUL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_GSW2TX (1UL << 0xaUL)
#define DSI_CMCR_GSW2TX_SHIFT 0xaUL
#define DSI_CMCR_GSW2TX_MASK (((1ULL << 1) - 1) << DSI_CMCR_GSW2TX_SHIFT)
/**
 * @brief DSI CMCR GSR0TX field
 *
 * Generic short read zero parameters transmission This bit configures the generic short read packet with zero parameters command transmission type:
 *
 * @note offset: 0xbUL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_GSR0TX (1UL << 0xbUL)
#define DSI_CMCR_GSR0TX_SHIFT 0xbUL
#define DSI_CMCR_GSR0TX_MASK (((1ULL << 1) - 1) << DSI_CMCR_GSR0TX_SHIFT)
/**
 * @brief DSI CMCR GSR1TX field
 *
 * Generic short read one parameters transmission This bit configures the generic short read packet with one parameters command transmission type:
 *
 * @note offset: 0xcUL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_GSR1TX (1UL << 0xcUL)
#define DSI_CMCR_GSR1TX_SHIFT 0xcUL
#define DSI_CMCR_GSR1TX_MASK (((1ULL << 1) - 1) << DSI_CMCR_GSR1TX_SHIFT)
/**
 * @brief DSI CMCR GSR2TX field
 *
 * Generic short read two parameters transmission This bit configures the generic short read packet with two parameters command transmission type:
 *
 * @note offset: 0xdUL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_GSR2TX (1UL << 0xdUL)
#define DSI_CMCR_GSR2TX_SHIFT 0xdUL
#define DSI_CMCR_GSR2TX_MASK (((1ULL << 1) - 1) << DSI_CMCR_GSR2TX_SHIFT)
/**
 * @brief DSI CMCR GLWTX field
 *
 * Generic long write transmission This bit configures the generic long write packet command transmission type :
 *
 * @note offset: 0xeUL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_GLWTX (1UL << 0xeUL)
#define DSI_CMCR_GLWTX_SHIFT 0xeUL
#define DSI_CMCR_GLWTX_MASK (((1ULL << 1) - 1) << DSI_CMCR_GLWTX_SHIFT)
/**
 * @brief DSI CMCR DSW0TX field
 *
 * DCS short write zero parameter transmission This bit configures the DCS short write packet with zero parameter command transmission type:
 *
 * @note offset: 0x10UL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_DSW0TX (1UL << 0x10UL)
#define DSI_CMCR_DSW0TX_SHIFT 0x10UL
#define DSI_CMCR_DSW0TX_MASK (((1ULL << 1) - 1) << DSI_CMCR_DSW0TX_SHIFT)
/**
 * @brief DSI CMCR DSW1TX field
 *
 * DCS short read one parameter transmission This bit configures the DCS short read packet with one parameter command transmission type:
 *
 * @note offset: 0x11UL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_DSW1TX (1UL << 0x11UL)
#define DSI_CMCR_DSW1TX_SHIFT 0x11UL
#define DSI_CMCR_DSW1TX_MASK (((1ULL << 1) - 1) << DSI_CMCR_DSW1TX_SHIFT)
/**
 * @brief DSI CMCR DSR0TX field
 *
 * DCS short read zero parameter transmission This bit configures the DCS short read packet with zero parameter command transmission type:
 *
 * @note offset: 0x12UL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_DSR0TX (1UL << 0x12UL)
#define DSI_CMCR_DSR0TX_SHIFT 0x12UL
#define DSI_CMCR_DSR0TX_MASK (((1ULL << 1) - 1) << DSI_CMCR_DSR0TX_SHIFT)
/**
 * @brief DSI CMCR DLWTX field
 *
 * DCS long write transmission This bit configures the DCS long write packet command transmission type:
 *
 * @note offset: 0x13UL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_DLWTX (1UL << 0x13UL)
#define DSI_CMCR_DLWTX_SHIFT 0x13UL
#define DSI_CMCR_DLWTX_MASK (((1ULL << 1) - 1) << DSI_CMCR_DLWTX_SHIFT)
/**
 * @brief DSI CMCR MRDPS field
 *
 * Maximum read packet size This bit configures the maximum read packet size command transmission type:
 *
 * @note offset: 0x18UL
 *       width:  1
 *       access: read-write
 */
#define DSI_CMCR_MRDPS (1UL << 0x18UL)
#define DSI_CMCR_MRDPS_SHIFT 0x18UL
#define DSI_CMCR_MRDPS_MASK (((1ULL << 1) - 1) << DSI_CMCR_MRDPS_SHIFT)


struct dsi_cmcr {
    uint32_t teare:1;
    uint32_t are:1;
    uint32_t reserved0:6;
    uint32_t gsw0tx:1;
    uint32_t gsw1tx:1;
    uint32_t gsw2tx:1;
    uint32_t gsr0tx:1;
    uint32_t gsr1tx:1;
    uint32_t gsr2tx:1;
    uint32_t glwtx:1;
    uint32_t reserved1:1;
    uint32_t dsw0tx:1;
    uint32_t dsw1tx:1;
    uint32_t dsr0tx:1;
    uint32_t dlwtx:1;
    uint32_t reserved2:4;
    uint32_t mrdps:1;
    };

typedef struct dsi_cmcr dsi_cmcr_t;
static_assert(sizeof(dsi_cmcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI GHCR register
 *
 * DSI Host generic header configuration register
 *
 *  @note offset: 0x6cUL
 *        width:  32 bits
 */
#define DSI_GHCR_REG  0x6cUL

/**
 * @brief DSI GHCR DT field
 *
 * Type This field configures the packet data type of the header packet.
 *
 * @note offset: 0x0UL
 *       width:  6
 *       access: read-write
 */
#define DSI_GHCR_DT_SHIFT 0x0UL
#define DSI_GHCR_DT_MASK (((1ULL << 6) - 1) << DSI_GHCR_DT_SHIFT)
/**
 * @brief DSI GHCR VCID field
 *
 * Channel This field configures the virtual channel ID of the header packet.
 *
 * @note offset: 0x6UL
 *       width:  2
 *       access: read-write
 */
#define DSI_GHCR_VCID_SHIFT 0x6UL
#define DSI_GHCR_VCID_MASK (((1ULL << 2) - 1) << DSI_GHCR_VCID_SHIFT)
/**
 * @brief DSI GHCR WCLSB field
 *
 * WordCount LSB This field configures the less significant byte of the header packet word count for long packets, or data 0 for short packets.
 *
 * @note offset: 0x8UL
 *       width:  8
 *       access: read-write
 */
#define DSI_GHCR_WCLSB_SHIFT 0x8UL
#define DSI_GHCR_WCLSB_MASK (((1ULL << 8) - 1) << DSI_GHCR_WCLSB_SHIFT)
/**
 * @brief DSI GHCR WCMSB field
 *
 * WordCount MSB This field configures the most significant byte of the header packet's word count for long packets, or data 1 for short packets.
 *
 * @note offset: 0x10UL
 *       width:  8
 *       access: read-write
 */
#define DSI_GHCR_WCMSB_SHIFT 0x10UL
#define DSI_GHCR_WCMSB_MASK (((1ULL << 8) - 1) << DSI_GHCR_WCMSB_SHIFT)


struct dsi_ghcr {
    uint32_t dt:6;
    uint32_t vcid:2;
    uint32_t wclsb:8;
    uint32_t wcmsb:8;
    };

typedef struct dsi_ghcr dsi_ghcr_t;
static_assert(sizeof(dsi_ghcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI GPDR register
 *
 * DSI Host generic payload data register
 *
 *  @note offset: 0x70UL
 *        width:  32 bits
 */
#define DSI_GPDR_REG  0x70UL

/**
 * @brief DSI GPDR DATA1 field
 *
 * Payload byte 1 This field indicates the byte 1 of the packet payload.
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define DSI_GPDR_DATA1_SHIFT 0x0UL
#define DSI_GPDR_DATA1_MASK (((1ULL << 8) - 1) << DSI_GPDR_DATA1_SHIFT)
/**
 * @brief DSI GPDR DATA2 field
 *
 * Payload byte 2 This field indicates the byte 2 of the packet payload.
 *
 * @note offset: 0x8UL
 *       width:  8
 *       access: read-write
 */
#define DSI_GPDR_DATA2_SHIFT 0x8UL
#define DSI_GPDR_DATA2_MASK (((1ULL << 8) - 1) << DSI_GPDR_DATA2_SHIFT)
/**
 * @brief DSI GPDR DATA3 field
 *
 * Payload byte 3 This field indicates the byte 3 of the packet payload.
 *
 * @note offset: 0x10UL
 *       width:  8
 *       access: read-write
 */
#define DSI_GPDR_DATA3_SHIFT 0x10UL
#define DSI_GPDR_DATA3_MASK (((1ULL << 8) - 1) << DSI_GPDR_DATA3_SHIFT)
/**
 * @brief DSI GPDR DATA4 field
 *
 * Payload byte 4 This field indicates the byte 4 of the packet payload.
 *
 * @note offset: 0x18UL
 *       width:  8
 *       access: read-write
 */
#define DSI_GPDR_DATA4_SHIFT 0x18UL
#define DSI_GPDR_DATA4_MASK (((1ULL << 8) - 1) << DSI_GPDR_DATA4_SHIFT)


struct dsi_gpdr {
    uint32_t data1:8;
    uint32_t data2:8;
    uint32_t data3:8;
    uint32_t data4:8;
    };

typedef struct dsi_gpdr dsi_gpdr_t;
static_assert(sizeof(dsi_gpdr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI GPSR register
 *
 * DSI Host generic packet status register
 *
 *  @note offset: 0x74UL
 *        width:  32 bits
 */
#define DSI_GPSR_REG  0x74UL

/**
 * @brief DSI GPSR CMDFE field
 *
 * Command FIFO empty This bit indicates the empty status of the generic command FIFO:
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-only
 */
#define DSI_GPSR_CMDFE (1UL << 0x0UL)
#define DSI_GPSR_CMDFE_SHIFT 0x0UL
#define DSI_GPSR_CMDFE_MASK (((1ULL << 1) - 1) << DSI_GPSR_CMDFE_SHIFT)
/**
 * @brief DSI GPSR CMDFF field
 *
 * Command FIFO full This bit indicates the full status of the generic command FIFO:
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-only
 */
#define DSI_GPSR_CMDFF (1UL << 0x1UL)
#define DSI_GPSR_CMDFF_SHIFT 0x1UL
#define DSI_GPSR_CMDFF_MASK (((1ULL << 1) - 1) << DSI_GPSR_CMDFF_SHIFT)
/**
 * @brief DSI GPSR PWRFE field
 *
 * Payload write FIFO empty This bit indicates the empty status of the generic write payload FIFO:
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-only
 */
#define DSI_GPSR_PWRFE (1UL << 0x2UL)
#define DSI_GPSR_PWRFE_SHIFT 0x2UL
#define DSI_GPSR_PWRFE_MASK (((1ULL << 1) - 1) << DSI_GPSR_PWRFE_SHIFT)
/**
 * @brief DSI GPSR PWRFF field
 *
 * Payload write FIFO full This bit indicates the full status of the generic write payload FIFO:
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-only
 */
#define DSI_GPSR_PWRFF (1UL << 0x3UL)
#define DSI_GPSR_PWRFF_SHIFT 0x3UL
#define DSI_GPSR_PWRFF_MASK (((1ULL << 1) - 1) << DSI_GPSR_PWRFF_SHIFT)
/**
 * @brief DSI GPSR PRDFE field
 *
 * Payload read FIFO empty This bit indicates the empty status of the generic read payload FIFO:
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: read-only
 */
#define DSI_GPSR_PRDFE (1UL << 0x4UL)
#define DSI_GPSR_PRDFE_SHIFT 0x4UL
#define DSI_GPSR_PRDFE_MASK (((1ULL << 1) - 1) << DSI_GPSR_PRDFE_SHIFT)
/**
 * @brief DSI GPSR PRDFF field
 *
 * Payload read FIFO full This bit indicates the full status of the generic read payload FIFO:
 *
 * @note offset: 0x5UL
 *       width:  1
 *       access: read-only
 */
#define DSI_GPSR_PRDFF (1UL << 0x5UL)
#define DSI_GPSR_PRDFF_SHIFT 0x5UL
#define DSI_GPSR_PRDFF_MASK (((1ULL << 1) - 1) << DSI_GPSR_PRDFF_SHIFT)
/**
 * @brief DSI GPSR RCB field
 *
 * Read command busy This bit is set when a read command is issued and cleared when the entire response is stored in the FIFO:
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: read-only
 */
#define DSI_GPSR_RCB (1UL << 0x6UL)
#define DSI_GPSR_RCB_SHIFT 0x6UL
#define DSI_GPSR_RCB_MASK (((1ULL << 1) - 1) << DSI_GPSR_RCB_SHIFT)
/**
 * @brief DSI GPSR CMDBE field
 *
 * Command buffer empty This bit indicates the empty status of the generic payload internal buffer:
 *
 * @note offset: 0x10UL
 *       width:  1
 *       access: read-only
 */
#define DSI_GPSR_CMDBE (1UL << 0x10UL)
#define DSI_GPSR_CMDBE_SHIFT 0x10UL
#define DSI_GPSR_CMDBE_MASK (((1ULL << 1) - 1) << DSI_GPSR_CMDBE_SHIFT)
/**
 * @brief DSI GPSR CMDBF field
 *
 * Command buffer full This bit indicates the full status of the generic command internal buffer:
 *
 * @note offset: 0x11UL
 *       width:  1
 *       access: read-only
 */
#define DSI_GPSR_CMDBF (1UL << 0x11UL)
#define DSI_GPSR_CMDBF_SHIFT 0x11UL
#define DSI_GPSR_CMDBF_MASK (((1ULL << 1) - 1) << DSI_GPSR_CMDBF_SHIFT)
/**
 * @brief DSI GPSR PBE field
 *
 * Payload buffer empty This bit indicates the empty status of the generic payload internal buffer:
 *
 * @note offset: 0x12UL
 *       width:  1
 *       access: read-only
 */
#define DSI_GPSR_PBE (1UL << 0x12UL)
#define DSI_GPSR_PBE_SHIFT 0x12UL
#define DSI_GPSR_PBE_MASK (((1ULL << 1) - 1) << DSI_GPSR_PBE_SHIFT)
/**
 * @brief DSI GPSR PBF field
 *
 * Payload buffer full This bit indicates the full status of the generic payload internal buffer:
 *
 * @note offset: 0x13UL
 *       width:  1
 *       access: read-only
 */
#define DSI_GPSR_PBF (1UL << 0x13UL)
#define DSI_GPSR_PBF_SHIFT 0x13UL
#define DSI_GPSR_PBF_MASK (((1ULL << 1) - 1) << DSI_GPSR_PBF_SHIFT)


struct dsi_gpsr {
    uint32_t cmdfe:1;
    uint32_t cmdff:1;
    uint32_t pwrfe:1;
    uint32_t pwrff:1;
    uint32_t prdfe:1;
    uint32_t prdff:1;
    uint32_t rcb:1;
    uint32_t reserved0:9;
    uint32_t cmdbe:1;
    uint32_t cmdbf:1;
    uint32_t pbe:1;
    uint32_t pbf:1;
    };

typedef struct dsi_gpsr dsi_gpsr_t;
static_assert(sizeof(dsi_gpsr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI TCCR0 register
 *
 * DSI Host timeout counter configuration register 0
 *
 *  @note offset: 0x78UL
 *        width:  32 bits
 */
#define DSI_TCCR0_REG  0x78UL

/**
 * @brief DSI TCCR0 LPRX_TOCNT field
 *
 * Low-power reception timeout counter This field configures the timeout counter that triggers a low-power reception timeout contention detection (measured in TOCKDIV cycles).
 *
 * @note offset: 0x0UL
 *       width:  16
 *       access: read-write
 */
#define DSI_TCCR0_LPRX_TOCNT_SHIFT 0x0UL
#define DSI_TCCR0_LPRX_TOCNT_MASK (((1ULL << 16) - 1) << DSI_TCCR0_LPRX_TOCNT_SHIFT)
/**
 * @brief DSI TCCR0 HSTX_TOCNT field
 *
 * High-speed transmission timeout counter This field configures the timeout counter that triggers a high-speed transmission timeout contention detection (measured in TOCKDIV cycles). If using the non-burst mode and there is no enough time to switch from high-speed to low-power and back in the period from one line data finishing to the next line sync start, the DSI link returns the low-power state once per frame, then configure the TOCKDIV and HSTX_TOCNT to be in accordance with: HSTX_TOCNT * lanebyteclkperiod * TOCKDIV â¥ the time of one FRAME data transmission *Â (1 + 10%) In burst mode, RGB pixel packets are time-compressed, leaving more time during a scan line. Therefore, if in burst mode and there is enough time to switch from high-speed to low-power and back in the period from one line data finishing to the next line sync start, the DSI link can return low-power mode and back in this time interval to save power. For this, configure the TOCKDIV and HSTX_TOCNT to be in accordance with: HSTX_TOCNT * lanebyteclkperiod * TOCKDIV â¥ the time of one LINE data transmission *Â (1Â +Â 10%)
 *
 * @note offset: 0x10UL
 *       width:  16
 *       access: read-write
 */
#define DSI_TCCR0_HSTX_TOCNT_SHIFT 0x10UL
#define DSI_TCCR0_HSTX_TOCNT_MASK (((1ULL << 16) - 1) << DSI_TCCR0_HSTX_TOCNT_SHIFT)


struct dsi_tccr0 {
    uint32_t lprx_tocnt:16;
    uint32_t hstx_tocnt:16;
    };

typedef struct dsi_tccr0 dsi_tccr0_t;
static_assert(sizeof(dsi_tccr0_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI TCCR1 register
 *
 * DSI Host timeout counter configuration register 1
 *
 *  @note offset: 0x7cUL
 *        width:  32 bits
 */
#define DSI_TCCR1_REG  0x7cUL

/**
 * @brief DSI TCCR1 HSRD_TOCNT field
 *
 * High-speed read timeout counter This field sets a period for which the DSI Host keeps the link still, after sending a high-speed read operation. This period is measured in cycles of lanebyteclk. The counting starts when the D-PHY enters the Stop state and causes no interrupts.
 *
 * @note offset: 0x0UL
 *       width:  16
 *       access: read-write
 */
#define DSI_TCCR1_HSRD_TOCNT_SHIFT 0x0UL
#define DSI_TCCR1_HSRD_TOCNT_MASK (((1ULL << 16) - 1) << DSI_TCCR1_HSRD_TOCNT_SHIFT)


struct dsi_tccr1 {
    uint32_t hsrd_tocnt:16;
    };

typedef struct dsi_tccr1 dsi_tccr1_t;
static_assert(sizeof(dsi_tccr1_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI TCCR2 register
 *
 * DSI Host timeout counter configuration register 2
 *
 *  @note offset: 0x80UL
 *        width:  32 bits
 */
#define DSI_TCCR2_REG  0x80UL

/**
 * @brief DSI TCCR2 LPRD_TOCNT field
 *
 * Low-power read timeout counter This field sets a period for which the DSI Host keeps the link still, after sending a low-power read operation. This period is measured in cycles of lanebyteclk. The counting starts when the D-PHY enters the Stop state and causes no interrupts.
 *
 * @note offset: 0x0UL
 *       width:  16
 *       access: read-write
 */
#define DSI_TCCR2_LPRD_TOCNT_SHIFT 0x0UL
#define DSI_TCCR2_LPRD_TOCNT_MASK (((1ULL << 16) - 1) << DSI_TCCR2_LPRD_TOCNT_SHIFT)


struct dsi_tccr2 {
    uint32_t lprd_tocnt:16;
    };

typedef struct dsi_tccr2 dsi_tccr2_t;
static_assert(sizeof(dsi_tccr2_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI TCCR3 register
 *
 * DSI Host timeout counter configuration register 3
 *
 *  @note offset: 0x84UL
 *        width:  32 bits
 */
#define DSI_TCCR3_REG  0x84UL

/**
 * @brief DSI TCCR3 HSWR_TOCNT field
 *
 * High-speed write timeout counter This field sets a period for which the DSI Host keeps the link inactive after sending a high-speed write operation. This period is measured in cycles of lanebyteclk. The counting starts when the D-PHY enters the Stop state and causes no interrupts.
 *
 * @note offset: 0x0UL
 *       width:  16
 *       access: read-write
 */
#define DSI_TCCR3_HSWR_TOCNT_SHIFT 0x0UL
#define DSI_TCCR3_HSWR_TOCNT_MASK (((1ULL << 16) - 1) << DSI_TCCR3_HSWR_TOCNT_SHIFT)
/**
 * @brief DSI TCCR3 PM field
 *
 * Presp mode When set to 1, this bit ensures that the peripheral response timeout caused by HSWR_TOCNT is used only once per LTDC frame in command mode, when both the following conditions are met: dpivsync_edpiwms has risen and fallen. Packets originated from LTDC in command mode have been transmitted and its FIFO is empty again. In this scenario no non-LTDC command requests are sent to the D-PHY, even if there is traffic from generic interface ready to be sent, making it return to stop state. When it does so, PRESP_TO counter is activated and only when it finishes does the controller send any other traffic that is ready.
 *
 * @note offset: 0x18UL
 *       width:  1
 *       access: read-write
 */
#define DSI_TCCR3_PM (1UL << 0x18UL)
#define DSI_TCCR3_PM_SHIFT 0x18UL
#define DSI_TCCR3_PM_MASK (((1ULL << 1) - 1) << DSI_TCCR3_PM_SHIFT)


struct dsi_tccr3 {
    uint32_t hswr_tocnt:16;
    uint32_t reserved0:8;
    uint32_t pm:1;
    };

typedef struct dsi_tccr3 dsi_tccr3_t;
static_assert(sizeof(dsi_tccr3_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI TCCR4 register
 *
 * DSI Host timeout counter configuration register 4
 *
 *  @note offset: 0x88UL
 *        width:  32 bits
 */
#define DSI_TCCR4_REG  0x88UL

/**
 * @brief DSI TCCR4 LPWR_TOCNT field
 *
 * Low-power write timeout counter This field sets a period for which the DSI Host keeps the link still, after sending a low-power write operation. This period is measured in cycles of lanebyteclk. The counting starts when the D-PHY enters the Stop state and causes no interrupts.
 *
 * @note offset: 0x0UL
 *       width:  16
 *       access: read-write
 */
#define DSI_TCCR4_LPWR_TOCNT_SHIFT 0x0UL
#define DSI_TCCR4_LPWR_TOCNT_MASK (((1ULL << 16) - 1) << DSI_TCCR4_LPWR_TOCNT_SHIFT)


struct dsi_tccr4 {
    uint32_t lpwr_tocnt:16;
    };

typedef struct dsi_tccr4 dsi_tccr4_t;
static_assert(sizeof(dsi_tccr4_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI TCCR5 register
 *
 * DSI Host timeout counter configuration register 5
 *
 *  @note offset: 0x8cUL
 *        width:  32 bits
 */
#define DSI_TCCR5_REG  0x8cUL

/**
 * @brief DSI TCCR5 BTA_TOCNT field
 *
 * Bus-turn-around timeout counter This field sets a period for which the DSI Host keeps the link still, after completing a bus-turn-around. This period is measured in cycles of lanebyteclk. The counting starts when the DâPHY enters the Stop state and causes no interrupts.
 *
 * @note offset: 0x0UL
 *       width:  16
 *       access: read-write
 */
#define DSI_TCCR5_BTA_TOCNT_SHIFT 0x0UL
#define DSI_TCCR5_BTA_TOCNT_MASK (((1ULL << 16) - 1) << DSI_TCCR5_BTA_TOCNT_SHIFT)


struct dsi_tccr5 {
    uint32_t bta_tocnt:16;
    };

typedef struct dsi_tccr5 dsi_tccr5_t;
static_assert(sizeof(dsi_tccr5_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI CLCR register
 *
 * DSI Host clock lane configuration register
 *
 *  @note offset: 0x94UL
 *        width:  32 bits
 */
#define DSI_CLCR_REG  0x94UL

/**
 * @brief DSI CLCR DPCC field
 *
 * D-PHY clock control This bit controls the D-PHY clock state:
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_CLCR_DPCC (1UL << 0x0UL)
#define DSI_CLCR_DPCC_SHIFT 0x0UL
#define DSI_CLCR_DPCC_MASK (((1ULL << 1) - 1) << DSI_CLCR_DPCC_SHIFT)
/**
 * @brief DSI CLCR ACR field
 *
 * Automatic clock lane control This bit enables the automatic mechanism to stop providing clock in the clock lane when time allows.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define DSI_CLCR_ACR (1UL << 0x1UL)
#define DSI_CLCR_ACR_SHIFT 0x1UL
#define DSI_CLCR_ACR_MASK (((1ULL << 1) - 1) << DSI_CLCR_ACR_SHIFT)


struct dsi_clcr {
    uint32_t dpcc:1;
    uint32_t acr:1;
    };

typedef struct dsi_clcr dsi_clcr_t;
static_assert(sizeof(dsi_clcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI CLTCR register
 *
 * DSI Host clock lane timer configuration register
 *
 *  @note offset: 0x98UL
 *        width:  32 bits
 */
#define DSI_CLTCR_REG  0x98UL

/**
 * @brief DSI CLTCR LP2HS_TIME field
 *
 * Low-power to high-speed time This field configures the maximum time that the D-PHY clock lane takes to go from lowâpower to high-speed transmission measured in lane byte clock cycles.
 *
 * @note offset: 0x0UL
 *       width:  10
 *       access: read-write
 */
#define DSI_CLTCR_LP2HS_TIME_SHIFT 0x0UL
#define DSI_CLTCR_LP2HS_TIME_MASK (((1ULL << 10) - 1) << DSI_CLTCR_LP2HS_TIME_SHIFT)
/**
 * @brief DSI CLTCR HS2LP_TIME field
 *
 * High-speed to low-power time This field configures the maximum time that the D-PHY clock lane takes to go from highâspeed to low-power transmission measured in lane byte clock cycles.
 *
 * @note offset: 0x10UL
 *       width:  10
 *       access: read-write
 */
#define DSI_CLTCR_HS2LP_TIME_SHIFT 0x10UL
#define DSI_CLTCR_HS2LP_TIME_MASK (((1ULL << 10) - 1) << DSI_CLTCR_HS2LP_TIME_SHIFT)


struct dsi_cltcr {
    uint32_t lp2hs_time:10;
    uint32_t reserved0:6;
    uint32_t hs2lp_time:10;
    };

typedef struct dsi_cltcr dsi_cltcr_t;
static_assert(sizeof(dsi_cltcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI DLTCR register
 *
 * DSI Host data lane timer configuration register
 *
 *  @note offset: 0x9cUL
 *        width:  32 bits
 */
#define DSI_DLTCR_REG  0x9cUL

/**
 * @brief DSI DLTCR LP2HS_TIME field
 *
 * Low-power to high-speed time This field configures the maximum time that the D-PHY data lanes take to go from low-power to high-speed transmission measured in lane byte clock cycles.
 *
 * @note offset: 0x0UL
 *       width:  10
 *       access: read-write
 */
#define DSI_DLTCR_LP2HS_TIME_SHIFT 0x0UL
#define DSI_DLTCR_LP2HS_TIME_MASK (((1ULL << 10) - 1) << DSI_DLTCR_LP2HS_TIME_SHIFT)
/**
 * @brief DSI DLTCR HS2LP_TIME field
 *
 * High-speed to low-power time This field configures the maximum time that the D-PHY data lanes take to go from high-speed to low-power transmission measured in lane byte clock cycles.
 *
 * @note offset: 0x10UL
 *       width:  10
 *       access: read-write
 */
#define DSI_DLTCR_HS2LP_TIME_SHIFT 0x10UL
#define DSI_DLTCR_HS2LP_TIME_MASK (((1ULL << 10) - 1) << DSI_DLTCR_HS2LP_TIME_SHIFT)


struct dsi_dltcr {
    uint32_t lp2hs_time:10;
    uint32_t reserved0:6;
    uint32_t hs2lp_time:10;
    };

typedef struct dsi_dltcr dsi_dltcr_t;
static_assert(sizeof(dsi_dltcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI PCTLR register
 *
 * DSI Host PHY control register
 *
 *  @note offset: 0xa0UL
 *        width:  32 bits
 */
#define DSI_PCTLR_REG  0xa0UL

/**
 * @brief DSI PCTLR DEN field
 *
 * Digital enable When set to 0, this bit places the digital section of the D-PHY in the reset state
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define DSI_PCTLR_DEN (1UL << 0x1UL)
#define DSI_PCTLR_DEN_SHIFT 0x1UL
#define DSI_PCTLR_DEN_MASK (((1ULL << 1) - 1) << DSI_PCTLR_DEN_SHIFT)
/**
 * @brief DSI PCTLR CKE field
 *
 * Clock enable This bit enables the D-PHY clock lane module:
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-write
 */
#define DSI_PCTLR_CKE (1UL << 0x2UL)
#define DSI_PCTLR_CKE_SHIFT 0x2UL
#define DSI_PCTLR_CKE_MASK (((1ULL << 1) - 1) << DSI_PCTLR_CKE_SHIFT)


struct dsi_pctlr {
    uint32_t reserved0:1;
    uint32_t den:1;
    uint32_t cke:1;
    };

typedef struct dsi_pctlr dsi_pctlr_t;
static_assert(sizeof(dsi_pctlr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI PCONFR register
 *
 * DSI Host PHY configuration register
 *
 *  @note offset: 0xa4UL
 *        width:  32 bits
 */
#define DSI_PCONFR_REG  0xa4UL

/**
 * @brief DSI PCONFR NL field
 *
 * Number of lanes This field configures the number of active data lanes: Others: Reserved
 *
 * @note offset: 0x0UL
 *       width:  2
 *       access: read-write
 */
#define DSI_PCONFR_NL_SHIFT 0x0UL
#define DSI_PCONFR_NL_MASK (((1ULL << 2) - 1) << DSI_PCONFR_NL_SHIFT)
/**
 * @brief DSI PCONFR SW_TIME field
 *
 * Stop wait time This field configures the minimum wait period to request a high-speed transmission after the Stop state.
 *
 * @note offset: 0x8UL
 *       width:  8
 *       access: read-write
 */
#define DSI_PCONFR_SW_TIME_SHIFT 0x8UL
#define DSI_PCONFR_SW_TIME_MASK (((1ULL << 8) - 1) << DSI_PCONFR_SW_TIME_SHIFT)


struct dsi_pconfr {
    uint32_t nl:2;
    uint32_t reserved0:6;
    uint32_t sw_time:8;
    };

typedef struct dsi_pconfr dsi_pconfr_t;
static_assert(sizeof(dsi_pconfr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI PUCR register
 *
 * DSI Host PHY ULPS control register
 *
 *  @note offset: 0xa8UL
 *        width:  32 bits
 */
#define DSI_PUCR_REG  0xa8UL

/**
 * @brief DSI PUCR URCL field
 *
 * ULPS request on clock lane ULPS mode request on clock lane.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_PUCR_URCL (1UL << 0x0UL)
#define DSI_PUCR_URCL_SHIFT 0x0UL
#define DSI_PUCR_URCL_MASK (((1ULL << 1) - 1) << DSI_PUCR_URCL_SHIFT)
/**
 * @brief DSI PUCR UECL field
 *
 * ULPS exit on clock lane ULPS mode exit on clock lane.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define DSI_PUCR_UECL (1UL << 0x1UL)
#define DSI_PUCR_UECL_SHIFT 0x1UL
#define DSI_PUCR_UECL_MASK (((1ULL << 1) - 1) << DSI_PUCR_UECL_SHIFT)
/**
 * @brief DSI PUCR URDL field
 *
 * ULPS request on data lane ULPS mode request on all active data lanes.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-write
 */
#define DSI_PUCR_URDL (1UL << 0x2UL)
#define DSI_PUCR_URDL_SHIFT 0x2UL
#define DSI_PUCR_URDL_MASK (((1ULL << 1) - 1) << DSI_PUCR_URDL_SHIFT)
/**
 * @brief DSI PUCR UEDL field
 *
 * ULPS exit on data lane ULPS mode exit on all active data lanes.
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-write
 */
#define DSI_PUCR_UEDL (1UL << 0x3UL)
#define DSI_PUCR_UEDL_SHIFT 0x3UL
#define DSI_PUCR_UEDL_MASK (((1ULL << 1) - 1) << DSI_PUCR_UEDL_SHIFT)


struct dsi_pucr {
    uint32_t urcl:1;
    uint32_t uecl:1;
    uint32_t urdl:1;
    uint32_t uedl:1;
    };

typedef struct dsi_pucr dsi_pucr_t;
static_assert(sizeof(dsi_pucr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI PTTCR register
 *
 * DSI Host PHY TX triggers configuration register
 *
 *  @note offset: 0xacUL
 *        width:  32 bits
 */
#define DSI_PTTCR_REG  0xacUL

/**
 * @brief DSI PTTCR TX_TRIG field
 *
 * Transmission trigger Escape mode transmit trigger 0-3. Only one bit of TX_TRIG is asserted at any given time.
 *
 * @note offset: 0x0UL
 *       width:  4
 *       access: read-write
 */
#define DSI_PTTCR_TX_TRIG_SHIFT 0x0UL
#define DSI_PTTCR_TX_TRIG_MASK (((1ULL << 4) - 1) << DSI_PTTCR_TX_TRIG_SHIFT)


struct dsi_pttcr {
    uint32_t tx_trig:4;
    };

typedef struct dsi_pttcr dsi_pttcr_t;
static_assert(sizeof(dsi_pttcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI PSR register
 *
 * DSI Host PHY status register
 *
 *  @note offset: 0xb0UL
 *        width:  32 bits
 */
#define DSI_PSR_REG  0xb0UL

/**
 * @brief DSI PSR PD field
 *
 * PHY direction This bit indicates the status of phydirection D-PHY signal.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-only
 */
#define DSI_PSR_PD (1UL << 0x1UL)
#define DSI_PSR_PD_SHIFT 0x1UL
#define DSI_PSR_PD_MASK (((1ULL << 1) - 1) << DSI_PSR_PD_SHIFT)
/**
 * @brief DSI PSR PSSC field
 *
 * PHY stop state clock lane This bit indicates the status of phystopstateclklane D-PHY signal.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-only
 */
#define DSI_PSR_PSSC (1UL << 0x2UL)
#define DSI_PSR_PSSC_SHIFT 0x2UL
#define DSI_PSR_PSSC_MASK (((1ULL << 1) - 1) << DSI_PSR_PSSC_SHIFT)
/**
 * @brief DSI PSR UANC field
 *
 * ULPS active not clock lane This bit indicates the status of ulpsactivenotclklane D-PHY signal.
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-only
 */
#define DSI_PSR_UANC (1UL << 0x3UL)
#define DSI_PSR_UANC_SHIFT 0x3UL
#define DSI_PSR_UANC_MASK (((1ULL << 1) - 1) << DSI_PSR_UANC_SHIFT)
/**
 * @brief DSI PSR PSS0 field
 *
 * PHY stop state lane 0 This bit indicates the status of phystopstate0lane D-PHY signal.
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: read-only
 */
#define DSI_PSR_PSS0 (1UL << 0x4UL)
#define DSI_PSR_PSS0_SHIFT 0x4UL
#define DSI_PSR_PSS0_MASK (((1ULL << 1) - 1) << DSI_PSR_PSS0_SHIFT)
/**
 * @brief DSI PSR UAN0 field
 *
 * ULPS active not lane 1 This bit indicates the status of ulpsactivenot0lane D-PHY signal.
 *
 * @note offset: 0x5UL
 *       width:  1
 *       access: read-only
 */
#define DSI_PSR_UAN0 (1UL << 0x5UL)
#define DSI_PSR_UAN0_SHIFT 0x5UL
#define DSI_PSR_UAN0_MASK (((1ULL << 1) - 1) << DSI_PSR_UAN0_SHIFT)
/**
 * @brief DSI PSR RUE0 field
 *
 * RX ULPS escape lane 0 This bit indicates the status of rxulpsesc0lane D-PHY signal.
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: read-only
 */
#define DSI_PSR_RUE0 (1UL << 0x6UL)
#define DSI_PSR_RUE0_SHIFT 0x6UL
#define DSI_PSR_RUE0_MASK (((1ULL << 1) - 1) << DSI_PSR_RUE0_SHIFT)
/**
 * @brief DSI PSR PSS1 field
 *
 * PHY stop state lane 1 This bit indicates the status of phystopstate1lane D-PHY signal.
 *
 * @note offset: 0x7UL
 *       width:  1
 *       access: read-only
 */
#define DSI_PSR_PSS1 (1UL << 0x7UL)
#define DSI_PSR_PSS1_SHIFT 0x7UL
#define DSI_PSR_PSS1_MASK (((1ULL << 1) - 1) << DSI_PSR_PSS1_SHIFT)
/**
 * @brief DSI PSR UAN1 field
 *
 * ULPS active not lane 1 This bit indicates the status of ulpsactivenot1lane D-PHY signal.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-only
 */
#define DSI_PSR_UAN1 (1UL << 0x8UL)
#define DSI_PSR_UAN1_SHIFT 0x8UL
#define DSI_PSR_UAN1_MASK (((1ULL << 1) - 1) << DSI_PSR_UAN1_SHIFT)


struct dsi_psr {
    uint32_t reserved0:1;
    uint32_t pd:1;
    uint32_t pssc:1;
    uint32_t uanc:1;
    uint32_t pss0:1;
    uint32_t uan0:1;
    uint32_t rue0:1;
    uint32_t pss1:1;
    uint32_t uan1:1;
    };

typedef struct dsi_psr dsi_psr_t;
static_assert(sizeof(dsi_psr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI ISR0 register
 *
 * DSI Host interrupt and status register 0
 *
 *  @note offset: 0xbcUL
 *        width:  32 bits
 */
#define DSI_ISR0_REG  0xbcUL

/**
 * @brief DSI ISR0 AE0 field
 *
 * Acknowledge error 0 This bit retrieves the SoT error from the acknowledge error report.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE0 (1UL << 0x0UL)
#define DSI_ISR0_AE0_SHIFT 0x0UL
#define DSI_ISR0_AE0_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE0_SHIFT)
/**
 * @brief DSI ISR0 AE1 field
 *
 * Acknowledge error 1 This bit retrieves the SoT sync error from the acknowledge error report.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE1 (1UL << 0x1UL)
#define DSI_ISR0_AE1_SHIFT 0x1UL
#define DSI_ISR0_AE1_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE1_SHIFT)
/**
 * @brief DSI ISR0 AE2 field
 *
 * Acknowledge error 2 This bit retrieves the EoT sync error from the acknowledge error report.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE2 (1UL << 0x2UL)
#define DSI_ISR0_AE2_SHIFT 0x2UL
#define DSI_ISR0_AE2_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE2_SHIFT)
/**
 * @brief DSI ISR0 AE3 field
 *
 * Acknowledge error 3 This bit retrieves the escape mode entry command error from the acknowledge error report.
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE3 (1UL << 0x3UL)
#define DSI_ISR0_AE3_SHIFT 0x3UL
#define DSI_ISR0_AE3_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE3_SHIFT)
/**
 * @brief DSI ISR0 AE4 field
 *
 * Acknowledge error 4 This bit retrieves the LP transmit sync error from the acknowledge error report.
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE4 (1UL << 0x4UL)
#define DSI_ISR0_AE4_SHIFT 0x4UL
#define DSI_ISR0_AE4_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE4_SHIFT)
/**
 * @brief DSI ISR0 AE5 field
 *
 * Acknowledge error 5 This bit retrieves the peripheral timeout error from the acknowledge error report.
 *
 * @note offset: 0x5UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE5 (1UL << 0x5UL)
#define DSI_ISR0_AE5_SHIFT 0x5UL
#define DSI_ISR0_AE5_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE5_SHIFT)
/**
 * @brief DSI ISR0 AE6 field
 *
 * Acknowledge error 6 This bit retrieves the false control error from the acknowledge error report.
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE6 (1UL << 0x6UL)
#define DSI_ISR0_AE6_SHIFT 0x6UL
#define DSI_ISR0_AE6_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE6_SHIFT)
/**
 * @brief DSI ISR0 AE7 field
 *
 * Acknowledge error 7 This bit retrieves the reserved (specific to the device) from the acknowledge error report.
 *
 * @note offset: 0x7UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE7 (1UL << 0x7UL)
#define DSI_ISR0_AE7_SHIFT 0x7UL
#define DSI_ISR0_AE7_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE7_SHIFT)
/**
 * @brief DSI ISR0 AE8 field
 *
 * Acknowledge error 8 This bit retrieves the ECC error, single-bit (detected and corrected) from the acknowledge error report.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE8 (1UL << 0x8UL)
#define DSI_ISR0_AE8_SHIFT 0x8UL
#define DSI_ISR0_AE8_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE8_SHIFT)
/**
 * @brief DSI ISR0 AE9 field
 *
 * Acknowledge error 9 This bit retrieves the ECC error, multi-bit (detected, not corrected) from the acknowledge error report.
 *
 * @note offset: 0x9UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE9 (1UL << 0x9UL)
#define DSI_ISR0_AE9_SHIFT 0x9UL
#define DSI_ISR0_AE9_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE9_SHIFT)
/**
 * @brief DSI ISR0 AE10 field
 *
 * Acknowledge error 10 This bit retrieves the checksum error (long packet only) from the acknowledge error report.
 *
 * @note offset: 0xaUL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE10 (1UL << 0xaUL)
#define DSI_ISR0_AE10_SHIFT 0xaUL
#define DSI_ISR0_AE10_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE10_SHIFT)
/**
 * @brief DSI ISR0 AE11 field
 *
 * Acknowledge error 11 This bit retrieves the not recognized DSI data type from the acknowledge error report.
 *
 * @note offset: 0xbUL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE11 (1UL << 0xbUL)
#define DSI_ISR0_AE11_SHIFT 0xbUL
#define DSI_ISR0_AE11_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE11_SHIFT)
/**
 * @brief DSI ISR0 AE12 field
 *
 * Acknowledge error 12 This bit retrieves the DSI VC ID Invalid from the acknowledge error report.
 *
 * @note offset: 0xcUL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE12 (1UL << 0xcUL)
#define DSI_ISR0_AE12_SHIFT 0xcUL
#define DSI_ISR0_AE12_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE12_SHIFT)
/**
 * @brief DSI ISR0 AE13 field
 *
 * Acknowledge error 13 This bit retrieves the invalid transmission length from the acknowledge error report.
 *
 * @note offset: 0xdUL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE13 (1UL << 0xdUL)
#define DSI_ISR0_AE13_SHIFT 0xdUL
#define DSI_ISR0_AE13_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE13_SHIFT)
/**
 * @brief DSI ISR0 AE14 field
 *
 * Acknowledge error 14 This bit retrieves the reserved (specific to the device) from the acknowledge error report.
 *
 * @note offset: 0xeUL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE14 (1UL << 0xeUL)
#define DSI_ISR0_AE14_SHIFT 0xeUL
#define DSI_ISR0_AE14_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE14_SHIFT)
/**
 * @brief DSI ISR0 AE15 field
 *
 * Acknowledge error 15 This bit retrieves the DSI protocol violation from the acknowledge error report.
 *
 * @note offset: 0xfUL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_AE15 (1UL << 0xfUL)
#define DSI_ISR0_AE15_SHIFT 0xfUL
#define DSI_ISR0_AE15_MASK (((1ULL << 1) - 1) << DSI_ISR0_AE15_SHIFT)
/**
 * @brief DSI ISR0 PE0 field
 *
 * PHY error 0 This bit indicates the ErrEsc escape entry error from lane 0.
 *
 * @note offset: 0x10UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_PE0 (1UL << 0x10UL)
#define DSI_ISR0_PE0_SHIFT 0x10UL
#define DSI_ISR0_PE0_MASK (((1ULL << 1) - 1) << DSI_ISR0_PE0_SHIFT)
/**
 * @brief DSI ISR0 PE1 field
 *
 * PHY error 1 This bit indicates the ErrSyncEsc low-power transmission synchronization error from lane 0.
 *
 * @note offset: 0x11UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_PE1 (1UL << 0x11UL)
#define DSI_ISR0_PE1_SHIFT 0x11UL
#define DSI_ISR0_PE1_MASK (((1ULL << 1) - 1) << DSI_ISR0_PE1_SHIFT)
/**
 * @brief DSI ISR0 PE2 field
 *
 * PHY error 2 This bit indicates the ErrControl error from lane 0.
 *
 * @note offset: 0x12UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_PE2 (1UL << 0x12UL)
#define DSI_ISR0_PE2_SHIFT 0x12UL
#define DSI_ISR0_PE2_MASK (((1ULL << 1) - 1) << DSI_ISR0_PE2_SHIFT)
/**
 * @brief DSI ISR0 PE3 field
 *
 * PHY error 3 This bit indicates the LP0 contention error ErrContentionLP0 from lane 0.
 *
 * @note offset: 0x13UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_PE3 (1UL << 0x13UL)
#define DSI_ISR0_PE3_SHIFT 0x13UL
#define DSI_ISR0_PE3_MASK (((1ULL << 1) - 1) << DSI_ISR0_PE3_SHIFT)
/**
 * @brief DSI ISR0 PE4 field
 *
 * PHY error 4 This bit indicates the LP1 contention error ErrContentionLP1 from lane 0.
 *
 * @note offset: 0x14UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR0_PE4 (1UL << 0x14UL)
#define DSI_ISR0_PE4_SHIFT 0x14UL
#define DSI_ISR0_PE4_MASK (((1ULL << 1) - 1) << DSI_ISR0_PE4_SHIFT)


struct dsi_isr0 {
    uint32_t ae0:1;
    uint32_t ae1:1;
    uint32_t ae2:1;
    uint32_t ae3:1;
    uint32_t ae4:1;
    uint32_t ae5:1;
    uint32_t ae6:1;
    uint32_t ae7:1;
    uint32_t ae8:1;
    uint32_t ae9:1;
    uint32_t ae10:1;
    uint32_t ae11:1;
    uint32_t ae12:1;
    uint32_t ae13:1;
    uint32_t ae14:1;
    uint32_t ae15:1;
    uint32_t pe0:1;
    uint32_t pe1:1;
    uint32_t pe2:1;
    uint32_t pe3:1;
    uint32_t pe4:1;
    };

typedef struct dsi_isr0 dsi_isr0_t;
static_assert(sizeof(dsi_isr0_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI ISR1 register
 *
 * DSI Host interrupt and status register 1
 *
 *  @note offset: 0xc0UL
 *        width:  32 bits
 */
#define DSI_ISR1_REG  0xc0UL

/**
 * @brief DSI ISR1 TOHSTX field
 *
 * Timeout high-speed transmission This bit indicates that the high-speed transmission timeout counter reached the end and contention is detected.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_TOHSTX (1UL << 0x0UL)
#define DSI_ISR1_TOHSTX_SHIFT 0x0UL
#define DSI_ISR1_TOHSTX_MASK (((1ULL << 1) - 1) << DSI_ISR1_TOHSTX_SHIFT)
/**
 * @brief DSI ISR1 TOLPRX field
 *
 * Timeout low-power reception This bit indicates that the low-power reception timeout counter reached the end and contention is detected.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_TOLPRX (1UL << 0x1UL)
#define DSI_ISR1_TOLPRX_SHIFT 0x1UL
#define DSI_ISR1_TOLPRX_MASK (((1ULL << 1) - 1) << DSI_ISR1_TOLPRX_SHIFT)
/**
 * @brief DSI ISR1 ECCSE field
 *
 * ECC single-bit error This bit indicates that the ECC single error is detected and corrected in a received packet.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_ECCSE (1UL << 0x2UL)
#define DSI_ISR1_ECCSE_SHIFT 0x2UL
#define DSI_ISR1_ECCSE_MASK (((1ULL << 1) - 1) << DSI_ISR1_ECCSE_SHIFT)
/**
 * @brief DSI ISR1 ECCME field
 *
 * ECC multi-bit error This bit indicates that the ECC multiple error is detected in a received packet.
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_ECCME (1UL << 0x3UL)
#define DSI_ISR1_ECCME_SHIFT 0x3UL
#define DSI_ISR1_ECCME_MASK (((1ULL << 1) - 1) << DSI_ISR1_ECCME_SHIFT)
/**
 * @brief DSI ISR1 CRCE field
 *
 * CRC error This bit indicates that the CRC error is detected in the received packet payload.
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_CRCE (1UL << 0x4UL)
#define DSI_ISR1_CRCE_SHIFT 0x4UL
#define DSI_ISR1_CRCE_MASK (((1ULL << 1) - 1) << DSI_ISR1_CRCE_SHIFT)
/**
 * @brief DSI ISR1 PSE field
 *
 * Packet size error This bit indicates that the packet size error is detected during the packet reception.
 *
 * @note offset: 0x5UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_PSE (1UL << 0x5UL)
#define DSI_ISR1_PSE_SHIFT 0x5UL
#define DSI_ISR1_PSE_MASK (((1ULL << 1) - 1) << DSI_ISR1_PSE_SHIFT)
/**
 * @brief DSI ISR1 EOTPE field
 *
 * EoTp error This bit indicates that the EoTp packet is not received at the end of the incoming peripheral transmission.
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_EOTPE (1UL << 0x6UL)
#define DSI_ISR1_EOTPE_SHIFT 0x6UL
#define DSI_ISR1_EOTPE_MASK (((1ULL << 1) - 1) << DSI_ISR1_EOTPE_SHIFT)
/**
 * @brief DSI ISR1 LPWRE field
 *
 * LTDC payload write error This bit indicates that during a DPI pixel line storage, the payload FIFO becomes full and the data stored is corrupted.
 *
 * @note offset: 0x7UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_LPWRE (1UL << 0x7UL)
#define DSI_ISR1_LPWRE_SHIFT 0x7UL
#define DSI_ISR1_LPWRE_MASK (((1ULL << 1) - 1) << DSI_ISR1_LPWRE_SHIFT)
/**
 * @brief DSI ISR1 GCWRE field
 *
 * Generic command write error This bit indicates that the system tried to write a command through the generic interface and the FIFO is full. Therefore, the command is not written.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_GCWRE (1UL << 0x8UL)
#define DSI_ISR1_GCWRE_SHIFT 0x8UL
#define DSI_ISR1_GCWRE_MASK (((1ULL << 1) - 1) << DSI_ISR1_GCWRE_SHIFT)
/**
 * @brief DSI ISR1 GPWRE field
 *
 * Generic payload write error This bit indicates that the system tried to write a payload data through the generic interface and the FIFO is full. Therefore, the payload is not written.
 *
 * @note offset: 0x9UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_GPWRE (1UL << 0x9UL)
#define DSI_ISR1_GPWRE_SHIFT 0x9UL
#define DSI_ISR1_GPWRE_MASK (((1ULL << 1) - 1) << DSI_ISR1_GPWRE_SHIFT)
/**
 * @brief DSI ISR1 GPTXE field
 *
 * Generic payload transmit error This bit indicates that during a generic interface packet build, the payload FIFO becomes empty and corrupt data is sent.
 *
 * @note offset: 0xaUL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_GPTXE (1UL << 0xaUL)
#define DSI_ISR1_GPTXE_SHIFT 0xaUL
#define DSI_ISR1_GPTXE_MASK (((1ULL << 1) - 1) << DSI_ISR1_GPTXE_SHIFT)
/**
 * @brief DSI ISR1 GPRDE field
 *
 * Generic payload read error This bit indicates that during a DCS read data, the payload FIFO becomes empty and the data sent to the interface is corrupted.
 *
 * @note offset: 0xbUL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_GPRDE (1UL << 0xbUL)
#define DSI_ISR1_GPRDE_SHIFT 0xbUL
#define DSI_ISR1_GPRDE_MASK (((1ULL << 1) - 1) << DSI_ISR1_GPRDE_SHIFT)
/**
 * @brief DSI ISR1 GPRXE field
 *
 * Generic payload receive error This bit indicates that during a generic interface packet read back, the payload FIFO becomes full and the received data is corrupted.
 *
 * @note offset: 0xcUL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_GPRXE (1UL << 0xcUL)
#define DSI_ISR1_GPRXE_SHIFT 0xcUL
#define DSI_ISR1_GPRXE_MASK (((1ULL << 1) - 1) << DSI_ISR1_GPRXE_SHIFT)
/**
 * @brief DSI ISR1 PBUE field
 *
 * Payload buffer underflow error This bit indicates that underflow has occurred when reading payload to build DSI packet for video mode.
 *
 * @note offset: 0x13UL
 *       width:  1
 *       access: read-only
 */
#define DSI_ISR1_PBUE (1UL << 0x13UL)
#define DSI_ISR1_PBUE_SHIFT 0x13UL
#define DSI_ISR1_PBUE_MASK (((1ULL << 1) - 1) << DSI_ISR1_PBUE_SHIFT)


struct dsi_isr1 {
    uint32_t tohstx:1;
    uint32_t tolprx:1;
    uint32_t eccse:1;
    uint32_t eccme:1;
    uint32_t crce:1;
    uint32_t pse:1;
    uint32_t eotpe:1;
    uint32_t lpwre:1;
    uint32_t gcwre:1;
    uint32_t gpwre:1;
    uint32_t gptxe:1;
    uint32_t gprde:1;
    uint32_t gprxe:1;
    uint32_t reserved0:6;
    uint32_t pbue:1;
    };

typedef struct dsi_isr1 dsi_isr1_t;
static_assert(sizeof(dsi_isr1_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI IER0 register
 *
 * DSI Host interrupt enable register 0
 *
 *  @note offset: 0xc4UL
 *        width:  32 bits
 */
#define DSI_IER0_REG  0xc4UL

/**
 * @brief DSI IER0 AE0IE field
 *
 * Acknowledge error 0 interrupt enable This bit enables the interrupt generation on acknowledge error 0.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE0IE (1UL << 0x0UL)
#define DSI_IER0_AE0IE_SHIFT 0x0UL
#define DSI_IER0_AE0IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE0IE_SHIFT)
/**
 * @brief DSI IER0 AE1IE field
 *
 * Acknowledge error 1 interrupt enable This bit enables the interrupt generation on acknowledge error 1.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE1IE (1UL << 0x1UL)
#define DSI_IER0_AE1IE_SHIFT 0x1UL
#define DSI_IER0_AE1IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE1IE_SHIFT)
/**
 * @brief DSI IER0 AE2IE field
 *
 * Acknowledge error 2 interrupt enable This bit enables the interrupt generation on acknowledge error 2.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE2IE (1UL << 0x2UL)
#define DSI_IER0_AE2IE_SHIFT 0x2UL
#define DSI_IER0_AE2IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE2IE_SHIFT)
/**
 * @brief DSI IER0 AE3IE field
 *
 * Acknowledge error 3 interrupt enable This bit enables the interrupt generation on acknowledge error 3.
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE3IE (1UL << 0x3UL)
#define DSI_IER0_AE3IE_SHIFT 0x3UL
#define DSI_IER0_AE3IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE3IE_SHIFT)
/**
 * @brief DSI IER0 AE4IE field
 *
 * Acknowledge error 4 interrupt enable This bit enables the interrupt generation on acknowledge error 4.
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE4IE (1UL << 0x4UL)
#define DSI_IER0_AE4IE_SHIFT 0x4UL
#define DSI_IER0_AE4IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE4IE_SHIFT)
/**
 * @brief DSI IER0 AE5IE field
 *
 * Acknowledge error 5 interrupt enable This bit enables the interrupt generation on acknowledge error 5.
 *
 * @note offset: 0x5UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE5IE (1UL << 0x5UL)
#define DSI_IER0_AE5IE_SHIFT 0x5UL
#define DSI_IER0_AE5IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE5IE_SHIFT)
/**
 * @brief DSI IER0 AE6IE field
 *
 * Acknowledge error 6 interrupt enable This bit enables the interrupt generation on acknowledge error 6.
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE6IE (1UL << 0x6UL)
#define DSI_IER0_AE6IE_SHIFT 0x6UL
#define DSI_IER0_AE6IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE6IE_SHIFT)
/**
 * @brief DSI IER0 AE7IE field
 *
 * Acknowledge error 7 interrupt enable This bit enables the interrupt generation on acknowledge error 7.
 *
 * @note offset: 0x7UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE7IE (1UL << 0x7UL)
#define DSI_IER0_AE7IE_SHIFT 0x7UL
#define DSI_IER0_AE7IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE7IE_SHIFT)
/**
 * @brief DSI IER0 AE8IE field
 *
 * Acknowledge error 8 interrupt enable This bit enables the interrupt generation on acknowledge error 8.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE8IE (1UL << 0x8UL)
#define DSI_IER0_AE8IE_SHIFT 0x8UL
#define DSI_IER0_AE8IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE8IE_SHIFT)
/**
 * @brief DSI IER0 AE9IE field
 *
 * Acknowledge error 9 interrupt enable This bit enables the interrupt generation on acknowledge error 9.
 *
 * @note offset: 0x9UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE9IE (1UL << 0x9UL)
#define DSI_IER0_AE9IE_SHIFT 0x9UL
#define DSI_IER0_AE9IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE9IE_SHIFT)
/**
 * @brief DSI IER0 AE10IE field
 *
 * Acknowledge error 10 interrupt enable This bit enables the interrupt generation on acknowledge error 10.
 *
 * @note offset: 0xaUL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE10IE (1UL << 0xaUL)
#define DSI_IER0_AE10IE_SHIFT 0xaUL
#define DSI_IER0_AE10IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE10IE_SHIFT)
/**
 * @brief DSI IER0 AE11IE field
 *
 * Acknowledge error 11 interrupt enable This bit enables the interrupt generation on acknowledge error 11.
 *
 * @note offset: 0xbUL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE11IE (1UL << 0xbUL)
#define DSI_IER0_AE11IE_SHIFT 0xbUL
#define DSI_IER0_AE11IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE11IE_SHIFT)
/**
 * @brief DSI IER0 AE12IE field
 *
 * Acknowledge error 12 interrupt enable This bit enables the interrupt generation on acknowledge error 12.
 *
 * @note offset: 0xcUL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE12IE (1UL << 0xcUL)
#define DSI_IER0_AE12IE_SHIFT 0xcUL
#define DSI_IER0_AE12IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE12IE_SHIFT)
/**
 * @brief DSI IER0 AE13IE field
 *
 * Acknowledge error 13 interrupt enable This bit enables the interrupt generation on acknowledge error 13.
 *
 * @note offset: 0xdUL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE13IE (1UL << 0xdUL)
#define DSI_IER0_AE13IE_SHIFT 0xdUL
#define DSI_IER0_AE13IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE13IE_SHIFT)
/**
 * @brief DSI IER0 AE14IE field
 *
 * Acknowledge error 14 interrupt enable This bit enables the interrupt generation on acknowledge error 14.
 *
 * @note offset: 0xeUL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE14IE (1UL << 0xeUL)
#define DSI_IER0_AE14IE_SHIFT 0xeUL
#define DSI_IER0_AE14IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE14IE_SHIFT)
/**
 * @brief DSI IER0 AE15IE field
 *
 * Acknowledge error 15 interrupt enable This bit enables the interrupt generation on acknowledge error 15.
 *
 * @note offset: 0xfUL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_AE15IE (1UL << 0xfUL)
#define DSI_IER0_AE15IE_SHIFT 0xfUL
#define DSI_IER0_AE15IE_MASK (((1ULL << 1) - 1) << DSI_IER0_AE15IE_SHIFT)
/**
 * @brief DSI IER0 PE0IE field
 *
 * PHY error 0 interrupt enable This bit enables the interrupt generation on PHY error 0.
 *
 * @note offset: 0x10UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_PE0IE (1UL << 0x10UL)
#define DSI_IER0_PE0IE_SHIFT 0x10UL
#define DSI_IER0_PE0IE_MASK (((1ULL << 1) - 1) << DSI_IER0_PE0IE_SHIFT)
/**
 * @brief DSI IER0 PE1IE field
 *
 * PHY error 1 interrupt enable This bit enables the interrupt generation on PHY error 1.
 *
 * @note offset: 0x11UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_PE1IE (1UL << 0x11UL)
#define DSI_IER0_PE1IE_SHIFT 0x11UL
#define DSI_IER0_PE1IE_MASK (((1ULL << 1) - 1) << DSI_IER0_PE1IE_SHIFT)
/**
 * @brief DSI IER0 PE2IE field
 *
 * PHY error 2 interrupt enable This bit enables the interrupt generation on PHY error 2.
 *
 * @note offset: 0x12UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_PE2IE (1UL << 0x12UL)
#define DSI_IER0_PE2IE_SHIFT 0x12UL
#define DSI_IER0_PE2IE_MASK (((1ULL << 1) - 1) << DSI_IER0_PE2IE_SHIFT)
/**
 * @brief DSI IER0 PE3IE field
 *
 * PHY error 3 interrupt enable This bit enables the interrupt generation on PHY error 4.
 *
 * @note offset: 0x13UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_PE3IE (1UL << 0x13UL)
#define DSI_IER0_PE3IE_SHIFT 0x13UL
#define DSI_IER0_PE3IE_MASK (((1ULL << 1) - 1) << DSI_IER0_PE3IE_SHIFT)
/**
 * @brief DSI IER0 PE4IE field
 *
 * PHY error 4 interrupt enable This bit enables the interrupt generation on PHY error 4.
 *
 * @note offset: 0x14UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER0_PE4IE (1UL << 0x14UL)
#define DSI_IER0_PE4IE_SHIFT 0x14UL
#define DSI_IER0_PE4IE_MASK (((1ULL << 1) - 1) << DSI_IER0_PE4IE_SHIFT)


struct dsi_ier0 {
    uint32_t ae0ie:1;
    uint32_t ae1ie:1;
    uint32_t ae2ie:1;
    uint32_t ae3ie:1;
    uint32_t ae4ie:1;
    uint32_t ae5ie:1;
    uint32_t ae6ie:1;
    uint32_t ae7ie:1;
    uint32_t ae8ie:1;
    uint32_t ae9ie:1;
    uint32_t ae10ie:1;
    uint32_t ae11ie:1;
    uint32_t ae12ie:1;
    uint32_t ae13ie:1;
    uint32_t ae14ie:1;
    uint32_t ae15ie:1;
    uint32_t pe0ie:1;
    uint32_t pe1ie:1;
    uint32_t pe2ie:1;
    uint32_t pe3ie:1;
    uint32_t pe4ie:1;
    };

typedef struct dsi_ier0 dsi_ier0_t;
static_assert(sizeof(dsi_ier0_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI IER1 register
 *
 * DSI Host interrupt enable register 1
 *
 *  @note offset: 0xc8UL
 *        width:  32 bits
 */
#define DSI_IER1_REG  0xc8UL

/**
 * @brief DSI IER1 TOHSTXIE field
 *
 * Timeout high-speed transmission interrupt enable This bit enables the interrupt generation on timeout high-speed transmission .
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_TOHSTXIE (1UL << 0x0UL)
#define DSI_IER1_TOHSTXIE_SHIFT 0x0UL
#define DSI_IER1_TOHSTXIE_MASK (((1ULL << 1) - 1) << DSI_IER1_TOHSTXIE_SHIFT)
/**
 * @brief DSI IER1 TOLPRXIE field
 *
 * Timeout low-power reception interrupt enable This bit enables the interrupt generation on timeout low-power reception.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_TOLPRXIE (1UL << 0x1UL)
#define DSI_IER1_TOLPRXIE_SHIFT 0x1UL
#define DSI_IER1_TOLPRXIE_MASK (((1ULL << 1) - 1) << DSI_IER1_TOLPRXIE_SHIFT)
/**
 * @brief DSI IER1 ECCSEIE field
 *
 * ECC single-bit error interrupt enable This bit enables the interrupt generation on ECC single-bit error.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_ECCSEIE (1UL << 0x2UL)
#define DSI_IER1_ECCSEIE_SHIFT 0x2UL
#define DSI_IER1_ECCSEIE_MASK (((1ULL << 1) - 1) << DSI_IER1_ECCSEIE_SHIFT)
/**
 * @brief DSI IER1 ECCMEIE field
 *
 * ECC multi-bit error interrupt enable This bit enables the interrupt generation on ECC multi-bit error.
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_ECCMEIE (1UL << 0x3UL)
#define DSI_IER1_ECCMEIE_SHIFT 0x3UL
#define DSI_IER1_ECCMEIE_MASK (((1ULL << 1) - 1) << DSI_IER1_ECCMEIE_SHIFT)
/**
 * @brief DSI IER1 CRCEIE field
 *
 * CRC error interrupt enable This bit enables the interrupt generation on CRC error.
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_CRCEIE (1UL << 0x4UL)
#define DSI_IER1_CRCEIE_SHIFT 0x4UL
#define DSI_IER1_CRCEIE_MASK (((1ULL << 1) - 1) << DSI_IER1_CRCEIE_SHIFT)
/**
 * @brief DSI IER1 PSEIE field
 *
 * Packet size error interrupt enable This bit enables the interrupt generation on packet size error.
 *
 * @note offset: 0x5UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_PSEIE (1UL << 0x5UL)
#define DSI_IER1_PSEIE_SHIFT 0x5UL
#define DSI_IER1_PSEIE_MASK (((1ULL << 1) - 1) << DSI_IER1_PSEIE_SHIFT)
/**
 * @brief DSI IER1 EOTPEIE field
 *
 * EoTp error interrupt enable This bit enables the interrupt generation on EoTp error.
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_EOTPEIE (1UL << 0x6UL)
#define DSI_IER1_EOTPEIE_SHIFT 0x6UL
#define DSI_IER1_EOTPEIE_MASK (((1ULL << 1) - 1) << DSI_IER1_EOTPEIE_SHIFT)
/**
 * @brief DSI IER1 LPWREIE field
 *
 * LTDC payload write error interrupt enable This bit enables the interrupt generation on LTDC payload write error.
 *
 * @note offset: 0x7UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_LPWREIE (1UL << 0x7UL)
#define DSI_IER1_LPWREIE_SHIFT 0x7UL
#define DSI_IER1_LPWREIE_MASK (((1ULL << 1) - 1) << DSI_IER1_LPWREIE_SHIFT)
/**
 * @brief DSI IER1 GCWREIE field
 *
 * Generic command write error interrupt enable This bit enables the interrupt generation on generic command write error.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_GCWREIE (1UL << 0x8UL)
#define DSI_IER1_GCWREIE_SHIFT 0x8UL
#define DSI_IER1_GCWREIE_MASK (((1ULL << 1) - 1) << DSI_IER1_GCWREIE_SHIFT)
/**
 * @brief DSI IER1 GPWREIE field
 *
 * Generic payload write error interrupt enable This bit enables the interrupt generation on generic payload write error.
 *
 * @note offset: 0x9UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_GPWREIE (1UL << 0x9UL)
#define DSI_IER1_GPWREIE_SHIFT 0x9UL
#define DSI_IER1_GPWREIE_MASK (((1ULL << 1) - 1) << DSI_IER1_GPWREIE_SHIFT)
/**
 * @brief DSI IER1 GPTXEIE field
 *
 * Generic payload transmit error interrupt enable This bit enables the interrupt generation on generic payload transmit error.
 *
 * @note offset: 0xaUL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_GPTXEIE (1UL << 0xaUL)
#define DSI_IER1_GPTXEIE_SHIFT 0xaUL
#define DSI_IER1_GPTXEIE_MASK (((1ULL << 1) - 1) << DSI_IER1_GPTXEIE_SHIFT)
/**
 * @brief DSI IER1 GPRDEIE field
 *
 * Generic payload read error interrupt enable This bit enables the interrupt generation on generic payload read error.
 *
 * @note offset: 0xbUL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_GPRDEIE (1UL << 0xbUL)
#define DSI_IER1_GPRDEIE_SHIFT 0xbUL
#define DSI_IER1_GPRDEIE_MASK (((1ULL << 1) - 1) << DSI_IER1_GPRDEIE_SHIFT)
/**
 * @brief DSI IER1 GPRXEIE field
 *
 * Generic payload receive error interrupt enable This bit enables the interrupt generation on generic payload receive error.
 *
 * @note offset: 0xcUL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_GPRXEIE (1UL << 0xcUL)
#define DSI_IER1_GPRXEIE_SHIFT 0xcUL
#define DSI_IER1_GPRXEIE_MASK (((1ULL << 1) - 1) << DSI_IER1_GPRXEIE_SHIFT)
/**
 * @brief DSI IER1 PBUEIE field
 *
 * Payload buffer underflow error interrupt enable This bit enables the interrupt generation on payload buffer underflow error.
 *
 * @note offset: 0x13UL
 *       width:  1
 *       access: read-write
 */
#define DSI_IER1_PBUEIE (1UL << 0x13UL)
#define DSI_IER1_PBUEIE_SHIFT 0x13UL
#define DSI_IER1_PBUEIE_MASK (((1ULL << 1) - 1) << DSI_IER1_PBUEIE_SHIFT)


struct dsi_ier1 {
    uint32_t tohstxie:1;
    uint32_t tolprxie:1;
    uint32_t eccseie:1;
    uint32_t eccmeie:1;
    uint32_t crceie:1;
    uint32_t pseie:1;
    uint32_t eotpeie:1;
    uint32_t lpwreie:1;
    uint32_t gcwreie:1;
    uint32_t gpwreie:1;
    uint32_t gptxeie:1;
    uint32_t gprdeie:1;
    uint32_t gprxeie:1;
    uint32_t reserved0:6;
    uint32_t pbueie:1;
    };

typedef struct dsi_ier1 dsi_ier1_t;
static_assert(sizeof(dsi_ier1_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI FIR0 register
 *
 * DSI Host force interrupt register 0
 *
 *  @note offset: 0xd8UL
 *        width:  32 bits
 */
#define DSI_FIR0_REG  0xd8UL

/**
 * @brief DSI FIR0 FAE0 field
 *
 * Force acknowledge error 0 Writing one to this bit forces an acknowledge error 0.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE0 (1UL << 0x0UL)
#define DSI_FIR0_FAE0_SHIFT 0x0UL
#define DSI_FIR0_FAE0_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE0_SHIFT)
/**
 * @brief DSI FIR0 FAE1 field
 *
 * Force acknowledge error 1 Writing one to this bit forces an acknowledge error 1.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE1 (1UL << 0x1UL)
#define DSI_FIR0_FAE1_SHIFT 0x1UL
#define DSI_FIR0_FAE1_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE1_SHIFT)
/**
 * @brief DSI FIR0 FAE2 field
 *
 * Force acknowledge error 2 Writing one to this bit forces an acknowledge error 2.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE2 (1UL << 0x2UL)
#define DSI_FIR0_FAE2_SHIFT 0x2UL
#define DSI_FIR0_FAE2_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE2_SHIFT)
/**
 * @brief DSI FIR0 FAE3 field
 *
 * Force acknowledge error 3 Writing one to this bit forces an acknowledge error 3.
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE3 (1UL << 0x3UL)
#define DSI_FIR0_FAE3_SHIFT 0x3UL
#define DSI_FIR0_FAE3_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE3_SHIFT)
/**
 * @brief DSI FIR0 FAE4 field
 *
 * Force acknowledge error 4 Writing one to this bit forces an acknowledge error 4.
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE4 (1UL << 0x4UL)
#define DSI_FIR0_FAE4_SHIFT 0x4UL
#define DSI_FIR0_FAE4_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE4_SHIFT)
/**
 * @brief DSI FIR0 FAE5 field
 *
 * Force acknowledge error 5 Writing one to this bit forces an acknowledge error 5.
 *
 * @note offset: 0x5UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE5 (1UL << 0x5UL)
#define DSI_FIR0_FAE5_SHIFT 0x5UL
#define DSI_FIR0_FAE5_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE5_SHIFT)
/**
 * @brief DSI FIR0 FAE6 field
 *
 * Force acknowledge error 6 Writing one to this bit forces an acknowledge error 6.
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE6 (1UL << 0x6UL)
#define DSI_FIR0_FAE6_SHIFT 0x6UL
#define DSI_FIR0_FAE6_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE6_SHIFT)
/**
 * @brief DSI FIR0 FAE7 field
 *
 * Force acknowledge error 7 Writing one to this bit forces an acknowledge error 7.
 *
 * @note offset: 0x7UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE7 (1UL << 0x7UL)
#define DSI_FIR0_FAE7_SHIFT 0x7UL
#define DSI_FIR0_FAE7_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE7_SHIFT)
/**
 * @brief DSI FIR0 FAE8 field
 *
 * Force acknowledge error 8 Writing one to this bit forces an acknowledge error 8.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE8 (1UL << 0x8UL)
#define DSI_FIR0_FAE8_SHIFT 0x8UL
#define DSI_FIR0_FAE8_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE8_SHIFT)
/**
 * @brief DSI FIR0 FAE9 field
 *
 * Force acknowledge error 9 Writing one to this bit forces an acknowledge error 9.
 *
 * @note offset: 0x9UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE9 (1UL << 0x9UL)
#define DSI_FIR0_FAE9_SHIFT 0x9UL
#define DSI_FIR0_FAE9_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE9_SHIFT)
/**
 * @brief DSI FIR0 FAE10 field
 *
 * Force acknowledge error 10 Writing one to this bit forces an acknowledge error 10.
 *
 * @note offset: 0xaUL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE10 (1UL << 0xaUL)
#define DSI_FIR0_FAE10_SHIFT 0xaUL
#define DSI_FIR0_FAE10_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE10_SHIFT)
/**
 * @brief DSI FIR0 FAE11 field
 *
 * Force acknowledge error 11 Writing one to this bit forces an acknowledge error 11.
 *
 * @note offset: 0xbUL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE11 (1UL << 0xbUL)
#define DSI_FIR0_FAE11_SHIFT 0xbUL
#define DSI_FIR0_FAE11_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE11_SHIFT)
/**
 * @brief DSI FIR0 FAE12 field
 *
 * Force acknowledge error 12 Writing one to this bit forces an acknowledge error 12.
 *
 * @note offset: 0xcUL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE12 (1UL << 0xcUL)
#define DSI_FIR0_FAE12_SHIFT 0xcUL
#define DSI_FIR0_FAE12_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE12_SHIFT)
/**
 * @brief DSI FIR0 FAE13 field
 *
 * Force acknowledge error 13 Writing one to this bit forces an acknowledge error 13.
 *
 * @note offset: 0xdUL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE13 (1UL << 0xdUL)
#define DSI_FIR0_FAE13_SHIFT 0xdUL
#define DSI_FIR0_FAE13_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE13_SHIFT)
/**
 * @brief DSI FIR0 FAE14 field
 *
 * Force acknowledge error 14 Writing one to this bit forces an acknowledge error 14.
 *
 * @note offset: 0xeUL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE14 (1UL << 0xeUL)
#define DSI_FIR0_FAE14_SHIFT 0xeUL
#define DSI_FIR0_FAE14_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE14_SHIFT)
/**
 * @brief DSI FIR0 FAE15 field
 *
 * Force acknowledge error 15 Writing one to this bit forces an acknowledge error 15.
 *
 * @note offset: 0xfUL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FAE15 (1UL << 0xfUL)
#define DSI_FIR0_FAE15_SHIFT 0xfUL
#define DSI_FIR0_FAE15_MASK (((1ULL << 1) - 1) << DSI_FIR0_FAE15_SHIFT)
/**
 * @brief DSI FIR0 FPE0 field
 *
 * Force PHY error 0 Writing one to this bit forces a PHY error 0.
 *
 * @note offset: 0x10UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FPE0 (1UL << 0x10UL)
#define DSI_FIR0_FPE0_SHIFT 0x10UL
#define DSI_FIR0_FPE0_MASK (((1ULL << 1) - 1) << DSI_FIR0_FPE0_SHIFT)
/**
 * @brief DSI FIR0 FPE1 field
 *
 * Force PHY error 1 Writing one to this bit forces a PHY error 1.
 *
 * @note offset: 0x11UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FPE1 (1UL << 0x11UL)
#define DSI_FIR0_FPE1_SHIFT 0x11UL
#define DSI_FIR0_FPE1_MASK (((1ULL << 1) - 1) << DSI_FIR0_FPE1_SHIFT)
/**
 * @brief DSI FIR0 FPE2 field
 *
 * Force PHY error 2 Writing one to this bit forces a PHY error 2.
 *
 * @note offset: 0x12UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FPE2 (1UL << 0x12UL)
#define DSI_FIR0_FPE2_SHIFT 0x12UL
#define DSI_FIR0_FPE2_MASK (((1ULL << 1) - 1) << DSI_FIR0_FPE2_SHIFT)
/**
 * @brief DSI FIR0 FPE3 field
 *
 * Force PHY error 3 Writing one to this bit forces a PHY error 3.
 *
 * @note offset: 0x13UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FPE3 (1UL << 0x13UL)
#define DSI_FIR0_FPE3_SHIFT 0x13UL
#define DSI_FIR0_FPE3_MASK (((1ULL << 1) - 1) << DSI_FIR0_FPE3_SHIFT)
/**
 * @brief DSI FIR0 FPE4 field
 *
 * Force PHY error 4 Writing one to this bit forces a PHY error 4.
 *
 * @note offset: 0x14UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR0_FPE4 (1UL << 0x14UL)
#define DSI_FIR0_FPE4_SHIFT 0x14UL
#define DSI_FIR0_FPE4_MASK (((1ULL << 1) - 1) << DSI_FIR0_FPE4_SHIFT)


struct dsi_fir0 {
    uint32_t fae0:1;
    uint32_t fae1:1;
    uint32_t fae2:1;
    uint32_t fae3:1;
    uint32_t fae4:1;
    uint32_t fae5:1;
    uint32_t fae6:1;
    uint32_t fae7:1;
    uint32_t fae8:1;
    uint32_t fae9:1;
    uint32_t fae10:1;
    uint32_t fae11:1;
    uint32_t fae12:1;
    uint32_t fae13:1;
    uint32_t fae14:1;
    uint32_t fae15:1;
    uint32_t fpe0:1;
    uint32_t fpe1:1;
    uint32_t fpe2:1;
    uint32_t fpe3:1;
    uint32_t fpe4:1;
    };

typedef struct dsi_fir0 dsi_fir0_t;
static_assert(sizeof(dsi_fir0_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI FIR1 register
 *
 * DSI Host force interrupt register 1
 *
 *  @note offset: 0xdcUL
 *        width:  32 bits
 */
#define DSI_FIR1_REG  0xdcUL

/**
 * @brief DSI FIR1 FTOHSTX field
 *
 * Force timeout high-speed transmission Writing one to this bit forces a timeout high-speed transmission.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FTOHSTX (1UL << 0x0UL)
#define DSI_FIR1_FTOHSTX_SHIFT 0x0UL
#define DSI_FIR1_FTOHSTX_MASK (((1ULL << 1) - 1) << DSI_FIR1_FTOHSTX_SHIFT)
/**
 * @brief DSI FIR1 FTOLPRX field
 *
 * Force timeout low-power reception Writing one to this bit forces a timeout low-power reception.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FTOLPRX (1UL << 0x1UL)
#define DSI_FIR1_FTOLPRX_SHIFT 0x1UL
#define DSI_FIR1_FTOLPRX_MASK (((1ULL << 1) - 1) << DSI_FIR1_FTOLPRX_SHIFT)
/**
 * @brief DSI FIR1 FECCSE field
 *
 * Force ECC single-bit error Writing one to this bit forces a ECC single-bit error.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FECCSE (1UL << 0x2UL)
#define DSI_FIR1_FECCSE_SHIFT 0x2UL
#define DSI_FIR1_FECCSE_MASK (((1ULL << 1) - 1) << DSI_FIR1_FECCSE_SHIFT)
/**
 * @brief DSI FIR1 FECCME field
 *
 * Force ECC multi-bit error Writing one to this bit forces a ECC multi-bit error.
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FECCME (1UL << 0x3UL)
#define DSI_FIR1_FECCME_SHIFT 0x3UL
#define DSI_FIR1_FECCME_MASK (((1ULL << 1) - 1) << DSI_FIR1_FECCME_SHIFT)
/**
 * @brief DSI FIR1 FCRCE field
 *
 * Force CRC error Writing one to this bit forces a CRC error.
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FCRCE (1UL << 0x4UL)
#define DSI_FIR1_FCRCE_SHIFT 0x4UL
#define DSI_FIR1_FCRCE_MASK (((1ULL << 1) - 1) << DSI_FIR1_FCRCE_SHIFT)
/**
 * @brief DSI FIR1 FPSE field
 *
 * Force packet size error Writing one to this bit forces a packet size error.
 *
 * @note offset: 0x5UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FPSE (1UL << 0x5UL)
#define DSI_FIR1_FPSE_SHIFT 0x5UL
#define DSI_FIR1_FPSE_MASK (((1ULL << 1) - 1) << DSI_FIR1_FPSE_SHIFT)
/**
 * @brief DSI FIR1 FEOTPE field
 *
 * Force EoTp error Writing one to this bit forces a EoTp error.
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FEOTPE (1UL << 0x6UL)
#define DSI_FIR1_FEOTPE_SHIFT 0x6UL
#define DSI_FIR1_FEOTPE_MASK (((1ULL << 1) - 1) << DSI_FIR1_FEOTPE_SHIFT)
/**
 * @brief DSI FIR1 FLPWRE field
 *
 * Force LTDC payload write error Writing one to this bit forces a LTDC payload write error.
 *
 * @note offset: 0x7UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FLPWRE (1UL << 0x7UL)
#define DSI_FIR1_FLPWRE_SHIFT 0x7UL
#define DSI_FIR1_FLPWRE_MASK (((1ULL << 1) - 1) << DSI_FIR1_FLPWRE_SHIFT)
/**
 * @brief DSI FIR1 FGCWRE field
 *
 * Force generic command write error Writing one to this bit forces a generic command write error.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FGCWRE (1UL << 0x8UL)
#define DSI_FIR1_FGCWRE_SHIFT 0x8UL
#define DSI_FIR1_FGCWRE_MASK (((1ULL << 1) - 1) << DSI_FIR1_FGCWRE_SHIFT)
/**
 * @brief DSI FIR1 FGPWRE field
 *
 * Force generic payload write error Writing one to this bit forces a generic payload write error.
 *
 * @note offset: 0x9UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FGPWRE (1UL << 0x9UL)
#define DSI_FIR1_FGPWRE_SHIFT 0x9UL
#define DSI_FIR1_FGPWRE_MASK (((1ULL << 1) - 1) << DSI_FIR1_FGPWRE_SHIFT)
/**
 * @brief DSI FIR1 FGPTXE field
 *
 * Force generic payload transmit error Writing one to this bit forces a generic payload transmit error.
 *
 * @note offset: 0xaUL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FGPTXE (1UL << 0xaUL)
#define DSI_FIR1_FGPTXE_SHIFT 0xaUL
#define DSI_FIR1_FGPTXE_MASK (((1ULL << 1) - 1) << DSI_FIR1_FGPTXE_SHIFT)
/**
 * @brief DSI FIR1 FGPRDE field
 *
 * Force generic payload read error Writing one to this bit forces a generic payload read error.
 *
 * @note offset: 0xbUL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FGPRDE (1UL << 0xbUL)
#define DSI_FIR1_FGPRDE_SHIFT 0xbUL
#define DSI_FIR1_FGPRDE_MASK (((1ULL << 1) - 1) << DSI_FIR1_FGPRDE_SHIFT)
/**
 * @brief DSI FIR1 FGPRXE field
 *
 * Force generic payload receive error Writing one to this bit forces a generic payload receive error.
 *
 * @note offset: 0xcUL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FGPRXE (1UL << 0xcUL)
#define DSI_FIR1_FGPRXE_SHIFT 0xcUL
#define DSI_FIR1_FGPRXE_MASK (((1ULL << 1) - 1) << DSI_FIR1_FGPRXE_SHIFT)
/**
 * @brief DSI FIR1 FPBUE field
 *
 * Force payload buffer underflow error Writing one to this bit forces a payload undrflow error.
 *
 * @note offset: 0x13UL
 *       width:  1
 *       access: write-only
 */
#define DSI_FIR1_FPBUE (1UL << 0x13UL)
#define DSI_FIR1_FPBUE_SHIFT 0x13UL
#define DSI_FIR1_FPBUE_MASK (((1ULL << 1) - 1) << DSI_FIR1_FPBUE_SHIFT)


struct dsi_fir1 {
    uint32_t ftohstx:1;
    uint32_t ftolprx:1;
    uint32_t feccse:1;
    uint32_t feccme:1;
    uint32_t fcrce:1;
    uint32_t fpse:1;
    uint32_t feotpe:1;
    uint32_t flpwre:1;
    uint32_t fgcwre:1;
    uint32_t fgpwre:1;
    uint32_t fgptxe:1;
    uint32_t fgprde:1;
    uint32_t fgprxe:1;
    uint32_t reserved0:6;
    uint32_t fpbue:1;
    };

typedef struct dsi_fir1 dsi_fir1_t;
static_assert(sizeof(dsi_fir1_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI DLTRCR register
 *
 * DSI Host data lane timer read configuration register
 *
 *  @note offset: 0xf4UL
 *        width:  32 bits
 */
#define DSI_DLTRCR_REG  0xf4UL

/**
 * @brief DSI DLTRCR MRD_TIME field
 *
 * Maximum read time This field configures the maximum time required to perform a read command in lane byte clock cycles. This register can only be modified when no read command is in progress.
 *
 * @note offset: 0x0UL
 *       width:  15
 *       access: read-write
 */
#define DSI_DLTRCR_MRD_TIME_SHIFT 0x0UL
#define DSI_DLTRCR_MRD_TIME_MASK (((1ULL << 15) - 1) << DSI_DLTRCR_MRD_TIME_SHIFT)


struct dsi_dltrcr {
    uint32_t mrd_time:15;
    };

typedef struct dsi_dltrcr dsi_dltrcr_t;
static_assert(sizeof(dsi_dltrcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VSCR register
 *
 * DSI Host video shadow control register
 *
 *  @note offset: 0x100UL
 *        width:  32 bits
 */
#define DSI_VSCR_REG  0x100UL

/**
 * @brief DSI VSCR EN field
 *
 * Enable When set to 1, DSI Host LTDC interface receives the active configuration from the auxiliary registers. When this bit is set along with the UR bit, the auxiliary registers are automatically updated.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_VSCR_EN (1UL << 0x0UL)
#define DSI_VSCR_EN_SHIFT 0x0UL
#define DSI_VSCR_EN_MASK (((1ULL << 1) - 1) << DSI_VSCR_EN_SHIFT)
/**
 * @brief DSI VSCR UR field
 *
 * Update register When set to 1, the LTDC registers are copied to the auxiliary registers. After copying, this bit is auto cleared.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-write
 */
#define DSI_VSCR_UR (1UL << 0x8UL)
#define DSI_VSCR_UR_SHIFT 0x8UL
#define DSI_VSCR_UR_MASK (((1ULL << 1) - 1) << DSI_VSCR_UR_SHIFT)


struct dsi_vscr {
    uint32_t en:1;
    uint32_t reserved0:7;
    uint32_t ur:1;
    };

typedef struct dsi_vscr dsi_vscr_t;
static_assert(sizeof(dsi_vscr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI LCVCIDR register
 *
 * DSI Host LTDC current VCID register
 *
 *  @note offset: 0x10cUL
 *        width:  32 bits
 */
#define DSI_LCVCIDR_REG  0x10cUL

/**
 * @brief DSI LCVCIDR VCID field
 *
 * Virtual channel ID This field returns the virtual channel ID for the LTDC interface.
 *
 * @note offset: 0x0UL
 *       width:  2
 *       access: read-write
 */
#define DSI_LCVCIDR_VCID_SHIFT 0x0UL
#define DSI_LCVCIDR_VCID_MASK (((1ULL << 2) - 1) << DSI_LCVCIDR_VCID_SHIFT)


struct dsi_lcvcidr {
    uint32_t vcid:2;
    };

typedef struct dsi_lcvcidr dsi_lcvcidr_t;
static_assert(sizeof(dsi_lcvcidr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI LCCCR register
 *
 * DSI Host LTDC current color coding register
 *
 *  @note offset: 0x110UL
 *        width:  32 bits
 */
#define DSI_LCCCR_REG  0x110UL

/**
 * @brief DSI LCCCR COLC field
 *
 * Color coding This field returns the current LTDC interface color coding. 0110-1111: reserved If LTDC interface in command mode is chosen and currently works in the command mode (CMDM=1), then 0110-1111: 24-bit
 *
 * @note offset: 0x0UL
 *       width:  4
 *       access: read-only
 */
#define DSI_LCCCR_COLC_SHIFT 0x0UL
#define DSI_LCCCR_COLC_MASK (((1ULL << 4) - 1) << DSI_LCCCR_COLC_SHIFT)
/**
 * @brief DSI LCCCR LPE field
 *
 * Loosely packed enable This bit returns the current state of the loosely packed variant to 18-bit configurations.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-only
 */
#define DSI_LCCCR_LPE (1UL << 0x8UL)
#define DSI_LCCCR_LPE_SHIFT 0x8UL
#define DSI_LCCCR_LPE_MASK (((1ULL << 1) - 1) << DSI_LCCCR_LPE_SHIFT)


struct dsi_lcccr {
    uint32_t colc:4;
    uint32_t reserved0:4;
    uint32_t lpe:1;
    };

typedef struct dsi_lcccr dsi_lcccr_t;
static_assert(sizeof(dsi_lcccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI LPMCCR register
 *
 * DSI Host low-power mode current configuration register
 *
 *  @note offset: 0x118UL
 *        width:  32 bits
 */
#define DSI_LPMCCR_REG  0x118UL

/**
 * @brief DSI LPMCCR VLPSIZE field
 *
 * VACT largest packet size This field returns the current size, in bytes, of the largest packet that can fit in a line during VACT regions, for the transmission of commands in low-power mode.
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-only
 */
#define DSI_LPMCCR_VLPSIZE_SHIFT 0x0UL
#define DSI_LPMCCR_VLPSIZE_MASK (((1ULL << 8) - 1) << DSI_LPMCCR_VLPSIZE_SHIFT)
/**
 * @brief DSI LPMCCR LPSIZE field
 *
 * Largest packet size This field is returns the current size, in bytes, of the largest packet that can fit in a line during VSA, VBP and VFP regions, for the transmission of commands in low-power mode.
 *
 * @note offset: 0x10UL
 *       width:  8
 *       access: read-only
 */
#define DSI_LPMCCR_LPSIZE_SHIFT 0x10UL
#define DSI_LPMCCR_LPSIZE_MASK (((1ULL << 8) - 1) << DSI_LPMCCR_LPSIZE_SHIFT)


struct dsi_lpmccr {
    uint32_t vlpsize:8;
    uint32_t reserved0:8;
    uint32_t lpsize:8;
    };

typedef struct dsi_lpmccr dsi_lpmccr_t;
static_assert(sizeof(dsi_lpmccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VMCCR register
 *
 * DSI Host video mode current configuration register
 *
 *  @note offset: 0x138UL
 *        width:  32 bits
 */
#define DSI_VMCCR_REG  0x138UL

/**
 * @brief DSI VMCCR VMT field
 *
 * Video mode type This field returns the current video mode transmission type: 1x: Burst mode
 *
 * @note offset: 0x0UL
 *       width:  2
 *       access: read-only
 */
#define DSI_VMCCR_VMT_SHIFT 0x0UL
#define DSI_VMCCR_VMT_MASK (((1ULL << 2) - 1) << DSI_VMCCR_VMT_SHIFT)
/**
 * @brief DSI VMCCR LPVSAE field
 *
 * Low-power vertical sync time enable This bit returns the current state of return to low-power inside the vertical sync time (VSA) period when timing allows.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-only
 */
#define DSI_VMCCR_LPVSAE (1UL << 0x2UL)
#define DSI_VMCCR_LPVSAE_SHIFT 0x2UL
#define DSI_VMCCR_LPVSAE_MASK (((1ULL << 1) - 1) << DSI_VMCCR_LPVSAE_SHIFT)
/**
 * @brief DSI VMCCR LPVBPE field
 *
 * Low-power vertical back-porch enable This bit returns the current state of return to low-power inside the vertical back-porch (VBP) period when timing allows.
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-only
 */
#define DSI_VMCCR_LPVBPE (1UL << 0x3UL)
#define DSI_VMCCR_LPVBPE_SHIFT 0x3UL
#define DSI_VMCCR_LPVBPE_MASK (((1ULL << 1) - 1) << DSI_VMCCR_LPVBPE_SHIFT)
/**
 * @brief DSI VMCCR LPVFPE field
 *
 * Low-power vertical front-porch enable This bit returns the current state of return to low-power inside the vertical front-porch (VFP) period when timing allows.
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: read-only
 */
#define DSI_VMCCR_LPVFPE (1UL << 0x4UL)
#define DSI_VMCCR_LPVFPE_SHIFT 0x4UL
#define DSI_VMCCR_LPVFPE_MASK (((1ULL << 1) - 1) << DSI_VMCCR_LPVFPE_SHIFT)
/**
 * @brief DSI VMCCR LPVAE field
 *
 * Low-power vertical active enable This bit returns the current state of return to low-power inside the vertical active (VACT) period when timing allows.
 *
 * @note offset: 0x5UL
 *       width:  1
 *       access: read-only
 */
#define DSI_VMCCR_LPVAE (1UL << 0x5UL)
#define DSI_VMCCR_LPVAE_SHIFT 0x5UL
#define DSI_VMCCR_LPVAE_MASK (((1ULL << 1) - 1) << DSI_VMCCR_LPVAE_SHIFT)
/**
 * @brief DSI VMCCR LPHBPE field
 *
 * Low-power horizontal back-porch enable This bit returns the current state of return to low-power inside the horizontal back-porch (HBP) period when timing allows.
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: read-only
 */
#define DSI_VMCCR_LPHBPE (1UL << 0x6UL)
#define DSI_VMCCR_LPHBPE_SHIFT 0x6UL
#define DSI_VMCCR_LPHBPE_MASK (((1ULL << 1) - 1) << DSI_VMCCR_LPHBPE_SHIFT)
/**
 * @brief DSI VMCCR LPHFE field
 *
 * Low-power horizontal front-porch enable This bit returns the current state of return to low-power inside the horizontal front-porch (HFP) period when timing allows.
 *
 * @note offset: 0x7UL
 *       width:  1
 *       access: read-only
 */
#define DSI_VMCCR_LPHFE (1UL << 0x7UL)
#define DSI_VMCCR_LPHFE_SHIFT 0x7UL
#define DSI_VMCCR_LPHFE_MASK (((1ULL << 1) - 1) << DSI_VMCCR_LPHFE_SHIFT)
/**
 * @brief DSI VMCCR FBTAAE field
 *
 * Frame BTA acknowledge enable This bit returns the current state of request for an acknowledge response at the end of a frame.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-only
 */
#define DSI_VMCCR_FBTAAE (1UL << 0x8UL)
#define DSI_VMCCR_FBTAAE_SHIFT 0x8UL
#define DSI_VMCCR_FBTAAE_MASK (((1ULL << 1) - 1) << DSI_VMCCR_FBTAAE_SHIFT)
/**
 * @brief DSI VMCCR LPCE field
 *
 * Low-power command enable This bit returns the current command transmission state in low-power mode.
 *
 * @note offset: 0x9UL
 *       width:  1
 *       access: read-only
 */
#define DSI_VMCCR_LPCE (1UL << 0x9UL)
#define DSI_VMCCR_LPCE_SHIFT 0x9UL
#define DSI_VMCCR_LPCE_MASK (((1ULL << 1) - 1) << DSI_VMCCR_LPCE_SHIFT)


struct dsi_vmccr {
    uint32_t vmt:2;
    uint32_t lpvsae:1;
    uint32_t lpvbpe:1;
    uint32_t lpvfpe:1;
    uint32_t lpvae:1;
    uint32_t lphbpe:1;
    uint32_t lphfe:1;
    uint32_t fbtaae:1;
    uint32_t lpce:1;
    };

typedef struct dsi_vmccr dsi_vmccr_t;
static_assert(sizeof(dsi_vmccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VPCCR register
 *
 * DSI Host video packet current configuration register
 *
 *  @note offset: 0x13cUL
 *        width:  32 bits
 */
#define DSI_VPCCR_REG  0x13cUL

/**
 * @brief DSI VPCCR VPSIZE field
 *
 * Video packet size This field returns the number of pixels in a single video packet.
 *
 * @note offset: 0x0UL
 *       width:  14
 *       access: read-only
 */
#define DSI_VPCCR_VPSIZE_SHIFT 0x0UL
#define DSI_VPCCR_VPSIZE_MASK (((1ULL << 14) - 1) << DSI_VPCCR_VPSIZE_SHIFT)


struct dsi_vpccr {
    uint32_t vpsize:14;
    };

typedef struct dsi_vpccr dsi_vpccr_t;
static_assert(sizeof(dsi_vpccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VCCCR register
 *
 * DSI Host video chunks current configuration register
 *
 *  @note offset: 0x140UL
 *        width:  32 bits
 */
#define DSI_VCCCR_REG  0x140UL

/**
 * @brief DSI VCCCR NUMC field
 *
 * Number of chunks This field returns the number of chunks being transmitted during a line period.
 *
 * @note offset: 0x0UL
 *       width:  13
 *       access: read-only
 */
#define DSI_VCCCR_NUMC_SHIFT 0x0UL
#define DSI_VCCCR_NUMC_MASK (((1ULL << 13) - 1) << DSI_VCCCR_NUMC_SHIFT)


struct dsi_vcccr {
    uint32_t numc:13;
    };

typedef struct dsi_vcccr dsi_vcccr_t;
static_assert(sizeof(dsi_vcccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VNPCCR register
 *
 * DSI Host video null packet current configuration register
 *
 *  @note offset: 0x144UL
 *        width:  32 bits
 */
#define DSI_VNPCCR_REG  0x144UL

/**
 * @brief DSI VNPCCR NPSIZE field
 *
 * Null packet size This field returns the number of bytes inside a null packet.
 *
 * @note offset: 0x0UL
 *       width:  13
 *       access: read-only
 */
#define DSI_VNPCCR_NPSIZE_SHIFT 0x0UL
#define DSI_VNPCCR_NPSIZE_MASK (((1ULL << 13) - 1) << DSI_VNPCCR_NPSIZE_SHIFT)


struct dsi_vnpccr {
    uint32_t npsize:13;
    };

typedef struct dsi_vnpccr dsi_vnpccr_t;
static_assert(sizeof(dsi_vnpccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VHSACCR register
 *
 * DSI Host video HSA current configuration register
 *
 *  @note offset: 0x148UL
 *        width:  32 bits
 */
#define DSI_VHSACCR_REG  0x148UL

/**
 * @brief DSI VHSACCR HSA field
 *
 * Horizontal synchronism active duration This fields returns the horizontal synchronism active period in lane byte clock cycles.
 *
 * @note offset: 0x0UL
 *       width:  12
 *       access: read-only
 */
#define DSI_VHSACCR_HSA_SHIFT 0x0UL
#define DSI_VHSACCR_HSA_MASK (((1ULL << 12) - 1) << DSI_VHSACCR_HSA_SHIFT)


struct dsi_vhsaccr {
    uint32_t hsa:12;
    };

typedef struct dsi_vhsaccr dsi_vhsaccr_t;
static_assert(sizeof(dsi_vhsaccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VHBPCCR register
 *
 * DSI Host video HBP current configuration register
 *
 *  @note offset: 0x14cUL
 *        width:  32 bits
 */
#define DSI_VHBPCCR_REG  0x14cUL

/**
 * @brief DSI VHBPCCR HBP field
 *
 * Horizontal back-porch duration This field returns the horizontal back-porch period in lane byte clock cycles.
 *
 * @note offset: 0x0UL
 *       width:  12
 *       access: read-only
 */
#define DSI_VHBPCCR_HBP_SHIFT 0x0UL
#define DSI_VHBPCCR_HBP_MASK (((1ULL << 12) - 1) << DSI_VHBPCCR_HBP_SHIFT)


struct dsi_vhbpccr {
    uint32_t hbp:12;
    };

typedef struct dsi_vhbpccr dsi_vhbpccr_t;
static_assert(sizeof(dsi_vhbpccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VLCCR register
 *
 * DSI Host video line current configuration register
 *
 *  @note offset: 0x150UL
 *        width:  32 bits
 */
#define DSI_VLCCR_REG  0x150UL

/**
 * @brief DSI VLCCR HLINE field
 *
 * Horizontal line duration This field returns the current total of the horizontal line period (HSA+HBP+HACT+HFP) counted in lane byte clock cycles.
 *
 * @note offset: 0x0UL
 *       width:  15
 *       access: read-only
 */
#define DSI_VLCCR_HLINE_SHIFT 0x0UL
#define DSI_VLCCR_HLINE_MASK (((1ULL << 15) - 1) << DSI_VLCCR_HLINE_SHIFT)


struct dsi_vlccr {
    uint32_t hline:15;
    };

typedef struct dsi_vlccr dsi_vlccr_t;
static_assert(sizeof(dsi_vlccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VVSACCR register
 *
 * DSI Host video VSA current configuration register
 *
 *  @note offset: 0x154UL
 *        width:  32 bits
 */
#define DSI_VVSACCR_REG  0x154UL

/**
 * @brief DSI VVSACCR VSA field
 *
 * Vertical synchronism active duration This field returns the current vertical synchronism active period measured in number of horizontal lines.
 *
 * @note offset: 0x0UL
 *       width:  10
 *       access: read-only
 */
#define DSI_VVSACCR_VSA_SHIFT 0x0UL
#define DSI_VVSACCR_VSA_MASK (((1ULL << 10) - 1) << DSI_VVSACCR_VSA_SHIFT)


struct dsi_vvsaccr {
    uint32_t vsa:10;
    };

typedef struct dsi_vvsaccr dsi_vvsaccr_t;
static_assert(sizeof(dsi_vvsaccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VVBPCCR register
 *
 * DSI Host video VBP current configuration register
 *
 *  @note offset: 0x158UL
 *        width:  32 bits
 */
#define DSI_VVBPCCR_REG  0x158UL

/**
 * @brief DSI VVBPCCR VBP field
 *
 * Vertical back-porch duration This field returns the current vertical back-porch period measured in number of horizontal lines.
 *
 * @note offset: 0x0UL
 *       width:  10
 *       access: read-only
 */
#define DSI_VVBPCCR_VBP_SHIFT 0x0UL
#define DSI_VVBPCCR_VBP_MASK (((1ULL << 10) - 1) << DSI_VVBPCCR_VBP_SHIFT)


struct dsi_vvbpccr {
    uint32_t vbp:10;
    };

typedef struct dsi_vvbpccr dsi_vvbpccr_t;
static_assert(sizeof(dsi_vvbpccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VVFPCCR register
 *
 * DSI Host video VFP current configuration register
 *
 *  @note offset: 0x15cUL
 *        width:  32 bits
 */
#define DSI_VVFPCCR_REG  0x15cUL

/**
 * @brief DSI VVFPCCR VFP field
 *
 * Vertical front-porch duration This field returns the current vertical front-porch period measured in number of horizontal lines.
 *
 * @note offset: 0x0UL
 *       width:  10
 *       access: read-only
 */
#define DSI_VVFPCCR_VFP_SHIFT 0x0UL
#define DSI_VVFPCCR_VFP_MASK (((1ULL << 10) - 1) << DSI_VVFPCCR_VFP_SHIFT)


struct dsi_vvfpccr {
    uint32_t vfp:10;
    };

typedef struct dsi_vvfpccr dsi_vvfpccr_t;
static_assert(sizeof(dsi_vvfpccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI VVACCR register
 *
 * DSI Host video VA current configuration register
 *
 *  @note offset: 0x160UL
 *        width:  32 bits
 */
#define DSI_VVACCR_REG  0x160UL

/**
 * @brief DSI VVACCR VA field
 *
 * Vertical active duration This field returns the current vertical active period measured in number of horizontal lines.
 *
 * @note offset: 0x0UL
 *       width:  14
 *       access: read-only
 */
#define DSI_VVACCR_VA_SHIFT 0x0UL
#define DSI_VVACCR_VA_MASK (((1ULL << 14) - 1) << DSI_VVACCR_VA_SHIFT)


struct dsi_vvaccr {
    uint32_t va:14;
    };

typedef struct dsi_vvaccr dsi_vvaccr_t;
static_assert(sizeof(dsi_vvaccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI FBSR register
 *
 * DSI Host FIFO and buffer status register
 *
 *  @note offset: 0x168UL
 *        width:  32 bits
 */
#define DSI_FBSR_REG  0x168UL

/**
 * @brief DSI FBSR VCWFE field
 *
 * Video mode command write FIFO empty This bit indicates the empty status of the video mode write command FIFO:
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_VCWFE (1UL << 0x0UL)
#define DSI_FBSR_VCWFE_SHIFT 0x0UL
#define DSI_FBSR_VCWFE_MASK (((1ULL << 1) - 1) << DSI_FBSR_VCWFE_SHIFT)
/**
 * @brief DSI FBSR VCWFF field
 *
 * Video mode command write FIFO full This bit indicates the full status of the video mode write command FIFO:
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_VCWFF (1UL << 0x1UL)
#define DSI_FBSR_VCWFF_SHIFT 0x1UL
#define DSI_FBSR_VCWFF_MASK (((1ULL << 1) - 1) << DSI_FBSR_VCWFF_SHIFT)
/**
 * @brief DSI FBSR VPWFE field
 *
 * Video mode payload write FIFO empty This bit indicates the empty status of the video mode write payload FIFO:
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_VPWFE (1UL << 0x2UL)
#define DSI_FBSR_VPWFE_SHIFT 0x2UL
#define DSI_FBSR_VPWFE_MASK (((1ULL << 1) - 1) << DSI_FBSR_VPWFE_SHIFT)
/**
 * @brief DSI FBSR VPWFF field
 *
 * Video mode payload write FIFO full This bit indicates the full status of the video mode write payload FIFO:
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_VPWFF (1UL << 0x3UL)
#define DSI_FBSR_VPWFF_SHIFT 0x3UL
#define DSI_FBSR_VPWFF_MASK (((1ULL << 1) - 1) << DSI_FBSR_VPWFF_SHIFT)
/**
 * @brief DSI FBSR ACWFE field
 *
 * Adapted command mode command write FIFO empty This bit indicates the empty status of the adapted command mode write command FIFO:
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_ACWFE (1UL << 0x4UL)
#define DSI_FBSR_ACWFE_SHIFT 0x4UL
#define DSI_FBSR_ACWFE_MASK (((1ULL << 1) - 1) << DSI_FBSR_ACWFE_SHIFT)
/**
 * @brief DSI FBSR ACWFF field
 *
 * Adapted command mode command write FIFO full This bit indicates the full status of the adapted command mode write command FIFO:
 *
 * @note offset: 0x5UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_ACWFF (1UL << 0x5UL)
#define DSI_FBSR_ACWFF_SHIFT 0x5UL
#define DSI_FBSR_ACWFF_MASK (((1ULL << 1) - 1) << DSI_FBSR_ACWFF_SHIFT)
/**
 * @brief DSI FBSR APWFE field
 *
 * Adapted command mode payload write FIFO empty This bit indicates the empty status of the adapted command mode write payload FIFO:
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_APWFE (1UL << 0x6UL)
#define DSI_FBSR_APWFE_SHIFT 0x6UL
#define DSI_FBSR_APWFE_MASK (((1ULL << 1) - 1) << DSI_FBSR_APWFE_SHIFT)
/**
 * @brief DSI FBSR APWFF field
 *
 * Adapted command mode payload write FIFO full This bit indicates the full status of the adapted command mode write payload FIFO:
 *
 * @note offset: 0x7UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_APWFF (1UL << 0x7UL)
#define DSI_FBSR_APWFF_SHIFT 0x7UL
#define DSI_FBSR_APWFF_MASK (((1ULL << 1) - 1) << DSI_FBSR_APWFF_SHIFT)
/**
 * @brief DSI FBSR VPBE field
 *
 * Video mode payload buffer empty This bit indicates the empty status of the video mode payload internal buffer:
 *
 * @note offset: 0x10UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_VPBE (1UL << 0x10UL)
#define DSI_FBSR_VPBE_SHIFT 0x10UL
#define DSI_FBSR_VPBE_MASK (((1ULL << 1) - 1) << DSI_FBSR_VPBE_SHIFT)
/**
 * @brief DSI FBSR VPBF field
 *
 * Video mode payload buffer full This bit indicates the full status of the video mode payload internal buffer:
 *
 * @note offset: 0x11UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_VPBF (1UL << 0x11UL)
#define DSI_FBSR_VPBF_SHIFT 0x11UL
#define DSI_FBSR_VPBF_MASK (((1ULL << 1) - 1) << DSI_FBSR_VPBF_SHIFT)
/**
 * @brief DSI FBSR ACBE field
 *
 * Adapted command mode command buffer empty This bit indicates the empty status of the adapted command mode command internal buffer:
 *
 * @note offset: 0x14UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_ACBE (1UL << 0x14UL)
#define DSI_FBSR_ACBE_SHIFT 0x14UL
#define DSI_FBSR_ACBE_MASK (((1ULL << 1) - 1) << DSI_FBSR_ACBE_SHIFT)
/**
 * @brief DSI FBSR ACBF field
 *
 * Adapted command mode command buffer full This bit indicates the full status of the adapted command mode command internal buffer:
 *
 * @note offset: 0x15UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_ACBF (1UL << 0x15UL)
#define DSI_FBSR_ACBF_SHIFT 0x15UL
#define DSI_FBSR_ACBF_MASK (((1ULL << 1) - 1) << DSI_FBSR_ACBF_SHIFT)
/**
 * @brief DSI FBSR APBE field
 *
 * Adapted command mode payload buffer empty This bit indicates the empty status of the adapted command mode payload internal buffer:
 *
 * @note offset: 0x16UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_APBE (1UL << 0x16UL)
#define DSI_FBSR_APBE_SHIFT 0x16UL
#define DSI_FBSR_APBE_MASK (((1ULL << 1) - 1) << DSI_FBSR_APBE_SHIFT)
/**
 * @brief DSI FBSR APBF field
 *
 * Adapted command mode payload buffer full This bit indicates the full status of the adapted command mode payload internal buffer:
 *
 * @note offset: 0x17UL
 *       width:  1
 *       access: read-only
 */
#define DSI_FBSR_APBF (1UL << 0x17UL)
#define DSI_FBSR_APBF_SHIFT 0x17UL
#define DSI_FBSR_APBF_MASK (((1ULL << 1) - 1) << DSI_FBSR_APBF_SHIFT)


struct dsi_fbsr {
    uint32_t vcwfe:1;
    uint32_t vcwff:1;
    uint32_t vpwfe:1;
    uint32_t vpwff:1;
    uint32_t acwfe:1;
    uint32_t acwff:1;
    uint32_t apwfe:1;
    uint32_t apwff:1;
    uint32_t reserved0:8;
    uint32_t vpbe:1;
    uint32_t vpbf:1;
    uint32_t reserved1:2;
    uint32_t acbe:1;
    uint32_t acbf:1;
    uint32_t apbe:1;
    uint32_t apbf:1;
    };

typedef struct dsi_fbsr dsi_fbsr_t;
static_assert(sizeof(dsi_fbsr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI WCFGR register
 *
 * DSI Wrapper configuration register
 *
 *  @note offset: 0x400UL
 *        width:  32 bits
 */
#define DSI_WCFGR_REG  0x400UL

/**
 * @brief DSI WCFGR DSIM field
 *
 * DSI mode This bit selects the mode for the video transmission. This bit must only be changed when DSI Host is stopped (DSI_CR.EN = 0).
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WCFGR_DSIM (1UL << 0x0UL)
#define DSI_WCFGR_DSIM_SHIFT 0x0UL
#define DSI_WCFGR_DSIM_MASK (((1ULL << 1) - 1) << DSI_WCFGR_DSIM_SHIFT)
/**
 * @brief DSI WCFGR COLMUX field
 *
 * Color multiplexing This bit selects the color multiplexing used by DSI Host. This field must only be changed when DSI is stopped (DSI_WCR.DSIEN = 0 and DSI_CR.ENÂ =Â 0).
 *
 * @note offset: 0x1UL
 *       width:  3
 *       access: read-write
 */
#define DSI_WCFGR_COLMUX_SHIFT 0x1UL
#define DSI_WCFGR_COLMUX_MASK (((1ULL << 3) - 1) << DSI_WCFGR_COLMUX_SHIFT)
/**
 * @brief DSI WCFGR TESRC field
 *
 * TE source This bit selects the tearing effect (TE) source. This bit must only be changed when DSI Host is stopped (DSI_CR.EN = 0).
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WCFGR_TESRC (1UL << 0x4UL)
#define DSI_WCFGR_TESRC_SHIFT 0x4UL
#define DSI_WCFGR_TESRC_MASK (((1ULL << 1) - 1) << DSI_WCFGR_TESRC_SHIFT)
/**
 * @brief DSI WCFGR TEPOL field
 *
 * TE polarity This bit selects the polarity of the external pin tearing effect (TE) source. This bit must only be changed when DSI Host is stopped (DSI_CR.EN = 0).
 *
 * @note offset: 0x5UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WCFGR_TEPOL (1UL << 0x5UL)
#define DSI_WCFGR_TEPOL_SHIFT 0x5UL
#define DSI_WCFGR_TEPOL_MASK (((1ULL << 1) - 1) << DSI_WCFGR_TEPOL_SHIFT)
/**
 * @brief DSI WCFGR AR field
 *
 * Automatic refresh This bit selects the refresh mode in DBI mode. This bit must only be changed when DSI Host is stopped (DSI_CR.EN = 0).
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WCFGR_AR (1UL << 0x6UL)
#define DSI_WCFGR_AR_SHIFT 0x6UL
#define DSI_WCFGR_AR_MASK (((1ULL << 1) - 1) << DSI_WCFGR_AR_SHIFT)
/**
 * @brief DSI WCFGR VSPOL field
 *
 * VSync polarity This bit selects the VSync edge on which the LTDC is halted. This bit must only be changed when DSI is stopped (DSI_WCR.DSIEN = 0 and DSI_CR.ENÂ =Â 0).
 *
 * @note offset: 0x7UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WCFGR_VSPOL (1UL << 0x7UL)
#define DSI_WCFGR_VSPOL_SHIFT 0x7UL
#define DSI_WCFGR_VSPOL_MASK (((1ULL << 1) - 1) << DSI_WCFGR_VSPOL_SHIFT)


struct dsi_wcfgr {
    uint32_t dsim:1;
    uint32_t colmux:3;
    uint32_t tesrc:1;
    uint32_t tepol:1;
    uint32_t ar:1;
    uint32_t vspol:1;
    };

typedef struct dsi_wcfgr dsi_wcfgr_t;
static_assert(sizeof(dsi_wcfgr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI WCR register
 *
 * DSI Wrapper control register
 *
 *  @note offset: 0x404UL
 *        width:  32 bits
 */
#define DSI_WCR_REG  0x404UL

/**
 * @brief DSI WCR COLM field
 *
 * Color mode This bit controls the display color mode in video mode.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WCR_COLM (1UL << 0x0UL)
#define DSI_WCR_COLM_SHIFT 0x0UL
#define DSI_WCR_COLM_MASK (((1ULL << 1) - 1) << DSI_WCR_COLM_SHIFT)
/**
 * @brief DSI WCR SHTDN field
 *
 * Shutdown This bit controls the display shutdown in video mode.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WCR_SHTDN (1UL << 0x1UL)
#define DSI_WCR_SHTDN_SHIFT 0x1UL
#define DSI_WCR_SHTDN_MASK (((1ULL << 1) - 1) << DSI_WCR_SHTDN_SHIFT)
/**
 * @brief DSI WCR LTDCEN field
 *
 * LTDC enable This bit enables the LTDC for a frame transfer in adapted command mode.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WCR_LTDCEN (1UL << 0x2UL)
#define DSI_WCR_LTDCEN_SHIFT 0x2UL
#define DSI_WCR_LTDCEN_MASK (((1ULL << 1) - 1) << DSI_WCR_LTDCEN_SHIFT)
/**
 * @brief DSI WCR DSIEN field
 *
 * DSI enable This bit enables the DSI Wrapper.
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WCR_DSIEN (1UL << 0x3UL)
#define DSI_WCR_DSIEN_SHIFT 0x3UL
#define DSI_WCR_DSIEN_MASK (((1ULL << 1) - 1) << DSI_WCR_DSIEN_SHIFT)


struct dsi_wcr {
    uint32_t colm:1;
    uint32_t shtdn:1;
    uint32_t ltdcen:1;
    uint32_t dsien:1;
    };

typedef struct dsi_wcr dsi_wcr_t;
static_assert(sizeof(dsi_wcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI WIER register
 *
 * DSI Wrapper interrupt enable register
 *
 *  @note offset: 0x408UL
 *        width:  32 bits
 */
#define DSI_WIER_REG  0x408UL

/**
 * @brief DSI WIER TEIE field
 *
 * Tearing effect interrupt enable This bit enables the tearing effect interrupt.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WIER_TEIE (1UL << 0x0UL)
#define DSI_WIER_TEIE_SHIFT 0x0UL
#define DSI_WIER_TEIE_MASK (((1ULL << 1) - 1) << DSI_WIER_TEIE_SHIFT)
/**
 * @brief DSI WIER ERIE field
 *
 * End of refresh interrupt enable This bit enables the end of refresh interrupt.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WIER_ERIE (1UL << 0x1UL)
#define DSI_WIER_ERIE_SHIFT 0x1UL
#define DSI_WIER_ERIE_MASK (((1ULL << 1) - 1) << DSI_WIER_ERIE_SHIFT)
/**
 * @brief DSI WIER PLLLIE field
 *
 * PLL lock interrupt enable This bit enables the PLL lock interrupt.
 *
 * @note offset: 0x9UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WIER_PLLLIE (1UL << 0x9UL)
#define DSI_WIER_PLLLIE_SHIFT 0x9UL
#define DSI_WIER_PLLLIE_MASK (((1ULL << 1) - 1) << DSI_WIER_PLLLIE_SHIFT)
/**
 * @brief DSI WIER PLLUIE field
 *
 * PLL unlock interrupt enable This bit enables the PLL unlock interrupt.
 *
 * @note offset: 0xaUL
 *       width:  1
 *       access: read-write
 */
#define DSI_WIER_PLLUIE (1UL << 0xaUL)
#define DSI_WIER_PLLUIE_SHIFT 0xaUL
#define DSI_WIER_PLLUIE_MASK (((1ULL << 1) - 1) << DSI_WIER_PLLUIE_SHIFT)


struct dsi_wier {
    uint32_t teie:1;
    uint32_t erie:1;
    uint32_t reserved0:7;
    uint32_t plllie:1;
    uint32_t plluie:1;
    };

typedef struct dsi_wier dsi_wier_t;
static_assert(sizeof(dsi_wier_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI WISR register
 *
 * DSI Wrapper interrupt and status register
 *
 *  @note offset: 0x40cUL
 *        width:  32 bits
 */
#define DSI_WISR_REG  0x40cUL

/**
 * @brief DSI WISR TEIF field
 *
 * Tearing effect interrupt flag This bit is set when a tearing effect event occurs.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-only
 */
#define DSI_WISR_TEIF (1UL << 0x0UL)
#define DSI_WISR_TEIF_SHIFT 0x0UL
#define DSI_WISR_TEIF_MASK (((1ULL << 1) - 1) << DSI_WISR_TEIF_SHIFT)
/**
 * @brief DSI WISR ERIF field
 *
 * End of refresh interrupt flag This bit is set when the transfer of a frame in adapted command mode is finished.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-only
 */
#define DSI_WISR_ERIF (1UL << 0x1UL)
#define DSI_WISR_ERIF_SHIFT 0x1UL
#define DSI_WISR_ERIF_MASK (((1ULL << 1) - 1) << DSI_WISR_ERIF_SHIFT)
/**
 * @brief DSI WISR BUSY field
 *
 * Busy flag This bit is set when the transfer of a frame in adapted command mode is ongoing.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-only
 */
#define DSI_WISR_BUSY (1UL << 0x2UL)
#define DSI_WISR_BUSY_SHIFT 0x2UL
#define DSI_WISR_BUSY_MASK (((1ULL << 1) - 1) << DSI_WISR_BUSY_SHIFT)
/**
 * @brief DSI WISR PLLLS field
 *
 * PLL lock status This bit is set when the PLL is locked and cleared when it is unlocked.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-only
 */
#define DSI_WISR_PLLLS (1UL << 0x8UL)
#define DSI_WISR_PLLLS_SHIFT 0x8UL
#define DSI_WISR_PLLLS_MASK (((1ULL << 1) - 1) << DSI_WISR_PLLLS_SHIFT)
/**
 * @brief DSI WISR PLLLIF field
 *
 * PLL lock interrupt flag This bit is set when the PLL becomes locked.
 *
 * @note offset: 0x9UL
 *       width:  1
 *       access: read-only
 */
#define DSI_WISR_PLLLIF (1UL << 0x9UL)
#define DSI_WISR_PLLLIF_SHIFT 0x9UL
#define DSI_WISR_PLLLIF_MASK (((1ULL << 1) - 1) << DSI_WISR_PLLLIF_SHIFT)
/**
 * @brief DSI WISR PLLUIF field
 *
 * PLL unlock interrupt flag This bit is set when the PLL becomes unlocked.
 *
 * @note offset: 0xaUL
 *       width:  1
 *       access: read-only
 */
#define DSI_WISR_PLLUIF (1UL << 0xaUL)
#define DSI_WISR_PLLUIF_SHIFT 0xaUL
#define DSI_WISR_PLLUIF_MASK (((1ULL << 1) - 1) << DSI_WISR_PLLUIF_SHIFT)


struct dsi_wisr {
    uint32_t teif:1;
    uint32_t erif:1;
    uint32_t busy:1;
    uint32_t reserved0:5;
    uint32_t pllls:1;
    uint32_t plllif:1;
    uint32_t plluif:1;
    };

typedef struct dsi_wisr dsi_wisr_t;
static_assert(sizeof(dsi_wisr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI WIFCR register
 *
 * DSI Wrapper interrupt flag clear register
 *
 *  @note offset: 0x410UL
 *        width:  32 bits
 */
#define DSI_WIFCR_REG  0x410UL

/**
 * @brief DSI WIFCR CTEIF field
 *
 * Clear tearing effect interrupt flag Write 1 clears the TEIF flag in the DSI_WSR register.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: write-only
 */
#define DSI_WIFCR_CTEIF (1UL << 0x0UL)
#define DSI_WIFCR_CTEIF_SHIFT 0x0UL
#define DSI_WIFCR_CTEIF_MASK (((1ULL << 1) - 1) << DSI_WIFCR_CTEIF_SHIFT)
/**
 * @brief DSI WIFCR CERIF field
 *
 * Clear end of refresh interrupt flag Write 1 clears the ERIF flag in the DSI_WSR register.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: write-only
 */
#define DSI_WIFCR_CERIF (1UL << 0x1UL)
#define DSI_WIFCR_CERIF_SHIFT 0x1UL
#define DSI_WIFCR_CERIF_MASK (((1ULL << 1) - 1) << DSI_WIFCR_CERIF_SHIFT)
/**
 * @brief DSI WIFCR CPLLLIF field
 *
 * Clear PLL lock interrupt flag Write 1 clears the PLLLIF flag in the DSI_WSR register.
 *
 * @note offset: 0x9UL
 *       width:  1
 *       access: write-only
 */
#define DSI_WIFCR_CPLLLIF (1UL << 0x9UL)
#define DSI_WIFCR_CPLLLIF_SHIFT 0x9UL
#define DSI_WIFCR_CPLLLIF_MASK (((1ULL << 1) - 1) << DSI_WIFCR_CPLLLIF_SHIFT)
/**
 * @brief DSI WIFCR CPLLUIF field
 *
 * Clear PLL unlock interrupt flag Write 1 clears the PLLUIF flag in the DSI_WSR register.
 *
 * @note offset: 0xaUL
 *       width:  1
 *       access: write-only
 */
#define DSI_WIFCR_CPLLUIF (1UL << 0xaUL)
#define DSI_WIFCR_CPLLUIF_SHIFT 0xaUL
#define DSI_WIFCR_CPLLUIF_MASK (((1ULL << 1) - 1) << DSI_WIFCR_CPLLUIF_SHIFT)


struct dsi_wifcr {
    uint32_t cteif:1;
    uint32_t cerif:1;
    uint32_t reserved0:7;
    uint32_t cplllif:1;
    uint32_t cplluif:1;
    };

typedef struct dsi_wifcr dsi_wifcr_t;
static_assert(sizeof(dsi_wifcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI WPCR0 register
 *
 * DSI Wrapper PHY configuration register 0
 *
 *  @note offset: 0x418UL
 *        width:  32 bits
 */
#define DSI_WPCR0_REG  0x418UL

/**
 * @brief DSI WPCR0 SWCL field
 *
 * Swap clock lane pins This bit swaps the pins on clock lane.
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WPCR0_SWCL (1UL << 0x6UL)
#define DSI_WPCR0_SWCL_SHIFT 0x6UL
#define DSI_WPCR0_SWCL_MASK (((1ULL << 1) - 1) << DSI_WPCR0_SWCL_SHIFT)
/**
 * @brief DSI WPCR0 SWDL0 field
 *
 * Swap data lane 0 pins This bit swaps the pins on data lane 0.
 *
 * @note offset: 0x7UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WPCR0_SWDL0 (1UL << 0x7UL)
#define DSI_WPCR0_SWDL0_SHIFT 0x7UL
#define DSI_WPCR0_SWDL0_MASK (((1ULL << 1) - 1) << DSI_WPCR0_SWDL0_SHIFT)
/**
 * @brief DSI WPCR0 SWDL1 field
 *
 * Swap data lane 1 pins This bit swaps the pins on clock lane.
 *
 * @note offset: 0x8UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WPCR0_SWDL1 (1UL << 0x8UL)
#define DSI_WPCR0_SWDL1_SHIFT 0x8UL
#define DSI_WPCR0_SWDL1_MASK (((1ULL << 1) - 1) << DSI_WPCR0_SWDL1_SHIFT)
/**
 * @brief DSI WPCR0 FTXSMCL field
 *
 * Force in TX Stop mode the clock lane This bit forces the clock lane in TX stop mode. It is used to initialize a lane module in transmit mode. It causes the lane module to immediately jump to transmit control mode and to begin transmitting a stop state (LP-11). It can be used to go back in TX mode after a wrong BTA sequence.
 *
 * @note offset: 0xcUL
 *       width:  1
 *       access: read-write
 */
#define DSI_WPCR0_FTXSMCL (1UL << 0xcUL)
#define DSI_WPCR0_FTXSMCL_SHIFT 0xcUL
#define DSI_WPCR0_FTXSMCL_MASK (((1ULL << 1) - 1) << DSI_WPCR0_FTXSMCL_SHIFT)
/**
 * @brief DSI WPCR0 FTXSMDL field
 *
 * Force in TX Stop mode the data lanes This bit forces the data lanes in TX stop mode. It is used to initialize a lane module in transmit mode. It causes the lane module to immediately jump to transmit control mode and to begin transmitting a stop state (LP-11). It can be used to go back in TX mode after a wrong BTA sequence.
 *
 * @note offset: 0xdUL
 *       width:  1
 *       access: read-write
 */
#define DSI_WPCR0_FTXSMDL (1UL << 0xdUL)
#define DSI_WPCR0_FTXSMDL_SHIFT 0xdUL
#define DSI_WPCR0_FTXSMDL_MASK (((1ULL << 1) - 1) << DSI_WPCR0_FTXSMDL_SHIFT)


struct dsi_wpcr0 {
    uint32_t reserved0:6;
    uint32_t swcl:1;
    uint32_t swdl0:1;
    uint32_t swdl1:1;
    uint32_t reserved1:3;
    uint32_t ftxsmcl:1;
    uint32_t ftxsmdl:1;
    };

typedef struct dsi_wpcr0 dsi_wpcr0_t;
static_assert(sizeof(dsi_wpcr0_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI WRPCR register
 *
 * DSI Wrapper regulator and PLL control register
 *
 *  @note offset: 0x430UL
 *        width:  32 bits
 */
#define DSI_WRPCR_REG  0x430UL

/**
 * @brief DSI WRPCR PLLEN field
 *
 * PLL enable This bit enables the D-PHY PLL.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define DSI_WRPCR_PLLEN (1UL << 0x0UL)
#define DSI_WRPCR_PLLEN_SHIFT 0x0UL
#define DSI_WRPCR_PLLEN_MASK (((1ULL << 1) - 1) << DSI_WRPCR_PLLEN_SHIFT)
/**
 * @brief DSI WRPCR NDIV field
 *
 * PLL loop division factor This field configures the PLL loop division factor. 2: PLL loop divided by 2x2 ... 511: PLL loop divided by 511x2
 *
 * @note offset: 0x2UL
 *       width:  9
 *       access: read-write
 */
#define DSI_WRPCR_NDIV_SHIFT 0x2UL
#define DSI_WRPCR_NDIV_MASK (((1ULL << 9) - 1) << DSI_WRPCR_NDIV_SHIFT)
/**
 * @brief DSI WRPCR IDF field
 *
 * PLL input division factor This field configures the PLL input division factor. 2: PLL input divided by 2 ... 511: PLL input divided by 511
 *
 * @note offset: 0xbUL
 *       width:  9
 *       access: read-write
 */
#define DSI_WRPCR_IDF_SHIFT 0xbUL
#define DSI_WRPCR_IDF_MASK (((1ULL << 9) - 1) << DSI_WRPCR_IDF_SHIFT)
/**
 * @brief DSI WRPCR ODF field
 *
 * PLL output division factor This field configures the PLL output division factor. 2: PLL output divided by 2 ... 511: PLL output divided by 511
 *
 * @note offset: 0x14UL
 *       width:  9
 *       access: read-write
 */
#define DSI_WRPCR_ODF_SHIFT 0x14UL
#define DSI_WRPCR_ODF_MASK (((1ULL << 9) - 1) << DSI_WRPCR_ODF_SHIFT)


struct dsi_wrpcr {
    uint32_t pllen:1;
    uint32_t reserved0:1;
    uint32_t ndiv:9;
    uint32_t idf:9;
    uint32_t odf:9;
    };

typedef struct dsi_wrpcr dsi_wrpcr_t;
static_assert(sizeof(dsi_wrpcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI BCFGR register
 *
 * DSI bias configuration register
 *
 *  @note offset: 0x808UL
 *        width:  32 bits
 */
#define DSI_BCFGR_REG  0x808UL

/**
 * @brief DSI BCFGR PWRUP field
 *
 * Power-up This bit powers-up the reference bias for the MIPI D-PHY
 *
 * @note offset: 0x6UL
 *       width:  1
 *       access: read-write
 */
#define DSI_BCFGR_PWRUP (1UL << 0x6UL)
#define DSI_BCFGR_PWRUP_SHIFT 0x6UL
#define DSI_BCFGR_PWRUP_MASK (((1ULL << 1) - 1) << DSI_BCFGR_PWRUP_SHIFT)


struct dsi_bcfgr {
    uint32_t reserved0:6;
    uint32_t pwrup:1;
    };

typedef struct dsi_bcfgr dsi_bcfgr_t;
static_assert(sizeof(dsi_bcfgr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI DPCBCR register
 *
 * DSI D-PHY clock band control register
 *
 *  @note offset: 0xc04UL
 *        width:  32 bits
 */
#define DSI_DPCBCR_REG  0xc04UL

/**
 * @brief DSI DPCBCR BC field
 *
 * Band control This field selects the frequency band used by the D-PHY. Others: Reserved
 *
 * @note offset: 0x3UL
 *       width:  5
 *       access: read-write
 */
#define DSI_DPCBCR_BC_SHIFT 0x3UL
#define DSI_DPCBCR_BC_MASK (((1ULL << 5) - 1) << DSI_DPCBCR_BC_SHIFT)


struct dsi_dpcbcr {
    uint32_t reserved0:3;
    uint32_t bc:5;
    };

typedef struct dsi_dpcbcr dsi_dpcbcr_t;
static_assert(sizeof(dsi_dpcbcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI DPCSRCR register
 *
 * DSI D-PHY clock skew rate control register
 *
 *  @note offset: 0xc34UL
 *        width:  32 bits
 */
#define DSI_DPCSRCR_REG  0xc34UL

/**
 * @brief DSI DPCSRCR SRC field
 *
 * Slew rate control This field selects the slew rate for HS-TX speed. Others: Reserved
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define DSI_DPCSRCR_SRC_SHIFT 0x0UL
#define DSI_DPCSRCR_SRC_MASK (((1ULL << 8) - 1) << DSI_DPCSRCR_SRC_SHIFT)


struct dsi_dpcsrcr {
    uint32_t src:8;
    };

typedef struct dsi_dpcsrcr dsi_dpcsrcr_t;
static_assert(sizeof(dsi_dpcsrcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI DPDL0BCR register
 *
 * DSI D-PHY data lane 0 band control register
 *
 *  @note offset: 0xc70UL
 *        width:  32 bits
 */
#define DSI_DPDL0BCR_REG  0xc70UL

/**
 * @brief DSI DPDL0BCR BC field
 *
 * Band control This field selects the frequency band used by the D-PHY. Others: Reserved
 *
 * @note offset: 0x0UL
 *       width:  5
 *       access: read-write
 */
#define DSI_DPDL0BCR_BC_SHIFT 0x0UL
#define DSI_DPDL0BCR_BC_MASK (((1ULL << 5) - 1) << DSI_DPDL0BCR_BC_SHIFT)


struct dsi_dpdl0bcr {
    uint32_t bc:5;
    };

typedef struct dsi_dpdl0bcr dsi_dpdl0bcr_t;
static_assert(sizeof(dsi_dpdl0bcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI DPDL0SRCR register
 *
 * DSI D-PHY data lane 0 skew rate control register
 *
 *  @note offset: 0xca0UL
 *        width:  32 bits
 */
#define DSI_DPDL0SRCR_REG  0xca0UL

/**
 * @brief DSI DPDL0SRCR SRC field
 *
 * Slew rate control This field selects the slew rate for HS-TX speed. Others: Reserved
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define DSI_DPDL0SRCR_SRC_SHIFT 0x0UL
#define DSI_DPDL0SRCR_SRC_MASK (((1ULL << 8) - 1) << DSI_DPDL0SRCR_SRC_SHIFT)


struct dsi_dpdl0srcr {
    uint32_t src:8;
    };

typedef struct dsi_dpdl0srcr dsi_dpdl0srcr_t;
static_assert(sizeof(dsi_dpdl0srcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI DPDL1BCR register
 *
 * DSI D-PHY data lane 1 band control register
 *
 *  @note offset: 0xd08UL
 *        width:  32 bits
 */
#define DSI_DPDL1BCR_REG  0xd08UL

/**
 * @brief DSI DPDL1BCR BC field
 *
 * Band control This field selects the frequency band used by the D-PHY. Others: Reserved
 *
 * @note offset: 0x0UL
 *       width:  5
 *       access: read-write
 */
#define DSI_DPDL1BCR_BC_SHIFT 0x0UL
#define DSI_DPDL1BCR_BC_MASK (((1ULL << 5) - 1) << DSI_DPDL1BCR_BC_SHIFT)


struct dsi_dpdl1bcr {
    uint32_t bc:5;
    };

typedef struct dsi_dpdl1bcr dsi_dpdl1bcr_t;
static_assert(sizeof(dsi_dpdl1bcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief DSI DPDL1SRCR register
 *
 * DSI D-PHY data lane 1 skew rate control register
 *
 *  @note offset: 0xd38UL
 *        width:  32 bits
 */
#define DSI_DPDL1SRCR_REG  0xd38UL

/**
 * @brief DSI DPDL1SRCR SRC field
 *
 * Slew rate control This field selects the slew rate for HS-TX speed. Others: Reserved
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define DSI_DPDL1SRCR_SRC_SHIFT 0x0UL
#define DSI_DPDL1SRCR_SRC_MASK (((1ULL << 8) - 1) << DSI_DPDL1SRCR_SRC_SHIFT)


struct dsi_dpdl1srcr {
    uint32_t src:8;
    };

typedef struct dsi_dpdl1srcr dsi_dpdl1srcr_t;
static_assert(sizeof(dsi_dpdl1srcr_t) == sizeof(uint32_t), "Invalid register description");

/*@

    predicate dsi_is_writable_register(ℤ r) = (
        r == 0x4 ||
        r == 0x8 ||
        r == 0xc ||
        r == 0x10 ||
        r == 0x14 ||
        r == 0x18 ||
        r == 0x2c ||
        r == 0x30 ||
        r == 0x34 ||
        r == 0x38 ||
        r == 0x3c ||
        r == 0x40 ||
        r == 0x44 ||
        r == 0x48 ||
        r == 0x4c ||
        r == 0x50 ||
        r == 0x54 ||
        r == 0x58 ||
        r == 0x5c ||
        r == 0x60 ||
        r == 0x64 ||
        r == 0x68 ||
        r == 0x6c ||
        r == 0x70 ||
        r == 0x78 ||
        r == 0x7c ||
        r == 0x80 ||
        r == 0x84 ||
        r == 0x88 ||
        r == 0x8c ||
        r == 0x94 ||
        r == 0x98 ||
        r == 0x9c ||
        r == 0xa0 ||
        r == 0xa4 ||
        r == 0xa8 ||
        r == 0xac ||
        r == 0xc4 ||
        r == 0xc8 ||
        r == 0xf4 ||
        r == 0x100 ||
        r == 0x10c ||
        r == 0x400 ||
        r == 0x404 ||
        r == 0x408 ||
        r == 0x418 ||
        r == 0x430 ||
        r == 0x808 ||
        r == 0xc04 ||
        r == 0xc34 ||
        r == 0xc70 ||
        r == 0xca0 ||
        r == 0xd08 ||
        r == 0xd38 ||
        \false
    );

    predicate dsi_is_readable_register(ℤ r) = (
        r == 0x0 ||
        r == 0x4 ||
        r == 0x8 ||
        r == 0xc ||
        r == 0x10 ||
        r == 0x14 ||
        r == 0x18 ||
        r == 0x2c ||
        r == 0x30 ||
        r == 0x34 ||
        r == 0x38 ||
        r == 0x3c ||
        r == 0x40 ||
        r == 0x44 ||
        r == 0x48 ||
        r == 0x4c ||
        r == 0x50 ||
        r == 0x54 ||
        r == 0x58 ||
        r == 0x5c ||
        r == 0x60 ||
        r == 0x64 ||
        r == 0x68 ||
        r == 0x6c ||
        r == 0x70 ||
        r == 0x74 ||
        r == 0x78 ||
        r == 0x7c ||
        r == 0x80 ||
        r == 0x84 ||
        r == 0x88 ||
        r == 0x8c ||
        r == 0x94 ||
        r == 0x98 ||
        r == 0x9c ||
        r == 0xa0 ||
        r == 0xa4 ||
        r == 0xa8 ||
        r == 0xac ||
        r == 0xb0 ||
        r == 0xbc ||
        r == 0xc0 ||
        r == 0xc4 ||
        r == 0xc8 ||
        r == 0xf4 ||
        r == 0x100 ||
        r == 0x10c ||
        r == 0x110 ||
        r == 0x118 ||
        r == 0x138 ||
        r == 0x13c ||
        r == 0x140 ||
        r == 0x144 ||
        r == 0x148 ||
        r == 0x14c ||
        r == 0x150 ||
        r == 0x154 ||
        r == 0x158 ||
        r == 0x15c ||
        r == 0x160 ||
        r == 0x168 ||
        r == 0x400 ||
        r == 0x404 ||
        r == 0x408 ||
        r == 0x40c ||
        r == 0x418 ||
        r == 0x430 ||
        r == 0x808 ||
        r == 0xc04 ||
        r == 0xc34 ||
        r == 0xc70 ||
        r == 0xca0 ||
        r == 0xd08 ||
        r == 0xd38 ||
        \false
    );

    predicate dsi_register_exists(ℤ r) = (
        r == 0x0 ||
        r == 0x4 ||
        r == 0x8 ||
        r == 0xc ||
        r == 0x10 ||
        r == 0x14 ||
        r == 0x18 ||
        r == 0x2c ||
        r == 0x30 ||
        r == 0x34 ||
        r == 0x38 ||
        r == 0x3c ||
        r == 0x40 ||
        r == 0x44 ||
        r == 0x48 ||
        r == 0x4c ||
        r == 0x50 ||
        r == 0x54 ||
        r == 0x58 ||
        r == 0x5c ||
        r == 0x60 ||
        r == 0x64 ||
        r == 0x68 ||
        r == 0x6c ||
        r == 0x70 ||
        r == 0x74 ||
        r == 0x78 ||
        r == 0x7c ||
        r == 0x80 ||
        r == 0x84 ||
        r == 0x88 ||
        r == 0x8c ||
        r == 0x94 ||
        r == 0x98 ||
        r == 0x9c ||
        r == 0xa0 ||
        r == 0xa4 ||
        r == 0xa8 ||
        r == 0xac ||
        r == 0xb0 ||
        r == 0xbc ||
        r == 0xc0 ||
        r == 0xc4 ||
        r == 0xc8 ||
        r == 0xd8 ||
        r == 0xdc ||
        r == 0xf4 ||
        r == 0x100 ||
        r == 0x10c ||
        r == 0x110 ||
        r == 0x118 ||
        r == 0x138 ||
        r == 0x13c ||
        r == 0x140 ||
        r == 0x144 ||
        r == 0x148 ||
        r == 0x14c ||
        r == 0x150 ||
        r == 0x154 ||
        r == 0x158 ||
        r == 0x15c ||
        r == 0x160 ||
        r == 0x168 ||
        r == 0x400 ||
        r == 0x404 ||
        r == 0x408 ||
        r == 0x40c ||
        r == 0x410 ||
        r == 0x418 ||
        r == 0x430 ||
        r == 0x808 ||
        r == 0xc04 ||
        r == 0xc34 ||
        r == 0xc70 ||
        r == 0xca0 ||
        r == 0xd08 ||
        r == 0xd38 ||
        \false
    );


*/

#endif /* __STM32U599_DSI_DEFS_H */
