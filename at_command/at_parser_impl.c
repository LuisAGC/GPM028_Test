#include <stdio.h>
#include "at_parser_impl.h"
#include "../menu/ledstate_menu_callback.h"
#include "../menu/MicroMenu.h"

static const char command_led_state_text1[] = "Led %d is now ";
static const char command_led_pulse_text1[] = "Led %d pulse configuration changed\r\n";
static const char command_led_pulse_text2[] = "Pulses Amount: %d\r\n";
static const char command_led_pulse_text3[] = "Ticks Low: %d\r\n";
static const char command_led_pulse_text4[] = "Ticks High: %d\r\n";
static const char command_led_pulse_text5[] = "All Leds pulse configuration changed\r\n";
static const char command_led_text1[] = "Led %d is OK\r\n";

void Init_Parser(void){
    atCommandParserSingleton.callbackFn = commandSuccessfullyParsed;
    atCommandParserSingleton.errorCallbackFn = commandError;
}

void commandChangeLedState(Led *ledInstance, uint16_t state){
    switch(state){
        case 0:
            printf("Off\r\n");
            Led_Ticker(ledInstance, LED_OFF);
            break;
        case 1:
            printf("On\r\n");
            Led_Ticker(ledInstance, LED_ON);
            break;
        case 2:
            printf("Pulsing\r\n");
            Led_Ticker(ledInstance, LED_PULSE);
            break;
        default:
            break;
    }
}

static void commandLedState_Helper(uint16_t ledIndex, uint16_t ledStatus, Led * ledInstance){
    printf(command_led_state_text1, ledIndex+1);
    ledsCurrentState[0] = ledStatus;
    commandChangeLedState(ledInstance, ledStatus);
}

void commandLedState(ATCommand *command){
    switch(command->modifierIndex){
        case 0:
            switch(command->data[0]){
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                    commandLedState_Helper(command->data[0]-1, command->data[1], leds[command->data[0]-1]);
                    break;
                case 9:
                    printf("All Leds are now:\r\n");
                    for(uint16_t i = 0; i < 8; i++){
                        ledsCurrentState[i] = command->data[1];
                        commandChangeLedState(leds[i], command->data[1]);
                    }
                    break;
                default:
                    printf("Not an existing Led\r\n");
                    break;
            }
            break;
        case 1:
            switch(command->data[0]){
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                    printf(command_led_text1, command->data[0]);
                    break;
                case 9:
                    printf("All Leds are OK\r\n");
                    break;
                default:
                    printf("Not an existing Led\r\n");
                    break;
            }
            break;
        default:
            break;
    }
    MENU_RENDER();
}

void commandChangeLedPulse(Led *ledInstance, uint16_t pulses, uint16_t pulseLow, uint16_t pulseHigh){
    ledInstance->pulsesAmount = pulses;
    ledInstance->pulseLowDurationTicks = pulseLow;
    ledInstance->pulseHighDurationTicks = pulseHigh;
}

static void commandLedPulse_Helper(uint16_t ledIndex, Led * ledInstance, uint16_t pulses, uint16_t pulseLow, uint16_t pulseHigh){
    printf(command_led_pulse_text1, ledIndex);
    printf(command_led_pulse_text2, pulses);
    printf(command_led_pulse_text3, pulseLow);
    printf(command_led_pulse_text4, pulseHigh);
    commandChangeLedPulse(ledInstance, pulses, pulseLow, pulseHigh);
}

void commandLedPulse(ATCommand *command){
    switch(command->modifierIndex){
        case 0:
            switch(command->data[0]){
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:  
                case 6:
                case 7:
                case 8:
                    commandLedPulse_Helper(command->data[0], leds[command->data[0]-1], command->data[1], command->data[2], command->data[3]);
                    break;
                case 9:
                    printf(command_led_pulse_text5);
                    printf(command_led_pulse_text2, command->data[1]);
                    printf(command_led_pulse_text3, command->data[2]);
                    printf(command_led_pulse_text4, command->data[3]);
                    for(uint16_t i = 0; i < 8; i++){
                        commandChangeLedPulse(leds[i], command->data[1], command->data[2], command->data[3]);
                    }
                    break;
                default:
                    printf("Not an existing Led\r\n");
                    break;
            }
            break;
        case 1:
            switch(command->data[0]){
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                    printf(command_led_text1, command->data[0]);
                    break;
                case 9:
                    printf("All Leds are OK\r\n");
                    break;
                default:
                    printf("Not an existing Led\r\n");
                    break;
            }
            break;
        default:
            break;
    }
    MENU_RENDER();
}

void commandPwmPeriod(ATCommand *command){
    uint16_t SCCP4_primaryValue = CCP4RA;
    uint16_t SCCP4_secondaryValue = CCP4RB;
    switch(command->modifierIndex){
        case 0:
            SCCP4_COMPARE_DualEdgeBufferedConfig(SCCP4_primaryValue, command->data[0]);
            printf("PWM Period Set to %u\r\n",command->data[0]);
            break;
        case 1:
            printf("PWM Period is set to %u\r\n", SCCP4_secondaryValue);
            break;
    }
    MENU_RENDER();
}

void commandPwmDuty(ATCommand *command){
    uint16_t SCCP4_primaryValue = CCP4RA;
    uint16_t SCCP4_secondaryValue = CCP4RB;
    switch(command->modifierIndex){
        case 0:
            SCCP4_COMPARE_DualEdgeBufferedConfig(command->data[0], SCCP4_secondaryValue);
            printf("PWM Duty Set to %u\r\n",command->data[0]);
            break;
        case 1:
            printf("PWM Duty is set to %u\r\n", SCCP4_primaryValue);
            break;
    }
    MENU_RENDER();
}

void commandSuccessfullyParsed(ATCommand *command){
    printf("OK: \r\n");
    switch(command->commandIndex){
        case 0:
            commandLedState(command);
            break;
        case 1:
            commandLedPulse(command);
            break;
        case 2:
            commandPwmPeriod(command);
            break;
        case 3:
            commandPwmDuty(command);
            break;
        default:
            break;
    }
}

void commandError(){
    printf("Invalid Command\r\n");
}