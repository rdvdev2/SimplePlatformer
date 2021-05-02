#ifndef SIMPLEPLATFORMER_GOOMBAOBJECT_H
#define SIMPLEPLATFORMER_GOOMBAOBJECT_H

#include "EnemyObject.h"
#include "GameObject.h"
#include "../resources/ResourceManager.h"
#include "../drawables/AnimatedSprite.h"
#include "IPhysicsObject.h"

namespace SP::Scene::Gameplay {

    class GoombaObject : public GameObject, public EnemyObject, public IPhysicsObject {
    public:
        explicit GoombaObject(SP::Scene::Resource::ResourceManager &resourceManager);

        void Render(sf::RenderWindow &window, float deltaRTime) override;

        void CreatePhysicsBody(b2World &physicsWorld) override;
        b2Body *GetPhysicsBody() override;

    private:
        b2Body* physicsBody = nullptr;
        SP::Scene::Drawable::AnimatedSprite sprite;
    };
}

#endif //SIMPLEPLATFORMER_GOOMBAOBJECT_H
