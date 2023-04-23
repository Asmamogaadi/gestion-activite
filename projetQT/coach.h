#ifndef COACH_H
#define COACH_H
#include<QString>
#include <QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>
class coach
{

public:

    //constructeur
    coach(){}
    coach(int,QString,QString,QString,QString,QString,QDate);

    //Getters
    QString getNom();
    QString getPrenom();
    QString getSexe();
    int getID();
    QDate getDate();
    QString getEmail();
    QString getPassword();

    //Setters
    void setNom(QString n) ;
    void setPrenom(QString p) ;
    void setSexe(QString s);
    void setID(int id);
    void setDate(QDate d);
    void setEmail(QString e);
    void setPassword(QString pass);

    //CRUD
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher1();
    bool supprimer(int id);
    bool modifier();

private:
    int idC;
    QString nom , prenom, sexe,password,email;
    QDate date;
};

#endif // COACH_H
