#include "catalogue.h"
#include "client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Client c(argc, argv);
    return c.exec();
}
