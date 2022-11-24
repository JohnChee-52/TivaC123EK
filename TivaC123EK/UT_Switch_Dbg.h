/*
 * UT_Switch_Dbg.h
 *
 *  Created on: 1 Nov 2022
 *      Author: John Chee
 */

#ifndef UT_SWITCH_DBG_H_
#define UT_SWITCH_DBG_H_

#include "Switch_Dbg_RGB.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class cl_ut_switch_dbg{
private:
protected:
public:
    //--- Import objects
    cl_switch_dbg oSwitch_Dbg; //Ctor


    cl_ut_switch_dbg(); //Ctor

    void run_unit_tests();
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





#endif /* UT_SWITCH_DBG_H_ */
