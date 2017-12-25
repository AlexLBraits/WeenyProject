#include <application.h>

int main(int argc, char** argv)
{
    Application& app = Singleton<Application>::getInstance(argc, argv);
    return app.exec();
}
