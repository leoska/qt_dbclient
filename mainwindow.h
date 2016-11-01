#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDateTime>
#include "loginform.h"
#include "ui_loginform.h"
#include "workerform.h"
#include "ui_workerform.h"
#include "departform.h"
#include "ui_departform.h"
#include "visitform.h"
#include "ui_visitform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void AddLog(const QString);

private slots:
    void on_actionConnect_to_Database_triggered();
    void DBAllowed();
    void WorkerAdd(QString, QString, int);
    void DepartmentAdd(QString, QString, QString, QDateTime);
    void VisitAdd(int, int, QDateTime, QDateTime, QDateTime, QString, QString);

    void on_actionAdd_New_Worker_triggered();

    void on_actionAdd_New_Department_triggered();

    void on_actionAdd_New_Visit_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    //QSqlTableModel *modelka;
    QSqlQueryModel *modelka;
    LoginForm *app;
    WorkerForm *work;
    DepartForm *depr;
    VisitForm *vis;
};

#endif // MAINWINDOW_H
