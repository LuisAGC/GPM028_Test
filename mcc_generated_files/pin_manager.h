/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC32MM0256GPM028
    The generated drivers are tested against the following:
        Compiler          :  XC32 v2.50
        MPLAB 	          :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>
#include <stdbool.h>
/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RB10, high using LATB10.

  @Description
    Sets the GPIO pin, RB10, high using LATB10.

  @Preconditions
    The RB10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB10 high (1)
    LCD_RESET_SetHigh();
    </code>

*/
#define LCD_RESET_SetHigh()          ( LATBSET = (1 << 10) )
/**
  @Summary
    Sets the GPIO pin, RB10, low using LATB10.

  @Description
    Sets the GPIO pin, RB10, low using LATB10.

  @Preconditions
    The RB10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB10 low (0)
    LCD_RESET_SetLow();
    </code>

*/
#define LCD_RESET_SetLow()           ( LATBCLR = (1 << 10) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB10, low or high using LATB10.

  @Preconditions
    The RB10 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB10 to low.
    LCD_RESET_SetValue(false);
    </code>

*/
inline static void LCD_RESET_SetValue(bool value)
{
  if(value)
  {
    LCD_RESET_SetHigh();
  }
  else
  {
    LCD_RESET_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB10, using LATB10.

  @Description
    Toggles the GPIO pin, RB10, using LATB10.

  @Preconditions
    The RB10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB10
    LCD_RESET_Toggle();
    </code>

*/
#define LCD_RESET_Toggle()           ( LATBINV = (1 << 10) )
/**
  @Summary
    Reads the value of the GPIO pin, RB10.

  @Description
    Reads the value of the GPIO pin, RB10.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB10
    postValue = LCD_RESET_GetValue();
    </code>

*/
#define LCD_RESET_GetValue()         PORTBbits.RB10
/**
  @Summary
    Configures the GPIO pin, RB10, as an input.

  @Description
    Configures the GPIO pin, RB10, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB10 as an input
    LCD_RESET_SetDigitalInput();
    </code>

*/
#define LCD_RESET_SetDigitalInput()   ( TRISBSET = (1 << 10) )
/**
  @Summary
    Configures the GPIO pin, RB10, as an output.

  @Description
    Configures the GPIO pin, RB10, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB10 as an output
    LCD_RESET_SetDigitalOutput();
    </code>

*/
#define LCD_RESET_SetDigitalOutput()   ( TRISBCLR = (1 << 10) )
/**
  @Summary
    Sets the GPIO pin, RB11, high using LATB11.

  @Description
    Sets the GPIO pin, RB11, high using LATB11.

  @Preconditions
    The RB11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB11 high (1)
    LCD_CE_SetHigh();
    </code>

*/
#define LCD_CE_SetHigh()          ( LATBSET = (1 << 11) )
/**
  @Summary
    Sets the GPIO pin, RB11, low using LATB11.

  @Description
    Sets the GPIO pin, RB11, low using LATB11.

  @Preconditions
    The RB11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB11 low (0)
    LCD_CE_SetLow();
    </code>

*/
#define LCD_CE_SetLow()           ( LATBCLR = (1 << 11) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB11, low or high using LATB11.

  @Preconditions
    The RB11 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB11 to low.
    LCD_CE_SetValue(false);
    </code>

*/
inline static void LCD_CE_SetValue(bool value)
{
  if(value)
  {
    LCD_CE_SetHigh();
  }
  else
  {
    LCD_CE_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB11, using LATB11.

  @Description
    Toggles the GPIO pin, RB11, using LATB11.

  @Preconditions
    The RB11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB11
    LCD_CE_Toggle();
    </code>

*/
#define LCD_CE_Toggle()           ( LATBINV = (1 << 11) )
/**
  @Summary
    Reads the value of the GPIO pin, RB11.

  @Description
    Reads the value of the GPIO pin, RB11.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB11
    postValue = LCD_CE_GetValue();
    </code>

*/
#define LCD_CE_GetValue()         PORTBbits.RB11
/**
  @Summary
    Configures the GPIO pin, RB11, as an input.

  @Description
    Configures the GPIO pin, RB11, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB11 as an input
    LCD_CE_SetDigitalInput();
    </code>

*/
#define LCD_CE_SetDigitalInput()   ( TRISBSET = (1 << 11) )
/**
  @Summary
    Configures the GPIO pin, RB11, as an output.

  @Description
    Configures the GPIO pin, RB11, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB11 as an output
    LCD_CE_SetDigitalOutput();
    </code>

*/
#define LCD_CE_SetDigitalOutput()   ( TRISBCLR = (1 << 11) )
/**
  @Summary
    Sets the GPIO pin, RB13, high using LATB13.

  @Description
    Sets the GPIO pin, RB13, high using LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB13 high (1)
    LCD_DC_SetHigh();
    </code>

*/
#define LCD_DC_SetHigh()          ( LATBSET = (1 << 13) )
/**
  @Summary
    Sets the GPIO pin, RB13, low using LATB13.

  @Description
    Sets the GPIO pin, RB13, low using LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB13 low (0)
    LCD_DC_SetLow();
    </code>

*/
#define LCD_DC_SetLow()           ( LATBCLR = (1 << 13) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB13, low or high using LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB13 to low.
    LCD_DC_SetValue(false);
    </code>

*/
inline static void LCD_DC_SetValue(bool value)
{
  if(value)
  {
    LCD_DC_SetHigh();
  }
  else
  {
    LCD_DC_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB13, using LATB13.

  @Description
    Toggles the GPIO pin, RB13, using LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB13
    LCD_DC_Toggle();
    </code>

*/
#define LCD_DC_Toggle()           ( LATBINV = (1 << 13) )
/**
  @Summary
    Reads the value of the GPIO pin, RB13.

  @Description
    Reads the value of the GPIO pin, RB13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB13
    postValue = LCD_DC_GetValue();
    </code>

*/
#define LCD_DC_GetValue()         PORTBbits.RB13
/**
  @Summary
    Configures the GPIO pin, RB13, as an input.

  @Description
    Configures the GPIO pin, RB13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB13 as an input
    LCD_DC_SetDigitalInput();
    </code>

*/
#define LCD_DC_SetDigitalInput()   ( TRISBSET = (1 << 13) )
/**
  @Summary
    Configures the GPIO pin, RB13, as an output.

  @Description
    Configures the GPIO pin, RB13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB13 as an output
    LCD_DC_SetDigitalOutput();
    </code>

*/
#define LCD_DC_SetDigitalOutput()   ( TRISBCLR = (1 << 13) )
/**
  @Summary
    Sets the GPIO pin, RB14, high using LATB14.

  @Description
    Sets the GPIO pin, RB14, high using LATB14.

  @Preconditions
    The RB14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB14 high (1)
    SDO2_SetHigh();
    </code>

*/
#define SDO2_SetHigh()          ( LATBSET = (1 << 14) )
/**
  @Summary
    Sets the GPIO pin, RB14, low using LATB14.

  @Description
    Sets the GPIO pin, RB14, low using LATB14.

  @Preconditions
    The RB14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB14 low (0)
    SDO2_SetLow();
    </code>

*/
#define SDO2_SetLow()           ( LATBCLR = (1 << 14) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB14, low or high using LATB14.

  @Preconditions
    The RB14 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB14 to low.
    SDO2_SetValue(false);
    </code>

*/
inline static void SDO2_SetValue(bool value)
{
  if(value)
  {
    SDO2_SetHigh();
  }
  else
  {
    SDO2_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB14, using LATB14.

  @Description
    Toggles the GPIO pin, RB14, using LATB14.

  @Preconditions
    The RB14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB14
    SDO2_Toggle();
    </code>

*/
#define SDO2_Toggle()           ( LATBINV = (1 << 14) )
/**
  @Summary
    Reads the value of the GPIO pin, RB14.

  @Description
    Reads the value of the GPIO pin, RB14.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB14
    postValue = SDO2_GetValue();
    </code>

*/
#define SDO2_GetValue()         PORTBbits.RB14
/**
  @Summary
    Configures the GPIO pin, RB14, as an input.

  @Description
    Configures the GPIO pin, RB14, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB14 as an input
    SDO2_SetDigitalInput();
    </code>

*/
#define SDO2_SetDigitalInput()   ( TRISBSET = (1 << 14) )
/**
  @Summary
    Configures the GPIO pin, RB14, as an output.

  @Description
    Configures the GPIO pin, RB14, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB14 as an output
    SDO2_SetDigitalOutput();
    </code>

*/
#define SDO2_SetDigitalOutput()   ( TRISBCLR = (1 << 14) )
/**
  @Summary
    Sets the GPIO pin, RB15, high using LATB15.

  @Description
    Sets the GPIO pin, RB15, high using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB15 high (1)
    SCK2OUT_SetHigh();
    </code>

*/
#define SCK2OUT_SetHigh()          ( LATBSET = (1 << 15) )
/**
  @Summary
    Sets the GPIO pin, RB15, low using LATB15.

  @Description
    Sets the GPIO pin, RB15, low using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB15 low (0)
    SCK2OUT_SetLow();
    </code>

*/
#define SCK2OUT_SetLow()           ( LATBCLR = (1 << 15) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RB15, low or high using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RB15 to low.
    SCK2OUT_SetValue(false);
    </code>

*/
inline static void SCK2OUT_SetValue(bool value)
{
  if(value)
  {
    SCK2OUT_SetHigh();
  }
  else
  {
    SCK2OUT_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RB15, using LATB15.

  @Description
    Toggles the GPIO pin, RB15, using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB15
    SCK2OUT_Toggle();
    </code>

*/
#define SCK2OUT_Toggle()           ( LATBINV = (1 << 15) )
/**
  @Summary
    Reads the value of the GPIO pin, RB15.

  @Description
    Reads the value of the GPIO pin, RB15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB15
    postValue = SCK2OUT_GetValue();
    </code>

*/
#define SCK2OUT_GetValue()         PORTBbits.RB15
/**
  @Summary
    Configures the GPIO pin, RB15, as an input.

  @Description
    Configures the GPIO pin, RB15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB15 as an input
    SCK2OUT_SetDigitalInput();
    </code>

*/
#define SCK2OUT_SetDigitalInput()   ( TRISBSET = (1 << 15) )
/**
  @Summary
    Configures the GPIO pin, RB15, as an output.

  @Description
    Configures the GPIO pin, RB15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB15 as an output
    SCK2OUT_SetDigitalOutput();
    </code>

*/
#define SCK2OUT_SetDigitalOutput()   ( TRISBCLR = (1 << 15) )

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the PIC32MM0256GPM028
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);



#endif
