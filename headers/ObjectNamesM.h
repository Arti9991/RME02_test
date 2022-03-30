typedef struct {
//тип   наименование	   Размер, смещения	примечание
USHORT  MkioOutput_M[32];		//64	0h	Массив слов выходных параметров для Mkio
USHORT  MkioInput_M[32];		//64 	40h	Массив слов входных параметров от Mkio
} SHMEMSTR_M, *PSHMEMSTR_M;