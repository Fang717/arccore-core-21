/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2014, ArcCore AB, Sweden, www.arccore.com.
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

#include "Rte_ModeManager.h"

void modeManagerInit(void) {
	/* Call EcuM */
	Rte_Call_RunControl_RequestRUN();

	/* Call BswM */
	Rte_IWrite_ModeManagerInit_ComMControl_requestedMode(COMM_FULL_COMMUNICATION);
}
