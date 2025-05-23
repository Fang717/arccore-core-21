/**
 * \file IfxCpu_Trap.c
 * \brief This file contains the APIs for Trap related functions.
 *
 * \version iLLD_1_0_0_12_0
 * \copyright Copyright (c) 2012 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Cpu_Trap Trap Functions
 * \ingroup IfxLld_Cpu
 *
 * \defgroup IfxLld_Cpu_Trap_Hooks Trap Function Hooks
 * \ingroup IfxLld_Cpu_Trap
 *
 * \defgroup IfxLld_Cpu_Trap_Usage How to use the Trap Function Hooks?
 * \ingroup IfxLld_Cpu_Trap
 *
 */

#ifndef IFXCPU_TRAPS_H_
#define IFXCPU_TRAPS_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Cpu/Std/Ifx_Types.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "Ifx_Cfg.h"

/*******************************************************************************
**                      Type definitions                                     **
*******************************************************************************/
/** \addtogroup IfxLld_Cpu_Trap_Hooks
 * \{ */

/** \brief Enum for available Trap classes.
 *
 */
typedef enum
{
    IfxCpu_Trap_Class_memoryManagement     = 0U,
    IfxCpu_Trap_Class_internalProtection   = 1U,
    IfxCpu_Trap_Class_instructionErrors    = 2U,
    IfxCpu_Trap_Class_contextManagement    = 3U,
    IfxCpu_Trap_Class_bus                  = 4U,
    IfxCpu_Trap_Class_assertion            = 5U,
    IfxCpu_Trap_Class_systemCall           = 6U,
    IfxCpu_Trap_Class_nonMaskableInterrupt = 7U
} IfxCpu_Trap_Class;

/** \brief Enum for available Identification numbers under Memory Management Trap.
 *
 */
typedef enum
{
    IfxCpu_Trap_MemoryManagement_Id_virtualAddressFill       = 0U,
    IfxCpu_Trap_MemoryManagement_Id_virtualAddressProtection = 1U,
} IfxCpu_Trap_MemoryManagement_Id;

/** \brief Enum for available Identification numbers under Internal Protection Trap.
 *
 */
typedef enum
{
    IfxCpu_Trap_InternalProtection_Id_privilegeViolation               = 1U,
    IfxCpu_Trap_InternalProtection_Id_memoryProtectionRead             = 2U,
    IfxCpu_Trap_InternalProtection_Id_memoryProtectionWrite            = 3U,
    IfxCpu_Trap_InternalProtection_Id_memoryProtectionExecute          = 4U,
    IfxCpu_Trap_InternalProtection_Id_memoryProtectionPeripheralAccess = 5U,
    IfxCpu_Trap_InternalProtection_Id_memoryProtectionNullAddress      = 6U,
    IfxCpu_Trap_InternalProtection_Id_globalRegisterWriteProtection    = 7U,
} IfxCpu_Trap_InternalProtection_Id;

/** \brief Enum for available Identification numbers under Instruction Errors Trap.
 *
 */
typedef enum
{
    IfxCpu_Trap_InstructionErrors_Id_illegalOpcode        = 1U,
    IfxCpu_Trap_InstructionErrors_Id_unimplementedOpcode  = 2U,
    IfxCpu_Trap_InstructionErrors_Id_invalidOperand       = 3U,
    IfxCpu_Trap_InstructionErrors_Id_dataAddressAlignment = 4U,
    IfxCpu_Trap_InstructionErrors_Id_invalidMemoryAddress = 5U,
} IfxCpu_Trap_InstructionErrors_Id;

/** \brief Enum for available Identification numbers under Context Management Trap.
 *
 */
typedef enum
{
    IfxCpu_Trap_ContextManagement_Id_freeContextListDepletion = 1U,
    IfxCpu_Trap_ContextManagement_Id_callDepthOverflow        = 2U,
    IfxCpu_Trap_ContextManagement_Id_callDepthUnderflow       = 3U,
    IfxCpu_Trap_ContextManagement_Id_freeContextListUnderflow = 4U,
    IfxCpu_Trap_ContextManagement_Id_callStackUnderflow       = 5U,
    IfxCpu_Trap_ContextManagement_Id_contextType              = 6U,
    IfxCpu_Trap_ContextManagement_Id_nestingError             = 7U,
} IfxCpu_Trap_ContextManagement_Id;

/** \brief Enum for available Identification numbers under Bus Trap.
 *
 */
typedef enum
{
    IfxCpu_Trap_Bus_Id_programFetchSynchronousError     = 1U,
    IfxCpu_Trap_Bus_Id_dataAccessSynchronousError       = 2U,
    IfxCpu_Trap_Bus_Id_dataAccessAsynchronousError      = 3U,
    IfxCpu_Trap_Bus_Id_CoprocessorTrapAsynchronousError = 4U,
    IfxCpu_Trap_Bus_Id_programMemoryIntegrityError      = 5U,
    IfxCpu_Trap_Bus_Id_dataMemoryIntegrityError         = 6U,
    IfxCpu_Trap_Bus_Id_temporalAsynchronousError        = 7U,
} IfxCpu_Trap_Bus_Id;

/** \brief Enum for available Identification numbers under Assertion Trap.
 *
 */
typedef enum
{
    IfxCpu_Trap_Assertion_Id_arithmeticOverflow       = 1U,
    IfxCpu_Trap_Assertion_Id_stickyArithmeticOverflow = 2U,
} IfxCpu_Trap_Assertion_Id;

/** \brief Type for Identification numbers under SystemCall Trap.
 *
 */
typedef sint32 IfxCpu_Trap_SystemCall_Id;

/** \brief Type for Identification number for Non Maskable Interrupt Trap.
 *
 */
typedef sint32 IfxCpu_Trap_NonMaskableInterrupt_Id;

/** \brief Union to abstract Identification numbers under Traps.
 *
 */
typedef union
{
    IfxCpu_Trap_MemoryManagement_Id     memoryManagement;
    IfxCpu_Trap_InternalProtection_Id   internalProtection;
    IfxCpu_Trap_InstructionErrors_Id    instructionErrors;
    IfxCpu_Trap_ContextManagement_Id    contextManagement;
    IfxCpu_Trap_Bus_Id                  bus;
    IfxCpu_Trap_Assertion_Id            assertion;
    IfxCpu_Trap_SystemCall_Id           systemCall;
    IfxCpu_Trap_NonMaskableInterrupt_Id nonMaskableInterrupt;
} IfxCpu_Trap_Id;

/** \brief Structure to contain the trap information.
 *
 */
typedef struct
{
    unsigned int tAddr;
    unsigned int tId : 8;
    unsigned int tClass : 8;
    unsigned int tCpu : 3;
} IfxCpu_Trap;

/*******************************************************************************
**                Global Exported variables/constants                         **
*******************************************************************************/

/*******************************************************************************
**         Global Exported macros/inlines/function ptototypes                 **
*******************************************************************************/
/** \brief Macro to define the trap vector table.
 * This macro is provided to define the trap vector table in the frameowrk. User shall not use
 * this macro.
 * Refer to the documentation to extend the trap with hook functions. \ref IfxLld_Cpu_Trap_Usage
 */
#if defined(__GNUC__)
#define __ALIGN_TRAP_TAB__ __asm(" .align 5");
#define IfxCpu_Tsr_CallTSR(serviceRoutine)         \
    {                                              \
        __ALIGN_TRAP_TAB__;                        \
        __asm("svlcx\n");                          \
        __asm("mov\t %d4, %d15");                  \
        __asm("ji\t %0" : : "a" (serviceRoutine)); \
        __asm("rfe");                              \
    }
#elif defined(__DCC__)
#define IfxCpu_Tsr_CallTSR(serviceRoutine)                  \
    {                                                       \
        __ALIGN_TRAP_TAB__;                                 \
        __asm("\n#$$bp\n");                                 \
        __asm("svlcx\n");                                   \
        __asm("  movh.a\t %a15,"#serviceRoutine "@ha\n");   \
        __asm("  lea\t %a15,[%a15]"#serviceRoutine "@l\n"); \
        __asm("  mov\t %d4,%d15\n");                        \
        __asm("  ji\t  %a15\n");                            \
        __asm("  rfe");                                     \
        __asm("#$$ep");                                     \
    }
#define __ALIGN_TRAP_TAB__ __asm(" .align 5");
#elif defined(__TASKING__)
#define IfxCpu_Tsr_CallTSR(serviceRoutine)                                              \
    {                                                                                   \
        __ALIGN_TRAP_TAB__;                                                             \
        __asm("svlcx\n\tmov\td4,d15\n\tji\t%0\n" : : "a" (serviceRoutine) : "d4", "d15"); \
    }
#define __ALIGN_TRAP_TAB__ __asm(" .align 32");
#endif

/** \} */

/*Documentation */
/** \addtogroup IfxLld_Cpu_Trap_Usage
 * \{
 *
 * This page describes how to use the trap function hooks with application framework.\n
 * Framework has built in Trap Service Routines, which has minimal set of debug information.
 * The execution of trap service is as below,\n
 * 1) When a trap occurs, a global structure variable "trapWatch" is updated with the information:\n
 * __a. Which CPU caused this trap,\n
 * __b. What is the trap class and\n
 * __c. What is the trap identification number\n
 * 2) Call to a configurable hook function, passing structure trapWatch as parameter.\n
 * 3) Then debug instruction executed.\n
 * 4) Returning from the trap. (This instruction is not reached if debugger is connected because of
 *  "debug" instruction before)\n
 * For normal cases during development, where user works with debugger, user can watch the structure variable
 *  "trapWatch" in the debugger.
 *
 * In case, user wants to make use of the information of trap for further processing,\n
 * extend the traps, using the hook functions provided.
 *
 * \section IfxLld_Cpu_Trap_Hooks Extending the traps with hook functions.
 *
 * If the trap extensions are to be extended, it is very important to enable this feature. By default this
 * feature is disabled.
 *
 * \subsection IfxLld_Cpu_Trap_Hooks_EnableExtn How to enable the trap extension feature?
 * To extend the trap hook functions user must enable this feature by defining the macro
 * "IFX_CFG_EXTEND_TRAP_HOOKS" in Ifx_Cfg.h, at path: 0_Src/0_AppSw/Config/Common/, as shown below.
 * \code
 * //file: Ifx_Cfg.h
 *
 * #define IFX_CFG_EXTEND_TRAP_HOOKS
 *
 * \endcode
 * Now the compiler will accept the further configurations to extend the hooks.\n
 * IfxCpu_Traps_Cfg.h file shall be used to extend the traps. This provide two kind of hook functions.
 * ie. Hook for error traps and hooks (per CPU available) for system calls.
 *
 * \subsection IfxLld_Cpu_Trap_ErrorHooks Extending the "Error traps" with hook function.
 * Error trap occurs as a result of an error event such as an instruction error, memory-management error
 * or an illegal access.\n
 * To extend the error traps, following steps are to be followed:\n
 * \subsubsection IfxLld_Cpu_Trap_ErrorHooksStep1 Step1: Define a routine to substitute the hook for error traps.
 * This definition shall be as user defined code (Generally in DemoApps folder).\n
 * Considerations:\n
 * 1. Format: IFX_INLINE void \<trap extension name\>(IfxCpu_Trap trapInfo)
 * \note Define such a routine with the consideration that the trap extension hook is not a function. In case
 *  of context management error, this extension itself will not call any other function.
 *
 * 2. Use the information trapInfo, which is available as parameter passed to this hook and process further.
 * Example code in a user defined file eg. Ifx_TrapExtension.h, placed under folder/subfolder: 0_AppSw/Tricore/DemoApp:
 * \code
 * //Example "inlined" function for trap Extension Hook.
 * IFX_INLINE myTrapExtensionHook(IfxCpu_Trap trapInfo)
 * {
 *   switch (trapInfo.tClass)
 *   {
 *     case IfxCpu_Trap_Class_memoryManagement:
 *     {
 *       //user code: Function calls allowed.
 *       break;
 *     }
 *     case IfxCpu_Trap_Class_internalProtection:
 *     {
 *       //user code: Function calls allowed.
 *       break;
 *     }
 *     case IfxCpu_Trap_Class_instructionErrors:
 *     {
 *       //user code: Function calls allowed.
 *       break;
 *     }
 *     case IfxCpu_Trap_Class_contextManagement:
 *     {
 *       //user code: Function calls NOT allowed.
 *       break;
 *     }
 *     case IfxCpu_Trap_Class_bus:
 *     {
 *       //user code: Function calls allowed.
 *       break;
 *     }
 *     case IfxCpu_Trap_Class_assertion:
 *     {
 *       //user code: Function calls allowed.
 *       break;
 *     }
 *     case IfxCpu_Trap_Class_nonMaskableInterrupt:
 *     {
 *       //user code: Function calls allowed.
 *       break;
 *     }
 *     case default:
 *     {
 *       break;
 *     }
 *   }
 * }
 * \endcode
 * \note The error trap functions execute the debug instruction immediately after returning from extension hooks.
 *
 * \subsubsection IfxLld_Cpu_Trap_ErrorHooksStep2 Step2: Configure error trap hook extension function.
 * Configure error trap hook extension function as defined above to the macro as below:
 * \note Configuration of hook extension is available in IfxCpu_Trap_Cfg at path ../0_Src/0_AppSw/Tricore/McHalCfg/
 *
 * \code
 * //file: IfxCpu_Trap_Cfg.h
 *
 * #include "Ifx_TrapExtension.h" //Assuming this is the file name as in above example
 *
 * #define IFXCPU_TRAP_CFG_TSR_HOOK(trapInfo)  myTrapExtensionHook(trapInfo) //This is INLINE function.
 *
 * \endcode
 * \note The exten hooks are effective only if this feature is enabled as explained in \ref Ifx_Trap_Hooks_EnableExtn
 *
 * \subsection IfxLld_Cpu_Trap_SysCallHooks Extending the cpu specific "system call" hook functions.
 * Tricore architecture provides the system call trap which is executed by software trigger. The instruction "syscall"
 * triggers this trap. Please refer Tricore architecture manual for more details.\n
 * IfxCpu_trap driver provide hook function for each CPU separately. To extend System Call trap following steps
 * are to be followed:\n
 * \subsubsection IfxLld_Cpu_Trap_SysCallHooksStep1 Step1: Define routine/s to substitute the hook/s for System Call trap.
 * This definition shall be as user defined code (Generally in DemoApps folder).\n
 * Considerations:\n
 * 1. Format: void \<syscall function name\>(IfxCpu_Trap trapInfo)
 * It is allowed to define this trap extension as function definition, because this trap is not triggered due to any error.
 * Depending on the application requirement, define single or per CPU instance of the extension.
 *
 * 2. Use the information trapInfo which is available as parameter passed to this hook and process further. The parameter
 * passed, with syscall instruction, will be trap identification number (refer to Tricore architecture manual for more details).
 * \note To hook extension, information about trap identification number is available through parameter "trapInfo".
 *
 * Example code in a user defined file eg. Ifx_TrapExtension.h, placed under folder/subfolder: 0_AppSw/Tricore/DemoApp:
 * \code
 * //Example function for System Call Extension Hook.
 * IFX_INLINE mySysCallExtensionHook(IfxCpu_Trap trapInfo)
 * {
 *   switch (trapInfo.tId)
 *   {
 *     case 0:
 *     {
 *       //user code: Function calls allowed.
 *       break;
 *     }
 *     case 1:
 *     {
 *       //user code: Function calls allowed.
 *       break;
 *     }
 *     // and so on..
 *     case default:
 *     {
 *       break;
 *     }
 *   }
 * }
 * \endcode
 *
 * \subsubsection IfxLld_Cpu_Trap_SysCallHooksStep2 Step2: Configure the extension function.\n
 * Configure the hook extension function defined above, to the macro as below:
 * \note Configuration of hook extension is available in IfxCpu_Trap_Cfg file at path ../0_Src/0_AppSw/Tricore/McHalCfg/
 * \code
 * //file: IfxCpu_Trap_Cfg.h
 *
 * #include "Ifx_TrapExtension.h" //Assuming this is the file name as in above example
 *
 * #define IFXCPU_TRAP_CFG_SYSCALL_CPU0_HOOK(trapInfo)  mySysCallExtensionHook(trapInfo)
 *
 * #define IFXCPU_TRAP_CFG_SYSCALL_CPU1_HOOK(trapInfo)  // Not used in this example
 *
 * #define IFXCPU_TRAP_CFG_SYSCALL_CPU2_HOOK(trapInfo)  // Not used in this example
 *
 * #define IFXCPU_TRAP_CFG_SYSCALL_CPU3_HOOK(trapInfo)  // Not used in this example
 *
 * #define IFXCPU_TRAP_CFG_SYSCALL_CPU4_HOOK(trapInfo)  // Not used in this example
 *
 * #define IFXCPU_TRAP_CFG_SYSCALL_CPU5_HOOK(trapInfo)  // Not used in this example
 *
 * \endcode
 *
 * \note The exten hooks are effective only if this feature is enabled as explained in \ref Ifx_Trap_Hooks_EnableExtn
 *
 */
/** \} */

#endif /* IFXCPU_TRAPS_H_ */
