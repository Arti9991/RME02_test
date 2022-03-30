//////////////////////////////////////////////////////////////////
//
//	MCS_CC.h - header file
//
// This file was generated using the RTX Application Wizard 
// for Visual Studio.  
//////////////////////////////////////////////////////////////////

#include <windows.h>
#include <rtapi.h>
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <errno.h>

#define LAMP_ON		1
#define LAMP_OFF	0
#define LAMP_BLINK	2

#include  "Airplane29UPG.h"

#if defined(MCS_CC_DLL)
# define MCS_CC_API __declspec(dllexport)
#elif defined(MCS_CC_APP)
# define MCS_CC_API __declspec(dllimport)
# else
# define MCS_CC_API
#endif

// Add DEFINES Here

//  Add Function prototypes Here

MCS_CC_API VOID __stdcall Init_MCS_CC(TPLANE_IN *, TPLANE_OUT *, int PrintOkEn, int PrintErrEn);
MCS_CC_API VOID __stdcall Close_MCS_CC(VOID);

void RecvPacket(void);
void WriteNameToShm(void);