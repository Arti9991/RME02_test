/*
������� ������ ������������ ������ VMIPCI5565

��������
������ ��������� ����������
2004�
*/

//---------------------------------------------------------------------------
#ifndef VMIPCI5565H
#define VMIPCI5565H
//---------------------------------------------------------------------------

//��� RTX_SDK ������ ��� 2009 (9.1) ����� ���������� � VMIPCI5565.h #define RTX_SDK_VER_LESS_91, ����� �� ����������
//#define	RTX_SDK_VER_LESS_91

#include "windows.h"

// ���� ������ VMIPCI5565.xxx
#define	Err_5565_OK             0x0//������ ���
#define	Err_5565_NO_EMUL_RAM    0x1//�� ������� �������� ������ ��� �������� RAM
#define	Err_5565_LESS_EMUL_RAM  0x2//��� �������� RAM �������� ������ ������ ���
                                   //���������. ������� ���������� ������ �����
                                   //���������� ������� GetRealSizeMem()
#define	Err_5565_NO_MAP_RAM     0x4//�� ������� ���������� RAM �� ������������
#define	Err_5565_LESS_MAP_RAM   0x8//���������� RAM �� ������������ ������ ���
                                   //���������. ������� ������������ ������ �����
                                   //���������� ������� GetRealSizeMem()

#define	Err_5565_NO_MAP_RFMCSR  0x10    //�� ������� ���������� RFM Control and
                                        //Status Registers �� ������������
#define	Err_5565_INIT_IRQ       0x20    //������ ������������� ����������

#define	Err_5565_NO_MAP_BAR0     0x40//�� ������� ���������� BAR0 �� ������������
#define	Err_5565_NO_MAP_BAR1     0x80//�� ������� ���������� BAR1 �� ������������

// Define RTAPI function calling convention unless an override is in effect.
#ifndef RTAPI
#       if (defined(_MSC_VER)&&(_MSC_VER >= 800)) || defined(_STDCALL_SUPPORTED)
#              define RTAPI __stdcall
#       else
#              define RTAPI
#       endif
#endif
// Define the declaration for application provided functions.
#define RTFCNDCL RTAPI

//���� ����� � �������������
#define VMIPCI5565_VID          0x114A
#define VMIPCI5565_DID          0x5565

#define INTCSR_5565  0x68L // Interrupt Control and Status          Lword (R/W)

//��� ������������� ���������� �� ����� �����
//Local Input Interrupt Active.
//When set to a one (1), indicates the Local input interrupt is active.
#define LOCAL_INP_INT_ACTIVE_5565  0x00008000L

//PCI Interrupt Enable. Writing a one (1) enables PCI interrupts.
#define PCI_INT_ENABLE_5565  0x00000100L

//Local Interrupt Input Enable.
//Writing a one (1) enables a Local interrupt input to assert a PCI interrupt.
//Used in conjunction with the PCI Interrupt Enable bit (INTCSR[8]).
//Clearing the Local bus cause of the interrupt also clears the interrupt.
#define LOCAL_INT_INP_ENABLE_5565  0x00000800L

//Global Interrupt Enable bit
#define GLOB_INT_EN_5565 0x4000L

//��� ����������, ������� ����� ������������� �� ����
#define EN_INT1_5565         0x1L | GLOB_INT_EN_5565      // INT1
#define EN_INT2_5565         0x2L | GLOB_INT_EN_5565      // INT2
#define EN_INT3_5565         0x4L | GLOB_INT_EN_5565      // INT3
#define EN_INT_RESET_5565    0x8L | GLOB_INT_EN_5565      // Reset
#define EN_INT_INIT_5565     0x80L| GLOB_INT_EN_5565      //Init
#define DISABLE_INT_5565     0x0L //������ ����

//��� ����������, ������� ���� �������������
#define IS_INT1_5565         0x1
#define IS_INT2_5565         0x2
#define IS_INT3_5565         0x4
#define IS_INT_RESET_5565    0x8
#define IS_INT_INIT_5565     0x80

//��� ����������, ������� ���� �������������
#define GEN_INT_RESET_5565   0 //Reset Node Request (sets LISR Bit 03 only, PCI master must perform actual reset)
#define GEN_INT1_5565        1 //Network Interrupt 1 (stored in a 127 deep FIFO at the receiving node)
#define GEN_INT2_5565        2 //Network Interrupt 2 (stored in a 127 deep FIFO at the receiving node)
#define GEN_INT3_5565        3 //Network Interrupt 3 (stored in a 127 deep FIFO at the receiving node)
#define GEN_OWN_DATA_5565    4 //Reserved (Setting to this type will only set the OWN DATA bit in the CSR1)
#define GEN_INT_INIT_5565    7 //Network Initialized Interrupt (stored in a 127 deep FIFO at the receiving node)
#define GEN_INT_GLOBAL_5565  8 //Global enable. Send to all nodes regardless of Network Target Node Reg (NTN)

//������ ���� ��������� ��� ���� �� ������� ���������
#define RING_IS_BREAK_5565   -1

//��� �������� OWN DATA
#define OWN_DATA_LED_5565    1

//��� �������� STATUS
#define STATUS_LED_5565      0x80000000

//��� �������� RX Signal Detect
#define RX_SIG_DET_LED_5565  0x4

//The RFM Control and Status registers for the VMIPCI-5565
#define BRV_5565     0x00 //Board Revision Read Only Current board revision/model
#define BID_5565     0x01 //Board ID Register Read Only BID is $65 for VMIPCI-5565
					 // $3�2 -- Reserved --
#define NID_5565     0x04 //Node ID Register Read Only Set by 8 board jumpers
                     // $7�5 -- Reserved --
#define LCSR1_5565   0x08 //$B...8  Local Control & Status Reg. 1 Read/Write Some bits reserved. Some bits read only.
                     //$F...C -- Reserved --
#define LISR_5565    0x10 //$13...10  Local Interrupt Status Reg. Read/Write Some bits reserved. Some bits read only.
#define LIER_5565    0x14 //$17...14  Local Interrupt Enable R. Read/Write
#define NTD_5565     0x18 //$1B..18  Network Target Data Read/Write 32 Data bits for network target
#define NTN_5565     0x1C //Network Target Node Read/Write Target node ID for network Int.
#define NIC_5565     0x1D //Network Interrupt Command Read/Write Select Int type and initiate interrupt
                     //$1F�1E -- Reserved --
#define ISD1_5565    0x20 //$23...20  Int. 1 Sender Data Read/Write 127 loc. By 32 bit FIFO for network Int. 1
#define SID1_5565    0x24 //Int. 1 Sender ID Read/Write 127 loc. Deep FIFO/ write clears pointers
					 //$27�25 -- Reserved --
#define ISD2_5565    0x28 //$2B...28  Int. 2 Sender Data Read/Write 127 loc. By 32 bit FIFO for network Int. 2
#define SID2_5565    0x2C //Int. 2 Sender ID Read/Write 127 loc. Deep FIFO/ write clears pointers
                     // $2F�2D -- Reserved --
#define ISD3_5565    0x30 //$33...30  Int. 3 Sender Data Read/Write 127 loc. By 32 bit FIFO for network Int. 3
#define SID3_5565    0x34 //Int. 3 Sender ID Read/Write 127 loc. Deep FIFO/ write clears pointers
                     // $37...35 -- Reserved
#define INITD_5565   0x38 //$3B...38  Initialized Node Data Read/Write 127 loc. By 32 bit FIFO for opt. Data
#define INITN_5565   0x3C //Initialized Node ID Read/Write 127 loc. Deep FIFO/ write clears pointers
                     //$3F.3D -- Reserved --

//������ ������� BAR0
#define SIZE_BAR0_5565                256

//������ ������� BAR1
#define SIZE_BAR1_5565                256

//������ ������� BAR2 ( RFM control & status register)
#define SIZE_BAR2_5565                64

//����� ������ ��� �� ����� VMIPCI-5565-010 (64Mb)
#define SIZE_BAR3_64M_5565             0x3FFFFFF + 1

//����� ������ ��� �� ����� VMIPCI-5565-110 (128Mb)
#define SIZE_BAR3_128M_5565            0x7FFFFFF + 1

//������ ������������� ISR
#define IRQL_NOT_USE_5565            0xFF

//��� ������� ������ ��� ��������� �����
#define	MSGSTR_SHM_5565	__TEXT("VMIPCI5565_Emulator.Shm")

#if defined(VMIPCI5565_DLL)
# define VMIPCI5565CLASS __declspec(dllexport)
#elif defined(VMIPCI5565_APP)
# define VMIPCI5565CLASS __declspec(dllimport)
# else
# define VMIPCI5565CLASS
#endif

class VMIPCI5565CLASS VmiPci5565 {
public:


#if defined (UNICODE)
	VmiPci5565(ULONG   SizeEmulMem = SIZE_BAR3_64M_5565, wchar_t *Name=MSGSTR_SHM_5565); //������������� ������ ������ ��� �������� - UNICODE
#else
	VmiPci5565(ULONG   SizeEmulMem = SIZE_BAR3_64M_5565, char *Name=MSGSTR_SHM_5565); //������������� ������ ������ ��� �������� - ANSI
#endif

	   ~VmiPci5565();

//����� Pci ����� � ������� NumBrd(� 1),
//������������� ��������������� ������ BaseAddr0, BaseAddr1,BaseAddr2,BaseAddr3,
//� IrqL, PCIBusMumber, DeviceMumber ��� ��������� �����
//������� - ���������� ��������� ���� (� 1)
int ScanPciBoard(int NumBrd, ULONG & BaseAddr0, ULONG & BaseAddr1, ULONG & BaseAddr2, ULONG & BaseAddr3,
                             UCHAR & IrqL, ULONG & PCIBusMumber,ULONG & DeviceMumber);

//������������� �����.
//��� ������������� ���� ������� ������ ����������� � ��������� ������.
// ������� true-�������, false-���������
bool InitBoard(ULONG BaseAddr0, ULONG BaseAddr1, ULONG BaseAddr2, ULONG BaseAddr3,
                UCHAR IrqL, BOOLEAN (RTFCNDCL *pRoutine)(PVOID context), ULONG BusMumber);

//������ � ������ �� �������� Offset ������ �� buf �������� Size
void WriteMemory(PUCHAR buf, ULONG Offset, ULONG Size);
//������ �� ������ �� �������� Offset ������ � buf �������� Size
void ReadMemory(PUCHAR buf, ULONG Offset, ULONG Size);

//������ � ������ �� �������� Offset ���������� UCHAR
void WriteChar(UCHAR c, ULONG Offset);
//������ �� ������ �� �������� Offset ���������� UCHAR
UCHAR ReadChar(ULONG Offset);

//������ � ������ �� �������� Offset ���������� USHORT
void WriteShort(USHORT s, ULONG Offset);
//������ �� ������ �� �������� Offset ���������� USHORT
USHORT ReadShort(ULONG Offset);

//������ � ������ �� �������� Offset ���������� ULONG
void WriteLong(ULONG l, ULONG Offset);
//������ �� ������ �� �������� Offset ���������� ULONG
ULONG ReadLong(ULONG Offset);

// ��������� ���������� � ������ ���� RMN
// ���������:
// DestNId - NID ����, � ������� ���� ������������� ����������
// GlobalINT - ������������� ���������� �� ���� ����� �����
// Type_INT - ��� ����������, ������� ���� �������������
//              (GEN_INT1_5565 ��� GEN_INT2_5565 ��� GEN_INT3_5565 ��� GEN_INT_RESET_5565 ��� GEN_INT_INIT_5565)
// INT_DATA - ������, ���������� � �����������
void GenerateInterrupt(UCHAR DestNId, BOOL GlobalINT,UCHAR Type_INT, ULONG INT_DATA);

// ���������� ��������� ���������� � ���� RMN
// ���������:
// Type_En_INT - ��� ����������, ������� ����� ������������� �� ����
//           (EN_INT1_5565 �/��� EN_INT2_5565 �/��� EN_INT3_5565 �/��� EN_INT_RESET_5565 �/��� EN_INT_INIT_5565 ��� DISABLE_INT_5565)
void EnableInterrupt(ULONG Type_En_INT);

// ###############  ��������� ��� ����������� ���������� #######################

// ����������� ������� ����������.
// ������ ����������� ������� ����������� ����������.
// ������������ �������� true ���� ��� ���������� �� �����, ����� - �� ������� ���������
bool IsMyInterrupt(void);

//��������� ���������� � ���������� ���� 1,2,3,Init
// � SenderID ������������ NID ����, ������� ������������ ����������
// � IntData  ������������ ������, ���������� � ����������� (��. GenerateInterrupt)
void GetInt1Info(UCHAR &SenderID,  ULONG &IntData)
		{IntData  = ReadRFMCSRLong(ISD1_5565);SenderID = ReadRFMCSRChar(SID1_5565);}
void GetInt2Info(UCHAR &SenderID,  ULONG &IntData)
        {IntData  = ReadRFMCSRLong(ISD2_5565);SenderID = ReadRFMCSRChar(SID2_5565);}
void GetInt3Info(UCHAR &SenderID,  ULONG &IntData)
        {IntData  = ReadRFMCSRLong(ISD3_5565);SenderID = ReadRFMCSRChar(SID3_5565);}
void GetIntInitInfo(UCHAR &SenderID,  ULONG &IntData)
        {IntData  = ReadRFMCSRLong(INITD_5565);SenderID = ReadRFMCSRChar(INITN_5565);}

//��������������� ����������.
//������ ����������� � ����� ����������� ����������.
void UnMaskInterrupt(void) {WriteRFMCSRLong(GLOB_INT_EN_5565,LISR_5565);} //������� � LISR Global Int Enable ������ ��� ������ INT Reset

// ############### ����� �������� ��� ����������� ���������� #######################

// ��������� ������� �������� ����������� ������ �� ������ ����
// ������������ ����� �������� � 100�� �������� ���
// RING_IS_BREAK_5565, ���� ������ ���� ��������� ��� ���� �� ������� ���������
long GetLatency(void);

// ��������� ��������� ������� ������ �� ����� ��� ���������� �������������
ULONG GetRealSizeMem(void) {return dwRealSizeMem;}

//��������� ���� ������
ULONG GetLastError5565();

//������� ���������� ����� ������ ��������.
int GetVersion();

//��������� Node ID
UCHAR GetNID(void) {return ReadRFMCSRChar(NID_5565);}

//�������� �������� STATUS: true - �����, false - �� �����
bool GetStatusLed(void);

//�������� �������� RX Signal Detect: true - �����, false - �� �����
bool GetRxSigDetLed(void);

//�������� �������� Own Data: true - �����, false - �� �����
bool GetOwnDataLed(void);

//��������� �������� STATUS: true - �����, false - �� �����
void SetStatusLed(bool Status);

//��������� �������� Own Data: true - �����, false - �� �����
void SetOwnDataLed(bool Status);

//������ � RFM Control and Status Registers
//������ � RFMCSR �� �������� Offset ���������� UCHAR
void WriteRFMCSRChar(UCHAR c, ULONG Offset);
//������ �� RFMCSR �� �������� Offset ���������� UCHAR
UCHAR ReadRFMCSRChar(ULONG Offset);
//������ � RFMCSR �� �������� Offset ���������� ULONG
void WriteRFMCSRLong(ULONG l, ULONG Offset);
//������ �� RFMCSR �� �������� Offset ���������� ULONG
ULONG ReadRFMCSRLong(ULONG Offset);

//������ � BA0 Registers
//������ � BA0 �� �������� Offset ���������� ULONG
void WriteBA0Long(ULONG l, ULONG Offset);
//������ �� BA0 �� �������� Offset ���������� ULONG
ULONG ReadBA0Long(ULONG Offset);

//������ � BA1 Registers
//������ � BA1 �� �������� Offset ���������� ULONG
void WriteBA1Long(ULONG l, ULONG Offset);
//������ �� BA1 �� �������� Offset ���������� ULONG
ULONG ReadBA1Long(ULONG Offset);

TCHAR SharedMemName[64];
int     NumBoard;       //���������� ��������� ����
protected:

//������������� ������� � Local Configuration, Runtime and DMA Registers (BAR0)
// ������� true-�������, false-���������
bool InitBAR0(ULONG BaseAddr);

//������������� ������� � Local Configuration, Runtime and DMA Registers (BAR1)
// ������� true-�������, false-���������
bool InitBAR1(ULONG BaseAddr);

//������������� ������� � ������ RFM Control and Status Registers (BAR2)
// ������� true-�������, false-���������
bool InitRFMCSRAddr(ULONG BaseAddr);

//������������� ������� � ������ RAM  (BAR3)
// ������� true-�������, false-���������
bool InitRAMAddr(ULONG BaseAddr);

//������������� ISR
// ������� true-�������, false-���������
bool InitISR(UCHAR IrqL, BOOLEAN (RTFCNDCL *pRoutine)(PVOID context), ULONG BusMumber);

PUCHAR  pvBA0;          //����������� ������� ����� Local Configuration, Runtime and DMA Registers (�� BAR0)
ULONG   ulBA1;          //������� ����� ������ �����-������  Local Configuration, Runtime and DMA Registers (�� BAR1)
PUCHAR  pvRFMCSRAddr;   //����������� ������� ����� RFM Control and Status Registers (�� BAR2)
PUCHAR  pvRAMAddr;      //����������� ������� ����� ��� ����� (�� BAR3)

HANDLE  hInterrupt;     //interrupt vector handle
ULONG   TypeEnInt;      //��� ����������, ������� ����� ������������� �� ����
HANDLE	hShm;           //���������� SharedMemory
ULONG   dwRealSizeMem;  //�������� ������ ������ �� ����� ��� ���������� �������������
ULONG   LastError;      //��� ������
};
//---------------------------------------------------------------------------
#endif
