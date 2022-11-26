/*
 * UT_Report.cpp
 *
 *  Created on: 25 Nov 2022
 *      Author: John Chee
 */


#include <assert.h>
#include "UT_Report.h"

//::cc-------------------------------------------------------------------------
cl_ut_report::cl_ut_report(){ //Ctor

}
//::cc-------------------------------------------------------------------------
//::---------------------------------------------------------------------------
void cl_ut_report::run_unit_tests(){

    printf(">> test: void init_TrackCnt_function(); \n");
    oReport.init_TrackCnt_function();
    assert(oReport.ui16_Track_cnt_Functions == 1);


    printf(">> test: void prnLns_Hdr_TestReport(const char* aui8Usr_ModName, const char* aui8Usr_Date); \n");
    oReport.prnLns_Hdr_TestReport("UnitTester", "18 Nov 2022");



    //-- print Body of functions undergoing tests
    printf(">> test: void prnLn_Hdr_SubSection(const char* aui8Usr_Hdr); \n");
    oReport.prnLn_Hdr_SubSection("//-- Body of functions undergoing tests");


    printf(">> test: void prnLn_CommentLine(const char* aui8Usr_Comment); \n");
    oReport.prnLn_CommentLine("This is a sample of user comment line.");


    printf(">> test: void prnLn_Cnt_n_FnName(const char* aui8Usr_Function); \n");
    oReport.prnLn_Cnt_n_FnName("Module Function1");
    assert(oReport.ui16_Track_cnt_Functions == 2);

    oReport.prnLn_Cnt_n_FnName("Module Function2");
    assert(oReport.ui16_Track_cnt_Functions == 3);


    printf(">> test: void prnLn_Cnt_n_FnName_ET(const char* aui8Usr_Funtion_at_Edge); \n");
    oReport.prnLn_Cnt_n_FnName_ET("Module Function3");
    assert(oReport.ui16_Track_cnt_Functions == 4);

    oReport.prnLn_Cnt_n_FnName_ET("Module Function4");
    assert(oReport.ui16_Track_cnt_Functions == 5);


    printf(">> test: void prnLn_Hdr_SubSection_UsageExamples(); \n"); //"=====----- Usage Examples -----=====" \n");
    oReport.prnLn_Hdr_SubSection_UsageExamples(); //"=====----- Usage Examples -----====="


    printf(">> test: void prnLns_Footer_TestReport(); \n");
    oReport.prnLns_Footer_TestReport();


    printf("\n");
    printf(">> test: emulate auto generation unit-test report. \n");
    oReport.prnLn_Hdr_SubSection_UsageExamples();
    oReport.prnLn_CommentLine("Ex 1. Demo on using UnitTester prn functions");
    oReport.init_TrackCnt_function();
    oReport.prnLns_Hdr_TestReport("UnitTester", "19 Nov 2022");
    oReport.prnLn_ClassName("cl_unit_tester");

    oReport.prnLn_Hdr_SubSection("Initialisation");
    oReport.prnLn_Cnt_n_FnName("do_Fn1");
    oReport.prnLn_Cnt_n_FnName_ET("do_Fn2");

    oReport.prnLn_Hdr_SubSection("Main functions");
    oReport.prnLn_Cnt_n_FnName("do_Fn3");
    oReport.prnLn_Cnt_n_FnName_ET("do_Fn4");

    oReport.prnLns_Footer_TestReport();
}
//::---------------------------------------------------------------------------

