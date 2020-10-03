/*******************************************************************************
 *    TODO: description of class
 ******************************************************************************/

#ifndef _MYDERIVED_H
#define _MYDERIVED_H


/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "mybase.h"


/*******************************************************************************
 *    MACROS
 ******************************************************************************/

/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

typedef struct S_MyDerived T_MyDerived;

typedef struct S_MyDerived_CtorParams {
   T_MyBase_CtorParams super_params;

   //-- add your ctor params here
} T_MyDerived_CtorParams;



/*******************************************************************************
 *    OBJECT CONTEXT
 ******************************************************************************/

/*
 * Object context
 */
struct S_MyDerived {
   struct {
      T_MyBase mybase;
   } super;

   /*- object_context -*/
};



/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR PROTOTYPES
 ******************************************************************************/

/**
 * Constructor
 *
 * @return MYBASE_RES__OK if everything is ok, otherwise returns error code
 */
T_MyBase_Res myderived__ctor(T_MyDerived *me, const T_MyDerived_CtorParams *p_params);



/*******************************************************************************
 *    PUBLIC METHOD PROTOTYPES
 ******************************************************************************/

/**
 * Returns whether pointer to superclass (`T_MyBase`) points to an instance
 * of subclass (`T_MyDerived`).
 *
 * NOTE: works only for 1-level inheritance!
 */
OOC_BOOL instanceof_myderived(const T_MyBase *me_super);

/**
 * Returns pointer to subclass by pointer to superclass
 */
T_MyDerived *myderived__get_by_mybase(const T_MyBase *me_super);

/**
 * Returns pointer to superclass (i.e. `T_MyBase`)
 */
static inline T_MyBase *myderived__mybase__get(T_MyDerived *me)
{
   return &(me->super.mybase);
}




/*******************************************************************************
 *    ALLOCATOR, DEALLOCATOR PROTOTYPES
 ******************************************************************************/

/*
 * Allocator and Deallocator
 *
 * Please NOTE: There's not necessary to use them! 
 * For instance, you can just allocate in stack or statically or manually from
 * heap, and use _ctor only.
 */
#if defined OOC_MALLOC && defined OOC_FREE

/* allocator */
T_MyDerived *new_myderived(const T_MyDerived_CtorParams *p_params);

#endif


#endif // _MYDERIVED_H

/*******************************************************************************
 *    end of file
 ******************************************************************************/

