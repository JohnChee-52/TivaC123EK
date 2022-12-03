/*
 * UnitTester.h
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

#ifndef UNITTESTER_H_
#define UNITTESTER_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "Unit_Test_Mode.h"
#include "UT_TM4C123GH6PM_Config_Pins.h"
#include "UT_LED_Dbg_RGB.h"
#include "UT_Report.h"
#include "UT_Switch_Dbg.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class cl_unit_tester{
private:
    int16_t ui16_Track_cnt_Functions;
protected:
public:
    //--- Import objects
    cl_ut_TM4C123GH6PM_Config_Pins utMCU; //Ctor
    cl_ut_LEDs_Dbg_RGB ut_oLED_Dbg; //Ctor
    cl_report oReport; //Ctor
    cl_ut_report uto_Report; //Ctor
    cl_ut_switch_dbg uto_Sw_Debug; //Ctor

    //+++ class functions
    cl_unit_tester(); //Ctor
    void run_unit_tests_of_project_modules();
    void run_unit_tests_of_report_module();

};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif /* UNITTESTER_H_ */
