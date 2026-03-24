#include "client.h"

Client::Client(int& argc, char** argv): QApplication(argc, argv)
{
    rpc.connectToNode(QUrl("tcp://localhost:9999"));
    catalogue.reset(rpc.acquire<CatalogueReplica>());
}

