/*Драйвер модуля рефлективной памяти VMIPCI5587

ГосНИИАС
Гурвиц Александр Валерьевич
*/

//для RTX_SDK младше чем 2009 (9.1) НУЖНО ОПРЕДЕЛИТЬ в VMIPCI5565.h #define RTX_SDK_VER_LESS_91, иначе не определять
//#define	RTX_SDK_VER_LESS_91

//---------------------------------------------------------------------------
#ifndef VMIPCI5587H
#define VMIPCI5587H
//---------------------------------------------------------------------------
#include "windows.h"

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
#define VMIPCI5587_VID          0x114A
#define VMIPCI5587_DID          0x5587

//Тип прерывания, которое надо сгенерировать
#define GEN_INT_RESET   0
#define GEN_INT1        1
#define GEN_INT2        2
#define GEN_INT3        3

//Тип прерывания, которое было сгенерировано
#define IS_INT1         1
#define IS_INT2         2
#define IS_INT3         4
#define IS_INT_RESET    8

//Тип прерываний, которые можно сгенерировать на узле
#define EN_INT1         0x41//Global + INT1
#define EN_INT2         0x42//Global + INT2
#define EN_INT3         0x44//Global + INT3
#define EN_INT_RESET    0x48//Global + Reset
#define DISABLE_INT     0x0 //запрет всех

//Кольцо сети разорвано или один из модулей обесточен
#define RING_IS_BREAK   -1

//бит проверки Кольца сети
#define OWN_DATA        4

//бит подтверждения прерывания от нашей платы
#define INCOMING_MAIL_BOX_INT  0x00020000L

// PCI bus Operation Register Map
//   Mnemonic  Offset Descriptions                            Access Mode
#define OMB1    0x00 // I/O Outgoing Mailbox                  Lword (R/W)
#define OMB2    0x04 // I/O Outgoing Mailbox                  Lword (R/W)
#define OMB3    0x08 // I/O Outgoing Mailbox                  Lword (R/W)
#define OMB4    0x0C // I/O Outgoing Mailbox                  Lword (R/W)
#define IMB1    0x10 // Incoming Mailbox                      Lword (Read-Only)
#define MWAR    0x24 // Master Write Address Register         Lword (R/W)
#define MWTC    0x28 // Master Write Transfer Count Register  Lword (R/W)
#define MRAR    0x2C // Master Read Address Register          Lword (R/W)
#define MRTC    0x30 // Master Read Transfer Count Register   Lword (R/W)
#define INTCSR  0x38 // Interrupt Control and Status          Lword (R/W)
#define MCSR    0x3C // Bus Master Control and Status         Lword (R/W)

// VMIPCI-5587A Register Map
//  Mnemonic Offset    Descriptions                             Access Mode
#define BID   0x1     // Board ID                               Byte (R)
#define NID   0x4     // Node ID                                Byte (R)
#define IRS   0x8     // INT and Receiver Status                Byte/Word (R/W)
#define CSR1  0x9     // Control and Status 1                   Byte/Word (R/W)
#define CSR2  0xC     // Control and Status 2                   Byte/Word (R/W)
#define CSR3  0xD     // Control and Status 3                   Byte/Word (R/W)
#define CMDN  0x10    // Command Node                           Byte, Word, Lword (W)
#define CMD   0x11    // Command                                Byte, Word, Lword (W)
#define CMDD  0x12    // and $13 Command Data Registers 0       Byte, Word, Lword (W)
#define ICSR  0x14    // INT Control and Status                 Byte/Word (W)
#define SID1  0x18    // INT1 Sender ID                         Byte, Word, Lword (R/W)
#define IFR1  0x19    // INT1 Flag Register                     Byte, Word, Lword (R)
#define IDR1  0x1A    // and $1B INT1 Data Registers            Byte, Word, Lword (R)
#define SID2  0x1C    // INT2 Sender ID                         Byte, Word, Lword (R/W)
#define IFR2  0x1D    // INT2 Flag Register                     Byte, Word, Lword (R)
#define IDR2  0x1E    // and $1F INT2 Data Registers            Byte, Word, Lword (R)
#define SID3  0x20    // INT3 Sender ID                         Byte, Word, Lword (R/W)
#define IFR3  0x21    // INT3 Flag Register                     Byte, Word, Lword (R)
#define IDR3  0x22    // and $23 INT3 Data Registers            Byte, Word, Lword (R)
#define DADD  0x24    // DMA Start Address                      Lword (W)
#define EIS   0x28    // Extended Interrupt Status              Byte (R/W)
#define ECSR3 0x29    // Extended Control and Status 3          Byte/Word (R/W)
#define MICS  0x2A    // Manual Interrupt Control and Status    Byte (R/W)
#define BPSR  0x2C    // Block Prot Set/Reset Register          Byte (R/W)
#define MACR  0x2D    // Memory Access Control Register         Byte (W)
#define BSR   0x30    // Block Select Register                  Byte/Word (R/W)
#define NSR   0x31    // Node Select Register                   Byte/Word (R/W)
#define PNF   0x34    // Protected Node Fault                   Byte/Word (R/W)
#define INLD  0x38    // Initiator Node List Data               Byte (R/W)
#define INLA  0x39    // Initiator Node List Address            Byte (R/W)
#define USNID 0x3C    // Upstream Node ID                       Byte (R/W)
#define START_RAM 0x40// Start of RAM                           Byte, Word, Lword (R/W)

//общий размер ОЗУ на плате VMIPCI-5587A-011 (1Mb)
#define SIZE_RAM                0xFFFFF

//размер области портов ввода-вывода
#define SIZE_PIO                0x40

//запрет инициализации ISR
#define IRQL_NOT_USE            0xFF

//имя объекта памяти для эмулятора платы
#define	MSGSTR_SHM	__TEXT("VMIPCI5587_Emulator.Shm")

#if defined(VMIPCI5587_DLL)
# define VMIPCI5587CLASS __declspec(dllexport)
#elif defined(VMIPCI5587_APP)
# define VMIPCI5587CLASS __declspec(dllimport)
# else
# define VMIPCI5587CLASS
#endif

class VMIPCI5587CLASS VmiPci5587 {
public:
        VmiPci5587();
       ~VmiPci5587();

//поиск Pci платы с номером NumBrd(с 1),
//устанавливает транслированные адреса BaseAddr0, BaseAddr1,
//и IrqL, PCIBusMumber, DeviceMumber для найденной платы
//Возврат - количество найденных плат (с 1)
int VmiPci5587::ScanPciBoard(int NumBrd, ULONG & BaseAddr0, ULONG & BaseAddr1,
                             UCHAR & IrqL, ULONG & PCIBusMumber,ULONG & DeviceMumber);

//Инициализация платы.
//при необнаружении плат область памяти эмулируется в системной памяти.
// Возврат true-успешно, false-неуспешно
bool InitBoard(ULONG BaseAddrPIO,ULONG BaseAddrMem,
                UCHAR IrqL, BOOLEAN (RTFCNDCL *pRoutine)(PVOID context), ULONG BusMumber);

//запись в регистры портов ввода-вывода по смещению Offset значения Data
void WritePortUlong(ULONG Data, ULONG Offset);
//чтение из регистра портов ввода-вывода по смещению Offset значения ULONG
ULONG ReadPortUlong(ULONG Offset);

//запись в память по смещению Offset данных из buf размером Size
//В ПРЕДЕЛАХ  START_RAM - SIZE_RAM
void WriteMemory(PUCHAR buf, ULONG Offset, ULONG Size);
//чтение из памяти по смещению Offset данных в buf размером Size
//В ПРЕДЕЛАХ  START_RAM - SIZE_RAM
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
//              (GEN_INT1 или GEN_INT2 или GEN_INT3 или GEN_INT_RESET)
// INT_DATA - ДАННЫЕ, посылаемые с прерыванием
void GenerateInterrupt(UCHAR DestNId, BOOL GlobalINT, UCHAR Type_INT, USHORT INT_DATA);

// Разрешение генерации прерывания в узле RMN
// параметры:
// Type_En_INT - Тип прерываний, которые можно сгенерировать на узле
//           (EN_INT1 и/или EN_INT2 и/или EN_INT3 и/или EN_INT_RESET или DISABLE_INT)
void EnableInterrupt(UCHAR Type_En_INT);

// ###############  процедуры для обработчика прерывания #######################

// определение причины прерывания.
// должно выполняться вначале обработчика прерывания.
// возвращается Значение INTCSR Interrupt Control and Status для сравнения с
// INCOMING_MAIL_BOX_INT.
// Если этот бит установлен, то это прерывание от платы, иначе - от другого источника
ULONG IsMyInterrupt(void);

// маскирование прерывания.
// должно выполняться вначале обработчика прерывания после IsMyInterrupt.
// возвращается тип прерывания, которое было сгенерировано
// IS_INT1 / IS_INT2 / INT3 / IS_INT_RESET
UCHAR MaskInterrupt(void);

//получение информации о прерывании типа 1,2,3
// в SenderID возвращается NID узла, который сгенерировал прерывание
// в IntFlag  возвращаются флаги прерывания:
//              бит 6=1  -прерывание Глобальное для всех узлов (см. GenerateInterrupt)
//              биты 3-0 -тип прерывания - INT1/INT2/INT3 (см. GenerateInterrupt)
// в IntData  возвращаются ДАННЫЕ, посылаемые с прерыванием (см. GenerateInterrupt)
void GetInt1Info(UCHAR &SenderID, UCHAR &IntFlag, USHORT &IntData);
void GetInt2Info(UCHAR &SenderID, UCHAR &IntFlag, USHORT &IntData);
void GetInt3Info(UCHAR &SenderID, UCHAR &IntFlag, USHORT &IntData);

//размаскирование прерывания.
//должно выполняться в конце обработчика прерывания.
void UnMaskInterrupt(void);

//Получение ID узла, непосредственно подсоединенного к входу нашего узла
//Внимание!
// перед использ. этой процедуры необходимо хотя бы раз сгенерировать обмен по сети
UCHAR GetUpstreamNID(void);

// Получение времени задержки прохождения данных по кольцу сети
// возвращается время задержки в 100нс единицах или
// RING_IS_BREAK, если Кольцо сети разорвано или один из модулей обесточен
long GetLatency(void);

protected:
//Инициализация портов ввода-вывода
// Возврат true-успешно, false-неуспешно
bool InitPIO(ULONG BaseAddr);

//Инициализация доступа к памяти
// Возврат true-успешно, false-неуспешно
bool InitMemory(ULONG BaseAddr);

//Инициализация ISR
// Возврат true-успешно, false-неуспешно
bool InitISR(UCHAR IrqL, BOOLEAN (RTFCNDCL *pRoutine)(PVOID context), ULONG BusMumber);

ULONG BaseAddrPIO;  //базовый адрес портов ввода-вывода
PUCHAR pvMemAddr;   //виртуальный базовый адрес озу платы
HANDLE  hInterrupt; // interrupt vector handle
int NumBoard;       //Количество найденных плат
UCHAR TypeEnInt;    //Тип прерываний, которые можно сгенерировать на узле
HANDLE	hShm;
};
//---------------------------------------------------------------------------
#endif
