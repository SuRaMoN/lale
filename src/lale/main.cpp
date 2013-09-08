#include "app/application.h"

int main(int argc, char *argv[])
{
    lale::app::Application application(argc, argv);
    return application.exec();
}
