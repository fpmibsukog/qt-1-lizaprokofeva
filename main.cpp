#include <iostream>
#include <cstring>
#include "Library.h"
#include "Utils.h" 
#include "Book.h"
#include "User.h"
#include <QApplication>
#include "MainWindow.h"

void Demonstration2();
void Demonstration3();
void Demonstration4();
void Demonstration5();
void Demonstration2() {
    // Создаем объект библиотеки и несколько книг с использованием std::shared_ptr
    Library lib;
    lib.addBook(std::make_shared<Book>("Pride and Prejudice", "Jane Austen", 1813));
    lib.addBook(std::make_shared<Book>("Moby-Dick", "Herman Melville", 1851));
    lib.addBook(std::make_shared<Book>("War and Peace", "Leo Tolstoy", 1869));
    lib.displayBooks();
}
void Demonstration3(){
    Library lib;
    // Демонстрация поиска книги через std::weak_ptr
    lib.addBook(std::make_shared<Book>("Pride and Prejudice", "Jane Austen", 1813));
    lib.addBook(std::make_shared<Book>("Moby-Dick", "Herman Melville", 1851));
    lib.addBook(std::make_shared<Book>("War and Peace", "Leo Tolstoy", 1869));
    auto weakBook = lib.findBook("War and Peace", "Leo Tolstoy");
    if (auto bookPtr = weakBook.lock()) {
        std::cout << "\nFound book with weak_ptr:" << std::endl;
        bookPtr->print();
    } else {
        std::cout << "\nBook not found" << std::endl;
    }
}

void Demonstration4() {
    Library lib;
    lib.addBook(std::make_shared<Book>("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    lib.addBook(std::make_shared<Book>("1984", "George Orwell", 1949));
    lib.addBook(std::make_shared<Book>("To Kill a Mockingbird", "Harper Lee", 1960));
    lib.displayBooks();
    
    lib.addUser(std::make_shared<User>("Liza", 1));
    lib.addUser(std::make_shared<User>("Max", 2));
    
    std::cout << "\nUsers:" << std::endl;
    lib.displayUsers();
    
    lib.lendBook("1984", 1);
    lib.lendBook("The Great Gatsby", 2);
    lib.lendBook("Non Book", 1);
    
    std::cout << "\nLibrary books after lending:" << std::endl;
    lib.displayBooks();
    
    std::cout << "\nUsers after lending:" << std::endl;
    lib.displayUsers();
}

void Demonstration5() {
    Library lib;
    // Создаем книги с использованием std::make_shared и std::allocate_shared
    auto book1 = std::make_shared<Book>("Brave New World", "Aldous Huxley", 1932);
    auto book2 = std::allocate_shared<Book>(std::allocator<Book>(), "Fahrenheit 451", "Ray Bradbury", 1953);
    lib.addBook(book1);
    lib.addBook(book2);

    lib.displayBooks();
    
    // Создаем пользователей с использованием std::make_shared и std::allocate_shared
    auto user1 = std::make_shared<User>("Kate", 3);
    auto user2 = std::allocate_shared<User>(std::allocator<User>(), "Diana", 4);
    lib.addUser(user1);
    lib.addUser(user2);
    lib.displayUsers();
}

int main(int argc, char* argv[])
{

    std::cout << "Part 1: std::unique_ptr Demonstration" << std::endl;
    createAndPrintUniqueBook();
    
    std::cout << "\nPart 2: std::shared_ptr" << std::endl;
    Demonstration2();

    std::cout << "\nPart 3: std::weak_ptr" << std::endl;
    Demonstration3();
    
    std::cout << "\nPart 4: User class and Book Lending Demonstration" << std::endl;
    Demonstration4();
    
    std::cout << "\nPart 5: std::make_shared and std::allocate_shared" << std::endl;
    Demonstration5();

        QApplication app(argc, argv);
        MainWindow mainWindow;
        mainWindow.show();
        return app.exec();
    return 0;
}
