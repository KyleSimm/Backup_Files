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


#define FCY 8000000UL

#include <xc.h>
#include <stdio.h>
#include <string.h>
#include <libpic30.h>

#include "mcc_generated_files/system/system.h"

#include "spi_client.h"         // SPI1 slave
#include "spi_test.h"           // SPI2 master
#include "vfd_Control_Loop.h"
#include "system_mode.h"
#include "timing.h"

/******************************************************************************
 * SYSTEM MODE STATE
 ******************************************************************************/
SystemMode currentMode = MODE_INIT;

/******************************************************************************
 * SPI2 MASTER TEST STATE MACHINE
 ******************************************************************************/
typedef enum {
    MASTER_STATE_SEND_ON = 0,
    MASTER_STATE_WAIT_AFTER_ON,
    MASTER_STATE_SEND_10HZ,
    MASTER_STATE_WAIT_AFTER_10HZ,
    MASTER_STATE_SEND_20HZ,
    MASTER_STATE_WAIT_AFTER_20HZ,
    MASTER_STATE_SEND_OFF,
    MASTER_STATE_WAIT_AFTER_OFF
} MasterState_t;

static MasterState_t masterState = MASTER_STATE_SEND_ON;
static uint32_t masterStateTimestamp = 0;

/* debug tracking */
static uint8_t lastMasterModeSent = 0xFF;
static float   lastMasterFreqSent = -1.f;

/* delays */
#define MASTER_DELAY_AFTER_ON_MS     500
#define MASTER_DELAY_AFTER_10HZ_MS   500
#define MASTER_DELAY_AFTER_20HZ_MS   500
#define MASTER_DELAY_AFTER_OFF_MS    500

static void masterTick(void);

/******************************************************************************
 * MAIN
 ******************************************************************************/
int main(void)
{
    SYSTEM_Initialize();

    spi_init();                // SPI1 slave init
    //spi_master2_init();        // SPI2 master init
    sensor_init();
    printf("\r\n=== SYSTEM BOOT COMPLETE ===\r\n");

    currentMode = MODE_INIT;
    //masterState = MASTER_STATE_SEND_ON;
    //masterStateTimestamp = millis();
    
    //PWM_Initialize();
    //vfd_Init();
    
    while (1)
    {
        printf("Test");
        /**********************
         * NORMAL OPERATION
         **********************/
        switch (currentMode)
        {
            case MODE_INIT:
                printf("[SYS] MODE_INIT: Initializing PWM + VFD\r\n");

                PWM_Initialize();
                vfd_Init();

                currentMode = MODE_ON;
                printf("[SYS] Entering MODE_ON\r\n");
                break;

            case MODE_ON:
                printf("Mode On Cycle \r\n");
                /* --- SPI1 SLAVE RX --- */
                spi_checkChannel(); // prints when receiving a command

                /* --- SEND SENSOR TELEMETRY --- */
//                printf("[SLAVE TX] Sending telemetry packet\r\n");
//                spi_sendChannel();

                break;

            case MODE_OFF:
                printf("[SYS] MODE_OFF ? Shutting down PWM\r\n");

                PWM_Deinitialize();
                vfd_setDutyCycle(0);
                currentMode = MODE_IDLE;

                printf("[SYS] Entering MODE_IDLE\r\n");
                break;

            case MODE_IDLE:
                printf("Idle Mode \r\n");
                spi_checkChannel(); // still listens for "ON" command
                break;

            case MODE_REVERSE:
                printf("[SYS] MODE_REVERSE: forcing safe LOW + reversing\r\n");

                vfd_setDutyCycle(0);

                PG1IOCONLbits.OVRENH = 1; PG1IOCONLbits.OVRENL = 1;
                PG2IOCONLbits.OVRENH = 1; PG2IOCONLbits.OVRENL = 1;
                PG3IOCONLbits.OVRENH = 1; PG3IOCONLbits.OVRENL = 1;

                PG1IOCONLbits.OVRDAT = 0;
                PG2IOCONLbits.OVRDAT = 0;
                PG3IOCONLbits.OVRDAT = 0;

                __delay_ms(3);

                vfd_SetDirection(-1);

                PG1IOCONLbits.OVRENH = 0; PG1IOCONLbits.OVRENL = 0;
                PG2IOCONLbits.OVRENH = 0; PG2IOCONLbits.OVRENL = 0;
                PG3IOCONLbits.OVRENH = 0; PG3IOCONLbits.OVRENL = 0;

                currentMode = MODE_ON;
                break;

            default:
                currentMode = MODE_IDLE;
                break;
        }

        /**********************
         * SPI2 MASTER TEST
         **********************/
        //masterTick();

        __delay_ms(40);  // lightweight cooperative delay
    }

    return 0;
}

/******************************************************************************
 * SPI2 MASTER TEST STATE MACHINE
 ******************************************************************************/
static void masterTick(void)
{
    uint32_t now = millis();

    switch (masterState)
    {
        case MASTER_STATE_SEND_ON:
            spi_master2_sendMode(1);
            printf("[MASTER TX] Sending CMD: MODE = ON\r\n");
            lastMasterModeSent = 1;

            masterStateTimestamp = now;
            masterState = MASTER_STATE_WAIT_AFTER_ON;
            break;

        case MASTER_STATE_WAIT_AFTER_ON:
            if (now - masterStateTimestamp >= MASTER_DELAY_AFTER_ON_MS)
                masterState = MASTER_STATE_SEND_10HZ;
            break;

        case MASTER_STATE_SEND_10HZ:
            spi_master2_sendFrequency(10.f);
            printf("[MASTER TX] Sending CMD: FREQ = 10 Hz\r\n");
            lastMasterFreqSent = 10.f;

            masterStateTimestamp = now;
            masterState = MASTER_STATE_WAIT_AFTER_10HZ;
            break;

        case MASTER_STATE_WAIT_AFTER_10HZ:
            if (now - masterStateTimestamp >= MASTER_DELAY_AFTER_10HZ_MS)
                masterState = MASTER_STATE_SEND_20HZ;
            break;

        case MASTER_STATE_SEND_20HZ:
            spi_master2_sendFrequency(20.f);
            printf("[MASTER TX] Sending CMD: FREQ = 20 Hz\r\n");
            lastMasterFreqSent = 20.f;

            masterStateTimestamp = now;
            masterState = MASTER_STATE_WAIT_AFTER_20HZ;
            break;

        case MASTER_STATE_WAIT_AFTER_20HZ:
            if (now - masterStateTimestamp >= MASTER_DELAY_AFTER_20HZ_MS)
                masterState = MASTER_STATE_SEND_OFF;
            break;

        case MASTER_STATE_SEND_OFF:
            spi_master2_sendMode(0);
            printf("[MASTER TX] Sending CMD: MODE = OFF\r\n");
            lastMasterModeSent = 0;

            masterStateTimestamp = now;
            masterState = MASTER_STATE_WAIT_AFTER_OFF;
            break;

        case MASTER_STATE_WAIT_AFTER_OFF:
            if (now - masterStateTimestamp >= MASTER_DELAY_AFTER_OFF_MS)
                masterState = MASTER_STATE_SEND_ON;   // restart test cycle
            break;

        default:
            masterState = MASTER_STATE_SEND_ON;
            break;
    }
}
