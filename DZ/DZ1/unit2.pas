unit unit2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Container, set_interactions, helpers;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    procedure Button1Click(Sender: TObject);
  private
  public

  end;

var
  Form1: TForm1;
  s: TModifiedSet;
implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
var in1, in2, in3: string; lb, rb: integer;
begin
     in1 := Edit1.text;
     in2 := edit2.text;
     in3 := edit3.text;
     if isValidInt(in1) and isValidInt(in2) then
       begin
            lb := strtoint(in1);
            rb := strtoint(in2);
            s := TModifiedSet.create(lb, rb, in3);
            edit1.clear;
            edit2.clear;
            edit3.clear;
            Form2.s := s;
            Form2.show;
       end
     else Application.MessageBox('Введены некорректные данные!', 'Error');
end;

end.

