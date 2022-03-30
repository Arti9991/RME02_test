#pragma once

#if defined(CalibrCtrl_DLL)
	#define CalibrCtrlDeclSpec __declspec(dllexport)
#elif defined(CalibrCtrl_APP)
	#define CalibrCtrlDeclSpec __declspec(dllimport)
#endif

namespace MIG29UPG
{

	//	������ ����������, ���������� ����������
	enum CalibrControls
	{
		CalibrControls_NULL	=	-1,	// �����������
		CC_Counter = 0,						// �������
		CC_DU_Tangage,						// ��_������
		CC_DU_Roll,								// ��_����
		CC_DU_Direction,					// ��_�����������
		CC_DOS_Tangage_1,					// ���_������_1
		CC_DOS_Tangage_2,					// ���_������_2
		CC_DOS_Roll_1,						// ���_����_1
		CC_DOS_Roll_2,						// ���_����_2
		CC_DOS_Direction_1,				// ���_�����������_1
		CC_DOS_Direction_2,				// ���_�����������_2
		CC_RUS_Roll,							// ���_����
		CC_RUS_Tangage,						// ���_������
		CC_Pedals,								// ������
		CC_RUD_left,							// ���_�����
		CC_RUD_right,							// ���_������
		CC_RUD_D,									// ���_�
		CC_unknown_1,							// �����������
		CC_AGR_Tangage,						// ���_������
		CC_ews_audio,							// ews_audio
		CC_dash_brtn,							// dash_brtn
		CC_msl_audio,							// msl_audio
		CC_dev_bright,						// �������_��������
		CC_KY,										// �������_y
		CC_KX,										// �������_x
		CC_unknown_2,							// �����������
		CC_brake,									// ������
		CC_emerg_brake,						// ���������_������
		CC_unknown_3,							// �����������
		CC_unknown_4,							// �����������
		CC_Ref_Voltage,						// ����_������
		CC_unknown_5,							// �����������
		CC_unknown_6,							// �����������
		CC_unknown_7,							// �����������
		CC_unknown_8,							// �����������
		CC_unknown_9,							// �����������
		CC_unknown_10,						// �����������

		CalibrControls_Last
	};

	//	������������� ���������� ���������� �������� ���29UPG 
	extern "C" CalibrCtrlDeclSpec bool __stdcall Init();
	//	�������� �������� ������� � ��������������� idCtrl (��. ��������� ����)
	extern "C" CalibrCtrlDeclSpec short __stdcall MakeCalibrCtrl(const CalibrControls idCtrl, const short int code);
	//	���������� ������ ����������
	extern "C" CalibrCtrlDeclSpec bool __stdcall Close();

}