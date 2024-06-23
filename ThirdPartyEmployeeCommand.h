#pragma once
#include "Command.h"

class SendCheckCommand : public ThirdPartyEmployeeCommand {
public:
    SendCheckCommand(ThirdPartyEmployee* thirdPartyEmployee)
        : ThirdPartyEmployeeCommand(thirdPartyEmployee) {}

    void execute(BankingSystem& system) override;

    Command* clone() const override {
        return new SendCheckCommand(*this);
    }
private:
    bool isValidCode(const MyString& code);
};
