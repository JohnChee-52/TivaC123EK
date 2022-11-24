/*
 * Switch_Dbg.h
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

#ifndef SWITCH_DBG_H_
#define SWITCH_DBG_H_

#include "Unit_Test_Mode.h"
#include "TM4C123GH6PM_Config_Pins.h"

/*
//^^^^^........................................................................
extern "C" { //Make function name compatible for use as ISR Vector
interrupt void PortAIntHandler();
interrupt void PortBIntHandler();
interrupt void PortEIntHandler();
interrupt void PortFIntHandler();
}
//^^^^^........................................................................
*/

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
enum en_sw_bitpat_t { //bit pattern
    en_Sw_None_bp   = 0,
    en_Sw_Pulse_bp  = 1 << 0,  //0x01
    en_Sw_AlmRst_bp = 1 << 1,  //0x02
    en_Sw_Fetch_bp  = 1 << 2,  //0x04
    en_Sw_Mute_bp   = 1 << 3,  //0x08
    en_Sw_Pwr_bp    = 1 << 4,  //0x10

    en_Sw_SysWakekup_bp = 1 << 5,  //0x10
    en_Sw_SysMode_bp    = 1 << 6,  //0x10


    en_Sw_MonMode_bp = 0x04,

};
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//... Switch pressed Global Variables .........................................
uint8_t SwPressed_bitpat; //Bit pattern of buttons just pressed
//.............................................................................


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class cl_switches : public cl_tm4c123gh6pm_pins{
private:
protected:
public:
    //... Switch (individual)
    static bool bF_Level_Pulse_mem;
    static bool bF_Level_MonMode_mem;
    static bool bF_Level_TxRS485_mem;
    static bool bF_Level_PwrSense_mem;
    static bool bF_Level_Mute_mem;
    static bool bF_Level_AlmReset_mem;
    static bool bF_Level_SysWakeup_mem;
    static bool bF_Level_SysMode_mem;

    //... Switches
    static uint8_t ui8_Switches_JustPressed_bitpat;
    uint8_t SwPressed_bitpat; //Bit pattern of buttons just pressed
    static bool bF_SwPressed; //1=a switch has been pressed



    cl_switches(); //Ctor


    //----- Switch name             DO   IC pin TIVA
    //--- Sw_Pulse        ::      // PB0     45  J1p3
    bool read_Level_Pulse();
    bool is_pressed_Pulse();
    bool is_justPressed_Pulse();
    bool is_released_Pulse();
    bool is_justReleased_Pulse();

    //--- Sw_MonMode            // PB2     47  J2p2
    bool read_Level_MonMode();
    bool is_pressed_MonMode();
    bool is_justPressed_MonMode();
    bool is_released_MonMode();
    bool is_justReleased_MonMode();

    //--- Sw_TxRS485            // PB2     47  J2p2
    bool read_Level_TxRS485();
    bool is_pressed_TxRS485();
    bool is_justPressed_TxRS485();
    bool is_released_TxRS485();
    bool is_justReleased_TxRS485();

    //--- Sw_PwrSense           // PB7       4   J2p6
    bool read_Level_PwrSense();
    bool is_pressed_PwrSense();
    bool is_justPressed_PwrSense();
    bool is_released_PwrSense();
    bool is_justReleased_PwrSense();

    //--- Sw_Mute           //PE0           9   J2p3
    bool read_Level_Mute();
    bool is_pressed_Mute();
    bool is_justPressed_Mute();
    bool is_released_Mute();
    bool is_justReleased_Mute();

    //--- Sw_AlmReset          // PA4       21   J2p8
    bool read_Level_AlmReset();
    bool is_pressed_AlmReset();
    bool is_justPressed_AlmReset();
    bool is_released_AlmReset();
    bool is_justReleased_AlmReset();

    //--- Sw_SysWakeup          // PF0      28  J4p10
    bool read_Level_SysWakeup();
    bool is_pressed_SysWakeup();
    bool is_justPressed_SysWakeup();
    bool is_released_SysWakeup();
    bool is_justReleased_SysWakeup();

    //--- Sw_SysMode            // PF4       5   J2p4
    bool read_Level_SysMode();
    bool is_pressed_SysMode();
    bool is_justPressed_SysMode();
    bool is_released_SysMode();
    bool is_justReleased_SysMode();


    //--- Monitor Switches
    void set_SwPressed_bitpat(uint8_t ui8Usr_Sw_BitPat);
    void clr_SwPressed_bitpat();
    uint8_t read_SwPressed_bitpat(); //Switch press sets a bit to 1
    bool check_SwPressed_any(); //>0 => 1 or more switch has been pressed
    bool is_SwPressed_any(); //1=a switch has been pressed, auto clear bitpat
/*
    //---^^^ Sw Interrupts
    void setup_Interrupt_PortA(); //~IRQ: PA4,
    void setup_Interrupt_PortB(); //~IRQ: PB0,2,7
    void setup_Interrupt_PortE(); //~IRQ: PE0
    void setup_Interrupt_PortF(); //~IRQ: PF0,4
*/
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





#endif /* SWITCH_DBG_H_ */
