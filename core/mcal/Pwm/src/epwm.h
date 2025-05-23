/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 *
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with
 * the terms contained in the written license agreement between you and ArcCore,
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as
 * published by the Free Software Foundation and appearing in the file
 * LICENSE.GPL included in the packaging of this file or here
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/
/* --COPYRIGHT--,BSD
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
#ifndef _PWM_H_
#define _PWM_H_

/** @file   epwm.h
 * 	@brief  Contains public interface to various functions related
 *
 * (C) Copyright 2011, Texas Instruments, Inc. */


// **************************************************************************
// the includes

/*lint -save -w1 EXTERNAL FILE */

#include <stdint.h>
#include "string.h"
/* Include Platform_Types.h For endianness */
#include "Platform_Types.h"

//!
//!
//! \defgroup EPWM EPWM
//!
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines


//! \brief Defines the location of the ZRO bits in the AQCTL register
//!
#define PWM_AQCTL_ZRO_BITS              (3 << 0)

//! \brief Defines the location of the PRD bits in the AQCTL register
//!
#define PWM_AQCTL_PRD_BITS              (3 << 2)

//! \brief Defines the location of the CAU bits in the AQCTL register
//!
#define PWM_AQCTL_CAU_BITS              (3 << 4)

//! \brief Defines the location of the CAD bits in the AQCTL register
//!
#define PWM_AQCTL_CAD_BITS              (3 << 6)

//! \brief Defines the location of the CBU bits in the AQCTL register
//!
#define PWM_AQCTL_CBU_BITS              (3 << 8)

//! \brief Defines the location of the CBD bits in the AQCTL register
//!
#define PWM_AQCTL_CBD_BITS              (3 << 10)

//! \brief Defines the location of the CSFA bits in the AQCSFRC register
//!
#define PWM_AQCSFRC_CSFA_BITS           (3 << 0)

//! \brief Defines the location of the CSFB bits in the AQCSFRC register
//!
#define PWM_AQCSFRC_CSFB_BITS           (3 << 2)

//! \brief Defines the location of the LOADAMODE bits in the CMPCTL register
//!
#define PWM_CMPCTL_LOADAMODE_BITS       (3 << 0)

//! \brief Defines the location of the LOADBMODE bits in the CMPCTL register
//!
#define PWM_CMPCTL_LOADBMODE_BITS       (3 << 2)

//! \brief Defines the location of the SHDWAMODE bits in the CMPCTL register
//!
#define PWM_CMPCTL_SHDWAMODE_BITS       (1 << 4)

//! \brief Defines the location of the SHDWBMODE bits in the CMPCTL register
//!
#define PWM_CMPCTL_SHDWBMODE_BITS       (1 << 6)

//! \brief Defines the location of the SHDWAFULL bits in the CMPCTL register
//!
#define PWM_CMPCTL_SHDWAFULL_BITS       (1 << 8)

//! \brief Defines the location of the SHDWBFULL bits in the CMPCTL register
//!
#define PWM_CMPCTL_SHDWBFULL_BITS       (1 << 9)


//! \brief Defines the location of the OUTMODE bits in the DBCTL register
//!
#define PWM_DBCTL_OUTMODE_BITS          (3 << 0)

//! \brief Defines the location of the POLSEL bits in the DBCTL register
//!
#define PWM_DBCTL_POLSEL_BITS           (3 << 2)

//! \brief Defines the location of the INMODE bits in the DBCTL register
//!
#define PWM_DBCTL_INMODE_BITS           (3 << 4)

//! \brief Defines the location of the HALFCYCLE bits in the DBCTL register
//!
#define PWM_DBCTL_HALFCYCLE_BITS        (1 << 15)


//! \brief Defines the location of the ETCR bits in the ETCLR register
//!
#define PWM_ETCLR_INT_BITS              (1 << 0)

//! \brief Defines the location of the SOCA bits in the ETCLR register
//!
#define PWM_ETCLR_SOCA_BITS             (1 << 2)

//! \brief Defines the location of the SOCB bits in the ETCLR register
//!
#define PWM_ETCLR_SOCB_BITS             (1 << 3)


//! \brief Defines the location of the INTPRD bits in the ETPS register
//!
#define PWM_ETPS_INTPRD_BITS            (3 << 0)

//! \brief Defines the location of the INTCNT bits in the ETPS register
//!
#define PWM_ETPS_INTCNT_BITS            (3 << 2)

//! \brief Defines the location of the SOCAPRD bits in the ETPS register
//!
#define PWM_ETPS_SOCAPRD_BITS           (3 << 8)

//! \brief Defines the location of the SOCACNT bits in the ETPS register
//!
#define PWM_ETPS_SOCACNT_BITS           (3 << 10)

//! \brief Defines the location of the SOCBPRD bits in the ETPS register
//!
#define PWM_ETPS_SOCBPRD_BITS           (3 << 12)

//! \brief Defines the location of the SOCBCNT bits in the ETPS register
//!
#define PWM_ETPS_SOCBCNT_BITS           (3 << 14)


//! \brief Defines the location of the INTSEL bits in the ETSEL register
//!
#define PWM_ETSEL_INTSEL_BITS           (7 << 0)

//! \brief Defines the location of the INTEN bits in the ETSEL register
//!
#define PWM_ETSEL_INTEN_BITS            (1 << 3)

//! \brief Defines the location of the SOCASEL bits in the ETSEL register
//!
#define PWM_ETSEL_SOCASEL_BITS          (7 << 8)

//! \brief Defines the location of the SOCAEN bits in the ETSEL register
//!
#define PWM_ETSEL_SOCAEN_BITS           (1 << 11)

//! \brief Defines the location of the SOCBSEL bits in the ETSEL register
//!
#define PWM_ETSEL_SOCBSEL_BITS          (7 << 12)

//! \brief Defines the location of the SOCBEN bits in the ETSEL register
//!
#define PWM_ETSEL_SOCBEN_BITS           (1 << 15)


//! \brief Defines the location of the CHPEN bits in the PCCTL register
//!
#define PWM_PCCTL_CHPEN_BITS            (1 << 0)

//! \brief Defines the location of the OSHTWTH bits in the PCCTL register
//!
#define PWM_PCCTL_OSHTWTH_BITS          (15 << 1)

//! \brief Defines the location of the CHPFREQ bits in the PCCTL register
//!
#define PWM_PCCTL_CHPFREQ_BITS          (7 << 5)

//! \brief Defines the location of the CHPDUTY bits in the PCCTL register
//!
#define PWM_PCCTL_CHPDUTY_BITS          (7 << 8)



//! \brief Defines the location of the CTRMODE bits in the TBCTL register
//!
#define PWM_TBCTL_CTRMODE_BITS          (3 << 0)

//! \brief Defines the location of the PHSEN bits in the TBCTL register
//!
#define PWM_TBCTL_PHSEN_BITS            (1 << 2)

//! \brief Defines the location of the PRDLD bits in the TBCTL register
//!
#define PWM_TBCTL_PRDLD_BITS            (1 << 3)

//! \brief Defines the location of the SYNCOSEL bits in the TBCTL register
//!
#define PWM_TBCTL_SYNCOSEL_BITS         (3 << 4)

//! \brief Defines the location of the SWFSYNC bits in the TBCTL register
//!
#define PWM_TBCTL_SWFSYNC_BITS          (1 << 6)

//! \brief Defines the location of the HSPCLKDIV bits in the TBCTL register
//!
#define PWM_TBCTL_HSPCLKDIV_BITS        (7 << 7)

//! \brief Defines the location of the CLKDIV bits in the TBCTL register
//!
#define PWM_TBCTL_CLKDIV_BITS           (7 << 10)

//! \brief Defines the location of the PHSDIR bits in the TBCTL register
//!
#define PWM_TBCTL_PHSDIR_BITS           (1 << 13)

//! \brief Defines the location of the FREESOFT bits in the TBCTL register
//!
#define PWM_TBCTL_FREESOFT_BITS         (3 << 14)


//! \brief Defines the location of the INT bits in the TXCLR register
//!
#define PWM_TZCLR_INT_BITS              (1 << 0)

//! \brief Defines the location of the CBC bits in the TXCLR register
//!
#define PWM_TZCLR_CBC_BITS              (1 << 1)

//! \brief Defines the location of the OST bits in the TXCLR register
//!
#define PWM_TZCLR_OST_BITS              (1 << 2)

//! \brief Defines the location of the DCAEVT1 bits in the TXCLR register
//!
#define PWM_TZCLR_DCAEVT1_BITS          (1 << 3)

//! \brief Defines the location of the DCAEVT2 bits in the TXCLR register
//!
#define PWM_TZCLR_DCAEVT2_BITS          (1 << 4)

//! \brief Defines the location of the DCBEVT1 bits in the TXCLR register
//!
#define PWM_TZCLR_DCBEVT1_BITS          (1 << 5)

//! \brief Defines the location of the DCBEVT2 bits in the TXCLR register
//!
#define PWM_TZCLR_DCBEVT2_BITS          (1 << 6)


//! \brief Defines the location of the TZA bits in the TZCTL register
//!
#define PWM_TZCTL_TZA_BITS              (3 << 0)

//! \brief Defines the location of the  TZB bits in the TZCTL register
//!
#define PWM_TZCTL_TZB_BITS              (3 << 2)

//! \brief Defines the location of the DCAEVT1 bits in the TZCTL register
//!
#define PWM_TZCTL_DCAEVT1_BITS          (3 << 4)

//! \brief Defines the location of the DCAEVT2 bits in the TZCTL register
//!
#define PWM_TZCTL_DCAEVT2_BITS          (3 << 6)

//! \brief Defines the location of the DCBEVT1 bits in the TZCTL register
//!
#define PWM_TZCTL_DCBEVT1_BITS          (3 << 8)

//! \brief Defines the location of the DCBEVT2 bits in the TZCTL register
//!
#define PWM_TZCTL_DCBEVT2_BITS          (3 << 10)


//! \brief Defines the location of the CBC bits in the TZFRC register
//!
#define PWM_TZFRC_CBC_BITS              (1 << 1)

//! \brief Defines the location of the OST bits in the TZFRC register
//!
#define PWM_TZFRC_OST_BITS              (1 << 2)

//! \brief Defines the location of the DCAEVT1 bits in the TZFRC register
//!
#define PWM_TZFRC_DCAEVT1_BITS          (1 << 3)

//! \brief Defines the location of the DCAEVT2 bits in the TZFRC register
//!
#define PWM_TZFRC_DCAEVT2_BITS          (1 << 4)

//! \brief Defines the location of the DCBEVT1 bits in the TZFRC register
//!
#define PWM_TZFRC_DCBEVT1_BITS          (1 << 5)

//! \brief Defines the location of the DCBEVT2 bits in the TZFRC register
//!
#define PWM_TZFRC_DCBEVT2_BITS          (1 << 6)


#if defined(CFG_TMS570LS12X)
#define PWM_IOMM_KICK0 0xFFFFEA38
#define PWM_IOMM_KICK1 0xFFFFEA3C
#elif defined(CFG_TMS570LC43X)
#define PWM_IOMM_KICK0 (IOMM_BASE_ADDR + 0x38u)
#define PWM_IOMM_KICK1 (IOMM_BASE_ADDR + 0x3Cu)
#endif

// There are 48 PINMMR registers, each is 32 bits
// PINMMR37 and PINMMR38 are used to enable/disable PWM
#define PWM_PINMMR02_BASE_ADDR			0xFFFFEB18
#define PWM_PINMMR03_BASE_ADDR			0xFFFFEB1C

#ifdef CFG_TMS570LC43X
#define PINMMR166_IOMM_BASE_ADDR_OFFSET	0x3A8u
#define PINMMR166_ADDR					((uint32 *)(IOMM_BASE_ADDR + PINMMR166_IOMM_BASE_ADDR_OFFSET))
#elif defined(CFG_TMS570LS12X)
#define PWM_PINMMR37_BASE_ADDR			0xFFFFEBA4
#define PWM_PINMMR38_BASE_ADDR			0xFFFFEBA8
#endif

#define PWM_REQENASET2_BASE_ADDR		0xFFFFFE38
#define PWM_REQENASET3_BASE_ADDR		0xFFFFFE3C


// **************************************************************************
// the typedefs

//! \brief Enumeration to define the pulse width modulation (PWM) action qualifiers
//!
typedef enum
{
  PWM_ActionQual_Disabled=0,
  PWM_ActionQual_Clear,
  PWM_ActionQual_Set,
  PWM_ActionQual_Toggle
} PWM_ActionQual_e;


//! \brief Enumeration to define the pulse width modulation (PWM) Action-qualifier Continuous Software Force
//!
typedef enum
{
  PWM_ActionQualContSWForce_Disabled=0,
  PWM_ActionQualContSWForce_Clear,
  PWM_ActionQualContSWForce_Set
} PWM_ActionQualContSWForce_e;


//! \brief Enumeration to define the pulse width modulation (PWM) clock dividers
//!
typedef enum
{
  PWM_ClkDiv_by_1=(0 << 10),
  PWM_ClkDiv_by_2=(1 << 10),
  PWM_ClkDiv_by_4=(2 << 10),
  PWM_ClkDiv_by_8=(3 << 10),
  PWM_ClkDiv_by_16=(4 << 10),
  PWM_ClkDiv_by_32=(5 << 10),
  PWM_ClkDiv_by_64=(6 << 10),
  PWM_ClkDiv_by_128=(7 << 10)
} PWM_ClkDiv_e;


//! \brief Enumeration to define the pulse width modulation (PWM) chopping clock frequencies
//!
typedef enum
{
  PWM_ChoppingClkFreq_SysClkOut_by_1=(0 << 5),
  PWM_ChoppingClkFreq_SysClkOut_by_2=(1 << 5),
  PWM_ChoppingClkFreq_SysClkOut_by_3=(2 << 5),
  PWM_ChoppingClkFreq_SysClkOut_by_4=(3 << 5),
  PWM_ChoppingClkFreq_SysClkOut_by_5=(4 << 5),
  PWM_ChoppingClkFreq_SysClkOut_by_6=(5 << 5),
  PWM_ChoppingClkFreq_SysClkOut_by_7=(6 << 5),
  PWM_ChoppingClkFreq_SysClkOut_by_8=(7 << 5)
} PWM_ChoppingClkFreq_e;


//! \brief Enumeration to define the pulse width modulation (PWM) chopping clock duty cycles
//!
typedef enum
{
  PWM_ChoppingDutyCycle_One_Eighth=(0 << 8),
  PWM_ChoppingDutyCycle_Two_Eighths=(1 << 8),
  PWM_ChoppingDutyCycle_Three_Eighths=(2 << 8),
  PWM_ChoppingDutyCycle_Four_Eighths=(3 << 8),
  PWM_ChoppingDutyCycle_Five_Eighths=(4 << 8),
  PWM_ChoppingDutyCycle_Six_Eighths=(5 << 8),
  PWM_ChoppingDutyCycle_Seven_Eighths=(6 << 8)
} PWM_ChoppingDutyCycle_e;


//! \brief Enumeration to define the pulse width modulation (PWM) chopping clock pulse widths
//!
typedef enum
{
  PWM_ChoppingPulseWidth_One_Eighth_SysClkOut=(0 << 1),
  PWM_ChoppingPulseWidth_Two_Eighths_SysClkOut=(1 << 1),
  PWM_ChoppingPulseWidth_Three_Eighths_SysClkOut=(2 << 1),
  PWM_ChoppingPulseWidth_Four_Eighths_SysClkOut=(3 << 1),
  PWM_ChoppingPulseWidth_Five_Eighths_SysClkOut=(4 << 1),
  PWM_ChoppingPulseWidth_Six_Eighths_SysClkOut=(5 << 1),
  PWM_ChoppingPulseWidth_Seven_Eighths_SysClkOut=(6 << 1),
  PWM_ChoppingPulseWidth_Eight_Eighths_SysClkOut=(7 << 1),
  PWM_ChoppingPulseWidth_Nine_Eighths_SysClkOut=(8 << 1),
  PWM_ChoppingPulseWidth_Ten_Eighths_SysClkOut=(9 << 1),
  PWM_ChoppingPulseWidth_Eleven_Eighths_SysClkOut=(10 << 1),
  PWM_ChoppingPulseWidth_Twelve_Eighths_SysClkOut=(11 << 1),
  PWM_ChoppingPulseWidth_Thirteen_Eighths_SysClkOut=(12 << 1),
  PWM_ChoppingPulseWidth_Fourteen_Eighths_SysClkOut=(13 << 1),
  PWM_ChoppingPulseWidth_Fifteen_Eighths_SysClkOut=(14 << 1),
  PWM_ChoppingPulseWidth_Sixteen_Eighths_SysClkOut=(15 << 1)
} PWM_ChoppingPulseWidth_e;


//! \brief Enumeration to define the pulse width modulation (PWM) counter modes
//!
typedef enum
{
  PWM_CounterMode_Up=(0 << 0),
  PWM_Countermode_Down=(1 << 0),
  PWM_CounterMode_UpDown=(2 << 0),
  PWM_CounterMode_Stop=(3 << 0)
} PWM_CounterMode_e;


//! \brief Enumeration to define the pulse width modulation (PWM) deadband options
//!
typedef enum
{
  PWM_DeadBandInputMode_EPWMxA_Rising_and_Falling=(0 << 4),
  PWM_DeadBandInputMode_EPWMxA_Falling_EPWMxB_Rising=(1 << 4),
  PWM_DeadBandInputMode_EPWMxA_Rising_EPWMxB_Falling=(2 << 4),
  PWM_DeadBandInputMode_EPWMxB_Rising_and_Falling=(3 << 4)
} PWM_DeadBandInputMode_e;


//! \brief Enumeration to define the pulse width modulation (PWM) deadband output modes
//!
typedef enum
{
  PWM_DeadBandOutputMode_Bypass=(0 << 0),
  PWM_DeadBandOutputMode_EPWMxA_Disable_EPWMxB_Falling=(1 << 0),
  PWM_DeadBandOutputMode_EPWMxA_Rising_EPWMxB_Disable=(2 << 0),
  PWM_DeadBandOutputMode_EPWMxA_Rising_EPWMxB_Falling=(3 << 0)
} PWM_DeadBandOutputMode_e;


//! \brief Enumeration to define the pulse width modulation (PWM) deadband polarity
//!
typedef enum
{
  PWM_DeadBandPolarity_EPWMxA_EPWMxB=(0 << 2),
  PWM_DeadBandPolarity_EPWMxA_Inverted=(1 << 2),
  PWM_DeadBandPolarity_EPWMxB_Inverted=(2 << 2),
  PWM_DeadBandPolarity_EPWMxA_Inverted_EPWMxB_Inverted=(3 << 2)
} PWM_DeadBandPolarity_e;


//! \brief Enumeration to define the pulse width modulation (PWM) high speed clock divide options
//!
typedef enum
{
  PWM_HspClkDiv_by_1=(0 << 7),
  PWM_HspClkDiv_by_2=(1 << 7),
  PWM_HspClkDiv_by_4=(2 << 7),
  PWM_HspClkDiv_by_6=(3 << 7),
  PWM_HspClkDiv_by_8=(4 << 7),
  PWM_HspClkDiv_by_10=(5 << 7),
  PWM_HspClkDiv_by_12=(6 << 7),
  PWM_HspClkDiv_by_14=(7 << 7)
} PWM_HspClkDiv_e;


//! \brief Enumeration to define the pulse width modulation (PWM) interrupt generation modes
//!
typedef enum
{
  PWM_IntMode_CounterEqualZero=(1 << 0),
  PWM_IntMode_CounterEqualPeriod=(2 << 0),
  PWM_IntMode_CounterEqualZeroOrPeriod=(3 << 0),
  PWM_IntMode_CounterEqualCmpAIncr=(4 << 0),
  PWM_IntMode_CounterEqualCmpADecr=(5 << 0),
  PWM_IntMode_CounterEqualCmpBIncr=(6 << 0),
  PWM_IntMode_CounterEqualCmpBDecr=(7 << 0)
} PWM_IntMode_e;


//! \brief Enumeration to define the pulse width modulation (PWM) interrupt period options
//!
typedef enum
{
  PWM_IntPeriod_Disable=(0 << 0),
  PWM_IntPeriod_FirstEvent=(1 << 0),
  PWM_IntPeriod_SecondEvent=(2 << 0),
  PWM_IntPeriod_ThirdEvent=(3 << 0)
} PWM_IntPeriod_e;


//! \brief Enumeration to define the pulse width modulation (PWM) load modes
//!
typedef enum
{
  PWM_LoadMode_Zero=0,
  PWM_LoadMode_Period,
  PWM_LoadMode_Either,
  PWM_LoadMode_Freeze
} PWM_LoadMode_e;


//! \brief Enumeration to define the pulse width modulation (PWM) numbers
//!
typedef enum
{
  PWM_Number_1=0,
  PWM_Number_2,
  PWM_Number_3,
  PWM_Number_4,
  PWM_Number_5,
  PWM_Number_6,
  PWM_Number_7
} PWM_Number_e;


//! \brief Enumeration to define the pulse width modulation (PWM) period load options
//!
typedef enum
{
  PWM_PeriodLoad_Shadow=(0 << 3),
  PWM_PeriodLoad_Immediate=(1 << 3)
} PWM_PeriodLoad_e;


//! \brief Enumeration to define the pulse width modulation (PWM) phase direction modes
//!
typedef enum
{
  PWM_PhaseDir_CountDown=(0 << 13),
  PWM_PhaseDir_CountUp=(1 << 13)
} PWM_PhaseDir_e;


//! \brief Enumeration to define the pulse width modulation (PWM) run modes
//!
typedef enum
{
  PWM_RunMode_SoftStopAfterIncr=(0 << 14),
  PWM_RunMode_SoftStopAfterDecr=(0 << 14),
  PWM_RunMode_SoftStopAfterCycle=(1 << 14),
  PWM_RunMode_FreeRun=(2 << 14)
} PWM_RunMode_e;


//! \brief Enumeration to define the pulse width modulation (PWM) shadow modes
//!
typedef enum
{
  PWM_ShadowMode_Shadow=0,
  PWM_ShadowMode_Immediate
} PWM_ShadowMode_e;


//! \brief Enumeration to define the pulse width modulation (PWM) shadow status options
//!
typedef enum
{
  PWM_ShadowStatus_NotFull=0,
  PWM_ShadowStatus_Full
} PWM_ShadowStatus_e;


//! \brief Enumeration to define the pulse width modulation (PWM) start of conversion (SOC) period options
//!
typedef enum
{
  PWM_SocPeriod_Disable=0,
  PWM_SocPeriod_FirstEvent,
  PWM_SocPeriod_SecondEvent,
  PWM_SocPeriod_ThirdEvent
} PWM_SocPeriod_e;


//! \brief Enumeration to define the pulse width modulation (PWM) start of conversion (SOC) sources
//!
typedef enum
{
  PWM_SocPulseSrc_DcEvt=0,
  PWM_SocPulseSrc_CounterEqualZero,
  PWM_SocPulseSrc_CounterEqualPeriod,
  PWM_SocPulseSrc_CounterEqualZeroOrPeriod,
  PWM_SocPulseSrc_CounterEqualCmpAIncr,
  PWM_SocPulseSrc_CounterEqualCmpADecr,
  PWM_SocPulseSrc_CounterEqualCmpBIncr,
  PWM_SocPulseSrc_CounterEqualCmpBDecr
} PWM_SocPulseSrc_e;


//! \brief Enumeration to define the pulse width modulation (PWM) sync modes
//!
typedef enum
{
  PWM_SyncMode_EPWMxSYNC=(0 << 4),
  PWM_SyncMode_CounterEqualZero=(1 << 4),
  PWM_SyncMode_CounterEqualCounterCompareZero=(2 << 4),
  PWM_SyncMode_Disable=(3 << 4)
} PWM_SyncMode_e;


//! \brief Enumeration to define the pulse width modulation (PWM) trip zone sources
//!
typedef enum
{
  PWM_TripZoneSrc_CycleByCycle_TZ1_NOT=(1 << 0),
  PWM_TripZoneSrc_CycleByCycle_TZ2_NOT=(1 << 1),
  PWM_TripZoneSrc_CycleByCycle_TZ3_NOT=(1 << 2),
  PWM_TripZoneSrc_CycleByCycle_TZ4_NOT=(1 << 3),
  PWM_TripZoneSrc_CycleByCycle_TZ5_NOT=(1 << 4),
  PWM_TripZoneSrc_CycleByCycle_TZ6_NOT=(1 << 5),
  PWM_TripZoneSrc_CycleByCycle_CmpA=(1 << 6),
  PWM_TripZoneSrc_CycleByCycle_CmpB=(1 << 7),
  PWM_TripZoneSrc_OneShot_TZ1_NOT=(1 << 8),
  PWM_TripZoneSrc_OneShot_TZ2_NOT=(1 << 9),
  PWM_TripZoneSrc_OneShot_TZ3_NOT=(1 << 10),
  PWM_TripZoneSrc_OneShot_TZ4_NOT=(1 << 11),
  PWM_TripZoneSrc_OneShot_TZ5_NOT=(1 << 12),
  PWM_TripZoneSrc_OneShot_TZ6_NOT=(1 << 13),
  PWM_TripZoneSrc_OneShot_CmpA=(1 << 14),
  PWM_TripZoneSrc_OneShot_CmpB=(1 << 15)
} PWM_TripZoneSrc_e;


//! \brief Enumeration to define the pulse width modulation (PWM) trip zone states
//!
typedef enum
{
  PWM_TripZoneState_HighImp=0,
  PWM_TripZoneState_EPWM_High,
  PWM_TripZoneState_EPWM_Low,
  PWM_TripZoneState_DoNothing
} PWM_TripZoneState_e;

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
//! \brief Defines the pulse width modulation (PWM) object
//!
typedef struct _PWM_Obj_
{
  uint16_t   TBCTL;       //!< Time-Base Control Register
  uint16_t   TBSTS;       //!< Time-Base Status Register
  uint16_t   TBPHSHR;     //!< Extension for the HRPWM Phase Register
  uint16_t   TBPHS;       //!< Time-Base Phase Register
  uint16_t   TBCTR;       //!< Time-Base Counter
  uint16_t   TBPRD;       //!< Time-Base Period register set
  uint16_t   TBPRDHR;     //!< Time-Base Period High Resolution Register
  uint16_t   CMPCTL;      //!< Counter-Compare Control Register
  uint16_t   CMPAHR;      //!< Extension of HRPWM Counter-Compare A Register
  uint16_t   CMPA;        //!< Counter-Compare A Register
  uint16_t   CMPB;        //!< Counter-Compare B Register
  uint16_t   AQCTLA;      //!< Action-Qualifier Control Register for Output A (EPWMxA)
  uint16_t   AQCTLB;      //!< Action-Qualifier Control Register for Output B (EPWMxB)
  uint16_t   AQSFRC;      //!< Action qual SW force
  uint16_t   AQCSFRC;     //!< Action qualifier continuous SW force
  uint16_t   DBCTL;       //!< Dead-band control
  uint16_t   DBRED;       //!< Dead-band rising edge delay
  uint16_t   DBFED;       //!< Dead-band falling edge delay
  uint16_t   TZSEL;       //!< Trip zone select
  uint16_t   TZDCSEL;     //!< Trip zone digital comparator select
  uint16_t   TZCTL;       //!< Trip zone control
  uint16_t   TZEINT;      //!< Trip zone interrupt enable
  uint16_t   TZFLG;       //!< Trip zone interrupt flags
  uint16_t   TZCLR;       //!< Trip zone clear
  uint16_t   TZFRC;       //!< Trip zone force interrupt
  uint16_t   ETSEL;       //!< Event trigger selection
  uint16_t   ETPS;        //!< Event trigger pre-scaler
  uint16_t   ETFLG;       //!< Event trigger flags
  uint16_t   ETCLR;       //!< Event trigger clear
  uint16_t   ETFRC;       //!< Event trigger force
  uint16_t   PCCTL;       //!< PWM chopper control
  uint16_t   rsvd_1;      //!< Reserved
  uint16_t	 HRCTL;
  uint16_t	 HRCALM;
  uint16_t	 HRCAL;
  uint16_t	 HRPRD;
  uint16_t	 HRCOUNT0;
  uint16_t	 HRCOUNT1;
  uint16_t   HRMSTEP;     //!< HRPWM MEP Step Register
  uint16_t   rsvd_2;      //!< Reserved
  uint16_t	 TRCTL;
  uint16_t	 TRREM;
  uint16_t	 TBPRDHRM;
  uint16_t   TBPRDM;
  uint16_t	 CMPAHRM;
  uint16_t   CMPAM;
  uint16_t	 rsvd_3;
  uint16_t   DCTRIPSEL;   //!< Digital Compare Trip Select
  uint16_t   DCACTL;      //!< Digital Compare A Control
  uint16_t   DCBCTL;      //!< Digital Compare B Control
  uint16_t   DCFCTL;      //!< Digital Compare Filter Control
  uint16_t   DCCAPCTL;    //!< Digital Compare Capture Control
  uint16_t   DCFOFFSET;   //!< Digital Compare Filter Offset
  uint16_t   DCFOFFSETCNT;//!< Digital Compare Filter Offset Counter
  uint16_t   DCFWINDOW;   //!< Digital Compare Filter Window
  uint16_t   DCFWINDOWCNT;//!< Digital Compare Filter Window Counter
  uint16_t   DCCAP;       //!< Digital Compare Filter Counter Capture
  uint16_t   rsvd_4;      //!< Reserved
  uint16_t   rsvd_5;      //!< Reserved
  uint16_t   ETEST;       //!< TEST
  uint16_t   EPWMREV;     //!< EPWM REV
  uint16_t   HRPWMREV;    //!< HR PWM REV
} PWM_Obj;

#else
//! \brief Defines the pulse width modulation (PWM) object
//!
typedef struct _PWM_Obj_
{
  uint16_t   TBSTS;       //!< Time-Base Status Register
  uint16_t   TBCTL;       //!< Time-Base Control Register
  uint16_t   TBPHS;       //!< Time-Base Phase Register
  uint16_t   TBPHSHR;     //!< Extension for the HRPWM Phase Register
  uint16_t   TBPRD;       //!< Time-Base Period register set
  uint16_t   TBCTR;       //!< Time-Base Counter
  uint16_t   CMPCTL;      //!< Counter-Compare Control Register
  uint16_t   TBPRDHR;     //!< Time-Base Period High Resolution Register
  uint16_t   CMPA;        //!< Counter-Compare A Register
  uint16_t   CMPAHR;      //!< Extension of HRPWM Counter-Compare A Register
  uint16_t   AQCTLA;      //!< Action-Qualifier Control Register for Output A (EPWMxA)
  uint16_t   CMPB;        //!< Counter-Compare B Register
  uint16_t   AQSFRC;      //!< Action qual SW force
  uint16_t   AQCTLB;      //!< Action-Qualifier Control Register for Output B (EPWMxB)
  uint16_t   DBCTL;       //!< Dead-band control
  uint16_t   AQCSFRC;     //!< Action qualifier continuous SW force
  uint16_t   DBFED;       //!< Dead-band falling edge delay
  uint16_t   DBRED;       //!< Dead-band rising edge delay
  uint16_t   TZDCSEL;     //!< Trip zone digital comparator select
  uint16_t   TZSEL;       //!< Trip zone select
  uint16_t   TZEINT;      //!< Trip zone interrupt enable
  uint16_t   TZCTL;       //!< Trip zone control
  uint16_t   TZCLR;       //!< Trip zone clear
  uint16_t   TZFLG;       //!< Trip zone interrupt flags
  uint16_t   ETSEL;       //!< Event trigger selection
  uint16_t   TZFRC;       //!< Trip zone force interrupt
  uint16_t   ETFLG;       //!< Event trigger flags
  uint16_t   ETPS;        //!< Event trigger pre-scaler
  uint16_t   ETFRC;       //!< Event trigger force
  uint16_t   ETCLR;       //!< Event trigger clear
  uint16_t   rsvd_1;      //!< Reserved
  uint16_t   PCCTL;       //!< PWM chopper control
  uint16_t	 HRCALM;
  uint16_t	 HRCTL;
  uint16_t	 HRPRD;
  uint16_t	 HRCAL;
  uint16_t	 HRCOUNT1;
  uint16_t	 HRCOUNT0;
  uint16_t   rsvd_2;      //!< Reserved
  uint16_t   HRMSTEP;     //!< HRPWM MEP Step Register
  uint16_t	 TRREM;
  uint16_t	 TRCTL;
  uint16_t   TBPRDM;
  uint16_t	 TBPRDHRM;
  uint16_t   CMPAM;
  uint16_t	 CMPAHRM;
  uint16_t	 rsvd_3;
  uint16_t   DCACTL;      //!< Digital Compare A Control
  uint16_t   DCTRIPSEL;   //!< Digital Compare Trip Select
  uint16_t   DCFCTL;      //!< Digital Compare Filter Control
  uint16_t   DCBCTL;      //!< Digital Compare B Control
  uint16_t   DCFOFFSET;   //!< Digital Compare Filter Offset
  uint16_t   DCCAPCTL;    //!< Digital Compare Capture Control
  uint16_t   DCFWINDOW;   //!< Digital Compare Filter Window
  uint16_t   DCFOFFSETCNT;//!< Digital Compare Filter Offset Counter
  uint16_t   DCCAP;       //!< Digital Compare Filter Counter Capture
  uint16_t   DCFWINDOWCNT;//!< Digital Compare Filter Window Counter
  uint16_t   rsvd_4;      //!< Reserved
  uint16_t   ETEST;       //!< TEST
  uint16_t   rsvd_5;      //!< Reserved
  uint16_t   HRPWMREV;    //!< HR PWM REV
  uint16_t   EPWMREV;     //!< EPWM REV
} PWM_Obj;
#endif

//! \brief Defines the pulse width modulation (PWM) handle
//!
typedef struct PWM_Obj *PWM_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes

//! \brief     Clears the pulse width modulation (PWM) interrupt flag
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
inline void PWM_clearIntFlag(PWM_Handle pwmHandle)
{
  PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


  // set the bits
  pwm->ETCLR = PWM_ETCLR_INT_BITS;

  return;
} // end of PWM_clearIntFlag() function


//! \brief     Clears the pulse width modulation (PWM) one shot trip
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
inline void PWM_clearOneShotTrip(PWM_Handle pwmHandle)
{
  PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


  //ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  // set the bits
  pwm->TZCLR = PWM_TZCLR_OST_BITS;

  //DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of PWM_clearOneShotTrip() function


//! \brief     Clears the pulse width modulation (PWM) start of conversion (SOC) A flag
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
inline void PWM_clearSocAFlag(PWM_Handle pwmHandle)
{
  PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


  // set the bits
  pwm->ETCLR = PWM_ETCLR_SOCA_BITS;

  return;
} // end of PWM_clearSocAFlag() function


//! \brief     Clears the pulse width modulation (PWM) start of conversion (SOC) B flag
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
inline void PWM_clearSocBFlag(PWM_Handle pwmHandle)
{
  PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


  // set the bits
  pwm->ETCLR = PWM_ETCLR_SOCB_BITS;

  return;
} // end of PWM_clearSocBFlag() function


//! \brief     Disables the pulse width modulation (PWM) chopping
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_disableChopping(PWM_Handle pwmHandle);


//! \brief     Disables the pulse width modulation (PWM) counter loading from the phase register
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_disableCounterLoad(PWM_Handle pwmHandle);


//! \brief     Disables the pulse width modulation (PWM) deadband
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_disableDeadBand(PWM_Handle pwmHandle);


//! \brief     Disables the pulse width modulation (PWM) deadband half cycle clocking
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_disableDeadBandHalfCycle(PWM_Handle pwmHandle);


//! \brief     Disables the pulse width modulation (PWM) interrupt
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_disableInt(PWM_Handle pwmHandle);


//! \brief     Disables the pulse width modulation (PWM) start of conversion (SOC) B pulse generation
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_disableSocAPulse(PWM_Handle pwmHandle);


//! \brief     Disables the pulse width modulation (PWM) start of conversion (SOC) B pulse generation
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_disableSocBPulse(PWM_Handle pwmHandle);


//! \brief     Disables the pulse width modulation (PWM) trip zones
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_disableTripZones(PWM_Handle pwmHandle);


//! \brief     Disable the pulse width modulation (PWM) trip zone source
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] src        The pulse width modulation (PWM) trip zone source
void PWM_disableTripZoneSrc(PWM_Handle pwmHandle,const PWM_TripZoneSrc_e src);


//! \brief     Enables the pulse width modulation (PWM) chopping
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_enableChopping(PWM_Handle pwmHandle);


//! \brief     Enables the pulse width modulation (PWM) counter loading from the phase register
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_enableCounterLoad(PWM_Handle pwmHandle);


//! \brief     Enables the pulse width modulation (PWM) deadband half cycle clocking
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_enableDeadBandHalfCycle(PWM_Handle pwmHandle);


//! \brief     Enables the pulse width modulation (PWM) interrupt
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_enableInt(PWM_Handle pwmHandle);


//! \brief     Enables the pulse width modulation (PWM) start of conversion (SOC) A pulse generation
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_enableSocAPulse(PWM_Handle pwmHandle);


//! \brief     Enables the pulse width modulation (PWM) start of conversion (SOC) B pulse generation
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
void PWM_enableSocBPulse(PWM_Handle pwmHandle);


//! \brief     Enable the pulse width modulation (PWM) trip zone source
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] src        The pulse width modulation (PWM) trip zone source
void PWM_enableTripZoneSrc(PWM_Handle pwmHandle,const PWM_TripZoneSrc_e src);


//! \brief     Gets the value of the Counter Compare A hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The CMPA value
inline uint16_t PWM_get_CmpA(PWM_Handle pwmHandle)
{
  PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

  return pwm->CMPA;
} // end of PWM_get_CmpA() function


//! \brief     Gets the pulse width modulation (PWM) interrupt event count
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The interrupt event count
uint16_t PWM_getIntCount(PWM_Handle pwmHandle);


//! \brief     Gets the pulse width modulation (PWM) start of conversion (SOC) A count
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The SOC A count
uint16_t PWM_getSocACount(PWM_Handle pwmHandle);


//! \brief     Gets the pulse width modulation (PWM) start of conversion (SOC) B count
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The SOC B count
uint16_t PWM_getSocBCount(PWM_Handle pwmHandle);


//! \brief     Gets the value of the timer period
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The TBPRD value
inline uint16_t PWM_get_Tbprd(PWM_Handle pwmHandle)
{
  PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

  return pwm->TBPRD;
} // end of PWM_get_CmpA() function


//! \brief     Initializes the pulse width modulation (PWM) object handle
//! \param[in] pMemory   A pointer to the base address of the PWM registers
//! \param[in] numBytes  The number of bytes allocated for the PWM object, bytes
//! \return    The pulse width modulation (PWM) object handle
PWM_Handle PWM_init(void *pMemory,const size_t numBytes);


//! \brief     Sets the pulse width modulation (PWM) object action for PWM A when the counter equals CMPA and the counter is decrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
void PWM_setActionQual_CntDown_CmpA_PwmA(PWM_Handle pwmHandle,const PWM_ActionQual_e actionQual);


//! \brief     Sets the pulse width modulation (PWM) object action for PWM B when the counter equals CMPA and the counter is decrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
void PWM_setActionQual_CntDown_CmpA_PwmB(PWM_Handle pwmHandle,const PWM_ActionQual_e actionQual);


//! \brief     Sets the pulse width modulation (PWM) object action for PWM A when the counter equals CMPB and the counter is decrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
void PWM_setActionQual_CntDown_CmpB_PwmA(PWM_Handle pwmHandle,const PWM_ActionQual_e actionQual);


//! \brief     Sets the pulse width modulation (PWM) object action for PWM B when the counter equals CMPB and the counter is decrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
void PWM_setActionQual_CntDown_CmpB_PwmB(PWM_Handle pwmHandle,const PWM_ActionQual_e actionQual);


//! \brief     Sets the pulse width modulation (PWM) object action for PWM A when the counter equals CMPA and the counter is incrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
void PWM_setActionQual_CntUp_CmpA_PwmA(PWM_Handle pwmHandle,const PWM_ActionQual_e actionQual);


//! \brief     Sets the pulse width modulation (PWM) object action for PWM B when the counter equals CMPA and the counter is incrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
void PWM_setActionQual_CntUp_CmpA_PwmB(PWM_Handle pwmHandle,const PWM_ActionQual_e actionQual);


//! \brief     Sets the pulse width modulation (PWM) object action for PWM A when the counter equals CMPB and the counter is incrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
void PWM_setActionQual_CntUp_CmpB_PwmA(PWM_Handle pwmHandle,const PWM_ActionQual_e actionQual);


//! \brief     Sets the pulse width modulation (PWM) object action for PWM B when the counter equals CMPB and the counter is incrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
void PWM_setActionQual_CntUp_CmpB_PwmB(PWM_Handle pwmHandle,const PWM_ActionQual_e actionQual);


//! \brief     Sets the pulse width modulation (PWM) object Continuous Software Force action for PWM A
//! \param[in] pwmHandle              The pulse width modulation (PWM) object handle
//! \param[in] actionQualContSWForce  The action qualifier continuous software force
void PWM_setActionQualContSWForce_PwmA(PWM_Handle pwmHandle,const PWM_ActionQualContSWForce_e actionQualContSWForce);


//! \brief     Sets the pulse width modulation (PWM) object Continuous Software Force action for PWM B
//! \param[in] pwmHandle              The pulse width modulation (PWM) object handle
//! \param[in] actionQualContSWForce  The action qualifier continuous software force
void PWM_setActionQualContSWForce_PwmB(PWM_Handle pwmHandle,const PWM_ActionQualContSWForce_e actionQualContSWForce);


//! \brief     Sets the pulse width modulation (PWM) object action for PWM A when the counter equals the period
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
void PWM_setActionQual_Period_PwmA(PWM_Handle pwmHandle,const PWM_ActionQual_e actionQual);


//! \brief     Sets the pulse width modulation (PWM) object action for PWM B when the counter equals the period
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
void PWM_setActionQual_Period_PwmB(PWM_Handle pwmHandle,const PWM_ActionQual_e actionQual);


//! \brief     Sets the pulse width modulation (PWM) object action for PWM A when the counter equals the zero
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
void PWM_setActionQual_Zero_PwmA(PWM_Handle pwmHandle,const PWM_ActionQual_e actionQual);


//! \brief     Sets the pulse width modulation (PWM) object action for PWM B when the counter equals the zero
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
void PWM_setActionQual_Zero_PwmB(PWM_Handle pwmHandle,const PWM_ActionQual_e actionQual);


//! \brief     Sets the pulse width modulation (PWM) chopping clock frequency
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] clkFreq    The clock frequency
void PWM_setChoppingClkFreq(PWM_Handle pwmHandle,const PWM_ChoppingClkFreq_e clkFreq);


//! \brief     Sets the pulse width modulation (PWM) chopping clock duty cycle
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] dutyCycle  The duty cycle
void PWM_setChoppingDutyCycle(PWM_Handle pwmHandle,const PWM_ChoppingDutyCycle_e dutyCycle);


//! \brief     Sets the pulse width modulation (PWM) chopping clock pulse width
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] pulseWidth  The pulse width
void PWM_setChoppingPulseWidth(PWM_Handle pwmHandle,const PWM_ChoppingPulseWidth_e pulseWidth);


//! \brief     Sets the pulse width modulation (PWM) clock divisor
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] clkDiv     The clock divisor
void PWM_setClkDiv(PWM_Handle pwmHandle,const PWM_ClkDiv_e clkDiv);


//! \brief     Sets the pulse width modulation (PWM) count
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] count      The count
void PWM_setCount(PWM_Handle pwmHandle,const uint16_t count);


//! \brief     Sets the pulse width modulation (PWM) counter mode
//! \param[in] pwmHandle    The pulse width modulation (PWM) object handle
//! \param[in] counterMode  The count mode
void PWM_setCounterMode(PWM_Handle pwmHandle,const PWM_CounterMode_e counterMode);


//! \brief     Sets the pulse width modulation (PWM) deadband falling edge delay
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] delay      The delay
void PWM_setDeadBandFallingEdgeDelay(PWM_Handle pwmHandle,const uint8_t delay);


//! \brief     Sets the pulse width modulation (PWM) deadband input mode
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] inputMode  The input mode
void PWM_setDeadBandInputMode(PWM_Handle pwmHandle,const PWM_DeadBandInputMode_e inputMode);


//! \brief     Sets the pulse width modulation (PWM) deadband output mode
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] outputMode  The output mode
void PWM_setDeadBandOutputMode(PWM_Handle pwmHandle,const PWM_DeadBandOutputMode_e outputMode);


//! \brief     Sets the pulse width modulation (PWM) deadband polarity
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] polarity   The polarity
void PWM_setDeadBandPolarity(PWM_Handle pwmHandle,const PWM_DeadBandPolarity_e polarity);


//! \brief     Sets the pulse width modulation (PWM) deadband rising edge delay
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] delay      The delay
void PWM_setDeadBandRisingEdgeDelay(PWM_Handle pwmHandle,const uint8_t delay);


//! \brief     Sets the pulse width modulation (PWM) period
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] period     The period
void PWM_setPeriod(PWM_Handle pwmHandle,const uint16_t period);


//! \brief     Sets the pulse width modulation (PWM) high speed clock divisor
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] clkDiv     The clock divisor
void PWM_setHighSpeedClkDiv(PWM_Handle pwmHandle,const PWM_HspClkDiv_e clkDiv);


//! \brief     Sets the pulse width modulation (PWM) interrupt mode
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] intMode    The interrupt mode
void PWM_setIntMode(PWM_Handle pwmHandle,const PWM_IntMode_e intMode);


//! \brief     Sets the pulse width modulation (PWM) interrupt period
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] intPeriod  The interrupt period
void PWM_setIntPeriod(PWM_Handle pwmHandle,const PWM_IntPeriod_e intPeriod);


//! \brief     Sets the pulse width modulation (PWM) load mode for CMPA
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] loadMode   The load mode
void PWM_setLoadMode_CmpA(PWM_Handle pwmHandle,const PWM_LoadMode_e loadMode);


//! \brief     Sets the pulse width modulation (PWM) load mode for CMPB
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] loadMode   The load mode
void PWM_setLoadMode_CmpB(PWM_Handle pwmHandle,const PWM_LoadMode_e loadMode);


//! \brief     Sets the pulse width modulation (PWM) period load mode
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] periodLoad  The period load mode
void PWM_setPeriodLoad(PWM_Handle pwmHandle,const PWM_PeriodLoad_e periodLoad);


//! \brief     Sets the pulse width modulation (PWM) one shot trip
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
inline void PWM_setOneShotTrip(PWM_Handle pwmHandle)
{
  PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


  //ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  // set the bits
  pwm->TZFRC |= PWM_TZFRC_OST_BITS;

  //DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of PWM_setOneShotTrip() function


//! \brief     Sets the pulse width modulation (PWM) phase
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] phase      The phase
void PWM_setPhase(PWM_Handle pwmHandle,const uint16_t phase);


//! \brief     Sets the pulse width modulation (PWM) phase direction
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] phaseDir   The phase direction
void PWM_setPhaseDir(PWM_Handle pwmHandle,const PWM_PhaseDir_e phaseDir);


//! \brief     Sets the pulse width modulation (PWM) run mode
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] runMode    The run mode
void PWM_setRunMode(PWM_Handle pwmHandle,const PWM_RunMode_e runMode);


//! \brief     Sets the pulse width modulation (PWM) start of conversion (SOC) A interrupt period
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] intPeriod  The interrupt period
void PWM_setSocAPeriod(PWM_Handle pwmHandle,const PWM_SocPeriod_e intPeriod);


//! \brief     Sets the pulse width modulation (PWM) start of conversion (SOC) A interrupt pulse source
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] pulseSrc   The interrupt pulse source
void PWM_setSocAPulseSrc(PWM_Handle pwmHandle,const PWM_SocPulseSrc_e pulseSrc);


//! \brief     Sets the pulse width modulation (PWM) start of conversion (SOC) B interrupt period
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] intPeriod  The interrupt period
void PWM_setSocBPeriod(PWM_Handle pwmHandle,const PWM_SocPeriod_e intPeriod);


//! \brief     Sets the pulse width modulation (PWM) start of conversion (SOC) B interrupt pulse source
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] pulseSrc   The interrupt pulse source
void PWM_setSocBPulseSrc(PWM_Handle pwmHandle,const PWM_SocPulseSrc_e pulseSrc);


//! \brief     Sets the pulse width modulation (PWM) shadow mode for CMPA
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] shadowMode  The shadow mode
void PWM_setShadowMode_CmpA(PWM_Handle pwmHandle,const PWM_ShadowMode_e shadowMode);


//! \brief     Sets the pulse width modulation (PWM) shadow mode for CMPB
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] shadowMode  The shadow mode
void PWM_setShadowMode_CmpB(PWM_Handle pwmHandle,const PWM_ShadowMode_e shadowMode);


//! \brief     Sets the pulse width modulation (PWM) software sync
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
void PWM_setSwSync(PWM_Handle pwmHandle);


//! \brief     Sets the pulse width modulation (PWM) sync mode
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] syncMode   The sync mode
void PWM_setSyncMode(PWM_Handle pwmHandle,const PWM_SyncMode_e syncMode);


//! \brief     Sets the pulse width modulation (PWM) trip zone state for Digital Compare Output A Event 1 (DCAEVT1)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneState  The trip zone state
void PWM_setTripZoneState_DCAEVT1(PWM_Handle pwmHandle,const PWM_TripZoneState_e tripZoneState);


//! \brief     Sets the pulse width modulation (PWM) trip zone state for Digital Compare Output A Event 2 (DCAEVT1)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneState  The trip zone state
void PWM_setTripZoneState_DCAEVT2(PWM_Handle pwmHandle,const PWM_TripZoneState_e tripZoneState);


//! \brief     Sets the pulse width modulation (PWM) trip zone state for Digital Compare Output B Event 1 (DCBEVT1)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneState  The trip zone state
void PWM_setTripZoneState_DCBEVT1(PWM_Handle pwmHandle,const PWM_TripZoneState_e tripZoneState);


//! \brief     Sets the pulse width modulation (PWM) trip zone state for Digital Compare Output B Event 2 (DCBEVT1)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneState  The trip zone state
void PWM_setTripZoneState_DCBEVT2(PWM_Handle pwmHandle,const PWM_TripZoneState_e tripZoneState);


//! \brief     Sets the pulse width modulation (PWM) trip zone state for Output A (TZA)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneState  The trip zone state
void PWM_setTripZoneState_TZA(PWM_Handle pwmHandle,const PWM_TripZoneState_e tripZoneState);


//! \brief     Sets the pulse width modulation (PWM) trip zone state for Output B (TZB)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneState  The trip zone state
void PWM_setTripZoneState_TZB(PWM_Handle pwmHandle,const PWM_TripZoneState_e tripZoneState);


//! \brief     Writes the pulse width modulation (PWM) data value to the Counter Compare A hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] pwmData    The PWM data value
inline void PWM_write_CmpA(PWM_Handle pwmHandle,const int16_t pwmData)
{
  PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

  int16_t value;
  uint16_t period = pwm->TBPRD;
  int32_t tmp;


  /* Compute the compare A (Q0) from the related duty cycle ratio (Q15)*/
  tmp = (int32_t)period * (int32_t)(pwmData);				/* Q15 = Q0*Q15	*/
  value = (int16_t)(tmp>>16) + (int16_t)(period>>1);  /*Q0 = (Q15->Q0)/2 + (Q0/2)*/

  pwm->CMPA = value;

  return;
} // end of PWM_write_CmpA() function


//! \brief     Writes the pulse width modulation (PWM) data value to the Counter Compare B hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] pwmData    The PWM data value
inline void PWM_write_CmpB(PWM_Handle pwmHandle,const int16_t pwmData)
{
  PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

  int16_t value;
  uint16_t period = pwm->TBPRD;
  int32_t tmp;


  /* Compute the compare A (Q0) from the related duty cycle ratio (Q15)*/
  tmp = (int32_t)period * (int32_t)(pwmData);				/* Q15 = Q0*Q15	*/
  value = (int16_t)(tmp>>16) + (int16_t)(period>>1);  /*Q0 = (Q15->Q0)/2 + (Q0/2)*/

  pwm->CMPB = value;

  return;
} // end of PWM_write_CmpB() function


#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif  // end of _PWM_H_ definition

/*lint -restore */
