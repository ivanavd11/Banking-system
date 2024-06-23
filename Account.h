#pragma once
#include "MyString.h"

class Account {
private:
    static int nextId;
    int id;
    MyString bankName;
    MyString ownerFirstName;
    MyString ownerLastName;
    MyString ownerEgn;
    double balance;

public:
    Account() = default;
    Account(const MyString& bankName, 
            const MyString& ownerFirstName, const MyString& ownerLastName, const MyString& ownerEgn,
            double initialBalance = 0.0);

    int getId() const;
    MyString getBankName() const;
    MyString getOwnerFirstName() const;
    MyString getOwnerLastName() const;
    MyString getOwnerEgn() const;
    double getBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);

    void display() const;
};
