#include "ThirdPartyEmployeeCommand.h"

    void SendCheckCommand::execute(BankingSystem& system) {
        try {
            MyString egn;
            double sum;
            MyString verificationCode;


            std::cin >> sum;
            std::cin >> verificationCode;
            std::cin >> egn;
             

            if (verificationCode.getSize() != 3) {
                throw std::runtime_error("Verification code must be exactly 3 characters.");
            }

            if (!isValidCode(verificationCode)) {
                throw std::runtime_error("Verification code must contain only digits, lowercase and uppercase Latin letters.");
            }

            Client* client = system.getClientByEgn(egn);
            if (!client) {
                throw std::runtime_error("Client does not exist.");
            }

            Cheque cheque(verificationCode, sum);
            client->addCheque(cheque);
            MyString message = "You have a check assigned to you.";
            client->addMessage(message);

            std::cout << "Cheque sent successfully.\n\n";
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }


bool SendCheckCommand::isValidCode(const MyString& code) {
    for (size_t i = 0; i < code.getSize(); ++i) {
        char c = code[i];
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            return false;
        }
    }
    return true;
}
