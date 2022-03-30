
//-----------------------------------------------------------------------------
//			��������� ������ �������
//-----------------------------------------------------------------------------
#define SUCCESS 0							// �������

#define ERROR_DEVICE_NOT_FIND -1			// ������ �-��� Create_PCIxyzDAC (���������� �� �������)
#define ERROR_ENABLE_REG_IO_FAIL -2			// ������ �-��� Create_PCIxyzDAC (��� ������� � ��������� ����������)
#define ERROR_NUM_DEV -3					// ������ �-��� Create_PCIxyzDAC (���������� ���������� ��������� > 8)

#define ERROR_ANOTHER_TYPE_DEVICE -4		// ������ �-��� Put_PCIxyzDAC (������ ������ ����������)
#define ERROR_NUM_DEVICE -5					// ������ �-��� Put_PCIxyzDAC (��������� ���������� ��������� ������ ���� � 1, � �� � 0)
#define ERROR_NUM_CHANNEL -6				// ������ �-��� Put_PCIxyzDAC (��������� ������� � �� ������ ���� � 1, � �� � 0)
#define ERROR_BUS_NUM_0 -8					// ������ �-��� Put_PCIxyzDAC (����� � ������� �� ��������� ������ ���������� ����� 0)
#define ERROR_DISABLE_PORT_IO_FAIL -7		// ������ �-��� Close_PCIxyzDAC (������ � ��������� ���������� �� ������)

//-----------------------------------------------------------------------------
//			������� �������
//-----------------------------------------------------------------------------
short __stdcall Create_PCIxyzDAC (DeviceResources SN[], short NumDev);		// ������� ������ � ���������� (������� - ������������ ����� ���������� Dev = NumDev)
short __stdcall Put_PCIxyzDAC (ID_Parameter & InParam);							// �������� ���������
void __stdcall Close_PCIxyzDAC (void);					// ��������

unsigned long __stdcall ReadTimer_PCIxyzDAC (ULONG InNumDevice);						// ������ ��������
void		  __stdcall ClearTimer_PCIxyzDAC (ULONG InNumDevice);						// ��������� ��������

// ���������: ��������� ���������� ��������� � �� ���������� � 1 (1 - ������ ����������)
//			  ��������� ������� � ���������� � �� ���������� � 1 (1 - ������ �����)