#ifndef CLASSES_H
#define CLASSES_H

#include <ctime>
#include <string.h>
using namespace std;

class Number {
protected:
    char value[4];
    char* alphabet;

public:
    Number(const char* _alphabet);

    ~Number() {delete [] value; delete [] alphabet;}

    bool isDigitInNumber(char digit);

    const char* getValue() {
        return value;
    }
};

class OctalNumber : public Number {
public:
    OctalNumber();
};

class DecimalNumber : public Number {
public:
    DecimalNumber();
};

class HexNumber : public Number {
public:
    HexNumber();
};

template <class number>
class Game {
private:
    number* data;
    bool areDigitsGuessed[3] = {false, false, false};
    int numberOfMoves = 0;

    void makeMove();

public:
    Game() {this->data = new number();}

    ~Game() {delete data;}

    void play();
};

#endif // CLASSES_H
