#pragma once
#include "User.h"

class ThirdPartyEmployee : public User {
public:
    ThirdPartyEmployee() = default;
    ThirdPartyEmployee(const MyString& name, const MyString& surname, 
                       const MyString& egn, const MyString& password, int age);

    void display() const override;

    User* clone() const override;
};

