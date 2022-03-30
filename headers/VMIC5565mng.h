/*Драйвер VMIC5565mng

ГосНИИАС
Гурвиц Александр Валерьевич
*/

#ifndef VMIC5565mng_H
#define VMIC5565mng_H

#include "CommonDef.h"

#if defined(VMIC5565mng_DLL)
# define VMIC5565MNG     __declspec(dllexport)
#elif defined(VMIC5565mng_APP)
# define VMIC5565MNG     __declspec(dllimport)
# else
# define VMIC5565MNG
#endif
//коды ошибок
#define  VMIC5565mng_OK          0//ошибок нет
#define  VMIC5565mng_CREATE      1//ошибка инициализации плат
#define  VMIC5565mng_BAD_PARAM   2//неверные атрибуты параметра

#ifdef __cplusplus
extern "C"
{
#endif

//создание объектов управления платами 
//NumPC - код номера РС (NPC_IPC1,NPC_IPC2)
//возврат - количество найденных плат
VMIC5565MNG int __stdcall Create_VMIC5565(int NumPC, ULONG SizeEmulMem); //запрашиваемый размер памяти для эмуляции

//удаление объектов управления платами 
VMIC5565MNG void __stdcall Close_VMIC5565(void);

//запись одного параметра в плату 
//возврат 0-OK, -1 - ошибка задания параметра
VMIC5565MNG int __stdcall WriteData_VMIC5565(ID_Parameter Param);

//чтение одного параметра из платы 
//возврат 0-OK, -1 - ошибка задания параметра
VMIC5565MNG int __stdcall ReadData_VMIC5565(ID_Parameter &Param);

//получение кода последней ошибки
namespace  __VMIC5565mng {
VMIC5565MNG int __stdcall GetLastError_VMIC5565(void);
}

#ifdef __cplusplus
}
#endif
#endif
