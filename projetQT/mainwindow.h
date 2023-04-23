#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "coach.h"
#include "activite.h"
#include <QMainWindow>
#include <QMainWindow>
#include <QMainWindow>
#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QSqlQuery>
#include <QDateTime>
#include <QFile>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_pushButton_10_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_9_clicked();

    void on_ajouter_clicked();



    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_ajouter_as_clicked();

    void on_supprimerA_clicked();

    void on_modifierA_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_14_clicked();

    void on_pushButton_19_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_radioButton_5_clicked();

    void on_pushButton_25_clicked();

    void on_selectImageButton_clicked();



    void on_qrcodegen_clicked();

private:
    Ui::MainWindow *ui;

    coach c;
    activite a;
    QString m_imageFilename;

};
#endif // MAINWINDOW_H
