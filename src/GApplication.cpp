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

    RectangleNode* node = new RectangleNode(
        Application::app()->universe().window().width(),
        Application::app()->universe().window().height(),
        glm::vec3(0,0,0),
        glm::vec4(1.0f,1.0f,1.0f,1.0f)
    );

    layer->appendChild(node);

    node->setTranslation(glm::vec3(100.0f, 100.0f, 0.0f));

    m_universe.push_back(layer);

    glm::vec3 st = layer->spectator()->translation();
    st.x -= 100;
    layer->spectator()->setTranslation(st);

}
