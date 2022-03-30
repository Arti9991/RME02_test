Module Module_RefMem

 'Public Const RF_Common = &H40
 '
 'Public Const RF_IPC1 = &H20000
 'Public Const RF_IPC2 = &H40000
 'Public Const RF_IPC4 = &H60000
 'Public Const RF_IPC6 = &H80000
 'Public Const RF_PC1 = &HA0000
 'Public Const RF_PCVS1 = &HC0000
 'Public Const RF_Reserve = &HE0000
 '
 'Public Const SH_STATUS_IPC1 = &H48
 'Public Const SH_STATUS_IPC2 = &H50
 'Public Const SH_STATUS_IPC4 = &H58
 'Public Const SH_STATUS_IPC6 = &H60
 'Public Const SH_STATUS_PC1 = &H68
 'Public Const SH_STATUS_PCVS1 = &H70

 '//запрет инициализации ISR
 Public Const IRQL_NOT_USE = &HFF

 ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
 Public Const RefMemSize = &H200000 ' Размер рефлективной памяти 2Мб
' Public BaseRefMemType = RMe_02 ' Базовая рефлективная память
' Public BaseRefMemType = VMIPCI5565 ' Базовая рефлективная память
' Public BaseRefMemType = VMIPCI5587A ' Базовая рефлективная память
 Public BaseRefMemType As Int32 = -1
 ' Аналогичную аналогичную настройку надо сделать в #kssr_dll.dll !!!
 ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

 ' -------------------------------------------------------------
 '                         VMI5587A
 ' -------------------------------------------------------------
 ' создание объекта
 ' COVER_VMIPCI5587 void __stdcall Create_COVER_VMIPCI5587();
 Public Declare Sub Create_COVER_VMIPCI5587 Lib "#RMN5587.dll" ()

 ' удаление объекта
 ' COVER_VMIPCI5587 void __stdcall Close_COVER_VMIPCI5587();
 Public Declare Sub Close_COVER_VMIPCI5587 Lib "#RMN5587.dll" ()

 ' Получение времени задержки прохождения данных по кольцу сети
 ' возвращается время задержки в 100нс единицах или
 ' RING_IS_BREAK, если Кольцо сети разорвано или один из модулей обесточен
 ' COVER_VMIPCI5587 long __stdcall GetLatency_COVER(void);
 Public Declare Function GetLatency_COVER Lib "#RMN5587.dll" () As Int32


 '//поиск Pci платы с номером NumBrd(с 1),
 '//устанавливает транслированные адреса BaseAddr0, BaseAddr1,
 '//и IrqL, PCIBusMumber, DeviceMumber для найденной платы
 '//Возврат - количество найденных плат (с 1)
 'COVER_VMIPCI5587 int __stdcall ScanPciBoard_COVER(int NumBrd, ULONG & BaseAddr0, ULONG & BaseAddr1,
 '                             UCHAR & IrqL, ULONG & PCIBusMumber,ULONG & DeviceMumber);
 Public Declare Function ScanPciBoard_COVER Lib "#RMN5587.dll" _
   (ByVal NumBrd As Int32 _
    , ByRef BaseAddr0 As Int32, ByRef BaseAddr1 As Int32, _
     ByRef IrqL As Byte, ByRef PCIBusMumber As Int32, ByRef DeviceMumber As Int32) As Int32

 '// Инициализация платы.
 '// при необнаружении плат область памяти эмулируется в системной памяти.
 '// Возврат true-успешно, false-неуспешно
 '// если без прерывания, то pRoutine=NULL
 'COVER_VMIPCI5587 bool __stdcall InitBoard_COVER(ULONG BaseAddrPIO,ULONG BaseAddrMem,
 '                UCHAR IrqL, BOOLEAN (RTFCNDCL *pRoutine)(PVOID context), ULONG BusMumber);
 Public Declare Function InitBoard_COVER Lib "#RMN5587.dll" ( _
   ByVal BaseAddrPIO As Int32, ByVal BaseAddrMem As Int32, _
   ByVal IrqL As Byte, ByRef pRoutine As Int32, ByVal BusMumberas As Int32) As Int32

 ' -------------------------------------------------------------
 '                         VMI5565
 ' -------------------------------------------------------------
 '//создание объекта
 '// COVER_VMIPCI5565 void __stdcall Create_COVER_VMIPCI5565(ULONG   SizeEmulMem = SIZE_BAR3_64M_5565); //запрашиваемый размер памяти для эмуляции
 Public Declare Sub Create_COVER_VMIPCI5565 Lib "#RMN5565.dll" (ByVal size As Int32)

 '//удаление объекта
 'COVER_VMIPCI5565 void __stdcall Close_COVER_VMIPCI5565();
 Public Declare Sub Close_COVER_VMIPCI5565 Lib "#RMN5565.dll" ()

 '// Получение времени задержки прохождения данных по кольцу сети
 '// возвращается время задержки в 100нс единицах или
 '// RING_IS_BREAK, если Кольцо сети разорвано или один из модулей обесточен
 'COVER_VMIPCI5565 long __stdcall GetLatency_COVER_VMIPCI5565(void);
 Public Declare Function GetLatency_COVER_VMIPCI5565 Lib "#RMN5565.dll" () As Int32

 '//поиск Pci платы с номером NumBrd(с 1),
 '//устанавливает транслированные адреса BaseAddr0, BaseAddr1,
 '//и IrqL, PCIBusMumber, DeviceMumber для найденной платы
 '//Возврат - количество найденных плат (с 1)
 'COVER_VMIPCI5565 int __stdcall ScanPciBoard_COVER_VMIPCI5565(int NumBrd, ULONG & BaseAddr0, ULONG & BaseAddr1, ULONG & BaseAddr2, ULONG & BaseAddr3,
 '                             UCHAR & IrqL, ULONG & PCIBusMumber,ULONG & DeviceMumber);
 Public Declare Function ScanPciBoard_COVER_VMIPCI5565 Lib "#RMN5565.dll" _
   (ByVal NumBrd As Int32, _
     ByRef BaseAddr0 As Int32, ByRef BaseAddr1 As Int32, ByRef BaseAddr2 As Int32, ByRef BaseAddr3 As Int32, _
     ByRef IrqL As Byte, ByRef PCIBusMumber As Int32, ByRef DeviceMumber As Int32) As Int32

 '// Инициализация платы.
 '// при необнаружении плат область памяти эмулируется в системной памяти.
 '// Возврат true-успешно, false-неуспешно
 '// если без прерывания, то pRoutine=NULL
 'COVER_VMIPCI5565 bool __stdcall InitBoard_COVER_VMIPCI5565(ULONG BaseAddrPIO,ULONG BaseAddrMem, ULONG BaseAddr2, ULONG BaseAddr3,
 '                UCHAR IrqL, BOOLEAN (RTFCNDCL *pRoutine)(PVOID context), ULONG BusMumber);
 Public Declare Function InitBoard_COVER_VMIPCI5565 Lib "#RMN5565.dll" ( _
   ByVal BaseAddrPIO As Int32, ByVal BaseAddrMem As Int32, ByVal BaseAddr2 As Int32, ByVal BaseAddr3 As Int32, _
   ByVal IrqL As Byte, ByRef pRoutine As Int32, ByVal BusMumberas As Int32) As Int32

 ' -------------------------------------------------------------
 '                         RMe_02
 ' -------------------------------------------------------------
'//время обхода инициализационного пакета по всей петле, нс
'//_int32 __stdcall GetLatency_RMe_2();
 Public Declare Function GetLatency_RMe_2 Lib "#RMe_2.dll" () As Int32






End Module
