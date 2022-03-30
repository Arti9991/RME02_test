/*������� CusBmk

��������
������ ��������� ����������
*/

#ifndef CusBmk_H
#define CusBmk_H

#include "CommonDef.h"

#if defined(CusBmk_DLL)
# define CusBmk     __declspec(dllexport)
#elif defined(CusBmk_APP)
# define CusBmk     __declspec(dllimport)
# else
# define CusBmk
#endif
//���� ������
#define  CusBmk_OK          0//������ ���
#define  CusBmk_CREATE      1//������ ������������� ����
#define  CusBmk_BAD_PARAM   2//�������� �������� ���������

#ifdef __cplusplus
extern "C"
{
#endif

//�������� �������� ���������� ������� 
//NumPC - ��� ������ �� (NPC_IPC1,NPC_IPC2)
// Port - �� ������������
//������� - ���������� ��������� ����
CusBmk int __stdcall Create_CusBmk(int NumPC, int Port); 

//�������� �������� ���������� ������� 
CusBmk void __stdcall Close_CusBmk(void);

//������ ������ ��������� �� ����� 
//������� 0-OK, -1 - ������ ������� ���������
CusBmk int __stdcall ReadData_CusBmk(ID_Parameter &Param);

//����� ������ ���������� ������ c ������� NumCard
CusBmk void __stdcall Recv_CusBmk(int NumCard);

//��������� ���� ��������� ������
CusBmk int __stdcall GetLastError_CusBmk(void);

#ifdef __cplusplus
}
#endif
#endif
