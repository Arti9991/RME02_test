#pragma once

#pragma pack(push, 1)
struct TMM_CockpitLampsController_DataOut
{
	// ������ �� ModelCocpitAdapt	
	bool Ksc;					// ������-����� ��� ( 0 - �� ������ ) +
	bool FireExtingL;			// ��������� ����������� ������������ (������) +
	bool FireExtingC;			// ��������� ����������� ������������ (������������) +
	bool FireExtingR;			// ��������� ����������� ������������ (�������) +

	// ������ �� ��� (��� ������ ���) 0-�� �����, 1-�����, 2-������
	BYTE Director;				// ����� �������� +
	BYTE AutoPilot;				// ����� ��������� +
	BYTE Altitude;				// ����� ����������	+
	BYTE Refuel;				// ����� ���������� +
	BYTE DamperSensitivity;		// ����� ������� (���������������� �������� ����������)
	BYTE Recover;					// ����� ���� +
	BYTE TransformFail;			// ����� ��������������
	BYTE LhInletCheck;			// ����� ����������������, �����
	BYTE RhInletCheck;			// ����� ����������������, ������
	bool ExtendLg;				// ��� ������� �����
	bool Fire;					// ����� FIRE +
	bool DecelerateLh;			// ����� ������ ������� ��� +
	bool DoubleHydSys;			// ����� ������������
	bool SmallLimiter;			// ����� ������� ��������������� ��������
	bool DecelerateRh;			// ����� ������ ������� ��� +
	bool Remain500;				// �������� ������ 500 �����������
	bool Lsa;					// ����� "����"
	bool NotReadyForTakeOff;	// � ��˨�� �� ����� -
	bool Damper;				// ������� ��������
	bool Ail;					// ����� ������������ ��������
	bool SfTol;					// ��� �����-�������
	bool SfRef;					// ��� ����������
	bool TurbStartCritCond;		// ����������
	bool Armed;					// ����� +
	bool LhEngAb;				// ������ ������ ���������
	BYTE LhEngStart;			// ������ ������ ��������� +
	bool RhEngAb;				// ������ ������� ���������
	BYTE RhEngStart;			// ������ ������� ��������� +
	bool FeelUnitOk;			// ��� ��������	
	bool Flash;					// ������� �������
	

	// Debug & Reserve
	bool LampTest;				// ������ �������� ���� ( 0 - �� ������ ) + 
	// (����� ��� �������, ���� ���� (�������) ���������� � ������)

	bool LampIsFlashing;		// ������������ ��������� ���� �� ����� �����

	bool ReservLamp1;			// ��������� ����� �1 (�������)
	bool ReservLamp2;			// ��������� ����� �2 (�������)
	bool ReservLamp3;			// ��������� ����� �3 (������)


	// �������� (�������� � � ��� ������-�� � ��� ������)
	// bool Levelling;				// ���������� � ��������� (priv_horiz_lp) - �� UPG ��� ����� ����� �� ����
	// bool BatGndSupLh;			// ������������� �����. ����. ������. ����� ( 0 - ����������� ��������� ) +
	// bool BatGndSupRh;			// ������������� �����. ����. ������. ������ ( 0 - ����������� ��������� ) +

};
#pragma pack(pop)