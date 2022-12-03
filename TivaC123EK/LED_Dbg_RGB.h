/*
 * LED_Dbg_RGB.h
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

#ifndef LED_DBG_RGB_H_
#define LED_DBG_RGB_H_

//#include "Unit_Test_Mode.h"
#include "TM4C123GH6PM_Config_Pins.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class cl_led_dbg_rgb : cl_tm4c123gh6pm_pins{
private:
protected:
    static uint16_t ui16_Blink_cnt;  //Default Blink Cnt
    static uint16_t ui16_Dur_ms; //Default ON duration (ms)
    static uint32_t ui32_Period_ms; //Default Period in a repeat cycle (ms)
    static bool bF_TrigBlink; //1=trigger blinking process
public:

    cl_led_dbg_rgb();//Ctor

    //--- Red Led       PF1    MCUp29  J1p10
    void on_Red();
    void off_Red();
    void toggle_Red();
    void on_Red_while(bool bF_UserFlag);

    void pulse_Red();   //LHL H=720ns
    void pulse_x2_Red();//LHLHL
    void pulse_x3_Red();//LHLHLHL
    void pulse_delay_Red_100us();//uses SysCtlDelay
    void pulse_delay_Red_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay
    void pulse_delay_Red_10ms();//uses SysCtlDelay
    void pulse_delay_Red_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay


    //--- Green Led     PF3     MCUp31  J4p2
    void on_Green();
    void off_Green();
    void toggle_Green();
    void on_Green_while(bool bF_UserFlag);

    void pulse_Green();
    void pulse_x2_Green();
    void pulse_x3_Green();
    void pulse_delay_Green_100us();//uses SysCtlDelay
    void pulse_delay_Green_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay
    void pulse_delay_Green_10ms();//uses SysCtlDelay
    void pulse_delay_Green_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay


    //--- Blue Led      PF2     MCUp30  J4p1
    void on_Blue();
    void off_Blue();
    void toggle_Blue();
    void on_Blue_while(bool bF_UserFlag);

    void pulse_Blue();
    void pulse_x2_Blue();
    void pulse_x3_Blue();
    void pulse_delay_Blue_100us();//uses SysCtlDelay
    void pulse_delay_Blue_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay
    void pulse_delay_Blue_10ms();//uses SysCtlDelay
    void pulse_delay_Blue_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay


    //------- Multiple LED combinations
    //--- Yellow (ie Red + Green)
    void pulse_delay_Yellow_100us();//uses SysCtlDelay
    void pulse_delay_Yellow_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay
    void pulse_delay_Yellow_10ms();//uses SysCtlDelay
    void pulse_delay_Yellow_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay

    //--- Magenta (ie Red + Blue)
    void pulse_delay_Magenta_100us();//uses SysCtlDelay
    void pulse_delay_Magenta_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay
    void pulse_delay_Magenta_10ms();//uses SysCtlDelay
    void pulse_delay_Magenta_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay

    //--- Turquoise (ie Green + Blue)
    void pulse_delay_Turquoise_100us();//uses SysCtlDelay
    void pulse_delay_Turquoise_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay
    void pulse_delay_Turqoise_10ms();//uses SysCtlDelay
    void pulse_delay_Turqoise_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay

    //--- White (ie Red + Green + Blue)
    void pulse_delay_White_100us();//uses SysCtlDelay
    void pulse_delay_White_us(uint16_t ui16Usr_Delay_us); //uses SysCtlDelay
    void pulse_delay_White_10ms();//uses SysCtlDelay
    void pulse_delay_White_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay


    //--- Orange (ie Red + 0.3*Green)
    void pulse_delay_Orange_10ms();//uses SysCtlDelay
    void pulse_delay_Orange_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay


    //--- BlueBright (ie Blue + 0.3*Green)
    void pulse_delay_BlueBright_10ms();//uses SysCtlDelay
    void pulse_delay_BlueBright_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay


    //--- GreenBright (ie Green + 0.3*Blue)
    void pulse_delay_GreenBright_10ms();//uses SysCtlDelay
    void pulse_delay_GreenBright_ms(uint16_t ui16Usr_Delay_ms);//uses SysCtlDelay

};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



#endif /* LED_DBG_RGB_H_ */
