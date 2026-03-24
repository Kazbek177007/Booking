#pragma once
#include <QObject>
#include <rep_user_source.h>

class UserProfile : public UserProfileSimpleSource
{
    Q_OBJECT
public:
    explicit UserProfile(QObject *parent = nullptr);

signals:
};

