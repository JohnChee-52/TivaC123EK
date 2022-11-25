/*
 * M_TivaC123_EK.cpp
 * Tiva C Evaluation Kit - User interface
 * An example of Version Control using EGit
 * If you are using stdio, you need to allocate heap space e.g. 1000.
 * Note: printf will only show on console if the string has "\n".
 *
 * Simple example of printing:  "<n> Hi" five times, where n=1..5
 *
 *  Created on: 30 Oct 2022
 *      Author: John Chee
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "Unit_Test_Mode.h"
#include "UnitTester.h"


#ifndef Unit_Test_Mode  //Code below runs only when not unit-testing
//=======================================================================================
int main(){ //TivaC123EK
    printf("Running TivaC123EK:\n"); //Sign on
    uint32_t ui32_Cnt;

    ui32_Cnt = 0;
    while (1){
        ui32_Cnt++;
        if(ui32_Cnt <= 5){
            printf("%d Hi\n", ui32_Cnt);
            if (ui32_Cnt == 5){
                printf("Done %d times already. Bye! \n", ui32_Cnt);
            }
        }
    }
}
//=======================================================================================
#endif


