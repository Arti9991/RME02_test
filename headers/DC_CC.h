
// ����� �� �� ��  (DcToCc.XX)
typedef struct{// ������ 16 ����
char
				//����� �� �� �������� IN 11
LG_Press_On,		// �� �� �� �� ������
TRIP_1,				//TRIP-1 (197ft) �� �� �� ��
TRIP_2,				//TRIP-2 (646ft) �� �� �� ��
SVS_Test,			//����� ����� ���
SVS_PVD,			//��� ��� �� ���
INS1_OK,			//���� ���1 �� ��
INS2_OK,			//���� ���2 �� ��
INS1_VERT_OK,		//���� ���� ���1 �� ��
INS1_PSI_M_OK,		//���� Psi ���� ���1 �� ��
INS1_PSI_T_OK,		//���� Psi ��� ���1 �� ��
INS2_VERT_OK,		//���� ���� ���2 �� ��
INS2_PSI_M_OK,		//���� Psi ���� ���2 �� ��
INS2_PSI_T_OK,		//���� Psi ��� ���2 �� ��
TI_NotUse,			//�� �� FTI-03UPG �� ��������
				//����� �� �� �������� IN 14
TMP_GPS,			//TMP GPS b(-) �� INS1/2, +5� �� ����������
TI;					//�������� ��� �� PCADS02, 5�
} DC_TO_CC, *PDC_TO_CC;

// ������ �� � �� (DcFromCc.XX)
typedef struct{// ������ 25 ����
char
//������ �� �� �������� OUT 7
LG_Not_Press,		//������ �� ������ �� 20���
MAX_FromSam,		//��� �� ������ �������� �� 20���
Afterburning,		//������ �� ������ �������� �� 20���
TRIP_1,				//TRIP-1 (197ft) �� ����
TRIP_2,				//TRIP-2 (646ft) �� ����
SVS_OK_Karat,		//���� ��� � �����
SVS_OK_Cims,		//���� ��� �� ����
INS1_OK_Cims,		//���� ���1 � ����
INS2_OK_Cims,		//���� ���2 � ����
INS1_OK_Karat,		//���� ���1 � �����
INS2_OK_Karat,		//���� ���2 � �����
INS1_OK_IVK,		//���� ���1 � ���
INS2_OK_IVK,		//���� ���2 � ���
INS1_VERT_OK_IVK,	//���� ���� ���1 � ���
INS1_PSI_M_OK,		//���� Psi ���� ���1 � ���
INS1_PSI_T_OK,		//���� Psi ��� ���1 � ���
INS2_VERT_OK_IVK,	//���� ���� ���2 � ���
INS2_PSI_M_OK,		//���� Psi ���� ���2 � ���
INS2_PSI_T_OK,		//���� Psi ��� ���2 � ���

//������ �� �� �������� OUT 8
INS1_Model,			//������ INS1
INS2_Model,			//������ INS2
RAM_Model,			//������ RAM
LG_Press_On,		// �� �� ������ ���-�� �� ��

//������ �� �� �������� OUT 10
TMP_GPS_INS1,		//��������� ����� �� ������ INS1
TMP_GPS_INS2;		//��������� ����� �� ������ INS2
} DC_FROM_CC, *PDC_FROM_CC;