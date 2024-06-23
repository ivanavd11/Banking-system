#include "BankEmployeeCommand.h"
#include "BankingSystem.h"
#include "OpenTask.h"
#include "CloseTask.h"
#include "ChangeTask.h"
#include <iostream>

void ViewTasksCommand::execute(BankingSystem& system) {
    try {
        bankEmployee->listTasks();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void ViewTaskDetailsCommand::execute(BankingSystem& system) {
    try {
        int taskId;
        std::cin >> taskId;
        Task* task = bankEmployee->findTaskById(taskId);
        if (task) {
            task->displayWithDescription();
        }
        else {
            throw std::runtime_error( "Task not found.\n");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void ApproveTaskCommand::execute(BankingSystem& system) {
    try {
        int taskId;
        std::cin >> taskId;
        Task* task = bankEmployee->findTaskById(taskId);
        if (task->getType() == TaskType::OPEN)
        {
            OpenTask* openTask = static_cast<OpenTask*>(task);
            if (openTask) {
                MyString clientName = openTask->getClientName();
                MyString clientSurname = openTask->getClientSurname();
                MyString clientEgn = openTask->getClientEgn();
                MyString bankName = openTask->getBankName();
                double initialBalance = 0.0; 

                Bank* bank = system.getBankByName(bankName);
                if (bank) {
                    Account newAccount(bankName, clientName, clientSurname, clientEgn, initialBalance);
                    bank->addAccount(newAccount);
                    system.getClientByEgn(clientEgn)->addMessage("You opened an account in " + bankName + ".");
                    std::cout << "Account created for " << clientName.c_str() << " " << clientSurname.c_str() << " in bank " << bankName.c_str() << "\n\n";
                    bankEmployee->removeTaskById(taskId);
                }
                else {
                    throw std::runtime_error( "Bank not found.\n");
                }
            }
        }
        else {
            throw std::runtime_error("Task does not support approve operation.\n");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void DisapproveTaskCommand::execute(BankingSystem& system) {
    try {
        int taskId;
        MyString message;
        std::cin >> taskId;
        std::cin >> message;
        Task* task = bankEmployee->findTaskById(taskId);
        if (task) {
            MyString clientName = task->getClientName();
            MyString clientSurname = task->getClientSurname();
            MyString clientEgn = task->getClientEgn();
            MyString bankName = task->getBankName();

            // Remove the task from the bankEmployee's task list
            bankEmployee->removeTaskById(taskId);

            // Send disapproval message to the client
            Client* client = system.getClientByEgn(clientEgn);
            if (client) {
                MyString disapprovalMessage = "Your Close request was not approved. Reason: " + message;
                client->addMessage(disapprovalMessage);
                std::cout << "\nDisapproval message sent to client " << clientName.c_str() << " " 
                          << clientSurname.c_str() << ".\n\n";
                bankEmployee->removeTaskById(taskId);
            }
            else {
                throw std::runtime_error( "Client not found.\n");
            }
        }
        else {
            throw std::runtime_error( "Task does not support disapprove operation.\n");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
void ValidateTaskCommand::execute(BankingSystem& system) {
    try {
        int taskId;
        std::cin >> taskId;
        Task* task = bankEmployee->findTaskById(taskId);
        ChangeTask* changeTask = dynamic_cast<ChangeTask*>(task);
        if (changeTask) {
            system.validateChangeTask(*changeTask);
        }
        else {
            throw std::runtime_error( "Task is not a ChangeTask.\n");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}