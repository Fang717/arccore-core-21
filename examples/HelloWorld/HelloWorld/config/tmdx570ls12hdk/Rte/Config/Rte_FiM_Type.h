/**
 * Application Types Header File
 *
 * @req SWS_Rte_07122
 */

/** === HEADER ====================================================================================
 */

#ifndef RTE_FIM_TYPE_H_
#define RTE_FIM_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** --- Includes ----------------------------------------------------------------------------------
 * @req SWS_Rte_07127
 */
#include <Rte_Type.h>

/** === BODY ====================================================================================
 */

/** --- ENUMERATION DATA TYPES ------------------------------------------------------------------ */

/** Enum literals for boolean */
#ifndef FALSE
#define FALSE 0U
#endif /* FALSE */

#ifndef TRUE
#define TRUE 1U
#endif /* TRUE */

/** --- MODE TYPES ------------------------------------------------------------------------------ */

/** === FOOTER ====================================================================================
 */

/** @req SWS_Rte_07126 */
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_FIM_TYPE_H_ */
