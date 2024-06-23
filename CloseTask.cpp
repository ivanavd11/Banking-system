#include "CloseTask.h"
#include <iostream>

CloseTask::CloseTask(const MyString& description, const MyString& clientName, const MyString& clientSurname, const MyString& clientEgn, const MyString& bankName, int accountId)
    : Task(TaskType::CLOSE, description, clientName, clientSurname, clientEgn, bankName), accountId(accountId) {}

void CloseTask::display() const 
{
    std::cout << "Close -  " << clientName << " " << clientSurname << " wants to close account with id" << accountId <<".\n\n";
  
}

void CloseTask::displayWithDescription() const
{
    std::cout << "Close request from\n"
        << "\nClient: " << clientName << " " << clientSurname
        << "\nEGN: " << clientEgn
        << "\nBank: " << bankName
        << "\nAccount ID: " << accountId;
        std::cout << "\n\n";
}

int CloseTask::getAccountId() const {
    return accountId;
}

Task* CloseTask::clone() const
{
    return new CloseTask(*this);
}