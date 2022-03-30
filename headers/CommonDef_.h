// Общие определения констант и структур данных

#ifndef COMMONDEF_H
#define COMMONDEF_H

#include "Config.h"

#ifndef CONF_RIG
#error ### CONF_RIG from Config.h undefine ###
#endif

// ----------------------------------------------------------------------------------
//номера блоков компьютеров
// ----------------------------------------------------------------------------------

#if CONF_RIG==1 // 2900СМТ

#define NPC_1				0   // DISP_IO, моделей нет
#define NPC_2				1   // DISP_IO, Самолет, цели, SIGMA, СБКВ
#define NPC_3				2			// 
#define NPC_4				3			// DISP_IO, ИПО & ИСУО
#define NPC_5				4			// DISP_IO, позиция РВВ-АЕ
#define NPC_6				5			// ЦИРС
#define NPC_7 			6			// Визуализация 29СМТ
#define NPC_8	 		7   // КАРАТ 29КУБ
#define NPC_9	 		8   // 
#define NPC_10	 	9   // 
#define NPC_11	 10   // 
#define NPC_12	 11   // 
#define NPC_13	 12   // 
#define NPC_14	 13   // 
#define NPC_15	 14   // 
#define NPC_16		15			// DISP_SI, Регистрация и управление стендом

#endif

#if CONF_RIG==2 // 2900К/КУБ 

#define NPC_1				0   // 
#define NPC_2				1   // 
#define NPC_3				2			// 
#define NPC_4				3			// 
#define NPC_5				4			// 
#define NPC_6				5			// ЦИРС
#define NPC_7 			6			// 
#define NPC_8	 		7   // 
#define NPC_9	 		8   // 
#define NPC_10	 	9   // 
#define NPC_11	 10   // DISP_IO, моделей нет
#define NPC_12	 11   // Самолет, цели, SIGMA, СБКВ
#define NPC_13	 12   // 
#define NPC_14	 13   // DISP_IO, ИПО & ИСУО
#define NPC_15	 14   // DISP_IO, моделей нет
#define NPC_16		15			// DISP_SI, Регистрация и управление стендом

#endif

#if CONF_RIG==3 // Резерв

//#define NPC_1				0   //
//#define NPC_2				1   //
//#define NPC_3				2			// 
//#define NPC_4				3			//
//#define NPC_5				4			//
//#define NPC_6				5			//
//#define NPC_7 			6			//
//#define NPC_8	 		7   //
//#define NPC_9	 		8   // 
//#define NPC_10	 	9   // 
//#define NPC_11	 10   // 
//#define NPC_12	 11   // 
//#define NPC_13	 12   // 
//#define NPC_14	 13   // 
//#define NPC_15	 14   // 
#define NPC_16		15			// DISP_SI, Регистрация и управление стендом

#endif

#if CONF_RIG==4 // Резерв

#define NPC_1				0   //
#define NPC_2				1   //
#define NPC_3				2			// 
#define NPC_4				3			//
#define NPC_5				4			//
#define NPC_6				5			//
#define NPC_7 			6			//
#define NPC_8	 		7   //
#define NPC_9	 		8   // 
#define NPC_10	 	9   // 
#define NPC_11	 10   // 
#define NPC_12	 11   // 
#define NPC_13	 12   // 
#define NPC_14	 13   // 
#define NPC_15	 14   // 
#define NPC_16		15			// DISP_SI, Регистрация и управление стендом

#endif

//номера блоков компьютеров
#if CONF_RIG==5 // 170M

//#define NPC_1				0   //
//#define NPC_2				1   //
//#define NPC_3				2			// 
//#define NPC_4				3			//
//#define NPC_5				4			//
//#define NPC_6				5			//
//#define NPC_7 			6			//
//#define NPC_8	 		7   //
//#define NPC_9	 		8   // 
//#define NPC_10	 	9   // 
//#define NPC_11	 10   // 
//#define NPC_12	 11   // 
//#define NPC_13	 12   // 
//#define NPC_14	 13   // 
//#define NPC_15	 14   // 
#define NPC_16		15			// DISP_SI, Регистрация и управление стендом

#endif

#if CONF_RIG==6 // 29UPG

#define NPC_1				0   // СС-IPC2   :
#define NPC_2				1   // DS-IPC1   : 
#define NPC_3				2			// SSS-IPC1  :
#define NPC_4				3			// SSS-IPC2  :
#define NPC_5				4			// SSS-IPC3  : 
#define NPC_6				5			// DRSS-IPC1 :
#define NPC_7 			6			// SOLS-IPC1 :
#define NPC_8	 		7   // ESVS-IPC1 :
#define NPC_9	 		8   // SLS-IPC1  :
#define NPC_10	 	9   // 
#define NPC_11	 10   // 
#define NPC_12	 11   // 
#define NPC_13	 12   // 
#define NPC_14	 13   // 
#define NPC_15	 14   // 
#define NPC_16		15			// СС-IPC1: DISP_SI, Регистрация и управление стендом

#endif

#if CONF_RIG==7 // 29M/M2

#define NPC_1				0   // СС2   :
#define NPC_2				1   // DS1   : 
#define NPC_3				2			// SSS1  :
#define NPC_4				3			// SSS2  :
#define NPC_5				4			// SSS3  : 
#define NPC_6				5			// DRSS1 :
#define NPC_7 			6			// SOLS1 :
#define NPC_8	 		7   // SOLS2 :
#define NPC_9	 		8   // ESVS1 :
#define NPC_10	 	9   // SLS1  :
#define NPC_11	 10   // 
#define NPC_12	 11   // 
#define NPC_13	 12   // 
#define NPC_14	 13   // 
#define NPC_15	 14   // 
#define NPC_16		15			// СС1: DISP_SI, Регистрация и управление стендом

#endif

#if CONF_RIG==8 // 29К/КУБ(Р)

#define NPC_1				0   // СС2    :
#define NPC_2				1   //
#define NPC_3				2			// SSS1   :
#define NPC_4				3			// SSS2   :
#define NPC_5				4			// SSS3   : 
#define NPC_6				5			// DRSS1  :
#define NPC_7 			6			// CSOLS1 :
#define NPC_8	 		7   //
#define NPC_9	 		8   // ESVS1 :
#define NPC_10	 	9   // SLS3  :
#define NPC_11	 10   // 
#define NPC_12	 11   // 
#define NPC_13	 12   // 
#define NPC_14	 13   // 
#define NPC_15	 14   // 
#define NPC_16		15			// СС1: DISP_SI, Регистрация и управление стендом

#endif
// ----------------------------------------------------------------------------------


// -------   Reflective Memory   -------------

#define RF_INT					0x00000	 // состояние приемника прерываний, записанное программой RNM_and_OMB1.rtss

#define SIZE_RF_TIME														8  //
#define SIZE_RF_TIME_PULSE_COMMON	8  //
#define SIZE_RF_TIME_PULSE_TEST			8  //
#define SIZE_RF_WAIT_CIRS									8  //
#define SIZE_RF_STATUS_DISP							4  //
#define SIZE_RF_IDENTIFIER       16  //

#define size_RF_USER 0x10000 // Размер области памяти на IPC для свободного использования
#define size_RF_DISP 0x10000 // Размер области памяти на IPC где запущена DISP_IO.exe
// не более 0x8000 = 32768 входных параметров
// не более 0x8000 = 32768 выходных параметров
#define size_RF_in_DISP  (size_RF_DISP/2) // Размер области памяти для вх.парам. на IPC где запущена DISP_IO.exe
#define size_RF_out_DISP (size_RF_DISP/2) // Размер области памяти для вых.парам. на IPC где запущена DISP_IO.exe

#define RF_Common								   		0x000040 // Глобальное время

#define RF_TIME_IPC1						  		(RF_Common     + SIZE_RF_TIME) // 0x48 время для IPC1
#define RF_TIME_IPC2						  		(RF_TIME_IPC1  + SIZE_RF_TIME) // 0x50 время для IPC2
#define RF_TIME_IPC3						 	 	(RF_TIME_IPC2  + SIZE_RF_TIME) // 0x58 время для IPC3
#define RF_TIME_IPC4		 				 		(RF_TIME_IPC3  + SIZE_RF_TIME) // 0x60 время для IPC4
#define RF_TIME_IPC5			 			 		(RF_TIME_IPC4  + SIZE_RF_TIME) // 0x68 время для IPC5
#define RF_TIME_IPC6				 		 		(RF_TIME_IPC5  + SIZE_RF_TIME) // 0x70 время для IPC6
#define RF_TIME_IPC7					 	 		(RF_TIME_IPC6  + SIZE_RF_TIME) // 0x78 время для IPC7
#define RF_TIME_IPC8						  		(RF_TIME_IPC7  + SIZE_RF_TIME) // 0x80 время для IPC8
#define RF_TIME_IPC9						  		(RF_TIME_IPC8  + SIZE_RF_TIME) // 0x88 время для IPC9
#define RF_TIME_IPC10						 		(RF_TIME_IPC9  + SIZE_RF_TIME) // 0x90 время для IPC10
#define RF_TIME_IPC11						 		(RF_TIME_IPC10 + SIZE_RF_TIME) // 0x98 время для IPC11
#define RF_TIME_IPC12						 		(RF_TIME_IPC11 + SIZE_RF_TIME) // 0xA0 время для IPC12
#define RF_TIME_IPC13						 		(RF_TIME_IPC12 + SIZE_RF_TIME) // 0xA8 время для IPC13
#define RF_TIME_IPC14						 		(RF_TIME_IPC13 + SIZE_RF_TIME) // 0xB0 время для IPC14
#define RF_TIME_IPC15						 		(RF_TIME_IPC14 + SIZE_RF_TIME) // 0xB8 время для IPC15
#define RF_TIME_IPC16						 		(RF_TIME_IPC15 + SIZE_RF_TIME) // 0xC0 время для IPC16


#define RF_TIME_PULSE_COMMON	0x100                                            //  : время такта (в 0.1мкс) пишется в режиме тактирования UseRMN_IRQ=4
#if RF_TIME_IPC16 + SIZE_RF_TIME >  RF_TIME_PULSE_COMMON
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  RF_TIME_PULSE_COMMON  uncorrect !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#endif
#define RF_TIME_PULSE_TEST			(RF_TIME_PULSE_COMMON + SIZE_RF_TIME_PULSE_COMMON) //  : время такта задаваемое программой timer.exe в 0.1мкс 
#define RF_TIME_WAIT_CIRS			 (RF_TIME_PULSE_TEST + SIZE_RF_TIME_PULSE_TEST)     //  : задержка в 0.1мкс для запуска процедур ЦИРСа
#define RF_IDENTIFIER			     (RF_TIME_WAIT_CIRS + SIZE_RF_WAIT_CIRS)            //  : идентификационный код первого запуска

#define RF_STATUS_DISP_1     0x200                                   // 0x200
#if RF_IDENTIFIER + SIZE_RF_IDENTIFIER >  RF_STATUS_DISP_1
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  RF_STATUS_DISP_1  uncorrect !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#endif
#define RF_STATUS_DISP_2     (RF_STATUS_DISP_1  + SIZE_RF_STATUS_DISP) // 0x204
#define RF_STATUS_DISP_3     (RF_STATUS_DISP_2  + SIZE_RF_STATUS_DISP) // 0x208
#define RF_STATUS_DISP_4     (RF_STATUS_DISP_3  + SIZE_RF_STATUS_DISP) // 0x20C
#define RF_STATUS_DISP_5     (RF_STATUS_DISP_4  + SIZE_RF_STATUS_DISP) // 0x210
#define RF_STATUS_DISP_6     (RF_STATUS_DISP_5  + SIZE_RF_STATUS_DISP) // 0x214
#define RF_STATUS_DISP_7     (RF_STATUS_DISP_6  + SIZE_RF_STATUS_DISP) // 0x218
#define RF_STATUS_DISP_8     (RF_STATUS_DISP_7  + SIZE_RF_STATUS_DISP) // 0x21C
#define RF_STATUS_DISP_9     (RF_STATUS_DISP_8  + SIZE_RF_STATUS_DISP) // 0x220
#define RF_STATUS_DISP_10    (RF_STATUS_DISP_9  + SIZE_RF_STATUS_DISP) // 0x224
#define RF_STATUS_DISP_11    (RF_STATUS_DISP_10 + SIZE_RF_STATUS_DISP) // 0x228
#define RF_STATUS_DISP_12    (RF_STATUS_DISP_11 + SIZE_RF_STATUS_DISP) // 0x22C
#define RF_STATUS_DISP_13    (RF_STATUS_DISP_12 + SIZE_RF_STATUS_DISP) // 0x230
#define RF_STATUS_DISP_14    (RF_STATUS_DISP_13 + SIZE_RF_STATUS_DISP) // 0x234
#define RF_STATUS_DISP_15    (RF_STATUS_DISP_14 + SIZE_RF_STATUS_DISP) // 0x238
#define RF_STATUS_DISP_16    (RF_STATUS_DISP_15 + SIZE_RF_STATUS_DISP) // 0x23C

#define RF_DISP_1   0x10000                    // 0x10000... 0x20000-1 
#define RF_USER_1	 	(RF_DISP_1 + size_RF_DISP)   // 0x20000... 0x30000-1

#define RF_DISP_2   (RF_USER_1 + size_RF_USER)   // 0x30000... 0x40000-1
#define RF_USER_2	 	(RF_DISP_2 + size_RF_DISP)   // 0x40000... 0x50000-1

#define RF_DISP_3   (RF_USER_2 + size_RF_USER)   // 0x50000... 0x60000-1
#define RF_USER_3	 	(RF_DISP_3 + size_RF_DISP)   // 0x60000... 0x70000-1

#define RF_DISP_4   (RF_USER_3 + size_RF_USER)   // 0x70000... 0x80000-1
#define RF_USER_4	 	(RF_DISP_4 + size_RF_DISP)   // 0x80000... 0x90000-1

#define RF_DISP_5   (RF_USER_4 + size_RF_USER)   // 0x90000... 0xA0000-1
#define RF_USER_5	 	(RF_DISP_5 + size_RF_DISP)   // 0xA0000... 0xB0000-1

#define RF_DISP_6   (RF_USER_5 + size_RF_USER)   // 0xB0000... 0xC0000-1
#define RF_USER_6	 	(RF_DISP_6 + size_RF_DISP)   // 0xC0000... 0xD0000-1

#define RF_DISP_7   (RF_USER_6 + size_RF_USER)   // 0xD0000... 0xE0000-1
#define RF_USER_7	 	(RF_DISP_7 + size_RF_DISP)   // 0xE0000... 0xF0000-1

#define RF_DISP_8   (RF_USER_7 + size_RF_USER)   // 0xF0000... 0x100000-1
#define RF_USER_8	 	(RF_DISP_8 + size_RF_DISP)   // 0x100000... 0x110000-1

#define RF_DISP_9   (RF_USER_8 + size_RF_USER)   // 0x110000... 0x120000-1
#define RF_USER_9	 	(RF_DISP_9 + size_RF_DISP)   // 0x120000... 0x130000-1

#define RF_DISP_10   (RF_USER_9 + size_RF_USER)  // 0x130000... 0x140000-1
#define RF_USER_10	 	(RF_DISP_10 + size_RF_DISP) // 0x140000... 0x150000-1

#define RF_DISP_11   (RF_USER_10 + size_RF_USER) // 0x150000... 0x160000-1
#define RF_USER_11	 	(RF_DISP_11 + size_RF_DISP) // 0x160000... 0x170000-1

#define RF_DISP_12   (RF_USER_11 + size_RF_USER) // 0x170000... 0x180000-1
#define RF_USER_12	 	(RF_DISP_12 + size_RF_DISP) // 0x180000... 0x190000-1

#define RF_DISP_13   (RF_USER_12 + size_RF_USER) // 0x190000... 0x1A0000-1
#define RF_USER_13	 	(RF_DISP_13 + size_RF_DISP) // 0x1A0000... 0x1B0000-1

#define RF_DISP_14   (RF_USER_13 + size_RF_USER) // 0x1B0000... 0x1C0000-1
#define RF_USER_14	 	(RF_DISP_14 + size_RF_DISP) // 0x1C0000... 0x1D0000-1

#define RF_DISP_15   (RF_USER_14 + size_RF_USER) // 0x1D0000... 0x1E0000-1
#define RF_USER_15	 	(RF_DISP_15 + size_RF_DISP) // 0x1E0000... 0x1F0000-1

#define RF_DISP_16   (RF_USER_15 + size_RF_USER) // 0x1F0000... 0x200000-1
#define RF_USER_16	 	(RF_DISP_16 + size_RF_DISP) // 0x200000... 0x210000-1

// ..................................................
// типы адаптеров IdAdaptersType
// ..................................................
#define RES1		         1   // В базе данных SEALEVEL
#define TX6_PC_C							2
#define PC429_3_88					3
#define PC429_4_xx					4
#define PCADS_05							5   // В базе данных PCADS05t
#define PCADS_05K						6   // В базе данных PCADS05K
#define PCADS_05RK  		 7   // В базе данных PCADS05RK
#define iMKIO_1      		8   // В базе данных iMKIO-01
#define SPECIAL								9   // В базе данных VIRTUAL
#define PCADS_06RTM		 10   // В базе данных PCADS06RTM
#define PCADS_06K		   11   // В базе данных PCADS06K
#define PCADS_06RK				12   // В базе данных PCADS06RK
#define PCI_1753						13   // В базе данных PCI-1753
#define RES7 									14   // В базе данных Astra
#define VMIPCI5587A			15   // В базе данных VMIPCI-5587A
#define PCI_1716      16
#define PCI_1724      17
#define IPK1      				18
#define VMIPCI5565				19   // В базе данных VMIPCI-5565
#define PCI_1713	     20
#define RMe_02	        21   // В базе данных RMe-02
#define PCI_ASTRA	    22
#define CUS_BMK	      23   // В базе данных CusBmk
#define PCI_ASTRA_BL	 24
#define PCADSv7RTMin		 25   // В базе данных PCADSv7RTMin
#define PCADSv7RTMout		26   // В базе данных PCADSv7RTMout
#define PCADS_v7RK         27   // В базе данных PCADSv7RK
#define RES12         28   // В базе данных не объявлен !!!
#define pciSPI		      29   // В базе данных SPI
#define RS485_MTVS		  30   // В базе данных MTVS
#define RES13         31   // В базе данных не объявлен !!!
// ..................................................

//ресурсы устройств
struct DeviceResources {
	ULONGLONG BaseMemory; // базовый адрес памяти
	USHORT BasePort;      // базовый адрес портов ввода-вывода
	USHORT DMAPort;       // порт канала DMA
	UCHAR DMAChannel;     // номер канала DMA
	UCHAR nIRQ;           // номер линии запроса прерывания
	USHORT NumChannel;				// кол-во каналов адаптера
};


//ресурсы Pci1753
struct DevicePci1753 {
	UCHAR  config[8];		// настройка портов на In/Out
	USHORT BasePort;   // базовый адрес портов ввода-вывода
	USHORT reserv1;				// резерв
	UCHAR reserv2;					// резерв
	UCHAR nIRQ;        // номер линии запроса прерывания
	USHORT reserv;				 // резерв
};

//ресурсы Астры
struct DeviceAstraResources {
	ULONGLONG reserv1;		// резерв
	USHORT BasePort;		  // Adapters.PortIO- базовый адрес портов ввода-вывода, сейчас 310
	USHORT reserv2;		   // резерв
	UCHAR PortSize;   	 // Adapters.PortSize
	UCHAR nIRQ;	    	   // резерв
	USHORT reserv3;		   // резерв
};

//Адресов МПИ в пакете(линии) для Astra
struct Astra_BURST_INFO{
	ULONG InOut;	     // DataBurst.InOut признак входной-1/выходной-0 
	ULONG MPIAddress; // StrDescr.Address - адрес МПИ
	ULONG Mode;	      // StrDescr.SubAddress - признак регистрации, 1 - да, 0- нет
};                //Адресов МПИ в пакете(линии) для Astra

struct AstraPCI_BURST_INFO{
	ULONG MPIAddress; // StrDescr.Address - адрес МПИ
	USHORT Choice;	   // StrDescr.Choice  признак регистраци (у нас всегда 1, в автономной задаче возможно снятие регистрации)
	USHORT Intr;	     // StrDescr.SubAddress - признак формирования импульса по приходу адреса, 1 - да, 0- нет
};


//описание структуры пакета(линии) для МКИО
struct MKIO_Batch {
	USHORT NumBatch;            //сквозной номер пакета

	USHORT reserv1 : 1;
	USHORT InOut : 1; //признак пакета входной-1/выходной-0 - берется из свойства линии
	USHORT MessageError : 3; //состояние выполненных сообщений КК
	USHORT CodeTransfer : 5; //код формата передачи (0-BC->RT, 1-RT->BC, 2-RT->RT)
	USHORT NumWord : 6; //число слов данных в сообщении

	USHORT  AddrRT1 : 5; //адрес ОУ /  адрес ОУ-приемника в режиме RT->RT)  AddrRT = 0...31
	USHORT  AddrRT2 : 5; //адрес ОУ-передатчика  (для RT->RT)		AddrRT = 0...31
	USHORT  SubAddr : 5; //подадрес сообщения     SubAddr = 1...30
	USHORT  Activ : 1; //флаг активности абонента, принимающего это сообщение. Activ=1 -абонент активен, 0-нет

	USHORT  CodeFreq;           //код частоты выдачи пакета(линии) (1-100Гц, 2-50, 3-33,4-25, 5-20,10-10,20-5,100-1Гц)
};

#define MAX_NUM_MESSAGE      512 //максимальное количество  сообщений для каждого КК

//информация для настройки плат TMK1553
struct TMK1553INFO {
	USHORT BoardType;    // тип платы: TX1,RT1,TX4,TX5,TX6,TX5MRT,TX6MRT - определены в tmk1553.h
	UCHAR AddrRT[4];     // для режима RT_MODE - адрес ОУ,  AddrRT = 0...31
	//для одноадресных ОУ(TX1,RT1,TX4,TX5,TX6,TE6_PCI,TE1_PCI)AddrRT[0],
	//для многоадресных ОУ(TX5MRT,TX6MRT,TE6_PCI_MRT)AddrRT[0]...AddrRT[3]
	USHORT BoardMode;    // режим платы:   BC_MODE,RT_MODE,MT_MODE,MRT_MODE - определены в tmk1553.h
	USHORT NumMessage;   //общее количество пакетов сообщений, уложенных в Mkio_Batch для каждой платы (для режима КК)
	UCHAR		NumPC;        //номер РС
	UCHAR		NumBoard;     //номер платы в РС
	MKIO_Batch  Mkio_Batch[MAX_NUM_MESSAGE];//массив с описанием списка пакетов для конкретной платы (для режима КК)
};

//описание структуры пакета(линии) для КМБО
struct KMBO_Batch {
	USHORT reserv1 : 1;
	USHORT NumWord : 6; //число слов данных в сообщении
	USHORT InOut : 1; //признак пакета входной-1/выходной-0 - берется из свойства линии
	USHORT AddrRT : 8; //адрес ОУ 
};


//ресурсы ADVANTECH DA PCI1724
struct DeviceRes_PCI1724{
	ULONG	BaseMemory;   // базовый адрес памяти
	ULONG	ulReserv;
	USHORT	BasePort;    // базовый адрес портов ввода-вывода
	USHORT	usReserv;    // порт канала DMA
	UCHAR	Sync;         // номер канала DMA
	UCHAR	nIRQ;         // номер линии запроса прерывания
	USHORT	NumChannel;	 // кол-во каналов адаптера
};//определение параметра для ADVANTECH AD PCI1724

//ресурсы MTVS
struct DeviceMTVS {
	ULONGLONG Baud;				// скорость передачи Vmax = 115200 бит/с в десятичной системе счисления(настройка порта)
	USHORT DevAddr;    // адрес устройства МТВС (0х08) в шестнадц системе счисления (для инициализации устройства)
	USHORT NumCOMport; // номер порта COM 1 ... COM 4. Только Цифра в десятичной системе счисления(настройка порта)
	UCHAR LenWord;		   // длина слова передачи мах 8 бит десятичной системе счисления (настройка порта)
	UCHAR NoUse1;      // не используется
	USHORT NoUse2;	    // не используется
};

struct ID_PCI1724 {
	ULONG InOut : 1;        // признак входной-1/выходной-0 (бит 1)
	ULONG GroupMode : 2;	    //2,3	SubAddress: 0(3) - normal, 1(2)-offset(calibr)  2(1) -Gain mode(calibr)
	ULONG bit4_6 : 3;	      // (1-4)
	ULONG bit7_18 : 12;      //заполнение младших разрядов (биты 7-18)	
	ULONG NumChannel : 5; // StrDescr.NumWord Номер канала адаптера 0-31 (биты 19,20,21,22,23) (Порты ввода-вывода пронумерованные насквозь для адаптера)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27,28,29,30)

	ULONG LoBit : 5;        // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;        // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	     // 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	     // 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;     // Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29,30,31,32)

	ULONG Data; // значение параметра (бит 1)
};
//ресурсы ADVANTECH DA PCI1723
struct DeviceRes_PCI1723{
	ULONG	BaseMemory;    // базовый адрес памяти
	ULONG	ulReserv;
	USHORT	BasePort;     // базовый адрес портов ввода-вывода
	USHORT	usReserv;     // порт канала DMA
	UCHAR	Sync;          // номер канала DMA
	UCHAR	nIRQ;          // номер линии запроса прерывания
	USHORT	NumChannel;	  // кол-во каналов адаптера
};//определение параметра для ADVANTECH AD PCI1723  // Таня
struct ID_PCI1723 {
	ULONG InOut : 1; // признак входной-1/выходной-0 (бит 1)
	ULONG GroupMode : 2;	// 2,3	SubAddress: 0(3) - normal, 1(2)-offset(calibr)  2(1) -Gain mode(calibr)
	ULONG bit4_6 : 3;	// (1-4)
	ULONG bit7_18 : 12;//заполнение младших разрядов (биты 7-18)	
	ULONG NumChannel : 5; // StrDescr.NumWord Номер канала адаптера 0-31 (биты 19,20,21,22,23) (Порты ввода-вывода пронумерованные насквозь для адаптера)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27,28,29,30)

	ULONG LoBit : 5; // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29,30,31,32)

	ULONG Data;       // значение параметра (бит 1)
};

//ресурсы ADVANTECH AD PCI1713
struct DevicePCI1713 {
	ULONG	BaseMemory;    // базовый адрес памяти Adapters.DmaCh
	ULONG	ulReserv;
	USHORT	BasePort;    // базовый адрес портов ввода-вывода Adapters.PortIO
	USHORT	usReserv;    // порт канала DMA
	UCHAR	FirstChannel; // номер первого сканируемого канала(1-32),если 0, то	1 
	//  Adapters.DmaCh
	UCHAR	nIRQ;         // номер линии запроса прерывания 
	//Adapters.InterruptNum
	USHORT	NumChannel;	 // кол-во задействованных каналов адаптера, если 0, то 32 
	//Adapters.NumCh
};
//настройки канала ADVANTECH AD PCI1713
struct PCI1713_CH_CONFIG //DataBurst
{
	USHORT Gain : 4;	// Gain code - 0(20в),1(10в),2(5в),4(2.5в) 8(1.25в). 
	// Gain =5/(Scale*(1+SignBit1) 
	// Пример: Scale= 2.5 для +-5 Gain =1
	// Scale= 2.5 для  0-5в       Gain =2 
	USHORT B_U : 1;	// ~StrDescr.SignBit: 0 = Bipolar->SignBit=1, 1 = uniopolar->SignBit=0,  
	USHORT S_D : 1;	// StrDescr.SubAddr: 0 = single ended, 1 = differential
	USHORT res2 : 2; //резерв
	USHORT res8 : 8;	//reserv
};

//настройки режима ADVANTECH AD PCI1713
struct PCI1713_DEV_CTRL
{
	USHORT SW : 1;  //   Software trigger enable.Adapters.DmaPort&1
	USHORT PACER : 1;  //   Pacer trigger enable.Adapters.DmaPort&2
	USHORT EXT : 1;  //   External trigger enable.Adapters.DmaPort & 4
	USHORT GATE : 1;  //   External trigger gate function enable.Adapters.DmaPort&8
	USHORT IRQ_EN : 1;  //   Interrupt enable Adapters.DmaPort & 16
	USHORT ONE_FH : 1;  //   0 = interrupt after one data conversion, 1 = FIFO half full.Adapters.DmaPort & 32
	USHORT reserv10 : 10; //
};
//настройка платы ADVANTECH AD PCI1713
struct PCI1713_CONFIG
{
	UCHAR NumPC;	                 // Номер компьютера 
	UCHAR NumDevice;		            // Порядковый номер адаптера данного типа в данном РС(биты )
	PCI1713_DEV_CTRL dev_ctrl;    // Тип триггера, IRQ и проч, - Определить для адаптера
	PCI1713_CH_CONFIG ch_conf[32];//Gain,B_U,S_D-определить для каждого канала
};

//ресурсы ADVANTECH AD PCI1716
struct DevicePCI1716
{
	ULONG	BaseMemory;    // базовый адрес памяти Adapters.DmaCh
	ULONG	ulReserv;
	USHORT	BasePort;    // базовый адрес портов ввода-вывода Adapters.PortIO
	USHORT	usReserv;    // порт канала DMA
	UCHAR	FirstChannel; // номер первого сканируемого канала(1-16),если 0, то	1 
	//  Adapters.DmaCh
	UCHAR	nIRQ;         // номер линии запроса прерывания 
	//Adapters.InterruptNum
	USHORT	NumChannel;	 // кол-во задействованных каналов адаптера, если 0, то 16 
	//Adapters.NumCh
};
//настройки канала ADVANTECH AD PCI1716
struct PCI1716_CH_CONFIG //DataBurst
{
	USHORT Gain : 4;	//3! Gain code - 0(20в=+-10),1(10в=0-10|+-5),2(5в),4(2.5в) 8(1.25в). 
	// Gain =5/(Scale*(1+SignBit1) 
	// Пример: Scale= 2.5 для +-5 Gain =1
	// Scale= 2.5 для  0-5в       Gain =2 
	USHORT B_U : 1;	// ~StrDescr.SignBit: 0 = Bipolar->SignBit=1, 1 = uniopolar->SignBit=0,  
	USHORT S_D : 1;	// StrDescr.SubAddr: 0 = single ended, 1 = differential
	USHORT res2 : 2; //резерв
	USHORT res8 : 8;	//reserv
};

//настройки режима ADVANTECH AD PCI1716
struct PCI1716_DEV_CTRL
{
	USHORT SW : 1;  //      Software trigger enable.Adapters.DmaPort&1
	USHORT PACER : 1;  //   Pacer trigger enable.Adapters.DmaPort&2
	USHORT EXT : 1;  //     External trigger enable.Adapters.DmaPort & 4
	USHORT GATE : 1;  //    External trigger gate function enable.Adapters.DmaPort&8
	USHORT IRQ_EN : 1;  //  Interrupt enable Adapters.DmaPort & 16
	USHORT ONE_FH : 1;  //  0 = interrupt after one data conversion, 1 = FIFO half full.Adapters.DmaPort & 32
	USHORT reserv10 : 10;  //
};

//настройка платы ADVANTECH AD PCI1716
struct PCI1716_CONFIG
{
	UCHAR NumPC;	// Номер компьютера 
	UCHAR NumDevice;		// Порядковый номер адаптера данного типа в данном РС(биты )
	PCI1716_DEV_CTRL dev_ctrl;   // Тип триггера, IRQ и проч, - Определить для адаптера
	PCI1716_CH_CONFIG ch_conf[16];//Gain,B_U,S_D-определить для каждого канала
};

//определение характеристик параметра
//привязка параметра к устройству
struct DeviceInfo
{
	ULONG bit1_23 : 23;	// заполнение младших разрядов (биты 1-26)
	ULONG NumDevice : 3;	 // Порядковый номер адаптера данного типа в данном РС(биты 24-26)
	ULONG TypeDevice : 6;	 // Тип адаптера (биты 27-32)
	//дополнительные 32 бита
	ULONG bit1_28 : 28;	// Заполнение разрядов (биты 1-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29,30,31,32)

	ULONG reserv;    		       // заполнение старших разрядов ()
};

//определение параметра для TX6_PC_C Саша
struct ID_TX6_PC_C
{
	ULONG InOut : 1;	// признак входной-1/выходной-0 (бит 1)
	ULONG bit2_6 : 5;	// заполнение разрядов
	ULONG NumWord : 5;	// номер слова (биты 7-11) NumWord = 0...31
	ULONG SubAddr : 5;	// подадрес (биты 12-16)   SubAddr = 1...30
	ULONG mtDirection : 2;	// направление передачи параметра, который мониторится: 1-прием, 0-передача, 2 - ТЛМ-170, 3 - динамическое вкл/выкл ОУ (биты 17-18)
	ULONG AddrRT : 5; 	// Адрес ОУ (биты 19-23)       AddrRT = 0...31
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24-26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27-32)

	ULONG LoBit : 5; 	// младмий бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; 	// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG NumBatch : 16;	// сквозной номер пакета к которому относится параметр  (биты 13-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29,32)

	union
	{
		ULONG d32;  // Значение параметра, для случая, когда он занимает два 16-ти разр. слова (HiBit>15)
		USHORT d16[2];// Значение 16-ти разрядного параметра.  (в [0]-младшая часть d32,в [1]-старшая часть d32)
	} Data;

};
//Для управления вкл/выкл ОУ необходимо к адаптеру привязать выходной параметр с адресом ОУ, которым необходимо управлять и mtDirection=3.
//При значении этого параметра =1 - ОУ активно на шине.
//При значении этого параметра =0 - ОУ выключено.

//определение параметра для PC429_3_88
struct ID_PC429_3_88
{
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG AddrFromData : 1;		// =0 адрес берется из поля Address, =1 адрес берется из младших 8 бит поля Data (биты 2)
	ULONG Gap : 1;		// Признак выдачи слова (бит 3), =1: выдать слово, =0: сформировать пробел на месте слова
	ULONG Address : 8;		// Заполнение младших разрядов (биты 4-11)
	ULONG NumWord : 8;  // Порядковый номер слова в канале (биты 12-19)
	ULONG NumChannel : 4;  // Номер канала адаптера (биты 20-23)
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;  // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;  // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	 // 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	 // 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16; // Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;	 // Номер компьютера (биты 29,30,31,32)

	ULONG Data;             	// Значение параметра (биты 1-32)
};

//определение параметра для PC429_3_88
struct ID_PC429_4_xx
{
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG AddrFromData : 1;		// =0 адрес берется из поля Address, =1 адрес берется из младших 8 бит поля Data (биты 2)
	ULONG Gap : 1;		// Признак выдачи слова (бит 3), =1: выдать слово, =0: сформировать пробел на месте слова
	ULONG Address : 8;		// Заполнение младших разрядов (биты 4-11)
	ULONG NumWord : 8;  // Порядковый номер слова в канале (биты 12-19)
	ULONG NumChannel : 4;  // Номер канала адаптера (биты 20-23)
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;  // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;  // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	 // 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	 // 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16; // Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;	 // Номер компьютера (биты 29,30,31,32)

	ULONG Data;             	// Значение параметра (биты 1-32)
};

//определение параметра для SPECIAL
// адрес 0x0 зарезервирован:
//			 входной параметер: для получения времени ведущих часов текущего компьютера из RefMem 
//			 входной параметер: для управления системным генератором звука
//  Источником входных параметров с адресами <> 0 может быть, только сценарий
//  Источником выходных параметров с адресами <> 0 могут быть, модели или сценарий,
//  причем если параметр прописан в модели, отработка его в сценарии заблокирована
//
struct ID_SPECIAL {
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG Address : 22; // адрес (биты 2-23) 
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;		// младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;		// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;		// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;		// 2-й знаковый бит (бит 12)
	ULONG TypePack : 8;		// Способ упаковки данных (биты 13-20)
	// ----------------------------------------------------------------------------------------------
	// TypePack   Тип            Размер     Описание
	// ----------------------------------------------------------------------------------------------
	//				0			 unknow														4     при упаковке использовать поля LoBit,HiBit,SignBit1,SignBit2)
	//				1				int															  4					signed, signed int System dependent
	//				2				unsigned int						  4					unsigned System dependent
	//				3				__int8												  1					char, signed char –128 to 127
	//				4				__int16											  2					short, short int, signed short int –32,768 to 32,767
	//				5				__int32											  4					signed, signed int –2,147,483,648 to 2,147,483,647
	//				6				__int64											  8					none –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
	//				7				char														  1					signed char –128 to 127
	//				8				unsigned char					  1					none 0 to 255
	//				9				short													  2					short int, signed short int –32,768 to 32,767
	//			10				unsigned short				  2					unsigned short int 0 to 65,535
	//			11				long														  4					long int, signed long int –2,147,483,648 to 2,147,483,647
	//			12				unsigned long					  4					unsigned long int 0 to 4,294,967,295
	//			13				enum														  *					none Same as int
	//			14				float													  4					none 3.4E +/- 38 (7 digits)
	//			15				double												  8					none 1.7E +/- 308 (15 digits)
	//			16				long double							 10					none 1.2E +/- 4932 (19 digits)
	// ----------------------------------------------------------------------------------------------
	ULONG bit13_28 : 8;		// Заполнение разрядов (биты 21-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29,30,31,32)

	union
	{
		float flD;								// Значение параметра
		LONG lD;										// Значение параметра
		ULONG ulD;								// Значение параметра
		SHORT sD[2];						// Значение параметра
		USHORT usD[2];				// Значение параметра
		CHAR cD[4];							// Значение параметра
		UCHAR ucD[4];	    // Значение параметра
	} Data;

};

//определение параметра для АЦП LCARD_761  // Таня
struct ID_LCARD_761 {
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG bit2_18 : 17;	// not used (биты 2-18)
	ULONG NumChannel : 5;		// DataBurst.NumLine - Номер канала адаптера (биты 19,20,21,22,23)
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;		// младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;		// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;		// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;		// 2-й знаковый бит (бит 12)
	ULONG reserv : 16;		// not used
	ULONG NumPC : 4;		// Номер компьютера (биты 29-32)

	union
	{
		ULONG d32;  // Значение параметра, для случая, когда он занимает два 16-ти разр. слова (HiBit>15)
		USHORT d16[2];// Значение 16-ти разрядного параметра.  (в [0]-младшая часть d32,в [1]-старшая часть d32)
	}  Data;
};
//определение параметра для ЦАП LCARD_1208   // Таня
struct ID_LCARD_1208 {
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG fSin : 2;		// =StrDescr.SubAddr (0-simple signal,1-амплитуда синусоиды, 2 - фаза сигнала) (биты 2-3)
	ULONG Address : 8;		// =StrDescr.Address (1-8) - для TTL-адрес(биты 4-11)
	//	для SimpleDAC -не используется
	ULONG bit3_19 : 8;		// (биты 12-19)
	ULONG NumChannel : 4;		// =StrDescr.NumLine-Номер канала адаптера (биты 20-23)
	// каналы 1-8 -ЦАП
	// каналы 9,10-ТТЛ
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24-26)
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;		// младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;		// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;		// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;		// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	// (биты 13-28) 
	ULONG NumPC : 4;		// Номер компьютера (биты 30-32)
	union
	{
		ULONG d32;     // Значение параметра, для случая, когда он занимает два 16-ти разр. слова (HiBit>15)
		USHORT d16[2]; //  
		float  phase;  // фаза в рад.для фоновой синусоиды
	}  Data;
};

//определение параметра для адаптера ОЛ   // Таня

struct ID_OL {
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG NumWord : 10;	// StrDescr.NumWine (0-23,без пропусков!) 2-11
	ULONG reserv : 12;	// Not used  (биты 12-23)
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;		// младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;		// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;		// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;		// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29-32)

	ULONG Data;					// Значение параметра (биты 1-32)
};

//определение параметра для адаптера Astra   // Таня
struct ID_ASTRA {
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG Address : 18;	// StrDescr.Address (биты 2-19)-18 бит 
	ULONG Update : 1;		// Данные обновлены (бит 20)
	ULONG reserv : 3;		// Not used  (биты 21-23)
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;		// младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;		// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;		// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;		// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29-32)

	ULONG Data;					// Значение параметра (биты 1-32)
};

//определение параметра для адаптера Astra_BL   // Таня
struct ID_ASTRA_BL {
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG Address : 18;	// StrDescr.Address (биты 2-19)-18 бит 
	ULONG False : 1;		// Признак сбоя данных (бит 20)
	ULONG NumWord : 3;		// 0, 1..4 StrDescr.NumWord (биты 21-23)-номер считываемой записи для отладки, c 1, 0 - штатное считывание 
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26), в БД - с 1, из IPC - c 0.
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;		// младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;		// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;		// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;		// 2-й знаковый бит (бит 12)
	ULONG reserv : 16;	// Счётчик слова (биты 13-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29-32)

	ULONG Data;					// Значение параметра (биты 1-32)
};
//определение параметра для PCI_1753  // Юра
struct ID_PCI_1753 {
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG bit2_14 : 13;	// заполнение младших разрядов (биты 2-14)
	ULONG Inversion : 1;		// признак инверсии данных перед выводом/вводом (бит 15)
	ULONG Address : 3;	 // адрес(биты 16-18) (номер бита в порте ввода-вывода)
	ULONG NumChannel : 5;	 // Номер канала адаптера (биты 19-23) (Порты ввода-вывода пронумерованные насквозь для адаптера)
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32

	ULONG LoBit : 5; // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29,30,31,32)

	ULONG Data : 1; // значение параметра (бит 1)
	ULONG reserv : 31;// резерв для выравнивания (биты 2-32)
};

//определение параметра для VMIC5587 // Саша
struct ID_VMIC5587 {
	ULONG InOut : 1;	// признак входной-1/выходной-0 (бит 1)
	ULONG Address : 22;// адрес (биты 2-23)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;	// Тип адаптера = 15 (биты 27-32)

	ULONG Type_INT : 2;	//Тип прерывания, которое надо сгенерировать
	//	GEN_INT_RESET   0
	//	GEN_INT1        1
	//	GEN_INT2        2
	//	GEN_INT3        3
	// берется из поля LoBit
	ULONG INT_DATA : 10;// ДАННЫЕ, посылаемые с прерыванием. Берется из поля HiBit
	ULONG TypePack : 8;	// Способ упаковки данных (биты 13-20).  Берется из информации получаемой из ShMem
	// результат записывается в поле NumLowBit
	// ----------------------------------------------------------------------------------------------
	// TypePack   Тип            Размер     Описание
	// ----------------------------------------------------------------------------------------------
	// 0			 unknow														4     при упаковке использовать поля LoBit,HiBit,SignBit1,SignBit2,NumLowBit)
	// 1				int															  4					signed, signed int System dependent
	// 2				unsigned int						  4					unsigned System dependent
	// 3				__int8												  1					char, signed char –128 to 127
	// 4				__int16											  2					short, short int, signed short int –32,768 to 32,767
	// 5				__int32											  4					signed, signed int –2,147,483,648 to 2,147,483,647
	// 6				__int64											  8					none –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
	// 7				char														  1					signed char –128 to 127
	// 8				unsigned char					  1					none 0 to 255
	// 9				short													  2					short int, signed short int –32,768 to 32,767
	// 10				unsigned short				  2					unsigned short int 0 to 65,535
	// 11				long														  4					long int, signed long int –2,147,483,648 to 2,147,483,647
	// 12				unsigned long					  4					unsigned long int 0 to 4,294,967,295
	// 13				enum														  *					none Same as int
	// 14				float													  4					none 3.4E +/- 38 (7 digits)
	// 15				double												  8					none 1.7E +/- 308 (15 digits)
	// 16				long double							 10					none 1.2E +/- 4932 (19 digits)
	// ----------------------------------------------------------------------------------------------
	ULONG DestNId : 8;	// NID узла, в котором надо сгенерировать прерывание (значения 1...254)
	// или 0, если не генерировать или 255, если во всех узлах сразу.
	// Берется из поля CheckWord
	ULONG NumPC : 4;	// Номер компьютера (биты 29,30,31,32)

	union
	{
		float f32bit;	// Значение параметра 32bit
		ULONG u32bit;		// Значение параметра 32bit
		USHORT u16bit;		// Значение параметра 16bit
		UCHAR u8bit;	    // Значение параметра 8bit
	} Data;
};

//определение параметра для VMIC5565 Саша
struct ID_VMIC5565 {
	ULONG InOut : 1;	// признак входной-1/выходной-0 (бит 1)
	ULONG Type_INT : 3;	//Тип прерывания, которое надо сгенерировать (бит 2-4)
	//GEN_INT_RESET_5565   0 //Reset Node Request 
	//GEN_INT1_5565        1 //Network Interrupt 1
	//GEN_INT2_5565        2 //Network Interrupt 2
	//GEN_INT3_5565        3 //Network Interrupt 3
	//GEN_INT_INIT_5565    7 //Network Initialized Interrupt
	// берется из поля LoBit
	ULONG TypePack : 8;	// Способ упаковки данных (биты 5-12).  Берется из информации получаемой из ShMem
	// результат записывается в поле NumLowBit
	ULONG DestNId : 8;	// (биты 13-20) NID узла, в котором надо сгенерировать прерывание (значения 1...254)
	// или 0, если не генерировать или 255, если во всех узлах сразу.
	// Берется из поля CheckWord
	ULONG reserv3 : 3; // резерв (биты 21-23). 
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;	// Тип адаптера = 15 (биты 27,28,29,30,31,32)

	ULONG Address : 27;// адрес параметра в RMN (биты 1-27)
	ULONG reserv28 : 1;	// резерв (бит 28). 
	ULONG NumPC : 4;	// Номер компьютера (биты 29,30,31,32)
	union
	{
		float f32bit;	// Значение параметра 32bit
		ULONG u32bit;		// Значение параметра 32bit или данные для прерывания, если DestNId = 1...255
		USHORT u16bit;		// Значение параметра 16bit
		UCHAR u8bit;	    // Значение параметра 8bit
	} Data;
};

//определение параметра для IPK1  // Юра
struct ID_IPK1 {
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG bit2_23 : 22; // Заполнение разрядов (биты 2-23)
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32)

	ULONG LoBit : 5; // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29,30,31,32)

	ULONG  Data;              // Значение параметра (биты 1-32)
};

//определение параметра для ADVANTECH AD PCI1713  // Таня
struct ID_PCI1713 {
	ULONG InOut : 1; 	// признак входной-1/выходной-0 (бит 1)
	ULONG bit2_9 : 8; // Заполнение разрядов (биты 2-9)
	ULONG SignShift : 1;	 // ' Знак смещения 0: положит. 1:отриц.
	ULONG Shift : 8;	// ' Смещение 0 на входе в разрядных единицах
	ULONG NumChannel : 5;  // Address c 1- Номер канала адаптера (биты 19-23) (Порты ввода-вывода пронумерованные насквозь для адаптера)
	ULONG NumDevice : 3;		// c 1- Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// 20 Тип адаптера (биты 27,28,29,30,31,32)

	ULONG LoBit : 5; // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29,30,31,32)

	ULONG Data;      // значение параметра (бит 1-32) -12 бит
};

//определение параметра для ADVANTECH AD PCI1716  // Таня
struct ID_PCI1716 {
	ULONG InOut : 1; 	// признак входной-1/выходной-0 (бит 1)
	ULONG bit2_18 : 17;	// резерв (биты 2-18)
	ULONG NumChannel : 5;  // Address c 1- Номер канала адаптера (биты 19-23) (Порты ввода-вывода пронумерованные насквозь для адаптера)
	ULONG NumDevice : 3;		// c 1- Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// 20 Тип адаптера (биты 27,28,29,30,31,32)

	ULONG LoBit : 5; // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29,30,31,32)

	ULONG Data; // значение параметра (бит 1-32) -12 бит
};

//определение параметра для ЦУС БМК  // Саша
struct ID_CusBmk {

	ULONG InOut : 1;	// признак входной-1/выходной-0 (бит 1)
	ULONG bit2_6 : 5;	// заполнение разрядов
	ULONG bit7_11 : 5;	// номер слова (биты 7-11) 
	ULONG bit12_15 : 4;	// подадрес (биты 12-15)   
	ULONG Addr : 8; // Адрес параметра (биты 16-23)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24-26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27-32)

	ULONG LoBit : 5; 	// младмий бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; 	// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	//   (биты 13-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29-32)

	USHORT Data;			// Значение 16-ти разрядного параметра
	USHORT Rez;
};

// определение параметра для ЦАП PCIxyzDAC
struct ID_PCIxyzDAC {
	ULONG InOut : 1;	// признак входной-1/выходной-0 (бит 1)
	ULONG NumChannel : 3; // номер канала адаптера (нумерация с 1)(биты 2,3,4)
	ULONG bit5_23 : 19;// пусто (биты 5-23)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС (начиная с 1)(биты 24,25,26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27-32)

	ULONG LoBit : 5; // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;// пусто (биты 13-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29,30,31,32)

	USHORT Data;				// Значение 16-ти разрядного параметра
	USHORT bit16_32;			// пусто
};

// определение параметра для КМБО PCI_1705
struct ID_PCI1705 {
	ULONG InOut : 1;  // признак входной-1/выходной-0 (бит 1)
	ULONG bit2_9 : 8;  // Резерв
	ULONG Address : 8;	 // адрес оконечного устройства (от 1 до 255)
	ULONG NumWord : 6;	 // номер слова данных (начиная с 0)
	ULONG NumDevice : 3;	 // Порядковый номер адаптера данного типа в данном РС(начиная с 0)(биты 24,25,26)
	ULONG TypeDevice : 6;	 // Тип адаптера (биты 27-32)

	ULONG LoBit : 5;  // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;  // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	 // 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	 // 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 20; // 


	ULONG Data; // значение параметра 
};
// определение параметра для ЦАП pciSPI
struct ID_pciSPI {
	ULONG InOut : 1;	// признак входной-1/выходной-0 (бит 1)
	ULONG Address : 3; // адрес ОУ (нумерация с 1)(биты 2,3,4)
	ULONG bit5_23 : 19;// пусто (биты 5-23)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС (начиная с 1)(биты 24,25,26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27-32)

	ULONG LoBit : 5; // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;// пусто (биты 13-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29,30,31,32)

	USHORT Data;				// Значение 16-ти разрядного параметра, задействовано только с 0-4 бит.
	USHORT bit16_32;			// пусто
};

// определение параметров для МТВС
struct ID_MTVS {
	ULONG InOut : 1;	 // признак входной-1/выходной-0 (бит 1)
	ULONG Address : 4; // адрес МТВС (0х08) (биты 2,3,4,5)
	ULONG bit5_23 : 18;// пусто (биты 6-23)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС (начиная с 1)(биты 24,25,26)
	ULONG TypeDevice : 6;	// Тип адаптера = 30 (биты 27-32)

	ULONG LoBit : 5; // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;// пусто (биты 13-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29,30,31,32)

	union
	{
		USHORT Data;		// Значение 16-ти разрядного параметра
		unsigned char usD[2];   // 1 байт данных
	}Data;
	USHORT bit16_32;			// пусто
};


struct ID_PCADS05
{
	ULONG InOut : 1;	// признак входной-1/выходной-0 (бит 1)
	ULONG AddrFromData : 1;	// =0 адрес берется из поля Address, =1 адрес берется из младших 8 бит поля Data (бит 2)
	ULONG Gap : 1;	// Признак выдачи слова (бит 3), =1: выдать слово, =0: сформировать пробел на месте слова
	ULONG Address : 8;	// Заполнение младших разрядов (биты 4-11)
	ULONG NumWord : 8;	// Порядковый номер слова в канале (биты 12-19)
	ULONG bit20_23 : 4;	// резерв (биты 20-23)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;	// младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;	// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG NumChannel : 7;	// Номер канала адаптера (биты 13-19)
	ULONG bit20_28 : 9;	// Заполнение младших разрядов (биты 20-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29,30,31,32)

	ULONG Data;					// Значение параметра (биты 1-32)
};

struct ID_PCADS05K
{
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG bit2_23 : 22; // Заполнение разрядов (биты 2-23)
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32)

	ULONG LoBit : 5; // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29,30,31,32)

	ULONG Data;					// Значение параметра (биты 1-32)
};


struct ID_PCADS05RK
{
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG Channel : 6;		// Номер канала внутри модуля РК
	ULONG Logic : 1;		// Значение
	// Поле адресс используется для определения типа данных для ФПИ
	// 0 - заносятся данные для РК
	// 1 - заносятся данные для формирования точек ФПИ
	// 2 - заносятся данные для управления ФПИ, и установки счетчика
	// Так же поле Adress используется для определения источника данных по каналу РК
	ULONG Address : 2;		// Используется для отличия данных от управления в РК и ФПИ
	ULONG bit11_23 : 13;		// Заполнение разрядов (биты 11-23)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;		// младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;		// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;		// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;		// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29,30,31,32)

	//Описание структуры data 
	// Значение РК в канале задается переменной с Address = 0
	// бит [0] - выходное значение. 
	// Управление источником данных для выходного сигнала РК происходит следующим образом Address = 1
	// бит [0] - значение источника входных данных. 
	// 0 - исходящий сигнал определяется значением данных переданных по Address = 0
	// 1 - исходящий сигнал равен входящему сигналe/лам привязанному к данному каналу

	// Отличие между источником данных для выходного сигнала РК и передачей точек для ФПИ служит поле mode, передаваемое при вызове функции vbCreate_PCADS05RK
	// Если осуществляеся передача точек для ФПИ, то упаковка происходит слудеющим образом Address = 1
	// биты [31…28] – номер ключевой точки (от 0 до 15);
	// бит  [27] – выставляемый уровень;
	// биты [26…0] – интервал времени(в мкс) до выставления требуемого уровня(от 0 до 134с (227мкс)).

	// Если осуществляется передача данных для управления ФПИ, то данные формираются следующим образом  Address = 2
	// биты [31-16] - Счетчик ФПИ. Учитывается только в том случае, если режим передачи данных на ФПИ = 2
	// бит [4] - Настройка ФПИ blockCounter. Учитывается только в том случае, если режим передачи данных на ФПИ = 3
	// 0 - Счетчик ФПИ учитывается при записи. 1 - Счетчик ФПИ не учитывается при записи.
	// бит [3] - Настройка ФПИ extControl. Учитывается только в том случае, если режим передачи данных на ФПИ = 3
	// 0 - ФПИ не зависит от внешнего источника. 1 - ФПИ зависит от внешнего источника.
	// бит [2] - Настройка ФПИ enable. Учитывается только в том случае, если режим передачи данных на ФПИ = 3
	// 0 - ФПИ выключен. 1 - ФПИ включен.
	// бит [0-1] - Выставляется режим передачи данных на ФПИ:
	// 0 - на ФПИ не передаются никакие данные.
	// 1 - на ФПИ передаются ключевые точки
	// 2 - на ФПИ передается счетчик
	// 3 - на ФПИ передаются настройки
	ULONG Data;				// Значение параметра (биты 1-32)
};

struct ID_PCADS06RTM
{
	ULONG InOut : 1;	// признак входной-1/выходной-0 (бит 1)
	ULONG AddrFromData : 1;	// =0 адрес берется из поля Address, =1 адрес берется из младших 8 бит поля Data (бит 2)
	ULONG Gap : 1;	// Признак выдачи слова (бит 3), =1: выдать слово, =0: сформировать пробел на месте слова
	ULONG Address : 8;	// Заполнение младших разрядов (биты 4-11)
	ULONG NumWord : 8;	// Порядковый номер слова в канале (биты 12-19)
	ULONG bit20_23 : 4;	// резерв (биты 20-23)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;	// младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;	// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG NumChannel : 8;	// Номер канала адаптера (биты 13-20)
	ULONG bit21_28 : 8;	// Заполнение младших разрядов (биты 21-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29,30,31,32)

	ULONG Data;					// Значение параметра (биты 1-32)
};

struct ID_PCADS06K
{
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG bit2_23 : 22; // Заполнение разрядов (биты 2-23)
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32)

	ULONG LoBit : 5; // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29,30,31,32)

	ULONG Data;					// Значение параметра (биты 1-32)
};

struct ID_PCADS06RK
{
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG Channel : 8;		// Номер канала внутри модуля РК (бит 2-9)
	ULONG Logic : 1;		// Значение (бит 10)
	// Поле адресс используется для определения типа данных для ФПИ
	// 0 - заносятся данные для РК
	// 1 - заносятся данные для формирования точек ФПИ
	// 2 - заносятся данные для управления ФПИ, и установки счетчика
	// Так же поле Adress используется для определения источника данных по каналу РК
	ULONG Address : 2;		// Используется для отличия данных от управления в РК и ФПИ (бит 11-12)
	ULONG bit13_23 : 11;		// Заполнение разрядов (биты 13-23)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24-26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;		// младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;		// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;		// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;		// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29,30,31,32)

	//Описание структуры data 
	// Значение РК в канале задается переменной с Address = 0
	// бит [0] - выходное значение. 
	// Управление источником данных для выходного сигнала РК происходит следующим образом Address = 1
	// бит [0] - значение источника входных данных. 
	// 0 - исходящий сигнал определяется значением данных переданных по Address = 0
	// 1 - исходящий сигнал равен входящему сигналe/лам привязанному к данному каналу

	// Отличие между источником данных для выходного сигнала РК и передачей точек для ФПИ служит поле mode, передаваемое при вызове функции vbCreate_PCADS05RK
	// Если осуществляеся передача точек для ФПИ, то упаковка происходит слудеющим образом Address = 1
	// биты [31…28] – номер ключевой точки (от 0 до 15);
	// бит  [27] – выставляемый уровень;
	// биты [26…0] – интервал времени(в мкс) до выставления требуемого уровня(от 0 до 134с (227мкс)).

	// Если осуществляется передача данных для управления ФПИ, то данные формираются следующим образом  Address = 2
	// биты [31-16] - Счетчик ФПИ. Учитывается только в том случае, если режим передачи данных на ФПИ = 2
	// бит [4] - Настройка ФПИ blockCounter. Учитывается только в том случае, если режим передачи данных на ФПИ = 3
	// 0 - Счетчик ФПИ учитывается при записи. 1 - Счетчик ФПИ не учитывается при записи.
	// бит [3] - Настройка ФПИ extControl. Учитывается только в том случае, если режим передачи данных на ФПИ = 3
	// 0 - ФПИ не зависит от внешнего источника. 1 - ФПИ зависит от внешнего источника.
	// бит [2] - Настройка ФПИ enable. Учитывается только в том случае, если режим передачи данных на ФПИ = 3
	// 0 - ФПИ выключен. 1 - ФПИ включен.
	// бит [0-1] - Выставляется режим передачи данных на ФПИ:
	// 0 - на ФПИ не передаются никакие данные.
	// 1 - на ФПИ передаются ключевые точки
	// 2 - на ФПИ передается счетчик
	// 3 - на ФПИ передаются настройки
	ULONG Data;				// Значение параметра (биты 1-32)
};

struct ID_PCADSv7RTM	//Структура подходит для адаптеров типа PCADSv7RTMin и PCADSv7RTMout
{
	ULONG InOut : 1;	// признак входной-1/выходной-0 (бит 1)
	ULONG AddrFromData : 1;	// =0 адрес берется из поля Address, =1 адрес берется из младших 8 бит поля Data (бит 2)
	ULONG Gap : 1;	// Признак выдачи слова (бит 3), =1: выдать слово, =0: сформировать пробел на месте слова
	ULONG Address : 8;	// Заполнение младших разрядов (биты 4-11)
	ULONG NumWord : 8;	// Порядковый номер слова в канале (биты 12-19)
	ULONG bit20_23 : 4;	// резерв (биты 20-23)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;	// младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;	// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG NumChannel : 6;	// Номер канала адаптера (биты 13-18)	Нам нужно именно 64 канала, т.к. с [33 по 64] канал - каналы подмены
	ULONG bit19_28 : 10;	// Заполнение младших разрядов (биты 19-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29,30,31,32)

	ULONG Data;					// Значение параметра (биты 1-32)
};
struct ID_PCADSv7RK		//Структура подходит для адаптеров типа PCADSv7RKin и PCADSv7RKout
{
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG Channel : 6;		// Номер канала внутри модуля РК (бит 2-7)
	ULONG Logic : 1;		// Значение (бит 8)
	// Поле адресс используется для определения типа данных для ФПИ
	// 0 - заносятся данные для РК
	// 1 - заносятся данные для формирования точек ФПИ
	// 2 - заносятся данные для управления ФПИ, и установки счетчика
	// Так же поле Adress используется для определения источника данных по каналу РК
	ULONG Address : 2;		// Используется для отличия данных от управления в РК и ФПИ (бит 9-10)
	ULONG Line : 4;			//Номер линии передачи данных [0..6] - входные, [7..13] - выходные
	ULONG bit15_23 : 9;		// Заполнение разрядов (биты 11-23)
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24-26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27-32)

	ULONG LoBit : 5;		// младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5;		// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;		// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;		// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29,30,31,32)

	//Описание структуры data 
	// Значение РК в канале задается переменной с Address = 0
	// бит [0] - выходное значение. 
	// Управление источником данных для выходного сигнала РК происходит следующим образом Address = 1
	// бит [0] - значение источника входных данных. 
	// 0 - исходящий сигнал определяется значением данных переданных по Address = 0
	// 1 - исходящий сигнал равен входящему сигналe/лам привязанному к данному каналу

	// Отличие между источником данных для выходного сигнала РК и передачей точек для ФПИ служит поле mode, передаваемое при вызове функции vbCreate_PCADS05RK
	// Если осуществляеся передача точек для ФПИ, то упаковка происходит слудеющим образом Address = 1
	// биты [31…28] – номер ключевой точки (от 0 до 15);
	// бит  [27] – выставляемый уровень;
	// биты [26…0] – интервал времени(в мкс) до выставления требуемого уровня(от 0 до 134с (227мкс)).

	// Если осуществляется передача данных для управления ФПИ, то данные формираются следующим образом  Address = 2
	// биты [31-16] - Счетчик ФПИ. Учитывается только в том случае, если режим передачи данных на ФПИ = 2
	// бит [4] - Настройка ФПИ blockCounter. Учитывается только в том случае, если режим передачи данных на ФПИ = 3
	// 0 - Счетчик ФПИ учитывается при записи. 1 - Счетчик ФПИ не учитывается при записи.
	// бит [3] - Настройка ФПИ extControl. Учитывается только в том случае, если режим передачи данных на ФПИ = 3
	// 0 - ФПИ не зависит от внешнего источника. 1 - ФПИ зависит от внешнего источника.
	// бит [2] - Настройка ФПИ enable. Учитывается только в том случае, если режим передачи данных на ФПИ = 3
	// 0 - ФПИ выключен. 1 - ФПИ включен.
	// бит [0-1] - Выставляется режим передачи данных на ФПИ:
	// 0 - на ФПИ не передаются никакие данные.
	// 1 - на ФПИ передаются ключевые точки
	// 2 - на ФПИ передается счетчик
	// 3 - на ФПИ передаются настройки
	ULONG Data;				// Значение параметра (биты 1-32)
};
struct ID_iMKIO
{
	ULONG InOut : 1;	// признак входной-1/выходной-0 (бит 1)
	ULONG Bus : 1;		// номер шины (бит 2)
	ULONG bit3_5 : 3;	// заполнение разрядов (биты 3-5)
	ULONG NumWord : 5;	// номер слова (биты 6-10) NumWord = 0...31
	ULONG SubAddr : 5;	// подадрес (биты 11-15)   SubAddr = 1...30
	ULONG mtDirection : 3;	// направление передачи параметра, который мониторится: 0-на ОУ, 1-На Шину, 2 - задание ответного слова 3 - динамическое вкл/выкл ОУ (биты 16-18)
	ULONG AddrRT : 5; 	// Адрес ОУ (биты 19-23)       AddrRT = 0...31
	ULONG NumDevice : 3;	// Порядковый номер адаптера данного типа в данном РС(биты 24-26)
	ULONG TypeDevice : 6;	// Тип адаптера (биты 27-32)

	ULONG LoBit : 5; 	// младмий бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; 	// старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	// (биты 13-28)
	ULONG NumPC : 4;	// Номер компьютера (биты 29,32)

	union
	{
		ULONG d32;  // Значение параметра, для случая, когда он занимает два 16-ти разр. слова (HiBit>15)
		USHORT d16[2];// Значение 16-ти разрядного параметра.  (в [0]-младшая часть d32,в [1]-старшая часть d32)
	} Data;
};

// Общие поля в глобальных параметрах для всех адаптеров
struct ParameterInfo {
	ULONG InOut : 1;		// признак входной-1/выходной-0 (бит 1)
	ULONG bit2_23 : 22; // Заполнение разрядов (биты 2-23)
	ULONG NumDevice : 3;		// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
	ULONG TypeDevice : 6;		// Тип адаптера (биты 27-32)

	ULONG LoBit : 5; // младший бит параметра (с 1-го) (биты 1-5)
	ULONG HiBit : 5; // старший бит параметра (с 1-го) (биты 6-10)
	ULONG SignBit1 : 1;	// 1-й знаковый бит (бит 11)
	ULONG SignBit2 : 1;	// 2-й знаковый бит (бит 12)
	ULONG bit13_28 : 16;	// Заполнение младших разрядов (биты 13-28)
	ULONG NumPC : 4;		// Номер компьютера (биты 29,30,31,32)

	union
	{
		float flD;								// Значение параметра (биты 1-24) и адреса (биты 25-32)
		ULONG ulD;								// Значение параметра (биты 1-24) и адреса (биты 25-32)
		USHORT usD[2];				// Значение параметра (биты 1-24) и адреса (биты 25-32)
		UCHAR ucD[4];	    // Значение параметра (биты 1-24) и адреса (биты 25-32)
	} Data;

};

//определение характеристик параметра
union ID_Parameter
{
	ULONG              FullParam[3]; // массив из трех 32разрядных параметров
	DeviceInfo         DevInfo;      // привязка параметра к устройству
	ParameterInfo					 ParamInfo;				// Общие битовые поля
	ID_SPECIAL         special;						// определение параметра для SPECIAL (вирт.устройство)
	ID_TX6_PC_C        Tx6_pc;       // определение параметра для TX6_PC_C
	ID_PC429_3_88      pc429;        // определение параметра для PC429_3_88
	ID_PC429_4_xx      pc429_4;      // определение параметра для PC429_4_xx
	ID_PCI_1753        pci1753;      // определение параметра для PCI_1753
	ID_ASTRA           Astra;        // определение параметра для Астры
	ID_VMIC5587	     		vmic5587;		   // определение параметра для VMIC5587
	ID_VMIC5565				    vmic5565;		   // определение параметра для VMIC5565
	ID_IPK1            ipk1;				     // определение параметра для IPK1
	ID_PCI1713				     pci1713;	     // определение параметра для PCI_1713
	ID_PCI1724				     pci1724;		    // определение параметра для PCI_1724
	ID_PCI1723				     pci1723;		    // определение параметра для PCI_1723
	ID_CusBmk			       cus_bmk; 		   // определение параметра для ЦУС БМК
	ID_PCI1716				     pci1716;	     // определение параметра для PCI_1716
	ID_ASTRA_BL        Astra_BL;     // определение параметра для Астры BL - чтение блоков
	ID_PCIxyzDAC       xyzDAC;       // определение параметра для ЦАП xyzDAC
	ID_PCI1705         KMBO_1705;    // определение параметра для КМБО PCI_1705
	ID_pciSPI          pci_SPI;      // определение параметра для ЦАП pciSPI
	ID_MTVS			         rs485mtvs;    // определение параметра для МТВС управляемого через RS485
	ID_PCADS05	      		PCADS05;		   	// определение параметра для PCADS05 RTM
	ID_PCADS05K		      PCADS05K;				 // определение параметра для PCADS05 комутатора
	ID_PCADS05RK       PCADS05RK;    // определение параметра для PCADS05 разовые команды
	ID_PCADS06RTM	     PCADS06RTM;		 // определение параметра для PCADS06 RTM
	ID_PCADS06K		      PCADS06K;				 // определение параметра для PCADS06 комутатора
	ID_PCADS06RK       PCADS06RK;    // определение параметра для PCADS06 разовые команды
	ID_PCADSv7RTM		PCADSv7RTM;		// определение параметра для PCADSv7 РТМ
	ID_PCADSv7RK	PCADSv7RK;		// определение параметра для PCADSv7 РК
	ID_iMKIO		        	iMKIO;	       // определение параметра для iMKIO1
};

#endif