/*
 * Report.cpp
 *
 *  Created on: 25 Nov 2022
 *      Author: John Chee
 */

#include "Report.h"


//::cc-------------------------------------------------------------------------
cl_report::cl_report(){ //Ctor
}
//::cc-------------------------------------------------------------------------

//-- print Report Header
//::---------------------------------------------------------------------------
void cl_report::init_TrackCnt_function(){
    ui16_Track_cnt_Functions = 1;
}
//::---------------------------------------------------------------------------
void cl_report::prnLns_Hdr_TestReport(const char* aui8Usr_ModName,
                                           const char* aui8Usr_TestDate){ //eg "MCP7940_RTC", "5 Mar 2022"
    printf("=== Biosense Diagnostics Pte Ltd:     Firmware Test Report ===================\n");
    printf("Module Name: \t%s.cpp \t%s \n", aui8Usr_ModName, aui8Usr_TestDate);
}
//::--------------------------------------------------------------------------- //eg "cl_mcp7940_rtc"
void cl_report::prnLn_ClassName(const char* aui8Usr_ClassName){
    printf("Class Name: \t%s \t ..testing functions...\n", aui8Usr_ClassName);
}
//::---------------------------------------------------------------------------

//-- print Body of functions undergoing tests
//::---------------------------------------------------------------------------
void cl_report::prnLn_Hdr_SubSection(const char* aui8Usr_Hdr){
    printf("%s \n", aui8Usr_Hdr);
}
//::---------------------------------------------------------------------------
void cl_report::prnLn_CommentLine(const char* aui8Usr_Comment){
    printf("%s \n", aui8Usr_Comment);
}
//::---------------------------------------------------------------------------
void cl_report::prnLn_Cnt_n_FnName(const char* aui8Usr_Function){
    printf("   %d \t %s \n", ui16_Track_cnt_Functions, aui8Usr_Function);
    ui16_Track_cnt_Functions++;
}
//::---------------------------------------------------------------------------
void cl_report::prnLn_Cnt_n_FnName_ET(const char* aui8Usr_Function_at_Edge){
    printf("   %d ET\t %s \n", ui16_Track_cnt_Functions, aui8Usr_Function_at_Edge);
    ui16_Track_cnt_Functions++;
}
//::---------------------------------------------------------------------------

//::---------------------------------------------------------------------------
void cl_report::prnLn_Hdr_SubSection_UsageExamples(){//"=====----- Usage Examples -----====="
    printf("=====----- Usage Examples -----===== \n");
}
//::---------------------------------------------------------------------------
void cl_report::prnLns_Footer_TestReport(){
    printf("\nAll %d functions have successfully passed unit testing!\n", (ui16_Track_cnt_Functions - 1));
    printf("----------------------------------------------------------------------------\n");
}
//::---------------------------------------------------------------------------



