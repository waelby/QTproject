#include "gestion_des_equipes.h"
#include "ui_gestion_des_equipes.h"
#include <QDebug>
#include "equipe.h"
#include <QMessageBox>
#include <QSystemTrayIcon>


gestion_des_equipes::gestion_des_equipes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_des_equipes)
{
    ui->setupUi(this);
    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);

    ui->tabequipe->setModel(tmpequipe.afficher());//refresh

}

gestion_des_equipes::~gestion_des_equipes()
{
    delete ui;
}


void gestion_des_equipes::on_pushButton_8_clicked()
{
    QString num_equipe = ui->lineEdit->text();
    QString responsable_equipe= ui->lineEdit_2->text();
    QString nature_equipe= ui->lineEdit_3->text();
     QString ID_P= ui->lineEdit_4->text();
  equipe e (num_equipe,responsable_equipe,nature_equipe,ID_P);
  bool test=e.ajouter();
  if(test)
{ui->tabequipe->setModel(tmpequipe.afficher());//refresh
      mysystem->showMessage(tr("notification"),tr("ajout d'une equipe avec succe"));
QMessageBox::information(nullptr, QObject::tr("Ajouter une equipe"),
                QObject::tr("equipe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une equipe"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}

void gestion_des_equipes::on_pushButton_10_clicked()
{
    QString num_equipe = ui->lineEdit_9->text();
    bool test=tmpequipe.supprimer(num_equipe);
    if(test)
    {ui->tabequipe->setModel(tmpequipe.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une equipe"),
                    QObject::tr("equipe supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une equipe"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion_des_equipes::on_pushButton_11_clicked()
{
    QString num_equipe = ui->lineEdit_12->text();
    QString responsable_equipe = ui->lineEdit_13->text();
       QString nature= ui->lineEdit_14->text();
       QString ID_P= ui->lineEdit_15->text();



     bool test = tmpequipe.modifierequipe( num_equipe,nature, responsable_equipe, ID_P);
         if (test)
         {
              ui->tabequipe->setModel( tmpequipe.afficher());

             QMessageBox::information(nullptr, QObject::tr("modifier avec sucess !"),
                         QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
         }
         else
             QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),
                         QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion_des_equipes::on_pushButton_clicked()
{
    QString num_equipe  = ui->lineEdit_5->text();
    ui->tabequipe->setModel(tmpequipe.chercher(num_equipe));
}

void gestion_des_equipes::on_pushButton_2_clicked()
{
    ui->tabequipe->setModel(tmpequipe.trie_numequipe());


}
