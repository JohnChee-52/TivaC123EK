/*
 * UT_Switch_Dbg.cpp
 * Perform unit tests on class functions of "cl_switch_dbg"
 *
 *  Created on: 1 Nov 2022
 *      Author: John Chee
 */
/*
 * M_Switch_Dbg.cpp
 * NTL uses 7 switches, of which 5 are user-accessible:
 * 1.  Sw_Pulse
 * 2.  Sw_TxRS485
 * 3.  Sw_PwrSense
 * 4.  Sw_Mute
 * 4.  Sw_AlmReset
 * The remaining 2 switches are PCBA mounted, for use during firmware development:
 * 1.  Sw_SysWakeup
 * 2.  Sw_SysMode
 *
 * Switches are connected to the GPIO pins as follows:
 * ------------------------------------------------|
 * GPIO|Pin|Config  |MCU Control/Input lines |TIVA |
 * ------------------------------------------------|
 * PB0 |p45|DI      |Sw3_Pulse_PB0           |J1p3 |
 * PB2 |p47|DI      |Sw4_TxRS485_PB2         |J2p2 |
 * PB7 |p4 |DI      |Sw6_PwrSense_PB7        |J2p6 |
 * PE0 |p9 |DI      |Sw5_Mute_PE0            |J2p3 |
 * PA4 |p21|DI      |Sw7_AlmReset_PA4        |J2p8 |
 * PF0 |p28|DI      |Sw2_SysWakeup_PF0       |J2p4 | TIVA RHS
 * PF4 |p5 |DI      |Sw1_SysMode_PF4         |J4p10| TIVA LHS
 * ------------------------------------------------|
 *
 *  Created on: 22 Jul 2021  rev M625
 *      Author: John Chee
 */
#include <assert.h>
#include <stdio.h>
#include "UT_Switch_Dbg.h"


//::cc-------------------------------------------------------------------------
cl_ut_switch_dbg::cl_ut_switch_dbg(){ //Ctor

}
//::cc-------------------------------------------------------------------------
//::---------------------------------------------------------------------------
void cl_ut_switch_dbg::run_unit_tests(){
    bool bF_Sw_Status;

    //-- Tx Report Header
    oReport.init_TrackCnt_function();
    oReport.prnLns_Hdr_TestReport("M_Switches", "19 Mar 2022");
    oReport.prnLn_ClassName("cl_switch_dbg");



//#define QUICK_test
#ifdef QUICK_test
    //qt***** Quick Test/Debug *****qt
    for (int i=0; i<10000; i++){
        bF_Sw_Status = oSw_Dbg.read_Level_SysMode(); //1 <- not pressed
        bF_Sw_Status = oSw_Dbg.read_Level_SysWakeup(); //1 <- not pressed
    }
    //qt****************************qt
#endif



    oReport.prnLn_Hdr_SubSection("//------- Test Switches");
    oReport.prnLn_CommentLine("//Pressing the switch & check the status expected ");


    oReport.prnLn_Hdr_SubSection("Sw_Pulse PB0");
    //-- Press & release Sw3_Pulse_PB0
    oReport.prnLn_Cnt_n_FnName_ET("bool read_Level_Pulse();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.read_Level_Pulse(); //1 <- not pressed
    bF_Sw_Status = oSw_Dbg.read_Level_Pulse(); //0 <- pressed
    bF_Sw_Status = oSw_Dbg.read_Level_Pulse(); //1 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_pressed_Pulse();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_pressed_Pulse(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_Pulse(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_Pulse(); //0 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_justPressed_Pulse();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justPressed_Pulse(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_Pulse(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_Pulse(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justPressed_Pulse(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_Pulse(); //0 <-  "


    oReport.prnLn_Cnt_n_FnName_ET("bool is_released_Pulse();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_released_Pulse(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_released_Pulse(); //0 <- not released
    bF_Sw_Status = oSw_Dbg.is_released_Pulse(); //1 <- released


    oReport.prnLn_Cnt_n_FnName_ET("bool is_justReleased_Pulse();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justReleased_Pulse(); //0 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_Pulse(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSw_Dbg.is_justReleased_Pulse(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_Pulse(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_Pulse(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_Pulse(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_Pulse(); //0 <-  "



    oReport.prnLn_Hdr_SubSection("Sw4_TxRS485_PB2");
    oReport.prnLn_Cnt_n_FnName_ET("bool read_Level_MonMode();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.read_Level_MonMode(); //1 <- not pressed
    bF_Sw_Status = oSw_Dbg.read_Level_MonMode(); //0 <- pressed
    bF_Sw_Status = oSw_Dbg.read_Level_MonMode(); //1 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_pressed_MonMode();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_pressed_MonMode(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_MonMode(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_MonMode(); //0 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_justPressed_MonMode();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justPressed_MonMode(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_MonMode(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_MonMode(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justPressed_MonMode(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_MonMode(); //0 <-  "


    oReport.prnLn_Cnt_n_FnName_ET("bool is_released_MonMode();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_released_MonMode(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_released_MonMode(); //0 <- not released
    bF_Sw_Status = oSw_Dbg.is_released_MonMode(); //1 <- released


    oReport.prnLn_Cnt_n_FnName_ET("bool is_released_MonMode();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justReleased_MonMode(); //0 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_MonMode(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSw_Dbg.is_justReleased_MonMode(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_MonMode(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_MonMode(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_MonMode(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_MonMode(); //0 <-  "



    oReport.prnLn_Hdr_SubSection("Sw6_PwrSense_PB7");
    oReport.prnLn_Cnt_n_FnName_ET("bool read_Level_PwrSense();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.read_Level_PwrSense(); //1 <- not pressed
    bF_Sw_Status = oSw_Dbg.read_Level_PwrSense(); //0 <- pressed
    bF_Sw_Status = oSw_Dbg.read_Level_PwrSense(); //1 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_pressed_PwrSense();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_pressed_PwrSense(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_PwrSense(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_PwrSense(); //0 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_justPressed_PwrSense();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justPressed_PwrSense(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_PwrSense(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_PwrSense(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justPressed_PwrSense(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_PwrSense(); //0 <-  "


    oReport.prnLn_Cnt_n_FnName_ET("bool is_released_PwrSense();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_released_PwrSense(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_released_PwrSense(); //0 <- not released
    bF_Sw_Status = oSw_Dbg.is_released_PwrSense(); //1 <- released


    oReport.prnLn_Cnt_n_FnName_ET("bool is_justReleased_PwrSense();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justReleased_PwrSense(); //0 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_PwrSense(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSw_Dbg.is_justReleased_PwrSense(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_PwrSense(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_PwrSense(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_PwrSense(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_PwrSense(); //0 <-  "



    oReport.prnLn_Hdr_SubSection("Sw5_Mute_PE0");
    oReport.prnLn_Cnt_n_FnName_ET("bool read_Level_Mute();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.read_Level_Mute(); //1 <- not pressed
    bF_Sw_Status = oSw_Dbg.read_Level_Mute(); //0 <- pressed
    bF_Sw_Status = oSw_Dbg.read_Level_Mute(); //1 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_pressed_Mute();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_pressed_Mute(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_Mute(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_Mute(); //0 <- not pressed

    oReport.prnLn_Cnt_n_FnName_ET("bool is_justPressed_Mute();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justPressed_Mute(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_Mute(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_Mute(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justPressed_Mute(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_Mute(); //0 <-  "


    oReport.prnLn_Cnt_n_FnName_ET("bool is_released_Mute();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_released_Mute(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_released_Mute(); //0 <- not released
    bF_Sw_Status = oSw_Dbg.is_released_Mute(); //1 <- released

    oReport.prnLn_Cnt_n_FnName_ET("bool is_justReleased_Mute();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justReleased_Mute(); //0 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_Mute(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSw_Dbg.is_justReleased_Mute(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_Mute(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_Mute(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_Mute(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_Mute(); //0 <-  "



    oReport.prnLn_Hdr_SubSection("Sw7_AlmReset_PA4");
    oReport.prnLn_Cnt_n_FnName_ET("bool read_Level_AlmReset();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.read_Level_AlmReset(); //1 <- not pressed
    bF_Sw_Status = oSw_Dbg.read_Level_AlmReset(); //0 <- pressed
    bF_Sw_Status = oSw_Dbg.read_Level_AlmReset(); //1 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_pressed_AlmReset();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_pressed_AlmReset(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_AlmReset(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_AlmReset(); //0 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_justPressed_AlmReset();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justPressed_AlmReset(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_AlmReset(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_AlmReset(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justPressed_AlmReset(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_AlmReset(); //0 <-  "


    oReport.prnLn_Cnt_n_FnName_ET("bool is_released_AlmReset();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_released_AlmReset(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_released_AlmReset(); //0 <- not released
    bF_Sw_Status = oSw_Dbg.is_released_AlmReset(); //1 <- released


    oReport.prnLn_Cnt_n_FnName_ET("bool is_justReleased_AlmReset();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justReleased_AlmReset(); //0 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_AlmReset(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSw_Dbg.is_justReleased_AlmReset(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_AlmReset(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_AlmReset(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_AlmReset(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_AlmReset(); //0 <-  "



    oReport.prnLn_Hdr_SubSection("Sw_SysWakeup PF0 TIVA RHS");
    oReport.prnLn_Cnt_n_FnName_ET("bool read_Level_SysWakeup();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.read_Level_SysWakeup(); //1 <- not pressed
    bF_Sw_Status = oSw_Dbg.read_Level_SysWakeup(); //0 <- pressed
    bF_Sw_Status = oSw_Dbg.read_Level_SysWakeup(); //1 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_pressed_SysWakeup();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_pressed_SysWakeup(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_SysWakeup(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_SysWakeup(); //0 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_justPressed_SysWakeup();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justPressed_SysWakeup(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_SysWakeup(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_SysWakeup(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justPressed_SysWakeup(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_SysWakeup(); //0 <-  "


    oReport.prnLn_Cnt_n_FnName_ET("bool is_released_SysWakeup();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_released_SysWakeup(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_released_SysWakeup(); //0 <- not released
    bF_Sw_Status = oSw_Dbg.is_released_SysWakeup(); //1 <- released


    oReport.prnLn_Cnt_n_FnName_ET("bool is_justReleased_SysWakeup();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysWakeup(); //0 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysWakeup(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysWakeup(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysWakeup(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysWakeup(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysWakeup(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysWakeup(); //0 <-  "



    oReport.prnLn_Hdr_SubSection("Sw_SysMode PF4 TIVA LHS");
    oReport.prnLn_Cnt_n_FnName_ET("bool read_Level_SysMode();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.read_Level_SysMode(); //1 <- not pressed
    bF_Sw_Status = oSw_Dbg.read_Level_SysMode(); //0 <- pressed
    bF_Sw_Status = oSw_Dbg.read_Level_SysMode(); //1 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_pressed_SysMode();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_pressed_SysMode(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_SysMode(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_pressed_SysMode(); //0 <- not pressed


    oReport.prnLn_Cnt_n_FnName_ET("bool is_justPressed_SysMode();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justPressed_SysMode(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_SysMode(); //1 <- pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_SysMode(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justPressed_SysMode(); //0 <- not pressed
    bF_Sw_Status = oSw_Dbg.is_justPressed_SysMode(); //0 <-  "


    oReport.prnLn_Cnt_n_FnName_ET("bool is_released_SysMode();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_released_SysMode(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_released_SysMode(); //0 <- not released
    bF_Sw_Status = oSw_Dbg.is_released_SysMode(); //1 <- released


    oReport.prnLn_Cnt_n_FnName_ET("bool is_justReleased_SysMode();"); //EdgeTest
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysMode(); //0 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysMode(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysMode(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysMode(); //1 <- released
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysMode(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysMode(); //0 <-  "
    bF_Sw_Status = oSw_Dbg.is_justReleased_SysMode(); //0 <-  "



    oReport.prnLn_Hdr_SubSection("Monitor Switches");
    uint8_t ui8_SwPressed_bitpat;
    bool bF_Status_SwPressed;

    oReport.prnLn_Cnt_n_FnName("void set_SwPressed_bitpat(uint8_t ui8Usr_Sw_BitPat);"); //EdgeTest
    oSw_Dbg.set_SwPressed_bitpat(0x3A);
    assert(oSw_Dbg.ui8_Switches_JustPressed_bitpat == 0x3A);


    oReport.prnLn_Cnt_n_FnName("void clr_SwPressed_bitpat();");
    oSw_Dbg.ui8_Switches_JustPressed_bitpat = 0x3A;
    oSw_Dbg.clr_SwPressed_bitpat();
    assert(oSw_Dbg.ui8_Switches_JustPressed_bitpat == 0x00);


    oReport.prnLn_Cnt_n_FnName("int8_t read_SwPressed_bitpat(); //Switch press sets a bit to 1"); //EdgeTest
    oSw_Dbg.ui8_Switches_JustPressed_bitpat = 0x71;
    ui8_SwPressed_bitpat = oSw_Dbg.read_SwPressed_bitpat();
    assert(oSw_Dbg.ui8_Switches_JustPressed_bitpat == 0x71);


    oReport.prnLn_Cnt_n_FnName("bool check_SwPressed_bitpat(); //>0 => 1 or more switch has been pressed"); //EdgeTest
    oSw_Dbg.ui8_Switches_JustPressed_bitpat = 0x05;
    bF_Status_SwPressed = oSw_Dbg.check_SwPressed_any();
    assert(bF_Status_SwPressed == true);

    oSw_Dbg.ui8_Switches_JustPressed_bitpat = 0x00;
    bF_Status_SwPressed = oSw_Dbg.check_SwPressed_any();
    assert(bF_Status_SwPressed == false);


    oReport.prnLn_Cnt_n_FnName("bool is_SwPressed_bitpat(); //1=a switch pressed, auto clear bitpat"); //EdgeTest
    oSw_Dbg.ui8_Switches_JustPressed_bitpat = 0x40;
    bF_Status_SwPressed = oSw_Dbg.is_SwPressed_any();
    assert(bF_Status_SwPressed == true);

    bF_Status_SwPressed = oSw_Dbg.is_SwPressed_any();
    assert(bF_Status_SwPressed == false);



    //----- Just to avoid warning "never used"
    if(bF_Sw_Status);
    ui8_SwPressed_bitpat++;

    oReport.prnLn_Hdr_SubSection("//=====----- Usage Example -----=====");
    oReport.prnLn_Cnt_n_FnName("Ex 1. Sense switch and show on UART0 via PuTTY");
    oReport.prnLns_Footer_TestReport();

    oReport.prnLn_CommentLine("Press any switch..");
    for (int i=0; i<0; i++){
        if(oSw_Dbg.is_justPressed_Pulse()){
//            oLED_Dbg.pulse_delay_Green_10ms();
            oReport.prnLn_CommentLine("Switch pressed - Pulse!");
        }
        if(oSw_Dbg.is_justPressed_AlmReset()){
//            oLED_Dbg.pulse_delay_BlueBright_10ms();
            oReport.prnLn_CommentLine("Switch pressed - AlmReset!");
        }
        if(oSw_Dbg.is_justPressed_TxRS485()){
//            oLED_Dbg.pulse_delay_Orange_10ms();
            oReport.prnLn_CommentLine("Switch pressed - Upload!");
        }
        if(oSw_Dbg.is_justPressed_Mute()){
//            oLED_Dbg.pulse_delay_Magenta_10ms();
//            oReport.prnLn_CommentLine("Switch pressed - MuteMode!");
        }
        if(oSw_Dbg.is_justPressed_PwrSense()){
//            oLED_Dbg.pulse_delay_Red_10ms();
            oReport.prnLn_CommentLine("Switch pressed - PwrSense!");
        }
        if(oSw_Dbg.is_justPressed_SysWakeup()){
//            oLED_Dbg.pulse_delay_Blue_10ms();
            oReport.prnLn_CommentLine("Switch pressed - SysWakeup!");
        }

        SysCtlDelay(300 * 7500);
    }
}
//=============================================================================



