#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include "evenement.cpp"
#include <QMessageBox> // bib bsh tatina les messages erreur w ila succe
MainWindow::MainWindow(QWidget *parent)  //constructeur mta graphique lhajet li tji automatique fl affichage
    : QMainWindow(parent),

     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->line_id->setValidator( new QIntValidator(100, 999999, this)); //controle de saisie
    QRegExp rx("[a-zA-Z]+");
        QValidator *validator = new
                QRegExpValidator(rx,this);
        ui->line_libelle->setValidator(validator);
        ui->line_lieu->setValidator(validator);
        ui->line_type->setValidator(validator);
    ui->event->setModel(e.afficher()); //par defaut affichage
}
MainWindow::~MainWindow()  //destructeur yfregh memoire
{
    delete ui;
}


void MainWindow::on_pushButton_afficher_clicked()
{
     ui->event->setModel(e.afficher());
}

void MainWindow::on_pushButton_clicked()//houni tzid l verif
{
    int id_event=ui->line_id->text().toInt();
      QString libelle=ui->line_libelle->text();
      QString lieu=ui->line_lieu->text();
      QString type=ui->line_type->text();
    QDate datee=ui->dateEdit->date();

       evenement e(id_event,libelle,lieu,type,datee);

       bool test=e.ajouter();
       QMessageBox msgBox;

         if(test)
           {  msgBox.setText("Ajout avec succes.");
             ui->event->setModel(e.afficher());
         }
         else
            { msgBox.setText("Echec d'ajout");}

       msgBox.exec();
}



void MainWindow::on_pushButton_supp_clicked()
{
    evenement e;
    e.Set_id_event(ui->line_id->text().toInt());
        bool test=e.supprimer(e.Get_id_event()); //get tjbed beha
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
        ui->event->setModel(e.afficher());

        }
        else
           { msgBox.setText("Echec de suppression");}


        msgBox.exec();
}

void MainWindow::on_event_activated(const QModelIndex & index)//taatih id w yrecuperi les donnes
{

        int id_event=ui->line_id->text().toInt(); //njbd fyh m lineedit
        evenement e;



        e=e.SelectModif(id_event);

       ui->line_id->setText(QString(QString::number(e.Get_id_event())));
       ui->line_libelle->setText(QString(e.Get_libelle()));
       ui->line_lieu->setText(QString(e.Get_lieu()));
       ui->line_type->setText(QString(e.Get_type()));
       ui->dateEdit->setDate(QDate(e.get_datee()));

}

void MainWindow::on_pushButton_modif_clicked()
{


        int id_event=ui->line_id->text().toInt();
        QString libelle=ui->line_libelle->text();
        QString lieu=ui->line_lieu->text();
        QString type=ui->line_type->text();
        QDate datee=ui->dateEdit->date();
        bool test=false;


        evenement e(id_event,libelle,lieu,type,datee);
        test=e.Modifer(id_event);

        if(test==true)
        {
          QMessageBox::information(nullptr,QObject::tr("ok"),
          QObject::tr("Modifier avec success\n""click ok to exit"),QMessageBox::Ok);
          ui->event->setModel(e.afficher()); //affichage automatique apres modification


        }
        else
        {

                QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                QObject::tr("modification non effectue\n""click cancel to exit"),QMessageBox::Cancel);

        }
}
