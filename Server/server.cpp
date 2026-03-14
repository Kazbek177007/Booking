#include "server.h"

Server::Server(int &argc, char **argv):QCoreApplication(argc, argv),
    userManager(new UserManager(this)),
    rpc(new QRemoteObjectHost(QUrl("tcp://0.0.0.0:9999"), this)),
    catalogue(new Catalogue(this))
{

}

Server* Server::instanse()
{
    return static_cast<Server*>(QCoreApplication::instance());
}


