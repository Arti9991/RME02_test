
//-----------------------------------------------------------------------------
//			Результат работы функции
//-----------------------------------------------------------------------------
#define SUCCESS 0							// Успешно

#define ERROR_DEVICE_NOT_FIND -1			// Ошибка ф-ции Create_PCIxyzDAC (Устройство не найдено)
#define ERROR_ENABLE_REG_IO_FAIL -2			// Ошибка ф-ции Create_PCIxyzDAC (Нет доступа к регистрам устройства)
#define ERROR_NUM_DEV -3					// Ошибка ф-ции Create_PCIxyzDAC (Количество однотипных устройств > 8)

#define ERROR_ANOTHER_TYPE_DEVICE -4		// Ошибка ф-ции Put_PCIxyzDAC (Задано другое устройство)
#define ERROR_NUM_DEVICE -5					// Ошибка ф-ции Put_PCIxyzDAC (Нумерация однотипных устройств должна быть с 1, а не с 0)
#define ERROR_NUM_CHANNEL -6				// Ошибка ф-ции Put_PCIxyzDAC (Нумерация каналов в БД должна быть с 1, а не с 0)
#define ERROR_BUS_NUM_0 -8					// Ошибка ф-ции Put_PCIxyzDAC (Адрес в таблице по серийному номеру устройства равен 0)
#define ERROR_DISABLE_PORT_IO_FAIL -7		// Ошибка ф-ции Close_PCIxyzDAC (Доступ к регистрам устройства не закрыт)

//-----------------------------------------------------------------------------
//			Внешние функции
//-----------------------------------------------------------------------------
short __stdcall Create_PCIxyzDAC (DeviceResources SN[], short NumDev);		// Открыть доступ к устройству (успешно - возвращается номер найденного Dev = NumDev)
short __stdcall Put_PCIxyzDAC (ID_Parameter & InParam);							// Передача параметра
void __stdcall Close_PCIxyzDAC (void);					// Закрытие

unsigned long __stdcall ReadTimer_PCIxyzDAC (ULONG InNumDevice);						// Чтение счетчика
void		  __stdcall ClearTimer_PCIxyzDAC (ULONG InNumDevice);						// Обнуление счетчика

// Замечание: Нумерация одинаковых устройств в БД начинается с 1 (1 - первое устройство)
//			  Нумерация каналов в устройстве в БД начинается с 1 (1 - первый канал)