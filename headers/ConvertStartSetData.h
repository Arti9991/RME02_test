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

# define ERR_OPEN_FILE			0x4L // �� ���� ������� ���� ��

//������ ����� ��������� ������� � ����������� ������
ConvertStartSetData void __stdcall WriteStartSet(char * FileName);

//������ �� ����������� ������ � ��������� ��������� ������� 
ConvertStartSetData void __stdcall ReadStartSet(PUCHAR pglob, PUCHAR pper, PUCHAR ptarg, PUCHAR pt_property);

//��������� ���� ������
ConvertStartSetData ULONG __stdcall GetLastErrorStartSet();
#ifdef __cplusplus
} 		
#endif 