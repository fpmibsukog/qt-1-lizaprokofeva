#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include <string>
#include "Book.h"
#include "User.h"
#include "Utils.h"


class Library {
private:
    std::vector<std::shared_ptr<Book>> books;
    std::vector<std::shared_ptr<User>> users;
public:
    void addBook(const std::shared_ptr<Book>& book);
    void removeBook(const std::string &title);
    void displayBooks() const;
    std::weak_ptr<Book> findBook(const std::string &title, const std::string &author) const;
    void addUser(const std::shared_ptr<User>& user);
    void removeUser(int userId);
    // Метод выдачи книги (удаляет книгу из списка и добавляет её пользователю)
    void lendBook(const std::string &bookTitle, int userId);
    void displayUsers() const;
    const std::vector<std::shared_ptr<Book>>& getBooks() const { return books; }
    const std::vector<std::shared_ptr<User>>& getUsers() const { return users; }
};

#endif // LIBRARY_H
