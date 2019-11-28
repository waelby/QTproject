#ifndef EQUIPE_H
#define EQUIPE_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class equipe
{
    QString num_equipe;
    QString responsable_equipe;
    QString nature_equipe;
    QString ID_P;

public:
    equipe();
    equipe (QString,QString,QString,QString);
    QString  get_numero_equipe();
    QString  get_responsable_equipe();
    QString  get_nature_equipe();
    QString  get_ID_P();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifierequipe(QString,QString,QString,QString);
    QSqlQueryModel *chercher(QString);
    QSqlQueryModel *trie_numequipe();
};

#endif // EQUIPE_H
