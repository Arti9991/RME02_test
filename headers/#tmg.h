#ifndef TMG
#define TMG

LARGE_INTEGER Frequency_tmg;

struct TIMING // ��������� ��������� �������
 { 
 // ����������
 LARGE_INTEGER t1, t2, dtcurr, dtmin, dtmax;

 // �������
 void RESET (void)
  {
  t1.QuadPart = 0; t2 = t1;
  dtcurr.QuadPart=0; dtmin.QuadPart=0x7fffffffffffffff; dtmax.QuadPart=0;
  return;
  }

 void START (void)
 {
  QueryPerformanceCounter( &t1 );
  return; }
 void STOP  (void) {
  QueryPerformanceCounter( &t2 );
 return; }

 LONGLONG DT(void)
 {
  dtcurr.QuadPart = (t2.QuadPart - t1.QuadPart)*(1000000000 / Frequency_tmg.QuadPart);// ����� � ��
  if (dtmin.QuadPart > dtcurr.QuadPart) dtmin.QuadPart = dtcurr.QuadPart;     // ����� � ��
  if (dtmax.QuadPart < dtcurr.QuadPart) dtmax.QuadPart = dtcurr.QuadPart;     // ����� � ��
  return dtcurr.QuadPart;
 }

 LONGLONG NOW(void)
 {
 QueryPerformanceCounter(&dtcurr);
 dtcurr.QuadPart = (dtcurr.QuadPart)*(1000000000 / Frequency_tmg.QuadPart); // ����� � ��
 return dtcurr.QuadPart;
 }

 TIMING(void)
 {
  DWORD f;
  t1.QuadPart = 0; t2 = t1;
  dtcurr.QuadPart = 0; dtmin.QuadPart = 0x7fffffffffffffff; dtmax.QuadPart = 0;
  if (Frequency_tmg.QuadPart == 0) QueryPerformanceFrequency(&Frequency_tmg);          // ������� ���������� � [��� ��� windows 7 � � �� ��� XP]
  f = GetLastError();
  };

 };

#endif