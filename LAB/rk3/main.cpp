#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class W {
protected:
int a;
int b;
char c;

public:
    W()
    {
        srand(time(0));
        char alph[27] = "abcdefghigklmnopqrstuvwxyz";
        a = rand() % 10;
        b = rand() % 10;
        c = alph[rand() % 26];
    }

    virtual void Out() {
        for (int i = 0; i < a-1; i++) {
            cout << '_' << endl;
        }
        for (int i = 0; i < b-1; i++) {
            cout << '_';
        }
        cout << c << endl;
    }

    void Print() {
        cout << a << ' ' << b << endl;
        Out();
    }
};

class X : public W {
public:
    X() : W() {}

    void Out() override {
        for (int i = 0; i < a-1; i++) {
            cout << '_' << endl;
        }
        for (int i = 0; i < b-1; i++) {
            cout << '_';
        }
        cout << "Mitin" << endl;
    }
};

class Y : public W {
public:
    Y() : W() {}

    void Out() override {
        for (int i = 0; i < a-1; i++) {
            cout << '_' << endl;
        }
        for (int i = 0; i < b-1; i++) {
            cout << '_';
        }
        cout << "IU6-24B" << endl;
    }
};

int main() {
    W *w1 = new W();
    X *a1 = new X();
    Y *b1 = new Y();
    w1->Print();
    a1->Print();
    b1->Print();
    delete w1;
    delete a1;
    delete b1;
    return 0;
}
