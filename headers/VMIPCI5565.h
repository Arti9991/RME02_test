/*
Драйвер модуля рефлективной памяти VMIPCI5565

ГосНИИАС
Гурвиц Александр Валерьевич
2004г
*/

//---------------------------------------------------------------------------
#ifndef VMIPCI5565H
#define VMIPCI5565H
//---------------------------------------------------------------------------

//для RTX_SDK младше чем 2009 (9.1) НУЖНО ОПРЕДЕЛИТЬ в VMIPCI5565.h #define RTX_SDK_VER_LESS_91, иначе не определять
//#define	RTX_SDK_VER_LESS_91

#include "windows.h"

// коды ошибок VMIPCI5565.xxx
#define	Err_5565_OK             0x0//ошибок нет
#define	Err_5565_NO_EMUL_RAM    0x1//не удалось выделить память для эмуляции RAM
#define	Err_5565_LESS_EMUL_RAM  0x2//для эмуляции RAM выделено меньше памяти чем
                                   //запрошено. Реально выделенный размер можно
                                   //определить вызовом GetRealSizeMem()
#define	Err_5565_NO_MAP_RAM     0x4//не удалось отобразить RAM на пользователя
#define	Err_5565_LESS_MAP_RAM   0x8//отображено RAM на пользователя меньше чем
                                   //запрошено. Реально отображенный размер можно
                                   //определить вызовом GetRealSizeMem()

#define	Err_5565_NO_MAP_RFMCSR  0x10    //не удалось отобразить RFM Control and
                                        //Status Registers на пользователя
#define	Err_5565_INIT_IRQ       0x20    //ошибка инициализации прерывания

#define	Err_5565_NO_MAP_BAR0     0x40//не удалось отобразить BAR0 на пользователя
#define	Err_5565_NO_MAP_BAR1     0x80//не удалось отобразить BAR1 на пользователя

// Define RTAPI function calling convention unless an override is in effect.
#ifndef RTAPI
#       if (defined(_MSC_VER)&&(_MSC_VER >= 800)) || defined(_STDCALL_SUPPORTED)
#              define RTAPI __stdcall
#       else
#              define RTAPI
#       endif
#endif
// Define the declaration for application provided functions.
#define RTFCNDCL RTAPI

//коды платы и производителя
#define VMIPCI5565_VID          0x114A
#define VMIPCI5565_DID          0x5565

#define INTCSR_5565  0x68L // Interrupt Control and Status          Lword (R/W)

//бит подтверждения прерывания от нашей платы
//Local Input Interrupt Active.
//When set to a one (1), indicates the Local input interrupt is active.
#define LOCAL_INP_INT_ACTIVE_5565  0x00008000L

//PCI Interrupt Enable. Writing a one (1) enables PCI interrupts.
#define PCI_INT_ENABLE_5565  0x00000100L

//Local Interrupt Input Enable.
//Writing a one (1) enables a Local interrupt input to assert a PCI interrupt.
//Used in conjunction with the PCI Interrupt Enable bit (INTCSR[8]).
//Clearing the Local bus cause of the interrupt also clears the interrupt.
#define LOCAL_INT_INP_ENABLE_5565  0x00000800L

//Global Interrupt Enable bit
#define GLOB_INT_EN_5565 0x4000L

//Тип прерываний, которые можно сгенерировать на узле
#define EN_INT1_5565         0x1L | GLOB_INT_EN_5565      // INT1
#define EN_INT2_5565         0x2L | GLOB_INT_EN_5565      // INT2
#define EN_INT3_5565         0x4L | GLOB_INT_EN_5565      // INT3
#define EN_INT_RESET_5565    0x8L | GLOB_INT_EN_5565      // Reset
#define EN_INT_INIT_5565     0x80L| GLOB_INT_EN_5565      //Init
#define DISABLE_INT_5565     0x0L //запрет всех

//Тип прерывания, которое было сгенерировано
#define IS_INT1_5565         0x1
#define IS_INT2_5565         0x2
#define IS_INT3_5565         0x4
#define IS_INT_RESET_5565    0x8
#define IS_INT_INIT_5565     0x80

//Тип прерывания, которое надо сгенерировать
#define GEN_INT_RESET_5565   0 //Reset Node Request (sets LISR Bit 03 only, PCI master must perform actual reset)
#define GEN_INT1_5565        1 //Network Interrupt 1 (stored in a 127 deep FIFO at the receiving node)
#define GEN_INT2_5565        2 //Network Interrupt 2 (stored in a 127 deep FIFO at the receiving node)
#define GEN_INT3_5565        3 //Network Interrupt 3 (stored in a 127 deep FIFO at the receiving node)
#define GEN_OWN_DATA_5565    4 //Reserved (Setting to this type will only set the OWN DATA bit in the CSR1)
#define GEN_INT_INIT_5565    7 //Network Initialized Interrupt (stored in a 127 deep FIFO at the receiving node)
#define GEN_INT_GLOBAL_5565  8 //Global enable. Send to all nodes regardless of Network Target Node Reg (NTN)

//Кольцо сети разорвано или один из модулей обесточен
#define RING_IS_BREAK_5565   -1

//бит проверки OWN DATA
#define OWN_DATA_LED_5565    1

//бит лампочки STATUS
#define STATUS_LED_5565      0x80000000

//бит лампочки RX Signal Detect
#define RX_SIG_DET_LED_5565  0x4

//The RFM Control and Status registers for the VMIPCI-5565
#define BRV_5565     0x00 //Board Revision Read Only Current board revision/model
#define BID_5565     0x01 //Board ID Register Read Only BID is $65 for VMIPCI-5565
					 // $3…2 -- Reserved --
#define NID_5565     0x04 //Node ID Register Read Only Set by 8 board jumpers
                     // $7…5 -- Reserved --
#define LCSR1_5565   0x08 //$B...8  Local Control & Status Reg. 1 Read/Write Some bits reserved. Some bits read only.
                     //$F...C -- Reserved --
#define LISR_5565    0x10 //$13...10  Local Interrupt Status Reg. Read/Write Some bits reserved. Some bits read only.
#define LIER_5565    0x14 //$17...14  Local Interrupt Enable R. Read/Write
#define NTD_5565     0x18 //$1B..18  Network Target Data Read/Write 32 Data bits for network target
#define NTN_5565     0x1C //Network Target Node Read/Write Target node ID for network Int.
#define NIC_5565     0x1D //Network Interrupt Command Read/Write Select Int type and initiate interrupt
                     //$1F…1E -- Reserved --
#define ISD1_5565    0x20 //$23...20  Int. 1 Sender Data Read/Write 127 loc. By 32 bit FIFO for network Int. 1
#define SID1_5565    0x24 //Int. 1 Sender ID Read/Write 127 loc. Deep FIFO/ write clears pointers
					 //$27…25 -- Reserved --
#define ISD2_5565    0x28 //$2B...28  Int. 2 Sender Data Read/Write 127 loc. By 32 bit FIFO for network Int. 2
#define SID2_5565    0x2C //Int. 2 Sender ID Read/Write 127 loc. Deep FIFO/ write clears pointers
                     // $2F…2D -- Reserved --
#define ISD3_5565    0x30 //$33...30  Int. 3 Sender Data Read/Write 127 loc. By 32 bit FIFO for network Int. 3
#define SID3_5565    0x34 //Int. 3 Sender ID Read/Write 127 loc. Deep FIFO/ write clears pointers
                     // $37...35 -- Reserved
#define INITD_5565   0x38 //$3B...38  Initialized Node Data Read/Write 127 loc. By 32 bit FIFO for opt. Data
#define INITN_5565   0x3C //Initialized Node ID Read/Write 127 loc. Deep FIFO/ write clears pointers
                     //$3F.3D -- Reserved --

//размер области BAR0
#define SIZE_BAR0_5565                256

//размер области BAR1
#define SIZE_BAR1_5565                256

//размер области BAR2 ( RFM control & status register)
#define SIZE_BAR2_5565                64

//общий размер ОЗУ на плате VMIPCI-5565-010 (64Mb)
#define SIZE_BAR3_64M_5565             0x3FFFFFF + 1

//общий размер ОЗУ на плате VMIPCI-5565-110 (128Mb)
#define SIZE_BAR3_128M_5565            0x7FFFFFF + 1

//запрет инициализации ISR
#define IRQL_NOT_USE_5565            0xFF

//имя объекта памяти для эмулятора платы
#define	MSGSTR_SHM_5565	__TEXT("VMIPCI5565_Emulator.Shm")

#if defined(VMIPCI5565_DLL)
# define VMIPCI5565CLASS __declspec(dllexport)
#elif defined(VMIPCI5565_APP)
# define VMIPCI5565CLASS __declspec(dllimport)
# else
# define VMIPCI5565CLASS
#endif

class VMIPCI5565CLASS VmiPci5565 {
public:


#if defined (UNICODE)
	VmiPci5565(ULONG   SizeEmulMem = SIZE_BAR3_64M_5565, wchar_t *Name=MSGSTR_SHM_5565); //запрашиваемый размер памяти для эмуляции - UNICODE
#else
	VmiPci5565(ULONG   SizeEmulMem = SIZE_BAR3_64M_5565, char *Name=MSGSTR_SHM_5565); //запрашиваемый размер памяти для эмуляции - ANSI
#endif

	   ~VmiPci5565();

//поиск Pci платы с номером NumBrd(с 1),
//устанавливает транслированные адреса BaseAddr0, BaseAddr1,BaseAddr2,BaseAddr3,
//и IrqL, PCIBusMumber, DeviceMumber для найденной платы
//Возврат - количество найденных плат (с 1)
int ScanPciBoard(int NumBrd, ULONG & BaseAddr0, ULONG & BaseAddr1, ULONG & BaseAddr2, ULONG & BaseAddr3,
                             UCHAR & IrqL, ULONG & PCIBusMumber,ULONG & DeviceMumber);

//Инициализация платы.
//при необнаружении плат область памяти эмулируется в системной памяти.
// Возврат true-успешно, false-неуспешно
bool InitBoard(ULONG BaseAddr0, ULONG BaseAddr1, ULONG BaseAddr2, ULONG BaseAddr3,
                UCHAR IrqL, BOOLEAN (RTFCNDCL *pRoutine)(PVOID context), ULONG BusMumber);

//запись в память по смещению Offset данных из buf размером Size
void WriteMemory(PUCHAR buf, ULONG Offset, ULONG Size);
//чтение из памяти по смещению Offset данных в buf размером Size
void ReadMemory(PUCHAR buf, ULONG Offset, ULONG Size);

//запись в память по смещению Offset переменной UCHAR
void WriteChar(UCHAR c, ULONG Offset);
//чтение из памяти по смещению Offset переменной UCHAR
UCHAR ReadChar(ULONG Offset);

//запись в память по смещению Offset переменной USHORT
void WriteShort(USHORT s, ULONG Offset);
//чтение из памяти по смещению Offset переменной USHORT
USHORT ReadShort(ULONG Offset);

//запись в память по смещению Offset переменной ULONG
void WriteLong(ULONG l, ULONG Offset);
//чтение из памяти по смещению Offset переменной ULONG
ULONG ReadLong(ULONG Offset);

// Генерация прерывания в другом узле RMN
// параметры:
// DestNId - NID узла, в котором надо сгенерировать прерывание
// GlobalINT - сгенерировать прерывание во всех узлах сразу
// Type_INT - Тип прерывания, которое надо сгенерировать
//              (GEN_INT1_5565 или GEN_INT2_5565 или GEN_INT3_5565 или GEN_INT_RESET_5565 или GEN_INT_INIT_5565)
// INT_DATA - ДАННЫЕ, посылаемые с прерыванием
void GenerateInterrupt(UCHAR DestNId, BOOL GlobalINT,UCHAR Type_INT, ULONG INT_DATA);

// Разрешение генерации прерывания в узле RMN
// параметры:
// Type_En_INT - Тип прерываний, которые можно сгенерировать на узле
//           (EN_INT1_5565 и/или EN_INT2_5565 и/или EN_INT3_5565 и/или EN_INT_RESET_5565 и/или EN_INT_INIT_5565 или DISABLE_INT_5565)
void EnableInterrupt(ULONG Type_En_INT);

// ###############  процедуры для обработчика прерывания #######################

// определение причины прерывания.
// должно выполняться вначале обработчика прерывания.
// возвращается значение true если это прерывание от платы, иначе - от другого источника
bool IsMyInterrupt(void);

//получение информации о прерывании типа 1,2,3,Init
// в SenderID возвращается NID узла, который сгенерировал прерывание
// в IntData  возвращаются ДАННЫЕ, посылаемые с прерыванием (см. GenerateInterrupt)
void GetInt1Info(UCHAR &SenderID,  ULONG &IntData)
		{IntData  = ReadRFMCSRLong(ISD1_5565);SenderID = ReadRFMCSRChar(SID1_5565);}
void GetInt2Info(UCHAR &SenderID,  ULONG &IntData)
        {IntData  = ReadRFMCSRLong(ISD2_5565);SenderID = ReadRFMCSRChar(SID2_5565);}
void GetInt3Info(UCHAR &SenderID,  ULONG &IntData)
        {IntData  = ReadRFMCSRLong(ISD3_5565);SenderID = ReadRFMCSRChar(SID3_5565);}
void GetIntInitInfo(UCHAR &SenderID,  ULONG &IntData)
        {IntData  = ReadRFMCSRLong(INITD_5565);SenderID = ReadRFMCSRChar(INITN_5565);}

//размаскирование прерывания.
//должно выполняться в конце обработчика прерывания.
void UnMaskInterrupt(void) {WriteRFMCSRLong(GLOB_INT_EN_5565,LISR_5565);} //пишемем в LISR Global Int Enable только для взвода INT Reset

// ############### конец процедур для обработчика прерывания #######################

// Получение времени задержки прохождения данных по кольцу сети
// возвращается время задержки в 100нс единицах или
// RING_IS_BREAK_5565, если Кольцо сети разорвано или один из модулей обесточен
long GetLatency(void);

// Получение реального размера памяти на плате или выделенной эмулированной
ULONG GetRealSizeMem(void) {return dwRealSizeMem;}

//Получение кода ошибки
ULONG GetLastError5565();

//Функция возвращает Номер версии драйвера.
int GetVersion();

//Получение Node ID
UCHAR GetNID(void) {return ReadRFMCSRChar(NID_5565);}

//проверка лампочки STATUS: true - горит, false - не горит
bool GetStatusLed(void);

//проверка лампочки RX Signal Detect: true - горит, false - не горит
bool GetRxSigDetLed(void);

//проверка лампочки Own Data: true - горит, false - не горит
bool GetOwnDataLed(void);

//установка лампочки STATUS: true - горит, false - не горит
void SetStatusLed(bool Status);

//установка лампочки Own Data: true - горит, false - не горит
void SetOwnDataLed(bool Status);

//Работа с RFM Control and Status Registers
//запись в RFMCSR по смещению Offset переменной UCHAR
void WriteRFMCSRChar(UCHAR c, ULONG Offset);
//чтение из RFMCSR по смещению Offset переменной UCHAR
UCHAR ReadRFMCSRChar(ULONG Offset);
//запись в RFMCSR по смещению Offset переменной ULONG
void WriteRFMCSRLong(ULONG l, ULONG Offset);
//чтение из RFMCSR по смещению Offset переменной ULONG
ULONG ReadRFMCSRLong(ULONG Offset);

//Работа с BA0 Registers
//запись в BA0 по смещению Offset переменной ULONG
void WriteBA0Long(ULONG l, ULONG Offset);
//чтение из BA0 по смещению Offset переменной ULONG
ULONG ReadBA0Long(ULONG Offset);

//Работа с BA1 Registers
//запись в BA1 по смещению Offset переменной ULONG
void WriteBA1Long(ULONG l, ULONG Offset);
//чтение из BA1 по смещению Offset переменной ULONG
ULONG ReadBA1Long(ULONG Offset);

TCHAR SharedMemName[64];
int     NumBoard;       //Количество найденных плат
protected:

//Инициализация доступа к Local Configuration, Runtime and DMA Registers (BAR0)
// Возврат true-успешно, false-неуспешно
bool InitBAR0(ULONG BaseAddr);

//Инициализация доступа к Local Configuration, Runtime and DMA Registers (BAR1)
// Возврат true-успешно, false-неуспешно
bool InitBAR1(ULONG BaseAddr);

//Инициализация доступа к памяти RFM Control and Status Registers (BAR2)
// Возврат true-успешно, false-неуспешно
bool InitRFMCSRAddr(ULONG BaseAddr);

//Инициализация доступа к памяти RAM  (BAR3)
// Возврат true-успешно, false-неуспешно
bool InitRAMAddr(ULONG BaseAddr);

//Инициализация ISR
// Возврат true-успешно, false-неуспешно
bool InitISR(UCHAR IrqL, BOOLEAN (RTFCNDCL *pRoutine)(PVOID context), ULONG BusMumber);

PUCHAR  pvBA0;          //виртуальный базовый адрес Local Configuration, Runtime and DMA Registers (из BAR0)
ULONG   ulBA1;          //базовый адрес портов ввода-вывода  Local Configuration, Runtime and DMA Registers (из BAR1)
PUCHAR  pvRFMCSRAddr;   //виртуальный базовый адрес RFM Control and Status Registers (из BAR2)
PUCHAR  pvRAMAddr;      //виртуальный базовый адрес ОЗУ платы (из BAR3)

HANDLE  hInterrupt;     //interrupt vector handle
ULONG   TypeEnInt;      //Тип прерываний, которые можно сгенерировать на узле
HANDLE	hShm;           //дескриптор SharedMemory
ULONG   dwRealSizeMem;  //реальный размер памяти на плате или выделенной эмулированной
ULONG   LastError;      //код ошибки
};
//---------------------------------------------------------------------------
#endif
