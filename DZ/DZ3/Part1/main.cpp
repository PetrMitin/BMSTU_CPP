#include <iostream>
#include <vector>
#include "classes.h"

using namespace std;

int main()
{
    Letter *l = new Letter("Me", "You", 20);
    l->printInfo();
    delete l;
    ValuableLetter *l1 = new ValuableLetter("Me", "You", 20, 20);
    ValuableLetter *l2 = new ValuableLetter("Me", "Not You", 20, 120);
    ValuableLetter *l3 = new ValuableLetter("Not Me", "You", 120, 20);
    ValuableLetter *l4 = new ValuableLetter("Not Me", "Not You", 120, 120);
    l1->printInfo();
    vector<ValuableLetter*> arr;
    arr.push_back(l1);
    arr.push_back(l2);
    arr.push_back(l3);
    arr.push_back(l4);
    MailBox* mailbox = new MailBox(arr, 4);
    arr.clear();
    mailbox->printLettersInfo();
    cout << "Full price: " << mailbox->getFullPrice() << endl;
    delete mailbox;
    return 0;
}
