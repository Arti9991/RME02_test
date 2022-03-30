#include "C5_450.h"			// ��������� RM(5565)
#include "LineAccelXYZ.h"	// ��������� ��� xyzDac
#include "ObjectNames.h"	// ��������� ���� ��_3
#include "ObjectNamesM.h"	// ��������� ���� �������
#include "RTMparam170M.h"	// ��������� ���
#include "KMBO_170M.h"		// ��������� ����
#include "Conf_170M.h"		// ��������� ��� ����������� ��������� ������������ ����. �������
#include "RS422_170M.h"		// ��������� ��� �����/������ ���������� ���(����) �� RS-422/485

//��������� ��� �������� � "������"
typedef struct {
float Time;				// � ���� � ������ ������� ������, ��
unsigned int CallCnt;	// ������� ������� ��������� CallFortran
PIN_PACK InPack;		// ��������� �� ���������, �������� �� �5-450
PSHMEMSTR pStend;		// �������� ��3(���)- ������� ������� MkioInput[32],�������� ������� MkioOutput[32] � �������� ��������� ��������� Stend.exe
PSHMEMSTR_M pStend_M;	// ���� ������� - ���������� ��3 (���)
PCONF_STEND Conf;		// ������ ��������� ������ ������������ ���� ������ Variant[8]
PT_RS422_IN pRS422_IN;  // RS422/485
} TO_MODEL_STR, *PTO_MODEL_STR;

//��������� ��� ������ �� "������" ��� ������ ����� ��������
typedef struct {
float a; 
POUT_PACK	OutPack;	// ��������� �� ��������� ��� ������ �� �5-450
PLINE_ACCEL OutAccel;	// ��� ������� - ��������� ������ ���� ���. �� ���� ����������� X, Y, Z;
PLINE_U		OutU;		// ��� ���������� U1, U2;
pR_170M		RVV;		// ��� - �������� �������
POUT_KMBO	OutKMBO;	// ����
PT_RS422_OUT pRS422_OUT;// ��������� ��� �����/������ ���������� ���(����) �� RS-422/485
} FROM_MODEL_STR, *PFROM_MODEL_STR;