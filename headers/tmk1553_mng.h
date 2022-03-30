#ifndef TMK1553MNG_H
#define TMK1553MNG_H

//#include "d:\alex\karat\common\CommonDef.h"
//#include "\\DELL\e\@kssr\@common\CommonDef.h"

#include "CommonDef.h"
//#include "CommonDef.h"

#if defined(TMK1553MNG_DLL)
# define TMK1553MNG     __declspec(dllexport)
#elif defined(TMK1553MNG_APP)
# define TMK1553MNG     __declspec(dllimport)
# else
# define TMK1553MNG
#endif

//коды ошибок
//определены в tmk1553.h
//TX_OK
//TX_BAD_PARAMS
//TX_NOT_FOUND_OR_ALREADY_LOADED
//TX_LOAD_ERROR
//TX_INIT_ERROR
//TX_TEST_ERROR
//TX_INIT_PORT_ERROR
//TX_INIT_IRQL_ERROR
#define  ERR_1553MNG_BAD_PARAM 256       //неверные атрибуты параметра
#define  ERR_1553MNG_BAD_BOARD_MODE 512  //неверный режим платы

#define SizeTlmBuf	24//размер бефера (в сообщениях) для регистрации ТЛМ сообщений по 34*2 байт каждый

#ifdef __cplusplus
extern "C"
{
#endif

//создание объектов управления платами TMK1553
//DeviceResources d[] - массив ресурсов платы
//NumDevice - количество плат
//NumPC - код номера РС (NPC_IPC1,NPC_IPC2)
//TMK1553INFO info[] - массив для настройки плат TMK1553
//возврат - количество найденных плат  из числа запрошенных
TMK1553MNG int __stdcall Create_tmk1553(DeviceResources d[], int MaxNumDevice,int NumPC, TMK1553INFO info[]);

//удаление объектов управления платами tmk1553
TMK1553MNG void __stdcall Close_tmk1553(void);

//запись одного параметра в плату tmk1553
//возврат 0-OK, -1 - ошибка задания параметра
TMK1553MNG int __stdcall WriteData_tmk1553(ID_Parameter Param);

//чтение одного параметра из платы tmk1553
//возврат 0-OK, -1 - ошибка задания параметра
TMK1553MNG int __stdcall ReadData_tmk1553(ID_Parameter &Param);

//выдача пакета параметров платой c номером NumCard в режиме ОУ и МОУ
TMK1553MNG void __stdcall Send_tmk1553(int NumCard);

//прием пакета параметров платой c номером NumCard в режиме ОУ и МОУ
TMK1553MNG void __stdcall Recv_tmk1553(int NumCard);

// чтения буфера телеметрических сообщений для первой попавшейся платы, работающей в режиме монитора
// в location возвращается указатель на буфер сообщений
// в lpNumberOfMessages возвращается количество сообщений, находящихся в буфере. Размер сообщения = 34*2 байт
TMK1553MNG void __stdcall GetTlmMsg(VOID** location, LPDWORD lpNumberOfMessages);


//формирование текущего задания Контроллером шины для платы c номером NumCard
TMK1553MNG void __stdcall MakeTaskBC_tmk1553(int NumCard);

//чтение данных из монитора для платы c номером NumCard
TMK1553MNG void __stdcall MakeMT_tmk1553(int NumCard);

//анализ одного блока Base сообщения из монитора для платы c номером NumCard
// и запись этого сообщения в ТЛМ буфер по смещению  NumMsg
TMK1553MNG void __stdcall mtGetMSG_tmk1553(int NumCard, USHORT Base, USHORT NumMsg);

//выполнение всеми платами операций Send, Recv, MakeTaskBC в зависимости от типа платы
TMK1553MNG void __stdcall Execute_All_tmk1553(void);

//получение кода последней ошибки
TMK1553MNG int __stdcall GetLastError_tmk1553(void);

#ifdef __cplusplus
}
#endif
#endif

//класс для хранения вспомагательных данных
class  AUXData {
public:
        AUXData();
       ~AUXData();

USHORT RecvRT[32][32][32];//буфер приема данных [номер ОУ][номер П/А][слово в П/А]
USHORT SendRT[32][32][32];//буфер передачи данных [номер ОУ][номер П/А][слово в П/А]
USHORT mtLastBase;//номер блока ОЗУ до которого монитор записал сообщения в прошлом цикле
USHORT mtNextBase;//номер блока ОЗУ c которого монитор будет записать сообщения
UCHAR ReqRxNW[32][32];//массив количества слов запрашиваемых на прием [номер ОУ][номер П/А]
UCHAR ReqTxNW[32][32];//массив количества слов запрашиваемых на выдачу [номер ОУ][номер П/А]
USHORT TlmData[16][32];//массив для 16 телеметрических таблиц по 32 слова.
USHORT TlmMsgBuf[SizeTlmBuf][34];//буфер для регистрации ТЛМ сообщений
USHORT NumberOfTlmMsg;//количество ТЛМ сообщений, находящихся в буфере 
USHORT StatusRT[4], StatusRTprev[4];//состояния ОУ/МОУ включен или выключен для динамического вкл-выкл
};
