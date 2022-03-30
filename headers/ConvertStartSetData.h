#if defined(ConvertStartSetData_DLL)
# define ConvertStartSetData     __declspec(dllexport)
#elif defined(ConvertStartSetData_APP)
# define ConvertStartSetData     __declspec(dllimport)
# else
# define ConvertStartSetData
#endif

#ifdef __cplusplus
extern "C"
{
#endif

# define ERR_OPEN_FILE			0x4L // не могу открыть файл НУ

//запись файла начальных условий в разделяемую память
ConvertStartSetData void __stdcall WriteStartSet(char * FileName);

//чтение из разделяемой памяти в структуры начальных условий 
ConvertStartSetData void __stdcall ReadStartSet(PUCHAR pglob, PUCHAR pper, PUCHAR ptarg, PUCHAR pt_property);

//Получение кода ошибки
ConvertStartSetData ULONG __stdcall GetLastErrorStartSet();
#ifdef __cplusplus
} 		
#endif 