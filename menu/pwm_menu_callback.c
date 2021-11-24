#include <xc.h>
#include <stdio.h>
#include "pwm_menu_callback.h"
#include "../PCD8544_TilePrinter/pcd8544_tileprinter.h"
#include "MicroMenu.h"


char pwm_menu_buffer[21];

const char pwm_menu_text_array[2][21] = {
    "%cPWM Duty:   %05u",
    "%cPWM Period: %05u",
};

static inline void PWM_Draw_Helper(uint16_t currentPWMOption){
    char indicatorArray[] = {' ', ' '};
    indicatorArray[currentPWMOption] = '>';
    PCD8544_ClearScreen();
    
    uint16_t duty = CCP4RA;
    uint16_t period = CCP4RB;
    
    sprintf(pwm_menu_buffer, pwm_menu_text_array[0], indicatorArray[0],duty );
    PCD8544_SetAddress(0,0);
    PCD8544_PrintString(pwm_menu_buffer);
    
    sprintf(pwm_menu_buffer, pwm_menu_text_array[1], indicatorArray[1], period);
    PCD8544_SetAddress(0,1);
    PCD8544_PrintString(pwm_menu_buffer);
    
}

void PWM_Duty_Draw(void){
    PWM_Draw_Helper(0);
}

void PWM_Period_Draw(void){
    PWM_Draw_Helper(1);
}

void PWM_DutyInc(void){
    uint16_t duty = CCP4RA;
    duty++;
    CCP4RA = duty;
    MENU_RENDER();
}

void PWM_DutyDec(void){
    uint16_t duty = CCP4RA;
    duty--;
    CCP4RA = duty;
    MENU_RENDER();
}

void PWM_PeriodInc(void){
    uint16_t period = CCP4RB;
    period++;
    CCP4RB = period;
    MENU_RENDER();
}

void PWM_PeriodDec(void){
    uint16_t period = CCP4RB;
    period--;
    CCP4RB = period;
    MENU_RENDER();
}