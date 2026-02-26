#include <QCoreApplication>
#include "catalogue.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Catalogue srcCatalogue;
    QRemoteObjectHost srcNode(QUrl(QStringLiteral("local:replica")));
    srcNode.enableRemoting(&srcCatalogue);


    return a.exec();
}
