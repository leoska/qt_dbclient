#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();
    void setDBPointer(QSqlDatabase*);

signals:
    void DBAllow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginForm *ui;
    QSqlDatabase *db;
};

#endif // LOGINFORM_H
