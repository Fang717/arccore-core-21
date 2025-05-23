/**
 * \file IfxScuCcu.h
 * \brief SCU  basic functionality
 * \ingroup IfxLld_Scu
 *
 * \version iLLD_1_0_0_12_0
 * \copyright Copyright (c) 2016 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
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
 *
 * \defgroup IfxLld_Scu SCU
 * \addtogroup IfxLld_Scu
 * \{
 * \defgroup IfxLld_ScuCcu How to use the Scu Clock driver?
 * \addtogroup IfxLld_ScuCcu
 * \{
 *
 * The Scu Clock control unit driver provides a default configuration for pll and Clock initialisation and set of peripheral clock configuration functions.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_ScuCcu_Std_Preparation Preparation
 * \subsection IfxLld_ScuCcu_Std_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Scu/Std/IfxScuCcu.h>
 * \endcode
 *
 * \subsection IfxLld_ScuCcu_Std_Variables Variables
 *
 * Declare the Clock Configuration variables in your C code:
 *
 * \code
 * // used globally
 *
 * // configuration for the PLL  steps
 * static IfxScuCcu_PllStepsConfig IfxScuCcu_testPllConfigSteps[] = {
 *     IFXSCU_CFG_PLL_STEPS
 * };
 *
 * static const IfxScuCcu_FlashWaitstateConfig IfxScuCcu_defaultFlashWaitstateConfig = IFXSCU_CFG_FLASH_WAITSTATE;
 * // Default configuration for the Clock Configuration
 * IfxScuCcu_Config                      IfxScuCcu_testClockConfig = {
 *     // IfxScuCcu_InitialStepConfig: Configuration of first step which is same as internal osc frequency.
 *     IFXSCU_CFG_PLL_INITIAL_STEP,
 *     //IfxScuCcu_PllThrottleConfig: Configuration of PLL throttling.
 *     {
 *         sizeof(IfxScuCcu_defaultPllConfigSteps) / sizeof(IfxScuCcu_PllStepConfig),
 *         IfxScuCcu_defaultPllConfigSteps
 *     },
 *     IFXSCU_CFG_CLK_DISTRIBUTION,
 *     &IfxScuCcu_defaultFlashWaitstateConfig
 * };
 *
 * \endcode
 *
 * \subsection IfxLld_ScuCcu_Std_Init Module Initialisation
 *
 * The module initialisation can be done in the same function. Here an example:
 * \code
 *
 *        // standard PLL & clock initialisation
 *         IfxScuCcu_init(&IfxScuCcu_testClockConfig);
 * \endcode
 *
 *    The SYS PLL, PER PLL1 , PLL2 and clocks are now initialised based on the XTAL and PLL values configured in Ifx_Cfg.h and are ready for use now!
 *
 * Alternately the PLL and clocks can be initialised using below method which provides greater control on the configuration.
 *
 * \code
 * static const IfxScuCcu_PllStepConfig IfxScuCcu_defaultPllConfigSteps[] = {
 *     {                   //Step 0 Config: 150MHz
 *         (4 - 1),        //uint8 k2Step;
 *         0.000100,       //float32 waitTime;
 *     },
 *     {                   //Step 1 Config: 200MHz
 *         (3 - 1),       //uint8 k2Step;
 *         0.000100,       //float32 waitTime;
 *     },
 *     {                   //Step 2 Config: 300MHz
 *         (2 - 1),        //uint8 k2Step;
 *         0.000100,       //float32 waitTime;
 *     }
 * };
 *     IfxScuCcu_Config        IfxScuCcu_sampleClockConfig;
 *
 *     IfxScuCcu_initConfig(&IfxScuCcu_sampleClockConfig);
 *
 *
 *     IfxScuCcu_sampleClockConfig.pllInitialStepConfig.pllsParameters.pllInputClockSelection = IfxScuCcu_PllInputClockSelection_fOsc0;
 *
 *     //SYS PLL = 300Mhz, XTAL = 20Mhz
 *     IfxScuCcu_sampleClockConfig.pllInitialStepConfig.pllsParameters.sysPllConfig.k2Divider = IfxScuCcu_K2divider_2;
 *     IfxScuCcu_sampleClockConfig.pllInitialStepConfig.pllsParameters.sysPllConfig.nDivider = IfxScuCcu_Ndivider_60;
 *     IfxScuCcu_sampleClockConfig.pllInitialStepConfig.pllsParameters.sysPllConfig.pDivider = IfxScuCcu_Pdivider_2;
 *     IfxScuCcu_sampleClockConfig.pllInitialStepConfig.waitTime = 0.000200F;  // wait time
 *
 *     IfxScuCcu_sampleClockConfig.sysPllThrottleConfig.numOfSteps = sizeof(IfxScuCcu_defaultPllConfigSteps) / sizeof(IfxScuCcu_PllStepConfig); //  step clock incr
 *     IfxScuCcu_sampleClockConfig.sysPllThrottleConfig.pllSteps = IfxScuCcu_defaultPllConfigSteps;
 *
 *     // PER PLL1 = 240Mhz, PERPLL2 = 50Mhz
 *     IfxScuCcu_sampleClockConfig.pllInitialStepConfig.pllsParameters.perPllConfig.k2Divider = IfxScuCcu_K2divider_2;
 *     IfxScuCcu_sampleClockConfig.pllInitialStepConfig.pllsParameters.perPllConfig.k3Divider = IfxScuCcu_K3divider_6;
 *     IfxScuCcu_sampleClockConfig.pllInitialStepConfig.pllsParameters.perPllConfig.k3DividerBypass = 0;
 *     IfxScuCcu_sampleClockConfig.pllInitialStepConfig.pllsParameters.perPllConfig.nDivider = IfxScuCcu_Ndivider_24;
 *     IfxScuCcu_sampleClockConfig.pllInitialStepConfig.pllsParameters.perPllConfig.pDivider = IfxScuCcu_Pdivider_1;
 *
 *     // update CCUCON Config use mask and value as below
 *     IfxScuCcu_sampleClockConfig.clockDistribution.ccucon0.mask =IFXSCU_CFG_CCUCON0_MASK;
 *     IfxScuCcu_sampleClockConfig.clockDistribution.ccucon0.value = IFXSCU_CFG_CCUCON0;
 *
 *         // standard PLL & clock initialisation
 *         IfxScuCcu_init(&IfxScuCcu_sampleClockConfig);
 *
 * \endcode
 *
 * \}
 * \}
 *
 * \defgroup IfxLld_Scu_Std_Ccu Ccu Basic Functionality
 * \ingroup IfxLld_Scu_Std
 * \defgroup IfxLld_Scu_Std_Ccu_Ccu Clock Control Functions
 * \ingroup IfxLld_Scu_Std_Ccu
 * \defgroup IfxLld_Scu_Std_Ccu_Ccu_Operative Clock Control Operative Functions
 * \ingroup IfxLld_Scu_Std_Ccu
 * \defgroup IfxLld_Scu_Std_Ccu_Ccu_Configuration Clock Control Configuration Functions
 * \ingroup IfxLld_Scu_Std_Ccu
 * \defgroup IfxLld_Scu_Std_Ccu_Enum Enumerations
 * \ingroup IfxLld_Scu_Std_Ccu
 */

#ifndef IFXSCUCCU_H
#define IFXSCUCCU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxScu_cfg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Cpu/Std/IfxCpu.h"
#include "IfxStm_reg.h"
#include "IfxScu_reg.h"
#include "_PinMap/IfxScu_PinMap.h"
#include "IfxSmu_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Oscillator stability check timeout count
 */
#ifndef IFXSCUCCU_OSC_STABLECHK_TIME
#define IFXSCUCCU_OSC_STABLECHK_TIME               (640)
#endif

#define IFXSCUCCU_SMUALARM_MASK                    (0x387U)

/** \brief ~40uS max wait time
 */
#ifndef IFXSCUCCU_CCUCON_LCK_BIT_TIMEOUT_COUNT
#define IFXSCUCCU_CCUCON_LCK_BIT_TIMEOUT_COUNT     (0x1000U)
#endif

/** \brief ~122uS max wait time for PLL locking
 */
#define IFXSCUCCU_PLL_LOCK_TIMEOUT_COUNT           (0x3000U)

/** \brief ~122uS max wait time for PLL power down/up state update
 */
#define IFXSCUCCU_SYSPLLSTAT_PWDSTAT_TIMEOUT_COUNT (0x3000U)

/** \brief ~244uS max wait time
 */
#define IFXSCUCCU_PLL_KRDY_TIMEOUT_COUNT           (0x6000U)

/** \brief ~5.2mS max wait time for PLL power down/up state update
 */
#define IFXSCUCCU_OSCCON_PLLLV_OR_HV_TIMEOUT_COUNT (0x80000U)

#define IFXSCUCCU_LOOP_TIMEOUT_CHECK(tVar, tErr) \
    {                                            \
        if (((sint32)--tVar) <= 0)               \
        {                                        \
            tErr = (uint8)1;                     \
            break;                               \
        }                                        \
        else                                     \
        {                                        \
        }                                        \
    }

/******************************************************************************/
/*------------------------------Type Definitions------------------------------*/
/******************************************************************************/

/** \brief Function pointer type for the hooks
 * \return None
 */
typedef void (*IfxScuCcu_PllStepsFunctionHook)(void);

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Scu_Std_Ccu_Enum
 * \{ */
/** \brief clock source selection
 */
typedef enum
{
    IfxScuCcu_Fsource_0 = 0,      /**< \brief fSource0  */
    IfxScuCcu_Fsource_1,          /**< \brief fSource1  */
    IfxScuCcu_Fsource_2           /**< \brief fSource2  */
} IfxScuCcu_Fsource;

/** \brief MODULE_SCU.PLLCON1.B.K2DIV, specifies the K2-Divider
 */
typedef enum
{
    IfxScuCcu_K2divider_1 = 0,      /**< \brief K2-Divider 1  */
    IfxScuCcu_K2divider_2,          /**< \brief K2-Divider 2  */
    IfxScuCcu_K2divider_3,          /**< \brief K2-Divider 3  */
    IfxScuCcu_K2divider_4,          /**< \brief K2-Divider 4  */
    IfxScuCcu_K2divider_5,          /**< \brief K2-Divider 5  */
    IfxScuCcu_K2divider_6,          /**< \brief K2-Divider 6  */
    IfxScuCcu_K2divider_7,          /**< \brief K2-Divider 7  */
    IfxScuCcu_K2divider_8           /**< \brief K2-Divider 8  */
} IfxScuCcu_K2divider;

/** \brief MODULE_SCU.PLLCON1.B.K3DIV, specifies the K3-Divider
 */
typedef enum
{
    IfxScuCcu_K3divider_1 = 0,      /**< \brief K3-Divider 1  */
    IfxScuCcu_K3divider_2,          /**< \brief K3-Divider 2  */
    IfxScuCcu_K3divider_3,          /**< \brief K3-Divider 3  */
    IfxScuCcu_K3divider_4,          /**< \brief K3-Divider 4  */
    IfxScuCcu_K3divider_5,          /**< \brief K3-Divider 5  */
    IfxScuCcu_K3divider_6,          /**< \brief K3-Divider 6  */
    IfxScuCcu_K3divider_7,          /**< \brief K3-Divider 7  */
    IfxScuCcu_K3divider_8           /**< \brief K3-Divider 8  */
} IfxScuCcu_K3divider;

/** \brief MODULE_SCU.PLLCON0.B.NDIV, specifies the N-Divider
 */
typedef enum
{
    IfxScuCcu_Ndivider_1 = 0,      /**< \brief  N-divider 1  */
    IfxScuCcu_Ndivider_2,          /**< \brief  N-divider 2  */
    IfxScuCcu_Ndivider_3,          /**< \brief  N-divider 3  */
    IfxScuCcu_Ndivider_4,          /**< \brief  N-divider 4  */
    IfxScuCcu_Ndivider_5,          /**< \brief  N-divider 5  */
    IfxScuCcu_Ndivider_6,          /**< \brief  N-divider 6  */
    IfxScuCcu_Ndivider_7,          /**< \brief  N-divider 7  */
    IfxScuCcu_Ndivider_8,          /**< \brief  N-divider 8  */
    IfxScuCcu_Ndivider_9,          /**< \brief  N-divider 9  */
    IfxScuCcu_Ndivider_10,         /**< \brief  N-divider 10  */
    IfxScuCcu_Ndivider_11,         /**< \brief  N-divider 11  */
    IfxScuCcu_Ndivider_12,         /**< \brief  N-divider 12  */
    IfxScuCcu_Ndivider_13,         /**< \brief  N-divider 13  */
    IfxScuCcu_Ndivider_14,         /**< \brief  N-divider 14  */
    IfxScuCcu_Ndivider_15,         /**< \brief  N-divider 15  */
    IfxScuCcu_Ndivider_16,         /**< \brief  N-divider 16  */
    IfxScuCcu_Ndivider_17,         /**< \brief  N-divider 17  */
    IfxScuCcu_Ndivider_18,         /**< \brief  N-divider 18  */
    IfxScuCcu_Ndivider_19,         /**< \brief  N-divider 19  */
    IfxScuCcu_Ndivider_20,         /**< \brief  N-divider 20  */
    IfxScuCcu_Ndivider_21,         /**< \brief  N-divider 21  */
    IfxScuCcu_Ndivider_22,         /**< \brief  N-divider 22  */
    IfxScuCcu_Ndivider_23,         /**< \brief  N-divider 23  */
    IfxScuCcu_Ndivider_24,         /**< \brief  N-divider 24  */
    IfxScuCcu_Ndivider_25,         /**< \brief  N-divider 25  */
    IfxScuCcu_Ndivider_26,         /**< \brief  N-divider 26  */
    IfxScuCcu_Ndivider_27,         /**< \brief  N-divider 27  */
    IfxScuCcu_Ndivider_28,         /**< \brief  N-divider 28  */
    IfxScuCcu_Ndivider_29,         /**< \brief  N-divider 29  */
    IfxScuCcu_Ndivider_30,         /**< \brief  N-divider 30  */
    IfxScuCcu_Ndivider_31,         /**< \brief  N-divider 31  */
    IfxScuCcu_Ndivider_32,         /**< \brief  N-divider 32  */
    IfxScuCcu_Ndivider_33,         /**< \brief  N-divider 33  */
    IfxScuCcu_Ndivider_34,         /**< \brief  N-divider 34  */
    IfxScuCcu_Ndivider_35,         /**< \brief  N-divider 35  */
    IfxScuCcu_Ndivider_36,         /**< \brief  N-divider 36  */
    IfxScuCcu_Ndivider_37,         /**< \brief  N-divider 37  */
    IfxScuCcu_Ndivider_38,         /**< \brief  N-divider 38  */
    IfxScuCcu_Ndivider_39,         /**< \brief  N-divider 39  */
    IfxScuCcu_Ndivider_40,         /**< \brief  N-divider 40  */
    IfxScuCcu_Ndivider_41,         /**< \brief  N-divider 41  */
    IfxScuCcu_Ndivider_42,         /**< \brief  N-divider 42  */
    IfxScuCcu_Ndivider_43,         /**< \brief  N-divider 43  */
    IfxScuCcu_Ndivider_44,         /**< \brief  N-divider 44  */
    IfxScuCcu_Ndivider_45,         /**< \brief  N-divider 45  */
    IfxScuCcu_Ndivider_46,         /**< \brief  N-divider 46  */
    IfxScuCcu_Ndivider_47,         /**< \brief  N-divider 47  */
    IfxScuCcu_Ndivider_48,         /**< \brief  N-divider 48  */
    IfxScuCcu_Ndivider_49,         /**< \brief  N-divider 49  */
    IfxScuCcu_Ndivider_50,         /**< \brief  N-divider 50  */
    IfxScuCcu_Ndivider_51,         /**< \brief  N-divider 51  */
    IfxScuCcu_Ndivider_52,         /**< \brief  N-divider 52  */
    IfxScuCcu_Ndivider_53,         /**< \brief  N-divider 53  */
    IfxScuCcu_Ndivider_54,         /**< \brief  N-divider 54  */
    IfxScuCcu_Ndivider_55,         /**< \brief  N-divider 55  */
    IfxScuCcu_Ndivider_56,         /**< \brief  N-divider 56  */
    IfxScuCcu_Ndivider_57,         /**< \brief  N-divider 57  */
    IfxScuCcu_Ndivider_58,         /**< \brief  N-divider 58  */
    IfxScuCcu_Ndivider_59,         /**< \brief  N-divider 59  */
    IfxScuCcu_Ndivider_60,         /**< \brief  N-divider 60  */
    IfxScuCcu_Ndivider_61,         /**< \brief  N-divider 61  */
    IfxScuCcu_Ndivider_62,         /**< \brief  N-divider 62  */
    IfxScuCcu_Ndivider_63,         /**< \brief  N-divider 63  */
    IfxScuCcu_Ndivider_64,         /**< \brief  N-divider 64  */
    IfxScuCcu_Ndivider_65,         /**< \brief  N-divider 65  */
    IfxScuCcu_Ndivider_66,         /**< \brief  N-divider 66  */
    IfxScuCcu_Ndivider_67,         /**< \brief  N-divider 67  */
    IfxScuCcu_Ndivider_68,         /**< \brief  N-divider 68  */
    IfxScuCcu_Ndivider_69,         /**< \brief  N-divider 69  */
    IfxScuCcu_Ndivider_70,         /**< \brief  N-divider 70  */
    IfxScuCcu_Ndivider_71,         /**< \brief  N-divider 71  */
    IfxScuCcu_Ndivider_72,         /**< \brief  N-divider 72  */
    IfxScuCcu_Ndivider_73,         /**< \brief  N-divider 73  */
    IfxScuCcu_Ndivider_74,         /**< \brief  N-divider 74  */
    IfxScuCcu_Ndivider_75,         /**< \brief  N-divider 75  */
    IfxScuCcu_Ndivider_76,         /**< \brief  N-divider 76  */
    IfxScuCcu_Ndivider_77,         /**< \brief  N-divider 77  */
    IfxScuCcu_Ndivider_78,         /**< \brief  N-divider 78  */
    IfxScuCcu_Ndivider_79,         /**< \brief  N-divider 79  */
    IfxScuCcu_Ndivider_80,         /**< \brief  N-divider 80  */
    IfxScuCcu_Ndivider_81,         /**< \brief  N-divider 81  */
    IfxScuCcu_Ndivider_82,         /**< \brief  N-divider 82  */
    IfxScuCcu_Ndivider_83,         /**< \brief  N-divider 83  */
    IfxScuCcu_Ndivider_84,         /**< \brief  N-divider 84  */
    IfxScuCcu_Ndivider_85,         /**< \brief  N-divider 85  */
    IfxScuCcu_Ndivider_86,         /**< \brief  N-divider 86  */
    IfxScuCcu_Ndivider_87,         /**< \brief  N-divider 87  */
    IfxScuCcu_Ndivider_88,         /**< \brief  N-divider 88  */
    IfxScuCcu_Ndivider_89,         /**< \brief  N-divider 89  */
    IfxScuCcu_Ndivider_90,         /**< \brief  N-divider 90  */
    IfxScuCcu_Ndivider_91,         /**< \brief  N-divider 91  */
    IfxScuCcu_Ndivider_92,         /**< \brief  N-divider 92  */
    IfxScuCcu_Ndivider_93,         /**< \brief  N-divider 93  */
    IfxScuCcu_Ndivider_94,         /**< \brief  N-divider 94  */
    IfxScuCcu_Ndivider_95,         /**< \brief  N-divider 95  */
    IfxScuCcu_Ndivider_96,         /**< \brief  N-divider 96  */
    IfxScuCcu_Ndivider_97,         /**< \brief  N-divider 97  */
    IfxScuCcu_Ndivider_98,         /**< \brief  N-divider 98  */
    IfxScuCcu_Ndivider_99,         /**< \brief  N-divider 99  */
    IfxScuCcu_Ndivider_100,        /**< \brief  N-divider 100  */
    IfxScuCcu_Ndivider_101,        /**< \brief  N-divider 101  */
    IfxScuCcu_Ndivider_102,        /**< \brief  N-divider 102  */
    IfxScuCcu_Ndivider_103,        /**< \brief  N-divider 103  */
    IfxScuCcu_Ndivider_104,        /**< \brief  N-divider 104  */
    IfxScuCcu_Ndivider_105,        /**< \brief  N-divider 105  */
    IfxScuCcu_Ndivider_106,        /**< \brief  N-divider 106  */
    IfxScuCcu_Ndivider_107,        /**< \brief  N-divider 107  */
    IfxScuCcu_Ndivider_108,        /**< \brief  N-divider 108  */
    IfxScuCcu_Ndivider_109,        /**< \brief  N-divider 109  */
    IfxScuCcu_Ndivider_110,        /**< \brief  N-divider 110  */
    IfxScuCcu_Ndivider_111,        /**< \brief  N-divider 111  */
    IfxScuCcu_Ndivider_112,        /**< \brief  N-divider 112  */
    IfxScuCcu_Ndivider_113,        /**< \brief  N-divider 113  */
    IfxScuCcu_Ndivider_114,        /**< \brief  N-divider 114  */
    IfxScuCcu_Ndivider_115,        /**< \brief  N-divider 115  */
    IfxScuCcu_Ndivider_116,        /**< \brief  N-divider 116  */
    IfxScuCcu_Ndivider_117,        /**< \brief  N-divider 117  */
    IfxScuCcu_Ndivider_118,        /**< \brief  N-divider 118  */
    IfxScuCcu_Ndivider_119,        /**< \brief  N-divider 119  */
    IfxScuCcu_Ndivider_120,        /**< \brief  N-divider 120  */
    IfxScuCcu_Ndivider_121,        /**< \brief  N-divider 121  */
    IfxScuCcu_Ndivider_122,        /**< \brief  N-divider 122  */
    IfxScuCcu_Ndivider_123,        /**< \brief  N-divider 123  */
    IfxScuCcu_Ndivider_124,        /**< \brief  N-divider 124  */
    IfxScuCcu_Ndivider_125,        /**< \brief  N-divider 125  */
    IfxScuCcu_Ndivider_126,        /**< \brief  N-divider 126  */
    IfxScuCcu_Ndivider_127,        /**< \brief  N-divider 127  */
    IfxScuCcu_Ndivider_128         /**< \brief  N-divider 128  */
} IfxScuCcu_Ndivider;

/** \brief MODULE_SCU.PLLCON0.B.PDIV, specifies the P-Divider
 */
typedef enum
{
    IfxScuCcu_Pdivider_1 = 0,      /**< \brief  P-divider 1  */
    IfxScuCcu_Pdivider_2,          /**< \brief  P-divider 2  */
    IfxScuCcu_Pdivider_3,          /**< \brief  P-divider 3  */
    IfxScuCcu_Pdivider_4,          /**< \brief  P-divider 4  */
    IfxScuCcu_Pdivider_5,          /**< \brief  P-divider 5  */
    IfxScuCcu_Pdivider_6,          /**< \brief  P-divider 6  */
    IfxScuCcu_Pdivider_7,          /**< \brief  P-divider 7  */
    IfxScuCcu_Pdivider_8           /**< \brief  P-divider 8  */
} IfxScuCcu_Pdivider;

/** \brief SysPll & Per Pll input clock selection.
 * SYSPLLCON0.B.INSEL
 */
typedef enum
{
    IfxScuCcu_PllInputClockSelection_fOsc1   = 0, /**< \brief Backup clock select */
    IfxScuCcu_PllInputClockSelection_fOsc0   = 1, /**< \brief fOsc0 or XTAL clock select */
    IfxScuCcu_PllInputClockSelection_fSysclk = 2  /**< \brief fOsc1 */
} IfxScuCcu_PllInputClockSelection;

/** \brief trap request type
 */
typedef enum
{
    IfxScuCcu_Traprequest_esr0 = 0,  /**< \brief external service request 0 */
    IfxScuCcu_Traprequest_esr1,      /**< \brief external service request 1 */
    IfxScuCcu_Traprequest_trap2,     /**< \brief trap2 */
    IfxScuCcu_Traprequest_smu        /**< \brief safety management unit */
} IfxScuCcu_Traprequest;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu_Configuration
 * \{ */
/** \brief Configuration structure type for the Per Pll step.
 * This structure must be used to configure the P, N and K2, K3 dividers .
 */
typedef struct
{
    uint8 pDivider;              /**< \brief P divider value for basic (initial) step */
    uint8 nDivider;              /**< \brief N divider value for basic (initial) step */
    uint8 k2Divider;             /**< \brief K2 divider value */
    uint8 k3Divider;             /**< \brief K3 divider value */
    uint8 k3DividerBypass;       /**< \brief Divider Bypass
                                  * 0 - The divide by block in front of the K3-Divider is not bypassed.
                                  * 1-  The divide by block in front of the K3-Divider is bypassed. */
} IfxScuCcu_PerPllConfig;

/** \brief Configuration structure type for the Pll initial step.
 * This structure must be used to configure the P, N and K2 dividers for initial step.
 */
typedef struct
{
    uint8 pDivider;        /**< \brief P divider value */
    uint8 nDivider;        /**< \brief N divider value */
    uint8 k2Divider;       /**< \brief K2 divider value */
} IfxScuCcu_SysPllConfig;

/** \} */

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu_Configuration
 * \{ */
/** \brief Configuration structure type for CCUCON registers.
 */
typedef struct
{
    uint32 value;       /**< \brief CCUCON Register value to be updated. */
    uint32 mask;        /**< \brief CCUCON Mask to select the bit fields to be updated. */
} IfxScuCcu_CcuconRegConfig;

/** \brief Configuration structure type for the Pll Steps for current jump control.
 */
typedef struct
{
    uint8   k2Step;         /**< \brief K2 divider value for this step. */
    float32 waitTime;       /**< \brief Wait time for for this step. */
} IfxScuCcu_PllStepConfig;

/** \brief Configuration structure type for the Pll Parameters.
 */
typedef struct
{
    uint32                           xtalFrequency;                /**< \brief Xtal frequency */
    IfxScuCcu_PllInputClockSelection pllInputClockSelection;       /**< \brief Pll input clock selection */
    IfxScuCcu_SysPllConfig           sysPllConfig;                 /**< \brief System PLL Configurations */
    IfxScuCcu_PerPllConfig           perPllConfig;                 /**< \brief Peripheral PLL Configurations */
} IfxScuCcu_pllsParameterConfig;

/** \} */

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu
 * \{ */
/** \brief Configuration structure type for the Flash waitstate configuration.
 */
typedef struct
{
    uint32 value;       /**< \brief FLASH.FCON Register value to be updated. */
    uint32 mask;        /**< \brief FLASH.FCON Mask to select the bit fields to be updated. */
} IfxScuCcu_FlashWaitstateConfig;

/** \} */

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu_Configuration
 * \{ */
/** \brief Configuration structure type for all the CCUCON registers to configure clock distribution.
 */
typedef struct
{
    IfxScuCcu_CcuconRegConfig ccucon0;        /**< \brief CCUCON0 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon1;        /**< \brief CCUCON1 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon2;        /**< \brief CCUCON2 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon3;        /**< \brief CCUCON3 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon4;        /**< \brief CCUCON4 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon6;        /**< \brief CCUCON6 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon7;        /**< \brief CCUCON7 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon8;        /**< \brief CCUCON8 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon9;        /**< \brief CCUCON9 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon10;       /**< \brief CCUCON10 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon11;       /**< \brief CCUCON11 Register configuration */
} IfxScuCcu_ClockDistributionConfig;

/** \brief Configuration structure type for the Pll Initial Step Configuration.
 */
typedef struct
{
    IfxScuCcu_pllsParameterConfig pllsParameters;       /**< \brief Configuration Parameters for both PLLs */
    float32                       waitTime;             /**< \brief Wait time for for basic (initial) step */
} IfxScuCcu_InitialStepConfig;

/** \brief
 */
typedef struct
{
    uint8                              numOfSteps;       /**< \brief Number of PLL divider steps during clock throttling */
    IFX_CONST IfxScuCcu_PllStepConfig *pllSteps;         /**< \brief Pointer to the array of Pll divider step configuration. */
} IfxScuCcu_PllThrottleConfig;

/** \} */

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu_Configuration
 * \{ */
/** \brief Configuration structure SCU module
 */
typedef struct
{
    IfxScuCcu_InitialStepConfig               pllInitialStepConfig;           /**< \brief Configuration of first step which is same as internal osc frequency. */
    IfxScuCcu_PllThrottleConfig               sysPllThrottleConfig;           /**< \brief Configuration of PLL throttling. */
    IfxScuCcu_ClockDistributionConfig         clockDistribution;              /**< \brief Configuration of of bus clocks and other module clock distribution. */
    IFX_CONST IfxScuCcu_FlashWaitstateConfig *flashFconWaitStateConfig;       /**< \brief Configuration of flash waitstate */
} IfxScuCcu_Config;

/** \} */

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to wait for requested duration.
 * Note: IfxScuCcu_wait shall not use STM in future, because we can guarantee that STM is enabled after reset but  If PLL init is called for changing the frequency during runtime, there is no guarantee that STM is enabled
 * \return None
 */
IFX_INLINE void IfxScuCcu_wait(float32 timeSec);

/** \} */

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu_Operative
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to get Adc (EVADC, EDSADC)  frequency.
 * This API returns the based on the divider value in CCUCON register and fSOURCE.
 * \return Adc frequency (fADC) in Hz
 */
IFX_INLINE float32 IfxScuCcu_getAdcFrequency(void);

/** \brief API to get ASCLINF divider frequency.
 * This API returns the based on the divider value in CCUCON register and fSOURCE.
 * \return AsclinF frequency (fASCLINF) in Hz
 */
IFX_INLINE float32 IfxScuCcu_getAsclinFFrequency(void);

/** \brief API to get EBU frequency.
 * This API returns the based on the divider value in CCUCON register and fSOURCE.
 * \return EBU frequency (fEBU) in Hz
 */
IFX_INLINE float32 IfxScuCcu_getEbuFrequency(void);

/** \brief API to get EVR Oscillator frequency.
 * This API returns the constant which is specific to the ScuCcu of the controller.
 * \return EVR Oscillator frequency (fBACK or fEVR) in Hz.
 */
IFX_INLINE float32 IfxScuCcu_getEvrFrequency(void);

/** \brief API to get GTMdivider frequency
 * This API returns the based on the divider value in CCUCON register and fSOURCE.
 * return GTM frequency (fGTM) in Hz
 * \return Gtm Frequency
 */
IFX_INLINE float32 IfxScuCcu_getGtmFrequency(void);

/** \brief API to get I2C frequency.
 * This API returns the based on the divider value in CCUCON register and fSOURCE.
 * \return I2C frequency (fI2C) in Hz
 */
IFX_INLINE float32 IfxScuCcu_getI2cFrequency(void);

/** \brief API to get Oscillator 0 frequency.
 * This API returns the fOsc0 frequency based on the divider value in CCUCON register and the input oscillator.
 * \return Osc0 frequency (fOSC0) in Hz.
 */
IFX_INLINE float32 IfxScuCcu_getOsc0Frequency(void);

/** \brief API to get Oscillator 0 frequency.
 * This API returns the fOsc0 frequency based on the divider value in CCUCON register and the input oscillator.
 * \return Osc frequency (fOSC) in Hz.
 */
IFX_INLINE float32 IfxScuCcu_getOscFrequency(void);

/** \brief Returns the clock source selection
 * \return Clock source selection
 */
IFX_INLINE IfxScuCcu_PllInputClockSelection IfxScuCcu_getSourceSelection(void);

/** \brief API to get STM divider frequency.
 * This API returns the based on the divider value in CCUCON register and fSOURCE.
 * \return STM frequency (fSTM) in Hz
 */
IFX_INLINE float32 IfxScuCcu_getStmFrequency(void);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to get ASCLINS divider frequency.
 * This API returns the ASCLINS frequency  based on the divider value in CCUCON register and fSOURCE.
 * \return AsclinS frequency (fASCLINS) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getAsclinSFrequency(void);

/** \brief API to get BBB divider frequency.
 * This API returns the BBBDivider frequency based on the divider value in CCUCON register and the input oscillator.
 * \return BBB frequency (fBBB) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getBbbFrequency(void);

/** \brief This API returns the Cpu frequency based on the divider value in CCUCON register and fSource frequency
 * \param cpu CPU number for which effective fCPU is sought
 * \return Cpu[x] frequency in Hz, where x is cpu number passed as parameter
 */
IFX_EXTERN float32 IfxScuCcu_getCpuFrequency(const IfxCpu_ResourceCpu cpu);

/** \brief API to get FSI2 divider frequency in Hz.
 * This API returns the fFSI2 frequency based on the divider value in CCUCON register and the input oscillator.
 * \return FSI2 frequency (fFSI2) in Hz.
 */
IFX_EXTERN float32 IfxScuCcu_getFsi2Frequency(void);

/** \brief API to get FSI divider frequency in Hz.
 * This API returns the fFSI based on the divider value in CCUCON register and the input oscillator.
 * \return FSI frequency (fFSI) in Hz.
 */
IFX_EXTERN float32 IfxScuCcu_getFsiFrequency(void);

/** \brief API to get MCAN divider frequency.
 * This API returns the based on the divider value in CCUCON register and fSOURCE.
 * \return Mcan frequency (fMCAN) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getMcanFrequency(void);

/** \brief get source frequency fSOURCE.
 * This API returns the source frequency based on the configurations with CCUCON register configuration.
 * \return Module frequency in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getModuleFrequency(void);

/** \brief API to get MSC divider frequency.
 * This API returns the based on the divider value in CCUCON register and fSOURCE.
 * \return Msc frequency (fMSC) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getMscFrequency(void);

/** \brief API to get actual PER PLL1  frequency
 * This API returns the PER PLL1 frequency based on the K2 divider value in PLLCON and the VCO frequency.
 * Fpll1= (Fosc*N)/(P*K2)
 * \return PER PLL1 (K2 Divider) frequency in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getPerPllFrequency1(void);

/** \brief API to get actual PER PLL2 (K3 Divider) frequency
 * This API returns the PER PLL2 frequency based on the K3 divider value in PLLCON and the VCO frequency.
 * Fpll2= (Fosc*N)/(P*K3*1.6)  // DIVBY = 0,
 * Fpll2= (Fosc*N)/(P*K3)  // DIVBY = 1
 * \return PER PLL2 (K3 Divider ) frequency in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getPerPllFrequency2(void);

/** \brief API to get actual Sys PLL output frequency.
 * This API returns the based on the divider values in CCUCON, PLLCON registers and the input oscillator.
 * \return System Pll (fSysPLL) frequency in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getPllFrequency(void);

/** \brief API to get Qspi divider frequency.
 * This API returns the based on the divider value in CCUCON register and fSOURCE.
 * \return Qspi frequency (fQspi) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getQspiFrequency(void);

/** \brief get source frequency fSOURCE.
 * This API returns the source frequency based on the configurations with CCUCON register configuration.
 * \param fsource fsource selection
 * \return Effective fSOURCE in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getSourceFrequency(IfxScuCcu_Fsource fsource);

/** \brief API to get SPB divider frequency.
 * This API returns the based on fSOURCE and also on Low power divider mode and/or SPBDIV divider value in CCUCON registers.
 * \return SPB frequency (fSPB) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getSpbFrequency(void);

/** \brief API to get SRI divider frequency.
 * This API returns the Sri frequency based on the divider values in CCUCON registers and fSOURCE.
 * \return Sri frequency (fSRI) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getSriFrequency(void);

/** \brief API to set ASCLINF frequency (with ASCLINF divider)
 * This API configure ASCLINF divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param asclinFFreq AsclinF frequency (fASCLINF) in Hz
 * \return Actual AsclinF frequency (fASCLINF) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setAsclinFFrequency(float32 asclinFFreq);

/** \brief API to set ASCLINS frequency (with ASCLINS divider)
 * This API configure ASCLINS divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param asclinSFreq Desired AscLinS frequency in Hz
 * \return Actual AsclinS frequency (fASCLINS) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setAsclinSFrequency(float32 asclinSFreq);

/** \brief API to set BBB frequency (with Bbb divider)
 * This API configure Bbb divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param bbbFreq Bbb frequency (fBBB) in Hz
 * \return Actual Bbb frequency (fBBB) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setBbbFrequency(float32 bbbFreq);

/** \brief API to set CPU frequency (with CPU divider)
 * This API configure CPU divider values in CCUCON registers. The actual frequency is always depends on the feasibility with the divider value
 * \param cpu CPU number for which fCPU to be configured
 * \param cpuFreq Desired CPU frequency in Hz
 * \return Actual CPU[x] frequency in Hz, where x is the cpu number passed as parameter
 */
IFX_EXTERN float32 IfxScuCcu_setCpuFrequency(IfxCpu_ResourceCpu cpu, float32 cpuFreq);

/** \brief API to set FSI2 frequency (with FSI2 divider)
 * This API configure Fsi2 divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param fsi2Freq FSI2 frequency (fFSI) in Hz
 * \return Actual Fsi2 frequency (fFSI2) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setFsi2Frequency(float32 fsi2Freq);

/** \brief API to set FSI frequency (with FSI divider)
 * This API configure Fsi divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param fsiFreq FSI frequency (fFSI) in Hz
 * \return Actual Fsi frequency (fFSI) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setFsiFrequency(float32 fsiFreq);

/** \brief API to set GTM frequency (with GTM divider)
 * This API configure GTM divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param gtmFreq Desired GTM frequency in Hz
 * \return Actual GTM frequency in HZ
 */
IFX_EXTERN float32 IfxScuCcu_setGtmFrequency(float32 gtmFreq);

/** \brief API to set MCAN frequency (with MCAN divider)
 * This API configure MCAN divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param mcanFreq Desired MSC frequency in Hz
 * \return Actual Mcan frequency (fMCAN) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setMcanFrequency(float32 mcanFreq);

/** \brief API to set MSC frequency (with MSC divider)
 * This API configure MSC divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param mscFreq Desired MSC frequency in Hz
 * \return Actual Msc frequency (fMSC) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setMscFrequency(float32 mscFreq);

/** \brief API to set QSPI frequency (with QSPI divider)
 * This API configure Qspi divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param qspiFreq Desired QSPI frequency in Hz
 * \return Actual Qspi frequency (fQspi) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setQspiFrequency(float32 qspiFreq);

/** \brief API to set SPB frequency (with SPB divider)
 * This API configure SPB divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param spbFreq Desired SPB frequency in Hz
 * \return Actual SPB frequency in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setSpbFrequency(float32 spbFreq);

/** \brief API to set SRI frequency (with SRI divider)
 * This API configure Sri divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param sriFreq Sri frequency (fSRI) in Hz
 * \return Actual Sri frequency (fSRI) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setSriFrequency(float32 sriFreq);

/** \brief API to set STM frequency (with STM divider)
 * This API configure Stm divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param stmFreq Stm frequency (fASCLINF) in Hz
 * \return Actual Stm frequency (fSTM) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setStmFrequency(float32 stmFreq);

/** \} */

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu_Configuration
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Inlined API for clock distribution
 * For each CCUCON register update the configured value with the mask.
 * \param clockDistributionConfig pointer to clock distribution structure
 * \return TRUE: Operation successful, FALSE: Operation Failure
 */
IFX_INLINE boolean IfxScuCcu_distributeClockInline(const IfxScuCcu_ClockDistributionConfig *clockDistributionConfig);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to initialize the SCU Clock Control Unit.
 * This API initialize the Sys PLL with ramp steps, BUS dividers and Per PLL for the configuration provided by the configuration structure.
 * FSyspll = (Fosc * Nsys)/(Psys * K2sys);
 * Fpll1= (Fosc * Nper)/(Pper * K2per);
 * Fpll2= (Fosc * Nper)/(Pper * K3per * 1.6); // if DIVBY = 0, else Fpll2= (Fosc * Nper)/(Pper * K3per * 2) // if DIVBY = 1
 *
 * Note: Following SMU alarms are disabled before the PLL configuration and Enabled at the end of PLL lock in the function.
 * PLL0,1,2 clock out of range frequency
 * PLL0,1 VCO loss of lock event
 * System PLL Oscillator Watchdog, input clock out of range
 * The application should store/restore these alarm configurations if required.
 * \param config Pointer to the configuration structure of the ScuCcu
 * \return Error status of the ScuCcu initialization process.
 * \retval TRUE: If an error occurred during initialization.
 * \retval FALSE: If initialization was successful.
 */
IFX_EXTERN boolean IfxScuCcu_init(const IfxScuCcu_Config *config);

/** \brief Initializes the clock configuration with default values
 * \param cfg Pointer to the configuration structure of the ScuCcu
 * \return None
 */
IFX_EXTERN void IfxScuCcu_initConfig(IfxScuCcu_Config *cfg);

/** \brief API to switch to Backup clock from the current PLL frequency.
 * \param cfg Pointer to the configuration structure of the ScuCcu
 * \return None
 */
IFX_EXTERN void IfxScuCcu_switchToBackupClock(const IfxScuCcu_Config *cfg);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clear the trap status flag.
 * \param request Trap request type.
 * \return None
 */
IFX_INLINE void IfxScuCcu_clearTrapStatusFlag(IfxScuCcu_Traprequest request);

/** \brief This inline function configures the Ccu SYS PLLs initial step and PER PLL.
 */
IFX_INLINE boolean IfxScuCcu_configureCcuInitialStep(const IfxScuCcu_InitialStepConfig *pllInitStepCfg);

/** \brief Get trap disable flag.
 * \param cpuIndex Cpu index
 * \param request Trap request type.
 * \return Trap request can be generated or not.
 */
IFX_INLINE boolean IfxScuCcu_getTrapDisableFlag(IfxCpu_ResourceCpu cpuIndex, IfxScuCcu_Traprequest request);

/** \brief Get the trap status.
 * \param request Trap request type.
 * \return Trap was requested or not.
 */
IFX_INLINE boolean IfxScuCcu_getTrapStatusFlag(IfxScuCcu_Traprequest request);

/** \brief Set the trap disable flag
 * \param cpuIndex Cpu index.
 * \param request Trap request type.
 * \return None
 */
IFX_INLINE void IfxScuCcu_setTrapDisableFlag(IfxCpu_ResourceCpu cpuIndex, IfxScuCcu_Traprequest request);

/** \brief Set the trap status flag.
 * \param request Trap request type.
 * \return None
 */
IFX_INLINE void IfxScuCcu_setTrapStatusFlag(IfxScuCcu_Traprequest request);

/**
 */
IFX_INLINE boolean IfxScuCcu_throttleSysPllClockInline(const IfxScuCcu_PllThrottleConfig *pllThrottleConfig);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \return None
 */
IFX_EXTERN void IfxScuCcu_distributeClock(IfxScuCcu_ClockDistributionConfig *clockDistributionConfig);

/**
 * \return None
 */
IFX_EXTERN void IfxScuCcu_throttleSysPllClock(IfxScuCcu_PllThrottleConfig *pllThrottleConfig);

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

/** \brief Configuration structure for SCU CCU driver.
 * The values of this structure are defined as # defined macros in the implementation of Scu
 */
IFX_EXTERN IFX_CONST IfxScuCcu_Config IfxScuCcu_defaultClockConfig;

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxScuCcu_clearTrapStatusFlag(IfxScuCcu_Traprequest request)
{
    uint32 trapclear = 1;
    SCU_TRAPCLR.U |= (trapclear << request);
}


IFX_INLINE boolean IfxScuCcu_configureCcuInitialStep(const IfxScuCcu_InitialStepConfig *pllInitStepCfg)
{
    uint8                                initError = 0;
    uint16                               endinitSfty_pw;
    uint32                               timeoutCycleCount;
    const IfxScuCcu_pllsParameterConfig *pllsParamCfg;

    pllsParamCfg   = &pllInitStepCfg->pllsParameters;
    /*get the watch-dog passwords for usage with this function*/
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPasswordInline();

    /* Reset Safety ENDINIT, SCU_CCUCON registers are protected*/
    IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);

    timeoutCycleCount = IFXSCUCCU_CCUCON_LCK_BIT_TIMEOUT_COUNT;

    while (SCU_CCUCON0.B.LCK != 0U)
    {
        IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    {
        Ifx_SCU_CCUCON0 scuCcucon0;
        scuCcucon0.U        = SCU_CCUCON0.U;
        scuCcucon0.B.CLKSEL = 0; /*Select the EVR as fsource0/1/2 for the clock distribution */
        scuCcucon0.B.UP     = 1; /*Update the ccucon0 register */
        SCU_CCUCON0.U       = scuCcucon0.U;
    }

    timeoutCycleCount = IFXSCUCCU_CCUCON_LCK_BIT_TIMEOUT_COUNT;

    while (SCU_CCUCON0.B.LCK != 0U)
    {
        IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    /*Disable SMU Alarms */
    {
        SMU_KEYS.U    = (uint32)0xBCU;        /* Enable access to SMU registers */
        SMU_AG8CF0.U &= ~IFXSCUCCU_SMUALARM_MASK;
        SMU_AG8CF1.U &= ~IFXSCUCCU_SMUALARM_MASK;
        SMU_AG8CF2.U &= ~IFXSCUCCU_SMUALARM_MASK;
        SMU_KEYS.U    = (uint32)0U;
    }

    /* Power down the both the PLLs before configuring registers*/
    /* Both the PLLs are powered down to be sure for asynchronous PLL registers update cause no glitches */
    SCU_SYSPLLCON0.B.PLLPWD = 0;
    SCU_PERPLLCON0.B.PLLPWD = 0;

    timeoutCycleCount       = IFXSCUCCU_SYSPLLSTAT_PWDSTAT_TIMEOUT_COUNT;

    while ((SCU_SYSPLLSTAT.B.PWDSTAT == 0) || (SCU_PERPLLSTAT.B.PWDSTAT == 0))
    {
        IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    /* Now configure the oscillator, required oscillator mode is external crystal */
    if (pllsParamCfg->pllInputClockSelection == IfxScuCcu_PllInputClockSelection_fOsc0)
    {
        Ifx_SCU_OSCCON scuOsccon;
        scuOsccon.U        = SCU_OSCCON.U;
        scuOsccon.B.MODE   = 0U;
        scuOsccon.B.OSCVAL = (uint32)(pllsParamCfg->xtalFrequency / 1000000U) - 15; /*XTAL range 16MHz to 40MHz*/
        /*Note: Oscillator Watchdog Reset (OSCRES) is not required when the PLLs are powered down*/
        SCU_OSCCON.U       = scuOsccon.U;
#ifndef IFX_CFG_OSC_DISABLE_HW_WORKAROUND
        /** TODO:
         * WORKAROUND: Due to problem with HW (Not enough negative resistance at OSC module.
         * Suggested workaround to wait for 5ms after OSC configuration.
         * This workaround shall be later reconfirmed with the ERRATA workaround
         */
        IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);   //TODO: WORKAROUND
        IfxScuCcu_wait(0.005);                              //TODO: WORKAROUND
        IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw); //TODO: WORKAROUND
#endif
    }

    /* Configure the initial steps for the system PLL*/
    {
        Ifx_SCU_SYSPLLCON0 sysPllCon0;
        sysPllCon0.U      = SCU_SYSPLLCON0.U;
        sysPllCon0.B.PDIV = pllsParamCfg->sysPllConfig.pDivider;
        sysPllCon0.B.NDIV = pllsParamCfg->sysPllConfig.nDivider;
        SCU_SYSPLLCON0.U  = sysPllCon0.U;
    }

    /* Configure the initial steps for the peripheral PLL*/
    {
        Ifx_SCU_PERPLLCON0 scuPerPllCon0;
        scuPerPllCon0.U       = SCU_PERPLLCON0.U;
        scuPerPllCon0.B.DIVBY = pllsParamCfg->perPllConfig.k3DividerBypass;
        scuPerPllCon0.B.PDIV  = pllsParamCfg->perPllConfig.pDivider;
        scuPerPllCon0.B.NDIV  = pllsParamCfg->perPllConfig.nDivider;
        SCU_PERPLLCON0.U      = scuPerPllCon0.U;
    }

    /* Power up the both the PLLs before configuring registers*/
    SCU_SYSPLLCON0.B.PLLPWD = 1;
    SCU_PERPLLCON0.B.PLLPWD = 1;

    timeoutCycleCount       = IFXSCUCCU_SYSPLLSTAT_PWDSTAT_TIMEOUT_COUNT;

    while ((SCU_SYSPLLSTAT.B.PWDSTAT == 1) || (SCU_PERPLLSTAT.B.PWDSTAT == 1))
    {
        IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    timeoutCycleCount = IFXSCUCCU_PLL_KRDY_TIMEOUT_COUNT;

    while ((SCU_SYSPLLSTAT.B.K2RDY == 0U) ||
           (SCU_PERPLLSTAT.B.K2RDY == 0U) ||
           (SCU_PERPLLSTAT.B.K3RDY == 0U))
    {
        IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    SCU_SYSPLLCON1.B.K2DIV = pllsParamCfg->sysPllConfig.k2Divider;
    {
        Ifx_SCU_PERPLLCON1 scuPerPllCon1;
        scuPerPllCon1.U       = SCU_PERPLLCON1.U;
        scuPerPllCon1.B.K2DIV = pllsParamCfg->perPllConfig.k2Divider;
        scuPerPllCon1.B.K3DIV = pllsParamCfg->perPllConfig.k3Divider;
        SCU_PERPLLCON1.U      = scuPerPllCon1.U;
    }

    timeoutCycleCount = IFXSCUCCU_PLL_KRDY_TIMEOUT_COUNT;

    while ((SCU_SYSPLLSTAT.B.K2RDY == 0U) ||
           (SCU_PERPLLSTAT.B.K2RDY == 0U) ||
           (SCU_PERPLLSTAT.B.K3RDY == 0U))
    {
        IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    /*Check if the OSC frequencies are in the limit*/
    timeoutCycleCount = IFXSCUCCU_OSCCON_PLLLV_OR_HV_TIMEOUT_COUNT;

    while ((SCU_OSCCON.B.PLLLV == 0) && (SCU_OSCCON.B.PLLHV == 0))
    {
        IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    /* Now start PLL locking for latest set values*/
    {
        SCU_SYSPLLCON0.B.RESLD = 1;             /* Restart Sys PLL lock detection */
        SCU_PERPLLCON0.B.RESLD = 1;             /* Restart Per PLL lock detection */

        timeoutCycleCount      = IFXSCUCCU_PLL_LOCK_TIMEOUT_COUNT;

        while ((SCU_SYSPLLSTAT.B.LOCK == 0) && (SCU_PERPLLSTAT.B.LOCK == 0))
        {
            IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
        }
    }

    /*Enable SMU Alarms */
    {
        SMU_KEYS.U = (uint32)0xBCU;           /* Enable access to SMU registers */
        SMU_CMD.U  = (uint32)0x00000005;
        SMU_AG8.U  = IFXSCUCCU_SMUALARM_MASK; /* Clear SMU Alarms*/
        SMU_KEYS.U = (uint32)0U;
    }

    {
        Ifx_SCU_CCUCON0 scu_ccucon0;
        scu_ccucon0.U        = SCU_CCUCON0.U;
        scu_ccucon0.B.CLKSEL = 1; /*Select the PLLs for fsource0/1/2 */
        scu_ccucon0.B.UP     = 1; /*Update the ccucon0 register */

        timeoutCycleCount    = IFXSCUCCU_CCUCON_LCK_BIT_TIMEOUT_COUNT;

        while (SCU_CCUCON0.B.LCK != 0U)
        {
            IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
        }

        SCU_CCUCON0.U     = scu_ccucon0.U;

        timeoutCycleCount = IFXSCUCCU_CCUCON_LCK_BIT_TIMEOUT_COUNT;

        while (SCU_CCUCON0.B.LCK != 0U)
        {
            IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
        }
    }

    IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);
    return (boolean)initError;
}


IFX_INLINE boolean IfxScuCcu_distributeClockInline(const IfxScuCcu_ClockDistributionConfig *clockDistributionConfig)
{
    uint16 endinitSfty_pw;
    uint32 timeoutCycleCount;
    uint32 initError = 0;

    /*get the watch-dog passwords for usage with this function*/
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPasswordInline();

    /* Reset Safety ENDINIT, SCU_CCUCON registers are protected*/
    IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);

    /*Configure the clock distribution */
    {                                                    /*Write CCUCON0 configuration */
        Ifx_SCU_CCUCON0 ccucon0;
        ccucon0.U         = SCU_CCUCON0.U & ~clockDistributionConfig->ccucon0.mask;
        /*update with configured value */
        ccucon0.U        |= (clockDistributionConfig->ccucon0.mask & clockDistributionConfig->ccucon0.value);
        ccucon0.B.UP      = 1;
        timeoutCycleCount = IFXSCUCCU_CCUCON_LCK_BIT_TIMEOUT_COUNT;

        while (SCU_CCUCON0.B.LCK != 0U)
        {
            IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
        }

        SCU_CCUCON0.U     = ccucon0.U;      /*Set update bit explicitly to make above configurations effective */
        timeoutCycleCount = IFXSCUCCU_CCUCON_LCK_BIT_TIMEOUT_COUNT;

        while (SCU_CCUCON0.B.LCK != 0U)
        {
            IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
        }
    }

    {
        /*Write CCUCON1 configuration */
        Ifx_SCU_CCUCON1 ccucon1;
        ccucon1.U         = SCU_CCUCON1.U & ~clockDistributionConfig->ccucon1.mask;
        /*update with configured value */
        ccucon1.U        |= (clockDistributionConfig->ccucon1.mask & clockDistributionConfig->ccucon1.value);
        timeoutCycleCount = IFXSCUCCU_CCUCON_LCK_BIT_TIMEOUT_COUNT;

        while (SCU_CCUCON1.B.LCK != 0U)
        {
            IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
        }

        SCU_CCUCON1.U     = ccucon1.U;
        timeoutCycleCount = IFXSCUCCU_CCUCON_LCK_BIT_TIMEOUT_COUNT;

        while (SCU_CCUCON2.B.LCK != 0U)
        {
            IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
        }
    }

    {
        /*Write CCUCON2 configuration */
        Ifx_SCU_CCUCON2 ccucon2;
        ccucon2.U     = SCU_CCUCON2.U & ~clockDistributionConfig->ccucon2.mask;
        /*update with configured value */
        ccucon2.U    |= (clockDistributionConfig->ccucon2.mask & clockDistributionConfig->ccucon2.value);
        SCU_CCUCON2.U = ccucon2.U;
    }

    {
        /*Write CCUCON6 configuration */
        Ifx_SCU_CCUCON6 ccucon6;
        ccucon6.U     = SCU_CCUCON6.U & ~clockDistributionConfig->ccucon6.mask;
        /*update with configured value */
        ccucon6.U    |= (clockDistributionConfig->ccucon6.mask & clockDistributionConfig->ccucon6.value);
        SCU_CCUCON6.U = ccucon6.U;
    }

    {
        /*Write CCUCON7 configuration */
        Ifx_SCU_CCUCON7 ccucon7;
        ccucon7.U     = SCU_CCUCON7.U & ~clockDistributionConfig->ccucon7.mask;
        /*update with configured value */
        ccucon7.U    |= (clockDistributionConfig->ccucon7.mask & clockDistributionConfig->ccucon7.value);
        SCU_CCUCON7.U = ccucon7.U;
    }

    {
        /*Write CCUCON8 configuration */
        Ifx_SCU_CCUCON8 ccucon8;
        ccucon8.U     = SCU_CCUCON8.U & ~clockDistributionConfig->ccucon8.mask;
        /*update with configured value */
        ccucon8.U    |= (clockDistributionConfig->ccucon8.mask & clockDistributionConfig->ccucon8.value);
        SCU_CCUCON8.U = ccucon8.U;
    }

    {
        /*Write CCUCON9 configuration */
        Ifx_SCU_CCUCON9 ccucon9;
        ccucon9.U     = SCU_CCUCON9.U & ~clockDistributionConfig->ccucon9.mask;
        /*update with configured value */
        ccucon9.U    |= (clockDistributionConfig->ccucon9.mask & clockDistributionConfig->ccucon9.value);
        SCU_CCUCON9.U = ccucon9.U;
    }

    {
        /*Write CCUCON10 configuration */
        Ifx_SCU_CCUCON10 ccucon10;
        ccucon10.U     = SCU_CCUCON10.U & ~clockDistributionConfig->ccucon10.mask;
        /*update with configured value */
        ccucon10.U    |= (clockDistributionConfig->ccucon10.mask & clockDistributionConfig->ccucon10.value);
        SCU_CCUCON10.U = ccucon10.U;
    }
    {
        /*Write CCUCON11 configuration */
        Ifx_SCU_CCUCON11 ccucon11;
        ccucon11.U     = SCU_CCUCON11.U & ~clockDistributionConfig->ccucon11.mask;
        /*update with configured value */
        ccucon11.U    |= (clockDistributionConfig->ccucon11.mask & clockDistributionConfig->ccucon11.value);
        SCU_CCUCON11.U = ccucon11.U;
    }

    IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);
    return (boolean)initError;
}


IFX_INLINE float32 IfxScuCcu_getAdcFrequency(void)
{
    return IfxScuCcu_getSourceFrequency(IfxScuCcu_Fsource_1);
}


IFX_INLINE float32 IfxScuCcu_getAsclinFFrequency(void)
{
    float32 freq          = 0;

    uint8   asclindiv[16] = {1, 1, 2, 3, 4, 5, 6, 6, 8, 8, 10, 10, 12, 12, 12, 15};

    if (SCU_CCUCON2.B.ASCLINFDIV)
    {
        freq = IfxScuCcu_getSourceFrequency(IfxScuCcu_Fsource_2) / asclindiv[SCU_CCUCON2.B.ASCLINFDIV];
    }

    return freq;
}


IFX_INLINE float32 IfxScuCcu_getEbuFrequency(void)
{
    return IfxScuCcu_getSourceFrequency(IfxScuCcu_Fsource_1);
}


IFX_INLINE float32 IfxScuCcu_getEvrFrequency(void)
{
    return IFXSCU_EVR_OSC_FREQUENCY;
}


IFX_INLINE float32 IfxScuCcu_getGtmFrequency(void)
{
/* fGTM = fSOURCEGTM / GTMDIV ;
 * fSOURCEGTM = fSPB *2
 */
    uint8   gtmDiv  = SCU_CCUCON0.B.GTMDIV;
    float32 gtmFreq = 0;

    if (gtmDiv == 1U)
    {
        gtmFreq = IfxScuCcu_getSpbFrequency() * 2;
    }
    else
    {
        gtmFreq = IfxScuCcu_getSourceFrequency(IfxScuCcu_Fsource_0) / gtmDiv;
    }

    return gtmFreq;
}


IFX_INLINE float32 IfxScuCcu_getI2cFrequency(void)
{
    return IfxScuCcu_getSourceFrequency(IfxScuCcu_Fsource_2) / 3;
}


IFX_INLINE float32 IfxScuCcu_getOsc0Frequency(void)
{
    return (float32)IFX_CFG_SCU_XTAL_FREQUENCY;
}


IFX_INLINE float32 IfxScuCcu_getOscFrequency(void)
{
    float32 freq;

    if (SCU_SYSPLLCON0.B.INSEL == IfxScuCcu_PllInputClockSelection_fOsc1)
    {
        freq = IFXSCU_EVR_OSC_FREQUENCY;
    }
    else if (SCU_SYSPLLCON0.B.INSEL == IfxScuCcu_PllInputClockSelection_fOsc0)
    {
        freq = (float32)IFX_CFG_SCU_XTAL_FREQUENCY;
    }
    else if (SCU_SYSPLLCON0.B.INSEL == IfxScuCcu_PllInputClockSelection_fSysclk)
    {
        freq = IFX_CFG_SCU_SYSCLK_FREQUENCY;
    }
    else
    {
        /* Reserved values, this */
        freq = 0.0;
    }

    return freq;
}


IFX_INLINE IfxScuCcu_PllInputClockSelection IfxScuCcu_getSourceSelection(void)
{
    return (IfxScuCcu_PllInputClockSelection)SCU_CCUCON0.B.CLKSEL;
}


IFX_INLINE float32 IfxScuCcu_getStmFrequency(void)
{
    return IfxScuCcu_getSourceFrequency(IfxScuCcu_Fsource_0) / SCU_CCUCON0.B.STMDIV;
}


IFX_INLINE boolean IfxScuCcu_getTrapDisableFlag(IfxCpu_ResourceCpu cpuIndex, IfxScuCcu_Traprequest request)
{
    boolean trapdisable = 0;

    if (cpuIndex < IfxCpu_ResourceCpu_4)
    {
        trapdisable = ((SCU_TRAPDIS0.U >> ((cpuIndex << 3) + request)) & 0x1);
    }
    else
    {
        cpuIndex    = (IfxCpu_ResourceCpu)(cpuIndex - IfxCpu_ResourceCpu_4);

        trapdisable = ((SCU_TRAPDIS1.U >> ((cpuIndex << 3) + request)) & 0x1);
    }

    return trapdisable;
}


IFX_INLINE boolean IfxScuCcu_getTrapStatusFlag(IfxScuCcu_Traprequest request)
{
    boolean trapstatus = 0;

    trapstatus = (((SCU_TRAPSTAT.U) >> request) & (0x1));

    return trapstatus;
}


IFX_INLINE void IfxScuCcu_setTrapDisableFlag(IfxCpu_ResourceCpu cpuIndex, IfxScuCcu_Traprequest request)
{
    uint32 trapdis = 1;

    if (cpuIndex < IfxCpu_ResourceCpu_4)
    {
        trapdis         = (trapdis << (cpuIndex << 3));
        SCU_TRAPDIS0.U |= (trapdis << request);
    }
    else
    {
        cpuIndex        = (IfxCpu_ResourceCpu)(cpuIndex - IfxCpu_ResourceCpu_4);
        trapdis         = (trapdis << (cpuIndex << 3));
        SCU_TRAPDIS1.U |= (trapdis << request);
    }
}


IFX_INLINE void IfxScuCcu_setTrapStatusFlag(IfxScuCcu_Traprequest request)
{
    uint32 trapset = 1;
    SCU_TRAPSET.U |= (trapset << request);
}


IFX_INLINE boolean IfxScuCcu_throttleSysPllClockInline(const IfxScuCcu_PllThrottleConfig *pllThrottleConfig)
{
    uint8  initError = 0;
    uint8  pllStepsCount;
    uint16 endinitSfty_pw;
    uint32 timeoutCycleCount;

    /*get the watch-dog passwords for usage with this function*/
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPasswordInline();

    /*Start Pll ramp up sequence */
    for (pllStepsCount = 0; pllStepsCount < pllThrottleConfig->numOfSteps; pllStepsCount++)
    {                       /*iterate through number of pll steps */
        {
            IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);

            /*Configure K2 divider */
            timeoutCycleCount = IFXSCUCCU_PLL_KRDY_TIMEOUT_COUNT;

            while (SCU_SYSPLLSTAT.B.K2RDY == 0U)
            {
                IFXSCUCCU_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
            }

            /*Now set the K2 divider value for the step corresponding to step count */
            SCU_SYSPLLCON1.B.K2DIV = pllThrottleConfig->pllSteps[pllStepsCount].k2Step;
            IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);
        }

        /*Wait for waitCounter corresponding to the pll step */
        IfxScuCcu_wait(pllThrottleConfig->pllSteps[pllStepsCount].waitTime);
    }

    return (boolean)initError;
}


IFX_INLINE void IfxScuCcu_wait(float32 timeSec)
{
    uint32 stmCount      = (uint32)(IfxScuCcu_getStmFrequency() * timeSec);
    uint32 stmCountBegin = STM0_TIM0.U;

    while ((uint32)(STM0_TIM0.U - stmCountBegin) < stmCount)
    {
        /* There is no need to check overflow of the STM timer.
         * When counter after overflow subtracted with counter before overflow,
         * the subtraction result will be as expected, as long as both are unsigned 32 bits
         * eg: stmCountBegin= 0xFFFFFFFE (before overflow)
         *     stmCountNow = 0x00000002 (before overflow)
         *     diff= stmCountNow - stmCountBegin = 4 as expected.*/
    }
}


#endif /* IFXSCUCCU_H */
