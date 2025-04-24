#ifndef UTILS_H
#define UTILS_H
#include <memory>
#include "Book.h"
void printBook(std::unique_ptr<Book> bookPtr);
void createAndPrintUniqueBook();
#endif // UTILS_H
