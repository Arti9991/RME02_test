/************************************************************************************
*																					*
*	������:		18.05.2011															*
*	�������:																		*
*	����:		out_struct.h														*
*	�����:		��������� �.�.														*
*	��������:	�������� ��������� ������											*
*																					*
*************************************************************************************/

#pragma once

#pragma pack(push,1)

// �������� ��������� ��������� ���������
struct BORT_TACAN_OUT{
	struct {
		unsigned char IBIT_FAULT;				// 1 - ����� IBIT, ����� �������� ������ ���� IBIT_IB_PROGRESS = 0
		unsigned char IBIT_IN_PROGRESS; // 1 - �������; 0 - IBIT_VALID
		unsigned char IBIT_STATUS;			// 1 - IBIT ��� ��������
	} TACAN_IBIT_RESULT;	// ��������� ��������������� ���

	struct {
		struct{
			unsigned char DYNAMIC_MEMORY_DISTANCE;	// �������� ������������ ������(�� �� ������������� ���������) �������� ��� � ������� 10 ������ ����� ������ �����
			unsigned char DYNAMIC_MEMORY_BEARING;		// ������ ������������ ������, �������� ��� � ������� 15 ������ ����� ������ �����
			unsigned char DISTANCE;									// ������������� ���������
			unsigned char BEARING;									// ������������� �������
			unsigned char TIME_TO_VALIDITY;					// ������������� ������� ������� ������
			unsigned char LAMMING;									// ���������� �����
		} DISTANCE_BEARING_TIME_VALID;

		double DISTANCE;							// ��������� ��������� �� �����(�������� ��������� �������� ��������)	[��]
		double QDM;										// ��������� ������ �� ���� (�������� ��������� �������� ��������)		[���]
		unsigned long TIME_TO_GO;			// ���������� ����� ������(���� �� �����������)							[���]

		struct {
			unsigned char X_MODE;
			unsigned char Y_MODE;
			unsigned char REC;
			unsigned char TR;
			unsigned char AA;
		} CHANNEL_TYPE_RETURN;						// ��� ������ � ����� ������

		short CHANNEL_NO_RETURN;					// ������ ������ �� ������� ���������
	}TACAN_DATA;

	struct {
		struct {
			unsigned char CPU_CLOCK_FAILURE;					// ����� �������������� ����� CPU
			unsigned char RANGE_PROCESSOR_FAILURE;		// ����� ���������� ���������
			unsigned char RECEIVER_FAILURE;						// ����� ���������
			unsigned char TRANSMITTER_FAILURE;				// ����� �����������
			unsigned char VCWR_FAILURE;								// ����� ����
		} TEST_FAULTS;
		struct {
			unsigned char EERPOM_CHECK;								// �������� ������
			unsigned char _1553_ACE_RAM_FAILURE;			// ����� ��� 1553 ACE
			unsigned char _1553_ACE_REGISTER_FAILURE;	// ����� �������� 1553 ACE
		} PRICESSOR_FAULTS;
	} TACAN_CBIT;
	unsigned short TACAN_DATA_WRAP_AROUND_OUT[32];			// ����������� ������� ������ �� TACAN � ����
};

//	�������� ��������� ��� ������������ ������
struct BLOCKS_TACAN_OUT
{
	char beacon_calling[4];						// �������� (TACAN ���� ������������� �������� ���� ������ ����� ������) (�������� ����� ��2�)
	bool bIsLinked;										// ������� ������� �������������� �  ������(�� �� ������� ������ �������) (�������� ����� ��2�)
};

//	�������� ��������� �� TACAN
struct TACAN_OUT_STRUCT{
	BORT_TACAN_OUT ToBCMV;						// ��������� ��������� ���������

	BLOCKS_TACAN_OUT ToMM;						// ����� �� ������ ��
};

#pragma pack(pop)