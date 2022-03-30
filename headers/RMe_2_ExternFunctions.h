#ifndef RMe_2_ExternFunction
#define RMe_2_ExternFunction

#define RING_IS_BREAK_RME_2 -1
//запись в память по смещению Offset данных из buf размером Size
//Использование данной функции возможно, когда на компьютере установлена только одна плата
void __stdcall WriteMemory_RMe_2(PUCHAR buf, ULONG Offset, ULONG Size);
//чтение из памяти по смещению Offset данных в buf размером Size
//Использование данной функции возможно, когда на компьютере установлена только одна плата
void __stdcall ReadMemory_RMe_2(PUCHAR buf, ULONG Offset, ULONG Size);
//запись в память по смещению Offset переменной UCHAR
//Использование данной функции возможно, когда на компьютере установлена только одна плата
void __stdcall WriteChar_RMe_2(UCHAR data, ULONG Offset);
//чтение из памяти по смещению Offset переменной UCHAR
//Использование данной функции возможно, когда на компьютере установлена только одна плата
unsigned __int8 __stdcall ReadChar_RMe_2(ULONG Offset);
//запись в память по смещению Offset переменной USHORT
//Использование данной функции возможно, когда на компьютере установлена только одна плата
void __stdcall WriteShort_RMe_2(USHORT data, ULONG Offset);
//чтение из памяти по смещению Offset переменной USHORT
//Использование данной функции возможно, когда на компьютере установлена только одна плата
unsigned __int16  __stdcall ReadShort_RMe_2(ULONG Offset);
//запись в память по смещению Offset переменной ULONG
//Использование данной функции возможно, когда на компьютере установлена только одна плата
void __stdcall WriteLong_RMe_2(ULONG data, ULONG Offset);
//чтение из памяти по смещению Offset переменной ULONG
//Использование данной функции возможно, когда на компьютере установлена только одна плата
unsigned __int32 __stdcall ReadLong_RMe_2(ULONG Offset);
//время обхода инициализационного пакета по всей петле, нс
//Использование данной функции возможно, когда на компьютере установлена только одна плата
__int32 __stdcall GetLatency_RMe_2();
//Получение кода ошибок и сброс их в 0
__int32 __stdcall GetErrors_RMe_2();
//Удаление мусора из линии
void __stdcall DeNoise_RMe_2();

#endif