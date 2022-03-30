#ifndef _RtxMSI
#define _RtxMSI

////////////////////////////////////////////////////////////////////
//                                                                //
//	RtxApp1.h - header file                                       //
//                                                                //
// This file was generated using the RTX Application Wizard       //
// for Visual Studio.                                             //
////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <wchar.h>
#include <rtapi.h>
#include <RtxProp.h>
#include <stdio.h>
#include <time.h>

// RMe_02
#define  RMe_02_VendorID  0x1172;
#define  RMe_02_DeviceID  0x5950;
const unsigned __int64 PartCount = 8; //���������� ��������� ������ �� �����
const unsigned __int64 InterruptCount = 16;  //������������ ���������� ���������� ������� ����

#define WAIT_PULSE_by_REG  75000 // ���-�� ������ �������� �������� ��������� LPT �����

// Total number of cards allowed for the test
#define MAX_NUM_CARDS 8

struct _RMe_02_BAR0
 {
 unsigned __int64 Counter;	       // 0x00 R/W ������� ������ 100���. ����� ������ ���������� ������� � 0;
	unsigned __int32 Frameware : 32;	// 0x08 RO  ����� �������� RMe_02
	unsigned __int32 ID        : 32;	// 0x0C RO  ����� ���� (������������ ���������� �� �����)
 struct                           // 0x10 R/W ������� ���������� ������;
		{
		unsigned __int32 clearLine           : 1;  // ��������� ������ ������� ����� (deNoise) �� 10���� ����� �������� ������������ ������������ ����. ������ ��� ��������� � �������� �� ��������� �������������;
		unsigned __int32 resetPackCounter    : 1;	 // ����� ���������. ������� (�������� 1Ch). ������ ��� ��������� � �������� �� ��������� �������������;
		unsigned __int32 resetBufferOverload : 1;	 // ����� ����� ������������ FIFO-������� (�������� 14h, ���� 8 � 12). ������ ��� ��������� � �������� �� ��������� �������������;
		unsigned __int32                     : 5;  // �� ������������
		unsigned __int32 lockBuferOutput     : 1;	 // ���������� FIFO-������ ��������� �������� ������ (BAR1 ->RAM);
		unsigned __int32                     : 7;  // �� ������������
		unsigned __int32 counterChoose       : 2;  //����� �������� ��� ����������� � �������� �� ��������� 1Ch (�00� � ����� ������ ������������������ ������ �� ���� �����, � 10�� ��������; �01� � ������� ������� ������������ � ������ ����; �10� - ������� �������, ������������ � ������������ ����; �11� - ������� �������, ���������� �� ������������ ����);
		unsigned __int32                     : 14; // �� ������������
		} config;
 struct                           // 0x14 RO ��������� �������
		{
		unsigned __int32 SD                  : 1; // SD� ����������� ������� ���������� ����������� ����� RMe - 02 (��� ��������� �������� ������� ���������� �� ������ ����� RMe - 02);
		unsigned __int32 onLine              : 1;	// �onLine� � ������� ����� ���������������� ������������ ����: ����� ���������������� ����� ����� � ������ � ������ �����������;
		unsigned __int32 breakLoop           : 1;	// �BreakLoop�- ���, ������������ ������ ����� � ������������ ����;
		unsigned __int32 deNoise             : 1;	// �deNoise� - ���, ������������ ��������� ������ ������� �����;
		unsigned __int32 SFPerror            : 1; // ���, ������������ ������� ������ ����������� �����������SFP-������ (TXfault);
		unsigned __int32 SFP                 : 1;	// ��� ������� SFP-������;
		unsigned __int32                     : 2; // �� ������������
		unsigned __int32 bufferOverloadPass  : 1;	// ��� ������������ ���������� FIFO-������;
		unsigned __int32 bufferOverloadOut   : 1;	// ��� ������������ ��������� FIFO-������;
		unsigned __int32 bufferOverloadLocal : 1;	// ��� ������������ FIFO-������ ��������� �������� ������ (BAR1->RAM);
		unsigned __int32                     : 1; // �� ������������
		unsigned __int32 bufferOverloadIn    : 1; // ��� ������������ FIFO-������ ����������, ����������� �� ������������ ����;
		unsigned __int32                     : 3; // �� ������������
		unsigned __int32 breackLoopNumber    : 8;	//� ������ �BreakLoop�, �������� ����� ���� ������������ ����, ���������� �������� �������� �� ��������� � �����������;
		unsigned __int32                     : 8; // �� ������������
	 } status;
 struct                           // 0x18 �� ������������
		{
  //
		unsigned __int32 temperature         : 16;	// ������� ����������� � �������� �������. ���� [15..11] � ���� ����� (0 � �+�, 1 - �-�), ����[10..4] � ����� �����, ����[3..0] � ������� �����(��.��� ����� 0, 0625��);
		unsigned __int32                     : 16; // �� ������������
	 } mon;
 unsigned __int64 InputPhysicalAddress[PartCount]; // 0x20,0x28,...,0x58 ������ ���������� ������� ��������� (8 ��������� �� 16��);
      
 // 0x78 RO ������� ��������������� ����������, ������ ������ (� 0 �� 15-��) ����������, ����� ���������� ����� ������������� �� ������ ����.// 0x7C RO ������� ������� ����������, ������ ������ (� 0 �� 15-��) ����������, ����� ���������� ���� ������������� ���������
	union                           // 0x80,0x84,...,0xBC R/W ������� ������ 64-������ ������ ������,������ � �������, �� ������������ ����, ���������� ���������� irq0,1,...,15 ���������������.
		{
		unsigned __int32 data;
		struct InterruptValue
 		{
			unsigned __int32 ncell  :21;						//����� 64 ������ ������ � �������� (0 � 2�-1);
			unsigned __int32 nseg   : 3;						//����� 16�� �������� ������ � �������������� �������;
			unsigned __int32        : 7;
			unsigned __int32 enable : 1;						//��������� ����������;
	 	}interruptValue;
  } interrupt[InterruptCount];
 };


// Device object
typedef struct {
	ULONG  busNum;      // Bus number
	DWORD  deviceNum;   // Device number
	DWORD  functionNum; // Function number
	DWORD  base[6];     // Memory mapped address
	ULONG  cardNum;     // Card number, 0-based
	ULONG  Order;       // Order based on IST priority: 0-highest
	ULONG  priority;    // IST priority
	ULONG  msiEnable;   // Use MSI/MSIX if supported
	HANDLE ihr;			      // Interrupt handler
	ULONG  istReady;    // IST ready to handle next interrupt
} DRVDEV;


//  Add Function prototypes Here
// function prototype for periodic timer function

void RTFCNDCL TimerHandler( void * nContext);

void WordIn ();
//void RTFCNDCL InterruptHandler(PVOID context);

// Event server child thread prototype
//ULONG RTFCNDCL ChildThread_high( void * nContext );
int Device_Search
		(
		int CardNumber,					          // input: PCI card to find
		PCI_SLOT_NUMBER *pSlotNumber,	// output: pointer to slot number
		PPCI_COMMON_CONFIG  PciData		 // output: PCI card information
		);

int RMe_02_Configure(PPCI_COMMON_CONFIG PciData, DRVDEV *pCardInfo);
void RMe_02_CLOSE(void);

//#pragma pack(pop)   

#endif


