#include <Rte_Internal.h>
#include <Rte_Calprms.h>
#include <Rte_Assert.h>
#include <Rte_Fifo.h>
#include <Com.h>
#include <Os.h>
#include <Ioc.h>
#include <Rte_Buffers.h>

/*lint -e522 lint does not understand that low level calls to void operator are needed */
/*lint -e160 warning only viable if in c++ */
/*lint -e950 asm command needs to be used */
/*lint -e9008 The comma operator is acceptable even with loss of readability */
/*lint -e451 AUTOSAR API */
/*lint -e515 Variable amount of Arguments for SYS_CALLS */
/*lint -e970 Use of types and modifiers acceptable outside of typedefs */
/*lint -e843 AUTOSAR API for memory wrapping */
/*lint -e838 all values must have an assigned value on initialization even if unused */
/*lint -e9018 AUTOSAR API for Union types */
/*lint -e516 Variable argument types for SYS_CALLS */
/*lint -e545 Sending pointer address is legal in ANSI C */

/*lint -e957 Should be fixed, most functions are missing these prototypes */
/** --- SERVER ACTIVATIONS ------------------------------------------------------------------ */

/** --- FUNCTIONS --------------------------------------------------------------------------- */
//lint -save -e715 Ignore unconnected functions
#define Rte_START_SEC_CODE
#include <Rte_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
/** ------ DoorStatus */
/*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
Std_ReturnType Rte_Write_DoorSensor_leftDoorSensor_DoorStatus_status(/*IN*/DoorStatusImpl value) {
    Std_ReturnType retVal = RTE_E_OK;

    /* --- Sender (leftDoorSensor_DoorStatus_to_lightManager_LeftDoorStatus) */
    {
        SYS_CALL_AtomicCopyBoolean(Rte_Buffer_lightManager_LeftDoorStatus_status, value);
    }

    return retVal;
}

/** ------ DoorSwitchSignal */
//lint --e{818}
/*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
Std_ReturnType Rte_Call_DoorSensor_leftDoorSensor_DoorSwitchSignal_Read(/*OUT*/DigitalLevel * Level, /*OUT*/SignalQuality * Quality) {
    return Rte_Call_IoHwAb_ioHwAb_Digital_FrontDoorLeft_Read(Level, Quality);
}

/** ------ DoorStatus */
/*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
Std_ReturnType Rte_Write_DoorSensor_rightDoorSensor_DoorStatus_status(/*IN*/DoorStatusImpl value) {
    Std_ReturnType retVal = RTE_E_OK;

    /* --- Sender (rightDoorSensor_DoorStatus_to_lightManager_RightDoorStatus) */
    {
        SYS_CALL_AtomicCopyBoolean(Rte_Buffer_lightManager_RightDoorStatus_status, value);
    }

    return retVal;
}

/** ------ DoorSwitchSignal */
//lint --e{818}
/*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
Std_ReturnType Rte_Call_DoorSensor_rightDoorSensor_DoorSwitchSignal_Read(/*OUT*/DigitalLevel * Level, /*OUT*/SignalQuality * Quality) {
    return Rte_Call_IoHwAb_ioHwAb_Digital_FrontDoorRight_Read(Level, Quality);
}

#define Rte_STOP_SEC_CODE
#include <Rte_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

//lint -restore
