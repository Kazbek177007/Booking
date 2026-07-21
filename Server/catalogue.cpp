#include "catalogue.h"
#include "server.h"

Catalogue::Catalogue(QObject* parent) : CatalogueSimpleSource(parent)
{
    Server* s = Server::instance();
    s->getrpc()->enableRemoting(this);
    qDebug() << "server is lauched";
}



void Catalogue::registerClient(QString clientId)
{
    qDebug() <<"New login with Id: " << clientId;
    Server* s = Server::instance();
    emit s->userConnected(clientId);
}
