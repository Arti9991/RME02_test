
#ifndef COCKPITtoCC_H
#define COCKPITtoCC_H 

#include "windows.h"
long __stdcall InitCockpit(DWORD size, LPSTR Name);//Размер разделяемой памяти и ее имя
void __stdcall UnPakCockpit(void);
void __stdcall CloseCockpit(void);

//параметры от кабины на ВЦ (120 Байт)
struct str_COCKPITtoCC
{

//	COCPtoCC->

//аналоговые сигналы, диапазон 0-10В
double
RUS_TANG,	//РУС по тангажу
RUS_KREN,	//РУС по крену
Pedal,	//педали
PedalTormL,	//педальный тормоз левый
PedalTormR,	//педальный тормоз правый 
RudL,		//РУД левый
RudR,		//РУД правый
Uoc;		//Положение АТ обр связь
//аналоговые сигналы КУ-31, ± 10В 
double
Uy,	// КУ-31, Alfa Z
Ux;	// КУ-31, Betta Y

//разовые команды из кабины
UCHAR
OtklSAU,	//Откл САУ
Manevr,		//Маневр
ShU,		//ШУ
ShV,		//ШВ
SnatPam,	//Снятие памяти
Uvod,		//Увод 
Otkaz,		//отказ
PKZakrR,	//ПК закр правый
PKZakrL,	//ПК зак левый
GashSAU,	//Гашетка САУ
PG,			//ПГ
TrimLKR,	//Трим левый крен
TrimRKR,	//Трим правый крен
TrimKabr,	//Трим кабрирование
TrimPik,	//Трим пикирование
StartTorm,	//Старт тормоз
SAUOsn,		//САУ основн
AUT,		//АУТ
AVT,		//АВТ
DOZ,		//ДОЗ
TRUpr,		//Траект Управл
Hbar,		//Нбар
SAURez,		//САУ резерв
Knuppel,	//КУ-31 кнопка

Radio,		//Радио
Sbros,		//Сброс
Vvod,		//Ввод
SelectTP,	//Выбор подвесок
Fire,		//Огонь
Sight,		//Прицел
IspCom,		//Исполн команд
Sbros_LTC,	//Сброс до ЛТЦ
Main,		//Главный вкл
OPS1,		//4КНР УПР ОПС "1"
OPS2,		//4КНР УПР ОПС "2"
OPS3,		//4КНР УПР ОПС "3"
OPS4,		//4КНР УПР ОПС "4"
VzadUp,		//Vзад больше
VzadDn;		//Vзад меньше

UCHAR Rezerv;
};


//параметры от ВЦ в кабину (40 Байт)
struct str_CCtoCOCP
{
//CCtoCOCP->
//аналоговые сигналы в кабину, диапазон В
double
U_AT;	//Напр автомата управления

//разовые команды в кабину
UCHAR
Avariya,	//Авария
Fire,	//Пожар
Gidro,	//Гидро
Alfa_Ny_kritih,	//Ny критичное
Otk_PRT,	//отказ ПРТ
Naz_contrl,	//Наз контроль
KB_chassi,	//КВ шасси
Test,	//Тест
Otkaz,	//Отказ
Fire_Left_eng,	//Пожар лев двиг
PK_left_zakr,	//ПК закр левый 
Fire_Right_eng,	//Пожар прав двиг
PK_right_zakr,	//ПК закр правый 
Upr_ruch,	//Управл в ручную
Man_SDU,	//Маневр СДУ
Uvod,	//Увод
AT_On,	//Вкл АТ
SAU_osn,	//САУ осн
AUT,	//АУТ
Avt,	//АВТ
Doz,	//ДОЗ
TraektUpr,	//Траект Управл
Hbar,	//Нбар
SAU_rez,	//САУ резерв
SDU;	//СДУ
UCHAR Rezerv[7];
};


#endif