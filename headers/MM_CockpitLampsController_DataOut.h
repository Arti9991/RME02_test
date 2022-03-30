#pragma once

#pragma pack(push, 1)
struct TMM_CockpitLampsController_DataOut
{
	// Данные от ModelCocpitAdapt	
	bool Ksc;					// Кнопка-лампа КСЦ ( 0 - не нажата ) +
	bool FireExtingL;			// Подсветка изображения огнетушителя (левого) +
	bool FireExtingC;			// Подсветка изображения огнетушителя (центрального) +
	bool FireExtingR;			// Подсветка изображения огнетушителя (правого) +

	// Данные от КСУ (для пульта КСУ) 0-не горит, 1-горит, 2-мигает
	BYTE Director;				// Режим ДИРЕКТОР +
	BYTE AutoPilot;				// Режим АВТОПИЛОТ +
	BYTE Altitude;				// Режим БАРОВЫСОТА	+
	BYTE Refuel;				// Режим ДОЗАПРАВКА +
	BYTE DamperSensitivity;		// Режим ДЕМПФЕР (чувствительность рулевого управления)
	BYTE Recover;					// Режим УВОД +
	BYTE TransformFail;			// Отказ трансформатора
	BYTE LhInletCheck;			// Отказ воздухозаборника, левый
	BYTE RhInletCheck;			// Отказ воздухозаборника, правый
	bool ExtendLg;				// Нет выпуска шасси
	bool Fire;					// Табло FIRE +
	bool DecelerateLh;			// Табло СБРОСЬ ОБОРОТЫ ЛЕВ +
	bool DoubleHydSys;			// Отказ гидросистемы
	bool SmallLimiter;			// Отказ системы ограничительных сигналов
	bool DecelerateRh;			// Табло СБРОСЬ ОБОРОТЫ ЛЕВ +
	bool Remain500;				// Осталось меньше 500 киллограмов
	bool Lsa;					// Отказ "АПУС"
	bool NotReadyForTakeOff;	// К ВЗЛЁТУ НЕ ГОТОВ -
	bool Damper;				// Демпфер отключён
	bool Ail;					// Отказ переключения элеронов
	bool SfTol;					// АРУ Взлет-Посадка
	bool SfRef;					// АРУ Дозаправка
	bool TurbStartCritCond;		// Турбостарт
	bool Armed;					// Взрыв +
	bool LhEngAb;				// Форсаж левого двигателя
	BYTE LhEngStart;			// Запуск левого двигателя +
	bool RhEngAb;				// Форсаж правого двигателя
	BYTE RhEngStart;			// Запуск правого двигателя +
	bool FeelUnitOk;			// АРУ исправно	
	bool Flash;					// Признак мигания
	

	// Debug & Reserve
	bool LampTest;				// Кнопка Контроль ламп ( 0 - не нажата ) + 
	// (чисто для отладки, тест ламп (мигание) проводится в модели)

	bool LampIsFlashing;		// Проблесковое состояние хотя бы одной лампы

	bool ReservLamp1;			// Резервная лампа №1 (зеленая)
	bool ReservLamp2;			// Резервная лампа №2 (зеленая)
	bool ReservLamp3;			// Резервная лампа №3 (желтая)


	// Выпилено (осталось с К или откуда-то с тех времен)
	// bool Levelling;				// Приведение к горизонту (priv_horiz_lp) - на UPG нет такой лампы на РУСе
	// bool BatGndSupLh;			// Переключатель Аккум. борт. аэродр. левый ( 0 - выключенное положение ) +
	// bool BatGndSupRh;			// Переключатель Аккум. борт. аэродр. правый ( 0 - выключенное положение ) +

};
#pragma pack(pop)