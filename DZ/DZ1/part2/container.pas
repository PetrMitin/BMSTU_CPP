unit Container;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils, Grids, forms;

type TElement = class(TObject)
  public
    isIncluded: boolean;
  end;

  type TElementPointer = ^TElement;

  type TNum = class(TElement)
    public
      val: integer;
      constructor Create(aNum: integer);
    end;

type TNumPointer = ^TNum;

type TChar = class(TElement)
  public
    val: char;
    constructor Create(aChar: char);
  end;

type TCharPointer = ^TChar;

type TCustomSet = class(TObject)
  public
    arr: array of TElement;
    l: integer;
    constructor Create(startNum, endNum: integer; chars: string);
    procedure Add(element: TElement);
    procedure Delete(element: TElement);
    procedure ShowAll(grid: TStringGrid);
    function Includes(element: TElement): boolean;
    destructor Destroy();override;
  end;

type TModifiedSet = class(TCustomSet)
  public
    function Cardinality(): integer;
  end;

implementation
    constructor TNum.Create(aNum: integer);
    begin
         inherited Create;
         self.isIncluded:=false;
         val := aNum;
    end;

    constructor TChar.Create(aChar: char);
    begin
         inherited Create;
         self.isIncluded:=false;
         val := aChar;
    end;

    constructor TCustomSet.Create(startNum, endNum: integer; chars: string);
    var i: integer; currNum: TNum; currChar: TChar; str: string;
    begin
         inherited Create;
         str := '';
         for i := 0 to length(chars)-1 do
         begin
              if not str.Contains(chars[i+1]) then
                begin
                  str := str + chars[i+1];
                end;
         end;
         l := endNum-startNum+Length(str);
         arr := [];
         setLength(self.arr, self.l);
         for i := 0 to endNum-startNum-1 do
         begin
              currNum := TNum.create(i + startNum);
              arr[i] := currNum;
         end;
         for i := 0 to length(str)-1 do
           begin
             currChar := TChar.create(str[i]);
             arr[i+endNum-startNum] := currChar;
           end;
    end;

    function TCustomSet.Includes(element: TElement): boolean;
    var i : integer; res: boolean=false;
    begin
         if (element is TNum) then
         begin
              for i := 0 to l-1 do
              begin
                   if (arr[i] is TNum) and ((arr[i] as TNum).val=(element as TNum).val) then res := True;
              end;
         end
         else if (element is TChar) then
         begin
           for i := 0 to l-1 do
                begin
                     if (arr[i] is TChar) and ((arr[i] as TChar).val=(element as TChar).val) then res := True;
                end;
         end;
         result := res;
    end;

    procedure TCustomSet.Add(element: TElement);
    var i: integer;
    begin
         if Self.Includes(element) then
         begin
              if (element is TNum) then
                 begin
                      for i := 0 to l-1 do
                      begin
                           if (arr[i] is TNum) and ((arr[i] as TNum).val=(element as TNum).val) then arr[i].isIncluded:=true;
                      end;
                 end
                 else if (element is TChar) then
                 begin
                   for i := 0 to l-1 do
                        begin
                             if (arr[i] is TChar) and ((arr[i] as TChar).val=(element as TChar).val) then arr[i].isIncluded:=true;
                        end;
                 end;
         end
         else application.messagebox('Некорректные данные для ввода!', 'Error');
    end;

    procedure TCustomSet.Delete(element: TElement);
    var i: integer;
    begin
         if Self.Includes(element) then
         begin
              if (element is TNum) then
                 begin
                      for i := 0 to l-1 do
                      begin
                           if (arr[i] is TNum) and ((arr[i] as TNum).val=(element as TNum).val) then arr[i].isIncluded:=false;
                      end;
                 end
                 else if (element is TChar) then
                 begin
                   for i := 0 to l-1 do
                        begin
                             if (arr[i] is TChar) and ((arr[i] as TChar).val=(element as TChar).val) then arr[i].isIncluded:=false;
                        end;
                 end;
         end
         else application.messagebox('Некорректные данные для удаления!', 'error');
    end;

    procedure TCustomSet.ShowAll(grid: TStringGrid);
    var i: integer;
    begin
         for i := 0 to self.l-1 do
             if arr[i].isIncluded then
                begin
                     if (arr[i] is TNum) then begin
                       grid.InsertRowWithValues(grid.RowCount, [IntToStr((arr[i] as TNum).val)]);
                     end
                     else if (arr[i] is TChar) then begin
                       grid.InsertRowWithValues(grid.RowCount, [(arr[i] as TChar).val]);
                     end;
                end;
    end;

    destructor TCustomSet.destroy();
    var i: integer;
    begin
         for i := 0 to l-1 do
             begin
                  arr[i].Destroy;
                  inherited destroy();
             end;
    end;

    function TModifiedSet.Cardinality(): integer;
    begin
         result := l;
    end;

end.

