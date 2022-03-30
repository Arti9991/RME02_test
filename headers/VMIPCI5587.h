/*������� ������ ������������ ������ VMIPCI5587

��������
������ ��������� ����������
*/

//��� RTX_SDK ������ ��� 2009 (9.1) ����� ���������� � VMIPCI5565.h #define RTX_SDK_VER_LESS_91, ����� �� ����������
//#define	RTX_SDK_VER_LESS_91

//---------------------------------------------------------------------------
#ifndef VMIPCI5587H
#define VMIPCI5587H
//---------------------------------------------------------------------------
#include "windows.h"

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
#define VMIPCI5587_VID          0x114A
#define VMIPCI5587_DID          0x5587

//��� ����������, ������� ���� �������������
#define GEN_INT_RESET   0
#define GEN_INT1        1
#define GEN_INT2        2
#define GEN_INT3        3

//��� ����������, ������� ���� �������������
#define IS_INT1         1
#define IS_INT2         2
#define IS_INT3         4
#define IS_INT_RESET    8

//��� ����������, ������� ����� ������������� �� ����
#define EN_INT1         0x41//Global + INT1
#define EN_INT2         0x42//Global + INT2
#define EN_INT3         0x44//Global + INT3
#define EN_INT_RESET    0x48//Global + Reset
#define DISABLE_INT     0x0 //������ ����

//������ ���� ��������� ��� ���� �� ������� ���������
#define RING_IS_BREAK   -1

//��� �������� ������ ����
#define OWN_DATA        4

//��� ������������� ���������� �� ����� �����
#define INCOMING_MAIL_BOX_INT  0x00020000L

// PCI bus Operation Register Map
//   Mnemonic  Offset Descriptions                            Access Mode
#define OMB1    0x00 // I/O Outgoing Mailbox                  Lword (R/W)
#define OMB2    0x04 // I/O Outgoing Mailbox                  Lword (R/W)
#define OMB3    0x08 // I/O Outgoing Mailbox                  Lword (R/W)
#define OMB4    0x0C // I/O Outgoing Mailbox                  Lword (R/W)
#define IMB1    0x10 // Incoming Mailbox                      Lword (Read-Only)
#define MWAR    0x24 // Master Write Address Register         Lword (R/W)
#define MWTC    0x28 // Master Write Transfer Count Register  Lword (R/W)
#define MRAR    0x2C // Master Read Address Register          Lword (R/W)
#define MRTC    0x30 // Master Read Transfer Count Register   Lword (R/W)
#define INTCSR  0x38 // Interrupt Control and Status          Lword (R/W)
#define MCSR    0x3C // Bus Master Control and Status         Lword (R/W)

// VMIPCI-5587A Register Map
//  Mnemonic Offset    Descriptions                             Access Mode
#define BID   0x1     // Board ID                               Byte (R)
#define NID   0x4     // Node ID                                Byte (R)
#define IRS   0x8     // INT and Receiver Status                Byte/Word (R/W)
#define CSR1  0x9     // Control and Status 1                   Byte/Word (R/W)
#define CSR2  0xC     // Control and Status 2                   Byte/Word (R/W)
#define CSR3  0xD     // Control and Status 3                   Byte/Word (R/W)
#define CMDN  0x10    // Command Node                           Byte, Word, Lword (W)
#define CMD   0x11    // Command                                Byte, Word, Lword (W)
#define CMDD  0x12    // and $13 Command Data Registers 0       Byte, Word, Lword (W)
#define ICSR  0x14    // INT Control and Status                 Byte/Word (W)
#define SID1  0x18    // INT1 Sender ID                         Byte, Word, Lword (R/W)
#define IFR1  0x19    // INT1 Flag Register                     Byte, Word, Lword (R)
#define IDR1  0x1A    // and $1B INT1 Data Registers            Byte, Word, Lword (R)
#define SID2  0x1C    // INT2 Sender ID                         Byte, Word, Lword (R/W)
#define IFR2  0x1D    // INT2 Flag Register                     Byte, Word, Lword (R)
#define IDR2  0x1E    // and $1F INT2 Data Registers            Byte, Word, Lword (R)
#define SID3  0x20    // INT3 Sender ID                         Byte, Word, Lword (R/W)
#define IFR3  0x21    // INT3 Flag Register                     Byte, Word, Lword (R)
#define IDR3  0x22    // and $23 INT3 Data Registers            Byte, Word, Lword (R)
#define DADD  0x24    // DMA Start Address                      Lword (W)
#define EIS   0x28    // Extended Interrupt Status              Byte (R/W)
#define ECSR3 0x29    // Extended Control and Status 3          Byte/Word (R/W)
#define MICS  0x2A    // Manual Interrupt Control and Status    Byte (R/W)
#define BPSR  0x2C    // Block Prot Set/Reset Register          Byte (R/W)
#define MACR  0x2D    // Memory Access Control Register         Byte (W)
#define BSR   0x30    // Block Select Register                  Byte/Word (R/W)
#define NSR   0x31    // Node Select Register                   Byte/Word (R/W)
#define PNF   0x34    // Protected Node Fault                   Byte/Word (R/W)
#define INLD  0x38    // Initiator Node List Data               Byte (R/W)
#define INLA  0x39    // Initiator Node List Address            Byte (R/W)
#define USNID 0x3C    // Upstream Node ID                       Byte (R/W)
#define START_RAM 0x40// Start of RAM                           Byte, Word, Lword (R/W)

//����� ������ ��� �� ����� VMIPCI-5587A-011 (1Mb)
#define SIZE_RAM                0xFFFFF

//������ ������� ������ �����-������
#define SIZE_PIO                0x40

//������ ������������� ISR
#define IRQL_NOT_USE            0xFF

//��� ������� ������ ��� ��������� �����
#define	MSGSTR_SHM	__TEXT("VMIPCI5587_Emulator.Shm")

#if defined(VMIPCI5587_DLL)
# define VMIPCI5587CLASS __declspec(dllexport)
#elif defined(VMIPCI5587_APP)
# define VMIPCI5587CLASS __declspec(dllimport)
# else
# define VMIPCI5587CLASS
#endif

class VMIPCI5587CLASS VmiPci5587 {
public:
        VmiPci5587();
       ~VmiPci5587();

//����� Pci ����� � ������� NumBrd(� 1),
//������������� ��������������� ������ BaseAddr0, BaseAddr1,
//� IrqL, PCIBusMumber, DeviceMumber ��� ��������� �����
//������� - ���������� ��������� ���� (� 1)
int VmiPci5587::ScanPciBoard(int NumBrd, ULONG & BaseAddr0, ULONG & BaseAddr1,
                             UCHAR & IrqL, ULONG & PCIBusMumber,ULONG & DeviceMumber);

//������������� �����.
//��� ������������� ���� ������� ������ ����������� � ��������� ������.
// ������� true-�������, false-���������
bool InitBoard(ULONG BaseAddrPIO,ULONG BaseAddrMem,
                UCHAR IrqL, BOOLEAN (RTFCNDCL *pRoutine)(PVOID context), ULONG BusMumber);

//������ � �������� ������ �����-������ �� �������� Offset �������� Data
void WritePortUlong(ULONG Data, ULONG Offset);
//������ �� �������� ������ �����-������ �� �������� Offset �������� ULONG
ULONG ReadPortUlong(ULONG Offset);

//������ � ������ �� �������� Offset ������ �� buf �������� Size
//� ��������  START_RAM - SIZE_RAM
void WriteMemory(PUCHAR buf, ULONG Offset, ULONG Size);
//������ �� ������ �� �������� Offset ������ � buf �������� Size
//� ��������  START_RAM - SIZE_RAM
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
//              (GEN_INT1 ��� GEN_INT2 ��� GEN_INT3 ��� GEN_INT_RESET)
// INT_DATA - ������, ���������� � �����������
void GenerateInterrupt(UCHAR DestNId, BOOL GlobalINT, UCHAR Type_INT, USHORT INT_DATA);

// ���������� ��������� ���������� � ���� RMN
// ���������:
// Type_En_INT - ��� ����������, ������� ����� ������������� �� ����
//           (EN_INT1 �/��� EN_INT2 �/��� EN_INT3 �/��� EN_INT_RESET ��� DISABLE_INT)
void EnableInterrupt(UCHAR Type_En_INT);

// ###############  ��������� ��� ����������� ���������� #######################

// ����������� ������� ����������.
// ������ ����������� ������� ����������� ����������.
// ������������ �������� INTCSR Interrupt Control and Status ��� ��������� �
// INCOMING_MAIL_BOX_INT.
// ���� ���� ��� ����������, �� ��� ���������� �� �����, ����� - �� ������� ���������
ULONG IsMyInterrupt(void);

// ������������ ����������.
// ������ ����������� ������� ����������� ���������� ����� IsMyInterrupt.
// ������������ ��� ����������, ������� ���� �������������
// IS_INT1 / IS_INT2 / INT3 / IS_INT_RESET
UCHAR MaskInterrupt(void);

//��������� ���������� � ���������� ���� 1,2,3
// � SenderID ������������ NID ����, ������� ������������ ����������
// � IntFlag  ������������ ����� ����������:
//              ��� 6=1  -���������� ���������� ��� ���� ����� (��. GenerateInterrupt)
//              ���� 3-0 -��� ���������� - INT1/INT2/INT3 (��. GenerateInterrupt)
// � IntData  ������������ ������, ���������� � ����������� (��. GenerateInterrupt)
void GetInt1Info(UCHAR &SenderID, UCHAR &IntFlag, USHORT &IntData);
void GetInt2Info(UCHAR &SenderID, UCHAR &IntFlag, USHORT &IntData);
void GetInt3Info(UCHAR &SenderID, UCHAR &IntFlag, USHORT &IntData);

//��������������� ����������.
//������ ����������� � ����� ����������� ����������.
void UnMaskInterrupt(void);

//��������� ID ����, ��������������� ��������������� � ����� ������ ����
//��������!
// ����� �������. ���� ��������� ���������� ���� �� ��� ������������� ����� �� ����
UCHAR GetUpstreamNID(void);

// ��������� ������� �������� ����������� ������ �� ������ ����
// ������������ ����� �������� � 100�� �������� ���
// RING_IS_BREAK, ���� ������ ���� ��������� ��� ���� �� ������� ���������
long GetLatency(void);

protected:
//������������� ������ �����-������
// ������� true-�������, false-���������
bool InitPIO(ULONG BaseAddr);

//������������� ������� � ������
// ������� true-�������, false-���������
bool InitMemory(ULONG BaseAddr);

//������������� ISR
// ������� true-�������, false-���������
bool InitISR(UCHAR IrqL, BOOLEAN (RTFCNDCL *pRoutine)(PVOID context), ULONG BusMumber);

ULONG BaseAddrPIO;  //������� ����� ������ �����-������
PUCHAR pvMemAddr;   //����������� ������� ����� ��� �����
HANDLE  hInterrupt; // interrupt vector handle
int NumBoard;       //���������� ��������� ����
UCHAR TypeEnInt;    //��� ����������, ������� ����� ������������� �� ����
HANDLE	hShm;
};
//---------------------------------------------------------------------------
#endif
