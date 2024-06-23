#pragma once
#include "User.h"
#include "Task.h"

#include "MyVector.hpp"
#include "polymorphic_ptr.hpp"

class BankEmployee : public User {
private:
    MyString workplaceName;
    MyVector<polymorphic_ptr<Task>> tasks;

public:
    BankEmployee() = default;
    BankEmployee(const MyString& name, const MyString& surname, const MyString& egn, const MyString& password, int age, const MyString& workplaceName);

    void addTask(Task* task);
    size_t getTaskCount() const;
    const MyVector<polymorphic_ptr<Task>>& getTasks() const;
    void listTasks() const;
    void viewTask(int taskId);

    Task* findTaskById(int taskId);
    void removeTaskById(int taskId);
    MyString getWorkplaceName() const;

    void display() const override;
    User* clone() const override;
};