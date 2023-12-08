#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string.h>
using namespace std;

class Element {
public:
    Element* next;
    bool isIncluded;

    Element(bool _isIncluded=false, Element* _next=nullptr) : isIncluded(_isIncluded), next(_next) {}

    virtual void include() {isIncluded = true;}

    virtual void exclude() {isIncluded = false;}
};

class NumElement : public Element {
public:
    int val;
    NumElement(int _val) : Element(), val(_val) {}
};

class CharElement : public Element {
public:
    char val;
    CharElement(char _val) : Element(), val(_val) {}
};

class CustomSet {
protected:
    Element *first, *last;
public:
    void addInitialElement(Element* el) {
        if (last != nullptr) last->next = el;
        if (first == nullptr) first = el;
        last = el;
    }

    void addElement(int el) {
        Element* c = first;
        do {
            if(NumElement* curr = dynamic_cast<NumElement*>(c)) if(curr->val == el) curr->include();
            c = c ? c->next : nullptr;
        } while(c);
    }

    void addElement(char el) {
        Element* c = first;
        do {
            if(CharElement* curr = dynamic_cast<CharElement*>(c)) if(curr->val == el) curr->include();
            c = c ? c->next : nullptr;
        } while(c);
    }

    void deleteElement(int el) {
        Element* c = first;
        do {
            if(NumElement* curr = dynamic_cast<NumElement*>(c)) if(curr->val == el) curr->exclude();
            c = c ? c->next : nullptr;
        } while(c);
    }

    void deleteElement(char el) {
        Element* c = first;
        do {
            if(CharElement* curr = dynamic_cast<CharElement*>(c)) if(curr->val == el)  curr->exclude();
            c = c ? c->next : nullptr;
        } while(c);
    }

    bool isIncluded(int el) {
        bool result = false;
        Element* c = first;
        do {
            if(NumElement* curr = dynamic_cast<NumElement*>(c)) if(curr->val == el) result = true;
            c = c ? c->next : nullptr;
        } while(c);
        return result;
    }

    bool isIncluded(char el) {
        bool result = false;
        Element* c = first;
        do {
            if(CharElement* curr = dynamic_cast<CharElement*>(c)) if(curr->val == el) result = true;
            c = c ? c->next : nullptr;
        } while(c);
        return result;
    }

    void printAll() {
        Element* c = first;
        do {
            if(NumElement* curr = dynamic_cast<NumElement*>(c)) {
                if (curr->isIncluded) cout << curr->val << endl;
            }
            else if (CharElement* curr = dynamic_cast<CharElement*>(c)) if (curr->isIncluded) cout << curr->val << endl;
            c = c ? c->next : nullptr;
        } while(c);
    }

    CustomSet(int lb=0, int rb=0, const char* chars="") {
        first = nullptr;
        last = nullptr;
        for (int i = lb; i < rb; i++) addInitialElement(new NumElement(i));
        for (int i = 0; i < strlen(chars); i++) addInitialElement(new CharElement(chars[i]));
    }
};

class CardinalitySet : public CustomSet {
public:
    CardinalitySet(int lb=0, int rb=0, const char* chars="") : CustomSet(lb, rb, chars) {}

    int getCardinality() {
        int result = 0;
        Element* curr = first;
        while(curr != nullptr) {
            result++;
            curr = curr->next;
        }
        return result;
    }
};

#endif // CLASSES_H
