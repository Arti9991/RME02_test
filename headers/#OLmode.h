//
// #OLmode.H
//

#include <windows.h>
#include <rtapi.h>

//=======������� �� ����� �������� ����� �� ���� ===============
//		��������� � ��������� �������
//		������� ����������� � mpi.ini
long  __stdcall OLM_WriteFileMPI(int pStop);
long  __stdcall OLM_WriteFullFileMPI();
//=======================================================================
// Descr: ������� ������������ ������ ���������� � ���������� � SHM
// ���� ����=0 -> ���������� ������� ������.
// ���� ������� ������ =0, ���������� ������ �� ini-�����
// Input : ������ �� ini-�����,
// Output : KssrToSam32Dll.dt (��������� Hli � struct_in_out.h)
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
// Descr: ������� ����� � SHM 
// Returns: 0-Succsess 
//=======================================================================
long  __stdcall OL_WriteFieldInfo_SHM(void);

long WriteMPIdt_SHM(double dt);
