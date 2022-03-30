#pragma once

#if defined(CalibrCtrl_DLL)
	#define CalibrCtrlDeclSpec __declspec(dllexport)
#elif defined(CalibrCtrl_APP)
	#define CalibrCtrlDeclSpec __declspec(dllimport)
#endif

namespace MIG29UPG
{

	//	Органы управления, подлежащие таррировке
	enum CalibrControls
	{
		CalibrControls_NULL	=	-1,	// неизвестный
		CC_Counter = 0,						// Счетчик
		CC_DU_Tangage,						// ДУ_ТАНГАЖ
		CC_DU_Roll,								// ДУ_КРЕН
		CC_DU_Direction,					// ДУ_НАПРАВЛЕНИЕ
		CC_DOS_Tangage_1,					// ДОС_ТАНГАЖ_1
		CC_DOS_Tangage_2,					// ДОС_ТАНГАЖ_2
		CC_DOS_Roll_1,						// ДОС_КРЕН_1
		CC_DOS_Roll_2,						// ДОС_КРЕН_2
		CC_DOS_Direction_1,				// ДОС_НАПРАВЛЕНИЕ_1
		CC_DOS_Direction_2,				// ДОС_НАПРАВЛЕНИЕ_2
		CC_RUS_Roll,							// РУС_КРЕН
		CC_RUS_Tangage,						// РУС_ТАНГАЖ
		CC_Pedals,								// ПЕДАЛИ
		CC_RUD_left,							// РУД_левый
		CC_RUD_right,							// РУД_правый
		CC_RUD_D,									// РУД_Д
		CC_unknown_1,							// Неизвестный
		CC_AGR_Tangage,						// АГР_ТАНГАЖ
		CC_ews_audio,							// ews_audio
		CC_dash_brtn,							// dash_brtn
		CC_msl_audio,							// msl_audio
		CC_dev_bright,						// ЯРКОСТЬ_приборов
		CC_KY,										// Кнюпель_y
		CC_KX,										// Кнюпель_x
		CC_unknown_2,							// Неизвестный
		CC_brake,									// Тормоз
		CC_emerg_brake,						// Аварийный_тормоз
		CC_unknown_3,							// Неизвестный
		CC_unknown_4,							// Неизвестный
		CC_Ref_Voltage,						// Опор_напряж
		CC_unknown_5,							// Неизвестный
		CC_unknown_6,							// Неизвестный
		CC_unknown_7,							// Неизвестный
		CC_unknown_8,							// Неизвестный
		CC_unknown_9,							// Неизвестный
		CC_unknown_10,						// Неизвестный

		CalibrControls_Last
	};

	//	Инициализация библиотеки таррировки датчиков МКС29UPG 
	extern "C" CalibrCtrlDeclSpec bool __stdcall Init();
	//	Пересчет значения датчика с идентификатором idCtrl (см. константы выше)
	extern "C" CalibrCtrlDeclSpec short __stdcall MakeCalibrCtrl(const CalibrControls idCtrl, const short int code);
	//	Завершение работы библиотеки
	extern "C" CalibrCtrlDeclSpec bool __stdcall Close();

}