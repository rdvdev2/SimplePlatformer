#ifndef SIMPLEPLATFORMER_BACKGROUNDPARALLAXOBJECT_H
#define SIMPLEPLATFORMER_BACKGROUNDPARALLAXOBJECT_H

#include "IGameObject.h"
#include "../resources/ResourceManager.h"

namespace SP::Scene::Gameplay {

    class BackgroundParallaxObject : public IGameObject {
    public:
        explicit BackgroundParallaxObject(SP::Scene::Resource::ResourceManager &resourceManager);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;

    private:
        sf::Sprite layer0;
        sf::Sprite layer2;
    };
}

#endif //SIMPLEPLATFORMER_BACKGROUNDPARALLAXOBJECT_H
