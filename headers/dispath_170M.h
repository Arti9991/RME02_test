// Инициализация библиотеки Dispath
// Вход: size, Name - размер и имя разделяемой памяти,
// cnf - признак того, что в текущей конфигурации БД выбран пакет с соответствующим именем: 
//	бит0=1 - выбран пакет "Conf_v1" ... бит7=1 - выбран пакет "Conf_v8", иначе соответствующий бит =0.
void __stdcall InitDispath(DWORD size, LPSTR Name, unsigned char cnf);

//вызов функций обработчика dll
void __stdcall WorkFunction(void);

// Пропись имен
void __stdcall WriteName(void);


//перезапуск dll
void __stdcall RestartDispath(void);

//закрытие работы с dll 	
void __stdcall CloseDispath(void);
	
