typedef struct {
//���   ������������	   ������, ��������	����������
USHORT  MkioOutput_M[32];		//64	0h	������ ���� �������� ���������� ��� Mkio
USHORT  MkioInput_M[32];		//64 	40h	������ ���� ������� ���������� �� Mkio
} SHMEMSTR_M, *PSHMEMSTR_M;