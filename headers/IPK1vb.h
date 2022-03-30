#include <windows.h>
#include <rtapi.h>

// na						:	кол-во адаптеров данного типа на данной IPC (нумерация с 1)
// DevRes[]: массив структур с параметрами адаптера
//
unsigned long __stdcall vbCreate_IPK1 (DeviceResources DevRes[], unsigned char na);

bool __stdcall vbPut_IPK1 (ID_Parameter & glob);
unsigned long __stdcall vbGetReady_IPK1 (ID_Parameter & glob);
void __stdcall vbChoose_Timer_IPK1 (unsigned long period);

