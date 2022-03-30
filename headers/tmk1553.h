//---------------------------------------------------------------------------
#ifndef TMK1553H
#define TMK1553H

#if defined(TMK1553_DLL)
# define TMK1553CLASS     __declspec(dllexport)
#elif defined(TMK1553_APP)
# define TMK1553CLASS     __declspec(dllimport)
# else
# define TMK1553CLASS
#endif

// коды ошибок tmkconfig и TMKXLoadByIndex
#define		TX_OK                   0x0
#define		TX_BAD_PARAMS           0x1
#define		TX_NOT_FOUND_OR_ALREADY_LOADED 0x2
#define		TX_LOAD_ERROR           0x4
#define		TX_INIT_ERROR           0x8
#define		TX_TEST_ERROR           0x10
#define		TX_INIT_PORT_ERROR      0x20
#define		TX_INIT_IRQL_ERROR      0x40
#define		TX_PCI_BRD_NOT_FND      0x80 //плата не найдена

// Define RTAPI function calling convention unless an override is in effect.
#ifndef RTAPI
#       if (defined(_MSC_VER)&&(_MSC_VER >= 800)) || defined(_STDCALL_SUPPORTED)
#              define RTAPI __stdcall
#       else
#              define RTAPI
#       endif
#endif
// Define the declaration for application provided functions.
#define RTFCNDCL RTAPI

class TMK1553CLASS TTMK1553 {
public:
        TTMK1553();
       ~TTMK1553();

/**************************************************************************
                        Функции общего назначения
**************************************************************************/
int tmkconfig(int tmkType, USHORT tmkPorts, UCHAR tmkIrq,
                BOOLEAN (RTFCNDCL *pRoutine)(PVOID context));
/*     Параметры:
          tmkType - тип установленной платы:
                TX1, RT1, TX4, TX5, TX6, TX5MRT, TX6MRT, TE6_PCI, TE6_PCI_MRT, TE1_PCI

          tmkPorts - базовый адрес портов / номер платы PCI;
          tmkIrq - номер линии запроса прерывания ( 0 - 15 )
                   или IRQL_NOT_USE, если не используется;
                   IRQL_PCI_AUTO - для платы PCI
          pRoutine - адрес процедуры обработки прерывания (или NULL)

     Возвращаемое значение:
                TX_OK
                TX_BAD_PARAMS
                TX_NOT_FOUND_OR_ALREADY_LOADED
                TX_LOAD_ERROR
                TX_INIT_ERROR
                TX_TEST_ERROR
                TX_INIT_PORT_ERROR
                TX_INIT_IRQL_ERROR
                TX_PCI_BRD_NOT_FND
     Выполняемые действия:
          Функция настраивает драйвер на конкретные значения адресов
          портов и номера линий прерывания для платы с указанным типом,
          запоминает размер ОЗУ в SIZE_OZU
---------------------------------------------------------------------------*/

void tmkdone();
/*     Параметры:
          Нет.
     Возвращаемое значение:
          Нет.
     Выполняемые действия:
          Функция должна вызываться в конце работы с платами ТМК. Основное
          назначение функции - восстановление системы прерываний ПЭВМ
          и закрытие портов.
---------------------------------------------------------------------------*/

int tmkGetVersion();
/*     Параметры:
          Нет.
     Возвращаемое значение:
          Номер версии драйвера.
     Выполняемые действия:
          Функция возвращает Номер версии драйвера.
---------------------------------------------------------------------------*/
//функций для работы с регистрами платы
//------------------- Работа с портами в RTX -----------------------------------
 BOOL EnablePortsIO(USHORT);//открытие портов
 BOOL DisablePortsIO(void);//закрытие портов
 void  WritePort(USHORT Port,USHORT Value);//запись в порт
 USHORT  ReadPort(USHORT Port);//чтение из порта
//--------------------- Функции работы с регистрами платы ----------------------
 void StopTask(void);//Останов задания
 void ResetDevice(void);//Программный сброс устройства
 USHORT GetRegBaseAddrCurrTask(void);//Чтение Рег. базового адр. текущ. задания
 void SetRegMoge(USHORT);//Запись в Регистр режима работы
 void SetRegInitialAddr(USHORT);//Запись в Регистр  начального адреса ДОЗУ (RGA)
 USHORT GetRegStatusWord(void);//Чтение Регистра  слова состояния
 void SetRegCommandWord(USHORT);//Запись в Регистр управляющего слова
 void SetRegData(USHORT);//Запись в Двухпортовое ОЗУ
 USHORT GetRegData(void);//Чтение Двухпортового ОЗУ
 void SetRegDataBuf(PUSHORT pBuffer, USHORT NWord);//Запись в ОЗУ NWord слов из буфера pBuffer
 void GetRegDataBuf(PUSHORT pBuffer, USHORT NWord);//Чтение из ОЗУ NWord слов в буфер pBuffer
 //загрузка плат
//вход: TX1-0, RT1-1, TX4-2, TX5-3, TX6-4,TX5_MRT -5,TX6_MRT -6,TE6_PCI -7,
//      TE6_PCI_MRT -8, TE1_PCI-9
//выход: TX_OK,TX_NOT_FOUND,TX_LOAD_ERROR,TX_INIT_ERROR,TX_TEST_ERROR
int TMKXLoadByIndex(int nLoadType);
int tmkxload(PUCHAR Buffer, ULONG  Count);
int tmkxiload(unsigned portplx, int reset, unsigned char *fpgabuf, int len);
USHORT TestRAM(void);
void ClearRAM(void);
void Srand(unsigned short);
unsigned short Rand();

//поиск Pci платы с номером NumBoard(с 1),
//устанавливает portplx, port, IrqL, PCIBusMumber для найденной платы
//Возврат - количество найденных плат (с 1)
int ScanPciBoard(int NumBoard, unsigned & portplx, unsigned & port, unsigned char &IrqL, unsigned & PCIBusMumber);

bool IsMyInterrupt(void);

protected:
USHORT BasePortAddr;
unsigned PCIportplx; //базовый адрес портов управления
USHORT SIZE_OZU;
unsigned short _wRand;
int _fRand;

/**************************************************************************
                        Определения констант
**************************************************************************/

//------------ смещения адресов регистров платы --------------------------------
#define TMK_StopPort          0x4 //Останов задания КК,МК Зап.
#define TMK_ResetPort         0x6 //Программный сброс устройства КК,ОУ, МК Зап
#define TMK_BaseAddrPort      0x8 //Рег. базового адр. текущего задания КК,МК Чт
#define TMK_ModePort          0x8 //Рег. режима работы КК,ОУ, МК Зап.
#define TMK_AddrPort          0xA //Рег. начального адр. ДОЗУ (RGA) КК,ОУ,МК Зап
#define TMK_StatusPort        0xC //Рег. слова состояния КК,ОУ, МК Чт.
#define TMK_ControlPort       0xC //Рег. управляющего слова КК,ОУ, МК Зап.
#define TMK_DataPort          0xE //Двухпортовое ОЗУ КК,ОУ,МК

#define		BUSY             0x0080
#define		BUSY_DEVICE      0x7E7F
#define		EMPTY_DEVICE     0x7EFF
#define		ERROR_DEVICE     0x7FFF
#define		LOADED_DEVICE    0x0000

//типы плат:
#define TX1            0
#define RT1            1
#define TX4            2
#define TX5            3
#define TX6            4
#define TX5MRT         5
#define TX6MRT         6
#define TE6_PCI        7
#define TE6_PCI_MRT    8
#define TE1_PCI        9

//допустимые базовые адреса Для ISA плат
#define PIO150      0x150
#define PIO160      0x160
#define PIO190      0x190
#define PIO1A0      0x1A0
#define PIO250      0x250
#define PIO260      0x260
#define PIO290      0x290
#define PIO2A0      0x2A0

//допустимые номера плат для PCI
#define BOARD1      0x1
#define BOARD2      0x2
#define BOARD3      0x3
#define BOARD4      0x4
#define BOARD5      0x5
#define BOARD6      0x6
#define BOARD7      0x7
#define BOARD8      0x8

//допустимые IRQL
#define IRQL3        3
#define IRQL4        4
#define IRQL5        5
#define IRQL6        6
#define IRQL7        7
#define IRQL9        9
#define IRQL10       10
#define IRQL11       11
#define IRQL12       12
#define IRQL14       14
#define IRQL15       15
#define IRQL_NOT_USE       0xFF
#define IRQL_PCI_AUTO      16

#define BC_MODE         0x00  //режим КК
#define RT_MODE         0x80  //режим ОУ
#define MT_MODE         0x100 //режим МТ
#define MRT_MODE        0x200 //режим МОУ
#define UNDEFINED_MODE  0xFFFF//режим платы не был определен

#define MRT_NOT_USE     0x1F //запрет использования ОУ

#define RT_HBIT_MODE 0x0001 //режим использования аппаратного бита
#define RT_FLAG_MODE 0x0002 //режим работы с флагами
#define RT_BRCST_MODE 0x100 //режим приема сообщений с групповым адресом
#define RT_DATA_BL 0x2000   //RT_DATA_BL - режим блокировки прерываний по приему/передаче данных
#define RT_GENER1_BL 0x0004 //режим блокировки прерываний по генерации в основной ЛПИ;
#define RT_GENER2_BL 0x4000 //режим блокировки прерываний по генерации в резервной ЛПИ;
#define BC_GENER1_BL 0x0004 //режим блокировки прерываний по генерации в основной ЛПИ;
#define BC_GENER2_BL 0x4000 //режим блокировки прерываний по генерации в резервной ЛПИ;
#define MT_GENER1_BL 0x0004 //MT_GENER1_BL - режим блокировки прерываний по генерации в основной ЛПИ
#define MT_GENER2_BL 0x4000 //MT_GENER2_BL - режим блокировки прерываний по генерации в резервной ЛПИ
#define TMK_IRQ_OFF 0x8000  //режим отключения линии запроса прерывания платы.

#define DATA_BC_RT      0x00 //передача данных КК-ОУ;
#define DATA_BC_RT_BRCST 0x08//передача данных КК-ОУ в групповом режиме;
#define DATA_RT_BC      0x01 //передача данных ОУ-КК;
#define DATA_RT_RT      0x02 //передача данных ОУ-ОУ;
#define DATA_RT_RT_BRCST 0x0A//передача данных ОУ-ОУ в групповом режиме;
#define CTRL_C_A        0x03 //команда управления формата КС-ОС;
#define CTRL_C_BRCST    0x0B //команда управления формата КС в групповом режиме;
#define CTRL_CD_A       0x04 //команда управления формата КС+ИС-ОС;
#define CTRL_CD_BRCST   0x0C //команда управления формата КС+ИС в групповом режиме;
#define CTRL_C_AD       0x05 //команда управления формата КС-ОС+ИС.

#define BUS_A           0 //для всех обменов по основной линии
#define BUS_1           0 //для всех обменов по основной линии
#define BUS_B           1 //для всех обменов по резервной линии
#define BUS_2           1 //для всех обменов по резервной линии

//константы направления передачи
#define RT_TRANSMIT     0x0400 // ОУ передает
#define RT_RECEIVE      0x0000 // ОУ принимает

#define NWORDS_MASK     0x001F
#define SUBADDR_MASK    0x03E0
#define ADDRESS_MASK 	0xF800
#define RT_DIR_MASK 	0x0400

#define NO_FLAG_REQ     0x040

#define AUTO_CONT     0x10//признак автоматического продолжения

#define RT_MODE_WITH_FLAGS      0
#define RT_MODE_WO_FLAGSW_1     1
#define RT_MODE_WO_FLAGSW_2     2

//PCI атрибуты элкусовской платы
#define TX_VID                  0x10B5
#define TX_DID                  0x9030
#define TX_SubVID               0xE1C5
#define TX1_SubDID              0x0001
#define TX6_SubDID              0x0002

//---------------------------------------------------------------------------
};
#endif
