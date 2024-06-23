#pragma once
#include "MyString.h"

class User
{
protected:
    MyString name;
    MyString surname;
    MyString password;
    MyString egn;
    int age;

public:
    User() = default;
    User(const MyString& name, const MyString& surname, const MyString& egn, const MyString& password, int age);

    virtual User* clone() const = 0;
    virtual void display() const = 0;
    virtual ~User() = default; 

    bool validatePassword(const MyString& password) const;

    MyString getName() const;
    MyString getSurname() const;
    MyString getEgn() const;
    int getAge() const;
};
