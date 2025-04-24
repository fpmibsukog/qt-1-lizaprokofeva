#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>
#include "Library.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
     MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void slotAddBook();
    void slotDeleteBook();
    void slotSearchBook();
    void slotAddUser();
    void slotDeleteUser();
    void slotShowBookDetails(const QModelIndex &index);
    void slotShowUserDetails(const QModelIndex &index);
    void slotLendBook();
private:
    void createMenus();
    void updateBookModel();
    void updateUserModel();

    Library m_library;
    QTableView* m_booksT;
    QStandardItemModel* m_books;
    QTableView* m_usersT;
    QStandardItemModel* m_users;
};

#endif // MAINWINDOW_H