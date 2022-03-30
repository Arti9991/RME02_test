#if !defined(__ASP)
#define      __ASP

#include <stdio.h>
#include <windows.h>


#pragma pack(push, 1)

#include "#tmg.h"

struct sASP
	{
	public:
 
	// In
 unsigned __int8  code;          // ��� �������
	unsigned __int8  typeMKIO;      // ��� ������ �� ���� (0-TE6, 1-iMKIO)

 unsigned __int8  K[32];         // �� �� ��� �� ������ ���
 unsigned __int16 MH1[8];        // ����� ������ 1-� ���� ���� (����) |  8 : ���.07 |
 unsigned __int16 MH2[28];       // ����� ������ 2-� ���� ���� (����) | 28 : ���.07 |
 unsigned __int16 MH3[32];       // ����� ������ 3-� ���� ���� (����) | 32 : ���.07 |
 unsigned __int16 MH4[30];       // ����� ������ 4-� ���� ���� (����) | 30 : ���.07 |
 unsigned __int16 MH5[29];       // ����� ������ 5-� ���� ���� (����) | 29 : ���.07 |
	unsigned __int32 tMH1;        // ����� ���������� ������ ������� MH1 �� ���� ���, ��
	unsigned __int32 tMH2;        // ����� ���������� ������ ������� MH2 �� ���� ���, ��
	unsigned __int32 tMH3;        // ����� ���������� ������ ������� MH3 �� ���� ���, ��
	unsigned __int32 tMH4;        // ����� ���������� ������ ������� MH4 �� ���� ���, ��
	unsigned __int32 tMH5;        // ����� ���������� ������ ������� MH5 �� ���� ���, ��
	unsigned __int32 PZD[28];       // ����� ������ � �������� (���)

	double Targ_lat[19];            // ������ ����� (�������� 8 �����)
	double Targ_long[19];           // ������� ����� (�������� 8 �����)
	unsigned __int8 Targ_n;         // ���������� �����, �������� � ��

	// Out
	unsigned __int8  S[32];         // �� �� ��� �� ������ ���
	unsigned __int16 MR1[1];        // ����� ������ ������ ��1 (����)    |  1 : ���.07 |
	unsigned __int16 MR2[29];       // ����� ������ ������ ��2 (����)    | 29 : ���.07 |
	unsigned __int32 tMR1;          // ����� ���������� ������ ������� MR1 �� ���� ���, ��
	unsigned __int32 tMR2;          // ����� ���������� ������ ������� MR2 �� ���� ���, ��
	unsigned __int16 ASP_RT_Status; // C����� ��������� RT �� ���� ���� ���
 unsigned __int32 PZA[28];       // ������ ���� ������(���)

	// InOut
	unsigned __int8  Shod;          // ������� ������

 // Simulation
 unsigned __int32 simul[2];         // �������� ������������� ������ / ������ ��������� �� ������� ���

	// ������� �������� ����������� �����
 unsigned __int16 chekSumMH1(void); // ����������� ����� ������� ��1
 unsigned __int16 chekSumMH2(void); // ����������� ����� ������� ��2
 unsigned __int16 chekSumMH3(void); // ����������� ����� ������� ��3
 unsigned __int16 chekSumMH4(void); // ����������� ����� ������� ��4
 unsigned __int16 chekSumMH5(void); // ����������� ����� ������� ��5
 unsigned __int16 chekSumMR1(void); // ����������� ����� ������� ��1
 unsigned __int16 chekSumMR2(void); // ����������� ����� ������� ��2
 
	sASP ();
	};

#define szMAS(NAME)   sizeof(NAME)/sizeof(NAME[0])

sASP::sASP ()
	{
	int i;
 for (i = 0; i<szMAS(K); i++)   { K[i] = 0;   }
 for (i = 0; i<szMAS(MH1); i++) { MH1[i] = 0; }
 for (i = 0; i<szMAS(MH2); i++) { MH2[i] = 0; }
 for (i = 0; i<szMAS(MH3); i++) { MH3[i] = 0; }
 for (i = 0; i<szMAS(MH4); i++) { MH4[i] = 0; }
 for (i = 0; i<szMAS(MH5); i++) { MH5[i] = 0; }
 for (i = 0; i<szMAS(PZD); i++) { PZD[i] = 0; }
 for (i = 0; i<szMAS(S); i++) { S[i] = 0; }
 for (i = 0; i<szMAS(MR1); i++) { MR1[i] = 0; }
 for (i = 0; i<szMAS(MR2); i++) { MR2[i] = 0; }
 for (i = 0; i<szMAS(PZA); i++) { PZA[i] = 0; }
 code = 0;
 Shod =0;
	}

unsigned __int16 sASP::chekSumMH1(void) // ����������� ����� ������� MH1
 {
 unsigned __int16 res = 0;

 for (int i = 0; i<szMAS(MH1) - 1; i++) { res += MH1[i]; }
 return res;
 }

unsigned __int16 sASP::chekSumMH2(void) // ����������� ����� ������� MH2
 {
 unsigned __int16 res = 0;

 for (int i = 0; i<szMAS(MH2) - 1; i++) { res += MH2[i]; }
 return res;
 }

unsigned __int16 sASP::chekSumMH3(void) // ����������� ����� ������� MH3
{
 unsigned __int16 res = 0;

 for (int i = 0; i<szMAS(MH3) - 1; i++) { res += MH3[i]; }
 return res;
}

unsigned __int16 sASP::chekSumMH4(void) // ����������� ����� ������� MH4
{
 unsigned __int16 res = 0;

 for (int i = 0; i<szMAS(MH4) - 1; i++) { res += MH4[i]; }
 return res;
}

unsigned __int16 sASP::chekSumMH5(void) // ����������� ����� ������� MH5
{
 unsigned __int16 res = 0;

 for (int i = 0; i<szMAS(MH5) - 1; i++) { res += MH5[i]; }
 return res;
}

unsigned __int16 sASP::chekSumMR1(void) // ����������� ����� ������� ��1 (�������� ��� �������!!! ����� ����!!!)
{
	unsigned __int16 res = 0;
 return res;
}

unsigned __int16 sASP::chekSumMR2(void) // ����������� ����� ������� ��2
{
 unsigned __int16 res = 0;

 for (int i = 0; i<szMAS(MR2) - 1; i++) { res += MR2[i]; }
 return res;
}

#endif