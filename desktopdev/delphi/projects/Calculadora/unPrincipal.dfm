object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Calculadora'
  ClientHeight = 368
  ClientWidth = 218
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 53
    Height = 15
    Caption = 'N'#250'mero 1'
  end
  object Label3: TLabel
    Left = 16
    Top = 184
    Width = 55
    Height = 15
    Caption = 'Resultado:'
  end
  object Label2: TLabel
    Left = 16
    Top = 72
    Width = 53
    Height = 15
    Caption = 'N'#250'mero 2'
  end
  object txtNum1: TEdit
    Left = 16
    Top = 37
    Width = 184
    Height = 23
    TabOrder = 0
    OnChange = txtNum1Change
  end
  object txtNum2: TEdit
    Left = 16
    Top = 93
    Width = 184
    Height = 23
    TabOrder = 1
    OnChange = txtNum1Change
  end
  object btnSomar: TButton
    Left = 16
    Top = 136
    Width = 41
    Height = 25
    Caption = '+'
    Enabled = False
    TabOrder = 2
    OnClick = btnSomarClick
  end
  object btnSubtrair: TButton
    Left = 65
    Top = 136
    Width = 41
    Height = 25
    Caption = '-'
    Enabled = False
    TabOrder = 3
    OnClick = btnSubtrairClick
  end
  object btnMultiplicar: TButton
    Left = 112
    Top = 136
    Width = 41
    Height = 25
    Caption = '*'
    Enabled = False
    TabOrder = 4
    OnClick = btnMultiplicarClick
  end
  object btnDividir: TButton
    Left = 159
    Top = 136
    Width = 41
    Height = 25
    Caption = '/'
    Enabled = False
    TabOrder = 5
    OnClick = btnDividirClick
  end
  object txtResultado: TEdit
    Left = 16
    Top = 205
    Width = 184
    Height = 23
    ReadOnly = True
    TabOrder = 6
  end
  object optVisual: TRadioGroup
    Left = 16
    Top = 250
    Width = 184
    Height = 95
    Caption = 'Alterar visual da Calculadora'
    ItemIndex = 0
    Items.Strings = (
      'Light'
      'Dark')
    TabOrder = 7
    OnClick = optVisualClick
  end
end
