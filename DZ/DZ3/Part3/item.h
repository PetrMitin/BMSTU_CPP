#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
public:
    QString name;
    float price;
    int amount;

    Item(QString _name, float _price = 0, int _amount = 0);

};

#endif // ITEM_H
