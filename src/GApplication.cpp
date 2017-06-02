#include <GApplication.h>

GApplication::GApplication(int argc, char** argv)
    : Application(argc, argv)
{
}

void GApplication::initialize()
{
    Application::initialize();
    m_universe.push_back(UniverseLayer());
}
