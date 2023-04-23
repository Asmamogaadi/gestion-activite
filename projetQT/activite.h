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
QString getimage_path();
    //Setters
    void setMatricule(int m);
    void setDuree(int d);
    void setNom_activite(QString a);
    void setDateA(QDate d);
void setimage_path(QString s);
    //Constructeur
    activite(int,int,QString,QDate,QString);
    //CRUD
    bool ajouterA();
    QSqlQueryModel* afficherA();
    bool supprimerA(int mat);
    bool modifierA();
    QSqlQueryModel*recherche(QString cas);
    QSqlQueryModel *tricin();

private:
    int matricule,duree;
    QString nom_activite,image_path;
    QDate dateA;



};

#endif // ACTIVITE_H
