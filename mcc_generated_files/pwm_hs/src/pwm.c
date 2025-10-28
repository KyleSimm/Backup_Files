/**
 * PWM Generated Driver Source File
 * 
 * @file      pwm.c
 * 
 * @ingroup   pwmhsdriver
 * 
 * @brief     This is the generated driver source file for PWM driver
 *
 * @skipline @version   Firmware Driver Version 1.1.6
 *
 * @skipline @version   PLIB Version 2.5.1
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


#include "../pwm.h"

// Section: File specific functions

static void (*PWM_GeneratorEOCEventHandler)(enum PWM_GENERATOR genNum) = NULL;


// Section: Driver Interface

const struct PWM_HS_INTERFACE PWM_HS = {
    .Initialize                     = &PWM_Initialize,
    .Deinitialize                   = &PWM_Deinitialize,
    .Disable                        = &PWM_Disable,
    .Enable                         = &PWM_Enable,
    .ModeSet                        = &PWM_ModeSet,
    .MasterPeriodSet                = &PWM_MasterPeriodSet,
    .MasterDutyCycleSet             = &PWM_MasterDutyCycleSet,
    .PeriodSet                      = &PWM_PeriodSet,
    .DutyCycleSet                   = &PWM_DutyCycleSet,
    .PhaseSelect                    = &PWM_PhaseSelect,
    .PhaseSet                       = &PWM_PhaseSet,
    .OverrideDataSet                = &PWM_OverrideDataSet,
    .OverrideDataHighSet            = &PWM_OverrideDataHighSet,
    .OverrideDataLowSet             = &PWM_OverrideDataLowSet,
    .OverrideDataGet                = &PWM_OverrideDataGet,
    .OverrideHighEnable             = &PWM_OverrideHighEnable,
    .OverrideLowEnable              = &PWM_OverrideLowEnable,
    .OverrideHighDisable            = &PWM_OverrideHighDisable,
    .OverrideLowDisable             = &PWM_OverrideLowDisable,
    .DeadTimeLowSet                 = &PWM_DeadTimeLowSet,
    .DeadTimeHighSet                = &PWM_DeadTimeHighSet,
    .DeadTimeSet                    = &PWM_DeadTimeSet,
    .TriggerCompareValueSet         = &PWM_TriggerCompareValueSet,
    .GeneratorInterruptEnable       = &PWM_GeneratorInterruptEnable,
    .GeneratorInterruptDisable      = &PWM_GeneratorInterruptDisable,
    .GeneratorEventStatusGet        = &PWM_GeneratorEventStatusGet,
    .GeneratorEventStatusClear      = &PWM_GeneratorEventStatusClear,

    .SpecialEventPrimaryCompareValueSet     = NULL,    
    .SpecialEventTriggerInterruptFlagClear  = NULL,
    .SpecialEventPrimaryInterruptEnable     = NULL,
    .SpecialEventPrimaryInterruptDisable    = NULL,
    .FaultModeLatchDisable                  = NULL,
    .FaultModeLatchEnable                   = NULL,
    .MasterPhaseSet                         = &PWM_MasterPhaseSet,
    .GeneratorDisable                       = &PWM_GeneratorDisable,
    .GeneratorEnable                        = &PWM_GeneratorEnable,
    .TriggerACompareValueSet                = &PWM_TriggerACompareValueSet,
    .TriggerBCompareValueSet                = &PWM_TriggerBCompareValueSet,
    .TriggerCCompareValueSet                = &PWM_TriggerCCompareValueSet,
    .SoftwareUpdateRequest                  = &PWM_SoftwareUpdateRequest,
    .SoftwareUpdatePending                  = &PWM_SoftwareUpdatePending,
    .FaultModeLatchClear                    = &PWM_FaultModeLatchClear,
    .Trigger1Enable                         = &PWM_Trigger1Enable,
    .Trigger1Disable                        = &PWM_Trigger1Disable,
    .Trigger2Enable                         = &PWM_Trigger2Enable,
    .Trigger2Disable                        = &PWM_Trigger2Disable,
    
    .GeneratorEOCEventCallbackRegister = &PWM_GeneratorEOCEventCallbackRegister,
    
    
    .GeneratorTasks         = NULL,
    .CommonEventTasks       = NULL,
};

// Section: PWM Module APIs

void PWM_Initialize (void)
{
    // MODSEL Center-Aligned; TRGCNT 1; CLKSEL Master clock; ON enabled; HREN disabled; 
    PG1CONL = 0xcU;
    // MODSEL Center-Aligned; TRGCNT 1; CLKSEL Master clock; ON enabled; HREN disabled; 
    PG2CONL = 0xcU;
    // MODSEL Center-Aligned; TRGCNT 1; CLKSEL Master clock; ON enabled; HREN disabled; 
    PG3CONL = 0xcU;
    // 
    PG1CAP = 0x0U;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive; 
    PG1CLPCIH = 0x0U;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC; 
    PG1CLPCIL = 0x0U;
    // MSTEN disabled; TRIGMOD Single trigger mode; SOCS Self-trigger; UPDMOD Immediate; MPHSEL disabled; MPERSEL disabled; MDCSEL disabled; 
    PG1CONH = 0x100U;
    // DC1 0; 
    PG1DC = 0x0U;
    // DCA1 0x0; 
    PG1DCA = 0x0U;
    // DTH1 2; 
    PG1DTH = 0x2U;
    // DTL1 2; 
    PG1DTL = 0x2U;
    // ADTR2EN1 disabled; IEVTSEL EOC; SIEN disabled; FFIEN disabled; ADTR1OFS None; CLIEN disabled; FLTIEN disabled; ADTR2EN2 disabled; ADTR2EN3 disabled; 
    PG1EVTH = 0x0U;
    // UPDTRG Duty Cycle; ADTR1PS 1:1; PGTRGSEL EOC event; ADTR1EN3 disabled; ADTR1EN1 disabled; ADTR1EN2 disabled; 
    PG1EVTL = 0x8U;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive; 
    PG1FFPCIH = 0x0U;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC; 
    PG1FFPCIL = 0x0U;
    // TQPS Not inverted; LATMOD disabled; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive; 
    PG1FPCIH = 0x0U;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC; 
    PG1FPCIL = 0x0U;
    // PENL enabled; DTCMPSEL PCI Sync Logic; PMOD Complementary; POLL Active-high; PENH enabled; CAPSRC Software; POLH Active-high; 
    PG1IOCONH = 0xCU;
    // FLTDAT 0; DBDAT 0x0; SWAP disabled; OVRENH disabled; OVRENL disabled; OSYNC User output overrides occur when specified by UPDMOD bits; CLMOD disabled; FFDAT 0x0; CLDAT 0x0; OVRDAT 0; 
    PG1IOCONL = 0x200U;
    // PWMPCI PWM1; PLR disabled; PLF disabled; PHR disabled; PHF disabled; 
    PG1LEBH = 0x0U;
    // LEB 0x0; 
    PG1LEBL = 0x0U;
    // PER1 249; 
    PG1PER = 0xF9U;
    // PHASE1 0; 
    PG1PHASE = 0x0U;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive; 
    PG1SPCIH = 0x0U;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC; 
    PG1SPCIL = 0x0U;
    // TRSET disabled; UPDREQ disabled; CLEVT disabled; TRCLR disabled; CAP disabled; SEVT disabled; FFEVT disabled; UPDATE disabled; FLTEVT disabled; 
    PG1STAT = 0x0U;
    // TRIGA1 0; 
    PG1TRIGA = 0x0U;
    // TRIGB1 0; 
    PG1TRIGB = 0x0U;
    // TRIGC1 0; 
    PG1TRIGC = 0x0U;
    // 
    PG2CAP = 0x0U;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive; 
    PG2CLPCIH = 0x0U;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC; 
    PG2CLPCIL = 0x0U;
    // MSTEN disabled; TRIGMOD Single trigger mode; SOCS Trigger output selected by PG1 or PG5; UPDMOD Immediate; MPHSEL disabled; MPERSEL disabled; MDCSEL disabled; 
    PG2CONH = 0x101U;
    // DC2 0; 
    PG2DC = 0x0U;
    // DCA2 0x0; 
    PG2DCA = 0x0U;
    // DTH2 2; 
    PG2DTH = 0x2U;
    // DTL2 2; 
    PG2DTL = 0x2U;
    // ADTR2EN1 disabled; IEVTSEL EOC; SIEN disabled; FFIEN disabled; ADTR1OFS None; CLIEN disabled; FLTIEN disabled; ADTR2EN2 disabled; ADTR2EN3 disabled; 
    PG2EVTH = 0x0U;
    // UPDTRG Duty Cycle; ADTR1PS 1:1; PGTRGSEL EOC event; ADTR1EN3 disabled; ADTR1EN1 disabled; ADTR1EN2 disabled; 
    PG2EVTL = 0x8U;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive; 
    PG2FFPCIH = 0x0U;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC; 
    PG2FFPCIL = 0x0U;
    // TQPS Not inverted; LATMOD disabled; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive; 
    PG2FPCIH = 0x0U;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC; 
    PG2FPCIL = 0x0U;
    // PENL enabled; DTCMPSEL PCI Sync Logic; PMOD Complementary; POLL Active-high; PENH enabled; CAPSRC Software; POLH Active-high; 
    PG2IOCONH = 0xCU;
    // FLTDAT 0; DBDAT 0x0; SWAP disabled; OVRENH disabled; OVRENL disabled; OSYNC User output overrides occur when specified by UPDMOD bits; CLMOD disabled; FFDAT 0x0; CLDAT 0x0; OVRDAT 0; 
    PG2IOCONL = 0x200U;
    // PWMPCI PWM1; PLR disabled; PLF disabled; PHR disabled; PHF disabled; 
    PG2LEBH = 0x0U;
    // LEB 0x0; 
    PG2LEBL = 0x0U;
    // PER2 249; 
    PG2PER = 0xF9U;
    // PHASE2 0; 
    PG2PHASE = 0x0U;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive; 
    PG2SPCIH = 0x0U;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC; 
    PG2SPCIL = 0x0U;
    // TRSET disabled; UPDREQ disabled; CLEVT disabled; TRCLR disabled; CAP disabled; SEVT disabled; FFEVT disabled; UPDATE disabled; FLTEVT disabled; 
    PG2STAT = 0x0U;
    // TRIGA2 0; 
    PG2TRIGA = 0x0U;
    // TRIGB2 0; 
    PG2TRIGB = 0x0U;
    // TRIGC2 0; 
    PG2TRIGC = 0x0U;
    // 
    PG3CAP = 0x0U;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive; 
    PG3CLPCIH = 0x0U;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC; 
    PG3CLPCIL = 0x0U;
    // MSTEN disabled; TRIGMOD Single trigger mode; SOCS Trigger output selected by PG1 or PG5; UPDMOD Immediate; MPHSEL disabled; MPERSEL disabled; MDCSEL disabled; 
    PG3CONH = 0x101U;
    // DC3 0; 
    PG3DC = 0x0U;
    // DCA3 0x0; 
    PG3DCA = 0x0U;
    // DTH3 2; 
    PG3DTH = 0x2U;
    // DTL3 2; 
    PG3DTL = 0x2U;
    // ADTR2EN1 disabled; IEVTSEL EOC; SIEN disabled; FFIEN disabled; ADTR1OFS None; CLIEN disabled; FLTIEN disabled; ADTR2EN2 disabled; ADTR2EN3 disabled; 
    PG3EVTH = 0x0U;
    // UPDTRG Duty Cycle; ADTR1PS 1:1; PGTRGSEL EOC event; ADTR1EN3 disabled; ADTR1EN1 disabled; ADTR1EN2 disabled; 
    PG3EVTL = 0x8U;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive; 
    PG3FFPCIH = 0x0U;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC; 
    PG3FFPCIL = 0x0U;
    // TQPS Not inverted; LATMOD disabled; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive; 
    PG3FPCIH = 0x0U;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC; 
    PG3FPCIL = 0x0U;
    // PENL enabled; DTCMPSEL PCI Sync Logic; PMOD Complementary; POLL Active-high; PENH enabled; CAPSRC Software; POLH Active-high; 
    PG3IOCONH = 0xCU;
    // FLTDAT 0; DBDAT 0x0; SWAP disabled; OVRENH disabled; OVRENL disabled; OSYNC User output overrides occur when specified by UPDMOD bits; CLMOD disabled; FFDAT 0x0; CLDAT 0x0; OVRDAT 0; 
    PG3IOCONL = 0x200U;
    // PWMPCI PWM1; PLR disabled; PLF disabled; PHR disabled; PHF disabled; 
    PG3LEBH = 0x0U;
    // LEB 0x0; 
    PG3LEBL = 0x0U;
    // PER3 249; 
    PG3PER = 0xF9U;
    // PHASE3 0; 
    PG3PHASE = 0x0U;
    // PCIGT disabled; TQPS Not inverted; SWPCI Drives '0'; BPEN disabled; TQSS None; SWPCIM PCI acceptance logic; BPSEL PWM Generator 1; ACP Level-sensitive; 
    PG3SPCIH = 0x0U;
    // PSS Tied to 0; PPS Not inverted; SWTERM disabled; PSYNC disabled; TERM Manual Terminate; AQPS Not inverted; AQSS None; TSYNCDIS PWM EOC; 
    PG3SPCIL = 0x0U;
    // TRSET disabled; UPDREQ disabled; CLEVT disabled; TRCLR disabled; CAP disabled; SEVT disabled; FFEVT disabled; UPDATE disabled; FLTEVT disabled; 
    PG3STAT = 0x0U;
    // TRIGA3 0; 
    PG3TRIGA = 0x0U;
    // TRIGB3 0; 
    PG3TRIGB = 0x0U;
    // TRIGC3 0; 
    PG3TRIGC = 0x0U;
    // CTB3EN disabled; CTB2EN disabled; CTB1EN disabled; CTB4EN disabled; CTB8EN disabled; CTB7EN disabled; CTB6EN disabled; CTB5EN disabled; 
    CMBTRIGH = 0x0U;
    // CTA1EN disabled; CTA2EN disabled; CTA3EN disabled; CTA4EN disabled; CTA7EN disabled; CTA8EN disabled; CTA5EN disabled; CTA6EN disabled; 
    CMBTRIGL = 0x0U;
    // FSCL 0x0; 
    FSCL = 0x0U;
    // FSMINPER 0x0; 
    FSMINPER = 0x0U;
    // LFSR 0x0; 
    LFSR = 0x0U;
    // PWMLFA PWMS1 or PWMS2;; S1APOL Positive logic; S2APOL Positive logic; PWMLFAD No Assignment; PWMS1A PWM1H; PWMS2A PWM1H; 
    LOGCONA = 0x0U;
    // PWMLFB PWMS1 | PWMS2; S2BPOL Positive logic; PWMLFBD No Assignment; S1BPOL Positive logic; PWMS2B PWM1H; PWMS1B PWM1H; 
    LOGCONB = 0x0U;
    // PWMLFC PWMS1 | PWMS2; PWMLFCD No Assignment; S2CPOL Positive logic; S1CPOL Positive logic; PWMS1C PWM1H; PWMS2C PWM1H; 
    LOGCONC = 0x0U;
    // PWMS1D PWM1H; S1DPOL Positive logic; PWMLFD PWMS1 | PWMS2; PWMLFDD No Assignment; S2DPOL Positive logic; PWMS2D PWM1H; 
    LOGCOND = 0x0U;
    // PWMS1E PWM1H; PWMS2E PWM1H; S1EPOL Positive logic; PWMLFE PWMS1 | PWMS2; S2EPOL Positive logic; PWMLFED No Assignment; 
    LOGCONE = 0x0U;
    // S1FPOL Positive logic; PWMS2F PWM1H; PWMS1F PWM1H; S2FPOL Positive logic; PWMLFFD No Assignment; PWMLFF PWMS1 | PWMS2; 
    LOGCONF = 0x0U;
    // MDC 0; 
    MDC = 0x0U;
    // MPER 249; 
    MPER = 0xF9U;
    // MPHASE 0x0; 
    MPHASE = 0x0U;
    // MCLKSEL FOSC; LOCK disabled; DIVSEL 1:2; HRERR disabled; 
    PCLKCON = 0x0U;
    // EVTASEL PGTRGSEL bits; EVTASYNC Not synchronized; EVTAPOL Active-high; EVTAPGS PG1; EVTASTRD Stretched to 8 PWM clock cycles minimum; EVT1OEN disabled; 
    PWMEVTA = 0x0U;
    // EVTBPGS PG1; EVTBSYNC Not synchronized; EVTBPOL Active-high; EVTBSEL PGTRGSEL bits; EVTBSTRD Stretched to 8 PWM clock cycles minimum; EVT2OEN disabled; 
    PWMEVTB = 0x0U;
    // EVTCPGS PG1; EVTCPOL Active-high; EVTCSEL PGTRGSEL bits; EVTCSTRD Stretched to 8 PWM clock cycles minimum; EVTCSYNC Not synchronized; EVT3OEN disabled; 
    PWMEVTC = 0x0U;
    // EVT4OEN disabled; EVTDSTRD Stretched to 8 PWM clock cycles minimum; EVTDPOL Active-high; EVTDPGS PG1; EVTDSEL PGTRGSEL bits; EVTDSYNC Not synchronized; 
    PWMEVTD = 0x0U;
    // EVT5OEN disabled; EVTEPOL Active-high; EVTEPGS PG1; EVTESTRD Stretched to 8 PWM clock cycles minimum; EVTESEL PGTRGSEL bits; EVTESYNC Not synchronized; 
    PWMEVTE = 0x0U;
    // EVTFPOL Active-high; EVTFPGS PG1; EVTFSTRD Stretched to 8 PWM clock cycles minimum; EVTFSEL PGTRGSEL bits; EVT6OEN disabled; EVTFSYNC Not synchronized; 
    PWMEVTF = 0x0U;
    
    PWM_GeneratorEOCEventCallbackRegister(&PWM_GeneratorEOCEventCallback);
    
    
    //PWM Generator 1 Interrupt
    IFS4bits.PWM1IF = 0;
    IEC4bits.PWM1IE = 1;
    
    //PWM Generator 2 Interrupt
    IFS4bits.PWM2IF = 0;
    IEC4bits.PWM2IE = 1;
    
    //PWM Generator 3 Interrupt
    IFS4bits.PWM3IF = 0;
    IEC4bits.PWM3IE = 1;
    

    PG1CONLbits.ON = 1;
    PG2CONLbits.ON = 1;
    PG3CONLbits.ON = 1;
}

void PWM_Deinitialize (void)
{
    PWM_Disable();
    
    //PWM Generator 1 Interrupt
    IFS4bits.PWM1IF = 0;
    IEC4bits.PWM1IE = 0;
    
    //PWM Generator 2 Interrupt
    IFS4bits.PWM2IF = 0;
    IEC4bits.PWM2IE = 0;
    
    //PWM Generator 3 Interrupt
    IFS4bits.PWM3IF = 0;
    IEC4bits.PWM3IE = 0;
    
    PG1CONL = 0x0U;
    PG2CONL = 0x0U;
    PG3CONL = 0x0U;
    
    PG1CAP = 0x0U;
    PG1CLPCIH = 0x0U;
    PG1CLPCIL = 0x0U;
    PG1CONH = 0x0U;
    PG1DC = 0x0U;
    PG1DCA = 0x0U;
    PG1DTH = 0x0U;
    PG1DTL = 0x0U;
    PG1EVTH = 0x0U;
    PG1EVTL = 0x0U;
    PG1FFPCIH = 0x0U;
    PG1FFPCIL = 0x0U;
    PG1FPCIH = 0x0U;
    PG1FPCIL = 0x0U;
    PG1IOCONH = 0x0U;
    PG1IOCONL = 0x0U;
    PG1LEBH = 0x0U;
    PG1LEBL = 0x0U;
    PG1PER = 0x0U;
    PG1PHASE = 0x0U;
    PG1SPCIH = 0x0U;
    PG1SPCIL = 0x0U;
    PG1STAT = 0x0U;
    PG1TRIGA = 0x0U;
    PG1TRIGB = 0x0U;
    PG1TRIGC = 0x0U;
    PG2CAP = 0x0U;
    PG2CLPCIH = 0x0U;
    PG2CLPCIL = 0x0U;
    PG2CONH = 0x0U;
    PG2DC = 0x0U;
    PG2DCA = 0x0U;
    PG2DTH = 0x0U;
    PG2DTL = 0x0U;
    PG2EVTH = 0x0U;
    PG2EVTL = 0x0U;
    PG2FFPCIH = 0x0U;
    PG2FFPCIL = 0x0U;
    PG2FPCIH = 0x0U;
    PG2FPCIL = 0x0U;
    PG2IOCONH = 0x0U;
    PG2IOCONL = 0x0U;
    PG2LEBH = 0x0U;
    PG2LEBL = 0x0U;
    PG2PER = 0x0U;
    PG2PHASE = 0x0U;
    PG2SPCIH = 0x0U;
    PG2SPCIL = 0x0U;
    PG2STAT = 0x0U;
    PG2TRIGA = 0x0U;
    PG2TRIGB = 0x0U;
    PG2TRIGC = 0x0U;
    PG3CAP = 0x0U;
    PG3CLPCIH = 0x0U;
    PG3CLPCIL = 0x0U;
    PG3CONH = 0x0U;
    PG3DC = 0x0U;
    PG3DCA = 0x0U;
    PG3DTH = 0x0U;
    PG3DTL = 0x0U;
    PG3EVTH = 0x0U;
    PG3EVTL = 0x0U;
    PG3FFPCIH = 0x0U;
    PG3FFPCIL = 0x0U;
    PG3FPCIH = 0x0U;
    PG3FPCIL = 0x0U;
    PG3IOCONH = 0x0U;
    PG3IOCONL = 0x0U;
    PG3LEBH = 0x0U;
    PG3LEBL = 0x0U;
    PG3PER = 0x0U;
    PG3PHASE = 0x0U;
    PG3SPCIH = 0x0U;
    PG3SPCIL = 0x0U;
    PG3STAT = 0x0U;
    PG3TRIGA = 0x0U;
    PG3TRIGB = 0x0U;
    PG3TRIGC = 0x0U;
    CMBTRIGH = 0x0U;
    CMBTRIGL = 0x0U;
    FSCL = 0x0U;
    FSMINPER = 0x0U;
    LFSR = 0x0U;
    LOGCONA = 0x0U;
    LOGCONB = 0x0U;
    LOGCONC = 0x0U;
    LOGCOND = 0x0U;
    LOGCONE = 0x0U;
    LOGCONF = 0x0U;
    MDC = 0x0U;
    MPER = 0x0U;
    MPHASE = 0x0U;
    PCLKCON = 0x0U;
    PWMEVTA = 0x0U;
    PWMEVTB = 0x0U;
    PWMEVTC = 0x0U;
    PWMEVTD = 0x0U;
    PWMEVTE = 0x0U;
    PWMEVTF = 0x0U;
}

void PWM_GeneratorEOCEventCallbackRegister(void (*callback)(enum PWM_GENERATOR genNum))
{
    if(NULL != callback)
    {
        PWM_GeneratorEOCEventHandler = callback;
    }
}

void __attribute__ ((weak)) PWM_GeneratorEOCEventCallback ( enum PWM_GENERATOR genNum )
{ 

} 


/* cppcheck-suppress misra-c2012-8.4
*
* (Rule 8.4) REQUIRED: A compatible declaration shall be visible when an object or 
* function with external linkage is defined
*
* Reasoning: Interrupt declaration are provided by compiler and are available
* outside the driver folder
*/
void __attribute__ ( ( interrupt, no_auto_psv ) ) _PWM1Interrupt ( void )
{
    enum PWM_GENERATOR intGen = PWM_1;
    if(NULL != PWM_GeneratorEOCEventHandler)
    {
        (*PWM_GeneratorEOCEventHandler)(intGen);
    }
    
    IFS4bits.PWM1IF = 0;
}

/* cppcheck-suppress misra-c2012-8.4
*
* (Rule 8.4) REQUIRED: A compatible declaration shall be visible when an object or 
* function with external linkage is defined
*
* Reasoning: Interrupt declaration are provided by compiler and are available
* outside the driver folder
*/
void __attribute__ ( ( interrupt, no_auto_psv ) ) _PWM2Interrupt ( void )
{
    enum PWM_GENERATOR intGen = PWM_2;
    if(NULL != PWM_GeneratorEOCEventHandler)
    {
        (*PWM_GeneratorEOCEventHandler)(intGen);
    }
    
    IFS4bits.PWM2IF = 0;
}

/* cppcheck-suppress misra-c2012-8.4
*
* (Rule 8.4) REQUIRED: A compatible declaration shall be visible when an object or 
* function with external linkage is defined
*
* Reasoning: Interrupt declaration are provided by compiler and are available
* outside the driver folder
*/
void __attribute__ ( ( interrupt, no_auto_psv ) ) _PWM3Interrupt ( void )
{
    enum PWM_GENERATOR intGen = PWM_3;
    if(NULL != PWM_GeneratorEOCEventHandler)
    {
        (*PWM_GeneratorEOCEventHandler)(intGen);
    }
    
    IFS4bits.PWM3IF = 0;
}


/**
 End of File
*/
