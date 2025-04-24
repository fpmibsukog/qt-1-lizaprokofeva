#include "User.h"
#include <iostream>
User::User(const std::string &name_, int id_) : name(name_), id(id_) {}

std::string User::getName() const {
    return name;
}

int User::getId() const {
    return id;
}

void User::print() const {
    std::cout << "User ID: " << id << ", Name: " << name << std::endl;
    if (borrowedBooks.empty()) {
        std::cout << " No borrowed books." << std::endl;
    } else {
        std::cout << " Borrowed books:" << std::endl;
        for (const auto &book : borrowedBooks) {
            std::cout << "    ";
            book->print();
        }
    }
}
