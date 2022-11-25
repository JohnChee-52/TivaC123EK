/*
 * UnitTester.cpp
 * The Unit Tester runs the set of the unit tests of each and every module.
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
void cl_unit_tester::run_unit_tests(){
    printf("Running unit-tests of modules...\n");

    // *** user to add module unit-tests here e.g.
    //printf("unit-testing of ModName :\n"); //sign on
    //uto_ModName.run_unit_tests(); //Module unit-tests



    printf("...completed unit-testing of modules specified within function ""cl_unit_tester::run_unit_tests()"".\n");
}
//::---------------------------------------------------------------------------
void cl_unit_tester::run_unit_tests_of_report_module(){
    printf("Running unit-tests of ""UnitTester"" report module:\n");
    uto_Report.run_unit_tests();


    printf("...completed unit-testing of ""UnitTester"" report module.\n");
}
//::---------------------------------------------------------------------------

