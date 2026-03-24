#pragma once
#include <QObject>
#include <rep_user_source.h>

class Notifications : public NotificationsSimpleSource
{
    Q_OBJECT
public:
    explicit Notifications(QObject *parent = nullptr);

signals:
};

