#include "server.h"

Server::Server(int &argc, char **argv):QCoreApplication(argc, argv),
    userManager(new UserManager(this)),
    rpc(new QRemoteObjectHost(QUrl("tcp://127.0.0.1:9999"), this)),
    catalogue(new Catalogue(this))
{

}

Server* Server::instance()
{
    return static_cast<Server*>(QCoreApplication::instance());
}


