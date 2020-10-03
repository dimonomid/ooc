/*******************************************************************************
 * OOC: basic object-oriented C support
 *
 ******************************************************************************/

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "ooc.h"


/*******************************************************************************
 *    PUBLIC FUNCTIONS
 ******************************************************************************/

/*
 * See `OOC_EMPTY_FUNC`
 */
void ooc_empty_func(void)
{
   //-- this function is used as a stub for non-implemented virtual methods.
   //   This is better than use NULL pointer, because subclasses do not need 
   //   to know, if super-method implemented or not. They can just call it.
}

#if defined(OOC_EMPTY_FUNC_ERR_ECHO)
/*
 * See `OOC_EMPTY_FUNC_WITH_ERR`
 */
void ooc_empty_func_with_err(void)
{
   //-- same as ooc_empty_func(), but it also calls user callback,
   //   which should echo error to the log (or somehow differently indicate error)
   //   that function is not implemented.
   //
   //   Should be used if this function MUST be implemented.
   OOC_EMPTY_FUNC_ERR_ECHO();
}
#endif


