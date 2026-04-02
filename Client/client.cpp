#include "client.h"

Client::Client(int& argc, char** argv): QApplication(argc, argv)
{
    rpc.connectToNode(QUrl("tcp://127.0.0.1:9999"));
    catalogue.reset(rpc.acquire<CatalogueReplica>());
    qDebug() << "Client is trying to connect";
}

