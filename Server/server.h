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

private:
    UserManager* userManager;
    Catalogue* catalogue;
    QRemoteObjectHost* rpc;
};

