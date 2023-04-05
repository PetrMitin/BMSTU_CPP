#ifndef TEMPLATECLASSES_H
#define TEMPLATECLASSES_H

#include <iostream>
using namespace std;

class TElement {
public:
    bool isIncluded;

    TElement() : isIncluded(false) {}

    virtual void print() {}
};

class TNumElement : public TElement {
public:
    int n;
    TNumElement(int _n) : TElement(), n(_n) {}
    void print() override {
        cout << "Num: " << n << endl;
    }
};

class TCharElement : public TElement {
public:
    char c;
    TCharElement(char _c) : TElement(), c(_c) {}
    void print() override {
        cout << "Char: " << c << endl;
    }
};

template <class element>
class TCustomSet {
public:
    int len;
    element** arr;

    TCustomSet(int lb=0, int rb=0, const char* chars="");

    ~TCustomSet();

    void addElement(int n);

    void deleteElement(int n);

    bool isIncluded(int n);

    void addElement(char c);

    void deleteElement(char c);

    bool isIncluded(char c);

    void printAll();
};

class TCardinalitySet : public TCustomSet<TElement> {
public:
    TCardinalitySet(int lb, int rb, const char* chars);

    int getCardinality();
};

#endif // TEMPLATECLASSES_H
