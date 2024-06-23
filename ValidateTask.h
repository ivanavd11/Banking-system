#pragma once
#include "Task.h"
#include "ChangeTask.h"

class ValidateTask : public Task {
private:

    ChangeTask* ptrTask;
    const Account* ptrAccount;
    MyString targetBankName;

public:
    ValidateTask(const MyString& description,
                 const MyString& clientName, const MyString& clientSurname, const MyString& clientEgn,
                 const MyString& bankName,
                 ChangeTask* ptrTask, const Account* ptrAccount, const MyString& targetBankName);

    void display() const override;
    ChangeTask* getTask() const;
    const Account* getAccount() const;
    MyString getTargetBankName() const;

    void changeOtherTaskState(bool isValid);

    Task* clone() const override;
};
