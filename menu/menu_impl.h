#ifndef MENU_IMPL_H
#define	MENU_IMPL_H

#include "MicroMenu.h"
#include "main_menu_callback.h"
#include "ledstate_menu_callback.h"
#include "ledpulse_menu_callback.h"
#include "pwm_menu_callback.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    //Main menu items, callbacks are in main_menu_callback.h, if a new entry is needed remember to also add the callbacks
    MENU_ITEM(MainMenu_LedState,    MainMenu_LedPulse,  MainMenu_PWM,       NULL_MENU, LedState_1,  NULL, NULL, MainMenu_LedState_Draw);
    MENU_ITEM(MainMenu_LedPulse,    MainMenu_PWM,       MainMenu_LedState,  NULL_MENU, LedPulse_1,  NULL, NULL, MainMenu_LedPulse_Draw);
    MENU_ITEM(MainMenu_PWM,         MainMenu_LedState,  MainMenu_LedPulse,  NULL_MENU, PWM_Duty,    NULL, NULL, MainMenu_PWM_Draw);
    
    //Led state menu items, callbacks are in ledstate_menu_callback.h, if a new entry is needed remember to also add the callbacks
    MENU_ITEM(LedState_1,       LedState_2,     LedState_8,     MainMenu_LedState,  LedState_1_Sub, NULL, NULL,     LedState_1_Draw);
    MENU_ITEM(LedState_2,       LedState_3,     LedState_1,     MainMenu_LedState,  LedState_2_Sub, NULL, NULL,     LedState_2_Draw);
    MENU_ITEM(LedState_3,       LedState_4,     LedState_2,     MainMenu_LedState,  LedState_3_Sub, NULL, NULL,     LedState_3_Draw);
    MENU_ITEM(LedState_4,       LedState_5,     LedState_3,     MainMenu_LedState,  LedState_4_Sub, NULL, NULL,     LedState_4_Draw);
    MENU_ITEM(LedState_5,       LedState_6,     LedState_4,     MainMenu_LedState,  LedState_5_Sub, NULL, NULL,     LedState_5_Draw);
    MENU_ITEM(LedState_6,       LedState_7,     LedState_5,     MainMenu_LedState,  LedState_6_Sub, NULL, NULL,     LedState_6_Draw);
    MENU_ITEM(LedState_7,       LedState_8,     LedState_6,     MainMenu_LedState,  LedState_7_Sub, NULL, NULL,     LedState_7_Draw);
    MENU_ITEM(LedState_8,       LedState_1,     LedState_7,     MainMenu_LedState,  LedState_8_Sub, NULL, NULL,     LedState_8_Draw);
    
    MENU_ITEM(LedState_1_Sub,   NULL_MENU,      NULL_MENU,      LedState_1,         NULL_MENU,      NULL, NULL,     LedState_1_Callback);
    MENU_ITEM(LedState_2_Sub,   NULL_MENU,      NULL_MENU,      LedState_2,         NULL_MENU,      NULL, NULL,     LedState_2_Callback);
    MENU_ITEM(LedState_3_Sub,   NULL_MENU,      NULL_MENU,      LedState_3,         NULL_MENU,      NULL, NULL,     LedState_3_Callback);
    MENU_ITEM(LedState_4_Sub,   NULL_MENU,      NULL_MENU,      LedState_4,         NULL_MENU,      NULL, NULL,     LedState_4_Callback);
    MENU_ITEM(LedState_5_Sub,   NULL_MENU,      NULL_MENU,      LedState_5,         NULL_MENU,      NULL, NULL,     LedState_5_Callback);
    MENU_ITEM(LedState_6_Sub,   NULL_MENU,      NULL_MENU,      LedState_6,         NULL_MENU,      NULL, NULL,     LedState_6_Callback);
    MENU_ITEM(LedState_7_Sub,   NULL_MENU,      NULL_MENU,      LedState_7,         NULL_MENU,      NULL, NULL,     LedState_7_Callback);
    MENU_ITEM(LedState_8_Sub,   NULL_MENU,      NULL_MENU,      LedState_8,         NULL_MENU,      NULL, NULL,     LedState_8_Callback);
    
    //Led pulse menu items, callbacks are in ledpulse_menu_callback.h, if a new entry is needed remember to also add the callbacks
    MENU_ITEM(LedPulse_1, LedPulse_2, LedPulse_8, MainMenu_LedPulse, LedPulse_1_PulseHigh, NULL, NULL, LedPulse_1_Draw);
    MENU_ITEM(LedPulse_2, LedPulse_3, LedPulse_1, MainMenu_LedPulse, LedPulse_2_PulseHigh, NULL, NULL, LedPulse_2_Draw);
    MENU_ITEM(LedPulse_3, LedPulse_4, LedPulse_2, MainMenu_LedPulse, LedPulse_3_PulseHigh, NULL, NULL, LedPulse_3_Draw);
    MENU_ITEM(LedPulse_4, LedPulse_5, LedPulse_3, MainMenu_LedPulse, LedPulse_4_PulseHigh, NULL, NULL, LedPulse_4_Draw);
    MENU_ITEM(LedPulse_5, LedPulse_6, LedPulse_4, MainMenu_LedPulse, LedPulse_5_PulseHigh, NULL, NULL, LedPulse_5_Draw);
    MENU_ITEM(LedPulse_6, LedPulse_7, LedPulse_5, MainMenu_LedPulse, LedPulse_6_PulseHigh, NULL, NULL, LedPulse_6_Draw);
    MENU_ITEM(LedPulse_7, LedPulse_8, LedPulse_6, MainMenu_LedPulse, LedPulse_7_PulseHigh, NULL, NULL, LedPulse_7_Draw);
    MENU_ITEM(LedPulse_8, LedPulse_1, LedPulse_7, MainMenu_LedPulse, LedPulse_8_PulseHigh, NULL, NULL, LedPulse_8_Draw);
    
    MENU_ITEM(LedPulse_1_PulseHigh, LedPulse_1_PulseLow,    LedPulse_1_Pulses,      LedPulse_1, NULL_MENU, LedPulse_1_PulseHighInc, LedPulse_1_PulseHighDec,    LedPulse_1_PulseHigh_Draw);
    MENU_ITEM(LedPulse_1_PulseLow,  LedPulse_1_Pulses,      LedPulse_1_PulseHigh,   LedPulse_1, NULL_MENU, LedPulse_1_PulseLowInc,  LedPulse_1_PulseLowDec,     LedPulse_1_PulseLow_Draw);
    MENU_ITEM(LedPulse_1_Pulses,    LedPulse_1_PulseHigh,   LedPulse_1_PulseLow,    LedPulse_1, NULL_MENU, LedPulse_1_PulsesInc,    LedPulse_1_PulsesDec,       LedPulse_1_Pulses_Draw);
    
    MENU_ITEM(LedPulse_2_PulseHigh, LedPulse_2_PulseLow,    LedPulse_2_Pulses,      LedPulse_2, NULL_MENU, LedPulse_2_PulseHighInc, LedPulse_2_PulseHighDec,    LedPulse_2_PulseHigh_Draw);
    MENU_ITEM(LedPulse_2_PulseLow,  LedPulse_2_Pulses,      LedPulse_2_PulseHigh,   LedPulse_2, NULL_MENU, LedPulse_2_PulseLowInc,  LedPulse_2_PulseLowDec,     LedPulse_2_PulseLow_Draw);
    MENU_ITEM(LedPulse_2_Pulses,    LedPulse_2_PulseHigh,   LedPulse_2_PulseLow,    LedPulse_2, NULL_MENU, LedPulse_2_PulsesInc,    LedPulse_2_PulsesDec,       LedPulse_2_Pulses_Draw);
    
    MENU_ITEM(LedPulse_3_PulseHigh, LedPulse_3_PulseLow,    LedPulse_3_Pulses,      LedPulse_3, NULL_MENU, LedPulse_3_PulseHighInc, LedPulse_3_PulseHighDec,    LedPulse_3_PulseHigh_Draw);
    MENU_ITEM(LedPulse_3_PulseLow,  LedPulse_3_Pulses,      LedPulse_3_PulseHigh,   LedPulse_3, NULL_MENU, LedPulse_3_PulseLowInc,  LedPulse_3_PulseLowDec,     LedPulse_3_PulseLow_Draw);
    MENU_ITEM(LedPulse_3_Pulses,    LedPulse_3_PulseHigh,   LedPulse_3_PulseLow,    LedPulse_3, NULL_MENU, LedPulse_3_PulsesInc,    LedPulse_3_PulsesDec,       LedPulse_3_Pulses_Draw);
    
    MENU_ITEM(LedPulse_4_PulseHigh, LedPulse_4_PulseLow,    LedPulse_4_Pulses,      LedPulse_4, NULL_MENU, LedPulse_4_PulseHighInc, LedPulse_4_PulseHighDec,    LedPulse_4_PulseHigh_Draw);
    MENU_ITEM(LedPulse_4_PulseLow,  LedPulse_4_Pulses,      LedPulse_4_PulseHigh,   LedPulse_4, NULL_MENU, LedPulse_4_PulseLowInc,  LedPulse_4_PulseLowDec,     LedPulse_4_PulseLow_Draw);
    MENU_ITEM(LedPulse_4_Pulses,    LedPulse_4_PulseHigh,   LedPulse_4_PulseLow,    LedPulse_4, NULL_MENU, LedPulse_4_PulsesInc,    LedPulse_4_PulsesDec,       LedPulse_4_Pulses_Draw);
    
    MENU_ITEM(LedPulse_5_PulseHigh, LedPulse_5_PulseLow,    LedPulse_5_Pulses,      LedPulse_5, NULL_MENU, LedPulse_5_PulseHighInc, LedPulse_5_PulseHighDec,    LedPulse_5_PulseHigh_Draw);
    MENU_ITEM(LedPulse_5_PulseLow,  LedPulse_5_Pulses,      LedPulse_5_PulseHigh,   LedPulse_5, NULL_MENU, LedPulse_5_PulseLowInc,  LedPulse_5_PulseLowDec,     LedPulse_5_PulseLow_Draw);
    MENU_ITEM(LedPulse_5_Pulses,    LedPulse_5_PulseHigh,   LedPulse_5_PulseLow,    LedPulse_5, NULL_MENU, LedPulse_5_PulsesInc,    LedPulse_5_PulsesDec,       LedPulse_5_Pulses_Draw);
    
    MENU_ITEM(LedPulse_6_PulseHigh, LedPulse_6_PulseLow,    LedPulse_6_Pulses,      LedPulse_6, NULL_MENU, LedPulse_6_PulseHighInc, LedPulse_6_PulseHighDec,    LedPulse_6_PulseHigh_Draw);
    MENU_ITEM(LedPulse_6_PulseLow,  LedPulse_6_Pulses,      LedPulse_6_PulseHigh,   LedPulse_6, NULL_MENU, LedPulse_6_PulseLowInc,  LedPulse_6_PulseLowDec,     LedPulse_6_PulseLow_Draw);
    MENU_ITEM(LedPulse_6_Pulses,    LedPulse_6_PulseHigh,   LedPulse_6_PulseLow,    LedPulse_6, NULL_MENU, LedPulse_6_PulsesInc,    LedPulse_6_PulsesDec,       LedPulse_6_Pulses_Draw);
    
    MENU_ITEM(LedPulse_7_PulseHigh, LedPulse_7_PulseLow,    LedPulse_7_Pulses,      LedPulse_7, NULL_MENU, LedPulse_7_PulseHighInc, LedPulse_7_PulseHighDec,    LedPulse_7_PulseHigh_Draw);
    MENU_ITEM(LedPulse_7_PulseLow,  LedPulse_7_Pulses,      LedPulse_7_PulseHigh,   LedPulse_7, NULL_MENU, LedPulse_7_PulseLowInc,  LedPulse_7_PulseLowDec,     LedPulse_7_PulseLow_Draw);
    MENU_ITEM(LedPulse_7_Pulses,    LedPulse_7_PulseHigh,   LedPulse_7_PulseLow,    LedPulse_7, NULL_MENU, LedPulse_7_PulsesInc,    LedPulse_7_PulsesDec,       LedPulse_7_Pulses_Draw);
    
    MENU_ITEM(LedPulse_8_PulseHigh, LedPulse_8_PulseLow,    LedPulse_8_Pulses,      LedPulse_8, NULL_MENU, LedPulse_8_PulseHighInc, LedPulse_8_PulseHighDec,    LedPulse_8_PulseHigh_Draw);
    MENU_ITEM(LedPulse_8_PulseLow,  LedPulse_8_Pulses,      LedPulse_8_PulseHigh,   LedPulse_8, NULL_MENU, LedPulse_8_PulseLowInc,  LedPulse_8_PulseLowDec,     LedPulse_8_PulseLow_Draw);
    MENU_ITEM(LedPulse_8_Pulses,    LedPulse_8_PulseHigh,   LedPulse_8_PulseLow,    LedPulse_8, NULL_MENU, LedPulse_8_PulsesInc,    LedPulse_8_PulsesDec,       LedPulse_8_Pulses_Draw);
    
    //PWM menu items, callbacks are in pwm_menu_callback.h, if a new entry is needed remember to also add the callbacks
    MENU_ITEM(PWM_Duty,     PWM_Period, PWM_Period, MainMenu_PWM,  NULL_MENU, PWM_DutyInc,      PWM_DutyDec,    PWM_Duty_Draw);
    MENU_ITEM(PWM_Period,   PWM_Duty,   PWM_Duty,   MainMenu_PWM,  NULL_MENU, PWM_PeriodInc,    PWM_PeriodDec,  PWM_Period_Draw);
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* MENU_IMPL_H */

