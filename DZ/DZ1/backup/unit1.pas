unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls, Figure;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    Button8: TButton;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    PaintBox1: TPaintBox;
    Timer1: TTimer;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button8Click(Sender: TObject);
    procedure FormActivate(Sender: TObject);
    procedure Timer1StopTimer(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
  private
  public

  end;

var
  Form1: TForm1;
implementation

{$R *.lfm}

{ TForm1 }
var
  L: TLine;
  S: TSquare;
  O: TOctagon;
  t: single=0;
  k1, k2, k3: real;

procedure TForm1.FormActivate(Sender: TObject);
begin
     k1 := 0.25;
     k2 := 0.125;
     k3 := 0.5;
     Paintbox1.Canvas.Brush.Color:=clWhite;
end;

procedure TForm1.Timer1StopTimer(Sender: TObject);
begin
  paintbox1.canvas.brush.color := clwhite;
  paintbox1.canvas.fillrect(0,0,paintbox1.width, paintbox1.Height);
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
   L := TLine.Create(60,100,30,Paintbox1);
   S := TSquare.create(180,100,50, Paintbox1);
   o := TOctagon.Create(400, 100, 100, paintbox1);
   Paintbox1.Canvas.Brush.Color:=clBlack;
   Paintbox1.Canvas.Pen.Color:=clBlack;
   timer1.enabled := true;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
     k1 := k1 + 0.3;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
     k1 := k1 - 0.3;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
      k2 := k2 + 0.3;
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
      k2 := k2 - 0.3;
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
     k3 := k3 + 0.3;
end;

procedure TForm1.Button7Click(Sender: TObject);
begin
    k3 := k3 - 0.3;
end;

procedure TForm1.Button8Click(Sender: TObject);
begin
  timer1.Enabled:=false;
end;

procedure TForm1.Timer1Timer(Sender: TObject);
begin
   L.Move(k1*t);
   S.Move(k2*t);
   o.move(k3*t);
   t:=t+0.5;
end;

end.

