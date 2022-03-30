//----------------------------------------------------------------------------------
#ifndef MKS_H_INCLUDED
#define MKS_H_INCLUDED
//----------------------------------------------------------------------------------
#include <sys/types.h>
//----------------------------------------------------------------------------------
#define FROM_MKS_HEADER_GLOBAL 	0xAAAB	//Идентификатор сетевого пакета от МКС
#define FROM_MKS_HEADER_ARINC 	0xAAB3	//Тип ИБ  - ARINC429
#define FROM_MKS_HEADER_ADC_SUZ	0xAAB5	//Тип ИБ - АЦП и СУЗ
#define FROM_MKS_HEADER_TIME 	0xAAB8	//Тип ИБ  - ВРЕМЯ НАРАБОТКИ МКС
#define FROM_MKS_HEADER_COM 	0xAAB1	//Тип ИБ  - COM-порт

 #define TO_MKS_HEADER_GLOBAL 	0xAAAA	//Идентификатор сетевого пакета для МКС
 #define TO_MKS_HEADER_ARINC 	0xAAB2	//Тип ИБ  - ARINC429
 #define TO_MKS_HEADER_SUZ	 	0xAAB4	//Тип ИБ  - СУЗ
 #define TO_MKS_HEADER_MFD 		0xAAB0	//Тип ИБ  - COM-порт МФИ левый(правый)
 #define TO_MKS_HEADER_ICW 		0xAAB0	//Тип ИБ  - COM-порт ИКШ
 #define TO_MKS_HEADER_UAP 		0xAAB0	//Тип ИБ  - COM-порт УАП
 #define TO_MKS_HEADER_KI13 	0xAAB0	//Тип ИБ  - COM-порт КИ-13


#define DEF_MFK_TYPE    		0xA // MFI
#define DEF_UAP_TYPE    		0xB // УАП
#define DEF_IKSH_TYPE  			0x13 // ИКШ
#define DEF_KI13_TYPE   		0x18 // КИ - 13

//----------------------------------------------------------------------------------

#pragma pack(push,1)

//	ЗАГОЛОВОК СЕТЕВОГО ПАКЕТА  
typedef struct _PACKET_HEADER {
WORD    Packet_ID;	//Идентификатор сетевого пакета для/от МКС					AAAA(hex)/AAAB(hex)
WORD    Packet_Size;//Размер  сетевого пакета для/от МКС в байтах           	4+размер всех ИБ
} PACKET_HEADER, * PPACKET_HEADER;

//Формат пакета от МКС:

//1.Заголовок сетевого пакета
//2. ИБ ARINC429
//3. ИБ АЦП
//4. ИБ СУЗ
//5. ИБ время наработки МКС
//6. ИБ COM-порт (МФИ левый, МФИ правый, ИКШ)


//ИБ ARINC429
typedef struct _PACKET_FROM_MKS_ARINC {
WORD	Packet_ID;		//Тип ИБ  												AAB3(hex)
WORD  	Packet_Size;	//Размер ИБ в байтах									42
BYTE    NumInputCh;		//Номер входного канала ARINC ( № вх ЛС минус 1 )		0 – 3
BYTE    NumArincWords;	//Количество 32-разрядных слов в канале 				9
DWORD   Word0100;		//слово с адресом 0100(oct)
DWORD   Word0101;		//слово с адресом 0101(oct)
DWORD   Word0102;		//слово с адресом 0102(oct)
DWORD   Word0103;		//слово с адресом 0103(oct)
DWORD   Word0104;		//слово с адресом 0104(oct)
DWORD   Word0105;		//слово с адресом 0105(oct)
DWORD   Word0106;		//слово с адресом 0106(oct)
DWORD   Word0107;		//слово с адресом 0107(oct)
DWORD   Word0110;		//слово с адресом 0110(oct)
} PACKET_FROM_MKS_ARINC, * PPACKET_FROM_MKS_ARINC;

//ИБ АЦП: 
typedef struct _PACKET_FROM_MKS_ADC {
WORD	Packet_ID;		//Тип ИБ  												AAB5 (hex)
WORD  	Packet_Size;	//Размер ИБ в байтах									75
BYTE    TypeInf;		//Тип информации										1
DWORD	DataSize;		//Размер данных от АЦП  в байтах           				66
WORD	Count;			//Счетчик циклов от программы АЦП						переменное
short	Ch[32];			//Код 1-32 ой канал АЦП 								переменное
//FLOAT volt = (code / 32768.) *10.;
} PACKET_FROM_MKS_ADC, * PPACKET_FROM_MKS_ADC;

//ИБ СУЗ:
typedef struct _PACKET_FROM_MKS_SUZ {
WORD	Packet_ID;		//Тип ИБ  												AAB5 (hex)
WORD  	Packet_Size;	//Размер ИБ в байтах									99
BYTE    TypeInf;		//Тип информации										2
DWORD	DataSize;		//Размер данных от СУЗ в байтах           				90
WORD	Count;			//Счетчик циклов от программы СУЗ						переменное

WORD X_RUS_INT[3];        // Положение органов 0-65535
										// [ 0 ]Датчик положения РУС по тангажу: 0 - 65535 (0 - пикирование 0xffff - кабрирование)
										// [ 1 ]Датчик положения РУС по крену: 0 - 65535 (0 - ручка влево  0xffff - ручка вправо)
										// [ 2 ]Датчик положения педалей:  0 - 65535 (0 - левая педаль до упора,0xffff - правая педаль до упора)
WORD X_MET_INT[3]; 		// Положение триммеров 0-65535
										// [ 0 ]Датчик положения триммера танга (АЦП)   0 - 65535 (0 - ручка вперед, 0xffff - ручка назад)
										// [ 1 ]Датчик положения триммера крена (АЦП)  0 - 65535 (0xffff - ручка влево, 0 - ручка вправо)
										// [ 2 ]Датчик положения триммера курса (АЦП)  0 - 65535 (0 - левая педаль вперед,0xffff - правая педаль вперед)
union {
	 struct {
		WORD I_Tng1	: 1;	// Исправность привода 1 по тангажу
		WORD I_Krn1	: 1;	// Исправность привода 1 по крену
		WORD I_Kur1	: 1;	// Исправность привода 1 педалей
		WORD I_Tng2	: 1;	// Исправность привода 2 по тангажу
		WORD I_Krn2	: 1;	// Исправность привода 2 по крену
		WORD I_Kur2	: 1;	// Исправность привода 2 педалей
		WORD I_Vop	: 1;	// Исправность опорного напряжения
		WORD PR_Ust	: 1;	// Выполняется юстировка
		};
	  WORD i;				// Разовые команды СУЗ
	  };
float	P_RUS[3];			// Усилия
float	X_Priv[3][2];		// Текущее положение приводов
float	X_Priv_Zad[3];		// Заданное положение приводов
float	X_RUS[3];			// Положение органов управления в миллиметрах хода
float	X_MET[3]; 			// Положение триммеров в миллиметрах хода
WORD	Res;				// Резерв
} PACKET_FROM_MKS_SUZ, * PPACKET_FROM_MKS_SUZ;

//ИБ ВРЕМЯ НАРАБОТКИ МКС:
typedef struct _PACKET_FROM_MKS_TIME {
WORD	Packet_ID;		//Тип ИБ  												AAB8 (hex)
WORD  	Packet_Size;	//Размер ИБ в байтах									8
DWORD	Time;			//Время наработки МКС в секундах						переменное
} PACKET_FROM_MKS_TIME, * PPACKET_FROM_MKS_TIME;

//ИБ COM-порт МФИ:
typedef struct _PACKET_FROM_MKS_MFD {
WORD	Packet_ID;		//Тип ИБ  												AAB1 (hex)
WORD  	Packet_Size;	//Размер ИБ в байтах									переменное
BYTE	NumberComPort;	//Номер COM-порта										1 – 4
WORD	DataSize;		//Размер данных от  COM-порта   в байтах           		переменное
//	Блок данных от  COM-порта:   	
BYTE	Synhro1;		//1-й Байт синхронизации								0xB0(нех)
BYTE	Synhro2;		//2-й Байт синхронизации								0x3B(нех)
BYTE	Synhro3;		//3-й Байт синхронизации								0x4F(нех)
BYTE	DataSizeWOSyn;	//Длина посылки в байтах без учета синхронизации		7
BYTE	DevType;		//Тип устройства										10
BYTE	DevAddr;		//Адрес устройства										0-левый(1-правый)
BYTE	PacketType;		//Тип пакета											2
BYTE	MFKCode;		//Код нажатой МФК или энкодера							0-нет нажатия,(1-28)-МФК,(29-32)-Энкодеры 
union {
	  struct {
		BYTE EncoderLD	: 2;//Энкодер Левый-низ
		BYTE EncoderRD	: 2;// Энкодер Правый-низ
		BYTE EncoderRT	: 2;// Энкодер Правый-верх
		BYTE EncoderLT	: 2;// Энкодер Правый-верх
		};
	  BYTE	EncoderStatus;	//Состояние энкодеров
	  };
BYTE	KS;				//Контрольная сумма (сумма посылки начиная с 1-ого байта синхронизации по модулю 256)
} PACKET_FROM_MKS_MFD, * PPACKET_FROM_MKS_MFD;

//ИБ COM-порт ИКШ:
typedef struct _PACKET_FROM_MKS_ICW {
WORD	Packet_ID;		//Тип ИБ  												AAB1 (hex)
WORD  	Packet_Size;	//Размер ИБ в байтах									переменное
BYTE	NumberComPort;	//Номер COM-порта										1 – 4
WORD	DataSize;		//Размер данных от  COM-порта   в байтах           		переменное
//	Блок данных от  COM-порта:   	
BYTE	Synhro1;		//1-й Байт синхронизации								0xB0(нех)
BYTE	Synhro2;		//2-й Байт синхронизации								0x3B(нех)
BYTE	Synhro3;		//3-й Байт синхронизации								0x4F(нех)
BYTE	DataSizeWOSyn;	//Длина посылки в байтах без учета синхронизации		11
BYTE	DevType;		//Тип устройства										13
BYTE	DevAddr;		//Адрес устройства										0
BYTE	PacketType;		//Тип пакета											2
BYTE	MFKCode;		//Код нажатой МФК или энкодера		Название кнопки	Код кнопки
						//									Нет нажатия			0
						//									Кнопка сверху HUD	1
						//									Кнопка сверху A/P	2
						//									Кнопка MRK			3
						//									Кнопка ABC/1		4
						//									Кнопка сверху SET	5
						//									Кнопка сверху COM	6
						//									Кнопка LDG			7
						//									Кнопка UP2			8
						//									Кнопка сверху D/L	9
						//									Кнопка сверху NAV	10
						//									Кнопка CLR			11
						//									Кнопка DEF/2		12
						//									Кнопка сверху RNA	13
						//									Кнопка APP			14
						//									Кнопка UP1			15
						//									Кнопка UP3			16
						//									Кнопка GHI/3		17
						//									Кнопка YZ/9			18
						//									Кнопка JKL/4		19
						//									Кнопка UP4			20
						//									Кнопка /0			21
						//									Кнопка MNO/5		22
						//									Кнопка ENT			23
						//									Кнопка UPD			24
						//									Кнопка VWX/8		25
						//									Кнопка STU/7		26
						//									Кнопка PQR/6		27
						//									Кнопка CRD			28
						//									Кнопка ABR			29
						//									Кнопка S/R			30
						//									Кнопка RST			31
						//									Кнопка STK			32
						//									Кнопка S*			33
						//									Кнопка R*			34
						//									Кнопка D*			35

BYTE	EncoderStatusS;		//Состояние энкодера S* 							0-255
BYTE	EncoderStatusR;		//Состояние энкодера  R*							0-255
BYTE	EncoderStatusD;		//Состояние энкодера  D*							0-255
BYTE	EncoderStatusVALIn;	//Состояние энкодера  VAL внутренний				0-255
BYTE	EncoderStatusVALOut;//Состояние энкодера  VAL внешний					0-255
BYTE	KS;				//Контрольная сумма (сумма посылки начиная с 1-ого байта синхронизации по модулю 256)
} PACKET_FROM_MKS_ICW, * PPACKET_FROM_MKS_ICW;

//полный пакет от МКС:

typedef struct _PACKET_FROM_MKS {// размер 409 байт
PACKET_HEADER				Header;
PACKET_FROM_MKS_ARINC		Arinc0,Arinc1,Arinc2,Arinc3;
PACKET_FROM_MKS_ADC			Adc;
PACKET_FROM_MKS_SUZ			Suz;
PACKET_FROM_MKS_TIME		Time;
PACKET_FROM_MKS_MFD			MfdLeft,MfdRight;
PACKET_FROM_MKS_ICW			Icw;

void InitPacket()// Инициализация постоянных параметров пакета
{
Header.Packet_ID = FROM_MKS_HEADER_GLOBAL;
Header.Packet_Size = sizeof(PACKET_FROM_MKS);

Arinc0.Packet_ID		= FROM_MKS_HEADER_ARINC;
Arinc0.Packet_Size		= sizeof(PACKET_FROM_MKS_ARINC);
Arinc0.NumInputCh = 0;
Arinc0.NumArincWords = 9;
Arinc0.Word0100= 0100;
Arinc0.Word0101= 0101;
Arinc0.Word0102= 0102;
Arinc0.Word0103= 0103;
Arinc0.Word0104= 0104;
Arinc0.Word0105= 0105;
Arinc0.Word0106= 0106;
Arinc0.Word0107= 0107;
Arinc0.Word0110= 0110;

Arinc1.Packet_ID		= FROM_MKS_HEADER_ARINC;
Arinc1.Packet_Size		= sizeof(PACKET_FROM_MKS_ARINC);
Arinc1.NumInputCh = 1;
Arinc1.NumArincWords = 9;
Arinc1.Word0100= 0100;
Arinc1.Word0101= 0101;
Arinc1.Word0102= 0102;
Arinc1.Word0103= 0103;
Arinc1.Word0104= 0104;
Arinc1.Word0105= 0105;
Arinc1.Word0106= 0106;
Arinc1.Word0107= 0107;
Arinc1.Word0110= 0110;

Arinc2.Packet_ID		= FROM_MKS_HEADER_ARINC;
Arinc2.Packet_Size		= sizeof(PACKET_FROM_MKS_ARINC);
Arinc2.NumInputCh = 2;
Arinc2.NumArincWords = 9;
Arinc2.Word0100= 0100;
Arinc2.Word0101= 0101;
Arinc2.Word0102= 0102;
Arinc2.Word0103= 0103;
Arinc2.Word0104= 0104;
Arinc2.Word0105= 0105;
Arinc2.Word0106= 0106;
Arinc2.Word0107= 0107;
Arinc2.Word0110= 0110;

Arinc3.Packet_ID		= FROM_MKS_HEADER_ARINC;
Arinc3.Packet_Size		= sizeof(PACKET_FROM_MKS_ARINC);
Arinc3.NumInputCh = 3;
Arinc3.NumArincWords = 9;
Arinc3.Word0100= 0100;
Arinc3.Word0101= 0101;
Arinc3.Word0102= 0102;
Arinc3.Word0103= 0103;
Arinc3.Word0104= 0104;
Arinc3.Word0105= 0105;
Arinc3.Word0106= 0106;
Arinc3.Word0107= 0107;
Arinc3.Word0110= 0110;

Adc.Packet_ID = FROM_MKS_HEADER_ADC_SUZ;
Adc.Packet_Size = sizeof(PACKET_FROM_MKS_ADC);
Adc.TypeInf	= 1;
Adc.DataSize=66;

Suz.Packet_ID	= FROM_MKS_HEADER_ADC_SUZ;
Suz.Packet_Size = sizeof(PACKET_FROM_MKS_SUZ);
Suz.TypeInf	= 2;
Suz.DataSize = 90;

Time.Packet_ID	=	FROM_MKS_HEADER_TIME;
Time.Packet_Size = sizeof(PACKET_FROM_MKS_TIME);

MfdLeft.Packet_ID	= FROM_MKS_HEADER_COM;
MfdLeft.Packet_Size	=sizeof(PACKET_FROM_MKS_MFD);
MfdLeft.NumberComPort = 3;	//Номер COM-порта
MfdLeft.DataSize	= 10;		
	
MfdLeft.Synhro1=	0xB0;
MfdLeft.Synhro2=	0x3B;
MfdLeft.Synhro3=	0x4F;
MfdLeft.DataSizeWOSyn =	7;
MfdLeft.DevType=	DEF_MFK_TYPE;
MfdLeft.DevAddr=		0;//-левый
MfdLeft.PacketType=		2;

MfdRight.Packet_ID	= FROM_MKS_HEADER_COM;
MfdRight.Packet_Size	=sizeof(PACKET_FROM_MKS_MFD);
MfdRight.NumberComPort = 1;	//Номер COM-порта
MfdRight.DataSize	= 10;		
	
MfdRight.Synhro1=	0xB0;
MfdRight.Synhro2=	0x3B;
MfdRight.Synhro3=	0x4F;
MfdRight.DataSizeWOSyn =	7;
MfdRight.DevType=	DEF_MFK_TYPE;
MfdRight.DevAddr=		1;//-правый
MfdRight.PacketType=	2;

Icw.Packet_ID	= FROM_MKS_HEADER_COM;
Icw.Packet_Size	=sizeof(PACKET_FROM_MKS_ICW);
Icw.NumberComPort=2;	//Номер COM-порта
Icw.DataSize=14;		//Размер данных от  COM-порта   в байтах           		переменное
//	Блок данных от  COM-порта:   	
Icw.Synhro1=	0xB0;
Icw.Synhro2=	0x3B;
Icw.Synhro3=	0x4F;
Icw.DataSizeWOSyn=		11;
Icw.DevType=	DEF_IKSH_TYPE;
Icw.DevAddr=			0;
Icw.PacketType=			2;

}

BYTE	GetKs(BYTE * FirstBytePtr, int count)
{
BYTE ks=0;
for(int i=0;i<count;i++)
	ks += *(FirstBytePtr + i);
return ks;
}

BYTE	GetKsMfdLeft	(){return GetKs( &MfdLeft. Synhro1, 9);}
BYTE	GetKsMfdRight	(){return GetKs( &MfdRight.Synhro1, 9);}
BYTE	GetKsIcw		(){return GetKs( &Icw.Synhro1,		13);}

} PACKET_FROM_MKS, * PPACKET_FROM_MKS;


//----------------------------------------------------------------------------------

//Формат пакета для МКС 

//1.Заголовок сетевого пакета
//2. ИБ ARINC429
//3. ИБ СУЗ
//4. ИБ COM-порт МФИ левый
//5. ИБ COM-порт МФИ правый
//6. ИБ COM-порт ИКШ
//7. ИБ COM-порт УАП
//8. ИБ COM-порт КИ-13


//ИБ ARINC429
typedef struct _PACKET_TO_MKS_ARINC {
WORD	Packet_ID;		//Тип ИБ  												AAB2(hex)
WORD  	Packet_Size;	//Размер ИБ в байтах									4+размер блоков  для  ЛС
	
WORD	PacketTypeLine1;	//Тип блока  для  вых. ЛС №1						AAB2(hex)
WORD  	PacketSizeLine1;	//Размер  блока  в байтах  для   вых. ЛС №1			6+(кол-во слов ЛС 1)*4
BYTE   	ChannelNumber1;		//Номер выходного канала ARINC ( № ЛС минус 1 )		0
BYTE	NumberWords1;		//Количество 32-разрядных слов в канале 			1
DWORD   Line1_Word0100;		//слово с адресом 0100(oct)

WORD	PacketTypeLine2;	//Тип блока  для вых. ЛС  №2						AAB2(hex)
WORD  	PacketSizeLine2;	//Размер  блока  в байтах   для   вых. ЛС №2		6+(кол-во слов   ЛС 2)*4
BYTE   	ChannelNumber2;		//Номер выходного канала ARINC ( № ЛС минус 1 )		1
BYTE	NumberWords2;		//Количество 32-разрядных слов в канале 			1
DWORD	Line2_Word0100;		//слово с адресом 0100(oct)

WORD	PacketTypeLine3;	//Тип блока  для   вых. ЛС  №3						AAB2(hex)
WORD  	PacketSizeLine3;	//Размер  блока  в байтах   для   вых. ЛС №3		6+(кол-во слов   ЛС  3)*4
BYTE   	ChannelNumber3;		//Номер выходного канала ARINC ( №  ЛС  минус 1 )	2
BYTE	NumberWords3;		//Количество 32-разрядных слов в канале 			2
DWORD	Line3_Word0100;		//слово с адресом 0100(oct)
DWORD	Line3_Word0101;		//слово с адресом 0101(oct)

//WORD	PacketTypeLine4;	//Тип блока  для   вых. ЛС  №4						AAB2(hex)
//WORD  	PacketSizeLine4;	//Размер  блока  в байтах   для   вых. ЛС №4		6+(кол-во слов   ЛС 4)*4
//BYTE   	ChannelNumber4;		//Номер выходного канала ARINC ( №  ЛС  минус 1 )	3
//BYTE	NumberWords4;		//Количество 32-разрядных слов в канале 			0
} PACKET_TO_MKS_ARINC, * PPACKET_TO_MKS_ARINC;


//ИБ СУЗ:
typedef struct _PACKET_TO_MKS_SUZ {
WORD	Packet_ID;		//Тип ИБ  												AAB4(hex)
WORD  	Packet_Size;	//Размер ИБ в байтах									61
BYTE    TypeInf;		//	Тип информации										2
DWORD	DataSize;		//Размер данных для СУЗ в байтах           				52
	union {//Разовые команды СУЗ
      struct {
		DWORD RK_Trim_Tng	   : 2;	// Разовые команы триммера тангаж 0 - нейтраль, 1 - вниз, 2  - вверх
		DWORD RK_Trim_Krn	   : 2;	// Разовые команы триммера тангаж 0 - нейтраль, 1 - влево, 2  вправо
		DWORD RK_Trim_Napr     : 2; // Разовые команы триммера педалей 0 - нейтраль, 1 - влево, 2 - вправо
		DWORD RK_SAU		   : 1;	// *** Разовая команда САУ включена
		DWORD RK_GearOn	       : 1;	// Шасси выпущены
		DWORD RK_Ust		   : 1;	// РК Юстировка РУС
		DWORD RK_Stop	       : 1;	// Остановить приводы
		DWORD RK_NULL		   : 1;	// Установить приводы в нулевое положение
		DWORD RK_MIN		   : 1;	// Устаноаить привода в минимум
		DWORD RK_MAX		   : 1;	// Устаноаить привода в максимум
		DWORD RK_TrimTngFail   : 2; // Отказ тримера тангажа (0 - нет, 1 - пассивный, 2 - вверх, 3 - вниз)
		DWORD RK_TrimKrnFail   : 2; // Отказ тримера крена (0 - нет, 1 - пассивный, 2 - влево, 3 - вправо)
		DWORD RK_TrimRnFail    : 2; // Отказ тримера педалей (0 - нет, 1 - пассивный, 2 - влево, 3 - вправо)
		};
	  DWORD	RK;
	  };
float	SAU_X_MET[3];	// *** Положение триммеров из САУ в миллиметрах хода РУС 	[0]-по тангажу	
						//															[1]-по крену	
						//															[2]-по напр	
float	Alfa; 			// Угол атаки, градусы	
float 	M;				// Число М	переменное
float 	Kfi;			// *** Коэффициент загрузки Kфи								1.0 – 1.86
float 	X_SOS;			// *** Положение СОС толкателя, в миллиметрах хода РУС	
BYTE	Res[20];		// Резерв	
} PACKET_TO_MKS_SUZ, * PPACKET_TO_MKS_SUZ;

//ИБ COM-порт МФИ левый(правый):
typedef struct _PACKET_TO_MKS_MFD {

WORD	Packet_ID;		//Тип ИБ  												AAB0 (hex)
WORD  	Packet_Size;	//Размер ИБ в байтах									17
BYTE	MumberComPort;	//Номер COM-порта										3-левый (1-правый)
WORD	DataSize;		//Размер данных для  COM-порта   в байтах           	10
BYTE	Synhro1;		//1-й Байт синхронизации								0xB0(нех)
BYTE	Synhro2;		//2-й Байт синхронизации								0x3B(нех)
BYTE	Synhro3;		//3-й Байт синхронизации								0x4F(нех)
BYTE	DataSizeWOSyn;	//Длина посылки в байтах без учета синхронизации		7
BYTE	DevType;		//Тип устройства										10
BYTE	DevAddr;		//Адрес устройства										0-левый(1-правый)
BYTE	PacketType;		//Тип пакета											1
WORD	Light;			//Яркость панели										0-1023
BYTE	KS;				//Контрольная сумма (сумма посылки начиная с 1-ого байта синхронизации по модулю 256)	
} PACKET_TO_MKS_MFD, * PPACKET_TO_MKS_MFD;


//ИБ COM-порт ИКШ:
typedef struct _PACKET_TO_MKS_ICW {
WORD	Packet_ID;		//Тип ИБ  												AAB0 (hex)
WORD  	Packet_Size;	//Размер ИБ в байтах									16
BYTE	MumberComPort;	//Номер COM-порта										2
WORD	DataSize;		//Размер данных для  COM-порта   в байтах           	9
BYTE	Synhro1;		//1-й Байт синхронизации								0xB0(нех)
BYTE	Synhro2;		//2-й Байт синхронизации								0x3B(нех)
BYTE	Synhro3;		//3-й Байт синхронизации								0x4F(нех)
BYTE	DataSizeWOSyn;	//Длина посылки в байтах без учета синхронизации		6
BYTE	DevType;		//Тип устройства										13      //?????????????????
BYTE	DevAddr;		//Адрес устройства										0
BYTE	PacketType;		//Тип пакета											1
BYTE	Light;			//Яркость панели										0-255
BYTE	KS;				//Контрольная сумма (сумма посылки начиная с 1-ого байта синхронизации по модулю 256)
} PACKET_TO_MKS_ICW, * PPACKET_TO_MKS_ICW;

//ИБ COM-порт УАП:
typedef struct _PACKET_TO_MKS_UAP {
WORD	Packet_ID;		//Тип ИБ  												AAB0 (hex)
WORD  Packet_Size;		//Размер ИБ в байтах									23
BYTE	MumberComPort;	//Номер COM-порта										4
WORD	DataSize;		//Размер данных для  COM-порта   в байтах           	16
BYTE	Synhro1;		//1-й Байт синхронизации								0xB0(нех)
BYTE	Synhro2;		//2-й Байт синхронизации								0x3B(нех)
BYTE	Synhro3;		//3-й Байт синхронизации								0x4F(нех)
BYTE	DataSizeWOSyn;	//Длина посылки в байтах без учета синхронизации		13
BYTE	DevType;		//Тип устройства										11
BYTE	DevAddr;		//Адрес устройства										0
BYTE	PacketType;		//Тип пакета											1
float	Arrow1;			//Код для первой стрелки								0.0 … 1.0
float	Arrow2;			//Код для второй стрелки								0.0 … 1.0
BYTE	KS;				//Контрольная сумма (сумма посылки начиная с 1-ого байта синхронизации по модулю 256)
} PACKET_TO_MKS_UAP, * PPACKET_TO_MKS_UAP;


//ИБ COM-порт КИ-13:
typedef struct _PACKET_TO_MKS_KI13 {
WORD	Packet_ID;		//Тип ИБ  												AAB0 (hex)
WORD  Packet_Size;	//Размер ИБ в байтах									19
BYTE	MumberComPort;	//Номер COM-порта										4
WORD	DataSize;		//Размер данных для  COM-порта   в байтах           	12
BYTE	Synhro1;		//1-й Байт синхронизации								0xB0(нех)
BYTE	Synhro2;		//2-й Байт синхронизации								0x3B(нех)
BYTE	Synhro3;		//3-й Байт синхронизации								0x4F(нех)
BYTE	DataSizeWOSyn;	//Длина посылки в байтах без учета синхронизации		9
BYTE	DevType;		//Тип устройства										24
BYTE	DevAddr;		//Адрес устройства										0
BYTE	PacketType;		//Тип пакета											1
WORD 	Gauge;			//Код для шкалы 										(курс(град))*6./5.
BYTE	LightRed;		//Яркость красного										0-31
BYTE	LightGreenBlue;	//Яркость зеленого и синего								0-31
BYTE	KS;				//Контрольная сумма (сумма посылки начиная с 1-ого байта синхронизации по модулю 256)	
} PACKET_TO_MKS_KI13, * PPACKET_TO_MKS_KI13;


//полный пакет для МКС:

typedef struct _PACKET_TO_MKS {// размер //195 байт          /////201
PACKET_HEADER				Header;
PACKET_TO_MKS_ARINC			Arinc;
PACKET_TO_MKS_SUZ			Suz;
//PACKET_TO_MKS_MFD			MfdLeft;
//PACKET_TO_MKS_MFD			MfdRight;
//PACKET_TO_MKS_ICW			Icw;

WORD	Packet_ID_Magic;	//Магическое число, подслушанное на РСК, без него не управлялся УАП
WORD	Packet_Size_Magic;	//Магическое число, подслушанное на РСК, без него не управлялся УАП

PACKET_TO_MKS_UAP			Uap;
//PACKET_TO_MKS_KI13		Ki13;

void InitPacket()// Инициализация постоянных параметров пакета
{
Header.Packet_ID = TO_MKS_HEADER_GLOBAL;
Header.Packet_Size = sizeof(PACKET_TO_MKS);

Arinc.Packet_ID			= TO_MKS_HEADER_ARINC;
Arinc.Packet_Size		= sizeof(PACKET_TO_MKS_ARINC);

Arinc.PacketTypeLine1	= TO_MKS_HEADER_ARINC;	
Arinc.ChannelNumber1	=0;
Arinc.NumberWords1		=1;
Arinc.Line1_Word0100	=0100;		//слово с адресом 0100(oct)
Arinc.PacketSizeLine1	=6 + 4*Arinc.NumberWords1;	//Размер  блока  в байтах  для   вых. ЛС №1			6+(кол-во слов ЛС 1)*4

Arinc.PacketTypeLine2	= TO_MKS_HEADER_ARINC;
Arinc.ChannelNumber2	=1;		//Номер выходного канала ARINC ( № ЛС минус 1 )		1
Arinc.NumberWords2		=1;		//Количество 32-разрядных слов в канале 			1
Arinc.Line2_Word0100	=0100;
Arinc.PacketSizeLine2	=6 + 4*Arinc.NumberWords2;		//Размер  блока  в байтах   для   вых. ЛС №2		6+(кол-во слов   ЛС 2)*4

Arinc.PacketTypeLine3	= TO_MKS_HEADER_ARINC;
Arinc.ChannelNumber3	=2;		//Номер выходного канала ARINC ( №  ЛС  минус 1 )	2
Arinc.NumberWords3		=2;		//Количество 32-разрядных слов в канале 			2
Arinc.Line3_Word0100	=0100;
Arinc.Line3_Word0101	=0101;
Arinc.PacketSizeLine3	=6 + 4*Arinc.NumberWords3;	//Размер  блока  в байтах   для   вых. ЛС №3		6+(кол-во слов   ЛС  3)*4

//Arinc.PacketTypeLine4	= TO_MKS_HEADER_ARINC;
//Arinc.ChannelNumber4	=3;		//Номер выходного канала ARINC ( №  ЛС  минус 1 )	3
//Arinc.NumberWords4		=0;		//Количество 32-разрядных слов в канале 			0
//Arinc.PacketSizeLine4	=6 + 4*Arinc.NumberWords4;	//Размер  блока  в байтах   для   вых. ЛС №4		6+(кол-во слов   ЛС 4)*4

Suz.Packet_ID	= TO_MKS_HEADER_SUZ;			//Тип ИБ  							AAB4(hex)
Suz.Packet_Size	= sizeof(PACKET_TO_MKS_SUZ);	//Размер ИБ в байтах				61 (63)
Suz.TypeInf		= 2;		//	Тип информации										2
Suz.DataSize	=52;		//Размер данных для СУЗ в байтах           				52
//Suz.DataSize	=54;		//Размер данных для СУЗ в байтах (добавлен FrameCount) 	54
/*
MfdLeft.Packet_ID		= TO_MKS_HEADER_MFD;
MfdLeft.Packet_Size		=sizeof(PACKET_TO_MKS_MFD);
MfdLeft.MumberComPort	= 3;	
MfdLeft.DataSize		= 10;		
MfdLeft.Synhro1=	0xB0;
MfdLeft.Synhro2=	0x3B;
MfdLeft.Synhro3=	0x4F;
MfdLeft.DataSizeWOSyn =	7;
MfdLeft.DevType=	DEF_MFK_TYPE;
MfdLeft.DevAddr=		0;//-левый
MfdLeft.PacketType=		1;

MfdRight.Packet_ID		= TO_MKS_HEADER_MFD;
MfdRight.Packet_Size	=sizeof(PACKET_TO_MKS_MFD);
MfdRight.MumberComPort = 1;	//Номер COM-порта	
MfdRight.DataSize	= 10;		
MfdRight.Synhro1=	0xB0;
MfdRight.Synhro2=	0x3B;
MfdRight.Synhro3=	0x4F;
MfdRight.DataSizeWOSyn =	7;
MfdRight.DevType=	DEF_MFK_TYPE;
MfdRight.DevAddr=		1;//-правый
MfdRight.PacketType=	1;

Icw.Packet_ID		= TO_MKS_HEADER_ICW;
Icw.Packet_Size		=sizeof(PACKET_TO_MKS_ICW);
Icw.MumberComPort	=2;	//Номер COM-порта	
Icw.DataSize		=9;	//Размер данных от  COM-порта   в байтах           		
Icw.Synhro1=	0xB0;
Icw.Synhro2=	0x3B;
Icw.Synhro3=	0x4F;
Icw.DataSizeWOSyn=		6;
Icw.DevType=	DEF_IKSH_TYPE;
Icw.DevAddr=			0;
Icw.PacketType=			1;
*/

Packet_ID_Magic		= TO_MKS_HEADER_UAP;
Packet_Size_Magic	= 27;	

Uap.Packet_ID		=TO_MKS_HEADER_UAP;			//Тип ИБ  						AAB0 (hex)
Uap.Packet_Size		=sizeof(PACKET_TO_MKS_UAP);	//Размер ИБ в байтах			23
Uap.MumberComPort=	 4;	//Номер COM-порта										4
Uap.DataSize=		16;		//Размер данных для  COM-порта   в байтах          	16
Uap.Synhro1=	0xB0;
Uap.Synhro2=	0x3B;
Uap.Synhro3=	0x4F;
Uap.DataSizeWOSyn=	13;	//Длина посылки в байтах без учета синхронизации		13
Uap.DevType=	DEF_UAP_TYPE;	//Тип устройства								11
Uap.DevAddr=		0;	//Адрес устройства										0
Uap.PacketType=		1;	//Тип пакета											1

/*
Ki13.Packet_ID		=TO_MKS_HEADER_KI13;		//Тип ИБ  						AAB0 (hex)
Ki13.Packet_Size	=sizeof(PACKET_TO_MKS_KI13);	//Размер ИБ в байтах		19
Ki13.MumberComPort=	4;	//Номер COM-порта										4
Ki13.DataSize=		12;		//Размер данных для  COM-порта   в байтах           12
Ki13.Synhro1=	0xB0;
Ki13.Synhro2=	0x3B;
Ki13.Synhro3=	0x4F;
Ki13.DataSizeWOSyn=	9;	//Длина посылки в байтах без учета синхронизации		9
Ki13.DevType=	DEF_KI13_TYPE;		//Тип устройства							24
Ki13.DevAddr=		0;		//Адрес устройства									0
Ki13.PacketType=	1;		//Тип пакета										1
*/
}

BYTE	GetKs(BYTE * FirstBytePtr, int count)
{
DWORD ks=0;
for(int i=0;i<count;i++)
	ks += *(FirstBytePtr + i);
return (BYTE)(ks & 0xFF);
}

//BYTE	GetKsMfdLeft	(){return GetKs( &MfdLeft. Synhro1, 9);}
//BYTE	GetKsMfdRight	(){return GetKs( &MfdRight.Synhro1, 9);}
//BYTE	GetKsIcw		(){return GetKs( &Icw.Synhro1,		8);}
BYTE	GetKsUap		(){return GetKs( &Uap.Synhro1,		15);}
//BYTE	GetKsKi13		(){return GetKs( &Ki13.Synhro1,		11);}

} PACKET_TO_MKS, * PPACKET_TO_MKS;

#pragma pack(pop)

//----------------------------------------------------------------------------------
#endif // MKS_H_INCLUDED
//----------------------------------------------------------------------------------

