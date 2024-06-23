#pragma once
#include "MyString.h"
#include "Account.h"
#include "BankEmployee.h"
#include "OpenTask.h"
#include "CloseTask.h"
#include "ChangeTask.h"
#include "MyVector.hpp"

class Bank {
private:
    MyString name;
    MyVector<Account> accounts;
    MyVector<BankEmployee> employees;

public:
    Bank() = default;
    Bank(const MyString& name);

    void addAccount(const Account& account);
    void addEmployee(const BankEmployee& employee);
    bool employeeExistsByEgn(const MyString& employeeEgn) const;
    Account* findAccountById(int accountId);
    BankEmployee* findEmployeeByEgn(const MyString& employeeEgn);
    bool accountExistsById(int accountId) const;
    const MyVector<BankEmployee>& getEmployees() const;

    BankEmployee* findEmployeeWithLeastTasks();

    void handleOpenAccountRequest(const MyString& clientName, const MyString& clientSurname, const MyString& clientEgn, double initialBalance);
    void handleCloseAccountRequest(int accountId);
    void handleChangeAccountRequest(int accountId, const MyString& newBankName, const MyString& currentBankName);

    void displayAccounts() const;
    void displayEmployees() const;
    MyString getName() const;
};