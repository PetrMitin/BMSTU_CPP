unit custom_types;

{$mode ObjFPC}{$H+}
{$modeswitch advancedrecords}

interface

uses
  Classes, SysUtils;

type rec = record
  stadium: string[50];
  team1: string[50];
  team2: string[50];
  score1: integer;
  score2: integer;
  class operator = (a, b: rec): Boolean;
end;

type df = file of rec;

type FilterFunction = function (r: rec, var filter_rec: rec): boolean;


implementation

class operator rec.=(a, b: rec): boolean;
begin
  result := (a.stadium = b.stadium) and (a.team1 = b.team1) and (a.team2 = b.team2) and (a.score1 = b.score1) and (a.score2 = b.score2);
end;

end.

