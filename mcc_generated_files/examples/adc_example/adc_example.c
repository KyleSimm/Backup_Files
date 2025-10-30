/**
 * ADC Data Streamer - Polled Example Driver File
 * 
 * @file adc_example.c
 * 
 * @addtogroup adc_example
 * 
 * @brief This is the generated example implementation for ADC Data Streamer in Polled mode.
 *
 * @version ADC Example Driver Version 1.0.0
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

/* 2. ADC Data Streamer -> Polled implementation. Copy this code to your project source, e.g., to main.c  */
/* ------------------------------------------------------------------
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/data_streamer/data_streamer.h"
#include "mcc_generated_files/adc/{adc_header}.h" // TODO: Replace {adc_header} with the corresponding ADC header file for your project (ex: adc1.h)
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/timer/delay.h"

int main(void)
{
    const struct ADC_INTERFACE *adc = &ADCx; // TODO: Replace with the ADC instance in your project

    SYSTEM_Initialize();    
    DataStreamer.adcResult = 0;
    DataStreamer.adcSampleCount = 0;

    while(1)
    {           
        DataStreamer.adcResult = adc->ConversionResultGet(Channel_ANx); // TODO: Replace with the ADC Channel you selected in the Pin Grid View   
        DataStreamer.adcSampleCount++;
        IO_LED_Toggle();
        IO_Debug_Toggle();
        adc->SoftwareTriggerEnable();

        WriteFrame();
        DELAY_milliseconds(100);  
    }
}
------------------------------------------------------------------ */

/**
 End of File
*/