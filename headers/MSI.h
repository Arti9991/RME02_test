#ifndef _MSI
#define _MSI

#include <windows.h>
#include <rtapi.h>

#pragma pack(push, 1)   

struct sVI
 {
 union uMIX
  {
  UINT32 w32;
  struct sBIT
   {
   UINT32 case_CW_BUS1:1;  // =1: ������ ���������� �� �� ���� 1
   UINT32 case_DW_BUS1:1;  // =1: ������ ���������� �� �� ���� 1
   UINT32 case_CW_BUS2:1;  // =1: ������ ���������� �� �� ���� 2
   UINT32 case_DW_BUS2:1;  // =1: ������ ���������� �� �� ���� 2
   UINT32 case_EXT:1;      // =1: ������ �������� ����������
   UINT32 CNT_INTERRUPT:3; // ���-�� ��������� ����������
                           // --- ���� 1
   UINT32 SA_BUS1:  5;     // ��������
   UINT32 DIR_BUS1: 1;     // =0: ������� �� �� �����, =1 : �� ��������
   UINT32 RT_BUS1:  5;     // ����� ��
   UINT32 PriRes1:  1;     // =0: ��������, =1: ��������� ����
                           // --- ���� 2
   UINT32 SA_BUS2:  5;     // ��������
   UINT32 DIR_BUS2: 1;     // =0: ������� �� �� �����, =1 : �� ��������
   UINT32 RT_BUS2:  5;     // ����� ��
   UINT32 PriRes2:  1;     // = 0: ��������, = 1 : ��������� ����
   } bit;
  } mix ;
 UINT64 t;  // ������ ������� ������� ����������, ���
 UINT64 dt; // ����� ����� ������� � ���������� �����������, ���
 };

#define SIZE_SharedMem_MSI 0x2000 // !!! �� �������� ��� ������������� � ��������� RMe-_02

struct sMSIshm
	{
 // ������� ��� �������� MPIe   0x00...0x0F (8-� �������� ������) �������� 16*8 = 128 ����
	struct sMPIe_Region
	 {
	 LARGE_INTEGER sysLogAddr;  // 0x00 : system logical address
		UINT32 TaskSet;            // ������� "i" � ���������� TaskSet[i] ������ �� ���������� ���������� MSI.exe
  UINT32 TaskAccepted;       // ������� "i" � ���������� TaskAccepted[i] ������� � ���������� ���������� MSI.rtss
		UINT8 PRN;   		    								// ������� ������ � ���� RtxServer
		UINT8 res[111];		  								// ������ ��� ������� �������� MPIe
	 } MPIe_Region;

 // ������� ��� �������� MKIOe  0x10...0x1F (8-� �������� ������) �������� 16*8 = 128 ����
	struct sMKIOe_Region
		{
		LARGE_INTEGER sysLogAddr; // 0x10 : system logical address
		sVI VI; // ������ 20 ����
		union // ������� �������� ��
			{
			UINT32 w32;
			struct
				{
				UINT32 value:16; // ������ ��������
				UINT32 mask:16;  // ������ �������
				} VandM;         
			} CW1,DW1,CW2,DW2;
  UINT32 TaskSet[3];       // ������� "i" � ���������� TaskSet[i] ������ �� ���������� ���������� MSI.exe
		                         // i = 0 : �������� ������� ���������� �� ���� 1
		                         // i = 1 : �������� ������� ���������� �� ���� 2
		                         // i = 2 : �������� ������� ���������� �� �������� ��������
  UINT32 TaskAccepted[3];  // ������� "i" � ���������� TaskAccepted[i] ������� � ���������� ���������� MSI.rtss
		UINT32 ctrlREG;								  // ������� ���������� FOHBe-01, R/W
		UINT8 PRN   ;		  								// ������� ������ � ���� RtxServer
		UINT8 res[55];								   // ������ ��� ������� �������� MKIOe
		} MKIOe_Region;

	// ������� ��� �������� RMe_02 0x20...0x2F (8-� �������� ������) �������� 16*8 = 128 ���� !!! �� �������� ��� ������������� � ��������� RMe-_02
	struct sRMe_02_Region
		{
		LARGE_INTEGER sysLogAddr;      // 0x20 : system logical address BAR0
		UINT64 sizeRM;											      // 0x21 : ������ ������ � 16�� ��., �.�. 8 => 128��
		LARGE_INTEGER PhysAddr_BAR1;   // 0x22 : �������� BAR1
		LARGE_INTEGER PhysAddr_SEG[8]; // 0x23...0x2A : ��������� 8-�� ��������� ������ �� ������
  UINT32 TaskSet;                // ������� "i" � ���������� TaskSet[i] ������ �� ���������� ���������� MSI.exe
  UINT32 TaskAccepted;           // ������� "i" � ���������� TaskAccepted[i] ������� � ���������� ���������� MSI.rtss
		union                          
			{
			unsigned __int32 data;
			struct InterruptValue
 			{
				unsigned __int32 ncell  :21;						//����� 64 ������ ������ � �������� (0 � 2�-1);
				unsigned __int32 nseg   : 3;						//����� 16�� �������� ������ � �������������� �������;
				unsigned __int32        : 7;
				unsigned __int32 enable : 1;						//��������� ����������;
	 		}interruptValue;
			} interruptSET[16];
		////UINT32 interruptSET[16];       // �������� ��������� i-�� ����������
		////                               // 0...20 ���� : ����� 64 ������ ������ � ����� �� 8-�� 16�� ��������� ������
		////                               // 21,22,23 ���� : ����� 16�� �������� ������
		////                               // 24...30 ���� : �� ������������
		////																															// 31 ��� : ������� ��������� ����������
  UINT32 nodeInterrupt;          // ������� ��������������� ����������, ������ ������ (� 0 �� 15-��) ����������, ����� ���������� ����� ������������� �� ������ ����.
  UINT32 lastInterrupt;          // ������� ������� ����������, ������ ������ (� 0 �� 15-��) ����������, ����� ���������� ���� ������������� ���������
  UINT64 t;                      // ������ ������� ������� ����������, ���
  UINT64 dt;                     // ����� ����� ������� � ���������� �����������, ���
		UINT8 PRN;	   	  				      				// ������� ������ � ���� RtxServer
		UINT8 res[327];														  // ������ ��� ������� �������� RMe_02
	 } RMe_02_Region;

	struct sSTAT
	 {
  UINT64 N;       // ���-�� �������
  UINT64 min;     // ����������� �������� dt[���]
	 UINT64 max;     // ������������ �������� dt[���]
		UINT32 AVT;     // 1: �������������� ������ min, max, 0: ������ ���� min, max �� ����. COInterrupt.exe
	 UINT32 m[1000]; // �����������

		UINT64 dti(UINT32 i) // ������ ������ ��������� dt �� ������ ���������
		 {
   return min+i*(max-min)/999;
		 }
		void erase_m(void)
		 {
			N = 0;
			memset(m,0,sizeof(m));
			return;
		 }

		void reset_MinMax(void)
		 {
			min = 0xFFFFFFFFFFFFFFFF;
			max = 0;
			return;
		 }

	} stat;

	INT32 HIST; // 1: ����� , 0: ��� ������, ������ ��� �������� � 1 �� 0
	// ��������� ���������� �� ��������� ������
	INT32 REG; // ����� ������ MSI.rtss
	INT32 PRN; // ����� ������ MSI.rtss
	INT32 DBG; // ����� ������������ MSI.rtss

	};

#pragma pack(pop)   

#endif

