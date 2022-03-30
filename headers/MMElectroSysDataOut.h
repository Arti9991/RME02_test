#pragma once

//
#pragma pack(push,1) //������������ ����� �������� ������ ���� �� 1 ����
//

//	��������� ������� �������� ���� ����������� ����
enum _ENERGY_SYSTEM_DC_STATE
{
	_ENERGY_SYSTEM_DC_OFF = 0,				//	��� ����������
	_ENERGY_SYSTEM_DC_ACCUMULATOR,		//	������� �� �������� ���������� (�������������)
	_ENERGY_SYSTEM_DC_SHRAP,					//	������� �� ��������� ���������
	_ENERGY_SYSTEM_DC_GENERATOR,			//	������� �� ���������� ���
	_ENERGY_SYSTEM_DC_VU							//	������� �� ��������������� ���������� (��)
};

//	��������� ������� �������� ���� ����������� ����
enum _ENERGY_SYSTEM_AC_STATE
{
	_ENERGY_SYSTEM_AC_OFF = 0,				//	��� ����������
	_ENERGY_SYSTEM_AC_SHRAP,					//	������� �� ��������� ���������
	_ENERGY_SYSTEM_AC_GENERATOR,			//	������� �� ���������� ��
	_ENERGY_SYSTEM_AC_INV						  //	������� �� ��������������� (���)

};

enum _INV_AC_STATE
{
	_INV_AC_STATE_OFF = 0,
	_INV_AC_STATE_STARTING,
	_INV_AC_STATE_STABLE
};



//	��������� �������� ������ ������� ������
struct TMMElectroSysDataOut
{
	bool bPowerARU;   		//	���. ���
	bool bPowerSOS;   		//	���  ���
	bool bPowerVLO;				//	���. ���
	bool bPowerSVS;   		//	���. ���
	bool bPowerRV;    		//	���. �������������� (RAM - 1701AC)
	bool bPowerSAU;   		//	���. ���
	bool bPowerENGL;  		//	���. ���������� ������
	bool bPowerENGR;  		//	���. ���������� �������
	bool bPowerKUTR;  		//	���. ����
	bool bPowerFuelGuageUnit;	//	���. ������������� ������� ����
	bool bPowerINP;   		//	���  ��������� ������������-�������� (���-��)
	bool bPowerAGR;   		//	���. ������������
	bool bPowerINS1;			//	���. Totem3000-1
	bool bPowerINS2;			//	���. Totem3000-2
	bool bPowerEkran;			//	���. ������ (�����)
	bool bPowerPUI;				//	���. ���
	bool bPowerILS;				//	���. ��� (���)
	bool bPowerMFIL;			//	���. ��� ���.
	bool bPowerMFIR;			//	���. ��� ����.
	bool bPowerRI;				//	���. �� ��-2�
	bool bPower833_1;			//	���. �-833-1
	bool bPower833_2;			//	���. �-833-2
	bool bPower098;				//	���. �-098-5�
	bool bPowerIFF;				//	���. ���������-�������� TSC-2525
	bool bPowerRWR;				//	���. RWR Tarang-1B
	bool bPowerRLS;				//	���. ��� ���-�� FGM-229
	bool bPowerOLS;			 	//	���. ���
	bool bPowerSUO;				//	���. ���-29��
	bool bPowerCMDS;			//	���. 20���-01�
	bool bPowerBSBP;			//	���. ������� ������������ ������
	bool bPowerDVRS;			//	���. ������� ����������������(���) RADA
	bool bPowerTacan;			//	���. Tacan
	bool bPowerVORILSMKR;	//	���. VOR/ILS/MKR
	bool bPowerDASH;			//	���. ��������� ������� ������������
	bool bPowerACMI;			//	���. ��������� ACMI
	bool bPowerSeat1;			//	������� �� ������ �1
	bool bPowerVSS;				//	���. ������� ��������� ������������ � �������� �����
	bool bAvarShina27V;		//	������ �� ��������� ����	(bEmergShina ???)
	bool bMainShina;			//	������ �� �������� ����	(???)
	bool bGenPerem;				//	��������� ~ ���� (bACGen)
	bool bGenPost;				//	��������� = ���� (bDCGen)
	bool bDCSysIsOk;			//	������ ���� ���� ����
	bool bPowerSPJ;				//	���. C������ ���������� �������� ����� ����� (SPJ)
	bool bPowerOxygenSys;	//	������� ����������� �������
	bool bPowerVRS;				//	���. ���

	bool bPower27;				// ������� ������� ����������� ���� 27�
	bool bPower36;				// ������� ������� ����������� ���� 36� 400��
	bool bPower115;				// ������� ������� ����������� ���� 115� 400��
	bool bPowerLight;			//	������� �� ���������������� ������������
	bool bPowerMC1;				//	���. ����1
	bool bPowerMC2;				//	���. ����1
	bool bPowerTV_CSU;		//	���. ���� (���� ���������� ��-�������� �� ���)
	bool bPowerADAC;			//	���. ���-80
	bool bPowerUCP;				//	���. ��� (������������ ����� ���������� ��������������)

	BYTE btAccumCapacity;	// ������� �����. ������� (�*�)			
	float fDCVoltage;			// ��������� ����������� ����, �	
	BYTE btACVoltage;			// 100���������� ����������� ���� (0-115 �)

	bool bACGen;					// ������� ������ ���������� ����������� ����					(bPowerOfACGen)
	bool bACShrap;				// ������� ������ �� �����. ���. ~ ���� (����-400-3�)	(bPowerOfACAirdrom)
	bool bACInv;					// ������� ~ ���� �� ���
	bool bDCGen;					// ������� ������ ���������� ����. ����								(bPowerOfDCGen)
	bool bDCShrap;				// ������� ������ �� �����. ���. = ���� (����-500�)		(bPowerOfDCAirdrom)
	bool bDCVu;						// ������� = ���� �� ��-6
	bool bAccumBat;				// ������� �� �����. �������													(bPowerOfAccum)
	
	bool bPowerFullUnits;	// ���� ������ ������������
	bool bTransformPower;   // ������ ��������������
	bool bRectifierFail;    // ����� ��������������� ���������� (��)

	bool bElectricBus1;			// ������� �� ������������ ���� �1 
	bool bElectricBus2;			// ������� �� ������������ ���� �2
	bool bElectricBus3;			// ������� �� ������������ ���� �3
	bool bElectricBus4;			// ������� �� ������������ ���� �4
	bool bElectricBus5;			// ������� �� ������������ ���� �5   (�� ��� ?)
	bool bElectricBus6;			// ������� �� ������������ ���� �6
	bool bElectricBus7;			// ������� �� ������������ ���� �7
	
	float fDCVoltageDelta;  // ������� ���������� ��� ��������� ���
	float fDCVoltageMin;
	
	_ENERGY_SYSTEM_DC_STATE	iStateDC;		//	��������� ������� ����������� ����
	_ENERGY_SYSTEM_AC_STATE	iStateAC;		//	��������� ������� ����������� ����

	_INV_AC_STATE iStateINV;						//	��������� ������ ���
};

#pragma pack(pop)