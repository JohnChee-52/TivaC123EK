/*
 * Switch_Dbg.cpp
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

#include "Switch_Dbg.h"

//..... Instantiate Static Variables ..........................................
bool cl_switch_dbg::bF_Level_Pulse_mem;
bool cl_switch_dbg::bF_Level_MonMode_mem;
bool cl_switch_dbg::bF_Level_TxRS485_mem;
bool cl_switch_dbg::bF_Level_PwrSense_mem;
bool cl_switch_dbg::bF_Level_Mute_mem;
bool cl_switch_dbg::bF_Level_AlmReset_mem;
bool cl_switch_dbg::bF_Level_SysWakeup_mem;
bool cl_switch_dbg::bF_Level_SysMode_mem;
uint8_t cl_switch_dbg::ui8_Switches_JustPressed_bitpat;
bool cl_switch_dbg::bF_SwPressed; //1=a switch has been pressed
//.............................................................................

//::cc-------------------------------------------------------------------------
cl_switch_dbg::cl_switch_dbg(){ //Ctor
    ui8_Switches_JustPressed_bitpat = 0x00;
    bF_SwPressed = 0;  //1=a switch has been pressed

    bF_Level_Pulse_mem = 1;     //1=not pressed
    bF_Level_MonMode_mem = 1;   //1=not pressed
    bF_Level_TxRS485_mem = 1;   //1=not pressed
    bF_Level_PwrSense_mem = 1;  //1=not pressed
    bF_Level_Mute_mem = 1;      //1=not pressed
    bF_Level_AlmReset_mem = 1;  //1=not pressed
    bF_Level_SysWakeup_mem = 1; //1=not pressed
    bF_Level_SysMode_mem = 1;   //1=not pressed
}
//::cc-------------------------------------------------------------------------


//--- Sw_Pulse              // PB0     45  J1p3
//::---------------------------------------------------------------------------
bool cl_switch_dbg::read_Level_Pulse(){
    bF_Level_Pulse_mem =  read_DI_PB0();
    return bF_Level_Pulse_mem;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_pressed_Pulse(){
    bF_Level_Pulse_mem =  read_DI_PB0();
    return (bF_Level_Pulse_mem ? false : true);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justPressed_Pulse(){
    bool bF_JustPressed;
    bool bF_CurrLevel; //Current level of switch

    bF_CurrLevel = read_DI_PB0();
    if(bF_Level_Pulse_mem && (! bF_CurrLevel)){
        bF_JustPressed = true;
        ui8_Switches_JustPressed_bitpat |= en_Sw_Pulse_bp;
    }else{
        bF_JustPressed = false;
    }
    bF_Level_Pulse_mem = bF_CurrLevel;
    return bF_JustPressed;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_released_Pulse(){
    bF_Level_Pulse_mem =  read_DI_PB0();
    return (bF_Level_Pulse_mem ? true : false);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justReleased_Pulse(){
    bool bF_JustReleased;
    bool bF_CurrLevel;

    bF_CurrLevel = read_DI_PB0();
    if((! bF_Level_Pulse_mem) && bF_CurrLevel){
        bF_JustReleased = true;
    }else{
        bF_JustReleased = false;
    }
    bF_Level_Pulse_mem = bF_CurrLevel;
    return bF_JustReleased;
}
//::---------------------------------------------------------------------------

//--- Sw_MonMode            // PB2     47  J2p2
//::---------------------------------------------------------------------------
bool cl_switch_dbg::read_Level_MonMode(){
    bF_Level_MonMode_mem =  read_DI_PB2();
    return bF_Level_MonMode_mem;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_pressed_MonMode(){
    bF_Level_MonMode_mem =  read_DI_PB2();
    return (bF_Level_MonMode_mem ? false : true);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justPressed_MonMode(){
    bool bF_JustPressed;
    bool bF_CurrLevel; //Current level of switch

    bF_CurrLevel = read_DI_PB2();
    if(bF_Level_MonMode_mem && (! bF_CurrLevel)){
        bF_JustPressed = true;
        ui8_Switches_JustPressed_bitpat |= en_Sw_MonMode_bp;
    }else{
        bF_JustPressed = false;
    }
    bF_Level_MonMode_mem = bF_CurrLevel;
    return bF_JustPressed;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_released_MonMode(){
    bF_Level_MonMode_mem =  read_DI_PB2();
    return (bF_Level_MonMode_mem ? true : false);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justReleased_MonMode(){
    bool bF_JustReleased;
    bool bF_CurrLevel;

    bF_CurrLevel = read_DI_PB2();
    if((! bF_Level_MonMode_mem) && bF_CurrLevel){
        bF_JustReleased = true;
    }else{
        bF_JustReleased = false;
    }
    bF_Level_MonMode_mem = bF_CurrLevel;
    return bF_JustReleased;
}
//::---------------------------------------------------------------------------
//--- Sw_TxRS485            // PB2     47  J2p2
//::---------------------------------------------------------------------------
bool cl_switch_dbg::read_Level_TxRS485(){
    bF_Level_TxRS485_mem =  read_DI_PB2();
    return bF_Level_TxRS485_mem;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_pressed_TxRS485(){
    bF_Level_TxRS485_mem =  read_DI_PB2();
    return (bF_Level_TxRS485_mem ? false : true);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justPressed_TxRS485(){
    bool bF_JustPressed;
    bool bF_CurrLevel; //Current level of switch

    bF_CurrLevel = read_DI_PB2();
    if(bF_Level_TxRS485_mem && (! bF_CurrLevel)){
        bF_JustPressed = true;
        ui8_Switches_JustPressed_bitpat |= en_Sw_Fetch_bp;
    }else{
        bF_JustPressed = false;
    }
    bF_Level_TxRS485_mem = bF_CurrLevel;
    return bF_JustPressed;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_released_TxRS485(){
    bF_Level_TxRS485_mem =  read_DI_PB2();
    return (bF_Level_TxRS485_mem ? true : false);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justReleased_TxRS485(){
    bool bF_JustReleased;
    bool bF_CurrLevel;

    bF_CurrLevel = read_DI_PB2();
    if((! bF_Level_TxRS485_mem) && bF_CurrLevel){
        bF_JustReleased = true;
    }else{
        bF_JustReleased = false;
    }
    bF_Level_TxRS485_mem = bF_CurrLevel;
    return bF_JustReleased;
}
//::---------------------------------------------------------------------------

//--- Sw_PwrSense           // PB7       4   J2p6
//::---------------------------------------------------------------------------
bool cl_switch_dbg::read_Level_PwrSense(){
    bF_Level_PwrSense_mem =  read_DI_PB7();
    return bF_Level_PwrSense_mem;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_pressed_PwrSense(){
    bF_Level_PwrSense_mem =  read_DI_PB7();
    return (bF_Level_PwrSense_mem ? false : true);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justPressed_PwrSense(){
    bool bF_JustPressed;
    bool bF_CurrLevel; //Current level of switch

    bF_CurrLevel = read_DI_PB7();
    if(bF_Level_PwrSense_mem && (! bF_CurrLevel)){
        bF_JustPressed = true;
        ui8_Switches_JustPressed_bitpat |= en_Sw_Pwr_bp;
    }else{
        bF_JustPressed = false;
    }
    bF_Level_PwrSense_mem = bF_CurrLevel;
    return bF_JustPressed;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_released_PwrSense(){
    bF_Level_PwrSense_mem =  read_DI_PB7();
    return (bF_Level_PwrSense_mem ? true : false);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justReleased_PwrSense(){
    bool bF_JustReleased;
    bool bF_CurrLevel;

    bF_CurrLevel = read_DI_PB7();
    if((! bF_Level_PwrSense_mem) && bF_CurrLevel){
        bF_JustReleased = true;
    }else{
        bF_JustReleased = false;
    }
    bF_Level_PwrSense_mem = bF_CurrLevel;
    return bF_JustReleased;
}
//::---------------------------------------------------------------------------

//--- Sw_Mute          // PE0        9   J2p3
//::---------------------------------------------------------------------------
bool cl_switch_dbg::read_Level_Mute(){
    bF_Level_Mute_mem =  read_DI_PE0();
    return bF_Level_Mute_mem;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_pressed_Mute(){
    bF_Level_Mute_mem =  read_DI_PE0();
    return (bF_Level_Mute_mem ? false : true);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justPressed_Mute(){
    bool bF_JustPressed;
    bool bF_CurrLevel; //Current level of switch

    bF_CurrLevel = read_DI_PE0();
    if(bF_Level_Mute_mem && (! bF_CurrLevel)){
        bF_JustPressed = true;
        ui8_Switches_JustPressed_bitpat |= en_Sw_Mute_bp;
    }else{
        bF_JustPressed = false;
    }
    bF_Level_Mute_mem = bF_CurrLevel;
    return bF_JustPressed;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_released_Mute(){
    bF_Level_Mute_mem =  read_DI_PE0();
    return (bF_Level_Mute_mem ? true : false);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justReleased_Mute(){
    bool bF_JustReleased;
    bool bF_CurrLevel;

    bF_CurrLevel = read_DI_PE0();
    if((! bF_Level_Mute_mem) && bF_CurrLevel){
        bF_JustReleased = true;
    }else{
        bF_JustReleased = false;
    }
    bF_Level_Mute_mem = bF_CurrLevel;
    return bF_JustReleased;
}
//::---------------------------------------------------------------------------

//--- Sw_AlmReset          // PA4       21   J2p8
//::---------------------------------------------------------------------------
bool cl_switch_dbg::read_Level_AlmReset(){
    bF_Level_AlmReset_mem =  read_DI_PA4();
    return bF_Level_AlmReset_mem;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_pressed_AlmReset(){
    bF_Level_AlmReset_mem =  read_DI_PA4();
    return (bF_Level_AlmReset_mem ? false : true);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justPressed_AlmReset(){
    bool bF_JustPressed;
    bool bF_CurrLevel; //Current level of switch

    bF_CurrLevel = read_DI_PA4();
    if(bF_Level_AlmReset_mem && (! bF_CurrLevel)){
        bF_JustPressed = true;
        ui8_Switches_JustPressed_bitpat |= en_Sw_AlmRst_bp;
    }else{
        bF_JustPressed = false;
    }
    bF_Level_AlmReset_mem = bF_CurrLevel;
    return bF_JustPressed;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_released_AlmReset(){
    bF_Level_AlmReset_mem =  read_DI_PA4();
    return (bF_Level_AlmReset_mem ? true : false);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justReleased_AlmReset(){
    bool bF_JustReleased;
    bool bF_CurrLevel;

    bF_CurrLevel = read_DI_PA4();
    if((! bF_Level_AlmReset_mem) && bF_CurrLevel){
        bF_JustReleased = true;
    }else{
        bF_JustReleased = false;
    }
    bF_Level_AlmReset_mem = bF_CurrLevel;
    return bF_JustReleased;
}
//::---------------------------------------------------------------------------

//--- Sw_SysWakeup          // PF0      28  J4p10
//::---------------------------------------------------------------------------
bool cl_switch_dbg::read_Level_SysWakeup(){
    bF_Level_SysWakeup_mem =  read_DI_PF0();
    return bF_Level_SysWakeup_mem;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_pressed_SysWakeup(){
    bF_Level_SysWakeup_mem =  read_DI_PF0();
    return (bF_Level_SysWakeup_mem ? false : true);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justPressed_SysWakeup(){
    bool bF_JustPressed;
    bool bF_CurrLevel; //Current level of switch

    bF_CurrLevel = read_DI_PF0();
    if(bF_Level_SysWakeup_mem && (! bF_CurrLevel)){
        bF_JustPressed = true;
        ui8_Switches_JustPressed_bitpat |= en_Sw_SysWakekup_bp;
    }else{
        bF_JustPressed = false;
    }
    bF_Level_SysWakeup_mem = bF_CurrLevel;
    return bF_JustPressed;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_released_SysWakeup(){
    bF_Level_SysWakeup_mem =  read_DI_PF0();
    return (bF_Level_SysWakeup_mem ? true : false);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justReleased_SysWakeup(){
    bool bF_JustReleased;
    bool bF_CurrLevel;

    bF_CurrLevel = read_DI_PF0();
    if((! bF_Level_SysWakeup_mem) && bF_CurrLevel){
        bF_JustReleased = true;
    }else{
        bF_JustReleased = false;
    }
    bF_Level_SysWakeup_mem = bF_CurrLevel;
    return bF_JustReleased;
}
//::---------------------------------------------------------------------------

//--- Sw_SysMode            // PF4       5   J2p4
//::---------------------------------------------------------------------------
bool cl_switch_dbg::read_Level_SysMode(){
    bF_Level_SysMode_mem =  read_DI_PF4();
    return bF_Level_SysMode_mem;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_pressed_SysMode(){
    bF_Level_SysMode_mem =  read_DI_PF4();
    return (bF_Level_SysMode_mem ? false : true);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justPressed_SysMode(){
    bool bF_JustPressed;
    bool bF_CurrLevel; //Current level of switch

    bF_CurrLevel = read_DI_PF4();
    if(bF_Level_SysMode_mem && (! bF_CurrLevel)){
        bF_JustPressed = true;
        ui8_Switches_JustPressed_bitpat |= en_Sw_SysMode_bp;
    }else{
        bF_JustPressed = false;
    }
    bF_Level_SysMode_mem = bF_CurrLevel;
    return bF_JustPressed;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_released_SysMode(){
    bF_Level_SysMode_mem =  read_DI_PF4();
    return (bF_Level_SysMode_mem ? true : false);
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_justReleased_SysMode(){
    bool bF_JustReleased;
    bool bF_CurrLevel;

    bF_CurrLevel = read_DI_PF4();
    if((! bF_Level_SysMode_mem) && bF_CurrLevel){
        bF_JustReleased = true;
    }else{
        bF_JustReleased = false;
    }
    bF_Level_SysMode_mem = bF_CurrLevel;
    return bF_JustReleased;
}
//::---------------------------------------------------------------------------

//--- Monitor Switches
//::---------------------------------------------------------------------------
void cl_switch_dbg::set_SwPressed_bitpat(uint8_t ui8Usr_Sw_BitPat){
    ui8_Switches_JustPressed_bitpat |= ui8Usr_Sw_BitPat;
}
//::---------------------------------------------------------------------------
void cl_switch_dbg::clr_SwPressed_bitpat(){
    ui8_Switches_JustPressed_bitpat = en_Sw_None_bp; //=0x00
}
//::---------------------------------------------------------------------------
uint8_t cl_switch_dbg::read_SwPressed_bitpat(){ //Switch press sets a bit to 1
    return ui8_Switches_JustPressed_bitpat;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::check_SwPressed_any(){ //>0 => 1 or more switch has been pressed
    return (ui8_Switches_JustPressed_bitpat > 0) ? true : false;
}
//::---------------------------------------------------------------------------
bool cl_switch_dbg::is_SwPressed_any(){ //1=a sw was pressed, auto clear bitpat
    bool bF_Status;

    bF_Status = (ui8_Switches_JustPressed_bitpat > 0) ? true : false;
    ui8_Switches_JustPressed_bitpat = en_Sw_None_bp; //=0x00
    return bF_Status;
}
//::---------------------------------------------------------------------------

/*
//---^^^ Sw Interrupts
//::---------------------------------------------------------------------------
void cl_switch_dbg::setup_Interrupt_PortA(){ //~IRQ: PA4,
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)){}; //Wait
    GPIOIntRegister(GPIO_PORTA_BASE, PortAIntHandler);
    GPIOIntTypeSet(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_FALLING_EDGE); //PA4
}
//::---------------------------------------------------------------------------
void cl_switch_dbg::setup_Interrupt_PortB(){ //~IRQ: PB0,2,7
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)){}; //Wait
    GPIOIntRegister(GPIO_PORTB_BASE, PortBIntHandler);
    GPIOIntTypeSet(GPIO_PORTB_BASE, GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_0, GPIO_FALLING_EDGE); //PB0,2,7
}
//::---------------------------------------------------------------------------
void cl_switch_dbg::setup_Interrupt_PortE(){ //~IRQ: PE0
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE)){}; //Wait
    GPIOIntRegister(GPIO_PORTE_BASE, PortEIntHandler);
    GPIOIntTypeSet(GPIO_PORTE_BASE, GPIO_PIN_0, GPIO_FALLING_EDGE); //PA4
}
//::---------------------------------------------------------------------------
void cl_switch_dbg::setup_Interrupt_PortF(){ //~IRQ: PF0,4
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)){}; //Wait
    GPIOIntRegister(GPIO_PORTF_BASE, PortFIntHandler);
    GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_FALLING_EDGE); //PA4
}
//::---------------------------------------------------------------------------
*/

