#include "usermanager.h"

#include "server.h"

UserManager::UserManager(QObject *parent)
    : QObject{parent}
{
    connect(Server::instance(), &Server::userConnected, this, &UserManager::addUser);
}

void UserManager::addUser(QString userId)
{
    User* user = new User(userId,this);
    users[userId] = user;
    qDebug() << "User added to UserManager" << userId;
}
