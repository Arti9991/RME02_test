unsigned char KssrDataPut = 0; 	//		1: ������� ��������� ������� ������ � ShMem ���������� #kssr_func.dll
																																//  #kssr_func.dll ������������� � 0xFF
																																//  #sss.dll �������� 0-� ���
unsigned char KssrDataGet = 0; 	//		1: ������� ���������� ������ ������ �� ShMem ���������� #kssr_func.dll
																																//  #kssr_func.dll ������������� � 0xFF
																																//  #sss.dll �������� 0-� ���
unsigned char SSSDataPut = 0;			//		1:  ������� ��������� ������� ������ � ShMem ���������� #sss.dll
																																//  #sss.dll ������������� � 0xFF
																																//  #kssr_func.dll �������� 0-� ���
unsigned char SSSDataGet = 0;			//		1:  ������� ���������� ������ ������ �� ShMem ���������� #kssr_func.dll
																																//  #sss.dll ������������� � 0xFF
																																//  #kssr_func.dll �������� 0-� ���

unsigned char* pKssrDataPut = & KssrDataPut;
unsigned char* pSSSDataPut		= & SSSDataPut;
unsigned char* pKssrDataGet = & KssrDataGet;
unsigned char* pSSSDataGet		= & SSSDataGet;
// ----------------------------------------------------------------------------

// Share Memory
long __stdcall SSS_cnfg_ShMem (DWORD size, LPSTR Name);//������ ����������� ������ � �� ���
void __stdcall convSTRUC_SSS(long direction);
void __stdcall STEP_SSS(void);
void __stdcall vbChoose_Timer_sss (unsigned long period);
void __stdcall vbSoundOn (void);
void __stdcall vbSoundOff (void);
