#ifndef INFO_H
#define INFO_H
#include <QDialog>
#include <memory>
#include "Book.h"
#include "User.h"

class QLabel;
class QVBoxLayout;
class Info : public QDialog
{
    Q_OBJECT
public:
    explicit Info(QWidget *parent = nullptr);
    void setDetails(const std::shared_ptr<Book>& book, const std::shared_ptr<User>& user);

private:
    QVBoxLayout* layout;
    QLabel* detailsLabel;
};

#endif // INFO_H
