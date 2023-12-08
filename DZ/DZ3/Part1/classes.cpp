#include <iostream>
#include <cmath>
#include <string.h>
#include <iterator>
#include <vector>
#include "classes.h"

using namespace std;

Letter::Letter(const char *_senderAddress, const char *_receiverAddress, float _weight) : weight(_weight) {
    //cout << "Letter constructor begin" << endl;
    Letter::senderAddress = new char[strlen(_senderAddress)];
    Letter::receiverAddress = new char[strlen(_receiverAddress)];
    strcpy(Letter::senderAddress, _senderAddress);
    strcpy(Letter::receiverAddress, _receiverAddress);
    //cout << "Letter constructor end" << endl;
}

Letter::Letter(const Letter &initial) : Letter(initial.senderAddress, initial.receiverAddress, initial.weight) {
    //cout << "Letter copy constructor end" << endl;
}

Letter& Letter::operator =(const Letter& initial) {
    //cout << "Letter operator = begin" << endl;
    strcpy(Letter::senderAddress, initial.senderAddress);
    strcpy(Letter::receiverAddress, initial.receiverAddress);
    Letter::weight = initial.weight;
    //cout << "Letter operator = end" << endl;
    return *this;
}

Letter::~Letter()  {
    //cout << "Letter destructor" << endl;
    //cout << this->senderAddress << ' ' << this->receiverAddress << endl;
    delete [] senderAddress;
    delete [] receiverAddress;
}

void Letter::printInfo() {
    cout << "Sender: " << Letter::senderAddress << endl;
    cout << "Receiver: " << Letter::receiverAddress << endl;
    cout << "Weight: " << Letter::weight << endl;
    cout << "Delivery price: " << getDeliveryPrice() << endl << endl;
}

float Letter::getDeliveryPrice() {
    return 63 + 3.5 * ceil((weight-20) / 20);
}

ValuableLetter::ValuableLetter(const char *_senderAddress, const char *_receiverAddress, float _weight, float _price)
    : Letter(_senderAddress, _receiverAddress, _weight), price(_price) {
    //cout << "ValLetter constructor end" << endl;
}

ValuableLetter::ValuableLetter(const ValuableLetter &initial) : Letter(initial.senderAddress, initial.receiverAddress, initial.weight), price(initial.price) {
    //cout << "ValLetter copy constructor end" << endl;
}

ValuableLetter& ValuableLetter::operator =(const ValuableLetter &initial) {
    strcpy(ValuableLetter::senderAddress, initial.senderAddress);
    strcpy(ValuableLetter::receiverAddress, initial.receiverAddress);
    ValuableLetter::weight = initial.weight;
    ValuableLetter::price = initial.price;
    return *this;
}

void ValuableLetter::printInfo() {
    Letter::printInfo();
    cout << "Additional payment: " << ValuableLetter::getAdditionalPayment() << endl << endl;
}

float ValuableLetter::getAdditionalPayment() {
    return ValuableLetter::price * 0.03;
}

float ValuableLetter::getDeliveryPrice() {
    return Letter::getDeliveryPrice() + ValuableLetter::getAdditionalPayment();
}

MailBox::MailBox(vector<ValuableLetter*> _arr) {
    for (vector<ValuableLetter*>::iterator i = _arr.begin(); i != _arr.end(); i++) {
        ValuableLetter curr = *(*i);
        MailBox::arr.push_back(curr);
    }
}

MailBox::~MailBox() {
    //cout << "Mailbox destructor begin" << endl;
    for (vector<ValuableLetter>::iterator i = MailBox::arr.begin(); i != MailBox::arr.end(); i++) {
        (*i).~Letter();
    }
    //cout << "Mailbox destructor end" << endl;
}

float MailBox::getFullPrice() {
    float price = 0;
    for (vector<ValuableLetter>::iterator i = MailBox::arr.begin(); i != MailBox::arr.end(); i++) price += (*i).getDeliveryPrice();
    return price;
}

void MailBox::printLettersInfo() {
    for (vector<ValuableLetter>::iterator i = MailBox::arr.begin(); i != MailBox::arr.end(); i++) {
        (*i).printInfo();
        cout << endl;
    }
}
