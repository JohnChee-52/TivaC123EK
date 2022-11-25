/*
 * M_UnitTester.cpp
 *
 *  Created on: 16 Nov 2022
 *      Author: John Chee
 */

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"

#include "Unit_Test_Mode.h"
#include "UT_Report.h"
#include "UnitTester.h"



// *** Note: Uncomment next line to unit_test UnitTester itself; otherwise it tests other modules.
//#define TEST_UnitTester_itself //when defined, UnitTester will test itself
#ifndef TEST_UnitTester_itself


#ifdef Unit_Test_Mode
//ut=========================================================================ut
int main(){ //unit tester
    printf("Unit-testing: Project modules:\n"); //Sign on

//    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN); //config for 50MHz clock

    cl_unit_tester oReport; //Ctor
    oReport.run_unit_tests(); //

    while (1){
    }
}
//ut=========================================================================ut
#endif


#else
#ifdef TEST_UnitTester_itself   //Code below runs only during unit-testing mode when asked to test itself
//ut=========================================================================ut
int main(){ //unit tester
    printf("UnitTester: Report (console-print) module:\n"); //Sign on

    cl_unit_tester oUnitTester; //Ctor
    oUnitTester.run_unit_tests_of_report_module();

    while (1){
    }
}
//ut=========================================================================ut

#endif
#endif



