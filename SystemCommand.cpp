#include "SystemCommand.h"

void LoginCommand::execute(BankingSystem& system) {
    try {
        MyString egn;
        MyString password;

        std::cin >> egn;
        std::cin >> password;

        if (!system.login(egn, password)) {
            throw std::runtime_error("Invalid EGN or password.");
        }
        std::cout << "Login successful.\n\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void SignupCommand::execute(BankingSystem& system) {
    try {
        MyString name;
        MyString surname;
        MyString egn;
        MyString password;
        int age;
        char role;

        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter surname: ";
        std::cin >> surname;
        std::cout << "Enter EGN: ";
        std::cin >> egn;
        std::cout << "Enter age: ";
        std::cin >> age;
        std::cout << "Enter password: ";
        std::cin >> password;
        std::cout << "Enter role (c for client, e for employee, t for third-party): ";
        std::cin >> role;

        switch (role) {
        case 'c':
            system.signupClient(name, surname, egn, age, password);
            break;
        case 'e': {
            MyString bankName;
            std::cout << "Enter bank name: ";
            std::cin >> bankName;
            system.signupBankEmployee(name, surname, egn, age, password, bankName);
            break;
        }
        case 't':
            system.signupThirdPartyEmployee(name, surname, egn, age, password);
            break;
        default:
            throw std::runtime_error("Invalid role.");
        }
        std::cout << "Signup successful.\n\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void CreateBankCommand::execute(BankingSystem& system) {
    try {
        MyString bankName;

        std::cin >> bankName;
        system.createBank(bankName);
        std::cout << "Bank created successfully.\n\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}