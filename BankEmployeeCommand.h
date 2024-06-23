#pragma once
#include "Command.h"
#include "BankEmployee.h"
#include "ChangeTask.h"

class ViewTasksCommand : public BankEmployeeCommand {
public:
    ViewTasksCommand(BankEmployee* bankEmployee)
        : BankEmployeeCommand(bankEmployee) {}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new ViewTasksCommand(*this);
    }
};

class ViewTaskDetailsCommand : public BankEmployeeCommand {
public:
    ViewTaskDetailsCommand(BankEmployee* bankEmployee)
        : BankEmployeeCommand(bankEmployee){}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new ViewTaskDetailsCommand(*this);
    }
};

class ApproveTaskCommand : public BankEmployeeCommand {
public:
    ApproveTaskCommand(BankEmployee* bankEmployee)
        : BankEmployeeCommand(bankEmployee) {}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new ApproveTaskCommand(*this);
    }
};

class DisapproveTaskCommand : public BankEmployeeCommand {
public:
    DisapproveTaskCommand(BankEmployee* bankEmployee)
        : BankEmployeeCommand(bankEmployee) {}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new DisapproveTaskCommand(*this);
    }
};

class ValidateTaskCommand : public BankEmployeeCommand {
public:
    ValidateTaskCommand(BankEmployee* bankEmployee)
        : BankEmployeeCommand(bankEmployee) {}

    void execute(BankingSystem& system) override;
    Command* clone() const override {
        return new ValidateTaskCommand(*this);
    }
};