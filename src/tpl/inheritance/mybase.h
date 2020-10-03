/*******************************************************************************
 *    TODO: description of class
 ******************************************************************************/

#ifndef _MYBASE_H
#define _MYBASE_H

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "ooc.h"



/*******************************************************************************
 *    MACROS
 ******************************************************************************/

/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

typedef struct S_MyBase T_MyBase;

/*
 * Result codes
 */
typedef enum E_MyBase_Res {
   MYBASE_RES__OK,
} T_MyBase_Res;

typedef struct S_MyBase_CtorParams {
   //-- add your ctor params here
} T_MyBase_CtorParams;



/*******************************************************************************
 *    VTABLE
 ******************************************************************************/

/**
 * Destructor
 */
typedef void (T_MyBase_Dtor)                (T_MyBase *me);

/**
 * Memory deallocator. Needs to be overridden because pointer to subclass not
 * necessarily matches pointer to superclass.
 */
typedef void (T_MyBase_Free)                (T_MyBase *me);

/**
 * Example virtual method prototype, to be replaced by real
 * application-dependent method(s).
 */
typedef void (T_MyBase_SomeMethod)          (T_MyBase *me, int a, int b);



/**
 * Virtual functions table (vtable)
 */
typedef struct S_MyBase_VTable {
   T_MyBase_Dtor            *p_dtor;
   T_MyBase_Free            *p_free;
   T_MyBase_SomeMethod      *p_some_method;
} T_MyBase_VTable;



/*******************************************************************************
 *    OBJECT CONTEXT
 ******************************************************************************/

/*
 * Object context
 */
struct S_MyBase {

   //-- TODO: add fields to object context
   /*- object_context -*/

   struct S_MyBase_VTable *p_vtable;
};



/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR PROTOTYPES
 ******************************************************************************/

/**
 * Constructor
 *
 * @return MYBASE_RES__OK if everything is ok, otherwise returns error code
 */
T_MyBase_Res mybase__ctor(T_MyBase *me, const T_MyBase_CtorParams *p_params);

/**
 * Desctructor
 */
static inline void mybase__dtor(T_MyBase *me)
{
   me->p_vtable->p_dtor(me);
}



/*******************************************************************************
 *    PUBLIC METHOD PROTOTYPES
 ******************************************************************************/

static inline void mybase__some_method(T_MyBase *me, int a, int b)
{
   me->p_vtable->p_some_method(me, a, b);
}



/*******************************************************************************
 *    PROTECTED METHOD PROTOTYPES
 ******************************************************************************/

/**
 * Returns pointer to vtable for class MyBase.
 */
const T_MyBase_VTable *_mybase__vtable__get(void);



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
T_MyBase *new_mybase(const T_MyBase_CtorParams *p_params);

/* deallocator */
void delete_mybase(T_MyBase *me);

#endif


#endif // _MYBASE_H

/*******************************************************************************
 *    end of file
 ******************************************************************************/

