#ifndef _MSI
#define _MSI

#include <windows.h>
#include <rtapi.h>

#pragma pack(push, 1)   

struct sVI
 {
 union uMIX
  {
  UINT32 w32;
  struct sBIT
   {
   UINT32 case_CW_BUS1:1;  // =1: приход прерывания по КС шины 1
   UINT32 case_DW_BUS1:1;  // =1: приход прерывания по СД шины 1
   UINT32 case_CW_BUS2:1;  // =1: приход прерывания по КС шины 2
   UINT32 case_DW_BUS2:1;  // =1: приход прерывания по СД шины 2
   UINT32 case_EXT:1;      // =1: приход внешнего прерывания
   UINT32 CNT_INTERRUPT:3; // кол-во пришедших прерываний
                           // --- Шина 1
   UINT32 SA_BUS1:  5;     // подадрес
   UINT32 DIR_BUS1: 1;     // =0: команда ОУ на прием, =1 : на передачу
   UINT32 RT_BUS1:  5;     // адрес ОУ
   UINT32 PriRes1:  1;     // =0: основная, =1: резервная шина
                           // --- Шина 2
   UINT32 SA_BUS2:  5;     // подадрес
   UINT32 DIR_BUS2: 1;     // =0: команда ОУ на прием, =1 : на передачу
   UINT32 RT_BUS2:  5;     // адрес ОУ
   UINT32 PriRes2:  1;     // = 0: основная, = 1 : резервная шина
   } bit;
  } mix ;
 UINT64 t;  // момент времени прихода прерывания, мкс
 UINT64 dt; // время между текущим и предыдущим прерыванием, мкс
 };

#define SIZE_SharedMem_MSI 0x2000 // !!! не изменять для совместимости с драйвером RMe-_02

struct sMSIshm
	{
 // Область для адаптера MPIe   0x00...0x0F (8-и байтовые ячейки) размером 16*8 = 128 байт
	struct sMPIe_Region
	 {
	 LARGE_INTEGER sysLogAddr;  // 0x00 : system logical address
		UINT32 TaskSet;            // задание "i" с параметром TaskSet[i] задано на исполнение программой MSI.exe
  UINT32 TaskAccepted;       // задание "i" с параметром TaskAccepted[i] принято к исполнению программой MSI.rtss
		UINT8 PRN;   		    								// Признак печати в окно RtxServer
		UINT8 res[111];		  								// резерв для области адаптера MPIe
	 } MPIe_Region;

 // Область для адаптера MKIOe  0x10...0x1F (8-и байтовые ячейки) размером 16*8 = 128 байт
	struct sMKIOe_Region
		{
		LARGE_INTEGER sysLogAddr; // 0x10 : system logical address
		sVI VI; // размер 20 байт
		union // регистр шаблонов КС
			{
			UINT32 w32;
			struct
				{
				UINT32 value:16; // шаблон значений
				UINT32 mask:16;  // шаблон позиций
				} VandM;         
			} CW1,DW1,CW2,DW2;
  UINT32 TaskSet[3];       // задание "i" с параметром TaskSet[i] задано на исполнение программой MSI.exe
		                         // i = 0 : имитация прихода прерывания по шине 1
		                         // i = 1 : имитация прихода прерывания по шине 2
		                         // i = 2 : имитация прихода прерывания по внешнему импульсу
  UINT32 TaskAccepted[3];  // задание "i" с параметром TaskAccepted[i] принято к исполнению программой MSI.rtss
		UINT32 ctrlREG;								  // регистр управления FOHBe-01, R/W
		UINT8 PRN   ;		  								// Признак печати в окно RtxServer
		UINT8 res[55];								   // резерв для области адаптера MKIOe
		} MKIOe_Region;

	// Область для адаптера RMe_02 0x20...0x2F (8-и байтовые ячейки) размером 16*8 = 128 байт !!! не изменять для совместимости с драйвером RMe-_02
	struct sRMe_02_Region
		{
		LARGE_INTEGER sysLogAddr;      // 0x20 : system logical address BAR0
		UINT64 sizeRM;											      // 0x21 : размер памяти в 16Мб ед., т.е. 8 => 128Мб
		LARGE_INTEGER PhysAddr_BAR1;   // 0x22 : физадрес BAR1
		LARGE_INTEGER PhysAddr_SEG[8]; // 0x23...0x2A : физадреса 8-ми сегментов памяти на чтение
  UINT32 TaskSet;                // задание "i" с параметром TaskSet[i] задано на исполнение программой MSI.exe
  UINT32 TaskAccepted;           // задание "i" с параметром TaskAccepted[i] принято к исполнению программой MSI.rtss
		union                          
			{
			unsigned __int32 data;
			struct InterruptValue
 			{
				unsigned __int32 ncell  :21;						//номер 64 битной ячейки в сегменте (0 … 2М-1);
				unsigned __int32 nseg   : 3;						//номер 16МВ сегмента памяти с контролируемой ячейкой;
				unsigned __int32        : 7;
				unsigned __int32 enable : 1;						//включение прерывания;
	 		}interruptValue;
			} interruptSET[16];
		////UINT32 interruptSET[16];       // параметр настройки i-го прерывания
		////                               // 0...20 биты : номер 64 битной ячейки в одном из 8-ми 16Мб сегментов памяти
		////                               // 21,22,23 биты : номер 16Мб сегмента памяти
		////                               // 24...30 биты : не используются
		////																															// 31 бит : признак включения прерывания
  UINT32 nodeInterrupt;          // регистр задействованных прерываний, своими битами (с 0 по 15-ый) показывает, какие прерывания будут задействованы на данном узле.
  UINT32 lastInterrupt;          // регистр вектора прерываний, своими битами (с 0 по 15-ый) показывает, какое прерывание было сгенерировано последним
  UINT64 t;                      // момент времени прихода прерывания, мкс
  UINT64 dt;                     // время между текущим и предыдущим прерыванием, мкс
		UINT8 PRN;	   	  				      				// Признак печати в окно RtxServer
		UINT8 res[327];														  // резерв для области адаптера RMe_02
	 } RMe_02_Region;

	struct sSTAT
	 {
  UINT64 N;       // кол-во событий
  UINT64 min;     // минимальное значение dt[мкс]
	 UINT64 max;     // максимальное значение dt[мкс]
		UINT32 AVT;     // 1: автоматический расчет min, max, 0: ручной ввод min, max из прог. COInterrupt.exe
	 UINT32 m[1000]; // гистограмма

		UINT64 dti(UINT32 i) // расчет центра интервала dt по номеру интервала
		 {
   return min+i*(max-min)/999;
		 }
		void erase_m(void)
		 {
			N = 0;
			memset(m,0,sizeof(m));
			return;
		 }

		void reset_MinMax(void)
		 {
			min = 0xFFFFFFFFFFFFFFFF;
			max = 0;
			return;
		 }

	} stat;

	INT32 HIST; // 1: набор , 0: нет набора, печать при переходе с 1 на 0
	// Параметры задаваемые из командной строки
	INT32 REG; // режим работы MSI.rtss
	INT32 PRN; // режим печати MSI.rtss
	INT32 DBG; // режим тестирования MSI.rtss

	};

#pragma pack(pop)   

#endif

