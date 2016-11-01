#include "visitform.h"
#include "ui_visitform.h"
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>

VisitForm::VisitForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisitForm)
{
    ui->setupUi(this);
}

VisitForm::~VisitForm()
{
    delete ui;
}

void VisitForm::on_pushButton_2_clicked()
{
    close();
}

void VisitForm::DataUpdate(QSqlDatabase &db)
{
    QDateTime now(QDateTime::currentDateTime());
    ui->dateTimeEdit = now;
    QSqlQuery qry(db);
    qry.prepare("SELECT ID, FirstName, LastName FROM dbo.info");
    if (qry.exec())
    {
        QSqlRecord rec = qry.record();
        int fnameCol = rec.indexOf("FirstName");
        int lnameCol = rec.indexOf("LastName");
        int id = rec.indexOf("ID");
        ui->comboBox->clear();
        vec.clear();
        vec.resize(0);
        while(qry.next())
        {
            InfoRec rec(qry.value(fnameCol).toString(), qry.value(lnameCol).toString(), qry.value(id).toInt());
            ui->comboBox->addItem(rec.getName(false) + " " + rec.getName() + " (ID: " + QString("%1").arg(rec.getId()) + ")");
            vec.push_back(rec);
        }
    }

    QSqlQuery qry2(db);
    qry2.prepare("SELECT ID, Project, Podrazdel FROM dbo.Departments");
    if (qry2.exec())
    {
        QSqlRecord rec = qry2.record();
        int projCol = rec.indexOf("Project");
        int subdivCol = rec.indexOf("Podrazdel");
        int id = rec.indexOf("ID");
        ui->comboBox_2->clear();
        vec2.clear();
        vec2.resize(0);
        while(qry2.next())
        {
            ui->comboBox_2->addItem(qry2.value(projCol).toString() + " (" + qry2.value(subdivCol).toString() + ")");
            vec2.push_back(qry2.value(id).toInt());
        }
    }
}

void VisitForm::on_pushButton_clicked()
{
    QString cardcode, comments;
    cardcode = ui->lineEdit->text();
    comments = ui->textEdit->toPlainText();
    if (cardcode.isEmpty())
    {
        int n = QMessageBox::warning(0, "Warning", "CardCode field is empty!", "Ok", QString(), 0, 0);
        return;
    }

    QDateTime date, enter, leave;

    int cb1 = ui->comboBox->currentIndex();
    int cb2 = ui->comboBox_2->currentIndex();
    int id1 = vec[cb1].getId();
    int id2 = vec2[cb2];

    date = ui->dateTimeEdit->dateTime();
    enter = ui->dateTimeEdit_2->dateTime();
    leave = ui->dateTimeEdit_3->dateTime();

    emit VisAdd(id1, id2, date, enter, leave, cardcode, comments);

    //qDebug() << QString("%1").arg(ui->comboBox->currentIndex());
}
