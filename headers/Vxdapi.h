////////////////////////////////////////////////////////////////////////////////
// User API Dll for Windows 95/98 driver  HWINT.VxD
// Beta Version 1.0b
// Supported board L-305 L-264 L-1250 L-1251 L-1221 L-761/780/783
////////////////////////////////////////////////////////////////////////////////
#ifndef __LCARDVXD__
#define __LCARDVXD__

#include <windows.h>
#include <winioctl.h>
/*#include "1251cmd.h"
#include "1221cmd.h"
#include "1450cmd.h"
#include "pcicmd.h"
*/
#include "../@include/ioctl.h" //для 761

#define DllExport(type) extern "C" __declspec( dllexport ) type WINAPI
                                       
#pragma pack(1)
typedef struct __SLOT_PARAM
{
   DWORD size;
   DWORD Base;
   DWORD BaseL;
   DWORD Base1;
   DWORD BaseL1;
   DWORD Mem;
   DWORD MemL;
   DWORD Mem1;
   DWORD MemL1;
   DWORD Irq;
   DWORD Type;
   DWORD DSPType;
   DWORD Dma;
   DWORD DmaDac;
} SLOT_PAR, *PSLOT_PAR;

typedef struct __DEV_ALL
{
   DWORD       size;
   HANDLE      hVxd;
   DWORD       Type;
   DWORD       DSPType;
   DWORD       DSPBase;
   WORD        DTA_REG;
   WORD        IDMA_REG;
   WORD        CMD_REG;
   WORD        IRQ_RST;
   WORD        DTA_ARRAY;
   WORD        RDY_REG;
   WORD        CFG_REG;
   HANDLE      hEvent; // for ovelapped DIOC_START under NT
   OVERLAPPED  ov;
   WORD        Reserv[10];
} DEV_REG_UNI, *PDEV_REG_UNI;

#pragma pack()

extern DWORD TimeOUT;

// Working with I/O ports
DllExport(DWORD) inbyte ( HANDLE hVxd, DWORD offset, BYTE  *data, DWORD len=1, DWORD key=0 );
DllExport(DWORD) inword ( HANDLE hVxd, DWORD offset, WORD  *data, DWORD len=2, DWORD key=0 );
DllExport(DWORD) indword( HANDLE hVxd, DWORD offset, DWORD *data, DWORD len=4, DWORD key=0 );

DllExport(DWORD) outbyte ( HANDLE hVxd, DWORD offset, BYTE  *data, DWORD len=1, DWORD key=0 );
DllExport(DWORD) outword ( HANDLE hVxd, DWORD offset, WORD  *data, DWORD len=2, DWORD key=0 );
DllExport(DWORD) outdword( HANDLE hVxd, DWORD offset, DWORD *data, DWORD len=4, DWORD key=0 );

// Working with MEM ports
DllExport(DWORD) inmbyte ( HANDLE hVxd, DWORD offset, BYTE  *data, DWORD len=1, DWORD key=0 );
DllExport(DWORD) inmword ( HANDLE hVxd, DWORD offset, WORD  *data, DWORD len=2, DWORD key=0 );
DllExport(DWORD) inmdword( HANDLE hVxd, DWORD offset, DWORD *data, DWORD len=4, DWORD key=0 );

DllExport(DWORD) outmbyte ( HANDLE hVxd, DWORD offset, BYTE  *data, DWORD len=1, DWORD key=0 );
DllExport(DWORD) outmword ( HANDLE hVxd, DWORD offset, WORD  *data, DWORD len=2, DWORD key=0 );
DllExport(DWORD) outmdword( HANDLE hVxd, DWORD offset, DWORD *data, DWORD len=4, DWORD key=0 );
                                                                                                                                           

// Working with L-1250/1251 ////////////////////////////////////////////////////
DllExport(DWORD) SendCommand (LPVOID dev, WORD cmd, DWORD boffs=0, DWORD key=0 );
DllExport(DWORD) GetData (LPVOID dev, WORD *data, DWORD boffs=0, DWORD key=0 );
DllExport(DWORD) PutData (LPVOID dev, WORD data, DWORD boffs=0, DWORD key=0 );

//DWORD WINAPI _export GetDataFast ( DWORD hVxd, WORD *data, DWORD boffs=0, DWORD key=0 );
DllExport(DWORD) PlataTest_1251(LPVOID dev, DWORD boffs=0, DWORD key=0 );
DllExport(DWORD) SetSpeedADSP_1251(LPVOID dev, WORD type, DWORD boffs=0, DWORD key=0 );
DllExport(DWORD) AdChan_1251(LPVOID dev, WORD Chan, WORD *Data, DWORD boffs=0, DWORD key=0 );

DllExport(DWORD) SetInterDelay_1251(LPVOID dev, WORD Delay, DWORD boffs=0, DWORD key=0 ); //obsolete
DllExport(DWORD) SetTimerScale_1251(LPVOID dev, WORD Scale, DWORD boffs=0, DWORD key=0 );

DllExport(DWORD) FillADCparameters_1251(
                                          LPVOID adcPar,
                                          double *Rate,                    // set in kHz assume inter_delay
                                          double *Kadr,                    // set in ms  assume kadr freq
                                          WORD SynchroType,                // like dos mode
                                          WORD SynchroMode,                // like dos ttlmode
                                          WORD AdChannel,                  // like dos
                                          WORD AdPorog,                    // like dos
                                          WORD NCh,                        // channel numbers
                                          WORD *Chn,                       // logical numb
                                          WORD FIFO,                       // fifo size
                                          WORD IrqStep,                    // irq step == fifo size
                                          WORD Pages                       // pages quant.
                                       );

DllExport(DWORD) MemoryState_1251(LPVOID dev, WORD *MemSize, DWORD boffs=0, DWORD key=0);
DllExport(DWORD) Memory_PM_State_1251(LPVOID dev, WORD *MemState, DWORD boffs=0, DWORD key=0);

DllExport(DWORD) TTL_In_1251(LPVOID dev, WORD *Data, DWORD boffs=0, DWORD key=0);
DllExport(DWORD) TTL_Out_1251(LPVOID dev, WORD Data, DWORD boffs=0, DWORD key=0);  // in each set channel
DllExport(DWORD) TTL_DSP_Out_1251(LPVOID dev, WORD Data, DWORD boffs=0, DWORD key=0);
DllExport(DWORD) TTL_DSP_In_1251(LPVOID dev, WORD *Data, DWORD boffs=0, DWORD key=0);
DllExport(DWORD) DAC_Sample_1251(LPVOID dev, short *DAC_Value, DWORD boffs=0, DWORD key=0);
DllExport(DWORD) DAC_Output_1251(LPVOID dev, short *DAC_Value, DWORD boffs=0, DWORD key=0);
DllExport(DWORD) DAC_Config_1251(LPVOID dev, WORD DAC_Number, WORD DAC_Mode, DWORD boffs=0, DWORD key=0);
DllExport(DWORD) DAC_SetBuffer_1251(LPVOID dev, WORD DAC_Number, DWORD *Size, LPVOID DacBuf);

////////////////////////////////////////////////////////////////////////////////

// Working with L-1221 /////////////////////////////////////////////////////////
DllExport(DWORD) Get_DM_word_1221(LPVOID dev, WORD Addr, WORD *Data, DWORD boffs=0, DWORD key=0 );
DllExport(DWORD) Put_DM_word_1221(LPVOID dev, WORD Addr, WORD Data, DWORD boffs=0, DWORD key=0 );
DllExport(DWORD) Get_DM_array_1221( LPVOID dev, WORD Addr, DWORD Count, WORD *Data, DWORD boffs=0, DWORD key=0);
DllExport(DWORD) Put_DM_array_1221( LPVOID dev, WORD Addr, DWORD Count, WORD *Data, DWORD boffs=0, DWORD key=0);
DllExport(DWORD) Command1221(LPVOID dev, WORD cmd, DWORD boffs=0, DWORD key=0 );

// API functions
DllExport(DWORD) PlataTest_1221(LPVOID dev, DWORD key=0);
DllExport(DWORD) FillADCparameters_1221(
                                        LPVOID adcPar,  // стуктура к заполнению
                                        double *Rate,   // частота опроса
                                        WORD *RateCode,            // rate code (see table in manual)
                                        WORD *Divider,             // rate divider
                                        WORD SynchroType,         // not impl
                                        WORD SynchroSensitivity,  // not impl
                                        WORD SynchroMode,         // not impl
                                        WORD AdChannel,           // not impl
                                        WORD AdPorog,             // not impl
                                        WORD NCh,                 // bit mask of active chan
                                        WORD *Chn,                // 8 words of ampl coef (see table in manual)
                                        WORD FIFO,                // fifo size
                                        WORD IrqStep,             // irq step
                                        WORD Pages                // how much pages of irqstep to use
                                       );
DllExport(DWORD) ADC_Sample_1221(LPVOID dev, WORD Chan, WORD *Data, DWORD key=0);
DllExport(DWORD) GetExternalCounter_1221(LPVOID dev, DWORD *ExtCnt, DWORD key=0);
DllExport(DWORD) EnableCorrection_1221(LPVOID dev, WORD *EnCor, DWORD key=0);
DllExport(DWORD) SetBitResolution_1221(LPVOID dev, short *BitRes, DWORD key=0);
DllExport(DWORD) CheckOverflow_1221(LPVOID dev, WORD *Over, DWORD key=0);
DllExport(DWORD) TTL_In_1221(LPVOID dev, WORD *Data, DWORD key=0);        //0XXX 0000
DllExport(DWORD) TTL_Out_1221(LPVOID dev, WORD Data, DWORD key=0);        //0XXX 000R
DllExport(DWORD) TTL_Config_1221(LPVOID dev, WORD *TTLmask, DWORD key=0); //0XXX 0000

// Working with flash
DllExport(DWORD) ReadFlashByte_1221(LPVOID dev, WORD FlashAddress, BYTE *Data, DWORD key=0);
DllExport(DWORD) WriteFlashByte_1221(LPVOID dev, WORD FlashAddress, BYTE Data, DWORD key=0);
////////////////////////////////////////////////////////////////////////////////

// Working with PLX PCI board //////////////////////////////////////////////////
DllExport(DWORD) Get_DM_word_PLX(LPVOID dev, WORD Addr, WORD *Data, DWORD key=0);
DllExport(DWORD) Put_DM_word_PLX(LPVOID dev, WORD Addr, WORD Data, DWORD key=0);
DllExport(DWORD) Put_PM_word_PLX(LPVOID dev, WORD Addr, DWORD Data, DWORD key=0);
DllExport(DWORD) Get_PM_word_PLX(LPVOID dev, WORD Addr, DWORD *Data, DWORD key=0);

DllExport(DWORD) Get_DM_array_PLX(LPVOID dev, WORD Addr, DWORD count, WORD *Data, DWORD key=0 );
DllExport(DWORD) Put_DM_array_PLX(LPVOID dev, WORD Addr, DWORD count, WORD *Data, DWORD key=0 );
DllExport(DWORD) Put_PM_array_PLX(LPVOID dev, WORD Addr, DWORD count, DWORD *Data, DWORD key=0 );
DllExport(DWORD) Get_PM_array_PLX(LPVOID dev, WORD Addr, DWORD count, DWORD *Data, DWORD key=0 );

DllExport(DWORD) CommandPLX(LPVOID dev, WORD cmd, DWORD key=0 );

DllExport(DWORD) PlataTest_PLX(LPVOID dev, DWORD key=0);
DllExport(DWORD) PlataReset_PLX(LPVOID dev, DWORD key=0);

// ADC
DllExport(DWORD) ADC_Sample_PLX(LPVOID dev, WORD Chan, WORD *Data, DWORD key=0);

DllExport(DWORD) FillADCparameters_PLX(
                                          LPVOID adcPar,
                                          LPVOID pd,
                                          double *Rate,
                                          double *Kadr,
                                          WORD SynchroType,
                                          WORD SynchroSensitivity,
                                          WORD SynchroMode,
                                          WORD AdChannel,
                                          WORD AdPorog,
                                          WORD NCh,
                                          WORD *Chn,
                                          WORD FIFO,
                                          WORD IrqStep,
                                          WORD Pages
                                      );

// DAC
DllExport(DWORD) DAC_Fifo_Config_PLX(LPVOID dev, WORD *size, DWORD key = 0);
DllExport(DWORD) DAC_Sample_PLX(LPVOID dev, LPVOID pd, WORD DAC_Number, short *DAC_Value, DWORD key=0);
DllExport(DWORD) DAC_Stream_PLX(LPVOID dev, WORD enable, DWORD key=0 );
DllExport(DWORD) DAC_Rate_PLX(LPVOID dev, LPVOID pd, double *DAC_Rate, DWORD key=0);

// TTL lines
DllExport(DWORD) TTL_In_PLX(LPVOID dev, WORD *Data, DWORD key=0);
DllExport(DWORD) TTL_Out_PLX(LPVOID dev, WORD Data, DWORD key=0);

// Flash
DllExport(DWORD) ReadPlataDescr_PLX(LPVOID dev, LPVOID pd, DWORD key=0);
DllExport(DWORD) WritePlataDescr_PLX(LPVOID dev, LPVOID pd, WORD enable=0, DWORD key=0);
DllExport(DWORD) ReadFlashWord_PLX(LPVOID dev, WORD FlashAddress, WORD *Data, DWORD key=0);
DllExport(DWORD) WriteFlashWord_PLX(LPVOID dev, WORD FlashAddress, WORD FlashWord, DWORD key=0);
DllExport(DWORD) EnableFlashWrite_PLX(LPVOID dev, WORD Flag, DWORD key=0);
////////////////////////////////////////////////////////////////////////////////

// Common functions ////////////////////////////////////////////////////////////
DllExport(DWORD) SetTimeOut( DWORD timeOut );
DllExport(HANDLE) OpenLDevice( DWORD Slot, LPVOID dev);
DllExport(DWORD) CloseLDevice(LPVOID dev);
DllExport(DWORD) SetParameters(LPVOID dev, LPVOID ad_par, DWORD *UsedSize, LPVOID Data, LPVOID Sync);
DllExport(DWORD) RequestBuffer(LPVOID dev, DWORD *Size); //in words
DllExport(DWORD) InitStartLDevice(LPVOID dev);
DllExport(DWORD) StartLDevice(LPVOID dev);
DllExport(DWORD) StopLDevice(LPVOID dev);
////////////////////////////////////////////////////////////////////////////////

// WORD  WINAPI _export CreateChannel( WORD Ku, WORD NCh );

DllExport(DWORD) GetSlotParam(DWORD Slot, LPVOID sPar);
DllExport(DWORD) SetSlotParam(DWORD Slot, LPVOID sPar);

// LoadBios Group Function /////////////////////////////////////////////////////
DllExport(DWORD) LoadBios(LPVOID dev, char *FileName, DWORD boffs=0, DWORD key=0 );
DllExport(DWORD) LoadBios1251(LPVOID dev, char *FileName, DWORD boffs=0, DWORD key=0 );
DllExport(DWORD) LoadBios1221(LPVOID dev, char *FileName, DWORD boffs=0, DWORD key=0);
DllExport(DWORD) LoadBiosPLX(LPVOID dev, char *FileName, DWORD key=0);
////////////////////////////////////////////////////////////////////////////////


// Event Functions /////////////////////////////////////////////////////////////
DllExport(DWORD) SetLDeviceEvent( LPVOID dev, HANDLE hEvent );
DllExport(DWORD) CreateCommonEvent( HANDLE* pr3Evt, HANDLE* pr0Evt,
                                    BOOL bManualReset=0, BOOL bInitialState=0);


// API Helpers
DllExport(DWORD) GetSystemVersionMy();

// For LabView
DllExport(DWORD) GetSizeOf_DEV_REG_UNI();
DllExport(DWORD) GetSizeOf_SLOT_PAR();
DllExport(DWORD) GetSizeOf_ADC_PAR();
DllExport(DWORD) GetSizeOf_PLATA_DESCR();
DllExport(DWORD) GetSyncData(DWORD Sync, DWORD *SyncData0, DWORD *SyncData1);
DllExport(DWORD) GetDataFromBuffer(DWORD DataPtr, WORD *DataArray, DWORD size);
DllExport(DWORD) PutDataToBuffer(DWORD DataPtr, WORD *DataArray, DWORD size);
DllExport(DWORD) GetSizeOf_PLATA_DESCR_1450();

// Working with L1450 board //////////////////////////////////////////////////
DllExport(DWORD) Get_DM_word_1450(LPVOID dev, WORD Addr, WORD *Data, DWORD key=0);
DllExport(DWORD) Put_DM_word_1450(LPVOID dev, WORD Addr, WORD Data, DWORD key=0);
DllExport(DWORD) Put_PM_word_1450(LPVOID dev, WORD Addr, DWORD Data, DWORD key=0);
DllExport(DWORD) Get_PM_word_1450(LPVOID dev, WORD Addr, DWORD *Data, DWORD key=0);

DllExport(DWORD) Get_DM_array_1450(LPVOID dev, WORD Addr, DWORD count, WORD *Data, DWORD key=0 );
DllExport(DWORD) Put_DM_array_1450(LPVOID dev, WORD Addr, DWORD count, WORD *Data, DWORD key=0 );
DllExport(DWORD) Put_PM_array_1450(LPVOID dev, WORD Addr, DWORD count, DWORD *Data, DWORD key=0 );
DllExport(DWORD) Get_PM_array_1450(LPVOID dev, WORD Addr, DWORD count, DWORD *Data, DWORD key=0 );

DllExport(DWORD) Command_1450(LPVOID dev, WORD cmd, DWORD key=0 );

DllExport(DWORD) LoadBios1450(LPVOID dev, char *FileName, DWORD boffs=0, DWORD key=0);
DllExport(DWORD) FillADCparameters_1450(
                                          LPVOID adcPar,
                                          LPVOID pd,
                                          double *Rate,
                                          double *Kadr,
                                          WORD SynchroType,
                                          WORD SynchroSensitivity,
                                          WORD SynchroMode,
                                          WORD AdChannel,
                                          WORD AdPorog,
                                          WORD NCh,
                                          WORD *Chn,
                                          WORD FIFO,
                                          WORD IrqStep,
                                          WORD Pages
                                      );

DllExport(DWORD) PlataTest_1450(LPVOID dev);
DllExport(DWORD) ADC_Sample_1450(LPVOID dev, WORD Chan, short *Data);

DllExport(DWORD) Load_Coef_1450(LPVOID dev, LPVOID pd);
DllExport(DWORD) Enable_Correction_1450(LPVOID dev, WORD enable=1);
DllExport(DWORD) Enable_TTL_Out_1450(LPVOID dev, WORD enable=1);
DllExport(DWORD) TTL_In_1450(LPVOID dev, WORD *Data);
DllExport(DWORD) TTL_Out_1450(LPVOID dev, WORD Data);

// Flash
DllExport(DWORD) ReadPlataDescr_1450(LPVOID dev, LPVOID pd, DWORD key=0);
DllExport(DWORD) WritePlataDescr_1450(LPVOID dev, LPVOID pd, WORD enable=0, DWORD key=0);
DllExport(DWORD) ReadFlashWord_1450(LPVOID dev, WORD Address, WORD *Data, DWORD key=0);
DllExport(DWORD) WriteFlashWord_1450(LPVOID dev, WORD Address, WORD Data, DWORD key=0);
DllExport(DWORD) EnableFlashWrite_1450(LPVOID dev, WORD Flag, DWORD key=0);

DllExport(DWORD) Load_Coef_PLX(LPVOID dev, LPVOID pd);
DllExport(DWORD) Enable_Correction_PLX(LPVOID dev, WORD enable=1);

#endif

