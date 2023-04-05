unit add_match_form;
{$mode ObjFPC}{$H+}
interface
uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, Grids, StdCtrls,
  custom_types in 'custom_types.pas',
  db_service in 'db_service.pas',
  helpers;
type
  TForm2 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    StringGrid1: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
  public
    r: rec;
    f: df;
    state_ptr: ^string;
  end;

var
  Form2: TForm2;
implementation
{$R *.lfm}

procedure TForm2.Button1Click(Sender: TObject); //сохранить
var curr_r: rec; c1, c2, c3, c4, c5: string; is_valid_r: boolean;
begin
     c1 := Form2.StringGrid1.Cells[0, 1];
     c2 := Form2.StringGrid1.Cells[1, 1];
     c3 := Form2.StringGrid1.Cells[2, 1];
     c4 := Form2.StringGrid1.Cells[3, 1];
     c5 := Form2.StringGrid1.Cells[4, 1];
     Form2.StringGrid1.Cells[0, 1] := '';
     Form2.StringGrid1.Cells[1, 1] := '';
     Form2.StringGrid1.Cells[2, 1] := '';
     Form2.StringGrid1.Cells[3, 1] := '';
     Form2.StringGrid1.Cells[4, 1] := '';
     state_ptr^ := 'initial';
     is_valid_r := (Length(c1) > 0) and (Length(c1) > 0) and (Length(c1) > 0);
     is_valid_r := is_valid_r and IsValidInt(c4);
     if is_valid_r then
     begin
       curr_r.stadium := c1;
       curr_r.team1 := c2;
       curr_r.team2 := c3;
       curr_r.score1 := strtoint(c4);
       curr_r.score2 := strtoint(c5);
       addRec(curr_r, f);
     end;
end;

procedure TForm2.Button2Click(Sender: TObject); // отмена
begin
     Form2.StringGrid1.Cells[0, 1] := '';
     Form2.StringGrid1.Cells[1, 1] := '';
     Form2.StringGrid1.Cells[2, 1] := '';
     Form2.StringGrid1.Cells[3, 1] := '';
     Form2.StringGrid1.Cells[4, 1] := '';
     closefile(f);
     state_ptr^ := 'initial';
     close;
end;
end.

