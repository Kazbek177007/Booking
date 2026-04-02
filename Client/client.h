#pragma once
#include <QApplication>
#include <QObject>
#include "rep_user_replica.h"
#include "rep_catalogue_replica.h"

class Client : public QApplication
{
    Q_OBJECT
public:
    Client(int& argc, char** argv);
    static Client* instanse(){return static_cast<Client*>(QApplication::instance());}
    QSharedPointer<CatalogueReplica> catalogue;
    //login(),

private:
    QRemoteObjectNode rpc;
    QSharedPointer<CartReplica> cart;
    QSharedPointer<UserProfileReplica> userProfile;
    QSharedPointer<OrderHistoryReplica> orderHistory;
    QSharedPointer<NotificationsReplica> notifications;
    QString username;
};

