#include "mainwindow.h"

#include <QApplication>
#include<QtSql>
#include<QtDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include"connexion.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connexion c;
    w.show();
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.setUserName("wael");
    db.setPassword("esprit18");
    if (db.open())
    {
        qDebug()<<"data base open";
    }
    else
    {
        qDebug()<<"data base closed or there is an error";
    }

    return a.exec();
}
