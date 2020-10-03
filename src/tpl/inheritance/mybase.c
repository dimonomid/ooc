/*******************************************************************************
 *    TODO: description of class
 ******************************************************************************/

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "mybase.h"
#include <string.h>

/*- includes -*/


/*******************************************************************************
 *    MACROS
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE METHOD PROTOTYPES
 ******************************************************************************/

static void _vtable_init();

/*******************************************************************************
 *    PRIVATE TYPES
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE DATA
 ******************************************************************************/

static T_MyBase_VTable _vtable;
static OOC_BOOL _bool_vtable_initialized = 0;



/*******************************************************************************
 *    PUBLIC DATA
 ******************************************************************************/

/*******************************************************************************
 *    EXTERNAL DATA
 ******************************************************************************/

/*******************************************************************************
 *    EXTERNAL FUNCTION PROTOTYPES
 ******************************************************************************/

/*******************************************************************************
 *    PROTECTED METHODS
 ******************************************************************************/

const T_MyBase_VTable *_mybase__vtable__get(void)
{
   _vtable_init();
   return &_vtable;
}

/*******************************************************************************
 *    PRIVATE METHODS
 ******************************************************************************/

//TODO: here should be virtual methods implementations, like that:
static void _some_method(T_MyBase *me, int a, int b)
{
   //-- ... some actions
   /*- some_method -*/
}

static void _dtor(T_MyBase *me)
{
   // some desctruct code
   /*- dtor -*/
}

static void _free(T_MyBase *me)
{
   OOC_FREE(me);
}


static void _vtable_init()
{
   if (!_bool_vtable_initialized){
      _vtable.p_dtor           = _dtor;
      _vtable.p_free           = _free;

      _vtable.p_some_method    = _some_method;

      _bool_vtable_initialized = 1;
   }
}

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

/**
 * Constructor
 *
 */
T_MyBase_Res mybase__ctor(T_MyBase *me, const T_MyBase_CtorParams *p_params)
{
   T_MyBase_Res ret = MYBASE_RES__OK;
   memset(me, 0x00, sizeof(T_MyBase));

   //-- init virtual methods

   _vtable_init();
   me->p_vtable = &_vtable;

   //-- some construct code
   /*- ctor -*/

   return ret;
}



/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/



/*******************************************************************************
 *    ALLOCATOR, DEALLOCATOR
 ******************************************************************************/

/*
 * Allocator and Deallocator
 *
 * Please NOTE: There's not necessary to use them! 
 * For instance, you can just allocate in stack or statically or manually from heap,
 * and use _ctor only.
 */
#if defined OOC_MALLOC && defined OOC_FREE

/* allocator */
T_MyBase *new_mybase(const T_MyBase_CtorParams *p_params)
{
   T_MyBase *me = (T_MyBase *)OOC_MALLOC( sizeof(T_MyBase) );
   mybase__ctor(me, p_params);
   return me;
}

/* deallocator */
void delete_mybase(T_MyBase *me){
   mybase__dtor(me);
   me->p_vtable->p_free(me);
}
#endif



/*******************************************************************************
 *    end of file
 ******************************************************************************/


