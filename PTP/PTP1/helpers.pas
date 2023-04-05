unit helpers;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils, Grids,
  custom_types in 'custom_types.pas';
procedure DeleteRow(Grid: TStringGrid; ARow: Integer);
procedure FillGridWithFilter(Grid: TStringGrid; filter: FilterFunction; filter_rec: rec);
function IsValidInt(str_num: string): boolean;

implementation

procedure DeleteRow(Grid: TStringGrid; ARow: Integer);
var
  i: Integer;
begin
  for i := ARow to Grid.RowCount - 2 do
    Grid.Rows[i].Assign(Grid.Rows[i + 1]);
  Grid.RowCount := Grid.RowCount - 1;
end;

procedure FillGridWithFilter(Grid: TStringGrid; filter: FilterFunction; filter_rec: rec);
var counter: integer=0; f: df; r: rec;
begin
  Grid.RowCount:=1;
  assignfile(f, 'db.dat');
  reset(f);
  while not eof(f) do
        begin
          read(f, r);
          counter := counter + 1;
          if filter(r, filter_rec) then
             Grid.InsertRowWithValues(Grid.RowCount, [IntToStr(counter), r.stadium, r.team1, r.team2, IntToStr(r.score1), IntToStr(r.score2)]);
        end;
  closefile(f);
end;

function IsValidInt(str_num: string): boolean;
var res: boolean; i: integer;
begin
     res := True;
     i := 1;
     while (i <= Length(str_num)) and res do
           begin
                res := str_num[i] in ['0'..'9'];
                i := i + 1;
           end;
     IsValidInt := res;
end;

end.

