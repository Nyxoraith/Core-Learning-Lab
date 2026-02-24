program Agenda;

uses
  Vcl.Forms,
  unPrincipal in 'unPrincipal.pas' {Form1},
  unDM in 'unDM.pas' {DM: TDataModule};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TDM, DM);
  Application.Run;
end.
