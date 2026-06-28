#include "client.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Client c(argc, argv);
    MainWindow mainwindow;
    mainwindow.show();
    return c.exec();
}
