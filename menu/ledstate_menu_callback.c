#include <stdio.h>

#include "ledstate_menu_callback.h"
#include "../PCD8544_TilePrinter/pcd8544_tileprinter.h"
#include "../led/led_impl.h"
#include "MicroMenu.h"

const char ledStateMenuText1[] = "%cLed %d state: ";
char ledStateMenuText2[] = "OFF";
char ledStateMenuText3[] = "ON";
char ledStateMenuText4[] = "PULSE";
char ledStateMenuBuffer[22];

uint16_t led1CurrentState = 0;
uint16_t led2CurrentState = 0;
uint16_t led3CurrentState = 0;
uint16_t led4CurrentState = 0;

void LedState_Draw_Helper(uint16_t ledCurrentState){
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

void LedState_1_Draw(void){
    PCD8544_ClearScreen();
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, '>', 1);
    PCD8544_SetAddress(0,0);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led1CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText2, ' ', 2);
    PCD8544_SetAddress(0,1);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led2CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText3, ' ', 3);
    PCD8544_SetAddress(0,2);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led3CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText4, ' ', 4);
    PCD8544_SetAddress(0,3);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led4CurrentState);
}

void LedState_2_Draw(void){
    PCD8544_ClearScreen();
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 1);
    PCD8544_SetAddress(0,0);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led1CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText2, '>', 2);
    PCD8544_SetAddress(0,1);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led2CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText3, ' ', 3);
    PCD8544_SetAddress(0,2);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led3CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText4, ' ', 4);
    PCD8544_SetAddress(0,3);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led4CurrentState);
}

void LedState_3_Draw(void){
    PCD8544_ClearScreen();
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 1);
    PCD8544_SetAddress(0,0);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led1CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText2, ' ', 2);
    PCD8544_SetAddress(0,1);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led2CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText3, '>', 3);
    PCD8544_SetAddress(0,2);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led3CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText4, ' ', 4);
    PCD8544_SetAddress(0,3);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led4CurrentState);
}

void LedState_4_Draw(void){
    PCD8544_ClearScreen();
    
    sprintf(ledStateMenuBuffer, ledStateMenuText1, ' ', 1);
    PCD8544_SetAddress(0,0);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led1CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText2, ' ', 2);
    PCD8544_SetAddress(0,1);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led2CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText3, ' ', 3);
    PCD8544_SetAddress(0,2);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led3CurrentState);
    
    sprintf(ledStateMenuBuffer, ledStateMenuText4, '>', 4);
    PCD8544_SetAddress(0,3);
    PCD8544_PrintString(ledStateMenuBuffer);
    LedState_Draw_Helper(led4CurrentState);
}
    

void LedState_1_Callback(void){
    switch(led1CurrentState){
        case 0:
            Led_Ticker(&led1, LED_ON);
            led1CurrentState = 1;
            break;
        case 1:
            Led_Ticker(&led1, LED_PULSE);
            led1CurrentState = 2;
            break;
        case 2:
            Led_Ticker(&led1, LED_OFF);
            led1CurrentState = 0;
            break;
        default:
            break;
    }
    Menu_Navigate(MENU_PARENT);
}

void LedState_2_Callback(void){
    switch(led2CurrentState){
        case 0:
            Led_Ticker(&led2, LED_ON);
            led2CurrentState = 1;
            break;
        case 1:
            Led_Ticker(&led2, LED_PULSE);
            led2CurrentState = 2;
            break;
        case 2:
            Led_Ticker(&led2, LED_OFF);
            led2CurrentState = 0;
            break;
        default:
            break;
    }
    Menu_Navigate(MENU_PARENT);
}

void LedState_3_Callback(void){
    switch(led3CurrentState){
        case 0:
            Led_Ticker(&led3, LED_ON);
            led3CurrentState = 1;
            break;
        case 1:
            Led_Ticker(&led3, LED_PULSE);
            led3CurrentState = 2;
            break;
        case 2:
            Led_Ticker(&led3, LED_OFF);
            led3CurrentState = 0;
            break;
        default:
            break;
    }
    Menu_Navigate(MENU_PARENT);
}

void LedState_4_Callback(void){
    switch(led4CurrentState){
        case 0:
            Led_Ticker(&led4, LED_ON);
            led4CurrentState = 1;
            break;
        case 1:
            Led_Ticker(&led4, LED_PULSE);
            led4CurrentState = 2;
            break;
        case 2:
            Led_Ticker(&led4, LED_OFF);
            led4CurrentState = 0;
            break;
        default:
            break;
    }
    Menu_Navigate(MENU_PARENT);
}

