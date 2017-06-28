#include <GApplication.h>
#include <universe/universe.h>
#include <basicnodes.h>

GApplication::GApplication(int argc, char** argv)
    : Application(argc, argv)
{
}

void GApplication::initialize()
{
    Application::initialize();

    LayerPtr layer(new Layer());


    float w = Application::app()->universe().window().width();
    float h = Application::app()->universe().window().height();
    
    RectangleNode* node = new RectangleNode(
        w, h,
        glm::vec3(0,0,0),
        glm::vec4(1.0f,1.0f,1.0f,1.0f)
    );

    layer->appendChild(node);

    node->setTranslation(glm::vec3(100.0f, 100.0f, 0.0f));
    node->setRotation(glm::vec3(0, 0, -0.25));

    m_universe.push_back(layer);

//    glm::vec3 st = layer->spectator()->translation();
//    st.x = -200;
//    layer->spectator()->setTranslation(st);

}
