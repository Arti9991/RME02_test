/************************************************************************************
*																					*
*	Создан:		18.05.2011															*
*	Изменен:																		*
*	Файл:		in_struct.h															*
*	Автор:		Разгуляев В.Г.														*
*	Описание:	Входная структура модели											*
*																					*
*************************************************************************************/

#pragma once

#pragma pack(push,1)

// Продолжительность IBIT 3 сек

// Входная структура бортового протокола (общение с контроллером)
struct BORT_TACAN_IN{
	struct {
		unsigned char IBIT_IN; // 1 - START_IBIT, 0 - остановить контроль
	}TACAN_IBIT_IN;	// Инициализация инициированного ВСК
	struct {
		struct {
			unsigned char X_MODE;											//
			unsigned char Y_MODE;											//
			unsigned char REC;												// Режим радиомолчания(только азимут)
			unsigned char TR;													// Режим прием-передача
			unsigned char AA;													// Режим воздух-воздух
		}CHANNEL_TYPE;															// 1 - активно
		unsigned char CHANNEL_NUM;									// Номер канала
	}TACAN_CHANNEL_SELECT;												// Выбор канала TACAN
	unsigned short TACAN_DATA_WRAP_AROUND_IN[32];	// циклический возврат данных от БЦВМ в TACAN
};

//	Входная структура от моделируемых блоков
struct BLOCKS_TACAN_IN
{
	bool bPower;								// наличие питания (имитация блока питания) (1 - питание есть)
	double air_latitude;				// широта самолета (имитация блока антенны) [рад] (-PI ... PI)
	double air_longitude;				// долгота самолета (имитация блока антенны) [рад] (-PI ... PI)
	double air_heigth;					// высота самолета над уровнем моря (имитация блока антенны) [м]
};

// Входная структура ММ TACAN
struct TACAN_IN_STRUCT{
	BORT_TACAN_IN From_BCVM;		//	выход на бортовой интерфейс

	BLOCKS_TACAN_IN	From_MM;		//	выход на другие ММ

	// Данные для режима "воздух-воздух"
	// Координаты цели
	// Номер канала на который настроена
};

#pragma pack(pop)