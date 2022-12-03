/*
 * LED_Dbg_RGB.cpp
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
#include "LED_Dbg_RGB.h"

//..... Instantiate Static Variables ..........................................
//.............................................................................

//::cc-------------------------------------------------------------------------
cl_led_dbg_rgb::cl_led_dbg_rgb(){//Ctor

}
//::cc-------------------------------------------------------------------------


//--- Red Led       PF1    MCUp29  J1p10
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::on_Red(){
    drv_H_PF1();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::off_Red(){
    drv_L_PF1();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_Red(){
    drv_L_PF1();
    drv_H_PF1();
    drv_L_PF1();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_x2_Red(){
    drv_L_PF1();
    drv_H_PF1();
    drv_L_PF1();
    drv_H_PF1();
    drv_L_PF1();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_x3_Red(){
    drv_L_PF1();
    drv_H_PF1();
    drv_L_PF1();
    drv_H_PF1();
    drv_L_PF1();
    drv_H_PF1();
    drv_L_PF1();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::toggle_Red(){
    is_H_PF1() ? drv_L_PF1() :  drv_H_PF1();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Red_100us(){//uses SysCtlDelay
    drv_L_PF1();
    drv_H_PF1();
    SysCtlDelay(750);
    drv_L_PF1();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Red_us(uint16_t ui16Usr_Delay_us){ //uses SysCtlDelay
    drv_L_PF1();
    drv_H_PF1();
    SysCtlDelay(ui16Usr_Delay_us*15);
    drv_L_PF1();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Red_10ms(){//uses SysCtlDelay
    drv_L_PF1();
    drv_H_PF1();
    SysCtlDelay(10*7500);
    drv_L_PF1();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Red_ms(uint16_t ui16Usr_Delay_ms){//uses SysCtlDelay
    drv_L_PF1();
    drv_H_PF1();
    SysCtlDelay(ui16Usr_Delay_ms*7500);
    drv_L_PF1();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::on_Red_while(bool bF_UserFlag){
    bF_UserFlag ? drv_H_PF1() : drv_L_PF1();
}
//::---------------------------------------------------------------------------



//--- Green Led     PF3     MCUp31  J4p2
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::on_Green(){
    drv_H_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::off_Green(){
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_Green(){
    drv_L_PF3();
    drv_H_PF3();
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_x2_Green(){
    drv_L_PF3();
    drv_H_PF3();
    drv_L_PF3();
    drv_H_PF3();
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_x3_Green(){
    drv_L_PF3();
    drv_H_PF3();
    drv_L_PF3();
    drv_H_PF3();
    drv_L_PF3();
    drv_H_PF3();
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::toggle_Green(){
    is_H_PF3() ? drv_L_PF3() :  drv_H_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Green_100us(){//uses SysCtlDelay
    drv_L_PF3();
    drv_H_PF3();
    SysCtlDelay(750);
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Green_us(uint16_t ui16Usr_Delay_us){ //uses SysCtlDelay
    drv_L_PF3();
    drv_H_PF3();
    SysCtlDelay(ui16Usr_Delay_us*15);
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Green_10ms(){//uses SysCtlDelay
    drv_L_PF3();
    drv_H_PF3();
    SysCtlDelay(10*7500);
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Green_ms(uint16_t ui16Usr_Delay_ms){//uses SysCtlDelay
    drv_L_PF3();
    drv_H_PF3();
    SysCtlDelay(ui16Usr_Delay_ms*7500);
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::on_Green_while(bool bF_UserFlag){
    bF_UserFlag ? drv_H_PF3() : drv_L_PF3();
}
//::---------------------------------------------------------------------------


//--- Blue Led       PF1    MCUp29  J1p10
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::on_Blue(){
    drv_H_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::off_Blue(){
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_Blue(){
    drv_L_PF2();
    drv_H_PF2();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_x2_Blue(){
    drv_L_PF2();
    drv_H_PF2();
    drv_L_PF2();
    drv_H_PF2();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_x3_Blue(){
    drv_L_PF2();
    drv_H_PF2();
    drv_L_PF2();
    drv_H_PF2();
    drv_L_PF2();
    drv_H_PF2();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::toggle_Blue(){
    is_H_PF2() ? drv_L_PF2() :  drv_H_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Blue_100us(){//uses SysCtlDelay
    drv_L_PF2();
    drv_H_PF2();
    SysCtlDelay(750);
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Blue_10ms(){//uses SysCtlDelay
    drv_L_PF2();
    drv_H_PF2();
    SysCtlDelay(10*7500);
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Blue_us(uint16_t ui16Usr_Delay_us){ //uses SysCtlDelay
    drv_L_PF2();
    drv_H_PF2();
    SysCtlDelay(ui16Usr_Delay_us*15);
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Blue_ms(uint16_t ui16Usr_Delay_ms){//uses SysCtlDelay
    drv_L_PF2();
    drv_H_PF2();
    SysCtlDelay(ui16Usr_Delay_ms*7500);
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::on_Blue_while(bool bF_UserFlag){
    bF_UserFlag ? drv_H_PF2() : drv_L_PF2();
}
//::---------------------------------------------------------------------------

//------- Multiple LED combinations
//--- Yellow (ie Red + Green)
void cl_led_dbg_rgb::pulse_delay_Yellow_100us(){//uses SysCtlDelay
    drv_L_PF1();
    drv_L_PF3();
    drv_H_PF1();
    drv_H_PF3();
    SysCtlDelay(750);
    drv_L_PF1();
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Yellow_us(uint16_t ui16Usr_Delay_us){ //uses SysCtlDelay
    drv_L_PF1();
    drv_L_PF3();
    drv_H_PF1();
    drv_H_PF3();
    SysCtlDelay(ui16Usr_Delay_us*15);
    drv_L_PF1();
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Yellow_10ms(){//uses SysCtlDelay
    drv_L_PF1();
    drv_L_PF3();
    drv_H_PF1();
    drv_H_PF3();
    SysCtlDelay(10*7500);
    drv_L_PF1();
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Yellow_ms(uint16_t ui16Usr_Delay_ms){//uses SysCtlDelay
    drv_L_PF1();
    drv_L_PF3();
    drv_H_PF1();
    drv_H_PF3();
     SysCtlDelay(ui16Usr_Delay_ms*7500);
    drv_L_PF1();
    drv_L_PF3();
}
//::---------------------------------------------------------------------------

//--- Magenta (ie Red + Blue)
void cl_led_dbg_rgb::pulse_delay_Magenta_100us(){//uses SysCtlDelay
    drv_L_PF1();
    drv_L_PF2();
    drv_H_PF1();
    drv_H_PF2();
    SysCtlDelay(750);
    drv_L_PF1();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Magenta_us(uint16_t ui16Usr_Delay_us){ //uses SysCtlDelay
    drv_L_PF1();
    drv_L_PF2();
    drv_H_PF1();
    drv_H_PF2();
    SysCtlDelay(ui16Usr_Delay_us*15);
    drv_L_PF1();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Magenta_10ms(){//uses SysCtlDelay
    drv_L_PF1();
    drv_L_PF2();
    drv_H_PF1();
    drv_H_PF2();
    SysCtlDelay(10*7500);
    drv_L_PF1();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Magenta_ms(uint16_t ui16Usr_Delay_ms){//uses SysCtlDelay
    drv_L_PF1();
    drv_L_PF2();
    drv_H_PF1();
    drv_H_PF2();
    SysCtlDelay(ui16Usr_Delay_ms*7500);
    drv_L_PF1();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------

//--- Turquoise (ie Green + Blue)
void cl_led_dbg_rgb::pulse_delay_Turquoise_100us(){//uses SysCtlDelay
    drv_L_PF3();
    drv_L_PF2();
    drv_H_PF3();
    drv_H_PF2();
    SysCtlDelay(750);
    drv_L_PF3();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Turquoise_us(uint16_t ui16Usr_Delay_us){ //uses SysCtlDelay
    drv_L_PF3();
    drv_L_PF2();
    drv_H_PF3();
    drv_H_PF2();
    SysCtlDelay(ui16Usr_Delay_us*15);
    drv_L_PF3();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Turqoise_10ms(){//uses SysCtlDelay
    drv_L_PF3();
    drv_L_PF2();
    drv_H_PF3();
    drv_H_PF2();
    SysCtlDelay(10*7500);
    drv_L_PF3();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Turqoise_ms(uint16_t ui16Usr_Delay_ms){//uses SysCtlDelay
    drv_L_PF3();
    drv_L_PF2();
    drv_H_PF3();
    drv_H_PF2();
    SysCtlDelay(ui16Usr_Delay_ms*7500);
    drv_L_PF3();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------

//--- White (ie Red + Green + Blue)
void cl_led_dbg_rgb::pulse_delay_White_100us(){//uses SysCtlDelay
    drv_L_PF1();
    drv_L_PF3();
    drv_L_PF2();
    drv_H_PF1();
    drv_H_PF3();
    drv_H_PF2();
    SysCtlDelay(750);
    drv_L_PF1();
    drv_L_PF3();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_White_us(uint16_t ui16Usr_Delay_us){ //uses SysCtlDelay
    drv_L_PF1();
    drv_L_PF3();
    drv_L_PF2();
    drv_H_PF1();
    drv_H_PF3();
    drv_H_PF2();
    SysCtlDelay(ui16Usr_Delay_us*15);
    drv_L_PF1();
    drv_L_PF3();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_White_10ms(){//uses SysCtlDelay
    drv_L_PF1();
    drv_L_PF3();
    drv_L_PF2();
    drv_H_PF1();
    drv_H_PF3();
    drv_H_PF2();
    SysCtlDelay(10*7500);
    drv_L_PF1();
    drv_L_PF3();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_White_ms(uint16_t ui16Usr_Delay_ms){//uses SysCtlDelay
    drv_L_PF1();
    drv_L_PF3();
    drv_L_PF2();
    drv_H_PF1();
    drv_H_PF3();
    drv_H_PF2();
    SysCtlDelay(ui16Usr_Delay_ms*7500);
    drv_L_PF1();
    drv_L_PF3();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------

//--- Orange (ie Red + 0.5*Green)
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Orange_10ms(){//uses SysCtlDelay{
    drv_L_PF1();
    drv_L_PF3();
    drv_H_PF1();
    for(int i=0; i<10; i++){ //10x 1ms pulses
        drv_H_PF3();
        SysCtlDelay(3*750);
        drv_L_PF3();
        SysCtlDelay(7*750);
    }
    drv_L_PF1();
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_Orange_ms(uint16_t ui16Usr_Delay_ms){//uses SysCtlDelay{
    drv_L_PF1();
    drv_L_PF3();
    drv_H_PF1();
    for(int i=0; i<ui16Usr_Delay_ms; i++){
        drv_H_PF3();
        SysCtlDelay(3*750);
        drv_L_PF3();
        SysCtlDelay(7*750);
    }
    drv_L_PF1();
    drv_L_PF3();
}
//::---------------------------------------------------------------------------

//--- BlueBright (ie Blue + 0.3*Green)
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_BlueBright_10ms(){//uses SysCtlDelay
    drv_L_PF2();
    drv_L_PF3();
    drv_H_PF2();
    for(int i=0; i<10; i++){
        drv_H_PF3();
        SysCtlDelay(3*750);
        drv_L_PF3();
        SysCtlDelay(7*750);
    }
    drv_L_PF2();
    drv_L_PF3();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_BlueBright_ms(uint16_t ui16Usr_Delay_ms){//uses SysCtlDelay
    drv_L_PF2();
    drv_L_PF3();
    drv_H_PF2();
    for(int i=0; i<ui16Usr_Delay_ms; i++){
        drv_H_PF3();
        SysCtlDelay(3*750);
        drv_L_PF3();
        SysCtlDelay(7*750);
    }
    drv_L_PF2();
    drv_L_PF3();
}
//::---------------------------------------------------------------------------

//--- GreenBright (ie Green + 0.3*Blue)
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_GreenBright_10ms(){//uses SysCtlDelay
    drv_L_PF3();
    drv_L_PF2();
    drv_H_PF3();
    for(int i=0; i<10; i++){
        drv_H_PF2();
        SysCtlDelay(3*750);
        drv_L_PF2();
        SysCtlDelay(8*750);
    }
    drv_L_PF3();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------
void cl_led_dbg_rgb::pulse_delay_GreenBright_ms(uint16_t ui16Usr_Delay_ms){//uses SysCtlDelay
    drv_L_PF3();
    drv_L_PF2();
    drv_H_PF3();
    for(int i=0; i<ui16Usr_Delay_ms; i++){
        drv_H_PF2();
        SysCtlDelay(3*750);
        drv_L_PF2();
        SysCtlDelay(8*750);
    }
    drv_L_PF3();
    drv_L_PF2();
}
//::---------------------------------------------------------------------------




