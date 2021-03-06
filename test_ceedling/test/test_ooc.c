

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

//-- unity: unit test framework
#include "unity.h"

//-- specify headers for which we need sources to be compiled in test project
//   (this is done by ceedling automagically)
#include "ooc.h"



/*******************************************************************************
 *    DEFINITIONS
 ******************************************************************************/



/*******************************************************************************
 *    PRIVATE FUNCTION PROTOTYPES
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE TYPES
 ******************************************************************************/

struct S_TestStruct {
  int a;
  int b;
  int c;
};


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
void test_ooc_get_container_pt(void)
{
   struct S_TestStruct ts;

   TEST_ASSERT_EQUAL_INT(
         &ts,
         OOC_GET_CONTAINER_PT(struct S_TestStruct, a, &ts.a)
         );

   TEST_ASSERT_EQUAL_INT(
         &ts,
         OOC_GET_CONTAINER_PT(struct S_TestStruct, b, &ts.b)
         );

   TEST_ASSERT_EQUAL_INT(
         &ts,
         OOC_GET_CONTAINER_PT(struct S_TestStruct, c, &ts.c)
         );

}



