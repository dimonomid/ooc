

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

//-- unity: unit test framework
#include "unity.h"

//-- specify headers for which we need sources to be compiled in test project
//   (this is done by ceedling automagically)
#include "ooc.h"
#include "testbase.h"
#include "testderived.h"
#include "mock_mytest_support.h"



/*******************************************************************************
 *    DEFINITIONS
 ******************************************************************************/



/*******************************************************************************
 *    PRIVATE FUNCTION PROTOTYPES
 ******************************************************************************/

T_TestBase    *p_testbase     = NULL;
T_TestDerived *p_testderived  = NULL;

/*******************************************************************************
 *    PRIVATE TYPES
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE DATA
 ******************************************************************************/



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
 *    PRIVATE FUNCTIONS
 ******************************************************************************/



/*******************************************************************************
 *    SETUP, TEARDOWN
 ******************************************************************************/

void setUp(void)
{
}

void tearDown(void)
{
}



/*******************************************************************************
 *    TESTS
 ******************************************************************************/

/**
 * Test that initial state of fifobuf is correct
 */
void test_base(void)
{
   //-- specify expected checkpoints in order
   mytest_supp__checkpoint_Expect(CHECKPOINT__BASE_CTOR);
   mytest_supp__checkpoint_Expect(CHECKPOINT__BASE_SOME_METHOD);
   mytest_supp__checkpoint_Expect(CHECKPOINT__BASE_DTOR);

   //-- create object
   {
      T_TestBase_CtorParams params = {};
      p_testbase = new_testbase(&params);
   }

   //-- call some method
   testbase__some_method(p_testbase, 1, 2);

   //-- delete object
   delete_testbase(p_testbase);
}


void test_derived(void)
{
   //-- specify expected checkpoints in order
   mytest_supp__checkpoint_Expect(CHECKPOINT__BASE_CTOR);
   mytest_supp__checkpoint_Expect(CHECKPOINT__DERIVED_CTOR);

   mytest_supp__checkpoint_Expect(CHECKPOINT__BASE_SOME_METHOD);
   mytest_supp__checkpoint_Expect(CHECKPOINT__DERIVED_SOME_METHOD);

   mytest_supp__checkpoint_Expect(CHECKPOINT__DERIVED_DTOR);
   mytest_supp__checkpoint_Expect(CHECKPOINT__BASE_DTOR);

   //-- create object
   {
      T_TestDerived_CtorParams params = {};
      p_testbase = testderived__testbase__get(
            new_testderived(&params)
            );
   }

   //-- call some method
   testbase__some_method(p_testbase, 1, 2);

   //-- delete object
   delete_testbase(p_testbase);
}



