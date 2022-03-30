#define VMIPCI5587_APP
#define __SUCCESS	0

#define EPSILON 0.0001   // Define your own tolerance
#define FLOAT_EQ(x,v) (((v - EPSILON) < x) && (x <( v + EPSILON)))


//======Otladka==========================================

#define UKROP_WITHOUT_MPI1			//� ����� ������ ������ �� ���� ��������� 1,2 �����, ���� ��� ����� � ���� �������� � ���
#define WITHOUT_HLI1				//������������� �������� ��

#define SPEAKER_PORT ((PUCHAR)0x61)	//Port IO address for speaker
#define GATE_BIT	0x02

#define MAX_IN_RAY	2				//������������ ���. ����� � ����=����� �������
//#define MAX_IN_RAY	20				//������������ ���. ����� � ����=����� �������


#define JAMM_ON_VA_STT	0 //�� ���
#define JAMM_ON_SA_STT	1 //	�� ���
#define JAMM_ON_STT		2 //��
#define JAMM_ON_DESIGN	3 //�����
#define JAMM_ON_PK100	4 //���.��-100 

#define NUM_JAMM	5 //����������� ������� �����
//���� �����
#define JAMM_U_SP	0 //�������� �� ��������
#define JAMM_U_D	1 //�������� �� ���������
#define JAMM_U_SP_D	2 //������������� - �������� �� ��������/���������
#define JAMM_NOISE	3 //�������
#define JAMM_USP_JUNC	4 //�������� �� �������� ���������������
#define JAMM_UD_JUNC 5 //��� + �������� �� �������� 
#define JAMM_U_NOISE 6 //��� + �������� �� �������� 
#define JAMM_KOG	7 //�����������
#define JAMM_POL	8 //���������������
#define JAMM_8		9 //rezerv

//���� ������
#define MASK_KI 0xF
#define VA_SCAN 1
#define VA_STT	2
#define VA_TWS1	3
#define VA_TWS2	4
#define SA_SCAN	5
#define SA_STT	6
#define SA_TWS1	7
#define SA_TWS2	8
#define BB	9
#define MAP_LR	10	
#define MAP_MR	11
#define MAP_HR1	12
#define MAP_HR2	13
#define VRT_STT	14
#define GRC_RGC	15
#define ISN	16
#define SNDC1	17
#define SNDC2	18
#define KKS	19
#define IDZ	19
#define MVP	21
#define PHZ	22
#define JAM_ON	0x40  //6 ������- �������� ������
#define FLAG_STOP	0x80  //7 ������- c���
#define DESIGN	0xFF //�� ��������� ���

//�������
//������� ��� � ������ ���������
#ifdef UNDER_RTSS
 #define PrintStruct(TStr) RtPrintf("size\t"#TStr"=\t0x%x\t(%i)\n",sizeof(TStr),sizeof(TStr));
 #define PrintStructADD(TStr) ltmp+=sizeof(TStr);RtPrintf("size\t"#TStr"=\t0x%x\t(%i)\t\t Offset=%i\n",sizeof(TStr),sizeof(TStr),ltmp);
 #define PrintFileStructADD(TStr) 
#else
 #define PrintStruct(TStr) printf("size\t"#TStr"=\t0x%x\t(%i)\n",sizeof(TStr),sizeof(TStr));
 #define PrintStructADD(TStr) ltmp+=sizeof(TStr);printf("size\t"#TStr"=\t0x%x\t(%i)\t\t Offset=%i\n",sizeof(TStr),sizeof(TStr),ltmp);
 #define PrintFileStructADD(TStr) ltmp+=sizeof(TStr);os<<"size\t"#TStr"=\t"<<sizeof(TStr)<<"\t(0x"<<hex<<sizeof(TStr)<<")\t\t Offset="<<dec<<ltmp<<endl;

#endif

//���������� � ��������� ���������� �������� � �������� -��������, GLOBAL[55]
//#define JoinInd(lpSTR,TStr,i) wsprintf(lpSTR,""#TStr"[%i]",i);
//#define JoinString(lpSTR,str1,str2) wsprintf(lpSTR,"%s%s",str1,str2);
//StrName - ��� ���������
//StrField- ��� ���� ��� �������!
//lpSTR   - �������� ������ ��� ���������� � ��������
//#define WriteFieldInfo(StrName, StrField, SHM_StrOffset,lpSTR) WriteStrFieldInfo(&StrName,lpSTR ,typeid( StrField ).name(), &StrField, SHM_StrOffset);
//.........������ ������������� ���������������� ��� ������ ����� ��������� .....
//.........�� ������� ��������...................................................
//	char lpStr[512]; - ���������� �������� ����������
//  lpStr[0]	=0;
//  ������ ������ (������- � �����)
//		i = 0;
//->������������ ������
//	  JoinInd(lpStr,SamToOl.targ,i);//lpStr="SamToOl.targ[0]"
//->������������ ��� ����	  
//	  strcat(lpStr,".DALN");		//lpStr="SamToOl.targ[0].DALN"
//->�������� ���������� � SHM
//	  WriteFieldInfo(SamToOl,  SamToOl.targ[i].DALN, SH_Ol_OUT,lpStr)
	 
//.........������ ������������� ���������������� ��� ������ ����� ���������......
//.........- �������� �������............................................................
//->������������ ������->�������� ���������� � SHM
//		JoinInd(lpStr,OlToSam.Status,i);//lpStr="OlToSam.Status[0]"
//		WriteFieldInfo(OlToSam,  OlToSam.Status[i], SH_Ol_IN,lpStr)

	 
	 
	
//������ 18-���������� ������ �� ini-file
#define MPIAddrRead(n) GetPrivateProfileString("MPI", "A"#n, "0", Addr, sizeof(Addr),FullNameIniFile); mpi_a[n].mpiAddr = strtol(string, &stopstring, base );
//������ ���� ������ �� ini-file
#define ModeRead(n) mpi_a[n].mode = GetPrivateProfileInt("MPI", "MODE"#n, 1, FullNameIniFile); if (mpi_a[n].mode ==0) mpi_a[n].mode =5;
// setting of random pointer S
// to int pointer with shift i from initial address in S
#define MAKE_INTPTR(S,i) ( ( (int*)( (void*)&S)+i )  )

// setting of random pointer S
// to int pointer with shift i from initial address in S
#define MAKE_INT(S,i) ( *( (int*)( (void*)&S)+i )  )

// setting of random pointer S
// to float type with shift i from initial address in S
#define MAKE_FLOAT(S,i) ( *( (float*)( (void*)&S)+i )  )
// setting of random pointer S
// to float type with shift i from initial address in S
#define MAKE_DOUBLE(S,i) ( *( (double*)( (void*)&S)+i )  )
