#include "BankEmployee.h"
#include "ChangeTask.h"
#include <iostream>

BankEmployee::BankEmployee(const MyString& name, const MyString& surname, const MyString& egn, const MyString& password, int age, const MyString& workplaceName)
    : User(name, surname, egn, password, age), workplaceName(workplaceName) {}

void BankEmployee::addTask(Task* task) {
    tasks.push_back(polymorphic_ptr<Task>(task));
}

size_t BankEmployee::getTaskCount() const {
    return tasks.size();
}

const MyVector<polymorphic_ptr<Task>>& BankEmployee::getTasks() const {
    return tasks;
}

void BankEmployee::listTasks() const {
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "[" << i << "] ";
        tasks[i]->display();
    }
}

void BankEmployee::viewTask(int taskId) {
    Task* task = findTaskById(taskId);
    if (task) {
        task->displayWithDescription();
    }
    else {
        std::cerr << "Invalid task ID.\n\n";
    }
}

Task* BankEmployee::findTaskById(int taskId) {
    if ((taskId) < 0 ) {
        return nullptr;
    }
    return tasks[taskId].get();
}

MyString BankEmployee::getWorkplaceName() const {
    return workplaceName;
}

void BankEmployee::display() const {
    std::cout << "Bank Employee: " << name << " " << surname << "\nEGN: " << egn 
              << "\nAge: " << age << "\nWorkplace: " << workplaceName << std::endl;
}
void BankEmployee::removeTaskById(int taskId) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        //if (tasks[i] == taskId) 
        if (i == taskId) {
            tasks.erase(i);
            return;
        }
    }
    throw std::runtime_error("Task not found.");
}

User* BankEmployee::clone() const {
    return new BankEmployee(*this);
}