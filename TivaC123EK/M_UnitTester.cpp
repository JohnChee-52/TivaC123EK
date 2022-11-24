/*
 * M_UnitTester.cpp
 * 1. UnitTester will run the unit tests of each and every module, as long as
 * the module's "run-unit_tests()" function is called by (ie written in)
 * cl_unit_tester::run_unit_tests()"
 * 2. It also has console print functions for auto generation of unit test report.
 * 3. Note: unit testing of the UnitTester's functions itself is activated by
 * uncommenting out the line "#define TEST_UnitTester" in the "M_UnitTester.cpp" file.
 *
 *  Created on: 16 Nov 2022
 *      Author: John Chee
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include "UnitTester.h"
#include "Unit_Test_Mode.h"

//Note: To run unit tests functions of the UnitTester, comment next line
#define TEST_UnitTester_itself

#ifndef TEST_UnitTester_itself

#ifdef Unit_Test_Mode
/ut=========================================================================ut
int main(){ //unit tester
    printf("UnitTester:\n"); //Sign on

//    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN); //config for 50MHz clock

    cl_unit_tester oUnitTester; //Ctor
    oUnitTester.run_unit_tests();
    while (1){
    }
}
//ut=========================================================================ut

#endif

#else

#ifdef TEST_UnitTester_itself
//ut=========================================================================ut
int main(){ //unit tester
    printf("Testing UnitTester:\n"); //Sign on

//    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN); //config for 50MHz clock

    cl_unit_tester oUnitTester; //Ctor

    //--- print class function name
    printf("-- test cl_unit_tester(); //Ctor \n");
    printf("-- test: void prnLn_ClassName(const char* aui8Usr_ClassName); //eg ""cl_mcp7940_rtc"" \n");
    oUnitTester.prnLn_ClassName("cl_unit_tester(); //Ctor");


    printf("-- test: void run_unit_tests(); \n");
    oUnitTester.run_unit_tests();

    //-- print Report Header
    printf("-- test: void init_TrackCnt_function(); \n");
    oUnitTester.init_TrackCnt_function();
    assert(oUnitTester.ui16_Track_cnt_Functions == 1);


    printf("-- test: void prnLns_Hdr_TestReport(const char* aui8Usr_ModName, const char* aui8Usr_Date); \n");
    oUnitTester.prnLns_Hdr_TestReport("UnitTester", "18 Nov 2022");



    //-- print Body of functions undergoing tests
    printf("-- test: void prnLn_Hdr_SubSection(const char* aui8Usr_Hdr); \n");
    oUnitTester.prnLn_Hdr_SubSection("//-- Body of functions undergoing tests");


    printf("-- test: void prnLn_CommentLine(const char* aui8Usr_Comment); \n");
    oUnitTester.prnLn_CommentLine("This is a sample of user comment line.");


    printf("-- test: void prnLn_Cnt_n_FnName(const char* aui8Usr_Function); \n");
    oUnitTester.prnLn_Cnt_n_FnName("Module Function1");
    assert(oUnitTester.ui16_Track_cnt_Functions == 2);

    oUnitTester.prnLn_Cnt_n_FnName("Module Function2");
    assert(oUnitTester.ui16_Track_cnt_Functions == 3);


    printf("-- test: void prnLn_Cnt_n_FnName_ET(const char* aui8Usr_Funtion_at_Edge); \n");
    oUnitTester.prnLn_Cnt_n_FnName_ET("Module Function3");
    assert(oUnitTester.ui16_Track_cnt_Functions == 4);

    oUnitTester.prnLn_Cnt_n_FnName_ET("Module Function4");
    assert(oUnitTester.ui16_Track_cnt_Functions == 5);


    printf("-- test: void prnLn_Hdr_SubSection_UsageExamples(); \n"); //"=====----- Usage Examples -----=====" \n");
    oUnitTester.prnLn_Hdr_SubSection_UsageExamples(); //"=====----- Usage Examples -----====="


    printf("-- test: void prnLns_Footer_TestReport(); \n");
    oUnitTester.prnLns_Footer_TestReport();



    oUnitTester.prnLn_Hdr_SubSection_UsageExamples();
    oUnitTester.prnLn_CommentLine("Ex 1. Demo on using UnitTester prn functions");
    oUnitTester.init_TrackCnt_function();
    oUnitTester.prnLns_Hdr_TestReport("UnitTester", "19 Nov 2022");
    oUnitTester.prnLn_ClassName("cl_unit_tester");

    oUnitTester.prnLn_Hdr_SubSection("Initialisation");
    oUnitTester.prnLn_Cnt_n_FnName("do_Fn1");
    oUnitTester.prnLn_Cnt_n_FnName_ET("do_Fn2");

    oUnitTester.prnLn_Hdr_SubSection("Main functions");
    oUnitTester.prnLn_Cnt_n_FnName("do_Fn3");
    oUnitTester.prnLn_Cnt_n_FnName_ET("do_Fn4");

    oUnitTester.prnLns_Footer_TestReport();


    while (1){
    }
}
//ut=========================================================================ut

#endif
#endif


