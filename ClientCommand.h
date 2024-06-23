#pragma once
#include "Command.h"

class CheckBalanceCommand : public ClientCommand {
public:
    CheckBalanceCommand(Client* client)
        : ClientCommand(client) {}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new CheckBalanceCommand(*this);
    }
};

class OpenAccountCommand : public ClientCommand {
public:
    OpenAccountCommand(Client* client)
        : ClientCommand(client) {}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new OpenAccountCommand(*this);
    }
};

class CloseAccountCommand : public ClientCommand {
public:
    CloseAccountCommand(Client* client)
        : ClientCommand(client) {}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new CloseAccountCommand(*this);
    }
};

class RedeemChequeCommand : public ClientCommand {
public:
    RedeemChequeCommand(Client* client)
        : ClientCommand(client) {}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new RedeemChequeCommand(*this);
    }
};

class ChangeBankCommand : public ClientCommand {
public:
    ChangeBankCommand(Client* client)
        : ClientCommand(client) {}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new ChangeBankCommand(*this);
    }
};

class ListAccountsCommand : public ClientCommand {
public:
    ListAccountsCommand(Client* client)
        : ClientCommand(client) {}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new ListAccountsCommand(*this);
    }
};

class ShowMessagesCommand : public ClientCommand {
public:
    ShowMessagesCommand(Client* client)
        : ClientCommand(client) {}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new ShowMessagesCommand(*this);
    }
};