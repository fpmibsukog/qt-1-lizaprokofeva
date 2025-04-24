#ifndef LENDBOOK_H
#define LENDBOOK_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>

class LendBook : public QDialog
{
    Q_OBJECT
public:
    explicit LendBook(QWidget* parent = nullptr);

    QString getBookTitle() const;
    int getUserId() const;
    void accept();

private:
    QLineEdit* m_bookTitle;
    QSpinBox* m_userId;
};

#endif // LENDBOOK_H
