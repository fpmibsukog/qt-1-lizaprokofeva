#include "MainWindow.h"
#include "AddBookDialog.h"
#include "AddUserDialog.h"
#include "SearchBookDialog.h"
#include "Library.h"
#include <QMenuBar>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QAction>
#include <QSplitter>
#include <QStringList>
#include "Book.h"
#include "User.h"
#include "Info.h" 
#include "LendBook.h"     

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      m_booksT(new QTableView(this)),
      m_books(new QStandardItemModel(this)),
      m_usersT(new QTableView(this)),
      m_users(new QStandardItemModel(this))
{
    setWindowTitle("Library");
    setGeometry(250,150,1000,600);
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    QSplitter* splitter = new QSplitter(this);
    m_books->setHorizontalHeaderLabels(QStringList() << "Title" << "Author" << "Year");
    m_booksT->setModel(m_books);
    splitter->addWidget(m_booksT);

    m_users->setHorizontalHeaderLabels(QStringList() << "User ID" << "Name");
    m_usersT->setModel(m_users);
    splitter->addWidget(m_usersT);

    layout->addWidget(splitter);
    setCentralWidget(centralWidget);
    createMenus();
    updateBookModel();
    updateUserModel();
    // При двойном клике по строке таблицы показываем информацию
    connect(m_booksT, &QTableView::doubleClicked, this, &MainWindow::slotShowBookDetails);
    connect(m_usersT, &QTableView::doubleClicked, this, &MainWindow::slotShowUserDetails);
}

MainWindow::~MainWindow() { }

void MainWindow::createMenus()
{
    QMenu* bookMenu = menuBar()->addMenu("Books");
    QAction* addBookAction = new QAction("Add Book", this);
    connect(addBookAction, &QAction::triggered, this, &MainWindow::slotAddBook);
    bookMenu->addAction(addBookAction);

    QAction* deleteBookAction = new QAction("Delete Book", this);
    connect(deleteBookAction, &QAction::triggered, this, &MainWindow::slotDeleteBook);
    bookMenu->addAction(deleteBookAction);

    QAction* searchBookAction = new QAction("Search Book", this);
    connect(searchBookAction, &QAction::triggered, this, &MainWindow::slotSearchBook);
    bookMenu->addAction(searchBookAction);

    QAction* lendBookAction = new QAction("Lend Book", this);
    connect(lendBookAction, &QAction::triggered, this, &MainWindow::slotLendBook);
    bookMenu->addAction(lendBookAction);

    QMenu* userMenu = menuBar()->addMenu("Users");

    QAction* addUserAction = new QAction("Add User", this);
    connect(addUserAction, &QAction::triggered, this, &MainWindow::slotAddUser);
    userMenu->addAction(addUserAction);

    QAction* deleteUserAction = new QAction("Delete User", this);
    connect(deleteUserAction, &QAction::triggered, this, &MainWindow::slotDeleteUser);
    userMenu->addAction(deleteUserAction);
}

void MainWindow::slotAddBook()
{
    AddBookDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        QString title = dlg.getTitle();
        QString author = dlg.getAuthor();
        int year = dlg.getYear();
        m_library.addBook(std::make_shared<Book>(title.toStdString(), author.toStdString(), year));
        updateBookModel();
    }
}

void MainWindow::slotDeleteBook()
{
    QModelIndex index = m_booksT->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Delete Book", "Select a book to delete");
        return;
    }
    QString title = m_books->item(index.row(), 0)->text();
    m_library.removeBook(title.toStdString());
    updateBookModel();
}

void MainWindow::slotSearchBook()
{
    SearchBookDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        QString title = dlg.getTitle();
        QString author = dlg.getAuthor();
        auto weakBook = m_library.findBook(title.toStdString(), author.toStdString());
        if (auto bookPtr = weakBook.lock()) {
            QString info = QString("Found Book:\nTitle: %1\nAuthor: %2\nYear: %3")
                .arg(QString::fromStdString(bookPtr->getTitle()))
                .arg(QString::fromStdString(bookPtr->getAuthor()))
                .arg(bookPtr->getYear());
            QMessageBox::information(this, "Search Result", info);
        } else {
            QMessageBox::information(this, "Search Result", "Book not found");
        }
    }
}

void MainWindow::slotAddUser()
{
    AddUserDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        QString name = dlg.getName();
        int id = dlg.getId();
        m_library.addUser(std::make_shared<User>(name.toStdString(), id));
        updateUserModel();
    }
}

void MainWindow::slotDeleteUser()
{
    QModelIndex index = m_usersT->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Delete User", "Select a user to delete.");
        return;
    }
    int userId = m_users->item(index.row(), 0)->text().toInt();
    m_library.removeUser(userId);
    updateUserModel();
}
void MainWindow::slotLendBook()
{
    // Создаем диалог выдачи книги
    LendBook dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
         QString bookTitle = dlg.getBookTitle();
         int userId = dlg.getUserId();
         m_library.lendBook(bookTitle.toStdString(), userId);
         updateBookModel();
         updateUserModel();
    }
}
void MainWindow::updateBookModel()
{
    m_books->removeRows(0, m_books->rowCount());
    for (const auto& book : m_library.getBooks()) {
        QList<QStandardItem*> row;
        row << new QStandardItem(QString::fromStdString(book->getTitle()))
            << new QStandardItem(QString::fromStdString(book->getAuthor()))
            << new QStandardItem(QString::number(book->getYear()));
        m_books->appendRow(row);
    }
}

void MainWindow::updateUserModel()
{
    m_users->removeRows(0, m_users->rowCount());
    for (const auto& user : m_library.getUsers()) {
        QList<QStandardItem*> row;
        row << new QStandardItem(QString::number(user->getId()))
            << new QStandardItem(QString::fromStdString(user->getName()));
        m_users->appendRow(row);
    }
}
void MainWindow::slotShowBookDetails(const QModelIndex &index)
{
    if (!index.isValid()) return;
    if (index.row() < static_cast<int>(m_library.getBooks().size())) {
         auto book = m_library.getBooks()[index.row()];
         Info dlg(this);
         dlg.setDetails(book, nullptr);
         dlg.exec();
    }
}
void MainWindow::slotShowUserDetails(const QModelIndex &index)
{
    if (!index.isValid()) return;
    if (index.row() < static_cast<int>(m_library.getUsers().size())) {
         auto user = m_library.getUsers()[index.row()];
         Info dlg(this);
         dlg.setDetails(nullptr, user);
         dlg.exec();
    }
}
