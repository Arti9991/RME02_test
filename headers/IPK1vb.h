#include <windows.h>
#include <rtapi.h>

// na						:	���-�� ��������� ������� ���� �� ������ IPC (��������� � 1)
// DevRes[]: ������ �������� � ����������� ��������
//
unsigned long __stdcall vbCreate_IPK1 (DeviceResources DevRes[], unsigned char na);

bool __stdcall vbPut_IPK1 (ID_Parameter & glob);
unsigned long __stdcall vbGetReady_IPK1 (ID_Parameter & glob);
void __stdcall vbChoose_Timer_IPK1 (unsigned long period);

