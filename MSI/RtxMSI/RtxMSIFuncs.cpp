//////////////////////////////////////////////////////////////////
//                                                              //
//	RtxApp1Func.cpp - CPP file                                  //
//                                                              //
// This file was generated using the RTX Application Wizard     //
// for Visual Studio.                                           //
//////////////////////////////////////////////////////////////////

#include "RtxMSI.h"
#include "..\..\@include\MSI.h"
#include "..\..\@include\#tmg_dbl.h"

extern USHORT _VendorID;
extern USHORT _DeviceID;
extern DRVDEV Cards[MAX_NUM_CARDS];            // Device object array

extern int sizeRM;

extern TIMING timer;

extern __int32 REG; 
extern HANDLE	hShm;
extern DWORD errShm;
extern sMSIshm *pMSIshm;

int iBUS, iRT, iDIR, iSA;
int RMe_byse = 0;


// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv  RMe_02  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

extern _RMe_02_BAR0* pRMe_02_BAR0;

extern int isRMe_02, ifRMe_02, isRMe_02old, ifRMe_02old;
extern PVOID vAddress[8]; // virtual memory address returned by RtAllocateContiguousMemory

const int nRMe = 100;

// MPI START ----------------------------------------------------------

// MPI FINISH ----------------------------------------------------------

void timer1(unsigned __int64 count);

int Device_Search
		(
		int CardNumber,					          // input: PCI card to find
		PCI_SLOT_NUMBER *pSlotNumber,	// output: pointer to slot number
		PPCI_COMMON_CONFIG  PciData		 // output: PCI card information
		)
 {  
	ULONG   DeviceNumber;      // logical slot number for the PCI adapter
	ULONG   FunctionNumber;    // function number on the specified adapter
	ULONG   BytesWritten;      // return value from RtGetBusDataByOffset
	ULONG   Bus;               // bus number
	BOOLEAN Flag = TRUE;       // TRUE as long as we have PCI busses           
	int CardIndex = 0;

	pSlotNumber->u.bits.Reserved = 0;

	if (_VendorID == 0 || _DeviceID == 0 ) return -2;

	// 
	// All PCI cards have been searched when we are out of PCI busses. (Flag = 0) 
	//
	for (Bus=0; Flag; Bus++)
	 { 
		for (DeviceNumber=0; DeviceNumber < PCI_MAX_DEVICES && Flag; DeviceNumber++)
		 { 
			pSlotNumber->u.bits.DeviceNumber = DeviceNumber;

			for (FunctionNumber=0; FunctionNumber < PCI_MAX_FUNCTION; FunctionNumber++)
			 { 
				pSlotNumber->u.bits.FunctionNumber = FunctionNumber; 

				BytesWritten = RtGetBusDataByOffset
					(
					PCIConfiguration, 
					Bus, 
					pSlotNumber->u.AsULONG, 
					PciData, 
					0,
					PCI_COMMON_HDR_LENGTH 
					); 

				if (BytesWritten == 0)
				 { 
					// out of PCI buses 
					Flag = FALSE; 
					break; 
				 } 

				if (BytesWritten == 2 && PciData->VendorID == PCI_INVALID_VENDORID)
				 { 
					// no device at this slot number, skip to next slot 
					break; 
				 } 
				if ( (PciData->VendorID == _VendorID) && (PciData->DeviceID == _DeviceID) )
				 {

					if(CardIndex == CardNumber) { return Bus; } // This is our card!! stop searching
					else { CardIndex++; }
				 }
			 } // FunctionNumber-loop

		 } // DeviceNumber-loop

	 }  // Bus-loop

	return -1;   
}

void RMe_02_CLOSE(void)
	{
	if ( pRMe_02_BAR0 == NULL ) return;
	for ( int i=0; i<16; i++ )
	 {
  pRMe_02_BAR0->interrupt[i].data = 0; //* (((UINT32*)((DRVDEV)Cards[2]).base[0])+ 0x80/4 + i) = 0x00000000;
	 }

 if(hShm && (errShm != ERROR_ALREADY_EXISTS))  // память создана в первый раз!
	 {
		for ( int i=0; i<8; i++ )
			{
			pRMe_02_BAR0 = 0; //  ((_RMe_02_BAR0*)(UINT8*)Cards[2].base[0])->InputPhysicalAddress[i] = 0;
		 }
	 }
 return;
 }
int RMe_02_Configure(PPCI_COMMON_CONFIG PciData, DRVDEV *pCardInfo)
			{
	ULONG AddressSpace;
	LARGE_INTEGER BusAddr, TranslatedAddr, sysLogAddr;
	
	// Translate bus relative address to system address
	BusAddr.QuadPart = PciData->u.type0.BaseAddresses[0];
	AddressSpace = 0; // Memory mapped
	//timer1(pRMe_02_BAR0->Counter);
	if ( !RtTranslateBusAddress(PCIBus,pCardInfo->busNum,BusAddr,&AddressSpace,&TranslatedAddr) ) 
	 {
		RtPrintf("ERROR: RtTranslateBusAddress0 failed\n");
		return 0;
		}
	sysLogAddr.QuadPart = (TranslatedAddr.LowPart & 0xFFFFFFF0);

	//Map physical address to virtual address

 ULONG sizeRMe_02_BAR0 = 0x100; // 256b
	
	pCardInfo->base[0] = (ULONG)RtMapMemory (sysLogAddr, sizeRMe_02_BAR0, MmNonCached);
	if (pCardInfo->base[0] == 0)
 	{
		RtPrintf("ERROR: RtMapMemory for BusAddress0 failed\n");
		return 0;
 	}
 pMSIshm->RMe_02_Region.sysLogAddr = sysLogAddr; // запись в ShMem системного логического адреса BAR0
 RtPrintf("\nsysLogAddr BAR0 = 0x%016I64X\n\n", sysLogAddr.QuadPart ) ;

 ULONG sizeRMe_02_IN = 0x1000000/4; // 16/4=4 Mb

	LARGE_INTEGER maxPhyAddr;  //highest physical memory address
 pRMe_02_BAR0 = (_RMe_02_BAR0*)(UINT8*)Cards[2].base[0];
 maxPhyAddr.QuadPart = 0x00000000C0000000;
 sysLogAddr.QuadPart = 0;

 for (int i = 0; i < 8; i++)
  {
 	unsigned __int64 InputPhA = 0;
 	InputPhA = pRMe_02_BAR0->InputPhysicalAddress[i];
		RtPrintf("<<READ>> PhysAddr BAR0 segIN %d = 0x%016I64X\n", i+1, InputPhA);
	 }
		RtPrintf("\n");
 for (int i = 0; i < 8; i++)
  {
		sysLogAddr.QuadPart = 0;
		vAddress[i] = NULL;
	if(hShm && (errShm != ERROR_ALREADY_EXISTS))  // память создана в первый раз!
			{
				// Allocate memory для команд
				if (i==0) vAddress[i] = RtAllocateContiguousMemory(sizeRMe_02_IN, maxPhyAddr); // только 1-й сегмент
				//vAddress[i] = RtAllocateLockedMemory(sizeRMe_02_IN); //  все сегменты
				if (vAddress[i] != NULL)
					{
					sysLogAddr = RtGetPhysicalAddress(vAddress[i]);
					}
			}
	else
			{
   sysLogAddr = pMSIshm->RMe_02_Region.PhysAddr_SEG[i]; // BAR0: чтение из ShMem физадреса сегментов памяти на чтение
    if (i==0) vAddress[i] = RtMapMemory (sysLogAddr, sizeRMe_02_IN, MmNonCached); 
			}
	 if (sysLogAddr.QuadPart != 0)
 	 {
   pRMe_02_BAR0->InputPhysicalAddress[i] = *(unsigned __int64*)&sysLogAddr;
	 }
	pMSIshm->RMe_02_Region.PhysAddr_SEG[i] = sysLogAddr; // BAR0: запись в ShMem физадреса сегментов памяти на чтение
	RtPrintf("<<WRITE>> PhysAddr BAR0 segIN %d = 0x%016I64X  ( 0x%08X byte ) \n", i+1, sysLogAddr.QuadPart, sizeRMe_02_IN) ;
	//////////////!!!////////////////!!!//////////////!!!////////!!!/////////////!!!//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}
 ULONG sizeRMe_02_OUT = 0x8000000; // 0x8000000 = 128Мб
 BusAddr.QuadPart = PciData->u.type0.BaseAddresses[1];
 AddressSpace = 0; // Memory mapped
 //Запись в сегмент памяти с нулевым смещением
	


 timer1(pRMe_02_BAR0->Counter);


	if ( !RtTranslateBusAddress(PCIBus,pCardInfo->busNum,BusAddr,&AddressSpace,&TranslatedAddr) ) 
	 {
		RtPrintf("ERROR: RtTranslateBusAddress1 failed\n");
		return 0;
		}
	sysLogAddr.QuadPart = (TranslatedAddr.LowPart & 0xFFFFFFF0);

	pCardInfo->base[1] = (ULONG)RtMapMemory (sysLogAddr, sizeRMe_02_OUT, MmNonCached);
	if (pCardInfo->base[1] == 0)
 	{
		RtPrintf("ERROR: RtMapMemory for BusAddress1 failed\n");
		return 0;
 	}
	pMSIshm->RMe_02_Region.sizeRM = 8;                 // запись в ShMem размера памяти в 16Мб ед., т.е. 8 => 128Мб
	pMSIshm->RMe_02_Region.PhysAddr_BAR1 = sysLogAddr; // запись в ShMem физадреса BAR1     //////counterChoose
 RtPrintf("\n sizeRMe_02_OUT = 0x%08X ( %d byte = %d Mb )\n", sizeRMe_02_OUT, sizeRMe_02_OUT, sizeRMe_02_OUT/0x100000 ) ;
 RtPrintf(" PhysAddr BAR1 = 0x%016I64X\n\n", sysLogAddr.QuadPart ) ;

//запись в сегмент памяти с нулевым смещением
	* (((UINT32*)((DRVDEV)Cards[2]).base[0])+ 0x80/4) = 0x80000000;
	*((unsigned __int32*)Cards[2].base[1] + 0x0) = 0xA;
	RtPrintf("Write in first register = 0x%08X",Cards[2].base[1]);

 return 1;
}

void timer1(unsigned __int64 count)
{
	LARGE_INTEGER liPeriod; // timer period
	HANDLE hTimer; // timer handle
	liPeriod.QuadPart = count; 
	// Create a periodic timer
	if (!(hTimer = RtCreateTimer(
		NULL, // security
		0, // stack size - 0 uses default
		TimerHandler, // timer handler
		NULL, // NULL context (argument to handler)
		RT_PRIORITY_MAX, // priority
		CLOCK_1) )) // RTX HAL timer
		{
		ExitProcess(1);
	}
	if (! RtSetTimerRelative( hTimer,
		&liPeriod,
		&liPeriod) )
		{
		ExitProcess(1);
	}
	RtWprintf(L"\n*** Timer test finished ***\n\n");
	if(!RtDeleteTimer( hTimer ) )
		{
		ExitProcess(1);
		}
return;
}

 void RTFCNDCL TimerHandler( PVOID    context )

{
	unsigned __int64 c = pRMe_02_BAR0->Counter;
	unsigned __int32 n = 1;
	__int64 c1 = c/100000000;
	if (c1 < 60) RtPrintf ("Working timer = %d c\n", c1);
	else if (c1 >= 60)
	{
		unsigned __int32 n1 = 1;
		__int64 c2 = c1 - n1*60;
		if (c2 >= 60)
		{
			n1++;
			__int64 c3 = c1 - n*60;
			RtPrintf ("Working timer = %d :", n1); RtPrintf (" %d c\n", c3);
		}
		else RtPrintf ("Working timer = %d :", n1); RtPrintf (" %d c\n", c2);
	}

	RtPrintf ("Counter timer = %u nc\n", c*10);
	if (c > 100000000) pRMe_02_BAR0->Counter = 1;
	if (c > 100000000) ExitProcess(0) ;
}