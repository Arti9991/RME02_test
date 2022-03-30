#ifndef PC429_3vb
#define PC429_3vb

#pragma pack(push, 1)

#include <rtapi.h>

#include "PC429.h"

// 0: ������ ���
// 1-56 ���� ������ ��������� err_pc
//			1,2,3 -	������ � ������� �������� INT1,INT2,SA � ����.pc_contr
//			4	- �� ������� �����������(�������������) �������� � ����. pc_rj
//			10,11,20-23,30,40-42,51-56 - ������ � ����� ��� (�����. pc_tvk()
// 61: ������� �� ���������
// 62: �������� ����� �������� ������� ��� �������
// 63: ����������� ����� ����� �� ������ �� �����. ������ �������� ����� �� ��������
// 64: ������� ����� �������� ������� ��� ��������
// 65: ����������� ����� ����� �� ����� �� �����. ������ ������� ����� �� ��������

bool __stdcall vbCreate(short BaseAddr, unsigned char na);
bool __stdcall vbDevice_present(UCHAR na);
bool __stdcall vbSet_board_mode(USHORT  mode, UCHAR na);
bool __stdcall vbSet_chan_mode(char NumChan,char mode, UCHAR na);
bool __stdcall vbStart_chan_work(char NumChan,char mode, UCHAR na);
void __stdcall vbStop_chan_work(char NumChan, UCHAR na);
void __stdcall vbClear_data_buf_in(UCHAR na);
void __stdcall vbClear_data_buf_out(UCHAR na);
void __stdcall vbClear_OZU(UCHAR na);
bool __stdcall vbPut_words_in_outbuf(ULONG buff[], USHORT NumWord, char NumChan, UCHAR na);
bool __stdcall vbGet_words_from_inbuf(ULONG buff[], USHORT NumWord, char NumChan, UCHAR na);
void __stdcall vbView_TAB_SI_0 (short N, UCHAR na);
void __stdcall vbView_TAB_SI_1 (short N, UCHAR na);
void __stdcall vbView_TAB_SO_0 (short N, UCHAR na);
void __stdcall vbView_TAB_SO_1 (short N, UCHAR na);
void __stdcall vbView_DAT  (short shift, short N, UCHAR na);
void __stdcall vbChoose_Timer (ULONG period);
ULONG __stdcall vbCreate_PC429_3 (DeviceResources DevRes[], PC429INFO Info[], UCHAR na);
void __stdcall vbClose_PC429(void);

bool __stdcall vbSend_PC429(void);
bool __stdcall vbRecv_PC429(void);
bool __stdcall vbPut_PC429 (ID_Parameter & glob);
bool __stdcall vbGet_PC429 (ID_Parameter & glob);

USHORT __stdcall vbGet_err_PC429_3(UCHAR na);

#endif