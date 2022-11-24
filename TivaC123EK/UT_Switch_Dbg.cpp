/*
 * UT_Switch_Dbg.cpp
 *
 *  Created on: 1 Nov 2022
 *      Author: John Chee
 */

/*
 * M_Switches.cpp
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
#include "Switch_Dbg.h"

//=============================================================================
int main(void){
    bool bF_Sw_Status;

    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN); //config for 50MHz clock

    cl_led_dbg_rgb oLED_Dbg; //Ctor

    //-- Tx Report Header
    cl_uart0_PA oUART0_PA; //Ctor; RxD=PA0, TxD=PA1 BR=115200
    oUART0_PA.init_TrackCnt_function();
    oUART0_PA.tx_Hdr_TestReport("M_Switches", "19 Mar 2022");
    oUART0_PA.tx_ClassName("cl_switches");


    cl_switches oSwitch; //Ctor

//#define QUICK_test
#ifdef QUICK_test
    //qt***** Quick Test/Debug *****qt
    for (int i=0; i<10000; i++){
        bF_Sw_Status = oSwitch.read_Level_SysMode(); //1 <- not pressed
        bF_Sw_Status = oSwitch.read_Level_SysWakeup(); //1 <- not pressed
    }
    //qt****************************qt
#endif



    oUART0_PA.tx_Hdr_SubSection("//------- Test Switches");
    oUART0_PA.tx_StrLn("//Pressing the switch & check the status expected ");


    oUART0_PA.tx_Hdr_SubSection("Sw_Pulse PB0");
    //-- Press & release Sw3_Pulse_PB0
    oUART0_PA.tx_Cnt_n_FnName_ET("bool read_Level_Pulse();"); //EdgeTest
    bF_Sw_Status = oSwitch.read_Level_Pulse(); //1 <- not pressed
    bF_Sw_Status = oSwitch.read_Level_Pulse(); //0 <- pressed
    bF_Sw_Status = oSwitch.read_Level_Pulse(); //1 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_pressed_Pulse();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_pressed_Pulse(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_pressed_Pulse(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_pressed_Pulse(); //0 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justPressed_Pulse();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justPressed_Pulse(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_Pulse(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_justPressed_Pulse(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justPressed_Pulse(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_Pulse(); //0 <-  "


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_released_Pulse();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_released_Pulse(); //1 <- released
    bF_Sw_Status = oSwitch.is_released_Pulse(); //0 <- not released
    bF_Sw_Status = oSwitch.is_released_Pulse(); //1 <- released


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justReleased_Pulse();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justReleased_Pulse(); //0 <- released
    bF_Sw_Status = oSwitch.is_justReleased_Pulse(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSwitch.is_justReleased_Pulse(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_Pulse(); //1 <- released
    bF_Sw_Status = oSwitch.is_justReleased_Pulse(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_Pulse(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_Pulse(); //0 <-  "



    oUART0_PA.tx_Hdr_SubSection("Sw4_TxRS485_PB2");
    oUART0_PA.tx_Cnt_n_FnName_ET("bool read_Level_MonMode();"); //EdgeTest
    bF_Sw_Status = oSwitch.read_Level_MonMode(); //1 <- not pressed
    bF_Sw_Status = oSwitch.read_Level_MonMode(); //0 <- pressed
    bF_Sw_Status = oSwitch.read_Level_MonMode(); //1 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_pressed_MonMode();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_pressed_MonMode(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_pressed_MonMode(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_pressed_MonMode(); //0 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justPressed_MonMode();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justPressed_MonMode(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_MonMode(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_justPressed_MonMode(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justPressed_MonMode(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_MonMode(); //0 <-  "


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_released_MonMode();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_released_MonMode(); //1 <- released
    bF_Sw_Status = oSwitch.is_released_MonMode(); //0 <- not released
    bF_Sw_Status = oSwitch.is_released_MonMode(); //1 <- released


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_released_MonMode();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justReleased_MonMode(); //0 <- released
    bF_Sw_Status = oSwitch.is_justReleased_MonMode(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSwitch.is_justReleased_MonMode(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_MonMode(); //1 <- released
    bF_Sw_Status = oSwitch.is_justReleased_MonMode(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_MonMode(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_MonMode(); //0 <-  "



    oUART0_PA.tx_Hdr_SubSection("Sw6_PwrSense_PB7");
    oUART0_PA.tx_Cnt_n_FnName_ET("bool read_Level_PwrSense();"); //EdgeTest
    bF_Sw_Status = oSwitch.read_Level_PwrSense(); //1 <- not pressed
    bF_Sw_Status = oSwitch.read_Level_PwrSense(); //0 <- pressed
    bF_Sw_Status = oSwitch.read_Level_PwrSense(); //1 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_pressed_PwrSense();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_pressed_PwrSense(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_pressed_PwrSense(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_pressed_PwrSense(); //0 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justPressed_PwrSense();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justPressed_PwrSense(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_PwrSense(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_justPressed_PwrSense(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justPressed_PwrSense(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_PwrSense(); //0 <-  "


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_released_PwrSense();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_released_PwrSense(); //1 <- released
    bF_Sw_Status = oSwitch.is_released_PwrSense(); //0 <- not released
    bF_Sw_Status = oSwitch.is_released_PwrSense(); //1 <- released


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justReleased_PwrSense();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justReleased_PwrSense(); //0 <- released
    bF_Sw_Status = oSwitch.is_justReleased_PwrSense(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSwitch.is_justReleased_PwrSense(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_PwrSense(); //1 <- released
    bF_Sw_Status = oSwitch.is_justReleased_PwrSense(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_PwrSense(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_PwrSense(); //0 <-  "



    oUART0_PA.tx_Hdr_SubSection("Sw5_Mute_PE0");
    oUART0_PA.tx_Cnt_n_FnName_ET("bool read_Level_Mute();"); //EdgeTest
    bF_Sw_Status = oSwitch.read_Level_Mute(); //1 <- not pressed
    bF_Sw_Status = oSwitch.read_Level_Mute(); //0 <- pressed
    bF_Sw_Status = oSwitch.read_Level_Mute(); //1 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_pressed_Mute();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_pressed_Mute(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_pressed_Mute(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_pressed_Mute(); //0 <- not pressed

    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justPressed_Mute();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justPressed_Mute(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_Mute(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_justPressed_Mute(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justPressed_Mute(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_Mute(); //0 <-  "


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_released_Mute();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_released_Mute(); //1 <- released
    bF_Sw_Status = oSwitch.is_released_Mute(); //0 <- not released
    bF_Sw_Status = oSwitch.is_released_Mute(); //1 <- released

    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justReleased_Mute();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justReleased_Mute(); //0 <- released
    bF_Sw_Status = oSwitch.is_justReleased_Mute(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSwitch.is_justReleased_Mute(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_Mute(); //1 <- released
    bF_Sw_Status = oSwitch.is_justReleased_Mute(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_Mute(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_Mute(); //0 <-  "



    oUART0_PA.tx_Hdr_SubSection("Sw7_AlmReset_PA4");
    oUART0_PA.tx_Cnt_n_FnName_ET("bool read_Level_AlmReset();"); //EdgeTest
    bF_Sw_Status = oSwitch.read_Level_AlmReset(); //1 <- not pressed
    bF_Sw_Status = oSwitch.read_Level_AlmReset(); //0 <- pressed
    bF_Sw_Status = oSwitch.read_Level_AlmReset(); //1 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_pressed_AlmReset();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_pressed_AlmReset(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_pressed_AlmReset(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_pressed_AlmReset(); //0 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justPressed_AlmReset();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justPressed_AlmReset(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_AlmReset(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_justPressed_AlmReset(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justPressed_AlmReset(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_AlmReset(); //0 <-  "


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_released_AlmReset();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_released_AlmReset(); //1 <- released
    bF_Sw_Status = oSwitch.is_released_AlmReset(); //0 <- not released
    bF_Sw_Status = oSwitch.is_released_AlmReset(); //1 <- released


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justReleased_AlmReset();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justReleased_AlmReset(); //0 <- released
    bF_Sw_Status = oSwitch.is_justReleased_AlmReset(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSwitch.is_justReleased_AlmReset(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_AlmReset(); //1 <- released
    bF_Sw_Status = oSwitch.is_justReleased_AlmReset(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_AlmReset(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_AlmReset(); //0 <-  "



    oUART0_PA.tx_Hdr_SubSection("Sw_SysWakeup PF0 TIVA RHS");
    oUART0_PA.tx_Cnt_n_FnName_ET("bool read_Level_SysWakeup();"); //EdgeTest
    bF_Sw_Status = oSwitch.read_Level_SysWakeup(); //1 <- not pressed
    bF_Sw_Status = oSwitch.read_Level_SysWakeup(); //0 <- pressed
    bF_Sw_Status = oSwitch.read_Level_SysWakeup(); //1 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_pressed_SysWakeup();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_pressed_SysWakeup(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_pressed_SysWakeup(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_pressed_SysWakeup(); //0 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justPressed_SysWakeup();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justPressed_SysWakeup(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_SysWakeup(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_justPressed_SysWakeup(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justPressed_SysWakeup(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_SysWakeup(); //0 <-  "


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_released_SysWakeup();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_released_SysWakeup(); //1 <- released
    bF_Sw_Status = oSwitch.is_released_SysWakeup(); //0 <- not released
    bF_Sw_Status = oSwitch.is_released_SysWakeup(); //1 <- released


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justReleased_SysWakeup();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justReleased_SysWakeup(); //0 <- released
    bF_Sw_Status = oSwitch.is_justReleased_SysWakeup(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSwitch.is_justReleased_SysWakeup(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_SysWakeup(); //1 <- released
    bF_Sw_Status = oSwitch.is_justReleased_SysWakeup(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_SysWakeup(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_SysWakeup(); //0 <-  "



    oUART0_PA.tx_Hdr_SubSection("Sw_SysMode PF4 TIVA LHS");
    oUART0_PA.tx_Cnt_n_FnName_ET("bool read_Level_SysMode();"); //EdgeTest
    bF_Sw_Status = oSwitch.read_Level_SysMode(); //1 <- not pressed
    bF_Sw_Status = oSwitch.read_Level_SysMode(); //0 <- pressed
    bF_Sw_Status = oSwitch.read_Level_SysMode(); //1 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_pressed_SysMode();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_pressed_SysMode(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_pressed_SysMode(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_pressed_SysMode(); //0 <- not pressed


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justPressed_SysMode();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justPressed_SysMode(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_SysMode(); //1 <- pressed
    bF_Sw_Status = oSwitch.is_justPressed_SysMode(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justPressed_SysMode(); //0 <- not pressed
    bF_Sw_Status = oSwitch.is_justPressed_SysMode(); //0 <-  "


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_released_SysMode();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_released_SysMode(); //1 <- released
    bF_Sw_Status = oSwitch.is_released_SysMode(); //0 <- not released
    bF_Sw_Status = oSwitch.is_released_SysMode(); //1 <- released


    oUART0_PA.tx_Cnt_n_FnName_ET("bool is_justReleased_SysMode();"); //EdgeTest
    bF_Sw_Status = oSwitch.is_justReleased_SysMode(); //0 <- released
    bF_Sw_Status = oSwitch.is_justReleased_SysMode(); //0 <- not released (ie =pressed)
    bF_Sw_Status = oSwitch.is_justReleased_SysMode(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_SysMode(); //1 <- released
    bF_Sw_Status = oSwitch.is_justReleased_SysMode(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_SysMode(); //0 <-  "
    bF_Sw_Status = oSwitch.is_justReleased_SysMode(); //0 <-  "



    oUART0_PA.tx_Hdr_SubSection("Monitor Switches");
    uint8_t ui8_SwPressed_bitpat;
    bool bF_Status_SwPressed;

    oUART0_PA.tx_Cnt_n_FnName("void set_SwPressed_bitpat(uint8_t ui8Usr_Sw_BitPat);"); //EdgeTest
    oSwitch.set_SwPressed_bitpat(0x3A);
    assert(oSwitch.ui8_Switches_JustPressed_bitpat == 0x3A);


    oUART0_PA.tx_Cnt_n_FnName("void clr_SwPressed_bitpat();");
    oSwitch.ui8_Switches_JustPressed_bitpat = 0x3A;
    oSwitch.clr_SwPressed_bitpat();
    assert(oSwitch.ui8_Switches_JustPressed_bitpat == 0x00);


    oUART0_PA.tx_Cnt_n_FnName("int8_t read_SwPressed_bitpat(); //Switch press sets a bit to 1"); //EdgeTest
    oSwitch.ui8_Switches_JustPressed_bitpat = 0x71;
    ui8_SwPressed_bitpat = oSwitch.read_SwPressed_bitpat();
    assert(oSwitch.ui8_Switches_JustPressed_bitpat == 0x71);


    oUART0_PA.tx_Cnt_n_FnName("bool check_SwPressed_bitpat(); //>0 => 1 or more switch has been pressed"); //EdgeTest
    oSwitch.ui8_Switches_JustPressed_bitpat = 0x05;
    bF_Status_SwPressed = oSwitch.check_SwPressed_any();
    assert(bF_Status_SwPressed == true);

    oSwitch.ui8_Switches_JustPressed_bitpat = 0x00;
    bF_Status_SwPressed = oSwitch.check_SwPressed_any();
    assert(bF_Status_SwPressed == false);


    oUART0_PA.tx_Cnt_n_FnName("bool is_SwPressed_bitpat(); //1=a switch pressed, auto clear bitpat"); //EdgeTest
    oSwitch.ui8_Switches_JustPressed_bitpat = 0x40;
    bF_Status_SwPressed = oSwitch.is_SwPressed_any();
    assert(bF_Status_SwPressed == true);

    bF_Status_SwPressed = oSwitch.is_SwPressed_any();
    assert(bF_Status_SwPressed == false);



    //----- Just to avoid warning "never used"
    if(bF_Sw_Status);
    ui8_SwPressed_bitpat++;


    oUART0_PA.tx_Hdr_SubSection("//=====----- Usage Example -----=====");
    oUART0_PA.tx_Cnt_n_FnName("Ex 1. Sense switch and show on UART0 via PuTTY");
    oUART0_PA.tx_Footer_TestReport();

    oUART0_PA.tx_StrLn("Press any switch..");
    while(1){
        if(oSwitch.is_pressed_Pulse()){
            oLED_Dbg.pulse_delay_Green_10ms();
            oUART0_PA.tx_StrLn("Switch pressed - Pulse!");
        }
        if(oSwitch.is_pressed_AlmReset()){
            oLED_Dbg.pulse_delay_BlueBright_10ms();
            oUART0_PA.tx_StrLn("Switch pressed - AlmReset!");
        }
        if(oSwitch.is_pressed_TxRS485()){
            oLED_Dbg.pulse_delay_Orange_10ms();
            oUART0_PA.tx_StrLn("Switch pressed - Upload!");
        }
        if(oSwitch.is_pressed_Mute()){
            oLED_Dbg.pulse_delay_Magenta_10ms();
//            oUART0_PA.tx_StrLn("Switch pressed - MuteMode!");
        }
        if(oSwitch.is_pressed_PwrSense()){
            oLED_Dbg.pulse_delay_Red_10ms();
            oUART0_PA.tx_StrLn("Switch pressed - PwrSense!");
        }
        if(oSwitch.is_pressed_SysWakeup()){
            oLED_Dbg.pulse_delay_Blue_10ms();
            oUART0_PA.tx_StrLn("Switch pressed - SysWakeup!");
        }

        SysCtlDelay(300 * 7500);
    }
}
//=============================================================================



