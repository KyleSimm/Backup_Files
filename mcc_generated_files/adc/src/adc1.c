/**
 * ADC1 Generated Driver Source File
 * 
 * @file      adc1.c
 *            
 * @ingroup   adcdriver
 *            
 * @brief     This is the generated driver source file for ADC1 driver
 *            
 * @skipline @version   Firmware Driver Version 1.4.4
 *
 * @skipline @version   PLIB Version 2.4.4
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

// Section: Included Files
#include <stddef.h>
#include "../adc1.h"

// Section: Driver Interface Function Definitions
void ADC1_Initialize (void)
{
    // ADSIDL disabled; ADON enabled; 
    ADCON1L = (uint16_t)(0x8000U & 0x7FFFU); //Disabling ADON bit
    // SHRRES 12-bit resolution; FORM Integer; 
    ADCON1H = 0x60U;
    // SHRADCS 2; SHREISEL Early interrupt is generated 1 TADCORE clock prior to data being ready; PTGEN disabled; EIEN disabled; REFERCIE disabled; REFCIE disabled; 
    ADCON2L = 0x0U;
    // SHRSAMC 0; 
    ADCON2H = 0x0U;
    // CNVCHSEL AN0; SWCTRG disabled; SWLCTRG disabled; SHRSAMP disabled; SUSPCIE disabled; SUSPEND disabled; REFSEL disabled; 
    ADCON3L = 0x0U;
    // C0EN disabled; C1EN disabled; SHREN disabled; CLKDIV 1; CLKSEL FOSC/2; 
    ADCON3H = (uint16_t)(0x0U & 0xFF00U); //Disabling C0EN, C1EN, C2EN, C3EN and SHREN bits
    // SAMC0EN disabled; SAMC1EN disabled; 
    ADCON4L = 0x0U;
    // C0CHS AN0; C1CHS AN1; 
    ADCON4H = 0x0U;
    // SIGN0 disabled; DIFF0 disabled; SIGN1 disabled; DIFF1 disabled; SIGN2 disabled; DIFF2 disabled; SIGN3 disabled; DIFF3 disabled; SIGN4 disabled; DIFF4 disabled; SIGN5 disabled; DIFF5 disabled; SIGN6 disabled; DIFF6 disabled; SIGN7 disabled; DIFF7 disabled; 
    ADMOD0L = 0x0U;
    // SIGN8 disabled; DIFF8 disabled; SIGN9 disabled; DIFF9 disabled; SIGN10 disabled; DIFF10 disabled; SIGN11 disabled; DIFF11 disabled; SIGN12 disabled; DIFF12 disabled; SIGN13 disabled; DIFF13 disabled; SIGN14 disabled; DIFF14 disabled; SIGN15 disabled; DIFF15 disabled; 
    ADMOD0H = 0x0U;
    // SIGN16 disabled; DIFF16 disabled; SIGN17 disabled; DIFF17 disabled; SIGN18 disabled; DIFF18 disabled; SIGN19 disabled; DIFF19 disabled; SIGN20 disabled; DIFF20 disabled; SIGN21 disabled; DIFF21 disabled; SIGN22 disabled; DIFF22 disabled; SIGN23 disabled; DIFF23 disabled; 
    ADMOD1L = 0x0U;
    // SIGN24 disabled; DIFF24 disabled; SIGN25 disabled; DIFF25 disabled; 
    ADMOD1H = 0x0U;
    // IE0 disabled; IE1 disabled; IE2 disabled; IE3 disabled; IE4 disabled; IE5 disabled; IE6 disabled; IE7 disabled; IE8 disabled; IE9 disabled; IE10 disabled; IE11 disabled; IE12 disabled; IE13 disabled; IE14 disabled; IE15 disabled; 
    ADIEL = 0x0U;
    // IE16 disabled; IE17 disabled; IE18 disabled; IE19 disabled; IE20 disabled; IE21 disabled; IE22 disabled; IE23 disabled; IE24 disabled; IE25 disabled; 
    ADIEH = 0x0U;
    // 
    ADSTATL = 0x0U;
    // 
    ADSTATH = 0x0U;
    // CMPEN0 disabled; CMPEN1 disabled; CMPEN2 disabled; CMPEN3 disabled; CMPEN4 disabled; CMPEN5 disabled; CMPEN6 disabled; CMPEN7 disabled; CMPEN8 disabled; CMPEN9 disabled; CMPEN10 disabled; CMPEN11 disabled; CMPEN12 disabled; CMPEN13 disabled; CMPEN14 disabled; CMPEN15 disabled; 
    ADCMP0ENL = 0x0U;
    // CMPEN0 disabled; CMPEN1 disabled; CMPEN2 disabled; CMPEN3 disabled; CMPEN4 disabled; CMPEN5 disabled; CMPEN6 disabled; CMPEN7 disabled; CMPEN8 disabled; CMPEN9 disabled; CMPEN10 disabled; CMPEN11 disabled; CMPEN12 disabled; CMPEN13 disabled; CMPEN14 disabled; CMPEN15 disabled; 
    ADCMP1ENL = 0x0U;
    // CMPEN0 disabled; CMPEN1 disabled; CMPEN2 disabled; CMPEN3 disabled; CMPEN4 disabled; CMPEN5 disabled; CMPEN6 disabled; CMPEN7 disabled; CMPEN8 disabled; CMPEN9 disabled; CMPEN10 disabled; CMPEN11 disabled; CMPEN12 disabled; CMPEN13 disabled; CMPEN14 disabled; CMPEN15 disabled; 
    ADCMP2ENL = 0x0U;
    // CMPEN0 disabled; CMPEN1 disabled; CMPEN2 disabled; CMPEN3 disabled; CMPEN4 disabled; CMPEN5 disabled; CMPEN6 disabled; CMPEN7 disabled; CMPEN8 disabled; CMPEN9 disabled; CMPEN10 disabled; CMPEN11 disabled; CMPEN12 disabled; CMPEN13 disabled; CMPEN14 disabled; CMPEN15 disabled; 
    ADCMP3ENL = 0x0U;
    // CMPEN16 disabled; CMPEN17 disabled; CMPEN18 disabled; CMPEN19 disabled; CMPEN20 disabled; CMPEN21 disabled; CMPEN22 disabled; CMPEN23 disabled; CMPEN24 disabled; CMPEN25 disabled; 
    ADCMP0ENH = 0x0U;
    // CMPEN16 disabled; CMPEN17 disabled; CMPEN18 disabled; CMPEN19 disabled; CMPEN20 disabled; CMPEN21 disabled; CMPEN22 disabled; CMPEN23 disabled; CMPEN24 disabled; CMPEN25 disabled; 
    ADCMP1ENH = 0x0U;
    // CMPEN16 disabled; CMPEN17 disabled; CMPEN18 disabled; CMPEN19 disabled; CMPEN20 disabled; CMPEN21 disabled; CMPEN22 disabled; CMPEN23 disabled; CMPEN24 disabled; CMPEN25 disabled; 
    ADCMP2ENH = 0x0U;
    // CMPEN16 disabled; CMPEN17 disabled; CMPEN18 disabled; CMPEN19 disabled; CMPEN20 disabled; CMPEN21 disabled; CMPEN22 disabled; CMPEN23 disabled; CMPEN24 disabled; CMPEN25 disabled; 
    ADCMP3ENH = 0x0U;
    // CMPLO 0x0; 
    ADCMP0LO = 0x0U;
    // CMPLO 0x0; 
    ADCMP1LO = 0x0U;
    // CMPLO 0x0; 
    ADCMP2LO = 0x0U;
    // CMPLO 0x0; 
    ADCMP3LO = 0x0U;
    // CMPHI 0x0; 
    ADCMP0HI = 0x0U;
    // CMPHI 0x0; 
    ADCMP1HI = 0x0U;
    // CMPHI 0x0; 
    ADCMP2HI = 0x0U;
    // CMPHI 0x0; 
    ADCMP3HI = 0x0U;
    // 
    ADFL0DAT = 0x0U;
    // 
    ADFL1DAT = 0x0U;
    // 
    ADFL2DAT = 0x0U;
    // 
    ADFL3DAT = 0x0U;
    // FLCHSEL AN0; IE disabled; OVRSAM 4x; MODE Oversampling Mode; FLEN disabled; 
    ADFL0CON = 0x400U;
    // FLCHSEL AN0; IE disabled; OVRSAM 4x; MODE Oversampling Mode; FLEN disabled; 
    ADFL1CON = 0x400U;
    // FLCHSEL AN0; IE disabled; OVRSAM 4x; MODE Oversampling Mode; FLEN disabled; 
    ADFL2CON = 0x400U;
    // FLCHSEL AN0; IE disabled; OVRSAM 4x; MODE Oversampling Mode; FLEN disabled; 
    ADFL3CON = 0x400U;
    // LOLO disabled; LOHI disabled; HILO disabled; HIHI disabled; BTWN disabled; IE disabled; CMPEN disabled; 
    ADCMP0CON = 0x0U;
    // LOLO disabled; LOHI disabled; HILO disabled; HIHI disabled; BTWN disabled; IE disabled; CMPEN disabled; 
    ADCMP1CON = 0x0U;
    // LOLO disabled; LOHI disabled; HILO disabled; HIHI disabled; BTWN disabled; IE disabled; CMPEN disabled; 
    ADCMP2CON = 0x0U;
    // LOLO disabled; LOHI disabled; HILO disabled; HIHI disabled; BTWN disabled; IE disabled; CMPEN disabled; 
    ADCMP3CON = 0x0U;
    // LVLEN0 disabled; LVLEN1 disabled; LVLEN2 disabled; LVLEN3 disabled; LVLEN4 disabled; LVLEN5 disabled; LVLEN6 disabled; LVLEN7 disabled; LVLEN8 disabled; LVLEN9 disabled; LVLEN10 disabled; LVLEN11 disabled; LVLEN12 disabled; LVLEN13 disabled; LVLEN14 disabled; LVLEN15 disabled; 
    ADLVLTRGL = 0x0U;
    // LVLEN16 disabled; LVLEN17 disabled; LVLEN18 disabled; LVLEN19 disabled; LVLEN20 disabled; LVLEN21 disabled; LVLEN22 disabled; LVLEN23 disabled; LVLEN24 disabled; LVLEN25 disabled; 
    ADLVLTRGH = 0x0U;
    // SAMC 0x0; 
    ADCORE0L = 0x0U;
    // SAMC 0x0; 
    ADCORE1L = 0x0U;
    // ADCS 2; RES 12-bit resolution; EISEL Early interrupt is generated 1 TADCORE clock prior to data being ready; 
    ADCORE0H = 0x300U;
    // ADCS 2; RES 12-bit resolution; EISEL Early interrupt is generated 1 TADCORE clock prior to data being ready; 
    ADCORE1H = 0x300U;
    // EIEN0 disabled; EIEN1 disabled; EIEN2 disabled; EIEN3 disabled; EIEN4 disabled; EIEN5 disabled; EIEN6 disabled; EIEN7 disabled; EIEN8 disabled; EIEN9 disabled; EIEN10 disabled; EIEN11 disabled; EIEN12 disabled; EIEN13 disabled; EIEN14 disabled; EIEN15 disabled; 
    ADEIEL = 0x0U;
    // EIEN16 disabled; EIEN17 disabled; EIEN18 disabled; EIEN19 disabled; EIEN20 disabled; EIEN21 disabled; EIEN22 disabled; EIEN23 disabled; EIEN24 disabled; EIEN25 disabled; 
    ADEIEH = 0x0U;
    // EISTAT0 disabled; EISTAT1 disabled; EISTAT2 disabled; EISTAT3 disabled; EISTAT4 disabled; EISTAT5 disabled; EISTAT6 disabled; EISTAT7 disabled; EISTAT8 disabled; EISTAT9 disabled; EISTAT10 disabled; EISTAT11 disabled; EISTAT12 disabled; EISTAT13 disabled; EISTAT14 disabled; EISTAT15 disabled; 
    ADEISTATL = 0x0U;
    // EISTAT16 disabled; EISTAT17 disabled; EISTAT18 disabled; EISTAT19 disabled; EISTAT20 disabled; EISTAT21 disabled; EISTAT22 disabled; EISTAT23 disabled; EISTAT24 disabled; EISTAT25 disabled; 
    ADEISTATH = 0x0U;
    // C0CIE disabled; C1CIE disabled; SHRCIE disabled; WARMTIME 16 Source Clock Periods; 
    ADCON5H = (uint16_t)(0x400U & 0xF0FFU); //Disabling WARMTIME bit
    // 
    ADCBUF0 = 0x0U;
    // 
    ADCBUF1 = 0x0U;
    // 
    ADCBUF2 = 0x0U;
    // 
    ADCBUF3 = 0x0U;
    // 
    ADCBUF4 = 0x0U;
    // 
    ADCBUF5 = 0x0U;
    // 
    ADCBUF6 = 0x0U;
    // 
    ADCBUF7 = 0x0U;
    // 
    ADCBUF8 = 0x0U;
    // 
    ADCBUF9 = 0x0U;
    // 
    ADCBUF10 = 0x0U;
    // 
    ADCBUF11 = 0x0U;
    // 
    ADCBUF12 = 0x0U;
    // 
    ADCBUF13 = 0x0U;
    // 
    ADCBUF14 = 0x0U;
    // 
    ADCBUF15 = 0x0U;
    // 
    ADCBUF16 = 0x0U;
    // 
    ADCBUF17 = 0x0U;
    // 
    ADCBUF18 = 0x0U;
    // 
    ADCBUF19 = 0x0U;
    // 
    ADCBUF20 = 0x0U;
    // 
    ADCBUF21 = 0x0U;
    // 
    ADCBUF22 = 0x0U;
    // 
    ADCBUF23 = 0x0U;
    // 
    ADCBUF24 = 0x0U;
    // 
    ADCBUF25 = 0x0U;
    

    // Setting WARMTIME bit
    ADCON5Hbits.WARMTIME = 0xF;
    // Enabling ADC Module
    ADCON1Lbits.ADON = 0x1;

    //TRGSRC0 None; TRGSRC1 None; 
    ADTRIG0L = 0x0U;
    //TRGSRC2 None; TRGSRC3 None; 
    ADTRIG0H = 0x0U;
    //TRGSRC4 None; TRGSRC5 None; 
    ADTRIG1L = 0x0U;
    //TRGSRC6 None; TRGSRC7 None; 
    ADTRIG1H = 0x0U;
    //TRGSRC8 None; TRGSRC9 None; 
    ADTRIG2L = 0x0U;
    //TRGSRC10 None; TRGSRC11 None; 
    ADTRIG2H = 0x0U;
    //TRGSRC12 None; TRGSRC13 None; 
    ADTRIG3L = 0x0U;
    //TRGSRC14 None; TRGSRC15 None; 
    ADTRIG3H = 0x0U;
    //TRGSRC16 None; TRGSRC17 None; 
    ADTRIG4L = 0x0U;
    //TRGSRC18 None; TRGSRC19 None; 
    ADTRIG4H = 0x0U;
    //TRGSRC20 None; TRGSRC21 None; 
    ADTRIG5L = 0x0U;
    //TRGSRC22 None; TRGSRC23 None; 
    ADTRIG5H = 0x0U;
    //TRGSRC24 None; TRGSRC25 None; 
    ADTRIG6L = 0x0U;
}

void ADC1_Deinitialize (void)
{
    ADCON1Lbits.ADON = 0;
    
    
    ADCON1L = 0x0U;
    ADCON1H = 0x60U;
    ADCON2L = 0x0U;
    ADCON2H = 0x0U;
    ADCON3L = 0x0U;
    ADCON3H = 0x0U;
    ADCON4L = 0x0U;
    ADCON4H = 0x0U;
    ADMOD0L = 0x0U;
    ADMOD0H = 0x0U;
    ADMOD1L = 0x0U;
    ADMOD1H = 0x0U;
    ADIEL = 0x0U;
    ADIEH = 0x0U;
    ADSTATL = 0x0U;
    ADSTATH = 0x0U;
    ADCMP0ENL = 0x0U;
    ADCMP1ENL = 0x0U;
    ADCMP2ENL = 0x0U;
    ADCMP3ENL = 0x0U;
    ADCMP0ENH = 0x0U;
    ADCMP1ENH = 0x0U;
    ADCMP2ENH = 0x0U;
    ADCMP3ENH = 0x0U;
    ADCMP0LO = 0x0U;
    ADCMP1LO = 0x0U;
    ADCMP2LO = 0x0U;
    ADCMP3LO = 0x0U;
    ADCMP0HI = 0x0U;
    ADCMP1HI = 0x0U;
    ADCMP2HI = 0x0U;
    ADCMP3HI = 0x0U;
    ADFL0DAT = 0x0U;
    ADFL1DAT = 0x0U;
    ADFL2DAT = 0x0U;
    ADFL3DAT = 0x0U;
    ADFL0CON = 0x0U;
    ADFL1CON = 0x0U;
    ADFL2CON = 0x0U;
    ADFL3CON = 0x0U;
    ADTRIG0L = 0x0U;
    ADTRIG0H = 0x0U;
    ADTRIG1L = 0x0U;
    ADTRIG1H = 0x0U;
    ADTRIG2L = 0x0U;
    ADTRIG2H = 0x0U;
    ADTRIG3L = 0x0U;
    ADTRIG3H = 0x0U;
    ADTRIG4L = 0x0U;
    ADTRIG4H = 0x0U;
    ADTRIG5L = 0x0U;
    ADTRIG5H = 0x0U;
    ADTRIG6L = 0x0U;
    ADCMP0CON = 0x0U;
    ADCMP1CON = 0x0U;
    ADCMP2CON = 0x0U;
    ADCMP3CON = 0x0U;
    ADLVLTRGL = 0x0U;
    ADLVLTRGH = 0x0U;
    ADCORE0L = 0x0U;
    ADCORE1L = 0x0U;
    ADCORE0H = 0x300U;
    ADCORE1H = 0x300U;
    ADEIEL = 0x0U;
    ADEIEH = 0x0U;
    ADEISTATL = 0x0U;
    ADEISTATH = 0x0U;
    ADCON5L = 0x0U;
    ADCON5H = 0x0U;
    ADCBUF0 = 0x0U;
    ADCBUF1 = 0x0U;
    ADCBUF2 = 0x0U;
    ADCBUF3 = 0x0U;
    ADCBUF4 = 0x0U;
    ADCBUF5 = 0x0U;
    ADCBUF6 = 0x0U;
    ADCBUF7 = 0x0U;
    ADCBUF8 = 0x0U;
    ADCBUF9 = 0x0U;
    ADCBUF10 = 0x0U;
    ADCBUF11 = 0x0U;
    ADCBUF12 = 0x0U;
    ADCBUF13 = 0x0U;
    ADCBUF14 = 0x0U;
    ADCBUF15 = 0x0U;
    ADCBUF16 = 0x0U;
    ADCBUF17 = 0x0U;
    ADCBUF18 = 0x0U;
    ADCBUF19 = 0x0U;
    ADCBUF20 = 0x0U;
    ADCBUF21 = 0x0U;
    ADCBUF22 = 0x0U;
    ADCBUF23 = 0x0U;
    ADCBUF24 = 0x0U;
    ADCBUF25 = 0x0U;
}
