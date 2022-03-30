#if !defined(__ObjectNames_H)
#define      __ObjectNames_H

//#include "C5_450.h"
//
// IPC object names.
//
//#define	RigSoft_SHM    	__TEXT("RigSoft.Shm")
#define	RigSoft_SHM    	__TEXT("IPC15.Shm")

//��� CommandDevCntrl � CommandRigCntrl
#define	STOP_TASK		1//������� �� ������� ���������
#define	RESET	    	2//������� �� ����� ��������� �������

//��� AnswerRigCntrl
#define	RESET_TO_COMBINED	1//������� ��� STEND.EXE �������� � ���������� ����� �� �����������

//��������� ��������� stend.exe:
//������ ������ (ModeFlight)
#define	COMBINED_MODE	1//���������� ����� ����� ������� ���������
#define	AUTONOM__MODE	2//���������� ����� ����� ������� ���������

//����� �������� �������� (ActivePage)
#define	COMBINED_PAGE	1//�������� "���������� �����"
#define	AUTONOM__PAGE	2//�������� "���������� �����"

//	�������� ��������� ����������� ������.  ������ 140 ����
typedef struct {
//���   ������������	   ������, ��������	����������
USHORT  MkioOutput[32];		//64	0h	������ ���� �������� ���������� ��� Mkio
USHORT  MkioInput[32];		//64 	40h	������ ���� ������� ���������� �� Mkio

USHORT  AnswerRigCntrl;	    //2		0x00007821	����� ������� �� ������	
USHORT  ModeFlight;			//2		0x00007823  0-������� ������, COMBINED_MODE, AUTONOM__MODE	
USHORT  ActivePage;			//2		0-�� ���������� , COMBINED_PAGE, AUTONOM__PAGE (��� ����� �������� �� ������ ��������)
USHORT reserv[3];

//USHORT  CommandDevCntrl;   	//2		����� ������ �� TaskControl � DeviceControl
//USHORT  CommandRigCntrl;    	//2		����� ������ �� TaskControl � RigControl
//USHORT  AnswerDevCntrl;	    //2		����� ������� �� DeviceControl � TaskControl
//OUT_PACK	Out_Pack;
//IN_PACK		In_Pack;
} SHMEMSTR, *PSHMEMSTR;

#endif //  __ObjectNames_H