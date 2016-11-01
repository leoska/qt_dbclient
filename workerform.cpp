#include "workerform.h"
#include "ui_workerform.h"
#include <QMessageBox>

WorkerForm::WorkerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkerForm)
{
    ui->setupUi(this);
}

WorkerForm::~WorkerForm()
{
    delete ui;
}

void WorkerForm::on_pushButton_2_clicked()
{
    close();
}

void WorkerForm::on_pushButton_clicked()
{
    QString fname, lname;
    int age = ui->spinBox->value();
    fname = ui->lineEdit->text();
    lname = ui->lineEdit_2->text();

    if (fname.isEmpty())
    {
        int n = QMessageBox::warning(0, "Warning", "First Name field is empty!", "Ok", QString(), 0, 0);
        return;
    }
    if (lname.isEmpty())
    {
        int n = QMessageBox::warning(0, "Warning", "Last Name field is empty!", "Ok", QString(), 0, 0);
        return;
    }
    if ((age < 14) && (age > 120))
    {
        int n = QMessageBox::warning(0, "Warning", "Age field is incorrect!", "Ok", QString(), 0, 0);
        return;
    }
    emit WorkAdd(fname, lname, age);
    close();
}
