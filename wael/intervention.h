#ifndef INTERVENTION_H
#define INTERVENTION_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class intervention
{
    int num_intervention;
    int date_intervention;
    int num_equipe;
    int etat;
    int num_avion;
    QString type_intervention;

public:
    intervention();

    intervention (int,int,int,int,int,QString);
    int  get_num_intervention();
    int get_date_intervention();
    int  get_numero_equipe();
    int  get_etat();
    int  get_num_avion();
    QString get_type_intervention();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifierintervention (int, int , int , int , int ,QString );
    QSqlQueryModel *chercher(QString);
    QSqlQueryModel *trie_numintervention();
};

#endif // INTERVENTION_H
