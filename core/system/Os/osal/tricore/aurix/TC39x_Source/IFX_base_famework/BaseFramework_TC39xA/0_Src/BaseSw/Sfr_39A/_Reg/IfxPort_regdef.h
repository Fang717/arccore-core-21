/**
 * \file IfxPort_regdef.h
 * \brief
 * \copyright Copyright (c) 2014 Infineon Technologies AG. All rights reserved.
 *
 * Version: MCMCAN_TC39x_MCSFR.xml dated 07.08.2014
 * Specification: TBD
 * MAY BE CHANGED BY USER [yes/no]: No
 *
 *                                 IMPORTANT NOTICE
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Port Port
 * \ingroup IfxLld
 *
 * \defgroup IfxLld_Port_Bitfields Bitfields
 * \ingroup IfxLld_Port
 *
 * \defgroup IfxLld_Port_union Union
 * \ingroup IfxLld_Port
 *
 * \defgroup IfxLld_Port_struct Struct
 * \ingroup IfxLld_Port
 *
 */
#ifndef IFXPORT_REGDEF_H
#define IFXPORT_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/
/** \addtogroup IfxLld_Port_Bitfields
 * \{  */

/** \\brief  Port Access Enable Register 0 */
typedef struct _Ifx_P_ACCEN0_Bits
{
    unsigned int EN0 : 1;                     /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
    unsigned int EN1 : 1;                     /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
    unsigned int EN2 : 1;                     /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
    unsigned int EN3 : 1;                     /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
    unsigned int EN4 : 1;                     /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
    unsigned int EN5 : 1;                     /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
    unsigned int EN6 : 1;                     /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
    unsigned int EN7 : 1;                     /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
    unsigned int EN8 : 1;                     /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
    unsigned int EN9 : 1;                     /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
    unsigned int EN10 : 1;                    /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
    unsigned int EN11 : 1;                    /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
    unsigned int EN12 : 1;                    /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
    unsigned int EN13 : 1;                    /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
    unsigned int EN14 : 1;                    /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
    unsigned int EN15 : 1;                    /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
    unsigned int EN16 : 1;                    /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
    unsigned int EN17 : 1;                    /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
    unsigned int EN18 : 1;                    /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
    unsigned int EN19 : 1;                    /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
    unsigned int EN20 : 1;                    /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
    unsigned int EN21 : 1;                    /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
    unsigned int EN22 : 1;                    /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
    unsigned int EN23 : 1;                    /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
    unsigned int EN24 : 1;                    /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
    unsigned int EN25 : 1;                    /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
    unsigned int EN26 : 1;                    /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
    unsigned int EN27 : 1;                    /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
    unsigned int EN28 : 1;                    /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
    unsigned int EN29 : 1;                    /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
    unsigned int EN30 : 1;                    /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
    unsigned int EN31 : 1;                    /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
} Ifx_P_ACCEN0_Bits;

/** \\brief  Port Access Enable Register 1 */
typedef struct _Ifx_P_ACCEN1_Bits
{
    unsigned int reserved_0 : 32;             /**< \brief \internal Reserved */
} Ifx_P_ACCEN1_Bits;

/** \\brief  Port Emergency Stop Register */
typedef struct _Ifx_P_ESR_Bits
{
    unsigned int EN0 : 1;                     /**< \brief [0:0] Emergency Stop Enable for Pin 0 (rw) */
    unsigned int EN1 : 1;                     /**< \brief [1:1] Emergency Stop Enable for Pin 1 (rw) */
    unsigned int EN2 : 1;                     /**< \brief [2:2] Emergency Stop Enable for Pin 2 (rw) */
    unsigned int EN3 : 1;                     /**< \brief [3:3] Emergency Stop Enable for Pin 3 (rw) */
    unsigned int EN4 : 1;                     /**< \brief [4:4] Emergency Stop Enable for Pin 4 (rw) */
    unsigned int EN5 : 1;                     /**< \brief [5:5] Emergency Stop Enable for Pin 5 (rw) */
    unsigned int EN6 : 1;                     /**< \brief [6:6] Emergency Stop Enable for Pin 6 (rw) */
    unsigned int EN7 : 1;                     /**< \brief [7:7] Emergency Stop Enable for Pin 7 (rw) */
    unsigned int EN8 : 1;                     /**< \brief [8:8] Emergency Stop Enable for Pin 8 (rw) */
    unsigned int EN9 : 1;                     /**< \brief [9:9] Emergency Stop Enable for Pin 9 (rw) */
    unsigned int EN10 : 1;                    /**< \brief [10:10] Emergency Stop Enable for Pin 10 (rw) */
    unsigned int EN11 : 1;                    /**< \brief [11:11] Emergency Stop Enable for Pin 11 (rw) */
    unsigned int EN12 : 1;                    /**< \brief [12:12] Emergency Stop Enable for Pin 12 (rw) */
    unsigned int EN13 : 1;                    /**< \brief [13:13] Emergency Stop Enable for Pin 13 (rw) */
    unsigned int EN14 : 1;                    /**< \brief [14:14] Emergency Stop Enable for Pin 14 (rw) */
    unsigned int EN15 : 1;                    /**< \brief [15:15] Emergency Stop Enable for Pin 15 (rw) */
    unsigned int reserved_16 : 16;            /**< \brief \internal Reserved */
} Ifx_P_ESR_Bits;

/** \\brief  Port Identification Register */
typedef struct _Ifx_P_ID_Bits
{
    unsigned int MODREV : 8;                  /**< \brief [7:0] Module Revision Number (r) */
    unsigned int MODTYPE : 8;                 /**< \brief [15:8] Module Type (r) */
    unsigned int MODNUMBER : 16;              /**< \brief [31:16] Module Number Value (r) */
} Ifx_P_ID_Bits;

/** \\brief  Port Input Register */
typedef struct _Ifx_P_IN_Bits
{
    unsigned int P0 : 1;                      /**< \brief [0:0] Input Bit 0 (rh) */
    unsigned int P1 : 1;                      /**< \brief [1:1] Input Bit 1 (rh) */
    unsigned int P2 : 1;                      /**< \brief [2:2] Input Bit 2 (rh) */
    unsigned int P3 : 1;                      /**< \brief [3:3] Input Bit 3 (rh) */
    unsigned int P4 : 1;                      /**< \brief [4:4] Input Bit 4 (rh) */
    unsigned int P5 : 1;                      /**< \brief [5:5] Input Bit 5 (rh) */
    unsigned int P6 : 1;                      /**< \brief [6:6] Input Bit 6 (rh) */
    unsigned int P7 : 1;                      /**< \brief [7:7] Input Bit 7 (rh) */
    unsigned int P8 : 1;                      /**< \brief [8:8] Input Bit 8 (rh) */
    unsigned int P9 : 1;                      /**< \brief [9:9] Input Bit 9 (rh) */
    unsigned int P10 : 1;                     /**< \brief [10:10] Input Bit 10 (rh) */
    unsigned int P11 : 1;                     /**< \brief [11:11] Input Bit 11 (rh) */
    unsigned int P12 : 1;                     /**< \brief [12:12] Input Bit 12 (rh) */
    unsigned int P13 : 1;                     /**< \brief [13:13] Input Bit 13 (rh) */
    unsigned int P14 : 1;                     /**< \brief [14:14] Input Bit 14 (rh) */
    unsigned int P15 : 1;                     /**< \brief [15:15] Input Bit 15 (rh) */
    unsigned int reserved_16 : 16;            /**< \brief \internal Reserved */
} Ifx_P_IN_Bits;

/** \\brief  Port Input/Output Control Register 0 */
typedef struct _Ifx_P_IOCR0_Bits
{
    unsigned int reserved_0 : 3;              /**< \brief \internal Reserved */
    unsigned int PC0 : 5;                     /**< \brief [7:3]  (rw) */
    unsigned int reserved_8 : 3;              /**< \brief \internal Reserved */
    unsigned int PC1 : 5;                     /**< \brief [15:11]  (rw) */
    unsigned int reserved_16 : 3;             /**< \brief \internal Reserved */
    unsigned int PC2 : 5;                     /**< \brief [23:19]  (rw) */
    unsigned int reserved_24 : 3;             /**< \brief \internal Reserved */
    unsigned int PC3 : 5;                     /**< \brief [31:27]  (rw) */
} Ifx_P_IOCR0_Bits;

/** \\brief  Port Input/Output Control Register 12 */
typedef struct _Ifx_P_IOCR12_Bits
{
    unsigned int reserved_0 : 3;              /**< \brief \internal Reserved */
    unsigned int PC12 : 5;                    /**< \brief [7:3]  (rw) */
    unsigned int reserved_8 : 3;              /**< \brief \internal Reserved */
    unsigned int PC13 : 5;                    /**< \brief [15:11]  (rw) */
    unsigned int reserved_16 : 3;             /**< \brief \internal Reserved */
    unsigned int PC14 : 5;                    /**< \brief [23:19]  (rw) */
    unsigned int reserved_24 : 3;             /**< \brief \internal Reserved */
    unsigned int PC15 : 5;                    /**< \brief [31:27]  (rw) */
} Ifx_P_IOCR12_Bits;

/** \\brief  Port Input/Output Control Register 4 */
typedef struct _Ifx_P_IOCR4_Bits
{
    unsigned int reserved_0 : 3;              /**< \brief \internal Reserved */
    unsigned int PC4 : 5;                     /**< \brief [7:3]  (rw) */
    unsigned int reserved_8 : 3;              /**< \brief \internal Reserved */
    unsigned int PC5 : 5;                     /**< \brief [15:11]  (rw) */
    unsigned int reserved_16 : 3;             /**< \brief \internal Reserved */
    unsigned int PC6 : 5;                     /**< \brief [23:19]  (rw) */
    unsigned int reserved_24 : 3;             /**< \brief \internal Reserved */
    unsigned int PC7 : 5;                     /**< \brief [31:27]  (rw) */
} Ifx_P_IOCR4_Bits;

/** \\brief  Port Input/Output Control Register 8 */
typedef struct _Ifx_P_IOCR8_Bits
{
    unsigned int reserved_0 : 3;              /**< \brief \internal Reserved */
    unsigned int PC8 : 5;                     /**< \brief [7:3]  (rw) */
    unsigned int reserved_8 : 3;              /**< \brief \internal Reserved */
    unsigned int PC9 : 5;                     /**< \brief [15:11]  (rw) */
    unsigned int reserved_16 : 3;             /**< \brief \internal Reserved */
    unsigned int PC10 : 5;                    /**< \brief [23:19]  (rw) */
    unsigned int reserved_24 : 3;             /**< \brief \internal Reserved */
    unsigned int PC11 : 5;                    /**< \brief [31:27]  (rw) */
} Ifx_P_IOCR8_Bits;

/** \\brief  Port LVDS Pad Control Register 0 */
typedef struct _Ifx_P_LPCR0_Bits
{
    unsigned int REN_CTRL : 1;                /**< \brief [0:0] LVDS RX_EN controller (rw) */
    unsigned int RX_EN : 1;                   /**< \brief [1:1] Enable Receive LVDS (rw) */
    unsigned int TERM : 1;                    /**< \brief [2:2] Select Receiver Termination Mode (rw) */
    unsigned int LRXTERM : 3;                 /**< \brief [5:3] LVDS RX Poly-resistor configuration value (rw) */
    unsigned int LVDSM : 1;                   /**< \brief [6:6] LVDS-M Mode (rw) */
    unsigned int PS : 1;                      /**< \brief [7:7] Pad Supply Selection (rw) */
    unsigned int TEN_CTRL : 1;                /**< \brief [8:8] LVDS TX_EN controller (rw) */
    unsigned int TX_EN : 1;                   /**< \brief [9:9] Enable Transmit LVDS (rw) */
    unsigned int VDIFFADJ : 2;                /**< \brief [11:10] LVDS Output Amplitude Tuning (rw) */
    unsigned int VOSDYN : 1;                  /**< \brief [12:12] Tune Bit of VOS Control Loop Static/Dynamic (rw) */
    unsigned int VOSEXT : 1;                  /**< \brief [13:13] Tune Bit of VOS Control Loop Internal/External (rw) */
    unsigned int TX_PD : 1;                   /**< \brief [14:14] LVDS Power Down (rw) */
    unsigned int TX_PWDPD : 1;                /**< \brief [15:15] Enable TX Power down pull down. (rw) */
    unsigned int reserved_16 : 16;            /**< \brief \internal Reserved */
} Ifx_P_LPCR0_Bits;

/** \\brief  Port LVDS Pad Control Register 1 */
typedef struct _Ifx_P_LPCR1_Bits
{
    unsigned int REN_CTRL : 1;                /**< \brief [0:0] LVDS RX_EN controller (rw) */
    unsigned int RX_EN : 1;                   /**< \brief [1:1] Enable Receive LVDS (rw) */
    unsigned int TERM : 1;                    /**< \brief [2:2] Select Receiver Termination Mode (rw) */
    unsigned int LRXTERM : 3;                 /**< \brief [5:3] LVDS RX Poly-resistor configuration value (rw) */
    unsigned int LVDSM : 1;                   /**< \brief [6:6] LVDS-M Mode (rw) */
    unsigned int PS : 1;                      /**< \brief [7:7] Pad Supply Selection (rw) */
    unsigned int TEN_CTRL : 1;                /**< \brief [8:8] LVDS TX_EN controller (rw) */
    unsigned int TX_EN : 1;                   /**< \brief [9:9] Enable Transmit LVDS (rw) */
    unsigned int VDIFFADJ : 2;                /**< \brief [11:10] LVDS Output Amplitude Tuning (rw) */
    unsigned int VOSDYN : 1;                  /**< \brief [12:12] Tune Bit of VOS Control Loop Static/Dynamic (rw) */
    unsigned int VOSEXT : 1;                  /**< \brief [13:13] Tune Bit of VOS Control Loop Internal/External (rw) */
    unsigned int TX_PD : 1;                   /**< \brief [14:14] LVDS Power Down (rw) */
    unsigned int TX_PWDPD : 1;                /**< \brief [15:15] Enable TX Power down pull down. (rw) */
    unsigned int reserved_16 : 16;            /**< \brief \internal Reserved */
} Ifx_P_LPCR1_Bits;

/** \\brief  Port LVDS Pad Control Register 1 */
typedef struct _Ifx_P_LPCR1_P21_Bits
{
    unsigned int REN_CTRL : 1;                /**< \brief [0:0] LVDS RX_EN controller (rw) */
    unsigned int RX_EN : 1;                   /**< \brief [1:1] Enable Receive LVDS (rw) */
    unsigned int TERM : 1;                    /**< \brief [2:2] Select Receiver Termination Mode (rw) */
    unsigned int LRXTERM : 3;                 /**< \brief [5:3] LVDS RX Poly-resistor configuration value (rw) */
    unsigned int LVDSM : 1;                   /**< \brief [6:6] LVDS-M Mode (rw) */
    unsigned int PS : 1;                      /**< \brief [7:7] Pad Supply Selection (rw) */
    unsigned int reserved_8 : 24;             /**< \brief \internal Reserved */
} Ifx_P_LPCR1_P21_Bits;

/** \\brief  Port LVDS Pad Control Register 2 */
typedef struct _Ifx_P_LPCR2_Bits
{
    unsigned int REN_CTRL : 1;                /**< \brief [0:0] LVDS RX_EN controller (rw) */
    unsigned int RX_EN : 1;                   /**< \brief [1:1] Enable Receive LVDS (rw) */
    unsigned int TERM : 1;                    /**< \brief [2:2] Select Receiver Termination Mode (rw) */
    unsigned int LRXTERM : 3;                 /**< \brief [5:3] LVDS RX Poly-resistor configuration value (rw) */
    unsigned int LVDSM : 1;                   /**< \brief [6:6] LVDS-M Mode (rw) */
    unsigned int PS : 1;                      /**< \brief [7:7] Pad Supply Selection (rw) */
    unsigned int TEN_CTRL : 1;                /**< \brief [8:8] LVDS TX_EN controller (rw) */
    unsigned int TX_EN : 1;                   /**< \brief [9:9] Enable Transmit LVDS (rw) */
    unsigned int VDIFFADJ : 2;                /**< \brief [11:10] LVDS Output Amplitude Tuning (rw) */
    unsigned int VOSDYN : 1;                  /**< \brief [12:12] Tune Bit of VOS Control Loop Static/Dynamic (rw) */
    unsigned int VOSEXT : 1;                  /**< \brief [13:13] Tune Bit of VOS Control Loop Internal/External (rw) */
    unsigned int TX_PD : 1;                   /**< \brief [14:14] LVDS Power Down (rw) */
    unsigned int TX_PWDPD : 1;                /**< \brief [15:15] Enable TX Power down pull down. (rw) */
    unsigned int reserved_16 : 16;            /**< \brief \internal Reserved */
} Ifx_P_LPCR2_Bits;

/** \\brief  Port LVDS Pad Control Register 3 */
typedef struct _Ifx_P_LPCR3_Bits
{
    unsigned int REN_CTRL : 1;                /**< \brief [0:0] LVDS RX_EN controller (rw) */
    unsigned int RX_EN : 1;                   /**< \brief [1:1] Enable Receive LVDS (rw) */
    unsigned int TERM : 1;                    /**< \brief [2:2] Select Receiver Termination Mode (rw) */
    unsigned int LRXTERM : 3;                 /**< \brief [5:3] LVDS RX Poly-resistor configuration value (rw) */
    unsigned int LVDSM : 1;                   /**< \brief [6:6] LVDS-M Mode (rw) */
    unsigned int PS : 1;                      /**< \brief [7:7] Pad Supply Selection (rw) */
    unsigned int TEN_CTRL : 1;                /**< \brief [8:8] LVDS TX_EN controller (rw) */
    unsigned int TX_EN : 1;                   /**< \brief [9:9] Enable Transmit LVDS (rw) */
    unsigned int VDIFFADJ : 2;                /**< \brief [11:10] LVDS Output Amplitude Tuning (rw) */
    unsigned int VOSDYN : 1;                  /**< \brief [12:12] Tune Bit of VOS Control Loop Static/Dynamic (rw) */
    unsigned int VOSEXT : 1;                  /**< \brief [13:13] Tune Bit of VOS Control Loop Internal/External (rw) */
    unsigned int TX_PD : 1;                   /**< \brief [14:14] LVDS Power Down (rw) */
    unsigned int TX_PWDPD : 1;                /**< \brief [15:15] Enable TX Power down pull down. (rw) */
    unsigned int reserved_16 : 16;            /**< \brief \internal Reserved */
} Ifx_P_LPCR3_Bits;

/** \\brief  Port LVDS Pad Control Register 5 */
typedef struct _Ifx_P_LPCR5_Bits
{
    unsigned int REN_CTRL : 1;                /**< \brief [0:0] LVDS RX_EN controller (rw) */
    unsigned int RX_EN : 1;                   /**< \brief [1:1] Enable Receive LVDS (rw) */
    unsigned int TERM : 1;                    /**< \brief [2:2] Select Receiver Termination Mode (rw) */
    unsigned int LRXTERM : 3;                 /**< \brief [5:3] LVDS RX Poly-resistor configuration value (rw) */
    unsigned int LVDSM : 1;                   /**< \brief [6:6] LVDS-M Mode (rw) */
    unsigned int PS : 1;                      /**< \brief [7:7] Pad Supply Selection (rw) */
    unsigned int TEN_CTRL : 1;                /**< \brief [8:8] LVDS TX_EN controller (rw) */
    unsigned int TX_EN : 1;                   /**< \brief [9:9] Enable Transmit LVDS (rw) */
    unsigned int VDIFFADJ : 2;                /**< \brief [11:10] LVDS Output Amplitude Tuning (rw) */
    unsigned int VOSDYN : 1;                  /**< \brief [12:12] Tune Bit of VOS Control Loop Static/Dynamic (rw) */
    unsigned int VOSEXT : 1;                  /**< \brief [13:13] Tune Bit of VOS Control Loop Internal/External (rw) */
    unsigned int TX_PD : 1;                   /**< \brief [14:14] LVDS Power Down (rw) */
    unsigned int TX_PWDPD : 1;                /**< \brief [15:15] Enable TX Power down pull down. (rw) */
    unsigned int reserved_16 : 16;            /**< \brief \internal Reserved */
} Ifx_P_LPCR5_Bits;

/** \\brief  Port LVDS Pad Control Register 6 */
typedef struct _Ifx_P_LPCR6_Bits
{
    unsigned int reserved_0 : 7;              /**< \brief \internal Reserved */
    unsigned int PS : 1;                      /**< \brief [7:7] Pad Supply Selection (rw) */
    unsigned int TEN_CTRL : 1;                /**< \brief [8:8] LVDS TX_EN controller (rw) */
    unsigned int TX_EN : 1;                   /**< \brief [9:9] Enable Transmit LVDS (rw) */
    unsigned int VDIFFADJ : 2;                /**< \brief [11:10] LVDS Output Amplitude Tuning (rw) */
    unsigned int VOSDYN : 1;                  /**< \brief [12:12] Tune Bit of VOS Control Loop Static/Dynamic (rw) */
    unsigned int VOSEXT : 1;                  /**< \brief [13:13] Tune Bit of VOS Control Loop Internal/External (rw) */
    unsigned int TX_PD : 1;                   /**< \brief [14:14] LVDS Power Down (rw) */
    unsigned int TX_PWDPD : 1;                /**< \brief [15:15] Enable TX Power down pull down. (rw) */
    unsigned int reserved_16 : 16;            /**< \brief \internal Reserved */
} Ifx_P_LPCR6_Bits;

/** \\brief  Port Output Modification Clear Register 0 */
typedef struct _Ifx_P_OMCR0_Bits
{
    unsigned int reserved_0 : 16;             /**< \brief \internal Reserved */
    unsigned int PCL0 : 1;                    /**< \brief [16:16] Clear Bit 0 (w) */
    unsigned int PCL1 : 1;                    /**< \brief [17:17] Clear Bit 1 (w) */
    unsigned int PCL2 : 1;                    /**< \brief [18:18] Clear Bit 2 (w) */
    unsigned int PCL3 : 1;                    /**< \brief [19:19] Clear Bit 3 (w) */
    unsigned int reserved_20 : 12;            /**< \brief \internal Reserved */
} Ifx_P_OMCR0_Bits;

/** \\brief  Port Output Modification Clear Register 12 */
typedef struct _Ifx_P_OMCR12_Bits
{
    unsigned int reserved_0 : 28;             /**< \brief \internal Reserved */
    unsigned int PCL12 : 1;                   /**< \brief [28:28] Clear Bit 12 (w) */
    unsigned int PCL13 : 1;                   /**< \brief [29:29] Clear Bit 13 (w) */
    unsigned int PCL14 : 1;                   /**< \brief [30:30] Clear Bit 14 (w) */
    unsigned int PCL15 : 1;                   /**< \brief [31:31] Clear Bit 15 (w) */
} Ifx_P_OMCR12_Bits;

/** \\brief  Port Output Modification Clear Register 4 */
typedef struct _Ifx_P_OMCR4_Bits
{
    unsigned int reserved_0 : 20;             /**< \brief \internal Reserved */
    unsigned int PCL4 : 1;                    /**< \brief [20:20] Clear Bit 4 (w) */
    unsigned int PCL5 : 1;                    /**< \brief [21:21] Clear Bit 5 (w) */
    unsigned int PCL6 : 1;                    /**< \brief [22:22] Clear Bit 6 (w) */
    unsigned int PCL7 : 1;                    /**< \brief [23:23] Clear Bit 7 (w) */
    unsigned int reserved_24 : 8;             /**< \brief \internal Reserved */
} Ifx_P_OMCR4_Bits;

/** \\brief  Port Output Modification Clear Register 8 */
typedef struct _Ifx_P_OMCR8_Bits
{
    unsigned int reserved_0 : 24;             /**< \brief \internal Reserved */
    unsigned int PCL8 : 1;                    /**< \brief [24:24] Clear Bit 8 (w) */
    unsigned int PCL9 : 1;                    /**< \brief [25:25] Clear Bit 9 (w) */
    unsigned int PCL10 : 1;                   /**< \brief [26:26] Clear Bit 10 (w) */
    unsigned int PCL11 : 1;                   /**< \brief [27:27] Clear Bit 11 (w) */
    unsigned int reserved_28 : 4;             /**< \brief \internal Reserved */
} Ifx_P_OMCR8_Bits;

/** \\brief  Port Output Modification Clear Register */
typedef struct _Ifx_P_OMCR_Bits
{
    unsigned int reserved_0 : 16;             /**< \brief \internal Reserved */
    unsigned int PCL0 : 1;                    /**< \brief [16:16] Clear Bit 0 (w) */
    unsigned int PCL1 : 1;                    /**< \brief [17:17] Clear Bit 1 (w) */
    unsigned int PCL2 : 1;                    /**< \brief [18:18] Clear Bit 2 (w) */
    unsigned int PCL3 : 1;                    /**< \brief [19:19] Clear Bit 3 (w) */
    unsigned int PCL4 : 1;                    /**< \brief [20:20] Clear Bit 4 (w) */
    unsigned int PCL5 : 1;                    /**< \brief [21:21] Clear Bit 5 (w) */
    unsigned int PCL6 : 1;                    /**< \brief [22:22] Clear Bit 6 (w) */
    unsigned int PCL7 : 1;                    /**< \brief [23:23] Clear Bit 7 (w) */
    unsigned int PCL8 : 1;                    /**< \brief [24:24] Clear Bit 8 (w) */
    unsigned int PCL9 : 1;                    /**< \brief [25:25] Clear Bit 9 (w) */
    unsigned int PCL10 : 1;                   /**< \brief [26:26] Clear Bit 10 (w) */
    unsigned int PCL11 : 1;                   /**< \brief [27:27] Clear Bit 11 (w) */
    unsigned int PCL12 : 1;                   /**< \brief [28:28] Clear Bit 12 (w) */
    unsigned int PCL13 : 1;                   /**< \brief [29:29] Clear Bit 13 (w) */
    unsigned int PCL14 : 1;                   /**< \brief [30:30] Clear Bit 14 (w) */
    unsigned int PCL15 : 1;                   /**< \brief [31:31] Clear Bit 15 (w) */
} Ifx_P_OMCR_Bits;

/** \\brief  Port Output Modification Register */
typedef struct _Ifx_P_OMR_Bits
{
    unsigned int PS0 : 1;                     /**< \brief [0:0]  (w) */
    unsigned int PS1 : 1;                     /**< \brief [1:1]  (w) */
    unsigned int PS2 : 1;                     /**< \brief [2:2]  (w) */
    unsigned int PS3 : 1;                     /**< \brief [3:3]  (w) */
    unsigned int PS4 : 1;                     /**< \brief [4:4]  (w) */
    unsigned int PS5 : 1;                     /**< \brief [5:5]  (w) */
    unsigned int PS6 : 1;                     /**< \brief [6:6]  (w) */
    unsigned int PS7 : 1;                     /**< \brief [7:7]  (w) */
    unsigned int PS8 : 1;                     /**< \brief [8:8]  (w) */
    unsigned int PS9 : 1;                     /**< \brief [9:9]  (w) */
    unsigned int PS10 : 1;                    /**< \brief [10:10]  (w) */
    unsigned int PS11 : 1;                    /**< \brief [11:11]  (w) */
    unsigned int PS12 : 1;                    /**< \brief [12:12]  (w) */
    unsigned int PS13 : 1;                    /**< \brief [13:13]  (w) */
    unsigned int PS14 : 1;                    /**< \brief [14:14]  (w) */
    unsigned int PS15 : 1;                    /**< \brief [15:15]  (w) */
    unsigned int PCL0 : 1;                    /**< \brief [16:16]  (w) */
    unsigned int PCL1 : 1;                    /**< \brief [17:17]  (w) */
    unsigned int PCL2 : 1;                    /**< \brief [18:18]  (w) */
    unsigned int PCL3 : 1;                    /**< \brief [19:19]  (w) */
    unsigned int PCL4 : 1;                    /**< \brief [20:20]  (w) */
    unsigned int PCL5 : 1;                    /**< \brief [21:21]  (w) */
    unsigned int PCL6 : 1;                    /**< \brief [22:22]  (w) */
    unsigned int PCL7 : 1;                    /**< \brief [23:23]  (w) */
    unsigned int PCL8 : 1;                    /**< \brief [24:24]  (w) */
    unsigned int PCL9 : 1;                    /**< \brief [25:25]  (w) */
    unsigned int PCL10 : 1;                   /**< \brief [26:26]  (w) */
    unsigned int PCL11 : 1;                   /**< \brief [27:27]  (w) */
    unsigned int PCL12 : 1;                   /**< \brief [28:28]  (w) */
    unsigned int PCL13 : 1;                   /**< \brief [29:29]  (w) */
    unsigned int PCL14 : 1;                   /**< \brief [30:30]  (w) */
    unsigned int PCL15 : 1;                   /**< \brief [31:31]  (w) */
} Ifx_P_OMR_Bits;

/** \\brief  Port Output Modification Set Register 0 */
typedef struct _Ifx_P_OMSR0_Bits
{
    unsigned int PS0 : 1;                     /**< \brief [0:0] Set Bit 0 (w) */
    unsigned int PS1 : 1;                     /**< \brief [1:1] Set Bit 1 (w) */
    unsigned int PS2 : 1;                     /**< \brief [2:2] Set Bit 2 (w) */
    unsigned int PS3 : 1;                     /**< \brief [3:3] Set Bit 3 (w) */
    unsigned int reserved_4 : 28;             /**< \brief \internal Reserved */
} Ifx_P_OMSR0_Bits;

/** \\brief  Port Output Modification Set Register 12 */
typedef struct _Ifx_P_OMSR12_Bits
{
    unsigned int reserved_0 : 12;             /**< \brief \internal Reserved */
    unsigned int PS12 : 1;                    /**< \brief [12:12] Set Bit 12 (w) */
    unsigned int PS13 : 1;                    /**< \brief [13:13] Set Bit 13 (w) */
    unsigned int PS14 : 1;                    /**< \brief [14:14] Set Bit 14 (w) */
    unsigned int PS15 : 1;                    /**< \brief [15:15] Set Bit 15 (w) */
    unsigned int reserved_16 : 16;            /**< \brief \internal Reserved */
} Ifx_P_OMSR12_Bits;

/** \\brief  Port Output Modification Set Register 4 */
typedef struct _Ifx_P_OMSR4_Bits
{
    unsigned int reserved_0 : 4;              /**< \brief \internal Reserved */
    unsigned int PS4 : 1;                     /**< \brief [4:4] Set Bit 4 (w) */
    unsigned int PS5 : 1;                     /**< \brief [5:5] Set Bit 5 (w) */
    unsigned int PS6 : 1;                     /**< \brief [6:6] Set Bit 6 (w) */
    unsigned int PS7 : 1;                     /**< \brief [7:7] Set Bit 7 (w) */
    unsigned int reserved_8 : 24;             /**< \brief \internal Reserved */
} Ifx_P_OMSR4_Bits;

/** \\brief  Port Output Modification Set Register 8 */
typedef struct _Ifx_P_OMSR8_Bits
{
    unsigned int reserved_0 : 8;              /**< \brief \internal Reserved */
    unsigned int PS8 : 1;                     /**< \brief [8:8] Set Bit 8 (w) */
    unsigned int PS9 : 1;                     /**< \brief [9:9] Set Bit 9 (w) */
    unsigned int PS10 : 1;                    /**< \brief [10:10] Set Bit 10 (w) */
    unsigned int PS11 : 1;                    /**< \brief [11:11] Set Bit 11 (w) */
    unsigned int reserved_12 : 20;            /**< \brief \internal Reserved */
} Ifx_P_OMSR8_Bits;

/** \\brief  Port Output Modification Set Register */
typedef struct _Ifx_P_OMSR_Bits
{
    unsigned int PS0 : 1;                     /**< \brief [0:0] Set Bit 0 (w) */
    unsigned int PS1 : 1;                     /**< \brief [1:1] Set Bit 1 (w) */
    unsigned int PS2 : 1;                     /**< \brief [2:2] Set Bit 2 (w) */
    unsigned int PS3 : 1;                     /**< \brief [3:3] Set Bit 3 (w) */
    unsigned int PS4 : 1;                     /**< \brief [4:4] Set Bit 4 (w) */
    unsigned int PS5 : 1;                     /**< \brief [5:5] Set Bit 5 (w) */
    unsigned int PS6 : 1;                     /**< \brief [6:6] Set Bit 6 (w) */
    unsigned int PS7 : 1;                     /**< \brief [7:7] Set Bit 7 (w) */
    unsigned int PS8 : 1;                     /**< \brief [8:8] Set Bit 8 (w) */
    unsigned int PS9 : 1;                     /**< \brief [9:9] Set Bit 9 (w) */
    unsigned int PS10 : 1;                    /**< \brief [10:10] Set Bit 10 (w) */
    unsigned int PS11 : 1;                    /**< \brief [11:11] Set Bit 11 (w) */
    unsigned int PS12 : 1;                    /**< \brief [12:12] Set Bit 12 (w) */
    unsigned int PS13 : 1;                    /**< \brief [13:13] Set Bit 13 (w) */
    unsigned int PS14 : 1;                    /**< \brief [14:14] Set Bit 14 (w) */
    unsigned int PS15 : 1;                    /**< \brief [15:15] Set Bit 15 (w) */
    unsigned int reserved_16 : 16;            /**< \brief \internal Reserved */
} Ifx_P_OMSR_Bits;

/** \\brief  Port Output Register */
typedef struct _Ifx_P_OUT_Bits
{
    unsigned int P0 : 1;                      /**< \brief [0:0]  (rwh) */
    unsigned int P1 : 1;                      /**< \brief [1:1]  (rwh) */
    unsigned int P2 : 1;                      /**< \brief [2:2]  (rwh) */
    unsigned int P3 : 1;                      /**< \brief [3:3]  (rwh) */
    unsigned int P4 : 1;                      /**< \brief [4:4]  (rwh) */
    unsigned int P5 : 1;                      /**< \brief [5:5]  (rwh) */
    unsigned int P6 : 1;                      /**< \brief [6:6]  (rwh) */
    unsigned int P7 : 1;                      /**< \brief [7:7]  (rwh) */
    unsigned int P8 : 1;                      /**< \brief [8:8]  (rwh) */
    unsigned int P9 : 1;                      /**< \brief [9:9]  (rwh) */
    unsigned int P10 : 1;                     /**< \brief [10:10]  (rwh) */
    unsigned int P11 : 1;                     /**< \brief [11:11]  (rwh) */
    unsigned int P12 : 1;                     /**< \brief [12:12]  (rwh) */
    unsigned int P13 : 1;                     /**< \brief [13:13]  (rwh) */
    unsigned int P14 : 1;                     /**< \brief [14:14]  (rwh) */
    unsigned int P15 : 1;                     /**< \brief [15:15]  (rwh) */
    unsigned int reserved_16 : 16;            /**< \brief \internal Reserved */
} Ifx_P_OUT_Bits;

/** \\brief  Port Pin Controller Select Register */
typedef struct _Ifx_P_PCSR_Bits
{
    unsigned int SEL0 : 1;                    /**< \brief [0:0] Output Select for Pin 0 (rw) */
    unsigned int SEL1 : 1;                    /**< \brief [1:1] Output Select for Pin 1 (rw) */
    unsigned int SEL2 : 1;                    /**< \brief [2:2] Output Select for Pin 2 (rw) */
    unsigned int SEL3 : 1;                    /**< \brief [3:3] Output Select for Pin 3 (rw) */
    unsigned int SEL4 : 1;                    /**< \brief [4:4] Output Select for Pin 4 (rw) */
    unsigned int SEL5 : 1;                    /**< \brief [5:5] Output Select for Pin 5 (rw) */
    unsigned int SEL6 : 1;                    /**< \brief [6:6] Output Select for Pin 6 (rw) */
    unsigned int SEL7 : 1;                    /**< \brief [7:7] Output Select for Pin 7 (rw) */
    unsigned int SEL8 : 1;                    /**< \brief [8:8] Output Select for Pin 8 (rw) */
    unsigned int SEL9 : 1;                    /**< \brief [9:9] Output Select for Pin 9 (rw) */
    unsigned int SEL10 : 1;                   /**< \brief [10:10] Output Select for Pin 10 (rw) */
    unsigned int SEL11 : 1;                   /**< \brief [11:11] Output Select for Pin 11 (rw) */
    unsigned int SEL12 : 1;                   /**< \brief [12:12] Output Select for Pin 12 (rw) */
    unsigned int SEL13 : 1;                   /**< \brief [13:13] Output Select for Pin 13 (rw) */
    unsigned int SEL14 : 1;                   /**< \brief [14:14] Output Select for Pin 14 (rw) */
    unsigned int SEL15 : 1;                   /**< \brief [15:15] Output Select for Pin 15 (rw) */
    unsigned int reserved_16 : 15;            /**< \brief \internal Reserved */
    unsigned int LCK : 1;                     /**< \brief [31:31] Lock Status (rh) */
} Ifx_P_PCSR_Bits;

/** \\brief  Port Pin Function Decision Control Register */
typedef struct _Ifx_P_PDISC_Bits
{
    unsigned int PDIS0 : 1;                   /**< \brief [0:0] Pin Function Decision Control for Pin 0 (rw) */
    unsigned int PDIS1 : 1;                   /**< \brief [1:1] Pin Function Decision Control for Pin 1 (rw) */
    unsigned int PDIS2 : 1;                   /**< \brief [2:2] Pin Function Decision Control for Pin 2 (rw) */
    unsigned int PDIS3 : 1;                   /**< \brief [3:3] Pin Function Decision Control for Pin 3 (rw) */
    unsigned int PDIS4 : 1;                   /**< \brief [4:4] Pin Function Decision Control for Pin 4 (rw) */
    unsigned int PDIS5 : 1;                   /**< \brief [5:5] Pin Function Decision Control for Pin 5 (rw) */
    unsigned int PDIS6 : 1;                   /**< \brief [6:6] Pin Function Decision Control for Pin 6 (rw) */
    unsigned int PDIS7 : 1;                   /**< \brief [7:7] Pin Function Decision Control for Pin 7 (rw) */
    unsigned int PDIS8 : 1;                   /**< \brief [8:8] Pin Function Decision Control for Pin 8 (rw) */
    unsigned int PDIS9 : 1;                   /**< \brief [9:9] Pin Function Decision Control for Pin 9 (rw) */
    unsigned int PDIS10 : 1;                  /**< \brief [10:10] Pin Function Decision Control for Pin 10 (rw) */
    unsigned int PDIS11 : 1;                  /**< \brief [11:11] Pin Function Decision Control for Pin 11 (rw) */
    unsigned int PDIS12 : 1;                  /**< \brief [12:12] Pin Function Decision Control for Pin 12 (rw) */
    unsigned int PDIS13 : 1;                  /**< \brief [13:13] Pin Function Decision Control for Pin 13 (rw) */
    unsigned int PDIS14 : 1;                  /**< \brief [14:14] Pin Function Decision Control for Pin 14 (rw) */
    unsigned int PDIS15 : 1;                  /**< \brief [15:15] Pin Function Decision Control for Pin 15 (rw) */
    unsigned int reserved_16 : 16;            /**< \brief \internal Reserved */
} Ifx_P_PDISC_Bits;

/** \\brief  Port Pad Driver Mode Register 0 */
typedef struct _Ifx_P_PDR0_Bits
{
    unsigned int PD0 : 3;                     /**< \brief [2:0]  (rw) */
    unsigned int PL0 : 1;                     /**< \brief [3:3]  (rw) */
    unsigned int PD1 : 3;                     /**< \brief [6:4]  (rw) */
    unsigned int PL1 : 1;                     /**< \brief [7:7]  (rw) */
    unsigned int PD2 : 3;                     /**< \brief [10:8]  (rw) */
    unsigned int PL2 : 1;                     /**< \brief [11:11]  (rw) */
    unsigned int PD3 : 3;                     /**< \brief [14:12]  (rw) */
    unsigned int PL3 : 1;                     /**< \brief [15:15]  (rw) */
    unsigned int PD4 : 3;                     /**< \brief [18:16]  (rw) */
    unsigned int PL4 : 1;                     /**< \brief [19:19]  (rw) */
    unsigned int PD5 : 3;                     /**< \brief [22:20]  (rw) */
    unsigned int PL5 : 1;                     /**< \brief [23:23]  (rw) */
    unsigned int PD6 : 3;                     /**< \brief [26:24]  (rw) */
    unsigned int PL6 : 1;                     /**< \brief [27:27]  (rw) */
    unsigned int PD7 : 3;                     /**< \brief [30:28]  (rw) */
    unsigned int PL7 : 1;                     /**< \brief [31:31]  (rw) */
} Ifx_P_PDR0_Bits;

/** \\brief  Port Pad Driver Mode Register 1 */
typedef struct _Ifx_P_PDR1_Bits
{
    unsigned int PD8 : 3;                     /**< \brief [2:0]  (rw) */
    unsigned int PL8 : 1;                     /**< \brief [3:3]  (rw) */
    unsigned int PD9 : 3;                     /**< \brief [6:4]  (rw) */
    unsigned int PL9 : 1;                     /**< \brief [7:7]  (rw) */
    unsigned int PD10 : 3;                    /**< \brief [10:8]  (rw) */
    unsigned int PL10 : 1;                    /**< \brief [11:11]  (rw) */
    unsigned int PD11 : 3;                    /**< \brief [14:12]  (rw) */
    unsigned int PL11 : 1;                    /**< \brief [15:15]  (rw) */
    unsigned int PD12 : 3;                    /**< \brief [18:16]  (rw) */
    unsigned int PL12 : 1;                    /**< \brief [19:19]  (rw) */
    unsigned int PD13 : 3;                    /**< \brief [22:20]  (rw) */
    unsigned int PL13 : 1;                    /**< \brief [23:23]  (rw) */
    unsigned int PD14 : 3;                    /**< \brief [26:24]  (rw) */
    unsigned int PL14 : 1;                    /**< \brief [27:27]  (rw) */
    unsigned int PD15 : 3;                    /**< \brief [30:28]  (rw) */
    unsigned int PL15 : 1;                    /**< \brief [31:31]  (rw) */
} Ifx_P_PDR1_Bits;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Port_union
 * \{  */

/** \\brief  Port Access Enable Register 0 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int      U;
    /** \brief Signed access */
    signed int        I;
    /** \brief Bitfield access */
    Ifx_P_ACCEN0_Bits B;
} Ifx_P_ACCEN0;

/** \\brief  Port Access Enable Register 1 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int      U;
    /** \brief Signed access */
    signed int        I;
    /** \brief Bitfield access */
    Ifx_P_ACCEN1_Bits B;
} Ifx_P_ACCEN1;

/** \\brief  Port Emergency Stop Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int   U;
    /** \brief Signed access */
    signed int     I;
    /** \brief Bitfield access */
    Ifx_P_ESR_Bits B;
} Ifx_P_ESR;

/** \\brief  Port Identification Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int  U;
    /** \brief Signed access */
    signed int    I;
    /** \brief Bitfield access */
    Ifx_P_ID_Bits B;
} Ifx_P_ID;

/** \\brief  Port Input Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int  U;
    /** \brief Signed access */
    signed int    I;
    /** \brief Bitfield access */
    Ifx_P_IN_Bits B;
} Ifx_P_IN;

/** \\brief  Port Input/Output Control Register 0 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_IOCR0_Bits B;
} Ifx_P_IOCR0;

/** \\brief  Port Input/Output Control Register 12 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int      U;
    /** \brief Signed access */
    signed int        I;
    /** \brief Bitfield access */
    Ifx_P_IOCR12_Bits B;
} Ifx_P_IOCR12;

/** \\brief  Port Input/Output Control Register 4 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_IOCR4_Bits B;
} Ifx_P_IOCR4;

/** \\brief  Port Input/Output Control Register 8 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_IOCR8_Bits B;
} Ifx_P_IOCR8;

/** \\brief  Port LVDS Pad Control Register 0 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_LPCR0_Bits B;
} Ifx_P_LPCR0;

/** \\brief  Port LVDS Pad Control Register 1 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int         U;
    /** \brief Signed access */
    signed int           I;
    /** \brief Bitfield access */
    Ifx_P_LPCR1_Bits     B;
    /** \brief Bitfield access for P21 */
    Ifx_P_LPCR1_P21_Bits B_P21;
} Ifx_P_LPCR1;

/** \\brief  Port LVDS Pad Control Register 2 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_LPCR2_Bits B;
} Ifx_P_LPCR2;

/** \\brief  Port LVDS Pad Control Register 3 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_LPCR3_Bits B;
} Ifx_P_LPCR3;

/** \\brief  Port LVDS Pad Control Register 5 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_LPCR5_Bits B;
} Ifx_P_LPCR5;

/** \\brief  Port LVDS Pad Control Register 6 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_LPCR6_Bits B;
} Ifx_P_LPCR6;

/** \\brief  Port Output Modification Clear Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int    U;
    /** \brief Signed access */
    signed int      I;
    /** \brief Bitfield access */
    Ifx_P_OMCR_Bits B;
} Ifx_P_OMCR;

/** \\brief  Port Output Modification Clear Register 0 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_OMCR0_Bits B;
} Ifx_P_OMCR0;

/** \\brief  Port Output Modification Clear Register 12 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int      U;
    /** \brief Signed access */
    signed int        I;
    /** \brief Bitfield access */
    Ifx_P_OMCR12_Bits B;
} Ifx_P_OMCR12;

/** \\brief  Port Output Modification Clear Register 4 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_OMCR4_Bits B;
} Ifx_P_OMCR4;

/** \\brief  Port Output Modification Clear Register 8 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_OMCR8_Bits B;
} Ifx_P_OMCR8;

/** \\brief  Port Output Modification Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int   U;
    /** \brief Signed access */
    signed int     I;
    /** \brief Bitfield access */
    Ifx_P_OMR_Bits B;
} Ifx_P_OMR;

/** \\brief  Port Output Modification Set Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int    U;
    /** \brief Signed access */
    signed int      I;
    /** \brief Bitfield access */
    Ifx_P_OMSR_Bits B;
} Ifx_P_OMSR;

/** \\brief  Port Output Modification Set Register 0 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_OMSR0_Bits B;
} Ifx_P_OMSR0;

/** \\brief  Port Output Modification Set Register 12 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int      U;
    /** \brief Signed access */
    signed int        I;
    /** \brief Bitfield access */
    Ifx_P_OMSR12_Bits B;
} Ifx_P_OMSR12;

/** \\brief  Port Output Modification Set Register 4 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_OMSR4_Bits B;
} Ifx_P_OMSR4;

/** \\brief  Port Output Modification Set Register 8 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_OMSR8_Bits B;
} Ifx_P_OMSR8;

/** \\brief  Port Output Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int   U;
    /** \brief Signed access */
    signed int     I;
    /** \brief Bitfield access */
    Ifx_P_OUT_Bits B;
} Ifx_P_OUT;

/** \\brief  Port Pin Controller Select Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int    U;
    /** \brief Signed access */
    signed int      I;
    /** \brief Bitfield access */
    Ifx_P_PCSR_Bits B;
} Ifx_P_PCSR;

/** \\brief  Port Pin Function Decision Control Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int     U;
    /** \brief Signed access */
    signed int       I;
    /** \brief Bitfield access */
    Ifx_P_PDISC_Bits B;
} Ifx_P_PDISC;

/** \\brief  Port Pad Driver Mode Register 0 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int    U;
    /** \brief Signed access */
    signed int      I;
    /** \brief Bitfield access */
    Ifx_P_PDR0_Bits B;
} Ifx_P_PDR0;

/** \\brief  Port Pad Driver Mode Register 1 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int    U;
    /** \brief Signed access */
    signed int      I;
    /** \brief Bitfield access */
    Ifx_P_PDR1_Bits B;
} Ifx_P_PDR1;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Port_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \\brief  Port object */
typedef volatile struct _Ifx_P
{
    Ifx_P_OUT     OUT;                      /**< \brief 0, Port Output Register */
    Ifx_P_OMR     OMR;                      /**< \brief 4, Port Output Modification Register */
    Ifx_P_ID      ID;                       /**< \brief 8, Port Identification Register */
    unsigned char reserved_C[4];            /**< \brief C, \internal Reserved */
    Ifx_P_IOCR0   IOCR0;                    /**< \brief 10, Port Input/Output Control Register 0 */
    Ifx_P_IOCR4   IOCR4;                    /**< \brief 14, Port Input/Output Control Register 4 */
    Ifx_P_IOCR8   IOCR8;                    /**< \brief 18, Port Input/Output Control Register 8 */
    Ifx_P_IOCR12  IOCR12;                   /**< \brief 1C, Port Input/Output Control Register 12 */
    unsigned char reserved_20[4];           /**< \brief 20, \internal Reserved */
    Ifx_P_IN      IN;                       /**< \brief 24, Port Input Register */
    unsigned char reserved_28[24];          /**< \brief 28, \internal Reserved */
    Ifx_P_PDR0    PDR0;                     /**< \brief 40, Port Pad Driver Mode Register 0 */
    Ifx_P_PDR1    PDR1;                     /**< \brief 44, Port Pad Driver Mode Register 1 */
    unsigned char reserved_48[8];           /**< \brief 48, \internal Reserved */
    Ifx_P_ESR     ESR;                      /**< \brief 50, Port Emergency Stop Register */
    unsigned char reserved_54[12];          /**< \brief 54, \internal Reserved */
    Ifx_P_PDISC   PDISC;                    /**< \brief 60, Port Pin Function Decision Control Register */
    Ifx_P_PCSR    PCSR;                     /**< \brief 64, Port Pin Controller Select Register */
    unsigned char reserved_68[8];           /**< \brief 68, \internal Reserved */
    Ifx_P_OMSR0   OMSR0;                    /**< \brief 70, Port Output Modification Set Register 0 */
    Ifx_P_OMSR4   OMSR4;                    /**< \brief 74, Port Output Modification Set Register 4 */
    Ifx_P_OMSR8   OMSR8;                    /**< \brief 78, Port Output Modification Set Register 8 */
    Ifx_P_OMSR12  OMSR12;                   /**< \brief 7C, Port Output Modification Set Register 12 */
    Ifx_P_OMCR0   OMCR0;                    /**< \brief 80, Port Output Modification Clear Register 0 */
    Ifx_P_OMCR4   OMCR4;                    /**< \brief 84, Port Output Modification Clear Register 4 */
    Ifx_P_OMCR8   OMCR8;                    /**< \brief 88, Port Output Modification Clear Register 8 */
    Ifx_P_OMCR12  OMCR12;                   /**< \brief 8C, Port Output Modification Clear Register 12 */
    Ifx_P_OMSR    OMSR;                     /**< \brief 90, Port Output Modification Set Register */
    Ifx_P_OMCR    OMCR;                     /**< \brief 94, Port Output Modification Clear Register */
    unsigned char reserved_98[8];           /**< \brief 98, \internal Reserved */
    Ifx_P_LPCR0   LPCR0;                    /**< \brief A0, Port LVDS Pad Control Register 0 */
    Ifx_P_LPCR1   LPCR1;                    /**< \brief A4, Port LVDS Pad Control Register 1 */
    Ifx_P_LPCR2   LPCR2;                    /**< \brief A8, Port LVDS Pad Control Register 2 */
    Ifx_P_LPCR3   LPCR3;                    /**< \brief AC, Port LVDS Pad Control Register 3 */
    unsigned char reserved_B0[4];           /**< \brief B0, \internal Reserved */
    Ifx_P_LPCR5   LPCR5;                    /**< \brief B4, Port LVDS Pad Control Register 5 */
    Ifx_P_LPCR6   LPCR6;                    /**< \brief B8, Port LVDS Pad Control Register 6 */
    unsigned char reserved_B8[60];          /**< \brief BC, \internal Reserved */
    Ifx_P_ACCEN1  ACCEN1;                   /**< \brief F8, Port Access Enable Register 1 */
    Ifx_P_ACCEN0  ACCEN0;                   /**< \brief FC, Port Access Enable Register 0 */
} Ifx_P;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXPORT_REGDEF_H */
