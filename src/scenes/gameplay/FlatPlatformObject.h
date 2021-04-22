#ifndef SIMPLEPLATFORMER_FLATPLATFORMOBJECT_H
#define SIMPLEPLATFORMER_FLATPLATFORMOBJECT_H

#include "IGameObject.h"
#include "ICollidable.h"
#include "../resources/ResourceManager.h"

namespace SP::Scene::Gameplay {

    class FlatPlatformObject : public IGameObject, public ICollidable {
    public:
        explicit FlatPlatformObject(SP::Scene::Resource::ResourceManager &resourceManager);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;

        sf::FloatRect GetColliderBox() override;

    private:
        sf::FloatRect colliderBox = sf::FloatRect();

        sf::Sprite sprite;
    };
}

#endif //SIMPLEPLATFORMER_FLATPLATFORMOBJECT_H
