/*******************************************************************************
 * OOC: basic object-oriented C support
 *
 ******************************************************************************/

#ifndef _OOC_H
#define _OOC_H

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "ooc_cfg.h"



/*******************************************************************************
 *    MACROS
 ******************************************************************************/

/**
 * Calculates offset of member inside the struct
 */
#define OOC_OFFSETOF(_struct_, _member_)  (size_t)&(((_struct_ *)0)->_member_)

/**
 * Calculates pointer to subclass (i.e. containing struct) from pointer to
 * superclass (i.e. contained struct).
 */
#define OOC_GET_CONTAINER_PT(                                              \
      _T_Subclass_,                                                        \
      _superclass_field_name_,                                             \
      _superclass_pt_                                                      \
      )                                                                    \
                                                                           \
   ((_T_Subclass_ *)(                                                      \
      (unsigned char *)(_superclass_pt_)                                   \
      - OOC_OFFSETOF(_T_Subclass_, _superclass_field_name_)                \
      )                                                                    \
    )

/**
 * To be used when superclass doesn't have implementation of some method,
 * but we don't want to leave NULL pointer here
 */
#define OOC_EMPTY_FUNC            ((void *)ooc_empty_func)

/**
 * To be used when superclass doesn't have implementation of some method,
 * and we want for some run-time error (better than NULL pointer access)
 * if that method gets called
 */
#define OOC_EMPTY_FUNC_WITH_ERR   ((void *)ooc_empty_func_with_err)

#define OOC_TRUE     (1 == 1)
#define OOC_FALSE    (!OOC_TRUE)



/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

typedef unsigned char OOC_BOOL;



/*******************************************************************************
 *    PUBLIC FUNCTION PROTOTYPES
 ******************************************************************************/



/*
 * See `OOC_EMPTY_FUNC`
 */
void ooc_empty_func(void);

#ifdef OOC_EMPTY_FUNC_ERR_ECHO
/*
 * See `OOC_EMPTY_FUNC_WITH_ERR`
 */
void ooc_empty_func_with_err(void);
#endif

#endif // _OOC_H


