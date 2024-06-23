#pragma once
#include "Task.h"
#include "MyString.h"

enum class Status {
    Waiting,
    Approved,
    Rejected
};

class ChangeTask : public Task {
private:
    int accountId;
    MyString oldBankName;
    Status status;

public:
    ChangeTask() = default;
    ChangeTask(const MyString& description, 
               const MyString& clientName, const MyString& clientSurname, const MyString& clientEgn, 
               const MyString& bankName, int accountId, const MyString& oldBankName);

    void display() const override;
    void displayWithDescription() const;

    int getAccountId() const;
    MyString getOldBankName() const;
    Status getStatus() const;
    void approve();
    void reject();
    void setStatus(Status newState);

    Task* clone() const override;
};
