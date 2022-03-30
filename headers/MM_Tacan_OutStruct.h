/************************************************************************************
*																					*
*	Создан:		18.05.2011															*
*	Изменен:																		*
*	Файл:		out_struct.h														*
*	Автор:		Разгуляев В.Г.														*
*	Описание:	Выходная структура модели											*
*																					*
*************************************************************************************/

#pragma once

#pragma pack(push,1)

// Выходная структура бортового протокола
struct BORT_TACAN_OUT{
	struct {
		unsigned char IBIT_FAULT;				// 1 - Отказ IBIT, имеет значение только если IBIT_IB_PROGRESS = 0
		unsigned char IBIT_IN_PROGRESS; // 1 - процесс; 0 - IBIT_VALID
		unsigned char IBIT_STATUS;			// 1 - IBIT уже проведен
	} TACAN_IBIT_RESULT;	// Результат инициированного ВСК

	struct {
		struct{
			unsigned char DYNAMIC_MEMORY_DISTANCE;	// Интервал динамической памяти(он же достоверность дальности) выдается еще в течение 10 секунд после потери маяка
			unsigned char DYNAMIC_MEMORY_BEARING;		// Азимут динамической памяти, выдается еще в течение 15 секунд после потери маяка
			unsigned char DISTANCE;									// Достоверность интервала
			unsigned char BEARING;									// Достоверность пеленга
			unsigned char TIME_TO_VALIDITY;					// Достоверность остатка времени полета
			unsigned char LAMMING;									// Постановка помех
		} DISTANCE_BEARING_TIME_VALID;

		double DISTANCE;							// Наклонная дальность до маяка(выдается последнее принятое значение)	[ММ]
		double QDM;										// магнитный азимут на маяк (выдается последнее принятое значение)		[рад]
		unsigned long TIME_TO_GO;			// оставшееся время полета(пока не вычисляется)							[сек]

		struct {
			unsigned char X_MODE;
			unsigned char Y_MODE;
			unsigned char REC;
			unsigned char TR;
			unsigned char AA;
		} CHANNEL_TYPE_RETURN;						// Тип канала и режим работы

		short CHANNEL_NO_RETURN;					// Номера канала на который настроены
	}TACAN_DATA;

	struct {
		struct {
			unsigned char CPU_CLOCK_FAILURE;					// отказ синхронизатора блока CPU
			unsigned char RANGE_PROCESSOR_FAILURE;		// отказ процессора дальности
			unsigned char RECEIVER_FAILURE;						// отказ приемника
			unsigned char TRANSMITTER_FAILURE;				// отказ передатчика
			unsigned char VCWR_FAILURE;								// отказ КСВН
		} TEST_FAULTS;
		struct {
			unsigned char EERPOM_CHECK;								// проверка ЭСППЗУ
			unsigned char _1553_ACE_RAM_FAILURE;			// отказ ОЗУ 1553 ACE
			unsigned char _1553_ACE_REGISTER_FAILURE;	// отказ регистра 1553 ACE
		} PRICESSOR_FAULTS;
	} TACAN_CBIT;
	unsigned short TACAN_DATA_WRAP_AROUND_OUT[32];			// циклический возврат данных от TACAN в БЦВМ
};

//	Выходная структура для моделируемых блоков
struct BLOCKS_TACAN_OUT
{
	char beacon_calling[4];						// Позывные (TACAN дает трехбуквенные позывные плюс символ конца строки) (имитация блока МС2М)
	bool bIsLinked;										// признак наличия взаимодействия с  маяком(он же признак играть позыные) (имитация блока МС2М)
};

//	Выходная стурктура ММ TACAN
struct TACAN_OUT_STRUCT{
	BORT_TACAN_OUT ToBCMV;						// структура бортового протокола

	BLOCKS_TACAN_OUT ToMM;						// выход на другие ММ
};

#pragma pack(pop)