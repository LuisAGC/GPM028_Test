#include <stdio.h>

#include "ledstate_menu_callback.h"
#include "../PCD8544_TilePrinter/pcd8544_tileprinter.h"
#include "../led/led_impl.h"
#include "MicroMenu.h"

const char ledStateMenuText1[] = "%cLed %d: ";
char ledStateMenuText2[] = "OFF";
char ledStateMenuText3[] = "ON";
char ledStateMenuText4[] = "PULSE";
char ledStateMenuBuffer[16];

uint16_t ledsCurrentState[8] ={0,0,0,0,0,0,0,0};

static void LedState_CurrentStateDraw_Helper(uint16_t ledCurrentState){
    switch(ledCurrentState){
        case 0:
            PCD8544_PrintString(ledStateMenuText2);
            break;
        case 1:
            PCD8544_PrintString(ledStateMenuText3);
            break;
        case 2:
            PCD8544_PrintString(ledStateMenuText4);
            break;
        default:
            break;
    }
}

static void LedState_TopDraw_Helper(uint16_t selectedItem){
    PCD8544_ClearScreen();
    for(uint16_t i = 0; i < 6; i++){
        if(selectedItem == i){
            sprintf(ledStateMenuBuffer, ledStateMenuText1, '>', i+1);
        }
        else{
            sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', i+1);
        }
        PCD8544_SetAddress(0,i);
        PCD8544_PrintString(ledStateMenuBuffer);
        LedState_CurrentStateDraw_Helper(ledsCurrentState[i]);
    }
}

static void LedState_BottomDraw_Helper(uint16_t selectedItem){
    PCD8544_ClearScreen();
    for(uint16_t i = 6; i < 8; i++){
        if(selectedItem == i){
            sprintf(ledStateMenuBuffer, ledStateMenuText1, '>', i+1);
        }
        else{
            sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', i+1);
        }
        PCD8544_SetAddress(0,i-6);
        PCD8544_PrintString(ledStateMenuBuffer);
        LedState_CurrentStateDraw_Helper(ledsCurrentState[i]);
    }
}

void LedState_1_Draw(void){
    LedState_TopDraw_Helper(0);
}

void LedState_2_Draw(void){
    LedState_TopDraw_Helper(1);
}

void LedState_3_Draw(void){
    LedState_TopDraw_Helper(2);
}

void LedState_4_Draw(void){
    LedState_TopDraw_Helper(3);
}

void LedState_5_Draw(void){
    LedState_TopDraw_Helper(4);
}

void LedState_6_Draw(void){
    LedState_TopDraw_Helper(5);
}

void LedState_7_Draw(void){
    LedState_BottomDraw_Helper(6);
}

void LedState_8_Draw(void){
    LedState_BottomDraw_Helper(7);
}

static void LedState_Callback_Helper(uint16_t ledIndex, Led * ledInstance){
    switch(ledsCurrentState[ledIndex]){
        case 0:
            Led_Ticker(ledInstance, LED_ON);
            ledsCurrentState[ledIndex] = 1;
            break;
        case 1:
            Led_Ticker(ledInstance, LED_PULSE);
            ledsCurrentState[ledIndex] = 2;
            break;
        case 2:
            Led_Ticker(ledInstance, LED_OFF);
            ledsCurrentState[ledIndex] = 0;
            break;
        default:
            break;
    }
}

void LedState_1_Callback(void){
    LedState_Callback_Helper(0, leds[0]);
    Menu_Navigate(MENU_PARENT);
}

void LedState_2_Callback(void){
    LedState_Callback_Helper(1, leds[1]);
    Menu_Navigate(MENU_PARENT);
}

void LedState_3_Callback(void){
    LedState_Callback_Helper(2, leds[2]);
    Menu_Navigate(MENU_PARENT);
}

void LedState_4_Callback(void){
    LedState_Callback_Helper(3, leds[3]);
    Menu_Navigate(MENU_PARENT);
}

void LedState_5_Callback(void){
    LedState_Callback_Helper(4, leds[4]);
    Menu_Navigate(MENU_PARENT);
}

void LedState_6_Callback(void){
    LedState_Callback_Helper(5, leds[5]);
    Menu_Navigate(MENU_PARENT);
}

void LedState_7_Callback(void){
    LedState_Callback_Helper(6, leds[6]);
    Menu_Navigate(MENU_PARENT);
}

void LedState_8_Callback(void){
    LedState_Callback_Helper(7, leds[7]);
    Menu_Navigate(MENU_PARENT);
}
