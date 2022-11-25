/*
 * UT_Switch_Dbg.h
 * Perform unit tests on class functions of "cl_switch_dbg"
 *
 *  Created on: 1 Nov 2022
 *      Author: John Chee
 */

#ifndef UT_SWITCH_DBG_H_
#define UT_SWITCH_DBG_H_

#include "UnitTester.h"
#include "Switch_Dbg.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class cl_ut_switch_dbg{
private:
protected:
public:
    //--- Import objects
//    cl_unit_tester oUTester;
    cl_switch_dbg oSw_Dbg; //Ctor

    //+++ class & functions
    cl_ut_switch_dbg(); //Ctor
    void run_unit_tests();
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



#endif /* UT_SWITCH_DBG_H_ */
