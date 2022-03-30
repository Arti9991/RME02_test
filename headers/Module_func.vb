Module Module_func

 Public Sub fill_script(ByVal rsw As System.Data.DataTable, ByVal irw As Integer)

  ''''If CONF_RIG = 6 Then

  '''' Dim i As Integer, nm As String

  '''' With rsw

  ''''  For i = 0 To 5
  ''''   nm = "IdPar" + CStr(i + 1) : IPCtoDLL.script(irw).idpar(i) = toDEC(.Rows(irw)(nm))
  ''''  Next i

  ''''  IPCtoDLL.script(irw).value(0) = Val((.Rows(irw)("Value-1")))
  ''''  IPCtoDLL.script(irw).value(1) = Val((.Rows(irw)("Value-2")))
  ''''  IPCtoDLL.script(irw).WtDl = toDEC((.Rows(irw)("Wait/Delay")))

  ''''  For i = 0 To 1
  ''''   nm = "Cond-" + CStr(i + 1)
  ''''   Select Case .Rows(irw)(nm)
  ''''    Case "=" : IPCtoDLL.script(irw).Cond(i) = 1
  ''''    Case "<>" : IPCtoDLL.script(irw).Cond(i) = 2
  ''''    Case ">" : IPCtoDLL.script(irw).Cond(i) = 3
  ''''    Case ">=" : IPCtoDLL.script(irw).Cond(i) = 4
  ''''    Case "<" : IPCtoDLL.script(irw).Cond(i) = 5
  ''''    Case "=<" : IPCtoDLL.script(irw).Cond(i) = 6
  ''''    Case "|" : IPCtoDLL.script(irw).Cond(i) = 7
  ''''    Case "&" : IPCtoDLL.script(irw).Cond(i) = 8
  ''''   End Select
  ''''  Next i

  ''''  Select Case .Rows(irw)("Logic")
  ''''   Case "OR" : IPCtoDLL.script(irw).Logic = 1
  ''''   Case "AND" : IPCtoDLL.script(irw).Logic = 2
  ''''   Case "XOR" : IPCtoDLL.script(irw).Logic = 3
  ''''  End Select
  ''''  Select Case .Rows(irw)("Func")
  ''''   Case "Const" : IPCtoDLL.script(irw).Type_func = 1
  ''''   Case "Trap" : IPCtoDLL.script(irw).Type_func = 2
  ''''   Case "Sin" : IPCtoDLL.script(irw).Type_func = 3
  ''''   Case "Increase" : IPCtoDLL.script(irw).Type_func = 4
  ''''   Case "Decrease" : IPCtoDLL.script(irw).Type_func = 5
  ''''   Case "NumLine" : IPCtoDLL.script(irw).Type_func = 6
  ''''   Case Else : IPCtoDLL.script(irw).Type_func = 1
  ''''  End Select
  ''''  IPCtoDLL.script(irw).Min = Val(.Rows(irw)("Min/Value"))
  ''''  IPCtoDLL.script(irw).Max = Val(.Rows(irw)("Max"))
  ''''  IPCtoDLL.script(irw).T_start = Val(.Rows(irw)("T start"))
  ''''  IPCtoDLL.script(irw).Period = toDEC(.Rows(irw)("Period"))
  ''''  IPCtoDLL.script(irw).T_up = toDEC(.Rows(irw)("T up"))
  ''''  IPCtoDLL.script(irw).T_top = toDEC(.Rows(irw)("T top")) + IPCtoDLL.script(irw).T_up
  ''''  IPCtoDLL.script(irw).T_down = toDEC(.Rows(irw)("T down")) + IPCtoDLL.script(irw).T_top

  '''' End With

  ''''Else

  Dim i As Integer, nm As String

  With rsw

   For i = 0 To 5
    nm = "IdPar" + CStr(i + 1) : IPCtoDLL.script(irw).idpar(i) = toDEC(.Rows(irw)(nm))
   Next i

   IPCtoDLL.script(irw).value(0) = Val((.Rows(irw)("Value1")))
   IPCtoDLL.script(irw).value(1) = Val((.Rows(irw)("Value2")))
   IPCtoDLL.script(irw).WtDl = toDEC((.Rows(irw)("WaitDelay")))

   For i = 0 To 1
    nm = "Cond" + CStr(i + 1)
    Select Case .Rows(irw)(nm)
     Case "=" : IPCtoDLL.script(irw).Cond(i) = 1
     Case "<>" : IPCtoDLL.script(irw).Cond(i) = 2
     Case ">" : IPCtoDLL.script(irw).Cond(i) = 3
     Case ">=" : IPCtoDLL.script(irw).Cond(i) = 4
     Case "<" : IPCtoDLL.script(irw).Cond(i) = 5
     Case "=<" : IPCtoDLL.script(irw).Cond(i) = 6
     Case "|" : IPCtoDLL.script(irw).Cond(i) = 7
     Case "&" : IPCtoDLL.script(irw).Cond(i) = 8
    End Select
   Next i

   Select Case .Rows(irw)("Logic")
    Case "OR" : IPCtoDLL.script(irw).Logic = 1
    Case "AND" : IPCtoDLL.script(irw).Logic = 2
    Case "XOR" : IPCtoDLL.script(irw).Logic = 3
   End Select
   Select Case .Rows(irw)("Funct")
    Case "Const" : IPCtoDLL.script(irw).Type_func = 1
    Case "Trap" : IPCtoDLL.script(irw).Type_func = 2
    Case "Sin" : IPCtoDLL.script(irw).Type_func = 3
    Case "Increase" : IPCtoDLL.script(irw).Type_func = 4
    Case "Decrease" : IPCtoDLL.script(irw).Type_func = 5
    Case "NumLine" : IPCtoDLL.script(irw).Type_func = 6
    Case "Linear" : IPCtoDLL.script(irw).Type_func = 7
    Case Else : IPCtoDLL.script(irw).Type_func = 1
   End Select
   IPCtoDLL.script(irw).Min = Val(.Rows(irw)("MinValue"))
   IPCtoDLL.script(irw).Max = Val(.Rows(irw)("MaxOnly"))
   IPCtoDLL.script(irw).T_start = Val(.Rows(irw)("Tstart"))
   IPCtoDLL.script(irw).Period = toDEC(.Rows(irw)("Period"))
   IPCtoDLL.script(irw).T_up = toDEC(.Rows(irw)("Tup"))
   IPCtoDLL.script(irw).T_top = toDEC(.Rows(irw)("Ttop")) + IPCtoDLL.script(irw).T_up
   IPCtoDLL.script(irw).T_down = toDEC(.Rows(irw)("Tdown")) + IPCtoDLL.script(irw).T_top

  End With

  ''''End If

 End Sub

 'Функция для проверки записанного основания..........................
 Public Function toDEC(ByVal saddr As String) As Int32

  Dim curBase As Integer
  Dim sAddr_len As Integer

  sAddr_len = Len(saddr)

  If sAddr_len = 0 Then
   toDEC = 0
   Exit Function
  End If
  '...........Какая база записана?.....................
  If Left(saddr, 2) = "0x" Then
   curBase = 2
  Else
   If Left(saddr, 1) = "0" Then
    curBase = 1
   Else
    curBase = 0
   End If
  End If

  '............Достаем параметр..............................
  saddr = Mid(saddr, curBase + 1, sAddr_len - curBase)

  Select Case curBase
   Case 2 'hex
    saddr = "&H" + saddr + "&"
    toDEC = Val(saddr)
   Case 1 'oct
    saddr = "&o" + saddr + "&"
    toDEC = Val(saddr)
   Case 0 'dec
    toDEC = Val(saddr)
   Case Else
  End Select

 End Function

 ' '' 'Public Function value(s) As Long

 ' '' '  If s <> Null Then
 ' '' '   value = s
 ' '' '  Else
 ' '' '   value = 0
 ' '' '  End If

 ' '' 'End Function
 ' '' '=============================================================
 ' '' 'Поиск  в сетке по буквам
 ' '' 'Возвращает
 ' '' 'строку для поиска
 ' '' 'направление поиска F3-вперед, F4-назад
 ' '' 'с какой строки начать поиск относительно текущей позиции
 ' '' '=============================================================
 ' '' Public Function sKey(ByVal KeyCode As Integer, ByVal Shift As Integer, ByVal srcDirection As Integer, ByVal lSkipRows As Long) As String
 ' ''  Dim sName As String
 ' ''  Dim ss As String
 ' ''  Static s_fast As String

 ' ''  srcDirection = 0 'adSearchForward
 ' ''  lSkipRows = 0

 ' ''  Debug.Print("KeyCode=", KeyCode, " Shift=", Shift, " s-fast=", s_fast, AscB("_"))

 ' ''  If KeyCode = vbKeyF3 Then
 ' ''   lSkipRows = 1
 ' ''   sKey = s_fast
 ' ''   Exit Function
 ' ''  End If
 ' ''  If KeyCode = vbKeyF4 Then
 ' ''   srcDirection = 1 'adSearchBackward
 ' ''   lSkipRows = 1
 ' ''   sKey = s_fast
 ' ''   Exit Function
 ' ''  End If


 ' ''  'Идет буква+Ctrl или буква+Ctrl+Shift
 ' ''  If (Shift = 2 Or Shift = 3) And KeyCode <> vbKeyControl And KeyCode <> vbKeyShift Then
 ' ''   'Ловим знак _ или -
 ' ''   ss = ""
 ' ''   If KeyCode = 189 And Shift = 3 Then ss = "_"
 ' ''   If KeyCode = 189 And Shift = 2 Then ss = "-"
 ' ''   If KeyCode = 219 And Shift = 2 Then ss = "["
 ' ''   If KeyCode = 221 And Shift = 2 Then ss = "]"
 ' ''   If KeyCode = 190 And Shift = 2 Then ss = "."
 ' ''   If KeyCode = 55 And Shift = 3 Then ss = "&"

 ' ''   If ss = "" Then
 ' ''    s_fast = s_fast & Chr(KeyCode) ' + 32 * (Shift - 2))
 ' ''   Else
 ' ''    s_fast = s_fast & ss
 ' ''   End If
 ' ''   lSkipRows = 1
 ' ''  End If
 ' ''  'ТОЛЬКО ЧТО НАЖАЛИ CTRL
 ' ''  If KeyCode = vbKeyControl Then '17
 ' ''   s_fast = ""
 ' ''  End If
 ' ''  'If KeyCode = vbKeyShift and Then  '17
 ' ''  '  s_fast = ""
 ' ''  'End If

 ' ''  sKey = s_fast

 ' '' End Function


 '#End If

End Module
