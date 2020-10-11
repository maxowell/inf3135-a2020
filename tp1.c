#include <stdio.h>
#include <stdbool.h>
#include "tcv.h"
#include "/usr/include/CUnit/Basic.h"
//#include "/usr/include/CUnit/Automated.h"
//#include "/usr/include/CUnit/Console.h"


int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void test_validerTH_1 () {
	CU_ASSERT_TRUE(validerTH_1(200));
	CU_ASSERT_TRUE(validerTH_1(400));
	CU_ASSERT_FALSE(validerTH_1(169));
	CU_ASSERT_FALSE(validerTH_1(401));
	CU_ASSERT_FALSE(validerTH_1(100));
	CU_ASSERT_FALSE(validerTH_1(-200));
	CU_ASSERT_FALSE(validerTH_1(700));
	CU_ASSERT_FALSE(validerTH_1(-600));
}

void test_validerTH_2 () {
	CU_ASSERT_TRUE(validerTH_2(20));
	CU_ASSERT_TRUE(validerTH_2(40));
	CU_ASSERT_FALSE(validerTH_2(16));
	CU_ASSERT_FALSE(validerTH_2(40));
	CU_ASSERT_FALSE(validerTH_2(10));
	CU_ASSERT_FALSE(validerTH_2(-20));
	CU_ASSERT_FALSE(validerTH_2(90));
	CU_ASSERT_FALSE(validerTH_2(-90));
}

void test_validerTH_3 () {
	CU_ASSERT_TRUE(validerTH_3(200));
	CU_ASSERT_TRUE(validerTH_3(400));
	CU_ASSERT_FALSE(validerTH_3(169));
	CU_ASSERT_FALSE(validerTH_3(401));
	CU_ASSERT_FALSE(validerTH_3(100));
	CU_ASSERT_FALSE(validerTH_3(-200));
	CU_ASSERT_FALSE(validerTH_3(700));
	CU_ASSERT_FALSE(validerTH_3(-600));
}

void test_validerTA_1 () {
	CU_ASSERT_TRUE(validerTA_1(169));
	CU_ASSERT_TRUE(validerTA_1(169));
	CU_ASSERT_FALSE(validerTA_1(169));
	CU_ASSERT_FALSE(validerTA_1(169));
	CU_ASSERT_FALSE(validerTA_1(169));
	CU_ASSERT_FALSE(validerTA_1(169));
	CU_ASSERT_FALSE(validerTA_1(169));
	CU_ASSERT_FALSE(validerTA_1(169));
	CU_ASSERT_FALSE(validerTA_1(169));

}
//void test_validerTA_1 () {}
//void test_validerTA_1 () {}

//void test_validerPulsation_1 () {}
//void test_validerPulsation_1 () {}
//void test_validerPulsation_1 () {}

//void test_validerSignal_1 () {}
//void test_validerSignal_1 () {}
//void test_validerSignal_1 () {}




int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "tp1_test_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
	CU_cleanup_registry();
	return CU_get_error();
   }


   /* add the tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "test_validerTH_1", test_validerTH_1)) ||
        (NULL == CU_add_test(pSuite, "test_validerTH_2", test_validerTH_2)) ||
        (NULL == CU_add_test(pSuite, "test_validerTH_3", test_validerTH_3)) ||

        (NULL == CU_add_test(pSuite, "test_validerTA_1", test_validerTH_1)) //||
        //(NULL == CU_add_test(pSuite, "test_validerTA_2", test_validerTH_2)) ||
        //(NULL == CU_add_test(pSuite, "test_validerTA_3", test_validerTH_3)) ||

        //(NULL == CU_add_test(pSuite, "test_validerPulsation_1", test_validerPulsation_1)) ||
        //(NULL == CU_add_test(pSuite, "test_validerPulsation_2", test_validerPulsation_2)) ||
        //(NULL == CU_add_test(pSuite, "test_validerPulsation_3", test_validerPulsation_3)) ||

        //(NULL == CU_add_test(pSuite, "test_validerSignal_1", test_validerSignal_1)) ||
        //(NULL == CU_add_test(pSuite, "test_validerSignal_2", test_validerSignal_2)) ||
        //(NULL == CU_add_test(pSuite, "test_validerSignal_3", test_validerSignal_3))
	)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // Run all tests using the basic interface
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");

   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
