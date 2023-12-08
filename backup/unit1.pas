unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Grids,
  ExtCtrls, unit2, unit3, unit4;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Label1: TLabel;
    Label2: TLabel;
    Memo1: TMemo;
    Panel1: TPanel;
    RadioButton1: TRadioButton;
    RadioButton2: TRadioButton;
    RadioGroup1: TRadioGroup;
    StringGrid1: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;
  arr, resultArr: triangleArray;
  length, resultLength: integer;
  avgP: real;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
begin
     enterArray(memo1, length, arr);
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
     showArray(StringGrid1, length, arr);
end;

procedure TForm1.Button3Click(Sender: TObject);
var p: real;
begin
     formArray(length, arr, resultArr, resultLength, avgP);
     if radioButton1.Checked then
     begin
          form2.show;
          showArray(form2.StringGrid1, resultLength, resultArr);
     end
     else
     begin
          p := strtofloat(inputbox('P', 'Enter p', '0'));
          label1.caption := inttostr(perimeterMoreThan(p, length, arr));
          label2.caption := floattostr(avgP);
     end;
end;

end.

