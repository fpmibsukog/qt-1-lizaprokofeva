#include "AddUserDialog.h"
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QMessageBox>

AddUserDialog::AddUserDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Add User");
    m_name = new QLineEdit(this);
    m_id = new QSpinBox(this);
    m_id->setRange(1, 1000);

    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Name:", m_name);
    formLayout->addRow("ID:", m_id);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &AddUserDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &AddUserDialog::reject);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
}

QString AddUserDialog::getName() const {
    return m_name->text();
}

int AddUserDialog::getId() const {
    return m_id->value();
}
void AddUserDialog::accept() {
    if (m_name->text().trimmed().isEmpty()) {
         QMessageBox::warning(this, "Error", "Name cannot be empty");
         return;
    }
    QDialog::accept();
}
