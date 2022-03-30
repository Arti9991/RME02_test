#ifndef PC429_4vb
#define PC429_4vb

#pragma pack(push, 1)

#include <rtapi.h>

#include "PC429.h"

// 0: ошибок нет
// 1-56 коды ошибки процедуры err_pc
//			1,2,3 -	ошибка в задании констант INT1,INT2,SA в функ.pc_contr
//			4	- не найдена модификация(Идентификатор) Адаптера в функ. pc_rj
//			10,11,20-23,30,40-42,51-56 - ошибки в тесте ТВК (функц. pc_tvk()
// 61: адаптер не обнаружен
// 62: выходная линия адаптера описана как входная
// 63: запрошенный номер линии на выдачу не соотв. номеру выходной линии на адаптере
// 64: входная линия адаптера описана как выходная
// 65: запрошенный номер линии на прием не соотв. номеру входной линии на адаптере

bool __stdcall vbCreate(short BaseAddr, unsigned char na);
bool __stdcall vbDevice_present(UCHAR na);
bool __stdcall vbSet_board_mode(unsigned __int32 mode, UCHAR na);

//bool __stdcall vbStart_chan_work(char NumChan,char mode, UCHAR na);
//void __stdcall vbStop_chan_work(char NumChan, UCHAR na);

void __stdcall vbClear_data_buf_in(UCHAR na);
void __stdcall vbClear_data_buf_out(UCHAR na);
void __stdcall vbClear_data_glob(UCHAR na);
bool __stdcall vbPut_words_in_outbuf(unsigned __int32 buff[], unsigned __int16 NumWord, char NumChan, UCHAR na);
bool __stdcall vbGet_words_from_inbuf(unsigned __int32 buff[], unsigned __int16 NumWord, char NumChan, UCHAR na);
void __stdcall vbView_BPA (UCHAR na);
void __stdcall vbView_BAV (UCHAR na);
void __stdcall vbView_BAP (UCHAR na);
void __stdcall vbView_BPK (UCHAR na);
void __stdcall vbView_BVK (UCHAR na);
void __stdcall vbView_DAT  (UCHAR na);
void __stdcall vbChoose_Timer (ULONG period);
ULONG __stdcall vbCreate_PC429_4 (DeviceResources DevRes[], PC429INFO Info[], UCHAR na);
void __stdcall vbClose_PC429_4(void);

bool __stdcall vbSend_PC429_4(void);
bool __stdcall vbRecv_PC429_4(void);
bool __stdcall vbPut_PC429_4 (ID_Parameter & glob);
bool __stdcall vbGet_PC429_4 (ID_Parameter & glob);

USHORT __stdcall vbGet_err_PC429_4(UCHAR na);

#endif