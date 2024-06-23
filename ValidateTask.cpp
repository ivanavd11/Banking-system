#include "ValidateTask.h"
#include <iostream>

ValidateTask::ValidateTask(const MyString& description, 
                           const MyString& clientName, const MyString& clientSurname, const MyString& clientEgn, 
                           const MyString& bankName, 
                           ChangeTask* ptrTask, const Account* ptrAccount, const MyString& targetBankName)
            : Task(TaskType::VALIDATE, description, 
                   clientName, clientSurname, clientEgn, bankName), 
                   ptrTask(ptrTask), ptrAccount(ptrAccount), targetBankName(targetBankName) {}

void ValidateTask::display() const {
    std::cout << "Validate Task:\n"
        << "Description: " << description
        << "\nClient: " << clientName << " " << clientSurname
        << "\nEGN: " << clientEgn
        << "\nBank: " << bankName
        << "\nChange Task ID: " << (ptrTask ? ptrTask->getAccount()->getId() : -1)
        << "\nAccount ID: " << (ptrAccount ? ptrAccount->getId() : -1)
        << "\nTarget Bank: " << targetBankName
        << std::endl;
}

ChangeTask* ValidateTask::getTask() const {
    return ptrTask;
}

const Account* ValidateTask::getAccount() const {
    return ptrAccount;
}

MyString ValidateTask::getTargetBankName() const {
    return targetBankName;
}

void ValidateTask::changeOtherTaskState(bool isValid) {
    if (ptrTask) {
        if (isValid) {
            ptrTask->setState(State::Approve);
        }
        else {
            ptrTask->setState(State::Rejected);
        }
    }
}

Task* ValidateTask::clone() const
{
    return new ValidateTask(*this);
}