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

/* Generator version: 1.2.2
 * AUTOSAR version:   4.0.3
 */

#ifndef COM_PBCFG_H
#define COM_PBCFG_H

#if !(((COM_SW_MAJOR_VERSION == 1) && (COM_SW_MINOR_VERSION == 2)) )
#error Com: Configuration file expected BSW module version to be 1.2.*
#endif

#if !(((COM_AR_RELEASE_MAJOR_VERSION == 4) && (COM_AR_RELEASE_MINOR_VERSION == 0)) )
#error Com: Configuration file expected AUTOSAR version to be 4.0.*
#endif

#include "Com_Types.h"

// COM IPDU IDs 
#define ComConf_ComIPdu_ENG_TX               0
#define ComConf_ComIPdu_LAMPS_RX               1
#define ComConf_ComIPdu_TCM_RX               2

// COM PDU GROUP IDs
#define ComConf_ComIPduGroup_LIN			0

// COM SIGNAL IDs
#define ComConf_ComSignal_Signal_Rx_1          0
#define ComConf_ComSignal_Signal_Rx_2          1
#define ComConf_ComSignal_Signal_Tx_1          2
#define ComConf_ComSignal_Signal_Tx_2          3
#define ComConf_ComSignal_Signal_Tx_3          4
#define ComConf_ComSignal_Word_1          5
#define ComConf_ComSignal_Word_2          6

// COM GATEWAY SOURCE SIGNAL DESCRIPTION IDs

// COM GATEWAY DESTINATION SIGNAL DESCRIPTION IDs

// COM GATEWAY MAPPING IDs

#endif /* COM_PBCFG_H */