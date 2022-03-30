
short __stdcall Start_DISP(unsigned __int16);
short __stdcall Finish_DISP(void);
void __stdcall Code_ASP(unsigned __int8, unsigned __int8);       // 
void __stdcall Type_MKIO(unsigned __int8, unsigned __int8);

void __stdcall Write_K(unsigned __int8 , unsigned __int8);
void __stdcall Read_S(unsigned __int8 &, unsigned __int8);
void __stdcall Read_Shod(unsigned __int8 &, unsigned __int8);
void __stdcall Read_RT(unsigned __int8 &, unsigned __int8);

void __stdcall Write_MH1(unsigned __int16 , unsigned __int8);
void __stdcall Write_MH2(unsigned __int16, unsigned __int8);
void __stdcall Write_MH3(unsigned __int16, unsigned __int8);
void __stdcall Write_MH4(unsigned __int16, unsigned __int8);
void __stdcall Write_MH5(unsigned __int16, unsigned __int8);
void __stdcall Write_TargLat(double, unsigned __int8);
void __stdcall Write_TargLon(double, unsigned __int8);
void __stdcall Write_TargNum(unsigned __int8, unsigned __int8);
void __stdcall Write_SIMUL(unsigned __int32, unsigned __int8);

void __stdcall Read_MR1(unsigned __int16 &, unsigned __int8);
void __stdcall Read_MR2(unsigned __int16 &, unsigned __int8);