#ifndef vbPci1753_H
#define vbPci1753_H

#include <windows.h>
#include <rtapi.h>

// na						:	кол-во адаптеров данного типа на данной IPC (нумерация с 1)
// DevRes[]: массив структур с параметрами адаптера
//
unsigned long __stdcall vbCreate_Pci1753 (DeviceResources DevRes[], unsigned char na);

bool __stdcall vbPut_Pci1753 (ID_Parameter & glob);
bool __stdcall vbPutClass_Pci1753 ( unsigned char na, unsigned char CH, unsigned char Port, unsigned char Address, unsigned char Data );
bool __stdcall vbSend_Pci1753 (void);

bool __stdcall vbGet_Pci1753 (ID_Parameter & glob);
bool __stdcall vbGetClass_Pci1753 (unsigned char na, unsigned char CH,unsigned char Port, unsigned char Address, unsigned char & Data );
bool __stdcall vbRecv_Pci1753 (void);

void __stdcall vbChoose_Timer_Pci1753 (unsigned long period);

#endif