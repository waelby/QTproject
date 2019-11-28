#include "intervention.h"

intervention::intervention()
{
     num_intervention=0;
     num_equipe=0;
     num_avion=0;
     etat=0;
    type_intervention="";
    date_intervention=0;


}

intervention::intervention (int numero_intervention,int date ,int numero_eq,int etat,int numero_av,QString type)
{
     this->num_intervention=numero_intervention;
     this->date_intervention=date;
     this->num_equipe=numero_eq;
     this->etat=etat;
     this->num_avion=numero_av;
     this->type_intervention=type;

}

int  intervention::get_num_intervention(){return num_intervention ;}
int intervention::get_date_intervention(){return date_intervention;}
int intervention::get_numero_equipe(){return  num_equipe;}
int intervention::get_etat(){return  etat;}
int intervention::get_num_avion(){return  num_avion;}
QString intervention::get_type_intervention(){return type_intervention;}




bool intervention::ajouter()
{
QSqlQuery query;
QString res= QString::number(num_intervention);
QString res1= QString::number(num_equipe);
QString res2= QString::number(num_avion);
QString res3= QString::number(etat);
QString res4= QString::number(date_intervention);


query.prepare("INSERT INTO intervention (NUM_INTERVENTION,NUM_EQUIPE,NUM_AVION,ETAT,TYPE_INTERVENTION,DATE_INTERVENTION) "
                    "VALUES (:num_intervention,:num_equipe,:num_avion,:etat,:type_intervention,:date_intervention)");
query.bindValue(":num_intervention", res);
query.bindValue(":num_equipe", res1);
query.bindValue(":num_avion", res2);
query.bindValue(":etat", res3);
query.bindValue(":type_intervention", type_intervention);
query.bindValue(":date_intervention", res4);


return    query.exec();
}


QSqlQueryModel * intervention::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from intervention");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_INTERVENTION"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_EQUIPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUM_AVION"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_INTERVENTION"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_INTERVENTION"));



    return model;
}

bool intervention::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from intervention where NUM_INTERVENTION= :num_intervention ");
query.bindValue(":num_intervention", res);
return    query.exec();
}

bool intervention:: modifierintervention (int num_intervention, int date_intervention, int num_equipe, int etat, int num_avion, QString type_intervention)
{

    QString res= QString::number(num_intervention);
    QString res1= QString::number(num_equipe);
    QString res2= QString::number(num_avion);
    QString res3= QString::number(etat);
    QString res4= QString::number(date_intervention);

        QSqlQuery q;
         q.prepare("UPDATE intervention set NUM_INTERVENTION=:num_intervention,NUM_EQUIPE=:num_equipe,NUM_AVION=:num_avion,ETAT=:etat,TYPE_INTERVENTION=:type_intervention,DATE_INTERVENTION=:date_intervention where NUM_INTERVENTION =:num_intervention");

         q.bindValue(":num_intervention",res);
         q.bindValue(":num_equipe",res1);
         q.bindValue(":num_avion",res2);
         q.bindValue(":etat",res3);
        q.bindValue(":type_intervention",type_intervention);
        q.bindValue(":date_intervention",res4);




        return    q.exec();


}
QSqlQueryModel * intervention::chercher(QString TYPE_INTERVENTION)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from intervention WHERE TYPE_INTERVENTION=:TYPE_INTERVENTION"));

     query.bindValue(":TYPE_INTERVENTION",TYPE_INTERVENTION);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_INTERVENTION"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NUM_EQUIPE "));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("NUM_AVION"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_INTERVENTION "));


return model;
 }



QSqlQueryModel * intervention::trie_numintervention()
 { QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery(QString("SELECT * FROM intervention ORDER BY NUM_INTERVENTION asc"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_INTERVENTION"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NUM_EQUIPE "));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NUM_AVION"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_INTERVENTION "));

    return model;
 }
