#include <GApplication.h>
#include <universe.h>

GApplication::GApplication(int argc, char** argv)
    : Application(argc, argv)
{
}

void GApplication::initialize()
{
    Application::initialize();

    UniverseLayerPtr player(new UniverseLayer());
    player->m_root = DrawingNodePtr(new DrawingNode());

    m_universe.push_back(player);
}
