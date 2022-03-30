rem ERASE /?
ERASE /S/Q  *.exp *.bsc *.pdb *.ilk *.ncb *.suo *.aps *.idb *.htm *.obj *.sbr *.bsc *.pch *.plg
ERASE /S/Q/A:H *.exp *.bsc *.pdb *.ilk *.ncb *.suo *.aps *.idb *.htm *.obj *.sbr *.bsc *.pch *.plg
ERASE /S/Q *.tlb *.tli *.tlh *.tmp *.rsp *.user *.sdf  *.cfdb *.opensdf 
ERASE /S/Q/A:H *.tlb *.tli *.tlh *.tmp *.rsp *.user *.sdf  *.cfdb *.opensdf 
ERASE /S/Q DBG_ShMEM.TXT DBG_SSS.txt DBG DBG_IPC.txt
ERASE /S/Q/A:H DBG_ShMEM.TXT DBG_SSS.txt DBG DBG_IPC.txt
rmdir /s /Q @TEMP
pause