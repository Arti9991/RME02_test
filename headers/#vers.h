
//#vers.h
//������� �-�� ��� ������ ������ ���������� ��� ����������

//	Author T.Gorokhova


#include <windows.h>

long __stdcall vbGetFileVersion(HMODULE hmHandle, DWORD &dwL,DWORD &dwH);
long __stdcall vbGetFileVersionByName(char* szModName, DWORD &dwL,DWORD &dwH);

