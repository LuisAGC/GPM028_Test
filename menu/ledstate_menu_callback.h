#ifndef LEDSTATE_MENU_CALLBACK_H
#define	LEDSTATE_MENU_CALLBACK_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    extern uint16_t ledsCurrentState[8];
    
    void LedState_1_Draw(void);
    void LedState_2_Draw(void);
    void LedState_3_Draw(void);
    void LedState_4_Draw(void);
    void LedState_5_Draw(void);
    void LedState_6_Draw(void);
    void LedState_7_Draw(void);
    void LedState_8_Draw(void);
    
    void LedState_1_Callback(void);
    void LedState_2_Callback(void);
    void LedState_3_Callback(void);
    void LedState_4_Callback(void);
    void LedState_5_Callback(void);
    void LedState_6_Callback(void);
    void LedState_7_Callback(void);
    void LedState_8_Callback(void);
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* LEDSTATE_MENU_CALLBACK_H */

