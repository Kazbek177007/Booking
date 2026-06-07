#include "admin.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    Admin a(argc, argv);

    return Admin::exec();
}
