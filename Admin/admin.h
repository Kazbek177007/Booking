#ifndef ADMIN_H
#define ADMIN_H

#include <QApplication>
#include <QObject>
#include <qremoteobjectnode.h>

class Admin : public QApplication
{
    Q_OBJECT
public:
    Admin(int& argc, char** argv);
    static Admin* instance(){return static_cast<Admin*>(QApplication::instance());}

private:
    QRemoteObjectNode rpc;
};

#endif // ADMIN_H
