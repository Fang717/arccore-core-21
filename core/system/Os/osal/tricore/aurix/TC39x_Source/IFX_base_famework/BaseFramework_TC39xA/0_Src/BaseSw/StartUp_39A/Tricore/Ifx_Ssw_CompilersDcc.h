/*
 * Ifx_Ssw_CompilersDcc.h
 *
 *  Created on: 23.06.2016
 *      Author: abbi
 */

#ifndef IFX_SSW_COMPILERSDCC_H_
#define IFX_SSW_COMPILERSDCC_H_

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/


/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/*Linker definitions which are specific to Gnuc */
/* IFX_CFG_USE_COMPILER_DEFAULT_LINKER shall be defined in Ifx_Cfg.h
 * to use the default compiler linker varaibles and startup */
#ifndef IFX_CFG_USE_COMPILER_DEFAULT_LINKER

/*Start: Core 0 definitions ********************************************** */

/*C extern defintions */
#define IFX_SSW_CORE_LINKER_SYMBOLS(cpu)                                  \
    extern unsigned int __USTACK##cpu[];      /**< user stack end */          \
    extern unsigned int __ISTACK##cpu[];      /**< interrupt stack end */     \
    extern unsigned int __INTTAB_CPU##cpu[];  /**< interrupt vector table */  \
    extern unsigned int __TRAPTAB_CPU##cpu[]; /**< trap vector table */       \
    extern unsigned int __CSA##cpu[];         /**< context save area begin */ \
    extern unsigned int __CSA##cpu##_END[];   /**< context save area end   */

#define __USTACK(cpu)      __USTACK##cpu
#define __ISTACK(cpu)      __ISTACK##cpu
#define __INTTAB_CPU(cpu)  __INTTAB_CPU##cpu
#define __TRAPTAB_CPU(cpu) __TRAPTAB_CPU##cpu
#define __CSA(cpu)         __CSA##cpu
#define __CSA_END(cpu)     __CSA##cpu##_END

#define IFX_SSW_COMMON_LINKER_SYMBOLS() \
    __asm("\t .weak __A8_MEM, __A9_MEM");  /**< ASM extern definitions */

/*Wrapper macros for the tool specific definitions */
#if defined(IFX_USE_SW_MANAGED_INT)
#define __INTTAB(cpu)      ((unsigned int)__INTTAB_CPU##cpu | (unsigned int)0x1FE0)
#else
#define __INTTAB(cpu)      __INTTAB_CPU##cpu
#endif /*defined(IFX_USE_SW_MANAGED_INT) */

#define __TRAPTAB(cpu)     __TRAPTAB_CPU##cpu

#define __SDATA1(cpu)      _SMALL_DATA_
#define __SDATA2(cpu)      _LITERAL_DATA_
#define __SDATA3(cpu)      __A8_MEM
#define __SDATA4(cpu)      __A9_MEM

#endif /*#ifndef IFX_CFG_USE_COMPILER_DEFAULT_LINKER*/


#define IFX_SSW_INLINE   __inline__

#define IFX_SSW_NULL_PTR ((void*)0x0U)

/******************************************************************************/
/*--------------------------------   Typedefs  -------------------------------*/
/******************************************************************************/
typedef volatile union
{
	unsigned int       *ucPtr;
	unsigned int       *usPtr;
	unsigned int       *uiPtr;
    unsigned long long *ullPtr;
} Ifx_Ssw_CTablePtr;

/******************************************************************************/
/*----------------------------   GNU Intrinsics  -----------------------------*/
/******************************************************************************/

extern void Ifx_Ssw_MTCR( const unsigned int,  unsigned int) __attribute__((intrinsic_function(0x102, 0, "mtcr") ));

extern int Ifx_Ssw_MFCR( const unsigned int) __attribute__((intrinsic_function(0x101, 0, "mfcr") ));

extern void Ifx_Ssw_NOP( void) __attribute__((intrinsic_function(0x103, 0, "nop") ));

extern void Ifx_Ssw_DSYNC( void) __attribute__((intrinsic_function(0x103, 0, "dsync") ));

extern void Ifx_Ssw_ISYNC( void) __attribute__((intrinsic_function(0x103, 0, "isync") ));

extern unsigned int Ifx_Ssw_MINU(unsigned int, unsigned int) __attribute__((intrinsic_pseudo(3, "min.u") ));

extern int Ifx_Ssw_CLZ(int) __attribute__((intrinsic_pseudo(1, "clz") ));

#define Ifx_Ssw___setAddressReg(aReg, val) \
	{ __asm ("#$$bp"); \
	  __asm ("  movh.a\t %a15,"#val"@ha\n"); \
	  __asm ("  lea\t %a15,[%a15]"#val"@l\n"); \
	  __asm ("  mov.aa %"#aReg", %a15\n"); \
	  __asm ("#$$ep"); }

#define Ifx_Ssw_setAddressReg(regNum, val)  Ifx_Ssw___setAddressReg(regNum, val)

asm volatile void Ifx_Ssw_moveToDataParam0(unsigned int var)
{
% reg var
! "%d2"
	mov %d2, var
}

asm volatile unsigned int Ifx_Ssw_getDataParam0(void)
{
! "%d2"
	mov %d2, %d2
}

asm volatile void Ifx_Ssw_jumpToFunction(void *fun)
{
% reg fun
	ji fun
}

asm volatile void Ifx_Ssw_jumpToFunctionWithLink(void *fun)
{
% reg fun
	jli fun
}

asm void Ifx_Ssw_jumpBackToLink(void)
{
! "%a11"
	ji %a11
}

IFX_SSW_INLINE void Ifx_Ssw_C_InitInline(void)
{
	extern void __init_main(void);
	__init_main();              /* initialize data */
}



#endif /* IFX_SSW_COMPILERSDCC_H_ */
