#include "User.h"
#include <iostream>
#include <cctype>

User::User(const MyString& name, const MyString& surname, const MyString& egn, const MyString& password, int age)
    : name(name), surname(surname), age(age) {
    this->password = password;
    this->egn = egn;
}

bool User::validatePassword(const MyString& other_password) const {
   
    return password == other_password;
}

MyString User::getName() const {
    return name;
}

MyString User::getSurname() const {
    return surname;
}

MyString User::getEgn() const {
    return egn;
}

int User::getAge() const {
    return age;
}
