#include "windows.h"

//Создание разделяемой памяти
//Возвращает виртуальный адрес начала блока памяти (или NULL) 
typedef LPVOID (__stdcall *PROC_CreateSharedMem) (DWORD size, LPSTR Name);

//возврат - количество записей (с 1), FreeMemory - остаток памяти, SizeSharedMem - размер памяти
typedef ULONG (__stdcall *PROC_GetFieldCnt) (ULONG &FreeMemory, ULONG &SizeSharedMem);

//получение строки с именем поля структуры в РП и смещения поля
//возвращает смещение поля
typedef ULONG (__stdcall *PROC_GetStrFieldInfo)
     (ULONG Num,          //номер записи (с 0)
						PCHAR StrFieldName, //указатель на строку имени поле структуры  
						char &FieldTypeCode,//код типа поля
						char &FieldInOut);  //IN__PARAM=2, OUT_PARAM=1

//запись строки с именем поля структуры выходного параметра в РП и смещения поля
//возвращает номер (с 1) записанных строк
//запись строки с именем поля структуры в РП и смещения поля
//возвращает номер (с 1) записанных строк
typedef ULONG (__stdcall *PROC_WriteStrFieldInfoIO)
     (PVOID pStrName,	     	//указатель на структуру
						PCHAR StrFieldName,   //указатель на строку имени поля структуры  
						const char* FieldType,//указатель на строку типа переменной
						PVOID pStrFielName,	 	//указатель на поле структуры
						ULONG BaseOffset,	    //смещение начала структыры в РП
						char FieldInOut);     //IN__PARAM=1, OUT_PARAM=0
// ---------------------------------------------------------------------------------------------------
// FieldTypeCode FieldType    Size(byte)  Comment
// ---------------------------------------------------------------------------------------------------
//      0	       неизвестный тип
//      1	       int				         4        signed, signed int System dependent 
//      2	       unsigned int   	4        unsigned System dependent 
//      3	       __int8			       1        char, signed char –128 to 127 
//      4	       __int16		      	2        short, short int, signed short int –32,768 to 32,767 
//      5	       __int32		      	4        signed, signed int –2,147,483,648 to 2,147,483,647 
//      6	       __int64		      	8        none –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 
//      7	       char			         1        signed char –128 to 127 
//      8	       unsigned char  	1        none 0 to 255 
//      9	       short		        	2        short int, signed short int –32,768 to 32,767 
//     10	       unsigned short 	2        unsigned short int 0 to 65,535 
//     11	       long	       	  	4        long int, signed long int –2,147,483,648 to 2,147,483,647 
//     12	       unsigned long	  4        unsigned long int 0 to 4,294,967,295 
//     13	       неизвестный тип 
//     14	       float			        4        none 3.4E +/- 38 (7 digits) 
//     15	       double			       8        none 1.7E +/- 308 (15 digits) 
//     16	       long double	  	10        none 1.2E +/- 4932 (19 digits) 
// ---------------------------------------------------------------------------------------------------

//Получение кода ошибки и сброс флага ошибки
typedef ULONG (__stdcall *PROC_GetLastErrorSM) (ULONG ClearFlag);
// ---------------------------------------------------------------------------------------------------
//КОДЫ ОШИБОК от GetLastError
// ---------------------------------------------------------------------------------------------------
# define NO_ERR                 0x0L	   // все чисто
# define ERR_ALREADY_EXISTS     0x1L	   // память уже создана
# define ERR_CreateSharedMemory 0x2L	   // не могу создать РП
# define ERR_BOUND_MEM			       0x8L	   // выход за верхнюю границу РП
# define ERR_MEM_PTR			         0x10L	  // обращение к неинициализированному адресу РП
# define ERR_CROSS_DATA		      	0x20L	  // пересечение стректур данных и имен полей в РП
# define ERR_SECOND_WRITE		     0x40L	  // повторная запись поля в уже занятый адрес
# define ERR_NUM_RECORD			      0x80L	  // запрошена несуществующая запись
# define ERR_NAME_SIZE		       	0x100L	 // запрошена несуществующая запись
# define ERR_SECOND_WRITE_AND_CHANGE_OUT_TO_IN		0x200L	// повторная запись поля в ранее занятый адрес со сменой признака с выходного на входной
# define CREAR_ALL_ERR          ~NO_ERR // удаление всех ошибок
// ---------------------------------------------------------------------------------------------------

//Удаление разделяемой памяти
typedef void (__stdcall *PROC_CloseSharedMem)();

PROC_CreateSharedMem CreateSharedMem;
PROC_GetFieldCnt GetFieldCnt;
PROC_GetStrFieldInfo GetStrFieldInfo;
PROC_WriteStrFieldInfoIO WriteStrFieldInfoIO;
PROC_GetLastErrorSM GetLastErrorSM;
PROC_CloseSharedMem CloseSharedMem;

// Начальное смещение для дополнительных моделей
#define SH_MODELS	0x50000
// Максимальное смещение для дополнительных моделей
#define SH_MODELS_MAX	0x100000

// размеры вводимых переменных дополнительных моделей
#define size_DISTANCE 8

// смещения для вводимых переменных дополнительных моделей
#define SH_DISTANCE	SH_MODELS
#define SH_END_MODELS SH_DISTANCE + size_DISTANCE

#if SH_END_MODELS > SH_MODELS_MAX
 #error !!! Out of SH_MODELS_MAX !!!
#endif

#define pOffsetPAR(lp,size,iRec) (unsigned long*)((void *)( (UCHAR*)(lp) + size - iRec*262 - 12 ))
#define pPAR(lp,iRec) (void *)( (UCHAR*)(lp) + *pOffsetPAR(lp,size,iRec) )

long __stdcall InitModel_1(DWORD size, LPSTR Name);//Размер разделяемой памяти и ее имя
void __stdcall CallModel_1(void);
void __stdcall CloseModel_1(void);
void __stdcall RestartModel_1(void);

long StatusInit = -1;
const long *pXs=0, *pYs=0, *pZs=0; // Указатели на координаты носителя в [0.1м]
const long *pXt=0, *pYt=0, *pZt=0; // Указатели на координаты 1-й цели в [0.1м]
double *pDISTANCE=0;               // расстояние между ностителем и 1-й целью в [м]





