Module Key_DB
    Class clKey_DB_RS
        'Переменные внешние
        Public IsPIN As Int16 = 0 '1-в БД был пароль
        Public BD_RIG As Int32 = 0 'Конфигурация стенда в БД
        'Переменные внутренние:
        Private DBReadWrite As New OleDb.OleDbConnection

        Private TblAdapter As OleDb.OleDbDataAdapter : Private tAd As New DataTable("Ad")
        Private TblBurst As OleDb.OleDbDataAdapter : Private tBr As New DataTable("Br")
        Private TblParameter As OleDb.OleDbDataAdapter : Private tPr As New DataTable("Pr")
        Private TblAdType As OleDb.OleDbDataAdapter : Private tAT As New DataTable("AT")
        Private TblLine As OleDb.OleDbDataAdapter : Private tLn As New DataTable("Ln")
        Private TbInterf As OleDb.OleDbDataAdapter : Private tIt As New DataTable("It")
        Private TbParamW As OleDb.OleDbDataAdapter : Private tpw As New DataTable("pw")
        Private Tcount As Int16 = 13
        Private idAirKey As Int32 = 0
        Private Key1 As UInt64 = 5
        Private Key2 As UInt64 = 2
        Private Key3 As UInt64 = 3
        Private Key4 As UInt64 = 8
        Private Key5 As UInt64 = 2
        Private Key6 As UInt64 = 4
        Private Key7 As UInt64 = 2

        Private CountProvTable As Int16 = 7 'Количество таблиц для которых идет проверка

        Private Key8 As UInt64 = 7
        Private Key9 As UInt64 = 15

        'Private Pin As String = "дата/P0250" 'Ключевое слово
        Private prov As String = ""
        ' Функция дешифрования кодового поля DB_RS
        ' Вход: полное имя подключаемой БД 
        ' Выход: результат дешифрования: 0- успешно; 1- ошибка
        Public Function UnPack(ByVal DBFullName As String) As Int16 ' in - DB full name, out - result
            Dim DValue As UInt64 = 0
            Dim SValue1 As String = ""
            Dim SValue2 As String = ""
            Dim SValue3 As String = ""

            If ConnectDB(DBFullName) <> 0 Then Return 1 'ОШИБКА ПОДКЛЮЧЕНИЯ К БД либо ПОСЧЕТА КОЛИЧЕСТВА
            On Error GoTo ErrorHandler
            'ОЧИСТКА ТАБЛИЦ
            tAd.Clear() : tBr.Clear() : tPr.Clear() : tAT.Clear() : tLn.Clear() : tIt.Clear() : tpw.Clear()

            'НАСТРОЙКА АДАПТЕРОВ
            TblAdapter = New OleDb.OleDbDataAdapter("select * from Adapter", DBReadWrite) : TblAdapter.Fill(tAd)
            TblBurst = New OleDb.OleDbDataAdapter("select * from Burst", DBReadWrite) : TblBurst.Fill(tBr)
            TblParameter = New OleDb.OleDbDataAdapter("select * from Parameter", DBReadWrite) : TblParameter.Fill(tPr)
            TblAdType = New OleDb.OleDbDataAdapter("select * from AdapterType", DBReadWrite) : TblAdType.Fill(tAT)
            TblLine = New OleDb.OleDbDataAdapter("select * from Line", DBReadWrite) : TblLine.Fill(tLn)
            TbInterf = New OleDb.OleDbDataAdapter("select * from Interface", DBReadWrite) : TbInterf.Fill(tIt)
            TbParamW = New OleDb.OleDbDataAdapter("select * from parameter_where", DBReadWrite) : TbParamW.Fill(tpw)

            'ДЕШИФРОВАНИЕ
            Dim ReadNameC As OleDb.OleDbDataReader
            Dim KeyCom As New OleDb.OleDbCommand
            KeyCom.CommandText = "select * from Aircraft"
            KeyCom.Connection = DBReadWrite
            ReadNameC = KeyCom.ExecuteReader
            If ReadNameC.Read() = True And ReadNameC.IsDBNull(0) = False Then
                prov = ReadNameC.GetString(4)
                idAirKey = ReadNameC.GetValue(0)
            Else
                Return 1
            End If
            If ReadNameC.IsClosed = False Then ReadNameC.Close()

            Dim CurTime As String = ""

            If Now.Day <= 9 Then : CurTime = "0" + CStr(Now.Day) 'ДЕНЬ ФОРМАТ 01, 02...
            Else : CurTime = CStr(Now.Day)
            End If

            If Now.Month <= 9 Then : CurTime = CurTime + "0" + CStr(Now.Month) 'МЕСЯЦ ФОРМАТ 01, 02...
            Else : CurTime = CurTime + CStr(Now.Month)
            End If

            CurTime = CurTime + CStr(Now.Year) 'ГОД

            If prov = CurTime + "/P0250" Then 'ЕСЛИ СЛОВО КЛЮЧЕВОЕ
                IsPIN = 1
            Else
                IsPIN = 0
                SValue3 = prov
                For i As Int16 = 1 To SValue3.Count - 2
                    SValue2 = SValue2 + SValue3(SValue3.Count - 1 - i)
                Next i

                For i As Int16 = 0 To SValue2.Count - 1
                    SValue1 = SValue1 + ConvCh(SValue2(i))
                Next i

                DValue = Convert.ToUInt64(SValue1)
                Key9 = Val(SValue3(0))
                DValue = DValue / Key9

                If DValue <> (tAd.Rows.Count) * Key1 _
                        + (tBr.Rows.Count) * Key2 _
                        + (tPr.Rows.Count) * Key3 _
                        + (tAT.Rows.Count) * Key4 _
                        + (tLn.Rows.Count) * Key5 _
                        + (tpw.Rows.Count) * Key7 _
                        + (tIt.Rows.Count) * Key6 Then : Return 1
                End If

                If DValue - (tpw.Rows.Count) * Key7 <> (tAd.Rows.Count) * Key1 _
                        + (tBr.Rows.Count) * Key2 _
                        + (tPr.Rows.Count) * Key3 _
                        + (tAT.Rows.Count) * Key4 _
                        + (tLn.Rows.Count) * Key5 _
                        + (tIt.Rows.Count) * Key6 Then : Return 1
                End If

                If DValue - (tIt.Rows.Count) * Key6 <> (tAd.Rows.Count) * Key1 _
                        + (tBr.Rows.Count) * Key2 _
                        + (tPr.Rows.Count) * Key3 _
                        + (tAT.Rows.Count) * Key4 _
                        + (tLn.Rows.Count) * Key5 _
                        + (tpw.Rows.Count) * Key7 Then : Return 1
                End If

                If DValue - (tLn.Rows.Count) * Key5 <> (tAd.Rows.Count) * Key1 _
                        + (tBr.Rows.Count) * Key2 _
                        + (tPr.Rows.Count) * Key3 _
                        + (tAT.Rows.Count) * Key4 _
                        + (tIt.Rows.Count) * Key6 _
                        + (tpw.Rows.Count) * Key7 Then : Return 1
                End If
            End If

            ' Возврат в глобальной переменной класса типа выбранного стенда
            KeyCom.CommandText = "select * from Aircraft where ChoiceAir = true"
            KeyCom.Connection = DBReadWrite
            ReadNameC = KeyCom.ExecuteReader

            If ReadNameC.Read() = True Then
                If ReadNameC.IsDBNull(2) = False Then
                    BD_RIG = ReadNameC.GetValue(2)
                End If
            End If

            If DBReadWrite.State = ConnectionState.Open Then DBReadWrite.Close()
            Return 0 'успешно
ErrorHandler:
            Return 1
        End Function

        ' Функция шифрования кодового поля DB_RS
        ' Вход: полное имя подключаемой БД 
        ' Выход: результат шифрования: 0- успешно; 1- ошибка
        Public Function Pack(ByVal DBFullName As String) As Int16 ' in - DB full name, out - result
            Dim DValue As UInt64 = 0
            Dim SValue1 As String = ""
            Dim SValue2 As String = ""
            Dim SValue3 As String = ""
            Dim addUp As Int16 = 0

            'СОЕДИНЕНИЕ
            If ConnectDB(DBFullName) <> 0 Then Return 1 'ОШИБКА ПОДКЛЮЧЕНИЯ К БД либо ПОСЧЕТА КОЛИЧЕСТВА

            'ОЧИСТКА ТАБЛИЦ
            tAd.Clear() : tBr.Clear() : tPr.Clear() : tAT.Clear() : tLn.Clear() : tIt.Clear() : tpw.Clear()

            'НАСТРОЙКА АДАПТЕРОВ
            TblAdapter = New OleDb.OleDbDataAdapter("select * from Adapter", DBReadWrite) : TblAdapter.Fill(tAd)
            TblBurst = New OleDb.OleDbDataAdapter("select * from Burst", DBReadWrite) : TblBurst.Fill(tBr)
            TblParameter = New OleDb.OleDbDataAdapter("select * from Parameter", DBReadWrite) : TblParameter.Fill(tPr)
            TblAdType = New OleDb.OleDbDataAdapter("select * from AdapterType", DBReadWrite) : TblAdType.Fill(tAT)
            TblLine = New OleDb.OleDbDataAdapter("select * from Line", DBReadWrite) : TblLine.Fill(tLn)
            TbInterf = New OleDb.OleDbDataAdapter("select * from Interface", DBReadWrite) : TbInterf.Fill(tIt)
            TbParamW = New OleDb.OleDbDataAdapter("select * from parameter_where", DBReadWrite) : TbParamW.Fill(tpw)
            'ШИФРОВАНИЕ
            '1. Количество таблиц
            DValue = (tAd.Rows.Count) * Key1 _
                        + (tBr.Rows.Count) * Key2 _
                        + (tPr.Rows.Count) * Key3 _
                        + (tAT.Rows.Count) * Key4 _
                        + (tLn.Rows.Count) * Key5 _
                        + (tIt.Rows.Count) * Key6 _
                        + (tpw.Rows.Count) * Key7
            Randomize() : Key9 = CInt(Int(8 * Rnd()) + 1)
            DValue = DValue * Key9
            SValue1 = CStr(DValue)
            For i As Int16 = 0 To SValue1.Count - 1
                SValue2 = SValue2 + ConvCh(SValue1(i))
            Next i

            For i As Int16 = 0 To SValue2.Count - 1
                SValue3 = SValue3 + SValue2(SValue2.Count - 1 - i)
            Next i

            prov = Key9
            prov = prov + SValue3
            prov = prov + CStr(Int(8 * Rnd()) + 1)

            'ЗАПИСЬ
            Dim KeyCom As New OleDb.OleDbCommand
            KeyCom.CommandText = "update Aircraft set TypeK=@TypeK where idAircraft =" + CStr(idAirKey)
            KeyCom.Connection = DBReadWrite
            KeyCom.Parameters.AddWithValue("TypeK", prov)
            KeyCom.ExecuteNonQuery()
            KeyCom.Parameters.Clear() 'очищать параметры обязательно!

            If DBReadWrite.State = ConnectionState.Open Then DBReadWrite.Close()
            Return 0
        End Function

        Private Function ConnectDB(ByVal Name As String) As Int16
            Dim DTCount As New DataTable("cnt")
            Dim addUp As Int16 = 0
            Dim SysAddUp As Int16 = 0


            '1. ДОСТУП ДЛЯ СЧИТЫВАНИЯ/ЗАПИСИ
            DBReadWrite.ConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;" + "Data Source=" + Name ' тип и путь соединения 20.08.19 - переход на новый формат БД
            Try : DBReadWrite.Open() 'открыть доступ
            Catch : Return 1 'ОШИБКА СОЕДИНЕНИЯ
            End Try

            DTCount = DBReadWrite.GetSchema("Tables")
            For i As Int32 = 0 To DTCount.Rows.Count - 1
                If DTCount.Rows(i).Item(2) = "Adapter" Or _
                DTCount.Rows(i).Item(2) = "AdapterType" Or _
                DTCount.Rows(i).Item(2) = "Aircraft" Or _
                DTCount.Rows(i).Item(2) = "Burst" Or _
                DTCount.Rows(i).Item(2) = "Computer" Or _
                DTCount.Rows(i).Item(2) = "Interface" Or _
                DTCount.Rows(i).Item(2) = "Line" Or _
                DTCount.Rows(i).Item(2) = "Parameter" Or _
                DTCount.Rows(i).Item(2) = "Title" Or _
                DTCount.Rows(i).Item(2) = "parameter_where" Or _
                DTCount.Rows(i).Item(2) = "ParameterType" Or _
                DTCount.Rows(i).Item(2) = "qAdapters" Or _
                DTCount.Rows(i).Item(2) = "qDataBurst" Then
                    addUp = addUp + 1
                End If
                'Отсечка системных

                If Left(DTCount.Rows(i).Item(2), 4) = "MSys" Then
                    SysAddUp = SysAddUp + 1
                End If
            Next i
            'ПОДСЧЕТ СУММЫ
            If SysAddUp + addUp <> DTCount.Rows.Count Then Return 1 'ОШИБКА КОЛИЧЕСТВА

            Return 0 'УСПЕШНО
        End Function

        Private Function ConvCh(ByVal t As Char) As String
            Select Case t
                Case "0" : Return "9"
                Case "1" : Return "8"
                Case "2" : Return "7"
                Case "3" : Return "6"
                Case "4" : Return "5"
                Case "5" : Return "4"
                Case "6" : Return "3"
                Case "7" : Return "2"
                Case "8" : Return "1"
                Case "9" : Return "0"
            End Select
            Return 0
        End Function
    End Class
End Module
