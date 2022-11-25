/*
 * UT_Report.h
 *
 *  Created on: 25 Nov 2022
 *      Author: John Chee
 */

#ifndef UT_REPORT_H_
#define UT_REPORT_H_

#include "Unit_Test_Mode.h"
#include "Report.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class cl_ut_report{
private:
protected:
public:
    //--- Import objects
    cl_report oReport;

    //+++ class + functions
    cl_ut_report(); //Ctor
    void run_unit_tests();
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




#endif /* UT_REPORT_H_ */
