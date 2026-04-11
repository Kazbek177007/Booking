#include "client.h"

Client::Client(int& argc, char** argv): QApplication(argc, argv)
{
    rpc.connectToNode(QUrl("tcp://127.0.0.1:9999"));
    catalogue.reset(rpc.acquire<CatalogueReplica>());
    qDebug() << "Client is trying to connect";
}

void Client::login(QString clientId)
{
    catalogue->registerClient(clientId);
    cart.reset(rpc.acquire<CartReplica>(clientId+"/cart"));
    userProfile.reset(rpc.acquire<UserProfileReplica>(clientId+"/userProfile"));
    orderHistory.reset(rpc.acquire<OrderHistoryReplica>(clientId+"/orderHistory"));
    notifications.reset(rpc.acquire<NotificationsReplica>(clientId+"/notifications"));
}

