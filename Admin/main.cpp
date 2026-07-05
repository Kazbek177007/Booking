#include "admin.h"
#include "adminmainwindow.h"

int main(int argc, char* argv[])
{
    Admin a(argc, argv);

    AdminMainWindow w;
    w.show();

    return Admin::exec();
}
