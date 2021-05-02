#ifndef SIMPLEPLATFORMER_FLATPLATFORMOBJECT_H
#define SIMPLEPLATFORMER_FLATPLATFORMOBJECT_H

#include "GameObject.h"
#include "IPhysicsObject.h"
#include "../resources/ResourceManager.h"

namespace SP::Scene::Gameplay {

    class FlatPlatformObject : public GameObject, public IPhysicsObject {
    public:
        explicit FlatPlatformObject(SP::Scene::Resource::ResourceManager &resourceManager);

        void Render(sf::RenderWindow &window, float deltaRTime) override;

        void CreatePhysicsBody(b2World &world) override;
        b2Body* GetPhysicsBody() override;

    private:
        b2Body* physicsBody = nullptr;

        sf::RectangleShape sprite;
    };
}

#endif //SIMPLEPLATFORMER_FLATPLATFORMOBJECT_H
