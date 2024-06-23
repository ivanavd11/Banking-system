#include <iostream>
#include "BankingSystem.h"
#include "ClientCommand.h"
#include "BankEmployeeCommand.h"
#include "ThirdPartyEmployeeCommand.h"
#include "SystemCommand.h"

void showHelp() {
    std::cout << "  Available commands:\n";
    std::cout << "create_bank [bank_name] - Create a new bank\n";
    std::cout << "signup - Sign up a new user\n";
    std::cout << "login - Log in to the system\n";
    std::cout << "exit - Log out from the current profile\n";
    std::cout << "whoami - Show current user information\n";
    std::cout << "help - Show this help menu\n\n";
}

void displayClientHelp() {
    std::cout << "  Client commands:\n"
        << "check_avl [bank_name] [account_number]\n"
        << "open [bank_name]\n"
        << "close [bank_name] [account_number]\n"
        << "redeem [bank_name] [account_number] [verification_code]\n"
        << "change [new_bank_name] [current_bank_name] [account_number]\n"
        << "list [bank_name]\n"
        << "messages\n"
        << "exit\n"
        << "whoami\n"
        << "help\n\n";
}

void displayBankEmployeeHelp() {
    std::cout << "  Bank Employee commands:\n"
        << "tasks\n"
        << "view [task_id]\n"
        << "approve [task_id]\n"
        << "disapprove [task_id] [message]\n"
        << "validate [task_id]\n"
        << "exit\n"
        << "whoami\n"
        << "help\n\n";
}

void displayThirdPartyEmployeeHelp() {
    std::cout << "  Third-party Employee commands:\n"
        << "send_check [sum] [verification_code] [egn]\n"
        << "exit\n"
        << "whoami\n"
        << "help\n\n";
}

void handleSignup(BankingSystem& system) {
    MyString name, surname, egn, password;
    int age;
    MyString role;
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Surname: ";
    std::cin >> surname;
    std::cout << "EGN: ";
    std::cin >> egn;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Role: ";
    std::cin.ignore();
    char buffer[100];
    std::cin.getline(buffer, 100);
    role = buffer;
    std::cout << "Password: ";
    std::cin >> password;

    try {
        if (role == "Client" || role == "client") {
            system.signupClient(name, surname, egn, age, password);
        }
        else if (role == "Employee" || role == "employee") {
            MyString bankName;
            std::cout << "Bank associated: ";
            std::cin >> bankName;
            system.signupBankEmployee(name, surname, egn, age, password, bankName);
        }
        else if (role == "Third-party employee" || role == "third-party employee") {
            system.signupThirdPartyEmployee(name, surname, egn, age, password);
        }
        else {
            std::cerr << "Invalid input.\n\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n\n";
    }
}

void processClientCommand(BankingSystem& system, const MyString& command) {
    try {
        Client* client = static_cast<Client*>(system.getLoggedInUser());
        if (command == "check_avl") {

            CheckBalanceCommand cmd(client);
            cmd.execute(system);
        }
        else if (command == "open") {
            
            OpenAccountCommand cmd(client);
            cmd.execute(system);
        }
        else if (command == "close") {
            
            CloseAccountCommand cmd(client);
            cmd.execute(system);
        }
        else if (command == "redeem") {
            RedeemChequeCommand cmd(client);
            cmd.execute(system);
        }
        else if (command == "change") {
            ChangeBankCommand cmd(client);
            cmd.execute(system);
        }
        else if (command == "list") {
            ListAccountsCommand cmd(client);
            cmd.execute(system);
        }
        else if (command == "messages") {
            ShowMessagesCommand cmd(client);
            cmd.execute(system);
        }
        else if (command == "exit") {
            system.logout();
        }
        else if (command == "whoami") {
            system.showLoggedInUser();
        }
        else if (command == "help") {
            displayClientHelp();
        }
        else {
            std::cerr << "Unknown command.\n\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n\n";
    }
}

void processBankEmployeeCommand(BankingSystem& system, const MyString& command) {
    try {
        BankEmployee* bankEmployee = static_cast<BankEmployee*>(system.getLoggedInUser());
        if (command == "tasks") {
            ViewTasksCommand cmd(bankEmployee);
            cmd.execute(system);
        }
        else if (command == "view") {
            ViewTaskDetailsCommand cmd(bankEmployee);
            cmd.execute(system);
        }
        else if (command == "approve") {
            ApproveTaskCommand cmd(bankEmployee);
            cmd.execute(system);
        }
        else if (command == "disapprove") {
            DisapproveTaskCommand cmd(bankEmployee);
            cmd.execute(system);
        }
        else if (command == "validate") {
            ValidateTaskCommand cmd(bankEmployee);
            cmd.execute(system);
        }
        else if (command == "exit") {
            system.logout();
        }
        else if (command == "whoami") {
            system.showLoggedInUser();
        }
        else if (command == "help") {
            displayBankEmployeeHelp();
        }
        else {
            std::cerr << "Unknown command.\n\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n\n";
    }
}

void processThirdPartyEmployeeCommand(BankingSystem& system, const MyString& command) {
    try {
        ThirdPartyEmployee* thirdPartyEmployee = static_cast<ThirdPartyEmployee*>(system.getLoggedInUser());
        if (command == "send_check") {
            SendCheckCommand cmd(thirdPartyEmployee);
            cmd.execute(system);
        }
        else if (command == "exit") {
            system.logout();
        }
        else if (command == "whoami") {
            system.showLoggedInUser();
        }
        else if (command == "help") {
            displayThirdPartyEmployeeHelp();
        }
        else {
            std::cerr << "Unknown command.\n\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n\n";
    }
}

void handleLogin(BankingSystem& system) {
    MyString egn, password;
    std::cout << "EGN: ";
    std::cin >> egn;
    std::cout << "Password: ";
    std::cin >> password;

    try {
        if (system.login(egn, password)) {
            if (system.getLoggedInUserType() == LoggedInUserType::Client) {
                
                displayClientHelp();
                while (true) 
                {
                    std::cout << "> ";
                    MyString command;
                    std::cin >> command;
                    processClientCommand(system, command);
                    if (system.getLoggedInUserType() == LoggedInUserType::None)
                    {
                        break;
                    }
                }
            }
            else if (system.getLoggedInUserType() == LoggedInUserType::BankEmployee) {
                
                displayBankEmployeeHelp();
                while (true)
                {
                    
                    std::cout << "> ";
                    MyString command;
                    std::cin >> command;

                    processBankEmployeeCommand(system, command);
                    if (system.getLoggedInUserType() == LoggedInUserType::None)
                    {
                        break;
                    }
                }
            }
            else if (system.getLoggedInUserType() == LoggedInUserType::ThirdPartyEmployee) {
                
                displayThirdPartyEmployeeHelp();
                while (true)
                {
                    
                    std::cout << "> ";
                    MyString command;
                    std::cin >> command;
                    processThirdPartyEmployeeCommand(system, command);
                    if (system.getLoggedInUserType() == LoggedInUserType::None)
                    {
                        break;
                    }
                }
            }
            else if(system.getLoggedInUserType() == LoggedInUserType::None)
            {
                showHelp();
            }
        }
        else {
            std::cerr << "Invalid input or no user with this data.\n\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n\n";
    }
}

void handleCommands(BankingSystem& system) {
    MyString command;
    while (true) {
        std::cout << "> ";
        std::cin >> command;
        if (command == "create_bank") {
            MyString bankName;
            std::cin >> bankName;
            try {
                system.createBank(bankName);
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
        }
        else if (command == "signup") {
            handleSignup(system);
        }
        else if (command == "login") {
            handleLogin(system);

        }
        else if (command == "exit") {
            system.logout();
        }
        else if (command == "whoami") {
            system.showLoggedInUser();
        }
        else if (command == "help") {
            showHelp();
        }
        else {
            std::cerr << "Unknown command. Type 'help' to see the list of available commands.\n\n";
        }
    }
}

int main() {
    BankingSystem system;

    std::cout << "Welcome to the Banking System!\n";
    showHelp();
    handleCommands(system);

    return 0;
}