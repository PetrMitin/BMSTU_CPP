#include <iostream>
#include <ctime>
#include <string.h>
#include "classes.h"

using namespace std;

Number::Number(const char* alphabet) {
    Number::alphabet = new char[strlen(alphabet)+1];
    strcpy(Number::alphabet, alphabet);
    srand(time(0));
    for (int i = 0; i < 3; i++) {
        int idx = rand() % strlen(Number::alphabet);
        Number::value[i] = Number::alphabet[idx];
    }
    Number::value[3] = '\0';
}

bool Number::isDigitInNumber(char digit) {
    bool result = false;
    for (int i = 0; i < 3; i++) {
        if (Number::value[i] == digit) result = true;
    }
    return result;
}

OctalNumber::OctalNumber() : Number("01234567") {}

DecimalNumber::DecimalNumber() : Number("0123456789") {}

HexNumber::HexNumber() : Number("0123456789ABCDEF") {}

template<class number>
void Game<number>::makeMove() {
    char c;
    cout << "Enter character" << endl;
    cin >> c;
    if (data->isDigitInNumber(c)) {
        cout << "Popal!" << endl;
        for (int i = 0; i < 3; i++) {
            if (data->getValue()[i] == c) {
                cout << c << ' ';
                Game::areDigitsGuessed[i] = true;
            }
            else if (areDigitsGuessed[i]) {
                cout << data->getValue()[i] << ' ';
            }
            else cout << "_ ";
        }
        cout << endl;
    } else {
       cout << "Mimo!" << endl;
    }
    Game::numberOfMoves++;
    cout << endl;
}

template<>
void Game<OctalNumber>::play(){
   cout << "Game begins!" << endl;
   cout << "_ _ _" << endl;
   while (!(areDigitsGuessed[0] && areDigitsGuessed[1] && areDigitsGuessed[2])) makeMove();
   cout << "You won! Final number is: " << Game::data->getValue() << ". \n";
   cout << "You used " << Game::numberOfMoves << " moves to guess it!" << endl;
}

template<>
void Game<DecimalNumber>::play(){
   cout << "Game begins!" << endl;
   cout << "_ _ _" << endl;
   while (!(areDigitsGuessed[0] && areDigitsGuessed[1] && areDigitsGuessed[2])) makeMove();
   cout << "You won! Final number is: " << Game::data->getValue() << ". \n";
   cout << "You used " << Game::numberOfMoves << " moves to guess it!" << endl;
}

template<>
void Game<HexNumber>::play(){
   cout << "Game begins!" << endl;
   cout << "_ _ _" << endl;
   while (!(areDigitsGuessed[0] && areDigitsGuessed[1] && areDigitsGuessed[2])) makeMove();
   cout << "You won! Final number is: " << Game::data->getValue() << ". \n";
   cout << "You used " << Game::numberOfMoves << " moves to guess it!" << endl;
}
