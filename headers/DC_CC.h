
// входы РК на СС  (DcToCc.XX)
typedef struct{// размер 16 байт
char
				//входы РК на адаптере IN 11
LG_Press_On,		// ШО из ЗУ на модели
TRIP_1,				//TRIP-1 (197ft) из РВ на ВЦ
TRIP_2,				//TRIP-2 (646ft) из РВ на ВЦ
SVS_Test,			//Контр компл СВС
SVS_PVD,			//ПВД рез на СВС
INS1_OK,			//Испр ИНС1 на ВЦ
INS2_OK,			//Испр ИНС2 на ВЦ
INS1_VERT_OK,		//Испр верт ИНС1 на ВЦ
INS1_PSI_M_OK,		//Испр Psi магн ИНС1 на ВЦ
INS1_PSI_T_OK,		//Испр Psi ист ИНС1 на ВЦ
INS2_VERT_OK,		//Испр верт ИНС2 на ВЦ
INS2_PSI_M_OK,		//Испр Psi магн ИНС2 на ВЦ
INS2_PSI_T_OK,		//Испр Psi ист ИНС2 на ВЦ
TI_NotUse,			//ТИ от FTI-03UPG не занимать
				//входы РК на адаптере IN 14
TMP_GPS,			//TMP GPS b(-) от INS1/2, +5В на мониторинг
TI;					//Тактовый имп от PCADS02, 5В
} DC_TO_CC, *PDC_TO_CC;

// выходы РК с СС (DcFromCc.XX)
typedef struct{// размер 25 байт
char
//выходы РК на адаптере OUT 7
LG_Not_Press,		//Стойка не обжата на 20СПМ
MAX_FromSam,		//МАХ из модели Самолета на 20СПМ
Afterburning,		//Форсаж из модели Самолета на 20СПМ
TRIP_1,				//TRIP-1 (197ft) на ЦИМС
TRIP_2,				//TRIP-2 (646ft) на ЦИМС
SVS_OK_Karat,		//Испр СВС в Карат
SVS_OK_Cims,		//Испр СВС на ЦИМС
INS1_OK_Cims,		//Испр ИНС1 в ЦИМС
INS2_OK_Cims,		//Испр ИНС2 в ЦИМС
INS1_OK_Karat,		//Испр ИНС1 в Карат
INS2_OK_Karat,		//Испр ИНС2 в Карат
INS1_OK_IVK,		//Испр ИНС1 в ИВК
INS2_OK_IVK,		//Испр ИНС2 в ИВК
INS1_VERT_OK_IVK,	//Испр верт ИНС1 в ИВК
INS1_PSI_M_OK,		//Испр Psi магн ИНС1 в ИВК
INS1_PSI_T_OK,		//Испр Psi ист ИНС1 в ИВК
INS2_VERT_OK_IVK,	//Испр верт ИНС2 в ИВК
INS2_PSI_M_OK,		//Испр Psi магн ИНС2 в ИВК
INS2_PSI_T_OK,		//Испр Psi ист ИНС2 в ИВК

//выходы РК на адаптере OUT 8
INS1_Model,			//Модель INS1
INS2_Model,			//Модель INS2
RAM_Model,			//Модель RAM
LG_Press_On,		// ШО из модели сам-та на ЗУ

//выходы РК на адаптере OUT 10
TMP_GPS_INS1,		//секундная метка от Модель INS1
TMP_GPS_INS2;		//секундная метка от Модель INS2
} DC_FROM_CC, *PDC_FROM_CC;