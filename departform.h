#ifndef DEPARTFORM_H
#define DEPARTFORM_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class DepartForm;
}

class DepartForm : public QWidget
{
    Q_OBJECT

public:
    explicit DepartForm(QWidget *parent = 0);
    ~DepartForm();

signals:
    void DeprAdd(QString, QString, QString, QDateTime);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DepartForm *ui;
};

#endif // DEPARTFORM_H
