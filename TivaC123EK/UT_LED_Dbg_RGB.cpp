/*
 * M_LED_Dbg_RGB.cpp
 * This module drives 3 LEDs, R G B to assist in debugging
 * Simple functions are provided for all 3 Leds
 *  - On, Off, Toggle, Pulse - x1, x2, x3
 * Each pulse is about 720ns using 50 MHz SysClk
 *
 * ------------------------------------------------|
 * GPIO|Pin|Config  |MCU Control/Input lines |TIVA |
 * ------------------------------------------------|
 * PF1 |p29|DO      |Drv_LED1_Red_PF1        |J3p10|
 * PF2 |p30|DO      |Drv_LED2_Blue_PF2       |J4p1 |
 * PF3 |p31|DO      |Drv_LED3_Green_PF3      |J4p2 |
 * ------------------------------------------------|
 * This module is designed to be used for debugging purposes. Functions
 * provided include:
 *  1)  Turning LEDs on/off, and combining their output into different colours.
 *  2)  Pulse functions are provided for real-time debugging. They have
 *      very short durations. Their colours are limited to:
 *      •   Red PF1     J3p10
 *      •   Green   PF3 J4p2
 *      •   Blue    PF2 J4p1.
 *  3)  The pulse_delay functions are useful for visual indication when
 *      debugging user interface. They are not meant for use in normal
 *      programs since SysCtlDelay() is used – which basically occupies
 *      MCU time doing nothing.
 *      Colours available include (10 colours):
 *        Red, Magenta, Orange, Yellow, Green, GreenBright, Turquoise,
 *        Blue, BlueBright, and White.
 *
 *  Created on: 28 Jul 2021 rev L820
 *      Author: John Chee
 */

#include <stdio.h>
#include "UT_LED_Dbg_RGB.h"

//::cc-------------------------------------------------------------------------
cl_ut_LEDs_Dbg_RGB::cl_ut_LEDs_Dbg_RGB(){ //Ctor

}
//::cc-------------------------------------------------------------------------
//::---------------------------------------------------------------------------
void cl_ut_LEDs_Dbg_RGB::unit_test_LEDs_Dbg_RGB(){

    //-- Tx Report Header
//    cl_uart0_PA oUART0_PA; //Ctor; RxD=PA0, TxD=PA1 BR=115200
//    oUART0_PA.init_TrackCnt_function();
//    oUART0_PA.tx_Hdr_TestReport("LED_Dbg_RGB", "28 Jul 2021");
//    oUART0_PA.tx_ClassName("cl_led_dbg_rgb");

    printf("LED_Dbg_RGB     28 Jul 2021 \n");
    printf("class: cl_led_dbg_rgb \n");
    printf("cl_led_dbg_rgb();//Ctor");
    cl_led_dbg_rgb oLED_Dbg; //Ctor


    printf("//-- Test Debug LEDs");
    printf("Visual Check LEDs for light up|off according to the instructions \n");//
    printf("For pulses, use oscilloscope set to trig on Normal Mode \n");//


    //----- Red LED -----------------------------------------------------------
    printf("//-- Red Debug Led        PF1    MCUp29  J1p10 \n");
    //-- Visual check
    printf("void on_Red(); \n");
    oLED_Dbg.on_Red();      //On


    printf("void off_Red(); \n");
    oLED_Dbg.off_Red();     //Off


    printf("void toggle_Red(); \n");
    oLED_Dbg.toggle_Red();  //On
    oLED_Dbg.toggle_Red();  //Off

    printf("void on_Red_while(bool bF_UserFlag); \n");
    oLED_Dbg.on_Red_while(1); //On  when flag is set
    oLED_Dbg.on_Red_while(0); //Off when flag is clr


    //-- Oscilloscope check
    printf("void pulse_Red();   //LHL H=720ns \n");
    oLED_Dbg.pulse_Red();   //x1 pulse; width 720ns


    printf("void pulse_x2_Red();//LHLHL \n");
    oLED_Dbg.pulse_x2_Red();//x2 pulses


    printf("void pulse_x3_Red();//LHLHLHL \n");
    oLED_Dbg.pulse_x3_Red();//x3 pulses


    //--- Pulse Red w SysCtlDelay(..)
    printf("void pulse_delay_Red_100us();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Red_100us(); //100us pulse


    printf("void pulse_delay_Red_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Red_us(300); //300us pulse


    printf("void pulse_delay_Red_10ms();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Red_10ms();//uses SysCtlDelay


    printf("void pulse_delay_Red_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Red_ms(30);//uses SysCtlDelay



    //----- Green LED ---------------------------------------------------------
    printf("//-- Green Debug Led      PF3     MCUp31  J4p2 \n");
    //-- Visual check
    printf("void on_Green(); \n");
    oLED_Dbg.on_Green();      //On


    printf("void off_Green(); \n");
    oLED_Dbg.off_Green();     //Off


    printf("void toggle_Green(); \n");
    oLED_Dbg.toggle_Green();  //On
    oLED_Dbg.toggle_Green();  //Off


    printf("void on_Green_while(bool bF_UserFlag); \n");
    oLED_Dbg.on_Green_while(1); //On
    oLED_Dbg.on_Green_while(0); //Off


    //-- Oscilloscope check
    printf("void pulse_Green(); \n");
    oLED_Dbg.pulse_Green();   //x1 pulse; width 720ns


    printf("void pulse_x2_Green(); \n");
    oLED_Dbg.pulse_x2_Green();//x2 pulses


    printf("void pulse_x3_Green(); \n");
    oLED_Dbg.pulse_x3_Green();//x3 pulses


    //--- Pulse Green w SysCtlDelay(..)
    printf("void pulse_delay_Green_100us();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Green_100us(); //100us pulse


    printf("void pulse_delay_Green_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Green_us(300); //300us pulse


    printf("void pulse_delay_Green_10ms();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Green_10ms();//uses SysCtlDelay


    printf("void pulse_delay_Green_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Green_ms(30);//uses SysCtlDelay



    //----- Blue LED ----------------------------------------------------------
    printf("//-- Blue Debug Led       PF2     MCUp30  J4p1 \n");
    //-- Visual check
    printf("void on_Blue(); \n");
    oLED_Dbg.on_Blue();      //On


    printf("void off_Blue(); \n");
    oLED_Dbg.off_Blue();     //Off


    printf("void toggle_Blue(); \n");
    oLED_Dbg.toggle_Blue();  //On
    oLED_Dbg.toggle_Blue();  //Off


    printf("void on_Blue_while(bool bF_UserFlag); \n");
    oLED_Dbg.on_Blue_while(1); //On
    oLED_Dbg.on_Blue_while(0); //Off


    //-- Oscilloscope check
    printf("void pulse_Blue(); \n");
    oLED_Dbg.pulse_Blue();   //x1 pulse; width 720ns


    printf("void pulse_x2_Blue(); \n");
    oLED_Dbg.pulse_x2_Blue();//x2 pulses


    printf("void pulse_x3_Blue(); \n");
    oLED_Dbg.pulse_x3_Blue();//x3 pulses


    //--- Pulse Blue w SysCtlDelay(..)
    printf("void pulse_delay_Blue_100us();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Blue_100us(); //100us pulse


    printf("void pulse_delay_Blue_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Blue_us(300); //300us pulse



    printf("void pulse_delay_Blue_10ms();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Blue_10ms();//uses SysCtlDelay


    printf("void pulse_delay_Blue_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Blue_ms(30);//uses SysCtlDelay



    printf("//-- --- Multiple LED combinations --- \n");
    printf("//-- Yellow LED (ie Red + Green) \n");
    printf("void pulse_delay_Yellow_100us();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Yellow_100us();//uses SysCtlDelay


    printf("void pulse_delay_Yellow_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Yellow_us(300); //uses SysCtlDelay


    printf("void pulse_delay_Yellow_10ms();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Yellow_10ms();//uses SysCtlDelay


    printf("void pulse_delay_Yellow_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Yellow_ms(300);//uses SysCtlDelay

    //---
    printf("//-- Magenta LED (ie Red + Blue) \n");


    printf("void pulse_delay_Magenta_100us();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Magenta_100us();//uses SysCtlDelay


    printf("void pulse_delay_Magenta_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Magenta_us(300); //uses SysCtlDelay


    printf("void pulse_delay_Magenta_10ms();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Magenta_10ms();//uses SysCtlDelay


    printf("void pulse_delay_Magenta_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Magenta_ms(300);//uses SysCtlDelay



    printf("//-- Turquoise LED (ie Green + Blue) \n");
    printf("void pulse_delay_Turquoise_100us();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Turquoise_100us();//uses SysCtlDelay


    printf("void pulse_delay_Turquoise_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Turquoise_us(300); //uses SysCtlDelay


    printf("void pulse_delay_Turqoise_10ms();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Turqoise_10ms();//uses SysCtlDelay


    printf("void pulse_delay_Turqoise_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Turqoise_ms(300);//uses SysCtlDelay



    printf("//-- White LED (ie Red + Green + Blue) \n");
    printf("void pulse_delay_White_100us();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_White_100us();//uses SysCtlDelay


    printf("void pulse_delay_White_us(uint16_t ui16Usr_Delay_us);//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_White_us(300); //uses SysCtlDelay


    printf("void pulse_delay_White_10ms();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_White_10ms();//uses SysCtlDelay


    printf("void pulse_delay_White_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_White_ms(300);//uses SysCtlDelay



    printf("//-- Orange LED (ie Red + 0.3*Green) \n");
    printf("void pulse_delay_Orange_10ms();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Orange_10ms();//uses SysCtlDelay


    printf("void pulse_delay_Orange_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_Orange_ms(300);//uses SysCtlDelay



    printf("//-- BlueBright LED (ie Blue + 0.3*Green) \n");
    printf("void pulse_delay_BlueBright_10ms();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_BlueBright_10ms();//uses SysCtlDelay


    printf("void pulse_delay_BlueBright_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_BlueBright_ms(300);//uses SysCtlDelay



    printf("//-- GreenBright LED (ie Green + 0.3*Blue) \n");
    printf("void pulse_delay_GreenBright_10ms();//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_GreenBright_10ms();//uses SysCtlDelay

    printf("void pulse_delay_GreenBright_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay \n");
    oLED_Dbg.pulse_delay_GreenBright_ms(800);//uses SysCtlDelay


    printf("//-- =====----- Usage Examples -----===== \n");
    printf("Ex 1. Static light up of LED - visually observable \n");
    oLED_Dbg.on_Red();
    oLED_Dbg.off_Red();
    oLED_Dbg.toggle_Red();  //On|Off

    oLED_Dbg.on_Green();
    oLED_Dbg.off_Green();
    oLED_Dbg.toggle_Green();  //On|Off

    oLED_Dbg.on_Blue();
    oLED_Dbg.off_Blue();
    oLED_Dbg.toggle_Blue();  //On|Off



    printf("Ex 2. Light up LED following a flag \n");
    bool bF_Variable = true; //variable indicator

    oLED_Dbg.on_Red_while(bF_Variable); //On  when flag is set
    bF_Variable = false;
    oLED_Dbg.on_Red_while(bF_Variable); //Off

    bF_Variable = true;
    oLED_Dbg.on_Green_while(bF_Variable); //On
    bF_Variable = false;
    oLED_Dbg.on_Green_while(bF_Variable); //On

    bF_Variable = true;
    oLED_Dbg.on_Blue_while(bF_Variable); //On
    bF_Variable = false;
    oLED_Dbg.on_Blue_while(bF_Variable); //On



    printf("Ex 3. Blink LED in 10-colour sequence (using SysCtlDelay()) - visually observable \n");
//    oUART0_PA.tx_Footer_TestReport();

    while(1){
        //----- Indicator pulse
        oLED_Dbg.pulse_delay_Red_ms(300);//uses SysCtlDelay
        oLED_Dbg.pulse_delay_Green_ms(300);//uses SysCtlDelay
        oLED_Dbg.pulse_delay_Blue_ms(300);//uses SysCtlDelay

        oLED_Dbg.pulse_delay_Yellow_ms(300);//uses SysCtlDelay
        oLED_Dbg.pulse_delay_Magenta_ms(300);//uses SysCtlDelay
        oLED_Dbg.pulse_delay_Turqoise_ms(300);//uses SysCtlDelay
        oLED_Dbg.pulse_delay_White_ms(300);//uses SysCtlDelay
        oLED_Dbg.pulse_delay_Orange_ms(300);//uses SysCtlDelay
        oLED_Dbg.pulse_delay_BlueBright_ms(300);//uses SysCtlDelay
        oLED_Dbg.pulse_delay_GreenBright_ms(800);//uses SysCtlDelay

    }
}
//=============================================================================
