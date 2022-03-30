#ifndef PC429_h
#define PC429_h

#include <windows.h>
#include <stdio.h>
#include <rtapi.h>

#pragma pack(push, 1)

#define MAX_NUM_LINE			16		// максимальное количество линий in + out )
#define MAX_NUM_WORD		256		// максимальное количество слов в линии

	//описание структуры линии дл€ ARINC429
	struct ARINC429_Batch {
									UCHAR InOut;				//	тип линии (вх/вых) 
									UCHAR NumWord;		//	число слов в линии 
									float Freq;					//	несуща€ частота линии 0-25к√ц -> 12к√ц, 25-75к√ц -> 50к√ц, >75к√ц -> 100к√ц
									};
	//информаци€ дл€ настройки плат PC429-3,4
		struct PC429INFO {
				UCHAR		NumPC;																							            // номер –—
				UCHAR		NumBoard;																				            // номер платы в –—
				ARINC429_Batch  Arinc429_Batch[MAX_NUM_LINE*2];	// массив с описанием параметров линий дл€ конкретной платы
				};

	union uArincData
		{
		ULONG d;
		struct
			{
			ULONG Address :8;
			ULONG Data				:23;
			ULONG Gap					:1;
			} adg;
		};
	
#endif