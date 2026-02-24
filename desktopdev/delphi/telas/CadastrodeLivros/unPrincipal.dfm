object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Cadastro de Livros'
  ClientHeight = 504
  ClientWidth = 692
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlack
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 32
    Top = 28
    Width = 195
    Height = 25
    Caption = 'Cadastro de Livros'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 32
    Top = 79
    Width = 91
    Height = 16
    Caption = 'T'#237'tulo do Livro'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 32
    Top = 143
    Width = 38
    Height = 16
    Caption = 'Autor'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 32
    Top = 207
    Width = 46
    Height = 16
    Caption = 'G'#234'nero'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 32
    Top = 287
    Width = 43
    Height = 16
    Caption = 'Idioma'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 376
    Top = 143
    Width = 51
    Height = 16
    Caption = 'Resumo'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 376
    Top = 287
    Width = 114
    Height = 16
    Caption = 'Canais de Vendas'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 32
    Top = 101
    Width = 305
    Height = 23
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 32
    Top = 165
    Width = 177
    Height = 23
    TabOrder = 1
  end
  object ComboBox1: TComboBox
    Left = 32
    Top = 229
    Width = 177
    Height = 23
    TabOrder = 2
    Items.Strings = (
      'Romance'
      'Autoajuda'
      'Autobiografia'
      'Horror'
      'Fic'#231#227'o Cient'#237'fica')
  end
  object RadioButton1: TRadioButton
    Left = 48
    Top = 320
    Width = 113
    Height = 17
    Caption = 'Portugu'#234's'
    TabOrder = 3
  end
  object RadioButton2: TRadioButton
    Left = 48
    Top = 352
    Width = 113
    Height = 17
    Caption = 'Ingl'#234's'
    TabOrder = 4
  end
  object RadioButton3: TRadioButton
    Left = 48
    Top = 384
    Width = 113
    Height = 17
    Caption = 'Espanhol'
    TabOrder = 5
  end
  object CheckBox1: TCheckBox
    Left = 376
    Top = 104
    Width = 161
    Height = 17
    Caption = 'Dispon'#237'vel em Estoque'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
  end
  object Memo1: TMemo
    Left = 376
    Top = 165
    Width = 281
    Height = 100
    TabOrder = 7
  end
  object CheckBox2: TCheckBox
    Left = 393
    Top = 309
    Width = 97
    Height = 17
    Caption = 'Internet'
    TabOrder = 8
  end
  object CheckBox3: TCheckBox
    Left = 393
    Top = 332
    Width = 97
    Height = 17
    Caption = 'Telefone'
    TabOrder = 9
  end
  object CheckBox4: TCheckBox
    Left = 393
    Top = 355
    Width = 97
    Height = 17
    Caption = 'Loja F'#237'sica'
    TabOrder = 10
  end
  object Button1: TButton
    Left = 32
    Top = 448
    Width = 145
    Height = 33
    Caption = 'Cadastrar'
    TabOrder = 11
  end
  object Button2: TButton
    Left = 192
    Top = 448
    Width = 145
    Height = 33
    Caption = 'Excluir'
    TabOrder = 12
  end
  object Button3: TButton
    Left = 352
    Top = 448
    Width = 145
    Height = 33
    Caption = 'Pesquisar'
    TabOrder = 13
  end
end
