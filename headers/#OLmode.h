//
// #OLmode.H
//

#include <windows.h>
#include <rtapi.h>

//=======Команда на сброс рабочего файла на диск ===============
//		запускать в медленном таймере
//		Признак регистрации в mpi.ini
long  __stdcall OLM_WriteFileMPI(int pStop);
long  __stdcall OLM_WriteFullFileMPI();
//=======================================================================
// Descr: Функция рассчитывает период прерываний и записывает в SHM
// Если Тмпи=0 -> возвращает внешний период.
// если внешний период =0, возвращает период из ini-файла
// Input : период из ini-файла,
// Output : KssrToSam32Dll.dt (структура Hli в struct_in_out.h)
// Returns: 0-Succsess 
//=======================================================================
long __stdcall	OL_GetMPI_TI(LARGE_INTEGER t_ini,LARGE_INTEGER t_extern, long use_IRQ);

//=======================================================================
// Descr: 
// Input : 
// Output : 
// Returns: 0-Succsess 
//=======================================================================
//long __stdcall	OL_Init(long thisPC);
long __stdcall	OL_Init(DWORD size, LPSTR Name);
//=======================================================================
// Descr: 
// Input : 
// Output : 
// Returns: 0-Succsess 
//=======================================================================
long __stdcall	OL_Close();
long __stdcall  OL_ReStart();
long __stdcall	OL_InterruptHandler();

long  __stdcall OLM_GetVersion();
//=======================================================================
// Descr: Пропись полей в SHM 
// Returns: 0-Succsess 
//=======================================================================
long  __stdcall OL_WriteFieldInfo_SHM(void);

long WriteMPIdt_SHM(double dt);
