unit Unit2;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils;

type triangle = record
  a: real;
  b: real;
  c: real;
end;

type triangleArray = array [1..20] of triangle;

function perimeterMoreThan(p: real; length: integer; var arr: triangleArray) : integer;

procedure formArray(length: integer; var source: triangleArray; var result: triangleArray; var resultLength: integer; var avgPerimeter: real);

function getTriangle(str: string) : triangle;

implementation

function perimeterMoreThan(p: real; length: integer; var arr: triangleArray) : integer;
var i, res: integer;
begin
  res := 0;
  for i := 1 to length do
  begin
       if (arr[i].a + arr[i].b + arr[i].c) > p then
          res := res + 1;
  end;
  perimeterMoreThan := res;
end;

procedure formArray(length: integer; var source: triangleArray; var result: triangleArray; var resultLength: integer; var avgPerimeter: real);
var i, j: integer;
begin
  avgPerimeter := 0;
  j := 0;
  for i := 1 to length do
      avgPerimeter := avgPerimeter + source[i].a + source[i].b + source[i].c;
  avgPerimeter := avgPerimeter / length;
  for i := 1 to length do
      if (source[i].a + source[i].b + source[i].c) > avgPerimeter then
         begin
              j := j + 1;
              result[j] := source[i];
         end;
  resultLength := j;
end;

function getTriangle(str: string) : triangle;
var curr_val: string; res: triangle; c: char; i: integer;
begin
  i := 0;
  for c in str do
  begin
       if c = ' ' then
          begin
               if i = 0 then
                  begin
                  res.a := strtofloat(curr_val);
                  i := 1;
                  end
               else if i = 1 then
                  begin
                  res.b :=  strtofloat(curr_val);
                  i := 2;
                  end;
          end
       else
           curr_val := curr_val + c;
  end;
  res.c := strtofloat(curr_val);
  getTriangle := res;
end;

end.

