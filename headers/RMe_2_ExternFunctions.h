#ifndef RMe_2_ExternFunction
#define RMe_2_ExternFunction

#define RING_IS_BREAK_RME_2 -1
//������ � ������ �� �������� Offset ������ �� buf �������� Size
//������������� ������ ������� ��������, ����� �� ���������� ����������� ������ ���� �����
void __stdcall WriteMemory_RMe_2(PUCHAR buf, ULONG Offset, ULONG Size);
//������ �� ������ �� �������� Offset ������ � buf �������� Size
//������������� ������ ������� ��������, ����� �� ���������� ����������� ������ ���� �����
void __stdcall ReadMemory_RMe_2(PUCHAR buf, ULONG Offset, ULONG Size);
//������ � ������ �� �������� Offset ���������� UCHAR
//������������� ������ ������� ��������, ����� �� ���������� ����������� ������ ���� �����
void __stdcall WriteChar_RMe_2(UCHAR data, ULONG Offset);
//������ �� ������ �� �������� Offset ���������� UCHAR
//������������� ������ ������� ��������, ����� �� ���������� ����������� ������ ���� �����
unsigned __int8 __stdcall ReadChar_RMe_2(ULONG Offset);
//������ � ������ �� �������� Offset ���������� USHORT
//������������� ������ ������� ��������, ����� �� ���������� ����������� ������ ���� �����
void __stdcall WriteShort_RMe_2(USHORT data, ULONG Offset);
//������ �� ������ �� �������� Offset ���������� USHORT
//������������� ������ ������� ��������, ����� �� ���������� ����������� ������ ���� �����
unsigned __int16  __stdcall ReadShort_RMe_2(ULONG Offset);
//������ � ������ �� �������� Offset ���������� ULONG
//������������� ������ ������� ��������, ����� �� ���������� ����������� ������ ���� �����
void __stdcall WriteLong_RMe_2(ULONG data, ULONG Offset);
//������ �� ������ �� �������� Offset ���������� ULONG
//������������� ������ ������� ��������, ����� �� ���������� ����������� ������ ���� �����
unsigned __int32 __stdcall ReadLong_RMe_2(ULONG Offset);
//����� ������ ������������������ ������ �� ���� �����, ��
//������������� ������ ������� ��������, ����� �� ���������� ����������� ������ ���� �����
__int32 __stdcall GetLatency_RMe_2();
//��������� ���� ������ � ����� �� � 0
__int32 __stdcall GetErrors_RMe_2();
//�������� ������ �� �����
void __stdcall DeNoise_RMe_2();

#endif