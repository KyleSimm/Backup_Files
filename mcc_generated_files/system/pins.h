/**
 * PINS Generated Driver Header File 
 * 
 * @file      pins.h
 *            
 * @defgroup  pinsdriver Pins Driver
 *            
 * @brief     The Pin Driver directs the operation and function of 
 *            the selected device pins using dsPIC MCUs.
 *
 * @skipline @version   Firmware Driver Version 1.0.2
 *
 * @skipline @version   PLIB Version 1.4.1
 *
 * @skipline  Device : dsPIC33CK256MP508
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H
// Section: Includes
#include <xc.h>

// Section: Device Pin Macros

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC12 GPIO Pin which has a custom name of IO_RC12 to High
 * @pre      The RC12 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RC12_SetHigh()          (_LATC12 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC12 GPIO Pin which has a custom name of IO_RC12 to Low
 * @pre      The RC12 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC12_SetLow()           (_LATC12 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RC12 GPIO Pin which has a custom name of IO_RC12
 * @pre      The RC12 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC12_Toggle()           (_LATC12 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RC12 GPIO Pin which has a custom name of IO_RC12
 * @param    none
 * @return   none  
 */
#define IO_RC12_GetValue()         _RC12

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC12 GPIO Pin which has a custom name of IO_RC12 as Input
 * @param    none
 * @return   none  
 */
#define IO_RC12_SetDigitalInput()  (_TRISC12 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC12 GPIO Pin which has a custom name of IO_RC12 as Output
 * @param    none
 * @return   none  
 */
#define IO_RC12_SetDigitalOutput() (_TRISC12 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC13 GPIO Pin which has a custom name of IO_RC13 to High
 * @pre      The RC13 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RC13_SetHigh()          (_LATC13 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC13 GPIO Pin which has a custom name of IO_RC13 to Low
 * @pre      The RC13 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC13_SetLow()           (_LATC13 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RC13 GPIO Pin which has a custom name of IO_RC13
 * @pre      The RC13 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC13_Toggle()           (_LATC13 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RC13 GPIO Pin which has a custom name of IO_RC13
 * @param    none
 * @return   none  
 */
#define IO_RC13_GetValue()         _RC13

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC13 GPIO Pin which has a custom name of IO_RC13 as Input
 * @param    none
 * @return   none  
 */
#define IO_RC13_SetDigitalInput()  (_TRISC13 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC13 GPIO Pin which has a custom name of IO_RC13 as Output
 * @param    none
 * @return   none  
 */
#define IO_RC13_SetDigitalOutput() (_TRISC13 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);



#endif
