/*
 * Report.h
 * printf functions to assist automated report generation
 *
 *  Created on: 25 Nov 2022
 *      Author: John Chee
 */

#ifndef REPORT_H_
#define REPORT_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
//#include "Unit_Test_Mode.h"


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class cl_report{
private:
protected:
public:
    //--- Variables
    int16_t ui16_Track_cnt_Functions;

    //--- Import objects
//    cl_ut_TM4C123GH6PM_Config_Pins utMCU; //Ctor
//    cl_ut_switch_dbg uto_SwDbg; //Ctor

    //+++ class & functions
    cl_report(); //Ctor

    //-- print Report Header
    void init_TrackCnt_function();
    void prnLns_Hdr_TestReport(const char* aui8Usr_ModName, const char* aui8Usr_Date); //eg "MCP7940_RTC", "5 Mar 2022"
    void prnLn_ClassName(const char* aui8Usr_ClassName); //eg "cl_mcp7940_rtc"

    //-- print Body of functions undergoing tests
    void prnLn_Hdr_SubSection(const char* aui8Usr_Hdr);
    void prnLn_CommentLine(const char* aui8Usr_Comment);
    void prnLn_Cnt_n_FnName(const char* aui8Usr_Function);
    void prnLn_Cnt_n_FnName_ET(const char* aui8Usr_Function_at_Edge);

    void prnLn_Hdr_SubSection_UsageExamples(); //"=====----- Usage Examples -----====="
    void prnLns_Footer_TestReport();

};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




#endif /* REPORT_H_ */
