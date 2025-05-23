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

/* ----------------------------[includes]------------------------------------*/

#include "arc_assert.h"
#include "Std_Types.h"
#include "Mcu.h"
#include "io.h"
#include "mpc55xx.h"
#include "Mcu_Arc.h"
#if defined(USE_FEE)
#include "Fee_Memory_Cfg.h"
#endif
#if defined(USE_DMA)
#include "Dma.h"
#endif
#include "asm_ppc.h"
#include "Os.h"
#include "EcuM.h"
#include "isr.h"

#include <string.h>

/*lint -e923 Cast in Freescale header file */
/* ----------------------------[private define]------------------------------*/
/* ----------------------------[private macro]-------------------------------*/

#define ME_RUN_PC0      0uL
#define ME_RUN_PC1      1uL

/* ----------------------------[private typedef]-----------------------------*/
/* ----------------------------[private function prototypes]-----------------*/
/* ----------------------------[private variables]---------------------------*/
/* ----------------------------[private functions]---------------------------*/
/* ----------------------------[public functions]----------------------------*/



void Mcu_Arc_InitPre( const Mcu_ConfigType *configPtr ) {
    /*lint -e{920} General interface, the configPtr may be needed for other architectures */
    (void)configPtr;
#if defined(CFG_E200Z4D) || defined(CFG_E200Z4)
    Cache_EnableI(); 
#if !defined(USE_TTY_WINIDEA)
// cannot use debug terminal with D-cache enabled
    Cache_EnableD();
#endif
#endif
}

void Mcu_Arc_InitPost( const Mcu_ConfigType *configPtr ) {
    /*lint -e{920} General interface, the configPtr may be needed for other architectures */
    (void)configPtr;
}


#if defined(CFG_MCU_ARC_LP)

/**************************************************************
Supported processors: MPC560X, MPC5645S, MPC5646B
***************************************************************/
static void enterStandby( void ) {
    /* ME_PCTL_x MUST be off */

    /* Configure STANDBY0 Mode for lowest consumption (only WUP Unit ON) */
    /* Please note, WKPU (Wakeup Unit) is always enabled */
    /* To generate an interrupt event triggered by a wakeup line, it is */
    /* necessary to enable WKPU */

    /* Improvement: This code should to be encapsulated within 
     define "supported" processors, otherway dependency on header files 
	 doesn't reflect as well architectures deviations */
	 
    RGM.STDBY.B.BOOT_FROM_BKP_RAM = 1u;
    ME.MER.B.STANDBY = 1u;

#if defined(CFG_MPC5646B)
    RGM.STDBY.B.BOOT_FROM_BKP_RAM = 1u;
    ME.MER.B.STANDBY = 1u;

    /* PD0 is always on and that holds first 8K of SRAM */
    PCU.PCONF[2].B.STBY = 1u;       /* Enable 56K RAM in stdby */
	
    /* Turn off ALL ME_PCTL
     * All ME_PCTL point to LP config ME_LP_PC0 (LP_CFG=0)
     */
    ME.LPPC[0].R = 0uL;       /* Freeze peripherals */
    ME.RUNPC[0].R = 0xfeuL;
    ME.RUNPC[1].R = 0xfeuL;

    /*** Errata e3247, must write FRZ to all CAN devices. ***/
    CAN_0.MCR.B.FRZ = 1u;
    CAN_0.MCR.B.MDIS = 1u;
    CAN_1.MCR.B.FRZ = 1u;
    CAN_1.MCR.B.MDIS = 1u;
    CAN_2.MCR.B.FRZ = 1u;
    CAN_2.MCR.B.MDIS = 1u;
    CAN_3.MCR.B.FRZ = 1u;
    CAN_3.MCR.B.MDIS = 1u;
    CAN_4.MCR.B.FRZ = 1u;
    CAN_4.MCR.B.MDIS = 1u;
    CAN_5.MCR.B.FRZ = 1u;
    CAN_5.MCR.B.MDIS = 1u;

    Mcu_Arc_SwitchMode(MODE_STANDBY);
    /* From "MC_ME Mode Diagram", page 136 in RM,  it seems as e return to DRUN after exit of STANDBY0 */


#elif defined(CFG_MPC560X)
    RGM.STDBY.B.BOOT_FROM_BKP_RAM = 1u;
    ME.MER.B.STANDBY = 1u;

    PCU.PCONF[2].B.STBY0 = 1u;       /* Enable 32K RAM in stdby */

    /* Turn off ALL ME_PCTL
     * All ME_PCTL point to LP config ME_LP_PC0 (LP_CFG=0)
     */
    ME.LPPC[0].R = 0uL;       /* Freeze peripherals */
    ME.RUNPC[0].R = 0xfeuL;
    ME.RUNPC[1].R = 0xfeuL;

    /* Errata e3247, must write FRZ to all CAN devices. How do I know
     * what ones to disable?
     * */
    CAN_0.MCR.B.FRZ = 1u;
    CAN_1.MCR.B.FRZ = 1u;
    CAN_2.MCR.B.FRZ = 1u;
    CAN_0.MCR.B.MDIS = 1u;
    CAN_1.MCR.B.MDIS = 1u;
    CAN_2.MCR.B.MDIS = 1u;

     Mcu_Arc_SwitchMode(MODE_STANDBY);
    /* From "MC_ME Mode Diagram", page 136 in RM,  it seems as e return to DRUN after exit of STANDBY0 */	

#elif defined(CFG_MPC5645S)
    RGM.STDBY.B.BOOT_FROM_BKP_RAM = 1u;
    ME.MER.B.STANDBY = 1u;
	
    /* PD0 is always on and that holds first 8K of SRAM */
    PCU.PCONF[2].B.STBY0 = 1;       /* Enable 32K RAM in stdby */

    /* Turn off ALL ME_PCTL
     * All ME_PCTL point to LP config ME_LP_PC0 (LP_CFG=0)
     */
    ME.LPPC[0].R = 0uL;       /* Freeze peripherals */
    ME.RUNPC[0].R = 0xfeuL;
    ME.RUNPC[1].R = 0xfeuL;


    /* Errata e3247, must write FRZ to all CAN devices. How do I know
     * what ones to disable?
     * */
    CAN_0.MCR.B.FRZ = 1u;
    CAN_1.MCR.B.FRZ = 1u;
    CAN_2.MCR.B.FRZ = 1u;
    CAN_0.MCR.B.MDIS = 1u;
    CAN_1.MCR.B.MDIS = 1u;
    CAN_2.MCR.B.MDIS = 1u;

     Mcu_Arc_SwitchMode(MODE_STANDBY);
    /* From "MC_ME Mode Diagram", page 136 in RM,  it seems as e return to DRUN after exit of STANDBY0 */
	
#else
#error enterStandby(): Not supported processor !!!
#endif
    
}
/***** END OF CFG_MCU_ARC_LP ****/
#endif


void Mcu_Arc_InitClockPre( const Mcu_ClockSettingConfigType *clockSettingsPtr )
{
#if defined(CFG_MPC5646B)
    uint32 extal = 0uL;
    uint32 vcoFreq = 0uL;
    uint32 inputVCO = 0uL;
    uint32 val = ME.RUN[0].R;		

    /* pll1 - IDF,  pll2 - NDIV , pll3 - odf */
    // IDF should be <0;15> according to user manual
    CONFIG_ASSERT(clockSettingsPtr->Pll1 <= 15);
    // NDIV should be <32;96> according to user manual
    CONFIG_ASSERT((clockSettingsPtr->Pll2 >=32) && (clockSettingsPtr->Pll2 <= 96));
    // ODF should be <0;3> according to user manual
    CONFIG_ASSERT(clockSettingsPtr->Pll3 <= 3);

    // Get XTAL from configuration [MHz]
    extal = clockSettingsPtr->McuClockReferencePointFrequency;

    // VCO oscilator should to run between 256-512 MHz
    /* Fvco = (extal * NDIV) / (IDF+1) */
    vcoFreq = ((extal * clockSettingsPtr->Pll2) / (clockSettingsPtr->Pll1 + 1));
    CONFIG_ASSERT(vcoFreq >= 256000000 && vcoFreq <= 512000000);	
    
    // VCO input clock checking 4-16MHz
    inputVCO = extal / (clockSettingsPtr->Pll1 + 1);
    CONFIG_ASSERT(inputVCO >= 4000000 && inputVCO <=16000000); 

    // check crystal should be between 4-40MHz
    CONFIG_ASSERT(extal >= 4000000 && extal <=40000000); 

    // Write pll parameters.
    CGM.FMPLL_CR.B.IDF = clockSettingsPtr->Pll1;
    CGM.FMPLL_CR.B.NDIV = clockSettingsPtr->Pll2;
    CGM.FMPLL_CR.B.ODF = clockSettingsPtr->Pll3;
    /* behavior should be tested -> progressive PLL switching. 
    It should have better behavior on Power ON peak & VCO */
    CGM.FMPLL_CR.B.EN_PLL_SW = 0u;		
   // while(!CGM.FMPLL_CR.B.S_LOCK)
        {
            /* just waste a time ... it should to be stabilized within 200us
            for 120MHz system clk 
            the loop without instructions should to execute max. 24000 times 
           
            CGM.FMPLL_CR.B.I_LOCK = 1u;
            CGM.FMPLL_CR.B.IDF = clockSettingsPtr->Pll1;
            CGM.FMPLL_CR.B.NDIV = clockSettingsPtr->Pll2;
            CGM.FMPLL_CR.B.ODF = clockSettingsPtr->Pll3;   */
        }
    // write 1 to clear
    CGM.FMPLL_CR.B.I_LOCK = 1u;		

    val |= 0x04uL; /* SysClk = system FMPLL */
    val |= 0x20uL; /* XOSC on */
    val |= 0x40uL; /* PLL0 on */
    val |= 0x30000uL;  /* CFLAON=3 Normal mode */
    val |= 0xC0000uL;  /* DFLAON=3 Normal mode */	
    ME.RUN[0].R = val;
    ME.RUN[1].R = val;
    ME.RUN[2].R = val;

    ME.DRUN.R = val;

    /* Peri. Cfg. 1 settings: only run in RUN0 mode */
    ME.RUNPC[1].R = 0x00000010uL;

    /* MPC56xxB/S: select ME.RUNPC[1] */
    ME.PCTL[32].R = 0x01uL; //ADC0 control
    ME.PCTL[33].R = 0x01uL; //ADC1 control

    ME.PCTL[60].R = 0x01uL; // CAN sampler control

    ME.PCTL[104].R = 0x01uL; //CMU control

    ME.PCTL[57].R = 0x01uL; // CTU control

    ME.PCTL[23].R = 0x01uL; //DMA_MUX control

    ME.PCTL[4].R = 0x01uL; //DSPI0 control
    ME.PCTL[5].R = 0x01uL; //DSPI1 control
    ME.PCTL[6].R = 0x01uL; //DSPI2 control
    ME.PCTL[7].R = 0x01uL; //DSPI3 control
    ME.PCTL[8].R = 0x01uL; //DSPI4 control
    ME.PCTL[9].R = 0x01uL; //DSPI5 control
    ME.PCTL[10].R = 0x01uL; //DSPI6 control
    ME.PCTL[11].R = 0x01uL; //DSPI7 control

    ME.PCTL[72].R = 0x01uL; //emios0 control
    ME.PCTL[73].R = 0x01uL; //emios1 control
    
    ME.PCTL[16].R = 0x01uL; //FlexCAN0 control
    ME.PCTL[17].R = 0x01uL; //FlexCAN1 control
    ME.PCTL[18].R = 0x01uL; //FlexCAN2 control
    ME.PCTL[19].R = 0x01uL; //FlexCAN3 control
    ME.PCTL[20].R = 0x01uL; //FlexCAN4 control
    ME.PCTL[21].R = 0x01uL; //FlexCAN5 control

    ME.PCTL[44].R = 0x01uL; // I2C control

    ME.PCTL[48].R = 0x01uL; /* LINFlex 0 */
    ME.PCTL[49].R = 0x01uL; /* LINFlex 1 */
    ME.PCTL[50].R = 0x01uL; /* LINFlex 2 */
    ME.PCTL[51].R = 0x01uL; /* LINFlex 3 */
    ME.PCTL[52].R = 0x01uL; /* LINFlex 4 */
    ME.PCTL[53].R = 0x01uL; /* LINFlex 5 */
    ME.PCTL[54].R = 0x01uL; /* LINFlex 6 */
    ME.PCTL[55].R = 0x01uL; /* LINFlex 7 */
    ME.PCTL[12].R = 0x01uL; /* LINFlex 8 */
    ME.PCTL[13].R = 0x01uL; /* LINFlex 9 */
	
    ME.PCTL[92].R = 0x01uL; //PIT_RTI control
    ME.PCTL[91].R = 0x01uL; //RTC control
   	
    ME.PCTL[68].R = 0x01uL; //SIUL control
    ME.PCTL[69].R = 0x01uL; //WKUP control
	
    /* Mode Transition to enter RUN0 mode: */
    /* Enter RUN0 Mode & Key */
    ME.MCTL.R = 0x40005AF0uL;
    /* Enter RUN0 Mode & Inverted Key */
    ME.MCTL.R = 0x4000A50FuL;

    /* Wait for mode transition to complete */
    while (ME.GS.B.S_MTRANS) {}
    /* Verify RUN0 is the current mode */
    while(ME.GS.B.S_CURRENTMODE != 4u) {}
    /*************** MPC5646B ***********************/	
#endif	
#if defined(CFG_MPC5604B) || defined(CFG_MPC5606B) || defined(CFG_SPC560B54)
    // Write pll parameters.
    CGM.FMPLL_CR.B.IDF = clockSettingsPtr->Pll1;
    CGM.FMPLL_CR.B.NDIV = clockSettingsPtr->Pll2;
    CGM.FMPLL_CR.B.ODF = clockSettingsPtr->Pll3;

    /* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL0 */
    ME.RUN[0].R = 0x001F0074uL;
    /* Peri. Cfg. 1 settings: only run in RUN0 mode */
    ME.RUNPC[1].R = 0x00000010uL;
    /* MPC56xxB/S: select ME.RUNPC[1] */
    ME.PCTL[69].R = 0x01;  //WKUP
    ME.PCTL[68].R = 0x01u; //SIUL control
    ME.PCTL[91].R = 0x01u; //RTC/API control
    ME.PCTL[92].R = 0x01u; //PIT_RTI control
    ME.PCTL[72].R = 0x01u; //eMIOS0 control
    ME.PCTL[73].R = 0x01u; //eMIOS1 control
    ME.PCTL[16].R = 0x01u; //FlexCAN0 control
    ME.PCTL[17].R = 0x01u; //FlexCAN1 control
    ME.PCTL[18].R = 0x01u; //FlexCAN2 control
    ME.PCTL[19].R = 0x01u; //FlexCAN3 control
    ME.PCTL[20].R = 0x01u; //FlexCAN4 control
    ME.PCTL[21].R = 0x01u; //FlexCAN5 control
    ME.PCTL[4].R = 0x01u;  /* MPC56xxB/P/S DSPI0  */
    ME.PCTL[5].R = 0x01u;  /* MPC56xxB/P/S DSPI1  */
    ME.PCTL[6].R = 0x01u;  /* MPC56xxB/P/S DSPI2  */
    ME.PCTL[32].R = 0x01u; //ADC0 control
#if defined(CFG_MPC5606B) || defined(CFG_SPC560B54)
    ME.PCTL[33].R = 0x01u; //ADC1 control
#endif
    ME.PCTL[23].R = 0x01u; //DMAMUX control
    ME.PCTL[48].R = 0x01u; /* MPC56xxB/P/S LINFlex 0  */
    ME.PCTL[49].R = 0x01u; /* MPC56xxB/P/S LINFlex 1  */
    ME.PCTL[50].R = 0x01u; /* MPC56xxB/P/S LINFlex 2  */
    ME.PCTL[51].R = 0x01u; /* MPC56xxB/P/S LINFlex 3  */
#if defined(CFG_MPC5606B) || defined(CFG_SPC560B54)
    ME.PCTL[52].R = 0x01u; /* MPC56xxB/P/S LINFlex 4  */
    ME.PCTL[53].R = 0x01u; /* MPC56xxB/P/S LINFlex 5  */
    ME.PCTL[54].R = 0x01u; /* MPC56xxB/P/S LINFlex 6  */
    ME.PCTL[55].R = 0x01u; /* MPC56xxB/P/S LINFlex 7  */
#endif
    /* Mode Transition to enter RUN0 mode: */
    /* Enter RUN0 Mode & Key */
    ME.MCTL.R = 0x40005AF0uL;
    /* Enter RUN0 Mode & Inverted Key */
    ME.MCTL.R = 0x4000A50FuL;

    /* Wait for mode transition to complete */
    while (ME.GS.B.S_MTRANS != 0u) {}
    /* Verify RUN0 is the current mode */
    while(ME.GS.B.S_CURRENTMODE != 4u) {}

    CGM.SC_DC[0].R = 0x80u; /* MPC56xxB/S: Enable peri set 1 sysclk divided by 1 */
    CGM.SC_DC[1].R = 0x80u; /* MPC56xxB/S: Enable peri set 2 sysclk divided by 1 */
    CGM.SC_DC[2].R = 0x80u; /* MPC56xxB/S: Enable peri set 3 sysclk divided by 1 */

#elif defined(CFG_MPC5606S)
    // Write pll parameters.
    CGM.FMPLL[0].CR.B.IDF = clockSettingsPtr->Pll1;
    CGM.FMPLL[0].CR.B.NDIV = clockSettingsPtr->Pll2;
    CGM.FMPLL[0].CR.B.ODF = clockSettingsPtr->Pll3;

    /* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL0 */
    ME.RUN[0].R = 0x001F0074;
    /* Peri. Cfg. 1 settings: only run in RUN0 mode */
    ME.RUNPC[1].R = 0x00000010;
    /* MPC56xxB/S: select ME.RUNPC[1] */
    ME.PCTL[68].R = 0x01; //SIUL control
    ME.PCTL[91].R = 0x01; //RTC/API control
    ME.PCTL[92].R = 0x01; //PIT_RTI control
    ME.PCTL[72].R = 0x01; //eMIOS0 control
    ME.PCTL[73].R = 0x01; //eMIOS1 control
    ME.PCTL[16].R = 0x01; //FlexCAN0 control
    ME.PCTL[17].R = 0x01; //FlexCAN1 control
    ME.PCTL[4].R = 0x01;  /* MPC56xxB/P/S DSPI0  */
    ME.PCTL[5].R = 0x01;  /* MPC56xxB/P/S DSPI1:  */
    ME.PCTL[32].R = 0x01; //ADC0 control
    ME.PCTL[23].R = 0x01; //DMAMUX control
    ME.PCTL[48].R = 0x01; /* MPC56xxB/P/S LINFlex  */
    ME.PCTL[49].R = 0x01; /* MPC56xxB/P/S LINFlex  */
    /* Mode Transition to enter RUN0 mode: */
    /* Enter RUN0 Mode & Key */
    ME.MCTL.R = 0x40005AF0;
    /* Enter RUN0 Mode & Inverted Key */
    ME.MCTL.R = 0x4000A50F;

    /* Wait for mode transition to complete */
    while (ME.GS.B.S_MTRANS) {}
    /* Verify RUN0 is the current mode */
    while(ME.GS.B.S_CURRENTMODE != 4) {}

    CGM.SC_DC[0].R = 0x80; /* MPC56xxB/S: Enable peri set 1 sysclk divided by 1 */
    CGM.SC_DC[1].R = 0x80; /* MPC56xxB/S: Enable peri set 2 sysclk divided by 1 */
    CGM.SC_DC[2].R = 0x80; /* MPC56xxB/S: Enable peri set 3 sysclk divided by 1 */

#elif defined(CFG_MPC5604P)
    // Write pll parameters.
    CGM.FMPLL[0].CR.B.IDF = clockSettingsPtr->Pll1;
    CGM.FMPLL[0].CR.B.NDIV = clockSettingsPtr->Pll2;
    CGM.FMPLL[0].CR.B.ODF = clockSettingsPtr->Pll3;
    // PLL1 must be higher than 120MHz for PWM to work */
    CGM.FMPLL[1].CR.B.IDF = clockSettingsPtr->Pll1_1;
    CGM.FMPLL[1].CR.B.NDIV = clockSettingsPtr->Pll2_1;
    CGM.FMPLL[1].CR.B.ODF = clockSettingsPtr->Pll3_1;

    /* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON, PLL1ON,syclk=PLL0 */
      ME.RUN[0].R = 0x001F00F4;
    /* Peri. Cfg. 1 settings: only run in RUN0 mode */
    ME.RUNPC[1].R = 0x00000010;

    /* MPC56xxB/S: select ME.RUNPC[1] */
    ME.PCTL[68].R = 0x01; //SIUL control
    ME.PCTL[92].R = 0x01; //PIT_RTI control
    ME.PCTL[41].R = 0x01; //flexpwm0 control
    ME.PCTL[16].R = 0x01; //FlexCAN0 control
    ME.PCTL[26].R = 0x01; //FlexCAN1(SafetyPort) control
    ME.PCTL[4].R = 0x01;  /* MPC56xxB/P/S DSPI0  */
    ME.PCTL[5].R = 0x01;  /* MPC56xxB/P/S DSPI1:  */
    ME.PCTL[6].R = 0x01;  /* MPC56xxB/P/S DSPI2  */
    ME.PCTL[7].R = 0x01;  /* MPC56xxB/P/S DSPI3:  */
    ME.PCTL[32].R = 0x01; //ADC0 control
    ME.PCTL[33].R = 0x01; //ADC1 control
    ME.PCTL[48].R = 0x01; /* MPC56xxB/P/S LINFlex  */
    ME.PCTL[49].R = 0x01; /* MPC56xxB/P/S LINFlex  */
    /* Mode Transition to enter RUN0 mode: */
    /* Enter RUN0 Mode & Key */
    ME.MCTL.R = 0x40005AF0;
    /* Enter RUN0 Mode & Inverted Key */
    ME.MCTL.R = 0x4000A50F;

    /* Wait for mode transition to complete */
    while (ME.GS.B.S_MTRANS) {}
    /* Verify RUN0 is the current mode */
    while(ME.GS.B.S_CURRENTMODE != 4) {}

    /* Pwm, adc, etimer clock */
    CGM.AC0SC.R = 0x05000000uL;  /* MPC56xxP: Select FMPLL1 for aux clk 0  */
    CGM.AC0DC.R = 0x80000000uL;  /* MPC56xxP: Enable aux clk 0 div by 1 */

    /* Safety port clock */
    CGM.AC2SC.R = 0x04000000uL;  /* MPC56xxP: Select FMPLL0 for aux clk 2  */
    CGM.AC2DC.R = 0x80000000uL;  /* MPC56xxP: Enable aux clk 2 div by 1 */
#elif defined(CFG_MPC5643L) || defined(CFG_SPC56XL70)

    /* For some reason we are in SAFE mode from start
     * -> Need to go through DRUN to get to RUN 0
     * */
    uint32 runPC = ME_RUN_PC1;
    uint32 mode = MODE_DRUN;

    /* pll1 - IDF,  pll2 - NDIV , pll3 - odf */
   CONFIG_ASSERT(clockSettingsPtr->Pll1 <= 15);
   CONFIG_ASSERT(clockSettingsPtr->Pll2 >=32 && clockSettingsPtr->Pll2 <= 96);
   CONFIG_ASSERT(clockSettingsPtr->Pll3 <= 3);

   uint32  extal = clockSettingsPtr->McuClockReferencePointFrequency;

   PLLD0.CR.B.NDIV = clockSettingsPtr->Pll2;
   PLLD0.CR.B.IDF = clockSettingsPtr->Pll1;
   PLLD0.CR.B.ODF = clockSettingsPtr->Pll3;
   PLLD0.CR.B.EN_PLL_SW = 1;                    /* Enable progressive clock switching */

   /* Fvco = CLKIN * NDIV / IDF */
#if 0
   /* Specification ambigous, vcoFreq not currently used */
   uint32 vcoFreq = extal * clockSettingsPtr->Pll2 / (clockSettingsPtr->Pll1+1);
   CONFIG_ASSERT(vcoFreq >= 256000000 && vcoFreq <= 512000000);
#endif

   /* Calulation
    * phi = xosc * ldf / (idf * odf )
    *
    */
   uint32 sysFreq = ( (extal)*(clockSettingsPtr->Pll2) / ((clockSettingsPtr->Pll1+1)*(2<<(clockSettingsPtr->Pll3))) );
   CONFIG_ASSERT(sysFreq <= 120000000);


#if defined(CFG_MPC5643L)
   ME.RUN0_MC.R = 0x1f0074; /* SysClk = system FMPLL, IRCOSCON = 1, XOSCON = 1, PLL0ON = 1, PLL1ON = 0, FLAON = normal mode, MVRON = 1 */
#else
   uint32 val = ME.RUN0_MC.R;

   ME.RUN0_MC.R = ( val |= 0x30000);     /* FLAON=3 Normal mode */
   ME.RUN0_MC.R = ( val |= 0x20); /* XOSC on */
   ME.RUN0_MC.R = ( val |= 0x40); /* PLL0 on */
   ME.RUN0_MC.R = ( val |= 0x04); /* SysClk = 4; */
#endif
   /* Enable RUN0 mode in Peri config 1 */
   ME.RUN_PC1.R = 0x00000010;

   // setup clock source to xosc for PLL0
   CGM.AC3_SC.B.SELCTL = 1;

   /* Setup sources for aux clocks */
   CGM.AC0_SC.B.SELCTL = 4; // use system FMPLL as source for Aux clock 0 (motor control clock, SWG clock)
#if 0
   CGM.AC1_SC.B.SELCTL = 4; // use system FMPLL as source for Aux clock 1 (Flexray clock)
#endif
   CGM.AC2_SC.B.SELCTL = 4; // use system FMPLL as source for Aux clock 2 (FlexCAN clock)

   runPC = ME_RUN_PC1;
   mode = MODE_RUN0;

   ME.PCTL[92].R = runPC; //PIT_RTI control

   ME.PCTL[4].R = runPC; //Dspi0 control
   ME.PCTL[5].R = runPC; //Dspi1 control
   ME.PCTL[6].R = runPC; //Dspi2 control

   ME.PCTL[16].R = runPC; //FlexCAN0 control
   ME.PCTL[17].R = runPC; //FlexCAN1 control
#if defined(CFG_SPC56XL70)
   ME.PCTL[18].R = runPC; //FlexCAN2 control
#endif
   ME.PCTL[32].R = 0x01; //ADC0 control
   ME.PCTL[33].R = 0x01; //ADC1 control
   ME.PCTL[41].R = 0x01; //FlexPWM0 control
   ME.PCTL[42].R = 0x01; //FlexPWM1 control
   ME.PCTL[48].R = 0x01; //LINFlex0 control
   ME.PCTL[49].R = 0x01; //LINFlex1 control

   Mcu_Arc_SwitchMode(mode);
   
/*************** MPC5643L ********************/   
#endif

#if defined(CFG_MPC5645S)
   uint8 runPC = ME_RUN_PC1;
   uint32 mode = MODE_DRUN;

   /* pll1 - IDF,  pll2 - NDIV , pll3 - odf */
     CONFIG_ASSERT(clockSettingsPtr->Pll1 <= 15);
     CONFIG_ASSERT((clockSettingsPtr->Pll2 >=32) && (clockSettingsPtr->Pll2 <= 96));
     CONFIG_ASSERT(clockSettingsPtr->Pll3 <= 3);

#if 0
     uint32  extal = clockSettingsPtr->McuClockReferencePointFrequency;

      /* Specification ambigous, vcoFreq not currently used */
      /* Fvco = CLKIN * NDIV / IDF */
      uint32 vcoFreq = extal * clockSettingsPtr->Pll2 / clockSettingsPtr->Pll1;
      CONFIG_ASSERT(vcoFreq >= 256000000 && vcoFreq <= 512000000);
#endif
      // Write pll parameters.
      CGM.FMPLL[0].CR.B.IDF = clockSettingsPtr->Pll1;
      CGM.FMPLL[0].CR.B.NDIV = clockSettingsPtr->Pll2;
      CGM.FMPLL[0].CR.B.ODF = clockSettingsPtr->Pll3;


      /* Turn of things for RUN0 mode */
      /*lint -e{970,24,40,10,63,446,1058,1514,9018) Seems lint can't handle typeof */
      const typeof(ME.RUN[0]) val = {
              .B.PDO=1u,
              .B.MVRON=1u,
              .B.FLAON=3u,
              .B.FXOSCON=1u,
              .B.FMPLL0ON=1u,
              .B.FIRCON=1u,
              .B.SYSCLK=4u      /* System FMPLL as clock */
      };

      /*lint -e{10,40) Seems lint can't handle typeof */
      ME.RUN[0].R = val.R;

      /* Enable RUN0 mode in Peri config 1 */
      /*lint -e{10,40) Seems lint can't handle typeof */
      ME.RUNPC[1].R = 0x00000010;

      runPC = ME_RUN_PC1;
      mode = MODE_RUN0;

      ME.PCTL[16].R = runPC; //FlexCAN0 control
      ME.PCTL[17].R = runPC; //FlexCAN1 control
      ME.PCTL[18].R = runPC; //FlexCAN2 control

      ME.PCTL[23].R = runPC; //DMA-CH MUX
      ME.PCTL[32].R = runPC; //ADC0 control

      ME.PCTL[48].R = runPC; //LINFlex0 control
      ME.PCTL[49].R = runPC; //LINFlex1 control
      ME.PCTL[50].R = runPC; //LINFlex2 control
      ME.PCTL[51].R = runPC; //LINFlex3 control

      ME.PCTL[5].R = runPC;  // DSPI1 Control
      ME.PCTL[66].R = runPC; // CFLASH0 Control
      ME.PCTL[68].R = runPC; // SIUL control

      ME.PCTL[72].R = runPC; // eMIOS0
      ME.PCTL[73].R = runPC; // eMIOS1

      ME.PCTL[91].R = runPC; //RTC
      ME.PCTL[92].R = runPC; //PIT_RTI control


     Mcu_Arc_SwitchMode(mode);
	 
/*************** MPC5645S ********************/
#endif
     /*lint -e{920} General interface, the clockSettingsPtr may be needed for other architectures */
    (void)clockSettingsPtr; // get rid of compiler warning

}


/*******************************************************************
Supported Processors: MPC5643L, SPC56XL70, MPC5645S
********************************************************************/
void Mcu_Arc_InitClockPost( const Mcu_ClockSettingConfigType *clockSettingsPtr )
{

#if defined(CFG_MPC5643L) || defined(CFG_SPC56XL70)
    uint32 sysFreq = Mcu_Arc_GetSystemClock();

    //Setup perihperal set 0 clock
    typeof(CGM.SC_DC0.B) sc0Dc2 = {
        .DE = 1u,
        .DIV = (sysFreq + 120000000 - 1) / 120000000 - 1, // max 120MHz
    };
    CGM.SC_DC0.B = sc0Dc2; // register can only be accessed through full register write

#   if defined(USE_PWM)
    // setup MOTC clock
    typeof(CGM.AC0_DC0.B) ac0Dc0 = {
        .DE = 1u,
        .DIV = (sysFreq + 120000000 - 1) / 120000000 - 1, // max 120MHz
    };
    CGM.AC0_DC0.B = ac0Dc0; // register can only be accessed through full register write
    /**** END OF PWM ***/
#   endif

#   if defined(USE_CAN)
    // setup FlexCAN clock
    typeof(CGM.AC2_DC0.B) ac2Dc0 = {
        .DE = 1u,
        .DIV = (sysFreq + 60000000 - 1) / 60000000 - 1, // max 60MHz
    };
    CGM.AC2_DC0.B = ac2Dc0; // register can only be accessed through full register write
    /**** END OF CAN ***/
#   endif
    /**** END OF MPC5643L || SPC56XL70  ****/
#endif

#if defined(CFG_MPC5645S)
#   if defined(USE_PWM)
    // setup Aux clock 1 (Emios1)
    /*lint -e{970} Lint can't handle typeof */
    typeof(CGM.AC1_DC.B) ac1Dc0 = {
        .DE0 = 1u,
        .DIV0 = 0u,
    };
    CGM.AC1_DC.B = ac1Dc0; // register can only be accessed through full register write
    CGM.AC1_SC.B.SELCTL = 3u; // use system FMPLL/2 as source for Aux clock 1

    // setup Aux clock 1 (Emios2)
    /*lint -e{970} Lint can't handle typeof */
    typeof(CGM.AC2_DC.B) ac2Dc = {
        .DE0 = 1u,
        .DIV0 = 0u,
    };
    CGM.AC2_DC.B = ac2Dc; // register can only be accessed through full register write
    CGM.AC2_SC.B.SELCTL = 3; // use system FMPLL/2 as source for Aux clock 2
    /**** END OF PWM ***/
#   endif
    /**** END OF MPC5645S ***/
#endif
    /*lint -e{920} General interface, the clockSettingsPtr may be needed for other architectures */
    (void)clockSettingsPtr;
}


/*****************************************************************
****   LOW POWER MODE SECTION ****
In Linker file needs to be defined following sections:
__LP_TEXT_ROM >>> Start ADDRESS FLASH FROM where will be copied Low power recovery routine
__LP_TEXT_START >>> Start ADDRESS of RAM area where will be copied Low Powere recovery routine
__LP_TEXT_END >>> END ADDRESS of RAM area where will be copied Low Powere recovery routine
*****************************************************************/
#if defined(CFG_MCU_ARC_LP)

/*lint -esym(9003, __LP_TEXT_ROM, __LP_TEXT_START, __LP_TEXT_END, context) Needs to be global */
extern sint8 __LP_TEXT_ROM[];
extern sint8 __LP_TEXT_START[];
extern sint8 __LP_TEXT_END[];

//lint -e9019  MISRA 2012 20.1 (adv)   Allow #include here after declarations to increase readability

/* Context save area */
#define MCU_LP_START_SEC_CLEARED_8
#include "MemMap.h"
#if defined(CFG_MPC5645S)
/* All GPR + work registers + TLB Settings */
#define CONTEXT_SIZE      ((32+5+3*16)*4)
#else
/* All GPR + work registers */
#define CONTEXT_SIZE      ((32+5)*4)
#endif
//lint -esym(9003, Mcu_Arc_LP_Context)   Needs to be at global scope, used by assembly language
uint8 Mcu_Arc_LP_Context[CONTEXT_SIZE];
#define MCU_LP_STOP_SEC_CLEARED_8
#include "MemMap.h"


void Mcu_Arc_SetModePre(Mcu_ModeType mcuMode) {

    Mcu_ModeType localMcuMode = mcuMode; /* Variable needed for MISRA compliance */

#if defined(CFG_ECUM_VIRTUAL_SOURCES)
    EcuM_WakeupSourceType pendWakeup;
#endif

    if (localMcuMode == McuConf_McuModeSettingConf_NORMAL) {
        localMcuMode = McuConf_McuModeSettingConf_RUN;
    }

    if (McuConf_McuModeSettingConf_SLEEP == localMcuMode) {

    /**** Improvement: Check SIZE of RAM/FLASH if there is enough space 
    Check if ADDRESSES RAM/FLASH are valid  
    Otherway stop compilation 
    #error Mcu_Arc_SetModePre() Check size and addresses of RAM/FLASH !!! 
    ****/
		
        /* Copy LP recovery routines to RAM */
        memcpy(__LP_TEXT_START, __LP_TEXT_ROM, __LP_TEXT_END - __LP_TEXT_START); /*lint !e946 !e947 !e732 Simpler than alternative */

        /* Go to sleep */
        if (Mcu_Arc_setjmp(Mcu_Arc_LP_Context) == 0) {
            enterStandby();
        }

        /* Back from sleep!
         * Now running in DRUN and on FIRC (16Mhz)
         */

        /* Wdg OFF */
        SWT.SR.R = 0x0000c520UL; /* Write keys to clear soft lock bit */
        SWT.SR.R = 0x0000d928UL;
        SWT.CR.R = 0x8000010AUL;

#if defined(USE_ECUM_FIXED) || defined(USE_ECUM_FLEXIBLE)
        EcuM_CheckWakeup( 0x3fffffffUL );
#endif


        /* Setup exceptions and INTC again */
        Os_IsrInit();

    } /* MCU_MODE_SLEEP == localMcuMode */


}

void Mcu_Arc_SetModePost( Mcu_ModeType mcuMode)
{
    (void)mcuMode;
}
#endif






