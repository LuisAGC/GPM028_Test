#include "MCP23017.h"
#include <xc.h>

#define MCP23017_RETRY_MAX       100  // define the retry count
#define MCP23017_ADDRESS         0x20 << 1 // slave device address
#define MCP23017_DEVICE_TIMEOUT  50   // define slave timeout 

uint8_t MCP23017_Read(uint8_t address) {
    uint8_t toReturn = 0x00;
    I2C2CONbits.SEN = 1;
    while(I2C2CONbits.SEN);
    
    I2C2TRN = MCP23017_ADDRESS | 0x00;
    while(I2C2STATbits.TBF == 1 || I2C2STATbits.TRSTAT == 1);
    if(I2C2STATbits.ACKSTAT == 1){
        return 0x00;
    }
    
    I2C2TRN = address;
    while(I2C2STATbits.TBF == 1 || I2C2STATbits.TRSTAT == 1);
    if(I2C2STATbits.ACKSTAT == 1){
        return 0x00;
    }
    
    I2C2CONbits.RSEN = 1;
    while(I2C2CONbits.RSEN);
    
    I2C2TRN = MCP23017_ADDRESS | 0x01;
    while(I2C2STATbits.TBF == 1 || I2C2STATbits.TRSTAT == 1);
    if(I2C2STATbits.ACKSTAT == 1){
        return 0x00;
    }
    
    uint32_t conbuf = I2C2CON;
    while((conbuf & 0b11111) > 0);
    I2C2CONbits.RCEN = 1;
    while(I2C2CONbits.RCEN);
    if(I2C2STATbits.ACKSTAT == 1){
        return 0x00;
    }
    
    toReturn = I2C2RCV;
    I2C2CONbits.ACKDT = 1;
    I2C2CONbits.ACKEN = 1;
    while(I2C2CONbits.ACKEN);
    
    I2C2CONbits.PEN = 1;
    while(I2C2CONbits.PEN);
    
    return toReturn;
}

void MCP23017_Write(uint8_t address, uint8_t data) {
    I2C2CONbits.SEN = 1;
    while(I2C2CONbits.SEN);
    
    I2C2TRN = MCP23017_ADDRESS | 0x00;
    while(I2C2STATbits.TBF == 1 || I2C2STATbits.TRSTAT == 1);
    if(I2C2STATbits.ACKSTAT == 1){
        return;
    }
    
    I2C2TRN = address;
    while(I2C2STATbits.TBF == 1 || I2C2STATbits.TRSTAT == 1);
    if(I2C2STATbits.ACKSTAT == 1){
        return;
    }
    
    I2C2CONbits.RSEN = 1;
    while(I2C2CONbits.RSEN);
    
    I2C2TRN = MCP23017_ADDRESS | 0x00;
    while(I2C2STATbits.TBF == 1 || I2C2STATbits.TRSTAT == 1);
    if(I2C2STATbits.ACKSTAT == 1){
        return;
    }
    
    I2C2TRN = data;
    while(I2C2STATbits.TBF == 1 || I2C2STATbits.TRSTAT == 1);
    if(I2C2STATbits.ACKSTAT == 1){
        return;
    }
        
    I2C2CONbits.PEN = 1;
    while(I2C2CONbits.PEN);
}