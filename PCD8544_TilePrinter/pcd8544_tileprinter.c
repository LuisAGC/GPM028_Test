#include "pcd8544_tileprinter.h"

void PCD8544_PrintChar(unsigned char character){
    character = character < 0x20 ? 0x20 : character;
    character = character - 0x20;
    
    uint8_t char_buffer[6];
    
    for(uint8_t i = 0; i < 5; i++){
        char_buffer[i] = FONT_TABLE[character][i];    
    }
    char_buffer[5] = 0;
    PCD8544_SendDataBuffer(char_buffer, 6);
}

void PCD8544_PrintString(char string[]){
    while(*(string) != '\0') {
        PCD8544_PrintChar(*string++);
    } 
}

void PCD8544_PrintTile(uint8_t tileIndex, bool reverse){
    uint8_t tile_buffer[6];
    
    if(!reverse){
        for(uint8_t i = 0; i < 6; i++){
            tile_buffer[i] = TILE_TABLE[tileIndex][i];    
        }
    }
    else{
        for(uint8_t i = 0; i < 6; i++){
            tile_buffer[i] = TILE_TABLE[tileIndex][5-i];    
        }
    }
    PCD8544_SendDataBuffer(tile_buffer, 6);
}