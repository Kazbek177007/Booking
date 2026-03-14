#ifndef USER_H
#define USER_H

#include "cart.h"
#include "notifications.h"
#include "orderhistory.h"
#include "userprofile.h"

#include <QObject>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);

private:
    Cart* cart;
    UserProfile* userProfile;
    OrderHistory* orderHistory;
    Notifications* notifications;

    void registerSources();
};

#endif // USER_H
