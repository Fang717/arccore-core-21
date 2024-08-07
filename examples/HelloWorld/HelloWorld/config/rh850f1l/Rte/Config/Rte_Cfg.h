/**
 * RTE Configuration Header File
 *
 */

/** === HEADER ====================================================================================
 */

/** --- Normal include guard ----------------------------------------------------------------------
 */
#ifndef RTE_CFG_H_
#define RTE_CFG_H_

/** --- C++ guard ---------------------------------------------------------------------------------
 */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** --- Includes ----------------------------------------------------------------------------------
 * @req SWS_Rte_07641
 */
#include <Std_Types.h>

/** --- Condition Value Macros -------------------------------------------------------
 * @req SWS_Rte_06513
 */

/** === BODY ======================================================================================
 */

#define RTE_DEV_ERROR_DETECT    STD_ON

/** === FOOTER ====================================================================================
 */

/** @req SWS_Rte_07126 */
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_CFG_H_ */
