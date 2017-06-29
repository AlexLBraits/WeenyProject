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

    for(int i = 0; i < 4500; ++i )
    {
        RectangleNode* node = new RectangleNode(
            glm::linearRand(0.5f * w, w),
            glm::linearRand(0.5f * h, h),
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec4(
                glm::linearRand(0.0f, 1.0f),
                glm::linearRand(0.0f, 1.0f),
                glm::linearRand(0.0f, 1.0f),
                1.0f
            )
        );

        layer->appendChild(node);

        node->setTranslation(
                             glm::vec3(
                                       glm::linearRand(0.0f, 0.5f * w),
                                       glm::linearRand(0.0f, 0.5f * h),
                                       1.0f*i
                                       )
                             );
        node->setRotation(
                          glm::vec3(
                                    0,
                                    0,
                                    glm::linearRand(-0.25f, 0.25f)
                                    )
                          );
    }


    m_universe.push_back(layer);
}
