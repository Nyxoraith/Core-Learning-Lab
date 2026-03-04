program SistemaClinica;

uses
  Vcl.Forms,
  unPrincipal in 'unPrincipal.pas' {formPrincipal},
  unCadPacientes in 'unCadPacientes.pas' {formCadPacientes},
  unCadAgendamentos in 'unCadAgendamentos.pas' {formCadAgendamentos},
  unDM in 'unDM.pas' {DM: TDataModule};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TformPrincipal, formPrincipal);
  Application.CreateForm(TformCadPacientes, formCadPacientes);
  Application.CreateForm(TformCadAgendamentos, formCadAgendamentos);
  Application.CreateForm(TDM, DM);
  Application.Run;
end.
