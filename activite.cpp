#include "activite.h"

activite::activite(int matricule, int duree, QString nom_activite, QDate dateA)
{
 this->matricule=matricule;
 this->duree=duree;
 this->nom_activite=nom_activite;
 this->dateA=dateA;
}

activite::activite()
{

}

int activite::getMatricule(){return matricule;}
int activite::getDuree(){return duree;}
QString activite::getNom_activite(){return nom_activite;}
QDate activite::getDateA(){return dateA;}
void activite::setMatricule(int m){this->matricule=m;}
void activite::setDuree(int d){this->duree=d;}
void activite::setNom_activite(QString a){this->nom_activite=a;}
void activite::setDateA(QDate d){this->dateA=d;}

bool activite::ajouterA()
{
    QSqlQuery query;

    QString res = QString::number(matricule);
    QString res1 = QString::number(duree);

    query.prepare("INSERT INTO activites (MATRICULEA,NOM_ACTIVITE,DATE_ACT,DUREE)"
            "VALUES(:matricule, :nom_activite, :date, :duree)");
    query.bindValue(":matricule",res);
    query.bindValue(":nom_activite",nom_activite);
    query.bindValue(":date",dateA);
    query.bindValue(":duree",res1);

    return query.exec();
}

QSqlQueryModel* activite::afficherA()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from activites");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_activite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("duree"));

    return model;
}

bool activite::supprimerA(int mat)
{
    QSqlQuery query;
    QString res=QString::number(mat);

    query.prepare("delete from activites where MATRICULEA= :mat");
    query.bindValue(":mat",res);

    return query.exec();
}

bool activite::modifierA(){

    QSqlQuery query;
    QString res = QString::number(matricule);
    QString res1 = QString::number(duree);
    query.prepare(" UPDATE activites SET NOM_ACTIVITE= :nom_activite ,DATE_ACT= :dateA, DUREE= :duree where MATRICULEA= :matricule");
    //control  saisie
    //qDebug()<<cin;
    query.bindValue(":matricule",res);
    query.bindValue(":nom_activite",nom_activite);
    query.bindValue(":dateA",dateA);
    query.bindValue(":duree",res1);
    return query.exec();
    //qDebug()<<query.lastError();

}
QSqlQueryModel* activite ::recherche(QString cas)
{
  QSqlQueryModel* model=new QSqlQueryModel();
QSqlQuery query;

 model->setQuery("select * from activites WHERE (nom_activite LIKE '%"+cas+"%')");


 model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_activite"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("duree"));
query.exec();
  return  model;




}


QSqlQueryModel *activite::tricin()
{
  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM ACTIVITES ORDER BY MATRICULEA");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_activite"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("duree"));

        return model;
}

