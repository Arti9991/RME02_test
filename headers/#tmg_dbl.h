#ifndef TMG
#define TMG

#include <limits.h>
#include <float.h>

//LARGE_INTEGER Frequency_tmg;
//double dbl_Frequency_tmg;

#pragma pack(push, 1)   

struct TIMING // Структура измерения времени
 { 
 // Переменные
 LARGE_INTEGER Frequency_tmg;
 LARGE_INTEGER t, t1, t2, dtcurr, dtmin, dtmax;
 UINT64 corr; 

 // Функции
 void RESET (void)
  {
  t1.QuadPart = 0; t2 = t1;
  dtcurr.QuadPart=0; dtmin.QuadPart=LLONG_MAX; dtmax.QuadPart=LLONG_MIN;
  return;
  }

 void START (void)
  {
  QueryPerformanceCounter( &t1 );
  return;
	 }

 void STOP  (void)
	 {
  QueryPerformanceCounter( &t2 );
  return;
	 }

 LONGLONG DT(void)
  {
  dtcurr.QuadPart = (t2.QuadPart - t1.QuadPart)*(1000000000*corr/ Frequency_tmg.QuadPart)/10000; // время в нс
  if (dtmin.QuadPart > dtcurr.QuadPart) dtmin.QuadPart = dtcurr.QuadPart;     // время в нс
  if (dtmax.QuadPart < dtcurr.QuadPart) dtmax.QuadPart = dtcurr.QuadPart;     // время в нс
  return dtcurr.QuadPart;
  }

 LONGLONG NOW(void)
 {
 QueryPerformanceCounter(&dtcurr);
 dtcurr.QuadPart = dtcurr.QuadPart*(1000000000*corr / Frequency_tmg.QuadPart)/10000; // время в нс
 return dtcurr.QuadPart;
 }

 // Коррекция времени
 // now : время определенное c помощью структуры TIMING (в любых единицах)
 // must: время реальное в этих же единицах
 void CORRECTION(UINT32 must, UINT32 now)
 {
 if (must == 0) return;
 if ( must > now )
  {
  if ( (must - now)*10 > must ) return;
  }
 else
  {
  if ( (now - must)*10 > must ) return;
  }
 corr = (UINT64) corr*must/now;
 return;
 }


 TIMING(void)
 {
  DWORD f;
  t1.QuadPart = 0; t2 = t1;
		corr = 10000;
  dtcurr.QuadPart = 0; dtmin.QuadPart = LLONG_MAX; dtmax.QuadPart = LLONG_MIN;
  if (Frequency_tmg.QuadPart == 0) QueryPerformanceFrequency(&Frequency_tmg);          // Частота процессора в [кГц для windows 7 и в гц для XP]
#ifdef tmgHz
  Frequency_tmg.QuadPart = Frequency_tmg.QuadPart/1000;
#endif
  f = GetLastError();
  };

 };
//  !!!! НЕ ПОЛЬЗОВАТЬСЯ в процерурах обработки прерываний в RTSS !!!
struct TIMING_DBL // Структура измерения времени
 { 
 // Переменные
 double dbl_Frequency_tmg;

 LARGE_INTEGER t;
 double dbl_t1, dbl_t2, dbl_dtcurr, dbl_dtmin, dbl_dtmax, corr;

 // Функции
 void RESET (void)
  {
  dbl_t1 = 0; dbl_t2 = 0; dbl_t1 = 0;
  dbl_dtcurr = 0; dbl_dtmin = DBL_MAX; dbl_dtmax = DBL_MIN;
  return;
  }

 void START (void)
 {
  QueryPerformanceCounter( &t );
  dbl_t1 = (double) t.QuadPart*1000000000*corr;
  return; }

 void STOP  (void) {
  QueryPerformanceCounter( &t );
  dbl_t2 = (double) t.QuadPart*1000000000*corr;
 return; }

 LONGLONG DT(void)
 {
  dbl_dtcurr = (dbl_t2 - dbl_t1)/ dbl_Frequency_tmg;      // время в нс
  if (dbl_dtmin > dbl_dtcurr) dbl_dtmin = dbl_dtcurr;     // время в нс
  if (dbl_dtmax < dbl_dtcurr) dbl_dtmax = dbl_dtcurr;     // время в нс
  return (double) dbl_dtcurr;
 }

 LONGLONG NOW(void)
 {
 QueryPerformanceCounter(&t);
 dbl_dtcurr = t.QuadPart/dbl_Frequency_tmg*1000000000.*corr;  // время в нс
 return (double) dbl_dtcurr;
 }

	 // Коррекция времени
 // now : время определенное c помощью структуры TIMING (в любых единицах)
 // must: время реальное в этих же единицах
 void CORRECTION(double must, double now)
 {
 if (must == 0) return;
 if ( must > now )
  {
  if ( (must - now)*10 > must ) return;
  }
 else
  {
  if ( (now - must)*10 > must ) return;
  }
 corr = corr*must/now;
 return;
 }

 TIMING_DBL(void)
 {
  DWORD f;
  dbl_t1 = 0; dbl_t2 = 0, corr = 1.;
  dbl_dtcurr = 0; dbl_dtmin = DBL_MAX; dbl_dtmax = DBL_MIN;
  if (dbl_Frequency_tmg == 0) QueryPerformanceFrequency(&t);          // Частота процессора в [кГц для windows 7 и в гц для XP]
  dbl_Frequency_tmg = (double) t.QuadPart;
  f = GetLastError();
  };

 };

#pragma pack(pop)   

#endif