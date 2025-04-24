#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>

class AddBookDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddBookDialog(QWidget* parent = nullptr);

    QString getTitle() const;
    QString getAuthor() const;
    int getYear() const;
    void accept() ;

private:
    QLineEdit* m_title;
    QLineEdit* m_author;
    QSpinBox* m_year;
};

#endif // ADDBOOKDIALOG_H
