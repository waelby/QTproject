#ifndef GESTION_DES_EQUIPES_H
#define GESTION_DES_EQUIPES_H
#include "equipe.h"
#include <QDialog>

namespace Ui {
class gestion_des_equipes;
}
class QSystemTrayIcon;
class gestion_des_equipes : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_des_equipes(QWidget *parent = nullptr);
    ~gestion_des_equipes();

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_8_clicked();


    void on_pushButton_10_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gestion_des_equipes *ui;
    equipe tmpequipe;
    QSystemTrayIcon * mysystem;
};

#endif // GESTION_DES_EQUIPES_H
