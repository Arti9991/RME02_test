#ifndef TMK1553MNG_H
#define TMK1553MNG_H

//#include "d:\alex\karat\common\CommonDef.h"
//#include "\\DELL\e\@kssr\@common\CommonDef.h"

#include "CommonDef.h"
//#include "CommonDef.h"

#if defined(TMK1553MNG_DLL)
# define TMK1553MNG     __declspec(dllexport)
#elif defined(TMK1553MNG_APP)
# define TMK1553MNG     __declspec(dllimport)
# else
# define TMK1553MNG
#endif

//���� ������
//���������� � tmk1553.h
//TX_OK
//TX_BAD_PARAMS
//TX_NOT_FOUND_OR_ALREADY_LOADED
//TX_LOAD_ERROR
//TX_INIT_ERROR
//TX_TEST_ERROR
//TX_INIT_PORT_ERROR
//TX_INIT_IRQL_ERROR
#define  ERR_1553MNG_BAD_PARAM 256       //�������� �������� ���������
#define  ERR_1553MNG_BAD_BOARD_MODE 512  //�������� ����� �����

#define SizeTlmBuf	24//������ ������ (� ����������) ��� ����������� ��� ��������� �� 34*2 ���� ������

#ifdef __cplusplus
extern "C"
{
#endif

//�������� �������� ���������� ������� TMK1553
//DeviceResources d[] - ������ �������� �����
//NumDevice - ���������� ����
//NumPC - ��� ������ �� (NPC_IPC1,NPC_IPC2)
//TMK1553INFO info[] - ������ ��� ��������� ���� TMK1553
//������� - ���������� ��������� ����  �� ����� �����������
TMK1553MNG int __stdcall Create_tmk1553(DeviceResources d[], int MaxNumDevice,int NumPC, TMK1553INFO info[]);

//�������� �������� ���������� ������� tmk1553
TMK1553MNG void __stdcall Close_tmk1553(void);

//������ ������ ��������� � ����� tmk1553
//������� 0-OK, -1 - ������ ������� ���������
TMK1553MNG int __stdcall WriteData_tmk1553(ID_Parameter Param);

//������ ������ ��������� �� ����� tmk1553
//������� 0-OK, -1 - ������ ������� ���������
TMK1553MNG int __stdcall ReadData_tmk1553(ID_Parameter &Param);

//������ ������ ���������� ������ c ������� NumCard � ������ �� � ���
TMK1553MNG void __stdcall Send_tmk1553(int NumCard);

//����� ������ ���������� ������ c ������� NumCard � ������ �� � ���
TMK1553MNG void __stdcall Recv_tmk1553(int NumCard);

// ������ ������ ��������������� ��������� ��� ������ ���������� �����, ���������� � ������ ��������
// � location ������������ ��������� �� ����� ���������
// � lpNumberOfMessages ������������ ���������� ���������, ����������� � ������. ������ ��������� = 34*2 ����
TMK1553MNG void __stdcall GetTlmMsg(VOID** location, LPDWORD lpNumberOfMessages);


//������������ �������� ������� ������������ ���� ��� ����� c ������� NumCard
TMK1553MNG void __stdcall MakeTaskBC_tmk1553(int NumCard);

//������ ������ �� �������� ��� ����� c ������� NumCard
TMK1553MNG void __stdcall MakeMT_tmk1553(int NumCard);

//������ ������ ����� Base ��������� �� �������� ��� ����� c ������� NumCard
// � ������ ����� ��������� � ��� ����� �� ��������  NumMsg
TMK1553MNG void __stdcall mtGetMSG_tmk1553(int NumCard, USHORT Base, USHORT NumMsg);

//���������� ����� ������� �������� Send, Recv, MakeTaskBC � ����������� �� ���� �����
TMK1553MNG void __stdcall Execute_All_tmk1553(void);

//��������� ���� ��������� ������
TMK1553MNG int __stdcall GetLastError_tmk1553(void);

#ifdef __cplusplus
}
#endif
#endif

//����� ��� �������� ��������������� ������
class  AUXData {
public:
        AUXData();
       ~AUXData();

USHORT RecvRT[32][32][32];//����� ������ ������ [����� ��][����� �/�][����� � �/�]
USHORT SendRT[32][32][32];//����� �������� ������ [����� ��][����� �/�][����� � �/�]
USHORT mtLastBase;//����� ����� ��� �� �������� ������� ������� ��������� � ������� �����
USHORT mtNextBase;//����� ����� ��� c �������� ������� ����� �������� ���������
UCHAR ReqRxNW[32][32];//������ ���������� ���� ������������� �� ����� [����� ��][����� �/�]
UCHAR ReqTxNW[32][32];//������ ���������� ���� ������������� �� ������ [����� ��][����� �/�]
USHORT TlmData[16][32];//������ ��� 16 ��������������� ������ �� 32 �����.
USHORT TlmMsgBuf[SizeTlmBuf][34];//����� ��� ����������� ��� ���������
USHORT NumberOfTlmMsg;//���������� ��� ���������, ����������� � ������ 
USHORT StatusRT[4], StatusRTprev[4];//��������� ��/��� ������� ��� �������� ��� ������������� ���-����
};
