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
void cl_unit_tester::run_unit_tests(){
    printf("Running unit tests:\n");

    //todo - user to add  unit tests
    printf("cl_ut_TM4C123GH6PM_Config_Pins \n");
    utMCU.unit_test_TM4C123GH6PM_Config_Pins();
    ut_oLED_Dbg.unit_test_LEDs_Dbg_RGB();


    printf("...completed unit tests.\n");
}
//::---------------------------------------------------------------------------
//-- print Report Header
//::---------------------------------------------------------------------------
void cl_unit_tester::init_TrackCnt_function(){
    ui16_Track_cnt_Functions = 1;
}
//::---------------------------------------------------------------------------
void cl_unit_tester::prnLns_Hdr_TestReport(const char* aui8Usr_ModName,
                                           const char* aui8Usr_TestDate){ //eg "MCP7940_RTC", "5 Mar 2022"
    printf("=== Biosense Diagnostics Pte Ltd:     Firmware Test Report ===================\n");
    printf("Module Name: \t%s.cpp \t%s \n", aui8Usr_ModName, aui8Usr_TestDate);
}
//::--------------------------------------------------------------------------- //eg "cl_mcp7940_rtc"
void cl_unit_tester::prnLn_ClassName(const char* aui8Usr_ClassName){
    printf("Class Name: \t%s \t ..testing functions...\n", aui8Usr_ClassName);
}
//::---------------------------------------------------------------------------

//-- print Body of functions undergoing tests
//::---------------------------------------------------------------------------
void cl_unit_tester::prnLn_Hdr_SubSection(const char* aui8Usr_Hdr){
    printf("%s \n", aui8Usr_Hdr);
}
//::---------------------------------------------------------------------------
void cl_unit_tester::prnLn_CommentLine(const char* aui8Usr_Comment){
    printf("%s \n", aui8Usr_Comment);
}
//::---------------------------------------------------------------------------
void cl_unit_tester::prnLn_Cnt_n_FnName(const char* aui8Usr_Function){
    printf("   %d \t %s \n", ui16_Track_cnt_Functions, aui8Usr_Function);
    ui16_Track_cnt_Functions++;
}
//::---------------------------------------------------------------------------
void cl_unit_tester::prnLn_Cnt_n_FnName_ET(const char* aui8Usr_Function_at_Edge){
    printf("   %d ET\t %s \n", ui16_Track_cnt_Functions, aui8Usr_Function_at_Edge);
    ui16_Track_cnt_Functions++;
}
//::---------------------------------------------------------------------------

//::---------------------------------------------------------------------------
void cl_unit_tester::prnLn_Hdr_SubSection_UsageExamples(){//"=====----- Usage Examples -----====="
    printf("=====----- Usage Examples -----===== \n");
}
//::---------------------------------------------------------------------------
void cl_unit_tester::prnLns_Footer_TestReport(){
    printf("\nAll %d functions have successfully passed unit testing!\n", (ui16_Track_cnt_Functions - 1));
    printf("----------------------------------------------------------------------------\n");
}
//::---------------------------------------------------------------------------

