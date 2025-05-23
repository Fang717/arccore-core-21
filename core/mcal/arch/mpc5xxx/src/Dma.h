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


/*
 * Freescale uses two flavors for DMA.
 * 1. eDMA
 * 2. eDMA + DMA_MUX
 *
 * 1. eDMA only (MPC5557, etc)
 *   The "DMA Request Assignments" are used and configured in Dma_Cfg.h using Dma_ChannelType.
 *
 * 2. eDMA + DMA_MUX  (MPC551x , MPC5668, etc )
 *   The eDMA + DMA_MUX the "DMA Request Assignments" are just mappings from the DMA_MUX.
 *   The file Dma.h contains the Dma_MuxChannels
 *
 *
 *  eDMA+DMA_MUX
 *    MPC551x
 *    MPC5668
 *    MPC5605B,MPC5606B,MPC5607B,SPC560B54
 *    MPC5645S
 *
 *  eDMA
 *    MPC5567
 *
 *  NO DMA
 *    MPC5604B
 *
 */

#ifndef DMA_H_
#define DMA_H_


#include "Std_Types.h"
#include "Dma_Cfg.h"
#include "mpc55xx.h"

#if defined(CFG_MPC5516) || defined(CFG_MPC5517) || defined(CFG_MPC5606S) || defined(CFG_MPC5668) || \
           defined(CFG_MPC5606B) || defined(CFG_MPC5604P) || defined(CFG_MPC5645S) || defined(CFG_MPC5646B) || defined(CFG_SPC560B54)
#if !defined(CFG_DMA_MUX)
#define CFG_DMA_MUX
#endif
#endif

#if defined(CFG_DMA_MUX)

#if defined(CFG_MPC5606B) || defined(CFG_MPC5607B) || defined(CFG_SPC560B54)
typedef enum
{
  DMA_CHANNEL_DISABLED,

  DMA_DSPI_0_TX,
  DMA_DSPI_0_RX,
  DMA_DSPI_1_TX,
  DMA_DSPI_1_RX,
  DMA_DSPI_2_TX,
  DMA_DSPI_2_RX,
  DMA_DSPI_3_TX,
  DMA_DSPI_3_RX,
  DMA_DSPI_4_TX,
  DMA_DSPI_4_RX,
  DMA_DSPI_5_TX,
  DMA_DSPI_5_RX,                /* 12 */

  DMA_RESERVED1,
  DMA_RESERVED2,
  DMA_RESERVED3,
  DMA_RESERVED4,

  DMA_EMIOS200_0_FLAG_F0,       /* 17 */
  DMA_EMIOS200_0_FLAG_F1,
  DMA_EMIOS200_0_FLAG_F9,
  DMA_EMIOS200_0_FLAG_F18,
  DMA_EMIOS200_0_FLAG_F25,
  DMA_EMIOS200_0_FLAG_F26,

  DMA_EMIOS200_1_FLAG_F0,       /* 23 */
  DMA_EMIOS200_1_FLAG_F9,
  DMA_EMIOS200_1_FLAG_F17,
  DMA_EMIOS200_1_FLAG_F18,
  DMA_EMIOS200_1_FLAG_F25,
  DMA_EMIOS200_1_FLAG_F26,

  DMA_ADC0,                     /* 29 */
  DMA_ADC1,

  DMA_I2C_0_RX,                 /* 31 */
  DMA_I2C_0_TX,

  DMA_LINFLEX_A_RX_FIFO_FILL,   /* 33 */
  DMA_LINFLEX_A_TX_FIFO_FILL,
  DMA_LINFLEX_B_RX_FIFO_FILL,
  DMA_LINFLEX_B_TX_FIFO_FILL,

  DMA_RESERVED37,
  DMA_RESERVED38,
  DMA_RESERVED39,
  DMA_RESERVED40,
  DMA_RESERVED41,
  DMA_RESERVED42,
  DMA_RESERVED43,
  DMA_RESERVED44,
  DMA_RESERVED45,
  DMA_RESERVED46,
  DMA_RESERVED47,
  DMA_RESERVED48,
  DMA_RESERVED49,
  DMA_RESERVED50,
  DMA_RESERVED51,
  DMA_RESERVED52,
  DMA_RESERVED53,
  DMA_RESERVED54,
  DMA_RESERVED55,
  DMA_RESERVED56,
  DMA_RESERVED57,
  DMA_RESERVED58,
  DMA_RESERVED59,

  DMA_ALWAYS_REQUESTORS1,
  DMA_ALWAYS_REQUESTORS2,
  DMA_ALWAYS_REQUESTORS3,
  DMA_ALWAYS_REQUESTORS4,
} Dma_MuxChannels;


#elif defined(CFG_MPC5606S) || (CFG_MPC5604P)
typedef enum
{
  DMA_CHANNEL_DISABLED,

  DMA_DSPI_0_TX,
  DMA_DSPI_0_RX,
  DMA_DSPI_1_TX,
  DMA_DSPI_1_RX,

  DMA_QuadSPI_0_TFFF,
  DMA_QuadSPI_0_RFDF,

  DMA_I2C_0_TX,
  DMA_I2C_0_RX,
  DMA_I2C_1_TX,
  DMA_I2C_1_RX,
  DMA_I2C_2_TX,
  DMA_I2C_2_RX,
  DMA_I2C_3_TX,
  DMA_I2C_3_RX,

  DMA_EMIOS200_0_FLAG_F0,
  DMA_EMIOS200_0_FLAG_F1,
  DMA_EMIOS200_0_FLAG_F2,
  DMA_EMIOS200_0_FLAG_F3,
  DMA_EMIOS200_0_FLAG_F4,
  DMA_EMIOS200_0_FLAG_F5,
  DMA_EMIOS200_0_FLAG_F6,
  DMA_EMIOS200_0_FLAG_F7,
  DMA_EMIOS200_0_FLAG_F8,
  DMA_EMIOS200_0_FLAG_F9,
  DMA_EMIOS200_0_FLAG_F10,
  DMA_EMIOS200_0_FLAG_F11,
  DMA_EMIOS200_0_FLAG_F12,
  DMA_EMIOS200_0_FLAG_F13,
  DMA_EMIOS200_0_FLAG_F14,
  DMA_EMIOS200_0_FLAG_F15,
  DMA_EMIOS200_1_FLAG_F0,
  DMA_EMIOS200_1_FLAG_F1,
  DMA_EMIOS200_1_FLAG_F2,
  DMA_EMIOS200_1_FLAG_F3,
  DMA_EMIOS200_1_FLAG_F4,
  DMA_EMIOS200_1_FLAG_F5,
  DMA_EMIOS200_1_FLAG_F6,
  DMA_EMIOS200_1_FLAG_F7,

  DMA_RESERVED1,
  DMA_RESERVED2,
  DMA_RESERVED3,
  DMA_RESERVED4,
  DMA_RESERVED5,
  DMA_RESERVED6,
  DMA_RESERVED7,
  DMA_RESERVED8,

  DMA_SIU_EISR_E1F1,
  DMA_SIU_EISR_E1F2,
  DMA_SIU_EISR_E1F3,
  DMA_SIU_EISR_E1F4,

  DMA_ADC,

  DMA_RESERVED9,

  DMA_DCU,

  DMA_RESERVED10,
  DMA_RESERVED11,

  DMA_ALWAYS_REQUESTORS1,
  DMA_ALWAYS_REQUESTORS2,
  DMA_ALWAYS_REQUESTORS3,
  DMA_ALWAYS_REQUESTORS4,
  DMA_ALWAYS_REQUESTORS5,
  DMA_ALWAYS_REQUESTORS6,
  DMA_ALWAYS_REQUESTORS7,
  DMA_ALWAYS_REQUESTORS8
}Dma_MuxChannels;

#elif defined(CFG_MPC5645S)

typedef enum
{
  DMA_CHANNEL_DISABLED,

  DMA_DSPI_0_TX,
  DMA_DSPI_0_RX,
  DMA_DSPI_1_TX,
  DMA_DSPI_1_RX,
  DMA_DSPI_2_TX,
  DMA_DSPI_2_RX,            /* 6 */

  DMA_I2C_0_TX,
  DMA_I2C_0_RX,
  DMA_I2C_1_TX,
  DMA_I2C_1_RX,
  DMA_I2C_2_TX,
  DMA_I2C_2_RX,
  DMA_I2C_3_TX,
  DMA_I2C_3_RX,             /* 14 */

  DMA_EMIOS200_0_FLAG_F9,
  DMA_EMIOS200_0_FLAG_F11,
  DMA_EMIOS200_0_FLAG_F13,
  DMA_EMIOS200_0_FLAG_F15,
  DMA_EMIOS200_0_FLAG_F17,
  DMA_EMIOS200_0_FLAG_F19,
  DMA_EMIOS200_0_FLAG_F21,  /* 21 */

  DMA_EMIOS200_1_FLAG_F9,   /* 22 */
  DMA_EMIOS200_1_FLAG_F11,
  DMA_EMIOS200_1_FLAG_F13,
  DMA_EMIOS200_1_FLAG_F15,
  DMA_EMIOS200_1_FLAG_F17,
  DMA_EMIOS200_1_FLAG_F19,
  DMA_EMIOS200_1_FLAG_F21,  /* 28 */

  DMA_RESERVED1,
  DMA_RESERVED2,

  DMA_LINFLEX_A_RX_FIFO_FILL,   /* 31 */
  DMA_LINFLEX_A_TX_FIFO_FILL,
  DMA_LINFLEX_B_RX_FIFO_FILL,
  DMA_LINFLEX_B_TX_FIFO_FILL,
  DMA_LINFLEX_C_RX_FIFO_FILL,
  DMA_LINFLEX_C_TX_FIFO_FILL,
  DMA_LINFLEX_D_RX_FIFO_FILL,
  DMA_LINFLEX_D_TX_FIFO_FILL,   /* 38 */

  DMA_DRAMC_PRIO_MGR,
  DMA_QUAD_SPI_RX,

  DMA_RESERVED3,
  DMA_RESERVED4,

  DMA_SGM_CH0,                  /* 43 */
  DMA_SGM_CH1,
  DMA_SGM_CH2,
  DMA_SGM_CH3,

  DMA_RESERVED5,
  DMA_RESERVED6,
  DMA_RESERVED7,
  DMA_RESERVED8,

  DMA_ADC,                  /* 51 */

  DMA_RESERVED9,

  DMA_TLE_TX_FIFO,          /* 53 */
  DMA_TLE_RX_FIFO,

  DMA_RESERVED10,
  DMA_RESERVED11,

  DMA_ALWAYS_REQUESTORS1,   /* 56 */
  DMA_ALWAYS_REQUESTORS2,
  DMA_ALWAYS_REQUESTORS3,
  DMA_ALWAYS_REQUESTORS4,
  DMA_ALWAYS_REQUESTORS5,
  DMA_ALWAYS_REQUESTORS6,
  DMA_ALWAYS_REQUESTORS7,
  DMA_ALWAYS_REQUESTORS8
}Dma_MuxChannels;


#elif defined(CFG_MPC5646B)

typedef enum
{
  DMA_CHANNEL_DISABLED,

  DMA_DSPI_0_TX,
  DMA_DSPI_0_RX,
  DMA_DSPI_1_TX,
  DMA_DSPI_1_RX,
  DMA_DSPI_2_TX,
  DMA_DSPI_2_RX,            /* 6 */

  DMA_DSPI_3_TX,
  DMA_DSPI_3_RX,
  DMA_DSPI_4_TX,
  DMA_DSPI_4_RX,
  DMA_DSPI_5_TX,
  DMA_DSPI_5_RX,
  DMA_DSPI_6_TX,
  DMA_DSPI_6_RX,
  DMA_DSPI_7_TX,
  DMA_DSPI_7_RX,		/* 16 */

  DMA_EMIOS200_0_FLAG_F0,
  DMA_EMIOS200_0_FLAG_F1,
  DMA_EMIOS200_0_FLAG_F9,
  DMA_EMIOS200_0_FLAG_F18,
  DMA_EMIOS200_0_FLAG_F25,
  DMA_EMIOS200_0_FLAG_F26,  /* 22 */

  DMA_EMIOS200_1_FLAG_F0,   /* 23 */
  DMA_EMIOS200_1_FLAG_F9,
  DMA_EMIOS200_1_FLAG_F17,
  DMA_EMIOS200_1_FLAG_F18,
  DMA_EMIOS200_1_FLAG_F25,
  DMA_EMIOS200_1_FLAG_F26,  

  DMA_ADC_A,
  DMA_ADC_B,

  DMA_I2C_0_RX,
  DMA_I2C_0_TX,				/* 32 */
  
  DMA_LINFLEX_A_RX_FIFO_FILL,   /* 33 */
  DMA_LINFLEX_A_TX_FIFO_FILL,
  DMA_LINFLEX_B_RX_FIFO_FILL,
  DMA_LINFLEX_B_TX_FIFO_FILL,
  DMA_LINFLEX_C_RX_FIFO_FILL,
  DMA_LINFLEX_C_TX_FIFO_FILL,
  DMA_LINFLEX_D_RX_FIFO_FILL,
  DMA_LINFLEX_D_TX_FIFO_FILL,  
  DMA_LINFLEX_E_RX_FIFO_FILL,
  DMA_LINFLEX_E_TX_FIFO_FILL,  
  DMA_LINFLEX_F_RX_FIFO_FILL,
  DMA_LINFLEX_F_TX_FIFO_FILL,
  DMA_LINFLEX_G_RX_FIFO_FILL,
  DMA_LINFLEX_G_TX_FIFO_FILL,
  DMA_LINFLEX_H_RX_FIFO_FILL,
  DMA_LINFLEX_H_TX_FIFO_FILL,
  DMA_LINFLEX_I_RX_FIFO_FILL,
  DMA_LINFLEX_I_TX_FIFO_FILL,
  DMA_LINFLEX_J_RX_FIFO_FILL,
  DMA_LINFLEX_J_TX_FIFO_FILL,
  
  DMA_RESERVED1,				/* 53 */
  DMA_RESERVED2,
  DMA_RESERVED3,
  DMA_RESERVED4,
  DMA_RESERVED5,
  DMA_RESERVED6,
  DMA_RESERVED7,
  
  DMA_ALWAYS_ENABLED_0,  /* 60 */
  DMA_ALWAYS_ENABLED_1,
  DMA_ALWAYS_ENABLED_2,  
  DMA_ALWAYS_ENABLED_3,
  DMA_NUMBER_OF_MUXES
}Dma_MuxChannels;


#elif defined(CFG_MPC5668)

/* Table 22-4. DMA Source Configuration */

typedef enum
{
  DMA_CHANNEL_DISABLED,	/* 0 */
  DMA_CHANNEL_RESERVED,
  DMA_SCI_A_COMBTX,
  DMA_SCI_A_COMBRX,
  DMA_SCI_B_COMBTX,
  DMA_SCI_B_COMBRX,
  DMA_SCI_C_COMBTX,
  DMA_SCI_C_COMBRX,
  DMA_SCI_D_COMBTX,
  DMA_SCI_D_COMBRX,
  DMA_SCI_E_COMBTX,
  DMA_SCI_E_COMBRX,
  DMA_SCI_F_COMBTX,
  DMA_SCI_F_COMBRX,
  DMA_SCI_G_COMBTX,
  DMA_SCI_G_COMBRX,
  DMA_SCI_H_COMBTX,
  DMA_SCI_H_COMBRX,

  DMA_DSPI_A_SR_TFFF,  /* 0x12 */
  DMA_DSPI_A_SR_RFRD,
  DMA_DSPI_B_SR_TFFF,
  DMA_DSPI_B_SR_RFRD,
  DMA_DSPI_E_SR_TFFF,
  DMA_DSPI_E_SR_RFRD,
  DMA_DSPI_F_SR_TFFF,
  DMA_DSPI_F_SR_RFRD,

  DMA_EMIOS200_FLAG_F0, /* 0x1a */
  DMA_EMIOS200_FLAG_F1,
  DMA_EMIOS200_FLAG_F2,
  DMA_EMIOS200_FLAG_F3,
  DMA_EMIOS200_FLAG_F4,
  DMA_EMIOS200_FLAG_F5,
  DMA_EMIOS200_FLAG_F6,
  DMA_EMIOS200_FLAG_F7,
  DMA_EMIOS200_FLAG_F8,
  DMA_EMIOS200_FLAG_F9,
  DMA_EMIOS200_FLAG_F10,
  DMA_EMIOS200_FLAG_F11,
  DMA_EMIOS200_FLAG_F12,
  DMA_EMIOS200_FLAG_F13,
  DMA_EMIOS200_FLAG_F14,
  DMA_EMIOS200_FLAG_F15,

  DMA_IIC_A_TX,  /* 0x2a */
  DMA_IIC_A_RX,
  DMA_IIC_B_TX,
  DMA_IIC_B_RX,

  DMA_SIU_EISR_EIF0, /* 0x2e */
  DMA_SIU_EISR_EIF1,

  DMA_IIC_C_TX, /* 0x30 */
  DMA_IIC_C_RX,

  DMA_ADC_A,

  DMA_IIC_D_TX, /* 0x33 */
  DMA_IIC_D_RX,

  DMA_SCI_J_COMBTX, /* 0x35 */
  DMA_SCI_J_COMBRX,
  DMA_SCI_K_COMBTX,
  DMA_SCI_K_COMBRX,
  DMA_SCI_L_COMBTX,
  DMA_SCI_L_COMBRX,
  DMA_SCI_M_COMBTX,
  DMA_SCI_M_COMBRX,

  DMA_ALWAYS_ENABLED_0, /* 0x3d */
  DMA_ALWAYS_ENABLED_1,
  DMA_ALWAYS_ENABLED_2,
} Dma_MuxChannels;

#elif  defined(CFG_MPC5516) || defined(CFG_MPC5517)
/* MPC551x "Table 13-4. DMA Source Configuration" */

typedef enum
{
  DMA_CHANNEL_DISABLED,
  DMA_SCI_A_COMBTX,
  DMA_SCI_A_COMBRX,
  DMA_SCI_B_COMBTX,
  DMA_SCI_B_COMBRX,
  DMA_SCI_C_COMBTX,
  DMA_SCI_C_COMBRX,
  DMA_SCI_D_COMBTX,
  DMA_SCI_D_COMBRX,
  DMA_SCI_E_COMBTX,
  DMA_SCI_E_COMBRX,
  DMA_SCI_F_COMBTX,
  DMA_SCI_F_COMBRX,
  DMA_SCI_G_COMBTX,
  DMA_SCI_G_COMBRX,
  DMA_SCI_H_COMBTX,
  DMA_SCI_H_COMBRX,

  DMA_DSPI_A_SR_TFFF,
  DMA_DSPI_A_SR_RFRD,
  DMA_DSPI_B_SR_TFFF,
  DMA_DSPI_B_SR_RFRD,
  DMA_DSPI_C_SR_TFFF,
  DMA_DSPI_C_SR_RFRD,
  DMA_DSPI_D_SR_TFFF,
  DMA_DSPI_D_SR_RFRD,

  DMA_EMIOS200_FLAG_F0,
  DMA_EMIOS200_FLAG_F1,
  DMA_EMIOS200_FLAG_F2,
  DMA_EMIOS200_FLAG_F3,
  DMA_EMIOS200_FLAG_F4,
  DMA_EMIOS200_FLAG_F5,
  DMA_EMIOS200_FLAG_F6,
  DMA_EMIOS200_FLAG_F7,
  DMA_EMIOS200_FLAG_F8,
  DMA_EMIOS200_FLAG_F9,
  DMA_EMIOS200_FLAG_F10,
  DMA_EMIOS200_FLAG_F11,
  DMA_EMIOS200_FLAG_F12,
  DMA_EMIOS200_FLAG_F13,
  DMA_EMIOS200_FLAG_F14,
  DMA_EMIOS200_FLAG_F15,

  DMA_IIC_A_TX,
  DMA_IIC_A_RX,

  DMA_RESERVED1,
  DMA_RESERVED2,

  DMA_SIU_EISR_EIF1,
  DMA_SIU_EISR_EIF2,
  DMA_SIU_EISR_EIF3,
  DMA_SIU_EISR_EIF4,

  DMA_EQADC_FISR0_RFDF0,
  DMA_EQADC_FISR0_CFFF0,
  DMA_EQADC_FISR1_RFDF0,
  DMA_EQADC_FISR1_CFFF0,

  DMA_MLB_DMA_REQ,

  DMA_RESERVED3,
  DMA_RESERVED4,

  DMA_ALWAYS_ENABLED1,
  DMA_ALWAYS_ENABLED2,
  DMA_ALWAYS_ENABLED3,
  DMA_ALWAYS_ENABLED4,
  DMA_ALWAYS_ENABLED5,
  DMA_ALWAYS_ENABLED6,
  DMA_ALWAYS_ENABLED7,
  DMA_ALWAYS_ENABLED8
}Dma_MuxChannels;

#endif
#endif


#if defined(CFG_DMA_MUX)
typedef struct
{
  vuint8_t DMA_CHANNEL_ENABLE;
  vuint8_t DMA_CHANNEL_TRIG_ENABLE;
  Dma_MuxChannels DMA_CHANNEL_SOURCE;
} Dma_MuxConfigType;
#endif

typedef struct
{
  vuint8_t DMA_CHANNEL_PRIORITY;
  vuint8_t DMA_CHANNEL_PREEMTION_ENABLE;
}Dma_ChannelConfigType;

typedef enum
{
  DMA_TRANSFER_SIZE_8BITS,
  DMA_TRANSFER_SIZE_16BITS,
  DMA_TRANSFER_SIZE_32BITS,
  DMA_TRANSFER_SIZE_64BITS,
  DMA_TRANSFER_SIZE_16BYTES_BURST,
  DMA_TRANSFER_SIZE_32BYTES_BURST
}Dma_DataTranferSizeType;

typedef enum
{
  DMA_FIXED_PRIORITY_ARBITRATION,
  DMA_ROUND_ROBIN_ARBITRATION
}Dma_ChannelArbitrationType;

typedef struct
{
  // 5567 has no Dma Mux, but maybe this should be left in anyway?
#if defined(CFG_DMA_MUX)
  const Dma_MuxConfigType          *dmaMuxConfigPtr;
#endif
  const Dma_ChannelConfigType      *dmaChannelConfigPtr;
  const Dma_ChannelArbitrationType  dmaChannelArbitration;
}Dma_ConfigType;

extern const Dma_ConfigType DmaConfig [];


void Dma_Init (const Dma_ConfigType *ConfigPtr);
void Dma_DeInit (void );
#if defined(CFG_MPC5777C)
void Dma_ConfigureChannel (const Dma_TcdType *tcd, Dma_ChannelType channel, uint8_t unitID);
void Dma_ConfigureChannelTranferSize (uint32_t nbrOfIterations, Dma_ChannelType channel, uint8_t unitID);
void Dma_ConfigureChannelSourceCorr (uint32_t sourceCorrection, Dma_ChannelType channel, uint8_t unitID);
void Dma_ConfigureChannelDestinationCorr (uint32_t destinationCorrection, Dma_ChannelType channel, uint8_t unitID);
void Dma_ConfigureDestinationAddress (uint32_t destAddr, Dma_ChannelType channel, uint8_t unitID);
void Dma_ConfigureSourceAddress (uint32_t sourceAddr, Dma_ChannelType channel, uint8_t unitID);
void Dma_StartChannel (Dma_ChannelType channel, uint8_t unitID);
void Dma_StopChannel (Dma_ChannelType channel, uint8_t unitID);
Std_ReturnType Dma_ChannelDone (Dma_ChannelType channel, uint8_t unitID);
volatile Dma_TcdType * Dma_GetTcd( Dma_ChannelType channel, uint8_t unitID);
boolean Dma_CheckConfig(uint8_t unitID);
#else
void Dma_ConfigureChannel (const Dma_TcdType *tcd, Dma_ChannelType channel);
void Dma_ConfigureChannelTranferSize (uint32_t nbrOfIterations, Dma_ChannelType channel);
void Dma_ConfigureChannelSourceCorr (uint32_t sourceCorrection, Dma_ChannelType channel);
void Dma_ConfigureChannelDestinationCorr (uint32_t destinationCorrection, Dma_ChannelType channel);
void Dma_ConfigureDestinationAddress (uint32_t destAddr, Dma_ChannelType channel);
void Dma_ConfigureSourceAddress (uint32_t sourceAddr, Dma_ChannelType channel);
void Dma_StartChannel (Dma_ChannelType channel);
void Dma_StopChannel (Dma_ChannelType channel);
Std_ReturnType Dma_ChannelDone (Dma_ChannelType channel);
volatile Dma_TcdType * Dma_GetTcd( Dma_ChannelType channel );
boolean Dma_CheckConfig( void );
#endif

#endif /* DMA_H_ */
