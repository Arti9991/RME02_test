
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CMIRES_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CMIRES_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

#include "..\\@include\\CommonForMires.h"

#ifdef CMIRES_EXPORTS
#define CMIRES_API __declspec(dllexport)
#else
//#define CMIRES_API __declspec(dllimport)
#define CMIRES_API 
#endif

class cRLK_X;
class cGO;
class CSRTRImitation;
class CSRTR;
struct type_CONTRL;
struct str_Car;
struct targets;
struct Str_InMFI;

typedef struct Str_Ptr_Item
{// ��������� ���������� �� ���������� ������ cMires.
	cRLK_X         * pBrls;  // ����
	CSRTRImitation * pSRTRImitation;
	CSRTR          * pSRTR;  // ���
} Str_Ptr_Item;

typedef struct ParamForOutN036VV
{
//	int PrI; // ����� ���������
	unsigned PrI; // ����� ���������
//	int PrOI;// ������� ���������� ����������
	unsigned char PrOI;// ������� ���������� ����������
	double D; // ���������� ��������� �� ����
	double Vs;// ���������� �������� ��������� � �����
	double Az;// ���������� ���� ������� ����
//	float Um;// ���������� ���� ����� ����
	double Um;// ���������� ���� ����� ����
	unsigned Hour;// ����
	unsigned Min; // ������
	unsigned Sec; // �������
	double MSec;// ���� �������
	unsigned Nl; // ����� ���� ����������� �-036
//	int Nl; // ����� ���� ����������� �-036
//	int Kanal;// ����� X/L
	unsigned char Kanal;// ����� X/L
	unsigned char PrR; // ������� ��/���
//	int PrR; // ������� ��/���
	int RezGO;// ��������� ��
	int PrGO; // �������������� �������� ��
} ParamForOutN036VV;

typedef struct AllParamForOutN036VV
{
	int VV_X;    // ��������� ������ "������-������"
//	int No_zon_X;// ����� ���� ���-�
	ParamForOutN036VV Par[20];// ������ ����������
} AllParamForOutN036VV;

// This class is exported from the cMires.dll
class CMIRES_API cMires
{
public:
	cMires(type_CONTRL*);              // �� ������������ � cMires.dll
	cMires(DispInp*, strInputFromFPO*);// ������������ � cMires.dll

	virtual ~cMires();

	// ������� ��� ������������� ������ cMires. //////////////////////////////
	void RunRTR(double);   // ������ ������ ���.
	void RunGOcu(double);        // ������ ������ ��(��).
	void RunRadar(double); // ������ ������ ����.
	Str_Ptr* GetPtr( int init_pr );     // ������ ���������� �� ���������� ������� ������
	                       // ��� ��� �������������.
	void CleanPar();       // ���������� � ����� ����������.
	AllParamForOutN036VV ParVV;// �������� ���������.
	strPIV_L402_out* GetPIV_L402(); 
	//////////////////////////////////////////////////////////////////////////
	//////////// ��������� ������� ������ cMires /////////////////////////////
	int GetNTargVO();
	inline targets* GetTarget(){ return &Targ[0]; };
	Str_Ptr_Item* GetPtrToItem();
	//////////////////////////////////////////////////////////////////////////

private:
	Str_Ptr StrPtr;
	Str_Ptr_Item StrPtrItem;
	//////////// ���������� ������ cMires ////////////////////////////////////
	cGO    *GO;   // ��
	cRLK_X *Brls; // ����
	CSRTRImitation *SRTRImitation;
	CSRTR  *SRTR; // ���
	//////////////////////////////////////////////////////////////////////////
	type_CONTRL * CTRL; // ���������� ��������� ����������.
	DispInp *DI;        // ������� ��������� ����������.
	Str_InputH036 InputH036;  // ��������� ������� ���������� �-036
  Str_InputL402 InputL402;
	InputH121 InpH121;	      // ��������� ������� ���������� �-121
	OutputH121   OutH121;
	VhodPar VhParam;          // ������� ��������� ����.
	strOutputForFPO OutputForFPO;// �������� ���������� ��� ���.
	targets Targ[NC];// ��������� �����.
	str_Car Carrier; // ��������� ��������.
	Str_InMFI InMFI; // �������� ��������� ��� ��������� �� ���.
};
