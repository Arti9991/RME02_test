Imports System.Runtime.InteropServices

Module Module_main

 Public LNGV = "E" ' Выбор языка интерфейса

 Public Const N_lbl_lamp As Int32 = 4
 Public Const N_lbl_wtcycle As Int32 = 26
 Public Const N_lbl_no_adp As Int32 = 13 ' Максимальное кол-во типов адаптеров, обнаруженных на IPC 
 Public Const N_Btn_ctrl As Int32 = 8
 Public Const N_Btn_TeeChart As Int32 = 8

 Dim res As Integer
 Dim nAd_TX6 As Integer, nBurst_TX6 As Integer
 Dim period1, period2, cntG1, cntG2 As Int32
 Dim bar_max(0 To 7) As Single

 Public iRack, iIPC, iTypeAd, iAd As Int32

 Public sql As String
 Public sql_parameter_where As String
 Public sql_qDataBurst As String
 Public sql_qAdapters As String
 Public sql_logic_replay As String

 ''Public wrkJet As Workspace

 ''Public Db As Database
 ''Public Db_BD_RS As Database
 ''Public Db_RCR As Database
 ''Public Db_DISPLAY As Database

 Public rs As System.Data.DataTable

 ''Public gsDatabase As String
 ''Public gsRCR As String
 ''Public gsDISPLAY As String
 ''Public FullNameIniFile As String

 Public BD_RS_File As String = New String(CChar(" "), 256)
 Public RCR_File As String = New String(CChar(" "), 256)
 Public objCreate, fileCreate, file_Data, file_ab, file_tb As System.IO.StreamWriter
 Public DISPLAY_File As String = New String(CChar(" "), 256)

 Public DATA_File As String
 Public AB_File As String
 Public TB_File As String
 Public DIRCURR As String
 Public FreeMemory As Int32
 Public SizeSharedMem As Int32
 Public ShareMemAddress() As tShareMemAddress

 ''Public BaseRefMemType As Int32  ' Базовый тип рефлективной памяти для служебного обмена

 Public choose_MSFlexGrid_parameters As Integer
 Public choose_MSFlexGrid_DC_parameters As Integer
 Public choose_MSFlexGrid_manual_parameters As Integer

 Public ready_main ' статус завершения процедуры main =0 при входе в нее, =1 при выходе

 ' CONF_RIG :
 ' =1: 2900СМТ
 ' =2: 2900К/КУБ
 ' =3: Для 29СМ
 ' =4: Для И21
 ' =5: Для 170M
 ' =6: Для 29UPG
 ' =7: Для 29М/М2
 ' =8: Для 29К/КУБ(Р)
 Public CONF_RIG As Int32

 ' Общие определения констант и структур данных
 ' используемых в программах КССР

 Public Const color_pause = &HFF8080FF
 Public Const color_work = &HFFC0FFC0
 Public Const color_suspect = &HFF80FFFF
 Public Const color_unused = &HFF808080
 Public Const nSelColor = 8
 Public SelColor(nSelColor - 1) As System.Drawing.Color

 Public Const nBTN = 8         ' Кол-во кнопок управления в программе HLI.exe
 Public Const nMonParFree = 4  ' Кол-во параметров просмотра выбир.оператором
 Public Const nMonParFix = 8   ' Кол-во параметров просмотра с id из DISP_SI.ini
 Public Const nMonParTrig = 2   ' Кол-во параметров для формирования условия отановки программы
 Public Const nToHLI = 1024    '
 Public Const nMonDC = 256     '
 Public Const nSet = 5         ' Кол-во графиков
 Public NumPars As Integer     ' Кол-во графиков
 Public Const npoint = 2048    ' 512 Кол-во точек на графике
 Public NumGPoints As Integer  ' Кол-во точек на графике

 Public Const IPCnumber = 16         ' Максимальное кол-во IPC
 Public Const AdapterTypeNumber = 64 ' Максимальное кол-во типов адаптеров (вкл.виртуальные)
 Public Const AdapterNumber = 8      ' Максимальное кол-во адаптеров данного типа на данной IPC (нумерация с 0)

 '' типы адаптеров IdAdaptersType // Старый набор //
 'Public Const SEALEVEL_5011 = 1
 'Public Const TX6_PC_C = 2
 'Public Const PC429_3_88 = 3
 ''Public Const PCL_836 = 4
 'Public Const PC429_4_xx = 4
 'Public Const PCL_726 = 5
 'Public Const PCL_722 = 6
 'Public Const NI6704 = 7
 'Public Const ARINC_717 = 8
 'Public Const SPECIAL = 9       ' В базе данных VIRTUAL
 'Public Const LCARD_761 = 10
 'Public Const LCARD_1208 = 11
 'Public Const OL = 12
 'Public Const PCI_1753 = 13
 'Public Const ASTRA = 14
 'Public Const VMIPCI5587A = 15
 'Public Const PCI_1716 = 16
 'Public Const PCI_1724 = 17
 'Public Const IPK1 = 18
 'Public Const VMIPCI5565 = 19
 'Public Const PCI_1713 = 20
 'Public Const PCI_1723 = 21
 'Public Const PCI_ASTRA = 22
 'Public Const CUS_BMK = 23
 'Public Const PCI_ASTRA_BL = 24
 'Public Const PCIxyzDAC = 25
 'Public Const PCI_1705 = 26      ' В базе данных КМБО
 'Public Const RS422_MOXA = 28
 'Public Const pciSPI = 29
 'Public Const RS485_MTVS = 30

 ' типы адаптеров IdAdaptersType
 Public Const RES1 = 1
 Public Const TX6_PC_C = 2
 Public Const PC429_3_88 = 3
 Public Const PC429_4_xx = 4
 Public Const PCADS_05 = 5
 Public Const PCADS_05K = 6
 Public Const PCADS_05RK = 7
 Public Const iMKIO_1 = 8
 Public Const SPECIAL = 9       ' В базе данных VIRTUAL
 Public Const RES2 = 10
 Public Const PCADS_v7K = 11
 Public Const RES3 = 12
 Public Const PCI_1753 = 13
 Public Const RES4 = 14
 Public Const VMIPCI5587A = 15
 Public Const PCI_1716 = 16
 Public Const PCI_1724 = 17
 Public Const IPK1 = 18
 Public Const VMIPCI5565 = 19
 Public Const PCI_1713 = 20
 Public Const RMe_02 = 21
 Public Const PCI_ASTRA = 22
 Public Const CUS_BMK = 23
 Public Const PCI_ASTRA_BL = 24
 Public Const PCADSv7RTMin = 25
 Public Const PCADSv7RTMout = 26
 Public Const PCADS_v7RK = 27  ' В базе данных PCADSv7RK
 Public Const RES11 = 28
 Public Const RES12 = 29
 Public Const RS485_MTVS = 30
 Public Const RES13 = 31

 Public IdB() As Int32
 Public nBatch_1705(0 To AdapterNumber - 1) As Integer ' кол-во пакетов на адаптере

 ' -----------------------------------------------------------------------
 ' VP001...VP256: Виртуальные параметры приписаны к адаптеру типа SPECIAL
 ' глобальный номер строится следующим образом:
 '  FullParam(0) = iIPC*&H40000000 + Address*&H2 + InOut*&H1
 '  FullParam(1) = SignBit1*&H400 + HiBit*&H20 + LoBit
 ' где iIPC    : номер IPC к которому приписан параметр (нумерация с 0)
 '     InOut   : параметр выдается устройством = 0, принимается = 1
 '     Address : порядковый номер параметра (нумерация с 0)
 '     LowBit  : положение младшего бита (нумерация с 0)
 '     HiBit   : положение старшего бита (нумерация с 0)
 '     SignBit1: признак знака
 '
 ' VP001: время на IPC1 в 10мс тиках - глобальный номер FullParam(0) = 0x00000000
 '                                                      FullParam(1) = 0x000003E0
 ' VP002: время на IPC2 в 10мс тиках - глобальный номер FullParam(0) = 0x40000000
 '                                                      FullParam(1) = 0x000003E0
 ' -----------------------------------------------------------------------

 'ресурсы устройств
 <StructLayout(LayoutKind.Sequential, Pack:=1)> _
 Public Structure tDeviceResources  ' 16 байт
  Public HiBaseMemory As Int32      ' старшие 4 байта базового адреса памяти
  Public LoBaseMemory As Int32      ' младшие 4 байта базового адреса памяти
  Public BasePort As Int16        ' базовый адрес портов ввода-вывода
  Public DMAPort As Int16         ' порт канала DMA
  Public DMAChannel As Byte         ' номер канала DMA
  Public nIRQ As Byte               ' номер линии запроса прерывания
  Public NumChannel As Int16      ' кол-во каналов адаптера
 End Structure


 ' определение характеристик параметра
 ' привязка параметра к устройству
 Public Structure tDeviceInfo      ' 8 байт
  Public L1 As Int32 ' 23 bits:reserve
  '                     3 bits:NumDevice  Порядковый номер адаптера данного типа в данном РС(биты 24-26)
  '                     6 bits:TypeDevice Тип адаптера (биты 27-32)
  Public L2 As Int32 ' 28 bits:reserve    (биты 31,32)
  '                     4 bits:NumPC      Номер компьютера в стойке(биты 29,30,31,32)
  Public L3 As Int32 ' 32 bits:reserve
 End Structure

 ' определение параметров строки сценария
 <StructLayout(LayoutKind.Sequential, Pack:=1)> _
 Public Structure tSCRIPT  ' 73 байта (ReDim для idpar(), Index(), value(), Cond() в проц. read_script())
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> _
  Public idpar() As Int32  ' (5) идент.номер параметра
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> _
  Public Index() As Int32  ' (5) индекс в массиве вх.(индекс<0) / вых. (индекс>0) параметров
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=2)> _
  Public value() As Double ' (1) Массив значений в условиях сравнения
  Public WtDl As Int32     ' Ожидание(в режиме IN) или задержка (в режиме OUT) [0.1мкс]
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=2)> _
  Public Cond() As Byte    ' (1) Код операции сравнения или битовой операции
  Public Logic As Byte     ' Код логической операции
  Public Type_func As Byte ' Признак функции изменения выходного параметра
  Public Min As Double     ' Минимальное значение выходного параметра
  Public Max As Double     ' Максимальное значение выходного параметра
  Public T_start As Int32  ' Момент выполнения условия сценария [0.1мкс]
  Public Period As Int32   ' Период изменения выходного параметра [0.1мкс]
  Public T_up As Int32     ' Время нарастания уровня выходного параметра до Max [0.1мкс] от нач.периода
  Public T_top As Int32    ' Время стояния выходного параметра на Max уровне [0.1мкс] от нач.периода
  Public T_down As Int32   ' Время снижения уровня выходного параметра до Min [0.1мкс] от нач.периода
 End Structure

 ' определение параметров строки сценария
 <StructLayout(LayoutKind.Sequential, Pack:=1)> _
 Public Structure tGLOBNUM                  ' 12 байт
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=3)> _
  Public FullParam() As Int32   ' (2) Глобальный номер параметра + данные
 End Structure

 <StructLayout(LayoutKind.Sequential, Pack:=1)> _
 Public Structure tParameter
  Public glob As tGLOBNUM
  Public idpar As Int32    ' идент.номер параметра в БД BD_RS.mdb
  Public scal As Single    ' Цена старшего разряда
  Public Offset As Int32   ' Смещение в ShMem для параметра
  Public Direct As Int32    ' 0: параметер выходной для модели, 1: входной
  Public CodePar As Int32  ' Код параметра для упаковки в ShMem
  Public Sync As Int32     ' Параметр определяющий порядок вывода
  '                          =0: параметр используется во втором пакете цикла
  '                          >0: параметр используется в первом пакете цикла,
  '                          порядок вызова параметров соотв. Sync, т.е. Sync=5 вызовется перед Sync=3
 End Structure

 <StructLayout(LayoutKind.Sequential, Pack:=1)> _
 Public Structure tIPCtoDLL
  Public script() As tSCRIPT
  Public param_in() As tParameter
  Public param_out() As tParameter
 End Structure

 Public Structure tIdData
  Public id As Int32    ' уникальный идентификатор параметра в BD_RS.mdb
  Public Data As Int32  ' значение параметра
 End Structure

 <StructLayout(LayoutKind.Sequential, Pack:=1)> _
 Public Structure tIPCtoHLI
  Public time As Int32           ' Время пакета в мс от старта сценария на IPC1
  Public qin As Int32            ' Кол-во передаваемых вх.параметров
  Public qout As Int32           ' Кол-во передаваемых вых.параметров
  Public qscr As Int32           ' Кол-во ошибок выполнения сценария
  Public id_val_in() As tIdData  ' Массив структур идентификаторов и значений вх.параметров
  Public id_val_out() As tIdData ' Массив структур идентификаторов и значений вых.параметров
  Public error_script() As Int32 ' Массив номеров строк сценария,
  '                                где не удалось дождаться входного сигнала (нумерация с 1)
 End Structure

 <StructLayout(LayoutKind.Sequential, Pack:=1)> _
 Public Structure tHLItoIPC
  Public control As UInt32  ' Управляющее слово
  ' 0-й бит ULONG start      :1; //  1 - разрешение выполнения процедур таймера/прерывания , 0 - пропуск всех процедур в таймера/прерывании
  ' 1-й бит ULONG unload     :1; //  1 - признак выгрузки программы IPC.exe
  ' 2-й бит ULONG btn        :1; //  1 - отработка вых.параметров (от кнопок управления), 0 - игнорировать вых.параметры (от кнопок управления)
  ' 3-й бит ULONG regist     :1; //  1 - регистрировать параметры в файл, 0 - не регистрировать параметры в файл Data.dat программой HLI
  ' 4-й бит ULONG time       :1; //  1 - записывать время из программы DISP_SI в ячейку рефлективной памяти для глобального времени
  ' 5-й бит ULONG pause      :1; //  1 - прекращение вызова моделей в такте, 0 - вызов моделей в такте
  ' 6-й бит ULONG change     :1; //  1 - передавать неизменившиеся параметры , 0 - не передавать неизменившиеся параметры
  ' 7-й бит ULONG emulator   :1; //  1 - имитировать время обращения к адаптерам, 0 - не имитировать время обращения к адаптерам
  ' 8-й бит ULONG dbg        :1; //  1 - записывать в файл DBG отладочную информацию на каждом шаге программой IPC.exe, 0 - не записывать
  ' 9-й бит ULONG	pulseLPT   :1;	//  1 - разрешить формирование коротких импульсов на выходе LPT порта, не разрешать формирование импульсов
  '10-й бит ULONG	Beep       :1;	//  1 - разрешить выдавать короткий звук в начале цикла
  '11-й бит ULONG	EraseRF    :1;	//  1 - обнулять RefMem при каждом запуске DISP_SI, 0 - обнулять только при первом запуске DISP_SI
  '12,13-й биты ULONG	CycleBusy  :2;	//  !=0 - CYCLE_STEP не завершился
  '14,15-й биты ULONG	SingleBusy :2;	//  !=0 - SINGLE_STEP не завершился
  '16...23-й биты ULONG	cnt1     :8; //  текущий счетчик числа неудачных взводов RTX таймера
  '24...31-й биты ULONG	cnt2     :8;	//  максимальное значение числа неудачных взводов RTX таймера
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=nBTN)> _
  Public id() As Int32   ' (0 To nBTN - 1) уникальный идентификатор параметра в BD_RS.mdb
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=nBTN)> _
  Public Data() As Int32 ' (0 To nBTN - 1)Значения выходных параметров (кнопки 1-8 в программе HLI.exe)
  Public cnt As UInt32   '   Счетчик посылок структуры (по Socket или RM )
 End Structure

 <StructLayout(LayoutKind.Sequential, Pack:=1)> _
 Public Structure timeDLLtoHLI
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=nToHLI)> _
  Public Ln() As Int32
 End Structure

 <StructLayout(LayoutKind.Sequential, Pack:=1)> _
 Public Structure valueDLLtoHLI
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=nToHLI)> _
  Public Ln() As Double
 End Structure

 <StructLayout(LayoutKind.Sequential, Pack:=1)> _
 Public Structure tDLLtoHLI
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=(nMonParFree))> _
  Public qp() As Int32                    ' (0 To nMonParFree - 1) кол-во полученных значений параметра nMonParFree
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=(nMonParFree))> _
  Public time() As timeDLLtoHLI           ' (1 To nToHLI, 0 To nMonParFree - 1) время посылки параметра с IPC
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=(nMonParFree))> _
  Public idpar() As Int32                 ' (0 To nMonParFree - 1) уникальный идентификатор параметра в базе данных
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=(nMonParFree))> _
  Public value() As valueDLLtoHLI         ' (1 To nToHLI, 0 To nMonParFree - 1) значение свободного параметра

  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=(nMonParFix))> _
  Public fix_idpar() As Int32             ' (0 To nMonParFix - 1) уникальный идентификатор параметра в базе данных
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=(nMonParFix))> _
  Public fix_value() As Double            ' (0 To nMonParFix - 1) значение фиксированного параметра

  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=(nMonParTrig))> _
  Public trig_idpar() As Int32             ' (0 To nMonParTrig - 1) уникальный идентификатор параметра в базе данных
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=(nMonParTrig))> _
  Public trig_value() As Double            ' (0 To nMonParTrig - 1) значение параметра для формирования условия остановки программы

  Public trig_logic As Int32               ' логика формирования тригера

  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=(nMonDC))> _
  Public idRK() As Int32                   ' (0 To nMonDC - 1) уникальный идентификатор параметра в базе данных (<0: вх. и >0: вых)
  <MarshalAs(UnmanagedType.ByValArray, SizeConst:=(nMonDC))> _
  Public valueRK() As Int32                ' (0 To nMonDC - 1) значение параметра
 End Structure

 ' 1-й индекс тип адаптера (0,1,...,AdapterTypeNumber - 1)
 ' 2-й индекс номер адаптера данного типа на данной IPC (0,1,...,AdapterNumber-1)
 Public DeviceResources(AdapterTypeNumber - 1, AdapterNumber - 1) As tDeviceResources

 Public DevRes(AdapterNumber - 1) As tDeviceResources
 Public Adapter_query(AdapterTypeNumber - 1) As Byte ' признаки присутствия адаптера в таблице qAdapters
 Public DeviceInfo As tDeviceInfo
 Public GN As tGLOBNUM
 Public IPCtoDLL As tIPCtoDLL
 Public DLL_HLI As tDLLtoHLI
 Public HLItoIPC As tHLItoIPC
 Public HLItoIPC_old As tHLItoIPC

 Public in_parameters_number As Int32  ' кол-во входных параметров
 Public out_parameters_number As Int32 ' кол-во выходных параметров
 Public nrec_script As Int32           ' кол-во записей сценария
 Public s_fast As String               ' для быстрого поиска
 Public this_IPC                       ' Номер компьютера на котором запущена программа
 Public Period As Int32                ' Время такта системы

 Public Structure MSG
  Public hwnd As Long
  Public message As Long
  Public wParam As Long
  Public lParam As Long
  Public time As Long
  Public x As Long
  Public y As Long
 End Structure

 Public aMsg As MSG
 '.............................................................................................................................
 Declare Function GetPrivateProfileStringKey Lib "kernel32" Alias "GetPrivateProfileStringA" _
  (ByVal lpApplicationName As String, _
   ByVal lpKeyName As String, _
   ByVal lpDefault As String, _
   ByVal lpReturnedString As String, _
   ByVal nSize As Int32, _
   ByVal lpFileName As String) As Int32

 Public Declare Function GetPrivateProfileInt Lib "kernel32" Alias "GetPrivateProfileIntA" _
  (ByVal lpApplicationName As String, _
   ByVal lpKeyName As String, _
   ByVal nDefault As Int32, _
   ByVal lpFileName As String) As Int32

 Public Declare Function GetSystemMetrics Lib "user32" (ByVal nIndex As Int32) As Int32

 Public Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Int32)

 Private Declare Function GetMessage Lib "user32" Alias "GetMessageA" (ByRef lpMsg As MSG, ByVal hWnd As Long, ByVal wMsgFilterMin As Long, ByVal wMsgFilterMax As Long) As Long

 '.............................................................................................................................
 ' ------------------------------------------- KSSR_func -------------------------------------------------------

 Public Declare Sub vbChoose_Timer Lib "#KSSR_func.dll" (ByVal Period As Int32)

 ' Вставляет 32-х разрадное число w32 в 32-х разрадное число vbInsert_to_w32 таким образом, что
 ' младший бит w32 приходится на lobit. Часть битов числа w32 попавшая за hibit отбрасывается.
 ' Нумерация битов 0...31
 ' -------------------------------------------------------------------------------------------------------
 Public Declare Function vbInsert_to_w32 Lib "#KSSR_func.dll" _
  (ByVal dest32 As Int32, ByVal w32 As Int32, ByVal LoBit As Byte, ByVal HiBit As Byte) As Int32

 ' -------------------------------------------------------------------------------------------------------
 Public Declare Function vbInsert_to_w16 Lib "#KSSR_func.dll" _
  (ByVal dest16 As Int16, ByVal w16 As Int16, ByVal LoBit As Byte, ByVal HiBit As Byte) As Int16

 '' ''     Функция передает из IPC.exe класс со сценарием и информ. о параметрах
 '' '' -------------------------------------------------------------------------------------------------------
 ' ''Public Declare Sub vbToDLL Lib "#KSSR_func.dll" _
 ' '' (ByRef script As tSCRIPT, ByVal ns As Int32, _
 ' ''  ByRef pin As tParameter, ByVal pn_in As Int32, _
 ' ''  ByRef pout As tParameter, ByVal pn_out As Int32)

 ''// Создание массивов классов сценария, вх. и вых. параметров 
 ''void __stdcall vbToDLLsize (ULONG _ns, ULONG _pn_in ,ULONG _pn_out);
 Public Declare Sub vbToDLLsize Lib "#KSSR_func.dll" _
                              (ByVal ns As UInt32, ByVal pn_in As UInt32, ByVal pn_out As UInt32)

 ''// Передача из IPC.exe одного элемента класса script[i] из ns имеющихся
 ''void __stdcall vbToDLLscript (ScriptClass script, ULONG i);
 Public Declare Sub vbToDLLscript Lib "#KSSR_func.dll" (ByRef script As tSCRIPT, ByVal ns As Int32)

 ''// Передача из IPC.exe одного элемента класса pin[i] из pn_in имеющихся
 ''void __stdcall vbToDLLpin (ParameterClass pin, ULONG i);
 Public Declare Sub vbToDLLpin Lib "#KSSR_func.dll" (ByRef pin As tParameter, ByVal pn_in As Int32)

 ''// Передача из IPC.exe одного элемента класса pout[i] из pn_out имеющихся
 ''void __stdcall vbToDLLpout (ParameterClass pout, ULONG i);
 Public Declare Sub vbToDLLpout Lib "#KSSR_func.dll" (ByRef pout As tParameter, ByVal pn_out As Int32)

 ''// Формирование необходимых классов по полученной из IPC.exe информ.
 ''void __stdcall vbToDLLcreate (void);
 Public Declare Sub vbToDLLcreate Lib "#KSSR_func.dll" ()

 ' Упаковывает число f типа float в 32-х разрадное число vbPack_from_w32
 ' в соответствие с параметрами упаковки LowBit, HiBit, SignBit1, SignBit2, scale
 ' Нумерация битов 0...31
 ' --------------------------------------------------------------------------------------------
 Public Declare Function vbPack_to_w32 Lib "#KSSR_func.dll" _
  (ByVal f As Single, _
   ByVal LoBit As Byte, _
   ByVal HiBit As Byte, _
   ByVal SignBit1 As Byte, _
   ByVal SignBit2 As Byte, _
   ByVal scal As Single) As Int32

 ' Извлекает число vbUnpack_from_w32 типа float из 32-х разрадного числа w32
 ' в соответствие с параметрами распаковки LowBit, HiBit, SignBit1, SignBit2, scale
 ' Нумерация битов 0...31
 ' --------------------------------------------------------------------------------------------
 Public Declare Function vbUnpack_from_w32 Lib "#KSSR_func.dll" _
  (ByVal w32 As Int32, _
   ByVal LoBit As Byte, _
   ByVal HiBit As Byte, _
   ByVal SignBit1 As Byte, _
   ByVal SignBit2 As Byte, _
   ByVal scal As Single) As Single

 ' Возвращает 32-х разрядную битовую маску, содержащую 1 в разрадах c lobit по hibit
 ' Нумерация битов 0...31
 ' ----------------------------------------------------------------------------------
 'ULONG __stdcall vbMask ( unsigned char lobit, unsigned char hibit)
 Public Declare Function vbMask Lib "#KSSR_func.dll" (ByVal LoBit As Byte, ByVal HiBit As Byte) As Int32

 ' Возвращает номер IPC.  1:IPC1  2:IPC2  3:IPC3  4:IPC4  5:IPC5  6:IPC6  7:IPC7   16:HLI
 'IPC1    1
 'IPC2    2   // Самолет, цели, SIGMA, СБКВ
 'IPC3    3   //
 'IPC4    4   // ИПО & ИСУО
 'IPC5    5   // Ракеты: РВВ-АЕ
 'IPC6    6   // ЦИРС
 'PCSV1   7   // Визуализация СМТ
 'KARAT   8   // КАРАТ
 'PC1     9   // HLI1
 '
 'PCVS6  10   // Визуализация К/КУБ
 'IPC11  11
 'IPC12  12
 'PCVS2  13   // Визуализация К/КУБ
 'IPC14  14
 'IPC15  15
 'IPC16  16   // HLI2
 ' -------------------------------------------------------------------------------------------------------
 Public Declare Function vbGetLocation Lib "#kssr_func.dll" () As Int32

 Public Declare Sub vbWHO_CALL Lib "#KSSR_func.dll" (ByVal who_call As Int32)
 Public Declare Sub vbControl Lib "#KSSR_func.dll" (ByRef HLItoIPC As tHLItoIPC)
 Public Declare Sub vbMonitor Lib "#KSSR_func.dll" (ByRef DLL_HLI As tDLLtoHLI)
 Public Declare Function vbGetCONG_RIG Lib "#KSSR_func.dll" () As Int32
 ' Возвращает тип используемой в качестве системного интерфейса рефлективной памяти
 ' 1 : 5587
 ' 2 : 5565
 ' 3 : RMe_02
 Public Declare Function vbGetSYS_RM Lib "#KSSR_func.dll" () As Int32 '
 Public Declare Function vbGetEvent Lib "#KSSR_func.dll" () As UInt32

 ' Возвращает процент рабочего времени в цикле
 'float __stdcall vbGet_wtCycle
 ' (long num_t_Point,
 '  unsigned long & period1,
 '  unsigned long & period2,
 '  unsigned long & cntG1,
 '  unsigned long & cntG2)
 Public Declare Function vbGet_wtCycle Lib "#KSSR_func.dll" _
 (ByVal num_Tpoint As Int32) As Single
 ', ByRef period1 As UInt32 _
 ', ByRef period2 As UInt32 _
 ', ByRef cntG2 As UInt32 _
 ', ByRef cntG2 As UInt32 _
 ') As Single

 Public Declare Sub INIT_KSSR_FUNC Lib "#KSSR_func.dll" ()
 Public Declare Sub CLOSE_KSSR_FUNC Lib "#KSSR_func.dll" ()

 ' Возвращает состояние статусной ячейки в RefMem, соотв. запрошенному iIPC
 Public Declare Function vbGetStatusIPC Lib "#KSSR_func.dll" (ByVal iIPC As Int32) As Int32

 ' Задает состояние статусной ячейки в RefMem, соотв. запрошенному iIPC
 Public Declare Sub vbPutStatusIPC Lib "#KSSR_func.dll" (ByVal iIPC As Int32, ByVal status As Int32)

 '..........................................................................
 '0 неизвестный тип
 '1 int    4 signed, signed int System dependent
 '2 unsigned int 4 unsigned System dependent
 '3 __int8   1 char, signed char –128 to 127
 '4 __int16   2 short, short int, signed short int –32,768 to 32,767
 '5 __int32   4 signed, signed int –2,147,483,648 to 2,147,483,647
 '6 __int64   8 none –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
 '7 char   1 signed char –128 to 127
 '8 unsigned char 1 none 0 to 255
 '9 short   2 short int, signed short int –32,768 to 32,767
 '10 unsigned short 2 unsigned short int 0 to 65,535
 '11 long   4 long int, signed long int –2,147,483,648 to 2,147,483,647
 '12 unsigned long 4 unsigned long int 0 to 4,294,967,295
 '13 enum   * none Same as int
 '14 float   4 none 3.4E +/- 38 (7 digits)
 '15 double   8 none 1.7E +/- 308 (15 digits)
 '16 long double  10 none 1.2E +/- 4932 (19 digits)
 '..........................................................................
 Public Function CodeTypeParam(ByVal tpar As String) As Int32
  Select Case tpar
   Case "int" : CodeTypeParam = 1
   Case "unsigned int" : CodeTypeParam = 2
   Case "__int8" : CodeTypeParam = 3
   Case "__int16" : CodeTypeParam = 4
   Case "__int32" : CodeTypeParam = 5
   Case "__int64" : CodeTypeParam = 6
   Case "char" : CodeTypeParam = 7
   Case "unsigned char" : CodeTypeParam = 8
   Case "short" : CodeTypeParam = 9
   Case "unsigned short" : CodeTypeParam = 10
   Case "long" : CodeTypeParam = 11
   Case "unsigned long" : CodeTypeParam = 12
   Case "enum" : CodeTypeParam = 13
   Case "float" : CodeTypeParam = 14
   Case "double" : CodeTypeParam = 15
   Case "long double" : CodeTypeParam = 16
   Case Else : CodeTypeParam = 0
  End Select
 End Function

 ' ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 '             Процедуры общие в программах IPC.exe и HLI.exe
 '  (при любых изменениях не забывать скопировать этот блок в другую программу)
 ' ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

 Public Sub read_GlobNumPar()

  Dim i, j As Int32
  Dim W, ir_in, ir_out As Int32
  Dim NumRec, ShiftRec As Int32
  Dim cppParName As String = ""
  Dim ParName As String
  Dim CodeType As Byte
  Dim Direct As Byte
  Dim ii, jj, kk, mm As Int16
  Dim iRefMemStr(), ss As String
  Dim indexRefMemStr() As Int32
  Dim nRefMemStr, suspect_data As Int16
  Dim v1, v2, v As Int32
  Dim iir_in, iir_out As Int32

  On Error GoTo err_handler

  W = GetLastErrorSM(0)

  NumRec = GetFieldCnt(FreeMemory, SizeSharedMem)

  If W > 1 Or FreeMemory < 0 Then

   If (W And &H2) Then cppParName = cppParName + " - не могу создать память" + vbLf
   If (W And &H8) Then cppParName = cppParName + " - выход за верхнюю границу памяти" + vbLf
   If (W And &H10) Then cppParName = cppParName + " - обращение к неинициализированному адресу" + vbLf
   If (W And &H20) Then cppParName = cppParName + " - пересечение структур данных и имен полей" + vbLf
   If (W And &H40) Then cppParName = cppParName + " - повторная запись поля в уже занятый адрес" + vbLf
   If (W And &H80) Then cppParName = cppParName + " - запрошена несуществующая запись" + vbLf
   If (W And &H100) Then cppParName = cppParName + " - запрошена несуществующая запись" + vbLf
   If (W And &H200) Then cppParName = cppParName + " - повторная запись поля в ранее занятый адрес со сменой признака с выходного на входной" + vbLf
   If (FreeMemory < 0) Then cppParName = cppParName + vbLf + " - РАЗМЕР ПАМЯТИ ПРЕВЫШЕН !!!" + vbLf

   cppParName = "Ошибка при работе с Share Memory : " + "0x" + Hex(W) + vbLf + vbLf + cppParName

   Call MsgBox(cppParName, vbCritical, "IPC.exe")

   End

  End If


  fileCreate.WriteLine("------------------------------------------------")
  fileCreate.WriteLine(" SizeShMem = " + Format(SizeSharedMem, "#######0 bytes"))
  fileCreate.WriteLine(" BusyShMem = " + Format(SizeSharedMem - FreeMemory, "#######0 bytes"))
  fileCreate.WriteLine(" FreeShMem = " + Format(FreeMemory, "#######0 bytes"))
  fileCreate.WriteLine("------------------------------------------------")
  fileCreate.WriteLine("Кол-во переменных в ShMem = " + Format(NumRec, "#####0"))
  fileCreate.WriteLine("------------------------------------------------")
  fileCreate.WriteLine("NoSM  OffSet(ShMem) Code InOut Name")
  fileCreate.WriteLine("------------------------------------------------")

  ReDim ShareMemAddress(NumRec - 1)

  For ii = 0 To NumRec - 1
   cppParName = Strings.StrDup(256, " ")
   ShiftRec = GetStrFieldInfo(ii, cppParName, CodeType, Direct)
   cppParName = Trim(cppParName)
   If InStr(cppParName, Chr(0)) > 1 Then
    ShareMemAddress(ii).ParName = Left(cppParName, InStr(cppParName, Chr(0)) - 1)
   End If
   ShareMemAddress(ii).Offset = ShiftRec
   ShareMemAddress(ii).CodePar = CodeType
   ShareMemAddress(ii).Direction = Direct

   fileCreate.WriteLine(Format(ii + 1, "0000  ") _
                       + MkStrHex(ShiftRec) + "   " _
                       + Format(CodeType, " 00 ") _
                       + Format(Direct, "   0   ") _
                       + ShareMemAddress(ii).ParName _
                       )
  Next ii

  fileCreate.WriteLine("------------------------------------------------")

  ' ---------------------------------------------------------------------------------
  ' Расчет абсолютных смещений в RefMem для переменных относящихся к адаптеру RefMem
  ' ---------------------------------------------------------------------------------

  rs = BD_RS_DataSET.Tables("qPARAMETER")

  With rs

   ' ...........................................................................
   ' Определение кол-ва параметров адаптера VMIPCI5587A || VMIPCI5565 || RMe_02
   ' ...........................................................................
   nRefMemStr = 0
   For i = 0 To .Rows.Count - 1
    ParName = Trim(.Rows(i)("NamePar"))
    If .Rows(i)("IdAdaptersType") = VMIPCI5587A Or _
       .Rows(i)("IdAdaptersType") = VMIPCI5565 Or _
       .Rows(i)("IdAdaptersType") = RMe_02 Then
     nRefMemStr = nRefMemStr + 1
    End If
   Next i

   If nRefMemStr = 0 Then GoTo finish_RF
   ' ................................................................

   ReDim iRefMemStr(nRefMemStr)
   ReDim indexRefMemStr(nRefMemStr)

   ''   ' ..............................................
   ''   ' Выделение из имени параметра имени структуры
   ''   ' ..............................................
   ii = 0
   For i = 0 To .Rows.Count - 1
    ParName = Trim(.Rows(i)("NamePar"))
    If (.Rows(i)("IdAdaptersType") = VMIPCI5587A Or _
        .Rows(i)("IdAdaptersType") = VMIPCI5565 Or _
        .Rows(i)("IdAdaptersType") = RMe_02) And _
        toDEC(.Rows(i)("Location")) = this_IPC Then
      ii = ii + 1
      iRefMemStr(ii) = Seach_struct(ParName)
    End If
   Next i
   ' ..............................................

   ' ..............................................
   ' Замена повторяющихся имен структур на ""
   ' ..............................................
   For jj = 1 To nRefMemStr
    If iRefMemStr(jj) = "" Then GoTo cont_jj
    For ii = jj + 1 To nRefMemStr
     If iRefMemStr(jj) = iRefMemStr(ii) Then iRefMemStr(ii) = ""
    Next ii
cont_jj:
   Next jj
   ' ..............................................

   ' .........................................................................
   ' Определение кол-ва структур адаптера VMIPCI5587A || VMIPCI5565 || RMe_02
   ' .........................................................................
   jj = 0
   For ii = 1 To nRefMemStr
    If iRefMemStr(ii) <> "" Then
     jj = jj + 1
     indexRefMemStr(jj) = ii
    End If
   Next ii
   nRefMemStr = jj
   ' ..............................................

   ' ..............................................
   ' Удаление повторяющихся имен структур
   ' ..............................................
   For ii = 1 To nRefMemStr
    iRefMemStr(ii) = iRefMemStr(indexRefMemStr(ii))
   Next ii
   ' ..............................................

   ' ..............................................
   ' Определение смещения начала структур в ShareMem
   ' ..............................................
   For jj = 1 To nRefMemStr
    indexRefMemStr(jj) = &H7FFFFFFF
    For ii = 0 To NumRec - 1
     ss = Seach_struct(ShareMemAddress(ii).ParName)
     If ss = iRefMemStr(jj) And ShareMemAddress(ii).Offset < indexRefMemStr(jj) Then
      indexRefMemStr(jj) = ShareMemAddress(ii).Offset
     End If
    Next ii
   Next jj
   ' ..............................................

   fileCreate.WriteLine("")
   fileCreate.WriteLine("--------------------------------------------------------------------")
   fileCreate.WriteLine("BD_RS.mdb имеет" + Format(nRefMemStr, " 0") + " структур ад. VMIPCI5587A/5565 или RMe_02 ")
   fileCreate.WriteLine("--------------------------------------------------------------------")
   fileCreate.WriteLine("  NN  OffSet(ShMem)    StrName  ")
   fileCreate.WriteLine("--------------------------------------------------------------------")
   For ii = 1 To nRefMemStr
    fileCreate.WriteLine(Format(ii, "  0000    ") + MkStrHex(indexRefMemStr(ii)) + "       " + iRefMemStr(ii))
   Next ii
   fileCreate.WriteLine("--------------------------------------------------------------------")

   ' ..............................................
   ' Расчет относительного смещения для элементов
   ' структур в RefMem и запись полученных значений
   ' в столбец "SubAddress" таблицы parameter_where
   ' база данных Bd_rs.mdb
   ' ..............................................
   fileCreate.WriteLine("")
   fileCreate.WriteLine("--------------------------------------------------------------------")
   fileCreate.WriteLine("  NN   NoSM   OffSet(Str)  OffSet(RfMem)  ParName  ")
   fileCreate.WriteLine("--------------------------------------------------------------------")

   mm = 0 : W = 0

   For i = 0 To .Rows.Count - 1

    mm = mm + 1

    ParName = Trim(.Rows(i)("NamePar"))
    If (.Rows(i)("IdAdaptersType") = VMIPCI5587A Or _
        .Rows(i)("IdAdaptersType") = VMIPCI5565 Or _
        .Rows(i)("IdAdaptersType") = RMe_02) And _
        toDEC(.Rows(i)("Location")) = this_IPC Then
     ss = Seach_struct(ParName)
     For ii = 1 To nRefMemStr
      If ss = iRefMemStr(ii) Then jj = ii
     Next ii

     suspect_data = 1

     For ii = 0 To NumRec - 1
      If Trim(.Rows(i)("NamePar")) = ShareMemAddress(ii).ParName Then
       fileCreate.WriteLine(Format(mm, "00000 ") + Format(ii, " 00000   ") + _
       MkStrHex(ShareMemAddress(ii).Offset - indexRefMemStr(jj)) + "   " + _
       MkStrHex(toDEC(.Rows(i)("Address")) + ShareMemAddress(ii).Offset - _
       indexRefMemStr(jj)) + "    " + Trim(.Rows(i)("NamePar")))
       .Rows(i)("SubAddress") = ShareMemAddress(ii).Offset - indexRefMemStr(jj)
       suspect_data = 0
      End If
     Next ii

     If (suspect_data <> 0) Then
      v1 = toDEC(.Rows(i)("Address"))
      v2 = toDEC(.Rows(i)("SubAddress"))
      W = W + 1
#If DISP > 0 Then ' DISP_IO.exe  Start BLOCK
      frm_main.lbl_lamp(3).Text = CStr(W)
#End If ' DISP_IO.exe Finish BLOCK
      If 0 <= v1 And v1 < RefMemSize And 0 <= v2 And v2 < RefMemSize Then
       v = v1 + v2
       If 0 <= v And v < RefMemSize Then
        fileCreate.WriteLine(Format(mm, "00000 ") + " -----   ----------   " + _
                              MkStrHex(v) + "    " + Trim(.Rows(i)("NamePar")))
#If DISP > 0 Then ' DISP_IO.exe  Start BLOCK
        If frm_main.lbl_lamp(3).BackColor = SelColor(0) Then
         frm_main.lbl_lamp(3).BackColor = SelColor(1)
        End If
#End If ' DISP_IO.exe Finish BLOCK
       Else
        fileCreate.WriteLine(Format(mm, "00000 ") + " Address" + " + " + "SubAddress" + _
         " > RefMemSize" + "  " + Trim(.Rows(i)("NamePar")))
#If DISP > 0 Then ' DISP_IO.exe  Start BLOCK
        frm_main.lbl_lamp(3).BackColor = SelColor(3)
#End If ' DISP_IO.exe Finish BLOCK
       End If
      Else
       fileCreate.WriteLine(Format(mm, "00000 ") + " Address" + " + " + "SubAddress" + _
        " > RefMemSize" + "  " + Trim(.Rows(i)("NamePar")))
#If DISP > 0 Then ' DISP_IO.exe  Start BLOCK
       frm_main.lbl_lamp(3).BackColor = SelColor(3)
#End If ' DISP_IO.exe Finish BLOCK
      End If
     End If
    End If

   Next i
   ' ..............................................
   fileCreate.WriteLine("--------------------------------------------------------------------")
   fileCreate.WriteLine("")

finish_RF:

   ' Подсчет кол-ва параметров в табл. parameter_where БД BD_RS.mdb
   ' ---------------------------------------------------------------------------------
   ir_in = 0 : ir_out = 0

   ReDim IPCtoDLL.param_in(0) : ReDim IPCtoDLL.param_in(0).glob.FullParam(2)
   ReDim IPCtoDLL.param_out(0) : ReDim IPCtoDLL.param_out(0).glob.FullParam(2)

   For i = 0 To .Rows.Count - 1
    If Val(.Rows(i)("InOut")) = 0 Then ' Выходной параметр
     ' Если подадрес параметра относящегося к адаптеру TX6-PC-C = 0,
     ' то установить параметр входным, т.е. в поле InOut таблицы parameter_where записать 1
     If Val(.Rows(i)("SubAddress")) = 0 And Val(.Rows(i)("IdAdaptersType")) = TX6_PC_C Then
      ir_in = ir_in + 1
     Else
      ir_out = ir_out + 1
     End If
    Else                         ' Входной параметр
     ir_in = ir_in + 1
    End If
   Next i
   ' ---------------------------------------------------------------------------------

   ReDim IPCtoDLL.param_in(ir_in - 1)
   ReDim IPCtoDLL.param_out(ir_out - 1)

   For i = 0 To ir_in - 1
    ReDim IPCtoDLL.param_in(i).glob.FullParam(2)
   Next

   For i = 0 To ir_out - 1
    ReDim IPCtoDLL.param_out(i).glob.FullParam(2)
   Next

   iir_in = ir_in : iir_out = ir_out
   ir_in = 0 : ir_out = 0 : mm = 0

   ''   ' Расчет глобальных номеров
   fileCreate.WriteLine("---------------------------------------------------------------------------------------------------------------------------------")
   fileCreate.WriteLine(" Полный список переменных из табл. parameter_where БД BD_RS.mdb")
   fileCreate.WriteLine(" Переменные имеющие прочерки в колонках NoSM, OffSet(ShMem), CodePar не связаны с моделями")
   fileCreate.WriteLine("")
   fileCreate.WriteLine(" NN  : номер по порядку в табл. parameter_where БД BD_RS.mdb")
   fileCreate.WriteLine(" ind : номер параметра в списке выходных/входных")
   fileCreate.WriteLine(" NoSM : номер параметра в списке получаемом с ShMem этой IPC (прочерк, если параметра в ShMem нет)")
   fileCreate.WriteLine(" OffSet(ShMem) : смещение параметра в ShMem этой IPC")
   fileCreate.WriteLine(" CodePar : код параметра, выдаваемый моделью в ShMem этой IPC")
   fileCreate.WriteLine(" idpar : уникальный идентификатор параметра в БД BD_RS.mdb")
   fileCreate.WriteLine(" tAd : тип адаптера")
   fileCreate.WriteLine(" FullParam : глобальная структура параметра")
   fileCreate.WriteLine(" Rep : кол-во повторений имени модельного параметра в табл. parameter_where БД BD_RS.mdb")
   fileCreate.WriteLine(" IO_BD : параметр вх./вых. (1/0 соотв.) в в табл. parameter_where БД BD_RS.mdb")
   fileCreate.WriteLine(" IO_SM : параметра вх./вых. (1/0 соотв.) в Share Memory")
   fileCreate.WriteLine(" Name : имя параметра")
   fileCreate.WriteLine("---------------------------------------------------------------------------------------------------------------------------------")
   fileCreate.WriteLine(" NumPC NN   ind  NoSM  OffSet(ShMem) CodePar  idpar   tAd             FullParam               Rep  IO_BD IO_SM  Sync  Name")
   fileCreate.WriteLine("---------------------------------------------------------------------------------------------------------------------------------")

   For i = 0 To .Rows.Count - 1
    ParName = Trim(.Rows(i)("NamePar"))
    ' ''Debug.Print("i: " + CStr(i) + " idpar:" + CStr(.Rows(i)("IdPar")) + " Name: " + ParName)
    For ii = 0 To NumRec - 1 ' : Debug.Print("Shm: " + ShareMemAddress(ii).ParName)
     If ParName = ShareMemAddress(ii).ParName And ParName <> "" Then
      ShareMemAddress(ii).ExistName = ShareMemAddress(ii).ExistName + 1
      Exit For
     End If
    Next ii
    Call calc_GlobNumPar(rs, i)
    mm = mm + 1
    v = Val(Val(.Rows(i)("Location")))
    If Val(.Rows(i)("InOut")) = 0 Then ' Выходной параметр
     If Val(.Rows(i)("SubAddress")) = 0 And Val(.Rows(i)("IdAdaptersType")) = TX6_PC_C Then
      ' считать входным
      IPCtoDLL.param_in(ir_in).idpar = .Rows(i)("IdPar")    ' Id Par
      IPCtoDLL.param_in(ir_in).scal = .Rows(i)("Scale")     ' Scal
      IPCtoDLL.param_in(ir_in).Sync = .Rows(i)("Sync")      ' Sync
      GN.FullParam(0) = GN.FullParam(0) Or &H1        ' Установить параметр входным
      IPCtoDLL.param_in(ir_in).glob.FullParam(0) = GN.FullParam(0)
      IPCtoDLL.param_in(ir_in).glob.FullParam(1) = GN.FullParam(1)
      IPCtoDLL.param_in(ir_in).glob.FullParam(2) = GN.FullParam(2)
      If ii <> NumRec Then
       IPCtoDLL.param_in(ir_in).Offset = ShareMemAddress(ii).Offset
       IPCtoDLL.param_in(ir_in).CodePar = ShareMemAddress(ii).CodePar
       IPCtoDLL.param_in(ir_in).Direct = ShareMemAddress(ii).Direction
       fileCreate.WriteLine( _
                            Format(v, "  00 ") _
                            + Format(mm, "00000 ") _
                            + Format(ir_in + 1, "00000 ") _
                            + Format(ii + 1, "00000  ") _
                            + MkStrHex(IPCtoDLL.param_in(ir_in).Offset) _
                            + Format(IPCtoDLL.param_in(ir_in).CodePar, "     00  ") _
                            + Format(IPCtoDLL.param_in(ir_in).idpar, "  0000000  ") _
                            + Format(.Rows(i)("IdAdaptersType"), "00") _
                            + "   " + MkStrHex(IPCtoDLL.param_in(ir_in).glob.FullParam(0)) _
                            + " " + MkStrHex(IPCtoDLL.param_in(ir_in).glob.FullParam(1)) _
                            + " " + MkStrHex(IPCtoDLL.param_in(ir_in).glob.FullParam(2)) _
                            + Format(ShareMemAddress(ii).ExistName, "   00  ") _
                            + "   1 " _
                            + Format(ShareMemAddress(ii).Direction, "    00   ") _
                            + Format(IPCtoDLL.param_in(ir_in).Sync, " 00   ") _
                            + ParName)
      Else
       IPCtoDLL.param_in(ir_in).Offset = 0
       IPCtoDLL.param_in(ir_in).CodePar = CodeTypeParam(.Rows(i)("Type"))
       IPCtoDLL.param_in(ir_in).Direct = -1
       fileCreate.WriteLine( _
                            Format(v, "  00 ") _
                            + Format(mm, "00000 ") _
                            + Format(ir_in + 1, "00000 ") _
                            + "    -  " _
                            + "         -" _
                            + Format(IPCtoDLL.param_in(ir_in).CodePar, "     00  ") _
                            + Format(IPCtoDLL.param_in(ir_in).idpar, "  0000000  ") _
                            + Format(.Rows(i)("IdAdaptersType"), "00") _
                            + "   " + MkStrHex(IPCtoDLL.param_in(ir_in).glob.FullParam(0)) _
                            + " " + MkStrHex(IPCtoDLL.param_in(ir_in).glob.FullParam(1)) _
                            + " " + MkStrHex(IPCtoDLL.param_in(ir_in).glob.FullParam(2)) _
                            + "    -  " _
                            + "   1 " _
                            + "     -   " _
                            + Format(IPCtoDLL.param_in(ir_in).Sync, " 00   ") _
                            + ParName)
      End If
      ir_in = ir_in + 1
     Else
      ' Считать выходным
      IPCtoDLL.param_out(ir_out).idpar = .Rows(i)("IdPar")  ' IdPar
      IPCtoDLL.param_out(ir_out).scal = .Rows(i)("Scale")   ' Scale
      IPCtoDLL.param_out(ir_out).Sync = .Rows(i)("Sync")     ' Sync
      IPCtoDLL.param_out(ir_out).glob.FullParam(0) = GN.FullParam(0)
      IPCtoDLL.param_out(ir_out).glob.FullParam(1) = GN.FullParam(1)
      IPCtoDLL.param_out(ir_out).glob.FullParam(2) = GN.FullParam(2)
      If ii <> NumRec Then
       IPCtoDLL.param_out(ir_out).Offset = ShareMemAddress(ii).Offset
       IPCtoDLL.param_out(ir_out).CodePar = ShareMemAddress(ii).CodePar
       IPCtoDLL.param_out(ir_out).Direct = ShareMemAddress(ii).Direction
       fileCreate.WriteLine( _
                            Format(v, "  00 ") _
                            + Format(mm, "00000 ") _
                            + Format(ir_out + 1, "00000 ") _
                            + Format(ii + 1, "00000  ") _
                            + MkStrHex(IPCtoDLL.param_out(ir_out).Offset) _
                            + Format(IPCtoDLL.param_out(ir_out).CodePar, "     00  ") _
                            + Format(IPCtoDLL.param_out(ir_out).idpar, "  0000000  ") _
                            + Format(.Rows(i)("IdAdaptersType"), "00") _
                            + "   " + MkStrHex(IPCtoDLL.param_out(ir_out).glob.FullParam(0)) _
                            + " " + MkStrHex(IPCtoDLL.param_out(ir_out).glob.FullParam(1)) _
                            + " " + MkStrHex(IPCtoDLL.param_out(ir_out).glob.FullParam(2)) _
                            + Format(ShareMemAddress(ii).ExistName, "   00  ") _
                            + "   0 " _
                            + Format(ShareMemAddress(ii).Direction, "    00   ") _
                            + Format(IPCtoDLL.param_out(ir_out).Sync, " 00   ") _
                            + ParName)
      Else
       IPCtoDLL.param_out(ir_out).Offset = 0
       IPCtoDLL.param_out(ir_out).CodePar = CodeTypeParam(.Rows(i)("Type"))
       IPCtoDLL.param_out(ir_out).Direct = -1
       fileCreate.WriteLine( _
                            Format(v, "  00 ") _
                            + Format(mm, "00000 ") _
                            + Format(ir_out + 1, "00000 ") _
                            + "    -  " _
                            + "         -" _
                            + Format(IPCtoDLL.param_out(ir_out).CodePar, "     00  ") _
                            + Format(IPCtoDLL.param_out(ir_out).idpar, "  0000000  ") _
                            + Format(.Rows(i)("IdAdaptersType"), "00") _
                            + "   " + MkStrHex(IPCtoDLL.param_out(ir_out).glob.FullParam(0)) _
                            + " " + MkStrHex(IPCtoDLL.param_out(ir_out).glob.FullParam(1)) _
                            + " " + MkStrHex(IPCtoDLL.param_out(ir_out).glob.FullParam(2)) _
                            + "    -  " _
                            + "   0 " _
                            + "     -   " _
                            + Format(IPCtoDLL.param_out(ir_out).Sync, " 00   ") _
                            + ParName)
      End If
      ir_out = ir_out + 1
     End If
    Else                         ' Входной параметр
     IPCtoDLL.param_in(ir_in).idpar = .Rows(i)("IdPar")    ' Id Par
     IPCtoDLL.param_in(ir_in).scal = .Rows(i)("Scale")     ' Scal
     IPCtoDLL.param_in(ir_in).Sync = .Rows(i)("Sync")      ' Sync
     IPCtoDLL.param_in(ir_in).glob.FullParam(0) = GN.FullParam(0)
     IPCtoDLL.param_in(ir_in).glob.FullParam(1) = GN.FullParam(1)
     IPCtoDLL.param_in(ir_in).glob.FullParam(2) = GN.FullParam(2)
     If ii <> NumRec Then
      IPCtoDLL.param_in(ir_in).Offset = ShareMemAddress(ii).Offset
      IPCtoDLL.param_in(ir_in).CodePar = ShareMemAddress(ii).CodePar
      IPCtoDLL.param_in(ir_in).Direct = ShareMemAddress(ii).Direction
      fileCreate.WriteLine( _
                           Format(v, "  00 ") _
                           + Format(mm, "00000 ") _
                           + Format(ir_in + 1, "00000 ") _
                           + Format(ii + 1, "00000  ") _
                           + MkStrHex(IPCtoDLL.param_in(ir_in).Offset) _
                           + Format(IPCtoDLL.param_in(ir_in).CodePar, "     00  ") _
                           + Format(IPCtoDLL.param_in(ir_in).idpar, "  0000000  ") _
                           + Format(.Rows(i)("IdAdaptersType"), "00") _
                           + "   " + MkStrHex(IPCtoDLL.param_in(ir_in).glob.FullParam(0)) _
                           + " " + MkStrHex(IPCtoDLL.param_in(ir_in).glob.FullParam(1)) _
                           + " " + MkStrHex(IPCtoDLL.param_in(ir_in).glob.FullParam(2)) _
                           + Format(ShareMemAddress(ii).ExistName, "   00  ") _
                           + "   1 " _
                           + Format(ShareMemAddress(ii).Direction, "    00   ") _
                           + Format(IPCtoDLL.param_in(ir_in).Sync, " 00   ") _
                           + ParName)
     Else
      IPCtoDLL.param_in(ir_in).Offset = 0
      IPCtoDLL.param_in(ir_in).CodePar = CodeTypeParam(.Rows(i)("Type"))
      IPCtoDLL.param_in(ir_in).Direct = -1
      fileCreate.WriteLine( _
                            Format(v, "  00 ") _
                            + Format(mm, "00000 ") _
                           + Format(ir_in + 1, "00000 ") _
                           + "    -  " _
                           + "         -" _
                            + Format(IPCtoDLL.param_in(ir_in).CodePar, "     00  ") _
                           + Format(IPCtoDLL.param_in(ir_in).idpar, "  0000000  ") _
                           + Format(.Rows(i)("IdAdaptersType"), "00") _
                           + "   " + MkStrHex(IPCtoDLL.param_in(ir_in).glob.FullParam(0)) _
                           + " " + MkStrHex(IPCtoDLL.param_in(ir_in).glob.FullParam(1)) _
                           + " " + MkStrHex(IPCtoDLL.param_in(ir_in).glob.FullParam(2)) _
                            + "    -  " _
                            + "   1 " _
                            + "     -   " _
                            + Format(IPCtoDLL.param_in(ir_in).Sync, " 00   ") _
                           + ParName)
     End If
     ir_in = ir_in + 1
    End If
   Next i
   fileCreate.WriteLine("---------------------------------------------------------------------------------------------------------------------------------")
   fileCreate.WriteLine("")

   fileCreate.WriteLine("---------------------------------------------------------------------------------------------------------------------------------")
   fileCreate.WriteLine("Nin : " + Format(ir_in, "0") + " Nout : " + Format(ir_out, "0") + "  Nin+Nout: " + Format(ir_in + ir_out, "0"))
   fileCreate.WriteLine("---------------------------------------------------------------------------------------------------------------------------------")
   fileCreate.WriteLine("")

  End With

  i = 0
  For ii = 0 To NumRec - 1
   If ii = 0 Then
    fileCreate.WriteLine("--------------------------------------------------------")
    fileCreate.WriteLine("Следующие имена модельных переменных не обнаружены в БД")
    fileCreate.WriteLine("--------------------------------------------------------")
    fileCreate.WriteLine(" NN   NoSM  Code   Rep InOut  Name")
    fileCreate.WriteLine("--------------------------------------------------------")
   End If
   If ShareMemAddress(ii).ExistName < 1 Then
    i = i + 1
    fileCreate.WriteLine(Format(i, "00000 ") _
                        + Format(ii + 1, "00000 ") _
                        + Format(ShareMemAddress(ii).CodePar, " 00  ") _
                        + Format(ShareMemAddress(ii).ExistName, "  00  ") _
                        + Format(ShareMemAddress(ii).Direction, "  00   ") _
                        + ShareMemAddress(ii).ParName)
   End If
  Next ii

  fileCreate.WriteLine("--------------------------------------------------------")
  fileCreate.WriteLine(" В БД не обнаружено : " + Format(i, "0") + " мод. парам.")
  fileCreate.WriteLine("--------------------------------------------------------")
  fileCreate.WriteLine("")

  '' ''If i > 0 Then
  '' '' Call MsgBox("Не обнаружено в БД " + CStr(i) + " имен параметров", vbCritical, "I P C . e x e    a d v i s e :")
  '' ''End If

  i = 0
  For ii = 0 To NumRec - 1
   If ii = 0 Then
    fileCreate.WriteLine("---------------------------------------------------------------")
    fileCreate.WriteLine("Следующие имена модельных переменных обнаружены в БД многократно")
    fileCreate.WriteLine("---------------------------------------------------------------")
    fileCreate.WriteLine("   N   No   Code   Rep    Name")
    fileCreate.WriteLine("---------------------------------------------------------------")
   End If
   If ShareMemAddress(ii).ExistName > 1 Then
    i = i + 1
    fileCreate.WriteLine(Format(i, "00000 ") _
                        + Format(ii + 1, "00000 ") _
                        + Format(ShareMemAddress(ii).CodePar, " 00  ") _
                        + Format(ShareMemAddress(ii).ExistName, "  00  ") _
                        + ShareMemAddress(ii).ParName)
   End If
  Next ii

  fileCreate.WriteLine("---------------------------------------------------------------")
  fileCreate.WriteLine(" В БД обнаружено многократно: " + Format(i, "0") + " мод.парам.")
  fileCreate.WriteLine("---------------------------------------------------------------")

  ' If i > 0 Then
  '  Call MsgBox("Обнаружено многократно в БД " + CStr(i) + " имен параметров", vbCritical, "I P C . e x e    a d v i s e :")
  ' End If


  If ir_in <> iir_in Then
   If CONF_RIG <> 6 Then MsgBox("Проблема с подсчетом кол-ва входных параметров", vbCritical, "mdl_main/read_GlobNumPar")
  End If
  If ir_out <> iir_out Then
   If CONF_RIG <> 6 Then MsgBox("Проблема с подсчетом кол-ва выходных параметров", vbCritical, "mdl_main/read_GlobNumPar")
  End If

  in_parameters_number = ir_in
  out_parameters_number = ir_out

#If DISP > 0 Then ' DISP_IO.exe  Start BLOCK
  'Подключение к БД на заполнение колонки "SubAddress"
  If BD_RS_connect.State = ConnectionState.Closed Then BD_RS_connect.Open()
  BD_RS_Adapter_Q_param.UpdateCommand.Parameters.Add("@SubAddress", OleDb.OleDbType.Variant, rs.Rows.Count - 1, "SubAddress")
  BD_RS_Adapter_Q_param.UpdateCommand.Parameters.Add("@IdPar", OleDb.OleDbType.Variant, rs.Rows.Count - 1, "IdPar")
  BD_RS_Adapter_Q_param.Update(BD_RS_DataSET.Tables("qPARAMETER"))
  BD_RS_Adapter_Q_param.UpdateCommand.Parameters.Clear()
  BD_RS_connect.Close()
#End If ' DISP_IO.exe Finish BLOCK

  rs.Dispose() : rs = Nothing

  Exit Sub

err_handler:
  ' -----------------------------------------
  ' Процедура обработки ошибки
  ' -----------------------------------------
  MsgBox("Module_main/read_GlobNumPar" + vbCrLf + "err=" + CStr(Err.Number) + vbCrLf + Err.Description, vbCritical)

  in_parameters_number = ir_in
  out_parameters_number = ir_out

  ' Установка фактического размера динамич. массива

  ReDim IPCtoDLL.param_in(ir_in)
  ReDim IPCtoDLL.param_out(ir_out)

  rs.Dispose() : rs = Nothing

 End Sub


 Public Sub calc_GlobNumPar(ByVal rs As DataTable, ByVal iRow As Int32)
  Dim W, wmask, ww1, ww2, ww3 As Int32
  Dim Location, IdAdaptersType, LocNum, NumLine, NumWord, Address, SubAddress, _
      LBit, Hbit, NumLowBit, scal, SignBit1, SignBit2, InOut, idpar, IdBurst, _
      TypePack, CheckWord
  Dim NameField As String

  With rs

   ' -----------------------------------------
   ' Переход на процедуру обработки ошибки
   ' -----------------------------------------

   On Error GoTo err_handler
   ' -----------------------------------------

   ww1 = 0 : ww2 = 0 : ww3 = 0 : LocNum = 0


   NameField = "Location" : Location = Val(.Rows(iRow)("Location")) - 1
   If LocNum < 0 Then LocNum = &HF
   Location = Location And &HF
   NameField = "IdAdaptersType" : IdAdaptersType = Val(.Rows(iRow)("IdAdaptersType"))
   NameField = "LocNum" : LocNum = Val(.Rows(iRow)("LocNum")) - 1
   NameField = "NumLine" : NumLine = Val(.Rows(iRow)("NumLine")) - 1
   NameField = "NumWord" : NumWord = Val(.Rows(iRow)("NumWord"))
   NameField = "Address" : Address = toDEC(.Rows(iRow)("Address"))
   NameField = "SubAddress" : SubAddress = toDEC(.Rows(iRow)("SubAddress"))
   NameField = "LowBit" : LBit = Val(.Rows(iRow)("LowBit"))
   NameField = "HiBit" : Hbit = Val(.Rows(iRow)("HiBit"))
   NameField = "NumLowBit" : NumLowBit = Val(.Rows(iRow)("NumLowBit"))
   NameField = "Scale" : scal = Val(.Rows(iRow)("Scale"))
   NameField = "SignBit1" : SignBit1 = Val(.Rows(iRow)("SignBit1"))
   NameField = "SignBit2" : SignBit2 = Val(.Rows(iRow)("SignBit2"))
   NameField = "InOut" : InOut = Val(.Rows(iRow)("InOut"))
   NameField = "IdPar" : idpar = Val(.Rows(iRow)("IdPar"))
   NameField = "IdBurst" : IdBurst = Val(.Rows(iRow)("IdBurst"))
   NameField = "CheckWord" : CheckWord = Val(.Rows(iRow)("CheckWord"))
   NameField = "Type"

   ' Перенумерация номеров пакетов
   ' -----------------------------
   For W = 0 To UBound(IdB)
    If IdBurst = IdB(W) Then
     IdBurst = W + 1 : Exit For
    End If
   Next W
   ' -----------------------------

   W = InOut : ww1 = vbInsert_to_w32(ww1, W, 0, 0)            ' InOut
   W = IdAdaptersType : ww1 = vbInsert_to_w32(ww1, W, 26, 31) ' TypeDevice
   W = LocNum : ww1 = vbInsert_to_w32(ww1, W, 23, 25)         ' NumDevice

   W = LBit - NumLowBit : ww2 = vbInsert_to_w32(ww2, W, 0, 4) ' LoBit-NumLowBit ok
   W = Hbit - NumLowBit : ww2 = vbInsert_to_w32(ww2, W, 5, 9) ' HiBit-NumLowBit ok
   W = SignBit1 : If W <> 0 Then W = 1
   ww2 = vbInsert_to_w32(ww2, W, 10, 10)                      ' SignBit1
   W = SignBit2 : If W <> 0 Then W = 1
   ww2 = vbInsert_to_w32(ww2, W, 11, 11)                      ' SignBit2
   W = Location : ww2 = vbInsert_to_w32(ww2, W, 28, 31)        ' NumPC

   Select Case IdAdaptersType

    Case TX6_PC_C

     W = Address : ww1 = vbInsert_to_w32(ww1, W, 18, 22)     ' Address ok
     W = SubAddress : ww1 = vbInsert_to_w32(ww1, W, 11, 15)  ' SubAddress ok
     W = NumWord : ww1 = vbInsert_to_w32(ww1, W, 6, 10)      ' NumWord ok
     W = CheckWord : ww1 = vbInsert_to_w32(ww1, W, 16, 17)   ' mtDirection ok
     W = IdBurst : ww2 = vbInsert_to_w32(ww2, W, 12, 27)     ' IdBurst ok

    Case iMKIO_1

     W = NumLine Mod 2 : ww1 = vbInsert_to_w32(ww1, W, 1, 1)     ' Bus ok
     W = NumWord : ww1 = vbInsert_to_w32(ww1, W, 5, 9)       ' NumWord ok
     W = SubAddress : ww1 = vbInsert_to_w32(ww1, W, 10, 14)  ' SubAddress ok
     W = CheckWord : ww1 = vbInsert_to_w32(ww1, W, 15, 17)   ' mtDirection ok
     W = Address : ww1 = vbInsert_to_w32(ww1, W, 18, 22)     ' Address ok

    Case PC429_3_88

     W = NumLine : ww1 = vbInsert_to_w32(ww1, W, 19, 22)     ' NumChannel
     W = NumWord - 1 : ww1 = vbInsert_to_w32(ww1, W, 11, 18) ' NumWord
     W = Address : ww1 = vbInsert_to_w32(ww1, W, 3, 10)      ' Address
     If CheckWord <> 0 Then
      W = 1 ' Адрес из 8-ми младших бит слова данных
     Else
      W = 0 ' Адрес из поля Address
     End If
     ww1 = vbInsert_to_w32(ww1, W, 1, 1)                     ' AddrFromData
     If SubAddress = 1 Then
      W = 0 ' Сформировать пробел на месте слова
     Else
      W = 1 ' Выдать слово
     End If
     ww1 = vbInsert_to_w32(ww1, W, 2, 2)                    ' Gap

    Case PC429_4_xx

     W = NumLine : ww1 = vbInsert_to_w32(ww1, W, 19, 22)     ' NumChannel
     W = NumWord - 1 : ww1 = vbInsert_to_w32(ww1, W, 11, 18) ' NumWord
     W = Address : ww1 = vbInsert_to_w32(ww1, W, 3, 10)      ' Address
     If CheckWord <> 0 Then
      W = 1 ' Адрес из 8-ми младших бит слова данных
     Else
      W = 0 ' Адрес из поля Address
     End If
     ww1 = vbInsert_to_w32(ww1, W, 1, 1)                     ' AddrFromData
     If SubAddress = 0 Then
      W = 1 ' Выдать слово
     Else
      W = 0 ' Сформировать пробел на месте слова
     End If
     ww1 = vbInsert_to_w32(ww1, W, 2, 2)                    ' Gap

     ''Case PCL_836

     '' W = NumLine + 1 : ww1 = vbInsert_to_w32(ww1, W, 20, 22) ' NumLine

    Case PCADS_05

     If CheckWord <> 0 Then
      W = 1 ' Адрес из 8-ми младших бит слова данных
     Else
      W = 0 ' Адрес из поля Address
     End If
     ww1 = vbInsert_to_w32(ww1, W, 1, 1)                     ' AddrFromData

     W = NumWord - 1 : ww1 = vbInsert_to_w32(ww1, W, 11, 18) ' NumWord
     W = Address : ww1 = vbInsert_to_w32(ww1, W, 3, 10)      ' Address
     If SubAddress = 0 Then
      W = 1 ' Выдать слово
     Else
      W = 0 ' Сформировать пробел на месте слова
     End If
     ww1 = vbInsert_to_w32(ww1, W, 2, 2)                    ' Gap
     W = NumLine : ww2 = vbInsert_to_w32(ww2, W, 12, 18)    ' NumChannel



    Case PCADSv7RTMin

     If CheckWord <> 0 Then
      W = 1 ' Адрес из 8-ми младших бит слова данных
     Else
      W = 0 ' Адрес из поля Address
     End If
     ww1 = vbInsert_to_w32(ww1, W, 1, 1)                     ' AddrFromData

     W = NumWord - 1 : ww1 = vbInsert_to_w32(ww1, W, 11, 18) ' NumWord
     W = Address : ww1 = vbInsert_to_w32(ww1, W, 3, 10)      ' Address
     If SubAddress = 0 Then
      W = 1 ' Выдать слово
     Else
      W = 0 ' Сформировать пробел на месте слова
     End If
     ww1 = vbInsert_to_w32(ww1, W, 2, 2)                    ' Gap
     W = NumLine : ww2 = vbInsert_to_w32(ww2, W, 12, 17)    ' NumChannel

    Case PCADSv7RTMout

     If CheckWord <> 0 Then
      W = 1 ' Адрес из 8-ми младших бит слова данных
     Else
      W = 0 ' Адрес из поля Address
     End If
     ww1 = vbInsert_to_w32(ww1, W, 1, 1)                     ' AddrFromData

     W = NumWord - 1 : ww1 = vbInsert_to_w32(ww1, W, 11, 18) ' NumWord
     W = Address : ww1 = vbInsert_to_w32(ww1, W, 3, 10)      ' Address
     If SubAddress = 0 Then
      W = 1 ' Выдать слово
     Else
      W = 0 ' Сформировать пробел на месте слова
     End If
     ww1 = vbInsert_to_w32(ww1, W, 2, 2)                    ' Gap
     W = NumLine : ww2 = vbInsert_to_w32(ww2, W, 12, 17)    ' NumChannel

    Case PCADS_05RK
     'Тут
     W = Address - 1 : ww1 = vbInsert_to_w32(ww1, W, 1, 6)   ' Channel
     W = SubAddress : ww1 = vbInsert_to_w32(ww1, W, 7, 7) ' Logic
     W = NumWord : ww1 = vbInsert_to_w32(ww1, W, 8, 9)    ' Address

    Case PCADS_v7RK
     'Тут
     W = Address - 1 : ww1 = vbInsert_to_w32(ww1, W, 1, 6) ' Channel
     W = SubAddress : ww1 = vbInsert_to_w32(ww1, W, 7, 7)  ' Logic
     W = NumWord : ww1 = vbInsert_to_w32(ww1, W, 8, 9)     ' Address
     W = NumLine : ww1 = vbInsert_to_w32(ww1, W, 10, 13)   ' Line

    Case SPECIAL

     W = Address : ww1 = vbInsert_to_w32(ww1, W, 1, 22)      ' Address
     W = CodeTypeParam(.Rows(iRow)("Type")) : ww2 = vbInsert_to_w32(ww2, W, 12, 19) 'TypePack

    Case PCI_ASTRA

     W = Address : ww1 = vbInsert_to_w32(ww1, W, 1, 18)      ' Address
     W = SubAddress : ww1 = vbInsert_to_w32(ww1, W, 19, 19)  ' Update

    Case PCI_ASTRA_BL

     W = Address : ww1 = vbInsert_to_w32(ww1, W, 1, 18)      ' Address
     W = NumWord : ww1 = vbInsert_to_w32(ww1, W, 20, 22)  ' NumWord

    Case PCI_1753

     W = NumLine : ww1 = vbInsert_to_w32(ww1, W, 18, 22)     ' NumLine
     W = SubAddress : ww1 = vbInsert_to_w32(ww1, W, 14, 14)  ' SubAddress
     W = Address - 1 : ww1 = vbInsert_to_w32(ww1, W, 15, 17) ' Address

    Case VMIPCI5587A

     W = Address + SubAddress : ww1 = vbInsert_to_w32(ww1, W, 1, 22)            ' Address
     W = LBit : ww2 = vbInsert_to_w32(ww2, W, 0, 1)                             ' Type_INT
     W = Hbit : ww2 = vbInsert_to_w32(ww2, W, 2, 11)                            ' INT_DATA
     W = CodeTypeParam(.Rows(iRow)("Type")) : ww2 = vbInsert_to_w32(ww2, W, 12, 19) 'TypePack
     W = CheckWord : ww2 = vbInsert_to_w32(ww2, W, 20, 27)                      ' DestNId

    Case VMIPCI5565

     W = LBit : ww1 = vbInsert_to_w32(ww1, W, 1, 3)                             ' Type_INT
     W = CodeTypeParam(.Rows(iRow)("Type")) : ww1 = vbInsert_to_w32(ww1, W, 4, 11)  'TypePack
     W = CheckWord : ww1 = vbInsert_to_w32(ww1, W, 12, 19)                      ' DestNId

     W = Address + SubAddress : ww2 = vbInsert_to_w32(ww2, W, 0, 26)            ' Address

    Case RMe_02
     W = CodeTypeParam(.Rows(iRow)("Type")) : ww1 = vbInsert_to_w32(ww1, W, 4, 8)  'TypePack

     W = CheckWord - 1
     If (W >= 0 And W < 16) Then
      ww1 = vbInsert_to_w32(ww1, 1, 1, 1)                                       ' IsInterrupt
      ww1 = vbInsert_to_w32(ww1, W, 12, 15)                                     ' irq
     End If
     W = NumWord
     If (NumWord >= 0 And NumWord < 4) Then
      ww1 = vbInsert_to_w32(ww1, W, 2, 3)                                       ' Service
     End If

     W = Address + SubAddress : ww2 = vbInsert_to_w32(ww2, W, 0, 23)            ' Offset

    Case PCI_1713 '
     '' InOut          :1;     // признак входной-1/выходной-0 (бит 1)
     '' res_2_9        :8;    // Не реализован SubAddress значение сигнала на входе АЦП в [мв] при подаче на вход делителя 1000мв (биты 2-9)
     '' SignShift      :1;    // знак SubAddress: знак смещения Shift. 0 соотв. "+", 1 соотв. "-" (биты 10-10)
     '' Shift          :8;    // модуль SubAddress: смещение в единицах младшего разряда, добавляемое измеренному значению (биты 11-18)
     '' NumChannel     :5;     // Address c 1- Номер канала адаптера (биты 19-23) (Порты ввода-вывода пронумерованные насквозь для адаптера)
     '' NumDevice      :3;     // c 1- Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
     '' TypeDevice     :6;     // 20 Тип адаптера (биты 27,28,29,30,31,32)

     '' LoBit          :5; // младший бит параметра (с 1-го) (биты 1-5)
     '' HiBit          :5; // старший бит параметра (с 1-го) (биты 6-10)
     '' SignBit1       :1; // 1-й знаковый бит (бит 11)
     '' SignBit2       :1; // 2-й знаковый бит (бит 12)
     '' bit13_28       :16;// Заполнение младших разрядов (биты 13-28)
     '' NumPC          :4; // Номер компьютера (биты 29,30,31,32)


     If SubAddress >= 0 Then
      If SubAddress > 255 Then SubAddress = 255
      W = 0 : ww1 = vbInsert_to_w32(ww1, W, 9, 9)            ' Знак смещения 0: положит. 1:отриц.
      W = SubAddress : ww1 = vbInsert_to_w32(ww1, W, 10, 17)  ' Смещение 0 на входе в разрядных единицах
     Else
      If SubAddress < -255 Then SubAddress = -255
      W = 1 : ww1 = vbInsert_to_w32(ww1, W, 9, 9)            ' Знак смещения 0: положит. 1:отриц.
      W = -SubAddress : ww1 = vbInsert_to_w32(ww1, W, 10, 17) ' Смещение 0 на входе в разрядных единицах
     End If
     W = Address - 1 : ww1 = vbInsert_to_w32(ww1, W, 18, 22) ' Номер линии от 1 до 32

    Case PCI_1716 '
     '' InOut          :1; // признак входной-1/выходной-0 (бит 1)
     '' Divider        :17;// Не реализован SubAddress значение сигнала на входе АЦП в [мв] при подаче на вход делителя 1000мв (биты 2-18)
     '' NumChannel     :5; // Address c 1- Номер канала адаптера (биты 19-23) (Порты ввода-вывода пронумерованные насквозь для адаптера)
     '' NumDevice      :3; // c 1- Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
     '' TypeDevice     :6; // 20 Тип адаптера (биты 27,28,29,30,31,32)

     '' LoBit          :5; // младший бит параметра (с 1-го) (биты 1-5)
     '' HiBit          :5; // старший бит параметра (с 1-го) (биты 6-10)
     '' SignBit1       :1; // 1-й знаковый бит (бит 11)
     '' SignBit2       :1; // 2-й знаковый бит (бит 12)
     '' bit13_28       :16;// Заполнение младших разрядов (биты 13-28)
     '' NumPC          :4; // Номер компьютера (биты 29,30,31,32)

     W = Address - 1 : ww1 = vbInsert_to_w32(ww1, W, 18, 22) ' Номер линии от 0 до 31

    Case PCI_1724 '
     '' InOut			       :1; // признак входной-1/выходной-0 (бит 1)
     '' GroupMode		    :2;	// Не реализован 2,3	SubAddress: 0(3) - normal, 1(2)-offset(calibr)  2(1) -Gain mode(calibr)
     '' bit4_6			      :3;	// (1-4)
     '' bit7_18		      :12;//заполнение младших разрядов (биты 7-18)	
     '' NumChannel     :5; // StrDescr.NumWord Номер канала адаптера 0-31 (биты 19,20,21,22,23) (Порты ввода-вывода пронумерованные насквозь для адаптера)
     '' NumDevice      :3;	// Порядковый номер адаптера данного типа в данном РС(биты 24,25,26)
     '' TypeDevice     :6;	// Тип адаптера (биты 27,28,29,30)

     '' LoBit			       :5;        // младший бит параметра (с 1-го) (биты 1-5)
     '' HiBit			       :5;        // старший бит параметра (с 1-го) (биты 6-10)
     '' SignBit1		     :1;	     // 1-й знаковый бит (бит 11)
     '' SignBit2		     :1;	     // 2-й знаковый бит (бит 12)
     '' bit13_28		     :16;     // Заполнение младших разрядов (биты 13-28)
     '' NumPC          :4;	// Номер компьютера (биты 29,30,31,32)

     W = Address - 1 : ww1 = vbInsert_to_w32(ww1, W, 18, 22) ' Номер линии от 0 до 31

     ''Case PCI_1723

    Case CUS_BMK

     ' InOut        :1;  // признак входной-1/выходной-0 (бит 1)
     ' bit2_6       :5;  // заполнение разрядов
     ' bit7_11      :5;  // номер слова (биты 7-11)
     ' bit12_15     :4;  // подадрес (биты 12-15)
     ' Addr         :8;  // (Address) Адрес параметра (биты 16-23)
     ' NumDevice    :3;  // Порядковый номер адаптера данного типа в данном РС(биты 24-26)
     ' TypeDevice   :6;  // Тип адаптера (биты 27-32)

     ' LoBit        :5;  // младмий бит параметра (с 1-го) (биты 1-5)
     ' HiBit        :5;  // старший бит параметра (с 1-го) (биты 6-10)
     ' SignBit1     :1;  // 1-й знаковый бит (бит 11)
     ' SignBit2     :1;  // 2-й знаковый бит (бит 12)
     ' bit13_28     :16; //   (биты 13-28)
     ' NumPC        :4;  // Номер компьютера (биты 29-32)

     W = Address : ww1 = vbInsert_to_w32(ww1, W, 15, 22) ' Address

    Case IPK1

    Case RS485_MTVS

     '   определение параметров для МТВС
     '   ULONG InOut       :1;  // признак входной-1/выходной-0 (бит 1)
     '   ULONG Address     :4;  // адрес МТВС (0х08) (биты 2,3,4,5)
     '   ULONG bit5_23     :18; // пусто (биты 6-23)
     '   ULONG NumDevice   :3;  // Порядковый номер адаптера данного типа в данном РС (начиная с 1)(биты 24,25,26)
     '   ULONG TypeDevice  :6;  // Тип адаптера = 30 (биты 27-32)
     '
     '   ULONG LoBit       :5;  // младший бит параметра (с 1-го) (биты 1-5)
     '   ULONG HiBit       :5;  // старший бит параметра (с 1-го) (биты 6-10)
     '   ULONG SignBit1    :1;  // 1-й знаковый бит (бит 11)
     '   ULONG SignBit2    :1;  // 2-й знаковый бит (бит 12)
     '   ULONG bit13_28    :16; // пусто (биты 13-28)
     '   ULONG NumPC       :4;  // Номер компьютера (биты 29,30,31,32)

     W = Address : ww1 = vbInsert_to_w32(ww1, W, 1, 4) ' адрес МТВС

    Case Else

     W = 0

   End Select

   GN.FullParam(0) = ww1
   GN.FullParam(1) = ww2
   GN.FullParam(2) = ww3

  End With

  Exit Sub

  ' -----------------------------------------
  ' Процедура обработки ошибки
  ' -----------------------------------------
err_handler:
  MsgBox("Module_main/calc_GlobNumPar err=" + CStr(Err.Number) + vbCrLf + Err.Description, vbCritical)
  If Err.Number = 94 Then ' Пустая ячейка
   With rs
    .Rows(iRow)(NameField) = 0
    Resume
   End With
  End If

 End Sub


 Public Sub Init_BD()

  ' При изменение порядка сортировки для "sql_parameter_where"
  ' по первым двум параметрам недопустимо без соотв. изменения в #kssr_func.dll/vbToDll
  ' -----------------------------------------------------------------------------------
  sql_parameter_where = "SELECT * FROM parameter_where ORDER  BY " _
                      + "Location, -InOut, -Sync, IdAdaptersType, " _
                      + "LocNum, NumLine, NumWord, Address, SubAddress, LowBit, HiBit, IdPar"
  sql_qDataBurst = "SELECT * FROM qDataBurst"
  sql_qAdapters = "SELECT * FROM qAdapters ORDER BY Location,IdAdaptersType,LocNum"

  sql_logic_replay = Sort_String()

  Link_BD_RS_init()   '
  Link_RCR_init()     '
#If DISP > 0 Then
  Link_DISP_IO_init() ' DISP_IO.exe  BLOCK
#Else
        Link_DISP_SI_init() ' DISP_SI.exe  BLOCK
#End If

  'Call check_parameters(sql_parameter_where, Db_BD_RS) ' запись в пустые ячейки 0
  'Call check_parameters(sql_qDataBurst, Db_BD_RS)      ' запись в пустые ячейки 0
  'Call check_parameters(sql_qAdapters, Db_BD_RS)       ' запись в пустые ячейки 0
  'Call check_parameters(sql_logic_replay, Db_RCR)      ' запись в пустые ячейки 0

 End Sub

 'ПРОВЕРКА СТРУКТУРЫ ТАБЛИЦЫ logic_replay И ВЫБОР СТОЛБЦА СОРТИРОВКИ
 Public Function Sort_String() As String
  Dim ReadStr As OleDb.OleDbDataReader
  Dim ComStr As New OleDb.OleDbCommand
  Dim NumCol_ As Int32 = 0
  Dim mID_rcr(0) As Int32

  If RCR_connect.State = ConnectionState.Open Then RCR_connect.Close() 'ПРИ ПЕРВОМ ПРОХОДЕ

  RCR_connect.ConnectionString = _
  "Provider=Microsoft.ACE.OLEDB.12.0;" _
  + "Data Source=" + RCR_File ' тип и путь соединения 20.08.19 - переход на новый формат БД

  RCR_connect.Open() 'открыть доступ

  ComStr.CommandText = "select * from logic_replay"
  ComStr.Connection = RCR_connect
  ReadStr = ComStr.ExecuteReader

  Try : NumCol_ = ReadStr.GetOrdinal("NumLine")

  Catch
   'поиск всех id для последующего позиционирования по строкам при нумирации по возрастанию NumLine
   While ReadStr.Read() = True
    If ReadStr.IsDBNull(25) = False Then 'проверка на пустое поле
     mID_rcr(mID_rcr.Count - 1) = ReadStr.GetInt32(ReadStr.GetOrdinal("NoID"))
     ReDim Preserve mID_rcr(mID_rcr.Count)
    End If
   End While

   If ReadStr.IsClosed = False Then ReadStr.Close()
   ComStr.CommandText = "ALTER TABLE logic_replay ADD [Reserve] TEXT(50) null"
   ComStr.ExecuteNonQuery()
   ComStr.CommandText = "ALTER TABLE logic_replay ADD [NumLine] INTEGER NOT NULL DEFAULT 0"
   ComStr.ExecuteNonQuery()

   ComStr.CommandText = "UPDATE logic_replay SET NumLine=@NumLine where NoID = @NoID"

   NumCol_ = 0
   Do While NumCol_ <= mID_rcr.Count - 2
    ComStr.Parameters.AddWithValue("NumLine", (NumCol_ + 1))
    ComStr.Parameters.AddWithValue("NoID", mID_rcr(NumCol_))
    ComStr.ExecuteNonQuery()
    ComStr.Parameters.Clear() 'очищать параметры обязательно!
    NumCol_ += 1
   Loop

  End Try
  If ReadStr.IsClosed = False Then ReadStr.Close()
  RCR_connect.Close()
  Sort_String = "SELECT * FROM logic_replay ORDER BY NumLine"
 End Function


 '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
 ' Возвращение имени головной структуры из полного имени переменной parname,
 ' если имя переменной не содержит не является елементом структуры,
 ' то возвращается полное имя переменной
 '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
 Public Function Seach_struct(ByVal ParName As String) As String
  Dim i As Integer, ii As Integer

  i = InStr(1, ParName, ".", 0)
  ii = InStr(1, ParName, "->", 0)
  If i > 0 Then
   If ii > 0 And ii < i Then
    Seach_struct = Left(ParName, ii - 1)
   Else
    Seach_struct = Left(ParName, i - 1)
   End If
  Else
   If ii > 0 Then
    Seach_struct = Left(ParName, ii - 1)
   Else
    Seach_struct = ParName
   End If
  End If
 End Function

#If DISP > 0 Then ' DISP_IO.exe  Start BLOCK
 Public Sub read_DeviceResources()

  Dim rsw As System.Data.DataTable
  Dim i, j As Int32

  On Error GoTo err_handler
  ' -----------------------------------------
  rs = BD_RS_DataSET.Tables("qADAPTER")

  ' Подсчет кол-ва адартеров TX6_PC_C и пакетов для каждого из них
  For i = 0 To rs.Rows.Count - 1 ' Цикл по адаптерам

   nBurst_TX6 = -1

   ''Debug.Print( _
   ''              " Name: " + CStr(rs.Rows(i)("Name")) _
   ''            + " Location: " + CStr(rs.Rows(i)("Location")) _
   ''            + " IdAdaptersType: " + CStr(rs.Rows(i)("IdAdaptersType")) _
   ''            + " LocNum: " + CStr(rs.Rows(i)("LocNum")))

   iIPC = Val(rs.Rows(i)("Location"))    ' Location
   If iIPC <> this_IPC Then GoTo cont
   iTypeAd = Val(rs.Rows(i)("IdAdaptersType"))   ' IdAdaptersType
   If iTypeAd < 0 Or iTypeAd >= AdapterTypeNumber Then Exit Sub
   Adapter_query(iTypeAd) = 1 ' установить в 1 если заявлен адаптер
   iAd = Val(rs.Rows(i)("LocNum")) - 1     ' LocNum
   If iAd < 0 Or iAd > 7 Then
    MsgBox("The  " + rs.Rows(i)("Name") + " adapter ""LocNum"" index is beyond limits:" + Chr(13) + "LocNum < 1 or LocNum > 8" + Chr(13) + "Please correct the BD_RS database.", vbCritical, "read_DeviceResources")
    End
   End If

   ' BURRST ------------------------------------------------
   sql = "SELECT * FROM qDataBurst WHERE IdAdapter=" + CStr(rs.Rows(i)("IdAdapter"))
   BD_RS_Adapter_Q_burst.SelectCommand.Parameters.Clear()
   BD_RS_Adapter_Q_burst = New OleDb.OleDbDataAdapter(sql, BD_RS_connect)
   cmd_Builder_Q_burst = New OleDb.OleDbCommandBuilder(BD_RS_Adapter_Q_burst)
   BD_RS_DataSET.Tables("qBURST").Clear()
   BD_RS_Adapter_Q_burst.Fill(BD_RS_DataSET, "qBURST")
   ' -------------------------------------------------------

   rsw = BD_RS_DataSET.Tables("qBURST")

   ''Debug.Print(" Число пакетов: " + CStr(rsw.Rows.Count))
   For j = 0 To rsw.Rows.Count - 1 ' Цикл по пакетам
    ''Debug.Print(" Name Burst: " + CStr(rsw.Rows(j)("Name")))
    fill_BurstResources(rsw, j) ' чтение из таблицы DataBurst
   Next j

   rsw.Dispose()

   Call fill_DeviceResources(rs, i) ' чтение из таблицы Adapters

cont:
  Next i

  ' BURRST ------------------------------------------------
  BD_RS_Adapter_Q_burst.SelectCommand.Parameters.Clear()
  BD_RS_Adapter_Q_burst = New OleDb.OleDbDataAdapter(sql_qDataBurst, BD_RS_connect)
  cmd_Builder_Q_burst = New OleDb.OleDbCommandBuilder(BD_RS_Adapter_Q_burst)
  BD_RS_DataSET.Tables("qBURST").Clear()
  BD_RS_Adapter_Q_burst.Fill(BD_RS_DataSET, "qBURST")
  ' -------------------------------------------------------

  rs.Dispose()

  Exit Sub

err_handler:
  '  ' -----------------------------------------
  '  ' Процедура обработки ошибки
  '  ' -----------------------------------------
  MsgBox("frm_main/read_DeviceResources " + vbCrLf + "err=" + CStr(Err.Number) + vbCrLf + Err.Description, vbCritical)
  iTypeAd = -1

  rs.Dispose()
  rsw.Dispose()

 End Sub
#End If ' DISP_IO.exe Finish BLOCK

#If DISP > 0 Then ' DISP_IO.exe  Start BLOCK
 Public Sub fill_BurstResources(ByVal rsww As System.Data.DataTable, ByVal iBurst As Int32)

  Dim W, i1 As Int32
  Dim ii1 As Integer
  Dim IdBurst, CPak, BurstSize, IdAdapter, cNP, Freq, _
      hbAddr, lbAddr, hbSubAddr, lbSubAddr, IdAircraft, _
      InOut, NumLine, GlobalNum, F0, LocNum

  On Error GoTo err_handler
  ' -----------------------------------------

  IdBurst = Val(rsww.Rows(iBurst)("IdBurst"))
  ' Перенумерация номеров пакетов
  ' -----------------------------
  For W = 0 To UBound(IdB)
   If IdBurst = IdB(W) Then
    IdBurst = W + 1 : Exit For
   End If
  Next W
  ' -----------------------------
  BurstSize = Val(rsww.Rows(iBurst)("BurstSize"))
  NumLine = Val(rsww.Rows(iBurst)("NumLine"))
  InOut = Val(rsww.Rows(iBurst)("InOut"))
  IdAdapter = Val(rsww.Rows(iBurst)("IdAdapter"))
  Freq = Val(rsww.Rows(iBurst)("Freq"))
  CPak = Val(rsww.Rows(iBurst)("cPak"))
  hbAddr = Val(rsww.Rows(iBurst)("hbAddr"))
  lbAddr = Val(rsww.Rows(iBurst)("lbAddr"))
  hbSubAddr = Val(rsww.Rows(iBurst)("hbSubAddr"))
  lbSubAddr = toDEC(rsww.Rows(iBurst)("lbSubAddr"))
  cNP = Val(rsww.Rows(iBurst)("cNP"))
  GlobalNum = Val(rsww.Rows(iBurst)("GlobalNum"))
  IdAircraft = Val(rsww.Rows(iBurst)("IdAircraft"))
  F0 = Val(rsww.Rows(iBurst)("F0"))

  Select Case iTypeAd

   Case TX6_PC_C

    If nBurst_TX6 < MAX_NUM_MESSAGE - 1 Then
     nBurst_TX6 = nBurst_TX6 + 1
    Else
     If CONF_RIG <> 6 Then MsgBox("Число пакетов > 512", vbCritical, "Тип адаптера TX6_PC_C")
    End If

    With zTMK1555INFO.TMK1555INFO(iAd).Mkio_Batch(nBurst_TX6)

     .NumBatch = IdBurst                                     ' IdBurst
     i1 = InOut : ii1 = vbInsert_to_w16(0, i1, 1, 1)          ' InOut
     i1 = CPak : ii1 = vbInsert_to_w16(ii1, i1, 5, 9)         ' CPak
     i1 = BurstSize : ii1 = vbInsert_to_w16(ii1, i1, 10, 15)  ' BurstSize
     .Num = ii1
     i1 = hbAddr : ii1 = vbInsert_to_w16(0, i1, 0, 4)         ' HbAddr
     i1 = lbAddr : ii1 = vbInsert_to_w16(ii1, i1, 5, 9)       ' LbAddr
     i1 = hbSubAddr : ii1 = vbInsert_to_w16(ii1, i1, 10, 14)  ' HbSubAddr
     .Addr = ii1
     .CodeFreq = Freq                                        ' Freq

    End With

   Case PC429_3_88

    If NumLine > MAX_NUM_LINE Then
     If CONF_RIG <> 6 Then MsgBox("Номер линии > 16", vbCritical, "Адаптер PC429-3-XX")
    End If
    If NumLine < 1 Then
     If CONF_RIG <> 6 Then MsgBox("Номер линии < 1", vbCritical, "Адаптер PC429-3-XX")
    End If

    With zPC429_3_INFO.PC429INFO(iAd).Arinc429_Batch(NumLine - 1)

     If CPak <> 0 Then Exit Sub ' Выходной пакет предназначен для задания параметров выходной/входной линии NumLine-8
     .InOut = InOut       ' InOut
     .NumWord = BurstSize ' BurstSize
     .Freq = F0           ' F0

    End With

   Case PC429_4_xx

    If NumLine > MAX_NUM_LINE * 2 Then
     If CONF_RIG <> 6 Then MsgBox("Номер линии > 32", vbCritical, "Адаптер PC429-4-XX")
    End If
    If NumLine < 1 Then
     If CONF_RIG <> 6 Then MsgBox("Номер линии < 1", vbCritical, "Адаптер PC429-4-XX")
    End If

    With zPC429_4_INFO.PC429INFO(iAd).Arinc429_Batch(NumLine - 1)

     If CPak <> 0 Then Exit Sub ' Выходной пакет предназначен для задания параметров выходной/входной линии NumLine-8
     .InOut = InOut       ' InOut
     .NumWord = BurstSize ' BurstSize
     .Freq = F0           ' F0

    End With

   Case PCADS_05

    If NumLine > MAX_NUM_LINE_ARINC_PCADS5 * 3 Then
     MsgBox("Номер линии > 96", vbCritical, "Адаптер PCADS05")
     Exit Sub
    End If
    If NumLine < 1 Then
     MsgBox("Номер линии < 1", vbCritical, "Адаптер PCADS05")
     Exit Sub
    End If

    With PCADS05INFO.PCADS_Batch(NumLine - 1)

     If (BurstSize > 0) Then
      .NumWord = BurstSize ' BurstSize
      .Freq = F0           ' F0
     End If

    End With

   Case PCADSv7RTMin

    If NumLine > MAX_NUM_LINE_ARINC_PCADSv7 Then
     MsgBox("Номер линии > 32", vbCritical, "Адаптер PCADSv7RTMin")
     Exit Sub
    End If
    If NumLine < 1 Then
     MsgBox("Номер линии < 1", vbCritical, "Адаптер PCADSv7RTMin")
     Exit Sub
    End If
    With PCADSv7INFOin.PCADSv7Module(iAd).PCADS_Batch(NumLine - 1)
     .NumWord = BurstSize ' BurstSize
     .Freq = F0           ' F0
    End With

   Case PCADSv7RTMout

    If NumLine > MAX_NUM_LINE_ARINC_PCADSv7 * 2 Then
     MsgBox("Номер линии > 64", vbCritical, "Адаптер PCADSv7RTMout")
     Exit Sub
    End If
    If NumLine < 1 Then
     MsgBox("Номер линии < 1", vbCritical, "Адаптер PCADSv7RTMout")
     Exit Sub
    End If

    With PCADSv7INFOout.PCADSv7Module(iAd).PCADS_Batch(NumLine - 1)
     .NumWord = BurstSize ' BurstSize
     .Freq = F0           ' F0
    End With

   Case PCADS_v7RK

    If NumLine > PCADS_Max_Module_Count * 2 Then
     MsgBox("Номер линии > 14", vbCritical, "Адаптер PCADSv7RK")
     Exit Sub
    End If
    If NumLine < 1 Then
     MsgBox("Номер линии < 1", vbCritical, "Адаптер PCADSv7RK")
     Exit Sub
    End If

    With PCADSv7RKINFO.RKline(NumLine - 1)

     .InOut = InOut
     .LineNumber = NumLine

    End With

   Case iMKIO_1

    i1 = toDEC(lbAddr)

    If NumLine > 2 And NumLine < 5 And i1 >= 0 And i1 < MKIO_OUMaxCount Then

     iMKIO_1Info.iMKIO_Batch((NumLine - 3) * MKIO_OUMaxCount + i1) = 1

    End If

  End Select

  Exit Sub

err_handler:
  '  ' -----------------------------------------
  '  ' Процедура обработки ошибки
  '  ' -----------------------------------------
  MsgBox("frm_main/fill_BurstResources " + vbCrLf + "err=" + CStr(Err.Number) + vbCrLf + Err.Description, vbCritical)

  rsww.Dispose()

 End Sub
#End If ' DISP_IO.exe Finish BLOCK

#If DISP > 0 Then ' DISP_IO.exe  Start BLOCK
 Public Sub fill_DeviceResources _
  (ByVal rsww As System.Data.DataTable, ByVal iDev As Int32)

  Dim IdAdapter, IdAdaptersType, IdInterface, LocNum, _
      PortSize, MemSize, Location, NumChannel, SerialNumber
  Dim PortIO As Int16, InterruptNum As Byte, _
      DmaCh As Byte, DMAPort As Int16, LoMemAddr As Int32

  IdAdapter = Val(rsww.Rows(iDev)("IdAdapter"))
  NumChannel = Val(rsww.Rows(iDev)("NumChannel"))
  IdAdaptersType = Val(rsww.Rows(iDev)("IdAdaptersType"))
  IdInterface = Val(rsww.Rows(iDev)("IdInterface"))
  LocNum = Val(rsww.Rows(iDev)("LocNum"))
  PortIO = Val("&H" + rsww.Rows(iDev)("PortIO"))
  PortSize = Val(rsww.Rows(iDev)("PortSize"))
  InterruptNum = Val(rsww.Rows(iDev)("InterruptNum"))
  DmaCh = Val(rsww.Rows(iDev)("DmaCh"))
  DMAPort = Val(rsww.Rows(iDev)("DMAPort"))
  LoMemAddr = Val("&H" + rsww.Rows(iDev)("MemAddr") + "&")
  MemSize = Val(rsww.Rows(iDev)("MemSize"))
  Location = Val(rsww.Rows(iDev)("Location"))
  SerialNumber = Val(rsww.Rows(iDev)("SerialNumber"))

  With DeviceResources(iTypeAd, iAd)

   .HiBaseMemory = 0
   .LoBaseMemory = LoMemAddr ' MemAddr
   .BasePort = PortIO        ' PortIO
   .DMAPort = DMAPort        ' DmaPort
   .DMAChannel = DmaCh       ' DmaCh
   .nIRQ = InterruptNum      ' InterruptNum
   .NumChannel = NumChannel  ' NumChannel

  End With

  Select Case iTypeAd

   Case TX6_PC_C

    If nAd_TX6 < AdapterNumber - 1 Then
     nAd_TX6 = nAd_TX6 + 1
    Else
     If CONF_RIG <> 6 Then MsgBox("Кол-во адаптеров > 8", vbCritical, "Адаптеры TX6-PC-C")
    End If

    With zTMK1555INFO.TMK1555INFO(iAd)

     .BoardType = PortSize    ' PortSize
     .AddrRT(0) = DmaCh       ' DmaCh
     .AddrRT(1) = DMAPort     ' DmaPort
     .AddrRT(2) = LoMemAddr   ' MemAddr
     .AddrRT(3) = MemSize     ' MemSize
     .NumPC = iIPC - 1        ' Location
     .NumBoard = iAd      ' LocNum
     .NumMessage = nBurst_TX6 + 1

    End With

   Case PC429_3_88

    With zPC429_3_INFO.PC429INFO(iAd)

     .NumPC = iIPC - 1  ' Location
     .NumBoard = iAd    ' LocNum

    End With

   Case PC429_4_xx

    With zPC429_4_INFO.PC429INFO(iAd)

     DeviceResources(iTypeAd, iAd).HiBaseMemory = LoMemAddr ' MemAddr
     DeviceResources(iTypeAd, iAd).LoBaseMemory = 0
     .NumPC = iIPC - 1  ' Location
     .NumBoard = iAd    ' LocNum

    End With

   Case PCADSv7RTMin

    PCADSv7INFOin.PCADSv7Module(iAd).ModuleEnable = 1

   Case PCADSv7RTMout

    PCADSv7INFOout.PCADSv7Module(iAd).ModuleEnable = 1

   Case RS485_MTVS

    LoMemAddr = Val(rsww.Rows(iDev)("MemAddr"))
    DeviceResources(iTypeAd, iAd).LoBaseMemory = 0         ' MemAddr
    DeviceResources(iTypeAd, iAd).HiBaseMemory = LoMemAddr ' MemAddr

   Case RMe_02

    'LoMemAddr = Val(rsww.Rows(iDev)("MemAddr"))
    'DeviceResources(iTypeAd, iAd).LoBaseMemory = LoMemAddr  ' MemAddr
    'DeviceResources(iTypeAd, iAd).HiBaseMemory = 0          ' MemAddr

   Case iMKIO_1

    iMKIO_1Info.Config = SerialNumber

  End Select

 End Sub

 Public Sub INIT_DEVICES()

  Dim iTAd, iiAd, j As Int32
  Dim n_exist_ad As Int32 ' кол-во обнаруженных типов адаптеров
  Dim adtype As String
  Dim iTAdRow() As DataRow

  'NumDevice - количество плат (0,1,2...)
  'NumPC - код номера РС (NPC_IPCi, где i=1,2,...,16)
  n_exist_ad = 1 ' кол-во обнаруженных типов адаптеров


  For iTAd = 0 To AdapterTypeNumber - 1

   If Adapter_query(iTAd) <> 1 Then GoTo finish_typeAd

   ''iTAd = PCI_1705 '' DEBUG

   iTAdRow = BD_RS_DataSET.Tables("qADAPTER").Select("IdAdaptersType = " + iTAd.ToString)

   If iTAdRow.Length = 0 Then
    adtype = ""
   Else
    adtype = iTAdRow(0).Item("AdaptersType") ' Если найдено, то взать первое найденное значение
   End If

   Select Case iTAd

    Case SPECIAL

    Case TX6_PC_C

     For iiAd = 0 To AdapterNumber - 1
      DevRes(iiAd) = DeviceResources(iTAd, iiAd)
     Next iiAd

     ' создание объектов управления платами TMK1553
     ' DeviceResources d[] - массив ресурсов плат
     ' NumDevice - количество плат
     ' NumPC - код номера РС (NPC_IPC1,NPC_IPC2,...,NPC_IPC7, NPC_HLI)
     ' TMK1553INFO info[] - массив для настройки плат TMK1553
     ' возврат - количество найденных плат  из числа запрошенных
     ' TMK1553MNG int __stdcall Create_tmk1553(DeviceResources d[], int MaxNumDevice,int NumPC, TMK1553INFO info[]);

     j = Create_tmk1553(DevRes(0), AdapterNumber, this_IPC - 1, zTMK1555INFO)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "TX6-PC-C" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case iMKIO_1

     j = vbCreate_iMKIO_1(iMKIO_1Info)

     If j > 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "iMKIO_1" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     Else
       MsgBox(" Error vbCreate_iMKIO_1 : " + CStr(j), vbCritical, "INIT_DEVICE warning")
     End If

    Case PC429_3_88

     ' создание объектов управления платами PC429-3-xx
     ' DeviceResources d[] - массив ресурсов плат
     ' PC429_3_INFO(i).Arinc429_Batch[j].NumWord = кол-во слов на прием\передачу с j-го канала i-й платы
     ' PC429_3_INFO(i).Arinc429_Batch[j].Freq = частота с j-го канала i-й платы
     ' PC429_3_INFO(i).Arinc429_Batch[j].InOut = 0 j-й канал i-й платы передатчик !=0 приемник
     '
     For iiAd = 0 To AdapterNumber - 1
      DevRes(iiAd) = DeviceResources(iTAd, iiAd)
     Next iiAd

     'zPC429_3_INFO.PC429INFO(7).Arinc429_Batch(15).Freq = 666 ' DEBUG

     j = vbCreate_PC429_3(DevRes(0), zPC429_3_INFO, AdapterNumber)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '       .lbl_adp(n_exist_ad).Text = "PC429-3-88" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case PC429_4_xx

     ' создание объектов управления платами PC429-4-xx
     ' DeviceResources d[] - массив ресурсов плат
     ' PC429_4_INFO(i).Arinc429_Batch[j].NumWord = кол-во слов на прием\передачу с j-го канала i-й платы
     ' PC429_4_INFO(i).Arinc429_Batch[j].Freq = частота с j-го канала i-й платы
     ' PC429_4_INFO(i).Arinc429_Batch[j].InOut = 0 j-й канал i-й платы передатчик !=0 приемник
     '
     For iiAd = 0 To AdapterNumber - 1
      DevRes(iiAd) = DeviceResources(iTAd, iiAd)
     Next iiAd

     'zPC429_4_INFO.PC429INFO(7).Arinc429_Batch(15).Freq = 666 ' DEBUG

     j = vbCreate_PC429_4(DevRes(0), zPC429_4_INFO, AdapterNumber)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '       .lbl_adp(n_exist_ad).Text = "PC429-4-xx" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case PCADS_05

     'For iiAd = 0 To MAX_NUM_LINE_ARINC_PCADS5 * 3 - 1
     '    PCADS05INFO.PCADS_Batch(iiAd).Freq = 50000 ' DEBUG
     '    PCADS05INFO.PCADS_Batch(iiAd).NumWord = 1
     'Next iiAd

     j = vbCreate_PCADS05(PCADS05INFO)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '                               .lbl_adp(n_exist_ad).Text = "PCADS05" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case PCADSv7RTMin

     j = vbCreate_PCADSv7RTMin(PCADSv7INFOin)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "PCADSv7RTMin" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     Else
      MsgBox("Номер ошибки при vbCreate_PCADSv7RTMin : " + CStr(j), vbCritical, "INIT_DEVICE warning")
     End If

    Case PCADSv7RTMout

     j = vbCreate_PCADSv7RTMout(PCADSv7INFOout)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '                               .lbl_adp(n_exist_ad).Text = "PCADSv7RTMout" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     Else
      MsgBox("Номер ошибки при vbCreate_PCADSv7RTMout : " + CStr(j), vbCritical, "INIT_DEVICE warning")
     End If

    Case PCADS_05K

     j = vbCreate_PCADS05K()

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '                                .lbl_adp(n_exist_ad).Text = "PCADS05K" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case PCADS_v7K

     j = vbCreate_PCADSv7K()

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '                                .lbl_adp(n_exist_ad).Text = "PCADSv7K" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case PCADS_05RK

     Read_PCADS05RKconfig()
     j = vbCreate_PCADS05RK(PCADS05RKINFO)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '                                .lbl_adp(n_exist_ad).Text = "PCADS05RK" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case PCADS_v7RK

     Read_PCADSv7RKconfig()
     j = vbCreate_PCADSv7RK(PCADSv7RKINFO)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "PCADSv7RK" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     Else
      MsgBox("Номер ошибки при vbCreate_PCADSv7RTMout : " + CStr(j), vbCritical, "INIT_DEVICE warning")
     End If

    Case IPK1

     'DeviceResources d[] - массив ресурсов платы
     For iiAd = 0 To AdapterNumber - 1
      DevRes(iiAd) = DeviceResources(iTAd, iiAd)
     Next iiAd
     'возврат - количество найденных плат из числа запрошенных
     j = vbCreate_IPK1(DevRes(0), AdapterNumber)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '       .lbl_adp(n_exist_ad).Text = "IPK1" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case PCI_ASTRA

     Call read_pciASTRAconfig()

     j = 0
     For iiAd = 0 To AdapterNumber - 1
      If vbCreate_AstraPCI(iiAd, UBound(pciASTRAinf) + 1, pciASTRAinf(0)) >= 0 Then j = j + 1
     Next iiAd

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "pciASTRA" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case PCI_ASTRA_BL

     j = 0
     For iiAd = 0 To AdapterNumber - 1
      If vbCreate_AstraPCI_BL(iiAd) >= 0 Then j = j + 1
     Next iiAd

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "pciASTRA_BL" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case PCI_1753

     Call read_Pci1753config()
     For iiAd = 0 To AdapterNumber - 1
      DevRes(iiAd) = DeviceResources(iTAd, iiAd)
     Next iiAd

     'DeviceResources d[] - массив ресурсов платы
     'возврат - количество найденных плат из числа запрошенных
     j = vbCreate_Pci1753(DevRes(0), AdapterNumber)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "Pci1753" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case PCI_1713

     For iiAd = 0 To AdapterNumber - 1
      DevRes(iiAd) = DeviceResources(iTAd, iiAd)
      'Определяем первый задейств. канал и число включенных каналов
      'Стартовый канал АЦП
      If DevRes(iiAd).DMAChannel < 0 Then DevRes(iiAd).DMAChannel = 0
      If DevRes(iiAd).DMAChannel > PCI1713_NUM_CHANNELS Then DevRes(iiAd).DMAChannel = PCI1713_NUM_CHANNELS
      'Количество задейств. каналов АЦП
      If DevRes(iiAd).NumChannel < 0 Then DevRes(iiAd).NumChannel = 0
      If DevRes(iiAd).NumChannel > PCI1713_NUM_CHANNELS Then DevRes(iiAd).NumChannel = PCI1713_NUM_CHANNELS
     Next iiAd

     Call read_Pci1713config()
     '' ''Уточнить число адаптеров!
     j = vbCreateAndDef_PCI1713(AdapterNumber, DevRes(0), zconf_PCI1713)
     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "Pci1713" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case PCI_1716

     ''DevRes[] - массив ресурсов платы
     ''возврат - количество найденных плат из числа запрошенных

     For iiAd = 0 To AdapterNumber - 1
      DevRes(iiAd) = DeviceResources(iTAd, iiAd)
      'Определяем первый задейств. канал и число включенных каналов
      'Стартовый канал АЦП
      If DevRes(iiAd).DMAChannel < 0 Then DevRes(iiAd).DMAChannel = 0
      If DevRes(iiAd).DMAChannel > PCI1716_NUM_CHANNELS Then DevRes(iiAd).DMAChannel = PCI1716_NUM_CHANNELS
      'Количество задейств. каналов АЦП
      If DevRes(iiAd).NumChannel < 0 Then DevRes(iiAd).NumChannel = 0
      If DevRes(iiAd).NumChannel > PCI1716_NUM_CHANNELS Then DevRes(iiAd).NumChannel = PCI1716_NUM_CHANNELS
     Next iiAd

     Call read_Pci1716config()
     'Уточнить число адаптеров!
     j = vbCreateAndDef_PCI1716(AdapterNumber, DevRes(0), zconf_PCI1716)
     ''? индекс    j = vbCreateAndDef_PCI1716(AdapterNumber, DevRes(0), conf_PCI1716(1))
     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "Pci1716" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case PCI_1724

     ''DevRes[] - массив ресурсов платы
     ''возврат - количество найденных плат из числа запрошенных

     For iiAd = 0 To AdapterNumber - 1
      DevRes(iiAd) = DeviceResources(iTAd, iiAd)
     Next iiAd

     j = vbCreate_PCI1724(1, DevRes(0))
     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "Pci1724" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case VMIPCI5587A

     ''DevRes[] - массив ресурсов платы
     ''возврат - количество найденных плат из числа запрошенных

     'возврат - количество найденных плат из числа запрошенных
     j = Create_VMIC5587(this_IPC - 1)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "VMIC5587" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case VMIPCI5565

     'возврат - количество найденных плат из числа запрошенных
     j = Create_VMIC5565(this_IPC - 1, RefMemSize)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "VMIC5565" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case RMe_02

     'возврат - количество найденных плат из числа запрошенных
     j = vbCreate_RMe_2()

     If j = 1 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "RMe_02" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

    Case CUS_BMK

     'возврат - количество найденных плат из числа запрошенных
     j = Create_CusBmk(this_IPC - 1, 0)

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "CUS_BMK" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else

       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

     ''Case pciSPI

     '' 'DeviceResources d[] - массив ресурсов платы
     '' For iiAd = 0 To AdapterNumber - 1
     ''  DevRes(iiAd) = DeviceResources(iTAd, iiAd)
     '' Next iiAd

     '' j = Create_pciSPI(DevRes(0), AdapterNumber)

     '' If j >= 0 Then
     ''  If n_exist_ad < N_lbl_no_adp Then
     ''   With frm_main
     ''    .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
     ''    .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
     '''   .lbl_adp(n_exist_ad).Text = "pciSPI" : .lbl_adp(n_exist_ad).Visible = True
     ''    .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
     ''    n_exist_ad = n_exist_ad + 1
     ''   End With
     ''  Else
     ''   If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
     ''  End If
     '' End If

    Case RS485_MTVS

     ' В одном компьютере может использоваться только одно устройство MTVS

     'DeviceResources d[] - массив ресурсов платы
     For iiAd = 0 To AdapterNumber - 1
      DevRes(iiAd) = DeviceResources(iTAd, iiAd)
     Next iiAd

     j = Create_RS485_TV500(DevRes(0))

     If j >= 0 Then
      If n_exist_ad < N_lbl_no_adp Then
       With frm_main
        .lbl_no_adp(n_exist_ad).Text = CStr(n_exist_ad) : .lbl_no_adp(n_exist_ad).Visible = True
        .lbl_adp(n_exist_ad).Text = adtype : .lbl_adp(n_exist_ad).Visible = True
        '        .lbl_adp(n_exist_ad).Text = "RS485_MTVS" : .lbl_adp(n_exist_ad).Visible = True
        .lbl_quant(n_exist_ad).Text = CStr(j) : .lbl_quant(n_exist_ad).Visible = True
        n_exist_ad = n_exist_ad + 1
       End With
      Else
       If CONF_RIG <> 6 Then MsgBox("Количество обнаруженных типов адаптеров на IPC-" + CStr(this_IPC) + " > " + CStr(N_lbl_no_adp - 1), vbCritical, "INIT_DEVICE warning")
      End If
     End If

   End Select

finish_typeAd:

  Next iTAd

 End Sub
#End If ' DISP_IO.exe Finish BLOCK

 Function MkStrHex(ByVal ll As Int32) As String
  Dim sss As String, ddd As String

  ddd = "0x00000000"
  sss = Hex(ll)
  ddd = Left(ddd, Len(ddd) - Len(sss))
  MkStrHex = ddd + sss

 End Function
 Function MkStrHexUint32(ByVal ll As UInt32) As String
  Dim sss As String, ddd As String

  ddd = "0x00000000"
  sss = Hex(ll)
  ddd = Left(ddd, Len(ddd) - Len(sss))
  MkStrHexUint32 = ddd + sss

 End Function

End Module
