unit helpers;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils;

function IsValidInt(str_num: string): boolean;
implementation
function IsValidInt(str_num: string): boolean;
var res: boolean; i: integer;
begin
     res := length(str_num) > 0;
     i := 1;
     while (i <= Length(str_num)) and res do
           begin
                res := str_num[i] in ['0'..'9'];
                i := i + 1;
           end;
     IsValidInt := res;
end;
end.
