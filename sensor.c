

//Tempature Sensor Calculations



//Infeon Chip

//Tempature Monitor using NTC. 
// R25 around 6.8 k Ohms?
// V_ADC = V_REF * RNTC/(TNTC+Rpullup))
//R_pullup = ? On Schematic?


#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/adc/adc1.h"
#include "mcc_generated_files/system/pins.h"


/*
 enum ADC_CHANNEL
{
    ADC_temp,    <Channel Name:AN7   Assigned to:Shared Channel
    Channel_AN8,    <Channel Name:AN8   Assigned to:Shared Channel
    Channel_AN12,    <Channel Name:AN12   Assigned to:Shared Channel
    Channel_AN13,    <Channel Name:AN13   Assigned to:Shared Channel
    Channel_AN14,    <Channel Name:AN14   Assigned to:Shared Channel
    Channel_AN15,    <Channel Name:AN15   Assigned to:Shared Channel
    MAX_CHANNELS = 6,    < MAX_CHANNELS will be removed in future MCC releases. Use ADC_MAX_CHANNELS instead 
    ADC_MAX_CHANNELS = 6    < Maximum number of channels configured by user in MCC Melody User Interface 
*/
/*
volatile uint16_t dataAN0;
volatile uint16_t dataAN1;
volatile uint16_t dataAN6;


void Sensor_Main(){

    const struct ADC_INTERFACE *adc = &ADC1; // TODO: Replace with the ADC instance in your project
  

    while(1)
    {           
        
        
    }
}

static void writeValue((uint8_t *) &count32, 4){
    
}
*/

/*
 
static void variableWrite_SendValue(uint8_t* byte_ptr, uint8_t num_bytes)
 {
      for(uint8_t i = 0; i < num_bytes; i++)
      {
         UART1_Write(byte_ptr[i]);
      }
}

void variableWrite_SendFrame(uint8_t count, uint16_t count16, uint32_t count32, float count_f)
{
   UART1_Write(DATA_STREAMER_START_BYTE);  

   UART1_Write(count);                                 // uint8_t

   variableWrite_SendValue((uint8_t *) &count16, 2);         // uint16_t

   variableWrite_SendValue((uint8_t *) &count32, 4);         // uint32_t

   variableWrite_SendValue((uint8_t *) &count_f, 4);         // float

   UART1_Write(DATA_STREAMER_END_BYTE);  

   while(!UART1_IsTxDone());
}
 */