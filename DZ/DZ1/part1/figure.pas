unit Figure;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils, graphics, ExtCtrls;
 Type  TFigure=Class
      x,y, halflen,dx,dy:integer;        Image:TPaintbox;
      constructor Create(ax,ay,ah:integer;aImage:TPaintbox);
      procedure Move(t:single);virtual;
      procedure Draw;virtual;abstract;
      procedure Rel(t:real);virtual;
   end;
   TLine=Class(TFigure)
          procedure Draw;override;
   end;
   TSquare=Class(TFigure)
          procedure Draw;override;
   end;
   TOctagon=class(TFigure)
        dx1, dy1: integer;
        procedure Rel(t: real); override;
        procedure Draw(); override;
   end;
   Implementation
  Constructor TFigure.Create(ax,ay,ah:integer;aImage:TPaintbox);
    Begin
       inherited Create;
       x:=ax; y:=ay; halflen:=ah; Image:=aImage;
    End;
  Procedure TFigure.Rel(t: real);
    Begin
       dx:=round(halflen*cos(t));
       dy:=round(halflen*sin(t));
    End;
  Procedure TFigure.Move(t: single);
    Begin
       Image.Canvas.Pen.Color:=clWhite;
       Self.Draw;
       Image.Canvas.Brush.Color:=clBlack;
       Image.Canvas.Pen.Color:=clBlack;
       Self.Rel(t);
       Self.Draw;
    End;
  Procedure TLine.Draw;
    Begin   Image.Canvas.MoveTo(x+dx,y+dy);
            Image.Canvas.LineTo(x-dx,y-dy);
    End;
  Procedure TSquare.Draw;
    Begin   Image.Canvas.MoveTo(x+dx,y+dy);
            Image.Canvas.LineTo(x-dy,y+dx);
            Image.Canvas.LineTo(x-dx,y-dy);
            Image.Canvas.LineTo(x+dy,y-dx);
            Image.Canvas.LineTo(x+dx,y+dy);
    End;

  procedure TOctagon.Rel(t: real);
  begin
       inherited Rel(t);
       dx1 := round(halflen*cos(t + pi/4));
       dy1 := round(halflen*sin(t + pi/4));
  end;

  procedure TOctagon.draw();
  begin
       Image.canvas.moveto(x+dx, y+dy);
       Image.canvas.lineto(x+dx1, y+dy1);
       Image.canvas.lineto(x-dy, y+dx);
       Image.canvas.lineto(x-dy1, y+dx1);
       Image.canvas.lineto(x-dx, y-dy);
       Image.canvas.lineto(x-dx1, y-dy1);
       Image.canvas.lineto(x+dy, y-dx);
       Image.canvas.lineto(x+dy1, y-dx1);
       Image.canvas.lineto(x+dx, y+dy);
  end;

end.

