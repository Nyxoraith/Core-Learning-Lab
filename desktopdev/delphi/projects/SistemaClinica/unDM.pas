unit unDM;

interface

uses
  System.SysUtils, System.Classes, FireDAC.Stan.Intf, FireDAC.Stan.Option,
  FireDAC.Stan.Error, FireDAC.UI.Intf, FireDAC.Phys.Intf, FireDAC.Stan.Def,
  FireDAC.Stan.Pool, FireDAC.Stan.Async, FireDAC.Phys, FireDAC.Phys.MySQL,
  FireDAC.Phys.MySQLDef, FireDAC.VCLUI.Wait, FireDAC.Stan.Param, FireDAC.DatS,
  FireDAC.DApt.Intf, FireDAC.DApt, Data.DB, FireDAC.Comp.DataSet,
  FireDAC.Comp.Client;

type
  TDM = class(TDataModule)
    dbClinica: TFDConnection;
    tbPaciente: TFDTable;
    tbAgendamento: TFDTable;
    dsPaciente: TDataSource;
    dsAgendamento: TDataSource;
    tbPacienteid: TFDAutoIncField;
    tbPacientecpf: TStringField;
    tbPacientenome: TStringField;
    tbPacientecelular: TStringField;
    tbPacientedata_cadastro: TDateField;
    tbAgendamentoid: TFDAutoIncField;
    tbAgendamentoid_paciente: TIntegerField;
    tbAgendamentodata: TDateField;
    tbAgendamentohora: TStringField;
    tbAgendamentoespecialidade: TStringField;
    tbAgendamentomedico: TStringField;
    procedure tbPacienteAfterInsert(DataSet: TDataSet);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  DM: TDM;

implementation

{%CLASSGROUP 'Vcl.Controls.TControl'}

{$R *.dfm}

procedure TDM.tbPacienteAfterInsert(DataSet: TDataSet);
begin
  tbPacientedata_cadastro.Value := Date();
end;

end.
