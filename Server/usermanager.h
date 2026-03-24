#pragma once
#include "user.h"
#include <QObject>

class UserManager : public QObject
{
    Q_OBJECT
public:
    explicit UserManager(QObject *parent = nullptr);

private:
    QMap<QString, User*> users;

public slots:
    void addUser(QString userId);

};

