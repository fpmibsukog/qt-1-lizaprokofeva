#include "AddBookDialog.h"
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QMessageBox>
AddBookDialog::AddBookDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Add Book");
    m_title = new QLineEdit(this);
    m_author = new QLineEdit(this);
    m_year = new QSpinBox(this);
    m_year->setRange(0, 2500);
    m_year->setValue(1950);

    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Title:", m_title);
    formLayout->addRow("Author:", m_author);
    formLayout->addRow("Year:", m_year);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &AddBookDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &AddBookDialog::reject);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
}

QString AddBookDialog::getTitle() const {
    return m_title->text();
}

QString AddBookDialog::getAuthor() const {
    return m_author->text();
}

int AddBookDialog::getYear() const {
    return m_year->value();
}
void AddBookDialog::accept() {
    if (m_title->text().trimmed().isEmpty() || m_author->text().trimmed().isEmpty()) {
         QMessageBox::warning(this, "Error", " Title and Author fields cannot be empty");
         return;
    }
    QDialog::accept();
}