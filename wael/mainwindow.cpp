#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_des_equipes.h"
#include "gestion_des_interventions.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    gestion_des_equipes gestion_des_equipes;
    gestion_des_equipes.setModal(true);
    gestion_des_equipes.exec();
}

void MainWindow::on_pushButton_2_clicked()
{

    gestion_des_interventions gestion_des_interventions;
    gestion_des_interventions.setModal(true);
    gestion_des_interventions.exec();
}
