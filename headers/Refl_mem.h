//������������� ������������ ������ ������ VMIPCI-5587�

//                              �������� �������	������ �������, ����	����������
                                //00000h-0003Fh	        64	��������� ������� ������ ��������
#define SH_RESERV1      0x00040 //00040h-1FFFFh	        131008	������1
#define SH_IPC1         0x20000 //20000h-3FFFFh	        131072	������ IPC1
#define SH_IPC2         0x40000 //40000h-5FFFFh	        131072	������ IPC2
#define SH_IPC4         0x60000 //60000h-7FFFFh	        131072	������ IPC4
#define SH_IPC6         0x80000 //80000h-9FFFFh	        131072	������ IPC6
#define SH_PC1          0xA0000 //A0000h-BFFFFh	        131072	������ PC1
#define SH_PCVS1        0xC0000 //C0000h-DFFFFh	        131072	������ PC ������� ������������
#define SH_RESERV2      0xE0000 //E0000h-FFFFFh	        131072	������2


//IPC1......................................
#define SH_IPC1_TIME	SH_IPC1			//  8 ����, ��������� ����� �� IPC1
#define SH_IPC1_VS		SH_IPC1_TIME +8 //648 ����, ��������� ���� CC_TO_VS


//������ ������� ������� ���������� �� IPC1
//�� Sam32
#define SH_IPC1_FROM_SAM	SH_IPC1_VS+648			//20290-	, 1632 TSamToOLin strOLmode.h
//�� OLmode.dll
#define SH_IPC1_TO_SAM		SH_IPC1_FROM_SAM+1632	//-		,	20		TSamFromOL,  strOLmode.h
#define SH_IPC1_fFromMPI	SH_IPC1_TO_SAM+20		//-		,	72		T_FL_FROM_MPI, strOLmode.h
#define SH_IPC1_fToMPI		SH_IPC1_fFromMPI+72		//-		,	32		T_FL_TO_MPI= ,  strOLmode.h
#define SH_IPC1_OLData		SH_IPC1_fToMPI+32		//		,	96		data[],  strOLmode.h (long) 
#define SH_IPC1_FL_ToRSS	SH_IPC1_OLData+96		//�� ������������!	960		T_FL_ToRSS, strOLmode.h (������ - T_FL_ToUkrop)

#define FreeIPC1	 	SH_IPC1_FL_ToRSS+960	//0x20D8C=134540					0




//.......��������, IPC2......................................
// ������ ������� �������� ���������� �� IPC1
#define SH_IPC2_IN			SH_IPC2+0x100	//0x100-������		
// OUT
#define SH_IPC2_MPI			SH_IPC2_IN				//0x100



//	��������� ������� ������������ PCVS1
#define SH_PCVS1_TIME		SH_PCVS1// 8 ����, ��������� ����� �� PCVS1
#define SH_VS_IPC1			SH_PCVS1_TIME + 8// 112 ����, ��������� ���� VS_TO_CC