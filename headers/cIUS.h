// cIUS.h: interface for the cIUS class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIUS_H__5550B4E0_2765_47AC_B568_EB008389AB75__INCLUDED_)
#define AFX_CIUS_H__5550B4E0_2765_47AC_B568_EB008389AB75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define NAC   8     // ����������� ������� ������� �����.
#define Stend 1

#if(Stend > 0)
#include <winsock.h>
#pragma comment (lib, "ws2_32.lib")
#include <io.h>
#endif

#define  tuNtipMax    15 // ������������ ����� ����� ������ 
#define  tuNvarMax     5 // ������������ ����� ��������� ������ 
#define  tuNPartZapr  19 // ���-�� ��������� ������� ��������� �������� 

class cMires;
struct Str_InMFI;

template<class TYPE, class ARG_TYPE> class CList;

struct type_CZO_S
{ 
  float EGC;  // ������������ �� �������.
  float EVC;  // ������������ �� ���� �����.
  float Eg_z; // ������������ �� �������.
  float Ev_z; // ������������ �� ���� �����.
  int   IPr_cy;
};

struct targets;
struct Str_Ptr;

class cIUS
{
public:
	BOOL Play;
  cIUS(cMires*, DispInp*, InterfaceIntegraph*);
  virtual ~cIUS();

  void Disp(double);
  void Disp_KPM21i( double ); 

  void Vhod_KTU();       // ������� ���������� ��� ���� ��� (tucom)
  void Vhod_SH121();       // �������� ���������� ��� �-121 (��, ��� ��������� �� ����)
  void Vhod_KGS();       // ������� ���������� ��� ���

private:
  InterfaceIntegraph* pIIExternal;// ��������� �� ��������� ���������� �������� ���.
  InputH121*          pInpH121;
  Str_InputH036*      pInputH036;// ��������� ������� ���������� �-036
  VhodPar*            pVhParam;
  Str_InputL402*      pInputL402;
  InterfaceIntegraph MyMFI; // ��������� ������� ����������
  InterfaceIntegraph* pMyMFI;
  Str_Ptr *pFromMires;
  void PRCZ(double, double, double *, double *);
  void Input(InterfaceIntegraph*);
  
  void Send_To_Imitator_MFI( double Ttek );

// ��� ������ �� ���-21�
  void Input_KPM21i(InterfaceIntegraph* pOrg_Upr);
  void Knup_KPM21i(double Ttek);
  void Map_KPM21i();	
  void NICZO1();

  DispInp * pDisp;
  double  Dlx;    // ������ ���� ��������� ����� �� �
  double  dtt;
  double  Tknup;
  double  Tzkn;
  int     Lxz[3];
  int     Lyz[3];
  int     Masht;
  int     Lmfk;
  int     Pr_Nexit;
  int   P1vhVP;   // ������� ������� ����� � ����� �_� ��� ������ ����������
  int   P1vhUpr;  // ������� ������� ����� � �������� ������. �����
  int     Nf;
  int	decimator;// ������������� ������ ��������� ���
  DispInp *pDispInp;
  str_Car *pCarrier;
  targets *ptarg;
  type_CZO_S CZO;
  float egmn, evmn, egmx, evmx;
  cMires* pMires;
  Str_InMFI *pInMFI;
#if(Stend > 0)
  // ��� ������ �� ������� ��������
// ��� ��Ȩ�� ������ � ���
  HANDLE hEventIntgr;     // ��� ������������� � ��������� ���������
  SOCKET S_Intgr;       // ���������� �����
  SOCKET S_Intgr_A;     // ��������� ����������, ����� ���������� 
  STARTUPINFO Si_MFI;     // 
  PROCESS_INFORMATION Pi_MFI; // 
// ��� ������� ������ �� ���
  SOCKET SendMFI;       // ��� ������� �������������� ���������� �� ���
  HANDLE hEvent1,hEvent2;   // hEvent1 - ��� ����������� hEvent2 - ��� ����� ������
  HANDLE hMapFile;      // ��������� �� ����������� ������� ������
  HANDLE hEventIntgrRRV;
  HANDLE hEventIntgrRec;
  PVOID pBuf;
#endif
};

#endif // !defined(AFX_CIUS_H__5550B4E0_2765_47AC_B568_EB008389AB75__INCLUDED_)
