#include <GApplication.h>
#include <universe/universe.h>
#include <basicnodes.h>

extern std::map<std::string, std::pair<const unsigned char*, unsigned int>> resources;

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

    std::pair<const unsigned char*, unsigned int> res = resources[":rc/images/red_room_floor.png"];
    TexturePtr texture = TexturePtr(new Texture(res.first, res.second));

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

        node->setTexture(texture);
    }

    m_universe.push_back(layer);
}
