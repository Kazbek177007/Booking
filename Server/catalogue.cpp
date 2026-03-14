#include "catalogue.h"

#include "server.h"



Catalogue::Catalogue(QObject* parent) : CatalogueSimpleSource(parent)
{    
    Server* s = Server::instanse(); //Сервер может быть не создан?
    s->getrpc()->enableRemoting(this);

    setProductPreviews({ProductPreview(1, "Ball", QByteArray(), 100),
                        ProductPreview(2, "Doll", QByteArray(), 200),
                        ProductPreview(3, "Socks",QByteArray(), 500)});
}

void Catalogue::registerClient(QString clientId)
{
    qDebug() <<"New connection with Id: " << clientId;
    Server* s = Server::instanse();
    emit s->userConnected(clientId);
}
