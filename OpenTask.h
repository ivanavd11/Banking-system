#pragma once
#include "Task.h"

class OpenTask : public Task 
{
public:
    OpenTask() = default;
    OpenTask(const MyString& description,
             const MyString& clientName, const MyString& clientSurname, const MyString& clientEgn, 
             const MyString& bankName);

    void display() const override;
    void displayWithDescription() const;
    Task* clone() const override;
};
