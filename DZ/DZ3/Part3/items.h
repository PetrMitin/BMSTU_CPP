#ifndef ITEMS_H
#define ITEMS_H

#include <QtSql>
#include <vector>
#include "item.h"

class Items
{
public:
    Items(QString dbName="dz3part3", QString host="127.0.0.1", QString user="postgres", QString password="150600Pm");

    std::vector<Item> getAllItems();

    bool addItem(QString name, float price, int amount);

    bool updateItem(QString name, float price, int amount);

    bool deleteItem(QString name);

private:
    QSqlDatabase db;
};

#endif // ITEMS_H
