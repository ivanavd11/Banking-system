#pragma once
#include "BankingSystem.h"

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(BankingSystem& system) = 0;
    virtual Command* clone() const = 0;
};

class ClientCommand : public Command {
protected:
    Client* client;

public:
    ClientCommand(Client* client) : client(client) {}
};

class BankEmployeeCommand : public Command {
protected:
    BankEmployee* bankEmployee;

public:
    BankEmployeeCommand(BankEmployee* bankEmployee) : bankEmployee(bankEmployee) {}
};

class ThirdPartyEmployeeCommand : public Command {
protected:
    ThirdPartyEmployee* employee;

public:
    ThirdPartyEmployeeCommand(ThirdPartyEmployee* employee) : employee(employee) {}
};

class SystemCommand : public Command {
protected:
    BankingSystem* system;

public:
    SystemCommand(BankingSystem* system) : system(system) {}

};