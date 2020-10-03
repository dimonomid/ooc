
#ifndef _MYTEST_SUPPORT_H
#define _MYTEST_SUPPORT_H

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/


/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

enum E_Checkpoint {
   CHECKPOINT__BASE_CTOR,
   CHECKPOINT__BASE_SOME_METHOD,
   CHECKPOINT__BASE_DTOR,

   CHECKPOINT__DERIVED_CTOR,
   CHECKPOINT__DERIVED_SOME_METHOD,
   CHECKPOINT__DERIVED_DTOR,
};




/*******************************************************************************
 *    PUBLIC FUNCTIONS
 ******************************************************************************/

void mytest_supp__checkpoint(enum E_Checkpoint checkpoint);





#endif /* _MYTEST_SUPPORT_H */

