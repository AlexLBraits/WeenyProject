#include <GApplication.h>
#include <universe.h>
#include <basicnodes.h>

GApplication::GApplication(int argc, char** argv)
    : Application(argc, argv)
{
}

void GApplication::initialize()
{
    Application::initialize();

    UniverseLayerPtr layer(new UniverseLayer());

    for (int i = 0; i < 2048; ++i)
    { /// 2048 X 1536
        RectangleNode* node = new RectangleNode(
            glm::linearRand(256,512),
            glm::linearRand(192,384),
            glm::vec3(
                glm::linearRand(0,2048),
                glm::linearRand(0,1536),
                0
            ),
            glm::vec4(
                glm::linearRand(0.0,1.0),
                glm::linearRand(0.0,1.0),
                glm::linearRand(0.0,1.0),
                1
            )
        );
        layer->appendChild(node);
    }

    m_universe.push_back(layer);
}
