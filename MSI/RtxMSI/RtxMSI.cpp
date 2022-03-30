
#include "RtxMSI.h"
#include "..\..\@include\MSI.h"
#include "..\..\@include\#tmg_dbl.h"


INTERFACE_TYPE interfacetype=PCIBus;

void timer1(unsigned __int64 count);

USHORT _VendorID = 0;

USHORT _DeviceID = 0;

DRVDEV   Cards[MAX_NUM_CARDS]; 

TIMING timer;

HANDLE hShm;
DWORD errShm = 0;
sMSIshm *pMSIshm = 0;

_RMe_02_BAR0* pRMe_02_BAR0=NULL;

int isRMe_02, ifRMe_02, isRMe_02old = -1, ifRMe_02old = -1;

DWORD	dwMaximumSizeHigh = 0;
PUCHAR pvShMemAddr=0;

PVOID vAddress[8]; // virtual memory address returned by RtAllocateContiguousMemory
LARGE_INTEGER pAddress; // physical memory address returned by RtGetPhysicalAddress

// RMe_02 _____________________________________________

void _cdecl main(
	  int argc,
      char **argv,
      char **envp)	

	{
	DWORD iddd = GetCurrentProcessId();
	RtPrintf("  ID : %d  \n", iddd ) ;
	int iSear = 0;

	PCI_SLOT_NUMBER SlotNumber;
	DRVDEV *pCardInfo;
	UCHAR   buffer[PCI_COMMON_HDR_LENGTH]; //PCI Header
	PPCI_COMMON_CONFIG  PciData = (PPCI_COMMON_CONFIG) buffer;//PCI configuration



 RtPrintf("\n Wait START\n") ;
	
	
 RtPrintf("\n START\n") ;


	// ----------------------- Создание MSI.Shm  -----------------------------------

	hShm = RtCreateSharedMemory (PAGE_READWRITE, dwMaximumSizeHigh, SIZE_SharedMem_MSI, L"MSI.shm", (LPVOID*) &pvShMemAddr);
	if (hShm) { pMSIshm = (sMSIshm*)((void*)pvShMemAddr); }
	errShm  = GetLastError();
 if(hShm && (errShm != ERROR_ALREADY_EXISTS))  // память создана в первый раз!
	 {
		memset(pvShMemAddr,0,SIZE_SharedMem_MSI);// clear memory
  RtPrintf("\n'MSI.Shm' shared memory created! \n\n" ) ;
 	}
	else
	 {
  RtPrintf("\nThe shared memory 'MSI.Shm' is already created! \n\n" ) ;
	 }

//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv START RMe_02 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\\
	
	Cards[2].priority = 100;
	Cards[2].msiEnable = 1;
	Cards[2].Order = 0x0;
	Cards[2].cardNum = 0x0;
	pCardInfo = &Cards[2];

 _VendorID = RMe_02_VendorID;
 _DeviceID = RMe_02_DeviceID;

	RtPrintf("Search RMe_02 card \n");

	iSear = Device_Search (0, &SlotNumber, PciData);
	pCardInfo->busNum = iSear;

	if(iSear < 0)
	 {
		RtPrintf("WARNING: RMe-02 card was NOT found in this machine.\n\n");
	 }
 else
  {
 	RtPrintf("Got nIRQ = %d \n", PciData->u.type0.InterruptLine) ;
	 pCardInfo->deviceNum = SlotNumber.u.bits.DeviceNumber;
	 pCardInfo->functionNum = SlotNumber.u.bits.FunctionNumber;

	 if(!(RMe_02_Configure(PciData, pCardInfo)))
		 {
		 RtPrintf("WARNING: Configuration RMe_02 failed!\n");
		 }

	 if ( NULL == pRMe_02_BAR0 )
		 {
		 RtPrintf("Could not define pRMe_02_BAR0 in procedure RMe_02_Configure(..)\n", GetLastError() ) ;
		 }  
	}
 //vvvvvvvvvvvvvvvvvvvvvvvvvvv  END RMe_02 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

	
 LARGE_INTEGER  liPeriod;   // timer period
 HANDLE         hTimer;     // timer handle

 //timer1(pRMe_02_BAR0->Counter);

 if (pRMe_02_BAR0 != NULL) pRMe_02_BAR0->Counter = 0;
 liPeriod.QuadPart = 10000000;  //(период отображения 10000000 - 1 секунда)
 if (pRMe_02_BAR0 != NULL)  RtPrintf("\n\nCounter=%d\n\n", pRMe_02_BAR0->Counter);
 // Create a periodic timer
 if (! (hTimer = RtCreateTimer(
                               NULL,            // security
                               0,               // stack size - 0 uses default
                               TimerHandler,    // timer handler
                               NULL,            // NULL context (argument to handler)
                               RT_PRIORITY_MAX, // priority
                               CLOCK_1) ))      // RTX HAL timer
  {

     ExitProcess(1);
  }
 RtSetTimerRelative( hTimer,&liPeriod,&liPeriod);
 RtSetTimerRelative( hTimer,&liPeriod,&liPeriod);

RtPrintf(" Wait EXIT\n\n") ;

RtWaitForSingleObject(hTimer, INFINITE);

if (hTimer) RtCancelTimer( hTimer, NULL);
if (hTimer) { RtDeleteTimer(hTimer); hTimer = NULL; }


RMe_02_CLOSE();

	RtPrintf("\n Wait START\n\n") ;
 
return;
}