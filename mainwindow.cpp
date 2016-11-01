#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    app = new LoginForm();
    connect(app, SIGNAL(DBAllow()), this, SLOT(DBAllowed()));

    work = new WorkerForm();
    connect(work, SIGNAL(WorkAdd(QString, QString, int)), this, SLOT(WorkerAdd(QString ,QString, int)));

    depr = new DepartForm();
    connect(depr, SIGNAL(DeprAdd(QString, QString, QString, QDateTime)), this, SLOT(DepartmentAdd(QString, QString, QString, QDateTime)));

    vis = new VisitForm();
    connect(vis, SIGNAL(VisAdd(int,int,QDateTime,QDateTime,QDateTime,QString,QString)), this, SLOT(VisitAdd(int,int,QDateTime,QDateTime,QDateTime,QString,QString)));

    db = QSqlDatabase::addDatabase("QODBC");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete app;
    delete work;
    delete depr;
    db.close();
}

void MainWindow::AddLog(const QString str)
{
    QDateTime tim(QDateTime::currentDateTime());
    ui->textEdit->insertPlainText("[" + tim.toString("H:mm:ss") + "] " + str + "\n");
}

void MainWindow::DBAllowed()
{
    qDebug() << "Eeeee";
    modelka = new QSqlQueryModel();
    modelka->setQuery("SELECT ID, FirstName, LastName FROM dbo.info");

    ui->tableView->setModel(modelka);
    ui->tableView->show();

    /*modelka = new QSqlTableModel(this, db);
    modelka->setTable("info");
    modelka->setEditStrategy(QSqlTableModel::OnFieldChange);
    modelka->select();
    ui->tableView->setModel(modelka);*/
    AddLog("Successful connection!");
}

void MainWindow::WorkerAdd(QString fname, QString lname, int age)
{
    QSqlQuery qry;
    qry.prepare("{ CALL dbo.NewWorker(?, ?, ?) }");
    qry.bindValue(0, fname);
    qry.bindValue(1, lname);
    qry.bindValue(2, age);
    AddLog((qry.exec()) ? "Worker is successfully added!" : "Error: Worker is not added!");
}

void MainWindow::DepartmentAdd(QString man, QString prj, QString subdiv, QDateTime tim)
{
    QSqlQuery qry;
    qry.prepare("{ CALL dbo.NewDepartment(?, ?, ?, ?) }");
    qry.bindValue(0, man);
    qry.bindValue(1, prj);
    qry.bindValue(2, subdiv);
    qry.bindValue(3, tim);
    AddLog((qry.exec()) ? "Department is successfully added!" : "Error: Department is not added!");
}

void MainWindow::VisitAdd(int id1, int id2, QDateTime date, QDateTime enter, QDateTime leave, QString code, QString comments)
{
    QSqlQuery qry;
    qry.prepare("{ CALL dbo.NewVisit(?, ?, ?, ?, ?, ?, ?) }");
    qry.bindValue(0, id1);
    qry.bindValue(1, id2);
    qry.bindValue(2, date);
    qry.bindValue(3, enter);
    qry.bindValue(4, leave);
    qry.bindValue(5, code);
    qry.bindValue(6, comments);
    AddLog((qry.exec()) ? "Visit is successfully added!" : "Error: Visit is not added!");
}

void MainWindow::on_actionConnect_to_Database_triggered()
{
    app->setDBPointer(&db);
    app->show();
}

void MainWindow::on_actionAdd_New_Worker_triggered()
{
    work->show();
}

void MainWindow::on_actionAdd_New_Department_triggered()
{
    depr->show();
}

void MainWindow::on_actionAdd_New_Visit_triggered()
{
    vis->DataUpdate(db);
    vis->show();
}
