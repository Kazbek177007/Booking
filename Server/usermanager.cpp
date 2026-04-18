#include "usermanager.h"

#include "server.h"

UserManager::UserManager(QObject *parent)
    : QObject{parent}
{
    connect(Server::instance(), &Server::userConnected, this, &UserManager::addUser);
}

void UserManager::addUser(QString userId)
{
    if (users.contains(userId))
    {
        qWarning() << "User with Id" << userId << "is existing";
        return;
    }
    User* user = new User(userId,this);
    users[userId] = user;
    qDebug() << "User added to UserManager" << userId;
}
