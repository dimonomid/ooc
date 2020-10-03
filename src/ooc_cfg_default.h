/*******************************************************************************
 * OOC: object-oriented C
 *
 * Configuration file
 *
 ******************************************************************************/

#ifndef _OOC_CFG_H
#define _OOC_CFG_H

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

//-- needed for malloc, free
#include <stdlib.h>


/*******************************************************************************
 *    MACROS
 ******************************************************************************/


#define     OOC_MALLOC(size)      malloc(size)
#define     OOC_FREE(pt)          free(pt)

/**
 * To be implemented by application, if needed: should somehow notify the
 * programmer that run-time error has occurred. This macro is used by
 * `ooc_empty_func_with_err()`, which gets called if some virtual function
 * is not implemented but called.
 */
//#define     OOC_EMPTY_FUNC_ERR_ECHO()   //LOG_ERR("not implemented")



#endif /* _OOC_CFG_H */

