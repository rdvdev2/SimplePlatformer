#ifndef SIMPLEPLATFORMER_BACKGROUNDPARALLAXOBJECT_H
#define SIMPLEPLATFORMER_BACKGROUNDPARALLAXOBJECT_H

#include "GameObject.h"
#include "../resources/ResourceManager.h"

namespace SP::Scene::Gameplay {

    class BackgroundParallaxObject : public GameObject {
    public:
        explicit BackgroundParallaxObject(SP::Scene::Resource::ResourceManager &resourceManager);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;

    private:
        sf::RectangleShape layer0;
        sf::RectangleShape layer2;
    };
}

#endif //SIMPLEPLATFORMER_BACKGROUNDPARALLAXOBJECT_H
