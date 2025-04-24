#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

class Book {
    private:
        std::string title;
        std::string author;
        int year;
    public:
        Book(const std::string &title_, const std::string &author_, int year_);
        std::string getTitle() const;
        std::string getAuthor() const;
        int getYear() const;
        void print() const;
    };
#endif // BOOK_H
