#include <GApplication.h>
#include <universe.h>

GApplication::GApplication(int argc, char** argv)
    : Application(argc, argv)
{
}

void GApplication::initialize()
{
    Application::initialize();

    UniverseLayerPtr layer(new UniverseLayer());
    layer->appendChild(new DrawingNode());

    m_universe.push_back(layer);
}
