
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

/* Generator version: 7.0.0
 * AUTOSAR version:   4.3.0
 */

#include "Port.h"




static const ArcPort_InputSelectConfigType PortInputSelectConfigData[] = {
#ifdef INPUT_SELECT_PORT_PIN_MODE_CAN_PAD_11
	INPUT_SELECT_PORT_PIN_MODE_CAN_PAD_11, /* PCR	11	: PORT_PIN_MODE_CAN */
#endif
#ifdef INPUT_SELECT_PORT_PIN_MODE_CAN_PAD_40
	INPUT_SELECT_PORT_PIN_MODE_CAN_PAD_40, /* PCR	40	: PORT_PIN_MODE_CAN */
#endif
	{PORT_INVALID_REG, 0u} /* end marker */
};

/*lint -save -e835 -e9027 -e845 FALSE POSITIVE Zero given as right argument to | is okay (Generated code and depending on the defines this is true for some defines) */ 
static const ArcPort_PadConfigType PortPadConfigData[] = {
	{10, STD_OFF, STD_OFF, (PIN_FUNCTION_REG(10, PORT_PIN_MODE_CAN, 1) | PORT_IBE_ENABLE | PORT_SLEW_RATE_MAX | PORT_PULL_NONE  | PORT_OUTPUT )}, /* PCR	10	: PORT_PIN_MODE_CAN */
	{11, STD_OFF, STD_OFF, (PIN_FUNCTION_REG(11, PORT_PIN_MODE_CAN, 0) | PORT_IBE_ENABLE | PORT_SLEW_RATE_MAX | PORT_PULL_NONE  )}, /* PCR	11	: PORT_PIN_MODE_CAN */
	{16, STD_OFF, STD_OFF, (PIN_FUNCTION_REG(16, PORT_PIN_MODE_ADC, 0) | PORT_IBE_ENABLE | PORT_SLEW_RATE_MAX | PORT_PULL_NONE  )}, /* PCR	16	: PORT_PIN_MODE_ADC */
	{20, STD_OFF, STD_OFF, (PIN_FUNCTION_REG(20, PORT_PIN_MODE_ADC, 0) | PORT_IBE_ENABLE | PORT_SLEW_RATE_MAX | PORT_PULL_NONE  )}, /* PCR	20	: PORT_PIN_MODE_ADC */
	{40, STD_OFF, STD_OFF, (PIN_FUNCTION_REG(40, PORT_PIN_MODE_CAN, 0) | PORT_IBE_ENABLE | PORT_SLEW_RATE_MAX | PORT_PULL_NONE  )}, /* PCR	40	: PORT_PIN_MODE_CAN */
	{41, STD_OFF, STD_OFF, (PIN_FUNCTION_REG(41, PORT_PIN_MODE_CAN, 1) | PORT_IBE_ENABLE | PORT_SLEW_RATE_MAX | PORT_PULL_NONE  | PORT_OUTPUT )}, /* PCR	41	: PORT_PIN_MODE_CAN */
	{59, STD_OFF, STD_OFF, (PIN_FUNCTION_REG(59, PORT_PIN_MODE_ADC, 0) | PORT_IBE_ENABLE | PORT_SLEW_RATE_MAX | PORT_PULL_NONE  )}, /* PCR	59	: PORT_PIN_MODE_ADC */
	{64, STD_OFF, STD_OFF, (PIN_FUNCTION_REG(64, PORT_PIN_MODE_DIO, 1) | PORT_IBE_ENABLE | PORT_SLEW_RATE_MAX | PORT_PULL_NONE  | PORT_OUTPUT )}, /* PCR	64	: PORT_PIN_MODE_DIO */
	{65, STD_OFF, STD_OFF, (PIN_FUNCTION_REG(65, PORT_PIN_MODE_DIO, 1) | PORT_IBE_ENABLE | PORT_SLEW_RATE_MAX | PORT_PULL_NONE  | PORT_OUTPUT )}, /* PCR	65	: PORT_PIN_MODE_DIO */
	{77, STD_OFF, STD_OFF, (PIN_FUNCTION_REG(77, PORT_PIN_MODE_ADC, 0) | PORT_IBE_ENABLE | PORT_SLEW_RATE_MAX | PORT_PULL_NONE  )}, /* PCR	77	: PORT_PIN_MODE_ADC */
	{78, STD_OFF, STD_OFF, (PIN_FUNCTION_REG(78, PORT_PIN_MODE_ADC, 0) | PORT_IBE_ENABLE | PORT_SLEW_RATE_MAX | PORT_PULL_NONE  )}, /* PCR	78	: PORT_PIN_MODE_ADC */
	{PORT_INVALID_REG, STD_OFF, STD_OFF, 0u} /* end marker */
};
/*lint -restore */


static const ArcPort_OutConfigType PortOutConfigData[] = {
	{64u, PORT_GPDO_RESET}, /* GPDO	64 */
	{65u, PORT_GPDO_RESET}, /* GPDO	65 */
	{PORT_INVALID_REG, 0u} /* end marker */
};



const Port_ConfigType PortConfigData =
{
  .padConfig = PortPadConfigData,
  .outConfig = PortOutConfigData,
  .inputSelectConfig = PortInputSelectConfigData
};


