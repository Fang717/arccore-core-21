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


#ifndef IFX_SSW_H_
#define IFX_SSW_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Ifx_Ssw_Compilers.h"
#include "Ifx_Ssw_LegacySwCfg.h"

/******************************************************************************/
/*                          Macros                                            */
/******************************************************************************/

#ifndef IFX_CFG_SSW_ENABLE_TRICORE0
#define IFX_CFG_SSW_ENABLE_TRICORE0 (1)
#endif

#ifndef IFX_CFG_SSW_ENABLE_TRICORE1
/*
 * Disable Core 1
 * #define IFX_CFG_SSW_ENABLE_TRICORE1 (1)
 */
#define IFX_CFG_SSW_ENABLE_TRICORE1 (0)
#endif

#ifndef IFX_CFG_SSW_ENABLE_TRICORE2
/*
 * Disable Core 2
 * #define IFX_CFG_SSW_ENABLE_TRICORE2 (1)
 */
#define IFX_CFG_SSW_ENABLE_TRICORE2 (0)
#endif

#ifndef IFX_CFG_SSW_ENABLE_TRICORE3
/*
 * Disable Core 3
 * #define IFX_CFG_SSW_ENABLE_TRICORE3 (1)
 */
#define IFX_CFG_SSW_ENABLE_TRICORE3 (0)
#endif

#ifndef IFX_CFG_SSW_ENABLE_TRICORE4
/*
 * Disable Core 4
 * #define IFX_CFG_SSW_ENABLE_TRICORE4 (1)
 */
#define IFX_CFG_SSW_ENABLE_TRICORE4 (0)
#endif

#ifndef IFX_CFG_SSW_ENABLE_TRICORE5
/*
 * Disable Core 5
 * #define IFX_CFG_SSW_ENABLE_TRICORE5 (1)
 */
#define IFX_CFG_SSW_ENABLE_TRICORE5 (0)
#endif

#ifndef IFX_CFG_SSW_PSW_DEFAULT
#define IFX_CFG_SSW_PSW_DEFAULT     (0x00000980u)
#endif

/******************************************************************************/
/*                          Typedefs                                          */
/******************************************************************************/

/** \brief Structure definition for the BMHD\n
 *
 */
typedef struct
{
	unsigned short bmi;				/**< \brief 0x000: Boot Mode Index (BMI)*/
	unsigned short bmhdid;			/**< \brief 0x002: Boot Mode Header ID (CODE) = B359H*/
	unsigned int   stad;			/**< \brief 0x004: User Code start address*/
	unsigned int   crc;				/**< \brief 0x008: Check Result for the BMI Header (offset 000H - 007H)*/
	unsigned int   crcInv;			/**< \brief 0x00C: Inverted Check Result for the BMI Header (offset 000H - 007H)*/
	unsigned int   reserved[120];	/**< \brief 0x010: Reserved area (120 bytes) till the offset 0x1F0*/
	unsigned int   confirmation;	/**< \brief 0x1F0: 32-bit CODE, (always same)*/
} Ifx_Ssw_Bmhd;

typedef unsigned char (*Ifx_Ssw_CalloutJumpFunctionType)(void);
typedef void (*Ifx_Ssw_CalloutJumpErrorFunctionType)(void);
typedef unsigned char (*Ifx_Ssw_CalloutFunctionType)(void);
typedef void (*Ifx_Ssw_CalloutErrorFunctionType)(void);

typedef struct
{
	Ifx_Ssw_CalloutJumpFunctionType      initPmsCalloutJump;
	Ifx_Ssw_CalloutJumpFunctionType      pmsInitCheckCallOutJump;
	Ifx_Ssw_CalloutJumpErrorFunctionType pmsInitErrorCallOutJump;
}Ifx_Ssw_PmsCalloutConfig;


typedef struct
{
	Ifx_Ssw_CalloutJumpFunctionType      handleLbistCalloutJump;
	Ifx_Ssw_CalloutJumpErrorFunctionType lbistErrorCallOutJump;
}Ifx_Ssw_LbistCalloutConfig;

typedef struct
{
	Ifx_Ssw_CalloutJumpFunctionType      handleMbistAtSswPhase2CalloutJump;
	Ifx_Ssw_CalloutJumpErrorFunctionType mbistErrorCallOutJump;
	Ifx_Ssw_CalloutFunctionType          handleMbistAtSswPhase4Callout;
	Ifx_Ssw_CalloutErrorFunctionType     mbistErrorCallOut;
}Ifx_Ssw_MbistCalloutConfig;

typedef struct
{
	Ifx_Ssw_CalloutFunctionType          handleSbstCallOut;
	Ifx_Ssw_CalloutErrorFunctionType     sbstErrorCallOut;
}Ifx_Ssw_SbstCalloutConfig;

typedef struct
{
	Ifx_Ssw_CalloutFunctionType          initClocksCallOut;
	Ifx_Ssw_CalloutErrorFunctionType     clocksInitErrorCallOut;
}Ifx_Ssw_ClocksCalloutConfig;

typedef struct
{
	const Ifx_Ssw_PmsCalloutConfig *pms;
	const Ifx_Ssw_LbistCalloutConfig *lbist;
	const Ifx_Ssw_MbistCalloutConfig *mbist;
	const Ifx_Ssw_SbstCalloutConfig *sbst;
	const Ifx_Ssw_ClocksCalloutConfig *clocks;
}Ifx_Ssw_Callouts;

/******************************************************************************/
/*                         Exported prototypes                                */
/******************************************************************************/
void _Core1_start(void);
void _Core2_start(void);
void _Core3_start(void);
void _Core4_start(void);
void _Core5_start(void);

#endif /* IFX_SSW_H_ */
