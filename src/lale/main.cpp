#include "application.h"

int main(int argc, char *argv[])
{
    lale::Application application(argc, argv);
    return application.exec();
}
