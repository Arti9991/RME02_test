/************************************************************************************
*																					*
*	������:		18.05.2011															*
*	�������:																		*
*	����:		in_struct.h															*
*	�����:		��������� �.�.														*
*	��������:	������� ��������� ������											*
*																					*
*************************************************************************************/

#pragma once

#pragma pack(push,1)

// ����������������� IBIT 3 ���

// ������� ��������� ��������� ��������� (������� � ������������)
struct BORT_TACAN_IN{
	struct {
		unsigned char IBIT_IN; // 1 - START_IBIT, 0 - ���������� ��������
	}TACAN_IBIT_IN;	// ������������� ��������������� ���
	struct {
		struct {
			unsigned char X_MODE;											//
			unsigned char Y_MODE;											//
			unsigned char REC;												// ����� �������������(������ ������)
			unsigned char TR;													// ����� �����-��������
			unsigned char AA;													// ����� ������-������
		}CHANNEL_TYPE;															// 1 - �������
		unsigned char CHANNEL_NUM;									// ����� ������
	}TACAN_CHANNEL_SELECT;												// ����� ������ TACAN
	unsigned short TACAN_DATA_WRAP_AROUND_IN[32];	// ����������� ������� ������ �� ���� � TACAN
};

//	������� ��������� �� ������������ ������
struct BLOCKS_TACAN_IN
{
	bool bPower;								// ������� ������� (�������� ����� �������) (1 - ������� ����)
	double air_latitude;				// ������ �������� (�������� ����� �������) [���] (-PI ... PI)
	double air_longitude;				// ������� �������� (�������� ����� �������) [���] (-PI ... PI)
	double air_heigth;					// ������ �������� ��� ������� ���� (�������� ����� �������) [�]
};

// ������� ��������� �� TACAN
struct TACAN_IN_STRUCT{
	BORT_TACAN_IN From_BCVM;		//	����� �� �������� ���������

	BLOCKS_TACAN_IN	From_MM;		//	����� �� ������ ��

	// ������ ��� ������ "������-������"
	// ���������� ����
	// ����� ������ �� ������� ���������
};

#pragma pack(pop)