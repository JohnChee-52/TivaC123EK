/*
 * UT_LED_Dbg_RGB.h
 *
 *  Created on: 1 Nov 2022
 *      Author: John Chee
 */

#ifndef UT_LED_DBG_RGB_H_
#define UT_LED_DBG_RGB_H_

#include "LED_Dbg_RGB.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class cl_ut_LEDs_Dbg_RGB{
private:
protected:
public:
    //--- Import objects
    cl_led_dbg_rgb oLED_Dbg; //Ctor

    //+++ class & functions
    cl_ut_LEDs_Dbg_RGB(); //Ctor
    void unit_test_LEDs_Dbg_RGB();
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



#endif /* UT_LED_DBG_RGB_H_ */
