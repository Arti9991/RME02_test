#ifndef COVER_VMIPCI5565_H
#define COVER_VMIPCI5565_H

#if defined(COVER_VMIPCI5565_DLL)
# define COVER_VMIPCI5565     __declspec(dllexport)
#elif defined(COVER_VMIPCI5565_APP)
# define COVER_VMIPCI5565     __declspec(dllimport)
# else
# define COVER_VMIPCI5565
#endif


#ifdef __cplusplus
extern "C"
{
#endif

//создание объекта
COVER_VMIPCI5565 void __stdcall Create_COVER_VMIPCI5565(ULONG   SizeEmulMem = SIZE_BAR3_64M_5565); //запрашиваемый размер памяти для эмуляции
//удаление объекта
COVER_VMIPCI5565 void __stdcall Close_COVER_VMIPCI5565();


//поиск Pci платы с номером NumBrd(с 1),
//устанавливает транслированные адреса BaseAddr0, BaseAddr1,
//и IrqL, PCIBusMumber, DeviceMumber для найденной платы
//Возврат - количество найденных плат (с 1)
COVER_VMIPCI5565 int __stdcall ScanPciBoard_COVER_VMIPCI5565(int NumBrd, ULONG & BaseAddr0, ULONG & BaseAddr1, ULONG & BaseAddr2, ULONG & BaseAddr3,
                             UCHAR & IrqL, ULONG & PCIBusMumber,ULONG & DeviceMumber);

// Инициализация платы.
// при необнаружении плат область памяти эмулируется в системной памяти.
// Возврат true-успешно, false-неуспешно
// если без прерывания, то pRoutine=NULL
COVER_VMIPCI5565 bool __stdcall InitBoard_COVER_VMIPCI5565(ULONG BaseAddrPIO,ULONG BaseAddrMem, ULONG BaseAddr2, ULONG BaseAddr3,
                UCHAR IrqL, BOOLEAN (RTFCNDCL *pRoutine)(PVOID context), ULONG BusMumber);


//запись в память по смещению Offset данных из buf размером Size
//В ПРЕДЕЛАХ  START_RAM - SIZE_RAM
COVER_VMIPCI5565 void __stdcall WriteMemory_COVER(PUCHAR buf, ULONG Offset, ULONG Size);
//чтение из памяти по смещению Offset данных в buf размером Size
//В ПРЕДЕЛАХ  START_RAM - SIZE_RAM
COVER_VMIPCI5565 void __stdcall ReadMemory_COVER(PUCHAR buf, ULONG Offset, ULONG Size);

//запись в память по смещению Offset переменной UCHAR
COVER_VMIPCI5565 void __stdcall WriteChar_COVER(UCHAR c, ULONG Offset);
//чтение из памяти по смещению Offset переменной UCHAR
COVER_VMIPCI5565 UCHAR __stdcall ReadChar_COVER(ULONG Offset);

//запись в память по смещению Offset переменной USHORT
COVER_VMIPCI5565 void __stdcall WriteShort_COVER(USHORT s, ULONG Offset);
//чтение из памяти по смещению Offset переменной USHORT
COVER_VMIPCI5565 USHORT __stdcall ReadShort_COVER(ULONG Offset);

//запись в память по смещению Offset переменной ULONG
COVER_VMIPCI5565 void __stdcall WriteLong_COVER(ULONG l, ULONG Offset);
//чтение из памяти по смещению Offset переменной ULONG
COVER_VMIPCI5565 ULONG __stdcall ReadLong_COVER(ULONG Offset);

// Генерация прерывания в другом узле RMN
// параметры:
// DestNId - NID узла, в котором надо сгенерировать прерывание
// GlobalINT - сгенерировать прерывание во всех узлах сразу
// Type_INT - Тип прерывания, которое надо сгенерировать
//              (GEN_INT1 или GEN_INT2 или GEN_INT3 или GEN_INT_RESET)
// INT_DATA - ДАННЫЕ, посылаемые с прерыванием
COVER_VMIPCI5565 void __stdcall GenerateInterrupt_COVER(UCHAR DestNId, BOOL GlobalINT, UCHAR Type_INT, USHORT INT_DATA);

// Разрешение генерации прерывания в узле RMN
// параметры:
// Type_En_INT - Тип прерываний, которые можно сгенерировать на узле
//           (EN_INT1 и/или EN_INT2 и/или EN_INT3 и/или EN_INT_RESET или DISABLE_INT)
COVER_VMIPCI5565 void __stdcall EnableInterrupt_COVER(UCHAR Type_En_INT);

// ###############  процедуры для обработчика прерывания #######################

// определение причины прерывания.
// должно выполняться вначале обработчика прерывания.
// возвращается Значение INTCSR Interrupt Control and Status для сравнения с
// INCOMING_MAIL_BOX_INT.
// Если этот бит установлен, то это прерывание от платы, иначе - от другого источника
COVER_VMIPCI5565 ULONG __stdcall IsMyInterrupt_COVER(void);

//получение информации о прерывании типа 1,2,3
// в SenderID возвращается NID узла, который сгенерировал прерывание
// в IntFlag  возвращаются флаги прерывания:
//              бит 6=1  -прерывание Глобальное для всех узлов (см. GenerateInterrupt)
//              биты 3-0 -тип прерывания - INT1/INT2/INT3 (см. GenerateInterrupt)
// в IntData  возвращаются ДАННЫЕ, посылаемые с прерыванием (см. GenerateInterrupt)
COVER_VMIPCI5565 void __stdcall GetInt1Info_COVER(UCHAR &SenderID, ULONG &IntData);
COVER_VMIPCI5565 void __stdcall GetInt2Info_COVER(UCHAR &SenderID, ULONG &IntData);
COVER_VMIPCI5565 void __stdcall GetInt3Info_COVER(UCHAR &SenderID, ULONG &IntData);

//размаскирование прерывания.
//должно выполняться в конце обработчика прерывания.
COVER_VMIPCI5565 void __stdcall UnMaskInterrupt_COVER(void);

// Получение времени задержки прохождения данных по кольцу сети
// возвращается время задержки в 100нс единицах или
// RING_IS_BREAK, если Кольцо сети разорвано или один из модулей обесточен
COVER_VMIPCI5565 long __stdcall GetLatency_COVER_VMIPCI5565(void);

#ifdef __cplusplus
}
#endif
#endif