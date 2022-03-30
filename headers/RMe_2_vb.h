#ifndef RMe_2_vb
#define RMe_2_vb

#pragma pack(push, 1)

#include "CommonDef.h"
#include "RMe_2_ExternFunctions.h"

__int64 __stdcall  vbCreate_RMe_2();
void __stdcall vbClose_RMe_2();
void __stdcall WriteData_RMe_2(ID_Parameter & glob);
void __stdcall ReadData_RMe_2(ID_Parameter & glob);

#endif