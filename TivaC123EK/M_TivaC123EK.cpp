/*
 * M_TivaC123_EK.cpp
 * Tiva C Evaluation Kit - User interface
 * Press a switch for LED to light up - L switch = orange,
 * Right switch = turqouise.
 *
 *  Created on: 3 Dec 2022
 *      Author: John Chee
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "Unit_Test_Mode.h"
#include "LED_Dbg_RGB.h"
#include "Switch_Dbg.h"

#include "TivaC123EK.h"


#ifndef Unit_Test_Mode  //Code below runs only when not unit-testing
//=======================================================================================
int main(){ //TivaC123EK
    printf("Running TivaC123EK:\n"); //Sign on

    int i ;
    for (i=1; i<=3; i++){
        printf("%d Hi\n", i);
    }
    printf("Done %d times already. \n", (i - 1));

    //+++ Import objects
    cl_led_dbg_rgb oLEDs_Dbg_RGB; //Ctor
    cl_switch_dbg oSw_Debug; //Ctor


    //+++ Ctor
    cl_tivac123ek oTivaEK;


    //=== OS
    printf("Press a switch for LED to light up: L=orange, R=turqouise\n");
    while(1){
        if(oSw_Debug.is_justPressed_SysMode()){
            oLEDs_Dbg_RGB.pulse_delay_Orange_ms(300);
        }
        if(oSw_Debug.is_justPressed_SysWakeup()){
            oLEDs_Dbg_RGB.pulse_delay_Turqoise_ms(300);
        }
    }
    //==== OS end
}
//=======================================================================================
#endif


