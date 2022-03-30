/*������� VMIC5565mng

��������
������ ��������� ����������
*/

#ifndef VMIC5565mng_H
#define VMIC5565mng_H

#include "CommonDef.h"

#if defined(VMIC5565mng_DLL)
# define VMIC5565MNG     __declspec(dllexport)
#elif defined(VMIC5565mng_APP)
# define VMIC5565MNG     __declspec(dllimport)
# else
# define VMIC5565MNG
#endif
//���� ������
#define  VMIC5565mng_OK          0//������ ���
#define  VMIC5565mng_CREATE      1//������ ������������� ����
#define  VMIC5565mng_BAD_PARAM   2//�������� �������� ���������

#ifdef __cplusplus
extern "C"
{
#endif

//�������� �������� ���������� ������� 
//NumPC - ��� ������ �� (NPC_IPC1,NPC_IPC2)
//������� - ���������� ��������� ����
VMIC5565MNG int __stdcall Create_VMIC5565(int NumPC, ULONG SizeEmulMem); //������������� ������ ������ ��� ��������

//�������� �������� ���������� ������� 
VMIC5565MNG void __stdcall Close_VMIC5565(void);

//������ ������ ��������� � ����� 
//������� 0-OK, -1 - ������ ������� ���������
VMIC5565MNG int __stdcall WriteData_VMIC5565(ID_Parameter Param);

//������ ������ ��������� �� ����� 
//������� 0-OK, -1 - ������ ������� ���������
VMIC5565MNG int __stdcall ReadData_VMIC5565(ID_Parameter &Param);

//��������� ���� ��������� ������
namespace  __VMIC5565mng {
VMIC5565MNG int __stdcall GetLastError_VMIC5565(void);
}

#ifdef __cplusplus
}
#endif
#endif
