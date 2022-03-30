// CommonForMires.h: interface for the ClRadar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CommonForMires_H__958A62CF_1DEC_46F2_A5AF_630CFA97997D__INCLUDED_)
#define AFX_CommonForMires_H__958A62CF_1DEC_46F2_A5AF_630CFA97997D__INCLUDED_

#include "ConstMires.h"
#include "memory.h"
#include "CommonPlane.h"

struct DispInp
{// Диспетчер имитатора.
	double Trls; 
	int    d_Pfon;// Признак фона земли.
	int    Nbt;		// Число моделируемых целей (Имитатор КЦ).
	int    ComSNP;
	int    Is_Real_MFI;	// 0 - работа с имитатором, 1 - работа со штатным МФИ.
	int    NREAL;// номер реализации.
};

struct VhodPar
{
	int    Nbt;      //  Число моделируемых целей
	int    Ndrnp;    //  Кол-во целей, сопровожд. в ДРНП в текущем такте
	int    Ndc_snp;  //  Кол-во целей, переводимых с ДС на СНП  
	int    MCdrnp[8];//  Массив номеров целей, переводимых с СНП на ДС
	int	   M_DC_SNP[8];	// Массив номеров целей, переводимых с ДС на СНП
//	int    MCdrnp[8];//  Массив номеров целей, сопровождаемых в ДРНП
	int    MC129[8]; //  Поряд. номера целей РНП или ДРНП, обстрелив. Miss
	int    ComSNP;   //  Команда "СНП" (1 - только СНП, 0 - ДС + СНП).
	double Degv;     //  Ширина зоны обзора заданная
	int    Nstrokv;  //  Число строк зоны обзора заданное
	double EgCZOv;   //  Центр зоны обзора по азимуту
	double EvCZOv;   //  Центр зоны обзора по углу места
	int    SemiSph;  //  Полусфера атаки цели
	int    P1vhRLS;  //  Признак первого входа в модель БРЛС
	int    Pfon;     //  Признак фона Земли.(0, 1).
	double Kdal;     //  Коэффициент формирования строба захвата по дальности (1-2).
	double Kdt;      //  Коэффициент формирования строба захвата по скорости (1-2).
	double Kangl;    //  Коэффициент формирования строба захвата по углам (1-2).
	double TobMax;   //  Максимально допустимый период обзора для ЗО с перем. парам.
	int Npt[NC];     //  число создаваемых помех для каждой цели
	double Devv;     // величина зоны обзора по наклону

	VhodPar(){memset((void *)this,0,sizeof(VhodPar));};      //
};
 // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

// Структура параметров носителя
struct str_Car
{
	double Psi;      // Курс  [рад]
	double Teta;     // Тангаж  [рад]
	double Gamma;    // Крен [рад]
	double Hotn;     // Высота относительная [м]
	double V[3];     // Составляющие скоростей [м/с]
	double Xn;
	double Yn;
	double Zn;
  str_Car(){memset((void *)this,0,sizeof(str_Car));};
};

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
struct targets
{// Параметры кинематических целей   
	int		KinNom;		// Кинематический номер цели
	int		PrSH;		// Признак включения ШП
	int		SvChu;		// Признак "Свой-Чужой"
	double	Dalk;		// Дальность  [м]
	double	Dtk;		// Скорость сближения  [м/с]
	double	Evk;		// Угол места в ЗСК[рад]
	double	Egk;		// Азимут в ЗСК  [рад]
	double	Eprc;		// ЭПР        [кв.м]
	double	Gspp;		// Коэффициент усиления антенны ПП
	double	Np;			// Спектральная плотность ШП

	double	X;
	double	Ht;
	double	Z;
	double	V[3];
	int		  Ric;		// Уникальный идентификатор из списка РИЦ
	int		  Pr_Izl;		// Признак наличия излучения у данной цели
  int     PrV_Z;  // Признак "Воздух - Земля". 1 - "Воздух". 
	targets(){memset((void *)this,0,sizeof(targets));};
};

struct type_RangeVO
{
	int n;
	float Kr;	// критерий оценки близости кинематической и сопровождаемой целей.
};

struct type_RangeForIUS
{
	int n;
	float dD;	// критерий оценки близости кинематической и сопровождаемой целей.
	float dAz;
};

// Действительное комплексное число

struct complex
{
	double A, B;
};

// Выходные параметры БРЛС
struct OutRadar
{
	int   Rfunc;      // Режим функционирования БРЛС
						/* 4: СНП */
						/* 3: ДС */
						/* 2: Захват */
						/* 1: РК */
	int   Ksopr;      // Номер трассы цели ИУС, сопровождаемой в данном такте РДС.
	int   Ksopr1;     // Кин. номер текущей сопровождаемой цели в ДРНП для новой РЛС. ???
	int   Nrak;       // Номер Miss, для которой перед. РК в текущем такте
	int   NL;         // Количество целей в луче
	int   Notobz;     // Признак того, что нет обзора
	int   Pr4_4[8];   // Боковой ракурс
	int   NotzNP[8];  // Признак срыва захвата
	int   Mrdc[8];    // Массив целей, находящихся на сопровождении в РДС
	int   Riz;        // Режим излучения (СЧП, ВЧП)
	int  	Nkadr;      // Номер кадра обзора БРЛС
	int	  Pr_IzmInf;  //	Признак изменения информации по целям
	int	  Pr_RegMIRES;//	Признак режима работы МИРЭС
	int   Nrdc;       // Число целей, сопровождаемых в РДС
	double  Tobz;     // Период обзора зоны
	int   Zn;			// Знак движения по строке
	int   Kstrok;     // Текущая строка, на который находится луч
	int   Nobn;       // Число обнаруженных сигналов в данном такте

	OutRadar(){	memset((void *)this,0,sizeof(OutRadar)); };
};

// Структура измеренных координат целей в Обзоре
struct OutObzor
{
   double	Dizm;		  // Дальность цели измеренная   [м]
   double	DTizm;		// Скорость сближения цели измеренная  [м/с]
   double	EGizm;		// Азимут цели измеренный    [рад]
   double	EVizm;		// Угол места измеренный     [рад]
   double	Tizmer;		// Время измерения координат целей   [с]
   int		PizmD;		// Признак измерения дальности
   int		PizmDt;		// Признак измерения скорости сближения
   int		Pr_GO_RLK;// Признак госопознавания
   int		Type_Targ;// Тип цели РЛК
   int		N_Targ;		// Номер цели РЛК
   int		Kanal;		// Канал РЛК (Х или L)
   int    Pr_DC;		// Признак нахождения цели на ДС
   int		Pr_SNP_DC;// Признак перевода данного замера из СНП в ДС по номеру трассы
   int		RegIzl;		// Режим излучения, при котором был получен замер координат
   int		Pr_IzInfor;	// Признак изменения информации замера координат
   int		Ktrass;	    // Номер трассы СНП, переводимой в ДС

   OutObzor(){ memset((void *)this,0,sizeof(OutObzor)); };
};

struct Inf_RLS
{
	OutRadar Z;
	OutObzor Ot[NC];
};

// информация, поступающая с имитатора МФИ
typedef struct InterfaceIntegraph
{
// Органы управления, общие для всех режимов работы Н-036
  int IUP_Izl;             // Переключатель БРЛС изл. Откл
  unsigned IUP_CONF_kadr_kn;    // Текущий кадр, на котором организована работа с ОУ
// Штатные органы управления для режимов В-П (Обзорные режимы В-П (НР, МОРЕ) для Н-036,  Микроплан для РЛК-Х, Управление сопровождением НЦ Н-036 (ПКС и АС))
  int IUP_rej_OZP;        // Команда "режим обзор земной поверхности" 
  int IUP_RLP;            // Команда РЛ земной поверхности
  int IUP_rej_NR;         // КРТГ реальным лучом с низким разрешением
  int IUP_rej_CR;         // КРТГ реальным лучом с низким разрешением
  int IUP_rej_MORE;       // КРТГ реальным лучом морской поверхности
  unsigned IUP_RLS_rej_kart; // КРТГ с синтезированием апертуры антенны в переднее – боковом направлении (режим СА)
  unsigned IUP_SH121_FrameSize;        // Размер выходн. кадра РЛИ
  unsigned char IUP_RLS_sis_koord_RLI;         // Признак «Отображение секторное /прямоугольное»
    //int IUP_level_signal;   // Ручная регулировка уровня усиления приемника изд.Н-036
  unsigned IUP_RLS_Cel_Fon;   // Соотношение сигнал/шум приемных
  unsigned int IUP_RLS_daln_max_zad_VP;          // Номер шкалы дальности (номер ЗО, максимальная наклонная дальность ЗО)
  double IUP_RLS_czo_pel_zad_VP;      // Пеленг центра ЗО РЛС по горизонтали 
  unsigned char IUP_RLS_pr_rej_MKP;            // Команда «Микроплан»
  unsigned IUP_RLS_mash_MKP;         // Масштаб «Микроплана»
	unsigned char IUP_pr_naj_rud_4PP_right;// Положение ВПРАВО 4ПП РУД
	unsigned char IUP_pr_naj_rud_4PP_left;// Положение ВЛЕВО 4ПП РУД
	unsigned char IUP_pr_naj_rud_4PP;// Центральное нажатие  4ПП РУД (Зачем оно?)

  unsigned char IUP_RK_vvod;        // Разовая команда  «Ввод» 
  unsigned char IUP_RK_sbros;       // Разовая команда  «Сброс»
	double IUP_Ux_kn;			// Отклонение кнюппеля по оси Х
	double IUP_Uy_kn;			// Отклонение кнюппеля по оси y
	unsigned char IUP_RK_ZERO_KNP;
//	double IUP_Perek_X;     // Полож. перекрестья по оси Х для ВП (Д.б. в пикселях, т.е. int !!?)
//	double IUP_Perek_Y;     // Полож. перекрестья по оси Y для ВП (Д.б. в пикселях, т.е. int !!?)
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Штатные органы управления для режима В-В «Обзор воздушного пространства в основной зоне для РЛК_Х»
  unsigned char IUP_OPS_Hand_Aut;	// признак задания ручного ввода ЦЗИ 0 - ручное, 1 - авто
	unsigned int IUP_pr_naj_OVP;      // Признак включения ОВП
  unsigned IUP_RLS_Avtz_VV;      // Размер зоны обзора РЛК_Х
  double IUP_RLS_czo_pel_zad_VV;  // Заданный горизонтальный пеленг ЦЗО РЛК_Х
    double IUP_RLS_czo_daln_zad_VV; // Заданная дальность обнаружения для РЛК_Х
    double IUP_RLS_czo_h_zad_VV;		 // Заданная высота обнаруживаемой ВЦ для РЛК_Х
	double IUP_Dstr;			// Дальность центра строба на МФИ в момент нажатия кнопки «Ввод» 
	double IUP_Azstr;			// Азимут центра строба на МФИ в момент нажатия кнопки «Ввод» или кнопки «Сброс»
//	double IUP_Umstr;			// Угол места центра строба на МФИ в момент нажатия кн. «Ввод» и кн. «Сброс»
	// +++++++++++++++++++++++++++++++++++++++++++++
// Штатные органы управления для режима ГО и УВД 
  unsigned char IUP_ZaprIII_GO;      // Признак того, что требуется запросить «свою» цель в III режиме ГО
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++           
// Нештатные органы управления (требуются для отладки модели Ш-121 на стенде «Интеграф»
//  int IUP_Pr_corPKS;       // Признак коррекции координат
//  int IUP_PrTarg;          // Команда вывода на экран обнаруженных Н-036 или кинематических целей
//  int IUP_Obz_CU;          // Команда «Обзор (захват) по ЦУ»
  int IUP_GO_N;            // Команда «ГО по номеру цели Н-036)
  int IUP_GO_CU;           // Команда «ГО по ЦУ»
  int IUP_RTR;             // Команда «Доразведка заданной РИЦ» 
  int IUP_PPO;             // Команда «предварит. /предпусковое опознавание»
  int IUP_str_CU;          // Размер строба захвата цели в обзоре по ЦУ,  доразведке  и ГО по ЦУ
  int	IS_REAL_MFI;   	     // Признак того, что работа ведётся через реальный МФИ
  int Nf;					 // Номер трассы, соотв. стробу
} InterfaceIntegraph;

typedef struct Str_InputH036// Вход Н-036
{
	// Основные режимы
	unsigned		BP_P_RLK_X;			// Уровень мощности 
	unsigned		BP_Izl_X;			// Излучение РЛК_Х
	unsigned		BP_VP_X;			// Вкл. режим ВП
	unsigned		BP_VV_X;			// Вкл. режим ВВ
	unsigned     BP_BB;				// Признак ВВ
	unsigned     BP_RTR_REP;			// Команда "Вкл. режим РТР-РЭП"

	// Режимы В_П
	unsigned		BP_SO_PRM;			// Отображ.: сектор/прямоуг 
	unsigned		BP_Cel_Fon;			// Режим с выделением: фон/цель 
	unsigned		BP_Format_Kadr_VP;	// Формат кадра
	unsigned		BP_Otrab_VV_SBR;	// Разреш. обработки кн. Ввод/Сброс
	double			BP_Daln_CZ_VP;		// Дальность центра зоны КТГР
	double			BP_Az_CZ_VP;		// Азимут ЦЗ ВП
	unsigned		BP_MP_VP;			// Команда Микроплан РЛК-Х
	unsigned		BP_Masht_MP;		// "Масштаб МКП
	unsigned		BP_Cel_PKS_AS_L;	// Номер цели с подключенными ООУ
	unsigned		BP_More_VP;			// Команда  "Вкл. режим Море" РЛК-Х
	unsigned		BP_NR_VP;			// Команда "Вкл. режим НР" РЛК-Х    
	unsigned		BP_SR_VP;			// Команда "Вкл. Режим СР" РЛК-Х  
	unsigned		BP_VVOD;			// Нажатие кнопки ВВОД
	unsigned		BP_SBROS;			// Нажатие кнопки СБРОС 
	unsigned		BP_Priz_Form_Perekr; // Признак формиров. перекрестья
	unsigned 		BP_Perekr_X;		// Полож. перекрестья по Х 
	unsigned 		BP_Perekr_Y;		// Полож. перекрестья по Y


	unsigned		BP_VR_VP;			// Команда "Вкл. режим ВР" РЛК-Х
	unsigned		BP_PAM_VP;			// Команда "Вкл. режим Память" РЛК-Х
	unsigned		BP_MNGSTR;			// Признак "Многостр память" РЛК-Х
	unsigned		BP_NoK_PAM;			// "Номер кадра ПАМ" РЛК-Х
	unsigned		BP_DISS_VP;			// Команда "Вкл. ДИСС РЛК-Х
	unsigned		BP_RRY_RLI;			// Ручная регул. яркости изображ 
	unsigned		BP_IDZ_VP;			// Команда "Вкл. режим "ИДЗ"  РЛК-Х
	unsigned		BP_VIS_VP;			// Признак "Ведущая информац. система" РЛК-Х
	unsigned		BP_Upravl_RLK;		// Управл. РЛК-Х/РЛК-L
	double	BP_Az_IDZ;			// "Азимут в режиме ИДЗ" РЛК-Х
//	double	BP_Ym_IDZ;			// "Угол места в режиме ИДЗ" РЛК-Х
	unsigned	BP_Ym_IDZ;			// "Угол места в режиме ИДЗ" РЛК-Х
	unsigned		BP_Out_RLK_X;		// Команда "Вкл. вывод изображ. РЛК Х"


	// Режимы ВВ
	unsigned		BP_No_zon_X;		// "Номер зоны" РЛК-Х
	unsigned		BP_POLUSF;			// Признак "Полусфера РЛК-Х"
	unsigned		BP_CY_Ygl;			// Признак "ЦУ по углам" РЛК_Х
	unsigned		BP_CY_D;			// Признак "ЦУ по Д" РЛК_Х 
	unsigned		BP_CY_V;			// Признак "ЦУ по скорости " РЛК-Х
	unsigned		BP_NoC_DC;			// Номера целей, назначенные  на ДС
	unsigned		BP_NoC_SNP;			// Номера целей, назначенные на СНП
	double			BP_Az_CZ_X;			// "Азимут ЦЗ" РЛК-Х
	double			BP_Ym_CZ_X;			// "Угол места ЦЗ" РЛК-Х
	double			BP_Daln_CY_X;		// "Дальность ЦУ" РЛК-Х
	double			BP_Vsbl_CY_X;		// "Скорость сближения ЦУ" РЛК-Х
	unsigned		BP_DO;				// Признак "ДО"
	unsigned		BP_DO_Nom;			// Номер режима ДО
	double			BP_Delt_D_X;		// Полуширина ЦУ по D РЛК_Х
	double			BP_Delt_V_X;		// Полуширина ЦУ по V РЛК_Х

	unsigned		BP_REGIM_BBV;		// Подрежим ББВ
	unsigned		BP_NoC_Sbros;		// Номера целей назначенные на сброс
	
	// Для ГО по номеру цели

	unsigned		BP_NoC_GO;			// Номер цели на ГО
	unsigned		BP_Lin_GO;			// Линия опознавания
	unsigned		BP_Pr_ppo;			// Признак ППО
	unsigned		BP_Pr_Rr;			// Род работы
	unsigned		BP_Prior_T;			// Приоритет цели

} Str_InputH036;

typedef struct Str_InputL402
{						// Для режима РТР
	unsigned		IUS_TID;		// Уникальный идентиф. цели от Л-402	
	unsigned		IUS_PDE;		// Признаки наличия данных о цели				
	double			FSL;			// Нижняя граница ЧД поиска	
	double			FSH;			// Верхняя граница ЧД поиска		
	double			AZVL;			// Нижняя граница пеленгового сектора phiZ поиска		
	double			AZVH;			// Верхняя граница пеленгового сектора phiZ поиска		
	double			AZGL;			// Нижняя граница пеленгового сектора phiY поиска		
	double			AZGH;			// Верхняя граница пеленгового сектора phiY поиска		
	unsigned		IUS_DSKR;		// Дескриптор цели		
	unsigned		RPEL;			// Команда на обнаруж. или уточнение углов пеленга РЭС		
	unsigned		IUS_LZP;		// Литеры ЧД поиска 				
	unsigned		IUS_Pr_RTRRLS;	// РТР(РТР/РЛС)		
	unsigned		IUS_R_RTRCU;	// РТР/ЦУ		
	unsigned		IUS_R_RTRVTP;	// РТР/ВТП		
	unsigned		IUS_PT;			// РТР/РТ		
	unsigned		IUS_PrRTR;		// РТР		
} Str_InputL402;


typedef struct InputH121
{// ГО
	unsigned BP_zayavka;  // Заявка на опознавание
	unsigned BP_OperationMode_GO;  // ППО
	unsigned BP_RodRab;  // Род работы
	unsigned BP_Linia;  // Линия опознавания
	unsigned BP_Strob;  // Строб дальности
	double	BP_Azimut;   // Азимут
	unsigned BP_Prizn_Azimut; // Наличие данных азимута
	double BP_Ugol_mesta; // Угол места
	unsigned BP_Prizn_Ugol_mesta;  // Наличие данных угла места
	double BP_DC;  // Дальность до цели
	unsigned BP_Prizn_DC ; // Наличие данных дальности

	// Надо убрать!!!, используются для вызова программы в rlk_x.cpp
	int BP_GO_N0;  // Команда «ГО по номеру цели Н-036)
	int Nf;        // Номер формуляра трассы для GOnc.
} InputH121;

/* Данные ГО по целям от Н-036Ш. */
typedef struct t_DateGOTarg
{// ГО
	unsigned N036SH_Rez_PO_targ; // Результаты ГО
	unsigned N036SH_Dop_Prizn_targ; // Дополнительные признаки
	double   N036SH_D_targ; //Дальность ответившей цели
	unsigned char N036SH_D_targ_dostg; // Достоверность дальности ответившей цели
	double   N036SH_Azimut_targ; //Азимут ответившей цели
	unsigned char N036SH_Azimut_targ_dost; // Достоверность азимута ответившей цели
	double   N036SH_Ugol_mesta_targ; //Угол места ответившей цели
	unsigned char N036SH_Ugol_mesta_targ_dost; // Достоверность угла места ответившей цели
	
} t_DateGOTarg;

typedef struct t_timeGO
{
	unsigned Hour;
	unsigned Min;
	unsigned Sec;
	double MSec;
} t_timeGO;

typedef struct OutputH121
{// ГО
	unsigned N036SH_Num_targ1; // Количество ответивших целей
	Time50 timeGO;
	unsigned char N036SH_zayavka_out;// Заявка на опознавание принята
	unsigned char N036SH_Linia_out;// Установлена Линия опознавания
	unsigned N036SH_OperationMode_GO_out;// Установлен признак ППО
	unsigned char N036SH_RodRab_out;// Установлен Род работы субсистемы ГО
//	unsigned N036SH_hour_target; // Значение часов
//	unsigned N036SH_min_target; // Значение минут
//	unsigned N036SH_sec_targ; // Секунды
//	unsigned N036SH_msec_targ; // Доли секунды
    t_DateGOTarg DateGOTarg[14]; // Массив данных ГО по целям от Н-036Ш
} OutputH121;
typedef struct Str_OutNC13   // Результаты измерений для 1-й или 3-й цели
{
	unsigned		N036_hour_izm_1_3;	// Часы 1(3) цели
	unsigned		N036_min_izm_1_3;		// Минуты 1(3) цели 
	unsigned		N036_sec_izm_1_3;		// Секунды 1(3) цели
	double		N036_msec_izm_1_3;	// Миллисекунды 1(3) цели
	unsigned		N036_PKS_AS1_out;		// Признак неподвижной ПКС/АС подвижной ПКС/АС
	unsigned char		N036_SrivAS1_out;		// Признак Срыв АС
	unsigned char		N036_CvZone1;			  // Признак Цель в зоне
	unsigned		N036_NoC_H0361_out;	// Номер цели Н036 
	unsigned char		N036_Prizn_OI;			// Признак обновления информации
	unsigned char		N036_KanalX1_out;
	unsigned char		N036_KanalL1_out;
	double	N036_Az1_out;		// Азимут 1 (3) цели
	double	N036_ygl_mesta_out;	// Угол места 1 (3) цели 
	double	N036_danl1_out;			// Дальность 1 (3) цели
	double	N036_velocity1_out;	// Скорость 1 (3) цели
//	double	N036_vel_byAz1_out;	// Угловая скор. по азимуту 1 (3) цели
//	double	N036_sev_vel1_out;	// Северная составляющая скорости 1 (3) цели
//	double	N036_vost_vel1_out;	// Восточная составляющая скорости 1 (3) цели
	unsigned    N036_GO_1_3;      // Результат ГО
	unsigned    N036_Rez_GO_1_3;  // Дополнительные признаки ГО 
} Str_OutNC13; 

typedef struct Str_OutNC24			// Результаты измерений для 2-й или 4-й цели
{
	unsigned		N036_hour_izm_2_4;	// Часы 2(4) цели
	unsigned		N036_min_izm_2_4;		// Минуты 2(4) цели 
	unsigned		N036_sec_izm_2_4;		// Секунды 2(4) цели
	double		N036_msec_izm_2_4;	// Миллисекунды 2(4) цели
	unsigned		N036_PKS_AS2_out;		// Признак неподвижной ПКС/АС подвижной ПКС/АС
	unsigned char		N036_SrivAS2_out;		// Признак Срыв АС
	unsigned char		N036_CvZone2;			  // Признак Цель в зоне
	unsigned		N036_NoC_H0362_out;	// Номер цели Н036 
	unsigned char		N036_Prizn_OI_2_4;
	unsigned char		N036_KanalX2_out;
	unsigned char		N036_KanalL2_out;
	double	N036_Az2_out;			// Азимут 2 (4) цели
	double	N036_ygl_mesta2_out;// Угол места 2 (4) цели 
	double	N036_danl2_out;			// Дальность 2 (4) цели
	double	N036_velocity2_out;	// Скорость 2 (4) цели
//	double	N036_vel_byAz2_out;	// Угловая скор. по азимуту 2 (4) цели
//	double	N036_sev_vel2_out;	// Северная составляющая скорости 2 (4) цели
//	double	N036_vost_vel2_out;	// Восточная составляющая скорости 2 (4) цели
	unsigned N036_GO_2_4;      // Результат ГО
	unsigned N036_Rez_GO_2_4;  // Дополнительные признаки ГО 
} Str_OutNC24; 

typedef struct Str_OutH036		// Выход Н-036
{

	unsigned		N036_Cel_PKS_AS_L_out;	// "Число целей на АС и ПКС" 
	unsigned char		 N036_VP_X_out;			// Вкл. режим ВП
 	unsigned N036_Perekr_X_out;		// Положение перекрестья по Х 
	unsigned N036_Perekr_Y_out;		//	Положение перекрестья по Y 
	unsigned char N036_Prizn_Form_Perekr_out;//	Признак формирование перекрестья
	unsigned char		N036_VV_X_out;          //Вкл. режим ВВ
	unsigned		N036_No_zon_X_out;      //Номер зоны РЛК-Х
	unsigned		N036_NoC_GO_out;		// Номер цели на ГО
	unsigned		N036_Pr_Rr_out;			// Род работы
	unsigned		N036_Lin_GO_out;		// Линия опознавания
	unsigned char		N036_Pr_ppo_out;		// Признак ППО
	Str_OutNC13 OutNC13;			// Результаты измерений для 1-й или 3-й цели
	Str_OutNC24 OutNC24;			// Результаты измерений для 2-й или 4-й цели

} Str_OutH036;

typedef struct Str_InMFI	// Входные параметры для индикации
{
	int		Lx;				// Горизонтальный размер рабочей площади экрана МФИ
	int		Ly;				// Вертикальный размер рабочей площади экрана МФИ
	int		RMax;			// Радиус дальней границы сектора
	int		RMin;			// Радиус ближней границы сектора
	int		Ox;				// Горизонт. координата центра окружности для заданного сектора
	int		Oy;				// Вертик. координата центра окружности для заданного сектора 
	int		TypSopr[4];		// Тип i-й сопровождаемой цели 
	int		Pr_ExKTGR;		// Признак вывода на МФИ заданной зоны КТГР
	int		Lyzad[NbtMax];	// Координата Х цели на МФИ
	int		Lxzad[NbtMax];	// Координата Y цели на МФИ
	int		Lyizm[4];		// Координата Y  измеренной НЦ на экране МФИ
	int		Lxizm[4];		// Координата X  измеренной НЦ на экране МФИ
	double	Alf;			// Секторный угол картинки КТГР на экране МФИ
	double	betta;			// Секторный угол зоны КТГР
	int		KolTg;			// Кол-во заданных кинемат. НЦ, выводимых на экран
	int		Xugl;			// Коорд. Х верхнего правого угла карты для декартовой СК
	int		Yugl;			// Коорд. Y верхнего правого угла карты для декартовой СК
	int		SizeX;			// Размер карты по Х для декартовой СК
	int		SizeY;			// Размер карты по Y для декартовой СК
	int		Perekr_X;		// Положение прицельного перекрестья по оси Х
	int		Perekr_Y;		// Положение прицельного перекрестья по оси Y
	int		Pr_Zahv;		// Признак этапа захвата НЦ (Символ захватыв. НЦ мигает на МФИ)
	int		N_Tg;		    // Количество сопровождаемых целей
	double	EgCzo;			// Азимут ЦЗО в ЗСК
	double	Dminim;			// Минимальная дальность зоны КТГР или МКП
	double  Dmaxim;			// Максимальная дальность зоны КТГР или МКП
	int		NumTgou;		// Номер цели, к которой подкл ОУ
	unsigned tuErr_n_zo_VP;	// Сообщение "Неверно задана шкала дальности" 
	unsigned tuErr_pel_VP;	// Сообщение "Неверно задан пеленг ЦЗО"
	unsigned tuErr_DczoHabs;// Сообщение "Наклонная дальность меньше высоты носителя"
    unsigned tuErr_Dczo;	// Сообщение "Дальность ЦЗО вышла за допустимые пределы"
	unsigned tuErr_Dist;	// Сообщение "Центр зоны КТГР вне зоны видимости БРЛС" 
	unsigned tuErr_Dgor;	// Сообщение "Наклонная дальность больше дальности радиогор."
	unsigned tuPr_NotVP;	// Признак невозможности построения зоны КТГР 
	unsigned int SO_PRM;
	unsigned int MP_VP;

	// В-В
	int   Num;					// Количество сопровож. воздушных целей.
	int   Nbt;					// Количество кинематич. целей.
	int   IUP_RLK_ZO_Riz;		// Номер зоны РЛК-Х.
	int   SemiSph;				// Признак "Полусфера РЛК-Х".
	double ygl_az_C[NbtMax];    // Азимут сопровождаемой цели.
	double ygl_mesta_C[NbtMax]; // Угол места сопровождаемой цели.
	double dln_do_C[NbtMax];    // Дальность до сопровождаемой цели.
	double V_C[NbtMax];         // Скорость сопровождаемой цели.
	double ygl_az_C_nf[NbtMax]; // Измеренный азимут цели.
	double ygl_mesta_C_nf[NbtMax];// Измеренный угол места цели.
	double dln_do_C_nf[NbtMax]; // Измеренная дальность до цели.
	double V_C_nf[NbtMax];      // Измеренная скорость цели.
	int NoC_SNP_out[NbtMax];    // Номера целей, назначенных на СНП
	int DS_SNP[NbtMax];         // Признак ДС/СНП
	// Выход от КГС для отображения на имитаторе МФИ
//	int Num_KGS;				// число трасс в КГС
//	double fiy_KGS[NbtMax];		// азимут полученный в КГС
//	double dln_KGS[NbtMax];		// дальность полученная в КГС 
	//
	double Hcel;                //заданная высота цели
	double Dzad;                //Заданная дальность
	double EGzad;               //Заданная ширина зоны обзора по горизонтали
//	ГО
	int svoi[NbtMax];			// для кинематических целей (режим ГО по ЦУ)
	int svoi_cu[NbtMax];		// для сопровождаемых вторичкой целей (ГО по нумеру)
//	int priz[NbtMax];

	// РТР	
	int	Pr_IZL[NbtMax];				// признак наличия излучения у цели
	int	Pr_IZM_Fig_L402[NbtMax];	// признак измерения пеленга
	double IZM_Fig_L402[NbtMax];	// измеренный пеленг
	double IZM_Daln_L402[NbtMax];	// дальность до цели, равная кинематической
	int Pr_IZM_Rejim_L402[NbtMax];	// признак измеренния режима
	int	IZM_Rejim_L402[NbtMax];		// измеренный режим
	int Pr_In_L402[NbtMax];			// признак того, что цель излучает и находится в зоне приёма РТР
	int ID_In_L402[NbtMax];			// уникальный идентификатор цели от РТР
} Str_InMFI; 


struct strmasCel
{
	float Eg;
	float DC;
	int   Cel_SvCg; // цель "Своя-Чужая"
	int   RegRab;   // СЧП=0, ВЧП=1
	int   DC_SNP;   // ДС=0, СНП=1
};

/* дополнительная информация от интеграфа*/
/* 
 * struct str_Integraf
 * {
 * 	int  time_hour; // должно выдаваться как-то подругому
 * 	int  time_min;
 * 	int  time_sec;
 * 	float  time_msec;
 * 	int  Kol_Cel; // Количество целей от Интеграфа
 * 	strmasCel masCel_i[100]; // информация по целям
 * };
 */

// входная структура от ФПО 
typedef struct strInputFromFPO
{
	int i;
} strInputFromFPO;

// выходная структура для ФПО
typedef struct strOutputForFPO
{
	int i;
} strOutputForFPO;

/* дополнительная информация от РЛС */
struct str_RLS
{
	int  Kol_Cel; // Количество целей в РЛС
	strmasCel masCel[NbtMax]; // информация по целям
};

//******************** Надо убрать, но КГС использует **************
struct rez_GOcu
{
	int N036S_Rez_GO_targ;
	int N036S_Dop_Prizn_targ;
	float N036S_D_targ;
	float N036S_Azimut_targ;
	int N036S_Azimut_targ_dost;
	float N036S_Ugol_mesta_targ;
	int N036S_Ugol_mesta_targ_dost;
};

struct strMod_GOcu
{
			// Квитанции с выхода Н-036Ш

	unsigned char N036SH_zayavka_out;				// Заявка на опознавание принята		
	unsigned char N036SH_Linia_out;				// Установлена Линия опознавания
	unsigned N036SH_OperationMode_GO_out;	// Установлен признак ППО
	unsigned char N036SH_RodRab_out;				// Установлен Род работы субсистемы ГО
	unsigned N036SH_hour_target;				// Значение часов
	unsigned N036SH_min_target;				// Значение минут
	unsigned N036SH_sec_targ;				// Секунды
	double N036SH_msec_targ;				// Доли секунды
	rez_GOcu mrez_GOcu[14];
};

struct strMod_GOnc
{
	unsigned N036_NoC_GO_out;
	unsigned N036_Rez_GO[NbtMax];
	int N036_obrezGO[NbtMax];
};


struct strMod_RTR
{
	// Квитанции с выхода Л402

	unsigned L402_KCU;			// Квитанция о выполн. команды ЦУ и поиска
	unsigned L402_KZTT;			// Квитанция выполн. команды запрета/разреш. подавления
};


// выход от Л-402 согласно ПИВ
struct strPIV_L402_out
{
	unsigned L402_TID;
	unsigned L402_PFM;
	unsigned L402_PDI;
	unsigned char L402_FND;
	unsigned L402_TYP_F;
	unsigned L402_RW;
	double L402_AZN;
	unsigned char L402_AZS;
	unsigned char L402_DPEL;
	unsigned L402_TPEL;
	double L402_FTG;
	double L402_TDI;
	double L402_PWS; 
	double L402_PWM; 
 	double L402_PPT;
	double L402_VDT;
	unsigned int L402_TYP_C[3];
	unsigned L402_TYP_I;
	unsigned char L402_VID;
	unsigned L402_SOT; 
	double TIMELAST;
	double L402_TOS;
	double L402_UMT;
	unsigned char L402_DUMT;
	unsigned L402_RSK;
	double L402_TSK;
	unsigned L402_REP;
	unsigned int L402_PUS;
	unsigned L402_PRPS;
	unsigned int L402_IUS; 
	unsigned char L402_RPD;
	unsigned char L402_RPDK;
	unsigned char L402_RPDM;
	unsigned char L402_REPVZ;
	double L402_DAL;
	unsigned char L402_TDAL; 
	unsigned L402_HOURLAST;
	unsigned L402_MINLAST;
	unsigned L402_SEKLAST;
	unsigned L402_MSEKLAST;
	double L402_Hdg;
	double L402_Pitch;
	double L402_Roll;
};

// выдача радиобстановки на выход
struct strRadio_Situation
{
	unsigned i_TID;
	unsigned i_RW;
	double i_AZN;
	double i_FTG;
	double i_TDI;
	double i_PWS; 
	double i_PWM; 
 	double i_PPT;
	unsigned int i_TYP_C;
	unsigned int i_TYP_I;
	unsigned char i_VID; 
	double i_UMT;
	double i_TSK;
	unsigned i_PRPS;
	double i_time;
	double i_Hdg;
	double i_Pitch;
	double i_Roll;
	double i_DAL;
};

// Описание Радиоэлектронных средств в базе РЭС
// в таком виде записывается в файл             
struct CResBase
{
	int RESType;       // типа РЭС (уникальный)
	char RESName[40];  // название РЭС
	bool isafar;       // если 1 то фар/афар иначе щелевая

	// 0-min значение и 1-max значение
	double Fo[2];      // несущая частота ГГц
	double Tau[2];     // длительность импульса
	double Fp[2];      // частота повторения	
	double Tp[2];

	double Pim[2];   // импульсная (средняя) мощность
	int TipPW[3]; // 0 - для БРЛС с ЩАР в режиме РНП и БРЛС с ФАР и АФАР в режиме Захват
	// TipPW=1 - для БРЛС с ЩАР в режимах Обзор и  Захват и для некоторых БРЛС с ФАР и АФАР в режиме Обзор и для БРЛС с ФАР и АФАР в режиме ДС 
	// TipPW=2 - случайное сканирование луча  для некоторых типов БРЛС с ФАР и АФАР в режиме Обзор
	double Gain;       // коэффициент усиления антенны Дц

	double FiMax;     // предельное значение отклонения антенны по горизонту 

	bool isdelete;     //  флаг на удаление
	
	int ParamSig[3];   // параметры сигнала 0-имп 1-непр 2-квазинепр
	int PulsMod[4];     // виды импульсной модуляции
	// 0-гладкий 1-ЛЧМ 2-ФКМ 3-ЧМ от импульса к импульсу
};

// для рисования перемещения луча ДНА
struct StrDrawBeam
{
	int RfuncD;
	double MuD[3],NuD[3],FiMaxD[3],dFilD[3];
	double PSID,TETAD,GAMMAD;
	int NstrokD,PkadrD,NafarD,McD,NbtD,NkadrD;
	double EgCZOD,EvCZOD,DegD;
	double EgLD,EvLD;
	targets targD[NC]; 
	double EgkD[NC],EvkD[NC];
	double EgeD[NC],EveD[NC];
	bool IsExtrD[NC];
};

typedef struct Str_Ptr
{// Структура указателей на внутренние объекты класса cMires.
  Str_InputH036*   pInputH036; // Входная информация для БРЛС.
  Str_InMFI*       pInMFI;     // Выходная информация для вывода на МФИ.
  strOutputForFPO* pOutForFPO; // Информация для ФПО.
  str_Car *        pCarrier;   // Структура информации носителя.
  targets *        pTarget;    // Информация о целях (кинематика).
  InputH121*       pInputH121; // Входная информация для ГО.
  VhodPar  *       pVhParam;   // Входные параметры БРЛС.
  Str_OutH036*     pOutH036;
  OutputH121*      pOutH121;
  Str_InputL402*   pInputL402;
  strRadio_Situation *pRS;
} Str_Ptr;

#endif // !defined(AFX_CommonForMires_H__958A62CF_1DEC_46F2_A5AF_630CFA97996D__INCLUDED_)
/////////////////////////////////////////////////////////////////////////////
