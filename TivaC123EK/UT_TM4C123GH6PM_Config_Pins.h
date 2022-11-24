/*
 * UT_TM4C123GH6PM_Config_Pins.h
 *
 *  Created on: 1 Nov 2022
 *      Author: John Chee
 */

#ifndef UT_TM4C123GH6PM_CONFIG_PINS_H_
#define UT_TM4C123GH6PM_CONFIG_PINS_H_

#include "TM4C123GH6PM_Config_Pins.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class cl_ut_TM4C123GH6PM_Config_Pins{
private:
protected:
public:
    //--- Import objects
    cl_tm4c123gh6pm_pins oMCU;

    cl_ut_TM4C123GH6PM_Config_Pins(); //Ctor

    void unit_test_TM4C123GH6PM_Config_Pins();
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





#endif /* UT_TM4C123GH6PM_CONFIG_PINS_H_ */
