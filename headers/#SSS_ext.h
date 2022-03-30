unsigned char KssrDataPut = 0; 	//		1: признак прошедшей посылки данных в ShMem процедурой #kssr_func.dll
																																//  #kssr_func.dll устанавливает в 0xFF
																																//  #sss.dll обнуляет 0-й бит
unsigned char KssrDataGet = 0; 	//		1: признак прошедшего приема данных из ShMem процедурой #kssr_func.dll
																																//  #kssr_func.dll устанавливает в 0xFF
																																//  #sss.dll обнуляет 0-й бит
unsigned char SSSDataPut = 0;			//		1:  признак прошедшей посылки данных в ShMem процедурой #sss.dll
																																//  #sss.dll устанавливает в 0xFF
																																//  #kssr_func.dll обнуляет 0-й бит
unsigned char SSSDataGet = 0;			//		1:  признак прошедшего приема данных из ShMem процедурой #kssr_func.dll
																																//  #sss.dll устанавливает в 0xFF
																																//  #kssr_func.dll обнуляет 0-й бит

unsigned char* pKssrDataPut = & KssrDataPut;
unsigned char* pSSSDataPut		= & SSSDataPut;
unsigned char* pKssrDataGet = & KssrDataGet;
unsigned char* pSSSDataGet		= & SSSDataGet;
// ----------------------------------------------------------------------------

// Share Memory
long __stdcall SSS_cnfg_ShMem (DWORD size, LPSTR Name);//Размер разделяемой памяти и ее имя
void __stdcall convSTRUC_SSS(long direction);
void __stdcall STEP_SSS(void);
void __stdcall vbChoose_Timer_sss (unsigned long period);
void __stdcall vbSoundOn (void);
void __stdcall vbSoundOff (void);
