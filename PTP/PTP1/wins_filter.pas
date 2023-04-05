unit wins_filter;
{$mode ObjFPC}{$H+}
interface
uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, grids, StdCtrls, Buttons, custom_types, helpers;
type
  TForm6 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    StringGrid1: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
  public
  end;
  type WinsData=record
    team: string;
    wins: integer;
  end;
var Form6: TForm6;
implementation
{$R *.lfm}
procedure TForm6.Button1Click(Sender: TObject);
var f: df; r: rec; count_unique, fltr, i: integer; arr: array[1..100] of WinsData; is_new: boolean;
begin
     if IsValidInt(edit1.text) then fltr := strtoint(edit1.text)
     else exit;
     stringgrid1.RowCount:=1;
     assignfile(f, 'db.dat');
     reset(f);
     count_unique := 0;
     while not eof(f) do
           begin
             read(f, r);
             is_new := True;
             if (r.score1 > r.score2) then
                begin
                     for i := 1 to count_unique do
                       begin
                            if arr[i].team = r.team1 then
                               begin
                                    is_new := False;
                                    arr[i].wins := arr[i].wins+1;
                               end;
                       end;
                     if is_new then
                       begin
                         count_unique := count_unique+1;
                         arr[count_unique].team := r.team1;
                         arr[count_unique].wins := 1;
                       end;
                end
             else if (r.score1 < r.score2) then
                 begin
                   for i := 1 to count_unique do
                       begin
                            if arr[i].team = r.team2 then
                               begin
                                    is_new := False;
                                    arr[i].wins := arr[i].wins+1;
                               end;
                       end;
                   if is_new then
                       begin
                         count_unique := count_unique+1;
                         arr[count_unique].team := r.team2;
                         arr[count_unique].wins := 1;
                       end;
                 end;
           end;
           closefile(f);
           edit1.clear;
           for i := 1 to count_unique do
               begin
                 if (arr[i].wins >= fltr) then StringGrid1.insertrowwithvalues(i, arr[i].team);
               end;
  end;
  procedure TForm6.Button2Click(Sender: TObject);
  begin
  edit1.clear;
  close;
  end;
end.

