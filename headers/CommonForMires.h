// CommonForMires.h: interface for the ClRadar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CommonForMires_H__958A62CF_1DEC_46F2_A5AF_630CFA97997D__INCLUDED_)
#define AFX_CommonForMires_H__958A62CF_1DEC_46F2_A5AF_630CFA97997D__INCLUDED_

#include "ConstMires.h"
#include "memory.h"
#include "CommonPlane.h"

struct DispInp
{// ��������� ���������.
	double Trls; 
	int    d_Pfon;// ������� ���� �����.
	int    Nbt;		// ����� ������������ ����� (�������� ��).
	int    ComSNP;
	int    Is_Real_MFI;	// 0 - ������ � ����������, 1 - ������ �� ������� ���.
	int    NREAL;// ����� ����������.
};

struct VhodPar
{
	int    Nbt;      //  ����� ������������ �����
	int    Ndrnp;    //  ���-�� �����, ���������. � ���� � ������� �����
	int    Ndc_snp;  //  ���-�� �����, ����������� � �� �� ���  
	int    MCdrnp[8];//  ������ ������� �����, ����������� � ��� �� ��
	int	   M_DC_SNP[8];	// ������ ������� �����, ����������� � �� �� ���
//	int    MCdrnp[8];//  ������ ������� �����, �������������� � ����
	int    MC129[8]; //  �����. ������ ����� ��� ��� ����, ���������. Miss
	int    ComSNP;   //  ������� "���" (1 - ������ ���, 0 - �� + ���).
	double Degv;     //  ������ ���� ������ ��������
	int    Nstrokv;  //  ����� ����� ���� ������ ��������
	double EgCZOv;   //  ����� ���� ������ �� �������
	double EvCZOv;   //  ����� ���� ������ �� ���� �����
	int    SemiSph;  //  ��������� ����� ����
	int    P1vhRLS;  //  ������� ������� ����� � ������ ����
	int    Pfon;     //  ������� ���� �����.(0, 1).
	double Kdal;     //  ����������� ������������ ������ ������� �� ��������� (1-2).
	double Kdt;      //  ����������� ������������ ������ ������� �� �������� (1-2).
	double Kangl;    //  ����������� ������������ ������ ������� �� ����� (1-2).
	double TobMax;   //  ����������� ���������� ������ ������ ��� �� � �����. �����.
	int Npt[NC];     //  ����� ����������� ����� ��� ������ ����
	double Devv;     // �������� ���� ������ �� �������

	VhodPar(){memset((void *)this,0,sizeof(VhodPar));};      //
};
 // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

// ��������� ���������� ��������
struct str_Car
{
	double Psi;      // ����  [���]
	double Teta;     // ������  [���]
	double Gamma;    // ���� [���]
	double Hotn;     // ������ ������������� [�]
	double V[3];     // ������������ ��������� [�/�]
	double Xn;
	double Yn;
	double Zn;
  str_Car(){memset((void *)this,0,sizeof(str_Car));};
};

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
struct targets
{// ��������� �������������� �����   
	int		KinNom;		// �������������� ����� ����
	int		PrSH;		// ������� ��������� ��
	int		SvChu;		// ������� "����-�����"
	double	Dalk;		// ���������  [�]
	double	Dtk;		// �������� ���������  [�/�]
	double	Evk;		// ���� ����� � ���[���]
	double	Egk;		// ������ � ���  [���]
	double	Eprc;		// ���        [��.�]
	double	Gspp;		// ����������� �������� ������� ��
	double	Np;			// ������������ ��������� ��

	double	X;
	double	Ht;
	double	Z;
	double	V[3];
	int		  Ric;		// ���������� ������������� �� ������ ���
	int		  Pr_Izl;		// ������� ������� ��������� � ������ ����
  int     PrV_Z;  // ������� "������ - �����". 1 - "������". 
	targets(){memset((void *)this,0,sizeof(targets));};
};

struct type_RangeVO
{
	int n;
	float Kr;	// �������� ������ �������� �������������� � �������������� �����.
};

struct type_RangeForIUS
{
	int n;
	float dD;	// �������� ������ �������� �������������� � �������������� �����.
	float dAz;
};

// �������������� ����������� �����

struct complex
{
	double A, B;
};

// �������� ��������� ����
struct OutRadar
{
	int   Rfunc;      // ����� ���������������� ����
						/* 4: ��� */
						/* 3: �� */
						/* 2: ������ */
						/* 1: �� */
	int   Ksopr;      // ����� ������ ���� ���, �������������� � ������ ����� ���.
	int   Ksopr1;     // ���. ����� ������� �������������� ���� � ���� ��� ����� ���. ???
	int   Nrak;       // ����� Miss, ��� ������� �����. �� � ������� �����
	int   NL;         // ���������� ����� � ����
	int   Notobz;     // ������� ����, ��� ��� ������
	int   Pr4_4[8];   // ������� ������
	int   NotzNP[8];  // ������� ����� �������
	int   Mrdc[8];    // ������ �����, ����������� �� ������������� � ���
	int   Riz;        // ����� ��������� (���, ���)
	int  	Nkadr;      // ����� ����� ������ ����
	int	  Pr_IzmInf;  //	������� ��������� ���������� �� �����
	int	  Pr_RegMIRES;//	������� ������ ������ �����
	int   Nrdc;       // ����� �����, �������������� � ���
	double  Tobz;     // ������ ������ ����
	int   Zn;			// ���� �������� �� ������
	int   Kstrok;     // ������� ������, �� ������� ��������� ���
	int   Nobn;       // ����� ������������ �������� � ������ �����

	OutRadar(){	memset((void *)this,0,sizeof(OutRadar)); };
};

// ��������� ���������� ��������� ����� � ������
struct OutObzor
{
   double	Dizm;		  // ��������� ���� ����������   [�]
   double	DTizm;		// �������� ��������� ���� ����������  [�/�]
   double	EGizm;		// ������ ���� ����������    [���]
   double	EVizm;		// ���� ����� ����������     [���]
   double	Tizmer;		// ����� ��������� ��������� �����   [�]
   int		PizmD;		// ������� ��������� ���������
   int		PizmDt;		// ������� ��������� �������� ���������
   int		Pr_GO_RLK;// ������� ��������������
   int		Type_Targ;// ��� ���� ���
   int		N_Targ;		// ����� ���� ���
   int		Kanal;		// ����� ��� (� ��� L)
   int    Pr_DC;		// ������� ���������� ���� �� ��
   int		Pr_SNP_DC;// ������� �������� ������� ������ �� ��� � �� �� ������ ������
   int		RegIzl;		// ����� ���������, ��� ������� ��� ������� ����� ���������
   int		Pr_IzInfor;	// ������� ��������� ���������� ������ ���������
   int		Ktrass;	    // ����� ������ ���, ����������� � ��

   OutObzor(){ memset((void *)this,0,sizeof(OutObzor)); };
};

struct Inf_RLS
{
	OutRadar Z;
	OutObzor Ot[NC];
};

// ����������, ����������� � ��������� ���
typedef struct InterfaceIntegraph
{
// ������ ����������, ����� ��� ���� ������� ������ �-036
  int IUP_Izl;             // ������������� ���� ���. ����
  unsigned IUP_CONF_kadr_kn;    // ������� ����, �� ������� ������������ ������ � ��
// ������� ������ ���������� ��� ������� �-� (�������� ������ �-� (��, ����) ��� �-036,  ��������� ��� ���-�, ���������� �������������� �� �-036 (��� � ��))
  int IUP_rej_OZP;        // ������� "����� ����� ������ �����������" 
  int IUP_RLP;            // ������� �� ������ �����������
  int IUP_rej_NR;         // ���� �������� ����� � ������ �����������
  int IUP_rej_CR;         // ���� �������� ����� � ������ �����������
  int IUP_rej_MORE;       // ���� �������� ����� ������� �����������
  unsigned IUP_RLS_rej_kart; // ���� � ��������������� �������� ������� � �������� � ������� ����������� (����� ��)
  unsigned IUP_SH121_FrameSize;        // ������ ������. ����� ���
  unsigned char IUP_RLS_sis_koord_RLI;         // ������� ������������ ��������� /�������������
    //int IUP_level_signal;   // ������ ����������� ������ �������� ��������� ���.�-036
  unsigned IUP_RLS_Cel_Fon;   // ����������� ������/��� ��������
  unsigned int IUP_RLS_daln_max_zad_VP;          // ����� ����� ��������� (����� ��, ������������ ��������� ��������� ��)
  double IUP_RLS_czo_pel_zad_VP;      // ������ ������ �� ��� �� ����������� 
  unsigned char IUP_RLS_pr_rej_MKP;            // ������� ����������
  unsigned IUP_RLS_mash_MKP;         // ������� �����������
	unsigned char IUP_pr_naj_rud_4PP_right;// ��������� ������ 4�� ���
	unsigned char IUP_pr_naj_rud_4PP_left;// ��������� ����� 4�� ���
	unsigned char IUP_pr_naj_rud_4PP;// ����������� �������  4�� ��� (����� ���?)

  unsigned char IUP_RK_vvod;        // ������� �������  ����� 
  unsigned char IUP_RK_sbros;       // ������� �������  ������
	double IUP_Ux_kn;			// ���������� �������� �� ��� �
	double IUP_Uy_kn;			// ���������� �������� �� ��� y
	unsigned char IUP_RK_ZERO_KNP;
//	double IUP_Perek_X;     // �����. ����������� �� ��� � ��� �� (�.�. � ��������, �.�. int !!?)
//	double IUP_Perek_Y;     // �����. ����������� �� ��� Y ��� �� (�.�. � ��������, �.�. int !!?)
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ������� ������ ���������� ��� ������ �-� ������ ���������� ������������ � �������� ���� ��� ���_ջ
  unsigned char IUP_OPS_Hand_Aut;	// ������� ������� ������� ����� ��� 0 - ������, 1 - ����
	unsigned int IUP_pr_naj_OVP;      // ������� ��������� ���
  unsigned IUP_RLS_Avtz_VV;      // ������ ���� ������ ���_�
  double IUP_RLS_czo_pel_zad_VV;  // �������� �������������� ������ ��� ���_�
    double IUP_RLS_czo_daln_zad_VV; // �������� ��������� ����������� ��� ���_�
    double IUP_RLS_czo_h_zad_VV;		 // �������� ������ �������������� �� ��� ���_�
	double IUP_Dstr;			// ��������� ������ ������ �� ��� � ������ ������� ������ ����� 
	double IUP_Azstr;			// ������ ������ ������ �� ��� � ������ ������� ������ ����� ��� ������ ������
//	double IUP_Umstr;			// ���� ����� ������ ������ �� ��� � ������ ������� ��. ����� � ��. ������
	// +++++++++++++++++++++++++++++++++++++++++++++
// ������� ������ ���������� ��� ������ �� � ��� 
  unsigned char IUP_ZaprIII_GO;      // ������� ����, ��� ��������� ��������� ������ ���� � III ������ ��
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++           
// ��������� ������ ���������� (��������� ��� ������� ������ �-121 �� ������ ����������
//  int IUP_Pr_corPKS;       // ������� ��������� ���������
//  int IUP_PrTarg;          // ������� ������ �� ����� ������������ �-036 ��� �������������� �����
//  int IUP_Obz_CU;          // ������� ������ (������) �� �ӻ
  int IUP_GO_N;            // ������� ��� �� ������ ���� �-036)
  int IUP_GO_CU;           // ������� ��� �� �ӻ
  int IUP_RTR;             // ������� ����������� �������� ��ֻ 
  int IUP_PPO;             // ������� ����������. /������������ �����������
  int IUP_str_CU;          // ������ ������ ������� ���� � ������ �� ��,  ����������  � �� �� ��
  int	IS_REAL_MFI;   	     // ������� ����, ��� ������ ������ ����� �������� ���
  int Nf;					 // ����� ������, �����. ������
} InterfaceIntegraph;

typedef struct Str_InputH036// ���� �-036
{
	// �������� ������
	unsigned		BP_P_RLK_X;			// ������� �������� 
	unsigned		BP_Izl_X;			// ��������� ���_�
	unsigned		BP_VP_X;			// ���. ����� ��
	unsigned		BP_VV_X;			// ���. ����� ��
	unsigned     BP_BB;				// ������� ��
	unsigned     BP_RTR_REP;			// ������� "���. ����� ���-���"

	// ������ �_�
	unsigned		BP_SO_PRM;			// �������.: ������/������� 
	unsigned		BP_Cel_Fon;			// ����� � ����������: ���/���� 
	unsigned		BP_Format_Kadr_VP;	// ������ �����
	unsigned		BP_Otrab_VV_SBR;	// ������. ��������� ��. ����/�����
	double			BP_Daln_CZ_VP;		// ��������� ������ ���� ����
	double			BP_Az_CZ_VP;		// ������ �� ��
	unsigned		BP_MP_VP;			// ������� ��������� ���-�
	unsigned		BP_Masht_MP;		// "������� ���
	unsigned		BP_Cel_PKS_AS_L;	// ����� ���� � ������������� ���
	unsigned		BP_More_VP;			// �������  "���. ����� ����" ���-�
	unsigned		BP_NR_VP;			// ������� "���. ����� ��" ���-�    
	unsigned		BP_SR_VP;			// ������� "���. ����� ��" ���-�  
	unsigned		BP_VVOD;			// ������� ������ ����
	unsigned		BP_SBROS;			// ������� ������ ����� 
	unsigned		BP_Priz_Form_Perekr; // ������� ��������. �����������
	unsigned 		BP_Perekr_X;		// �����. ����������� �� � 
	unsigned 		BP_Perekr_Y;		// �����. ����������� �� Y


	unsigned		BP_VR_VP;			// ������� "���. ����� ��" ���-�
	unsigned		BP_PAM_VP;			// ������� "���. ����� ������" ���-�
	unsigned		BP_MNGSTR;			// ������� "�������� ������" ���-�
	unsigned		BP_NoK_PAM;			// "����� ����� ���" ���-�
	unsigned		BP_DISS_VP;			// ������� "���. ���� ���-�
	unsigned		BP_RRY_RLI;			// ������ �����. ������� ������� 
	unsigned		BP_IDZ_VP;			// ������� "���. ����� "���"  ���-�
	unsigned		BP_VIS_VP;			// ������� "������� ��������. �������" ���-�
	unsigned		BP_Upravl_RLK;		// ������. ���-�/���-L
	double	BP_Az_IDZ;			// "������ � ������ ���" ���-�
//	double	BP_Ym_IDZ;			// "���� ����� � ������ ���" ���-�
	unsigned	BP_Ym_IDZ;			// "���� ����� � ������ ���" ���-�
	unsigned		BP_Out_RLK_X;		// ������� "���. ����� �������. ��� �"


	// ������ ��
	unsigned		BP_No_zon_X;		// "����� ����" ���-�
	unsigned		BP_POLUSF;			// ������� "��������� ���-�"
	unsigned		BP_CY_Ygl;			// ������� "�� �� �����" ���_�
	unsigned		BP_CY_D;			// ������� "�� �� �" ���_� 
	unsigned		BP_CY_V;			// ������� "�� �� �������� " ���-�
	unsigned		BP_NoC_DC;			// ������ �����, �����������  �� ��
	unsigned		BP_NoC_SNP;			// ������ �����, ����������� �� ���
	double			BP_Az_CZ_X;			// "������ ��" ���-�
	double			BP_Ym_CZ_X;			// "���� ����� ��" ���-�
	double			BP_Daln_CY_X;		// "��������� ��" ���-�
	double			BP_Vsbl_CY_X;		// "�������� ��������� ��" ���-�
	unsigned		BP_DO;				// ������� "��"
	unsigned		BP_DO_Nom;			// ����� ������ ��
	double			BP_Delt_D_X;		// ���������� �� �� D ���_�
	double			BP_Delt_V_X;		// ���������� �� �� V ���_�

	unsigned		BP_REGIM_BBV;		// �������� ���
	unsigned		BP_NoC_Sbros;		// ������ ����� ����������� �� �����
	
	// ��� �� �� ������ ����

	unsigned		BP_NoC_GO;			// ����� ���� �� ��
	unsigned		BP_Lin_GO;			// ����� �����������
	unsigned		BP_Pr_ppo;			// ������� ���
	unsigned		BP_Pr_Rr;			// ��� ������
	unsigned		BP_Prior_T;			// ��������� ����

} Str_InputH036;

typedef struct Str_InputL402
{						// ��� ������ ���
	unsigned		IUS_TID;		// ���������� �������. ���� �� �-402	
	unsigned		IUS_PDE;		// �������� ������� ������ � ����				
	double			FSL;			// ������ ������� �� ������	
	double			FSH;			// ������� ������� �� ������		
	double			AZVL;			// ������ ������� ����������� ������� phiZ ������		
	double			AZVH;			// ������� ������� ����������� ������� phiZ ������		
	double			AZGL;			// ������ ������� ����������� ������� phiY ������		
	double			AZGH;			// ������� ������� ����������� ������� phiY ������		
	unsigned		IUS_DSKR;		// ���������� ����		
	unsigned		RPEL;			// ������� �� �������. ��� ��������� ����� ������� ���		
	unsigned		IUS_LZP;		// ������ �� ������ 				
	unsigned		IUS_Pr_RTRRLS;	// ���(���/���)		
	unsigned		IUS_R_RTRCU;	// ���/��		
	unsigned		IUS_R_RTRVTP;	// ���/���		
	unsigned		IUS_PT;			// ���/��		
	unsigned		IUS_PrRTR;		// ���		
} Str_InputL402;


typedef struct InputH121
{// ��
	unsigned BP_zayavka;  // ������ �� �����������
	unsigned BP_OperationMode_GO;  // ���
	unsigned BP_RodRab;  // ��� ������
	unsigned BP_Linia;  // ����� �����������
	unsigned BP_Strob;  // ����� ���������
	double	BP_Azimut;   // ������
	unsigned BP_Prizn_Azimut; // ������� ������ �������
	double BP_Ugol_mesta; // ���� �����
	unsigned BP_Prizn_Ugol_mesta;  // ������� ������ ���� �����
	double BP_DC;  // ��������� �� ����
	unsigned BP_Prizn_DC ; // ������� ������ ���������

	// ���� ������!!!, ������������ ��� ������ ��������� � rlk_x.cpp
	int BP_GO_N0;  // ������� ��� �� ������ ���� �-036)
	int Nf;        // ����� ��������� ������ ��� GOnc.
} InputH121;

/* ������ �� �� ����� �� �-036�. */
typedef struct t_DateGOTarg
{// ��
	unsigned N036SH_Rez_PO_targ; // ���������� ��
	unsigned N036SH_Dop_Prizn_targ; // �������������� ��������
	double   N036SH_D_targ; //��������� ���������� ����
	unsigned char N036SH_D_targ_dostg; // ������������� ��������� ���������� ����
	double   N036SH_Azimut_targ; //������ ���������� ����
	unsigned char N036SH_Azimut_targ_dost; // ������������� ������� ���������� ����
	double   N036SH_Ugol_mesta_targ; //���� ����� ���������� ����
	unsigned char N036SH_Ugol_mesta_targ_dost; // ������������� ���� ����� ���������� ����
	
} t_DateGOTarg;

typedef struct t_timeGO
{
	unsigned Hour;
	unsigned Min;
	unsigned Sec;
	double MSec;
} t_timeGO;

typedef struct OutputH121
{// ��
	unsigned N036SH_Num_targ1; // ���������� ���������� �����
	Time50 timeGO;
	unsigned char N036SH_zayavka_out;// ������ �� ����������� �������
	unsigned char N036SH_Linia_out;// ����������� ����� �����������
	unsigned N036SH_OperationMode_GO_out;// ���������� ������� ���
	unsigned char N036SH_RodRab_out;// ���������� ��� ������ ���������� ��
//	unsigned N036SH_hour_target; // �������� �����
//	unsigned N036SH_min_target; // �������� �����
//	unsigned N036SH_sec_targ; // �������
//	unsigned N036SH_msec_targ; // ���� �������
    t_DateGOTarg DateGOTarg[14]; // ������ ������ �� �� ����� �� �-036�
} OutputH121;
typedef struct Str_OutNC13   // ���������� ��������� ��� 1-� ��� 3-� ����
{
	unsigned		N036_hour_izm_1_3;	// ���� 1(3) ����
	unsigned		N036_min_izm_1_3;		// ������ 1(3) ���� 
	unsigned		N036_sec_izm_1_3;		// ������� 1(3) ����
	double		N036_msec_izm_1_3;	// ������������ 1(3) ����
	unsigned		N036_PKS_AS1_out;		// ������� ����������� ���/�� ��������� ���/��
	unsigned char		N036_SrivAS1_out;		// ������� ���� ��
	unsigned char		N036_CvZone1;			  // ������� ���� � ����
	unsigned		N036_NoC_H0361_out;	// ����� ���� �036 
	unsigned char		N036_Prizn_OI;			// ������� ���������� ����������
	unsigned char		N036_KanalX1_out;
	unsigned char		N036_KanalL1_out;
	double	N036_Az1_out;		// ������ 1 (3) ����
	double	N036_ygl_mesta_out;	// ���� ����� 1 (3) ���� 
	double	N036_danl1_out;			// ��������� 1 (3) ����
	double	N036_velocity1_out;	// �������� 1 (3) ����
//	double	N036_vel_byAz1_out;	// ������� ����. �� ������� 1 (3) ����
//	double	N036_sev_vel1_out;	// �������� ������������ �������� 1 (3) ����
//	double	N036_vost_vel1_out;	// ��������� ������������ �������� 1 (3) ����
	unsigned    N036_GO_1_3;      // ��������� ��
	unsigned    N036_Rez_GO_1_3;  // �������������� �������� �� 
} Str_OutNC13; 

typedef struct Str_OutNC24			// ���������� ��������� ��� 2-� ��� 4-� ����
{
	unsigned		N036_hour_izm_2_4;	// ���� 2(4) ����
	unsigned		N036_min_izm_2_4;		// ������ 2(4) ���� 
	unsigned		N036_sec_izm_2_4;		// ������� 2(4) ����
	double		N036_msec_izm_2_4;	// ������������ 2(4) ����
	unsigned		N036_PKS_AS2_out;		// ������� ����������� ���/�� ��������� ���/��
	unsigned char		N036_SrivAS2_out;		// ������� ���� ��
	unsigned char		N036_CvZone2;			  // ������� ���� � ����
	unsigned		N036_NoC_H0362_out;	// ����� ���� �036 
	unsigned char		N036_Prizn_OI_2_4;
	unsigned char		N036_KanalX2_out;
	unsigned char		N036_KanalL2_out;
	double	N036_Az2_out;			// ������ 2 (4) ����
	double	N036_ygl_mesta2_out;// ���� ����� 2 (4) ���� 
	double	N036_danl2_out;			// ��������� 2 (4) ����
	double	N036_velocity2_out;	// �������� 2 (4) ����
//	double	N036_vel_byAz2_out;	// ������� ����. �� ������� 2 (4) ����
//	double	N036_sev_vel2_out;	// �������� ������������ �������� 2 (4) ����
//	double	N036_vost_vel2_out;	// ��������� ������������ �������� 2 (4) ����
	unsigned N036_GO_2_4;      // ��������� ��
	unsigned N036_Rez_GO_2_4;  // �������������� �������� �� 
} Str_OutNC24; 

typedef struct Str_OutH036		// ����� �-036
{

	unsigned		N036_Cel_PKS_AS_L_out;	// "����� ����� �� �� � ���" 
	unsigned char		 N036_VP_X_out;			// ���. ����� ��
 	unsigned N036_Perekr_X_out;		// ��������� ����������� �� � 
	unsigned N036_Perekr_Y_out;		//	��������� ����������� �� Y 
	unsigned char N036_Prizn_Form_Perekr_out;//	������� ������������ �����������
	unsigned char		N036_VV_X_out;          //���. ����� ��
	unsigned		N036_No_zon_X_out;      //����� ���� ���-�
	unsigned		N036_NoC_GO_out;		// ����� ���� �� ��
	unsigned		N036_Pr_Rr_out;			// ��� ������
	unsigned		N036_Lin_GO_out;		// ����� �����������
	unsigned char		N036_Pr_ppo_out;		// ������� ���
	Str_OutNC13 OutNC13;			// ���������� ��������� ��� 1-� ��� 3-� ����
	Str_OutNC24 OutNC24;			// ���������� ��������� ��� 2-� ��� 4-� ����

} Str_OutH036;

typedef struct Str_InMFI	// ������� ��������� ��� ���������
{
	int		Lx;				// �������������� ������ ������� ������� ������ ���
	int		Ly;				// ������������ ������ ������� ������� ������ ���
	int		RMax;			// ������ ������� ������� �������
	int		RMin;			// ������ ������� ������� �������
	int		Ox;				// ��������. ���������� ������ ���������� ��� ��������� �������
	int		Oy;				// ������. ���������� ������ ���������� ��� ��������� ������� 
	int		TypSopr[4];		// ��� i-� �������������� ���� 
	int		Pr_ExKTGR;		// ������� ������ �� ��� �������� ���� ����
	int		Lyzad[NbtMax];	// ���������� � ���� �� ���
	int		Lxzad[NbtMax];	// ���������� Y ���� �� ���
	int		Lyizm[4];		// ���������� Y  ���������� �� �� ������ ���
	int		Lxizm[4];		// ���������� X  ���������� �� �� ������ ���
	double	Alf;			// ��������� ���� �������� ���� �� ������ ���
	double	betta;			// ��������� ���� ���� ����
	int		KolTg;			// ���-�� �������� �������. ��, ��������� �� �����
	int		Xugl;			// �����. � �������� ������� ���� ����� ��� ���������� ��
	int		Yugl;			// �����. Y �������� ������� ���� ����� ��� ���������� ��
	int		SizeX;			// ������ ����� �� � ��� ���������� ��
	int		SizeY;			// ������ ����� �� Y ��� ���������� ��
	int		Perekr_X;		// ��������� ����������� ����������� �� ��� �
	int		Perekr_Y;		// ��������� ����������� ����������� �� ��� Y
	int		Pr_Zahv;		// ������� ����� ������� �� (������ ��������. �� ������ �� ���)
	int		N_Tg;		    // ���������� �������������� �����
	double	EgCzo;			// ������ ��� � ���
	double	Dminim;			// ����������� ��������� ���� ���� ��� ���
	double  Dmaxim;			// ������������ ��������� ���� ���� ��� ���
	int		NumTgou;		// ����� ����, � ������� ����� ��
	unsigned tuErr_n_zo_VP;	// ��������� "������� ������ ����� ���������" 
	unsigned tuErr_pel_VP;	// ��������� "������� ����� ������ ���"
	unsigned tuErr_DczoHabs;// ��������� "��������� ��������� ������ ������ ��������"
    unsigned tuErr_Dczo;	// ��������� "��������� ��� ����� �� ���������� �������"
	unsigned tuErr_Dist;	// ��������� "����� ���� ���� ��� ���� ��������� ����" 
	unsigned tuErr_Dgor;	// ��������� "��������� ��������� ������ ��������� ��������."
	unsigned tuPr_NotVP;	// ������� ������������� ���������� ���� ���� 
	unsigned int SO_PRM;
	unsigned int MP_VP;

	// �-�
	int   Num;					// ���������� ��������. ��������� �����.
	int   Nbt;					// ���������� ���������. �����.
	int   IUP_RLK_ZO_Riz;		// ����� ���� ���-�.
	int   SemiSph;				// ������� "��������� ���-�".
	double ygl_az_C[NbtMax];    // ������ �������������� ����.
	double ygl_mesta_C[NbtMax]; // ���� ����� �������������� ����.
	double dln_do_C[NbtMax];    // ��������� �� �������������� ����.
	double V_C[NbtMax];         // �������� �������������� ����.
	double ygl_az_C_nf[NbtMax]; // ���������� ������ ����.
	double ygl_mesta_C_nf[NbtMax];// ���������� ���� ����� ����.
	double dln_do_C_nf[NbtMax]; // ���������� ��������� �� ����.
	double V_C_nf[NbtMax];      // ���������� �������� ����.
	int NoC_SNP_out[NbtMax];    // ������ �����, ����������� �� ���
	int DS_SNP[NbtMax];         // ������� ��/���
	// ����� �� ��� ��� ����������� �� ��������� ���
//	int Num_KGS;				// ����� ����� � ���
//	double fiy_KGS[NbtMax];		// ������ ���������� � ���
//	double dln_KGS[NbtMax];		// ��������� ���������� � ��� 
	//
	double Hcel;                //�������� ������ ����
	double Dzad;                //�������� ���������
	double EGzad;               //�������� ������ ���� ������ �� �����������
//	��
	int svoi[NbtMax];			// ��� �������������� ����� (����� �� �� ��)
	int svoi_cu[NbtMax];		// ��� �������������� ��������� ����� (�� �� ������)
//	int priz[NbtMax];

	// ���	
	int	Pr_IZL[NbtMax];				// ������� ������� ��������� � ����
	int	Pr_IZM_Fig_L402[NbtMax];	// ������� ��������� �������
	double IZM_Fig_L402[NbtMax];	// ���������� ������
	double IZM_Daln_L402[NbtMax];	// ��������� �� ����, ������ ��������������
	int Pr_IZM_Rejim_L402[NbtMax];	// ������� ���������� ������
	int	IZM_Rejim_L402[NbtMax];		// ���������� �����
	int Pr_In_L402[NbtMax];			// ������� ����, ��� ���� �������� � ��������� � ���� ����� ���
	int ID_In_L402[NbtMax];			// ���������� ������������� ���� �� ���
} Str_InMFI; 


struct strmasCel
{
	float Eg;
	float DC;
	int   Cel_SvCg; // ���� "����-�����"
	int   RegRab;   // ���=0, ���=1
	int   DC_SNP;   // ��=0, ���=1
};

/* �������������� ���������� �� ���������*/
/* 
 * struct str_Integraf
 * {
 * 	int  time_hour; // ������ ���������� ���-�� ���������
 * 	int  time_min;
 * 	int  time_sec;
 * 	float  time_msec;
 * 	int  Kol_Cel; // ���������� ����� �� ���������
 * 	strmasCel masCel_i[100]; // ���������� �� �����
 * };
 */

// ������� ��������� �� ��� 
typedef struct strInputFromFPO
{
	int i;
} strInputFromFPO;

// �������� ��������� ��� ���
typedef struct strOutputForFPO
{
	int i;
} strOutputForFPO;

/* �������������� ���������� �� ��� */
struct str_RLS
{
	int  Kol_Cel; // ���������� ����� � ���
	strmasCel masCel[NbtMax]; // ���������� �� �����
};

//******************** ���� ������, �� ��� ���������� **************
struct rez_GOcu
{
	int N036S_Rez_GO_targ;
	int N036S_Dop_Prizn_targ;
	float N036S_D_targ;
	float N036S_Azimut_targ;
	int N036S_Azimut_targ_dost;
	float N036S_Ugol_mesta_targ;
	int N036S_Ugol_mesta_targ_dost;
};

struct strMod_GOcu
{
			// ��������� � ������ �-036�

	unsigned char N036SH_zayavka_out;				// ������ �� ����������� �������		
	unsigned char N036SH_Linia_out;				// ����������� ����� �����������
	unsigned N036SH_OperationMode_GO_out;	// ���������� ������� ���
	unsigned char N036SH_RodRab_out;				// ���������� ��� ������ ���������� ��
	unsigned N036SH_hour_target;				// �������� �����
	unsigned N036SH_min_target;				// �������� �����
	unsigned N036SH_sec_targ;				// �������
	double N036SH_msec_targ;				// ���� �������
	rez_GOcu mrez_GOcu[14];
};

struct strMod_GOnc
{
	unsigned N036_NoC_GO_out;
	unsigned N036_Rez_GO[NbtMax];
	int N036_obrezGO[NbtMax];
};


struct strMod_RTR
{
	// ��������� � ������ �402

	unsigned L402_KCU;			// ��������� � ������. ������� �� � ������
	unsigned L402_KZTT;			// ��������� ������. ������� �������/������. ����������
};


// ����� �� �-402 �������� ���
struct strPIV_L402_out
{
	unsigned L402_TID;
	unsigned L402_PFM;
	unsigned L402_PDI;
	unsigned char L402_FND;
	unsigned L402_TYP_F;
	unsigned L402_RW;
	double L402_AZN;
	unsigned char L402_AZS;
	unsigned char L402_DPEL;
	unsigned L402_TPEL;
	double L402_FTG;
	double L402_TDI;
	double L402_PWS; 
	double L402_PWM; 
 	double L402_PPT;
	double L402_VDT;
	unsigned int L402_TYP_C[3];
	unsigned L402_TYP_I;
	unsigned char L402_VID;
	unsigned L402_SOT; 
	double TIMELAST;
	double L402_TOS;
	double L402_UMT;
	unsigned char L402_DUMT;
	unsigned L402_RSK;
	double L402_TSK;
	unsigned L402_REP;
	unsigned int L402_PUS;
	unsigned L402_PRPS;
	unsigned int L402_IUS; 
	unsigned char L402_RPD;
	unsigned char L402_RPDK;
	unsigned char L402_RPDM;
	unsigned char L402_REPVZ;
	double L402_DAL;
	unsigned char L402_TDAL; 
	unsigned L402_HOURLAST;
	unsigned L402_MINLAST;
	unsigned L402_SEKLAST;
	unsigned L402_MSEKLAST;
	double L402_Hdg;
	double L402_Pitch;
	double L402_Roll;
};

// ������ �������������� �� �����
struct strRadio_Situation
{
	unsigned i_TID;
	unsigned i_RW;
	double i_AZN;
	double i_FTG;
	double i_TDI;
	double i_PWS; 
	double i_PWM; 
 	double i_PPT;
	unsigned int i_TYP_C;
	unsigned int i_TYP_I;
	unsigned char i_VID; 
	double i_UMT;
	double i_TSK;
	unsigned i_PRPS;
	double i_time;
	double i_Hdg;
	double i_Pitch;
	double i_Roll;
	double i_DAL;
};

// �������� ���������������� ������� � ���� ���
// � ����� ���� ������������ � ����             
struct CResBase
{
	int RESType;       // ���� ��� (����������)
	char RESName[40];  // �������� ���
	bool isafar;       // ���� 1 �� ���/���� ����� �������

	// 0-min �������� � 1-max ��������
	double Fo[2];      // ������� ������� ���
	double Tau[2];     // ������������ ��������
	double Fp[2];      // ������� ����������	
	double Tp[2];

	double Pim[2];   // ���������� (�������) ��������
	int TipPW[3]; // 0 - ��� ���� � ��� � ������ ��� � ���� � ��� � ���� � ������ ������
	// TipPW=1 - ��� ���� � ��� � ������� ����� �  ������ � ��� ��������� ���� � ��� � ���� � ������ ����� � ��� ���� � ��� � ���� � ������ �� 
	// TipPW=2 - ��������� ������������ ����  ��� ��������� ����� ���� � ��� � ���� � ������ �����
	double Gain;       // ����������� �������� ������� ��

	double FiMax;     // ���������� �������� ���������� ������� �� ��������� 

	bool isdelete;     //  ���� �� ��������
	
	int ParamSig[3];   // ��������� ������� 0-��� 1-���� 2-���������
	int PulsMod[4];     // ���� ���������� ���������
	// 0-������� 1-��� 2-��� 3-�� �� �������� � ��������
};

// ��� ��������� ����������� ���� ���
struct StrDrawBeam
{
	int RfuncD;
	double MuD[3],NuD[3],FiMaxD[3],dFilD[3];
	double PSID,TETAD,GAMMAD;
	int NstrokD,PkadrD,NafarD,McD,NbtD,NkadrD;
	double EgCZOD,EvCZOD,DegD;
	double EgLD,EvLD;
	targets targD[NC]; 
	double EgkD[NC],EvkD[NC];
	double EgeD[NC],EveD[NC];
	bool IsExtrD[NC];
};

typedef struct Str_Ptr
{// ��������� ���������� �� ���������� ������� ������ cMires.
  Str_InputH036*   pInputH036; // ������� ���������� ��� ����.
  Str_InMFI*       pInMFI;     // �������� ���������� ��� ������ �� ���.
  strOutputForFPO* pOutForFPO; // ���������� ��� ���.
  str_Car *        pCarrier;   // ��������� ���������� ��������.
  targets *        pTarget;    // ���������� � ����� (����������).
  InputH121*       pInputH121; // ������� ���������� ��� ��.
  VhodPar  *       pVhParam;   // ������� ��������� ����.
  Str_OutH036*     pOutH036;
  OutputH121*      pOutH121;
  Str_InputL402*   pInputL402;
  strRadio_Situation *pRS;
} Str_Ptr;

#endif // !defined(AFX_CommonForMires_H__958A62CF_1DEC_46F2_A5AF_630CFA97996D__INCLUDED_)
/////////////////////////////////////////////////////////////////////////////
