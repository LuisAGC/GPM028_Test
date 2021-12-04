#ifndef MCP23017_H
#define	MCP23017_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

    uint8_t MCP23017_Read(uint8_t address);
    void MCP23017_Write(uint8_t address, uint8_t data);
    

#ifdef	__cplusplus
}
#endif

#endif	/* MCP23017_H */