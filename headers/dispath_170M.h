// ������������� ���������� Dispath
// ����: size, Name - ������ � ��� ����������� ������,
// cnf - ������� ����, ��� � ������� ������������ �� ������ ����� � ��������������� ������: 
//	���0=1 - ������ ����� "Conf_v1" ... ���7=1 - ������ ����� "Conf_v8", ����� ��������������� ��� =0.
void __stdcall InitDispath(DWORD size, LPSTR Name, unsigned char cnf);

//����� ������� ����������� dll
void __stdcall WorkFunction(void);

// ������� ����
void __stdcall WriteName(void);


//���������� dll
void __stdcall RestartDispath(void);

//�������� ������ � dll 	
void __stdcall CloseDispath(void);
	
