// #RS422_prep.h

//.......������������ �������.................
long __stdcall RS422p_Init(DWORD size, LPSTR Name);//������� ��� � ������ ����� ��
void  __stdcall RS422p_Action(void);//RS422/485
//�������� ������ 170
void  __stdcall RS422p_SetParamDub(void); // �� ������
