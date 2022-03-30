// cIUS.h: interface for the cIUS class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIUS_H__5550B4E0_2765_47AC_B568_EB008389AB75__INCLUDED_)
#define AFX_CIUS_H__5550B4E0_2765_47AC_B568_EB008389AB75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define NAC   8     // Размерность массива опасных целей.
#define Stend 1

#if(Stend > 0)
#include <winsock.h>
#pragma comment (lib, "ws2_32.lib")
#include <io.h>
#endif

#define  tuNtipMax    15 // Максимальное число типов заявок 
#define  tuNvarMax     5 // Максимальное число вариантов заявок 
#define  tuNPartZapr  19 // Кол-во элементов вектора частичных запретов 

class cMires;
struct Str_InMFI;

template<class TYPE, class ARG_TYPE> class CList;

struct type_CZO_S
{ 
  float EGC;  // целеуказание по азимуту.
  float EVC;  // целеуказание по углу места.
  float Eg_z; // целеуказание по азимуту.
  float Ev_z; // целеуказание по углу места.
  int   IPr_cy;
};

struct targets;
struct Str_Ptr;

class cIUS
{
public:
	BOOL Play;
  cIUS(cMires*, DispInp*, InterfaceIntegraph*);
  virtual ~cIUS();

  void Disp(double);
  void Disp_KPM21i( double ); 

  void Vhod_KTU();       // Входная информация для СКПО КТУ (tucom)
  void Vhod_SH121();       // Выходная информация для Ш-121 (то, что передаётся по МКИО)
  void Vhod_KGS();       // Входная информация для КГС

private:
  InterfaceIntegraph* pIIExternal;// указатель на структуру параметров штатного МФИ.
  InputH121*          pInpH121;
  Str_InputH036*      pInputH036;// Структура входных параметров Н-036
  VhodPar*            pVhParam;
  Str_InputL402*      pInputL402;
  InterfaceIntegraph MyMFI; // Структура органов управления
  InterfaceIntegraph* pMyMFI;
  Str_Ptr *pFromMires;
  void PRCZ(double, double, double *, double *);
  void Input(InterfaceIntegraph*);
  
  void Send_To_Imitator_MFI( double Ttek );

// для работы на КПМ-21и
  void Input_KPM21i(InterfaceIntegraph* pOrg_Upr);
  void Knup_KPM21i(double Ttek);
  void Map_KPM21i();	
  void NICZO1();

  DispInp * pDisp;
  double  Dlx;    // Начало зоны отрисовки карты по Х
  double  dtt;
  double  Tknup;
  double  Tzkn;
  int     Lxz[3];
  int     Lyz[3];
  int     Masht;
  int     Lmfk;
  int     Pr_Nexit;
  int   P1vhVP;   // Признак первого входа в режим В_П для каждой реализации
  int   P1vhUpr;  // Признак первого входа в подыгрыш управл. МИРЭС
  int     Nf;
  int	decimator;// Прореживатель вызова имитатора МФИ
  DispInp *pDispInp;
  str_Car *pCarrier;
  targets *ptarg;
  type_CZO_S CZO;
  float egmn, evmn, egmx, evmx;
  cMires* pMires;
  Str_InMFI *pInMFI;
#if(Stend > 0)
  // для обмена со стендом интеграф
// ДЛЯ ПРИЁМА ДАННЫХ С МФИ
  HANDLE hEventIntgr;     // для синхронизации с событиями интеграфа
  SOCKET S_Intgr;       // глобальный Сокет
  SOCKET S_Intgr_A;     // установка соединения, чтобы передавать 
  STARTUPINFO Si_MFI;     // 
  PROCESS_INFORMATION Pi_MFI; // 
// ДЛЯ ОТСЫЛКИ ДАННЫХ НА МФИ
  SOCKET SendMFI;       // для отсылки кинематической информации на МФИ
  HANDLE hEvent1,hEvent2;   // hEvent1 - для перерисовки hEvent2 - при новой строке
  HANDLE hMapFile;      // указатель на разделяемую область памяти
  HANDLE hEventIntgrRRV;
  HANDLE hEventIntgrRec;
  PVOID pBuf;
#endif
};

#endif // !defined(AFX_CIUS_H__5550B4E0_2765_47AC_B568_EB008389AB75__INCLUDED_)
