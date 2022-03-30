#ifndef PCADS05_vb
#define PCADS05_vb

#pragma pack(push, 1)
#include "CommonDef.h"

const int MAX_RK_INPUT = 64;
const int MAX_RK_OUTPUT = 64;

//описание структуры линии дл€ ARINC429
struct ARINC_PCADS {
 unsigned __int32 OutFreq;					//	несуща€ частота в √ц
 unsigned __int32 NumWord;
};

//информаци€ дл€ настройки
struct PCADS05INFO {
 ARINC_PCADS PCADS_Batch[96];	// массив с описанием параметров линий дл€ конкретной платы
 //[0..31] - прием, [32-63] - передача, [64-95] - подмена.
};

struct PCADS05RKINFO {
	unsigned __int32 InputRK[MAX_RK_INPUT];
	unsigned __int32 OutputRK[MAX_RK_OUTPUT];
 };

__int32 __stdcall vbCreate_PCADS05(PCADS05INFO &Info);
void __stdcall vbClose_PCADS05();
void __stdcall vbSend_PCADS05();
void __stdcall vbPut_PCADS05(ID_Parameter & glob);
void __stdcall vbGet_PCADS05(ID_Parameter & glob);

__int32 __stdcall vbCreate_PCADS05K(void);
void __stdcall vbClose_PCADS05K();
void __stdcall vbPut_PCADS05K(ID_Parameter & glob);

__int32 __stdcall vbCreate_PCADS05RK(PCADS05RKINFO &Info);
void __stdcall vbPut_PCADS05RK(ID_Parameter & glob);
void __stdcall vbSend_PCADS05RK();
void __stdcall vbGet_PCADS05RK(ID_Parameter & glob);
void __stdcall vbRecv_PCADS05RK();
void __stdcall vbClose_PCADS05RK();

#endif