#include "OpenTask.h"
#include <iostream>

OpenTask::OpenTask(const MyString& description, const MyString& clientName, const MyString& clientSurname, const MyString& clientEgn, const MyString& bankName)
    : Task(TaskType::OPEN, description, clientName, clientSurname, clientEgn, bankName) {}

void OpenTask::display() const {
    std::cout << "Open - " <<clientName << " "<< clientSurname <<" wants to create an account.\n\n";
}

void OpenTask::displayWithDescription() const
{
    std::cout << "Open request from:"
        << "\nClient: " << clientName << " " << clientSurname
        << "\nEGN: " << clientEgn
        << "\nBank: " << bankName;
        std::cout << "\n\n";
}

Task* OpenTask::clone() const
{
    return new OpenTask(*this);
}