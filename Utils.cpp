#include "Utils.h"
#include <iostream>

void printBook(std::unique_ptr<Book> bookPtr) {
    if (bookPtr) {
        std::cout << " Book Info:" << std::endl;
        bookPtr->print();
        std::cout << std::endl;
    }
}

void createAndPrintUniqueBook() {
    auto bookPtr = std::make_unique<Book>("1984", "George Orwell", 1949);
    printBook(std::move(bookPtr));
}
