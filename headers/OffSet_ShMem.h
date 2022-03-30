#pragma once
//смещения признаков готовности данных в структурах 0-63

#define SH_READY_StartSet         0
#define SH_READY_StendInDc        1
#define SH_READY_SamToDC          2
#define SH_READY_STEND            3
#define SH_READY_SAU_IN           4
#define SH_READY_SAU_OUT          5
#define SH_READY_VS_TO_CC         6
#define SH_READY_InSVS            7
#define SH_READY_InSBKV           8
#define SH_READY_InMKIO_SIGMA     9
#define SH_READY_CC_TO_VS        10
#define SH_READY_OutSVS          11
#define SH_READY_OutSBKV         12
#define SH_READY_OutSIGMA_MKIO   13
#define SH_READY_OutSIGMA_ANALOG 14
#define SH_READY_OutA037         15
#define SH_READY_Ol_OUT          16 
#define SH_READY_Ol_IN           17
#define SH_READY_ToIPO           18
#define SH_KssrDataGet           19
#define SH_KssrDataPut           20
#define SH_SSSDataGet            21
#define SH_SSSDataPut            22
#define SH_READY_DCToModel       23
#define SH_READY_Targ            24
#define SH_READY_TBCVMRF_OLS     25
#define SH_READY_OLSRF_BFS       26
#define SH_READY_OLSRF_BCVM      27
#define SH_READY_Sam             28
#define SH_READY_Svs1k_1         29
#define SH_READY_Svs2k_1         30
#define SH_READY_SvsKk_1         31
#define SH_READY_SvsKk_2         32
#define SH_READY_SvsKk_3         33
#define SH_READY_SvsKk_4         34
#define SH_READY_SvsKDC          35
#define SH_READY_KcuToMkio       36
#define SH_READY_DCToSamK        37
#define SH_READY_RAM1701_OUT     38
#define SH_READY_VPin_sam        39
#define SH_READY_CcToOlsK        40
#define SH_READY_TARGETS         41
#define SH_READY_ToOtnDvig		     42
#define SH_READY_SosToMc2		      43
#define SH_READY_KcuToMc2		      44	
#define SH_READY_DI_T50			       45	
#define SH_READY_Carry_T50		     46	
#define SH_READY_Trg_T50		       47		 
#define SH_READY_EVTOCC			       48
#define SH_READY_IBVP			         49
#define SH_READY_KsuToBcvm		     50 //

#define SH_CBcs		     52 //
#define SH_CBss		     56 //

#define SH_READY_StrFieldInfo    63

//............самолет.................
#define SIZE_SAM             224 //344
#define SIZE_StartSet_      1464
#define SIZE_Property      12600 //до новых помех было 6552
#define SIZE_DCToSam          10
#define SIZE_DCToSamK         34 
#define SIZE_DcToSvsK          3
#define SIZE_STEND            64
#define SIZE_SauIN           104
#define SIZE_SauOUT           40
#define SIZE_VS_TO_CC        112
#define SIZE_InSVS            24
#define SIZE_InSBKV           96
#define SIZE_InMKIO_SIGMA    176//128
#define SIZE_CC_TO_VS        900//648
#define SIZE_OutSVS          328//216
#define SIZE_OutSBKV         192
#define SIZE_OutSIGMA_MKIO   624//616//520
#define SIZE_OutSIGMA_ANALOG  56
#define SIZE_OutA037          24
#define SIZE_TO_IPO           36
#define SIZE_StendOutDc        4
#define SIZE_StendInDc        14
#define SIZE_KSSR              8
#define SIZE_Targ             96
#define SIZE_Svs1k_1         160
#define SIZE_Svs2k_1         160
#define SIZE_SvsKk_1         160
#define SIZE_SvsKk_2         160
#define SIZE_SvsKk_3         160
#define SIZE_SvsKk_4         160
#define SIZE_SvsKDC           10
#define SIZE_Bcvs1ToSVSK      32
#define SIZE_Bcvs2ToSVSK      32
#define SIZE_MkioToKcu       192
#define SIZE_KcuToMkio       320
#define SIZE_CcToOlsK         28
#define SIZE_SamToOtnDvig	  48
#define SIZE_CommonNewToSam   672
#define SIZE_SosToMc2		  56
#define SIZE_KcuToMc2		  29

#define SIZE_TARGETS        4536

//.........ОЛ.............................. 
#define SIZE_OL_IN            24
#define SIZE_OL_OUT          524
#define SIZE_TO_MPI           32
#define SIZE_TO_SPI           16  //Кудряшов 20.05.09
#define SIZE_FROM_MPI         84  //Кудряшов 31.05.21
#define SIZE_TO_RSS          648
#define SIZE_TO_RSS2          16
#define SIZE_FROM_RSS          8
#define SIZE_TO_UKROP         80
#define SIZE_From_Scenario	  	64
#define SIZE_ToSam32         328//304//264//240
#define SIZE_RMN_Int1		        2
#define SIZE_RTMToOLS         28
#define SIZE_OLSToBFS          4
#define SIZE_OLSToRTM         28

//........SSS............................
#define sizeOS             (16*8)
#define sizeU              (32*8)
#define SIZE_CUtoROK       (48*8)
#define sizeBORT              32
#define sizeSMSPUT            32
#define sizeGUN                4

#define size_NVG_SA1_Sto   (24*2)
#define size_NVG_SA2_Sto   (10*2)
#define size_NVG_SA3_Sto    (2*2)
#define size_NVG_SA1_toS    (3*2)
#define size_BZ_SA1_Sto    (24*2)
#define size_BZ_SA2_Sto    (12*2)
#define size_BZ_SA3_Sto     (3*2)
#define size_BZ_SA1_toS     (9*2)
#define size_BZ_SA2_toS     (1*2)
#define size_BZ_SA3_toS    (18*2)

#define size_Mt_NVG_SA8_PtoRL    (24*2) // для 170-1 или 270
#define size_Mt_NVG_SA30_RLtoP   (29*2) // для 170-1 или 270

#define sizeROK                8
#define sizeToR170					       16
#define sizeR170To					        8
#define sizeToIR35         (10*4)
#define sizeIR35TO          (3*4)
#define SIZE_mASP        (8*1060)
#define SIZE_MSI               4
#define SIZE_CONTROL           4

#define sizeBKTS                 (4*4) // Параметры управления БКТС для вывода изображений с ТП на 4-е МФИ
#define sizePZ              (8*28*4*2) // Полетное задание на 1...8 ТП
#define sizePCADS05out           (4*4) // Управление PCADS //Кудряшов 2.04.15
#define sizePCADS05in  (64*4+64*4+128) // Данные(64),время(64), адреса(128) PCADS //Кудряшов 2.04.15
#define sizePCADS05_FPI        (2*3*4) // Управление ФПИ 1 и ФПИ 2 // Барабаненков 27.03.2017
#define sizeBSI                (5*6+4) // БСИ

//ТЛМ
#define sizeBCVMtoBRPI  ((28+1)*4) //+1 это контрольный код начала данных
#define sizeBCVM_BRPI       (68*4)
#define sizeISUtoRGS        (16*4)
#define sizeISU_RGS         (46*4)
#define sizeRGStoISU        (15*4)
#define sizeRGS_ISU         (37*4)
#define sizeTlmRGSto        (18*4)
#define sizeTlmRGS_         (34*4)
#define sizeTlmBMKto        (73*2)
#define sizeTlmBMK_  ((148+1+1)*4) //+1+1 это контрольный код начала данных и К2OnIPC5
#define NumberTlmData  ((sizeBCVMtoBRPI + sizeBCVM_BRPI + sizeISUtoRGS + sizeISU_RGS + sizeRGStoISU + sizeRGS_ISU + sizeTlmRGSto + sizeTlmRGS_ + sizeTlmBMK_) / 4 + sizeTlmBMKto /2)

 //RAM
#define SIZE_RAM1701_OUT      16  // 8 слов*2
#define SIZE_RAM1701_IN        8 // (3 слова+reserv)*2

// VP
#define SIZE_VPin            288
#define SIZE_VPout           552 //344 //328  // На две цели 4 подвески

#define SIZE_WEAPON          9 // Размер структуры с кодами АСП

// Кабина Т50
#define SIZE_COCKPITtoCC     120 // Гурвиц 09.10.07
#define SIZE_CCtoCOCP         40 // Гурвиц 23.04.07

//170m
#define SIZE_InPack			    	64	// RM(5565)
#define SIZE_OutPack	    		64	// RM(5565)
#define SIZE_OutAccel	    	24	//6	//XYZDac
#define SIZE_OutU			      	16//4	//XYZDac
#define SIZE_STEND170M	   140 //Гурвиц (МКИО ОУ 3)
#define SIZE_RTM170M		   	248 //РТМ sizeof старый с резервом = 240
#define SIZE_MonitorMKIO		140 //МКИО Монитор
#define SIZE_KMBO			       	2	// КМБО
//RS422/485
#define SIZE_RS422_OUT   		76	// для ИРС(Крит)
#define SIZE_RS422_IN		   	12	// контрольные суммы,команды
#define SIZE_CONF		       		8	// VT 15 
//SOC KIN
#define SIZE_SOC_OUT			64	 
//Мониторинг режимов РЛС
#define SIZE_RLS_MODE_IN		8	 

//радар модель											!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define SIZE_DI_T50			      	28//16
#define SIZE_Carry_T50    			80
#define SIZE_Trg_T50		    	1180 //940	//700 (добавлены компоненты скоростей) (и координаты)
#define SIZE_ToH036_RR	    		16	//4*4
#define SIZE_ToH036_VV		   	148	//4*11+4*2+4*24
#define SIZE_ToH036_UT		    	20	//4*5
#define SIZE_H036To_NormRR	 	12	//4*3
#define SIZE_H036To_NormVV		168	//4*18+4*24
#define SIZE_H036To_NormVVC	188	//4*47
#define SIZE_pMires		    		8840 

//подмена для ведомого
#define	sizeEvToCc			11*4
//подмена для 4 ведомых
#define	sizeEvToCcAdd			38*4

//БВП стенд UPG
#define	sizeIBVP	6*4			// Тип слова ULONG по 6-ти ТП.

// TACAN 
#define	SIZE_TACAN_IN	         96	// модель TACAN входы  - размер структуры в байтах 
#define	SIZE_TACAN_OUT	       113	// модель TACAN выходы - размер структуры в байтах 
#define SIZE_TACAN_FROM_ICD    82	// Размер подструктуры №1 на выход
#define SIZE_TACAN_FROM_BLOCKS  6	// Размер подструктуры №2 на выход
//	113 - (82 + 6) = 25 б запас

//выходы ИНС по РТМ
#define	 SIZE_SigmaToRtm1	130 //15*8 + 10
#define	 SIZE_SigmaToRtm2	130 //15*8 + 10
#define	 SIZE_SigmaToRtm3	130 //15*8 + 10
#define	 SIZE_SigmaToRtm4	130 //15*8 + 10

//признаки включения ОУ для платы 1 на СС1 на UPG
#define	 SIZE_MRT	32 // 2*16
#define	 SIZE_RT6	 2
#define	 SIZE_RT7	 2
#define	 SIZE_RT27	2

//от кабины 29UPG
#define SIZE_FromMks 409

// входы РК на СС  29UPG
#define	 SIZE_DC_TO_CC		16
// выходы РК с СС 29UPG
#define	 SIZE_DC_FROM_CC	25

// в модель самолета-САУ  29UPG - только структура TACS_In !!!!!!
#define	 SIZE_PLANE_ACS_IN	209	//201
// из модели самолета 29UPG
//#define	 SIZE_PLANE_OUT		1618 //=ver 9 - //1682
#define	 SIZE_PLANE_OUT		1624 // vers10 1618 //=ver 9 - //1682

//признаки реальная система или модель 
#define	 SIZE_REAL_OR_MODEL		16
//модель электропитания самолета
#define	 SIZE_MM_ELECTRO_SYS 100
//признаки отказов систем самолета 29UPG
#define	SIZE_PLANE_SYS_FAILS	64

// в модель самолета 29UPG - вся структура PlaneUPG_in
//#define	 SIZE_PLANE_IN	496 //=ver 9 443 //- for vers8         438
#define	 SIZE_PLANE_IN	519// vers10 496 //=ver 9 443 //- for vers8         438

// Тестовые параметры
#define	SIZE_TestParam1	2
#define	SIZE_TestParam2	2
#define	SIZE_TestParam3	2
#define	SIZE_TestParam4	2
#define	SIZE_TestParam5	2
#define	SIZE_TestParam6	2

// TSB
#define SIZE_Tsb2525_IN  300
#define SIZE_Tsb2525_OUT 300

//BRK
#define SIZE_BRK				   64
#define SIZE_BRK_Out			64

//признаки включения ОУ на IPC-M плата 1
#define	 SIZE_NVG_RT10	  2
#define	 SIZE_NVG_RT25	  2
#define	 SIZE_NVG_RT2	  	2
#define	 SIZE_NVG_RT_NA2	2

//на кабину 29UPG
#define SIZE_ToMks			130

//кнопка перезапуска в кабине
#define SIZE_Restart_Button	2

// Управление Вкл./Откл. ОУ для платы 1 на СС1 на MM2
#define	SIZE_RT6_NVG_MM2 	2
#define	SIZE_RT8_NVG_MM2	 2
#define	SIZE_RT14_NVG_MM2	2
#define	SIZE_RT27_NVG_MM2	2

// Управление Вкл./Откл. ОУ для платы 1 на PC12 на КУБ
#define	SIZE_RT6_NVG_KUB	 2
#define	SIZE_RT8_NVG_KUB	 2
#define	SIZE_RT14_NVG_KUB	2
#define	SIZE_RT27_NVG_KUB	2

// ANS1100
#define	SIZE_ANS1100A_IN	 176		// имитатор ANS1100A входы  - размер структуры в байтах 
#define	SIZE_ANS1100A_OUT	168		// имитатор ANS1100A выходы - размер структуры в байтах 

// ЛС КАРАТ-МФИ
#define	SIZE_KARAT_MFD_LINE_IN 	1024
#define	SIZE_KARAT_MFD_LINE_OUT	1024

// TOTEM IN
#define	SIZE_TOTEM_IN	14
// TOTEM OUT
#define	SIZE_TOTEM_OUTi01	  193
#define	SIZE_TOTEM_OUTi07   112 //111
#define	SIZE_TOTEM_OUTi14	  136
#define	SIZE_TOTEM_OUTg01	   82
#define	SIZE_TOTEM_OUTg15	   90
#define	SIZE_TOTEM_OUTg16	   49
#define	SIZE_TOTEM_OUTKal1	  90
#define	SIZE_TOTEM_OUTKal2	   8
#define	SIZE_TOTEM_OUTKal3	   8

// KSU-BCVM

#define	SIZE_KsuToBcvm		1032

#define	SIZE_BcvmToKsu		224

//признаки включения ОУ для платы TE6(1 и 2) на СС2 на T50
#define	SIZE_RT_T50  2
// RAM_A098
#define SIZE_RAM_A098_IN 4
#define SIZE_RAM_A098_OUT 32

#define SIZE_sPLANE_OUT    304 // 30*8 + 4*1 + 2*1 +1*8 + 6*8+2*1
#define SIZE_sPLANE_IN     3   // 1*1 + 2*1

#define SIZE_LinsToMkio   743 //
#define SIZE_MkioToLins   176 //

#define SIZE_BinsToMkio   755 //749 
#define SIZE_MkioToBins   196 //
#define SIZE_RT_iMKIO		2 //1*2

#define SIZE_ChannelSVS		480 //160*3
#define SIZE_DcSvsOut		10
#define SIZE_BcvmToSvs		32
#define SIZE_DcSvsIn		3

#define SIZE_BinsRTM1		131 //119+12*1 (знак)
#define SIZE_BinsRTM2		275 //247+28*1 (знак)
#define SIZE_BinsRTM4		139	//125+14*1 (знак)

#define SIZE_RlsToTarget 48 //6*8 

//.......................................

//смещения начал структур   
#define SH_StartSet          (SH_READY_StrFieldInfo + 1)
#define SH_property          (SH_StartSet + SIZE_StartSet_)    
#define SH_DCToSam           (SH_property + SIZE_Property)

#define SH_STEND             (SH_DCToSam + SIZE_DCToSam) 
#define SH_SAU_IN            (SH_STEND + SIZE_STEND) 
#define SH_SAU_OUT           (SH_SAU_IN + SIZE_SauIN)      
#define SH_VS_TO_CC          (SH_SAU_OUT + SIZE_SauOUT)     
#define SH_InSVS             (SH_VS_TO_CC + SIZE_VS_TO_CC)
#define SH_InSBKV            (SH_InSVS + SIZE_InSVS)
#define SH_InMKIO_SIGMA      (SH_InSBKV + SIZE_InSBKV)
#define SH_CC_TO_VS          (SH_InMKIO_SIGMA + SIZE_InMKIO_SIGMA)
#define SH_OutSVS            (SH_CC_TO_VS + SIZE_CC_TO_VS)
#define SH_OutSBKV           (SH_OutSVS + SIZE_OutSVS) 
#define SH_OutSIGMA_MKIO     (SH_OutSBKV + SIZE_OutSBKV)
#define SH_OutSIGMA_ANALOG   (SH_OutSIGMA_MKIO + SIZE_OutSIGMA_MKIO)
#define SH_OutA037           (SH_OutSIGMA_ANALOG + SIZE_OutSIGMA_ANALOG)

//........ параметры ОЛ...........................
#define SH_Ol_IN             (SH_OutA037 + SIZE_OutA037)
#define SH_Ol_OUT            (SH_Ol_IN + SIZE_OL_IN)  
#define SH_To_MPI            (SH_Ol_OUT + SIZE_OL_OUT)
#define SH_To_SPI            (SH_To_MPI + SIZE_TO_MPI)    //Кудряшов 20.05.09
#define SH_From_MPI          (SH_To_SPI + SIZE_TO_SPI)     //Кудряшов 20.05.09  
#define SH_To_RSS            (SH_From_MPI + SIZE_FROM_MPI)  
#define SH_To_RSS2           (SH_To_RSS + SIZE_TO_RSS)
#define SH_From_RSS          (SH_To_RSS2 + SIZE_TO_RSS2)
#define SH_To_Ukr            (SH_From_RSS + SIZE_FROM_RSS)
#define SH_From_Scenario     (SH_To_Ukr + SIZE_TO_UKROP)
#define SH_RMN_Int1						    (SH_From_Scenario + SIZE_From_Scenario)

#define SH_END_OL            (SH_RMN_Int1+ SIZE_RMN_Int1)

//........Конец параметров ОЛ.....................

//........ параметры ИПО ...........................

#define SH_ToIPO             SH_END_OL              
#define SH_END_TO_IPO        (SH_ToIPO + SIZE_TO_IPO)

#define SH_OSout             (SH_END_TO_IPO)
#define SH_OSin              (SH_OSout + sizeOS)

#define SH_Uout              (SH_OSin + sizeOS)
#define SH_Uin               (SH_Uout + sizeU)

#define SH_BORTout           (SH_Uin + sizeU)
#define SH_BORTin            (SH_BORTout + sizeBORT)

#define SH_SMSPUTout         (SH_BORTin  + sizeBORT)
#define SH_SMSPUTin          (SH_SMSPUTout + sizeSMSPUT)

#define SH_GUNin             (SH_SMSPUTin + sizeSMSPUT)
#define SH_GUNout            (SH_GUNin + sizeGUN)

#define SH_NVG_SA1_Sto_out   (SH_GUNout + sizeGUN)
#define SH_NVG_SA1_Sto_in    (SH_NVG_SA1_Sto_out + size_NVG_SA1_Sto)

#define SH_NVG_SA2_Sto_out   (SH_NVG_SA1_Sto_in + size_NVG_SA1_Sto)
#define SH_NVG_SA2_Sto_in    (SH_NVG_SA2_Sto_out + size_NVG_SA2_Sto)

#define SH_NVG_SA3_Sto_out   (SH_NVG_SA2_Sto_in + size_NVG_SA2_Sto)
#define SH_NVG_SA3_Sto_in    (SH_NVG_SA3_Sto_out + size_NVG_SA3_Sto)

#define SH_NVG_SA1_toS_out   (SH_NVG_SA3_Sto_in + size_NVG_SA3_Sto)
#define SH_NVG_SA1_toS_in    (SH_NVG_SA1_toS_out + size_NVG_SA1_toS)

#define SH_BZ_SA1_Sto_out    (SH_NVG_SA1_toS_in + size_NVG_SA1_toS)
#define SH_BZ_SA1_Sto_in     (SH_BZ_SA1_Sto_out + size_BZ_SA1_Sto)

#define SH_BZ_SA2_Sto_out    (SH_BZ_SA1_Sto_in + size_BZ_SA1_Sto)
#define SH_BZ_SA2_Sto_in     (SH_BZ_SA2_Sto_out + size_BZ_SA2_Sto)

#define SH_BZ_SA3_Sto_out    (SH_BZ_SA2_Sto_in + size_BZ_SA2_Sto)
#define SH_BZ_SA3_Sto_in     (SH_BZ_SA3_Sto_out + size_BZ_SA3_Sto)

#define SH_BZ_SA1_toS_out    (SH_BZ_SA3_Sto_in + size_BZ_SA3_Sto)
#define SH_BZ_SA1_toS_in     (SH_BZ_SA1_toS_out + size_BZ_SA1_toS)

#define SH_BZ_SA2_toS_out    (SH_BZ_SA1_toS_in + size_BZ_SA1_toS)
#define SH_BZ_SA2_toS_in     (SH_BZ_SA2_toS_out + size_BZ_SA2_toS)

#define SH_BZ_SA3_toS_out    (SH_BZ_SA2_toS_in + size_BZ_SA2_toS)
#define SH_BZ_SA3_toS_in     (SH_BZ_SA3_toS_out + size_BZ_SA3_toS)

#define SH_UROKout           (SH_BZ_SA3_toS_in  + size_BZ_SA3_toS)
#define SH_OSROKin           (SH_UROKout  + sizeROK)

#define SH_ToIR35            (SH_OSROKin  + sizeROK)
#define SH_IR35TO            (SH_ToIR35  + sizeToIR35)

#define SH_StendOutDc        (SH_IR35TO  + sizeIR35TO)
#define SH_StendInDc         (SH_StendOutDc  + SIZE_StendOutDc)

#define SH_ToSam32           (SH_StendInDc + SIZE_StendInDc)
#define SH_KSSR              (SH_ToSam32 + SIZE_ToSam32)
#define SH_Targ              (SH_KSSR + SIZE_KSSR)

#define SH_RTMToOLS          (SH_Targ + SIZE_Targ)
#define SH_OLSToBFS          (SH_RTMToOLS + SIZE_RTMToOLS)
#define SH_OLSToRTM          (SH_OLSToBFS + SIZE_OLSToBFS)

#define SH_CUtoROKin         (SH_OLSToRTM + SIZE_OLSToRTM)
#define SH_CUtoROKout        (SH_CUtoROKin + SIZE_CUtoROK)
#define SH_BKTS              (SH_CUtoROKout + SIZE_CUtoROK)
#define SH_PZ                (SH_BKTS + sizeBKTS)

//........Конец параметров ИПО .....................

#define SH_PCADS05out        (SH_PZ + sizePZ)
#define SH_PCADS05in         (SH_PCADS05out + sizePCADS05out)

#define SH_PCADS05_FPI       (SH_PCADS05in + sizePCADS05in)

//ТЛМ
#define SH_BCVMtoBRPI        (SH_PCADS05_FPI + sizePCADS05_FPI)
#define SH_BCVM_BRPI         (SH_BCVMtoBRPI + sizeBCVMtoBRPI)
#define SH_ISUtoRGS          (SH_BCVM_BRPI + sizeBCVM_BRPI)
#define SH_ISU_RGS           (SH_ISUtoRGS  + sizeISUtoRGS)
#define SH_RGStoISU          (SH_ISU_RGS +  sizeISU_RGS)
#define SH_RGS_ISU           (SH_RGStoISU +  sizeRGStoISU)
#define SH_TlmRGSto          (SH_RGS_ISU + sizeRGS_ISU)
#define SH_TlmRGS_           (SH_TlmRGSto + sizeTlmRGSto)
#define SH_CusBMKto          (SH_TlmRGS_ + sizeTlmRGS_)
#define SH_TlmBMK_           (SH_CusBMKto + sizeTlmBMKto)

#define SH_SAM_OUT           (SH_TlmBMK_ + sizeTlmBMK_)

#define SH_Svs1k_1           (SH_SAM_OUT + SIZE_SAM)
#define SH_Svs2k_1           (SH_Svs1k_1 + SIZE_Svs1k_1)
#define SH_SvsKk_1           (SH_Svs2k_1 + SIZE_Svs2k_1)
#define SH_SvsKk_2           (SH_SvsKk_1 + SIZE_SvsKk_1)
#define SH_SvsKk_3           (SH_SvsKk_2 + SIZE_SvsKk_2)
#define SH_SvsKk_4           (SH_SvsKk_3 + SIZE_SvsKk_3)
#define SH_SvsKDC            (SH_SvsKk_4 + SIZE_SvsKk_4)

#define SH_Bcvs1ToSVSK       (SH_SvsKDC + SIZE_SvsKDC)
#define SH_Bcvs2ToSVSK       (SH_Bcvs1ToSVSK + SIZE_Bcvs1ToSVSK)
#define SH_MkioToKcu         (SH_Bcvs2ToSVSK + SIZE_Bcvs2ToSVSK)
#define SH_KcuToMkio         (SH_MkioToKcu + SIZE_MkioToKcu)
#define SH_DcToSamK          (SH_KcuToMkio + SIZE_KcuToMkio)

#define SH_RAM1701_OUT       (SH_DcToSamK + SIZE_DCToSamK)
#define SH_RAM1701_IN        (SH_RAM1701_OUT + SIZE_RAM1701_OUT)

#define SH_VPout             (SH_RAM1701_IN + SIZE_RAM1701_IN)
#define SH_VPin              (SH_VPout + SIZE_VPout)

#define SH_WEAPON            (SH_VPin + SIZE_VPin)

#define SH_CcToOlsK          (SH_WEAPON + SIZE_WEAPON)

 #define SH_DcToSvsK         (SH_CcToOlsK + SIZE_CcToOlsK)

#define SH_TARGETS           (SH_DcToSvsK + SIZE_DcToSvsK)
#define SH_SamToOtnDvig		    (SH_TARGETS + SIZE_TARGETS)
#define SH_CommonNewToSam	   (SH_SamToOtnDvig + SIZE_SamToOtnDvig)

//170m
#define SH_InPack		         	(SH_CommonNewToSam + SIZE_CommonNewToSam)	// RM(5565)
#define SH_OutPack		        	(SH_InPack + SIZE_InPack)               		// RM(5565)
#define SH_OutAccel		       	(SH_OutPack + SIZE_OutPack)              	// XYZDac
#define SH_OutU			          	(SH_OutAccel + SIZE_OutAccel)            	// XYZDac
#define SH_STEND170M	       	(SH_OutU + SIZE_OutU)                  			// Гурвиц (МКИО)
#define SH_RTM170M           (SH_STEND170M + SIZE_STEND170M)           // РТМ
#define SH_MonitorMKIO       (SH_RTM170M + SIZE_RTM170M)              	// МКИО Монитор
#define SH_KMBO			          	(SH_MonitorMKIO + SIZE_MonitorMKIO)       // КМБО

//RS422/485
#define SH_RS422_OUT        (SH_KMBO + SIZE_KMBO)
#define SH_RS422_IN         (SH_RS422_OUT + SIZE_RS422_OUT)

#define SH_CONF				(SH_RS422_IN + SIZE_RS422_IN)	// VT 15 


#define SH_SosToMc2			(SH_CONF + SIZE_CONF)
#define SH_KcuToMc2			(SH_SosToMc2 + SIZE_SosToMc2)

#define SH_SOC_OUT			   (SH_KcuToMc2 + SIZE_KcuToMc2)
#define SH_RLS_MODE_IN		(SH_SOC_OUT	+ SIZE_SOC_OUT)

//радар модель
#define SH_DI_T50		  	    (SH_RLS_MODE_IN + SIZE_RLS_MODE_IN)
#define SH_Carry_T50		    (SH_DI_T50 + SIZE_DI_T50)
#define SH_Trg_T50			     (SH_Carry_T50 + SIZE_Carry_T50)
#define SH_ToH036_RR		    (SH_Trg_T50 + SIZE_Trg_T50)
#define SH_ToH036_VV		    (SH_ToH036_RR + SIZE_ToH036_RR)
#define SH_ToH036_UT		    (SH_ToH036_VV + SIZE_ToH036_VV)
#define SH_H036To_NormRR	 (SH_ToH036_UT + SIZE_ToH036_UT)
#define SH_H036To_NormVV	 (SH_H036To_NormRR + SIZE_H036To_NormRR)
#define SH_H036To_NormVVC (SH_H036To_NormVV + SIZE_H036To_NormVV)

#define SH_EvToCc		(SH_H036To_NormVVC + SIZE_H036To_NormVVC) // Слово для ведомого
#define SH_IBVP				(SH_EvToCc + sizeEvToCc)	                 // БВП стенд UPG Попова 05.08.11
#define SH_BSI				 (SH_IBVP + sizeIBVP)                     	// БСИ

#define SH_pMires_ParVV		(SH_BSI + SIZE_TACAN_OUT)

//выходы ИНС по РТМ
#define	SH_SigmaToRtm1		(SH_pMires_ParVV + SIZE_pMires)
#define	SH_SigmaToRtm2		(SH_SigmaToRtm1 + SIZE_SigmaToRtm1)
#define	SH_SigmaToRtm3		(SH_SigmaToRtm2 + SIZE_SigmaToRtm2)
#define	SH_SigmaToRtm4		(SH_SigmaToRtm3 + SIZE_SigmaToRtm3)

// Управление Вкл./Откл. ОУ для платы 1 на СС1 на UPG
#define	SH_MRT		 (SH_SigmaToRtm4 + SIZE_SigmaToRtm4)
#define	SH_RT6		 (SH_MRT + SIZE_MRT)
#define	SH_RT7		 (SH_RT6 + SIZE_RT6)
#define	SH_RT27		(SH_RT7 + SIZE_RT7)

//от кабины 29UPG
#define SH_FromMks			(SH_RT27 + SIZE_RT27)

// входы РК на СС  29UPG
#define SH_DC_TO_CC			 (SH_FromMks + SIZE_FromMks)
// выходы РК с СС 29UPG
#define	SH_DC_FROM_CC		(SH_DC_TO_CC + SIZE_DC_TO_CC)

// Тестовые параметры
#define SH_TestParam1		(SH_DC_FROM_CC + SIZE_DC_FROM_CC)
#define SH_TestParam2		(SH_TestParam1 + SIZE_TestParam1)
#define SH_TestParam3		(SH_TestParam2 + SIZE_TestParam2)
#define SH_TestParam4		(SH_TestParam3 + SIZE_TestParam3)
#define SH_TestParam5		(SH_TestParam4 + SIZE_TestParam4)
#define SH_TestParam6		(SH_TestParam5 + SIZE_TestParam5)

//на кабину 29UPG
#define SH_ToMks			(SH_TestParam6 + SIZE_TestParam6)
//кнопка перезапуска в кабине
#define SH_Restart_Button	(SH_ToMks + SIZE_ToMks)

// Управление Вкл./Откл. ОУ для платы 1 на СС1 на MM2
#define	SH_RT6_NVG_MM2		 (SH_Restart_Button + SIZE_Restart_Button)
#define	SH_RT8_NVG_MM2		 (SH_RT6_NVG_MM2 + SIZE_RT6_NVG_MM2)
#define	SH_RT14_NVG_MM2		(SH_RT8_NVG_MM2 + SIZE_RT8_NVG_MM2)
#define	SH_RT27_NVG_MM2		(SH_RT14_NVG_MM2 + SIZE_RT27_NVG_MM2)

// Управление Вкл./Откл. ОУ для платы 1 на PC12 на КУБ
#define	SH_RT6_NVG_KUB		 (SH_RT27_NVG_MM2 + SIZE_RT27_NVG_MM2)
#define	SH_RT8_NVG_KUB		 (SH_RT6_NVG_KUB + SIZE_RT6_NVG_KUB)
#define	SH_RT14_NVG_KUB		(SH_RT8_NVG_KUB + SIZE_RT8_NVG_KUB)
#define	SH_RT27_NVG_KUB		(SH_RT14_NVG_KUB + SIZE_RT27_NVG_KUB)
//4 ведомых
#define SH_EvToCcAdd		   (SH_RT27_NVG_KUB + SIZE_RT27_NVG_KUB)

// TOTEM IN
#define	SH_InTotem1			(SH_EvToCcAdd + sizeEvToCcAdd)
#define	SH_InTotem2			(SH_InTotem1  + SIZE_TOTEM_IN)
	
// KSU
#define	SH_KsuToBcvm		(SH_InTotem2  + SIZE_TOTEM_IN)

#define	SH_BcvmToKsu1		(SH_KsuToBcvm + SIZE_KsuToBcvm)
#define SH_BcvmToKsu2  (SH_BcvmToKsu1 + SIZE_BcvmToKsu)
#define SH_BcvmToKsu3  (SH_BcvmToKsu2 + SIZE_BcvmToKsu)
#define SH_BcvmToKsu4  (SH_BcvmToKsu3 + SIZE_BcvmToKsu)

//признаки включения ОУ для платы TE6(1 и 2) на СС2 на T50
#define	SH_NVG_RT11_T50			(SH_BcvmToKsu4 + SIZE_BcvmToKsu)
#define	SH_NVG_RT12_T50   (SH_NVG_RT11_T50 + SIZE_RT_T50)
#define	SH_BP_RT13_T50    (SH_NVG_RT12_T50 + SIZE_RT_T50)
#define	SH_BP_RT14_T50    (SH_BP_RT13_T50 + SIZE_RT_T50)

//дальность до НТ для УСК (UPG)
#define SH_Distance_NT_USK	(SH_BP_RT14_T50 + SIZE_RT_T50)
#define SH_KUR_NT_USK					 (SH_Distance_NT_USK + 4)
#define SH_US2_NT_USK					 (SH_KUR_NT_USK + 4)

// Управление Вкл./Откл. ОУ для платы 1 на СС2 на CMT
#define SH_RT6_NVG_CMT	   	(SH_US2_NT_USK		+ 4)
#define SH_RT7_NVG_CMT		   (SH_RT6_NVG_CMT		+ 2)
#define SH_RT_Rez1_NVG_CMT	(SH_RT7_NVG_CMT		+ 2)
#define SH_RT_Rez2_NVG_CMT	(SH_RT_Rez1_NVG_CMT	+ 2)

//Протокол САУ<-ИВК (UPG)
//исправности параметров (берутся из 30 31 разрядов)
#define SH_WD1_D_courl0		(SH_RT_Rez2_NVG_CMT	+ 2)
#define SH_WD1_D_bank1		 (SH_RT_Rez2_NVG_CMT	+ 3)
#define SH_WD1_D_pitch2		(SH_RT_Rez2_NVG_CMT	+ 4)
#define SH_WD1_D_dPB3		  (SH_RT_Rez2_NVG_CMT	+ 5)
#define SH_WD1_D_dEL4		  (SH_RT_Rez2_NVG_CMT	+ 6)
#define SH_WD1_D_dRN5		  (SH_RT_Rez2_NVG_CMT	+ 7)
#define SH_WD2_D_Z0			   (SH_RT_Rez2_NVG_CMT	+ 8)
#define SH_WD2_D_dH1		   (SH_RT_Rez2_NVG_CMT	+ 9)
#define SH_WD2_D_dPsi2		 (SH_RT_Rez2_NVG_CMT	+ 10)
#define SH_WD2_D_Ek3		   (SH_RT_Rez2_NVG_CMT	+ 11)
#define SH_WD2_D_Eg4		   (SH_RT_Rez2_NVG_CMT	+ 12)
#define SH_WD2_D_Dost5		 (SH_RT_Rez2_NVG_CMT	+ 13)
#define SH_WD2_D_Hg6		   (SH_RT_Rez2_NVG_CMT	+ 14)
#define SH_WD2_D_Hop7		  (SH_RT_Rez2_NVG_CMT	+ 15)
#define SH_WD2_D_dZ8		   (SH_RT_Rez2_NVG_CMT	+ 16)
#define SH_WD2_D_SUO9_1		(SH_RT_Rez2_NVG_CMT	+ 17)
#define SH_WD2_D_SUO9_2		(SH_RT_Rez2_NVG_CMT	+ 18)

//выходная структура системы контроля обогрева ПВД
#define SH_PVD_OUT		(SH_WD2_D_SUO9_2	+ 1)

// RAM_A098
#define SH_RAM_A098_IN		(SH_PVD_OUT	+ 3)
#define SH_RAM_A098_OUT	(SH_RAM_A098_IN + SIZE_RAM_A098_IN)
#define SH_NVG_RAM_A098	(SH_RAM_A098_OUT + SIZE_RAM_A098_OUT)

// TOTEM OUT
#define SH_OutTotemi01		(SH_NVG_RAM_A098 + SIZE_RT_T50)
#define SH_OutTotemi07		(SH_OutTotemi01 + SIZE_TOTEM_OUTi01)
#define SH_OutTotemi14		(SH_OutTotemi07 + SIZE_TOTEM_OUTi07)

#define SH_OutTotemg01		(SH_OutTotemi14 + SIZE_TOTEM_OUTi14)
#define SH_OutTotemg15		(SH_OutTotemg01 + SIZE_TOTEM_OUTg01)			
#define SH_OutTotemg16		(SH_OutTotemg15 + SIZE_TOTEM_OUTg15)			
#define SH_OutTotemKal1	(SH_OutTotemg16 + SIZE_TOTEM_OUTg16)			
#define SH_OutTotemKal2	(SH_OutTotemKal1 + SIZE_TOTEM_OUTKal1)
#define SH_OutTotemKal3	(SH_OutTotemKal2 + SIZE_TOTEM_OUTKal2)

#define SH_ToR170		(SH_OutTotemKal3 + SIZE_TOTEM_OUTKal3)		
#define SH_R170To		(SH_ToR170 + sizeToR170)

#define SH_mASP		(SH_R170To + sizeR170To)

#define SH_MSI		(SH_mASP + SIZE_mASP)

#define SH_CONTROL		(SH_MSI + SIZE_MSI)

#define SH_Mt_NVG_SA8_PtoRL		(SH_CONTROL + SIZE_CONTROL)
#define SH_Mt_NVG_SA30_RLtoP		(SH_Mt_NVG_SA8_PtoRL + size_Mt_NVG_SA8_PtoRL)

#define SH_END_Main		(SH_MSI + size_Mt_NVG_SA30_RLtoP)

// смещение для дополнительных моделей
#define SH_ADD_MODELS	0x100000

#if SH_END_Main >=  SH_ADD_MODELS
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  SH_END_Main >=  SH_ADD_MODELS  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#endif

// TACAN 
#define	SH__TACAN_IN		SH_ADD_MODELS					// смещение от начала разделяемой памяти для структуры TACAN_IN.  Вычисляется как смещение предыдущей структуры + размер предыдущей структуры.
#define	SH__TACAN_OUT	(SH__TACAN_IN + SIZE_TACAN_IN)	// смещение от начала разделяемой памяти для структуры TACAN_OUT. Вычисляется как смещение предыдущей структуры + размер предыдущей структуры.

// в модель самолета-САУ  29UPG - только структура TACS_In !!!!!!
#define	SH_PLANE_ACS_IN			(SH__TACAN_OUT + SIZE_TACAN_OUT)
// из модели самолета 29UPG
#define	SH_PLANE_OUT		(SH_PLANE_ACS_IN + SIZE_PLANE_ACS_IN)
//признаки реальная система или модель и признаки отказов самолета 29UPG
#define	SH_REAL_OR_MODEL	(SH_PLANE_OUT + SIZE_PLANE_OUT)
//	Модель электропитания самолета
#define SH_MM_ELECTRO_SYS (SH_REAL_OR_MODEL + SIZE_REAL_OR_MODEL)

//признаки отказов систем самолета 29UPG
#define	SH_PLANE_SYS_FAILS	(SH_MM_ELECTRO_SYS + SIZE_MM_ELECTRO_SYS)

// в модель самолета 29UPG - вся структура PlaneUPG_in
#define	SH_PLANE_IN		(SH_PLANE_SYS_FAILS + SIZE_PLANE_SYS_FAILS)

// TSB
#define SH__Tsb2525_IN 	(SH_PLANE_IN + SIZE_PLANE_IN)
#define SH__Tsb2525_OUT	(SH__Tsb2525_IN + SIZE_Tsb2525_IN)

//BRK
#define SH_BRK			   (SH__Tsb2525_OUT + SIZE_Tsb2525_OUT)
#define SH_BRK_Out		(SH_BRK + SIZE_BRK)

//признаки включения ОУ на IPC-M плата 1
#define	 SH_NVG_RT10  	(SH_BRK_Out	+ SIZE_BRK_Out)
#define	 SH_NVG_RT25		 (SH_NVG_RT10	+ SIZE_NVG_RT10)
#define	 SH_NVG_RT2			 (SH_NVG_RT25	+ SIZE_NVG_RT25)
#define	 SH_NVG_RT_NA2	(SH_NVG_RT2	+ SIZE_NVG_RT2)

// ANS1100A
#define	SH_ANS1100A_IN 	(SH_NVG_RT_NA2 + SIZE_NVG_RT_NA2)
#define	SH_ANS1100A_OUT	(SH_ANS1100A_IN + SIZE_ANS1100A_IN)

// ЛС КАРАТ-МФИ
#define SH_KARAT_MFD_LINE_IN	 (SH_ANS1100A_OUT + SIZE_ANS1100A_OUT)
#define SH_KARAT_MFD_LINE_OUT	(SH_KARAT_MFD_LINE_IN + SIZE_KARAT_MFD_LINE_IN)

// CockpitLampsController
#define SIZE_CockpitLampsController_OUT  108
#define SH_CockpitLampsController_OUT (SH_KARAT_MFD_LINE_OUT + SIZE_KARAT_MFD_LINE_OUT)

//	Данные по аппаратуре Tacan на борту для целей
#define SIZE_TacanTrgtsData 120
#define SH_TacanTrgtsData (SH_CockpitLampsController_OUT + SIZE_CockpitLampsController_OUT)

// TSB+
#define SIZE_Tsb2525_p_IN  4096
#define SIZE_Tsb2525_p_OUT 4096
#define SH_Tsb2525_p_IN  (SH_TacanTrgtsData + SIZE_TacanTrgtsData)
#define SH_Tsb2525_p_OUT (SH_Tsb2525_p_IN + SIZE_Tsb2525_p_IN)

//	БСРК64
#define SIZE_BSRK64 32
#define SH_BSRK64 (SH_Tsb2525_p_OUT + SIZE_Tsb2525_p_OUT)


// Tarang1B
#define SIZE_Tarang1B_IN  4096
#define SIZE_Tarang1B_OUT 4096
#define	SIZE_CT_RT10	2
#define	SIZE_CT_RT19	2
#define SH_Tarang1B_IN  (SH_BSRK64 + SIZE_BSRK64)
#define SH_Tarang1B_OUT (SH_Tarang1B_IN + SIZE_Tarang1B_IN)
#define SH_CT_RT10	     (SH_Tarang1B_OUT + SIZE_Tarang1B_OUT)
#define SH_CT_RT19      (SH_CT_RT10 + SIZE_CT_RT10)

// ACMI
#define SIZE_ACMI_IN  4096
#define SIZE_ACMI_OUT 4096
#define	SIZE_NVG_RT22	2
#define SH_ACMI_IN  (SH_CT_RT19 + SIZE_CT_RT19)
#define SH_ACMI_OUT (SH_ACMI_IN + SIZE_ACMI_IN)
#define	SH_NVG_RT22 (SH_ACMI_OUT + SIZE_ACMI_OUT)

// Karat
#define SIZE_KaratCabling 800
#define SH_KaratCabling (SH_NVG_RT22 + SIZE_NVG_RT22)

#define SIZE_Brk46Signals	64
#define SH_Brk46Signals		(SH_KaratCabling + SIZE_KaratCabling)

// Karat IIASS Unit control
#define SIZE_KiiassUnitControl 64
#define SH_KiiassUnitControl (SH_Brk46Signals + SIZE_Brk46Signals)

// WeaponSystem_DataOut
#define SIZE_WeaponSystem_DataOut 64
#define SH_WeaponSystem_DataOut (SH_KiiassUnitControl + SIZE_KiiassUnitControl)

// Cmds_DataOut
#define SIZE_Cmds_DataOut 64
#define SH_Cmds_DataOut (SH_WeaponSystem_DataOut + SIZE_WeaponSystem_DataOut)

// Karat MIL1553
#define SIZE_Karat_DataOut 1024
#define SH_Karat_DataOut (SH_Cmds_DataOut + SIZE_Cmds_DataOut)

// SpecialPurposeDataOut
#define SIZE_SpecialPurposeDataOut 1024
#define SH_SpecialPurposeDataOut (SH_Karat_DataOut + SIZE_Karat_DataOut)

//	БСРК64+
#define SIZE_BSRK64_ 128
#define SH_BSRK64_ (SH_SpecialPurposeDataOut + SIZE_SpecialPurposeDataOut)

// RWR display unit
#define SIZE_RWR_DU_IN 1024
#define SH_RWR_DU_IN (SH_BSRK64_ + SIZE_BSRK64_)
#define SIZE_RWR_DU_OUT 1024
#define SH_RWR_DU_OUT (SH_RWR_DU_IN + SIZE_RWR_DU_IN)

// Karat Analog Signals
#define SIZE_KaratAnalogSignalsInput 64
#define SH_KaratAnalogSignalsInput (SH_RWR_DU_OUT + SIZE_RWR_DU_OUT)

// ANS1100A+
#define	SIZE_ANS1100A__IN 1024
#define	SH_ANS1100A__IN	(SH_KaratAnalogSignalsInput + SIZE_KaratAnalogSignalsInput)
#define	SIZE_ANS1100A__OUT 1024
#define	SH_ANS1100A__OUT	(SH_ANS1100A__IN + SIZE_ANS1100A__IN)

// TACAN2901A+
#define	SIZE_TACAN2901A_OUT 1024
#define	SH_TACAN2901A_OUT (SH_ANS1100A__OUT + SIZE_ANS1100A__OUT)

// 
#define	SIZE_KaratMfdDataLink_IN 2048
#define	SH_KaratMfdDataLink_IN (SH_TACAN2901A_OUT + SIZE_TACAN2901A_OUT)

#define	SIZE_Armament_IN 256
#define	SH_Armament_IN (SH_KaratMfdDataLink_IN + SIZE_KaratMfdDataLink_IN)

#define	SIZE_Armament_OUT 256
#define	SH_Armament_OUT (SH_Armament_IN + SIZE_Armament_IN) 

#define	SH_sPLANE_OUT (SH_Armament_OUT + SIZE_Armament_OUT)
#define	SH_sPLANE_IN (SH_sPLANE_OUT + SIZE_sPLANE_OUT)

#define SH_LinsToMkio_INS1 (SH_sPLANE_IN + SIZE_sPLANE_IN)
#define SH_MkioToLins_INS1 (SH_LinsToMkio_INS1 + SIZE_LinsToMkio)
#define SH_LinsToMkio_INS2 (SH_MkioToLins_INS1 + SIZE_MkioToLins)
#define SH_MkioToLins_INS2 (SH_LinsToMkio_INS2 + SIZE_LinsToMkio)

#define SH_BinsToMkio_INS1 (SH_MkioToLins_INS2 + SIZE_MkioToLins)
#define SH_MkioToBins_INS1 (SH_BinsToMkio_INS1 + SIZE_BinsToMkio)
#define SH_BinsToMkio_INS2 (SH_MkioToBins_INS1 + SIZE_MkioToBins)
#define SH_MkioToBins_INS2 (SH_BinsToMkio_INS2 + SIZE_BinsToMkio)
#define SH_RT_iMKIO (SH_MkioToBins_INS2 + SIZE_MkioToBins)

#define SH_SVS_CH1 (SH_RT_iMKIO + SIZE_RT_iMKIO)
#define SH_SVS_CH2 (SH_SVS_CH1 + SIZE_ChannelSVS)
#define SH_SVS_CHK (SH_SVS_CH2 + SIZE_ChannelSVS)
#define SH_DcSvsOut (SH_SVS_CHK + SIZE_ChannelSVS)
#define SH_Bcvm1ToSvs (SH_DcSvsOut + SIZE_DcSvsOut)
#define SH_Bcvm2ToSvs (SH_Bcvm1ToSvs + SIZE_BcvmToSvs)
#define SH_DcSvsIn (SH_Bcvm2ToSvs + SIZE_BcvmToSvs)

#define SH_Bins1RTM1 (SH_DcSvsIn + SIZE_DcSvsIn)
#define SH_Bins1RTM2 (SH_Bins1RTM1 + SIZE_BinsRTM1)
#define SH_Bins1RTM4 (SH_Bins1RTM2 + SIZE_BinsRTM2)
#define SH_Bins2RTM1 (SH_Bins1RTM4 + SIZE_BinsRTM4)
#define SH_Bins2RTM2 (SH_Bins2RTM1 + SIZE_BinsRTM1)
#define SH_Bins2RTM4 (SH_Bins2RTM2 + SIZE_BinsRTM2)

#define SH_RlsToTarget (SH_Bins2RTM4 +SIZE_BinsRTM4)

#define SH_END (SH_RlsToTarget + SIZE_RlsToTarget) // конец занятой области разделяемой памяти. Вычисляется как смещение последней структуры + ее размер.

#define SIZE_SharedMem_SAM32 0x400000  //

#if SH_END >=  SIZE_SharedMem_SAM32
#pragma  message ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  SH_END >=  SIZE_SharedMem       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
#endif

