unit Unit3;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils, Grids, strutils, stdCtrls,
  unit2 in 'unit2.pas';

procedure enterArray(memo: TMemo; var length: integer; var arr: triangleArray);

procedure showArray(grid: TStringGrid; length: integer; var arr: triangleArray);

implementation
procedure enterArray(memo: TMemo; var length: integer; var arr: triangleArray);
var curr_rec: triangle; str: string;
begin
     length := 0;
     for str in memo.lines do
     begin
       length := length + 1;
       curr_rec.a := StrToFloat(SplitString(str, ' ')[0]);
       curr_rec.b := StrToFloat(SplitString(str, ' ')[1]);
       curr_rec.c := StrToFloat(SplitString(str, ' ')[2]);
       arr[length] := curr_rec;
     end;
     memo.clear;
end;

procedure showArray(grid: TStringGrid; length: integer; var arr: triangleArray);
var i: integer;
begin
     grid.clear;
     grid.colcount := 3;
     grid.rowcount := length;
     for i := 1 to length do
     begin
       grid.Cells[0, i-1] := FloatToStr(arr[i].a);
       grid.Cells[1, i-1] := FloatToStr(arr[i].b);
       grid.Cells[2, i-1] := FloatToStr(arr[i].c);
     end;
end;

end.

