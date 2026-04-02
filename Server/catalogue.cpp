#include "catalogue.h"
#include "server.h"

Catalogue::Catalogue(QObject* parent) : CatalogueSimpleSource(parent)
{
    Server* s = Server::instanse();
    s->getrpc()->enableRemoting(this);
    qDebug() << "server is lauched";
    QFile photo1 ("C:/Users/Руслан/Desktop/png-transparent-football-soccer-sports-ball-game.png");
    photo1.open(QIODevice::ReadOnly);
    setProductPreviews({ProductPreview(1, "Ball", photo1.readAll(), 100),
                        ProductPreview(2, "Doll", QByteArray(), 200),
                        ProductPreview(3, "Socks",QByteArray(), 500)});
}

void Catalogue::registerClient(QString clientId)
{
    qDebug() <<"New login with Id: " << clientId;
    Server* s = Server::instanse();
    emit s->userConnected(clientId);
}
