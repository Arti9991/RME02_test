#ifndef CommonPlane_H
#define CommonPlane_H

#include "const.h"

// ?????????????? ????????? ?????? cPlane.

struct type_CONTRL 
{ 
	int   IR;		// ?????? ?????? ?????? ???????.
	float T;		// ????????? ?????.
	float DTB;	// ???????? ????? Miss.
	float DTR;	// ???????? ????? ?????.
	int   KF;		// ????? ?????????? ?? ???????.
	int   KOLR;	// ?????????? ??????????.
	int   ITB;	// ??????? ????? ?????????????? ?????????? ?????.
	int   ITR;	// ??????? ????? ?????????????? ?????????? Miss.
	int   NREAL;// ????? ??????????.
	int   End;	// ??????? ????????? ????? ??????????.
	float MaxTime;	// ???????????? ?????  ?????  ??????.
	int   OIZ;      // ??????? ???? ?????? ?????????.
					// 0 - ??? ??????,
					// 1 - ????????? ???????? ??????,
					// 2 - ????????????????? ???????? ??????.
	int   Count2; // ????????? ??????? DTR/DTB.
};

struct type_R129 
{// ?????????  ?????????    ???  ????????  ??????  ?? ???.
	int   KSD;		// ???????????, ???????????? ??? ???????? ?????? 
					// ? Miss.
					// =1 - ????????; =2 - ???????????????;=0 - ????? 0.
	float DU[3];	// ???  KSD = 1 :
					// DU[0]=DU[1]=DU[2] - ??? ????????? ???????????? ???????
					// ??????? ???????? ??????????? "?????" ????;
					// ???  KSD = 2 :
					// DU[0],DU[1],DU[2] - ??????? ???????? ??????????? "?????"
					// ???? ???????????? ??? X,Y,Z.
	float DUW[3];	// ???  KSD = 1 :
					// DUW[0]=DUW[1]=DUW[2] - ??? ?????????????, ????????????
					//						  ???????????? ??????? ??????? ????????
					//						  "?????" ????, ????????????? ???????
					//						  ??????? ????????? Miss.
					// ???  KSD = 2 :
					// DUW[0],DUW[1],DUW[2] - ???????????, ???????????? ???????
          //                        ???????? "?????" ???? ????????????
          //                        ???? X,Y,Z ??-?? ?????? ???????
          //                        ????????? Miss.
	float DWK[3];	// ???  KSD = 1 :
					// DWK[0]=DWK[1] - ??? ?????? ? ?????????? ???????????? ???
					// ???  KSD = 2 :
					// DWK[0],DWK[1],DWK[2] - ?????? ? ?????????? ????????????
					//                        ???x,????,???z
	float DWD[3];	// ???  KSD = 1 :
					// DWD[0]=DWD[1]=DWD[2] - ??? ?????? ???.
					// ???  KSD = 2 :
					// DWD[0],DWD[1],DWD[2] - ?????? ???x,????,???z.
	float DGAM;		// ??? ??????? ?????? ????????? ??? ?? ????? ????????????
					// Miss.
	float DGS[3];	// ??? ???????? ??? X ?????????  ?????????????? ??????? ??
					// ??? ???.
	float PQR;	// ??????????? ????????????????.
	float AU;		// ????????? ?????? ?? ????.
	float AF;		// ???????????? ???????? ??????? ??? ??????.
	int   L;		// ????? ????? ?? 24?? ? ????????? "??????".
	int   N_n;		// ??????????? ????? ???????????? ??????? IUF ??? ???????????
					// ????????????? ?????? ??????, ??????????? ??? ???????? ?
					// ????? ??????? ???? ???.
	float RPor;		// ?????? ????????? ?? ? ??????.
	int	  Rik00c_vob;
	int Pr_Lt;		// ??????? ??????? ?????? ???????.
	int Pr_Zem;		// ??????? ??????? ???????????? ???????????.
	int Pr_Ekl;		// ??????? ??????????.
	int Pr_F;		// ??????? ??????????? ????????? ??????????? ??????? ????.
};

struct type_Memory
{
	int WasFill;// 1 - ????????? ?????????, 0 - ????????? ?? ?????????.
	float K;		// ?????????? ???????? ????? ???????.
	float xs;		// ?????????? ???????? ?????????? x ???????.
	float zs;		// ?????????? ???????? ?????????? z ???????.
};

struct Bort
{// ?????????? ? ???????? ??? Miss.
	float X, //
				Y, // ?????????? ???????? ? ???.
				Z, //
				Vx,//
				Vy,// ???????? ???????? ???????? ? ???.
				Vz;//
	int	  Sv_Chu; // ??????? "????" (S) - "?????" (Z). S=0, Z=1.
	int   Ne;     // ?????? ????? ???????? ? ???????.
	char  NameSystem[64];// ??? ???????? ????????? ?????????.
						 // ??? ????????? ???? - ??? ???????? ??????????.
	int   Pob;    // ??????? ??????. Pob = 1 - Miss ?? ????? ???????? ????????.
	int   PTC;    // ??????? ???? ????.
				  // 0 - ???????, 1 - ???????, 2 - ?????????.
	int   Tip,	  // 0 - ????????? ???? ?? MVO.
				  // 1 - ????????.
				  // 2 - Miss.
				Ps;     // ??????? ????????????? ????????.
	float AG[3][3];	// ??????? ???????? ?? ??? ? ???.
	float Epr;    // ??? - ???????????  ??????????  ???????????.
	int   Npt;    // ????? ??????????? ????? (0 - 10).
};

struct InitParZel
{// ????????? ???????? ?????????? ???? (?? ????? kin.var).
	float X, Y, Z,  // ??????????  ????.
		  Vx, Vy, Vz, // ???????? ????.
		  EPR,  // ??? ???????????  ??????????  ???????????.
		  Per,  // ??????????.
		  Ahgl, // ????????????  ????  ?????????.
		  Time, // ?????  ???????.
		  GM;   // ????.
	int   PRm;// ??????????.
	int   TypeGoal; // ???  ????:
				    // 0 - ???????, 1 - ???????, 2 - ?????????.
	float TPRKL; // ?????  ??????  ?????????? ??  ?????? ???????.
	int   Npt;   // ????? ??????????? ????? ??? ????.
};

struct type_ParZel
{// ????????? ????.
	type_Memory Mem;
	Bort  IB;
	float frazv,// ???? ???????.
				t1;		// ????? ?????? ???????.
	int   Prm;	// ??????? ???????.
					// 0 - ?????????????? ??????.
					// 1 - ???????????? ??????.
					// 2 - ???????????????? ??????.
	float Tz;
	float GAM;	// ????.
	float zn;
	float W[3];	// ????????? ? ???.
	float en;		// ?????? ??????? ?????????.
	float Vmod0,// ?????? ??????? ????????.
				rrn1;
	float gamzad,	// ????.
				Gamt,	// ??????????? ???????? ???????? ?????.
				rrom;	// ???????? ????????? ?????.
	float tau,	// ????? ????????? ?? ???????????? ????.
				t2,		// ????? ????????? ???????.
				t3,		// ????? ????????? ??????????.
				t4,		// ????? ?????????? ????????????? ????.
				rrt;	// ??????? ?? t3 ? t4.
};

struct type_ParametersOfFlight 
{// ???????? ????????? ?????? ???????? (????????).
	Bort IB;		  // ?????????? ?????????? ?????.
	float ON[3];	// ??????? ???????? ???????? ? ???.
	float amz_s;	// ????? ???? ????????.
	float alfa;		// ???? ?????.
	float enn[3];	// ???????? ?????????? ???????? ? ????.
	float VNI[3];	// ???????? ???????? ???????? ? ????, ?/?.
	float RNI[3];	// ???????????? ??????????? ???????? ? ????, ?.
	float VNL[3];	// ???????? ???????? ???????? ? ???, ?/?.
	float X, Y, Z;// ??????? ?????????? ???????? ? ???, ?.
};

struct type_BO
{// ?????????? ? ?????????????? ????????? ???????.
	int   PosZ01;// 0 - ???? ?? ??????????????, ?? 0 - ???? ??????????????. ?????? ?
				       // ??????? ???????? ????? (Z01).
	int   PrPO;
	int   NfVO;
	int   Pr_NR; // 1 - ???? ?????? ???????????????.
	int   PrZC;	 // 1 - ???? ????????? ????.
	int   PrNZC; // 1 - ???? ?? ????? ???? ????????? ???? ? ?????? ?????? ???????.
	float t0;	// ????? ?????? ??????? ????????? ????.
	float EGE;	 // ?????????????????? ?????? ????, ?? ??????? ???????? ??????.
	float EVE;	 // ?????????????????? ???? ????? ????, ?? ??????? ???????? ??????.
	float DET;	 // ?????????????????? ???????? ????????? ? ?????,
				       // ?? ??????? ???????? ??????.
	float DE;	   // ?????????????????? ????????? ?? ????, ?? ??????? ???????? ??????.
	float PSIZ;  // ????.
	float XCIS[3];// ?????????? ?????????? ???? ? ????.
	float VCIS[3];// ?????????? ???????? ???????? ???? ? ????.
	float XCIO[3];// ?????????? ????????????? ?????????? ???? ? ????.
	float VCIO[3];// ?????????? ????????????? ???????? ???? ? ????.
	int   Pr_Z,
				Pr_ZZZ, //
				Pr_KA,
				Pr_Ogr,
				Pr_PS,
				sz;
	float GAZ,  // 
	      modUg,//
	      modqn,//
				tau,  //
	      Tn,   //
				ni,
	      q,		//
	      fi,		//
				D,    //
	      vg,		//
				vs,
				vt,
	      wlg,	//
				wm,   //
	      dpsi, //
				tM,
				tOM,
	      sD,		//
	      sDo,  //
	      Dg,   // ?????? ?????????????? ????????? ?? ????.
				nz,
				xo,
				zo;
};

struct type_SAU 
{// ???.
	float ENZ;	// ???????? ??????????.
	float GAZ;	// ???????? ????.
	float VZA;	// ???????? ????????.
	float DLG;	// ??????? ?????? ????????? ? ?????????????? ????????? ?
				// ????????????????? ?? ????? ??????? ?????????.
	float DLV;	// ??????? ?????? ????????? ? ???????????? ????????? ?
				// ????????????????? ?? ????? ?????? ?????????.
	int   GOR;	// ??????? "?????".
	int   OTV;	// ??????? "???????".
	int   MB;	// ??????? "????? ??????".
	int   Pr_kgu;
	int   PrNPO;
	float NYZ; // ???????? ?????????? (?? ???).
	float Gzad;
};

struct type_NNN 
{// ?????????? ????????? ????????.
	float HABS;		// ?????????? ?????? ????????.
	float VMN;		// ?????? ???????? ????????.
	float AMZ;		// ????? ????.
	float AL;		// ???? ?????.
	float HOTN;		// ????????????? ?????? ????????.
	float PSI;		// ???? ????????.
	float TET;		// ?????? ????????.
	float GM;		// ???? ????????.
	float VNA[3];	// ???????? ???????? ???????? ? ???.
	float ENNA[3];	// ?????????? ?????????? ????????.
};

struct type_NUZR
{ 
	float DRMG;		// ???????????? ????????? ????? ??? ?????? ??????? "?????".
	float DRM1;		// ???????????? ????????? ????? ???. ?? ??????????????? ????.
	float DRM2;		// ???????????? ????????? ????? ???. ?? ????????????? ????.
	float DRMI;		// M?????????? ????????? ????? ???.
	float TPOLR;	// ?????????????? ????? ?????? ???.
	int   CDR;	    // ??????? "????????? ???????????".	
	float DRZ;	    // ????????? ?????????? ??????? ???.
	float DZP;
};

struct type_CZO  
{ 
	float EGC;  // ???????????? ?? ???????.
	float EVC;	// ???????????? ?? ???? ?????.
	float Eg_z;	// ???????????? ?? ???????.
	float Ev_z;	// ???????????? ?? ???? ?????.
	int   IPr_cy;
};

struct type_NUOI 
{// type_NI
	float EGIS;		// ?????? ??????? ????? ??????????? ????.
	float EVIS;		// ?????? ???? ??????? ????? ??????????? ????.
	float DNC;		// ?????? ????????? ?? ????.
	float DG;     // ?????? ?????????????? ????????? ?? ????.
	float VG;     // ?????? ?????????????? ???????? ????.
	float DTNC;		// ?????? ???????? ?????????.
	float VC;			// ???????? ????.
	float VCL[3];	// ???????? ???????? ???? ? ??? => ???.
	float HC;			// ?????? ????.
	float DHC;		// ?????????? ???? ??? ?????????.
	float QZ;			// ??????? ??????? ????.
	float Pel;    // ??????.
	int   ZPS;		// ??????? ?????????.
	int   Cat;		// ??????? "????? + ?".
};

struct type_NI1
{
	int NOP;		// ????? ??????? ????.
	int Ic;			// ?????? ???? ? ??????? BO.
	int Nk;			// ?????????? ????? ???? ? ??????? ??.
	int SOC;		// ??????? ?????? ???? ? ?????????????.
};

struct type_NI
{
	int KVC;				// ????? ????????? ??????? ?????.
	int KSC;				// ????? ?????????? ?????.
	int Mode;				// ??????? ?????? ?????? ????.
	int P_at;				// ??????? "?????".
	type_NI1 Mp[NAC];		// ?????? ?????????? ?????.
};

struct type_NUZU 
{
	float RONZPZ[Nr_][3];// c????????? ????????????? ?????????? ? ????????.
	float VONZPZ[Nr_][3];// ????????????? ???????? k-? ???? ? ????.
	float RNPZ[3];		// ?????????? ? ???????? ???????? ???????? ? ????.
	float VNPZ[3];		// VNPZ(1-3)     |.
	float DrzPZ[Nr_];	// ????????? ?????????? ???????.
	float Hsam;			// ?????????? ?????? ????????.
	int   Npz[Nr_];		// ????? ????? ????????? ???????.
	float R0;			// R0, R1, R2, R3 - ???????????? ???????????.
	float R1;
	float R2;
	float R3;
	float G[3];			// ???????? ????????? ???? ???????.
	int   Kti[3];		// ?????????????? ???????? ?????????? ?? ????,
						// ???????????? ? ??? ? ?? ???.
	float DTikv;		// ????? ???????? ????? ?????????? ? ???. 
};

struct type_KINEM
{
	float EGK;	// ???????? ???? ??????? ???? ? ??? (? ????????? ?? -pip ?? pip).
	float EVK;	// ???????? ???? ????? ???? ? ???.
	float DK;	// ???????? ????????? ?? ????.
	float DTK;	// ???????? ???????? ????????? ? ?????.
	float Az;   // ?????? ???? ? ????????? ?? 0 ?? pi2.
	int   PrSH; // ??????? ????????? ??.
};

struct type_SUO
{// ???.
	int PRESS,	// ????????? ??????.
		NL,		// ??????? ???????? ??????? ????????? Miss, ??????? ? ???????.
		KMPL;	// ????? ???????? 0 - ?? ????? Miss (SINGLE),
				//                1 - ???????????? ???? ???????? (SALVO).
};

struct type_PDV
{// ????????.
	int TP;		// ??? Miss. 
	int ISP;	// ???????????.
	int CNOS;	// ??????? ??????? Miss ? ????????.
	int NMCR;	// ?????? ???? ? ??????? ??? + 1 (????, ?? ??????? ???????? Miss).
	int bkn;	// ??????? ??????? ?????? ??????.
	int VYB;	// ??????? ??????.
	int SH;		// ??????? ????? Miss.
	int DR;		// ??????? "????????? ???????????" ??? ???.
	int PODG;	// ??????? ??????? "??????????".
	float AGP[3][3];// ??????? ???????? ?? ??? ? ??????? ????????? ????????.
	float T_vist;	// ????? ?????. ??????? "??????????".
	int NAL;	// ??????? ??????? Miss. 
	float TsxSALVO;
	float x;	// ??????? ?????????? ???????? (??? ???????????).
	float y;	// ??????? ?????????? ????????.
};

struct t_nu_at_vn
{
	int		kts20gc, nts20gc;
	int		kts10gc, nts10gc;
};

struct type_IKWK
{
	float dom[3];		// ???????? ?????? ????????? ?? ?????.
	float dnk[3];		// ?????? ???????? ???????? ???????? ?????????.
	float dwdr[3];		// ???????? ???? ??????? ???????? ?????????.
	float dptg0[3];		// ????????? ?????? ? ????? ?????????.
	float apsi[3];		// ?????? ????????? ????????????? ???????.
	float rgnv[3];		// ???? ?????????? ????????? ???????????? ???.
	float agi[3][3];	// ?????????? ???????? ?????.
	float ain[3][3];
	float DV[3];		// ??????????????? ?????? ? ????????? ????????.
	float DPTG[3];		// ????? ?????????.
};

struct type_NUPZ
{// ?????? ?????????? ?????
	float AKal;
	float AKkr;
	float AKal_V;
	float AKkr_V;
	float Dpod;
	float Dkr;
};

struct type_RK
{// ??????????????.
	float RZRK[3];	// ?????????? ???? ? ????,
					// ???????????? ? ???????? ?????????????? ?? Miss.
	float VZRK[3];	// ???????? ???????? ???? ? ????,
					// ???????????? ? ???????? ?????????????? ?? Miss.
	int   NRK;		// ??????? ?????? ??????????????, ?????????? ?? Miss.
					// ( ??????? ??????? ?????????????? ).

	int   Lsh;		// ??????? ????? Miss.
	float TkRK;		// ????? ?????????? ??.
};
 
struct type_rui
{
	float dsr;		// ??????? ?????????.
	float egc;		// ???? ??????? ????.
	float evc;		// ???? ??????? ????? ??????????? ????.
	float delvg;	// ???????? ???????? ????????? ???????? ? ???? ?? ??? Y.
	float delvv;	// ???????? ???????? ????????? ???????? ? ???? ?? ??? Z.
	float h_cel;	// ?????? ????.
	float fvl;		// ???? ????????????? ??????? ???? ? ???????.
	float fgl;
	float tetv;		// ???? ??????? ?????????? ????. 
	float tetz;		// ???????? ???? ??????? ?????????? ????.
	float dksirui;	// ??? ???????.
	int   ip4;		// ??????? ??????? ???????.
	int   igd;		// ??????? ???????????? ???????? "?????" ?? ?????????.
	float delg;
	float delv;
};

struct type_konst
{
	float ak1;
	float ak3;
	float ak4;
	float ak5;
	float ak7;
	float ak11;
	float ak12;
	float akh;
	float ak14;
	float ak15;
	float ak22; 
	float ak23;
	float ak24;
	float ak25;
	float ak26;
	float ak27; 
	float ak29;
	float ak30;
	float ak31;
	float ak32;
};

struct type_Rang
{
	int n;		// ?????? ???? ? ???????.
	float t;	// ????? ?? ??????? ? ?????.
};

struct type_Izm
{
	float x;	// ?????????? x ??????? ???????????? ????????.
	float y;	// ?????????? y ??????? ???????????? ????????.
	float t;	// ?????.
	int   RR;	// ????? ?????? ????.
	int   PrD;  // ??????? ??????? ????????? ? ??????.
	float xn;   // ?????????? ????????.
	float yn;   // ?????????? ????????.
	int   st;   // ??????? ??????? ???????.
};

struct type_Range
{
	int n;
	float Kr;	// ???????? ?????? ???????? ?????????????? ? ?????????????? ?????.
	Bort* IB;
};

struct type_NotZahv
{
	int Nf;		// ????? ????????? ?????????????? ????.
	float t0;	// ????? ??????? ??????? NotZahv.
};

struct type_PKin
{// ????????? ?????????? ??????????.
	float D;
	float DT;
	float EG;
	float EV;
	float Epr;
	float Rakr;
	float X;
	float Y;
	float Z;
	float Vx;
};

struct type_ZVO
{// ?????????? ?????? ??? (?????).
	unsigned char Ident; // ?????????????  ?????? ? ?????????? i-?? ??. 
	unsigned char SubZone; // ????? ?????? i-?? ??.
	double phiY; // Y-?????? i-?? ??.
	double phiZ; // Z-?????? i-?? ??.
	double Amp;  // ????????? ??????? i-?? ??.
	double D;
	double KolP; // ??????? i-?? ??.
	double LA_Kurs; // ???? ???????? ?? ?????? ????????? ??????? ????????? i-?? ??.
	double LA_Tang; // ?????? ???????? ?? ?????? ????????? ??????? ????????? i-?? ??.
	double LA_Kren; // ???? ???????? ?? ?????? ????????? ??????? ????????? i-?? ??.
	unsigned int StrobIndex; // ????? ?????? i-?? ??.
	unsigned int StrobResult;// ????????? ?????? ? ?????? ??? i-?? ??.
	unsigned char UT_Hour; // ??? ??????? ????????? ??????? ????????? i-?? ??.
	unsigned char UT_Min;  // ?????? ??????? ????????? ??????? ????????? i-?? ??.
	unsigned char UT_Sec;  // ??????? ??????? ????????? ??????? ????????? i-?? ??.
	double UT_mSec; // ???????????? ??????? ????????? ??????? ????????? i-?? ??.
	int PrD; // ??????? ??????? ?????? ?????????.
	int PrR; // ??????? ??????.
};

struct type_ZVO_All
{
	unsigned int Kolvo;// ?????????? ???????????? ? ??????? ????? ?????? ?????????? ??.
	unsigned char V_VFRF;
	unsigned char OV_RF;
	unsigned char V_ScanFinished; // ?????????? ? ????????? ???????? ???? ??????.
	struct type_ZVO Zam[16];
};

struct type_InfKPNO
{
	double T100; // ????? ?????????? 100 ?? ????????????? ??????????.
	double Fi_100;// ??????????? ?????????????? ?????? ???????????? ????????.
	double Lm_100;// ??????????? ?????????????? ??????? ???????????? ????????.
	double H_100;// ????????????? ?????? ???????????? ????????.
	double V_n;// ??????????? ???????? ???????????? ????????.
	double V_e;// ??????????? ????????? ???????????? ???????? .
	double V_h;// ??????????? ???????????? ???????????? ????????.
	double A_x;// ?????????? ???????????? ????????? ????????? ??.
	double A_y;// ?????????? ???????????? ????????? ????????? ??.
	double A_z;// ??????? ???????????? ????????? ????????? ??.
	double Gam;// ????.
	double Tet;// ??????.
	double Psi_ist;// ???????? ????.
	double SKO_LmFi;// ??? ??????????? ????????? ? ?????????????? ?????????.
	double SKO_H;// ??? ??????????? ??????.
};

/*struct GeoKoord
{
	double fi; // ?????????????? ?????? ????????.
	double lam;// ?????????????? ??????? ????????.
};*/

struct AllKoord
{
	double fi; // ?????????????? ?????? ???????, ???.
	double lam;// ?????????????? ??????? ???????, ???.
	double dlam;
	float X, 
				H,  // ?????????? ?????????? ???????, ??.
				Z;
	float	dK[3];// ?????????? ???????? ? ?????? ???????????? ???, ?.
};

struct Time50
{
	unsigned int Hour;
	unsigned int Min;
	unsigned int Sec;
	unsigned int MSec;
};

#endif
