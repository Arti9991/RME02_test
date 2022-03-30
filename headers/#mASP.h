#if !defined(__ASP)
#define      __ASP

#include <stdio.h>
#include <windows.h>


#pragma pack(push, 1)

#include "#tmg.h"

struct sASP
	{
	public:
 
	// In
 unsigned __int8  code;          // код изделия
	unsigned __int8  typeMKIO;      // тип обмена по МКИО (0-TE6, 1-iMKIO)

 unsigned __int8  K[32];         // РК от СУО на модель АСП
 unsigned __int16 MH1[8];        // Слова данных 1-й кадр МПОЗ (МКИО) |  8 : изд.07 |
 unsigned __int16 MH2[28];       // Слова данных 2-й кадр МПОЗ (МКИО) | 28 : изд.07 |
 unsigned __int16 MH3[32];       // Слова данных 3-й кадр МПОЗ (МКИО) | 32 : изд.07 |
 unsigned __int16 MH4[30];       // Слова данных 4-й кадр МПОЗ (МКИО) | 30 : изд.07 |
 unsigned __int16 MH5[29];       // Слова данных 5-й кадр МПОЗ (МКИО) | 29 : изд.07 |
	unsigned __int32 tMH1;        // Время обновления данных массива MH1 по МКИО АСП, мс
	unsigned __int32 tMH2;        // Время обновления данных массива MH2 по МКИО АСП, мс
	unsigned __int32 tMH3;        // Время обновления данных массива MH3 по МКИО АСП, мс
	unsigned __int32 tMH4;        // Время обновления данных массива MH4 по МКИО АСП, мс
	unsigned __int32 tMH5;        // Время обновления данных массива MH5 по МКИО АСП, мс
	unsigned __int32 PZD[28];       // Слова данных с адресами (РТМ)

	double Targ_lat[19];            // Широта целей (максимум 8 целей)
	double Targ_long[19];           // Долгота целей (максимум 8 целей)
	unsigned __int8 Targ_n;         // Количество целей, заданных в НУ

	// Out
	unsigned __int8  S[32];         // РК на СУО от модели АСП
	unsigned __int16 MR1[1];        // Слова данных Массив МР1 (МКИО)    |  1 : изд.07 |
	unsigned __int16 MR2[29];       // Слова данных Массив МР2 (МКИО)    | 29 : изд.07 |
	unsigned __int32 tMR1;          // Время обновления данных массива MR1 по МКИО АСП, мс
	unsigned __int32 tMR2;          // Время обновления данных массива MR2 по МКИО АСП, мс
	unsigned __int16 ASP_RT_Status; // Cтатус состояния RT на шине МКИО АСП
 unsigned __int32 PZA[28];       // Адреса слов данных(РТМ)

	// InOut
	unsigned __int8  Shod;          // Признак сброса

 // Simulation
 unsigned __int32 simul[2];         // Имитация пользователем снятия / выдачи признаков со стороны АСП

	// Функции подсчета контрольной суммы
 unsigned __int16 chekSumMH1(void); // Контрольная сумма массива МН1
 unsigned __int16 chekSumMH2(void); // Контрольная сумма массива МН2
 unsigned __int16 chekSumMH3(void); // Контрольная сумма массива МН3
 unsigned __int16 chekSumMH4(void); // Контрольная сумма массива МН4
 unsigned __int16 chekSumMH5(void); // Контрольная сумма массива МН5
 unsigned __int16 chekSumMR1(void); // Контрольная сумма массива МР1
 unsigned __int16 chekSumMR2(void); // Контрольная сумма массива МР2
 
	sASP ();
	};

#define szMAS(NAME)   sizeof(NAME)/sizeof(NAME[0])

sASP::sASP ()
	{
	int i;
 for (i = 0; i<szMAS(K); i++)   { K[i] = 0;   }
 for (i = 0; i<szMAS(MH1); i++) { MH1[i] = 0; }
 for (i = 0; i<szMAS(MH2); i++) { MH2[i] = 0; }
 for (i = 0; i<szMAS(MH3); i++) { MH3[i] = 0; }
 for (i = 0; i<szMAS(MH4); i++) { MH4[i] = 0; }
 for (i = 0; i<szMAS(MH5); i++) { MH5[i] = 0; }
 for (i = 0; i<szMAS(PZD); i++) { PZD[i] = 0; }
 for (i = 0; i<szMAS(S); i++) { S[i] = 0; }
 for (i = 0; i<szMAS(MR1); i++) { MR1[i] = 0; }
 for (i = 0; i<szMAS(MR2); i++) { MR2[i] = 0; }
 for (i = 0; i<szMAS(PZA); i++) { PZA[i] = 0; }
 code = 0;
 Shod =0;
	}

unsigned __int16 sASP::chekSumMH1(void) // Контрольная сумма массива MH1
 {
 unsigned __int16 res = 0;

 for (int i = 0; i<szMAS(MH1) - 1; i++) { res += MH1[i]; }
 return res;
 }

unsigned __int16 sASP::chekSumMH2(void) // Контрольная сумма массива MH2
 {
 unsigned __int16 res = 0;

 for (int i = 0; i<szMAS(MH2) - 1; i++) { res += MH2[i]; }
 return res;
 }

unsigned __int16 sASP::chekSumMH3(void) // Контрольная сумма массива MH3
{
 unsigned __int16 res = 0;

 for (int i = 0; i<szMAS(MH3) - 1; i++) { res += MH3[i]; }
 return res;
}

unsigned __int16 sASP::chekSumMH4(void) // Контрольная сумма массива MH4
{
 unsigned __int16 res = 0;

 for (int i = 0; i<szMAS(MH4) - 1; i++) { res += MH4[i]; }
 return res;
}

unsigned __int16 sASP::chekSumMH5(void) // Контрольная сумма массива MH5
{
 unsigned __int16 res = 0;

 for (int i = 0; i<szMAS(MH5) - 1; i++) { res += MH5[i]; }
 return res;
}

unsigned __int16 sASP::chekSumMR1(void) // Контрольная сумма массива МР1 (УТОЧНИТЬ КАК СЧИТАТЬ!!! СЛОВО ОДНО!!!)
{
	unsigned __int16 res = 0;
 return res;
}

unsigned __int16 sASP::chekSumMR2(void) // Контрольная сумма массива МР2
{
 unsigned __int16 res = 0;

 for (int i = 0; i<szMAS(MR2) - 1; i++) { res += MR2[i]; }
 return res;
}

#endif