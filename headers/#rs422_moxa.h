//#rs422_moxa.h
// структуры и внешние ф-ии для работы с адаптером RS-422/485

//	Author T.Gorokhova

#include <windows.h>



//=========================================================================
// ФУНКЦИИ ВНЕШНЕГО ВЫЗОВА
//=================================================================
long __stdcall	vbCreate_RS422_MOXA(DeviceResources DevRes[],RS422_MOXA_INFO inf[], short MaxNumDevs);
long __stdcall vbClose_RS422_MOXA();
long __stdcall vbWrite_RS422_MOXA(ID_Parameter param );
long __stdcall vbRead_RS422_MOXA( ID_Parameter param );
long __stdcall vbSend_RS422_MOXA();
long __stdcall vbRecv_RS422_MOXA();

LPVOID __stdcall vbCreateSharedMem (LPSTR ShmName, DWORD ShmSize);
void __stdcall vbCloseSharedMem();
void __stdcall vbWriteSharedMem(PUCHAR buf, ULONG Offset, ULONG Size);
void __stdcall vbReadSharedMem(PUCHAR buf, ULONG Offset, ULONG Size);



