//Распределение рефлективной памяти модуля VMIPCI-5587А

//                              Диапазон адресов	Размер области, байт	назначение
                                //00000h-0003Fh	        64	Служебная область памяти адаптера
#define SH_RESERV1      0x00040 //00040h-1FFFFh	        131008	Резерв1
#define SH_IPC1         0x20000 //20000h-3FFFFh	        131072	Запись IPC1
#define SH_IPC2         0x40000 //40000h-5FFFFh	        131072	Запись IPC2
#define SH_IPC4         0x60000 //60000h-7FFFFh	        131072	Запись IPC4
#define SH_IPC6         0x80000 //80000h-9FFFFh	        131072	Запись IPC6
#define SH_PC1          0xA0000 //A0000h-BFFFFh	        131072	Запись PC1
#define SH_PCVS1        0xC0000 //C0000h-DFFFFh	        131072	Запись PC Системы Визуализации
#define SH_RESERV2      0xE0000 //E0000h-FFFFFh	        131072	Резерв2


//IPC1......................................
#define SH_IPC1_TIME	SH_IPC1			//  8 Байт, Системное время на IPC1
#define SH_IPC1_VS		SH_IPC1_TIME +8 //648 Байт, Структура типа CC_TO_VS


//Начало области входных параметров на IPC1
//из Sam32
#define SH_IPC1_FROM_SAM	SH_IPC1_VS+648			//20290-	, 1632 TSamToOLin strOLmode.h
//из OLmode.dll
#define SH_IPC1_TO_SAM		SH_IPC1_FROM_SAM+1632	//-		,	20		TSamFromOL,  strOLmode.h
#define SH_IPC1_fFromMPI	SH_IPC1_TO_SAM+20		//-		,	72		T_FL_FROM_MPI, strOLmode.h
#define SH_IPC1_fToMPI		SH_IPC1_fFromMPI+72		//-		,	32		T_FL_TO_MPI= ,  strOLmode.h
#define SH_IPC1_OLData		SH_IPC1_fToMPI+32		//		,	96		data[],  strOLmode.h (long) 
#define SH_IPC1_FL_ToRSS	SH_IPC1_OLData+96		//не используется!	960		T_FL_ToRSS, strOLmode.h (сейчас - T_FL_ToUkrop)

#define FreeIPC1	 	SH_IPC1_FL_ToRSS+960	//0x20D8C=134540					0




//.......Горохова, IPC2......................................
// Начало области выходных параметров на IPC1
#define SH_IPC2_IN			SH_IPC2+0x100	//0x100-резерв		
// OUT
#define SH_IPC2_MPI			SH_IPC2_IN				//0x100



//	компьютер Системы Визуализации PCVS1
#define SH_PCVS1_TIME		SH_PCVS1// 8 Байт, Системное время на PCVS1
#define SH_VS_IPC1			SH_PCVS1_TIME + 8// 112 Байт, Структура типа VS_TO_CC