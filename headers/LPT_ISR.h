/*Драйвер LPT для обработки прерываний

ГосНИИАС
Гурвиц Александр Валерьевич
*/

//---------------------------------------------------------------------------
#ifndef LPT_ISRH
#define LPT_ISRH
//---------------------------------------------------------------------------
#include "windows.h"

// Define RTAPI function calling convention unless an override is in effect.
#ifndef RTAPI
#       if (defined(_MSC_VER)&&(_MSC_VER >= 800)) || defined(_STDCALL_SUPPORTED)
#              define RTAPI __stdcall
#       else
#              define RTAPI
#       endif
#endif
// Define the declaration for application provided functions.
#define RTFCNDCL RTAPI

//Коды ошибок LPT_ISR
#define ErrorLPT_Ok			0x0//все нормально!
#define ErrorLPT_InitPort		0x1//ошибка открытия порта
#define ErrorLPT_InitISR		0x2//ошибка инициализации ISR

//размер области портов ввода-вывода
#define SIZE_PIO_LPT            0x3

//смещение регистра состояния
#define STATUSCREG          0x1
//смещение командного регистра
#define CREG                0x2

//бит разрешения прерывания
#define ASK          0x10

#if defined(LPT_ISR_DLL)
# define LPT_ISR_CLASS __declspec(dllexport)
#elif defined(LPT_ISR_APP)
# define LPT_ISR_CLASS __declspec(dllimport)
# else
# define LPT_ISR_CLASS
#endif

class LPT_ISR_CLASS LPT_ISR{
public:
        LPT_ISR();
       ~LPT_ISR();

//Инициализация ISR
void InitISR(VOID (RTFCNDCL *pRoutine)(PVOID context));

//ДеИнициализация ISR
void CloseISR(void);

//Запись UCHAR Data в порт данных
void SetData(UCHAR Data);

//Чтение UCHAR из порта данных
UCHAR GetData();

//Запись UCHAR Data в порт управления
void SetCtrl(UCHAR Data);

//Чтение UCHAR из порта управления
UCHAR GetCtrl();

//Чтение UCHAR из порта состояния
UCHAR GetStatus();

long GetLastErrorLPT(void);

protected:
ULONG BaseAddrPIO;  //базовый адрес портов ввода-вывода
HANDLE  hInterrupt; // interrupt vector handle
long LastError;
};
//---------------------------------------------------------------------------
#endif

