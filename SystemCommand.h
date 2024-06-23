#pragma once
#include "Command.h"
#include "BankingSystem.h"
#include "MyString.h"

class LoginCommand : public SystemCommand {
public:
    LoginCommand(BankingSystem* system)
        : SystemCommand(system) {}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new LoginCommand(*this);
    }
};

class SignupCommand : public SystemCommand {
public:
    SignupCommand(BankingSystem* system)
        : SystemCommand(system) {}

    void execute(BankingSystem& system) override;

    Command* clone() const override {
        return new SignupCommand(*this);
    }
};

class CreateBankCommand : public SystemCommand {
public:
    CreateBankCommand(BankingSystem* system)
        : SystemCommand(system) {}

    void execute(BankingSystem& system) override;

    Command* clone() const override {
        return new CreateBankCommand(*this);
    }
};
