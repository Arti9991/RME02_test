/*������� LPT ��� ��������� ����������

��������
������ ��������� ����������
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

//���� ������ LPT_ISR
#define ErrorLPT_Ok			0x0//��� ���������!
#define ErrorLPT_InitPort		0x1//������ �������� �����
#define ErrorLPT_InitISR		0x2//������ ������������� ISR

//������ ������� ������ �����-������
#define SIZE_PIO_LPT            0x3

//�������� �������� ���������
#define STATUSCREG          0x1
//�������� ���������� ��������
#define CREG                0x2

//��� ���������� ����������
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

//������������� ISR
void InitISR(VOID (RTFCNDCL *pRoutine)(PVOID context));

//��������������� ISR
void CloseISR(void);

//������ UCHAR Data � ���� ������
void SetData(UCHAR Data);

//������ UCHAR �� ����� ������
UCHAR GetData();

//������ UCHAR Data � ���� ����������
void SetCtrl(UCHAR Data);

//������ UCHAR �� ����� ����������
UCHAR GetCtrl();

//������ UCHAR �� ����� ���������
UCHAR GetStatus();

long GetLastErrorLPT(void);

protected:
ULONG BaseAddrPIO;  //������� ����� ������ �����-������
HANDLE  hInterrupt; // interrupt vector handle
long LastError;
};
//---------------------------------------------------------------------------
#endif

