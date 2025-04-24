#include "Library.h"
#include <iostream>
#include <algorithm>

void Library::addBook(const std::shared_ptr<Book>& book) {
    books.push_back(book);
}
void Library::removeBook(const std::string &title) {
    books.erase(std::remove_if(books.begin(), books.end(),
                               [&title](const std::shared_ptr<Book>& b){
                                   return b->getTitle() == title;
                               }),
                books.end());
}
void Library::displayBooks() const {
    std::cout << "Library books (" << books.size() << "):" << std::endl;
    for (const auto &book : books) {
        book->print();
    }
}
std::weak_ptr<Book> Library::findBook(const std::string &title, const std::string &author) const {
    for (const auto &book : books) {
        if ((title.empty() || book->getTitle() == title) &&
            (author.empty() || book->getAuthor() == author)) {
            return book;  
        }
    }
    return std::weak_ptr<Book>{};
}
void Library::addUser(const std::shared_ptr<User>& user) {
    users.push_back(user);
}

void Library::removeUser(int userId) {
    users.erase(std::remove_if(users.begin(), users.end(),
                               [userId](const std::shared_ptr<User>& u){
                                   return u->getId() == userId;
                               }),
                users.end());
}

void Library::lendBook(const std::string &bookTitle, int userId) {
    auto bookId = std::find_if(books.begin(), books.end(),
                               [&bookTitle](const std::shared_ptr<Book>& b) {
                                   return b->getTitle() == bookTitle;
                               });
    if (bookId == books.end()) {
        std::cout << "Book \"" << bookTitle << "\" not found in library" << std::endl;
        return;
    }
    
    auto userID= std::find_if(users.begin(), users.end(),
                               [userId](const std::shared_ptr<User>& u) {
                                   return u->getId() == userId;
                               });
    if (userID == users.end()) {
        std::cout << "User with ID " << userId << " not found." << std::endl;
        return;
    }
    
    (*userID)->borrowedBooks.push_back(*bookId);
    std::cout << "Lending book \"" << bookTitle << "\" to user \"" << (*userID)->getName() << "\"." << std::endl;
    books.erase(bookId);
}

void Library::displayUsers() const {
    std::cout << "\nLibrary Users (" << users.size() << " ):" << std::endl;
    for (const auto &user : users) {
        user->print();
        std::cout << std::endl;
    }
}
