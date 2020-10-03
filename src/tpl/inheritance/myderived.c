/*******************************************************************************
 *    TODO: description of class
 ******************************************************************************/

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "myderived.h"

//-- for memset()
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

static T_MyBase_VTable _super_vtable;
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

/*******************************************************************************
 *    PRIVATE METHODS
 ******************************************************************************/

//---------------- virtual methods implementations -----------------

/**
 * TODO: here should be virtual methods implementations, like that:
 */
static void _some_method(T_MyBase *me_super, int a, int b)
{
   //-- call method of superclass (if needed)
   _mybase__vtable__get()->p_some_method(me_super, a, b);

   T_MyDerived *me = myderived__get_by_mybase(me_super);

   //-- ... some actions
   /*- some_method -*/
}

/**
 * Destructor (virtual)
 */
static void _dtor(T_MyBase *me_super)
{
   T_MyDerived *me = myderived__get_by_mybase(me_super);
   // some desctruct code

   /*- dtor -*/

   // NOTE: this is a subclass, so that after performing destruction code,
   // we should call desctructor of superclass:
   _mybase__vtable__get()->p_dtor(me_super);
}

#if defined OOC_MALLOC && defined OOC_FREE
/**
 * Memory deallocator (virtual)
 */
static void _free(T_MyBase *me_super)
{
   T_MyDerived *me = myderived__get_by_mybase(me_super);
   OOC_FREE( me);
}
#endif


//---------------- just private methods -----------------

static void _vtable_init()
{
   if (!_bool_vtable_initialized){
      //-- firstly, just copy vtable of base class
      _super_vtable = *_mybase__vtable__get();

      //-- and then, specify what we need to override.
      //   There are _dtor and _free, inevitably.
      _super_vtable.p_dtor           = _dtor;
      _super_vtable.p_free           = _free;

      //-- and then, our own virtual methods. If we don't override them here,
      //   it's ok: then, methods of base class will be called.
      _super_vtable.p_some_method    = _some_method;

      //-- remember that vtable is already initialized.
      _bool_vtable_initialized = 1;
   }
}

/*******************************************************************************
 *    CONSTRUCTOR, DESTRUCTOR
 ******************************************************************************/

/**
 * Constructor
 */
T_MyBase_Res myderived__ctor(T_MyDerived *me, const T_MyDerived_CtorParams *p_params)
{
   memset(me, 0x00, sizeof(T_MyDerived));
   T_MyBase_Res ret = mybase__ctor(&me->super.mybase, &p_params->super_params);

   if (ret == MYBASE_RES__OK){

      //-- init virtual methods

      _vtable_init();
      me->super.mybase.p_vtable = &_super_vtable;

      //-- some construct code
      /*- ctor -*/

   }
   return ret;
}


/*******************************************************************************
 *    PUBLIC METHODS
 ******************************************************************************/

OOC_BOOL instanceof_myderived(const T_MyBase *me_super)
{
   //-- here we just check vtable pointer.
   return (me_super->p_vtable == &_super_vtable);
}

T_MyDerived *myderived__get_by_mybase(const T_MyBase *me_super)
{
   T_MyDerived *p_ret = NULL;

   if (instanceof_myderived(me_super)){
      p_ret = OOC_GET_CONTAINER_PT(
            T_MyDerived,
            super.mybase,
            me_super
            );
   } else {
      //-- TODO: probably add some run-time error
   }

   return p_ret;
}

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
T_MyDerived *new_myderived(const T_MyDerived_CtorParams *p_params)
{
   T_MyDerived *me = (T_MyDerived *)OOC_MALLOC( sizeof(T_MyDerived) );
   myderived__ctor(me, p_params);
   return me;
}

/*
 * NOTE: there's no deallocator in subclass; use deallocator of superclass
 * (i.e. `delete_mybase()`)
 */

#endif



/*******************************************************************************
 *    end of file
 ******************************************************************************/


