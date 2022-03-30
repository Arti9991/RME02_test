#ifndef RadarModelH
#define RadarModelH

#if defined(RADAR_MODEL_DLL)
# define RADAR_MODEL     __declspec(dllexport)
#elif defined(RADAR_MODEL_APP)
# define RADAR_MODEL     __declspec(dllimport)
# else
# define RADAR_MODEL
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "windows.h"

// »нициализаци€ библиотеки RadarModel
// ¬ход: size, Name - размер и им€ раздел€емой пам€ти,
RADAR_MODEL void __stdcall InitRadar(DWORD size, LPSTR Name);

//де»нициализаци€ библиотеки RadarModel 	
RADAR_MODEL void __stdcall CloseRadar(void);

//перезапуск dll
RADAR_MODEL void __stdcall RestartRadar(void);

//вызов функций по таймеру
RADAR_MODEL void __stdcall CallRadar(void);

#ifdef __cplusplus
} 		
#endif 
#endif
	
