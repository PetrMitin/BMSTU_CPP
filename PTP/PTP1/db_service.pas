unit db_service;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils,
  custom_types in 'custom_types.pas';

procedure addRec(r: rec; var f: df);
procedure deleteRecByNumber(number: integer);

implementation

procedure addRec(r: rec; var f: df);
          var isValidRec: boolean; curr_r: rec;
          begin
               isValidRec := True;
               while not eof(f) and isValidRec do
               begin
                 read(f, curr_r);
                 if (r = curr_r) then
                    isValidRec := False;
               end;
               if isValidRec then
                  write(f, r);
          end;

procedure deleteRecByNumber(number: integer);
          var curr_r: rec; counter: integer; f, del_f: df;
          begin
               assignfile(f, 'db.dat');
               reset(f);
               assignfile(del_f, 'del.dat');
               rewrite(del_f);
               counter := 0;
               while not eof(f) do
               begin
                 counter := counter + 1;
                 read(f, curr_r);
                 if counter <> number then
                    write(del_f, curr_r);
               end;
               closefile(f);
               DeleteFile('db.dat');
               closefile(del_f);
               RenameFile('del.dat', 'db.dat');
          end;

end.

