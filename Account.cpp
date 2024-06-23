#include "Account.h"
#include <iostream>

int Account::nextId = 1;

Account::Account(const MyString& bankName, 
                 const MyString& ownerFirstName, const MyString& ownerLastName, const MyString& ownerEgn, 
                 double initialBalance)
        : id(nextId++), bankName(bankName), 
          ownerFirstName(ownerFirstName), ownerLastName(ownerLastName), ownerEgn(ownerEgn),
          balance(initialBalance) {}

int Account::getId() const {
    return id;
}

MyString Account::getBankName() const {
    return bankName;
}

MyString Account::getOwnerFirstName() const {
    return ownerFirstName;
}

MyString Account::getOwnerLastName() const {
    return ownerLastName;
}

MyString Account::getOwnerEgn() const {
    return ownerEgn;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::display() const {
    std::cout << "Account ID: " << id
        << "\nBank: " << bankName
        << "\nOwner: " << ownerFirstName << " " << ownerLastName 
        << " with EGN: " << ownerEgn << "\n\n";
}
