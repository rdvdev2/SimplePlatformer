#ifndef SIMPLEPLATFORMER_COLLECTIBLEOBJECT_H
#define SIMPLEPLATFORMER_COLLECTIBLEOBJECT_H

#include "GameObject.h"
#include "IPhysicsObject.h"
#include "PlayerObject.h"

namespace SP::Scene::Gameplay {

    class CollectibleObject : public GameObject, public IPhysicsObject {
    public:
        CollectibleObject(sf::Texture *texture, int renderDepth);

        void Render(sf::RenderWindow &window, float deltaRTime) override;

        void CreatePhysicsBody(b2World &physicsWorld) override;
        b2Body *GetPhysicsBody() override;

        virtual void OnCollect(PlayerObject* playerObject) = 0;

    protected:
        b2Body* physicsBody = nullptr;
        sf::RectangleShape sprite;
    };
}


#endif //SIMPLEPLATFORMER_COLLECTIBLEOBJECT_H
