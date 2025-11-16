/**
 * INTERRUPT Generated Driver Source File 
 * 
 * @file      interrupt.c
 *            
 * @ingroup   interruptdriver
 *            
 * @brief     This is the generated driver source file for INTERRUPT driver
 *            
 * @skipline @version   Firmware Driver Version 1.1.2
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

// Section: Includes
#include <xc.h>
#include "../interrupt.h"

// Section: Driver Interface Function Definitions

void INTERRUPT_Initialize(void)
{
    // DMT: Dead Man Timer
    // Priority: 1
    IPC11bits.DMTIP = 1;
    
    // PEVTE: PWM EVENT E
    // Priority: 1
    IPC43bits.PEVTEIP = 1;
    
    // PEVTF: PWM EVENT F
    // Priority: 1
    IPC43bits.PEVTFIP = 1;
    
    // PWM1: PWM Generator 1
    // Priority: 1
    IPC16bits.PWM1IP = 1;
    
    // PWM2: PWM Generator 2
    // Priority: 1
    IPC17bits.PWM2IP = 1;
    
    // PWM3: PWM Generator 3
    // Priority: 1
    IPC17bits.PWM3IP = 1;
    
    // PEVTA: PWM EVENT A
    // Priority: 1
    IPC42bits.PEVTAIP = 1;
    
    // PEVTB: PWM EVENT B
    // Priority: 1
    IPC42bits.PEVTBIP = 1;
    
    // PEVTC: PWM EVENT C
    // Priority: 1
    IPC42bits.PEVTCIP = 1;
    
    // PEVTD: PWM EVENT D
    // Priority: 1
    IPC43bits.PEVTDIP = 1;
    
    // T1: Timer 1
    // Priority: 1
    IPC0bits.T1IP = 1;
    
}

void INTERRUPT_Deinitialize(void)
{
    //POR default value of priority
    IPC11bits.DMTIP = 4;
    IPC43bits.PEVTEIP = 4;
    IPC43bits.PEVTFIP = 4;
    IPC16bits.PWM1IP = 4;
    IPC17bits.PWM2IP = 4;
    IPC17bits.PWM3IP = 4;
    IPC42bits.PEVTAIP = 4;
    IPC42bits.PEVTBIP = 4;
    IPC42bits.PEVTCIP = 4;
    IPC43bits.PEVTDIP = 4;
    IPC0bits.T1IP = 4;
}
