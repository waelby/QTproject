#ifndef GESTION_DES_INTERVENTIONS_H
#define GESTION_DES_INTERVENTIONS_H
#include "intervention.h"
#include <QDialog>

namespace Ui {
class gestion_des_interventions;
}
class QSystemTrayIcon;

class gestion_des_interventions : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_des_interventions(QWidget *parent = nullptr);
    ~gestion_des_interventions();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gestion_des_interventions *ui;
    intervention tmpintervention;
    QSystemTrayIcon * mysystem;

};

#endif // GESTION_DES_INTERVENTIONS_H
