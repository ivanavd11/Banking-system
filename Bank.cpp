#include "Bank.h"
#include <iostream>

Bank::Bank(const MyString& name) : name(name) {}

void Bank::addAccount(const Account& account) {
    accounts.push_back(account);
}

void Bank::addEmployee(const BankEmployee& employee) {
    employees.push_back(employee);
}

bool Bank::employeeExistsByEgn(const MyString& employeeEgn) const {
    for (size_t i = 0; i < employees.size(); ++i) {
        if (employees[i].getEgn() == employeeEgn) {
            return true;
        }
    }
    return false;
}

Account* Bank::findAccountById(int accountId) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getId() == accountId) {
            return &accounts[i];
        }
    }
    return nullptr;
}

BankEmployee* Bank::findEmployeeByEgn(const MyString& employeeEgn) {
    for (size_t i = 0; i < employees.size(); ++i) {
        if (employees[i].getEgn() == employeeEgn) {
            return &employees[i];
        }
    }
    return nullptr;
}

const MyVector<BankEmployee>& Bank::getEmployees() const {
    return employees;
}

bool Bank::accountExistsById(int accountId) const {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getId() == accountId) {
            return true;
        }
    }
    return false;
}

BankEmployee* Bank::findEmployeeWithLeastTasks() {
    if (employees.empty()) {
        return nullptr;
    }

    BankEmployee* leastBusyEmployee = &employees[0];
    size_t leastTaskCount = employees[0].getTaskCount();

    for (size_t i = 1; i < employees.size(); ++i) {
        size_t taskCount = employees[i].getTaskCount();
        if (taskCount < leastTaskCount) {
            leastTaskCount = taskCount;
            leastBusyEmployee = &employees[i];
        }
    }

    return leastBusyEmployee;
}

void Bank::handleOpenAccountRequest(const MyString& clientName, const MyString& clientSurname, const MyString& clientEgn, double initialBalance) {
   
    // Намиране на банкера с най-малко задачи
    BankEmployee* leastBusyEmployee = findEmployeeWithLeastTasks();
    if (leastBusyEmployee) {
        // Създаване на нова задача за отваряне на сметка
        OpenTask* openTask = new OpenTask("Open Account", clientName, clientSurname, clientEgn, name);
        leastBusyEmployee->addTask(openTask);

        std::cout << "Account  request for " << clientName << " " << clientSurname << " has been sent to an employee.\n\n";
    }
    else {
        throw std::runtime_error( "No employees available to handle the open account request.\n");
    }
}
    

void Bank::handleCloseAccountRequest(int accountId) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getId() == accountId) {

            BankEmployee* leastBusyEmployee = findEmployeeWithLeastTasks();
            if (leastBusyEmployee) {

                CloseTask* closeTask = new CloseTask("Close Account", accounts[i].getOwnerFirstName(), 
                                                      accounts[i].getOwnerLastName(), accounts[i].getOwnerEgn(), name, accountId);
                leastBusyEmployee->addTask(closeTask);
                
               // accounts.erase(i);
                std::cout << "Account with ID " << accountId << " has been closed.\n\n";
                return;
            }
        }
        throw std::runtime_error("Account not found.\n\n");
    }
}

void Bank::handleChangeAccountRequest(int accountId, const MyString& newBankName, const MyString& currentBankName) 
{
    Account* account = findAccountById(accountId);
    if (account) {

        BankEmployee* leastBusyEmployee = findEmployeeWithLeastTasks();
        if (leastBusyEmployee) {

            ChangeTask* changeTask = new ChangeTask("Open request from:", account->getOwnerFirstName(), account->getOwnerLastName(),
                account->getOwnerEgn(), newBankName, accountId, currentBankName);
            leastBusyEmployee->addTask(changeTask);

            std::cout << "Account with ID " << accountId << " submits a move request to " << newBankName << ".\n\n";

        }
        else {
            throw std::runtime_error("Account not found.\n\n");
        }
    }
}

void Bank::displayAccounts() const {
    for (size_t i = 0; i < accounts.size(); ++i) {
        accounts[i].display();
    }
    if (accounts.size() == 0)
    {
        throw std::runtime_error("No accounts.");
    }
}

void Bank::displayEmployees() const {
    std::cout << "Employees in " << name << ":\n";
    for (size_t i = 0; i < employees.size(); ++i) {
        employees[i].display();
    }
    if (employees.size() == 0)
    {
        throw std::runtime_error("No employees.");
    }
}

MyString Bank::getName() const {
    return name;
}