// ????????? ? ??????? ?-?? ??? ?????? ? ????????? ??
// #Astra_CLS.H
//	Author T.Gorokhova

#include <windows.h>

#if defined(WIN32)
# define EXPORT_CL __stdcall
#else
# define EXPORT_CL _export far pascal
#endif

//=========================================================================
// ??????? ???????? ??????
//=================================================================
//=================================================================
//=================================================================
// NumDevice    ;	// ?????????? ????? ???????? ??????? ???? ? ?????? ??), ??????? ? 0. 
					//? ?? - ????? ? 1, ?? IPC ?????????? ? 0 !!!!!

// ?????????? 
// __SUCCESS:				?????????? ???????? ?????,??????? ????? ? ???????? ????????.
// ERROR_MEM_LOCATION		-1  ?????? ???????? ???????
// INVALID_BASE_ADDRESS		-2
// ERROR_ADAPTER_NOT_FOUND	-3
// ERROR_DATA_NOT_EQUAL		-4
long __stdcall vbCreate_AstraPCI_BL(ULONG NumDevice);								

//=========================================================================
// ????? ?????? ?? ???
// ?????????? 0;
//=================================================================
long  __stdcall vbRecv_AstraPCI_BL(void);
//=================================================================
//	?????? ?????????? 
// ????:
// Address		:18  =StrDescr.Address - 18-????. ????? ??? 
// NumWord	:3;	// 0, 1..4 StrDescr.NumWord (???? 21-23)-????? ??????????? ?????? ??? ???????, 
				// 0 - ??????? ?????????? 
// ?????:
// Data		  =	???????? ???????? ????? - ??????? 16 ???,
//				???? - ??????? 14 ???
// ???????????? ????????
// ?????????? :
//  0 - ??
// -2 - ?????? ??????? ??????
// -1 - ??????? ??????????
//=================================================================
 long  __stdcall vbRead_AstraPCI_BL(ID_Parameter &Param );
//=========================================================================
 long  __stdcall vbClose_AstraPCI_BL();
//------------------------------ ????????? ???????-------------------------
// ?????????? ????? ??????
//=========================================================================
long __stdcall vbGetVersionAstraPCI_BL(void);
