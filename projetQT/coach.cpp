#include "coach.h"

coach::coach(int idC, QString nom,QString prenom,QString sexe,QString email,QString password,QDate date)
{
    this->idC=idC;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->email=email;
    this->password=password;
    this->date=date;

}

int coach::getID()
{return idC;}

QString coach::getNom(){return nom;}
QString coach::getPrenom(){return prenom;}
QString coach::getSexe(){return sexe;}
QDate coach::getDate(){return date;}
QString coach::getEmail(){return email;}
QString coach::getPassword(){return password;}
void coach::setNom(QString n){this->nom=n;}
void coach::setPrenom(QString p){this->prenom=p;}
void coach::setSexe(QString s){this->sexe=s;}
void coach::setDate(QDate d){this->date=d;}
void coach::setEmail(QString e){this->email=e;}
void coach::setPassword(QString pass){this->password=pass;}

bool coach::ajouter()
{
    QSqlQuery query;

    QString res = QString::number(idC);

    query.prepare("INSERT INTO coach (IDC,NOMC,PRENOMC,SEXE,DATE_NAISSANCE,EMAIL,PASSWORD)"
            "VALUES(:id, :nom, :prenom, :sexe, :date,:email,:password)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":sexe",sexe);
    query.bindValue(":date",date);
    query.bindValue(":email",email);
    query.bindValue(":password",password);

    return query.exec();
}

QSqlQueryModel* coach::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from coach");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("password"));

    return model;
}
QSqlQueryModel* coach::afficher1()

{

    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT IDC FROM COACH");

    return model;

}

bool coach::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("delete from coach where IDC= :id");
    query.bindValue(":id",res);

    return query.exec();
}

bool coach::modifier(){

    QSqlQuery query;
    QString res = QString::number(idC);

    query.prepare(" UPDATE coach SET NOMC=:nom,PRENOMC= :prenom ,SEXE= :sexe, DATE_NAISSANCE= :date,EMAIL= :email,PASSWORD= :password where IDC= :id");
    //control  saisie
    //qDebug()<<cin;
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":sexe",sexe);
    query.bindValue(":date", date);
    query.bindValue(":email", email);
    query.bindValue(":password", password);
    return query.exec();
    //qDebug()<<query.lastError();

}
