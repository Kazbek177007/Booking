#include "user.h"

#include "server.h"

User::User(QString id,QObject *parent)
    : QObject{parent},
    id(id),
    cart(new Cart(id,this)),
    userProfile(new UserProfile(id,this)),
    orderHistory(new OrderHistory(id,this)),
    notifications(new Notifications(id,this))
{
    Server* s = Server::instance();
    s->getrpc()->enableRemoting(cart, id+"/cart");
    s->getrpc()->enableRemoting(userProfile, id+"/userProfile");
    s->getrpc()->enableRemoting(orderHistory, id+"/orderHistory");
    s->getrpc()->enableRemoting(notifications, id+"/notifications");
    qDebug() << "User added" << id;
}
