#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "coach.h"
#include "activite.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QIntValidator>
#include <QFileDialog>
#include <QRegExp>
#include <iostream>
#include <QDebug>

#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPushButton>
#include<QString>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QFileDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QGuiApplication>
//#include <QQmlApplicationEngine>

//#include <QQuickItem>
#include <QSystemTrayIcon>
#include <QIntValidator>
#include <QDebug>


#include <QMessageBox>
#include "QIntValidator"
#include <QDateEdit>
#include <QPlainTextEdit>

#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QGuiApplication>
//#include <QQmlApplicationEngine>

//#include <QQuickItem>
#include <QSystemTrayIcon>
#include <QIntValidator>
//#include <QQmlApplicationEngine>

//#include <QQuickItem>
#include <QSystemTrayIcon>
#include <QPixmap>
#include <QDesktopServices>
#include <QImage>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_7->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_6->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
        ui->lineEdit_5->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));


        // activites
        ui->lineEdit_15->setValidator(new QIntValidator(0,99999999,this));
        ui->lineEdit_16->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
          ui->lineEdit_17->setValidator(new QIntValidator(0,48,this));
}


MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->tableView->setModel(c.afficher());
    ui->comboBox_5->setModel(c.afficher1());
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_ajouter_clicked()
{
    int id=ui->lineEdit_7->text().toInt();
    QString cinstr = QString::number(id);
    QString nom=ui->lineEdit_5->text();
    QString prenom=ui->lineEdit_6->text();
    QString sexe=ui->comboBox->currentText();
    QString email=ui->lineEdit_12->text();
    QString password=ui->lineEdit_13->text();
    QDate date=ui->dateEdit->date();
    coach c(id,nom,prenom,sexe,email,password,date);
            QRegularExpression re("^[A-Za-z0-9.%+-]+@[A-Za-z0-9.-]+.[A-Z|a-z]{2,}$"); // Définir l'expression régulière pour une adresse mail valide
                QRegularExpressionMatch match = re.match(email);
            if(!nom.isEmpty() && !prenom.isEmpty() && !cinstr.isEmpty() && !email.isEmpty() && !sexe.isEmpty() && !password.isEmpty() )
            {if (match.hasMatch()){
                bool test=c.ajouter();

            if(test)
            {

                QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectue\n"
                                                                               "ok cancel to cancel"),QMessageBox::Ok);
                ui->tableView->setModel(c.afficher());
                ui->comboBox_5->setModel(c.afficher1());
            }

            else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("ajouter non effectue\n"
                                                  "click cancel to exit"),QMessageBox::Cancel);

    }else {QMessageBox::warning(this, "Erreur", "Adresse mail invalide !");}}


            else QMessageBox::warning(this, "Erreur", "Toutes les informations.\n"
                                                      "doivent être complétées.!");

    }








void MainWindow::on_supprimer_clicked()
{
    //coach c;
    //c.setID(ui->lineEdit_7->text().toInt());
    //int id=c.setID(ui->lineEdit_7->text().toInt());
    //bool test=c.supprimer(c.getID());
    int id =ui->comboBox_5->currentText().toInt();
    bool test=c.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectue\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(c.afficher());
        ui->comboBox_5->setModel(c.afficher1());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectue.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
    }

void MainWindow::on_modifier_clicked()
{
    int id=ui->lineEdit_7->text().toInt();
    QString nom=ui->lineEdit_5->text();
    QString prenom=ui->lineEdit_6->text();
    QString email=ui->lineEdit_12->text();
    QString password=ui->lineEdit_13->text();
    QString sexe=ui->comboBox->currentText();
    QDate date=ui->dateEdit->date();

    bool test;

    coach c(id,nom,prenom,sexe,email,password,date);

    test=c.modifier();

    if ( test) {

    QMessageBox::information(nullptr, QObject::tr("ok"),
                             QObject::tr("modification effectue.\n"
                                         "Cilck Cancel to exit."),QMessageBox::Cancel);
    ui->tableView->setModel(c.afficher());
}
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                              QObject::tr("modification non effectue.\n"
                                          "Click Cancel to exit"),QMessageBox::Cancel);
}


//CRUD activites





void MainWindow::on_ajouter_as_clicked()
{
    int mat=ui->lineEdit_15->text().toInt();
    int duree=ui->lineEdit_17->text().toInt();
    QString nomA=ui->lineEdit_16->text();
    QDate dateA=ui->dateEdit_2->date();

     //
    QString matA=QString::number (mat) ;
     QString dureeA=QString::number (duree) ;
 // IFFFF
     activite a(mat,duree,nomA,dateA);
    if(!matA.isEmpty() && !dureeA.isEmpty() && !nomA.isEmpty())
    {
        bool testt=a.ajouterA();

        if(testt)
        {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Ajout effectue\n"
                                                 "Click cancel to exit."),QMessageBox::Cancel);
            ui->tableView_2->setModel(a.afficherA());
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Ajout non effectue.\n"
                                  "Click Cancel to exit"), QMessageBox::Cancel);
    }

    else QMessageBox::warning(this, "Erreur", "Toutes les informations.\n"
                                              "doivent être complétées.!");


    }


void MainWindow::on_supprimerA_clicked()
{
    int mat =ui->lineEdit_14->text().toInt();
    bool testt=a.supprimerA(mat);
    if(testt)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectue\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_2->setModel(a.afficherA());
        //ui->comboBox_5->setModel(c.afficher1());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectue.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_modifierA_clicked()
{
    int matricule=ui->lineEdit_15->text().toInt();
    int duree=ui->lineEdit_17->text().toInt();
    QString nomA=ui->lineEdit_16->text();
    QDate dateA=ui->dateEdit_2->date();

    activite a(matricule,duree,nomA,dateA);
    bool testt=a.modifierA();

    if ( testt) {

    QMessageBox::information(nullptr, QObject::tr("ok"),
                             QObject::tr("modification effectue.\n"
                                         "Cilck Cancel to exit."),QMessageBox::Cancel);
    ui->tableView_2->setModel(a.afficherA());
}
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                              QObject::tr("modification non effectue.\n"
                                          "Click Cancel to exit"),QMessageBox::Cancel);
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
            QSqlQuery qry;
            qry.prepare("select * from coach where IDC='"+val+"'");
           if (qry.exec())
           {
               while(qry.next())
               {
                  ui->lineEdit_5->setText(qry.value(1).toString());
                  ui->lineEdit_6->setText(qry.value(2).toString());
                   ui->dateEdit->setDate(qry.value(4).toDate());
                   ui->comboBox->setCurrentText(qry.value(3).toString());

                  ui->lineEdit_7->setText(qry.value(0).toString());
                  ui->lineEdit_12->setText(qry.value(5).toString());
                  ui->lineEdit_13->setText(qry.value(6).toString());





               }
           }
           else
           {
               QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                       QObject::tr("Echec"),
                       QMessageBox::Cancel);
           }
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->tableView_2->setModel(a.afficherA());
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2->model()->data(index).toString();
            QSqlQuery qry;
            qry.prepare("select * from activites where MATRICULEA='"+val+"'");
           if (qry.exec())
           {
               while(qry.next())
               {
                  ui->lineEdit_15->setText(qry.value(0).toString());
                  ui->lineEdit_16->setText(qry.value(1).toString());
                   ui->dateEdit_2->setDate(qry.value(2).toDate());
                   ui->lineEdit_17->setText(qry.value(3).toString());


               }
           }
           else
           {
               QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                       QObject::tr("Echec"),
                       QMessageBox::Cancel);
           }
}

void MainWindow::on_pushButton_22_clicked()
{





    }



void MainWindow::on_pushButton_23_clicked()
{
    QPdfWriter pdf(qApp->applicationDirPath()+"//listeemployee.pdf");

    QPainter painter(&pdf);

                     int i = 4000;


                     painter.drawText(4500,1500,"LISTE DES ACTIVITES");
                     painter.setPen(Qt::blue);
                     painter.setFont(QFont("Arial", 50));
                     painter.drawRect(2000,200,6300,2600);
                     painter.setPen(Qt::black);


                     QSqlQuery query;
                     query.prepare("select * from activites");
                     query.exec();
                     while (query.next())

                     {
                         painter.setPen(Qt::red);
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 9));
                         painter.drawRect(-50,1000+i,3600,2500);
                         painter.drawText(0,1300+i,"matricule");
                         painter.drawText(0,1600+i,"nom_activite");
                         painter.drawText(0,1900+i,"date");
                         painter.drawText(0,2200+i,"duree");



                         painter.drawText(1600,1300+i,query.value(0).toString());
                         painter.drawText(1600,1600+i,query.value(1).toString());
                         painter.drawText(1600,1900+i,query.value(2).toString());
                         painter.drawText(1600,2200+i,query.value(3).toString());
                         painter.drawText(1600,2500+i,query.value(4).toString());
                         painter.drawText(1600,2800+i,query.value(5).toString());

                         i = i +3000;
                     }

                     int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                     if (reponse == QMessageBox::Yes)
                     {
                         QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath()+"//listeemployee.pdf"));

                         painter.end();
                     }
                     if (reponse == QMessageBox::No)
                     {
                         painter.end();
                     }
}

void MainWindow::on_pushButton_24_clicked()
{
    activite a;
    QString cas = ui->lineEdit_9->text();


            ui->tableView_2->setModel(a.recherche( cas));


}

void MainWindow::on_radioButton_5_clicked()
{
    ui->tableView_2->setModel(a.tricin());

}

void MainWindow::on_pushButton_25_clicked()
{

}

