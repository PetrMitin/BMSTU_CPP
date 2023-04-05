#ifndef CLASSES_H
#define CLASSES_H

#include <string.h>

class Letter {
protected:
    char* senderAddress;
    char* receiverAddress;
    int weight;

public:
    Letter() : senderAddress(""), receiverAddress(""), weight(0) {}

    Letter(const char* _senderAddress, const char* _receiverAddress, int _weight) : weight(_weight) {
        strcpy(senderAddress, _senderAddress);
        strcpy(receiverAddress, _receiverAddress);
    }

    Letter(const Letter &initial) {
        weight = initial.weight;
        strcpy(senderAddress, initial.senderAddress);
        strcpy(receiverAddress, initial.receiverAddress);
    }

    Letter& operator =(const Letter &initial) {

    }

    ~Letter() {
        delete [] senderAddress;
        delete [] receiverAddress;
    }
};

class ValuableLetter : public Letter {
protected:
    int price;

public:
    ValuableLetter() : Letter(), price(0) {}

    ValuableLetter(const char* _senderAddress, const char* _receiverAddress, int _weight, int _price)
        : Letter(_senderAddress, _receiverAddress, _weight), price(_price) {}

    ValuableLetter& operator =(const ValuableLetter &initial) {

    }
};

class MailBox {
protected:
    ValuableLetter* arr;
public:
    MailBox(ValuableLetter* _arr, int len) {
        arr = new ValuableLetter[len];
        for (int i = 0; i < len; i++) arr[i] = _arr[i];
    }

    ~MailBox() {
        delete [] arr;
    }
};

#endif // CLASSES_H
