#include "main_menu_callback.h"
#include "../PCD8544_TilePrinter/pcd8544_tileprinter.h"

char mainMenuText_1[] = "Led state config";
char mainMenuText_2[] = "Led pulse config";
char mainMenuText_3[] = "PWM config";

void MainMenu_LedState_Draw(void){
    PCD8544_ClearScreen();
    PCD8544_SetAddress(0,0);
    PCD8544_PrintChar('>');
    PCD8544_PrintString(mainMenuText_1);
    PCD8544_SetAddress(0,1);
    PCD8544_PrintChar(' ');
    PCD8544_PrintString(mainMenuText_2);
    PCD8544_SetAddress(0,2);
    PCD8544_PrintChar(' ');
    PCD8544_PrintString(mainMenuText_3);
}

void MainMenu_LedPulse_Draw(void){
    PCD8544_ClearScreen();
    PCD8544_SetAddress(0,0);
    PCD8544_PrintChar(' ');
    PCD8544_PrintString(mainMenuText_1);
    PCD8544_SetAddress(0,1);
    PCD8544_PrintChar('>');
    PCD8544_PrintString(mainMenuText_2);
    PCD8544_SetAddress(0,2);
    PCD8544_PrintChar(' ');
    PCD8544_PrintString(mainMenuText_3);
}

void MainMenu_PWM_Draw(void){
    PCD8544_ClearScreen();
    PCD8544_SetAddress(0,0);
    PCD8544_PrintChar(' ');
    PCD8544_PrintString(mainMenuText_1);
    PCD8544_SetAddress(0,1);
    PCD8544_PrintChar(' ');
    PCD8544_PrintString(mainMenuText_2);
    PCD8544_SetAddress(0,2);
    PCD8544_PrintChar('>');
    PCD8544_PrintString(mainMenuText_3);
}