object formCadAgendamentos: TformCadAgendamentos
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Cadastro de Agendamentos'
  ClientHeight = 648
  ClientWidth = 535
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object Label2: TLabel
    Left = 280
    Top = 176
    Width = 40
    Height = 15
    Caption = 'M'#233'dico'
  end
  object Label3: TLabel
    Left = 280
    Top = 240
    Width = 90
    Height = 15
    Caption = 'Data da Consulta'
  end
  object Label4: TLabel
    Left = 32
    Top = 240
    Width = 92
    Height = 15
    Caption = 'Hora da Consulta'
  end
  object Label5: TLabel
    Left = 32
    Top = 105
    Width = 98
    Height = 15
    Caption = 'Nome do Paciente'
  end
  object Label6: TLabel
    Left = 32
    Top = 176
    Width = 113
    Height = 15
    Caption = 'Especialidade M'#233'dica'
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
      Left = 192
      Top = 28
      Width = 156
      Height = 25
      Alignment = taCenter
      Caption = 'Agendamentos'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object DBEdit3: TDBEdit
    Left = 280
    Top = 261
    Width = 121
    Height = 23
    DataField = 'data'
    DataSource = DM.dsAgendamento
    MaxLength = 10
    TabOrder = 1
  end
  object DBEdit4: TDBEdit
    Left = 32
    Top = 261
    Width = 121
    Height = 23
    DataField = 'hora'
    DataSource = DM.dsAgendamento
    MaxLength = 5
    TabOrder = 2
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 32
    Top = 126
    Width = 465
    Height = 23
    DataField = 'id_paciente'
    DataSource = DM.dsAgendamento
    KeyField = 'id'
    ListField = 'nome'
    ListSource = DM.dsPaciente
    TabOrder = 3
  end
  object DBComboBox1: TDBComboBox
    Left = 32
    Top = 197
    Width = 145
    Height = 23
    DataField = 'especialidade'
    DataSource = DM.dsAgendamento
    Items.Strings = (
      'Cardiologista'
      'Oncologista'
      'Psic'#243'loga')
    TabOrder = 4
  end
  object DBComboBox2: TDBComboBox
    Left = 280
    Top = 197
    Width = 217
    Height = 23
    DataField = 'medico'
    DataSource = DM.dsAgendamento
    Items.Strings = (
      'Dr. Manuel Joaquim'
      'Dr. '#193'lvares Cabral'
      'Dra. Silvia Ferreira'
      'Dra. Juliana Silva')
    TabOrder = 5
  end
  object dbGridPacientes: TDBGrid
    Left = 32
    Top = 360
    Width = 465
    Height = 249
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    TabStop = False
    DataSource = DM.dsAgendamento
    TabOrder = 6
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'medico'
        Title.Caption = 'M'#233'dico'
        Width = 142
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'data'
        Title.Caption = 'Data'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'hora'
        Title.Caption = 'Hora'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'especialidade'
        Title.Caption = 'Especialidade'
        Width = 143
        Visible = True
      end>
  end
  object DBNavigator2: TDBNavigator
    Left = 32
    Top = 297
    Width = 460
    Height = 41
    DataSource = DM.dsAgendamento
    TabOrder = 7
  end
end
