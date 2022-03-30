#ifndef iMKIO_1_vb
#define iMKIO_1_vb

#pragma pack(push, 1)

#include "CommonDef.h"

const unsigned __int32 MKIO_OUMaxCount = 32;				//������������ ���������� �� �� ����� ����������
const unsigned __int32 MKIO_BusCount = 2;					//���������� �����������
//���������� ��� ���������
struct iMKIO_1Info {
 unsigned __int32 Config; //������������ ����� ����
 unsigned __int32 iMKIO_Batch[MKIO_OUMaxCount*MKIO_BusCount];	//������ � ������������� �� �� ������ ����. 1 - ������� �������������� ��. 0 - ����������.
};
// 1 - ���������� ����������
// 0 - ���������� ����������� 
//-1 - ���� �� ���������(����� ���������� ���� � ����� � �������� �������� ���)
//-2 - ������ ��������� ������ (������������� ���������)
//-3 - ���������� ������������ �� ������ 16
//-4 - ���������� ����������� �� ������ 1
//-5 - ��������������� ������������ �����.
__int32 __stdcall  vbCreate_iMKIO_1(iMKIO_1Info & Info);
void __stdcall vbClose_iMKIO_1();
void __stdcall vbSend_iMKIO_1();
void __stdcall vbRecv_iMKIO_1();
void __stdcall vbPut_iMKIO_1(ID_Parameter & glob);
void __stdcall vbGet_iMKIO_1(ID_Parameter & glob);

#endif