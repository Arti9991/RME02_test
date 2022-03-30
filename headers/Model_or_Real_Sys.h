#pragma once
#pragma pack(push,1) //������������ ����� �������� ������ ���� �� 1 ����

//	��������� ������ � ���������� �������� ������� ��� ������ ������� (1-����������� �������, 0-�������� ������� )
// ������ 16 ����
struct TModel_or_Real_Sys
{
	union{
		struct
		{
			char INS1_Model;   		//	����������� INS1
			char INS2_Model;   		//	����������� INS2
			char RAM_Model;			//	����������� RAM
			char TACAN_Model;		//	����������� TACAN
			char VOR_Model;			//	����������� VOR
			char TARANG_Model;		//	����������� TARANG
			char TSB_Model;			//	����������� TSB	
			char KARAT_Model;		//	����������� KARAT
			char ACMI_Model;		//	����������� ACMI
			char rezerv1;			//	������
			char rezerv2;			//	������
			char rezerv3;			//	������
			char rezerv4;			//	������
			char rezerv5;			//	������
			char rezerv6;			//	������
			char rezerv7;			//	������	
		};
		char modelOrNot[16];
	};
};
#pragma pack(pop)