#ifndef PCADSv7_vb
#define PCADSv7_vb

#pragma pack(push, 1)
#include "CommonDef.h"

const int PCADS_MAX_RTM = 32;	//���������� ������� ARINC ������� � ����� ������
const int PCADS_MAX_RK_Channel = 64;	//���������� �� � ����� ������
const int PCADS_Max_Module_Count = 7;	//������������ ���������� ������� ��� �������� ���������

//�������� ��������� ����� ��� ARINC429
struct ARINC_PCADSv7 {
 unsigned __int32 OutFreq;					//	������� ������� � ��
 unsigned __int32 NumWord;
};

//���������� ��� ���������
struct PCADSv7RTMINFO {
	struct Module
	{
		unsigned __int32 ModuleEnable;		//������� ������� ������ ������/�������� � ��.
		ARINC_PCADSv7 PCADS_Batch[PCADS_MAX_RTM * 2];	// ������ � ��������� ���������� ����� ��� ���������� �����
		//[0..31] - ����� ��� �������� (� ����������� �� ���� ��������), [32-63] - �������.
	}PCADSv7Module[PCADS_Max_Module_Count];
};

struct PCADSv7RKINFO {
	struct Line 
	{
	unsigned __int32 LineNumber;
	unsigned __int32 InOut;
	unsigned __int32 Channel[PCADS_MAX_RK_Channel];
	}line[PCADS_Max_Module_Count*2];
 };

__int32 __stdcall vbCreate_PCADSv7RTMin(PCADSv7RTMINFO &Info);
__int32 __stdcall vbCreate_PCADSv7RTMout(PCADSv7RTMINFO &Info);
void __stdcall vbClose_PCADSv7RTM();
void __stdcall vbSend_PCADSv7RTM();
void __stdcall vbRecv_PCADSv7RTM();
void __stdcall vbPut_PCADSv7RTM(ID_Parameter & glob);
void __stdcall vbGet_PCADSv7RTM(ID_Parameter & glob);

__int32 __stdcall vbCreate_PCADSv7K();
void __stdcall vbClose_PCADSv7K();
void __stdcall vbPut_PCADSv7K(ID_Parameter & glob);
void __stdcall vbSend_PCADSv7K();

__int32 __stdcall vbCreate_PCADSv7RK(PCADSv7RKINFO &Info);
void __stdcall vbPut_PCADSv7RK(ID_Parameter & glob);
void __stdcall vbSend_PCADSv7RK();
void __stdcall vbGet_PCADSv7RK(ID_Parameter & glob);
void __stdcall vbRecv_PCADSv7RK();
void __stdcall vbClose_PCADSv7RK();

#endif