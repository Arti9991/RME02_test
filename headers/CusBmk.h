/*Драйвер CusBmk

ГосНИИАС
Гурвиц Александр Валерьевич
*/

#ifndef CusBmk_H
#define CusBmk_H

#include "CommonDef.h"

#if defined(CusBmk_DLL)
# define CusBmk     __declspec(dllexport)
#elif defined(CusBmk_APP)
# define CusBmk     __declspec(dllimport)
# else
# define CusBmk
#endif
//коды ошибок
#define  CusBmk_OK          0//ошибок нет
#define  CusBmk_CREATE      1//ошибка инициализации плат
#define  CusBmk_BAD_PARAM   2//неверные атрибуты параметра

#ifdef __cplusplus
extern "C"
{
#endif

//создание объектов управления платами 
//NumPC - код номера РС (NPC_IPC1,NPC_IPC2)
// Port - не используется
//возврат - количество найденных плат
CusBmk int __stdcall Create_CusBmk(int NumPC, int Port); 

//удаление объектов управления платами 
CusBmk void __stdcall Close_CusBmk(void);

//чтение одного параметра из платы 
//возврат 0-OK, -1 - ошибка задания параметра
CusBmk int __stdcall ReadData_CusBmk(ID_Parameter &Param);

//прием пакета параметров платой c номером NumCard
CusBmk void __stdcall Recv_CusBmk(int NumCard);

//получение кода последней ошибки
CusBmk int __stdcall GetLastError_CusBmk(void);

#ifdef __cplusplus
}
#endif
#endif
