
#ifndef m002
#define m002

//????????? - ?????? ?.?.
//1 - ?????????? ????? ????????? ?? 8 - ????? ?? ???????
//2 - ? ????????? TUprASP double ???????? ?? short ? ???????????? ??????????
//3 - ? ????????? TIn0200 double ???????? ?? long ? ???????????? 
//  - 0.1 ????? ??? ??????????
//  - 10^-4??? ??? ??????? ???????
//  - 10^-4???/? ??? ??????? ?????????
//  - 10^-4 ?????/c ??? ?????????  
//  - 10^-4 ??? ?????????? ? ????
//  - 
//27/11/2006
//??????? ??????? ???? ????????? char
//???????? ????????????? short ?? unsigned short
//? struct TUprASP ?????? ??????? ?????? ?? float
//? struct TParamASP ?????? double -> float

//???????? ??????? / ???????? ?????????? ????????? ??? ?? (63, 07, ????)


#define QNT_POINT       8
#define QNT_POINT_CIKL  6

#define QNT_POINT_X31   4
#define QNT_POINT_X35   4
#define nWORDsX31      10

enum TCodeASP {
    _500KR,
				_63T,
				_63TE,
				_AB,
				_AB_MBD,
				_S_24,
				_S_13,
				_S_8,
				_77A,
				_77P,
    _65ML2_PRB,
    _65ML2_OFBCH };

enum TM_31A{ _S_31A_115, _S_31A_157, _S_31A_141, _S_31A_154, _S_31A_156, _S_31A_153, _S_31A_152, _S_31A_150, _S_31A_151, _S_31A_155};
//?????????????????? ??? ???? ?115,157,141,154,156,153,152,150,151,155
//115(77), 157 (111), 141 (97), 154 (108), 156 (110), 153 (107), 152 (106),150	(104), 151 (105), 155 (151)

// ???????????? ?????? 0700 ???.
struct TRK_ASP // ??????? ?? ??? ?? ?????? ????????
 {
 unsigned short Razar_07    :1;  // 0// ????? (?????) ??? ?07  ??12 (->d12)
 unsigned short Aim_07      :1;  // 1// ???? ??? ?07           ??29 (->d29)   
 unsigned short RZ_07       :1;  // 2// ?? ??? ?07             ??26 (->d26)
 unsigned short Podg_07     :1;  // 3// ?????????? ??? ?07     U10
 unsigned short TactSbr_07  :1;  // 4// ???? ????? ??? ?07     U9
 unsigned short Razar_63    :1;  // 5// ???? (?????) ??? 63    ??12 (->d12)
 unsigned short RZ_63       :1;  // 6// ?? ??? 63              ??26 (->d26)
 unsigned short Focus1      :1;  // 7// ????? 1 ??? 63         ??7  (->d7)
 unsigned short Focus2      :1;  // 8// ????? 2 ??? 63         ??6  (->d6)
 unsigned short OtklDN      :1;  // 9// ???? ?? ??? 63         ??28 (->d28)
 unsigned short CMD         :1;  //10// ????????? ?????								K20
 unsigned short PuskRele    :1;  //11// ???? ?? ???? ??? 63    U9
 unsigned short PuskEK      :1;  //12// ???? ?? ???.           U11
 unsigned short TactSbrNASP :1;  //13// ???? ????? ??? ??/???  U13
 unsigned short PuskPP      :1;  //14// ???? ?? ??             U10
 unsigned short Pit27       :1;  //15// ??????? +27 ??? 65??   U15 ???
                                     //                        0.5?  
};

// ????????? ????????? ??? ? ???? ??????? ?? ?????? ????????
struct TStateASP
 {
 unsigned char shod;   // ??????????????? ?? ????????? ???????? ???????, ????????? ??? ??????????????? Zagr[i]
                       // ?? ????????? ????? ???? ???????? ????????,??????? ? ???
 unsigned char zahvat; // ->OS10
 unsigned char gotov;  // ->OS11
 unsigned char NULL_PUS;    // ??????
 };

// ??????? ????????? ??? ????????? ??? ?? (63, 07, ????)

struct TIn0200 //  ???????? ? RM 0x60008, ????? ?????? 328 ????
  { 
  // ???????? ??????? 
  // ???????? ? RM 0x60008, ?????? 32 (4*8) ?????
  struct TZagr
   {    
  unsigned short CodeASP;  // ??? ???????????? - TCodeASP; ??? ?????????????? - ??? ????? ? ????
                           //  0 : ?07, ??
                           //  1 : 63?
                           //  2 : 63??, 
                           //  3 : ??
                           //  4 : ?? ?? ???
                           //  5 : ?24
                           //  6 : ?13
                           //  7 : ?8
                           //  8 : 77A
                           //  9 : 77P
                           // 10 : 65ML2_PRB
                           // 11 : 65ML2_OFBCH  ????
  unsigned short TypeASP;  // 0 - ????? ??????, 1 - ?????????????, 2 - ???????????;
   } Zagr[QNT_POINT];               // Zagr[0] - 1-? ??, Zagr[1] - 2-? ?? ...

  // ??????? ?????????? ?? ??? ?? ?????? ????????
  // ???????? ? RM 0x60028, ????? ?????? 160 (20*8) ????
 struct TUprASP
  {  
  float Om_y;    // ??????? ???????? ?????????? ??? (?????)
  float Om_z;    // ??????? ???????? ?????????? ??? (?????)
  float Gama_0;  // ???? ???????? (?????)
  float Omg_zad; // ?????_??? ? ???????? ??????? (?????)
  TRK_ASP RK_ASP;
  unsigned short MFI;     // ????? ??????? ??. ???? 0 ?? ?? ??? ??????? ??????????? ??????.
  }UprASP[QNT_POINT];

  //  ???????? ? RM 0x600C8, ????? ?????? ?? H_c ???????????? 104 ????
 long fi;      // ?????? ??????? (??? = pi/2, ??????(rad) = (long fi * ???) / 1073741824)
 long lm;      // ??????? ???????(??? = pi/2, ??????(rad) = (long fi * ???) / 1073741824)
 long H;       // ?????? ??? ??????? (0.1 * ?????)
 long Habs;      // ?????? ?????????? ??????????????? (0.1 * ?????)
 long Hg;      // ?????? ??? ???????????? ?????????????? (0.1 * ?????)
 long Psi_ist;     // ???? ???????? (???)(10^-4???)
 long Teta;      // ?????? (10^-4???)
 long Gamma;      // ???? (10^-4???)
 long Wn;      // ???????? ??????? ???????? (10^-4 ?????/c)
 long We;      // ???????? ??????? ????????? (10^-4 ?????/c)
 long Wh;      // ???????? ???????????? (10^-4 ?????/c)
 long Omg_x;      // ??????? ???????? ("+" - ?????? ????, 10^-4???/?)
 long Omg_y;      // ??????? ???????? ("+" - ????? ?? ?????, 10^-4???/?)
 long Omg_z;      // ??????? ???????? ("+" - ?? ????????????, 10^-4???/?)
 long Nx;      // ?????????? ?????????? 10^-4
 long Ny;      // ???????????? ?????????? 10^-4
 long Nz;      // ??????? ?????????? ("+" - ??????) 10^-4
 long Fz_d;      // ???? ????????? ????????? ("+" - ?????) (10^-4???)
 long Vist;      // ???????? ???????? (10^-4 ?????/c)
 long Vpr;      // ???????? ????????? (10^-4 ?????/c)
 long M;       // ????? ???? 10^-4
 long alfa;      // ???? ????? (10^-4???)
 long beta;      // ???? ?????????? (10^-4???)
 long fi_c;      // ?????? ???? (??? = pi/2, ??????(rad) = (long fi * ???) / 1073741824)
 long lm_c;      // ??????? ???? (??? = pi/2, ??????(rad) = (long fi * ???) / 1073741824)
 long H_c;      // ?????? ???? ??? ??????? (0.1 * ?????)
    
 // ????????? ?? ????????????.
 //  ???????? ? RM 0x60130, ????? ?????? 32 (4*8)????
 float Dpp[QNT_POINT];   // ????????? ?? ??????????? ? ??????????? ???????????. (0.1 * ?????)

 SYSTEMTIME TIME_SNS; // ????????? ?????

 // ????????? 4-? ????? ??? 77A
 //  ???????? ? RM 0x60160, ?????? 208 (13*4*4)????
struct sX31
		{
		unsigned long  RTM_mas[nWORDsX31];// ??? ?????? ???? ? ???. 77A //32-???, ??? ?????????? ??????
		//?????????????????? ??? ???? ?115,157,141,154,156,153,152,150,151,155
		long fi_c;						// ?????? ?? ??????? (10^-4???)
		long lm_c;						// ??????? ?? ???????(10^-4???)
		long H_c;						// ?????? ?? ??? ??????? (0.1 * ?????)
		} X31[QNT_POINT_X31];

 // ????? ??????? ?????? 0x601FC
 };


// ???????? ????????? ?? ????????? ??? ?? (63, 07, ????)

 struct TOut0200  //  ???????? ? RM 0x60300, ????? ?????? 288 (36*8) ????
  {
  // ????????? ?????????? ??? ?? ?????? ???????? ? ???????????? 
  struct TParamASP
   {
  float fi_z;    // ???? ?????????? ????? ??????????? ? ??? ("+" - ?????, ???)
  float fi_y;    // ???? ?????????? ????? ??????????? ? ???, ?????? ??????? ("+" - ?????, ???)
  float fi_gam;   // ???? ????????? ??????????? ("+" - ???? ?????? ?????? ??????? ???????)
  float fi_z_pp;   // ???? ?????????? ??????????? ??????????? ? ??? ("+" - ?????, ???)
  float fi_y_pp;   // ???? ?????????? ??????????? ??????????? ? ???, ?????? ??????? ("+" - ?????, ???)
  float dFhor;   // ?????? ???? ?????? ?? ??????????? (???)
  float dFvert;   // ?????? ???? ?????? ?? ????????? (???)
  unsigned short TYPE_IND;// ??? ?????????: 0 ? K07 ?? ???????, 1 ? K07 ? ???,  2 - 63;
  unsigned short res; // ??????
  TStateASP StateASP;
   }ParamASP[QNT_POINT_CIKL];
 long fi;      // ?????? ??????? (??? = pi/2, ??????(rad) = (long fi * ???) / 1073741824)
 long lm;      // ??????? ???????(??? = pi/2, ??????(rad) = (long fi * ???) / 1073741824)
 long H;       // ?????? ??? ??????? (0.1 * ?????)
 long Psi_ist;     // ???? ???????? (???)(10^-4???)
 long Teta;      // ?????? (10^-4???)
 long Gamma;      // ???? (10^-4???)
 long res[12];
  } ;
  

#endif
