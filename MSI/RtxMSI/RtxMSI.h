#ifndef _RtxMSI
#define _RtxMSI

////////////////////////////////////////////////////////////////////
//                                                                //
//	RtxApp1.h - header file                                       //
//                                                                //
// This file was generated using the RTX Application Wizard       //
// for Visual Studio.                                             //
////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <wchar.h>
#include <rtapi.h>
#include <RtxProp.h>
#include <stdio.h>
#include <time.h>

// RMe_02
#define  RMe_02_VendorID  0x1172;
#define  RMe_02_DeviceID  0x5950;
const unsigned __int64 PartCount = 8; //Количество сегментов памяти на плате
const unsigned __int64 InterruptCount = 16;  //Максимальное количество прерываний разного типа

#define WAIT_PULSE_by_REG  75000 // кол-во чтений базового регистра состояния LPT порта

// Total number of cards allowed for the test
#define MAX_NUM_CARDS 8

struct _RMe_02_BAR0
 {
 unsigned __int64 Counter;	       // 0x00 R/W Счетчик тактов 100МГц. Любая запись сбрасывает счетчик в 0;
	unsigned __int32 Frameware : 32;	// 0x08 RO  Номер прошивки RMe_02
	unsigned __int32 ID        : 32;	// 0x0C RO  Номер узла (выставляется джамперами на плате)
 struct                           // 0x10 R/W Регистр управления платой;
		{
		unsigned __int32 clearLine           : 1;  // включение режима очистки линии (deNoise) на 10мкси сброс счетчика динамической балансировки сети. Данный бит переходит в значение по умолчанию автоматически;
		unsigned __int32 resetPackCounter    : 1;	 // сброс счетчика…. пакетов (смещение 1Ch). Данный бит переходит в значение по умолчанию автоматически;
		unsigned __int32 resetBufferOverload : 1;	 // сброс битов переполнения FIFO-буферов (смещение 14h, биты 8 и 12). Данный бит переходит в значение по умолчанию автоматически;
		unsigned __int32                     : 5;  // не используется
		unsigned __int32 lockBuferOutput     : 1;	 // блокировка FIFO-буфера локальной передачи данных (BAR1 ->RAM);
		unsigned __int32                     : 7;  // не используется
		unsigned __int32 counterChoose       : 2;  //выбор счетчика для отображения в регистре со смещением 1Ch («00» – время обхода инициализационного пакета по всей петле, в 10нс единицах; «01» – счетчик пакетов отправленных в память ПЭВМ; «10» - счетчик пакетов, отправленных в рефлективную сеть; «11» - счетчик пакетов, полученных из рефлективной сети);
		unsigned __int32                     : 14; // не используется
		} config;
 struct                           // 0x14 RO Статусный регистр
		{
		unsigned __int32 SD                  : 1; // SD– обнаружение сигнала оптическим трансивером платы RMe - 02 (бит повторяет свечение желтого светодиода на планке платы RMe - 02);
		unsigned __int32 onLine              : 1;	// «onLine» – штатный режим функционирования рефлективной сети: платы синхронизированы между собой и готовы к обмену информацией;
		unsigned __int32 breakLoop           : 1;	// «BreakLoop»- бит, индицирующий разрыв петли в рефлективной сети;
		unsigned __int32 deNoise             : 1;	// «deNoise» - бит, индицирующий включение режима очистки линии;
		unsigned __int32 SFPerror            : 1; // бит, индицирующий наличие ошибки оптического передатчикаSFP-модуля (TXfault);
		unsigned __int32 SFP                 : 1;	// бит наличия SFP-модуля;
		unsigned __int32                     : 2; // не используется
		unsigned __int32 bufferOverloadPass  : 1;	// бит переполнения проходного FIFO-буфера;
		unsigned __int32 bufferOverloadOut   : 1;	// бит переполнения выходного FIFO-буфера;
		unsigned __int32 bufferOverloadLocal : 1;	// бит переполнения FIFO-буфера локальной передачи данных (BAR1->RAM);
		unsigned __int32                     : 1; // не используется
		unsigned __int32 bufferOverloadIn    : 1; // бит переполнения FIFO-буфера информации, поступающей из рефлективной сети;
		unsigned __int32                     : 3; // не используется
		unsigned __int32 breackLoopNumber    : 8;	//в режиме «BreakLoop», содержат номер узла рефлективной сети, оптический приемник которого не подключен к оптоволокну;
		unsigned __int32                     : 8; // не используется
	 } status;
 struct                           // 0x18 не используется
		{
  //
		unsigned __int32 temperature         : 16;	// Регистр температуры с внешнего датчика. биты [15..11] – биты знака (0 – «+», 1 - «-»), биты[10..4] – целая часть, биты[3..0] – дробная часть(мл.бит равен 0, 0625ОС);
		unsigned __int32                     : 16; // не используется
	 } mon;
 unsigned __int64 InputPhysicalAddress[PartCount]; // 0x20,0x28,...,0x58 Массив физических адресов сегментов (8 сегментов по 16Мб);
      
 // 0x78 RO регистр задействованных прерываний, своими битами (с 0 по 15-ый) показывает, какие прерывания будут задействованы на данном узле.// 0x7C RO регистр вектора прерываний, своими битами (с 0 по 15-ый) показывает, какое прерывание было сгенерировано последним
	union                           // 0x80,0x84,...,0xBC R/W регистр адреса 64-битной ячейки памяти,доступ к которым, из рефлективной сети, генерирует прерывания irq0,1,...,15 сосответственно.
		{
		unsigned __int32 data;
		struct InterruptValue
 		{
			unsigned __int32 ncell  :21;						//номер 64 битной ячейки в сегменте (0 … 2М-1);
			unsigned __int32 nseg   : 3;						//номер 16МВ сегмента памяти с контролируемой ячейкой;
			unsigned __int32        : 7;
			unsigned __int32 enable : 1;						//включение прерывания;
	 	}interruptValue;
  } interrupt[InterruptCount];
 };


// Device object
typedef struct {
	ULONG  busNum;      // Bus number
	DWORD  deviceNum;   // Device number
	DWORD  functionNum; // Function number
	DWORD  base[6];     // Memory mapped address
	ULONG  cardNum;     // Card number, 0-based
	ULONG  Order;       // Order based on IST priority: 0-highest
	ULONG  priority;    // IST priority
	ULONG  msiEnable;   // Use MSI/MSIX if supported
	HANDLE ihr;			      // Interrupt handler
	ULONG  istReady;    // IST ready to handle next interrupt
} DRVDEV;


//  Add Function prototypes Here
// function prototype for periodic timer function

void RTFCNDCL TimerHandler( void * nContext);

void WordIn ();
//void RTFCNDCL InterruptHandler(PVOID context);

// Event server child thread prototype
//ULONG RTFCNDCL ChildThread_high( void * nContext );
int Device_Search
		(
		int CardNumber,					          // input: PCI card to find
		PCI_SLOT_NUMBER *pSlotNumber,	// output: pointer to slot number
		PPCI_COMMON_CONFIG  PciData		 // output: PCI card information
		);

int RMe_02_Configure(PPCI_COMMON_CONFIG PciData, DRVDEV *pCardInfo);
void RMe_02_CLOSE(void);

//#pragma pack(pop)   

#endif


