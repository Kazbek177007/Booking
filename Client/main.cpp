#include "client.h"
#include "mainwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    Client c(argc, argv);
    std::cout << "Hello world";
    MainWindow mainwindow;
    mainwindow.show();
    return c.exec();
}
