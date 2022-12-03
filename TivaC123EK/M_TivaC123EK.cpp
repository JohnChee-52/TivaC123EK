/*
 * M_TivaC123_EK.cpp
 * Tiva C Evaluation Kit - User interface
 * An example of Version Control using EGit
 * If you are using stdio, you need to allocate heap space e.g. 1000.
 * Note: printf will only show on console if the string has "\n".
 *
 * Simple example of printing:  "<n> Hi" five times, where n=1..5
 *
 *  Created on: 30 Oct 2022
 *      Author: John Chee
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "Unit_Test_Mode.h"
//#include "LED_Dbg_RGB.h"
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
//    cl_LEDs_Dbg_RGB oLEDs_Dbg_RGB; //Ctor
    cl_switch_dbg oSw_Debug; //Ctor


    //+++ Ctor
    cl_tivac123ek oTivaEK;




}
//=======================================================================================
#endif


