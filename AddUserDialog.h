#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>

class AddUserDialog : public QDialog
{
    Q_OBJECT
public:
    AddUserDialog(QWidget* parent = nullptr);

    QString getName() const;
    int getId() const;
    void accept();

private:
    QLineEdit* m_name;
    QSpinBox* m_id;
};

#endif // ADDUSERDIALOG_H
