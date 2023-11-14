#include "connection.h"
#include "QSqlDatabase"

Connection::Connection()
{

}

bool Connection::createConnection(){
    bool test=false;                                                  /*declaration */
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("ma");
    db.setPassword("malek");
    if(db.open())
    {
        test=true;
    }

    return test;

}
