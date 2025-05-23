/**
 * \file IfxPort.h
 * \brief PORT  basic functionality
 * \ingroup IfxLld_Port
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
 *
 * \defgroup IfxLld_Port_Std_Enum Enumerations
 * \ingroup IfxLld_Port_Std
 * \defgroup IfxLld_Port_Std_DataStructures Data structures
 * \ingroup IfxLld_Port_Std
 * \defgroup IfxLld_Port_Std_SinglePin Single Pin Functions
 * \ingroup IfxLld_Port_Std
 * \defgroup IfxLld_Port_Std_PortGroup Group Access Functions
 * \ingroup IfxLld_Port_Std
 */

#ifndef IFXPORT_H
#define IFXPORT_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxPort_cfg.h"
#include "Scu/Std/IfxScuWdt.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Port_Std_Enum
 * \{ */
/** \brief The LVDS RX_DIS control function can be selected from the Port (default) or
 * HSCT module.declared in MODULE_PORTx.LPCRx
 */
typedef enum
{
    IfxPort_ControlledBy_port = 0,  /**< \brief port controlled by PORT Module */
    IfxPort_ControlledBy_hsct = 1   /**< \brief Port controlled by HSCT Module */
} IfxPort_ControlledBy;

/** \brief Ifx_P output modification modes definition.
 */
typedef enum
{
    IfxPort_InputMode_undefined    = -1,
    IfxPort_InputMode_noPullDevice = 0 << 3,
        IfxPort_InputMode_pullDown = 1U << 3,
        IfxPort_InputMode_pullUp   = 2U << 3  /**< \brief  */
} IfxPort_InputMode;

/** \brief specifies LVDS-M or LVDS-H mode as declare in Register MODULE_PORT.LPCRx.LVDSM
 */
typedef enum
{
    IfxPort_LvdsMode_high   = 0, /**< \brief LVDS-H Mode */
    IfxPort_LvdsMode_medium = 1  /**< \brief LVDS-M Mode */
} IfxPort_LvdsMode;

/** \brief Ifx_P input / output mode definition.
 *
 * \see Ifx_P.IOCR, IfxPort_setPinMode()
 */
typedef enum
{
    IfxPort_Mode_inputNoPullDevice      = 0,      /**< \brief Input, No pull device connected. */
    IfxPort_Mode_inputPullDown          = 8U,     /**< \brief Input, pull-down device connected. */
    IfxPort_Mode_inputPullUp            = 0x10U,  /**< \brief Input, pull-up device connected. */
    IfxPort_Mode_outputPushPullGeneral  = 0x80U,  /**< \brief Push-pull, General-purpose output */
    IfxPort_Mode_outputPushPullAlt1     = 0x88U,  /**< \brief Push-pull, Alternate output function 1. */
    IfxPort_Mode_outputPushPullAlt2     = 0x90U,  /**< \brief Push-pull, Alternate output function 2. */
    IfxPort_Mode_outputPushPullAlt3     = 0x98U,  /**< \brief Push-pull, Alternate output function 3. */
    IfxPort_Mode_outputPushPullAlt4     = 0xA0U,  /**< \brief Push-pull, Alternate output function 4. */
    IfxPort_Mode_outputPushPullAlt5     = 0xA8U,  /**< \brief Push-pull, Alternate output function 5. */
    IfxPort_Mode_outputPushPullAlt6     = 0xB0U,  /**< \brief Push-pull, Alternate output function 6. */
    IfxPort_Mode_outputPushPullAlt7     = 0xB8U,  /**< \brief Push-pull, Alternate output function 7. */
    IfxPort_Mode_outputOpenDrainGeneral = 0xC0U,  /**< \brief Open-drain, General-purpose output. */
    IfxPort_Mode_outputOpenDrainAlt1    = 0xC8U,  /**< \brief Open-drain, Alternate output function 1. */
    IfxPort_Mode_outputOpenDrainAlt2    = 0xD0U,  /**< \brief Open-drain, Alternate output function 2. */
    IfxPort_Mode_outputOpenDrainAlt3    = 0xD8U,  /**< \brief Open-drain, Alternate output function 3. */
    IfxPort_Mode_outputOpenDrainAlt4    = 0xE0U,  /**< \brief Open-drain, Alternate output function 4. */
    IfxPort_Mode_outputOpenDrainAlt5    = 0xE8U,  /**< \brief Open-drain, Alternate output function 5. */
    IfxPort_Mode_outputOpenDrainAlt6    = 0xF0U,  /**< \brief Open-drain, Alternate output function 6. */
    IfxPort_Mode_outputOpenDrainAlt7    = 0xF8U   /**< \brief Open-drain, Alternate output function 7. */
} IfxPort_Mode;

/** \brief Pin output alternate index
 */
typedef enum
{
    IfxPort_OutputIdx_general  = 0x10U << 3,
        IfxPort_OutputIdx_alt1 = 0x11U << 3,
        IfxPort_OutputIdx_alt2 = 0x12U << 3,
        IfxPort_OutputIdx_alt3 = 0x13U << 3,
        IfxPort_OutputIdx_alt4 = 0x14U << 3,
        IfxPort_OutputIdx_alt5 = 0x15U << 3,
        IfxPort_OutputIdx_alt6 = 0x16U << 3,
        IfxPort_OutputIdx_alt7 = 0x17U << 3
} IfxPort_OutputIdx;

/** \brief Pin output mode definition
 */
typedef enum
{
    IfxPort_OutputMode_pushPull      = 0x10U << 3,
        IfxPort_OutputMode_openDrain = 0x18U << 3
} IfxPort_OutputMode;

/** \brief Pad driver mode definition (strength and slew rate).
 *
 * \see Ifx_P.PDR, IfxPort_setPinPadDriver()
 */
typedef enum
{
    IfxPort_PadDriver_cmosAutomotiveSpeed1 = 0,  /**< \brief Speed grade 1. */
    IfxPort_PadDriver_cmosAutomotiveSpeed2 = 1,  /**< \brief Speed grade 2. */
    IfxPort_PadDriver_cmosAutomotiveSpeed3 = 2,  /**< \brief Speed grade 3. */
    IfxPort_PadDriver_ttlSpeed1            = 8,  /**< \brief Speed grade 1. */
    IfxPort_PadDriver_ttlSpeed2            = 9,  /**< \brief Speed grade 2. */
    IfxPort_PadDriver_ttlSpeed3            = 10, /**< \brief Speed grade 3. */
    IfxPort_PadDriver_ttl3v3Speed1         = 12, /**< \brief 3.3v Pad supply speed1 */
    IfxPort_PadDriver_ttl3v3Speed2         = 13, /**< \brief 3.3v Pad supply speed2 */
    IfxPort_PadDriver_ttl3v3Speed3         = 14  /**< \brief 3.3v Pad supply speed3 */
} IfxPort_PadDriver;

/** \brief MODULE_PORTx.LPCRx.B.PS1.Selects between 5v and 3.3v on Vext supply for the LVDSM pair
 */
typedef enum
{
    IfxPort_PadSupply_3v = 0,  /**< \brief select,3.3v */
    IfxPort_PadSupply_5v = 1   /**< \brief select,5V */
} IfxPort_PadSupply;

/** \brief enable analog/digital mode for port pin, as Defined in MODULE_PORTx.PDISC
 */
typedef enum
{
    IfxPort_PinFunctionMode_digital = 0,  /**< \brief Pad Pn.x is enabled and can be selected for digital function */
    IfxPort_PinFunctionMode_analog  = 1   /**< \brief Pad Pn.x is enabled and can be selected for analog function */
} IfxPort_PinFunctionMode;

/** \brief Ifx_P output modification modes definition.
 *
 * \see Ifx_P.OMR, IfxPort_setPinState()
 */
typedef enum
{
    IfxPort_State_notChanged = (0 << 16) | (0 << 0),  /**< \brief Ifx_P pin is left unchanged. */
    IfxPort_State_high       = (0 << 16) | (1U << 0), /**< \brief Ifx_P pin is set to high. */
    IfxPort_State_low        = (1U << 16) | (0 << 0), /**< \brief Ifx_P pin is set to low. */
    IfxPort_State_toggled    = (1U << 16) | (1U << 0) /**< \brief Ifx_P pin is toggled. */
} IfxPort_State;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Port_Std_DataStructures
 * \{ */
/** \brief To Configure LVDS mode
 */
typedef struct
{
    IfxPort_LvdsMode     lvdsMode;                   /**< \brief specifies LVDS-M or LVDS-H mode */
    IfxPort_ControlledBy enablePortControlled;       /**< \brief specifies whether LVDS is controlled by PORT or HSCT */
    IfxPort_PadSupply    padSupply;                  /**< \brief specify supply voltage */
} IfxPort_LvdsConfig;

/** \brief Defines a pin
 */
typedef struct
{
    Ifx_P *port;
    uint8  pinIndex;
} IfxPort_Pin;

/** \brief To configure pins
 */
typedef struct
{
    Ifx_P            *port;
    uint8             pinIndex;
    IfxPort_OutputIdx mode;
    IfxPort_PadDriver padDriver;
} IfxPort_Pin_Config;

/** \} */

/** \addtogroup IfxLld_Port_Std_SinglePin
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Return the port state.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin for which the state should be returned.
 * \return Returns TRUE the pin is high; FALSE the pin is low
 *
 * Coding example:
 * \code
 *    if( IfxPort_getPinState(&MODULE_P33, 0) ) {
 *      // ...
 *    }
 * \endcode
 *
 */
IFX_INLINE boolean IfxPort_getPinState(Ifx_P *port, uint8 pinIndex);

/** \brief Set the port output.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to be set.
 * \return None
 *
 * Coding example:
 * \code
 * IfxPort_setPinHigh(&MODULE_P33, 0);
 * \endcode
 *
 * \see IfxPort_setPinState(), IfxPort_setPinLow(), IfxPort_togglePin()
 *
 */
IFX_INLINE void IfxPort_setPinHigh(Ifx_P *port, uint8 pinIndex);

/** \brief Reset the port output.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to be reset.
 * \return None
 *
 * Coding example:
 * \code
 * IfxPort_setPinLow(&MODULE_P33, 0);
 * \endcode
 *
 * \see IfxPort_setPinState(), IfxPort_setPinHigh(), IfxPort_togglePin()
 *
 */
IFX_INLINE void IfxPort_setPinLow(Ifx_P *port, uint8 pinIndex);

/** \brief Configure the port input / output mode.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to be configured.
 * \param mode Specifies the port pin mode.
 * \return None
 *
 * Coding example:
 * \code
 *     IfxPort_setPinModeInput(&MODULE_P33, 0, IfxPort_InputMode_pullUp);
 * \endcode
 *
 */
IFX_INLINE void IfxPort_setPinModeInput(Ifx_P *port, uint8 pinIndex, IfxPort_InputMode mode);

/** \brief Configure the port input / output mode.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to be configured.
 * \param mode Specifies the port pin mode.
 * \param index Specifies the alternate (or general purpose) output channel.
 * \return None
 *
 * Coding example:
 * \code
 *     IfxPort_setPinModeOutput(&MODULE_P33, 0, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
 * \endcode
 *
 */
IFX_INLINE void IfxPort_setPinModeOutput(Ifx_P *port, uint8 pinIndex, IfxPort_OutputMode mode, IfxPort_OutputIdx index);

/** \brief Set / Resets / Toggle the port output.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to modify.
 * \param action Specifies the action: set, reset, toggle.
 * \return None
 *
 * Coding example:
 * \code
 * IfxPort_setPinState(&MODULE_P33, 0, IfxPort_State_toggled);
 * IfxPort_setPinState(&MODULE_P33, 0, IfxPort_State_toggled);
 * IfxPort_setPinState(&MODULE_P33, 0, IfxPort_State_toggled);
 * \endcode
 *
 */
IFX_INLINE void IfxPort_setPinState(Ifx_P *port, uint8 pinIndex, IfxPort_State action);

/** \brief Toggle the port output.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to be toggled.
 * \return None
 *
 * Coding example:
 * \code
 * IfxPort_togglePin(&MODULE_P33, 0);
 * \endcode
 *
 * \see IfxPort_setPinState(), IfxPort_setPinLow(), IfxPort_setPinHigh()
 *
 */
IFX_INLINE void IfxPort_togglePin(Ifx_P *port, uint8 pinIndex);

/** \brief set analog/digital mode for pin
 * \param port Pointer to Port register space
 * \param pinIndex specifies the pin index
 * \param mode set analog/digital mode
 * \return None
 */
IFX_INLINE void IfxPort_setPinFunctionMode(Ifx_P *port, uint8 pinIndex, IfxPort_PinFunctionMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disable the emergency stop function.
 * This function disables the emergency stop function. A check is done on port functionality.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin for which the emergency stop function should be disabled.
 * \return Returns TRUE if the emergency stop function has been disabled; FALSE if the emergency stop function could not be disabled
 *
 * Coding example:
 * /code
 *     if( !IfxPort_disableEmergencyStop(&MODULE_P33, 0) )
 *     {
 *         // failed to disable emergency stop for P33.0
 *     }
 * /endcode
 *
 * \see IfxPort_disableEmergencyStop(), IfxPort_resetESR()
 *
 */
IFX_EXTERN boolean IfxPort_disableEmergencyStop(Ifx_P *port, uint8 pinIndex);

/** \brief Enable the emergency stop function.
 * This function enables the emergency stop function. A check is done on port functionality.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin for which the emergency stop function should be enabled.
 * \return Returns TRUE if the emergency stop function has been enabled; FALSE if the emergency stop function could not be enabled
 *
 * Coding example:
 * \code
 *     if( !IfxPort_enableEmergencyStop(&MODULE_P33, 0) ) {
 *       // failed to enable emergency stop for P33.0
 *     }
 * \endcode
 *
 * \see IfxPort_disableEmergencyStop(), IfxPort_setESR()
 *
 */
IFX_EXTERN boolean IfxPort_enableEmergencyStop(Ifx_P *port, uint8 pinIndex);

/** \brief Configure the port input / output mode.
 * Also Configures the P40/P41 Port for digital functionality
 * which bydefault support analog functionality.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin to be configured.
 * \param mode Specifies the port pin mode.
 * \return None
 *
 * Coding example:
 * \code
 *     IfxPort_setPinMode(&MODULE_P33, 0, IfxPort_Mode_outputPushPullGeneral);
 * \endcode
 *
 */
IFX_EXTERN void IfxPort_setPinMode(Ifx_P *port, uint8 pinIndex, IfxPort_Mode mode);

/** \brief Configure the pad driver mode.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin for which the mode will be set.
 * \param padDriver Specifies the driver mode.
 * \return None
 *
 * Coding example:
 * \code
 * // enable strong 3.3V driver
 * IfxPort_setPinPadDriver(&MODULE_P33, 0, IfxPort_PadDriver_cmosAutomotiveSpeed1);
 * \endcode
 *
 */
IFX_EXTERN void IfxPort_setPinPadDriver(Ifx_P *port, uint8 pinIndex, IfxPort_PadDriver padDriver);

/** \brief set lvds mode
 * \param port pointer to Port Register space
 * \param pinIndex specifies pin index
 * \param pinMode specifes the mode of pin
 * \param lvds config LVDS
 * \return None
 */
IFX_EXTERN void IfxPort_setPinModeLVDS(Ifx_P *port, uint8 pinIndex, IfxPort_Mode pinMode, IfxPort_LvdsConfig *lvds);

/** \} */

/** \addtogroup IfxLld_Port_Std_PortGroup
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Return the port group state
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex start at the given pin
 * \param mask selects the pins which should be read (starting from pinIndex)
 * \return Returns the selected pin values
 *
 * Coding example:
 * \code
 * // read the current value of P33[7:0]
 * uint16 value = IfxPort_getGroupState(&MODULE_P33, 0, 0xff);
 * \endcode
 *
 */
IFX_INLINE uint32 IfxPort_getGroupState(Ifx_P *port, uint8 pinIndex, uint16 mask);

/** \brief Set the port group state.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex start at the given pin
 * \param mask selects the pins which should be modified (starting from pinIndex)
 * \param data specifies the value which should be set
 * \return None
 *
 * Coding example:
 * \code
 * // configure P33.[7:0] as GPIO outputs
 * IfxPort_setGroupModeOutput(&MODULE_P33, 0, 0xff, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
 *
 * // set initial value
 * IfxPort_setGroupState(&MODULE_P33, 0, 0xff, 0x42);
 * \endcode
 *
 */
IFX_INLINE void IfxPort_setGroupState(Ifx_P *port, uint8 pinIndex, uint16 mask, uint16 data);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Return port index within IfxModule_IndexMap (defined in IfxPort_cfg.c)
 * \param port Pointer to the port for which the index number in IfxModule_IndexMap should be retrieved.
 * \return port index of IfxModule_IndexMap. return -1 in case of unknown portIndex.
 */
IFX_EXTERN sint32 IfxPort_getIndex(Ifx_P *port);

/** \brief Set pin modes to input at the pin location specified by '1' by the mask
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex start at the given pin
 * \param mask selects the pins which should be modified (starting from pinIndex)
 * \param mode Specifies the port pin mode.
 * \return None
 *
 * Coding example:
 * \code
 * // configure P33.[7:0] as GPIO inputs with Pull-Down enabled
 * IfxPort_setGroupModeInput(&MODULE_P33, 0, 0xff, IfxPort_InputMode_pullDown);
 *  \endcode
 *
 */
IFX_EXTERN void IfxPort_setGroupModeInput(Ifx_P *port, uint8 pinIndex, uint16 mask, IfxPort_InputMode mode);

/** \brief Set pin modes to output at the pin location specified by '1' by the mask starting at pinIndex
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex start at the given pin
 * \param mask selects the pins which should be modified (starting from pinIndex)
 * \param mode Specifies the port pin mode.
 * \param index Specifies the alternate (or general purpose) output channel.
 * \return None
 *
 * Coding example:
 * \code
 * // configure P33.[7:0] as GPIO outputs
 * IfxPort_setGroupModeOutput(&MODULE_P33, 0, 0xff, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
 * \endcode
 *
 */
IFX_EXTERN void IfxPort_setGroupModeOutput(Ifx_P *port, uint8 pinIndex, uint16 mask, IfxPort_OutputMode mode, IfxPort_OutputIdx index);

/** \brief Set pad driver strength at the pin location specified by '1' by the mask
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex start at the given pin
 * \param mask selects the pins which should be modified (starting from pinIndex)
 * \param padDriver Specifies the pad driver strength.
 * \return None
 *
 * Coding example:
 * \code
 * // configure P33.[7:0] to use CMOS pad driver with speed 1
 * IfxPort_setGroupPadDriver(&MODULE_P33, 0, 0xff, IfxPort_PadDriver_cmosAutomotiveSpeed1);
 * \endcode
 *
 */
IFX_EXTERN void IfxPort_setGroupPadDriver(Ifx_P *port, uint8 pinIndex, uint16 mask, IfxPort_PadDriver padDriver);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disable the emergency stop function.
 * This function disables the emergency stop function. No check is done on port functionality.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin for which the emergency stop function should be disabled.
 * \return None
 *
 * \see IfxPort_disableEmergencyStop()
 *
 */
IFX_EXTERN void IfxPort_resetESR(Ifx_P *port, uint8 pinIndex);

/** \brief Enable the emergency stop function.
 * This function enables the emergency stop function. No check is done on port functionality.
 * \param port Pointer to the port which should be accessed.
 * \param pinIndex Specifies the pin for which the emergency stop function should be enabled.
 * \return None
 *
 * \see IfxPort_enableEmergencyStop()
 *
 */
IFX_EXTERN void IfxPort_setESR(Ifx_P *port, uint8 pinIndex);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE uint32 IfxPort_getGroupState(Ifx_P *port, uint8 pinIndex, uint16 mask)
{
    return (uint32)((port->IN.U) >> (pinIndex)) & mask;
}


IFX_INLINE boolean IfxPort_getPinState(Ifx_P *port, uint8 pinIndex)
{
    return (__getbit(&port->IN.U, pinIndex) != 0) ? TRUE : FALSE;
}


IFX_INLINE void IfxPort_setGroupState(Ifx_P *port, uint8 pinIndex, uint16 mask, uint16 data)
{
    port->OUT.U = (port->OUT.U & ~((uint32)(mask)) << pinIndex) | (data << pinIndex);
}


IFX_INLINE void IfxPort_setPinHigh(Ifx_P *port, uint8 pinIndex)
{
    IfxPort_setPinState(port, pinIndex, IfxPort_State_high);
}


IFX_INLINE void IfxPort_setPinLow(Ifx_P *port, uint8 pinIndex)
{
    IfxPort_setPinState(port, pinIndex, IfxPort_State_low);
}


IFX_INLINE void IfxPort_setPinModeInput(Ifx_P *port, uint8 pinIndex, IfxPort_InputMode mode)
{
    IfxPort_setPinMode(port, pinIndex, (IfxPort_Mode)mode);
}


IFX_INLINE void IfxPort_setPinModeOutput(Ifx_P *port, uint8 pinIndex, IfxPort_OutputMode mode, IfxPort_OutputIdx index)
{
    IfxPort_setPinMode(port, pinIndex, (IfxPort_Mode)(index | mode));
}


IFX_INLINE void IfxPort_setPinState(Ifx_P *port, uint8 pinIndex, IfxPort_State action)
{
    port->OMR.U = action << pinIndex;
}


IFX_INLINE void IfxPort_togglePin(Ifx_P *port, uint8 pinIndex)
{
    IfxPort_setPinState(port, pinIndex, IfxPort_State_toggled);
}


IFX_INLINE void IfxPort_setPinFunctionMode(Ifx_P *port, uint8 pinIndex, IfxPort_PinFunctionMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    port->PDISC.U |= (mode << pinIndex);
    IfxScuWdt_setCpuEndinit(passwd);
}


#endif /* IFXPORT_H */
