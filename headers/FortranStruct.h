#include "C5_450.h"			// параметры RM(5565)
#include "LineAccelXYZ.h"	// параметры ЦАП xyzDac
#include "ObjectNames.h"	// параметры МКИО ОУ_3
#include "ObjectNamesM.h"	// параметры МКИО Монитор
#include "RTMparam170M.h"	// параметры РТМ
#include "KMBO_170M.h"		// параметры КМБО
#include "Conf_170M.h"		// параметры для определения выбранной конфигурации Вирт. адаптер
#include "RS422_170M.h"		// параметры для синхр/асинхр управления ИРС(КРИТ) по RS-422/485

//структура для передачи в "модель"
typedef struct {
float Time;				// в ремя с начала запуска задачи, мс
unsigned int CallCnt;	// счетчик вызовов процедуры CallFortran
PIN_PACK InPack;		// указатель на структуру, принятую от С5-450
PSHMEMSTR pStend;		// Имитация ОУ3(ИСУ)- входной подарес MkioInput[32],выходной подарес MkioOutput[32] и признаки состояния программы Stend.exe
PSHMEMSTR_M pStend_M;	// МКИО Монитор - мониторинг ОУ3 (ИСУ)
PCONF_STEND Conf;		// массив признаков выбора конфигурации Базы данных Variant[8]
PT_RS422_IN pRS422_IN;  // RS422/485
} TO_MODEL_STR, *PTO_MODEL_STR;

//структура для приема из "модели" для выдачи через адаптеры
typedef struct {
float a; 
POUT_PACK	OutPack;	// указатель на структуру для выдачи на С5-450
PLINE_ACCEL OutAccel;	// ЦАП токовый - Ускорение центра масс изд. по трем координатам X, Y, Z;
PLINE_U		OutU;		// ЦАП напряжения U1, U2;
pR_170M		RVV;		// РТМ - полетное задание
POUT_KMBO	OutKMBO;	// КМБО
PT_RS422_OUT pRS422_OUT;// параметры для синхр/асинхр управления ИРС(КРИТ) по RS-422/485
} FROM_MODEL_STR, *PFROM_MODEL_STR;