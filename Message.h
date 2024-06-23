#pragma once
#include "MyString.h"

class Message {
private:
    MyString content;

public:
    Message() = default;
    Message(const MyString& content);

    MyString getContent() const;
    void display() const;
};

