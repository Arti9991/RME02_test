#pragma once
#pragma pack(push,1) //Выравнивание полей структур должно быть на 1 байт

//	Структура данных с признаками реальная система или модель системы (1-имитировать систему, 0-реальная система )
// Размер 16 байт
struct TModel_or_Real_Sys
{
	union{
		struct
		{
			char INS1_Model;   		//	имитировать INS1
			char INS2_Model;   		//	имитировать INS2
			char RAM_Model;			//	имитировать RAM
			char TACAN_Model;		//	имитировать TACAN
			char VOR_Model;			//	имитировать VOR
			char TARANG_Model;		//	имитировать TARANG
			char TSB_Model;			//	имитировать TSB	
			char KARAT_Model;		//	имитировать KARAT
			char ACMI_Model;		//	имитировать ACMI
			char rezerv1;			//	резерв
			char rezerv2;			//	резерв
			char rezerv3;			//	резерв
			char rezerv4;			//	резерв
			char rezerv5;			//	резерв
			char rezerv6;			//	резерв
			char rezerv7;			//	резерв	
		};
		char modelOrNot[16];
	};
};
#pragma pack(pop)