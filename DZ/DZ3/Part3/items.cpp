#include "items.h"

using namespace std;

Items::Items(QString dbName, QString host, QString user, QString password) {
    this->db = QSqlDatabase::addDatabase("QPSQL");
    this->db.setDatabaseName(dbName);
    this->db.setHostName(host);
    this->db.setUserName(user);
    this->db.setPassword(password);
}

vector<Item> Items::getAllItems() {
    vector<Item> result;
    if(this->db.open()) {
        QSqlQuery getAll;
        if (getAll.exec("SELECT * FROM public.items"))
            while(getAll.next())
                result.push_back(Item(getAll.value(0).toString(), getAll.value(1).toFloat(), getAll.value(2).toInt()));
    }
    this->db.close();
    return result;
}

bool Items::addItem(QString name, float price, int amount) {
    bool ok = true;
    if(this->db.open()) {
        QSqlQuery addNew;
        addNew.prepare("INSERT INTO public.items VALUES (?, ?, ?)");
        addNew.addBindValue(name);
        addNew.addBindValue(price);
        addNew.addBindValue(amount);
        if (!addNew.exec()) ok = false;
    } else ok = false;
    this->db.close();
    return ok;
}

bool Items::updateItem(QString name, float price, int amount) {
    bool ok = true;
    if(this->db.open()) {
        QSqlQuery update;
        update.prepare("UPDATE public.items SET name=:name, price=:price, amount=:amount WHERE name=:name");
        update.bindValue(":name", name);
        update.bindValue(":price", price);
        update.bindValue(":amount", amount);
        if (!update.exec()) ok = false;
    } else ok = false;
    this->db.close();
    return ok;
}

bool Items::deleteItem(QString name) {
    bool ok = true;
    if(this->db.open()) {
        QSqlQuery del;
        del.prepare("DELETE FROM public.items WHERE name=:name");
        del.bindValue(":name", name);
        if (!del.exec()) ok = false;
    } else ok = false;
    this->db.close();
    return ok;
}
