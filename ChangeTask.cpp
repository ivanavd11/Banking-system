#include "ChangeTask.h"
#include <iostream>

ChangeTask::ChangeTask(const MyString& description, const MyString& clientName, const MyString& clientSurname, const MyString& clientEgn, const MyString& bankName, int accountId, const MyString& oldBankName)
    : Task(TaskType::CHANGE, description, clientName, clientSurname, clientEgn, bankName), 
      accountId(accountId), oldBankName(oldBankName), status(Status::Waiting) {}

void ChangeTask::display() const {

    switch (status) {
    case Status::Waiting:
        std::cout << "Change - " << clientName << " " << clientSurname << " wants to join " << bankName << "\n\n";
        break;
    case Status::Approved:
        std::cout << "Change (approved) - " << clientName << " " << clientSurname << " wants to join " << bankName << "\n\n";
        break;
    case Status::Rejected:
        std::cout << "Change - " << bankName << " asks if " << clientName << " " << clientSurname << " is real user.\n\n ";
        break;
    }

}

void ChangeTask::displayWithDescription() const
{
    std::cout << "ChangeTask: " << description.c_str() << "\nClient: " << clientName.c_str() << " " << clientSurname.c_str()
        << "\nEGN: " << clientEgn.c_str() << "\nBank: " << bankName.c_str()
        << "\nOld Bank: " << oldBankName.c_str() << "\nAccount ID: " << accountId
        << "\nStatus: ";
    switch (status) {
    case Status::Waiting:
        std::cout << "Waiting";
        break;
    case Status::Approved:
        std::cout << "Approved";
        break;
    case Status::Rejected:
        std::cout << "Rejected";
        break;
    }
    std::cout << "\n\n";
}

int ChangeTask::getAccountId() const {
    return accountId;
}

MyString ChangeTask::getOldBankName() const {
    return oldBankName;
}

Status ChangeTask::getStatus() const {
    return status;
}

void ChangeTask::approve() {
    if (status == Status::Waiting) {
        status = Status::Approved;
        std::cout << "ChangeTask approved.\n\n";
        
    }
    else {
        std::cout << "ChangeTask is not in a state that can be approved.\n\n";
    }
}

void ChangeTask::reject() {
    if (status == Status::Waiting) {
        status = Status::Rejected;
        std::cout << "ChangeTask rejected.\n\n";
    }
    else {
        std::cout << "ChangeTask is not in a state that can be rejected.\n\n";
    }
}
void ChangeTask::setStatus(Status newState) {
    status = newState;
}

Task* ChangeTask::clone() const {
    return new ChangeTask(*this);
}