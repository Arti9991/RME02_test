/*������� VMIC5587mng

��������
������ ��������� ����������
*/

#ifndef VMIC5587mng_H
#define VMIC5587mng_H

#include "CommonDef.h"

#if defined(VMIC5587mng_DLL)
# define VMIC5587MNG     __declspec(dllexport)
#elif defined(VMIC5587mng_APP)
# define VMIC5587MNG     __declspec(dllimport)
# else
# define VMIC5587MNG
#endif
//���� ������
#define  VMIC5587mng_OK          0//������ ���
#define  VMIC5587mng_CREATE      1//������ ������������� ����
#define  VMIC5587mng_BAD_PARAM   2//�������� �������� ���������

#ifdef __cplusplus
extern "C"
{
#endif

//�������� �������� ���������� ������� 
//NumPC - ��� ������ �� (NPC_IPC1,NPC_IPC2)
//������� - ���������� ��������� ����
VMIC5587MNG int __stdcall Create_VMIC5587(int NumPC);

//�������� �������� ���������� ������� 
VMIC5587MNG void __stdcall Close_VMIC5587(void);

//������ ������ ��������� � ����� 
//������� 0-OK, -1 - ������ ������� ���������
VMIC5587MNG int __stdcall WriteData_VMIC5587(ID_Parameter Param);

//������ ������ ��������� �� ����� 
//������� 0-OK, -1 - ������ ������� ���������
VMIC5587MNG int __stdcall ReadData_VMIC5587(ID_Parameter &Param);

//��������� ���� ��������� ������
namespace  __VMIC5587mng {
VMIC5587MNG int __stdcall GetLastError_VMIC5587(void);
}

#ifdef __cplusplus
}
#endif
#endif
