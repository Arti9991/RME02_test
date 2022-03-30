#if !defined(__ipo_str)
#define      __ipo_str



struct ToIPO 
{
		DWORD count_IPC1;				// счетик тактов РС1
		DWORD count_BCVM; 
  
		float X, Y, Z, PSI, Te, Ga;    //coordinate, angles (radians).
  
		long MaxNc; 					//number of targets
};


#endif
