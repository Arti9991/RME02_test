#ifndef PC429_h
#define PC429_h

#include <windows.h>
#include <stdio.h>
#include <rtapi.h>

#pragma pack(push, 1)

#define MAX_NUM_LINE			16		// ������������ ���������� ����� in + out )
#define MAX_NUM_WORD		256		// ������������ ���������� ���� � �����

	//�������� ��������� ����� ��� ARINC429
	struct ARINC429_Batch {
									UCHAR InOut;				//	��� ����� (��/���) 
									UCHAR NumWord;		//	����� ���� � ����� 
									float Freq;					//	������� ������� ����� 0-25��� -> 12���, 25-75��� -> 50���, >75��� -> 100���
									};
	//���������� ��� ��������� ���� PC429-3,4
		struct PC429INFO {
				UCHAR		NumPC;																							            // ����� ��
				UCHAR		NumBoard;																				            // ����� ����� � ��
				ARINC429_Batch  Arinc429_Batch[MAX_NUM_LINE*2];	// ������ � ��������� ���������� ����� ��� ���������� �����
				};

	union uArincData
		{
		ULONG d;
		struct
			{
			ULONG Address :8;
			ULONG Data				:23;
			ULONG Gap					:1;
			} adg;
		};
	
#endif