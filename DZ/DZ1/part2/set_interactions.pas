unit set_interactions;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Grids,
  Container, helpers;

type

  { TForm2 }

  TForm2 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    StringGrid1: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure FormClose(Sender: TObject; var CloseAction: TCloseAction);
  private

  public
        s: TModifiedSet;
  end;

var
  Form2: TForm2;

implementation

{$R *.lfm}

{ TForm2 }

procedure TForm2.FormClose(Sender: TObject; var CloseAction: TCloseAction);
begin
     s.destroy();
     edit1.clear;
end;

procedure TForm2.Button1Click(Sender: TObject);
var in1: string; nNum: TNum; nChar: TChar;
begin
     in1 := edit1.Text;
     if isValidInt(in1) then
     begin
          nNum := TNum.create(strtoint(in1));
          s.Add(nNum);
     end
     else if length(in1)=1 then
     begin
          nChar := TChar.create(in1[1]);
          s.add(nChar);
     end
     else application.messagebox('Некорректные данные для ввода!', 'Error');
     edit1.clear;
end;

procedure TForm2.Button2Click(Sender: TObject);
var in1: string; nNum: TNum; nChar: TChar;
begin
    in1 := edit1.Text;
    if isValidInt(in1) then
    begin
         nNum := TNum.create(strtoint(in1));
         s.delete(nNum);
    end
    else if length(in1)=1 then
    begin
         nChar := TChar.create(in1[1]);
         s.delete(nChar);
    end
    else application.messagebox('Некорректные данные для ввода!', 'Error');
    edit1.clear;
end;

procedure TForm2.Button3Click(Sender: TObject);
begin
     StringGrid1.rowcount := 1;
     s.ShowAll(StringGrid1);
end;

procedure TForm2.Button4Click(Sender: TObject);
var str: string;
begin
     str := inttostr(s.Cardinality());
     edit1.text := str;
end;

end.

