
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CMIRES_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CMIRES_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

#include "..\\@include\\CommonForMires.h"

#ifdef CMIRES_EXPORTS
#define CMIRES_API __declspec(dllexport)
#else
//#define CMIRES_API __declspec(dllimport)
#define CMIRES_API 
#endif

class cRLK_X;
class cGO;
class CSRTRImitation;
class CSRTR;
struct type_CONTRL;
struct str_Car;
struct targets;
struct Str_InMFI;

typedef struct Str_Ptr_Item
{// Структура указателей на компоненты класса cMires.
	cRLK_X         * pBrls;  // БРЛС
	CSRTRImitation * pSRTRImitation;
	CSRTR          * pSRTR;  // РТР
} Str_Ptr_Item;

typedef struct ParamForOutN036VV
{
//	int PrI; // Режим излучения
	unsigned PrI; // Режим излучения
//	int PrOI;// Признак обновления информации
	unsigned char PrOI;// Признак обновления информации
	double D; // Измеренная дальность до цели
	double Vs;// Измеренная скорость сближения с целью
	double Az;// Измеренный угол азимута цели
//	float Um;// Измеренный угол места цели
	double Um;// Измеренный угол места цели
	unsigned Hour;// Часы
	unsigned Min; // Минуты
	unsigned Sec; // Секунды
	double MSec;// Доли секунды
	unsigned Nl; // Номер цели назначенный Н-036
//	int Nl; // Номер цели назначенный Н-036
//	int Kanal;// Канал X/L
	unsigned char Kanal;// Канал X/L
	unsigned char PrR; // Признак ДС/СНП
//	int PrR; // Признак ДС/СНП
	int RezGO;// Результат ГО
	int PrGO; // Дополнительные признаки ГО
} ParamForOutN036VV;

typedef struct AllParamForOutN036VV
{
	int VV_X;    // Включение режима "воздух-воздух"
//	int No_zon_X;// Номер зоны РЛК-Х
	ParamForOutN036VV Par[20];// Массив параметров
} AllParamForOutN036VV;

// This class is exported from the cMires.dll
class CMIRES_API cMires
{
public:
	cMires(type_CONTRL*);              // Не используется в cMires.dll
	cMires(DispInp*, strInputFromFPO*);// Используется в cMires.dll

	virtual ~cMires();

	// Функции для пользователей класса cMires. //////////////////////////////
	void RunRTR(double);   // Запуск модели РТР.
	void RunGOcu(double);        // Запуск модели ГО(ЦУ).
	void RunRadar(double); // Запуск модели БРЛС.
	Str_Ptr* GetPtr( int init_pr );     // Выдача указателей на внутренние объекты класса
	                       // для его пользователей.
	void CleanPar();       // Подготовка к новой реализации.
	AllParamForOutN036VV ParVV;// Выходные параметры.
	strPIV_L402_out* GetPIV_L402(); 
	//////////////////////////////////////////////////////////////////////////
	//////////// Служебные функции класса cMires /////////////////////////////
	int GetNTargVO();
	inline targets* GetTarget(){ return &Targ[0]; };
	Str_Ptr_Item* GetPtrToItem();
	//////////////////////////////////////////////////////////////////////////

private:
	Str_Ptr StrPtr;
	Str_Ptr_Item StrPtrItem;
	//////////// Компоненты класса cMires ////////////////////////////////////
	cGO    *GO;   // ГО
	cRLK_X *Brls; // БРЛС
	CSRTRImitation *SRTRImitation;
	CSRTR  *SRTR; // РТР
	//////////////////////////////////////////////////////////////////////////
	type_CONTRL * CTRL; // Внутренняя структура параметров.
	DispInp *DI;        // Входная структура параметров.
	Str_InputH036 InputH036;  // Структура входных параметров Н-036
  Str_InputL402 InputL402;
	InputH121 InpH121;	      // Структура входных параметров Н-121
	OutputH121   OutH121;
	VhodPar VhParam;          // Входные параметры БРЛС.
	strOutputForFPO OutputForFPO;// Выходная информация для ФПО.
	targets Targ[NC];// Параметры целей.
	str_Car Carrier; // Параметры носителя.
	Str_InMFI InMFI; // Выходные параметры для индикации на МФИ.
};
