unit unPrincipal;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls, Vcl.Styles, Vcl.Themes;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    txtNum1: TEdit;
    txtNum2: TEdit;
    txtResultado: TEdit;
    btnSomar: TButton;
    btnSubtrair: TButton;
    btnMultiplicar: TButton;
    btnDividir: TButton;
    optVisual: TRadioGroup;
    procedure btnSomarClick(Sender: TObject);
    procedure btnSubtrairClick(Sender: TObject);
    procedure btnMultiplicarClick(Sender: TObject);
    procedure btnDividirClick(Sender: TObject);
    procedure optVisualClick(Sender: TObject);
    procedure txtNum1Change(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);

  private
    function calcularResultado(num1, num2: Real; operacao: String): Real;
    function validarCampos(): Boolean;
    procedure habilitarBotoes(habilitado: Boolean);
    procedure registrarLog(acao: String);
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

{ TForm1 }

procedure TForm1.btnSomarClick(Sender: TObject);
begin
  if validarCampos then
  begin
    txtResultado.Text := FloatToStr(calcularResultado(StrToFloat(txtNum1.Text), StrToFloat(txtNum2.Text), 'somar'));
    registrarLog('Soma, num1=' + txtNum1.Text + ', num2=' + txtNum2.Text + ', resultado=' + txtResultado.Text);
  end;

end;

procedure TForm1.btnSubtrairClick(Sender: TObject);
begin
  if validarCampos then
  begin
    txtResultado.Text := FloatToStr(calcularResultado(StrToFloat(txtNum1.Text), StrToFloat(txtNum2.Text), 'subtrair'));
    registrarLog('Subtração, num1=' + txtNum1.Text + ', num2=' + txtNum2.Text + ', resultado=' + txtResultado.Text);
  end;

end;

procedure TForm1.btnMultiplicarClick(Sender: TObject);
begin
  if validarCampos then
  begin
    txtResultado.Text := FloatToStr(calcularResultado(StrToFloat(txtNum1.Text), StrToFloat(txtNum2.Text), 'multiplicar'));
    registrarLog('Multiplicação, num1=' + txtNum1.Text + ', num2=' + txtNum2.Text + ', resultado=' + txtResultado.Text);
  end;

end;

procedure TForm1.btnDividirClick(Sender: TObject);
begin
  if validarCampos then
    begin
      if txtNum2.Text = '0' then
        begin
          ShowMessage('Impossível dividir por zero!');
          registrarLog('Erro de divisão por zero.');
        end
      else
        begin
          txtResultado.Text := FloatToStr(calcularResultado(StrToFloat(txtNum1.Text), StrToFloat(txtNum2.Text), 'dividir'));
          registrarLog('Divisão, num1=' + txtNum1.Text + ', num2=' + txtNum2.Text + ', resultado=' + txtResultado.Text);
        end;
    end;

end;

function TForm1.calcularResultado(num1, num2: Real; operacao: String): Real;
var
  resultado: Real;
begin
  resultado := 0;

  if operacao = 'somar' then
    resultado := num1 + num2;
  if operacao = 'subtrair' then
    resultado := num1 - num2;
  if operacao = 'multiplicar' then
    resultado := num1 * num2;
  if operacao = 'dividir' then
    resultado := num1 / num2;

  Result := resultado;
end;

procedure TForm1.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  registrarLog('Aplicação Finalizada.');
  registrarLog('------------------------------');
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  registrarLog('------------------------------');
  registrarLog('Aplicação Iniciada.');
end;

procedure TForm1.optVisualClick(Sender: TObject);
begin
  case optVisual.ItemIndex of
    0:
      begin
        TStyleManager.SetStyle('Windows');
        registrarLog('Visual da aplicação alterado para Light');
      end;
    1:
      begin
        TStyleManager.SetStyle('Glow');
        registrarLog('Visual da aplicação alterado para Dark');
      end;
  end;


end;

procedure TForm1.txtNum1Change(Sender: TObject);
begin
  if validarCampos then
    habilitarBotoes(True)
  else
    habilitarBotoes(False);
end;

procedure TForm1.habilitarBotoes(habilitado: Boolean);
begin
    btnSomar.Enabled := habilitado;
    btnSubtrair.Enabled := habilitado;
    btnMultiplicar.Enabled := habilitado;
    btnDividir.Enabled := habilitado;
end;

procedure TForm1.registrarLog(acao: String);
var
  arquivo: TextFile;
begin
  try
    AssignFile(arquivo, 'Logs.txt');

    if FileExists('Logs.txt') then
      Append(arquivo)
    else
      Rewrite(arquivo);

    Writeln(arquivo, '[' + DateTimeToStr(now()) + '] - ' + acao);
  finally
    CloseFile(arquivo);
  end;
end;

function TForm1.validarCampos: Boolean;
begin
  if (txtNum1.Text = '') or (txtNum2.Text = '') then
    Result := False
  else
    try
      StrToFloat(txtNum1.Text);
      StrToFloat(txtNum2.Text);

      Result := True;
    except
        on E: EConvertError do
        begin
          Result := False;
        end;
    end;

end;

end.
