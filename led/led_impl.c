#include "led_impl.h"

Led led1 = {
    .currentPulses = 0, 
    .currentStateFn = Led_Idle,
    .currentTicks = 0,
    .ledChangeCallbackFn = &Led1_Callback,
    .ledLastPhyState = LED_OFF,
    .pulseHighDurationTicks = 16,
    .pulseLowDurationTicks = 16,
    .pulsesAmount = LED_PULSE_FOREVER
};

Led led2 = {
    .currentPulses = 0, 
    .currentStateFn = Led_Idle,
    .currentTicks = 0,
    .ledChangeCallbackFn = &Led2_Callback,
    .ledLastPhyState = LED_OFF,
    .pulseHighDurationTicks = 32,
    .pulseLowDurationTicks = 32,
    .pulsesAmount = LED_PULSE_FOREVER
};

Led led3 = {
    .currentPulses = 0, 
    .currentStateFn = Led_Idle,
    .currentTicks = 0,
    .ledChangeCallbackFn = &Led3_Callback,
    .ledLastPhyState = LED_OFF,
    .pulseHighDurationTicks = 64,
    .pulseLowDurationTicks = 64,
    .pulsesAmount = LED_PULSE_FOREVER
};

Led led4 = {
    .currentPulses = 0, 
    .currentStateFn = Led_Idle,
    .currentTicks = 0,
    .ledChangeCallbackFn = &Led4_Callback,
    .ledLastPhyState = LED_OFF,
    .pulseHighDurationTicks = 128,
    .pulseLowDurationTicks = 128,
    .pulsesAmount = LED_PULSE_FOREVER
};

Led led5 = {
    .currentPulses = 0, 
    .currentStateFn = Led_Idle,
    .currentTicks = 0,
    .ledChangeCallbackFn = &Led5_Callback,
    .ledLastPhyState = LED_OFF,
    .pulseHighDurationTicks = 256,
    .pulseLowDurationTicks = 256,
    .pulsesAmount = LED_PULSE_FOREVER
};

Led led6 = {
    .currentPulses = 0, 
    .currentStateFn = Led_Idle,
    .currentTicks = 0,
    .ledChangeCallbackFn = &Led6_Callback,
    .ledLastPhyState = LED_OFF,
    .pulseHighDurationTicks = 512,
    .pulseLowDurationTicks = 512,
    .pulsesAmount = LED_PULSE_FOREVER
};

Led led7 = {
    .currentPulses = 0, 
    .currentStateFn = Led_Idle,
    .currentTicks = 0,
    .ledChangeCallbackFn = &Led7_Callback,
    .ledLastPhyState = LED_OFF,
    .pulseHighDurationTicks = 1024,
    .pulseLowDurationTicks = 1024,
    .pulsesAmount = LED_PULSE_FOREVER
};

Led led8 = {
    .currentPulses = 0, 
    .currentStateFn = Led_Idle,
    .currentTicks = 0,
    .ledChangeCallbackFn = &Led8_Callback,
    .ledLastPhyState = LED_OFF,
    .pulseHighDurationTicks = 2048,
    .pulseLowDurationTicks = 2048,
    .pulsesAmount = LED_PULSE_FOREVER
};

Led *leds[8] = {&led1, &led2, &led3, &led4, &led5, &led6, &led7, &led8};

uint8_t leds_register;

void Init_Leds(void){
    Led_Ticker(&led1, LED_OFF);
    Led_Ticker(&led2, LED_OFF);
    Led_Ticker(&led3, LED_OFF);
    Led_Ticker(&led4, LED_OFF);
    Led_Ticker(&led5, LED_OFF);
    Led_Ticker(&led6, LED_OFF);
    Led_Ticker(&led7, LED_OFF);
    Led_Ticker(&led8, LED_OFF);
}

static inline void Led_Helper(uint8_t ledPosition, bool phyState){
    if(phyState){
        leds_register |= 1 << ledPosition;
    }
    else{
        leds_register &= ~(1 << ledPosition);
    }
}

void Led1_Callback(bool phyState){
    Led_Helper(0, phyState);
}

void Led2_Callback(bool phyState){
    Led_Helper(1, phyState);
}

void Led3_Callback(bool phyState){
    Led_Helper(2, phyState);
}

void Led4_Callback(bool phyState){
    Led_Helper(3, phyState);
}

void Led5_Callback(bool phyState){
    Led_Helper(4, phyState);
}

void Led6_Callback(bool phyState){
    Led_Helper(5, phyState);
}

void Led7_Callback(bool phyState){
    Led_Helper(6, phyState);
}

void Led8_Callback(bool phyState){
    Led_Helper(7, phyState);
}