#include "LendBook.h"
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QMessageBox>

LendBook::LendBook(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Lend Book to User");
    m_bookTitle = new QLineEdit(this);
    m_userId = new QSpinBox(this);
    m_userId->setRange(1, 1000);

    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Book Title:", m_bookTitle);
    formLayout->addRow("User ID:", m_userId);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &LendBook::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &LendBook::reject);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
}

QString LendBook::getBookTitle() const
{
    return m_bookTitle->text();
}

int LendBook::getUserId() const
{
    return m_userId->value();
}
void LendBook::accept() {
    if (m_bookTitle->text().trimmed().isEmpty()) {
         QMessageBox::warning(this, "Error", "Book Title cannot be empty");
         return;
    }
    if (m_userId->value() <= 0) {
         QMessageBox::warning(this, "Error", "Incorrect ID");
         return;
    }
    QDialog::accept();
}
