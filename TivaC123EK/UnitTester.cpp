/*
 * UnitTester.cpp
 * 1. UnitTester will run the unit tests of each and every module, as long as
 * the module's "run-unit_tests()" function is called by (ie written in)
 * cl_unit_tester::run_unit_tests()"
 * 2. It also has console print functions for auto generation of unit test report.
 * 3. Note: unit testing of the UnitTester's functions itself is activated by
 * uncommenting out the line "#define TEST_UnitTester" in the "M_UnitTester.cpp" file.
 *
 *  Created on: 31 Oct 2022
 *      Author: John Chee
 */

#include "UnitTester.h"


//::cc-------------------------------------------------------------------------
cl_unit_tester::cl_unit_tester(){ //Ctor
}
//::cc-------------------------------------------------------------------------
//::---------------------------------------------------------------------------
void cl_unit_tester::run_unit_tests_of_project_modules(){
    printf("Running unit-tests of project modules...\n");

    // *** user to add module unit-tests here e.g.
    //printf("unit-testing of ModName :\n"); //sign on
    //uto_ModName.run_unit_tests(); //Module unit-tests

    ut_oLED_Dbg.unit_test_LEDs_Dbg_RGB();


    printf("...completed unit-testing of modules specified within function ""cl_unit_tester::run_unit_tests()"".\n");
}
//::---------------------------------------------------------------------------
void cl_unit_tester::run_unit_tests_of_report_module(){
    printf("Running unit-tests of ""UnitTester"" report module:\n");
    uto_Report.run_unit_tests();

    printf("...completed unit-testing of ""UnitTester"" report module.\n");
}
//::---------------------------------------------------------------------------

