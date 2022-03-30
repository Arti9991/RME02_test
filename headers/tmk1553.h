//---------------------------------------------------------------------------
#ifndef TMK1553H
#define TMK1553H

#if defined(TMK1553_DLL)
# define TMK1553CLASS     __declspec(dllexport)
#elif defined(TMK1553_APP)
# define TMK1553CLASS     __declspec(dllimport)
# else
# define TMK1553CLASS
#endif

// ���� ������ tmkconfig � TMKXLoadByIndex
#define		TX_OK                   0x0
#define		TX_BAD_PARAMS           0x1
#define		TX_NOT_FOUND_OR_ALREADY_LOADED 0x2
#define		TX_LOAD_ERROR           0x4
#define		TX_INIT_ERROR           0x8
#define		TX_TEST_ERROR           0x10
#define		TX_INIT_PORT_ERROR      0x20
#define		TX_INIT_IRQL_ERROR      0x40
#define		TX_PCI_BRD_NOT_FND      0x80 //����� �� �������

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

class TMK1553CLASS TTMK1553 {
public:
        TTMK1553();
       ~TTMK1553();

/**************************************************************************
                        ������� ������ ����������
**************************************************************************/
int tmkconfig(int tmkType, USHORT tmkPorts, UCHAR tmkIrq,
                BOOLEAN (RTFCNDCL *pRoutine)(PVOID context));
/*     ���������:
          tmkType - ��� ������������� �����:
                TX1, RT1, TX4, TX5, TX6, TX5MRT, TX6MRT, TE6_PCI, TE6_PCI_MRT, TE1_PCI

          tmkPorts - ������� ����� ������ / ����� ����� PCI;
          tmkIrq - ����� ����� ������� ���������� ( 0 - 15 )
                   ��� IRQL_NOT_USE, ���� �� ������������;
                   IRQL_PCI_AUTO - ��� ����� PCI
          pRoutine - ����� ��������� ��������� ���������� (��� NULL)

     ������������ ��������:
                TX_OK
                TX_BAD_PARAMS
                TX_NOT_FOUND_OR_ALREADY_LOADED
                TX_LOAD_ERROR
                TX_INIT_ERROR
                TX_TEST_ERROR
                TX_INIT_PORT_ERROR
                TX_INIT_IRQL_ERROR
                TX_PCI_BRD_NOT_FND
     ����������� ��������:
          ������� ����������� ������� �� ���������� �������� �������
          ������ � ������ ����� ���������� ��� ����� � ��������� �����,
          ���������� ������ ��� � SIZE_OZU
---------------------------------------------------------------------------*/

void tmkdone();
/*     ���������:
          ���.
     ������������ ��������:
          ���.
     ����������� ��������:
          ������� ������ ���������� � ����� ������ � ������� ���. ��������
          ���������� ������� - �������������� ������� ���������� ����
          � �������� ������.
---------------------------------------------------------------------------*/

int tmkGetVersion();
/*     ���������:
          ���.
     ������������ ��������:
          ����� ������ ��������.
     ����������� ��������:
          ������� ���������� ����� ������ ��������.
---------------------------------------------------------------------------*/
//������� ��� ������ � ���������� �����
//------------------- ������ � ������� � RTX -----------------------------------
 BOOL EnablePortsIO(USHORT);//�������� ������
 BOOL DisablePortsIO(void);//�������� ������
 void  WritePort(USHORT Port,USHORT Value);//������ � ����
 USHORT  ReadPort(USHORT Port);//������ �� �����
//--------------------- ������� ������ � ���������� ����� ----------------------
 void StopTask(void);//������� �������
 void ResetDevice(void);//����������� ����� ����������
 USHORT GetRegBaseAddrCurrTask(void);//������ ���. �������� ���. �����. �������
 void SetRegMoge(USHORT);//������ � ������� ������ ������
 void SetRegInitialAddr(USHORT);//������ � �������  ���������� ������ ���� (RGA)
 USHORT GetRegStatusWord(void);//������ ��������  ����� ���������
 void SetRegCommandWord(USHORT);//������ � ������� ������������ �����
 void SetRegData(USHORT);//������ � ������������ ���
 USHORT GetRegData(void);//������ ������������� ���
 void SetRegDataBuf(PUSHORT pBuffer, USHORT NWord);//������ � ��� NWord ���� �� ������ pBuffer
 void GetRegDataBuf(PUSHORT pBuffer, USHORT NWord);//������ �� ��� NWord ���� � ����� pBuffer
 //�������� ����
//����: TX1-0, RT1-1, TX4-2, TX5-3, TX6-4,TX5_MRT -5,TX6_MRT -6,TE6_PCI -7,
//      TE6_PCI_MRT -8, TE1_PCI-9
//�����: TX_OK,TX_NOT_FOUND,TX_LOAD_ERROR,TX_INIT_ERROR,TX_TEST_ERROR
int TMKXLoadByIndex(int nLoadType);
int tmkxload(PUCHAR Buffer, ULONG  Count);
int tmkxiload(unsigned portplx, int reset, unsigned char *fpgabuf, int len);
USHORT TestRAM(void);
void ClearRAM(void);
void Srand(unsigned short);
unsigned short Rand();

//����� Pci ����� � ������� NumBoard(� 1),
//������������� portplx, port, IrqL, PCIBusMumber ��� ��������� �����
//������� - ���������� ��������� ���� (� 1)
int ScanPciBoard(int NumBoard, unsigned & portplx, unsigned & port, unsigned char &IrqL, unsigned & PCIBusMumber);

bool IsMyInterrupt(void);

protected:
USHORT BasePortAddr;
unsigned PCIportplx; //������� ����� ������ ����������
USHORT SIZE_OZU;
unsigned short _wRand;
int _fRand;

/**************************************************************************
                        ����������� ��������
**************************************************************************/

//------------ �������� ������� ��������� ����� --------------------------------
#define TMK_StopPort          0x4 //������� ������� ��,�� ���.
#define TMK_ResetPort         0x6 //����������� ����� ���������� ��,��, �� ���
#define TMK_BaseAddrPort      0x8 //���. �������� ���. �������� ������� ��,�� ��
#define TMK_ModePort          0x8 //���. ������ ������ ��,��, �� ���.
#define TMK_AddrPort          0xA //���. ���������� ���. ���� (RGA) ��,��,�� ���
#define TMK_StatusPort        0xC //���. ����� ��������� ��,��, �� ��.
#define TMK_ControlPort       0xC //���. ������������ ����� ��,��, �� ���.
#define TMK_DataPort          0xE //������������ ��� ��,��,��

#define		BUSY             0x0080
#define		BUSY_DEVICE      0x7E7F
#define		EMPTY_DEVICE     0x7EFF
#define		ERROR_DEVICE     0x7FFF
#define		LOADED_DEVICE    0x0000

//���� ����:
#define TX1            0
#define RT1            1
#define TX4            2
#define TX5            3
#define TX6            4
#define TX5MRT         5
#define TX6MRT         6
#define TE6_PCI        7
#define TE6_PCI_MRT    8
#define TE1_PCI        9

//���������� ������� ������ ��� ISA ����
#define PIO150      0x150
#define PIO160      0x160
#define PIO190      0x190
#define PIO1A0      0x1A0
#define PIO250      0x250
#define PIO260      0x260
#define PIO290      0x290
#define PIO2A0      0x2A0

//���������� ������ ���� ��� PCI
#define BOARD1      0x1
#define BOARD2      0x2
#define BOARD3      0x3
#define BOARD4      0x4
#define BOARD5      0x5
#define BOARD6      0x6
#define BOARD7      0x7
#define BOARD8      0x8

//���������� IRQL
#define IRQL3        3
#define IRQL4        4
#define IRQL5        5
#define IRQL6        6
#define IRQL7        7
#define IRQL9        9
#define IRQL10       10
#define IRQL11       11
#define IRQL12       12
#define IRQL14       14
#define IRQL15       15
#define IRQL_NOT_USE       0xFF
#define IRQL_PCI_AUTO      16

#define BC_MODE         0x00  //����� ��
#define RT_MODE         0x80  //����� ��
#define MT_MODE         0x100 //����� ��
#define MRT_MODE        0x200 //����� ���
#define UNDEFINED_MODE  0xFFFF//����� ����� �� ��� ���������

#define MRT_NOT_USE     0x1F //������ ������������� ��

#define RT_HBIT_MODE 0x0001 //����� ������������� ����������� ����
#define RT_FLAG_MODE 0x0002 //����� ������ � �������
#define RT_BRCST_MODE 0x100 //����� ������ ��������� � ��������� �������
#define RT_DATA_BL 0x2000   //RT_DATA_BL - ����� ���������� ���������� �� ������/�������� ������
#define RT_GENER1_BL 0x0004 //����� ���������� ���������� �� ��������� � �������� ���;
#define RT_GENER2_BL 0x4000 //����� ���������� ���������� �� ��������� � ��������� ���;
#define BC_GENER1_BL 0x0004 //����� ���������� ���������� �� ��������� � �������� ���;
#define BC_GENER2_BL 0x4000 //����� ���������� ���������� �� ��������� � ��������� ���;
#define MT_GENER1_BL 0x0004 //MT_GENER1_BL - ����� ���������� ���������� �� ��������� � �������� ���
#define MT_GENER2_BL 0x4000 //MT_GENER2_BL - ����� ���������� ���������� �� ��������� � ��������� ���
#define TMK_IRQ_OFF 0x8000  //����� ���������� ����� ������� ���������� �����.

#define DATA_BC_RT      0x00 //�������� ������ ��-��;
#define DATA_BC_RT_BRCST 0x08//�������� ������ ��-�� � ��������� ������;
#define DATA_RT_BC      0x01 //�������� ������ ��-��;
#define DATA_RT_RT      0x02 //�������� ������ ��-��;
#define DATA_RT_RT_BRCST 0x0A//�������� ������ ��-�� � ��������� ������;
#define CTRL_C_A        0x03 //������� ���������� ������� ��-��;
#define CTRL_C_BRCST    0x0B //������� ���������� ������� �� � ��������� ������;
#define CTRL_CD_A       0x04 //������� ���������� ������� ��+��-��;
#define CTRL_CD_BRCST   0x0C //������� ���������� ������� ��+�� � ��������� ������;
#define CTRL_C_AD       0x05 //������� ���������� ������� ��-��+��.

#define BUS_A           0 //��� ���� ������� �� �������� �����
#define BUS_1           0 //��� ���� ������� �� �������� �����
#define BUS_B           1 //��� ���� ������� �� ��������� �����
#define BUS_2           1 //��� ���� ������� �� ��������� �����

//��������� ����������� ��������
#define RT_TRANSMIT     0x0400 // �� ��������
#define RT_RECEIVE      0x0000 // �� ���������

#define NWORDS_MASK     0x001F
#define SUBADDR_MASK    0x03E0
#define ADDRESS_MASK 	0xF800
#define RT_DIR_MASK 	0x0400

#define NO_FLAG_REQ     0x040

#define AUTO_CONT     0x10//������� ��������������� �����������

#define RT_MODE_WITH_FLAGS      0
#define RT_MODE_WO_FLAGSW_1     1
#define RT_MODE_WO_FLAGSW_2     2

//PCI �������� ����������� �����
#define TX_VID                  0x10B5
#define TX_DID                  0x9030
#define TX_SubVID               0xE1C5
#define TX1_SubDID              0x0001
#define TX6_SubDID              0x0002

//---------------------------------------------------------------------------
};
#endif
