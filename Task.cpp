#include "Task.h"
#include <iostream>

Task::Task(TaskType type, const MyString& description, 
           const MyString& clientName, const MyString& clientSurname, const MyString& clientEgn,
           const MyString& bankName)
    : type(type), description(description), 
      clientName(clientName), clientSurname(clientSurname), clientEgn(clientEgn), 
      bankName(bankName) {}

TaskType Task::getType() const {
    return type;
}

MyString Task::getDescription() const {
    return description;
}

MyString Task::getClientName() const {
    return clientName;
}

MyString Task::getClientSurname() const {
    return clientSurname;
}

MyString Task::getClientEgn() const {
    return clientEgn;
}

MyString Task::getBankName() const {
    return bankName;
}