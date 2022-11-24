/*
 * TM4C123GH6PM_Config_Pins.cpp   256KB Flash, 32KB RAM, 2KB EEPROM
 * Configure the MCU pins only for the NTL project.
 * The initialistaion of registers to perform functions are not done in this module.
 * Only digital inputs (DI) and digital outputs (DO) are defined in this module.
 * ------------------------------------------------|
 * GPIO|Pin|Config  |MCU Control/Input lines |TIVA |
 * ------------------------------------------------|
 * PE3 |p6 |AIN0    |BatteryVoltage_PE3      |J3p9 |
 * PE2 |p7 |AIN1    |ClogPressure_PE2        |J3p8 |
 * PB4 |p58|AIN10   |BackPressure_PB4        |J1p7 |
 * PE5 |p60|AIN8    |ChamberPressure_PE5     |J1p6 |
 * ------------------------------------------------|
 * PB0 |p45|DI      |Sw3_Pulse_PB0           |J1p3 |
 * PB2 |p47|DI      |Sw4_Sgl_PB2             |J2p2 |
 * PB7 |p4 |DI      |Sw6_PwrSense_PB7        |J2p6 |
 * PE0 |p9 |DI      |Sw5_Mute_PE0            |J2p3 |
 * PF0 |p28|DI      |Sw2_Wakeup_PF0          |J2p4 |
 * PF4 |p5 |DI      |Sw1_Mode_PF4            |J4p10|
 * PA4 |p21|DI      |Sw7_AlmRst_PA4          |J2p8 |
 * ------------------------------------------------|
 * PB1 |p46|DO      |Drv_Valve_Bolus_PB1     |J1p4 |
 * PB6 |p1 |DO      |Drv_Valve_Exhaust_PB6   |J2p7 |
 * PE1 |p8 |DO      |Drv_Valve_TestBolus_PE1 |J3p7 |
 * PC4 |p16|DO      |LED_Send_Char_PC4       |J4p4 |
 * PC5 |p15|DO      |LED_Rcv_Char_PC5        |J4p5 |
 * PF1 |p29|DO      |Drv_LED1_Red_PF1        |J3p10|
 * PF2 |p30|DO      |Drv_LED2_Blue_PF2       |J4p1 |
 * PF3 |p31|DO      |Drv_LED3_Green_PF3      |J4p2 |
 * PB5 |p57|DO      |Buzzer_PB5              |J1p2 |
 * ------------------------------------------------|
 * PA6 |p23|I2C1_SCL|IO_Expander_SCL_PA6     |J1p9 |
 * PA7 |p24|I2C1_SDA|IO_Expander_SDA_PA7     |J1p10|
 * PA5 |p22|DI      |~Int_IO_Expander_PA5    |J1p8 |
 * ------------------------------------------------|
 * PA3 |p20|DO      |Enable_Pump_PA3         |J2p9 |
 * PE4 |p59|DO/PWM2 |Drv_AirPump_PE4         |J1p5 |
 * ------------------------------------------------|
 * PD0 |p61|SSI1_Clk|EEPROM_Clk_PD0          |J3p3 |
 * PD1 |p62|DO_FSS  |EEPROM_FSS_PD1          |J3p4 |
 * PD2 |p63|SSI1_Rx |EEPROM_Rx_PD2           |J3p5 |
 * PD3 |p64|SSI1_Tx |EEPROM_Tx_PD3           |J3p6 |
 * ------------------------------------------------|
 * PA2 |p19|DI      |ID_PC_Connected         |J2p10|
 * PD6 |p53|DO      |RS485_En_Rcv_PD6        |J4p8 |
 * PD7 |p10|DO      |RS485_En_Send_PD7       |J4p9 |
 * PC6 |p14|U3Rx    |UART_Rx_PC6             |J4p6 |
 * PC7 |p13|U3Tx    |UART_Tx_PC7             |J4p7 |
 * ------------------------------------------------|
 *
 * Adapted from the outputs of TI's PinMux version 4.0.1532.
 *
 *  Created on: 15 Jul 2021     X00.01 LB16
 *      Author: John Chee
 */

#include "TM4C123GH6PM_Config_Pins.h"

//::cc-------------------------------------------------------------------------
cl_tm4c123gh6pm_pins::cl_tm4c123gh6pm_pins(){
    //----- Enable Peripheral Clocks
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);



    //----- Configure GPIO Pins for Analog inputs    //GPIO|Pin |Config  |MCU Control/Input lines |TIVA
    MAP_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3); //PE3 |p6  |AIN0    |BatteryVoltage_PE3      |J3p9 |
    MAP_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_5); //PE5 |p60 |AIN8    |ChamberPressure_PE5     |J1p6
    MAP_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_2); //PE2 |p7  |AIN1    |ClogPressure_PE2        |J3p8



    //----- Configure GPIO Pins for Digital inputs         //GPIO|Pin |Config  |MCU Control/Input lines |TIVA
    //-- Setup DI for PA2:
    MAP_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_2); //PA2 |p19|DI      |~ID_PC_Connected        |J2p10|
    MAP_GPIOPadConfigSet(GPIO_PORTA_BASE, GPIO_PIN_2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);

    //-- Setup DI for PB0
    MAP_GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_0); //PB0 |p45 |DI      |Sw3_Pulse_PB0           |J1p3
    MAP_GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //-- Setup DI for PB2
    MAP_GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_2); //PB2 |p47 |DI    |Sw4_MonitorMode_PB2       |J2p2
    MAP_GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //-- Setup DI for PB7
    MAP_GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_7); //PB7 |p4  |DI      |Sw6_PwrSense_PB7        |J2p6
    MAP_GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_7, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //-- Setup DI for PE0
    MAP_GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_0); //PE0 |p9 |DI      |Sw5_Mute_PE0            |J2p3 |
    MAP_GPIOPadConfigSet(GPIO_PORTE_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //-- Setup DI for PA4
    MAP_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_4); //PA4 |p21  |DI    |Sw5_Mute/Reset Alert_PA4  |J2p8
    MAP_GPIOPadConfigSet(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //-- Setup DI for PF0
    //-- Unlock the Port Pin and Set the Commit Bit of Pin PF0
    HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;    //PF0 |p28 |DI      |Sw2_Wakeup_PF0          |pJ2p4
    HWREG(GPIO_PORTF_BASE+GPIO_O_CR)   |= GPIO_PIN_0;
    HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = 0x0;
    //-- Config the Port Pin PF0
    MAP_GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
    MAP_GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //-- Setup DI for PF4
    MAP_GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4); //PF4 | 5 |DI      |Sw1_Mode_PF4             |J4p10
    MAP_GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    MAP_GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_DIR_MODE_IN);

    //-- Setup DI for PA5
    MAP_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_5); //PA5 |p22 |DI      |~Int_IO_Expander_PA5    |J1p8
    MAP_GPIOPadConfigSet(GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);



    //----- Configure GPIO Pins for Digital Outputs        //GPIO|Pin |Config  |MCU Control/Input lines |TIVA
    //-- Setup DO for various port pins
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_6); //PB6 | 1 |DO      |Drv_Valve_Exhaust_PB6   |J2p7
    MAP_GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_6, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);

    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1); //PF1 |29 |DO      |Drv_LED1_Red_PF1        |J1p10
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_1); //PE1 | 8 |DO      |Drv_Valve_TestBolus_PE1 |J3p7
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4); //PC4 |16 |DO      |LED_Send_Char_PC4       |J4p4
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_5); //PC5 |15 |DO      |LED_Rcv_Char_PC5        |J4p5
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_1); //PB1 |46 |DO      |Drv_Valve_Bolus_PB1     |J1p4
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2); //PF2 |30 |DO      |Drv_LED2_Blue_PF2       |J4p1
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3); //PF3 |31 |DO      |Drv_LED3_Green_PF3      |J4p2
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_5); //PB5 |57 |DO      |Buzzer_PB5              |J1p2
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_6); //PD6 |53 |DO      |RS485_En_Rcv_PD6        |J4p8
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_1); //PD1 |62 |DO_     |SSI1_FSS                |J3p4



    //----- Configure GPIO Pins for either DO or PWM2      //GPIO|Pin |Config  |MCU Control/Input lines |TIVA
    //-- Setup Pump drive using PA3 as enable pump, PE4 as pump drive
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_3); //PA3 |20 |DO      |Enable_Pump_PA3         |J2p9
#ifdef M1PWM2_Drive
    //----- Configure GPIO Pins for PWM2 if using PWM drive
    MAP_GPIOPinConfigure(GPIO_PE4_M1PWM2);                  //PE4 |59 |PWM2    |Drv_AirPump_PE4         |J1p5
    MAP_GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_4);
#else
    //-- DO PE4 for motor drive (assuming not using PWM)
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_4); //PE4 |59 |PWM2    |Drv_AirPump_PE4         |J1p5
    MAP_GPIOPadConfigSet(GPIO_PORTE_BASE, GPIO_PIN_4, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
    MAP_GPIODirModeSet(GPIO_PORTE_BASE, GPIO_PIN_4, GPIO_DIR_MODE_OUT);
//    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, GPIO_PIN_4);
//    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0);
#endif


    //-- DO for PD7: Unlock the Port Pin and Set the Commit Bit
    HWREG(GPIO_PORTD_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTD_BASE+GPIO_O_CR)   |= GPIO_PIN_7;
    HWREG(GPIO_PORTD_BASE+GPIO_O_LOCK) = 0x0;
    //-- Config the Port Pin
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_7); //PD7 |10 |DO      |RS485_En_Send_PD7       |J4p9



    //------- Dedicated functions pin ------------------------------------------------------------------------
    //----- Configure GPIO Pins for I2C1               //GPIO|Pin |Config  |MCU Control/Input lines |TIVA
    //-- SCL
    MAP_GPIOPinConfigure(GPIO_PA6_I2C1SCL);             //PA6 |23 |I2C1    |IO_Expander_SCL_PA6     |J1p9
    MAP_GPIOPinTypeI2CSCL(GPIO_PORTA_BASE, GPIO_PIN_6);
    //-- SDA
    MAP_GPIOPinConfigure(GPIO_PA7_I2C1SDA);             //PA7 |24 |I2C1    |IO_Expander_SDA_PA7     |J1p10
    MAP_GPIOPinTypeI2C(GPIO_PORTA_BASE, GPIO_PIN_7);



    //----- Configure GPIO Pins for SSI1
    //-- SSI Rx
    MAP_GPIOPinConfigure(GPIO_PD2_SSI1RX);              //PD2 |63 |SSI1_Rx |EEPROM_Rx_PD2           |J3p5
    MAP_GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_2);

    //-- DO_FSS (configured earlier as DO instead of SSI_FSS) as
    //MAP_GPIOPinConfigure(GPIO_PD1_SSI1FSS);              //PD1 |62 |SSI1_FSS|EEPROM_FSS_PD1         |J3p4
    //MAP_GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_1);

    //-- SSI_Tx
    MAP_GPIOPinConfigure(GPIO_PD3_SSI1TX);              //PD3 |64 |SSI1_Tx |EEPROM_Tx_PD3           |J3p6
    MAP_GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_3);

    //-- SSI_Clk
    MAP_GPIOPinConfigure(GPIO_PD0_SSI1CLK);              //PD0 |61 |SSI1_Clk|EEPROM_Clk_PD0         |J3p3
    MAP_GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_0);



    //----- Configure GPIO Pins for UART3
    MAP_GPIOPinConfigure(GPIO_PC6_U3RX);                //PC6 |14 |U3Rx    |UART_Rx_PC6             |J4p6
    MAP_GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_6);

    MAP_GPIOPinConfigure(GPIO_PC7_U3TX);                //PC7 |13 |U3Tx    |UART_Tx_PC7             |J4p7
    MAP_GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_7);
}
//::cc-------------------------------------------------------------------------


//----- Digital inputs
//-- DI_PA2
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::read_DI_PA2(){ //MCUp19
   return ((GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_2) > 0)? true: false) ;
}
//::---------------------------------------------------------------------------

//-- DI_PB0
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::read_DI_PB0(){ //MCUp45
   return ((GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_0) > 0)? true: false) ;
}
//::---------------------------------------------------------------------------

//-- DI_PB2
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::read_DI_PB2(){ //MCUp47
    return ((GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_2) > 0)? true: false) ;
}
//::---------------------------------------------------------------------------

//-- DI_PB7
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::read_DI_PB7(){ //MCUp4
    return ((GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_7) > 0)? true: false) ;
}
//::---------------------------------------------------------------------------

//-- DI_PE0
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::read_DI_PE0(){ //MCUp9
    return ((GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_0) > 0)? true: false) ;
}
//::---------------------------------------------------------------------------

//-- DI_PA4
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::read_DI_PA4(){ //MCUp21
    return ((GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_4) > 0)? true: false) ;
}
//::---------------------------------------------------------------------------

//-- DI_PF0
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::read_DI_PF0(){ //MCUp28
    return ((GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0) > 0)? true: false) ;
}
//::---------------------------------------------------------------------------

//-- DI_PF4
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::read_DI_PF4(){ //MCUp5
    return ((GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) > 0)? true: false) ;
}
//::---------------------------------------------------------------------------

//-- DI_PA5
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::read_DI_PA5(){ //MCUp22
    return ((GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_5) > 0)? true: false) ;
}
//::---------------------------------------------------------------------------



//----- Digital outputs
//-- DO PB1
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PB1(){ //MCUp46
    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, GPIO_PIN_1);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PB1(){ //MCUp46
    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PB1(){ //MCUp46
    return GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_1);
}
//::---------------------------------------------------------------------------


//-- DO PB6
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PB6(){ //MCUp1
    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, GPIO_PIN_6);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PB6(){ //MCUp1
    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PB6(){ //MCUp1
    return GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_6);
}
//::---------------------------------------------------------------------------

//-- DO PE1
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PE1(){ //MCUp8
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, GPIO_PIN_1);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PE1(){ //MCUp8
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PE1(){ //MCUp8
    return GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_1);
}
//::---------------------------------------------------------------------------

//-- DO PC4
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PC4(){ //MCUp16
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, GPIO_PIN_4);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PC4(){ //MCUp16
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PC4(){ //MCUp16
    return GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4);
}
//::---------------------------------------------------------------------------

//-- DO PC5
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PC5(){ //MCUp15
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_5);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PC5(){ //MCUp15
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PC5(){ //MCUp15
    return GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_5);
}
//::---------------------------------------------------------------------------

//-- DO PF1
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PF1(){ //MCUp29
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PF1(){ //MCUp29
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PF1(){ //MCUp29
    return GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_1);
}
//::---------------------------------------------------------------------------

//-- DO PF2
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PF2(){ //MCUp30
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PF2(){ //MCUp30
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PF2(){ //MCUp30
    return GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_2);
}
//::---------------------------------------------------------------------------

//-- DO PF3
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PF3(){ //MCUp31
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PF3(){ //MCUp31
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PF3(){ //MCUp31
    return GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3);
}
//::---------------------------------------------------------------------------

//-- DO PB5
//::---------------------------------------------------------------------------
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PB5(){ //MCUp57
    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, GPIO_PIN_5);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PB5(){ //MCUp57
    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PB5(){ //MCUp57
    return GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_5);
}
//::---------------------------------------------------------------------------

//-- DO PD6
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PD6(){ //MCUp53
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, GPIO_PIN_6);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PD6(){ //MCUp53
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PD6(){ //MCUp53
    return GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_6);
}
//::---------------------------------------------------------------------------

//-- DO PD7
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PD7(){ //MCUp10
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, GPIO_PIN_7);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PD7(){ //MCUp10
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PD7(){ //MCUp10
    return GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_7);
}
//::---------------------------------------------------------------------------

//-- DO PA3
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PA3(){ //MCUp20
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, GPIO_PIN_3);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PA3(){ //MCUp20
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PA3(){ //MCUp20
    return GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_3);
}
//::---------------------------------------------------------------------------

#ifndef M1PWM2_Drive
//-- DO PE4
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_H_PE4(){ //MCUp59
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, GPIO_PIN_4);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PE4(){ //MCUp59
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PE4(){ //MCUp59
    return GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_4);
}
//::---------------------------------------------------------------------------
#endif

//-- DO PD1_FSS
void cl_tm4c123gh6pm_pins::drv_H_PD1_FSS(){ //MCUp62
    GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1, GPIO_PIN_1);
}
//::---------------------------------------------------------------------------
void cl_tm4c123gh6pm_pins::drv_L_PD1_FSS(){ //MCUp62
    GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1, 0);
}
//::---------------------------------------------------------------------------
bool cl_tm4c123gh6pm_pins::is_H_PD1_FSS(){ //MCUp62
    return GPIOPinRead(GPIO_PORTD_BASE,GPIO_PIN_1);
}
//::---------------------------------------------------------------------------


