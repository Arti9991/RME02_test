
//-----------------------------------------------------------------------------
//			Данные
//-----------------------------------------------------------------------------
#define NumTP 6				// Количество ТП

struct bitIBVP {
unsigned long nP				      :5;			//0-4 бит - номер патрона
unsigned long nErr				      :3;			//5-7 бит - номер ошибки
unsigned long pTime				      :24;			//8-31 бит - время
};

struct strIBVP {
	bitIBVP X1;
	bitIBVP X2;
	bitIBVP X3;
	bitIBVP X4;
	bitIBVP X5;
	bitIBVP X6;
} *IBVP;

typedef struct {
	unsigned long Time;
	unsigned char TP_N;
	unsigned char PatronN;
	unsigned short Err;
	unsigned char Xi;
} vbIBVP;

//-----------------------------------------------------------------------------
//			Внешние функции для DISP_IO
//-----------------------------------------------------------------------------
long __stdcall IBVP_WriteNameShM (DWORD,LPSTR);	//Пропись имен в ShMem и установка признака
//-----------------------------------------------------------------------------
//			Внешние функции для IBVP
//-----------------------------------------------------------------------------

short __stdcall Create_IBVP ( short );						// Открыть память для записи
short __stdcall Put_IBVP_FIFO (vbIBVP & );		// Передача данных в FIFO
short __stdcall Put_IBVP_MEM (void);        // Функция передачи данных в MEMORY
