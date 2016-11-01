#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

void LoginForm::setDBPointer(QSqlDatabase *datb)
{
    db = datb;
    //parent = par;
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_pushButton_clicked()
{
    QString log = ui->lineEdit->text();
    QString pas = ui->lineEdit_2->text();
    QString _db = ui->lineEdit_3->text();

    db->setDatabaseName("DRIVER={SQL Server};SERVER=" + _db + ";DATABASE=personal;");//Trusted_Connection=yes;
    db->setUserName(log);
    db->setPassword(pas);

    if (db->open())
    {
        qDebug("ds is open!");
        emit DBAllow();
        close();
    }
    else
    {
        QSqlError er = db->lastError();
        qDebug() << "SQL ERROR:";
        qDebug() << er.databaseText();
    }
}
