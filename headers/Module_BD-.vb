Module Module_BD


 ' 1. ГЛОБАЛЬНЫЕ ОБЪЯВЛЕНИЯ И ОПРЕДЕЛЕНИЯ
 Public BD_RS_connect As OleDb.OleDbConnection = New System.Data.OleDb.OleDbConnection ' Соединение с БД BD_RS.mbd только для команд SQL
 Public RCR_connect As OleDb.OleDbConnection = New System.Data.OleDb.OleDbConnection ' Соединение с БД RCR.mbd только для команд SQL
 Public DISP_IO_connect As OleDb.OleDbConnection = New System.Data.OleDb.OleDbConnection ' Соединение с БД RCR.mbd только для команд SQL

 Public CqAdapter As New OleDb.OleDbCommand      'Таблица запросов qAdapter
 Public CqBurst As New OleDb.OleDbCommand        'Таблица запросов qDataBurst
 Public CqParameter As New OleDb.OleDbCommand    'Таблица запросов qParameter
 Public CqScript As New OleDb.OleDbCommand       'Таблица сценариев

 'АДАПТЕРЫ ВЫБОРКА
 Public BD_RS_Adapter_Q_ad As OleDb.OleDbDataAdapter
 Public cmd_Builder_Q_ad As OleDb.OleDbCommandBuilder
 'ПАКЕТЫ ВЫБОРКА
 Public BD_RS_Adapter_Q_burst As OleDb.OleDbDataAdapter
 Public cmd_Builder_Q_burst As OleDb.OleDbCommandBuilder
 'ПАРАМЕТРЫ ВЫБОРКА
 Public BD_RS_Adapter_Q_param As OleDb.OleDbDataAdapter
 Public cmd_Builder_Q_param As OleDb.OleDbCommandBuilder
 'Сценарий ВЫБОРКА
 Public RCR_Adapter_script As OleDb.OleDbDataAdapter
 Public cmd_Builder_script As OleDb.OleDbCommandBuilder
 'Сценарий ВЫБОРКА
 Public DISP_IO_Adapter_script As OleDb.OleDbDataAdapter
 Public cmd_Builder_DISP_IO As OleDb.OleDbCommandBuilder

 Public BD_RS_DataSET As DataSet 'Устанавливаем отсоединенную БД и таблицы в нее входящие
 Public RCR_DataSET As DataSet   'Устанавливаем отсоединенную БД и таблицы в нее входящие
 Public DISP_IO_DataSET As DataSet   'Устанавливаем отсоединенную БД и таблицы в нее входящие

 ' Установка связей с таблицами из БД BD_RS.mbd при инициализации.
 Public Sub Link_BD_RS_init()

  On Error GoTo ErrorHandler

  'Dim SEC As New clKey_DB_RS

  'If SEC.UnPack(BD_RS_File) <> 0 Then
  ' MsgBox("Damage file: " + BD_RS_File)
  ' End
  'End If

  BD_RS_connect.ConnectionString = _
  "Provider=Microsoft.Jet.OLEDB.4.0;" _
  + "Data Source=" + BD_RS_File ' тип и путь соединения

  BD_RS_connect.Open() 'открыть доступ

  BD_RS_DataSET = New DataSet

  ' Инициализация адаптеров для каждой из таблиц и их подключение
  BD_RS_Adapter_Q_ad = New OleDb.OleDbDataAdapter(sql_qAdapters, BD_RS_connect)
  cmd_Builder_Q_ad = New OleDb.OleDbCommandBuilder(BD_RS_Adapter_Q_ad)
  BD_RS_Adapter_Q_ad.Fill(BD_RS_DataSET, "qADAPTER")

  BD_RS_Adapter_Q_burst = New OleDb.OleDbDataAdapter(sql_qDataBurst, BD_RS_connect)
  cmd_Builder_Q_burst = New OleDb.OleDbCommandBuilder(BD_RS_Adapter_Q_burst)
  BD_RS_Adapter_Q_burst.Fill(BD_RS_DataSET, "qBURST")

  BD_RS_Adapter_Q_param = New OleDb.OleDbDataAdapter(sql_parameter_where, BD_RS_connect)
  cmd_Builder_Q_param = New OleDb.OleDbCommandBuilder(BD_RS_Adapter_Q_param)
  BD_RS_Adapter_Q_param.Fill(BD_RS_DataSET, "qPARAMETER")
  BD_RS_connect.Close()

  Exit Sub
ErrorHandler:
  MsgBox("Module_BD / Link_BD_RS_init  err=" + CStr(Err.Number) + vbCrLf + Err.Description, vbCritical)
  End

 End Sub

 ' Установка связей с таблицами из БД RCR.mbd при инициализации.
 Public Sub Link_RCR_init()

  On Error GoTo ErrorHandler

  RCR_connect.ConnectionString = _
  "Provider=Microsoft.Jet.OLEDB.4.0;" _
  + "Data Source=" + RCR_File ' тип и путь соединения

  RCR_connect.Open() 'открыть доступ

  RCR_DataSET = New DataSet

  ' Инициализация адаптеров для каждой из таблиц и их подключение
  RCR_Adapter_script = New OleDb.OleDbDataAdapter(sql_logic_replay, RCR_connect)
  cmd_Builder_script = New OleDb.OleDbCommandBuilder(RCR_Adapter_script)
  RCR_Adapter_script.Fill(RCR_DataSET, "logic_replay")
  RCR_connect.Close()

  Exit Sub
ErrorHandler:
  MsgBox("Module_BD / Link_RCR_init  err=" + CStr(Err.Number) + vbCrLf + Err.Description, vbCritical)
  End

 End Sub


 ' Установка связей с таблицами из БД RCR.mbd при инициализации.
 Public Sub Link_DISP_IO_init()

  On Error GoTo ErrorHandler

  DISP_IO_connect.ConnectionString = _
  "Provider=Microsoft.Jet.OLEDB.4.0;" _
  + "Data Source=" + BD_RS_File ' тип и путь соединения

  DISP_IO_connect.Open() 'открыть доступ

  DISP_IO_DataSET = New DataSet

  ' Инициализация адаптеров для каждой из таблиц и их подключение
  DISP_IO_Adapter_script = New OleDb.OleDbDataAdapter("SELECT * FROM TITLE", DISP_IO_connect)
  cmd_Builder_DISP_IO = New OleDb.OleDbCommandBuilder(DISP_IO_Adapter_script)
  DISP_IO_Adapter_script.Fill(DISP_IO_DataSET, "TITLE")
  DISP_IO_connect.Close()

  Exit Sub
ErrorHandler:
  MsgBox("Module_BD / Link_DISP_IO_init  err=" + CStr(Err.Number) + vbCrLf + Err.Description, vbCritical)
  End

 End Sub


 Public Sub Write_param()

  BD_RS_Adapter_Q_param.Update(BD_RS_DataSET.Tables("qPARAMETER"))

 End Sub


 '2/3 Разрыв соединения с БД
 Public Sub Destroy_Connection_BD_RS()
  BD_RS_connect.Dispose()
 End Sub


End Module
