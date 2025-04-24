#include "SearchBookDialog.h"
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QVBoxLayout>

SearchBookDialog::SearchBookDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Search Book");
    m_title = new QLineEdit(this);
    m_author = new QLineEdit(this);

    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Title (optional):", m_title);
    formLayout->addRow("Author (optional):", m_author);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &SearchBookDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &SearchBookDialog::reject);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
}
QString SearchBookDialog::getTitle() const {
    return m_title->text();
}
QString SearchBookDialog::getAuthor() const {
    return m_author->text();
}
