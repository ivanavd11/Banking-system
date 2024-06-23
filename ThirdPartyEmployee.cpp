#include "ThirdPartyEmployee.h"
#include <iostream>

ThirdPartyEmployee::ThirdPartyEmployee(const MyString& name, const MyString& surname, 
                                       const MyString& egn, const MyString& password, int age)
    : User(name, surname, egn, password, age) {}

void ThirdPartyEmployee::display() const {
    std::cout << "Third-Party Employee\n "
              << "Name: "<< name << " " << surname <<"\n"
              << "EGN: " << egn << "\nPassword: "<< password<< "\nAge: " << age << std::endl;
}

User* ThirdPartyEmployee::clone() const {
    return new ThirdPartyEmployee(*this);
}

