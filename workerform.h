#ifndef WORKERFORM_H
#define WORKERFORM_H

#include <QWidget>

namespace Ui {
class WorkerForm;
}

class WorkerForm : public QWidget
{
    Q_OBJECT

public:
    explicit WorkerForm(QWidget *parent = 0);
    ~WorkerForm();

signals:
    void WorkAdd(QString, QString, int);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::WorkerForm *ui;
};

#endif // WORKERFORM_H
