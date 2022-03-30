#if !defined(__ObjectNames_H)
#define      __ObjectNames_H

//#include "C5_450.h"
//
// IPC object names.
//
//#define	RigSoft_SHM    	__TEXT("RigSoft.Shm")
#define	RigSoft_SHM    	__TEXT("IPC15.Shm")

//для CommandDevCntrl и CommandRigCntrl
#define	STOP_TASK		1//Команда на останов программы
#define	RESET	    	2//Команда на сброс счетчиков времени

//для AnswerRigCntrl
#define	RESET_TO_COMBINED	1//команда для STEND.EXE перехода в совместный режим из автономного

//Состояние программы stend.exe:
//режимы работы (ModeFlight)
#define	COMBINED_MODE	1//совместный режим после нажатия ПРИМЕНИТЬ
#define	AUTONOM__MODE	2//автономный режим после нажатия ПРИМЕНИТЬ

//номер активной страницы (ActivePage)
#define	COMBINED_PAGE	1//страница "совместный режим"
#define	AUTONOM__PAGE	2//страница "автономный режим"

//	Описание структуры разделяемой памяти.  Размер 140 байт
typedef struct {
//тип   наименование	   Размер, смещения	примечание
USHORT  MkioOutput[32];		//64	0h	Массив слов выходных параметров для Mkio
USHORT  MkioInput[32];		//64 	40h	Массив слов входных параметров от Mkio

USHORT  AnswerRigCntrl;	    //2		0x00007821	Слово ответов от модели	
USHORT  ModeFlight;			//2		0x00007823  0-останов режима, COMBINED_MODE, AUTONOM__MODE	
USHORT  ActivePage;			//2		0-не определено , COMBINED_PAGE, AUTONOM__PAGE (без учета перехода на третью страницу)
USHORT reserv[3];

//USHORT  CommandDevCntrl;   	//2		Слово команд от TaskControl к DeviceControl
//USHORT  CommandRigCntrl;    	//2		Слово команд от TaskControl к RigControl
//USHORT  AnswerDevCntrl;	    //2		Слово ответов от DeviceControl к TaskControl
//OUT_PACK	Out_Pack;
//IN_PACK		In_Pack;
} SHMEMSTR, *PSHMEMSTR;

#endif //  __ObjectNames_H