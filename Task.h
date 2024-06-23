#pragma once
#include "MyString.h"

enum class TaskType {
    OPEN,
    CLOSE,
    CHANGE
};

class Task {
protected:
    TaskType type;
    MyString description;
    MyString clientName;
    MyString clientSurname;
    MyString clientEgn;
    MyString bankName;

public:
    Task() = default;
    Task(TaskType type, const MyString& description, const MyString& clientName, const MyString& clientSurname, const MyString& clientEgn, const MyString& bankName);

    virtual ~Task() = default;

    TaskType getType() const;
    MyString getDescription() const;
    MyString getClientName() const;
    MyString getClientSurname() const;
    MyString getClientEgn() const;
    MyString getBankName() const;

    virtual void displayWithDescription() const=0;
    virtual void display() const = 0;
    virtual Task* clone() const = 0;
};