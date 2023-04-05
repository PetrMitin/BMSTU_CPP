unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, Grids, StdCtrls,
  ActnList, Menus, custom_types, helpers, add_match_form,
  delete_match_by_number, gistogramma, team_filter, wins_filter;

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
    StringGrid1: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button8Click(Sender: TObject);
  private

  public

  end;

type TeamData=record
     team: string;
     number: integer;
     end;

var
  Form1: TForm1;
  f: df;
  r, filter_r: rec;
  state: string='initial';
  filter_rec: rec;
  arr: array[1..100] of string;
implementation

{$R *.lfm}

function defaultFilter(r: rec; var filter_rec:rec): boolean;
         begin
           result := True;
         end;

function drawFilter(r: rec; var filter_rec: rec): boolean;
         begin
           result := r.score1 = r.score2;
         end;

procedure TForm1.Button6Click(Sender: TObject); //показать все матчи
begin
  FillGridWithFilter(Form1.StringGrid1, @defaultFilter, filter_r);
end;

procedure TForm1.Button7Click(Sender: TObject);
begin
  assignfile(f, 'db.dat');
  reset(f);
  closefile(f);
  close;
end;

procedure TForm1.Button8Click(Sender: TObject);
begin
  Form4.show;
end;


procedure TForm1.Button2Click(Sender: TObject); //добавить матч
begin
  assignfile(f, 'db.dat');
  {$I-} Reset(F); {$I+}
  if ioresult=0 then
     begin
          seek(f,FileSize(f));
     end
  else
     rewrite(f);
  if state = 'initial' then
     begin
          state := 'add_match';
          Form2.f := f;
          Form2.state_ptr := @state;
          Form2.Show;
     end;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
     Form3.Show;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  FillGridWithFilter(Form1.StringGrid1, @drawFilter, filter_r);
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
     Form5.filter_r := @filter_rec;
     Form5.grid := StringGrid1;
     Form5.show;
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
  Form6.show;
end;

end.

