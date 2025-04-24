#ifndef SEARCHBOOKDIALOG_H
#define SEARCHBOOKDIALOG_H
#include <QDialog>
#include <QLineEdit>
class SearchBookDialog : public QDialog
{
    Q_OBJECT
public:
   explicit SearchBookDialog(QWidget* parent = nullptr);

    QString getTitle() const;
    QString getAuthor() const;
private:
    QLineEdit* m_title;
    QLineEdit* m_author;
};

#endif // SEARCHBOOKDIALOG_H
