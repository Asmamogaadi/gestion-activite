#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <QString>
#include <QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>
class activite
{
public:
    activite();

    //Getters
    int getMatricule();
    int getDuree();
    QString getNom_activite();
    QDate getDateA();

    //Setters
    void setMatricule(int m);
    void setDuree(int d);
    void setNom_activite(QString a);
    void setDateA(QDate d);

    //Constructeur
    activite(int,int,QString,QDate);
    //CRUD
    bool ajouterA();
    QSqlQueryModel* afficherA();
    bool supprimerA(int mat);
    bool modifierA();
    QSqlQueryModel*recherche(QString cas);
    QSqlQueryModel *tricin();

private:
    int matricule,duree;
    QString nom_activite;
    QDate dateA;



};

#endif // ACTIVITE_H
