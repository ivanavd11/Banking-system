#pragma once
#include "MyVector.hpp"
#include "Bank.h"
#include "Client.h"
#include "ThirdPartyEmployee.h"
#include "User.h"
#include "ChangeTask.h"
#include <stdexcept>

enum class LoggedInUserType {
    None,
    Client,
    BankEmployee,
    ThirdPartyEmployee
};

class BankingSystem {
private:
    MyVector<Bank> banks;
    MyVector<Client> clients;
    MyVector<ThirdPartyEmployee> thirdPartyEmployees;
    User* loggedInUser = nullptr;

    LoggedInUserType loggedInUserType = LoggedInUserType::None;

    size_t findBankByName(const MyString& bankName) const;
    size_t findClientByEgn(const MyString& egn) const;
    size_t findThirdPartyEmployeeByEgn(const MyString& egn) const;
    size_t findBankEmployeeByEgn(const MyString& egn) const;

    bool ClientExists(const MyString& egn) const;
    bool ThirdPartyEmployeeExists(const MyString& egn) const;
    bool BankEmployeeExists(const MyString& egn, const MyString& bankName) const;

    bool validateEgn(const MyString& egn);
    bool validateAge(int age);
    bool validateName(const MyString& name);
public:
    BankingSystem() = default;
    BankingSystem(const MyVector<Bank>& banks, const MyVector<Client>& clients, const MyVector<ThirdPartyEmployee>& thirdPartyEmployees);

    LoggedInUserType getLoggedInUserType() const;
    User* getLoggedInUser() const;

    void addBank(const Bank& bank);
    void addClient(const Client& client);
    void addBankEmployee(const BankEmployee& employee, const MyString& bankName);
    void addThirdPartyEmployee(const ThirdPartyEmployee& thirdPartyEmployee);

    size_t getCounterOfBanks() const;

    void createBank(const MyString& bankName);
    void signupClient(const MyString& name, const MyString& surname, const MyString& egn, int age, const MyString& password);
    void signupBankEmployee(const MyString& name, const MyString& surname, const MyString& egn, int age, const MyString& password, const MyString& bankName);
    void signupThirdPartyEmployee(const MyString& name, const MyString& surname, const MyString& egn, int age, const MyString& password);
    bool login(const MyString& egn, const MyString& password);
    void logout();
    void showLoggedInUser() const;
    bool accountExistsById(const MyString& bankName, int accountId) const;

    User* getUserByEgn(const MyString& egn);
    Client* getClientByEgn(const MyString& egn);
    ThirdPartyEmployee* getThirdPartyEmployeeByEgn(const MyString& egn);
    Bank* getBankByName(const MyString& bankName);
    BankEmployee* getBankEmployeeByEgn(const MyString& egn);

    void validateChangeTask(ChangeTask& changeTask);
};