#include "Book.h"
Book::Book(const std::string &title_, const std::string &author_, int year_)
    : title(title_), author(author_), year(year_) {}
std::string Book::getTitle() const {
    return title;
}
std::string Book::getAuthor() const {
    return author;
}
int Book::getYear() const {
    return year;
}
void Book::print() const {
    std::cout << "Title: " << title 
              << ", Author: " << author 
              << ", Year: " << year << std::endl;
}
