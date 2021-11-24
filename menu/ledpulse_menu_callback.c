#include <stdio.h>

#include "ledstate_menu_callback.h"
#include "../PCD8544_TilePrinter/pcd8544_tileprinter.h"
#include "../led/led_impl.h"
#include "MicroMenu.h"

char ledpulse_menu_buffer[21];

const char ledpulse_menu_text[] = "%cLed %d pulse config";
const char ledpulse_menu_text_array[4][21] = {
    "%cPulse high: %05u",
    "%cPulse low:  %05u",
    "%cPulses:     %05d",
    "%cPulses:     Inf"
};


static inline void LedPulse_Draw_Helper(uint16_t currentLed){
    char indicatorArray[] = {' ', ' ', ' ', ' '};
    indicatorArray[currentLed] = '>';
    PCD8544_ClearScreen();
    
    for(uint16_t i = 0; i < 4; i++){
        sprintf(ledpulse_menu_buffer, ledpulse_menu_text, indicatorArray[i], i+1);
        PCD8544_SetAddress(0,i);
        PCD8544_PrintString(ledpulse_menu_buffer);
    }
}

void LedPulse_1_Draw(void){
    LedPulse_Draw_Helper(0);
}

void LedPulse_2_Draw(void){
    LedPulse_Draw_Helper(1);
}

void LedPulse_3_Draw(void){
    LedPulse_Draw_Helper(2);
}

void LedPulse_4_Draw(void){
    LedPulse_Draw_Helper(3);
}
    

static inline void LedPulseInstance_Draw_Helper(Led *led, uint16_t currentConfigIndex){
    
    char indicatorArray[] = {' ', ' ', ' '};
    indicatorArray[currentConfigIndex] = '>';
    PCD8544_ClearScreen();

    sprintf(ledpulse_menu_buffer, ledpulse_menu_text_array[0], indicatorArray[0], led->pulseHighDurationTicks);
    PCD8544_SetAddress(0,0);
    PCD8544_PrintString(ledpulse_menu_buffer);
    
    sprintf(ledpulse_menu_buffer, ledpulse_menu_text_array[1], indicatorArray[1], led->pulseLowDurationTicks);
    PCD8544_SetAddress(0,1);
    PCD8544_PrintString(ledpulse_menu_buffer);
    
    if(led->pulsesAmount < 0){
        sprintf(ledpulse_menu_buffer, ledpulse_menu_text_array[3], indicatorArray[2]);
        PCD8544_SetAddress(0,2);
        PCD8544_PrintString(ledpulse_menu_buffer);
    }
    else{
        sprintf(ledpulse_menu_buffer, ledpulse_menu_text_array[2], indicatorArray[2], led->pulsesAmount);
        PCD8544_SetAddress(0,2);
        PCD8544_PrintString(ledpulse_menu_buffer);
    }
}

void LedPulse_1_PulseHigh_Draw(void){
    LedPulseInstance_Draw_Helper(&led1, 0);
}

void LedPulse_1_PulseLow_Draw(void){
    LedPulseInstance_Draw_Helper(&led1, 1);
}

void LedPulse_1_Pulses_Draw(void){
    LedPulseInstance_Draw_Helper(&led1, 2);
}
    

void LedPulse_2_PulseHigh_Draw(void){
    LedPulseInstance_Draw_Helper(&led2, 0);
}

void LedPulse_2_PulseLow_Draw(void){
    LedPulseInstance_Draw_Helper(&led2, 1);
}

void LedPulse_2_Pulses_Draw(void){
    LedPulseInstance_Draw_Helper(&led2, 2);
}
    

void LedPulse_3_PulseHigh_Draw(void){
    LedPulseInstance_Draw_Helper(&led3, 0);
}

void LedPulse_3_PulseLow_Draw(void){
    LedPulseInstance_Draw_Helper(&led3, 1);
}

void LedPulse_3_Pulses_Draw(void){
    LedPulseInstance_Draw_Helper(&led3, 2);
}
    

void LedPulse_4_PulseHigh_Draw(void){
    LedPulseInstance_Draw_Helper(&led4, 0);
}

void LedPulse_4_PulseLow_Draw(void){
    LedPulseInstance_Draw_Helper(&led4, 1);
}

void LedPulse_4_Pulses_Draw(void){
    LedPulseInstance_Draw_Helper(&led4, 2);
}

static inline void LedPulse_PulseHighHelper(Led *led, bool increment){
    if(increment == true){
        led->pulseHighDurationTicks++;
    }
    else{
        led->pulseHighDurationTicks--;
    }
    MENU_RENDER();
}

static inline void LedPulse_PulseLowHelper(Led *led, bool increment){
    if(increment == true){
        led->pulseLowDurationTicks++;
    }
    else{
        led->pulseLowDurationTicks--;
    }
    MENU_RENDER();
}

static inline void LedPulse_PulsesHelper(Led *led, bool increment){
    if(increment == true){
        led->pulsesAmount++;
    }
    else{
        led->pulsesAmount--;
    }
    
    if(led->pulsesAmount < 0){
        led->pulsesAmount = -1;
    }
    MENU_RENDER();
}

void LedPulse_1_PulseHighInc(void){
    LedPulse_PulseHighHelper(&led1, true);
}
    
void LedPulse_1_PulseLowInc(void){
    LedPulse_PulseLowHelper(&led1, true);
}
    
void LedPulse_1_PulsesInc(void){
    LedPulse_PulsesHelper(&led1, true);
}

void LedPulse_1_PulseHighDec(void){
    LedPulse_PulseHighHelper(&led1, false);
}

void LedPulse_1_PulseLowDec(void){
    LedPulse_PulseLowHelper(&led1, false);
}

void LedPulse_1_PulsesDec(void){
    LedPulse_PulsesHelper(&led1, false);
}
    

void LedPulse_2_PulseHighInc(void){
    LedPulse_PulseHighHelper(&led2, true);
}

void LedPulse_2_PulseLowInc(void){
    LedPulse_PulseLowHelper(&led2, true);
}

void LedPulse_2_PulsesInc(void){
    LedPulse_PulsesHelper(&led2, true);
}

void LedPulse_2_PulseHighDec(void){
    LedPulse_PulseHighHelper(&led2, false);
}

void LedPulse_2_PulseLowDec(void){
    LedPulse_PulseLowHelper(&led2, false);
}

void LedPulse_2_PulsesDec(void){
    LedPulse_PulsesHelper(&led2, false);
}
    

void LedPulse_3_PulseHighInc(void){
    LedPulse_PulseHighHelper(&led3, true);
}

void LedPulse_3_PulseLowInc(void){
    LedPulse_PulseLowHelper(&led3, true);
}

void LedPulse_3_PulsesInc(void){
    LedPulse_PulsesHelper(&led3, true);
}

void LedPulse_3_PulseHighDec(void){
    LedPulse_PulseHighHelper(&led3, false);
}

void LedPulse_3_PulseLowDec(void){
    LedPulse_PulseLowHelper(&led3, false);
}

void LedPulse_3_PulsesDec(void){
    LedPulse_PulsesHelper(&led3, false);
}
    

void LedPulse_4_PulseHighInc(void){
    LedPulse_PulseHighHelper(&led4, true);
}

void LedPulse_4_PulseLowInc(void){
    LedPulse_PulseLowHelper(&led4, true);
}

void LedPulse_4_PulsesInc(void){
    LedPulse_PulsesHelper(&led4, true);
}

void LedPulse_4_PulseHighDec(void){
    LedPulse_PulseHighHelper(&led4, false);
}

void LedPulse_4_PulseLowDec(void){
    LedPulse_PulseLowHelper(&led4, false);
}

void LedPulse_4_PulsesDec(void){
    LedPulse_PulsesHelper(&led4, false);
}


