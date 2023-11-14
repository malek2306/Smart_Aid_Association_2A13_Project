#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QString> //bib mta string
#include <QSqlQuery>  //bsh ya9ra les requettes sql
#include <QSqlQueryModel> //
#include <QDate>

class evenement
{
    QString libelle,lieu,type;
    int id_event;
    QDate datee;


public:
    evenement(); //constructeur
    evenement(int,QString,QString,QString,QDate);

    int Get_id_event(){return id_event;}
    QString Get_libelle(){return libelle;}
    QString Get_lieu(){return lieu;}
    QString Get_type(){return type;}
    QDate get_datee(){return datee ; }


    void Set_id_event(int id_event){this->id_event=id_event;}
    void Set_libelle(QString libelle){this->libelle=libelle;}
    void Set_lieu(QString lieu){this->lieu=lieu;}
    void Set_type(QString type){this->type=type;}
    void Set_datee(QDate datee){this->datee=datee;}


    bool ajouter();                //ajouter
    QSqlQueryModel * afficher();  //bsh naffichi fi interface qt
    bool supprimer(int);          // fama int khtr bsh nfass5o bl id ahna wl id hoa int
    evenement SelectModif(int);
    bool Modifer(int );

           //modifier




};
#endif // EVENNEMENT_H
