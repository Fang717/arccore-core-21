/**
 * \file IfxScuEru.h
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
 * \defgroup IfxLld_Scu_Std_Eru Eru Basic Functionality
 * \ingroup IfxLld_Scu_Std
 * \defgroup IfxLld_Scu_Std_Eru_Enum ERU: Enumerations
 * \ingroup IfxLld_Scu_Std_Eru
 * \defgroup IfxLld_Scu_Std_Eru_External_Request_Selection ERU: External Request Selection
 * \ingroup IfxLld_Scu_Std_Eru
 * \defgroup IfxLld_Scu_Std_Eru_Event_Trigger_Logic ERU: Event Trigger Logic
 * \ingroup IfxLld_Scu_Std_Eru
 * \defgroup IfxLld_Scu_Std_Eru_Connecting_Matrix ERU: Connecting Matrix
 * \ingroup IfxLld_Scu_Std_Eru
 * \defgroup IfxLld_Scu_Std_Eru_Output_Gating_Unit ERU: Output Gating Unit
 * \ingroup IfxLld_Scu_Std_Eru
 * \defgroup IfxLld_Scu_Std_Eru_Data_Structures ERU: Data Structures
 * \ingroup IfxLld_Scu_Std_Eru
 * \defgroup IfxLld_Scu_Std_Eru_Input_Filtering ERU: Input Filtering
 * \ingroup IfxLld_Scu_Std_Eru
 */

#ifndef IFXSCUERU_H
#define IFXSCUERU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxScu_cfg.h"
#include "IfxScu_reg.h"
#include "Cpu/Std/IfxCpu.h"
#include "_PinMap/IfxScu_PinMap.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Scu_Std_Eru_Enum
 * \{ */
/** \brief Input line selection for input channel\n
 * Definition in Ifx_SCU.EICR[i].B.EXIS(j) (i = 0,1,2,3 and j = 0,1)
 */
typedef enum
{
    IfxScuEru_ExternalInputSelection_0 = 0,      /**< \brief External input 0 is selected  */
    IfxScuEru_ExternalInputSelection_1,          /**< \brief External input 1 is selected  */
    IfxScuEru_ExternalInputSelection_2,          /**< \brief External input 2 is selected  */
    IfxScuEru_ExternalInputSelection_3,          /**< \brief External input 3 is selected  */
    IfxScuEru_ExternalInputSelection_4,          /**< \brief External input 4 is selected  */
    IfxScuEru_ExternalInputSelection_5           /**< \brief External input 5 is selected  */
} IfxScuEru_ExternalInputSelection;

/** \brief Input channel for input selection  and conditioning of trigger or gating functions
 */
typedef enum
{
    IfxScuEru_InputChannel_0 = 0,      /**< \brief External Input channel 0  */
    IfxScuEru_InputChannel_1,          /**< \brief External Input channel 1  */
    IfxScuEru_InputChannel_2,          /**< \brief External Input channel 2  */
    IfxScuEru_InputChannel_3,          /**< \brief External Input channel 3  */
    IfxScuEru_InputChannel_4,          /**< \brief External Input channel 4  */
    IfxScuEru_InputChannel_5,          /**< \brief External Input channel 5  */
    IfxScuEru_InputChannel_6,          /**< \brief External Input channel 6  */
    IfxScuEru_InputChannel_7           /**< \brief External Input channel 7  */
} IfxScuEru_InputChannel;

/** \brief Digital Glitch Filter Clock Depth determines the number of port input samples considered\n
 * in the calculation of the floating average digital filter output for all enabled FLRQ filters.\n
 * Definition in Ifx_SCU.EIFILT.B.DEPTH
 */
typedef enum
{
    IfxScuEru_InputFilterDepth_disable = 0,  /**< \brief Disable all glitch filtering */
    IfxScuEru_InputFilterDepth_1,            /**< \brief glitch filter depth 1  */
    IfxScuEru_InputFilterDepth_2,            /**< \brief glitch filter depth 2  */
    IfxScuEru_InputFilterDepth_3,            /**< \brief glitch filter depth 3  */
    IfxScuEru_InputFilterDepth_4,            /**< \brief glitch filter depth 4  */
    IfxScuEru_InputFilterDepth_5,            /**< \brief glitch filter depth 5  */
    IfxScuEru_InputFilterDepth_6,            /**< \brief glitch filter depth 6  */
    IfxScuEru_InputFilterDepth_7,            /**< \brief glitch filter depth 7  */
    IfxScuEru_InputFilterDepth_8,            /**< \brief glitch filter depth 8  */
    IfxScuEru_InputFilterDepth_9,            /**< \brief glitch filter depth 9  */
    IfxScuEru_InputFilterDepth_10,           /**< \brief glitch filter depth 10  */
    IfxScuEru_InputFilterDepth_11,           /**< \brief glitch filter depth 11  */
    IfxScuEru_InputFilterDepth_12,           /**< \brief glitch filter depth 12  */
    IfxScuEru_InputFilterDepth_13,           /**< \brief glitch filter depth 13  */
    IfxScuEru_InputFilterDepth_14,           /**< \brief glitch filter depth 14  */
    IfxScuEru_InputFilterDepth_15            /**< \brief glitch filter depth 15  */
} IfxScuEru_InputFilterDepth;

/** \brief Digital Glitch Filter Clock Predivider to generate the digital filter sample clock\n
 * Definition in Ifx_SCU.EIFILT.B.FILTDIV
 */
typedef enum
{
    IfxScuEru_InputFilterPredivider_disable = 0,  /**< \brief Disable all glitch filtering */
    IfxScuEru_InputFilterPredivider_1,            /**< \brief glitch filter predivider 1  */
    IfxScuEru_InputFilterPredivider_2,            /**< \brief glitch filter predivider 2  */
    IfxScuEru_InputFilterPredivider_3,            /**< \brief glitch filter predivider 3  */
    IfxScuEru_InputFilterPredivider_4,            /**< \brief glitch filter predivider 4  */
    IfxScuEru_InputFilterPredivider_5,            /**< \brief glitch filter predivider 5  */
    IfxScuEru_InputFilterPredivider_6,            /**< \brief glitch filter predivider 6  */
    IfxScuEru_InputFilterPredivider_7,            /**< \brief glitch filter predivider 7  */
    IfxScuEru_InputFilterPredivider_8,            /**< \brief glitch filter predivider 8  */
    IfxScuEru_InputFilterPredivider_9,            /**< \brief glitch filter predivider 9  */
    IfxScuEru_InputFilterPredivider_10,           /**< \brief glitch filter predivider 10  */
    IfxScuEru_InputFilterPredivider_11,           /**< \brief glitch filter predivider 11  */
    IfxScuEru_InputFilterPredivider_12,           /**< \brief glitch filter predivider 12  */
    IfxScuEru_InputFilterPredivider_13,           /**< \brief glitch filter predivider 13  */
    IfxScuEru_InputFilterPredivider_14,           /**< \brief glitch filter predivider 14  */
    IfxScuEru_InputFilterPredivider_15            /**< \brief glitch filter predivider 15  */
} IfxScuEru_InputFilterPredivider;

/** \brief Digital port pin selection for input filter\n
 * Definition in Ifx_SCU.EIFILT.B.FILRQ(i)(j) (i = 0 to7 and j = A, B, C, D)
 */
typedef enum
{
    IfxScuEru_InputFilterRequestSelection_0A,  /**< \brief REQ0A */
    IfxScuEru_InputFilterRequestSelection_5A,  /**< \brief REQ5A */
    IfxScuEru_InputFilterRequestSelection_2A,  /**< \brief REQ2A */
    IfxScuEru_InputFilterRequestSelection_3A,  /**< \brief REQ3A */
    IfxScuEru_InputFilterRequestSelection_0C,  /**< \brief REQ0C */
    IfxScuEru_InputFilterRequestSelection_1C,  /**< \brief REQ1C */
    IfxScuEru_InputFilterRequestSelection_3C,  /**< \brief REQ3C */
    IfxScuEru_InputFilterRequestSelection_2C,  /**< \brief REQ2C */
    IfxScuEru_InputFilterRequestSelection_4A,  /**< \brief REQ4A */
    IfxScuEru_InputFilterRequestSelection_6A,  /**< \brief REQ6A */
    IfxScuEru_InputFilterRequestSelection_1A,  /**< \brief REQ1A */
    IfxScuEru_InputFilterRequestSelection_7A,  /**< \brief REQ7A */
    IfxScuEru_InputFilterRequestSelection_6D,  /**< \brief REQ6D */
    IfxScuEru_InputFilterRequestSelection_4D,  /**< \brief REQ4D */
    IfxScuEru_InputFilterRequestSelection_2D,  /**< \brief REQ2D */
    IfxScuEru_InputFilterRequestSelection_3D,  /**< \brief REQ3D */
    IfxScuEru_InputFilterRequestSelection_7C   /**< \brief REQ7C */
} IfxScuEru_InputFilterRequestSelection;

/** \brief Determines the destination (output channel) for trigger event (if enabled by Ifx_SCU.EICR[i].B.EIEN(j)).\n
 * Definition in Ifx_SCU.EICR[i].B.INP(j) (i = 0,1,2,3 and j = 0,1)
 */
typedef enum
{
    IfxScuEru_InputNodePointer_0 = 0,      /**< \brief Event from input ETLx triggers output OGU0 (signal TRx0)  */
    IfxScuEru_InputNodePointer_1,          /**< \brief Event from input ETLx triggers output OGU1 (signal TRx1)  */
    IfxScuEru_InputNodePointer_2,          /**< \brief Event from input ETLx triggers output OGU2 (signal TRx2)  */
    IfxScuEru_InputNodePointer_3,          /**< \brief Event from input ETLx triggers output OGU3 (signal TRx3)  */
    IfxScuEru_InputNodePointer_4,          /**< \brief Event from input ETLx triggers output OGU4 (signal TRx4)  */
    IfxScuEru_InputNodePointer_5,          /**< \brief Event from input ETLx triggers output OGU5 (signal TRx5)  */
    IfxScuEru_InputNodePointer_6,          /**< \brief Event from input ETLx triggers output OGU6 (signal TRx6)  */
    IfxScuEru_InputNodePointer_7           /**< \brief Event from input ETLx triggers output OGU7 (signal TRx7)  */
} IfxScuEru_InputNodePointer;

/** \brief Determines the pattern detection influence on the ouput lines ERU_GOUTy and ERU_IOUTy\n
 * Definition in Ifx_SCU.IGCR[i].B.IGP(j) (i = 0,1,2,3 and j = 0,1)
 */
typedef enum
{
    IfxScuEru_InterruptGatingPattern_none         = 0,  /**< \brief IOUTy is inactive, (the pattern is not considered) */
    IfxScuEru_InterruptGatingPattern_alwaysActive = 1,  /**< \brief IOUTy is activated in response to a trigger event, (the pattern is not considered) */
    IfxScuEru_InterruptGatingPattern_patternMatch = 2,  /**< \brief IOUTy is activated if a trigger event occures while the pattern is present, (the pattern is considered) */
    IfxScuEru_InterruptGatingPattern_patternMiss  = 3   /**< \brief IOUTy is activated if a trigger event occures while the pattern is not present, (the pattern is not considered) */
} IfxScuEru_InterruptGatingPattern;

/** \brief Output channel for combination of events, definition of their effects and distribution to the system (interrupt generation, ...)
 */
typedef enum
{
    IfxScuEru_OutputChannel_0 = 0,      /**< \brief Output channel 0  */
    IfxScuEru_OutputChannel_1,          /**< \brief Output channel 1  */
    IfxScuEru_OutputChannel_2,          /**< \brief Output channel 2  */
    IfxScuEru_OutputChannel_3,          /**< \brief Output channel 3  */
    IfxScuEru_OutputChannel_4,          /**< \brief Output channel 4  */
    IfxScuEru_OutputChannel_5,          /**< \brief Output channel 5  */
    IfxScuEru_OutputChannel_6,          /**< \brief Output channel 6  */
    IfxScuEru_OutputChannel_7           /**< \brief Output channel 7  */
} IfxScuEru_OutputChannel;

/** \} */

/** \addtogroup IfxLld_Scu_Std_Eru_External_Request_Selection
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initialises the External request Pin
 * \param req External request pin
 * \param inputMode Port Input mode
 * \return None
 */
IFX_INLINE void IfxScuEru_initReqPin(IfxScu_Req_In *req, IfxPort_InputMode inputMode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Determines which input line is selcted for input channel x
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \param inputSignal Input line selection for input channel
 * \return None
 */
IFX_EXTERN void IfxScuEru_selectExternalInput(IfxScuEru_InputChannel inputChannel, IfxScuEru_ExternalInputSelection inputSignal);

/** \} */

/** \addtogroup IfxLld_Scu_Std_Eru_Event_Trigger_Logic
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clears the external event flag of input channel x (INTFx)
 * \return None
 */
IFX_EXTERN void IfxScuEru_clearAllEventFlags(void);

/** \brief Clears the external event flag of input channel x (INTFx)
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return None
 */
IFX_EXTERN void IfxScuEru_clearEventFlag(IfxScuEru_InputChannel inputChannel);

/** \brief Clears all the configuration for the given input channel x
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return None
 */
IFX_EXTERN void IfxScuEru_clearInputChannelConfiguration(IfxScuEru_InputChannel inputChannel);

/** \brief Disables the automatic clearing of INTFx when the edge of input channel which has not been selected, is detected
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return None
 */
IFX_EXTERN void IfxScuEru_disableAutoClear(IfxScuEru_InputChannel inputChannel);

/** \brief Disables the falling edge of input channel to set the bit INTF x
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return None
 */
IFX_EXTERN void IfxScuEru_disableFallingEdgeDetection(IfxScuEru_InputChannel inputChannel);

/** \brief Disables the rising edge of input channel to set the bit INTF x
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return None
 */
IFX_EXTERN void IfxScuEru_disableRisingEdgeDetection(IfxScuEru_InputChannel inputChannel);

/** \brief Enables the automatic clearing of INTFx when the edge of input channel which has not been selected, is detected
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return None
 */
IFX_EXTERN void IfxScuEru_enableAutoClear(IfxScuEru_InputChannel inputChannel);

/** \brief Enables the falling edge of input channel to set the bit INTF x
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return None
 */
IFX_EXTERN void IfxScuEru_enableFallingEdgeDetection(IfxScuEru_InputChannel inputChannel);

/** \brief Enables the rising edge of input channel to set the bit INTF x
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return None
 */
IFX_EXTERN void IfxScuEru_enableRisingEdgeDetection(IfxScuEru_InputChannel inputChannel);

/** \brief Returns the status of the flags of all input channels
 * \return All flags Status
 */
IFX_EXTERN uint32 IfxScuEru_getAllEventFlagsStatus(void);

/** \brief Returns the status of the external event flag of input channel x (INTFx)
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return Status (TRUE / FALSE)
 */
IFX_EXTERN boolean IfxScuEru_getEventFlagStatus(IfxScuEru_InputChannel inputChannel);

/** \brief Returns all the configuration for the given input channel x
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return Input channel configuration
 */
IFX_EXTERN uint32 IfxScuEru_getInputChannelConfiguration(IfxScuEru_InputChannel inputChannel);

/** \brief Sets the external event flag of input channel x (INTFx)
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return None
 */
IFX_EXTERN void IfxScuEru_setEventFlag(IfxScuEru_InputChannel inputChannel);

/** \} */

/** \addtogroup IfxLld_Scu_Std_Eru_Connecting_Matrix
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Determines the destination (output channel) for trigger event (if enabled by Ifx_SCU.EICR[i].B.EIEN(j), i = 0,1,2,3 and j = 0,1).
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \param triggerSelect Trigger event selection
 * \return None
 */
IFX_EXTERN void IfxScuEru_connectTrigger(IfxScuEru_InputChannel inputChannel, IfxScuEru_InputNodePointer triggerSelect);

/** \brief Disables the generation of a trigger event for input channel x when the selected edge is detected
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return None
 */
IFX_EXTERN void IfxScuEru_disableTriggerPulse(IfxScuEru_InputChannel inputChannel);

/** \brief Enables the generation of a trigger event for input channel x when the selected edge is detected
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \return None
 */
IFX_EXTERN void IfxScuEru_enableTriggerPulse(IfxScuEru_InputChannel inputChannel);

/** \brief Enables the flag INTFx to take part in the pattern detection for output gating
 * \param outputChannel Output channel for combination of events, definition of their effects and distribution to the system (interrupt generation, ...)
 * \param inputChannel Input channel for input selection  and conditioning of trigger or gating functions
 * \param state FALSE: the bit INTFx does not take part in the pattern detection IPENjy = 0\n
 * TRUE : the bit INTFx is taken into consideration for the pattern detection IPENjy = 1
 * \return None
 */
IFX_EXTERN void IfxScuEru_setFlagPatternDetection(IfxScuEru_OutputChannel outputChannel, IfxScuEru_InputChannel inputChannel, boolean state);

/** \} */

/** \addtogroup IfxLld_Scu_Std_Eru_Output_Gating_Unit
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clears all the configuration for the given input channel y
 * \param outputChannel Output channel for combination of events, definition of their effects and distribution to the system (interrupt generation, ...)
 * \return None
 */
IFX_EXTERN void IfxScuEru_clearOutputChannelConfiguration(IfxScuEru_OutputChannel outputChannel);

/** \brief Disables the generation of a trigger event for output channel y when the result of the pattern detection changes
 * \param outputChannel Output channel for combination of events, definition of their effects and distribution to the system (interrupt generation, ...)
 * \return None
 */
IFX_EXTERN void IfxScuEru_disablePatternDetectionTrigger(IfxScuEru_OutputChannel outputChannel);

/** \brief Enables the generation of a trigger event for output channel y when the result of the pattern detection changes
 * \param outputChannel Output channel for combination of events, definition of their effects and distribution to the system (interrupt generation, ...)
 * \return None
 */
IFX_EXTERN void IfxScuEru_enablePatternDetectionTrigger(IfxScuEru_OutputChannel outputChannel);

/** \brief Clears all the configuration for the given input channel y
 * \param outputChannel Output channel for combination of events, definition of their effects and distribution to the system (interrupt generation, ...)
 * \return Output channel configuration
 */
IFX_EXTERN uint32 IfxScuEru_getOutputChannelConfiguration(IfxScuEru_OutputChannel outputChannel);

/** \brief Returns the status of the pattern detection result of output channel y (PDRy)
 * \param outputChannel Output channel for combination of events, definition of their effects and distribution to the system (interrupt generation, ...)
 * \return Status (TRUE / FALSE)
 */
IFX_EXTERN boolean IfxScuEru_getPatternDetectionResult(IfxScuEru_OutputChannel outputChannel);

/** \brief Returns the whole pattern detection result of all the selcted output channels
 * \return Detected pattern
 */
IFX_EXTERN uint32 IfxScuEru_getWholePatternDetectionResult(void);

/** \brief Sets the gating pattern of a ouput channel y to determine how the pattern detection influences the output lines GOUT and IOUT
 * \param outputChannel Output channel for combination of events, definition of their effects and distribution to the system (interrupt generation, ...)
 * \param gatingPattern Interrupt gating pattern to determine how the pattern detection influences the ouput lines GOUT and IOUT
 * \return None
 */
IFX_EXTERN void IfxScuEru_setInterruptGatingPattern(IfxScuEru_OutputChannel outputChannel, IfxScuEru_InterruptGatingPattern gatingPattern);

/** \} */

/** \addtogroup IfxLld_Scu_Std_Eru_Input_Filtering
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enables the input filter for the selected digital pin (REQxy)
 * \param requestSelection Digital port pin selection for input filter
 * \return None
 */
IFX_INLINE void IfxScuEru_disableInputFilter(IfxScuEru_InputFilterRequestSelection requestSelection);

/** \brief Enables the input filter for the selected digital pin (REQxy)
 * \param requestSelection Digital port pin selection for input filter
 * \return None
 */
IFX_INLINE void IfxScuEru_enableInputFilter(IfxScuEru_InputFilterRequestSelection requestSelection);

/** \brief Sets the digital glitch filter depth
 * \param depth Digital Glitch Filter depth
 * \return None
 */
IFX_INLINE void IfxScuEru_setInputFilterDepth(IfxScuEru_InputFilterDepth depth);

/** \brief Sets the digital glitch filter predivider
 * \param predivider Digital Glitch Filter Predivider
 * \return None
 */
IFX_INLINE void IfxScuEru_setInputFilterPredivider(IfxScuEru_InputFilterPredivider predivider);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxScuEru_disableInputFilter(IfxScuEru_InputFilterRequestSelection requestSelection)
{
    uint32 value = 1 << requestSelection;
    SCU_EIFILT.U &= ~(value);
}


IFX_INLINE void IfxScuEru_enableInputFilter(IfxScuEru_InputFilterRequestSelection requestSelection)
{
    uint32 value = 1 << requestSelection;
    SCU_EIFILT.U |= value;
}


IFX_INLINE void IfxScuEru_initReqPin(IfxScu_Req_In *req, IfxPort_InputMode inputMode)
{
    IfxPort_setPinModeInput(req->pin.port, req->pin.pinIndex, inputMode);
    IfxScuEru_selectExternalInput((IfxScuEru_InputChannel)req->channelId, (IfxScuEru_ExternalInputSelection)req->select);
}


IFX_INLINE void IfxScuEru_setInputFilterDepth(IfxScuEru_InputFilterDepth depth)
{
    SCU_EIFILT.B.DEPTH = depth;
}


IFX_INLINE void IfxScuEru_setInputFilterPredivider(IfxScuEru_InputFilterPredivider predivider)
{
    SCU_EIFILT.B.FILTDIV = predivider;
}


#endif /* IFXSCUERU_H */
