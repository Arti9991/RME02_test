// #RS422_prep.h

//.......Интерфейсные функции.................
long __stdcall RS422p_Init(DWORD size, LPSTR Name);//Задаётся имя и размер общей РП
void  __stdcall RS422p_Action(void);//RS422/485
//Эмуляция стенда 170
void  __stdcall RS422p_SetParamDub(void); // От Дубова
