#include "database.h"
#include "server.h"

int main(int argc, char* argv[])
{
    Server s(argc, argv);
    if(!Database::instance().open()) return 1;
    return s.exec();
}
