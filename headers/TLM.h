#include "windows.h"
long __stdcall InitTLM(DWORD size, LPSTR Name);//Размер разделяемой памяти и ее имя
void __stdcall UnPakTLM(void);
void __stdcall CloseTLM(void);

//данные ПОЗ - РТМ входные
struct str_BCVMtoBRPI
{
	unsigned long
	CheckCodeOffsetTlmData,//контрольный код, содержащий значение смещения этого параметра в разделяемой памяти
	SS_115,
	 SRK_201,
	 NR_220,
	 Vhy_221,
	 Vhz_222,
	 R0_223,
	 R1_224,
	 R2_225,
	 R3_226,
	 dtIKV_227,
	 Drz_230,
	 Qc_231,
	 qxi_232,
	 ZK_233,
	 CUO_234,
	 qyn_235,
	 qzn_236,
	 NLitRK_237,
	 NN_240,
	 TI_241,
	 ZR_242,
	 TP_243,
	 DT_244,
	 TC_245,
	 H0_246,
	 V0z_247,
	 OP_250,
	 UOR_251;
 };

//данные ПОЗ - виртуальные выходные (распакованные)
struct str_BCVM_BRPI
{
float
	ASP,//
	VSK,//
	Ntp,//

	PS_2,//
	Nk_2,//

	NR,//
	Vnx,//

	Vny,//
	ZV,//

	Vnz,//

	R0,//
	SCHA,//
	R1,//

	R2,//
	SCHB,//
	R3,//

	dt_IKV,//
	Xn,//

	Yn,//
	D_rz,//

	Zn,//
	Qc,//

	VI,//
	qxi,//

	Zk,//

	CUO,//
	Wiz,//
	Wiy,//

	SCHX,
	qyn,//

	qzn,//

	NLitRK,//
	PV,//
	BU,//
	Xni,//

	NN,//
	Nk,//
	Yni,//

	TId,//
	TIdst,//
	TIfi,//
	Vz,//
	Zni,//
	
	ZR,//
	PN,//
	ST,//
	X0i,//

	TP,//
	VK,//
	DI,//
	TM,//
	Y0i,//

	DT,//
	BB,//
	Alfa,//
	Z0n,//

	TC,//
	ZP,//
	OK,//
	V0x,//

	H0,//
	V0y,//

	V0z,//

	OP,//
	Np,//

	DRG,//
	DRY,//
	DRZ;//
};

//обмен ИСУ - РГС - РТМ входные
struct str_ISUtoRGS
{
unsigned long
SCH3_340,
SCH4_341,
Kg_342,
SCH1_343,
SCH2_344,
R00_345,
SCH5_346,
SCH6_347,
Y_350,
Z_351,
R0_352,
Y00_353,
SGI1_354,
SGI2_355,
SGI3_356,
SGI4_357;
};
//обмен ИСУ - РГС - виртуальные выходные (распакованные)
struct str_ISU_RGS
{
float
SCH3,//
Wy,//
DI,//

SCH4,//
Wz,//

Kg,//

Vy,//
SCH1,//

Vz,//
SCH2,//

R00,//

deltaY,//
SCH5,//

deltaZ,//
SCH6,//

A0,//
A1,//
Pel_Y,//

R01,//
Pel_Z,//

R0,//

V1,//
V2,//
V3,//
V4,//
PV,//

ZP,//
RE,//
BB,//
UP,//
CN,//
TS,//
TY,//
BP,//

V5,//
HP,//
PG,//

NK,//
NR,//
NN,//
PB,//

AP,//
BK,//
AR,//
NL,//
TC;//
};

//обмен РГС - ИСУ - РТМ входные
struct str_RGStoISU
{
unsigned long
SIN2_300,
SIN3_301,
SIN4_302,
SIN5_303,
SIN6_304,
SIN7_305,
SIG1_306,
SIN1_307,
Yg_311,
Zg_312,
RO_313,
deltaY_314,
deltaZ_315,
Sigma_316,
SIG2_317;
};
//обмен РГС - ИСУ - виртуальные выходные (распакованные)
struct str_RGS_ISU
{
float 
NR,
dXt,
dYt,
GC,
dZt,
Tc,
XD,
Xy,
Xc,
Xt,
Yt,
Zt,
RIy,
RIx,
DT,
RIz,

ZC,
GG22,
PK,
GG1,
GG2,

NK,
PP,
NC,
NN,
PI,

Pel_Yg,
Pel_Zg,
R0,
deltaY,
deltaZ,
Sigma,

PK2,
DO,
CHP,
DC,
ZC2;
};

//данные ТЛМ РГС - РТМ входные
struct str_TlmRGSto
{
unsigned long 
BK_200,
BK_020,
GG_010,
Vxc_230,
Vyc_130,
Vzc_330,
Xc_070,
Yc_270,
Zc_170,
X5_004,
SH_204,
S41_304,
S42_044,
S43_244,
S44_144,
S45_344,
S46_024,
KS_164;
};
//данные ТЛМ РГС - виртуальные выходные (распакованные)
struct str_TlmRGS_
{
float 
VK200,
RE200,

VK020,
VP,
RE020,
Sh020,
PK,

GG2,
GG1,
ZP,
GKS,

Vxc,
NR,
DT,

Vyc,
NP,
GS,
Vzc,
TC,
TI,
Xc,
Yc,
Zc,
X5,
SH204,
SCHK,
SNC4,
S41,
S42,
S43,
S44,
S45,
S46,
KS;
};

//данные ТЛМ ИСУ - БМК входные
struct str_CusBMKto
{
unsigned short 
AP_0,
AP_40,
AP_100,
AP_140,
R0_20,
R1_21,
R2_22,
R3_23,
VRX_27,
VRY_30,
VRZ_31,
XR_32,
YR_33,
ZR_34,
VNX_41,
VNY_42,
VNZ_43,
XNR_44,
YNR_45,
ZNR_46,
DP3_47,
AS_50,
ALH_52,
TO_53,
PO_54,
GX_55,
GY_56,
GZ_57,
XN0_60,
YN0_61,
ZN0_62,
X0_63,
Y0_64,
Z0_65,
V0X_66,
V0Y_67,
V0Z_70,
H0_71,
HPO_72,
SCH2_73,
NN_74,
ZR_75,
ZP_76,
NR_77,
SIC_114,
R0N_120,
R1N_121,
R2N_122,
R3N_123,
NN_135,
NL_136,
VNX_24,
VNY_25,
VNZ_26,
YPK_35,
ZPK_36,
TU_124,
SPK_125,
VKX_127,
VKY_130,
VKZ_131,
XK_132,
YK_133,
ZK_134,
DD_157,
D_160,
VCX_161,
VCY_162,
VCZ_163,
X0_164,
Y0_165,
Z0_166,
ZP_170;
};
//данные ТЛМ ИСУ - виртуальные выходные (распакованные)
struct str_TlmBMK_
{
float 
GG1_0_0,
GG2_0_0,
MO_0_0,
KK_0_0,
PS_0_0,
AP_0_0,
PS_40_0,
GG2_40_0,
GG1_40_0,
AP_40_0,
KK_40_0,
MO_40_0,
GG1_100_0,
PS_100_0,
KK_100_0,
MO_100_0,
GG2_100_0,
AP_100_0,
AP_140_0,
MO_140_0,
GG2_140_0,
PS_140_0,
KK_140_0,
GG1_140_0,
R0,
R1,
R2,
R3,
VRX,
VRY,
VRZ,
XR,
YR,
ZR,
VNX,
VNY,
VNZ,
XNR,
YNR,
ZNR,
DR3,
AS,
ALH,
T0,
P0,
AR,
CHK,
GX,
GY,
GZ,
XN0,
YN0,
ZN0,
X0_63,
Z0_64,
Y0_65,
V0X,
V0Y,
V0Z,
N0,
NP0,
SCH2,
SCH1,
NN_74,
NK_74,
NL_74,
ZR_75,
PN_75,
ST_75,
XD_75,
XC_75,
XY_75,
ZP,
TC,
OK,
TP,
TM,
NP,
ZV,
BB,
DT,
KP,
C0,
SIC,
R0N,
R1N,
R2N,
R3N,
NN_135,
NK_135,
NP_135,
NL_136,
AP_136,
VK_136,
AR_136,
AP_0_1,
RE_0_1,
AP_40_1,
RE_40_1,
AP_100_1,
RE_100_1,
AP_140_1,
RE_140_1,
XN,
YN,
ZN,
FY,
FZ,
XPK,
ZPK,
YPK,
TU_124,
TS_124,
TD_124,
XY_124,
XD_124,
XC_124,
PSL_124,
SPK,
KL4,
KL3,
KL2,
PK,
RK,
VKX,
TCK,
VKY,
VKZ,
DT_131,
XK,
YK,
ZK,
DD,
D,
VCX,
VCY,
VCZ,
X0,
Y0,
Z0,
ZP_170,
TS_170,
TY_170,
TC_170,
RE_170,
VP_170,
BB_170,
PSL_170;

unsigned long
K2onIPC5; //параметр К2 с РВВ-АЕ,  входной

unsigned long
CheckCodeNumberTlmData;//контрольный код, = количество всех телеметрических параметров + 2(CheckCodeNumberTlmData и CheckCodeOffsetTlmData) +1 Для K2OnIPC5
};