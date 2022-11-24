/*
 * M_UnitTester.cpp
 *
 *  Created on: 16 Nov 2022
 *      Author: John Chee
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "UnitTester.h"
#include "Unit_Test_Mode.h"

#ifdef Unit_Test_Mode

//ut=========================================================================ut
int main(){ //unit tester
    printf("UnitTester:\n"); //Sign on

//    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN); //config for 50MHz clock

    cl_unit_tester oUnitTester; //Ctor
    oUnitTester.run_unit_tests();
    while (1){
    }
}
//ut=========================================================================ut

#endif


