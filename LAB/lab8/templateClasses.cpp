#include <iostream>
#include "templateClasses.h"
#include <string.h>

using namespace std;

template <>
TCustomSet<TElement>::TCustomSet(int lb, int rb, const char* chars) {
    int len = rb - lb + strlen(chars);
    TCustomSet::len = len;
    TCustomSet::arr = new TElement* [len];
    for (int i = lb; i < rb; i++) arr[i-lb] = new TNumElement(i);
    for (int i = rb-lb; i < len; i++) arr[i] = new TCharElement(chars[i-rb+lb]);
}

template <>
TCustomSet<TElement>::~TCustomSet() {
    for (int i = 0; i < TCustomSet::len; i++) {
        delete arr[i];
    }
    delete [] arr;
}

template <>
void TCustomSet<TElement>::addElement(int n) {
    for (int i = 0; i < TCustomSet::len; i++) {
        TElement* el = TCustomSet::arr[i];
        if (TNumElement* curr = dynamic_cast<TNumElement*>(el)) {
            if (curr->n == n) curr->isIncluded = true;
        }
    }
}

template <>
void TCustomSet<TElement>::addElement(char c) {
    for (int i = 0; i < TCustomSet::len; i++) {
        TElement* el = TCustomSet::arr[i];
        if (TCharElement* curr = dynamic_cast<TCharElement*>(el)) {
            if (curr->c == c) curr->isIncluded = true;
        }
    }
}

template <>
void TCustomSet<TElement>::deleteElement(int n) {
    for (int i = 0; i < TCustomSet::len; i++) {
        TElement* el = TCustomSet::arr[i];
        if (TNumElement* curr = dynamic_cast<TNumElement*>(el)) {
            if (curr->n == n) curr->isIncluded = false;
        }
    }
}

template <>
void TCustomSet<TElement>::deleteElement(char c) {
    for (int i = 0; i < TCustomSet::len; i++) {
        TElement* el = TCustomSet::arr[i];
        if (TCharElement* curr = dynamic_cast<TCharElement*>(el)) {
            if (curr->c == c) curr->isIncluded = false;
        }
    }
}

template <>
bool TCustomSet<TElement>::isIncluded(int n) {
    bool result = false;
    for (int i = 0; i < TCustomSet::len; i++) {
        TElement* el = TCustomSet::arr[i];
        if (TNumElement* curr = dynamic_cast<TNumElement*>(el)) {
            if (curr->n == n && curr->isIncluded) result = true;
        }
    }
    return result;
}

template <>
bool TCustomSet<TElement>::isIncluded(char c) {
    bool result = false;
    for (int i = 0; i < TCustomSet::len; i++) {
        TElement* el = TCustomSet::arr[i];
        if (TCharElement* curr = dynamic_cast<TCharElement*>(el)) {
            if (curr->c == c && curr->isIncluded) result = true;
        }
    }
    return result;
}

template <>
void TCustomSet<TElement>::printAll() {
    for (int i = 0; i < TCustomSet::len; i++) {
        TElement* el = TCustomSet::arr[i];
        if (TNumElement* curr = dynamic_cast<TNumElement*>(el)) {
            if (curr->isIncluded) curr->print();
        } else if (TCharElement* curr = dynamic_cast<TCharElement*>(el)) {
            if (curr->isIncluded) curr->print();
        }
    }
}

TCardinalitySet::TCardinalitySet(int lb, int rb, const char *chars) : TCustomSet(lb, rb, chars) {}

int TCardinalitySet::getCardinality() {
    return len;
}
