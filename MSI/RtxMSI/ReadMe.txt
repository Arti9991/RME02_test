========================================================================
    RTX Application Wizard : "RtxApp1" Project Overview
========================================================================

RTX Application Wizard has created this "RtxApp1" project for you as a starting point.

This file contains a summary of what you will find in each of the files that make up your project.

RtxApp1.vcproj
    This is the main project file for projects generated using an Application Wizard. 
    It contains information about the version of the product that generated the file, and 
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

RtxApp1.h
   This is a header file which contains all includes and function protoypes.

RtxApp1.c
   This is a C file which contains main.

RtxApp1Funcs.c
   This is a C file which contains all functions.

/////////////////////////////////////////////////////////////////////////////
Other notes:

/////////////////////////////////////////////////////////////////////////////


- ������ ����� ��������� ��������� IntRoutineFirst,
  � ����� ~8��� ������ ��������� IntRoutineSecond
- InterruptMode ���� ���������� � Latched,
  � ��������� ������ ���������� ������������ � ����� ��� ������ ���������
- Sleep � ���������� IntRoutineFirst � IntRoutineSecond �������� � �������� ������
  (Sleep(1), � ������� ���������� ~100��)
- ������� �������� ShareVector �� �������� (��� IRQ=7)
- Priority ��������� �������� �� 0 �� 127
- InterfaceType ��� IRQ=7 ����� ������� ����� �� ���������� ��������

- ������ ���������� ������� DLL ���������� ���������� ���������:
  RtSetThreadPriority(hThread_Wait, RT_PRIORITY_MAX);
  ��� ������� ����� ������� ���� ��������� �� ���� ��� ����� 1��