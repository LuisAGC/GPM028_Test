#ifndef PCD8544_TILEPRINTER_H
#define	PCD8544_TILEPRINTER_H

#include <stdint.h>
#include <stdbool.h>

#include "../PCD8544/pcd8544.h"
#include "font.h"
#include "tile.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    void PCD8544_PrintChar(unsigned char character);
    void PCD8544_PrintString(char string[]);
    
    void PCD8544_PrintTile(uint8_t tileIndex, bool reverse);
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* PCD8544_TILEPRINTER_H */

