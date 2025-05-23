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

/** @reqSettings DEFAULT_SPECIFICATION_REVISION=4.1.2 */
/** @tagSettings DEFAULT_ARCHITECTURE=JACINTO5|JACINTO6 */

#include "Pwm.h"
#include "Pwm_Internal.h"
#if defined(USE_DET)
#include "Det.h"
#endif
#include "Mcu.h"
#include "Pwm_Hw_jacinto.h"
#if defined(CFG_JAC6)
#include "isr.h"
#include "irq_jacinto.h"
#include "epwm.h"
#include "epwm_asr.h"
#endif
#include <string.h>

#if (defined(CFG_JAC5) || defined(CFG_JAC5E))
#define PWM_NUM_TIMER_CHANNELS		8
#elif defined(CFG_JAC6)
#define PWM_NUM_TIMER_CHANNELS		16
#endif



typedef uint8 Pwm_Hw_ChannelType;

typedef struct {
    const Pwm_ConfigType (*config)[PWM_ARC_LOG_UNIT_CNT];
    /* Maps the a physical channel id to configured channel index */
    Pwm_ChannelType channelMap[PWM_ARC_HW_UNIT_CNT];
    Pwm_Hw_ChannelType channelToHwChannel[PWM_ARC_LOG_UNIT_CNT];
    boolean Pwm_NotifEnable[PWM_ARC_LOG_UNIT_CNT];
    boolean Pwm_WakUpEnable[PWM_ARC_LOG_UNIT_CNT];
} Pwm_GlobalType;

Pwm_GlobalType Pwm_Global;

const Pwm_ConfigType *PwmConfigPtr = NULL;

#if defined(CFG_JAC6)
static void Pwm_clearIntFlag(Pwm_ChannelType channel);


/* Used to track if interrupts should be enabled or not
 * when Pwm_EnableNotification is called. The reason that sometimes it should not
 * is that the interrupts are generated when the timer hits a certain value and not
 * because of an actual edge. So if the output is set to idle interrupts should not be
 * enabled although notifications are. Stopping the ePWM timer does not work if
 * updates should happen at the end of the period. */
static ePWM_ChannelOutputStateType ePWMchannelOutputStates[EPWM_JACINTO6_NUM_UNITS] = {
        EPWM_FLAT,
        EPWM_FLAT,
        EPWM_FLAT
};

/*lint -save -e923 Cast from unsigned int to pointer is OK when accessing hardware registers. */
static PWM_Handle const ePWMHandles[EPWM_JACINTO6_NUM_UNITS] = {
        (PWM_Handle) PWMSS1_EPWM_BASE_ADDRESS,
        (PWM_Handle) PWMSS2_EPWM_BASE_ADDRESS,
        (PWM_Handle) PWMSS3_EPWM_BASE_ADDRESS
};

/*lint -esym(9003, PWMSSRegs) OK to keep as file global variable. */
static PWMSS_CFG_Regs* const PWMSSRegs[EPWM_JACINTO6_NUM_UNITS] = {
    (PWMSS_CFG_Regs*) PWMSS1_CFG_BASE_ADDRESS,
    (PWMSS_CFG_Regs*) PWMSS2_CFG_BASE_ADDRESS,
    (PWMSS_CFG_Regs*) PWMSS3_CFG_BASE_ADDRESS
};
/*lint -restore -e923 */

static void setupEpwmClocks(uint8 i) {

    PWMSS_CFG_Regs *cfgRegs = PWMSSRegs[i];

    cfgRegs->PWMSS_SYSCONFIG = PWMSS_SYSCONFIG_SOFTRESET;

    /* Busy wait until the software reset has finished. */
    while ((cfgRegs->PWMSS_SYSCONFIG & PWMSS_SYSCONFIG_SOFTRESET) == PWMSS_SYSCONFIG_SOFTRESET) {}

    cfgRegs->PWMSS_SYSCONFIG |= PWMSS_SYSCONFIG_IDLEMODE_SMART << PWMSS_SYSCONFIG_IDLEMODE_SHIFT;

    /* Turn off eCAP and eQEP. All are on after reset
     * so no need to turn on ePWM. */
    cfgRegs->PWMSS_CLKCONFIG |= PWMSS_CLKCONFIG_ECAP_CLKSTOP_REQ | PWMSS_CLKCONFIG_EQEP_CLKSTOP_REQ;
}

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
Pwm_EdgeNotificationType ePWMnotificationTypes[EPWM_JACINTO6_NUM_UNITS] = {
        PWM_FALLING_EDGE,
        PWM_FALLING_EDGE,
        PWM_FALLING_EDGE
};

void Pwm_Hw_Isr(Pwm_ChannelType channel) {

    Pwm_ChannelType confChannel = Pwm_Global.channelMap[channel + PWM_NUM_TIMER_CHANNELS];

    if (ePWMnotificationTypes[channel] == PWM_BOTH_EDGES) {
        ePwm_ToggleEdgeDetection(ePWMHandles[channel]);
    }

    if (Pwm_Global.Pwm_NotifEnable[confChannel] == TRUE) {
        if (PwmConfigPtr->NotificationHandlers[confChannel] != NULL) {
            /** @req:JACINTO6 SWS_Pwm_00105 - The naming convention
             * is not used but the functionality is supported. */
            PwmConfigPtr->NotificationHandlers[confChannel]();
        }
    }

    /** @req:JACINTO6 SWS_Pwm_00026 */
    /** @req:JACINTO6 SWS_Pwm_30115 - Also reset during initialization but still consider
     * the requirement to be supported. */
    ePwm_ClearInterrupts(ePWMHandles[channel]);
}


#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */
#endif /* defined(CFG_JAC6) */

static Std_ReturnType calcPeriodTicksAndPrescaler(const Pwm_ChannelConfigurationType* channelConfig,
        Pwm_PeriodType* ticks,
        uint32* divisor) {

    Std_ReturnType ret = E_OK;
    uint64 moduleClockFreq = (uint64) Mcu_Arc_GetPeripheralClock(PERIPHERAL_CLOCK_TIMER_PWM);
    uint64 requestedFreq = (uint64) channelConfig->frequency;
    uint32 prescalerShift = (uint32) PWM_CHANNEL_DIVISOR_NONE;
    uint64 prescaler = 1;
    uint64 ticksTemp = 0xffffffffu;

    if (channelConfig->divisor == PWM_CHANNEL_DIVISOR_AUTO) {

        for (prescalerShift = ((uint32) PWM_CHANNEL_DIVISOR_NONE);
                prescalerShift <= ((uint32) PWM_CHANNEL_DIVISOR_256); prescalerShift++) {

            prescaler = ((uint64) 1u) << ((uint64) prescalerShift);
            ticksTemp = moduleClockFreq / (requestedFreq * prescaler);

            if (ticksTemp > 0xffffffffu) {

                ticksTemp = 0xffffffffu;

                if (prescalerShift == ((uint32) PWM_CHANNEL_DIVISOR_256)) {
                    ret = E_NOT_OK;
                }

            } else {
                /* A prescaler setting that achieves the requested frequency was found. */
                break;
            }
        }
    } else {

        prescalerShift = (uint32) channelConfig->divisor;
        prescaler = ((uint64) 1u) << ((uint64) prescalerShift);

        ticksTemp = moduleClockFreq / (requestedFreq * prescaler);

        if (ticksTemp > 0xffffffffu) {
            /* The configured prescaler is to low to achieve the requested frequency. */
            ticksTemp = 0xffffffffu;
            ret = E_NOT_OK;
        }
    }

    *ticks = (Pwm_PeriodType) ticksTemp;
    *divisor = prescalerShift;

    return ret;
}

/**
 * Change period and duty cycle for a channel.
 * @param Channel
 * @param Period in ticks
 * @param DutyCycle 0 <= DutyCycle <= 0x8000
 */
static void changePeriodAndDuty(Pwm_ChannelType channel, Pwm_PeriodType periodTicks, uint16 dutyCycle, Pwm_OutputStateType polarity)
{
    timBASE_t* timRegs = g_timBase[channel];
    uint16  tempDutyCycle = dutyCycle;

    /* The counter is up counting and the starting value controls the PWM period*/
    timRegs->TLDR = 0xffffffffu - periodTicks;
    if (tempDutyCycle > PWM_100_PERCENT) {
        tempDutyCycle = PWM_100_PERCENT;
#if PWM_DEV_ERROR_DETECT==STD_ON	/*lint !e553  STANDARD DEV SELECT*/
        (void)Det_ReportError(PWM_MODULE_ID,0,PWM_GLOBAL_SERVICE_ID, PWM_E_EXECUTION_ERROR);
#endif
    }

    uint32_t reg = timRegs->TCLR;
    /** @req SWS_PWM_00018 */ /*timer is stopped and pwm output state is obtained from configuration parameter PwmPolarity*/
    /** @req:JACINTO5 SWS_PWM_00020 */ /*timer is stopped and pwm output state is obtained from configuration parameter PwmPolarity*/
    /* Not set to supported for Jacinto 6 since it is not actively done for ePWM. */
    if(polarity == PWM_HIGH){
        reg = (reg & ~TCLR_SCPWM_MASK) | TCLR_SCPWM_POS_POLARITY;
    }
    else{
        reg = (reg & ~TCLR_SCPWM_MASK) | TCLR_SCPWM_NEG_POLARITY;
    }
    /** @req SWS_PWM_00014 */
    if (tempDutyCycle == PWM_0_PERCENT){
        timRegs->TMAR = timRegs->TLDR;
        reg = reg & ~TCLR_TRG_MASK; /* Turn off PWM triggering */
        timRegs->TCLR = reg;
        return;
    }
    else if(tempDutyCycle == PWM_100_PERCENT){
        timRegs->TMAR = 0xFFFFFFFFuL;

        reg = reg & ~TCLR_TRG_MASK; /* Turn off PWM triggering */

        /* Switch polarity */
        if(polarity == PWM_HIGH){
            reg = (reg & ~TCLR_SCPWM_MASK) | TCLR_SCPWM_NEG_POLARITY;
        }
        else{
            reg = (reg & ~TCLR_SCPWM_MASK) | TCLR_SCPWM_POS_POLARITY;
        }


        timRegs->TCLR = reg;
    }
    else{
        /** @req SWS_PWM_10009 */
        /** @req SWS_PWM_20009 */
        /** @req SWS_PWM_30009 */
        /** @req SWS_PWM_00059 */
        /* The match register controls the duty cycle */
        timRegs->TMAR = timRegs->TLDR + (uint32)(((uint64)periodTicks * (uint64)tempDutyCycle) >> 15u);
        reg = (reg & ~TCLR_TRG_MASK) | TCLR_TRG_OVRFLW_AND_MATCH; /* Trigger PWM on both match and overflow */
        timRegs->TCLR = reg;
    }
}

/** @req:JACINTO6 SWS_Pwm_00052 */
Std_ReturnType Pwm_Hw_Init(const Pwm_ConfigType* ConfigPtr) {
    uint32 divisor;
    Pwm_PeriodType periodTicks = 0u;    /* Period value in ticks from configuration. */

    PwmConfigPtr = ConfigPtr;

    memset(Pwm_Global.channelMap,0xff, sizeof(Pwm_Global.channelMap) );
    memset(Pwm_Global.channelToHwChannel,0xff, sizeof(Pwm_Global.channelToHwChannel) );

    uint8 hwCh;
	for (uint8 ch = 0; ch < PWM_ARC_LOG_UNIT_CNT; ch++) {
		hwCh = PwmConfigPtr->Channels[ch].channel;
		Pwm_Global.channelToHwChannel[ch] = hwCh;
		Pwm_Global.channelMap[hwCh] = ch;
		Pwm_Global.Pwm_NotifEnable[ch] = FALSE;
	}

    for (Pwm_ChannelType channelIterator = 0; channelIterator < PWM_NUMBER_OF_CHANNELS; channelIterator++) {

        const Pwm_ChannelConfigurationType* channelConfig = &PwmConfigPtr->Channels[channelIterator];

        if (channelConfig->channel < PWM_NUM_TIMER_CHANNELS) {

            timBASE_t* timRegs = g_timBase[channelConfig->channel];

            if (calcPeriodTicksAndPrescaler(channelConfig, &periodTicks, &divisor) == E_OK) {

                /* Perform a soft reset of the timer module */
                timRegs->TIOCP_CFG = TIOCP_CFG_SOFTRESET_BITMASK;
                while ((timRegs->TIOCP_CFG & TIOCP_CFG_SOFTRESET_BITMASK) != 0U){}

                timRegs->TIOCP_CFG = TIM_FORCE_IDLE_MODE;
                timRegs->TSICR = TIM_REG_RNP_WNP;

                changePeriodAndDuty(channelConfig->channel, periodTicks, channelConfig->duty, channelConfig->polarity);

                /* Get the first pulse the right length */
                timRegs->TCRR = 0xffffffffu - periodTicks;

                /* Use timer for PWM and auto reload counter */
                uint32 reg = TCLR_PT_TOGGLE | TCLR_TRG_OVRFLW_AND_MATCH | TCLR_CE_ENABLE | TCLR_AR_AUTO_RELOAD;

                if(channelConfig->polarity == PWM_HIGH){
                    reg |= TCLR_SCPWM_POS_POLARITY;
                }
                else{
                    reg |= TCLR_SCPWM_NEG_POLARITY;
                }

                if (divisor > ((uint32) PWM_CHANNEL_DIVISOR_NONE)) {
                    reg |= TCLR_PRE_ENABLE;
                    reg &= ~TCLR_MASK_PTV;
                    /* If 0 is stored in the prescaler register it is divided by 2, if 1 then by 4 etc. */
                    reg |= ((uint32) (divisor - 1)) << TCLR_PTV_BIT_POS;
                }

                reg |= TCLR_ST_START_TIMER;

                timRegs->TCLR = reg;
            } else {
                return E_NOT_OK;
            }
        }
#if defined(CFG_JAC6)
        else {

            /* ePWM channels */

            uint32 prescaler = 1;
            uint8 epwmChannel = channelConfig->channel - PWM_NUM_TIMER_CHANNELS;

            if (epwmChannel >= EPWM_JACINTO6_NUM_UNITS) {
                return E_NOT_OK;
            }

            if (channelConfig->divisor == PWM_CHANNEL_DIVISOR_AUTO) {
                if (ePWM_FindFittingPrescaler(Mcu_Arc_GetPeripheralClock(PERIPHERAL_CLOCK_EPWM),
                        channelConfig->frequency, &prescaler) != E_OK) {

                    return E_NOT_OK;
                }
            } else {
                prescaler = (1uL << ((uint32) channelConfig->divisor));
            }

            setupEpwmClocks(epwmChannel);

            if (ePWM_InitChannel(
                    ePWMHandles[epwmChannel],
                    Mcu_Arc_GetPeripheralClock(PERIPHERAL_CLOCK_EPWM),
                    prescaler,
                    channelConfig->frequency,
                    channelConfig->duty,
                    channelConfig->polarity) != E_OK) {

                return E_NOT_OK;
            }

            if ((channelConfig->duty == 0) || (channelConfig->duty >= 0x8000)) {
                ePWMchannelOutputStates[epwmChannel] = EPWM_FLAT;
            } else {
                ePWMchannelOutputStates[epwmChannel] = EPWM_MODULATING;
            }
        }
#endif /* defined(CFG_JAC6) */
    }

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
#if defined(CFG_JAC6)
    ISR_INSTALL_ISR2("ePWM1", Pwm1_Isr, (IrqType)(PWMSS1_ePWM0INT_IRQ), PWM_ISR_PRIORITY, PWM_ISR_APP);
    ISR_INSTALL_ISR2("ePWM2", Pwm2_Isr, (IrqType)(PWMSS2_ePWM1INT_IRQ), PWM_ISR_PRIORITY, PWM_ISR_APP);
    ISR_INSTALL_ISR2("ePWM3", Pwm3_Isr, (IrqType)(PWMSS3_ePWM2INT_IRQ), PWM_ISR_PRIORITY, PWM_ISR_APP);
#endif /* defined(CFG_JAC6) */
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */

    return E_OK;
}



#if (PWM_DE_INIT_API==STD_ON)
/** @req SWS_Pwm_00010 Does not deinitialize the hardware but the module is effectively deinitialized
 * (according to the idle states of the channels). */
/** @req:JACINTO6 SWS_Pwm_00012 */
void Pwm_Hw_Deinit( void ) {

    Pwm_ChannelType channelIterator;
    for (channelIterator = 0; channelIterator < PWM_NUMBER_OF_CHANNELS; channelIterator++) {

        const Pwm_ChannelConfigurationType* channelConfig = &PwmConfigPtr->Channels[channelIterator];

#if (PWM_NOTIFICATION_SUPPORTED==STD_ON)
        Pwm_Hw_DisableNotification(channelConfig->channel);
#endif
        Pwm_Hw_setOutputState(channelConfig->channel, channelConfig->idleState);

#if defined(CFG_JAC6)
        if (channelConfig->channel >= PWM_NUM_TIMER_CHANNELS) {

            ePWMchannelOutputStates[channelConfig->channel - PWM_NUM_TIMER_CHANNELS] = EPWM_FLAT;
        }
#endif /* defined(CFG_JAC6) */
    }

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
	for (uint8 channelIterator = 0; channelIterator < PWM_ARC_LOG_UNIT_CNT; channelIterator++) {
		Pwm_Global.Pwm_NotifEnable[channelIterator] = FALSE;
	}
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */
}
#endif /* (PWM_DE_INIT_API==STD_ON) */

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
void Pwm_Hw_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle) {

    /** @req SWS_Pwm_00013 */
    /** @req SWS_Pwm_00019 */
    /** @req SWS_Pwm_10086  */
    /* This function does not change the prescaler so the ticks are counted with the prescaler from the
     * initial setup.
     * */
	Pwm_ChannelType logCh = Pwm_Global.channelMap[ChannelNumber];
	Pwm_OutputStateType Polarity = PwmConfigPtr->Channels[logCh].polarity;

    if (ChannelNumber < PWM_NUM_TIMER_CHANNELS) {
        timBASE_t* timRegs = g_timBase[ChannelNumber];
        timRegs->TCLR = timRegs->TCLR & ~TCLR_ST_START_TIMER_MASK; /* Stop timer */
        /** @req SWS_Pwm_00016 */
        changePeriodAndDuty(ChannelNumber, Period, DutyCycle, Polarity);
        timRegs->TCLR = timRegs->TCLR | TCLR_ST_START_TIMER;
    }
#if defined(CFG_JAC6)
    else {
        uint8 epwmChannel = ChannelNumber - PWM_NUM_TIMER_CHANNELS;

        if (ePWM_SetPeriodAndDuty(ePWMHandles[epwmChannel], Period, DutyCycle, Polarity,
                Pwm_Global.Pwm_NotifEnable[Pwm_Global.channelMap[ChannelNumber]]) == E_OK) {

            if ((DutyCycle == 0) || (DutyCycle >= 0x8000) || (Period == 0)) {
                ePWMchannelOutputStates[epwmChannel] = EPWM_FLAT;
            } else {
                ePWMchannelOutputStates[epwmChannel] = EPWM_MODULATING;
            }
        } else {
            /* The period was to big to fit in the register, ignore request. */
        }
    }
#endif /* defined(CFG_JAC6) */
}
#endif

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
void Pwm_Hw_setDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle) {

	Pwm_ChannelType logCh = Pwm_Global.channelMap[ChannelNumber];
	Pwm_OutputStateType Polarity = PwmConfigPtr->Channels[logCh].polarity;

    if (ChannelNumber < PWM_NUM_TIMER_CHANNELS) {
        timBASE_t* timRegs = g_timBase[ChannelNumber];
        /* Get period value in ticks */
        Pwm_PeriodType periodTicks = 0xffffffffu - timRegs->TLDR;
        /* Stop timer */
        timRegs->TCLR = timRegs->TCLR & ~TCLR_ST_START_TIMER_MASK;
        changePeriodAndDuty(ChannelNumber, periodTicks, DutyCycle, Polarity);
        timRegs->TCLR = timRegs->TCLR | TCLR_ST_START_TIMER;
    }
#if defined(CFG_JAC6)
    else {
        uint8 epwmChannel = ChannelNumber - PWM_NUM_TIMER_CHANNELS;

        ePWM_SetDutyCycle(ePWMHandles[epwmChannel], DutyCycle, Polarity,
                Pwm_Global.Pwm_NotifEnable[Pwm_Global.channelMap[ChannelNumber]]);

        /* If the period previously has been set to 0 then the duty cycle will be set to 0
         * even if it is not. */
        if ((DutyCycle == 0) || (DutyCycle >= 0x8000) || (ePWM_GetPeriod(ePWMHandles[epwmChannel]) == 0)) {
            ePWMchannelOutputStates[epwmChannel] = EPWM_FLAT;
        } else {
            ePWMchannelOutputStates[epwmChannel] = EPWM_MODULATING;
        }
    }
#endif /* defined(CFG_JAC6) */
}
#endif

void Pwm_Hw_setOutputState(Pwm_ChannelType ChannelNumber, Pwm_OutputStateType IdleState) {

    /** @req SWS_Pwm_00021 */
    /** @req SWS_Pwm_20086 */
    /** @req SWS_Pwm_00119 */

    if (ChannelNumber < PWM_NUM_TIMER_CHANNELS) {
        timBASE_t* timRegs = g_timBase[ChannelNumber];
        uint32 reg = timRegs->TCLR & ~TCLR_ST_START_TIMER_MASK;
        timRegs->TCLR = reg;

        if (IdleState == PWM_HIGH) {
            /* idle state high == neg polarity (for 0% duty) */
            Pwm_Hw_setDutyCycle(ChannelNumber, 0);
        }
        else{
            Pwm_Hw_setDutyCycle(ChannelNumber, 0);
        }
    }
#if defined(CFG_JAC6)
    else {
        uint8 epwmChannel = ChannelNumber - PWM_NUM_TIMER_CHANNELS;

        ePWM_SetChannelToIdle(ePWMHandles[epwmChannel], IdleState);

        ePWMchannelOutputStates[epwmChannel] = EPWM_FLAT;
    }
#endif /* defined(CFG_JAC6) */
}


#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
Pwm_OutputStateType Pwm_Hw_GetOutputState(Pwm_ChannelType ChannelNumber) {
    /* Not Supported */
    (void) ChannelNumber;
    return PWM_LOW;
}
#endif

#if (PWM_NOTIFICATION_SUPPORTED==STD_ON)
#if defined(CFG_JAC6)
/** @req:JACINTO6 SWS_Pwm_00023 */
void Pwm_Hw_DisableNotification(Pwm_ChannelType ChannelNumber) {

//    if (ChannelNumber < PWM_NUM_TIMER_CHANNELS) {
//        return;
//    }

    Pwm_ChannelType logCh = Pwm_Global.channelMap[ChannelNumber];
    Pwm_Global.Pwm_NotifEnable[logCh] = FALSE;

    uint8 epwmChannel = ChannelNumber - PWM_NUM_TIMER_CHANNELS;

    EPWM_DISABLE_INTERRUPTS(ePWMHandles[epwmChannel]);
}

/** @req:JACINTO6 SWS_Pwm_00081 */
/** @req:JACINTO6 SWS_Pwm_00024 */
/** @req:JACINTO6 SWS_Pwm_00025 */
void Pwm_Hw_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification) {
	/** @req 4.1.2|4.3.0/SWS_PWM_00081 Pwm_EnableNotification shall cancel pending interrupts. */
	Pwm_clearIntFlag(ChannelNumber);

    /* Only supporting notifications for ePWM. */
    if (ChannelNumber < PWM_NUM_TIMER_CHANNELS) {
        return;
    }

    uint8 epwmChannel = ChannelNumber - PWM_NUM_TIMER_CHANNELS;

    EPWM_DISABLE_INTERRUPTS(ePWMHandles[epwmChannel]);

    ePWMnotificationTypes[epwmChannel] = Notification;

    Pwm_ChannelType logCh = Pwm_Global.channelMap[ChannelNumber];

    ePWM_EnableNotification(ePWMHandles[epwmChannel], Notification, PwmConfigPtr->Channels[logCh].polarity,
            ePWMchannelOutputStates[epwmChannel]);

    Pwm_Global.Pwm_NotifEnable[logCh] = TRUE;
}
#endif /* defined(CFG_JAC6) */
#endif /* (PWM_NOTIFICATION_SUPPORTED==STD_ON) */


/* @brief  		Function to set period and duty
 * @param[in] 	ChannelNumber 	Channel number
 * @return		PWM_VARIABLE_PERIOD			Variable period. The duty cycle and the period can be changed.
 * @return		PWM_FIXED_PERIOD			Fixed period. Only the duty cycle can be changed.
 * @return		PWM_FIXED_PERIOD_SHIFTED	Fixed shifted period. Impossible to change it.
 ******************************************************************************/
Pwm_ChannelClassType Pwm_Hw_getChannelClass(Pwm_ChannelType ChannelNumber){
	Pwm_ChannelType logCh = Pwm_Global.channelMap[ChannelNumber];
	return PwmConfigPtr->Channels[logCh].class;
}

/* @brief  		Function read back the configured idle state for specific channel.
 * @param[in] 	ChannelNumber 	Channel number.
 * @return		configured idle state
 * @retval		PWM_LOW			low state.
 * @retval		PWM_HIGH		high state.
 ******************************************************************************/
Pwm_OutputStateType Pwm_Hw_getConfiguredIdleState(Pwm_ChannelType Channel){
	Pwm_ChannelType logCh = Pwm_Global.channelMap[Channel];
	return PwmConfigPtr->Channels[logCh].idleState;
}

/* @brief  	Test to see if a channel is configured
 * @note     	Reentrant
 * @param[in] 	Channel 		channel number
 ******************************************************************************/
boolean Pwm_Hw_isChannelConfigured( Pwm_ChannelType channel ){
	return ((channel <= PWM_ARC_HW_UNIT_HIGH) && (Pwm_Global.channelMap[channel] < PWM_ARC_LOG_UNIT_CNT));
}

#if defined(CFG_JAC6)
/* @brief  Disables the pulse width modulation (PWM) interrupt
 * @note                reentrant
 * @param[in] 			channel  	number of channel to initialize
 ******************************************************************************/
void Pwm_Hw_disableInt(Pwm_ChannelType channel)
{
	uint8 epwmChannel = channel - PWM_NUM_TIMER_CHANNELS;

	EPWM_DISABLE_INTERRUPTS(ePWMHandles[epwmChannel]);

	Pwm_ChannelType logCh = Pwm_Global.channelMap[channel];
}

/***************************************************************************//**
 * @brief  Clears the pulse width modulation (PWM) interrupt flag
 * @note    	reentrant
 * @param[in] 	channel    Number of hardware PWM channel
 ******************************************************************************/
void Pwm_clearIntFlag(Pwm_ChannelType channel)
{
	uint8 epwmChannel = channel - PWM_NUM_TIMER_CHANNELS;

    PWM_Obj *pwm = (PWM_Obj *)ePWMHandles[epwmChannel];

    // set the bits
    pwm->ETCLR = PWM_ETCLR_INT_BITS;
}

#endif
