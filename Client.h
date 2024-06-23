#pragma once
#include "User.h"
#include "Message.h"
#include "Cheque.h"
#include "MyVector.hpp"

class Client : public User {
private:
    MyVector<Message> messages;
    MyVector<Cheque> cheques;

public:
    Client() = default;
    Client(const MyString& name, const MyString& surname, const MyString& egn, const MyString& password, int age);

    void display() const override;

    void addMessage(const Message& message);
    void addCheque(const Cheque& cheque);
    void removeCheque(const MyString& code);

    double redeemCheque(const MyString& code);
    void showMessages() const;
    void listCheques() const;

    User* clone() const override;
};

