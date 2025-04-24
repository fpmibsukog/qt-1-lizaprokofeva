#include "Info.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QString>

Info::Info(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Info");
    layout = new QVBoxLayout(this);
    detailsLabel = new QLabel(this);
    detailsLabel->setWordWrap(true);
    layout->addWidget(detailsLabel);
}

void Info::setDetails(const std::shared_ptr<Book>& book, const std::shared_ptr<User>& user)
{
    QString info;
    if (book) {
        info += QString("Book Details:\n")
              + QString("Title: %1\n").arg(QString::fromStdString(book->getTitle()))
              + QString("Author: %1\n").arg(QString::fromStdString(book->getAuthor()))
              + QString("Year: %1\n\n").arg(book->getYear());
    }
    if (user) {
        info += QString("User Details:\n")
              + QString("ID: %1\n").arg(user->getId())
              + QString("Name: %1").arg(QString::fromStdString(user->getName()));
              if (!user->borrowedBooks.empty()) {
                info += "\nBorrowed Books:\n";
                for (const auto& b : user->borrowedBooks) {
                    info += QString("%1, %2, %3\n")
                            .arg(QString::fromStdString(b->getTitle()))
                            .arg(QString::fromStdString(b->getAuthor()))
                            .arg(b->getYear());
                }
            } else {
                info += "\nNo borrowed books.\n";
            }
        }
    detailsLabel->setText(info);
}
