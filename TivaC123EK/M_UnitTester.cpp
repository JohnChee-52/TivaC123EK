/*
 * M_UnitTester.cpp
 * 1. UnitTester will run the unit tests of each and every module, as long as
 * the module's "run-unit_tests()" function is called by (ie written in)
 * cl_unit_tester::run_unit_tests()"
 * 2. It also has console print functions for auto generation of unit test report.
 * 3. Note: unit testing of the UnitTester's functions itself is activated by
 * uncommenting out the line "#define TEST_UnitTester" in the "M_UnitTester.cpp" file.
 *
 *  Created on: 16 Nov 2022
 *      Author: John Chee
 */

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

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



#ifdef Unit_Test_Mode   //Code below runs during unit-testing mode

// ***** Note: Uncomment next line to unit_test UnitTester itself; otherwise it tests other modules.
//#define TEST_UnitTester_itself //when defined, UnitTester will test itself
// ***** -----------------------------------------------------------------*****

#ifndef TEST_UnitTester_itself
//ut=========================================================================ut
int main(){ //unit tester
    printf("Unit-testing: Project modules:\n"); //Sign on

    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN); //config for 50MHz clock

    cl_unit_tester oUnitTester; //Ctor
    oUnitTester.run_unit_tests_of_project_modules();

    while (1){
    }
}
//ut=========================================================================ut


#else
//Code below runs only when asked to test itself during unit-testing mode
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

#endif  //Unit_Test_Mode


