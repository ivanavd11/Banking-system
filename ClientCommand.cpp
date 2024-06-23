#include "ClientCommand.h"
#include "BankingSystem.h"

void CheckBalanceCommand::execute(BankingSystem& system) {
    try {
        MyString bankName;
        int accountId;
        std::cin >> bankName;
        std::cin >> accountId;

        Bank* bank = system.getBankByName(bankName);
        if (!bank) {
            throw std::runtime_error("Bank does not exist.");
        }
        Account* account = bank->findAccountById(accountId);
        if (!account) {
            throw std::runtime_error("Account does not exist.\n");
        }
        std::cout << "Balance for account " << accountId << " in bank " << bankName.c_str() <<
                     " is: " << account->getBalance() << "$\n\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void OpenAccountCommand::execute(BankingSystem& system) {
    try {
        MyString bankName;
        std::cin >> bankName;

        Bank* bank = system.getBankByName(bankName);
        if (!bank) {
            throw std::runtime_error("Bank does not exist.");
        }
        bank->handleOpenAccountRequest(client->getName(), client->getSurname(), client->getEgn(), 0.0);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void CloseAccountCommand::execute(BankingSystem& system) {
    try {
        MyString bankName;
        int accountId;
        std::cin >> bankName;
        std::cin >> accountId;

        Bank* bank = system.getBankByName(bankName);
        if (!bank) {
            throw std::runtime_error("Bank does not exist.");
        }
        bank->handleCloseAccountRequest(accountId);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void RedeemChequeCommand::execute(BankingSystem& system) {
    try {
        MyString bankName;
        int accountId;
        MyString verificationCode;

        std::cin >> bankName;
        std::cin >> accountId;
        std::cin >> verificationCode;

        Bank* bank = system.getBankByName(bankName);
        if (!bank) {
            throw std::runtime_error("Bank does not exist.");
        }

        Account* account = bank->findAccountById(accountId);
        if (!account) {
            throw std::runtime_error("Account does not exist.");
        }

        double amount = client->redeemCheque(verificationCode);
        if (amount > 0) {
            account->deposit(amount);
            std::cout << "Cheque redeemed successfully.\n\n";

            client->removeCheque(verificationCode);
        }
        else {
            throw std::runtime_error("Cheque redemption failed.\n");
        }


    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void ChangeBankCommand::execute(BankingSystem& system) {
    try {
        MyString newBankName;
        MyString currentBankName;
        int accountId;

        std::cin >> newBankName;
        std::cin >> currentBankName;
        std::cin >> accountId;

        Bank* currentBank = system.getBankByName(currentBankName);
        Bank* newBank = system.getBankByName(newBankName);
        if (!currentBank || !newBank) {
            throw std::runtime_error("One of the banks does not exist.");
        }
        currentBank->handleChangeAccountRequest(accountId, newBankName, currentBankName);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void ListAccountsCommand::execute(BankingSystem& system) {
    try {
        MyString bankName;

        std::cin >> bankName;

        Bank* bank = system.getBankByName(bankName);
        if (!bank) {
            throw std::runtime_error("Bank does not exist.");
        }
        bank->displayAccounts();
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void ShowMessagesCommand::execute(BankingSystem& system) {
    try {
        client->showMessages();
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}