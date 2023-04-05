unit delete_match_by_number;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls,
  helpers in 'helpers.pas',
  db_service in 'db_service.pas';

type

  { TForm3 }

  TForm3 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    LabeledEdit1: TLabeledEdit;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private

  public

  end;

var
  Form3: TForm3;

implementation

{$R *.lfm}

{ TForm3 }

procedure TForm3.Button1Click(Sender: TObject);
var numberToDelete: integer;
begin
     if IsValidInt(Form3.LabeledEdit1.Text) then
        numberToDelete := StrToInt(Form3.LabeledEdit1.Text)
     else exit;
     deleteRecByNumber(numberToDelete);
     Form3.LabeledEdit1.Clear;
end;

procedure TForm3.Button2Click(Sender: TObject);
begin
     Form3.LabeledEdit1.Clear;
     close;
end;

end.

