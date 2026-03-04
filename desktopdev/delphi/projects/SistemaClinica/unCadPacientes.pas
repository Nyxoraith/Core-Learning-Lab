unit unCadPacientes;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.Mask, Vcl.ExtCtrls,
  Vcl.DBCtrls, Data.DB, Vcl.Buttons, Vcl.Grids, Vcl.DBGrids;

type
  TformCadPacientes = class(TForm)
    Panel1: TPanel;
    Label1: TLabel;
    dbTxtCpf: TDBEdit;
    dbTxtNome: TDBEdit;
    dbTxtCelular: TDBEdit;
    dbTxtDataCadastro: TDBEdit;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    dbGridPacientes: TDBGrid;
    DBNavigator1: TDBNavigator;
    txtBuscar: TEdit;
    Label6: TLabel;
    procedure txtBuscarChange(Sender: TObject);
    procedure FormKeyPress(Sender: TObject; var Key: Char);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  formCadPacientes: TformCadPacientes;

implementation

{$R *.dfm}

uses unDM;

procedure TformCadPacientes.FormKeyPress(Sender: TObject; var Key: Char);
begin
  if Key=#27 then Self.Close;

end;

procedure TformCadPacientes.txtBuscarChange(Sender: TObject);
begin
  DM.tbPaciente.Locate('nome', txtBuscar.Text, [loPartialKey]);
end;

end.
