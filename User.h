#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include <memory>
#include "Book.h"

class User {
private:
    std::string name;
    int id;
public:
    std::vector<std::shared_ptr<Book>> borrowedBooks;

    User(const std::string &name_, int id_);
    std::string getName() const;
    int getId() const;
    void print() const;
};

#endif // USER_H
