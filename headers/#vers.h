
//#vers.h
//внешние ф-ии для чтения версии приложения или библиотеки

//	Author T.Gorokhova


#include <windows.h>

long __stdcall vbGetFileVersion(HMODULE hmHandle, DWORD &dwL,DWORD &dwH);
long __stdcall vbGetFileVersionByName(char* szModName, DWORD &dwL,DWORD &dwH);

