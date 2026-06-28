#include "admin.h"

Admin::Admin(int& argc, char** argv) : QApplication(argc, argv)
{
    rpc.connectToNode(QUrl("tcp://127.0.0.1:9999"));
    listOfProducts.reset(rpc.acquire<ListOfProductsReplica>());
    qDebug() << "Admin is trying to connect";
}
