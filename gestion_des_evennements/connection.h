#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>  /* connectio m3a base de donne*/
#include <QSqlError>     /* y9ra l erreur */
#include <QSqlQuery>     /* bc y9ra les requetes */

class Connection
{   QSqlDatabase db;
public:
    Connection();
    bool createConnection();
};



#endif // CONNECTION_H
