#pragma once
#include <QApplication>
#include <QObject>
#include <qremoteobjectnode.h>
#include "rep_admin_replica.h"


class Admin : public QApplication
{
    Q_OBJECT
public:
    Admin(int& argc, char** argv);
    static Admin* instance(){return static_cast<Admin*>(QApplication::instance());}
    QSharedPointer<ListOfProductsReplica> listOfProducts;

private:
    QRemoteObjectNode rpc;
};

