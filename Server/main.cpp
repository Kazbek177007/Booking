#include "database.h"
#include "server.h"

int main(int argc, char* argv[])
{
    if(!Database::instance().open()) return 1;
    Server s(argc, argv);
    return s.exec();
}
