#pragma once
#include "Task.h"

class CloseTask : public Task {
private:
    int accountId;

public:
    CloseTask() = default;
    CloseTask(const MyString& description, 
             const MyString& clientName, const MyString& clientSurname, const MyString& clientEgn, 
             const MyString& bankName, int accountId);

    void display() const override;
    void displayWithDescription() const;
    int getAccountId() const;
    Task* clone() const override;
};
