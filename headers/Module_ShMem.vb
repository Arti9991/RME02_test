Module Module_ShMem

 ' смещения признаков готовности данных в структурах
 Public Const SH_READY_StartSet = 0
 Public Const SH_READY_OutADD = 1
 Public Const SH_READY_OutSBKV = 2
 Public Const SH_READY_InSBKV = 3
 Public Const SH_READY_InMKIO_SIGMA = 4
 Public Const SH_READY_OutSIGMA_MKIO = 5
 Public Const SH_READY_OutSIGMA_RTM = 6
 Public Const SH_READY_OutSIGMA_ANALOG = 7
 Public Const SH_READY_InSVS = 8
 Public Const SH_READY_OutSVS = 9
 Public Const SH_READY_StrFieldInfo = 10
 'Public Const SH_READY_rezerv

 ' смещения начал структур
 Public Const SH_StartSet = 16
 'Public Const SH_OutADD
 'Public Const SH_OutSBKV
 'Public Const SH_InSBKV
 'Public Const SH_InMKIO_SIGMA
 'Public Const SH_OutSIGMA_MKIO
 'Public Const SH_OutSIGMA_RTM
 'Public Const SH_OutSIGMA_ANALOG
 'Public Const SH_InSVS
 'Public Const SH_OutSVS
 Public Const SH_rezerv = 11

 Public Structure tShareMemAddress
  Public Offset As Int32          ' Смещение в ShMem для параметра
  Public CodePar As Int32         ' Код параметра
  Public ExistName As Int32       ' Кол-во раз которое имя переменной найдено в БД BD_RS
  Public ParName As String ' Имя параметра в БД BD_RS.mdb
  Public Direction As Int32       ' 0: out   1: in
 End Structure

 ' Создание разделяемой памяти
 ' Возвращает виртуальный адрес начала блока памяти (или NULL)
 ' SharedMem LPVOID __stdcall CreateSharedMem(DWORD size, LPSTR Name);
 Public Declare Function CreateSharedMem Lib "SharedMem.dll" (ByVal size As Int32, ByVal ShMemName As String) As Int32

 ' Удаление разделяемой памяти
 ' void __stdcall CloseSharedMem()
 Public Declare Sub CloseSharedMem Lib "SharedMem.dll" ()

 ' запись в память по смещению Offset данных из buf размером Size
 ' void __stdcall WriteSharedMem(PUCHAR buf, ULONG Offset, ULONG Size)
 Public Declare Sub WriteSharedMem Lib "SharedMem.dll" (ByRef buf As Byte, ByVal Offset As UInt32, ByVal size As UInt32)

 ' чтение из памяти по смещению Offset данных в buf размером Size
 ' void __stdcall ReadSharedMem(PUCHAR buf, ULONG Offset, ULONG Size);
 Public Declare Sub ReadSharedMem Lib "SharedMem.dll" (ByRef buf As Byte, ByVal Offset As UInt32, ByVal size As UInt32)

 ' Получение кода ошибки
 ' ULONG __stdcall GetLastErrorSM(unsigned long ClearFlag);
 Public Declare Function GetLastErrorSM Lib "SharedMem.dll" (ByVal ClearFlag As UInt32) As UInt32

 ' сброс счетчика записей
 ' void __stdcall ClearWFieldCnt(void );
 Public Declare Sub ClearWFieldCnt Lib "SharedMem.dll" ()

 ' возврат - количество записей (с 1)
 ' SharedMem ULONG __stdcall GetFieldCnt(ULONG &FreeMemory, ULONG &SizeSharedMem); // FreeMemory - остаток памяти
 '                                                                                 // SizeSharedMem - размер памяти
 Public Declare Function GetFieldCnt Lib "SharedMem.dll" _
        (ByRef FreeMemory As Int32, ByRef SizeSharedMem As UInt32) As UInt32

 ' получение строки с именем поля структуры в РП и смещения поля
 ' возвращает смещение поля
 ' ULONG __stdcall GetStrFieldInfo(ULONG Num,          //номер записи (с 0)
 '                                 PCHAR StrFieldName, //указатель на строку имени поле структуры
 '                                 char &FieldTypeCode,//код типа поля
 '                                 char &FieldInOut);  //IN__PARAM=1, OUT_PARAM=0
 'Data Type Ranges
 'C/C++ recognizes the types shown in the table below.
 '
 'Code Type Name  Bytes Other Names Range of Values
 '
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

 Public Declare Function GetStrFieldInfo Lib "SharedMem.dll" _
        (ByVal Num As Int32, _
         ByVal StrFieldName As String, _
         ByRef CodeType As Byte, _
         ByRef InOut As Byte) As Int32

 ' вызов функций инициализации
 ' и создание рефлективной и разделяемой памяти
 ' void __stdcall InitSam32DLL(void);
 Public Declare Sub InitSam32DLL Lib "sam32_dll.dll" ()

 ' запись файла начальных условий в разделяемую память
 ' void __stdcall WriteStartSet(char * FileName);
 Public Declare Sub WriteStartSet Lib "ConvertStartSetData.dll" (ByVal StrFieldName As String)

 ' Получение кода ошибки
 ' ConvertStartSetData ULONG __stdcall GetLastErrorStartSet();
 Public Declare Function GetLastErrorStartSet Lib "ConvertStartSetData.dll" () As Int32


End Module
