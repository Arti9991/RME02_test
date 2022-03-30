
//-----------------------------------------------------------------------------
//			������
//-----------------------------------------------------------------------------
#define NumTP 6				// ���������� ��

struct bitIBVP {
unsigned long nP				      :5;			//0-4 ��� - ����� �������
unsigned long nErr				      :3;			//5-7 ��� - ����� ������
unsigned long pTime				      :24;			//8-31 ��� - �����
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
//			������� ������� ��� DISP_IO
//-----------------------------------------------------------------------------
long __stdcall IBVP_WriteNameShM (DWORD,LPSTR);	//������� ���� � ShMem � ��������� ��������
//-----------------------------------------------------------------------------
//			������� ������� ��� IBVP
//-----------------------------------------------------------------------------

short __stdcall Create_IBVP ( short );						// ������� ������ ��� ������
short __stdcall Put_IBVP_FIFO (vbIBVP & );		// �������� ������ � FIFO
short __stdcall Put_IBVP_MEM (void);        // ������� �������� ������ � MEMORY
