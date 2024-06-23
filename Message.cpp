#include "Message.h"
#include <iostream>

Message::Message(const MyString& content) : content(content) {}

MyString Message::getContent() const {
    return content;
}

void Message::display() const {
    std::cout << content << std::endl;
}
