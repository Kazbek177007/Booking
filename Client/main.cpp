#include "catalogue.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QRemoteObjectNode repNode;
    repNode.connectToNode(QUrl(QStringLiteral("local:replica")));

    QSharedPointer<CatalogueReplica> ptr(repNode.acquire<CatalogueReplica>());;

    Catalogue catalogue(ptr);
    catalogue.show();

    return a.exec();
}
