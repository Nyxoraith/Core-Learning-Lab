object formCadPacientes: TformCadPacientes
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Cadastro de Pacientes'
  ClientHeight = 645
  ClientWidth = 535
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  KeyPreview = True
  Position = poScreenCenter
  OnKeyPress = FormKeyPress
  TextHeight = 15
  object Label2: TLabel
    Left = 32
    Top = 171
    Width = 21
    Height = 15
    Caption = 'CPF'
  end
  object Label3: TLabel
    Left = 32
    Top = 105
    Width = 89
    Height = 15
    Caption = 'Nome Completo'
  end
  object Label4: TLabel
    Left = 216
    Top = 176
    Width = 37
    Height = 15
    Caption = 'Celular'
  end
  object Label5: TLabel
    Left = 376
    Top = 176
    Width = 90
    Height = 15
    Caption = 'Data de Cadastro'
  end
  object Label6: TLabel
    Left = 32
    Top = 243
    Width = 83
    Height = 15
    Caption = 'Buscar Paciente'
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 535
    Height = 89
    Align = alTop
    TabOrder = 0
    ExplicitWidth = 624
    object Label1: TLabel
      Left = 160
      Top = 28
      Width = 233
      Height = 25
      Alignment = taCenter
      Caption = 'Cadastro de Pacientes'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object dbTxtCpf: TDBEdit
    Left = 32
    Top = 197
    Width = 145
    Height = 23
    DataField = 'cpf'
    DataSource = DM.dsPaciente
    MaxLength = 14
    TabOrder = 2
  end
  object dbTxtNome: TDBEdit
    Left = 32
    Top = 126
    Width = 465
    Height = 23
    DataField = 'nome'
    DataSource = DM.dsPaciente
    TabOrder = 1
  end
  object dbTxtCelular: TDBEdit
    Left = 216
    Top = 197
    Width = 121
    Height = 23
    DataField = 'celular'
    DataSource = DM.dsPaciente
    MaxLength = 16
    TabOrder = 3
  end
  object dbTxtDataCadastro: TDBEdit
    Left = 376
    Top = 197
    Width = 121
    Height = 23
    DataField = 'data_cadastro'
    DataSource = DM.dsPaciente
    Enabled = False
    ReadOnly = True
    TabOrder = 4
  end
  object dbGridPacientes: TDBGrid
    Left = 32
    Top = 304
    Width = 465
    Height = 249
    DataSource = DM.dsPaciente
    TabOrder = 6
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'nome'
        Title.Caption = 'Pacientes Cadastrados'
        Visible = True
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 32
    Top = 576
    Width = 460
    Height = 41
    DataSource = DM.dsPaciente
    TabOrder = 7
  end
  object txtBuscar: TEdit
    Left = 32
    Top = 264
    Width = 465
    Height = 23
    TabOrder = 5
    OnChange = txtBuscarChange
  end
end
