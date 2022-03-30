#ifndef iMKIO_1_vb
#define iMKIO_1_vb

#pragma pack(push, 1)

#include "CommonDef.h"

const unsigned __int32 MKIO_OUMaxCount = 32;				//Максимальное количество ОУ на одной магистрали
const unsigned __int32 MKIO_BusCount = 2;					//Количество магистралей
//информация для настройки
struct iMKIO_1Info {
 unsigned __int32 Config; //Конфигурация блока мкио
 unsigned __int32 iMKIO_Batch[MKIO_OUMaxCount*MKIO_BusCount];	//Массив с моделируемыми ОУ на каждой шине. 1 - наличие моделрирования ОУ. 0 - отсутствие.
};
// 1 - Устройство подключено
// 0 - Устройство виртуальное 
//-1 - Блок не подключен(Нужно подключить блок к плате и включить включить его)
//-2 - Ошибки выделения памяти (Перезагрузить компьютер)
//-3 - Количество моделируемых ОУ больше 16
//-4 - Количество подменяемых ОУ больше 1
//-5 - Несоответствует конфигурация блока.
__int32 __stdcall  vbCreate_iMKIO_1(iMKIO_1Info & Info);
void __stdcall vbClose_iMKIO_1();
void __stdcall vbSend_iMKIO_1();
void __stdcall vbRecv_iMKIO_1();
void __stdcall vbPut_iMKIO_1(ID_Parameter & glob);
void __stdcall vbGet_iMKIO_1(ID_Parameter & glob);

#endif