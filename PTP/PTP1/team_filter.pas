unit team_filter;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls,
  custom_types, grids, helpers;

type

  { TForm5 }

  TForm5 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Label1: TLabel;
    ListBox1: TListBox;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure FormShow(Sender: TObject);
  private

  public
    filter_r: ^rec;
    grid: tstringgrid
  end;

var
  Form5: TForm5;
  arr: array[1..100] of string;
  count_unique: integer;
implementation

{$R *.lfm}

{ TForm5 }

function teamFilter(r: rec; var filter_rec: rec): boolean;
         begin
           result := (r.team1=filter_rec.team1) or (r.team2=filter_rec.team1);
         end;

procedure TForm5.Button1Click(Sender: TObject);
var val: string; i: integer;
begin
     filter_r^.team1 := listbox1.items[ListBox1.ItemIndex];
     FillGridWithFilter(grid, @teamFilter, filter_r^);
     close;
end;

procedure TForm5.Button2Click(Sender: TObject);
begin
     close;
end;

procedure TForm5.FormShow(Sender: TObject);
var i: integer; is_new1, is_new2: boolean; f: df; r: rec;
begin
     assignfile(f, 'db.dat');
     reset(f);
     count_unique := 0;
     while not eof(f) do
       begin
         read(f, r);
         is_new1 := True;
         is_new2 := True;
         for i := 1 to 100 do
         begin
              if (r.team1 = arr[i]) then
                 is_new1 := False;
              if (r.team2 = arr[i]) then
                 is_new2 := False;
         end;
         if is_new1 then
            begin
                 count_unique := count_unique+1;
                 arr[count_unique] := r.team1;
            end;
         if is_new2 then
            begin
                 count_unique := count_unique+1;
                 arr[count_unique] := r.team2;
            end;
       end;
     closefile(f);
     for i := 1 to count_unique do
     begin
       ListBox1.AddItem(arr[i], nil);
     end;
end;
end.

