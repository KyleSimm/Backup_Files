/*
� [2025] Microchip Technology Inc. and its subsidiaries.

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
#include "mcc_generated_files/system/system.h"


/*
    Main application
*/

/* PIN MAPPING FOR dsPIC33CK1024MP710 && dsPIC33CK256MP508
 * ---|-------------|------------------|------------------|-----------------------------------------*
 * ---|  Pin Number |Pin Number: 256   |   Pin Type       |---Purpose------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     91      |        40        | SPI Input CLK    |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     90      |        46        | SPI Input DSI1   |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     89      |        47        | SPI Output SDO1  |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     86      |        66        | SPI Input SS1    |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     43      |        34        | Clock Out        |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     42      |        35        | Clock IN         |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     17      |        15        | ADC              |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     36      |        33        | ADC              |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     37      |        41        | ADC-RB2          |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     41      |        43        | ADC-RB3          |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     38      |        28        | ADC              |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     50      |        29        | ADC              |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     1       |        1         | PWM1H-RB14       |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     3       |        3         | PWM1L-RB15       |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     97      |        78        | PWM2H-RB12       |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     100     |        80        | PWM2L-RB13       |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     92      |        75        | PWM3H-RB10       |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     93      |        76        | PWM3L-RB11       |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     77      |        61        | PGCx Input       |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     75      |        60        | PGDx Input       |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---|     51      |        5         | GPIO             |----------------------------------------*
 * ---|------------ |------------------|------------------|----------------------------------------*
 * ---|     20      |        6         | GPIO             |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---| 64,39,88,14 |  31,12,51,71     | VDD              |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 * ---| 13,87,40,63 |  11,32,50,70     | VSS              |----------------------------------------*
 * ---|-------------|------------------|------------------|----------------------------------------*
 */

/* PWM Current Settings
 *    Master Input Frequency: 8 MHz
 *    Requested Frequency 15 kHz
 *    Operation Mode: Center-Aligned CHANGE
 *    PWM Output Mode: Complementary 
 *    Calculated Period: 66.671 us
 *    Calculated Frequency: 16 KHz
 *    Dead Time Low: 200ns
 *    Dead Time High: 200ns
 *    Data Update Settings: Immediate
 *    
 */

/* Notes
 Serial Port for printf: COM11
 */
#define FCY 8000000UL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>
#include <libpic30.h>
//Header/Custom Files
#include "vfd_Control_Loop.h"
#include "spi_client.h"
#include "system_mode.h"


SystemMode currentMode = MODE_INIT;  // start in idle mode


int main(void)
{
    SYSTEM_Initialize();
    //PWM_Deinitialize();
    spi_init();
            
    currentMode = MODE_INIT;

    /* Loop Error?
     * MODEON: No Issues
     * MODEINIT: Issue inside
     
     */
    printf("Entering While Loop \r\n");
    while(1)
    {
        printf("Current State: %s\n", modeToString(currentMode));
        
        switch(currentMode){
            printf("Inside CurrentMode \r\n");
            case MODE_INIT:
            
                //Initializes PWM Channels
                PWM_Initialize();
                //printf("Testing if PWM Initialized \r\n");
                vfd_Init();
                //printf("Testing if vfd Initialized \r\n");
                currentMode = MODE_ON;
                printf("Switching Mode to On \r\n\n");

                break;
                
            case MODE_OFF:
                //Disable PWM Channels
                PWM_Deinitialize();
                //Set Duty Cycle to 0%
                vfd_setDutyCycle(0);
                //Change Mode
                currentMode = MODE_IDLE;
                printf("Turning System Off, PWM output stopped \r\n");
                
                break;
                
            case MODE_ON:
                //Check for OFF Signal
                spi_checkChannel();
                //Check for new Frequency
                //Read Sensor Data
                spi_sendChannel();
                //Send Sensor Data over SPI
                
                printf("Inside MODE_ON!\r\n \r\n");

                break;
                
            case MODE_IDLE:
                //Check SPI Connection for "ON" signal;
                spi_checkChannel();  
                printf("Code is IDle \r\n");
                break;
            case MODE_REVERSE:
                printf("In Reverse Mode \r\n");
                //Set PWM Duty Cycle to 0 percent
                vfd_setDutyCycle(0);
                //Set PWM to LOW:
                // Force all PWM outputs LOW
                PG1IOCONLbits.OVRENH = 1;
                PG1IOCONLbits.OVRENL = 1;
                PG1IOCONLbits.OVRDAT = 0b00;

                PG2IOCONLbits.OVRENH = 1;
                PG2IOCONLbits.OVRENL = 1;
                PG2IOCONLbits.OVRDAT = 0b00;

                PG3IOCONLbits.OVRENH = 1;
                PG3IOCONLbits.OVRENL = 1;
                PG3IOCONLbits.OVRDAT = 0b00;
     
                //Wait 2 ms.
                 __delay_ms(3);
                //Adjust Values
                vfd_SetDirection(-1);
                
                // Release overrides
                PG1IOCONLbits.OVRENH = 0;
                PG1IOCONLbits.OVRENL = 0;

                PG2IOCONLbits.OVRENH = 0;
                PG2IOCONLbits.OVRENL = 0;

                PG3IOCONLbits.OVRENH = 0;
                PG3IOCONLbits.OVRENL = 0;   
                
                //Set Mode back to ON
                currentMode = MODE_ON;
                break;
        }
                 
         __delay_ms(300); //So Testing printf is possible to read.
        //Testing Code
    }
  
    
    

    return 0;
}
