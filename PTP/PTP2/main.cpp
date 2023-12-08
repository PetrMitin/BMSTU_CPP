#include <iostream>
#include "classes.h"
using namespace std;
void getNotation(int &notation) {
    cout  << "In which notation do you want to play? (Enter corresponding digit)" << endl;
    cout << "1. Octal" << endl;
    cout << "2. Decimal" << endl;
    cout << "3. Hexidecimal" << endl;
    cin >> notation;
    cout << '\n';
}
int main()
{
    cout << "Guess the Number game" << endl;
    cout << "So, let's begin! \n" << endl;
    int notation;
    getNotation(notation);
    while (notation < 1 || notation > 3) {
        cout << "Incorrect option selected!" << endl;
        getNotation(notation);
    }
    switch (notation) {
        case 1:
        {
            Game<OctalNumber> game;
            game.play();
            break;
        }
        case 2:
        {
            Game<DecimalNumber> game;
            game.play();
            break;
        }
        case 3:
        {
            Game<HexNumber> game;
            game.play();
            break;
        }
        default:
            break;
    }
    return 0;
}
