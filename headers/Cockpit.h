
#ifndef COCKPITtoCC_H
#define COCKPITtoCC_H 

#include "windows.h"
long __stdcall InitCockpit(DWORD size, LPSTR Name);//������ ����������� ������ � �� ���
void __stdcall UnPakCockpit(void);
void __stdcall CloseCockpit(void);

//��������� �� ������ �� �� (120 ����)
struct str_COCKPITtoCC
{

//	COCPtoCC->

//���������� �������, �������� 0-10�
double
RUS_TANG,	//��� �� �������
RUS_KREN,	//��� �� �����
Pedal,	//������
PedalTormL,	//��������� ������ �����
PedalTormR,	//��������� ������ ������ 
RudL,		//��� �����
RudR,		//��� ������
Uoc;		//��������� �� ��� �����
//���������� ������� ��-31, � 10� 
double
Uy,	// ��-31, Alfa Z
Ux;	// ��-31, Betta Y

//������� ������� �� ������
UCHAR
OtklSAU,	//���� ���
Manevr,		//������
ShU,		//��
ShV,		//��
SnatPam,	//������ ������
Uvod,		//���� 
Otkaz,		//�����
PKZakrR,	//�� ���� ������
PKZakrL,	//�� ��� �����
GashSAU,	//������� ���
PG,			//��
TrimLKR,	//���� ����� ����
TrimRKR,	//���� ������ ����
TrimKabr,	//���� ������������
TrimPik,	//���� �����������
StartTorm,	//����� ������
SAUOsn,		//��� ������
AUT,		//���
AVT,		//���
DOZ,		//���
TRUpr,		//������ ������
Hbar,		//����
SAURez,		//��� ������
Knuppel,	//��-31 ������

Radio,		//�����
Sbros,		//�����
Vvod,		//����
SelectTP,	//����� ��������
Fire,		//�����
Sight,		//������
IspCom,		//������ ������
Sbros_LTC,	//����� �� ���
Main,		//������� ���
OPS1,		//4��� ��� ��� "1"
OPS2,		//4��� ��� ��� "2"
OPS3,		//4��� ��� ��� "3"
OPS4,		//4��� ��� ��� "4"
VzadUp,		//V��� ������
VzadDn;		//V��� ������

UCHAR Rezerv;
};


//��������� �� �� � ������ (40 ����)
struct str_CCtoCOCP
{
//CCtoCOCP->
//���������� ������� � ������, �������� �
double
U_AT;	//���� �������� ����������

//������� ������� � ������
UCHAR
Avariya,	//������
Fire,	//�����
Gidro,	//�����
Alfa_Ny_kritih,	//Ny ���������
Otk_PRT,	//����� ���
Naz_contrl,	//��� ��������
KB_chassi,	//�� �����
Test,	//����
Otkaz,	//�����
Fire_Left_eng,	//����� ��� ����
PK_left_zakr,	//�� ���� ����� 
Fire_Right_eng,	//����� ���� ����
PK_right_zakr,	//�� ���� ������ 
Upr_ruch,	//������ � ������
Man_SDU,	//������ ���
Uvod,	//����
AT_On,	//��� ��
SAU_osn,	//��� ���
AUT,	//���
Avt,	//���
Doz,	//���
TraektUpr,	//������ ������
Hbar,	//����
SAU_rez,	//��� ������
SDU;	//���
UCHAR Rezerv[7];
};


#endif