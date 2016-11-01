#include "departform.h"
#include "ui_departform.h"
#include <QMessageBox>

DepartForm::DepartForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartForm)
{
    ui->setupUi(this);
}

DepartForm::~DepartForm()
{
    delete ui;
}

void DepartForm::on_pushButton_clicked()
{
    QString man, prj, subdiv;
    QDateTime tim = ui->dateTimeEdit->dateTime();
    man = ui->lineEdit->text();
    prj = ui->lineEdit_2->text();
    subdiv = ui->lineEdit_3->text();
    if (man.isEmpty())
    {
        int n = QMessageBox::warning(0, "Warning", "Manager field is empty!", "Ok", QString(), 0, 0);
        return;
    }
    if (prj.isEmpty())
    {
        int n = QMessageBox::warning(0, "Warning", "Project field is empty!", "Ok", QString(), 0, 0);
        return;
    }
    if (subdiv.isEmpty())
    {
        int n = QMessageBox::warning(0, "Warning", "Subdivision field is empty!", "Ok", QString(), 0, 0);
        return;
    }
    emit DeprAdd(man, prj, subdiv, tim);
    close();
}

void DepartForm::on_pushButton_2_clicked()
{
    close();
}
