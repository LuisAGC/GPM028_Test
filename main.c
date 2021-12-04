/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC32MM0256GPM028
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "mcc_generated_files/system.h"
#include "mcc_generated_files/coretimer.h"
#include "mcc_generated_files/sccp4_compare.h"
#include "mcc_generated_files/uart2.h"
#include "mcc_generated_files/interrupt_manager.h"
#include "mcc_generated_files/i2c2.h"

#include "led/led_impl.h"
#include "button/button_impl.h"
#include "at_command/at_parser_impl.h"
#include "PCD8544/pcd8544.h"
#include "menu/MicroMenu.h"
#include "MCP23017/MCP23017.h"

/*
                         Main application
 */

uint64_t previous_millis = 0L;
uint32_t millisMenuCallback = 0;

void MCP23017_Init(void);

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    INTERRUPT_GlobalDisable();
    IEC2bits.I2C2BCIE = 0;
    IEC2bits.I2C2MIE = 0;
    IEC2bits.I2C2SIE = 0;
    INTERRUPT_GlobalEnable();
    uint8_t data = 0x07;
    MCP23017_Write(0x00, data);
    data = 0x00;
    MCP23017_Write(0x01, data);
    MCP23017_Write(0x14, data);
    MCP23017_Write(0x15, data);
    delay(100);
    PCD8544_Init();
    Init_Leds();
    Init_Parser();
    Init_Buttons();
    SCCP4_COMPARE_DualEdgeBufferedConfig(0x0001, 0xFFFF);
    printf("SYSTEM STARTED: READY TO RECEIVE COMMANDS\r\n");
    while (1) {
        if(millis() != previous_millis){
            previous_millis = millis();
            Led_Ticker(&led1, LED_TICK);
            Led_Ticker(&led2, LED_TICK);
            Led_Ticker(&led3, LED_TICK);
            Led_Ticker(&led4, LED_TICK);
            Led_Ticker(&led5, LED_TICK);
            Led_Ticker(&led6, LED_TICK);
            Led_Ticker(&led7, LED_TICK);
            Led_Ticker(&led8, LED_TICK);
            Button_Ticker(&button1);
            Button_Ticker(&button2);
            Button_Ticker(&button3);
            millisMenuCallback++;
        }
        
        if(millisMenuCallback > 200){
            millisMenuCallback = 0;
            if(button1_longPressed == true){
                MENU_SELECT();
            }
            if(button2_longPressed == true){
                MENU_ENTER();
            }
        }
        
        if(UART2_IsRxReady()){
          AT_Ticker(&atCommandParserSingleton, UART2_Read());          
        }
        MCP23017_Write(0x15, leds_register);
        uint8_t buttons = MCP23017_Read(0x12);
        button1_status = (buttons >> 0) & 1;
        button2_status = (buttons >> 1) & 1;
        button3_status = (buttons >> 2) & 1;
    }
    return 1; 
}

/**
 End of File
*/

