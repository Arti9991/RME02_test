// ����� ����������� �������� � �������� ������

#ifndef COMMONDEF_H
#define COMMONDEF_H

#include "Config.h"

#ifndef CONF_RIG
#error ### CONF_RIG from Config.h undefine ###
#endif

// ----------------------------------------------------------------------------------
//������ ������ �����������
// ----------------------------------------------------------------------------------

#if CONF_RIG==1 // 2900���

#define NPC_1				0   // DISP_IO, ������� ���
#define NPC_2				1   // DISP_IO, �������, ����, SIGMA, ����
#define NPC_3				2			// 
#define NPC_4				3			// DISP_IO, ��� & ����
#define NPC_5				4			// DISP_IO, ������� ���-��
#define NPC_6				5			// ����
#define NPC_7 			6			// ������������ 29���
#define NPC_8	 		7   // ����� 29���
#define NPC_9	 		8   // 
#define NPC_10	 	9   // 
#define NPC_11	 10   // 
#define NPC_12	 11   // 
#define NPC_13	 12   // 
#define NPC_14	 13   // 
#define NPC_15	 14   // 
#define NPC_16		15			// DISP_SI, ����������� � ���������� �������

#endif

#if CONF_RIG==2 // 2900�/��� 

#define NPC_1				0   // 
#define NPC_2				1   // 
#define NPC_3				2			// 
#define NPC_4				3			// 
#define NPC_5				4			// 
#define NPC_6				5			// ����
#define NPC_7 			6			// 
#define NPC_8	 		7   // 
#define NPC_9	 		8   // 
#define NPC_10	 	9   // 
#define NPC_11	 10   // DISP_IO, ������� ���
#define NPC_12	 11   // �������, ����, SIGMA, ����
#define NPC_13	 12   // 
#define NPC_14	 13   // DISP_IO, ��� & ����
#define NPC_15	 14   // DISP_IO, ������� ���
#define NPC_16		15			// DISP_SI, ����������� � ���������� �������

#endif

#if CONF_RIG==3 // ������

//#define NPC_1				0   //
//#define NPC_2				1   //
//#define NPC_3				2			// 
//#define NPC_4				3			//
//#define NPC_5				4			//
//#define NPC_6				5			//
//#define NPC_7 			6			//
//#define NPC_8	 		7   //
//#define NPC_9	 		8   // 
//#define NPC_10	 	9   // 
//#define NPC_11	 10   // 
//#define NPC_12	 11   // 
//#define NPC_13	 12   // 
//#define NPC_14	 13   // 
//#define NPC_15	 14   // 
#define NPC_16		15			// DISP_SI, ����������� � ���������� �������

#endif

#if CONF_RIG==4 // ������

#define NPC_1				0   //
#define NPC_2				1   //
#define NPC_3				2			// 
#define NPC_4				3			//
#define NPC_5				4			//
#define NPC_6				5			//
#define NPC_7 			6			//
#define NPC_8	 		7   //
#define NPC_9	 		8   // 
#define NPC_10	 	9   // 
#define NPC_11	 10   // 
#define NPC_12	 11   // 
#define NPC_13	 12   // 
#define NPC_14	 13   // 
#define NPC_15	 14   // 
#define NPC_16		15			// DISP_SI, ����������� � ���������� �������

#endif

//������ ������ �����������
#if CONF_RIG==5 // 170M

//#define NPC_1				0   //
//#define NPC_2				1   //
//#define NPC_3				2			// 
//#define NPC_4				3			//
//#define NPC_5				4			//
//#define NPC_6				5			//
//#define NPC_7 			6			//
//#define NPC_8	 		7   //
//#define NPC_9	 		8   // 
//#define NPC_10	 	9   // 
//#define NPC_11	 10   // 
//#define NPC_12	 11   // 
//#define NPC_13	 12   // 
//#define NPC_14	 13   // 
//#define NPC_15	 14   // 
#define NPC_16		15			// DISP_SI, ����������� � ���������� �������

#endif

#if CONF_RIG==6 // 29UPG

#define NPC_1				0   // ��-IPC2   :
#define NPC_2				1   // DS-IPC1   : 
#define NPC_3				2			// SSS-IPC1  :
#define NPC_4				3			// SSS-IPC2  :
#define NPC_5				4			// SSS-IPC3  : 
#define NPC_6				5			// DRSS-IPC1 :
#define NPC_7 			6			// SOLS-IPC1 :
#define NPC_8	 		7   // ESVS-IPC1 :
#define NPC_9	 		8   // SLS-IPC1  :
#define NPC_10	 	9   // 
#define NPC_11	 10   // 
#define NPC_12	 11   // 
#define NPC_13	 12   // 
#define NPC_14	 13   // 
#define NPC_15	 14   // 
#define NPC_16		15			// ��-IPC1: DISP_SI, ����������� � ���������� �������

#endif

#if CONF_RIG==7 // 29M/M2

#define NPC_1				0   // ��2   :
#define NPC_2				1   // DS1   : 
#define NPC_3				2			// SSS1  :
#define NPC_4				3			// SSS2  :
#define NPC_5				4			// SSS3  : 
#define NPC_6				5			// DRSS1 :
#define NPC_7 			6			// SOLS1 :
#define NPC_8	 		7   // SOLS2 :
#define NPC_9	 		8   // ESVS1 :
#define NPC_10	 	9   // SLS1  :
#define NPC_11	 10   // 
#define NPC_12	 11   // 
#define NPC_13	 12   // 
#define NPC_14	 13   // 
#define NPC_15	 14   // 
#define NPC_16		15			// ��1: DISP_SI, ����������� � ���������� �������

#endif

#if CONF_RIG==8 // 29�/���(�)

#define NPC_1				0   // ��2    :
#define NPC_2				1   //
#define NPC_3				2			// SSS1   :
#define NPC_4				3			// SSS2   :
#define NPC_5				4			// SSS3   : 
#define NPC_6				5			// DRSS1  :
#define NPC_7 			6			// CSOLS1 :
#define NPC_8	 		7   //
#define NPC_9	 		8   // ESVS1 :
#define NPC_10	 	9   // SLS3  :
#define NPC_11	 10   // 
#define NPC_12	 11   // 
#define NPC_13	 12   // 
#define NPC_14	 13   // 
#define NPC_15	 14   // 
#define NPC_16		15			// ��1: DISP_SI, ����������� � ���������� �������

#endif
// ----------------------------------------------------------------------------------


// -------   Reflective Memory   -------------

#define RF_INT					0x00000	 // ��������� ��������� ����������, ���������� ���������� RNM_and_OMB1.rtss

#define SIZE_RF_TIME														8  //
#define SIZE_RF_TIME_PULSE_COMMON	8  //
#define SIZE_RF_TIME_PULSE_TEST			8  //
#define SIZE_RF_WAIT_CIRS									8  //
#define SIZE_RF_STATUS_DISP							4  //
#define SIZE_RF_IDENTIFIER       16  //

#define size_RF_USER 0x10000 // ������ ������� ������ �� IPC ��� ���������� �������������
#define size_RF_DISP 0x10000 // ������ ������� ������ �� IPC ��� �������� DISP_IO.exe
// �� ����� 0x8000 = 32768 ������� ����������
// �� ����� 0x8000 = 32768 �������� ����������
#define size_RF_in_DISP  (size_RF_DISP/2) // ������ ������� ������ ��� ��.�����. �� IPC ��� �������� DISP_IO.exe
#define size_RF_out_DISP (size_RF_DISP/2) // ������ ������� ������ ��� ���.�����. �� IPC ��� �������� DISP_IO.exe

#define RF_Common								   		0x000040 // ���������� �����

#define RF_TIME_IPC1						  		(RF_Common     + SIZE_RF_TIME) // 0x48 ����� ��� IPC1
#define RF_TIME_IPC2						  		(RF_TIME_IPC1  + SIZE_RF_TIME) // 0x50 ����� ��� IPC2
#define RF_TIME_IPC3						 	 	(RF_TIME_IPC2  + SIZE_RF_TIME) // 0x58 ����� ��� IPC3
#define RF_TIME_IPC4		 				 		(RF_TIME_IPC3  + SIZE_RF_TIME) // 0x60 ����� ��� IPC4
#define RF_TIME_IPC5			 			 		(RF_TIME_IPC4  + SIZE_RF_TIME) // 0x68 ����� ��� IPC5
#define RF_TIME_IPC6				 		 		(RF_TIME_IPC5  + SIZE_RF_TIME) // 0x70 ����� ��� IPC6
#define RF_TIME_IPC7					 	 		(RF_TIME_IPC6  + SIZE_RF_TIME) // 0x78 ����� ��� IPC7
#define RF_TIME_IPC8						  		(RF_TIME_IPC7  + SIZE_RF_TIME) // 0x80 ����� ��� IPC8
#define RF_TIME_IPC9						  		(RF_TIME_IPC8  + SIZE_RF_TIME) // 0x88 ����� ��� IPC9
#define RF_TIME_IPC10						 		(RF_TIME_IPC9  + SIZE_RF_TIME) // 0x90 ����� ��� IPC10
#define RF_TIME_IPC11						 		(RF_TIME_IPC10 + SIZE_RF_TIME) // 0x98 ����� ��� IPC11
#define RF_TIME_IPC12						 		(RF_TIME_IPC11 + SIZE_RF_TIME) // 0xA0 ����� ��� IPC12
#define RF_TIME_IPC13						 		(RF_TIME_IPC12 + SIZE_RF_TIME) // 0xA8 ����� ��� IPC13
#define RF_TIME_IPC14						 		(RF_TIME_IPC13 + SIZE_RF_TIME) // 0xB0 ����� ��� IPC14
#define RF_TIME_IPC15						 		(RF_TIME_IPC14 + SIZE_RF_TIME) // 0xB8 ����� ��� IPC15
#define RF_TIME_IPC16						 		(RF_TIME_IPC15 + SIZE_RF_TIME) // 0xC0 ����� ��� IPC16


#define RF_TIME_PULSE_COMMON	0x100                                            //  : ����� ����� (� 0.1���) ������� � ������ ������������ UseRMN_IRQ=4
#if RF_TIME_IPC16 + SIZE_RF_TIME >  RF_TIME_PULSE_COMMON
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  RF_TIME_PULSE_COMMON  uncorrect !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#endif
#define RF_TIME_PULSE_TEST			(RF_TIME_PULSE_COMMON + SIZE_RF_TIME_PULSE_COMMON) //  : ����� ����� ���������� ���������� timer.exe � 0.1��� 
#define RF_TIME_WAIT_CIRS			 (RF_TIME_PULSE_TEST + SIZE_RF_TIME_PULSE_TEST)     //  : �������� � 0.1��� ��� ������� �������� �����
#define RF_IDENTIFIER			     (RF_TIME_WAIT_CIRS + SIZE_RF_WAIT_CIRS)            //  : ����������������� ��� ������� �������

#define RF_STATUS_DISP_1     0x200                                   // 0x200
#if RF_IDENTIFIER + SIZE_RF_IDENTIFIER >  RF_STATUS_DISP_1
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  RF_STATUS_DISP_1  uncorrect !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#endif
#define RF_STATUS_DISP_2     (RF_STATUS_DISP_1  + SIZE_RF_STATUS_DISP) // 0x204
#define RF_STATUS_DISP_3     (RF_STATUS_DISP_2  + SIZE_RF_STATUS_DISP) // 0x208
#define RF_STATUS_DISP_4     (RF_STATUS_DISP_3  + SIZE_RF_STATUS_DISP) // 0x20C
#define RF_STATUS_DISP_5     (RF_STATUS_DISP_4  + SIZE_RF_STATUS_DISP) // 0x210
#define RF_STATUS_DISP_6     (RF_STATUS_DISP_5  + SIZE_RF_STATUS_DISP) // 0x214
#define RF_STATUS_DISP_7     (RF_STATUS_DISP_6  + SIZE_RF_STATUS_DISP) // 0x218
#define RF_STATUS_DISP_8     (RF_STATUS_DISP_7  + SIZE_RF_STATUS_DISP) // 0x21C
#define RF_STATUS_DISP_9     (RF_STATUS_DISP_8  + SIZE_RF_STATUS_DISP) // 0x220
#define RF_STATUS_DISP_10    (RF_STATUS_DISP_9  + SIZE_RF_STATUS_DISP) // 0x224
#define RF_STATUS_DISP_11    (RF_STATUS_DISP_10 + SIZE_RF_STATUS_DISP) // 0x228
#define RF_STATUS_DISP_12    (RF_STATUS_DISP_11 + SIZE_RF_STATUS_DISP) // 0x22C
#define RF_STATUS_DISP_13    (RF_STATUS_DISP_12 + SIZE_RF_STATUS_DISP) // 0x230
#define RF_STATUS_DISP_14    (RF_STATUS_DISP_13 + SIZE_RF_STATUS_DISP) // 0x234
#define RF_STATUS_DISP_15    (RF_STATUS_DISP_14 + SIZE_RF_STATUS_DISP) // 0x238
#define RF_STATUS_DISP_16    (RF_STATUS_DISP_15 + SIZE_RF_STATUS_DISP) // 0x23C

#define RF_DISP_1   0x10000                    // 0x10000... 0x20000-1 
#define RF_USER_1	 	(RF_DISP_1 + size_RF_DISP)   // 0x20000... 0x30000-1

#define RF_DISP_2   (RF_USER_1 + size_RF_USER)   // 0x30000... 0x40000-1
#define RF_USER_2	 	(RF_DISP_2 + size_RF_DISP)   // 0x40000... 0x50000-1

#define RF_DISP_3   (RF_USER_2 + size_RF_USER)   // 0x50000... 0x60000-1
#define RF_USER_3	 	(RF_DISP_3 + size_RF_DISP)   // 0x60000... 0x70000-1

#define RF_DISP_4   (RF_USER_3 + size_RF_USER)   // 0x70000... 0x80000-1
#define RF_USER_4	 	(RF_DISP_4 + size_RF_DISP)   // 0x80000... 0x90000-1

#define RF_DISP_5   (RF_USER_4 + size_RF_USER)   // 0x90000... 0xA0000-1
#define RF_USER_5	 	(RF_DISP_5 + size_RF_DISP)   // 0xA0000... 0xB0000-1

#define RF_DISP_6   (RF_USER_5 + size_RF_USER)   // 0xB0000... 0xC0000-1
#define RF_USER_6	 	(RF_DISP_6 + size_RF_DISP)   // 0xC0000... 0xD0000-1

#define RF_DISP_7   (RF_USER_6 + size_RF_USER)   // 0xD0000... 0xE0000-1
#define RF_USER_7	 	(RF_DISP_7 + size_RF_DISP)   // 0xE0000... 0xF0000-1

#define RF_DISP_8   (RF_USER_7 + size_RF_USER)   // 0xF0000... 0x100000-1
#define RF_USER_8	 	(RF_DISP_8 + size_RF_DISP)   // 0x100000... 0x110000-1

#define RF_DISP_9   (RF_USER_8 + size_RF_USER)   // 0x110000... 0x120000-1
#define RF_USER_9	 	(RF_DISP_9 + size_RF_DISP)   // 0x120000... 0x130000-1

#define RF_DISP_10   (RF_USER_9 + size_RF_USER)  // 0x130000... 0x140000-1
#define RF_USER_10	 	(RF_DISP_10 + size_RF_DISP) // 0x140000... 0x150000-1

#define RF_DISP_11   (RF_USER_10 + size_RF_USER) // 0x150000... 0x160000-1
#define RF_USER_11	 	(RF_DISP_11 + size_RF_DISP) // 0x160000... 0x170000-1

#define RF_DISP_12   (RF_USER_11 + size_RF_USER) // 0x170000... 0x180000-1
#define RF_USER_12	 	(RF_DISP_12 + size_RF_DISP) // 0x180000... 0x190000-1

#define RF_DISP_13   (RF_USER_12 + size_RF_USER) // 0x190000... 0x1A0000-1
#define RF_USER_13	 	(RF_DISP_13 + size_RF_DISP) // 0x1A0000... 0x1B0000-1

#define RF_DISP_14   (RF_USER_13 + size_RF_USER) // 0x1B0000... 0x1C0000-1
#define RF_USER_14	 	(RF_DISP_14 + size_RF_DISP) // 0x1C0000... 0x1D0000-1

#define RF_DISP_15   (RF_USER_14 + size_RF_USER) // 0x1D0000... 0x1E0000-1
#define RF_USER_15	 	(RF_DISP_15 + size_RF_DISP) // 0x1E0000... 0x1F0000-1

#define RF_DISP_16   (RF_USER_15 + size_RF_USER) // 0x1F0000... 0x200000-1
#define RF_USER_16	 	(RF_DISP_16 + size_RF_DISP) // 0x200000... 0x210000-1

// ..................................................
// ���� ��������� IdAdaptersType
// ..................................................
#define RES1		         1   // � ���� ������ SEALEVEL
#define TX6_PC_C							2
#define PC429_3_88					3
#define PC429_4_xx					4
#define PCADS_05							5   // � ���� ������ PCADS05t
#define PCADS_05K						6   // � ���� ������ PCADS05K
#define PCADS_05RK  		 7   // � ���� ������ PCADS05RK
#define iMKIO_1      		8   // � ���� ������ iMKIO-01
#define SPECIAL								9   // � ���� ������ VIRTUAL
#define PCADS_06RTM		 10   // � ���� ������ PCADS06RTM
#define PCADS_06K		   11   // � ���� ������ PCADS06K
#define PCADS_06RK				12   // � ���� ������ PCADS06RK
#define PCI_1753						13   // � ���� ������ PCI-1753
#define RES7 									14   // � ���� ������ Astra
#define VMIPCI5587A			15   // � ���� ������ VMIPCI-5587A
#define PCI_1716      16
#define PCI_1724      17
#define IPK1      				18
#define VMIPCI5565				19   // � ���� ������ VMIPCI-5565
#define PCI_1713	     20
#define RMe_02	        21   // � ���� ������ RMe-02
#define PCI_ASTRA	    22
#define CUS_BMK	      23   // � ���� ������ CusBmk
#define PCI_ASTRA_BL	 24
#define PCADSv7RTMin		 25   // � ���� ������ PCADSv7RTMin
#define PCADSv7RTMout		26   // � ���� ������ PCADSv7RTMout
#define PCADS_v7RK         27   // � ���� ������ PCADSv7RK
#define RES12         28   // � ���� ������ �� �������� !!!
#define pciSPI		      29   // � ���� ������ SPI
#define RS485_MTVS		  30   // � ���� ������ MTVS
#define RES13         31   // � ���� ������ �� �������� !!!
// ..................................................

//������� ���������
struct DeviceResources {
	ULONGLONG BaseMemory; // ������� ����� ������
	USHORT BasePort;      // ������� ����� ������ �����-������
	USHORT DMAPort;       // ���� ������ DMA
	UCHAR DMAChannel;     // ����� ������ DMA
	UCHAR nIRQ;           // ����� ����� ������� ����������
	USHORT NumChannel;				// ���-�� ������� ��������
};


//������� Pci1753
struct DevicePci1753 {
	UCHAR  config[8];		// ��������� ������ �� In/Out
	USHORT BasePort;   // ������� ����� ������ �����-������
	USHORT reserv1;				// ������
	UCHAR reserv2;					// ������
	UCHAR nIRQ;        // ����� ����� ������� ����������
	USHORT reserv;				 // ������
};

//������� �����
struct DeviceAstraResources {
	ULONGLONG reserv1;		// ������
	USHORT BasePort;		  // Adapters.PortIO- ������� ����� ������ �����-������, ������ 310
	USHORT reserv2;		   // ������
	UCHAR PortSize;   	 // Adapters.PortSize
	UCHAR nIRQ;	    	   // ������
	USHORT reserv3;		   // ������
};

//������� ��� � ������(�����) ��� Astra
struct Astra_BURST_INFO{
	ULONG InOut;	     // DataBurst.InOut ������� �������-1/��������-0 
	ULONG MPIAddress; // StrDescr.Address - ����� ���
	ULONG Mode;	      // StrDescr.SubAddress - ������� �����������, 1 - ��, 0- ���
};                //������� ��� � ������(�����) ��� Astra

struct AstraPCI_BURST_INFO{
	ULONG MPIAddress; // StrDescr.Address - ����� ���
	USHORT Choice;	   // StrDescr.Choice  ������� ���������� (� ��� ������ 1, � ���������� ������ �������� ������ �����������)
	USHORT Intr;	     // StrDescr.SubAddress - ������� ������������ �������� �� ������� ������, 1 - ��, 0- ���
};


//�������� ��������� ������(�����) ��� ����
struct MKIO_Batch {
	USHORT NumBatch;            //�������� ����� ������

	USHORT reserv1 : 1;
	USHORT InOut : 1; //������� ������ �������-1/��������-0 - ������� �� �������� �����
	USHORT MessageError : 3; //��������� ����������� ��������� ��
	USHORT CodeTransfer : 5; //��� ������� �������� (0-BC->RT, 1-RT->BC, 2-RT->RT)
	USHORT NumWord : 6; //����� ���� ������ � ���������

	USHORT  AddrRT1 : 5; //����� �� /  ����� ��-��������� � ������ RT->RT)  AddrRT = 0...31
	USHORT  AddrRT2 : 5; //����� ��-�����������  (��� RT->RT)		AddrRT = 0...31
	USHORT  SubAddr : 5; //�������� ���������     SubAddr = 1...30
	USHORT  Activ : 1; //���� ���������� ��������, ������������ ��� ���������. Activ=1 -������� �������, 0-���

	USHORT  CodeFreq;           //��� ������� ������ ������(�����) (1-100��, 2-50, 3-33,4-25, 5-20,10-10,20-5,100-1��)
};

#define MAX_NUM_MESSAGE      512 //������������ ����������  ��������� ��� ������� ��

//���������� ��� ��������� ���� TMK1553
struct TMK1553INFO {
	USHORT BoardType;    // ��� �����: TX1,RT1,TX4,TX5,TX6,TX5MRT,TX6MRT - ���������� � tmk1553.h
	UCHAR AddrRT[4];     // ��� ������ RT_MODE - ����� ��,  AddrRT = 0...31
	//��� ������������ ��(TX1,RT1,TX4,TX5,TX6,TE6_PCI,TE1_PCI)AddrRT[0],
	//��� ������������� ��(TX5MRT,TX6MRT,TE6_PCI_MRT)AddrRT[0]...AddrRT[3]
	USHORT BoardMode;    // ����� �����:   BC_MODE,RT_MODE,MT_MODE,MRT_MODE - ���������� � tmk1553.h
	USHORT NumMessage;   //����� ���������� ������� ���������, ��������� � Mkio_Batch ��� ������ ����� (��� ������ ��)
	UCHAR		NumPC;        //����� ��
	UCHAR		NumBoard;     //����� ����� � ��
	MKIO_Batch  Mkio_Batch[MAX_NUM_MESSAGE];//������ � ��������� ������ ������� ��� ���������� ����� (��� ������ ��)
};

//�������� ��������� ������(�����) ��� ����
struct KMBO_Batch {
	USHORT reserv1 : 1;
	USHORT NumWord : 6; //����� ���� ������ � ���������
	USHORT InOut : 1; //������� ������ �������-1/��������-0 - ������� �� �������� �����
	USHORT AddrRT : 8; //����� �� 
};


//������� ADVANTECH DA PCI1724
struct DeviceRes_PCI1724{
	ULONG	BaseMemory;   // ������� ����� ������
	ULONG	ulReserv;
	USHORT	BasePort;    // ������� ����� ������ �����-������
	USHORT	usReserv;    // ���� ������ DMA
	UCHAR	Sync;         // ����� ������ DMA
	UCHAR	nIRQ;         // ����� ����� ������� ����������
	USHORT	NumChannel;	 // ���-�� ������� ��������
};//����������� ��������� ��� ADVANTECH AD PCI1724

//������� MTVS
struct DeviceMTVS {
	ULONGLONG Baud;				// �������� �������� Vmax = 115200 ���/� � ���������� ������� ���������(��������� �����)
	USHORT DevAddr;    // ����� ���������� ���� (0�08) � �������� ������� ��������� (��� ������������� ����������)
	USHORT NumCOMport; // ����� ����� COM 1 ... COM 4. ������ ����� � ���������� ������� ���������(��������� �����)
	UCHAR LenWord;		   // ����� ����� �������� ��� 8 ��� ���������� ������� ��������� (��������� �����)
	UCHAR NoUse1;      // �� ������������
	USHORT NoUse2;	    // �� ������������
};

struct ID_PCI1724 {
	ULONG InOut : 1;        // ������� �������-1/��������-0 (��� 1)
	ULONG GroupMode : 2;	    //2,3	SubAddress: 0(3) - normal, 1(2)-offset(calibr)  2(1) -Gain mode(calibr)
	ULONG bit4_6 : 3;	      // (1-4)
	ULONG bit7_18 : 12;      //���������� ������� �������� (���� 7-18)	
	ULONG NumChannel : 5; // StrDescr.NumWord ����� ������ �������� 0-31 (���� 19,20,21,22,23) (����� �����-������ ��������������� �������� ��� ��������)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27,28,29,30)

	ULONG LoBit : 5;        // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;        // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	     // 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	     // 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;     // ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29,30,31,32)

	ULONG Data; // �������� ��������� (��� 1)
};
//������� ADVANTECH DA PCI1723
struct DeviceRes_PCI1723{
	ULONG	BaseMemory;    // ������� ����� ������
	ULONG	ulReserv;
	USHORT	BasePort;     // ������� ����� ������ �����-������
	USHORT	usReserv;     // ���� ������ DMA
	UCHAR	Sync;          // ����� ������ DMA
	UCHAR	nIRQ;          // ����� ����� ������� ����������
	USHORT	NumChannel;	  // ���-�� ������� ��������
};//����������� ��������� ��� ADVANTECH AD PCI1723  // ����
struct ID_PCI1723 {
	ULONG InOut : 1; // ������� �������-1/��������-0 (��� 1)
	ULONG GroupMode : 2;	// 2,3	SubAddress: 0(3) - normal, 1(2)-offset(calibr)  2(1) -Gain mode(calibr)
	ULONG bit4_6 : 3;	// (1-4)
	ULONG bit7_18 : 12;//���������� ������� �������� (���� 7-18)	
	ULONG NumChannel : 5; // StrDescr.NumWord ����� ������ �������� 0-31 (���� 19,20,21,22,23) (����� �����-������ ��������������� �������� ��� ��������)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27,28,29,30)

	ULONG LoBit : 5; // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29,30,31,32)

	ULONG Data;       // �������� ��������� (��� 1)
};

//������� ADVANTECH AD PCI1713
struct DevicePCI1713 {
	ULONG	BaseMemory;    // ������� ����� ������ Adapters.DmaCh
	ULONG	ulReserv;
	USHORT	BasePort;    // ������� ����� ������ �����-������ Adapters.PortIO
	USHORT	usReserv;    // ���� ������ DMA
	UCHAR	FirstChannel; // ����� ������� ������������ ������(1-32),���� 0, ��	1 
	//  Adapters.DmaCh
	UCHAR	nIRQ;         // ����� ����� ������� ���������� 
	//Adapters.InterruptNum
	USHORT	NumChannel;	 // ���-�� ��������������� ������� ��������, ���� 0, �� 32 
	//Adapters.NumCh
};
//��������� ������ ADVANTECH AD PCI1713
struct PCI1713_CH_CONFIG //DataBurst
{
	USHORT Gain : 4;	// Gain code - 0(20�),1(10�),2(5�),4(2.5�) 8(1.25�). 
	// Gain =5/(Scale*(1+SignBit1) 
	// ������: Scale= 2.5 ��� +-5 Gain =1
	// Scale= 2.5 ���  0-5�       Gain =2 
	USHORT B_U : 1;	// ~StrDescr.SignBit: 0 = Bipolar->SignBit=1, 1 = uniopolar->SignBit=0,  
	USHORT S_D : 1;	// StrDescr.SubAddr: 0 = single ended, 1 = differential
	USHORT res2 : 2; //������
	USHORT res8 : 8;	//reserv
};

//��������� ������ ADVANTECH AD PCI1713
struct PCI1713_DEV_CTRL
{
	USHORT SW : 1;  //   Software trigger enable.Adapters.DmaPort&1
	USHORT PACER : 1;  //   Pacer trigger enable.Adapters.DmaPort&2
	USHORT EXT : 1;  //   External trigger enable.Adapters.DmaPort & 4
	USHORT GATE : 1;  //   External trigger gate function enable.Adapters.DmaPort&8
	USHORT IRQ_EN : 1;  //   Interrupt enable Adapters.DmaPort & 16
	USHORT ONE_FH : 1;  //   0 = interrupt after one data conversion, 1 = FIFO half full.Adapters.DmaPort & 32
	USHORT reserv10 : 10; //
};
//��������� ����� ADVANTECH AD PCI1713
struct PCI1713_CONFIG
{
	UCHAR NumPC;	                 // ����� ���������� 
	UCHAR NumDevice;		            // ���������� ����� �������� ������� ���� � ������ ��(���� )
	PCI1713_DEV_CTRL dev_ctrl;    // ��� ��������, IRQ � ����, - ���������� ��� ��������
	PCI1713_CH_CONFIG ch_conf[32];//Gain,B_U,S_D-���������� ��� ������� ������
};

//������� ADVANTECH AD PCI1716
struct DevicePCI1716
{
	ULONG	BaseMemory;    // ������� ����� ������ Adapters.DmaCh
	ULONG	ulReserv;
	USHORT	BasePort;    // ������� ����� ������ �����-������ Adapters.PortIO
	USHORT	usReserv;    // ���� ������ DMA
	UCHAR	FirstChannel; // ����� ������� ������������ ������(1-16),���� 0, ��	1 
	//  Adapters.DmaCh
	UCHAR	nIRQ;         // ����� ����� ������� ���������� 
	//Adapters.InterruptNum
	USHORT	NumChannel;	 // ���-�� ��������������� ������� ��������, ���� 0, �� 16 
	//Adapters.NumCh
};
//��������� ������ ADVANTECH AD PCI1716
struct PCI1716_CH_CONFIG //DataBurst
{
	USHORT Gain : 4;	//3! Gain code - 0(20�=+-10),1(10�=0-10|+-5),2(5�),4(2.5�) 8(1.25�). 
	// Gain =5/(Scale*(1+SignBit1) 
	// ������: Scale= 2.5 ��� +-5 Gain =1
	// Scale= 2.5 ���  0-5�       Gain =2 
	USHORT B_U : 1;	// ~StrDescr.SignBit: 0 = Bipolar->SignBit=1, 1 = uniopolar->SignBit=0,  
	USHORT S_D : 1;	// StrDescr.SubAddr: 0 = single ended, 1 = differential
	USHORT res2 : 2; //������
	USHORT res8 : 8;	//reserv
};

//��������� ������ ADVANTECH AD PCI1716
struct PCI1716_DEV_CTRL
{
	USHORT SW : 1;  //      Software trigger enable.Adapters.DmaPort&1
	USHORT PACER : 1;  //   Pacer trigger enable.Adapters.DmaPort&2
	USHORT EXT : 1;  //     External trigger enable.Adapters.DmaPort & 4
	USHORT GATE : 1;  //    External trigger gate function enable.Adapters.DmaPort&8
	USHORT IRQ_EN : 1;  //  Interrupt enable Adapters.DmaPort & 16
	USHORT ONE_FH : 1;  //  0 = interrupt after one data conversion, 1 = FIFO half full.Adapters.DmaPort & 32
	USHORT reserv10 : 10;  //
};

//��������� ����� ADVANTECH AD PCI1716
struct PCI1716_CONFIG
{
	UCHAR NumPC;	// ����� ���������� 
	UCHAR NumDevice;		// ���������� ����� �������� ������� ���� � ������ ��(���� )
	PCI1716_DEV_CTRL dev_ctrl;   // ��� ��������, IRQ � ����, - ���������� ��� ��������
	PCI1716_CH_CONFIG ch_conf[16];//Gain,B_U,S_D-���������� ��� ������� ������
};

//����������� ������������� ���������
//�������� ��������� � ����������
struct DeviceInfo
{
	ULONG bit1_23 : 23;	// ���������� ������� �������� (���� 1-26)
	ULONG NumDevice : 3;	 // ���������� ����� �������� ������� ���� � ������ ��(���� 24-26)
	ULONG TypeDevice : 6;	 // ��� �������� (���� 27-32)
	//�������������� 32 ����
	ULONG bit1_28 : 28;	// ���������� �������� (���� 1-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29,30,31,32)

	ULONG reserv;    		       // ���������� ������� �������� ()
};

//����������� ��������� ��� TX6_PC_C ����
struct ID_TX6_PC_C
{
	ULONG InOut : 1;	// ������� �������-1/��������-0 (��� 1)
	ULONG bit2_6 : 5;	// ���������� ��������
	ULONG NumWord : 5;	// ����� ����� (���� 7-11) NumWord = 0...31
	ULONG SubAddr : 5;	// �������� (���� 12-16)   SubAddr = 1...30
	ULONG mtDirection : 2;	// ����������� �������� ���������, ������� �����������: 1-�����, 0-��������, 2 - ���-170, 3 - ������������ ���/���� �� (���� 17-18)
	ULONG AddrRT : 5; 	// ����� �� (���� 19-23)       AddrRT = 0...31
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24-26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27-32)

	ULONG LoBit : 5; 	// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; 	// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG NumBatch : 16;	// �������� ����� ������ � �������� ��������� ��������  (���� 13-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29,32)

	union
	{
		ULONG d32;  // �������� ���������, ��� ������, ����� �� �������� ��� 16-�� ����. ����� (HiBit>15)
		USHORT d16[2];// �������� 16-�� ���������� ���������.  (� [0]-������� ����� d32,� [1]-������� ����� d32)
	} Data;

};
//��� ���������� ���/���� �� ���������� � �������� ��������� �������� �������� � ������� ��, ������� ���������� ��������� � mtDirection=3.
//��� �������� ����� ��������� =1 - �� ������� �� ����.
//��� �������� ����� ��������� =0 - �� ���������.

//����������� ��������� ��� PC429_3_88
struct ID_PC429_3_88
{
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG AddrFromData : 1;		// =0 ����� ������� �� ���� Address, =1 ����� ������� �� ������� 8 ��� ���� Data (���� 2)
	ULONG Gap : 1;		// ������� ������ ����� (��� 3), =1: ������ �����, =0: ������������ ������ �� ����� �����
	ULONG Address : 8;		// ���������� ������� �������� (���� 4-11)
	ULONG NumWord : 8;  // ���������� ����� ����� � ������ (���� 12-19)
	ULONG NumChannel : 4;  // ����� ������ �������� (���� 20-23)
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32)

	ULONG LoBit : 5;  // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;  // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	 // 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	 // 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16; // ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;	 // ����� ���������� (���� 29,30,31,32)

	ULONG Data;             	// �������� ��������� (���� 1-32)
};

//����������� ��������� ��� PC429_3_88
struct ID_PC429_4_xx
{
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG AddrFromData : 1;		// =0 ����� ������� �� ���� Address, =1 ����� ������� �� ������� 8 ��� ���� Data (���� 2)
	ULONG Gap : 1;		// ������� ������ ����� (��� 3), =1: ������ �����, =0: ������������ ������ �� ����� �����
	ULONG Address : 8;		// ���������� ������� �������� (���� 4-11)
	ULONG NumWord : 8;  // ���������� ����� ����� � ������ (���� 12-19)
	ULONG NumChannel : 4;  // ����� ������ �������� (���� 20-23)
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32)

	ULONG LoBit : 5;  // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;  // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	 // 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	 // 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16; // ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;	 // ����� ���������� (���� 29,30,31,32)

	ULONG Data;             	// �������� ��������� (���� 1-32)
};

//����������� ��������� ��� SPECIAL
// ����� 0x0 ��������������:
//			 ������� ���������: ��� ��������� ������� ������� ����� �������� ���������� �� RefMem 
//			 ������� ���������: ��� ���������� ��������� ����������� �����
//  ���������� ������� ���������� � �������� <> 0 ����� ����, ������ ��������
//  ���������� �������� ���������� � �������� <> 0 ����� ����, ������ ��� ��������,
//  ������ ���� �������� �������� � ������, ��������� ��� � �������� �������������
//
struct ID_SPECIAL {
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG Address : 22; // ����� (���� 2-23) 
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32)

	ULONG LoBit : 5;		// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;		// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;		// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;		// 2-� �������� ��� (��� 12)
	ULONG TypePack : 8;		// ������ �������� ������ (���� 13-20)
	// ----------------------------------------------------------------------------------------------
	// TypePack   ���            ������     ��������
	// ----------------------------------------------------------------------------------------------
	//				0			 unknow														4     ��� �������� ������������ ���� LoBit,HiBit,SignBit1,SignBit2)
	//				1				int															  4					signed, signed int System dependent
	//				2				unsigned int						  4					unsigned System dependent
	//				3				__int8												  1					char, signed char �128 to 127
	//				4				__int16											  2					short, short int, signed short int �32,768 to 32,767
	//				5				__int32											  4					signed, signed int �2,147,483,648 to 2,147,483,647
	//				6				__int64											  8					none �9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
	//				7				char														  1					signed char �128 to 127
	//				8				unsigned char					  1					none 0 to 255
	//				9				short													  2					short int, signed short int �32,768 to 32,767
	//			10				unsigned short				  2					unsigned short int 0 to 65,535
	//			11				long														  4					long int, signed long int �2,147,483,648 to 2,147,483,647
	//			12				unsigned long					  4					unsigned long int 0 to 4,294,967,295
	//			13				enum														  *					none Same as int
	//			14				float													  4					none 3.4E +/- 38 (7 digits)
	//			15				double												  8					none 1.7E +/- 308 (15 digits)
	//			16				long double							 10					none 1.2E +/- 4932 (19 digits)
	// ----------------------------------------------------------------------------------------------
	ULONG bit13_28 : 8;		// ���������� �������� (���� 21-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29,30,31,32)

	union
	{
		float flD;								// �������� ���������
		LONG lD;										// �������� ���������
		ULONG ulD;								// �������� ���������
		SHORT sD[2];						// �������� ���������
		USHORT usD[2];				// �������� ���������
		CHAR cD[4];							// �������� ���������
		UCHAR ucD[4];	    // �������� ���������
	} Data;

};

//����������� ��������� ��� ��� LCARD_761  // ����
struct ID_LCARD_761 {
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG bit2_18 : 17;	// not used (���� 2-18)
	ULONG NumChannel : 5;		// DataBurst.NumLine - ����� ������ �������� (���� 19,20,21,22,23)
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32)

	ULONG LoBit : 5;		// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;		// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;		// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;		// 2-� �������� ��� (��� 12)
	ULONG reserv : 16;		// not used
	ULONG NumPC : 4;		// ����� ���������� (���� 29-32)

	union
	{
		ULONG d32;  // �������� ���������, ��� ������, ����� �� �������� ��� 16-�� ����. ����� (HiBit>15)
		USHORT d16[2];// �������� 16-�� ���������� ���������.  (� [0]-������� ����� d32,� [1]-������� ����� d32)
	}  Data;
};
//����������� ��������� ��� ��� LCARD_1208   // ����
struct ID_LCARD_1208 {
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG fSin : 2;		// =StrDescr.SubAddr (0-simple signal,1-��������� ���������, 2 - ���� �������) (���� 2-3)
	ULONG Address : 8;		// =StrDescr.Address (1-8) - ��� TTL-�����(���� 4-11)
	//	��� SimpleDAC -�� ������������
	ULONG bit3_19 : 8;		// (���� 12-19)
	ULONG NumChannel : 4;		// =StrDescr.NumLine-����� ������ �������� (���� 20-23)
	// ������ 1-8 -���
	// ������ 9,10-���
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24-26)
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32)

	ULONG LoBit : 5;		// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;		// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;		// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;		// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	// (���� 13-28) 
	ULONG NumPC : 4;		// ����� ���������� (���� 30-32)
	union
	{
		ULONG d32;     // �������� ���������, ��� ������, ����� �� �������� ��� 16-�� ����. ����� (HiBit>15)
		USHORT d16[2]; //  
		float  phase;  // ���� � ���.��� ������� ���������
	}  Data;
};

//����������� ��������� ��� �������� ��   // ����

struct ID_OL {
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG NumWord : 10;	// StrDescr.NumWine (0-23,��� ���������!) 2-11
	ULONG reserv : 12;	// Not used  (���� 12-23)
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32)

	ULONG LoBit : 5;		// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;		// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;		// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;		// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29-32)

	ULONG Data;					// �������� ��������� (���� 1-32)
};

//����������� ��������� ��� �������� Astra   // ����
struct ID_ASTRA {
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG Address : 18;	// StrDescr.Address (���� 2-19)-18 ��� 
	ULONG Update : 1;		// ������ ��������� (��� 20)
	ULONG reserv : 3;		// Not used  (���� 21-23)
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32)

	ULONG LoBit : 5;		// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;		// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;		// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;		// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29-32)

	ULONG Data;					// �������� ��������� (���� 1-32)
};

//����������� ��������� ��� �������� Astra_BL   // ����
struct ID_ASTRA_BL {
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG Address : 18;	// StrDescr.Address (���� 2-19)-18 ��� 
	ULONG False : 1;		// ������� ���� ������ (��� 20)
	ULONG NumWord : 3;		// 0, 1..4 StrDescr.NumWord (���� 21-23)-����� ����������� ������ ��� �������, c 1, 0 - ������� ���������� 
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26), � �� - � 1, �� IPC - c 0.
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32)

	ULONG LoBit : 5;		// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;		// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;		// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;		// 2-� �������� ��� (��� 12)
	ULONG reserv : 16;	// ������� ����� (���� 13-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29-32)

	ULONG Data;					// �������� ��������� (���� 1-32)
};
//����������� ��������� ��� PCI_1753  // ���
struct ID_PCI_1753 {
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG bit2_14 : 13;	// ���������� ������� �������� (���� 2-14)
	ULONG Inversion : 1;		// ������� �������� ������ ����� �������/������ (��� 15)
	ULONG Address : 3;	 // �����(���� 16-18) (����� ���� � ����� �����-������)
	ULONG NumChannel : 5;	 // ����� ������ �������� (���� 19-23) (����� �����-������ ��������������� �������� ��� ��������)
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32

	ULONG LoBit : 5; // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29,30,31,32)

	ULONG Data : 1; // �������� ��������� (��� 1)
	ULONG reserv : 31;// ������ ��� ������������ (���� 2-32)
};

//����������� ��������� ��� VMIC5587 // ����
struct ID_VMIC5587 {
	ULONG InOut : 1;	// ������� �������-1/��������-0 (��� 1)
	ULONG Address : 22;// ����� (���� 2-23)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;	// ��� �������� = 15 (���� 27-32)

	ULONG Type_INT : 2;	//��� ����������, ������� ���� �������������
	//	GEN_INT_RESET   0
	//	GEN_INT1        1
	//	GEN_INT2        2
	//	GEN_INT3        3
	// ������� �� ���� LoBit
	ULONG INT_DATA : 10;// ������, ���������� � �����������. ������� �� ���� HiBit
	ULONG TypePack : 8;	// ������ �������� ������ (���� 13-20).  ������� �� ���������� ���������� �� ShMem
	// ��������� ������������ � ���� NumLowBit
	// ----------------------------------------------------------------------------------------------
	// TypePack   ���            ������     ��������
	// ----------------------------------------------------------------------------------------------
	// 0			 unknow														4     ��� �������� ������������ ���� LoBit,HiBit,SignBit1,SignBit2,NumLowBit)
	// 1				int															  4					signed, signed int System dependent
	// 2				unsigned int						  4					unsigned System dependent
	// 3				__int8												  1					char, signed char �128 to 127
	// 4				__int16											  2					short, short int, signed short int �32,768 to 32,767
	// 5				__int32											  4					signed, signed int �2,147,483,648 to 2,147,483,647
	// 6				__int64											  8					none �9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
	// 7				char														  1					signed char �128 to 127
	// 8				unsigned char					  1					none 0 to 255
	// 9				short													  2					short int, signed short int �32,768 to 32,767
	// 10				unsigned short				  2					unsigned short int 0 to 65,535
	// 11				long														  4					long int, signed long int �2,147,483,648 to 2,147,483,647
	// 12				unsigned long					  4					unsigned long int 0 to 4,294,967,295
	// 13				enum														  *					none Same as int
	// 14				float													  4					none 3.4E +/- 38 (7 digits)
	// 15				double												  8					none 1.7E +/- 308 (15 digits)
	// 16				long double							 10					none 1.2E +/- 4932 (19 digits)
	// ----------------------------------------------------------------------------------------------
	ULONG DestNId : 8;	// NID ����, � ������� ���� ������������� ���������� (�������� 1...254)
	// ��� 0, ���� �� ������������ ��� 255, ���� �� ���� ����� �����.
	// ������� �� ���� CheckWord
	ULONG NumPC : 4;	// ����� ���������� (���� 29,30,31,32)

	union
	{
		float f32bit;	// �������� ��������� 32bit
		ULONG u32bit;		// �������� ��������� 32bit
		USHORT u16bit;		// �������� ��������� 16bit
		UCHAR u8bit;	    // �������� ��������� 8bit
	} Data;
};

//����������� ��������� ��� VMIC5565 ����
struct ID_VMIC5565 {
	ULONG InOut : 1;	// ������� �������-1/��������-0 (��� 1)
	ULONG Type_INT : 3;	//��� ����������, ������� ���� ������������� (��� 2-4)
	//GEN_INT_RESET_5565   0 //Reset Node Request 
	//GEN_INT1_5565        1 //Network Interrupt 1
	//GEN_INT2_5565        2 //Network Interrupt 2
	//GEN_INT3_5565        3 //Network Interrupt 3
	//GEN_INT_INIT_5565    7 //Network Initialized Interrupt
	// ������� �� ���� LoBit
	ULONG TypePack : 8;	// ������ �������� ������ (���� 5-12).  ������� �� ���������� ���������� �� ShMem
	// ��������� ������������ � ���� NumLowBit
	ULONG DestNId : 8;	// (���� 13-20) NID ����, � ������� ���� ������������� ���������� (�������� 1...254)
	// ��� 0, ���� �� ������������ ��� 255, ���� �� ���� ����� �����.
	// ������� �� ���� CheckWord
	ULONG reserv3 : 3; // ������ (���� 21-23). 
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;	// ��� �������� = 15 (���� 27,28,29,30,31,32)

	ULONG Address : 27;// ����� ��������� � RMN (���� 1-27)
	ULONG reserv28 : 1;	// ������ (��� 28). 
	ULONG NumPC : 4;	// ����� ���������� (���� 29,30,31,32)
	union
	{
		float f32bit;	// �������� ��������� 32bit
		ULONG u32bit;		// �������� ��������� 32bit ��� ������ ��� ����������, ���� DestNId = 1...255
		USHORT u16bit;		// �������� ��������� 16bit
		UCHAR u8bit;	    // �������� ��������� 8bit
	} Data;
};

//����������� ��������� ��� IPK1  // ���
struct ID_IPK1 {
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG bit2_23 : 22; // ���������� �������� (���� 2-23)
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32)

	ULONG LoBit : 5; // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29,30,31,32)

	ULONG  Data;              // �������� ��������� (���� 1-32)
};

//����������� ��������� ��� ADVANTECH AD PCI1713  // ����
struct ID_PCI1713 {
	ULONG InOut : 1; 	// ������� �������-1/��������-0 (��� 1)
	ULONG bit2_9 : 8; // ���������� �������� (���� 2-9)
	ULONG SignShift : 1;	 // ' ���� �������� 0: �������. 1:�����.
	ULONG Shift : 8;	// ' �������� 0 �� ����� � ��������� ��������
	ULONG NumChannel : 5;  // Address c 1- ����� ������ �������� (���� 19-23) (����� �����-������ ��������������� �������� ��� ��������)
	ULONG NumDevice : 3;		// c 1- ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// 20 ��� �������� (���� 27,28,29,30,31,32)

	ULONG LoBit : 5; // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29,30,31,32)

	ULONG Data;      // �������� ��������� (��� 1-32) -12 ���
};

//����������� ��������� ��� ADVANTECH AD PCI1716  // ����
struct ID_PCI1716 {
	ULONG InOut : 1; 	// ������� �������-1/��������-0 (��� 1)
	ULONG bit2_18 : 17;	// ������ (���� 2-18)
	ULONG NumChannel : 5;  // Address c 1- ����� ������ �������� (���� 19-23) (����� �����-������ ��������������� �������� ��� ��������)
	ULONG NumDevice : 3;		// c 1- ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// 20 ��� �������� (���� 27,28,29,30,31,32)

	ULONG LoBit : 5; // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29,30,31,32)

	ULONG Data; // �������� ��������� (��� 1-32) -12 ���
};

//����������� ��������� ��� ��� ���  // ����
struct ID_CusBmk {

	ULONG InOut : 1;	// ������� �������-1/��������-0 (��� 1)
	ULONG bit2_6 : 5;	// ���������� ��������
	ULONG bit7_11 : 5;	// ����� ����� (���� 7-11) 
	ULONG bit12_15 : 4;	// �������� (���� 12-15)   
	ULONG Addr : 8; // ����� ��������� (���� 16-23)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24-26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27-32)

	ULONG LoBit : 5; 	// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; 	// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	//   (���� 13-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29-32)

	USHORT Data;			// �������� 16-�� ���������� ���������
	USHORT Rez;
};

// ����������� ��������� ��� ��� PCIxyzDAC
struct ID_PCIxyzDAC {
	ULONG InOut : 1;	// ������� �������-1/��������-0 (��� 1)
	ULONG NumChannel : 3; // ����� ������ �������� (��������� � 1)(���� 2,3,4)
	ULONG bit5_23 : 19;// ����� (���� 5-23)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ �� (������� � 1)(���� 24,25,26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27-32)

	ULONG LoBit : 5; // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;// ����� (���� 13-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29,30,31,32)

	USHORT Data;				// �������� 16-�� ���������� ���������
	USHORT bit16_32;			// �����
};

// ����������� ��������� ��� ���� PCI_1705
struct ID_PCI1705 {
	ULONG InOut : 1;  // ������� �������-1/��������-0 (��� 1)
	ULONG bit2_9 : 8;  // ������
	ULONG Address : 8;	 // ����� ���������� ���������� (�� 1 �� 255)
	ULONG NumWord : 6;	 // ����� ����� ������ (������� � 0)
	ULONG NumDevice : 3;	 // ���������� ����� �������� ������� ���� � ������ ��(������� � 0)(���� 24,25,26)
	ULONG TypeDevice : 6;	 // ��� �������� (���� 27-32)

	ULONG LoBit : 5;  // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;  // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	 // 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	 // 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 20; // 


	ULONG Data; // �������� ��������� 
};
// ����������� ��������� ��� ��� pciSPI
struct ID_pciSPI {
	ULONG InOut : 1;	// ������� �������-1/��������-0 (��� 1)
	ULONG Address : 3; // ����� �� (��������� � 1)(���� 2,3,4)
	ULONG bit5_23 : 19;// ����� (���� 5-23)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ �� (������� � 1)(���� 24,25,26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27-32)

	ULONG LoBit : 5; // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;// ����� (���� 13-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29,30,31,32)

	USHORT Data;				// �������� 16-�� ���������� ���������, ������������� ������ � 0-4 ���.
	USHORT bit16_32;			// �����
};

// ����������� ���������� ��� ����
struct ID_MTVS {
	ULONG InOut : 1;	 // ������� �������-1/��������-0 (��� 1)
	ULONG Address : 4; // ����� ���� (0�08) (���� 2,3,4,5)
	ULONG bit5_23 : 18;// ����� (���� 6-23)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ �� (������� � 1)(���� 24,25,26)
	ULONG TypeDevice : 6;	// ��� �������� = 30 (���� 27-32)

	ULONG LoBit : 5; // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;// ����� (���� 13-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29,30,31,32)

	union
	{
		USHORT Data;		// �������� 16-�� ���������� ���������
		unsigned char usD[2];   // 1 ���� ������
	}Data;
	USHORT bit16_32;			// �����
};


struct ID_PCADS05
{
	ULONG InOut : 1;	// ������� �������-1/��������-0 (��� 1)
	ULONG AddrFromData : 1;	// =0 ����� ������� �� ���� Address, =1 ����� ������� �� ������� 8 ��� ���� Data (��� 2)
	ULONG Gap : 1;	// ������� ������ ����� (��� 3), =1: ������ �����, =0: ������������ ������ �� ����� �����
	ULONG Address : 8;	// ���������� ������� �������� (���� 4-11)
	ULONG NumWord : 8;	// ���������� ����� ����� � ������ (���� 12-19)
	ULONG bit20_23 : 4;	// ������ (���� 20-23)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27-32)

	ULONG LoBit : 5;	// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;	// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG NumChannel : 7;	// ����� ������ �������� (���� 13-19)
	ULONG bit20_28 : 9;	// ���������� ������� �������� (���� 20-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29,30,31,32)

	ULONG Data;					// �������� ��������� (���� 1-32)
};

struct ID_PCADS05K
{
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG bit2_23 : 22; // ���������� �������� (���� 2-23)
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32)

	ULONG LoBit : 5; // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29,30,31,32)

	ULONG Data;					// �������� ��������� (���� 1-32)
};


struct ID_PCADS05RK
{
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG Channel : 6;		// ����� ������ ������ ������ ��
	ULONG Logic : 1;		// ��������
	// ���� ������ ������������ ��� ����������� ���� ������ ��� ���
	// 0 - ��������� ������ ��� ��
	// 1 - ��������� ������ ��� ������������ ����� ���
	// 2 - ��������� ������ ��� ���������� ���, � ��������� ��������
	// ��� �� ���� Adress ������������ ��� ����������� ��������� ������ �� ������ ��
	ULONG Address : 2;		// ������������ ��� ������� ������ �� ���������� � �� � ���
	ULONG bit11_23 : 13;		// ���������� �������� (���� 11-23)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27-32)

	ULONG LoBit : 5;		// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;		// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;		// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;		// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29,30,31,32)

	//�������� ��������� data 
	// �������� �� � ������ �������� ���������� � Address = 0
	// ��� [0] - �������� ��������. 
	// ���������� ���������� ������ ��� ��������� ������� �� ���������� ��������� ������� Address = 1
	// ��� [0] - �������� ��������� ������� ������. 
	// 0 - ��������� ������ ������������ ��������� ������ ���������� �� Address = 0
	// 1 - ��������� ������ ����� ��������� ������e/��� ������������ � ������� ������

	// ������� ����� ���������� ������ ��� ��������� ������� �� � ��������� ����� ��� ��� ������ ���� mode, ������������ ��� ������ ������� vbCreate_PCADS05RK
	// ���� ������������� �������� ����� ��� ���, �� �������� ���������� ��������� ������� Address = 1
	// ���� [31�28] � ����� �������� ����� (�� 0 �� 15);
	// ���  [27] � ������������ �������;
	// ���� [26�0] � �������� �������(� ���) �� ����������� ���������� ������(�� 0 �� 134� (227���)).

	// ���� �������������� �������� ������ ��� ���������� ���, �� ������ ����������� ��������� �������  Address = 2
	// ���� [31-16] - ������� ���. ����������� ������ � ��� ������, ���� ����� �������� ������ �� ��� = 2
	// ��� [4] - ��������� ��� blockCounter. ����������� ������ � ��� ������, ���� ����� �������� ������ �� ��� = 3
	// 0 - ������� ��� ����������� ��� ������. 1 - ������� ��� �� ����������� ��� ������.
	// ��� [3] - ��������� ��� extControl. ����������� ������ � ��� ������, ���� ����� �������� ������ �� ��� = 3
	// 0 - ��� �� ������� �� �������� ���������. 1 - ��� ������� �� �������� ���������.
	// ��� [2] - ��������� ��� enable. ����������� ������ � ��� ������, ���� ����� �������� ������ �� ��� = 3
	// 0 - ��� ��������. 1 - ��� �������.
	// ��� [0-1] - ������������ ����� �������� ������ �� ���:
	// 0 - �� ��� �� ���������� ������� ������.
	// 1 - �� ��� ���������� �������� �����
	// 2 - �� ��� ���������� �������
	// 3 - �� ��� ���������� ���������
	ULONG Data;				// �������� ��������� (���� 1-32)
};

struct ID_PCADS06RTM
{
	ULONG InOut : 1;	// ������� �������-1/��������-0 (��� 1)
	ULONG AddrFromData : 1;	// =0 ����� ������� �� ���� Address, =1 ����� ������� �� ������� 8 ��� ���� Data (��� 2)
	ULONG Gap : 1;	// ������� ������ ����� (��� 3), =1: ������ �����, =0: ������������ ������ �� ����� �����
	ULONG Address : 8;	// ���������� ������� �������� (���� 4-11)
	ULONG NumWord : 8;	// ���������� ����� ����� � ������ (���� 12-19)
	ULONG bit20_23 : 4;	// ������ (���� 20-23)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27-32)

	ULONG LoBit : 5;	// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;	// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG NumChannel : 8;	// ����� ������ �������� (���� 13-20)
	ULONG bit21_28 : 8;	// ���������� ������� �������� (���� 21-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29,30,31,32)

	ULONG Data;					// �������� ��������� (���� 1-32)
};

struct ID_PCADS06K
{
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG bit2_23 : 22; // ���������� �������� (���� 2-23)
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32)

	ULONG LoBit : 5; // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29,30,31,32)

	ULONG Data;					// �������� ��������� (���� 1-32)
};

struct ID_PCADS06RK
{
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG Channel : 8;		// ����� ������ ������ ������ �� (��� 2-9)
	ULONG Logic : 1;		// �������� (��� 10)
	// ���� ������ ������������ ��� ����������� ���� ������ ��� ���
	// 0 - ��������� ������ ��� ��
	// 1 - ��������� ������ ��� ������������ ����� ���
	// 2 - ��������� ������ ��� ���������� ���, � ��������� ��������
	// ��� �� ���� Adress ������������ ��� ����������� ��������� ������ �� ������ ��
	ULONG Address : 2;		// ������������ ��� ������� ������ �� ���������� � �� � ��� (��� 11-12)
	ULONG bit13_23 : 11;		// ���������� �������� (���� 13-23)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24-26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27-32)

	ULONG LoBit : 5;		// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;		// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;		// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;		// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29,30,31,32)

	//�������� ��������� data 
	// �������� �� � ������ �������� ���������� � Address = 0
	// ��� [0] - �������� ��������. 
	// ���������� ���������� ������ ��� ��������� ������� �� ���������� ��������� ������� Address = 1
	// ��� [0] - �������� ��������� ������� ������. 
	// 0 - ��������� ������ ������������ ��������� ������ ���������� �� Address = 0
	// 1 - ��������� ������ ����� ��������� ������e/��� ������������ � ������� ������

	// ������� ����� ���������� ������ ��� ��������� ������� �� � ��������� ����� ��� ��� ������ ���� mode, ������������ ��� ������ ������� vbCreate_PCADS05RK
	// ���� ������������� �������� ����� ��� ���, �� �������� ���������� ��������� ������� Address = 1
	// ���� [31�28] � ����� �������� ����� (�� 0 �� 15);
	// ���  [27] � ������������ �������;
	// ���� [26�0] � �������� �������(� ���) �� ����������� ���������� ������(�� 0 �� 134� (227���)).

	// ���� �������������� �������� ������ ��� ���������� ���, �� ������ ����������� ��������� �������  Address = 2
	// ���� [31-16] - ������� ���. ����������� ������ � ��� ������, ���� ����� �������� ������ �� ��� = 2
	// ��� [4] - ��������� ��� blockCounter. ����������� ������ � ��� ������, ���� ����� �������� ������ �� ��� = 3
	// 0 - ������� ��� ����������� ��� ������. 1 - ������� ��� �� ����������� ��� ������.
	// ��� [3] - ��������� ��� extControl. ����������� ������ � ��� ������, ���� ����� �������� ������ �� ��� = 3
	// 0 - ��� �� ������� �� �������� ���������. 1 - ��� ������� �� �������� ���������.
	// ��� [2] - ��������� ��� enable. ����������� ������ � ��� ������, ���� ����� �������� ������ �� ��� = 3
	// 0 - ��� ��������. 1 - ��� �������.
	// ��� [0-1] - ������������ ����� �������� ������ �� ���:
	// 0 - �� ��� �� ���������� ������� ������.
	// 1 - �� ��� ���������� �������� �����
	// 2 - �� ��� ���������� �������
	// 3 - �� ��� ���������� ���������
	ULONG Data;				// �������� ��������� (���� 1-32)
};

struct ID_PCADSv7RTM	//��������� �������� ��� ��������� ���� PCADSv7RTMin � PCADSv7RTMout
{
	ULONG InOut : 1;	// ������� �������-1/��������-0 (��� 1)
	ULONG AddrFromData : 1;	// =0 ����� ������� �� ���� Address, =1 ����� ������� �� ������� 8 ��� ���� Data (��� 2)
	ULONG Gap : 1;	// ������� ������ ����� (��� 3), =1: ������ �����, =0: ������������ ������ �� ����� �����
	ULONG Address : 8;	// ���������� ������� �������� (���� 4-11)
	ULONG NumWord : 8;	// ���������� ����� ����� � ������ (���� 12-19)
	ULONG bit20_23 : 4;	// ������ (���� 20-23)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27-32)

	ULONG LoBit : 5;	// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;	// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG NumChannel : 6;	// ����� ������ �������� (���� 13-18)	��� ����� ������ 64 ������, �.�. � [33 �� 64] ����� - ������ �������
	ULONG bit19_28 : 10;	// ���������� ������� �������� (���� 19-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29,30,31,32)

	ULONG Data;					// �������� ��������� (���� 1-32)
};
struct ID_PCADSv7RK		//��������� �������� ��� ��������� ���� PCADSv7RKin � PCADSv7RKout
{
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG Channel : 6;		// ����� ������ ������ ������ �� (��� 2-7)
	ULONG Logic : 1;		// �������� (��� 8)
	// ���� ������ ������������ ��� ����������� ���� ������ ��� ���
	// 0 - ��������� ������ ��� ��
	// 1 - ��������� ������ ��� ������������ ����� ���
	// 2 - ��������� ������ ��� ���������� ���, � ��������� ��������
	// ��� �� ���� Adress ������������ ��� ����������� ��������� ������ �� ������ ��
	ULONG Address : 2;		// ������������ ��� ������� ������ �� ���������� � �� � ��� (��� 9-10)
	ULONG Line : 4;			//����� ����� �������� ������ [0..6] - �������, [7..13] - ��������
	ULONG bit15_23 : 9;		// ���������� �������� (���� 11-23)
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24-26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27-32)

	ULONG LoBit : 5;		// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5;		// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;		// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;		// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29,30,31,32)

	//�������� ��������� data 
	// �������� �� � ������ �������� ���������� � Address = 0
	// ��� [0] - �������� ��������. 
	// ���������� ���������� ������ ��� ��������� ������� �� ���������� ��������� ������� Address = 1
	// ��� [0] - �������� ��������� ������� ������. 
	// 0 - ��������� ������ ������������ ��������� ������ ���������� �� Address = 0
	// 1 - ��������� ������ ����� ��������� ������e/��� ������������ � ������� ������

	// ������� ����� ���������� ������ ��� ��������� ������� �� � ��������� ����� ��� ��� ������ ���� mode, ������������ ��� ������ ������� vbCreate_PCADS05RK
	// ���� ������������� �������� ����� ��� ���, �� �������� ���������� ��������� ������� Address = 1
	// ���� [31�28] � ����� �������� ����� (�� 0 �� 15);
	// ���  [27] � ������������ �������;
	// ���� [26�0] � �������� �������(� ���) �� ����������� ���������� ������(�� 0 �� 134� (227���)).

	// ���� �������������� �������� ������ ��� ���������� ���, �� ������ ����������� ��������� �������  Address = 2
	// ���� [31-16] - ������� ���. ����������� ������ � ��� ������, ���� ����� �������� ������ �� ��� = 2
	// ��� [4] - ��������� ��� blockCounter. ����������� ������ � ��� ������, ���� ����� �������� ������ �� ��� = 3
	// 0 - ������� ��� ����������� ��� ������. 1 - ������� ��� �� ����������� ��� ������.
	// ��� [3] - ��������� ��� extControl. ����������� ������ � ��� ������, ���� ����� �������� ������ �� ��� = 3
	// 0 - ��� �� ������� �� �������� ���������. 1 - ��� ������� �� �������� ���������.
	// ��� [2] - ��������� ��� enable. ����������� ������ � ��� ������, ���� ����� �������� ������ �� ��� = 3
	// 0 - ��� ��������. 1 - ��� �������.
	// ��� [0-1] - ������������ ����� �������� ������ �� ���:
	// 0 - �� ��� �� ���������� ������� ������.
	// 1 - �� ��� ���������� �������� �����
	// 2 - �� ��� ���������� �������
	// 3 - �� ��� ���������� ���������
	ULONG Data;				// �������� ��������� (���� 1-32)
};
struct ID_iMKIO
{
	ULONG InOut : 1;	// ������� �������-1/��������-0 (��� 1)
	ULONG Bus : 1;		// ����� ���� (��� 2)
	ULONG bit3_5 : 3;	// ���������� �������� (���� 3-5)
	ULONG NumWord : 5;	// ����� ����� (���� 6-10) NumWord = 0...31
	ULONG SubAddr : 5;	// �������� (���� 11-15)   SubAddr = 1...30
	ULONG mtDirection : 3;	// ����������� �������� ���������, ������� �����������: 0-�� ��, 1-�� ����, 2 - ������� ��������� ����� 3 - ������������ ���/���� �� (���� 16-18)
	ULONG AddrRT : 5; 	// ����� �� (���� 19-23)       AddrRT = 0...31
	ULONG NumDevice : 3;	// ���������� ����� �������� ������� ���� � ������ ��(���� 24-26)
	ULONG TypeDevice : 6;	// ��� �������� (���� 27-32)

	ULONG LoBit : 5; 	// ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; 	// ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	// (���� 13-28)
	ULONG NumPC : 4;	// ����� ���������� (���� 29,32)

	union
	{
		ULONG d32;  // �������� ���������, ��� ������, ����� �� �������� ��� 16-�� ����. ����� (HiBit>15)
		USHORT d16[2];// �������� 16-�� ���������� ���������.  (� [0]-������� ����� d32,� [1]-������� ����� d32)
	} Data;
};

// ����� ���� � ���������� ���������� ��� ���� ���������
struct ParameterInfo {
	ULONG InOut : 1;		// ������� �������-1/��������-0 (��� 1)
	ULONG bit2_23 : 22; // ���������� �������� (���� 2-23)
	ULONG NumDevice : 3;		// ���������� ����� �������� ������� ���� � ������ ��(���� 24,25,26)
	ULONG TypeDevice : 6;		// ��� �������� (���� 27-32)

	ULONG LoBit : 5; // ������� ��� ��������� (� 1-��) (���� 1-5)
	ULONG HiBit : 5; // ������� ��� ��������� (� 1-��) (���� 6-10)
	ULONG SignBit1 : 1;	// 1-� �������� ��� (��� 11)
	ULONG SignBit2 : 1;	// 2-� �������� ��� (��� 12)
	ULONG bit13_28 : 16;	// ���������� ������� �������� (���� 13-28)
	ULONG NumPC : 4;		// ����� ���������� (���� 29,30,31,32)

	union
	{
		float flD;								// �������� ��������� (���� 1-24) � ������ (���� 25-32)
		ULONG ulD;								// �������� ��������� (���� 1-24) � ������ (���� 25-32)
		USHORT usD[2];				// �������� ��������� (���� 1-24) � ������ (���� 25-32)
		UCHAR ucD[4];	    // �������� ��������� (���� 1-24) � ������ (���� 25-32)
	} Data;

};

//����������� ������������� ���������
union ID_Parameter
{
	ULONG              FullParam[3]; // ������ �� ���� 32��������� ����������
	DeviceInfo         DevInfo;      // �������� ��������� � ����������
	ParameterInfo					 ParamInfo;				// ����� ������� ����
	ID_SPECIAL         special;						// ����������� ��������� ��� SPECIAL (����.����������)
	ID_TX6_PC_C        Tx6_pc;       // ����������� ��������� ��� TX6_PC_C
	ID_PC429_3_88      pc429;        // ����������� ��������� ��� PC429_3_88
	ID_PC429_4_xx      pc429_4;      // ����������� ��������� ��� PC429_4_xx
	ID_PCI_1753        pci1753;      // ����������� ��������� ��� PCI_1753
	ID_ASTRA           Astra;        // ����������� ��������� ��� �����
	ID_VMIC5587	     		vmic5587;		   // ����������� ��������� ��� VMIC5587
	ID_VMIC5565				    vmic5565;		   // ����������� ��������� ��� VMIC5565
	ID_IPK1            ipk1;				     // ����������� ��������� ��� IPK1
	ID_PCI1713				     pci1713;	     // ����������� ��������� ��� PCI_1713
	ID_PCI1724				     pci1724;		    // ����������� ��������� ��� PCI_1724
	ID_PCI1723				     pci1723;		    // ����������� ��������� ��� PCI_1723
	ID_CusBmk			       cus_bmk; 		   // ����������� ��������� ��� ��� ���
	ID_PCI1716				     pci1716;	     // ����������� ��������� ��� PCI_1716
	ID_ASTRA_BL        Astra_BL;     // ����������� ��������� ��� ����� BL - ������ ������
	ID_PCIxyzDAC       xyzDAC;       // ����������� ��������� ��� ��� xyzDAC
	ID_PCI1705         KMBO_1705;    // ����������� ��������� ��� ���� PCI_1705
	ID_pciSPI          pci_SPI;      // ����������� ��������� ��� ��� pciSPI
	ID_MTVS			         rs485mtvs;    // ����������� ��������� ��� ���� ������������ ����� RS485
	ID_PCADS05	      		PCADS05;		   	// ����������� ��������� ��� PCADS05 RTM
	ID_PCADS05K		      PCADS05K;				 // ����������� ��������� ��� PCADS05 ����������
	ID_PCADS05RK       PCADS05RK;    // ����������� ��������� ��� PCADS05 ������� �������
	ID_PCADS06RTM	     PCADS06RTM;		 // ����������� ��������� ��� PCADS06 RTM
	ID_PCADS06K		      PCADS06K;				 // ����������� ��������� ��� PCADS06 ����������
	ID_PCADS06RK       PCADS06RK;    // ����������� ��������� ��� PCADS06 ������� �������
	ID_PCADSv7RTM		PCADSv7RTM;		// ����������� ��������� ��� PCADSv7 ���
	ID_PCADSv7RK	PCADSv7RK;		// ����������� ��������� ��� PCADSv7 ��
	ID_iMKIO		        	iMKIO;	       // ����������� ��������� ��� iMKIO1
};

#endif