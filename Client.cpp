#include "Client.h"
#include <iostream>

Client::Client(const MyString& name, const MyString& surname, const MyString& egn, const MyString& password, int age)
    : User(name, surname, egn, password, age) {}

void Client::display() const {
    std::cout << "Client\n " 
              <<"Name: " << name << " " << surname
              << "\nEGN: " << egn << "\nPassword: "<<password
              << "\nAge: " << age << std::endl;
}

void Client::addMessage(const Message& message) {
    messages.push_back(message);
}

void Client::addCheque(const Cheque& cheque) {
    cheques.push_back(cheque);
}

void Client::removeCheque(const MyString& code) {
    for (size_t i = 0; i < cheques.size(); ++i) {
        if (cheques[i].isValidCode(code)) {
            cheques.erase(i);
            return;
        }
    }
    throw std::runtime_error("Cheque not found.");
}

double Client::redeemCheque(const MyString& code) {
    for (size_t i = 0; i < cheques.size(); ++i) {
        if (cheques[i].isValidCode(code)) {
            double amount = cheques[i].withdrawCash();
          
            return amount;
        }
    }
    throw std::runtime_error("Cheque not found.\n");
    return 0.0;
}

void Client::showMessages() const {
    for (size_t i = 0; i < messages.size(); ++i) {
        std::cout << "[" << i << "] - ";
        messages[i].display();
    }
    std::cout << "\n";
}

void Client::listCheques() const {
    for (size_t i = 0; i < cheques.size(); ++i) {
        cheques[i].display();
    }
}

User* Client::clone() const {
    return new Client(*this);
}
