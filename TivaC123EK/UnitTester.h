/*
 * UnitTester.h
 *
 *  Created on: 31 Oct 2022
 *      Author: John Chee
 */

#ifndef UNITTESTER_H_
#define UNITTESTER_H_

#include <stdio.h>
#include "UT_Report.h"
#include "Unit_Test_Mode.h"


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class cl_unit_tester{
private:
protected:
public:
    //--- Import objects
    cl_ut_report uto_Report; //Ctor

    //--- class functions
    cl_unit_tester(); //Ctor
    void run_unit_tests();
    void run_unit_tests_of_report_module();

};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif /* UNITTESTER_H_ */
