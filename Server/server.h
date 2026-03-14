#pragma once

#include "catalogue.h"
#include "usermanager.h"
#include <QCoreApplication>
#include <QObject>

class Server : public QCoreApplication
{
    Q_OBJECT
public:
    Server(int &argc, char **argv);

    static Server* instanse();
    QRemoteObjectHost* getrpc(){return rpc;}

private:
    QRemoteObjectHost* rpc;
    UserManager* userManager;
    Catalogue* catalogue;

signals:
    void userConnected(QString userId);

};

