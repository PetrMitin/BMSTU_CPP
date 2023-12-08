#ifndef CLASSES_H
#define CLASSES_H

#include <vector>

/*! @file
@startuml
    class Letter {
        +senderAddress
        +receiverAddress
        +weight
        +Letter()
        +Letter(const char* _senderAddress, const char* _receiverAddress, float _weight)
        +Letter(const Letter& initial)
        +virtual ~Letter()
        +Letter& operator =(const Letter& initial)
        +virtual void printInfo()
        +virtual float getDeliveryPrice()
    }

    class ValuableLetter {
        +price
        +ValuableLetter()
        +ValuableLetter(const char* _senderAddress, const char* _receiverAddress, float _weight, float _price)
        +ValuableLetter(const ValuableLetter& initial)
        +ValuableLetter& operator =(const ValuableLetter& initial)
        +void printInfo() override
        +float getAdditionalPayment()
        +float getDeliveryPrice() override
    }

    class MailBox {
        +vector<ValuableLetter> arr
        +len
        +MailBox(std::vector<ValuableLetter*> _arr, int len)
        +~MailBox()
        +void printLettersInfo()
        +float getFullPrice()
    }

    Letter <|-- ValuableLetter
    MailBox o-- ValuableLetter
@enduml
*/

/*! @brief Класс, описывающий заказное письмо */
class Letter {
protected:
    /*! @brief Адрес отправителя */
    char* senderAddress;
    /*! @brief Адрес получателя */
    char* receiverAddress;
    /*! @brief Вес письма */
    float weight;

public:
    Letter() : senderAddress(""), receiverAddress(""), weight(0) {}

    /*!
     *  @brief Конструктор
     *  @param _senderAddress - адрес отправителя
     *  @param _receiverAddress - адрес получателя
     *  @param _weight - вес письма
    */
    Letter(const char* _senderAddress, const char* _receiverAddress, float _weight);

    /*!
     *  @brief Копирующий конструктор
    */
    Letter(const Letter& initial);

    /*!
     *  @brief Виртуальный деструктор
    */
    virtual ~Letter();

    /*!
     *  @brief Переопределенный оператор присваивания
    */
    Letter& operator =(const Letter& initial);

    /*!
     *  @brief Вывод иформации
     *  @details Выводит адреса отправителя и получателя, вес и цену отправки
    */
    virtual void printInfo();

    /*!
     *  @brief Расчёт цены отправки
    */
    virtual float getDeliveryPrice();
};

/*! @brief Класс, описывающий ценное письмо */
class ValuableLetter : public Letter {
protected:
    /*! @brief Ценность письма */
    float price;

public:
    /*!
     *  @brief Конструктор без параметров
    */
    ValuableLetter() : Letter(), price(0) {}

    /*!
     *  @brief Конструктор
     *  @param _senderAddress - адрес отправителя
     *  @param _receiverAddress - адрес получателя
     *  @param _weight - вес письма
     *  @param _price - ценность письма
    */
    ValuableLetter(const char* _senderAddress, const char* _receiverAddress, float _weight, float _price);

    /*!
     *  @brief Копирующий конструктор
    */
    ValuableLetter(const ValuableLetter& initial);

    /*!
     *  @brief Переопределенный оператор присваивания
    */
    ValuableLetter& operator =(const ValuableLetter& initial);

    /*!
     *  @brief Вывод иформации
     *  @details Выводит адреса отправителя и получателя, вес и цену отправки с учётом ценности письма
    */
    void printInfo() override;

    /*!
     *  @brief Расчёт дополнительной оплаты за ценность письма
    */
    float getAdditionalPayment();

    /*!
     *  @brief Расчёт цены отправки
    */
    float getDeliveryPrice() override;
};

/*! @brief Класс, описывающий почтовый ящик для ценных писем */
class MailBox {
protected:
    /*! @brief Ценные письма в std::vector */
    std::vector<ValuableLetter> arr;
    /*! @brief Количество писем */
    int len;
public:
    /*!
     *  @brief Конструктор
     *  @param _arr - указатели на ценные письма в std::vector
     *  @param len - количество писем
    */
    MailBox(std::vector<ValuableLetter*> _arr);

    /*!
     *  @brief Деструктор
     */
    ~MailBox();

    /*!
     *  @brief Вывод иформации
     *  @details Вызывает процедуру вывода информации для каждого письма
    */
    void printLettersInfo();

    /*!
     *  @brief Расчёт полной стоимости отправки
    */
    float getFullPrice();
};

#endif // CLASSES_H
