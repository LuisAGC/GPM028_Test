#include "../PCD8544/pcd8544.h"
#include "../mcc_generated_files/pin_manager.h"
#include "../mcc_generated_files/spi2.h"

void PCD8544_SPI_SendBuffer(uint8_t * buffer, uint16_t size){
    SPI2_Exchange8bitBuffer(buffer, size, NULL);
}

void PCD8544_DC_Command(){
    LCD_DC_SetLow();
}

void PCD8544_DC_Data(){
    LCD_DC_SetHigh();
}

void PCD8544_ChipEnable(){
    LCD_CE_SetLow();
}

void PCD8544_ChipDisable(){
    LCD_CE_SetHigh();
}

void PCD8544_Reset(){
    LCD_RESET_SetHigh();
    LCD_RESET_SetLow();
    LCD_RESET_SetHigh();
}