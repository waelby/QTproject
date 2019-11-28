#include "equipe.h"
#include <QDebug>

equipe::equipe()
{
   num_equipe="";
    responsable_equipe="";
    nature_equipe="";
   ID_P="";
}
equipe::equipe (QString numero,QString nature ,QString  responsable,QString ID_P)
{
  this->num_equipe=numero;
    this->nature_equipe=nature;
    this->responsable_equipe=responsable;
 this->ID_P=ID_P;
}
QString  equipe::get_numero_equipe(){return num_equipe ;}
QString equipe::get_responsable_equipe(){return responsable_equipe;}
QString equipe::get_nature_equipe(){return  nature_equipe;}
QString equipe::get_ID_P(){return  ID_P;}


bool equipe::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO equipe (NUM_EQUIPE,NATURE_EQUIPE,RESPONSABLE_EQUIPE,ID_P) "
                    "VALUES (:num_equipe,:nature_equipe,:responsable_equipe,:ID_P)");
query.bindValue(":num_equipe", num_equipe);
query.bindValue(":nature_equipe", nature_equipe);
query.bindValue(":responsable_equipe", responsable_equipe);
query.bindValue(":ID_P", ID_P);


return    query.exec();
}

QSqlQueryModel * equipe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from equipe");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_EQUIPE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NATURE_EQUIPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("RESPONSABLE_EQUIPE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_P"));

    return model;
}

bool equipe::supprimer(QString num_equipe)
{
QSqlQuery query;

query.prepare("Delete from equipe where NUM_EQUIPE =:num_equipe");
query.bindValue(":num_equipe",num_equipe);
return    query.exec();
}
bool equipe:: modifierequipe (QString num_equipe,QString responsable_equipe,QString nature,QString ID_P)
{

        QSqlQuery q;
         q.prepare("UPDATE equipe set NUM_EQUIPE =:num_equipe,NATURE_EQUIPE=:nature,RESPONSABLE_EQUIPE=:responsable_equipe,ID_P =:ID_P where NUM_EQUIPE =:num_equipe");
         q.bindValue(":num_equipe",num_equipe);
         q.bindValue(":nature",nature);
        q.bindValue(":responsable_equipe",responsable_equipe);
        q.bindValue(":ID_P",ID_P);


        return    q.exec();


}
QSqlQueryModel * equipe::chercher(QString NUM_EQUIPE)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from equipe WHERE NUM_EQUIPE=:NUM_EQUIPE"));

     query.bindValue(":NUM_EQUIPE",NUM_EQUIPE);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("NATURE_EQUIPE "));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("RESPONSABLE_EQUIPE"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("ID_P"));


return model;
 }



QSqlQueryModel * equipe::trie_numequipe()
 { QSqlQueryModel * model = new QSqlQueryModel();

   model->setQuery(QString("select * from equipe order by NUM_EQUIPE asc "));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_EQUIPE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NATURE_EQUIPE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("RESPONSABLE_EQUIPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_P"));



    return model;
 }
