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

/* ----------------------------[information]----------------------------------*/
/*
 * Author: mahi
 *
 * Description:
 *   Implements exceptions handlers for the mpc5xxx series.
 *   Vectors that are not used should probably report to some non-init RAM
 *   area and reset.
 *
 *   Comments about the vectors.
 *   IVOR0    - Critical interrupt
 *   IVOR1    - Machine check
 *   IVOR2    - Data Storage
 *   IVOR3    - Inst. Storage
 *   IVOR4    - External Input (INTC)
 *   IVOR5    - Alignment
 *   IVOR6    - Program
 *   IVOR7    - Floating point
 *   IVOR8    - System Call
 *   IVOR9    - Aux Processor (NOT USED)
 *   IVOR10   - Decrementer
 *   IVOR11   - FIT
 *   IVOR12   - Watchdog
 *   IVOR13   - Data TLB
 *   IVOR14   - Instr TLB
 *   IVOR15
 *   IVOR32
 *   IVOR33
 *   IVOR34
 *
 *   For *users* of the system the following could be of use:
 *     IVOR0  - If you use NMI pin and want to do something really critical.
 *     IVOR11 - The FIT is really bad timer (binary timeout) and since it's an exception
 *              it has higher priority than the INTC
 *     IVOR12 - Watchdog
 *
 *   and then we have ECC errors that affect IVOR1, IVOR2 and IVOR3.
 *   The exceptions can be divided into:
 *   - FEE related. Within this memory range the FEE should handle the errors.
 *     (Reset during program/erase should be considered normal behavior )
 *   - Non-FEE related. Something is very wrong with the flash.. record error and reset?
 *
 *  Design decision:
 *  - Call Os_Panic() for all exceptions not setup by the system.
 *  - Place Os_Panic() in Mcu_<cpu>.c
 *  - IMPROVEMENT: FEE memory ranges must be set somewhere?
 *  - Mcu_AddExceptionHook()
 *
 */


/* ----------------------------[includes]------------------------------------*/

//#if defined(CFG_MPC5XXX_TEST)
//#include "embUnit/embUnit.h"
//#endif
#include "mpc55xx.h"
#include "Mcu.h"
#include "asm_ppc.h"
#include "arch_stack.h"
#include "io.h"
#include "Mcu_Arc.h"
#include "arc.h"

/* ----------------------------[private define]------------------------------*/
/* ----------------------------[private macro]-------------------------------*/
/* ----------------------------[private typedef]-----------------------------*/
/* ----------------------------[private function prototypes]-----------------*/
/* ----------------------------[private variables]---------------------------*/
/* ----------------------------[private functions]---------------------------*/
/* ----------------------------[public functions]----------------------------*/



/*
 * Gets the instruction length of instructions at an address.
 *
 * The VLE detection is taken from AN4648 ( VLE 16-bit and 32-bit Instruction
 * Length Decode Algorithm )
 */
static uint32 adjustReturnAddr( uint32 instrAddr ) {

    uint32 vleMode = ( get_spr(SPR_ESR) & ESR_VLEMI );

    if( (vleMode!=0UL) ||
        ((*(uint16_t *)(instrAddr) & 0x9000U) == 0x1000U )) {
        instrAddr += 4UL;
    } else {
        /* Executing VLE and 16-bit instructions */
        instrAddr += 2UL;
    }
    return instrAddr;
}


/**
 * Calls higher level functions to handle the exception.
 *
 * @param exception The exception number
 * @param spr       The SPR number
 * @return
 */
static uint32 handleException( uint32 exception , uint32 spr ) {
    uint32 rv;
    uint32 _spr;

    /* Note that you cannot use get_spr() here directly since
     * it cannot be used that way */
    _spr = (spr==SPR_CSRR0) ? get_spr(SPR_CSRR0) : ((spr==SPR_MCSRR0)? get_spr(SPR_MCSRR0) : get_spr(SPR_SRR0));

    rv = Mpc5xxx_ExceptionHandler( exception );
    if( (rv & EXC_NOT_HANDLED) != 0UL ) {
        /* The exception was not handled */
        Os_Arc_Panic(exception,NULL);
        /* We may get back here if protection hook want us to ignore */
    }


    if( (rv & EXC_ADJUST_ADDR) != 0UL ) {
        rv = adjustReturnAddr( _spr );
    } else {
        rv = _spr;
    }
    return rv;
}

uint32 Mpc5xxx_Exception_IVOR0( void  );
uint32 Mpc5xxx_Exception_IVOR1( void  );
uint32 Mpc5xxx_Exception_IVOR2( void  );
uint32 Mpc5xxx_Exception_IVOR3( void  );
uint32 Mpc5xxx_Exception_IVOR5( void  );
uint32 Mpc5xxx_Exception_IVOR6( void  );
uint32 Mpc5xxx_Exception_IVOR7( void  );
uint32 Mpc5xxx_Exception_IVOR8( void  );
uint32 Mpc5xxx_Exception_IVOR11( void  );
uint32 Mpc5xxx_Exception_IVOR12( void  );
uint32 Mpc5xxx_Exception_IVOR13( void  );
uint32 Mpc5xxx_Exception_IVOR14( void  );
#if defined(CFG_SPE) || defined(CFG_EFPU)
uint32 Mpc5xxx_Exception_IVOR32( void  );
uint32 Mpc5xxx_Exception_IVOR33( void  );
uint32 Mpc5xxx_Exception_IVOR34( void  );
#if defined(CFG_MPC5777C)
uint32 Mpc5xxx_Exception_IVOR35( void  );
#endif
#endif


/* Critical Input:  CSRR0, CSRR1 */
uint32 Mpc5xxx_Exception_IVOR0( void  ) {
    return handleException(0, SPR_CSRR0 );
}

/* Machine Check:   CSRR0, CSRR1, MCSRR0, MCSRR1 */
uint32 Mpc5xxx_Exception_IVOR1( void ) {
    return handleException(1, SPR_MCSRR0 );
}

/* Data Storage:    SRR0, SRR1, ESR, DEAR */
uint32 Mpc5xxx_Exception_IVOR2( void ) {
    return handleException(2, SPR_SRR0 );
}

/* Inst. Storage:   SRR0, SRR1, ESR */
uint32 Mpc5xxx_Exception_IVOR3( void ) {
    return handleException(3, SPR_SRR0 );
}

/* Alignment:       SRR0, SRR1, ESR, DEAR */
uint32 Mpc5xxx_Exception_IVOR5( void ) {
    return handleException(5, SPR_SRR0 );
}

/* Program:         SRR0, SRR1, ESR */
uint32 Mpc5xxx_Exception_IVOR6( void ) {
    return handleException(6, SPR_SRR0 );
}

/* Floating Point:  SRR0, SRR1 */
uint32 Mpc5xxx_Exception_IVOR7( void ) {
    return handleException(7, SPR_SRR0 );
}

/* System Call:     SRR0, SRR1, ESR */
uint32 Mpc5xxx_Exception_IVOR8( void ) {
    return handleException(8, SPR_SRR0 );
}

/* FIT:             SRR0, SRR1 */
uint32 Mpc5xxx_Exception_IVOR11( void ) {
    return handleException(11, SPR_SRR0 );
}

/* Watchdog:        CSRR0, CSRR1 */
uint32 Mpc5xxx_Exception_IVOR12( void ) {
    return handleException(12, SPR_SRR0 );
}

/* Data TLB:        SRR0, SRR1, ESR, DEAR */
uint32 Mpc5xxx_Exception_IVOR13( void ) {
    return handleException(13, SPR_SRR0 );
}

/* Intstr TLB:      SRR0, SRR1, ESR */
uint32 Mpc5xxx_Exception_IVOR14( void ) {
    return handleException(14, SPR_SRR0 );
}

#if defined(CFG_SPE) || defined(CFG_EFPU)

/* SPE Unavailable:  SRR0, SRR1, ESR=SPE */
uint32 Mpc5xxx_Exception_IVOR32( void ) {
    return handleException(32, SPR_SRR0 );
}

/* SPE Data:  SRR0, SRR1, ESR=SPE */
uint32 Mpc5xxx_Exception_IVOR33( void ) {
    return handleException(33, SPR_SRR0 );
}

/* SPE round exception: SRR0, SRR1, ESR=SPE */
uint32 Mpc5xxx_Exception_IVOR34( void ) {
    return handleException(34, SPR_SRR0 );
}
#if defined(CFG_MPC5777C)
/* SPE round exception: SRR0, SRR1, ESR=SPE */
uint32_t Mpc5xxx_Exception_IVOR35( void ) {
    return handleException(35, SPR_SRR0 );
}
#endif
#endif



