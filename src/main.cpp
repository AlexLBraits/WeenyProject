#include <GApplication.h>

int main(int argc, char** argv)
{
    GApplication& app = Singleton<GApplication>::getInstance(argc, argv);
    return app.exec();
}
