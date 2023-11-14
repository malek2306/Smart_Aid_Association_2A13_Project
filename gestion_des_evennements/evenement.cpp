#include "connection.h"
#include "QSqlDatabase"
#include "evenement.h"
#include<QtDebug>
 //QObject est la classe de base de tous les objets Qt
evenement::evenement()  //constructeur par defaut
{
    this->id_event=0;
    this->libelle=" ";
    this->lieu=" ";
    this->type=" " ;
    this->datee=   QDate::currentDate() ;
}


evenement::evenement(int id_event, QString libelle ,  QString lieu,QString type, QDate datee) //constructeur parametré
{
    this->id_event=id_event;
    this->libelle=libelle;
    this->lieu=lieu;
    this->type=type;
    this->datee=datee;



}
QSqlQueryModel * evenement::afficher() // fournir des données pour afficher des classes telles que QTableView
{
    QSqlQueryModel * model= new QSqlQueryModel();//instantiation ml bib hedhk esmha model
         model->setQuery("SELECT * FROM EVENEMENTS");//reset ll model
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_event"));//bsh twarina l jadwal mnadham
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("lieu"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("datee"));
    return model;
}


bool evenement::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id_event);

    query.prepare("INSERT INTO EVENEMENTS(id_event, libelle, lieu,type,datee) "
                  "VALUES (:id_event, :libelle, :lieu,:type,:datee)");
    query.bindValue(":id_event", id_string); //bindvalue sert a inserer les donnes
    query.bindValue(":libelle", libelle);
    query.bindValue(":lieu", lieu);
    query.bindValue(":type", type);
    query.bindValue(":datee", datee);
    return query.exec();


}

bool evenement::supprimer(int id_event)
{
    QSqlQuery query;
    QString res=QString::number(id_event);
    query.prepare("Delete from evenements where id_event=:id_event");
    query.bindValue(":id_event",res);
    return query.exec();
}


evenement evenement ::SelectModif(int id_event)
{

    QSqlQuery query; //dec variable querry de type sql querry
    QString res=QString::number(id_event); //bsh nbadlo id ll type string w nhotouh f res
    query.prepare("Select * from evenements where id_event=:id_event"); //prepare hya fonc predefenie t9ra l requette
    query.bindValue(":id_event",res); //t9oul li id event hya nafsha res
    query.exec(); //exec bch texecuti l select li fl prepare
    query.next(); // next bch tetaada li baadou
    int id_eventval=query.value(0).toInt(); //ejbd loula id w thenya libelle b tartib yjbed ml bse de donnes
    QString libelleval=query.value(1).toString();
    QString lieuval=query.value(2).toString();
    QString typeval=query.value(3).toString();
    QDate dateeval=query.value(4).toDate();

    evenement e (id_eventval,libelleval,lieuval,typeval,dateeval); //instan

    return e;
}


bool evenement::Modifer(int id_event)
{
    QSqlQuery query;
    QString  id_event_string=QString::number( id_event);

    query.prepare("UPDATE EVENEMENTS SET libelle= :libelle, lieu= :lieu,type= :type,datee= :datee where id_event=:id_event");
    query.bindValue(":id_event", id_event_string); //n9olo kol haja equivalente l shnoa
    query.bindValue(":libelle", libelle);
    query.bindValue(":lieu", lieu);
    query.bindValue(":type", type);
    query.bindValue(":datee", datee);
    return query.exec(); //returnina l execution

}



















