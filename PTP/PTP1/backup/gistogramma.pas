unit gistogramma;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, Menus, StdCtrls,
  TASources, TAGraph, TASeries, custom_types, TACustomSource;

type
  TForm4 = class(TForm)
    Chart1: TChart;
    Chart1BarSeries1: TBarSeries;
    procedure FormShow(Sender: TObject);
  private

  public

  end;

type StadiumData=record
     stadium: string;
     matches: integer;
     end;

var
  Form4: TForm4;
  f: df;
implementation

{$R *.lfm}

procedure TForm4.FormShow(Sender: TObject);
var std: StadiumData; arr: array[1..100] of StadiumData; r: rec; i, count_unique, num: integer; was_new: boolean; col_code: string[7];
begin
     Randomize;
     chart1barseries1.Clear;
     assignfile(f, 'db.dat');
     reset(f);
     count_unique := 0;
     while not eof(f) do
     begin
          read(f, r);
          was_new := True;
          for i := 1 to 100 do
          begin
               if (arr[i].stadium = r.stadium) then
                  begin
                    arr[i].matches := arr[i].matches + 1;
                    was_new := False;
                  end;
          end;
          if was_new then
             begin
                  arr[count_unique+1].stadium := r.stadium;
                  arr[count_unique+1].matches := 1;
                  count_unique := count_unique + 1;
             end;
     end;
     for i := 1 to count_unique do
     begin
          num := random(99999) + 100000;
          col_code := '$' + inttostr(num) + inttostr(num) + inttostr(num);
          chart1barseries1.Add(arr[i].matches, arr[i].stadium, TColor(num));
     end;
     closefile(f);
end;
end.

