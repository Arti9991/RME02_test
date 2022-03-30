#ifndef COVER_VMIPCI5565_H
#define COVER_VMIPCI5565_H

#if defined(COVER_VMIPCI5565_DLL)
# define COVER_VMIPCI5565     __declspec(dllexport)
#elif defined(COVER_VMIPCI5565_APP)
# define COVER_VMIPCI5565     __declspec(dllimport)
# else
# define COVER_VMIPCI5565
#endif


#ifdef __cplusplus
extern "C"
{
#endif

//�������� �������
COVER_VMIPCI5565 void __stdcall Create_COVER_VMIPCI5565(ULONG   SizeEmulMem = SIZE_BAR3_64M_5565); //������������� ������ ������ ��� ��������
//�������� �������
COVER_VMIPCI5565 void __stdcall Close_COVER_VMIPCI5565();


//����� Pci ����� � ������� NumBrd(� 1),
//������������� ��������������� ������ BaseAddr0, BaseAddr1,
//� IrqL, PCIBusMumber, DeviceMumber ��� ��������� �����
//������� - ���������� ��������� ���� (� 1)
COVER_VMIPCI5565 int __stdcall ScanPciBoard_COVER_VMIPCI5565(int NumBrd, ULONG & BaseAddr0, ULONG & BaseAddr1, ULONG & BaseAddr2, ULONG & BaseAddr3,
                             UCHAR & IrqL, ULONG & PCIBusMumber,ULONG & DeviceMumber);

// ������������� �����.
// ��� ������������� ���� ������� ������ ����������� � ��������� ������.
// ������� true-�������, false-���������
// ���� ��� ����������, �� pRoutine=NULL
COVER_VMIPCI5565 bool __stdcall InitBoard_COVER_VMIPCI5565(ULONG BaseAddrPIO,ULONG BaseAddrMem, ULONG BaseAddr2, ULONG BaseAddr3,
                UCHAR IrqL, BOOLEAN (RTFCNDCL *pRoutine)(PVOID context), ULONG BusMumber);


//������ � ������ �� �������� Offset ������ �� buf �������� Size
//� ��������  START_RAM - SIZE_RAM
COVER_VMIPCI5565 void __stdcall WriteMemory_COVER(PUCHAR buf, ULONG Offset, ULONG Size);
//������ �� ������ �� �������� Offset ������ � buf �������� Size
//� ��������  START_RAM - SIZE_RAM
COVER_VMIPCI5565 void __stdcall ReadMemory_COVER(PUCHAR buf, ULONG Offset, ULONG Size);

//������ � ������ �� �������� Offset ���������� UCHAR
COVER_VMIPCI5565 void __stdcall WriteChar_COVER(UCHAR c, ULONG Offset);
//������ �� ������ �� �������� Offset ���������� UCHAR
COVER_VMIPCI5565 UCHAR __stdcall ReadChar_COVER(ULONG Offset);

//������ � ������ �� �������� Offset ���������� USHORT
COVER_VMIPCI5565 void __stdcall WriteShort_COVER(USHORT s, ULONG Offset);
//������ �� ������ �� �������� Offset ���������� USHORT
COVER_VMIPCI5565 USHORT __stdcall ReadShort_COVER(ULONG Offset);

//������ � ������ �� �������� Offset ���������� ULONG
COVER_VMIPCI5565 void __stdcall WriteLong_COVER(ULONG l, ULONG Offset);
//������ �� ������ �� �������� Offset ���������� ULONG
COVER_VMIPCI5565 ULONG __stdcall ReadLong_COVER(ULONG Offset);

// ��������� ���������� � ������ ���� RMN
// ���������:
// DestNId - NID ����, � ������� ���� ������������� ����������
// GlobalINT - ������������� ���������� �� ���� ����� �����
// Type_INT - ��� ����������, ������� ���� �������������
//              (GEN_INT1 ��� GEN_INT2 ��� GEN_INT3 ��� GEN_INT_RESET)
// INT_DATA - ������, ���������� � �����������
COVER_VMIPCI5565 void __stdcall GenerateInterrupt_COVER(UCHAR DestNId, BOOL GlobalINT, UCHAR Type_INT, USHORT INT_DATA);

// ���������� ��������� ���������� � ���� RMN
// ���������:
// Type_En_INT - ��� ����������, ������� ����� ������������� �� ����
//           (EN_INT1 �/��� EN_INT2 �/��� EN_INT3 �/��� EN_INT_RESET ��� DISABLE_INT)
COVER_VMIPCI5565 void __stdcall EnableInterrupt_COVER(UCHAR Type_En_INT);

// ###############  ��������� ��� ����������� ���������� #######################

// ����������� ������� ����������.
// ������ ����������� ������� ����������� ����������.
// ������������ �������� INTCSR Interrupt Control and Status ��� ��������� �
// INCOMING_MAIL_BOX_INT.
// ���� ���� ��� ����������, �� ��� ���������� �� �����, ����� - �� ������� ���������
COVER_VMIPCI5565 ULONG __stdcall IsMyInterrupt_COVER(void);

//��������� ���������� � ���������� ���� 1,2,3
// � SenderID ������������ NID ����, ������� ������������ ����������
// � IntFlag  ������������ ����� ����������:
//              ��� 6=1  -���������� ���������� ��� ���� ����� (��. GenerateInterrupt)
//              ���� 3-0 -��� ���������� - INT1/INT2/INT3 (��. GenerateInterrupt)
// � IntData  ������������ ������, ���������� � ����������� (��. GenerateInterrupt)
COVER_VMIPCI5565 void __stdcall GetInt1Info_COVER(UCHAR &SenderID, ULONG &IntData);
COVER_VMIPCI5565 void __stdcall GetInt2Info_COVER(UCHAR &SenderID, ULONG &IntData);
COVER_VMIPCI5565 void __stdcall GetInt3Info_COVER(UCHAR &SenderID, ULONG &IntData);

//��������������� ����������.
//������ ����������� � ����� ����������� ����������.
COVER_VMIPCI5565 void __stdcall UnMaskInterrupt_COVER(void);

// ��������� ������� �������� ����������� ������ �� ������ ����
// ������������ ����� �������� � 100�� �������� ���
// RING_IS_BREAK, ���� ������ ���� ��������� ��� ���� �� ������� ���������
COVER_VMIPCI5565 long __stdcall GetLatency_COVER_VMIPCI5565(void);

#ifdef __cplusplus
}
#endif
#endif