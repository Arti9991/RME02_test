#pragma once

//
#pragma pack(push,1) //Выравнивание полей структур должно быть на 1 байт
//

//	Состояния питания бортовой сети постоянного тока
enum _ENERGY_SYSTEM_DC_STATE
{
	_ENERGY_SYSTEM_DC_OFF = 0,				//	нет напряжения
	_ENERGY_SYSTEM_DC_ACCUMULATOR,		//	питание от бортовых источников (аккумуляторов)
	_ENERGY_SYSTEM_DC_SHRAP,					//	питание от наземного источника
	_ENERGY_SYSTEM_DC_GENERATOR,			//	питание от генератора ГСР
	_ENERGY_SYSTEM_DC_VU							//	питание от выпрямительного устройства (ВУ)
};

//	Состояния питания бортовой сети переменного тока
enum _ENERGY_SYSTEM_AC_STATE
{
	_ENERGY_SYSTEM_AC_OFF = 0,				//	нет напряжения
	_ENERGY_SYSTEM_AC_SHRAP,					//	питание от наземного источника
	_ENERGY_SYSTEM_AC_GENERATOR,			//	питание от генератора ГТ
	_ENERGY_SYSTEM_AC_INV						  //	питание от преобразователя (ПТО)

};

enum _INV_AC_STATE
{
	_INV_AC_STATE_OFF = 0,
	_INV_AC_STATE_STARTING,
	_INV_AC_STATE_STABLE
};



//	Структура выходных данных базовой модели
struct TMMElectroSysDataOut
{
	bool bPowerARU;   		//	Вкл. АРУ
	bool bPowerSOS;   		//	Вкл  СОС
	bool bPowerVLO;				//	Вкл. ВЛО
	bool bPowerSVS;   		//	Вкл. СВС
	bool bPowerRV;    		//	Вкл. Радиовысотомер (RAM - 1701AC)
	bool bPowerSAU;   		//	Вкл. САУ
	bool bPowerENGL;  		//	Вкл. Двигателей левого
	bool bPowerENGR;  		//	Вкл. Двигателей правого
	bool bPowerKUTR;  		//	Вкл. КУТР
	bool bPowerFuelGuageUnit;	//	Вкл. топливомерной системы КУТР
	bool bPowerINP;   		//	Вкл  Индикатор навигационно-плановый (ИНП-РД)
	bool bPowerAGR;   		//	Вкл. Авиагоризонт
	bool bPowerINS1;			//	Вкл. Totem3000-1
	bool bPowerINS2;			//	Вкл. Totem3000-2
	bool bPowerEkran;			//	Вкл. Экрана (Карат)
	bool bPowerPUI;				//	Вкл. ПУИ
	bool bPowerILS;				//	Вкл. ИЛС (ИКШ)
	bool bPowerMFIL;			//	Вкл. МФИ лев.
	bool bPowerMFIR;			//	Вкл. МФИ прав.
	bool bPowerRI;				//	Вкл. РИ МС-2М
	bool bPower833_1;			//	Вкл. Р-833-1
	bool bPower833_2;			//	Вкл. Р-833-2
	bool bPower098;				//	Вкл. Р-098-5Б
	bool bPowerIFF;				//	Вкл. Запросчик-ответчик TSC-2525
	bool bPowerRWR;				//	Вкл. RWR Tarang-1B
	bool bPowerRLS;				//	Вкл. РЛС Жук-МЭ FGM-229
	bool bPowerOLS;			 	//	Вкл. ОЛС
	bool bPowerSUO;				//	Вкл. СУО-29КИ
	bool bPowerCMDS;			//	Вкл. 20СПМ-01И
	bool bPowerBSBP;			//	Вкл. система безопасности полета
	bool bPowerDVRS;			//	Вкл. системы видеорегистрации(СВР) RADA
	bool bPowerTacan;			//	Вкл. Tacan
	bool bPowerVORILSMKR;	//	Вкл. VOR/ILS/MKR
	bool bPowerDASH;			//	Вкл. Нашлемная система целеуказания
	bool bPowerACMI;			//	Вкл. Контейнер ACMI
	bool bPowerSeat1;			//	Питание на Кресло №1
	bool bPowerVSS;				//	Вкл. Система аварийной сигнализации и световые табло
	bool bAvarShina27V;		//	Работа на аварийной шине	(bEmergShina ???)
	bool bMainShina;			//	Работа на основной шине	(???)
	bool bGenPerem;				//	Генератор ~ тока (bACGen)
	bool bGenPost;				//	Генератор = тока (bDCGen)
	bool bDCSysIsOk;			//	Исправ сист пост тока
	bool bPowerSPJ;				//	Вкл. Cистема постоновки активных радио помех (SPJ)
	bool bPowerOxygenSys;	//	питание Кислородной Системы
	bool bPowerVRS;				//	Вкл. ВЗУ

	bool bPower27;				// Наличие питания постоянного тока 27В
	bool bPower36;				// Наличие питания переменного тока 36В 400Гц
	bool bPower115;				// Наличие питания переменного тока 115В 400Гц
	bool bPowerLight;			//	Питание на светотехническое оборудование
	bool bPowerMC1;				//	Вкл. БЦВМ1
	bool bPowerMC2;				//	Вкл. БЦВМ1
	bool bPowerTV_CSU;		//	Вкл. БКТС (Блок коммутации ТВ-сигналов на МФИ)
	bool bPowerADAC;			//	Вкл. УСК-80
	bool bPowerUCP;				//	Вкл. ОПУ (объединенный пульт управления радиостанциями)

	BYTE btAccumCapacity;	// Емкость аккум. батарей (А*ч)			
	float fDCVoltage;			// Вольтметр постоянного тока, В	
	BYTE btACVoltage;			// 100напряжение переменного тока (0-115 В)

	bool bACGen;					// Признак работы генератора переменного тока					(bPowerOfACGen)
	bool bACShrap;				// Признак работы от назем. ист. ~ тока (ШРАП-400-3Ф)	(bPowerOfACAirdrom)
	bool bACInv;					// Питание ~ тока от ПТС
	bool bDCGen;					// Признак работы генератора пост. тока								(bPowerOfDCGen)
	bool bDCShrap;				// Признак работы от назем. ист. = тока (ШРАП-500К)		(bPowerOfDCAirdrom)
	bool bDCVu;						// Питание = тока от ВУ-6
	bool bAccumBat;				// Питание от аккум. батарей													(bPowerOfAccum)
	
	bool bPowerFullUnits;	// Реле мощных потребителей
	bool bTransformPower;   // Работа трансформатора
	bool bRectifierFail;    // Отказ выпрямительного устройства (ВУ)

	bool bElectricBus1;			// Питание на электической шине №1 
	bool bElectricBus2;			// Питание на электической шине №2
	bool bElectricBus3;			// Питание на электической шине №3
	bool bElectricBus4;			// Питание на электической шине №4
	bool bElectricBus5;			// Питание на электической шине №5   (от СУВ ?)
	bool bElectricBus6;			// Питание на электической шине №6
	bool bElectricBus7;			// Питание на электической шине №7
	
	float fDCVoltageDelta;  // Падение напряжения при включении ПТО
	float fDCVoltageMin;
	
	_ENERGY_SYSTEM_DC_STATE	iStateDC;		//	состояние системы постоянного тока
	_ENERGY_SYSTEM_AC_STATE	iStateAC;		//	состояние системы переменного тока

	_INV_AC_STATE iStateINV;						//	состояние работы ПТО
};

#pragma pack(pop)