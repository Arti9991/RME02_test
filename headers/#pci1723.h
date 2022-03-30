//   #pci1723.h
//   ����� �. ��������

//==========================================================================
//	EXTERNAL FUNCTION
//==========================================================================
//=================================================================
// ���� ����� ����� �������� d[].NumDev, ���� ����� � �������� �����,
// ���� d[].NumDev=0, ���� ����� 1723. 
// ���� -
//		NumDevs - ���������� ���� (�� 1 �� 8) ���� 1723
//      cnf[].NumPC - ����� ��, 
//		cnf[].Sync - ������� �����(1 -���������� ����� � �������)
//		cnf[].NumDev - ����� ���������� ������� ���� �� ����������, ������� � 1
//		cnf[].NumDev = 0 �������� - ������� ����� ���������� ������� ����
// ����� - ��������� ������� d[], ����� ����������, �������� �� ��������� �����
// ���������� ���������� ������� ���������

// __SUCCESS:				 1 ������� ���������
// ERROR_DEVICE_NUMBER       0 ����� ��������� ����� ��������
// ERROR_MEMORY_LOCATION	-1  ������ �������� �������
// ERROR_ADAPTER_NOT_FOUND	-2
//#define ERROR_MEMORY_LOCATION -1
//#define	ERROR_ADAPTER_NOT_FOUND -2
//#define ERROR_DEVICE_NUMBER      -3
//#define ERROR_DATA_NOT_READY -4
//#define ERROR_FIFO_DEFINITION -5



long __stdcall	vbCreate_PCI1723(short NumDevs, DeviceRes_PCI1723 d[]);

long __stdcall vbClose_PCI1723();
//==========================================================================
// 0= OK
// -4	ERROR_ADAPTER_NOT_FOUND = ���������� �� �������, ��� ���������� ����� ����, ��� ������ ��������
// -5	ERROR_DATA_NOT_READY = ������ �� �������
//==========================================================================
long __stdcall vbWrite_PCI1723( ID_Parameter Param );
//==========================================================================
// 0= OK
// -4	ERROR_ADAPTER_NOT_FOUND = ���������� �� �������, ��� ���������� ����� ����, ��� ������ ��������
// -5	ERROR_DATA_NOT_READY = ������ �� �������
//==========================================================================
long __stdcall vbSend_PCI1723();

long __stdcall vbClose_PCI1723(void);
long  __stdcall vbCreateTimer_PCI1723 (ULONG msPeriod);
