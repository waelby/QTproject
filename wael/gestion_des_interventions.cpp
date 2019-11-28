#include "gestion_des_interventions.h"
#include "ui_gestion_des_interventions.h"
#include "intervention.h"
#include<QMessageBox>
#include <QSystemTrayIcon>

gestion_des_interventions::gestion_des_interventions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_des_interventions)
{
    ui->setupUi(this);
    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);

    ui->tabintervention->setModel(tmpintervention.afficher());//refresh

}

gestion_des_interventions::~gestion_des_interventions()
{
    delete ui;
}

void gestion_des_interventions::on_pushButton_8_clicked()
{
    int num_intervention = ui->lineEdit_5->text().toInt();
    int date_intervention = ui->lineEdit_6->text().toInt();
    int num_equipe= ui->lineEdit_7->text().toInt();
     int etat= ui->lineEdit_8->text().toInt();
     int num_avion= ui->lineEdit_11->text().toInt();
     QString type_intervention=ui->lineEdit->text();

  intervention i (num_intervention,date_intervention,num_equipe,etat,num_avion,type_intervention);
  bool test=i.ajouter();
  if(test)
{ui->tabintervention->setModel(tmpintervention.afficher());//refresh
        mysystem->showMessage(tr("notification"),tr("ajout d'une intervention  avec succe"));
QMessageBox::information(nullptr, QObject::tr("Ajouter une intervention"),
                  QObject::tr("equipe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une intervention"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}

void gestion_des_interventions::on_pushButton_11_clicked()
{
    int num_intervention = ui->lineEdit_12->text().toInt();
    int date_intervention = ui->lineEdit_13->text().toInt();
    int num_equipe = ui->lineEdit_14->text().toInt();
       int etat= ui->lineEdit_15->text().toInt();
       int num_avion= ui->lineEdit_16->text().toInt();
       QString type_intervention=ui->lineEdit_2->text();



     bool test = tmpintervention.modifierintervention( num_intervention, date_intervention, num_equipe, etat, num_avion,type_intervention);
         if (test)
         {
              ui->tabintervention->setModel( tmpintervention.afficher());

             QMessageBox::information(nullptr, QObject::tr("modifier avec sucess !"),
                         QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
         }
         else
             QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),
                         QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion_des_interventions::on_pushButton_10_clicked()
{
    int num_interevention = ui->lineEdit_9->text().toInt();
    bool test=tmpintervention.supprimer(num_interevention);
    if(test)
    {ui->tabintervention->setModel(tmpintervention.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une interevention"),
                    QObject::tr("interevention supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une interevention"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_des_interventions::on_pushButton_clicked()
{
    QString TYPE_INTERVENTION = ui->lineEdit_3->text();
    ui->tabintervention->setModel(tmpintervention.chercher(TYPE_INTERVENTION));
}

void gestion_des_interventions::on_pushButton_2_clicked()
{
    ui->tabintervention->setModel(tmpintervention.trie_numintervention());
}

