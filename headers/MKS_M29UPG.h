//----------------------------------------------------------------------------------
#ifndef MKS_H_INCLUDED
#define MKS_H_INCLUDED
//----------------------------------------------------------------------------------
#include <sys/types.h>
//----------------------------------------------------------------------------------
#define FROM_MKS_HEADER_GLOBAL 	0xAAAB	//������������� �������� ������ �� ���
#define FROM_MKS_HEADER_ARINC 	0xAAB3	//��� ��  - ARINC429
#define FROM_MKS_HEADER_ADC_SUZ	0xAAB5	//��� �� - ��� � ���
#define FROM_MKS_HEADER_TIME 	0xAAB8	//��� ��  - ����� ��������� ���
#define FROM_MKS_HEADER_COM 	0xAAB1	//��� ��  - COM-����

 #define TO_MKS_HEADER_GLOBAL 	0xAAAA	//������������� �������� ������ ��� ���
 #define TO_MKS_HEADER_ARINC 	0xAAB2	//��� ��  - ARINC429
 #define TO_MKS_HEADER_SUZ	 	0xAAB4	//��� ��  - ���
 #define TO_MKS_HEADER_MFD 		0xAAB0	//��� ��  - COM-���� ��� �����(������)
 #define TO_MKS_HEADER_ICW 		0xAAB0	//��� ��  - COM-���� ���
 #define TO_MKS_HEADER_UAP 		0xAAB0	//��� ��  - COM-���� ���
 #define TO_MKS_HEADER_KI13 	0xAAB0	//��� ��  - COM-���� ��-13


#define DEF_MFK_TYPE    		0xA // MFI
#define DEF_UAP_TYPE    		0xB // ���
#define DEF_IKSH_TYPE  			0x13 // ���
#define DEF_KI13_TYPE   		0x18 // �� - 13

//----------------------------------------------------------------------------------

#pragma pack(push,1)

//	��������� �������� ������  
typedef struct _PACKET_HEADER {
WORD    Packet_ID;	//������������� �������� ������ ���/�� ���					AAAA(hex)/AAAB(hex)
WORD    Packet_Size;//������  �������� ������ ���/�� ��� � ������           	4+������ ���� ��
} PACKET_HEADER, * PPACKET_HEADER;

//������ ������ �� ���:

//1.��������� �������� ������
//2. �� ARINC429
//3. �� ���
//4. �� ���
//5. �� ����� ��������� ���
//6. �� COM-���� (��� �����, ��� ������, ���)


//�� ARINC429
typedef struct _PACKET_FROM_MKS_ARINC {
WORD	Packet_ID;		//��� ��  												AAB3(hex)
WORD  	Packet_Size;	//������ �� � ������									42
BYTE    NumInputCh;		//����� �������� ������ ARINC ( � �� �� ����� 1 )		0 � 3
BYTE    NumArincWords;	//���������� 32-��������� ���� � ������ 				9
DWORD   Word0100;		//����� � ������� 0100(oct)
DWORD   Word0101;		//����� � ������� 0101(oct)
DWORD   Word0102;		//����� � ������� 0102(oct)
DWORD   Word0103;		//����� � ������� 0103(oct)
DWORD   Word0104;		//����� � ������� 0104(oct)
DWORD   Word0105;		//����� � ������� 0105(oct)
DWORD   Word0106;		//����� � ������� 0106(oct)
DWORD   Word0107;		//����� � ������� 0107(oct)
DWORD   Word0110;		//����� � ������� 0110(oct)
} PACKET_FROM_MKS_ARINC, * PPACKET_FROM_MKS_ARINC;

//�� ���: 
typedef struct _PACKET_FROM_MKS_ADC {
WORD	Packet_ID;		//��� ��  												AAB5 (hex)
WORD  	Packet_Size;	//������ �� � ������									75
BYTE    TypeInf;		//��� ����������										1
DWORD	DataSize;		//������ ������ �� ���  � ������           				66
WORD	Count;			//������� ������ �� ��������� ���						����������
short	Ch[32];			//��� 1-32 �� ����� ��� 								����������
//FLOAT volt = (code / 32768.) *10.;
} PACKET_FROM_MKS_ADC, * PPACKET_FROM_MKS_ADC;

//�� ���:
typedef struct _PACKET_FROM_MKS_SUZ {
WORD	Packet_ID;		//��� ��  												AAB5 (hex)
WORD  	Packet_Size;	//������ �� � ������									99
BYTE    TypeInf;		//��� ����������										2
DWORD	DataSize;		//������ ������ �� ��� � ������           				90
WORD	Count;			//������� ������ �� ��������� ���						����������

WORD X_RUS_INT[3];        // ��������� ������� 0-65535
										// [ 0 ]������ ��������� ��� �� �������: 0 - 65535 (0 - ����������� 0xffff - ������������)
										// [ 1 ]������ ��������� ��� �� �����: 0 - 65535 (0 - ����� �����  0xffff - ����� ������)
										// [ 2 ]������ ��������� �������:  0 - 65535 (0 - ����� ������ �� �����,0xffff - ������ ������ �� �����)
WORD X_MET_INT[3]; 		// ��������� ��������� 0-65535
										// [ 0 ]������ ��������� �������� ����� (���)   0 - 65535 (0 - ����� ������, 0xffff - ����� �����)
										// [ 1 ]������ ��������� �������� ����� (���)  0 - 65535 (0xffff - ����� �����, 0 - ����� ������)
										// [ 2 ]������ ��������� �������� ����� (���)  0 - 65535 (0 - ����� ������ ������,0xffff - ������ ������ ������)
union {
	 struct {
		WORD I_Tng1	: 1;	// ����������� ������� 1 �� �������
		WORD I_Krn1	: 1;	// ����������� ������� 1 �� �����
		WORD I_Kur1	: 1;	// ����������� ������� 1 �������
		WORD I_Tng2	: 1;	// ����������� ������� 2 �� �������
		WORD I_Krn2	: 1;	// ����������� ������� 2 �� �����
		WORD I_Kur2	: 1;	// ����������� ������� 2 �������
		WORD I_Vop	: 1;	// ����������� �������� ����������
		WORD PR_Ust	: 1;	// ����������� ���������
		};
	  WORD i;				// ������� ������� ���
	  };
float	P_RUS[3];			// ������
float	X_Priv[3][2];		// ������� ��������� ��������
float	X_Priv_Zad[3];		// �������� ��������� ��������
float	X_RUS[3];			// ��������� ������� ���������� � ����������� ����
float	X_MET[3]; 			// ��������� ��������� � ����������� ����
WORD	Res;				// ������
} PACKET_FROM_MKS_SUZ, * PPACKET_FROM_MKS_SUZ;

//�� ����� ��������� ���:
typedef struct _PACKET_FROM_MKS_TIME {
WORD	Packet_ID;		//��� ��  												AAB8 (hex)
WORD  	Packet_Size;	//������ �� � ������									8
DWORD	Time;			//����� ��������� ��� � ��������						����������
} PACKET_FROM_MKS_TIME, * PPACKET_FROM_MKS_TIME;

//�� COM-���� ���:
typedef struct _PACKET_FROM_MKS_MFD {
WORD	Packet_ID;		//��� ��  												AAB1 (hex)
WORD  	Packet_Size;	//������ �� � ������									����������
BYTE	NumberComPort;	//����� COM-�����										1 � 4
WORD	DataSize;		//������ ������ ��  COM-�����   � ������           		����������
//	���� ������ ��  COM-�����:   	
BYTE	Synhro1;		//1-� ���� �������������								0xB0(���)
BYTE	Synhro2;		//2-� ���� �������������								0x3B(���)
BYTE	Synhro3;		//3-� ���� �������������								0x4F(���)
BYTE	DataSizeWOSyn;	//����� ������� � ������ ��� ����� �������������		7
BYTE	DevType;		//��� ����������										10
BYTE	DevAddr;		//����� ����������										0-�����(1-������)
BYTE	PacketType;		//��� ������											2
BYTE	MFKCode;		//��� ������� ��� ��� ��������							0-��� �������,(1-28)-���,(29-32)-�������� 
union {
	  struct {
		BYTE EncoderLD	: 2;//������� �����-���
		BYTE EncoderRD	: 2;// ������� ������-���
		BYTE EncoderRT	: 2;// ������� ������-����
		BYTE EncoderLT	: 2;// ������� ������-����
		};
	  BYTE	EncoderStatus;	//��������� ���������
	  };
BYTE	KS;				//����������� ����� (����� ������� ������� � 1-��� ����� ������������� �� ������ 256)
} PACKET_FROM_MKS_MFD, * PPACKET_FROM_MKS_MFD;

//�� COM-���� ���:
typedef struct _PACKET_FROM_MKS_ICW {
WORD	Packet_ID;		//��� ��  												AAB1 (hex)
WORD  	Packet_Size;	//������ �� � ������									����������
BYTE	NumberComPort;	//����� COM-�����										1 � 4
WORD	DataSize;		//������ ������ ��  COM-�����   � ������           		����������
//	���� ������ ��  COM-�����:   	
BYTE	Synhro1;		//1-� ���� �������������								0xB0(���)
BYTE	Synhro2;		//2-� ���� �������������								0x3B(���)
BYTE	Synhro3;		//3-� ���� �������������								0x4F(���)
BYTE	DataSizeWOSyn;	//����� ������� � ������ ��� ����� �������������		11
BYTE	DevType;		//��� ����������										13
BYTE	DevAddr;		//����� ����������										0
BYTE	PacketType;		//��� ������											2
BYTE	MFKCode;		//��� ������� ��� ��� ��������		�������� ������	��� ������
						//									��� �������			0
						//									������ ������ HUD	1
						//									������ ������ A/P	2
						//									������ MRK			3
						//									������ ABC/1		4
						//									������ ������ SET	5
						//									������ ������ COM	6
						//									������ LDG			7
						//									������ UP2			8
						//									������ ������ D/L	9
						//									������ ������ NAV	10
						//									������ CLR			11
						//									������ DEF/2		12
						//									������ ������ RNA	13
						//									������ APP			14
						//									������ UP1			15
						//									������ UP3			16
						//									������ GHI/3		17
						//									������ YZ/9			18
						//									������ JKL/4		19
						//									������ UP4			20
						//									������ /0			21
						//									������ MNO/5		22
						//									������ ENT			23
						//									������ UPD			24
						//									������ VWX/8		25
						//									������ STU/7		26
						//									������ PQR/6		27
						//									������ CRD			28
						//									������ ABR			29
						//									������ S/R			30
						//									������ RST			31
						//									������ STK			32
						//									������ S*			33
						//									������ R*			34
						//									������ D*			35

BYTE	EncoderStatusS;		//��������� �������� S* 							0-255
BYTE	EncoderStatusR;		//��������� ��������  R*							0-255
BYTE	EncoderStatusD;		//��������� ��������  D*							0-255
BYTE	EncoderStatusVALIn;	//��������� ��������  VAL ����������				0-255
BYTE	EncoderStatusVALOut;//��������� ��������  VAL �������					0-255
BYTE	KS;				//����������� ����� (����� ������� ������� � 1-��� ����� ������������� �� ������ 256)
} PACKET_FROM_MKS_ICW, * PPACKET_FROM_MKS_ICW;

//������ ����� �� ���:

typedef struct _PACKET_FROM_MKS {// ������ 409 ����
PACKET_HEADER				Header;
PACKET_FROM_MKS_ARINC		Arinc0,Arinc1,Arinc2,Arinc3;
PACKET_FROM_MKS_ADC			Adc;
PACKET_FROM_MKS_SUZ			Suz;
PACKET_FROM_MKS_TIME		Time;
PACKET_FROM_MKS_MFD			MfdLeft,MfdRight;
PACKET_FROM_MKS_ICW			Icw;

void InitPacket()// ������������� ���������� ���������� ������
{
Header.Packet_ID = FROM_MKS_HEADER_GLOBAL;
Header.Packet_Size = sizeof(PACKET_FROM_MKS);

Arinc0.Packet_ID		= FROM_MKS_HEADER_ARINC;
Arinc0.Packet_Size		= sizeof(PACKET_FROM_MKS_ARINC);
Arinc0.NumInputCh = 0;
Arinc0.NumArincWords = 9;
Arinc0.Word0100= 0100;
Arinc0.Word0101= 0101;
Arinc0.Word0102= 0102;
Arinc0.Word0103= 0103;
Arinc0.Word0104= 0104;
Arinc0.Word0105= 0105;
Arinc0.Word0106= 0106;
Arinc0.Word0107= 0107;
Arinc0.Word0110= 0110;

Arinc1.Packet_ID		= FROM_MKS_HEADER_ARINC;
Arinc1.Packet_Size		= sizeof(PACKET_FROM_MKS_ARINC);
Arinc1.NumInputCh = 1;
Arinc1.NumArincWords = 9;
Arinc1.Word0100= 0100;
Arinc1.Word0101= 0101;
Arinc1.Word0102= 0102;
Arinc1.Word0103= 0103;
Arinc1.Word0104= 0104;
Arinc1.Word0105= 0105;
Arinc1.Word0106= 0106;
Arinc1.Word0107= 0107;
Arinc1.Word0110= 0110;

Arinc2.Packet_ID		= FROM_MKS_HEADER_ARINC;
Arinc2.Packet_Size		= sizeof(PACKET_FROM_MKS_ARINC);
Arinc2.NumInputCh = 2;
Arinc2.NumArincWords = 9;
Arinc2.Word0100= 0100;
Arinc2.Word0101= 0101;
Arinc2.Word0102= 0102;
Arinc2.Word0103= 0103;
Arinc2.Word0104= 0104;
Arinc2.Word0105= 0105;
Arinc2.Word0106= 0106;
Arinc2.Word0107= 0107;
Arinc2.Word0110= 0110;

Arinc3.Packet_ID		= FROM_MKS_HEADER_ARINC;
Arinc3.Packet_Size		= sizeof(PACKET_FROM_MKS_ARINC);
Arinc3.NumInputCh = 3;
Arinc3.NumArincWords = 9;
Arinc3.Word0100= 0100;
Arinc3.Word0101= 0101;
Arinc3.Word0102= 0102;
Arinc3.Word0103= 0103;
Arinc3.Word0104= 0104;
Arinc3.Word0105= 0105;
Arinc3.Word0106= 0106;
Arinc3.Word0107= 0107;
Arinc3.Word0110= 0110;

Adc.Packet_ID = FROM_MKS_HEADER_ADC_SUZ;
Adc.Packet_Size = sizeof(PACKET_FROM_MKS_ADC);
Adc.TypeInf	= 1;
Adc.DataSize=66;

Suz.Packet_ID	= FROM_MKS_HEADER_ADC_SUZ;
Suz.Packet_Size = sizeof(PACKET_FROM_MKS_SUZ);
Suz.TypeInf	= 2;
Suz.DataSize = 90;

Time.Packet_ID	=	FROM_MKS_HEADER_TIME;
Time.Packet_Size = sizeof(PACKET_FROM_MKS_TIME);

MfdLeft.Packet_ID	= FROM_MKS_HEADER_COM;
MfdLeft.Packet_Size	=sizeof(PACKET_FROM_MKS_MFD);
MfdLeft.NumberComPort = 3;	//����� COM-�����
MfdLeft.DataSize	= 10;		
	
MfdLeft.Synhro1=	0xB0;
MfdLeft.Synhro2=	0x3B;
MfdLeft.Synhro3=	0x4F;
MfdLeft.DataSizeWOSyn =	7;
MfdLeft.DevType=	DEF_MFK_TYPE;
MfdLeft.DevAddr=		0;//-�����
MfdLeft.PacketType=		2;

MfdRight.Packet_ID	= FROM_MKS_HEADER_COM;
MfdRight.Packet_Size	=sizeof(PACKET_FROM_MKS_MFD);
MfdRight.NumberComPort = 1;	//����� COM-�����
MfdRight.DataSize	= 10;		
	
MfdRight.Synhro1=	0xB0;
MfdRight.Synhro2=	0x3B;
MfdRight.Synhro3=	0x4F;
MfdRight.DataSizeWOSyn =	7;
MfdRight.DevType=	DEF_MFK_TYPE;
MfdRight.DevAddr=		1;//-������
MfdRight.PacketType=	2;

Icw.Packet_ID	= FROM_MKS_HEADER_COM;
Icw.Packet_Size	=sizeof(PACKET_FROM_MKS_ICW);
Icw.NumberComPort=2;	//����� COM-�����
Icw.DataSize=14;		//������ ������ ��  COM-�����   � ������           		����������
//	���� ������ ��  COM-�����:   	
Icw.Synhro1=	0xB0;
Icw.Synhro2=	0x3B;
Icw.Synhro3=	0x4F;
Icw.DataSizeWOSyn=		11;
Icw.DevType=	DEF_IKSH_TYPE;
Icw.DevAddr=			0;
Icw.PacketType=			2;

}

BYTE	GetKs(BYTE * FirstBytePtr, int count)
{
BYTE ks=0;
for(int i=0;i<count;i++)
	ks += *(FirstBytePtr + i);
return ks;
}

BYTE	GetKsMfdLeft	(){return GetKs( &MfdLeft. Synhro1, 9);}
BYTE	GetKsMfdRight	(){return GetKs( &MfdRight.Synhro1, 9);}
BYTE	GetKsIcw		(){return GetKs( &Icw.Synhro1,		13);}

} PACKET_FROM_MKS, * PPACKET_FROM_MKS;


//----------------------------------------------------------------------------------

//������ ������ ��� ��� 

//1.��������� �������� ������
//2. �� ARINC429
//3. �� ���
//4. �� COM-���� ��� �����
//5. �� COM-���� ��� ������
//6. �� COM-���� ���
//7. �� COM-���� ���
//8. �� COM-���� ��-13


//�� ARINC429
typedef struct _PACKET_TO_MKS_ARINC {
WORD	Packet_ID;		//��� ��  												AAB2(hex)
WORD  	Packet_Size;	//������ �� � ������									4+������ ������  ���  ��
	
WORD	PacketTypeLine1;	//��� �����  ���  ���. �� �1						AAB2(hex)
WORD  	PacketSizeLine1;	//������  �����  � ������  ���   ���. �� �1			6+(���-�� ���� �� 1)*4
BYTE   	ChannelNumber1;		//����� ��������� ������ ARINC ( � �� ����� 1 )		0
BYTE	NumberWords1;		//���������� 32-��������� ���� � ������ 			1
DWORD   Line1_Word0100;		//����� � ������� 0100(oct)

WORD	PacketTypeLine2;	//��� �����  ��� ���. ��  �2						AAB2(hex)
WORD  	PacketSizeLine2;	//������  �����  � ������   ���   ���. �� �2		6+(���-�� ����   �� 2)*4
BYTE   	ChannelNumber2;		//����� ��������� ������ ARINC ( � �� ����� 1 )		1
BYTE	NumberWords2;		//���������� 32-��������� ���� � ������ 			1
DWORD	Line2_Word0100;		//����� � ������� 0100(oct)

WORD	PacketTypeLine3;	//��� �����  ���   ���. ��  �3						AAB2(hex)
WORD  	PacketSizeLine3;	//������  �����  � ������   ���   ���. �� �3		6+(���-�� ����   ��  3)*4
BYTE   	ChannelNumber3;		//����� ��������� ������ ARINC ( �  ��  ����� 1 )	2
BYTE	NumberWords3;		//���������� 32-��������� ���� � ������ 			2
DWORD	Line3_Word0100;		//����� � ������� 0100(oct)
DWORD	Line3_Word0101;		//����� � ������� 0101(oct)

//WORD	PacketTypeLine4;	//��� �����  ���   ���. ��  �4						AAB2(hex)
//WORD  	PacketSizeLine4;	//������  �����  � ������   ���   ���. �� �4		6+(���-�� ����   �� 4)*4
//BYTE   	ChannelNumber4;		//����� ��������� ������ ARINC ( �  ��  ����� 1 )	3
//BYTE	NumberWords4;		//���������� 32-��������� ���� � ������ 			0
} PACKET_TO_MKS_ARINC, * PPACKET_TO_MKS_ARINC;


//�� ���:
typedef struct _PACKET_TO_MKS_SUZ {
WORD	Packet_ID;		//��� ��  												AAB4(hex)
WORD  	Packet_Size;	//������ �� � ������									61
BYTE    TypeInf;		//	��� ����������										2
DWORD	DataSize;		//������ ������ ��� ��� � ������           				52
	union {//������� ������� ���
      struct {
		DWORD RK_Trim_Tng	   : 2;	// ������� ������ �������� ������ 0 - ��������, 1 - ����, 2  - �����
		DWORD RK_Trim_Krn	   : 2;	// ������� ������ �������� ������ 0 - ��������, 1 - �����, 2  ������
		DWORD RK_Trim_Napr     : 2; // ������� ������ �������� ������� 0 - ��������, 1 - �����, 2 - ������
		DWORD RK_SAU		   : 1;	// *** ������� ������� ��� ��������
		DWORD RK_GearOn	       : 1;	// ����� ��������
		DWORD RK_Ust		   : 1;	// �� ��������� ���
		DWORD RK_Stop	       : 1;	// ���������� �������
		DWORD RK_NULL		   : 1;	// ���������� ������� � ������� ���������
		DWORD RK_MIN		   : 1;	// ���������� ������� � �������
		DWORD RK_MAX		   : 1;	// ���������� ������� � ��������
		DWORD RK_TrimTngFail   : 2; // ����� ������� ������� (0 - ���, 1 - ���������, 2 - �����, 3 - ����)
		DWORD RK_TrimKrnFail   : 2; // ����� ������� ����� (0 - ���, 1 - ���������, 2 - �����, 3 - ������)
		DWORD RK_TrimRnFail    : 2; // ����� ������� ������� (0 - ���, 1 - ���������, 2 - �����, 3 - ������)
		};
	  DWORD	RK;
	  };
float	SAU_X_MET[3];	// *** ��������� ��������� �� ��� � ����������� ���� ��� 	[0]-�� �������	
						//															[1]-�� �����	
						//															[2]-�� ����	
float	Alfa; 			// ���� �����, �������	
float 	M;				// ����� �	����������
float 	Kfi;			// *** ����������� �������� K��								1.0 � 1.86
float 	X_SOS;			// *** ��������� ��� ���������, � ����������� ���� ���	
BYTE	Res[20];		// ������	
} PACKET_TO_MKS_SUZ, * PPACKET_TO_MKS_SUZ;

//�� COM-���� ��� �����(������):
typedef struct _PACKET_TO_MKS_MFD {

WORD	Packet_ID;		//��� ��  												AAB0 (hex)
WORD  	Packet_Size;	//������ �� � ������									17
BYTE	MumberComPort;	//����� COM-�����										3-����� (1-������)
WORD	DataSize;		//������ ������ ���  COM-�����   � ������           	10
BYTE	Synhro1;		//1-� ���� �������������								0xB0(���)
BYTE	Synhro2;		//2-� ���� �������������								0x3B(���)
BYTE	Synhro3;		//3-� ���� �������������								0x4F(���)
BYTE	DataSizeWOSyn;	//����� ������� � ������ ��� ����� �������������		7
BYTE	DevType;		//��� ����������										10
BYTE	DevAddr;		//����� ����������										0-�����(1-������)
BYTE	PacketType;		//��� ������											1
WORD	Light;			//������� ������										0-1023
BYTE	KS;				//����������� ����� (����� ������� ������� � 1-��� ����� ������������� �� ������ 256)	
} PACKET_TO_MKS_MFD, * PPACKET_TO_MKS_MFD;


//�� COM-���� ���:
typedef struct _PACKET_TO_MKS_ICW {
WORD	Packet_ID;		//��� ��  												AAB0 (hex)
WORD  	Packet_Size;	//������ �� � ������									16
BYTE	MumberComPort;	//����� COM-�����										2
WORD	DataSize;		//������ ������ ���  COM-�����   � ������           	9
BYTE	Synhro1;		//1-� ���� �������������								0xB0(���)
BYTE	Synhro2;		//2-� ���� �������������								0x3B(���)
BYTE	Synhro3;		//3-� ���� �������������								0x4F(���)
BYTE	DataSizeWOSyn;	//����� ������� � ������ ��� ����� �������������		6
BYTE	DevType;		//��� ����������										13      //?????????????????
BYTE	DevAddr;		//����� ����������										0
BYTE	PacketType;		//��� ������											1
BYTE	Light;			//������� ������										0-255
BYTE	KS;				//����������� ����� (����� ������� ������� � 1-��� ����� ������������� �� ������ 256)
} PACKET_TO_MKS_ICW, * PPACKET_TO_MKS_ICW;

//�� COM-���� ���:
typedef struct _PACKET_TO_MKS_UAP {
WORD	Packet_ID;		//��� ��  												AAB0 (hex)
WORD  Packet_Size;		//������ �� � ������									23
BYTE	MumberComPort;	//����� COM-�����										4
WORD	DataSize;		//������ ������ ���  COM-�����   � ������           	16
BYTE	Synhro1;		//1-� ���� �������������								0xB0(���)
BYTE	Synhro2;		//2-� ���� �������������								0x3B(���)
BYTE	Synhro3;		//3-� ���� �������������								0x4F(���)
BYTE	DataSizeWOSyn;	//����� ������� � ������ ��� ����� �������������		13
BYTE	DevType;		//��� ����������										11
BYTE	DevAddr;		//����� ����������										0
BYTE	PacketType;		//��� ������											1
float	Arrow1;			//��� ��� ������ �������								0.0 � 1.0
float	Arrow2;			//��� ��� ������ �������								0.0 � 1.0
BYTE	KS;				//����������� ����� (����� ������� ������� � 1-��� ����� ������������� �� ������ 256)
} PACKET_TO_MKS_UAP, * PPACKET_TO_MKS_UAP;


//�� COM-���� ��-13:
typedef struct _PACKET_TO_MKS_KI13 {
WORD	Packet_ID;		//��� ��  												AAB0 (hex)
WORD  Packet_Size;	//������ �� � ������									19
BYTE	MumberComPort;	//����� COM-�����										4
WORD	DataSize;		//������ ������ ���  COM-�����   � ������           	12
BYTE	Synhro1;		//1-� ���� �������������								0xB0(���)
BYTE	Synhro2;		//2-� ���� �������������								0x3B(���)
BYTE	Synhro3;		//3-� ���� �������������								0x4F(���)
BYTE	DataSizeWOSyn;	//����� ������� � ������ ��� ����� �������������		9
BYTE	DevType;		//��� ����������										24
BYTE	DevAddr;		//����� ����������										0
BYTE	PacketType;		//��� ������											1
WORD 	Gauge;			//��� ��� ����� 										(����(����))*6./5.
BYTE	LightRed;		//������� ��������										0-31
BYTE	LightGreenBlue;	//������� �������� � ������								0-31
BYTE	KS;				//����������� ����� (����� ������� ������� � 1-��� ����� ������������� �� ������ 256)	
} PACKET_TO_MKS_KI13, * PPACKET_TO_MKS_KI13;


//������ ����� ��� ���:

typedef struct _PACKET_TO_MKS {// ������ //195 ����          /////201
PACKET_HEADER				Header;
PACKET_TO_MKS_ARINC			Arinc;
PACKET_TO_MKS_SUZ			Suz;
//PACKET_TO_MKS_MFD			MfdLeft;
//PACKET_TO_MKS_MFD			MfdRight;
//PACKET_TO_MKS_ICW			Icw;

WORD	Packet_ID_Magic;	//���������� �����, ������������ �� ���, ��� ���� �� ���������� ���
WORD	Packet_Size_Magic;	//���������� �����, ������������ �� ���, ��� ���� �� ���������� ���

PACKET_TO_MKS_UAP			Uap;
//PACKET_TO_MKS_KI13		Ki13;

void InitPacket()// ������������� ���������� ���������� ������
{
Header.Packet_ID = TO_MKS_HEADER_GLOBAL;
Header.Packet_Size = sizeof(PACKET_TO_MKS);

Arinc.Packet_ID			= TO_MKS_HEADER_ARINC;
Arinc.Packet_Size		= sizeof(PACKET_TO_MKS_ARINC);

Arinc.PacketTypeLine1	= TO_MKS_HEADER_ARINC;	
Arinc.ChannelNumber1	=0;
Arinc.NumberWords1		=1;
Arinc.Line1_Word0100	=0100;		//����� � ������� 0100(oct)
Arinc.PacketSizeLine1	=6 + 4*Arinc.NumberWords1;	//������  �����  � ������  ���   ���. �� �1			6+(���-�� ���� �� 1)*4

Arinc.PacketTypeLine2	= TO_MKS_HEADER_ARINC;
Arinc.ChannelNumber2	=1;		//����� ��������� ������ ARINC ( � �� ����� 1 )		1
Arinc.NumberWords2		=1;		//���������� 32-��������� ���� � ������ 			1
Arinc.Line2_Word0100	=0100;
Arinc.PacketSizeLine2	=6 + 4*Arinc.NumberWords2;		//������  �����  � ������   ���   ���. �� �2		6+(���-�� ����   �� 2)*4

Arinc.PacketTypeLine3	= TO_MKS_HEADER_ARINC;
Arinc.ChannelNumber3	=2;		//����� ��������� ������ ARINC ( �  ��  ����� 1 )	2
Arinc.NumberWords3		=2;		//���������� 32-��������� ���� � ������ 			2
Arinc.Line3_Word0100	=0100;
Arinc.Line3_Word0101	=0101;
Arinc.PacketSizeLine3	=6 + 4*Arinc.NumberWords3;	//������  �����  � ������   ���   ���. �� �3		6+(���-�� ����   ��  3)*4

//Arinc.PacketTypeLine4	= TO_MKS_HEADER_ARINC;
//Arinc.ChannelNumber4	=3;		//����� ��������� ������ ARINC ( �  ��  ����� 1 )	3
//Arinc.NumberWords4		=0;		//���������� 32-��������� ���� � ������ 			0
//Arinc.PacketSizeLine4	=6 + 4*Arinc.NumberWords4;	//������  �����  � ������   ���   ���. �� �4		6+(���-�� ����   �� 4)*4

Suz.Packet_ID	= TO_MKS_HEADER_SUZ;			//��� ��  							AAB4(hex)
Suz.Packet_Size	= sizeof(PACKET_TO_MKS_SUZ);	//������ �� � ������				61 (63)
Suz.TypeInf		= 2;		//	��� ����������										2
Suz.DataSize	=52;		//������ ������ ��� ��� � ������           				52
//Suz.DataSize	=54;		//������ ������ ��� ��� � ������ (�������� FrameCount) 	54
/*
MfdLeft.Packet_ID		= TO_MKS_HEADER_MFD;
MfdLeft.Packet_Size		=sizeof(PACKET_TO_MKS_MFD);
MfdLeft.MumberComPort	= 3;	
MfdLeft.DataSize		= 10;		
MfdLeft.Synhro1=	0xB0;
MfdLeft.Synhro2=	0x3B;
MfdLeft.Synhro3=	0x4F;
MfdLeft.DataSizeWOSyn =	7;
MfdLeft.DevType=	DEF_MFK_TYPE;
MfdLeft.DevAddr=		0;//-�����
MfdLeft.PacketType=		1;

MfdRight.Packet_ID		= TO_MKS_HEADER_MFD;
MfdRight.Packet_Size	=sizeof(PACKET_TO_MKS_MFD);
MfdRight.MumberComPort = 1;	//����� COM-�����	
MfdRight.DataSize	= 10;		
MfdRight.Synhro1=	0xB0;
MfdRight.Synhro2=	0x3B;
MfdRight.Synhro3=	0x4F;
MfdRight.DataSizeWOSyn =	7;
MfdRight.DevType=	DEF_MFK_TYPE;
MfdRight.DevAddr=		1;//-������
MfdRight.PacketType=	1;

Icw.Packet_ID		= TO_MKS_HEADER_ICW;
Icw.Packet_Size		=sizeof(PACKET_TO_MKS_ICW);
Icw.MumberComPort	=2;	//����� COM-�����	
Icw.DataSize		=9;	//������ ������ ��  COM-�����   � ������           		
Icw.Synhro1=	0xB0;
Icw.Synhro2=	0x3B;
Icw.Synhro3=	0x4F;
Icw.DataSizeWOSyn=		6;
Icw.DevType=	DEF_IKSH_TYPE;
Icw.DevAddr=			0;
Icw.PacketType=			1;
*/

Packet_ID_Magic		= TO_MKS_HEADER_UAP;
Packet_Size_Magic	= 27;	

Uap.Packet_ID		=TO_MKS_HEADER_UAP;			//��� ��  						AAB0 (hex)
Uap.Packet_Size		=sizeof(PACKET_TO_MKS_UAP);	//������ �� � ������			23
Uap.MumberComPort=	 4;	//����� COM-�����										4
Uap.DataSize=		16;		//������ ������ ���  COM-�����   � ������          	16
Uap.Synhro1=	0xB0;
Uap.Synhro2=	0x3B;
Uap.Synhro3=	0x4F;
Uap.DataSizeWOSyn=	13;	//����� ������� � ������ ��� ����� �������������		13
Uap.DevType=	DEF_UAP_TYPE;	//��� ����������								11
Uap.DevAddr=		0;	//����� ����������										0
Uap.PacketType=		1;	//��� ������											1

/*
Ki13.Packet_ID		=TO_MKS_HEADER_KI13;		//��� ��  						AAB0 (hex)
Ki13.Packet_Size	=sizeof(PACKET_TO_MKS_KI13);	//������ �� � ������		19
Ki13.MumberComPort=	4;	//����� COM-�����										4
Ki13.DataSize=		12;		//������ ������ ���  COM-�����   � ������           12
Ki13.Synhro1=	0xB0;
Ki13.Synhro2=	0x3B;
Ki13.Synhro3=	0x4F;
Ki13.DataSizeWOSyn=	9;	//����� ������� � ������ ��� ����� �������������		9
Ki13.DevType=	DEF_KI13_TYPE;		//��� ����������							24
Ki13.DevAddr=		0;		//����� ����������									0
Ki13.PacketType=	1;		//��� ������										1
*/
}

BYTE	GetKs(BYTE * FirstBytePtr, int count)
{
DWORD ks=0;
for(int i=0;i<count;i++)
	ks += *(FirstBytePtr + i);
return (BYTE)(ks & 0xFF);
}

//BYTE	GetKsMfdLeft	(){return GetKs( &MfdLeft. Synhro1, 9);}
//BYTE	GetKsMfdRight	(){return GetKs( &MfdRight.Synhro1, 9);}
//BYTE	GetKsIcw		(){return GetKs( &Icw.Synhro1,		8);}
BYTE	GetKsUap		(){return GetKs( &Uap.Synhro1,		15);}
//BYTE	GetKsKi13		(){return GetKs( &Ki13.Synhro1,		11);}

} PACKET_TO_MKS, * PPACKET_TO_MKS;

#pragma pack(pop)

//----------------------------------------------------------------------------------
#endif // MKS_H_INCLUDED
//----------------------------------------------------------------------------------

