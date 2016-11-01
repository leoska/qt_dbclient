#ifndef VISITFORM_H
#define VISITFORM_H

#include <QWidget>
#include <QtSql>
#include <QVector>
#include <inforec.h>

namespace Ui {
class VisitForm;
}

class VisitForm : public QWidget
{
    Q_OBJECT

public:
    explicit VisitForm(QWidget *parent = 0);
    ~VisitForm();
    void DataUpdate(QSqlDatabase&);

signals:
    void VisAdd(int, int, QDateTime, QDateTime, QDateTime, QString, QString);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::VisitForm *ui;
    QVector<InfoRec> vec;
    QVector<int> vec2;
};

#endif // VISITFORM_H
