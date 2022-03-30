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


- Первой будет выполнена процедура IntRoutineFirst,
  а через ~8мкс вторая процедура IntRoutineSecond
- InterruptMode надо выставлять в Latched,
  в противном случае количество срабытываний в сотни раз больше реального
- Sleep в процедурах IntRoutineFirst и IntRoutineSecond приводит к зеленому экрану
  (Sleep(1), а частота прерывания ~100гц)
- влияние значения ShareVector не замечено (для IRQ=7)
- Priority принимает значения от 0 до 127
- InterfaceType для IRQ=7 можно выбрать любую из допустимых констант

- Потоку ожидающему событие DLL необходимо установить приоритет:
  RtSetThreadPriority(hThread_Wait, RT_PRIORITY_MAX);
  все события будут пойманы если генерация не чаще чем через 1мс