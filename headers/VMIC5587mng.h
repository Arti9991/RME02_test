/*Драйвер VMIC5587mng

ГосНИИАС
Гурвиц Александр Валерьевич
*/

#ifndef VMIC5587mng_H
#define VMIC5587mng_H

#include "CommonDef.h"

#if defined(VMIC5587mng_DLL)
# define VMIC5587MNG     __declspec(dllexport)
#elif defined(VMIC5587mng_APP)
# define VMIC5587MNG     __declspec(dllimport)
# else
# define VMIC5587MNG
#endif
//коды ошибок
#define  VMIC5587mng_OK          0//ошибок нет
#define  VMIC5587mng_CREATE      1//ошибка инициализации плат
#define  VMIC5587mng_BAD_PARAM   2//неверные атрибуты параметра

#ifdef __cplusplus
extern "C"
{
#endif

//создание объектов управления платами 
//NumPC - код номера РС (NPC_IPC1,NPC_IPC2)
//возврат - количество найденных плат
VMIC5587MNG int __stdcall Create_VMIC5587(int NumPC);

//удаление объектов управления платами 
VMIC5587MNG void __stdcall Close_VMIC5587(void);

//запись одного параметра в плату 
//возврат 0-OK, -1 - ошибка задания параметра
VMIC5587MNG int __stdcall WriteData_VMIC5587(ID_Parameter Param);

//чтение одного параметра из платы 
//возврат 0-OK, -1 - ошибка задания параметра
VMIC5587MNG int __stdcall ReadData_VMIC5587(ID_Parameter &Param);

//получение кода последней ошибки
namespace  __VMIC5587mng {
VMIC5587MNG int __stdcall GetLastError_VMIC5587(void);
}

#ifdef __cplusplus
}
#endif
#endif
