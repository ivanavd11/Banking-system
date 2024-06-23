#include "BankingSystem.h"
#include <iostream>

BankingSystem::BankingSystem(const MyVector<Bank>& banks, const MyVector<Client>& clients, 
                             const MyVector<ThirdPartyEmployee>& thirdPartyEmployees)
    : banks(banks), clients(clients), thirdPartyEmployees(thirdPartyEmployees) {}

size_t BankingSystem::findBankByName(const MyString& bankName) const {
    for (size_t i = 0; i < banks.size(); ++i) {
        if (banks[i].getName() == bankName) {
            return i;
        }
    }
    return banks.size();
}

size_t BankingSystem::findClientByEgn(const MyString& egn) const {
    for (size_t i = 0; i < clients.size(); ++i) {
        if (clients[i].getEgn() == egn) {
            return i;
        }
    }
    return clients.size();
}

size_t BankingSystem::findThirdPartyEmployeeByEgn(const MyString& egn) const {
    for (size_t i = 0; i < thirdPartyEmployees.size(); ++i) {
        if (thirdPartyEmployees[i].getEgn() == egn) {
            return i;
        }
    }
    return thirdPartyEmployees.size();
}

size_t BankingSystem::findBankEmployeeByEgn(const MyString& egn) const {
    for (size_t i = 0; i < banks.size(); ++i) {
        const MyVector<BankEmployee>& employees = banks[i].getEmployees();
        for (size_t j = 0; j < employees.size(); ++j) {
            if (employees[j].getEgn() == egn) {
                return i;
            }
        }
    }
    return banks.size(); 
}

bool BankingSystem::validateEgn(const MyString& egn) {
    if (egn.getSize() != 10) {
        throw std::invalid_argument("EGN must be exactly 10 digits long.");
    }
    for (size_t i = 0; i < egn.getSize(); ++i) {
        if (!isdigit(egn[i])) {
            throw std::invalid_argument("EGN must contain only digits.");
        }
    }
    return true;
}

bool BankingSystem::validateAge(int age) {
    if (age < 18 || age > 100) {
        throw std::invalid_argument("Age must be between 18 and 100.");
    }
    return true;
}

bool BankingSystem::validateName(const MyString& name) {
    for (size_t i = 0; i < name.getSize(); ++i) {
        char c = name[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            return false;
        }
    }
    return true;
}

bool BankingSystem::ClientExists(const MyString& egn) const {
    return findClientByEgn(egn) != clients.size();
}

bool BankingSystem::ThirdPartyEmployeeExists(const MyString& egn) const {
    return findThirdPartyEmployeeByEgn(egn) != thirdPartyEmployees.size();
}

bool BankingSystem::BankEmployeeExists(const MyString& egn, const MyString& bankName) const {
    size_t bankIndex = findBankByName(bankName);
    if (bankIndex == banks.size()) {
        return false;
    }
    return banks[bankIndex].employeeExistsByEgn(egn);
}

LoggedInUserType BankingSystem::getLoggedInUserType() const {
    return loggedInUserType;
}

User* BankingSystem::getLoggedInUser() const {
    return loggedInUser;
}

void BankingSystem::addBank(const Bank& bank) {
    banks.push_back(bank);
}

void BankingSystem::addClient(const Client& client) {
    clients.push_back(client);
}

void BankingSystem::addBankEmployee(const BankEmployee& employee, const MyString& bankName) {
    size_t bankIndex = findBankByName(bankName);
    if (bankIndex != banks.size()) {
        banks[bankIndex].addEmployee(employee);
    }
    else {
        throw std::runtime_error("Bank not found.");
    }
}

void BankingSystem::addThirdPartyEmployee(const ThirdPartyEmployee& thirdPartyEmployee) {
    thirdPartyEmployees.push_back(thirdPartyEmployee);
}

size_t BankingSystem::getCounterOfBanks() const {
    return banks.size();
}

void BankingSystem::createBank(const MyString& bankName) {
    if (findBankByName(bankName) != banks.size()) {
        throw std::runtime_error("Bank with this name already exists.");
    }
    banks.push_back(Bank(bankName));
    std::cout << "Bank " << bankName.c_str() << " created.\n\n";
}

void BankingSystem::signupClient(const MyString& name, const MyString& surname, const MyString& egn, int age, const MyString& password) {
    if (!validateEgn(egn) || !validateAge(age) || !validateName(name) || !validateName(surname)) {
        throw std::invalid_argument("Invalid input.");
    }
    if (ClientExists(egn) || ThirdPartyEmployeeExists(egn) || BankEmployeeExists(egn, name)) {
        throw std::runtime_error("User with this EGN already exists.");
    }
    clients.push_back(Client(name, surname, egn, password, age));
    std::cout << "  Client " << name.c_str() << " " << surname.c_str() << " signed up.\n\n";
}

void BankingSystem::signupBankEmployee(const MyString& name, const MyString& surname, const MyString& egn, int age, const MyString& password, const MyString& bankName) {
    if (!validateEgn(egn) || !validateAge(age) || !validateName(name) || !validateName(surname)) 
    {
        throw std::invalid_argument("Invalid input.");
    }
    else if (ClientExists(egn) || ThirdPartyEmployeeExists(egn) || BankEmployeeExists(egn, bankName)) 
        {
            throw std::runtime_error("User with this EGN already exists.");
        }
        size_t bankIndex = findBankByName(bankName);
    if (bankIndex < banks.size()) 
    {
            BankEmployee employee(name, surname, egn, password, age, bankName);
            banks[bankIndex].addEmployee(employee);
            std::cout << "  Bank employee " << name.c_str() << " " << surname.c_str() << " signed up.\n\n";
     }
        else 
    {
            throw std::runtime_error("Bank not found.");
    }
}


void BankingSystem::signupThirdPartyEmployee(const MyString& name, const MyString& surname, const MyString& egn, int age, const MyString& password) 
{
    if (!validateEgn(egn) || !validateAge(age) || !validateName(name) || !validateName(surname)) {
        throw std::invalid_argument("Invalid input.");
   
    }
    if (ClientExists(egn) || ThirdPartyEmployeeExists(egn) || BankEmployeeExists(egn, name)) {
        throw std::runtime_error("User with this EGN already exists.");
    }
    thirdPartyEmployees.push_back(ThirdPartyEmployee(name, surname, egn, password, age));
    std::cout << "  Third-party employee " << name.c_str() << " " << surname.c_str() << " signed up.\n\n";
}

bool BankingSystem::login(const MyString& egn, const MyString& password) {
    size_t clientIndex = findClientByEgn(egn);
    if (clientIndex != clients.size() && clients[clientIndex].validatePassword(password)) {
        loggedInUser = &clients[clientIndex];
        loggedInUserType = LoggedInUserType::Client;
        std::cout << "\n  Logged in as client " << loggedInUser->getName().c_str() << " " << loggedInUser->getSurname().c_str() << ".\n";
        return true;
    }

    size_t thirdPartyEmployeeIndex = findThirdPartyEmployeeByEgn(egn);
    if (thirdPartyEmployeeIndex != thirdPartyEmployees.size() && thirdPartyEmployees[thirdPartyEmployeeIndex].validatePassword(password)) {
        loggedInUser = &thirdPartyEmployees[thirdPartyEmployeeIndex];
        loggedInUserType = LoggedInUserType::ThirdPartyEmployee;
        std::cout << "\n  Logged in as third-party employee " << loggedInUser->getName().c_str() << " " << loggedInUser->getSurname().c_str() << ".\n";
        return true;
    }

    size_t bankIndex = findBankEmployeeByEgn(egn);
    if (bankIndex != banks.size()) {
        Bank& bank = banks[bankIndex];
        const MyVector<BankEmployee>& employees = bank.getEmployees();
        for (size_t i = 0; i < employees.size(); ++i) {
            if (employees[i].getEgn() == egn && employees[i].validatePassword(password)) {
                loggedInUser = const_cast<BankEmployee*>(&employees[i]); // Assuming mutable access is required
                loggedInUserType = LoggedInUserType::BankEmployee;
                std::cout << "\n  Logged in as bank employee " << loggedInUser->getName().c_str() << " " << loggedInUser->getSurname().c_str() << " from bank " << bank.getName().c_str() << ".\n";
                return true;
            }
        }

        throw std::runtime_error("Invalid EGN or password.");
    }
    return false;
}
void BankingSystem::logout() {
    if (loggedInUser) {
        std::cout << "  Logged out from " << loggedInUser->getName().c_str() << " " << loggedInUser->getSurname().c_str() << ".\n\n";
        loggedInUser = nullptr;
        loggedInUserType = LoggedInUserType::None;
    }
    else {
        throw std::runtime_error("No user is currently logged in.\n");
    }
}

void BankingSystem::showLoggedInUser() const {
    if (loggedInUser) {
        std::cout << "  Logged in as " << loggedInUser->getName().c_str() << " " << loggedInUser->getSurname().c_str() << ".\n\n";
    }
    else {
        throw std::runtime_error("No user is currently logged in.\n");
    }
}

bool BankingSystem::accountExistsById(const MyString& bankName, int accountId) const {
    size_t bankIndex = findBankByName(bankName);
    if (bankIndex == banks.size()) {
        return false;
    }
    return banks[bankIndex].accountExistsById(accountId);
}

User* BankingSystem::getUserByEgn(const MyString& egn) {
    size_t clientIndex = findClientByEgn(egn);
    if (clientIndex != clients.size()) {
        return &clients[clientIndex];
    }

    size_t thirdPartyEmployeeIndex = findThirdPartyEmployeeByEgn(egn);
    if (thirdPartyEmployeeIndex != thirdPartyEmployees.size()) {
        return &thirdPartyEmployees[thirdPartyEmployeeIndex];
    }

    for (size_t i = 0; i < banks.size(); ++i) {
        BankEmployee* employee = banks[i].findEmployeeByEgn(egn);
        if (employee != nullptr) {
            return employee;
        }
    }

    throw std::runtime_error("User not found.");
}

Client* BankingSystem::getClientByEgn(const MyString& egn) {
    size_t clientIndex = findClientByEgn(egn);
    if (clientIndex != clients.size()) {
        return &clients[clientIndex];
    }
    throw std::runtime_error("Client not found.");
}

ThirdPartyEmployee* BankingSystem::getThirdPartyEmployeeByEgn(const MyString& egn) {
    size_t thirdPartyEmployeeIndex = findThirdPartyEmployeeByEgn(egn);
    if (thirdPartyEmployeeIndex != thirdPartyEmployees.size()) {
        return &thirdPartyEmployees[thirdPartyEmployeeIndex];
    }
    throw std::runtime_error("Third-party employee not found.");
}

Bank* BankingSystem::getBankByName(const MyString& bankName) {
    size_t bankIndex = findBankByName(bankName);
    if (bankIndex != banks.size()) {
        return &banks[bankIndex];
    }
    throw std::runtime_error("Bank not found.");
}

BankEmployee* BankingSystem::getBankEmployeeByEgn(const MyString& egn) {
    for (size_t i = 0; i < banks.size(); ++i) {
        BankEmployee* employee = banks[i].findEmployeeByEgn(egn);
        if (employee != nullptr) {
            return employee;
        }
    }
    return nullptr;
}


void BankingSystem::validateChangeTask(ChangeTask& changeTask) {
    MyString oldBankName = changeTask.getOldBankName();
    int accountId = changeTask.getAccountId();
    Bank* oldBank = getBankByName(oldBankName);

    if (oldBank && oldBank->accountExistsById(accountId)) {
        changeTask.setStatus(Status::Approved);
        std::cout << "ChangeTask validated and approved for account ID " << accountId << ".\n";
    }
    else {
        changeTask.setStatus(Status::Rejected);
        throw std::runtime_error("ChangeTask validation failed. Account not found in old bank.\n");
    }
}