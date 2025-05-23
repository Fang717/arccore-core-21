/**
 * \file IfxStm.h
 * \brief STM  basic functionality
 * \ingroup IfxLld_Stm
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
 * \defgroup IfxLld_Stm_Usage How to use the Stm driver?
 * \ingroup IfxLld_Stm
 *
 * The Stm Standard driver provides APIs to initialize, configure and control the Stm.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Stm_Preparation Preparation
 * \subsection IfxLld_Stm_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Stm/Std/IfxStm.h>
 * \endcode
 *
 * \subsection IfxLld_Stm_Variables Variables
 *
 * Declare STM variables :
 * \code
 * Ifx_STM *stmSfr;
 * IfxStm_CompareConfig stmConfig;
 * \endcode
 *
 * \subsection IfxLld_Stm_Interrupt Interrupt Handler Installation
 *
 * See also \ref IfxLld_Cpu_Irq_Usage
 *
 * Define priorities for the Interrrupt handlers. This is normally done in the Ifx_IntPrioDef.h file:
 * \code
 * // priorities are normally defined in Ifx_IntPrioDef.h
 * #define IFX_INTPRIO_STM0_SR0  10
 * \endcode
 *
 * Add the interrupt service routines to your C code. They have to call the Stm interrupt handlers:
 * please take care in choosing number of ticks, the below example code will raise an interrupt
 * evry time the specified number of ticks have been elapsed.
 * \code
 * IFX_INTERRUPT(stm0Sr0ISR, 0, IFX_INTPRIO_STM0_SR0)
 * {
 *     IfxStm_clearCompareFlag(stmSfr, stmConfig.comparator);
 *     IfxStm_increaseCompare(stmSfr, stmConfig.comparator, stmConfig.ticks);
 * }
 * \endcode
 *
 * Finally install the interrupt handlers in your initialisation function:
 * \code
 *     // install interrupt handlers
 *     IfxCpu_Irq_installInterruptHandler(&stm0Sr0ISR, IFX_INTPRIO_STM0_SR0);
 *     IfxCpu_enableInterrupts();
 * \endcode
 *
 * \subsection IfxLld_Stm_Init Module Initialisation
 *
 * The STM module can be configured to generate an interrupt at every compare match of the selected comaparator with the desired compare value, the interrupt can further be routed to other comparator.
 *
 * The module initialisation can be done as followed.
 *
 * \code
 *     stmSfr = &MODULE_STM0;
 *
 *     IfxStm_initCompareConfig(&stmConfig);
 *
 *     // configure to generate interrupt every 10 us
 *     sint32 ticks = IfxStm_getTicksFromMicroseconds(10);
 *
 *     stmConfig.ticks = ticks;
 *
 *     stmConfig.triggerPriority = IFX_INTPRIO_STM0_SR0;
 *     stmConfig.typeOfService = IfxSrc_Tos_cpu0;
 *
 *     IfxStm_initCompare(stmSfr, &stmConfig);
 *
 * \endcode
 *
 * Now the Stm shall generate interrupts regularly based on the configured time !
 *
 * \defgroup IfxLld_Stm_Std_Enumerations Enumerations
 * \ingroup IfxLld_Stm_Std
 * \defgroup IfxLld_Stm_Std_Structures Data Structures
 * \ingroup IfxLld_Stm_Std
 * \defgroup IfxLld_Stm_Std_Module Module Functions
 * \ingroup IfxLld_Stm_Std
 * \defgroup IfxLld_Stm_Std_Timer Timer Functions
 * \ingroup IfxLld_Stm_Std
 * \defgroup IfxLld_Stm_Std_Comparator Comparator Functions
 * \ingroup IfxLld_Stm_Std
 */

#ifndef IFXSTM_H
#define IFXSTM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxStm_cfg.h"
#include "Scu/Std/IfxScuCcu.h"
#include "Src/Std/IfxSrc.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Stm_Std_Enumerations
 * \{ */
/** \brief Comparator Id defined in   MODULE_STMx.ISCR.B.CMP0IRR(x = 0, 1, 2)
 */
typedef enum
{
    IfxStm_Comparator_0 = 0,      /**< \brief Comparator Id 0  */
    IfxStm_Comparator_1           /**< \brief Comparator Id 1  */
} IfxStm_Comparator;

/** \brief Comparator Interrupt request source defined in MODULE_SRC.STM.STM[index].SRx (x =0, 1)
 */
typedef enum
{
    IfxStm_ComparatorInterrupt_ir0 = 0,  /**< \brief Select STMIR0 */
    IfxStm_ComparatorInterrupt_ir1 = 1   /**< \brief Select STMIR1 */
} IfxStm_ComparatorInterrupt;

/** \brief Comparator start bit position  defined in MODULE_STMx.CMCON.B.MSTART0(x = 0,1,2)
 */
typedef enum
{
    IfxStm_ComparatorOffset_0 = 0,      /**< \brief Comparator start bit position 0 with 64 bit timer  */
    IfxStm_ComparatorOffset_1,          /**< \brief Comparator start bit position 1 with 64 bit timer  */
    IfxStm_ComparatorOffset_2,          /**< \brief Comparator start bit position 2 with 64 bit timer  */
    IfxStm_ComparatorOffset_3,          /**< \brief Comparator start bit position 3 with 64 bit timer  */
    IfxStm_ComparatorOffset_4,          /**< \brief Comparator start bit position 4 with 64 bit timer  */
    IfxStm_ComparatorOffset_5,          /**< \brief Comparator start bit position 5 with 64 bit timer  */
    IfxStm_ComparatorOffset_6,          /**< \brief Comparator start bit position 6 with 64 bit timer  */
    IfxStm_ComparatorOffset_7,          /**< \brief Comparator start bit position 7 with 64 bit timer  */
    IfxStm_ComparatorOffset_8,          /**< \brief Comparator start bit position 8 with 64 bit timer  */
    IfxStm_ComparatorOffset_9,          /**< \brief Comparator start bit position 9 with 64 bit timer  */
    IfxStm_ComparatorOffset_10,         /**< \brief Comparator start bit position 10 with 64 bit timer  */
    IfxStm_ComparatorOffset_11,         /**< \brief Comparator start bit position 11 with 64 bit timer  */
    IfxStm_ComparatorOffset_12,         /**< \brief Comparator start bit position 12 with 64 bit timer  */
    IfxStm_ComparatorOffset_13,         /**< \brief Comparator start bit position 13 with 64 bit timer  */
    IfxStm_ComparatorOffset_14,         /**< \brief Comparator start bit position 14 with 64 bit timer  */
    IfxStm_ComparatorOffset_15,         /**< \brief Comparator start bit position 15 with 64 bit timer  */
    IfxStm_ComparatorOffset_16,         /**< \brief Comparator start bit position 16 with 64 bit timer  */
    IfxStm_ComparatorOffset_17,         /**< \brief Comparator start bit position 17 with 64 bit timer  */
    IfxStm_ComparatorOffset_18,         /**< \brief Comparator start bit position 18 with 64 bit timer  */
    IfxStm_ComparatorOffset_19,         /**< \brief Comparator start bit position 19 with 64 bit timer  */
    IfxStm_ComparatorOffset_20,         /**< \brief Comparator start bit position 20 with 64 bit timer  */
    IfxStm_ComparatorOffset_21,         /**< \brief Comparator start bit position 21 with 64 bit timer  */
    IfxStm_ComparatorOffset_22,         /**< \brief Comparator start bit position 22 with 64 bit timer  */
    IfxStm_ComparatorOffset_23,         /**< \brief Comparator start bit position 23 with 64 bit timer  */
    IfxStm_ComparatorOffset_24,         /**< \brief Comparator start bit position 24 with 64 bit timer  */
    IfxStm_ComparatorOffset_25,         /**< \brief Comparator start bit position 25 with 64 bit timer  */
    IfxStm_ComparatorOffset_26,         /**< \brief Comparator start bit position 26 with 64 bit timer  */
    IfxStm_ComparatorOffset_27,         /**< \brief Comparator start bit position 27 with 64 bit timer  */
    IfxStm_ComparatorOffset_28,         /**< \brief Comparator start bit position 28 with 64 bit timer  */
    IfxStm_ComparatorOffset_29,         /**< \brief Comparator start bit position 29 with 64 bit timer  */
    IfxStm_ComparatorOffset_30,         /**< \brief Comparator start bit position 30 with 64 bit timer  */
    IfxStm_ComparatorOffset_31          /**< \brief Comparator start bit position 31 with 64 bit timer  */
} IfxStm_ComparatorOffset;

/** \brief Size of compare value to compare with timer defined in  MODULE_STMx.CMCON.B.MSIZE0(x = 0,1,2)
 */
typedef enum
{
    IfxStm_ComparatorSize_1Bit   = 0,   /**< \brief Size of compare value to compare with timer: 1 bit */
    IfxStm_ComparatorSize_2Bits  = 1,   /**< \brief Size of compare value to compare with timer: 2 bits */
    IfxStm_ComparatorSize_3Bits  = 2,   /**< \brief Size of compare value to compare with timer: 3 bits */
    IfxStm_ComparatorSize_4Bits  = 3,   /**< \brief Size of compare value to compare with timer: 4 bits */
    IfxStm_ComparatorSize_5Bits  = 4,   /**< \brief Size of compare value to compare with timer: 5 bits */
    IfxStm_ComparatorSize_6Bits  = 5,   /**< \brief Size of compare value to compare with timer: 6 bits */
    IfxStm_ComparatorSize_7Bits  = 6,   /**< \brief Size of compare value to compare with timer: 7 bits */
    IfxStm_ComparatorSize_8Bits  = 7,   /**< \brief Size of compare value to compare with timer: 8 bits */
    IfxStm_ComparatorSize_9Bits  = 8,   /**< \brief Size of compare value to compare with timer: 9 bits */
    IfxStm_ComparatorSize_10Bits = 9,   /**< \brief Size of compare value to compare with timer: 10 bits */
    IfxStm_ComparatorSize_11Bits = 10,  /**< \brief Size of compare value to compare with timer: 11 bits */
    IfxStm_ComparatorSize_12Bits = 11,  /**< \brief Size of compare value to compare with timer: 12 bits */
    IfxStm_ComparatorSize_13Bits = 12,  /**< \brief Size of compare value to compare with timer: 13 bits */
    IfxStm_ComparatorSize_14Bits = 13,  /**< \brief Size of compare value to compare with timer: 14 bits */
    IfxStm_ComparatorSize_15Bits = 14,  /**< \brief Size of compare value to compare with timer: 15 bits */
    IfxStm_ComparatorSize_16Bits = 15,  /**< \brief Size of compare value to compare with timer: 16 bits */
    IfxStm_ComparatorSize_17Bits = 16,  /**< \brief Size of compare value to compare with timer: 17 bits */
    IfxStm_ComparatorSize_18Bits = 17,  /**< \brief Size of compare value to compare with timer: 18 bits */
    IfxStm_ComparatorSize_19Bits = 18,  /**< \brief Size of compare value to compare with timer: 19 bits */
    IfxStm_ComparatorSize_20Bits = 19,  /**< \brief Size of compare value to compare with timer: 20 bits */
    IfxStm_ComparatorSize_21Bits = 20,  /**< \brief Size of compare value to compare with timer: 21 bits */
    IfxStm_ComparatorSize_22Bits = 21,  /**< \brief Size of compare value to compare with timer: 22 bits */
    IfxStm_ComparatorSize_23Bits = 22,  /**< \brief Size of compare value to compare with timer: 23 bits */
    IfxStm_ComparatorSize_24Bits = 23,  /**< \brief Size of compare value to compare with timer: 24 bits */
    IfxStm_ComparatorSize_25Bits = 24,  /**< \brief Size of compare value to compare with timer: 25 bits */
    IfxStm_ComparatorSize_26Bits = 25,  /**< \brief Size of compare value to compare with timer: 26 bits */
    IfxStm_ComparatorSize_27Bits = 26,  /**< \brief Size of compare value to compare with timer: 27 bits */
    IfxStm_ComparatorSize_28Bits = 27,  /**< \brief Size of compare value to compare with timer: 28 bits */
    IfxStm_ComparatorSize_29Bits = 28,  /**< \brief Size of compare value to compare with timer: 29 bits */
    IfxStm_ComparatorSize_30Bits = 29,  /**< \brief Size of compare value to compare with timer: 30 bits */
    IfxStm_ComparatorSize_31Bits = 30,  /**< \brief Size of compare value to compare with timer: 31 bits */
    IfxStm_ComparatorSize_32Bits = 31   /**< \brief Size of compare value to compare with timer: 32 bits */
} IfxStm_ComparatorSize;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_STM.CLC.B.EDIS
 */
typedef enum
{
    IfxStm_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxStm_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxStm_SleepMode;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Stm_Std_Structures
 * \{ */
/** \brief Comparator Configuration Structure
 */
typedef struct
{
    IfxStm_Comparator          comparator;                /**< \brief Comparator Id defined in   MODULE_STMx.ISCR.B.CMP0IRR(x = 0, 1, 2). */
    IfxStm_ComparatorInterrupt comparatorInterrupt;       /**< \brief Comparator Interrupt request source defined in MODULE_SRC.STM.STM[index].SRx (x =0, 1). */
    IfxStm_ComparatorOffset    compareOffset;             /**< \brief Comparator start bit position  defined in MODULE_STMx.CMCON.B.MSTART0(x = 0,1,2). */
    IfxStm_ComparatorSize      compareSize;               /**< \brief Size of compare value to compare with timer defined in  MODULE_STMx.CMCON.B.MSIZE0(x = 0,1,2). */
    uint32                     ticks;                     /**< \brief count for next comparison from current timer count. */
    Ifx_Priority               triggerPriority;           /**< \brief Interrupt priority. Range = 0 .. 255. 0 = interrupt is disabled. */
    IfxSrc_Tos                 typeOfService;             /**< \brief Type of service. */
} IfxStm_CompareConfig;

/** \} */

/** \addtogroup IfxLld_Stm_Std_Module
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns system timer value.
 * \param stm pointer to System timer module registers.
 * \return system timer value.
 */
IFX_INLINE uint64 IfxStm_get(Ifx_STM *stm);

/** \brief Returns the system timer frequency.
 * \param stm pointer to System timer module registers.
 * \return the system timer frequency in Hz.
 */
IFX_INLINE float32 IfxStm_getFrequency(Ifx_STM *stm);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disables the Stm module
 * \param stm pointer to STM registers
 * \return None
 */
IFX_EXTERN void IfxStm_disableModule(Ifx_STM *stm);

/** \brief enable suspend by debugger.
 * \param stm pointer to System timer module registers.
 * \return None
 */
IFX_EXTERN void IfxStm_enableOcdsSuspend(Ifx_STM *stm);

/** \brief API to get the resource index of the STM specified.
 * \param stm pointer to System timer module registers.
 * \return system timer resource index.
 */
IFX_EXTERN IfxStm_ResourceStm IfxStm_getIndex(Ifx_STM *stm);

/** \} */

/** \addtogroup IfxLld_Stm_Std_Timer
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the lower system timer value.
 * \param stm pointer to System timer module registers.
 * \return the lower system timer value.
 */
IFX_INLINE uint32 IfxStm_getLower(Ifx_STM *stm);

/** \brief Gets the TIM3 couter value.
 * \param stm pointer to System timer module registers.
 * \return TIM3 counter value.
 */
IFX_INLINE uint32 IfxStm_getOffset12Timer(Ifx_STM *stm);

/** \brief Gets the TIM4 couter value.
 * \param stm pointer to System timer module registers.
 * \return TIM4 counter value.
 */
IFX_INLINE uint32 IfxStm_getOffset16Timer(Ifx_STM *stm);

/** \brief Gets the TIM5 couter value.
 * \param stm pointer to System timer module registers.
 * \return TIM5 counter value.
 */
IFX_INLINE uint32 IfxStm_getOffset20Timer(Ifx_STM *stm);

/** \brief Gets the TIM6 couter value.
 * \param stm pointer to System timer module registers.
 * \return TIM6 counter value.
 */
IFX_INLINE uint32 IfxStm_getOffset32Timer(Ifx_STM *stm);

/** \brief Gets the TIM1 couter value.
 * \param stm pointer to System timer module registers.
 * \return TIM1 counter value.
 */
IFX_INLINE uint32 IfxStm_getOffset4Timer(Ifx_STM *stm);

/** \brief Gets the TIM2 couter value.
 * \param stm pointer to System timer module registers.
 * \return TIM2 counter value.
 */
IFX_INLINE uint32 IfxStm_getOffset8Timer(Ifx_STM *stm);

/** \brief Returns the timer value shifted right by offset.
 * \param stm pointer to System timer module registers.
 * \param offset offset value.
 * \return the lower system timer value shifted by offset.
 */
IFX_INLINE uint32 IfxStm_getOffsetTimer(Ifx_STM *stm, uint8 offset);

/** \brief Wait for requested time.
 * The macro waits in while loop for the specified time in system timer ticks.
 * \param stm pointer to System timer module registers.
 * \param ticks ticks Wait time in system timer ticks.
 * \return None
 */
IFX_INLINE void IfxStm_waitTicks(Ifx_STM *stm, uint32 ticks);

/** \} */

/** \addtogroup IfxLld_Stm_Std_Comparator
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the updated compare register value.
 * \param stm pointer to System timer module registers.
 * \param comparator comparator selection comparator.
 * \return The compare value
 */
IFX_INLINE uint32 IfxStm_getCompare(Ifx_STM *stm, IfxStm_Comparator comparator);

/** \brief Returns the number of ticks for the selected micro seconds based on the STM frequency.
 * \param stm pointer to System timer module registers.
 * \param microSeconds Number of micro seconds that need to be converted to ticks
 * \return ticks
 */
IFX_INLINE sint32 IfxStm_getTicksFromMicroseconds(Ifx_STM *stm, uint32 microSeconds);

/** \brief Returns the number of ticks for the selected milli seconds based on the STM frequency.
 * \param stm pointer to System timer module registers.
 * \param milliSeconds Number of micro seconds that need to be converted to ticks
 * \return ticks
 */
IFX_INLINE sint32 IfxStm_getTicksFromMilliseconds(Ifx_STM *stm, uint32 milliSeconds);

/** \brief Update the compare register value increased with given ticks.
 * \param stm pointer to System timer module registers.
 * \param comparator comparator selection comparator.
 * \param ticks count for next comparison from current timer count.
 * \return None
 */
IFX_INLINE void IfxStm_increaseCompare(Ifx_STM *stm, IfxStm_Comparator comparator, uint32 ticks);

/** \brief Update the compare register value.
 * \param stm pointer to System timer module registers.
 * \param comparator comparator selection comparator.
 * \param ticks count for next comparison.
 * \return None
 */
IFX_INLINE void IfxStm_updateCompare(Ifx_STM *stm, IfxStm_Comparator comparator, uint32 ticks);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clear the compare interrupt flag.
 * \param stm pointer to System timer module registers.
 * \param comparator comparator selection comparator.
 * \return None
 */
IFX_EXTERN void IfxStm_clearCompareFlag(Ifx_STM *stm, IfxStm_Comparator comparator);

/** \brief Enables the compare interrupt .
 * \param stm pointer to System timer module registers.
 * \param comparator comparator selection comparator.
 * \return None
 */
IFX_EXTERN void IfxStm_enableComparatorInterrupt(Ifx_STM *stm, IfxStm_Comparator comparator);

/** \brief Initialise stm compare register.
 * \param stm pointer to System timer module registers.
 * \param config pointer to configuration structure.
 * \return TRUE if Comparator successful otherwise FLASE.
 */
IFX_EXTERN boolean IfxStm_initCompare(Ifx_STM *stm, const IfxStm_CompareConfig *config);

/** \brief Initialise compare configuration with default values.
 * \param config pointer to configuration structure.
 * \return None
 */
IFX_EXTERN void IfxStm_initCompareConfig(IfxStm_CompareConfig *config);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \param stm pointer STM registers
 * \param mode mode selection (enable/ disable)
 * \return None
 */
IFX_INLINE void IfxStm_setSleepMode(Ifx_STM *stm, IfxStm_SleepMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \param stm pointer to STM registers
 * \return None
 */
IFX_EXTERN void IfxStm_resetModule(Ifx_STM *stm);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE uint64 IfxStm_get(Ifx_STM *stm)
{
    uint64 result;

    result  = stm->TIM0.U;
    result |= ((uint64)stm->CAP.U) << 32;

    return result;
}


IFX_INLINE uint32 IfxStm_getCompare(Ifx_STM *stm, IfxStm_Comparator comparator)
{
    return stm->CMP[comparator].B.CMPVAL;
}


IFX_INLINE float32 IfxStm_getFrequency(Ifx_STM *stm)
{
    float32 result;

    result = IfxScuCcu_getStmFrequency();

    return result;
}


IFX_INLINE uint32 IfxStm_getLower(Ifx_STM *stm)
{
    return stm->TIM0.U;
}


IFX_INLINE uint32 IfxStm_getOffset12Timer(Ifx_STM *stm)
{
    return stm->TIM3.U;
}


IFX_INLINE uint32 IfxStm_getOffset16Timer(Ifx_STM *stm)
{
    return stm->TIM4.U;
}


IFX_INLINE uint32 IfxStm_getOffset20Timer(Ifx_STM *stm)
{
    return stm->TIM5.U;
}


IFX_INLINE uint32 IfxStm_getOffset32Timer(Ifx_STM *stm)
{
    return stm->TIM6.U;
}


IFX_INLINE uint32 IfxStm_getOffset4Timer(Ifx_STM *stm)
{
    return stm->TIM1.U;
}


IFX_INLINE uint32 IfxStm_getOffset8Timer(Ifx_STM *stm)
{
    return stm->TIM2.U;
}


IFX_INLINE uint32 IfxStm_getOffsetTimer(Ifx_STM *stm, uint8 offset)
{
    uint64 now;

    now = IfxStm_get(stm);

    return (uint32)(now >> offset);
}


IFX_INLINE sint32 IfxStm_getTicksFromMicroseconds(Ifx_STM *stm, uint32 microSeconds)
{
    sint32 freq = (sint32)IfxStm_getFrequency(stm);
    return (freq / (1000000)) * microSeconds;
}


IFX_INLINE sint32 IfxStm_getTicksFromMilliseconds(Ifx_STM *stm, uint32 milliSeconds)
{
    sint32 freq = (sint32)IfxStm_getFrequency(stm);
    return (freq / (1000)) * milliSeconds;
}


IFX_INLINE void IfxStm_increaseCompare(Ifx_STM *stm, IfxStm_Comparator comparator, uint32 ticks)
{
    stm->CMP[comparator].B.CMPVAL = stm->CMP[comparator].B.CMPVAL + ticks;
}


IFX_INLINE void IfxStm_setSleepMode(Ifx_STM *stm, IfxStm_SleepMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    stm->CLC.B.EDIS = mode;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxStm_updateCompare(Ifx_STM *stm, IfxStm_Comparator comparator, uint32 ticks)
{
    stm->CMP[comparator].B.CMPVAL = ticks;
}


IFX_INLINE void IfxStm_waitTicks(Ifx_STM *stm, uint32 ticks)
{
    uint32 beginTime;

    beginTime = IfxStm_getLower(stm);

    /*below code will work because of unsigned 32 bit calculation even at timer wrapping condition
     * As an example if beginTime = 0xFFFFFFFE and current time = 2 (after overflow), unsigned calculation
     * 2 - 0xFFFFFFFE will be 4*/
    while ((IfxStm_getLower(stm) - beginTime) < ticks)
    {}
}


#endif /* IFXSTM_H */
