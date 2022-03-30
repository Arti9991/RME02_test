#ifndef MIRES_BCVM_H_
#define MIRES_BCVM_H_

#undef EXTERN_MIRES
#undef MIRESEq
#undef MIRESEqList

#if(!defined SCPO_OUT_MIRES)

#define EXTERN_MIRES extern
#define MIRESEq(x)
#else*/
#define EXTERN_MIRES
#define MIRESEq(x) = (x)
#define MIRESEqList
#endif /* SCPO_OUT_MIRES */

 /*   Входной интерфейс задачи *** OUT_MIRES ***  */


/****************************************************************************/
/*               Выходная информация Mires (Входы БЦВМ)                     */

 /* Описаниe валидностей выходных сигналов Mires */


EXTERN_MIRES double  N036_dln_do_C_nf_1_;
EXTERN_MIRES double  N036_dln_do_C_nf_2_;
EXTERN_MIRES double  N036_dln_do_C_nf_3_;
EXTERN_MIRES double  N036_dln_do_C_nf_4_;
EXTERN_MIRES double  N036_dln_do_C_nf_5_;
EXTERN_MIRES double  N036_dln_do_C_nf_6_;
EXTERN_MIRES double  N036_dln_do_C_nf_7_;
EXTERN_MIRES double  N036_dln_do_C_nf_8_;
EXTERN_MIRES double  N036_dln_do_C_nf_9_;
EXTERN_MIRES double  N036_dln_do_C_nf_10_;
EXTERN_MIRES double  N036_dln_do_C_nf_11_;
EXTERN_MIRES double  N036_dln_do_C_nf_12_;
EXTERN_MIRES double  N036_dln_do_C_nf_13_;
EXTERN_MIRES double  N036_dln_do_C_nf_14_;
EXTERN_MIRES double  N036_dln_do_C_nf_15_;
EXTERN_MIRES double  N036_dln_do_C_nf_16_;
EXTERN_MIRES double  N036_dln_do_C_nf_17_;
EXTERN_MIRES double  N036_dln_do_C_nf_18_;
EXTERN_MIRES double  N036_dln_do_C_nf_19_;
EXTERN_MIRES double  N036_dln_do_C_nf_20_;
EXTERN_MIRES double  N036_V_C_nf_1_;
EXTERN_MIRES double  N036_V_C_nf_2_;
EXTERN_MIRES double  N036_V_C_nf_3_;
EXTERN_MIRES double  N036_V_C_nf_4_;
EXTERN_MIRES double  N036_V_C_nf_5_;
EXTERN_MIRES double  N036_V_C_nf_6_;
EXTERN_MIRES double  N036_V_C_nf_7_;
EXTERN_MIRES double  N036_V_C_nf_8_;
EXTERN_MIRES double  N036_V_C_nf_9_;
EXTERN_MIRES double  N036_V_C_nf_10_;
EXTERN_MIRES double  N036_V_C_nf_11_;
EXTERN_MIRES double  N036_V_C_nf_12_;
EXTERN_MIRES double  N036_V_C_nf_13_;
EXTERN_MIRES double  N036_V_C_nf_14_;
EXTERN_MIRES double  N036_V_C_nf_15_;
EXTERN_MIRES double  N036_V_C_nf_16_;
EXTERN_MIRES double  N036_V_C_nf_17_;
EXTERN_MIRES double  N036_V_C_nf_18_;
EXTERN_MIRES double  N036_V_C_nf_19_;
EXTERN_MIRES double  N036_V_C_nf_20_;
EXTERN_MIRES unsigned char N036_DS_SNP_1_;
EXTERN_MIRES unsigned char N036_DS_SNP_2_;
EXTERN_MIRES unsigned char N036_DS_SNP_3_;
EXTERN_MIRES unsigned char N036_DS_SNP_4_;
EXTERN_MIRES unsigned char N036_DS_SNP_5_;
EXTERN_MIRES unsigned char N036_DS_SNP_6_;
EXTERN_MIRES unsigned char N036_DS_SNP_7_;
EXTERN_MIRES unsigned char N036_DS_SNP_8_;
EXTERN_MIRES unsigned char N036_DS_SNP_9_;
EXTERN_MIRES unsigned char N036_DS_SNP_10_;
EXTERN_MIRES unsigned char N036_DS_SNP_11_;
EXTERN_MIRES unsigned char N036_DS_SNP_12_;
EXTERN_MIRES unsigned char N036_DS_SNP_13_;
EXTERN_MIRES unsigned char N036_DS_SNP_14_;
EXTERN_MIRES unsigned char N036_DS_SNP_15_;
EXTERN_MIRES unsigned char N036_DS_SNP_16_;
EXTERN_MIRES unsigned char N036_DS_SNP_17_;
EXTERN_MIRES unsigned char N036_DS_SNP_18_;
EXTERN_MIRES unsigned char N036_DS_SNP_19_;
EXTERN_MIRES unsigned char N036_DS_SNP_20_;
EXTERN_MIRES double  N036_ygl_az_c_nf_1_;
EXTERN_MIRES double  N036_ygl_az_c_nf_2_;
EXTERN_MIRES double  N036_ygl_az_c_nf_3_;
EXTERN_MIRES double  N036_ygl_az_c_nf_4_;
EXTERN_MIRES double  N036_ygl_az_c_nf_5_;
EXTERN_MIRES double  N036_ygl_az_c_nf_6_;
EXTERN_MIRES double  N036_ygl_az_c_nf_7_;
EXTERN_MIRES double  N036_ygl_az_c_nf_8_;
EXTERN_MIRES double  N036_ygl_az_c_nf_9_;
EXTERN_MIRES double  N036_ygl_az_c_nf_10_;
EXTERN_MIRES double  N036_ygl_az_c_nf_11_;
EXTERN_MIRES double  N036_ygl_az_c_nf_12_;
EXTERN_MIRES double  N036_ygl_az_c_nf_13_;
EXTERN_MIRES double  N036_ygl_az_c_nf_14_;
EXTERN_MIRES double  N036_ygl_az_c_nf_15_;
EXTERN_MIRES double  N036_ygl_az_c_nf_16_;
EXTERN_MIRES double  N036_ygl_az_c_nf_17_;
EXTERN_MIRES double  N036_ygl_az_c_nf_18_;
EXTERN_MIRES double  N036_ygl_az_c_nf_19_;
EXTERN_MIRES double  N036_ygl_az_c_nf_20_;
EXTERN_MIRES unsigned  N036_hour_izm_1_;
EXTERN_MIRES unsigned  N036_hour_izm_2_;
EXTERN_MIRES unsigned  N036_hour_izm_3_;
EXTERN_MIRES unsigned  N036_hour_izm_4_;
EXTERN_MIRES unsigned  N036_hour_izm_5_;
EXTERN_MIRES unsigned  N036_hour_izm_6_;
EXTERN_MIRES unsigned  N036_hour_izm_7_;
EXTERN_MIRES unsigned  N036_hour_izm_8_;
EXTERN_MIRES unsigned  N036_hour_izm_9_;
EXTERN_MIRES unsigned  N036_hour_izm_10_;
EXTERN_MIRES unsigned  N036_hour_izm_11_;
EXTERN_MIRES unsigned  N036_hour_izm_12_;
EXTERN_MIRES unsigned  N036_hour_izm_13_;
EXTERN_MIRES unsigned  N036_hour_izm_14_;
EXTERN_MIRES unsigned  N036_hour_izm_15_;
EXTERN_MIRES unsigned  N036_hour_izm_16_;
EXTERN_MIRES unsigned  N036_hour_izm_17_;
EXTERN_MIRES unsigned  N036_hour_izm_18_;
EXTERN_MIRES unsigned  N036_hour_izm_19_;
EXTERN_MIRES unsigned  N036_hour_izm_20_;
EXTERN_MIRES unsigned  N036_min_izm_1_;
EXTERN_MIRES unsigned  N036_min_izm_2_;
EXTERN_MIRES unsigned  N036_min_izm_3_;
EXTERN_MIRES unsigned  N036_min_izm_4_;
EXTERN_MIRES unsigned  N036_min_izm_5_;
EXTERN_MIRES unsigned  N036_min_izm_6_;
EXTERN_MIRES unsigned  N036_min_izm_7_;
EXTERN_MIRES unsigned  N036_min_izm_8_;
EXTERN_MIRES unsigned  N036_min_izm_9_;
EXTERN_MIRES unsigned  N036_min_izm_10_;
EXTERN_MIRES unsigned  N036_min_izm_11_;
EXTERN_MIRES unsigned  N036_min_izm_12_;
EXTERN_MIRES unsigned  N036_min_izm_13_;
EXTERN_MIRES unsigned  N036_min_izm_14_;
EXTERN_MIRES unsigned  N036_min_izm_15_;
EXTERN_MIRES unsigned  N036_min_izm_16_;
EXTERN_MIRES unsigned  N036_min_izm_17_;
EXTERN_MIRES unsigned  N036_min_izm_18_;
EXTERN_MIRES unsigned  N036_min_izm_19_;
EXTERN_MIRES unsigned  N036_min_izm_20_;
EXTERN_MIRES unsigned  N036_sec_izm_1_;
EXTERN_MIRES unsigned  N036_sec_izm_2_;
EXTERN_MIRES unsigned  N036_sec_izm_3_;
EXTERN_MIRES unsigned  N036_sec_izm_4_;
EXTERN_MIRES unsigned  N036_sec_izm_5_;
EXTERN_MIRES unsigned  N036_sec_izm_6_;
EXTERN_MIRES unsigned  N036_sec_izm_7_;
EXTERN_MIRES unsigned  N036_sec_izm_8_;
EXTERN_MIRES unsigned  N036_sec_izm_9_;
EXTERN_MIRES unsigned  N036_sec_izm_10_;
EXTERN_MIRES unsigned  N036_sec_izm_11_;
EXTERN_MIRES unsigned  N036_sec_izm_12_;
EXTERN_MIRES unsigned  N036_sec_izm_13_;
EXTERN_MIRES unsigned  N036_sec_izm_14_;
EXTERN_MIRES unsigned  N036_sec_izm_15_;
EXTERN_MIRES unsigned  N036_sec_izm_16_;
EXTERN_MIRES unsigned  N036_sec_izm_17_;
EXTERN_MIRES unsigned  N036_sec_izm_18_;
EXTERN_MIRES unsigned  N036_sec_izm_19_;
EXTERN_MIRES unsigned  N036_sec_izm_20_;
EXTERN_MIRES double  N036_msec_izm_1_;
EXTERN_MIRES double  N036_msec_izm_2_;
EXTERN_MIRES double  N036_msec_izm_3_;
EXTERN_MIRES double  N036_msec_izm_4_;
EXTERN_MIRES double  N036_msec_izm_5_;
EXTERN_MIRES double  N036_msec_izm_6_;
EXTERN_MIRES double  N036_msec_izm_7_;
EXTERN_MIRES double  N036_msec_izm_8_;
EXTERN_MIRES double  N036_msec_izm_9_;
EXTERN_MIRES double  N036_msec_izm_10_;
EXTERN_MIRES double  N036_msec_izm_11_;
EXTERN_MIRES double  N036_msec_izm_12_;
EXTERN_MIRES double  N036_msec_izm_13_;
EXTERN_MIRES double  N036_msec_izm_14_;
EXTERN_MIRES double  N036_msec_izm_15_;
EXTERN_MIRES double  N036_msec_izm_16_;
EXTERN_MIRES double  N036_msec_izm_17_;
EXTERN_MIRES double  N036_msec_izm_18_;
EXTERN_MIRES double  N036_msec_izm_19_;
EXTERN_MIRES double  N036_msec_izm_20_;
EXTERN_MIRES unsigned  N036_Rev_izl_1_;
EXTERN_MIRES unsigned  N036_Rev_izl_2_;
EXTERN_MIRES unsigned  N036_Rev_izl_3_;
EXTERN_MIRES unsigned  N036_Rev_izl_4_;
EXTERN_MIRES unsigned  N036_Rev_izl_5_;
EXTERN_MIRES unsigned  N036_Rev_izl_6_;
EXTERN_MIRES unsigned  N036_Rev_izl_7_;
EXTERN_MIRES unsigned  N036_Rev_izl_8_;
EXTERN_MIRES unsigned  N036_Rev_izl_9_;
EXTERN_MIRES unsigned  N036_Rev_izl_10_;
EXTERN_MIRES unsigned  N036_Rev_izl_11_;
EXTERN_MIRES unsigned  N036_Rev_izl_12_;
EXTERN_MIRES unsigned  N036_Rev_izl_13_;
EXTERN_MIRES unsigned  N036_Rev_izl_14_;
EXTERN_MIRES unsigned  N036_Rev_izl_15_;
EXTERN_MIRES unsigned  N036_Rev_izl_16_;
EXTERN_MIRES unsigned  N036_Rev_izl_17_;
EXTERN_MIRES unsigned  N036_Rev_izl_18_;
EXTERN_MIRES unsigned  N036_Rev_izl_19_;
EXTERN_MIRES unsigned  N036_Rev_izl_20_;
EXTERN_MIRES unsigned char  N036_Pr_OI_1_;
EXTERN_MIRES unsigned char  N036_Pr_OI_2_;
EXTERN_MIRES unsigned char  N036_Pr_OI_3_;
EXTERN_MIRES unsigned char  N036_Pr_OI_4_;
EXTERN_MIRES unsigned char  N036_Pr_OI_5_;
EXTERN_MIRES unsigned char  N036_Pr_OI_6_;
EXTERN_MIRES unsigned char  N036_Pr_OI_7_;
EXTERN_MIRES unsigned char  N036_Pr_OI_8_;
EXTERN_MIRES unsigned char  N036_Pr_OI_9_;
EXTERN_MIRES unsigned char  N036_Pr_OI_10_;
EXTERN_MIRES unsigned char  N036_Pr_OI_11_;
EXTERN_MIRES unsigned char  N036_Pr_OI_12_;
EXTERN_MIRES unsigned char  N036_Pr_OI_13_;
EXTERN_MIRES unsigned char  N036_Pr_OI_14_;
EXTERN_MIRES unsigned char  N036_Pr_OI_15_;
EXTERN_MIRES unsigned char  N036_Pr_OI_16_;
EXTERN_MIRES unsigned char  N036_Pr_OI_17_;
EXTERN_MIRES unsigned char  N036_Pr_OI_18_;
EXTERN_MIRES unsigned char  N036_Pr_OI_19_;
EXTERN_MIRES unsigned char  N036_Pr_OI_20_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_1_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_2_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_3_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_4_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_5_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_6_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_7_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_8_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_9_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_10_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_11_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_12_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_13_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_14_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_15_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_16_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_17_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_18_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_19_;
EXTERN_MIRES double  N036_ygl_mesta_C_nf_20_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_1_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_2_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_3_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_4_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_5_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_6_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_7_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_8_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_9_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_10_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_11_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_12_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_13_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_14_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_15_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_16_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_17_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_18_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_19_;
EXTERN_MIRES unsigned  N036_No_trC_naz_N036_20_;

// Результат ГО
EXTERN_MIRES unsigned  N036_GO_1_;
EXTERN_MIRES unsigned  N036_GO_2_;
EXTERN_MIRES unsigned  N036_GO_3_;
EXTERN_MIRES unsigned  N036_GO_4_;
EXTERN_MIRES unsigned  N036_GO_5_;
EXTERN_MIRES unsigned  N036_GO_6_;
EXTERN_MIRES unsigned  N036_GO_7_;
EXTERN_MIRES unsigned  N036_GO_8_;
EXTERN_MIRES unsigned  N036_GO_9_;
EXTERN_MIRES unsigned  N036_GO_10_;
EXTERN_MIRES unsigned  N036_GO_11_;
EXTERN_MIRES unsigned  N036_GO_12_;
EXTERN_MIRES unsigned  N036_GO_13_;
EXTERN_MIRES unsigned  N036_GO_14_;
EXTERN_MIRES unsigned  N036_GO_15_;
EXTERN_MIRES unsigned  N036_GO_16_;
EXTERN_MIRES unsigned  N036_GO_17_;
EXTERN_MIRES unsigned  N036_GO_18_;
EXTERN_MIRES unsigned  N036_GO_19_;
EXTERN_MIRES unsigned  N036_GO_20_;

// Дополнительный признак ГО
EXTERN_MIRES unsigned  N036_Rez_GO_1_;
EXTERN_MIRES unsigned  N036_Rez_GO_2_;
EXTERN_MIRES unsigned  N036_Rez_GO_3_;
EXTERN_MIRES unsigned  N036_Rez_GO_4_;
EXTERN_MIRES unsigned  N036_Rez_GO_5_;
EXTERN_MIRES unsigned  N036_Rez_GO_6_;
EXTERN_MIRES unsigned  N036_Rez_GO_7_;
EXTERN_MIRES unsigned  N036_Rez_GO_8_;
EXTERN_MIRES unsigned  N036_Rez_GO_9_;
EXTERN_MIRES unsigned  N036_Rez_GO_10_;
EXTERN_MIRES unsigned  N036_Rez_GO_11_;
EXTERN_MIRES unsigned  N036_Rez_GO_12_;
EXTERN_MIRES unsigned  N036_Rez_GO_13_;
EXTERN_MIRES unsigned  N036_Rez_GO_14_;
EXTERN_MIRES unsigned  N036_Rez_GO_15_;
EXTERN_MIRES unsigned  N036_Rez_GO_16_;
EXTERN_MIRES unsigned  N036_Rez_GO_17_;
EXTERN_MIRES unsigned  N036_Rez_GO_18_;
EXTERN_MIRES unsigned  N036_Rez_GO_19_;
EXTERN_MIRES unsigned  N036_Rez_GO_20_;

#ifdef _PRIM
// Для работы в составе модели.
#endif
/****************************************************************************/
/*                Входная информация Mires (Выходы БЦВМ)                    */

 /* Описаниe валидностей входных сигналов Mires */

//EXTERN_MIRES unsigned BP_VV_X_ MIRESEq(0);

#endif /* MIRES_BCVM_H_ */

/*==========================================================================*/
