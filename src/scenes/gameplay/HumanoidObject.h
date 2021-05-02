#ifndef SIMPLEPLATFORMER_HUMANOIDOBJECT_H
#define SIMPLEPLATFORMER_HUMANOIDOBJECT_H

#include "GameObject.h"
#include "IPhysicsObject.h"
#include "../GameplayScene.h"
#include "../drawables/AnimatedSprite.h"

namespace SP::Scene::Gameplay {

    class HumanoidObject : public GameObject, public IPhysicsObject {
    public:
        explicit HumanoidObject(int renderDepth, float animationFps);

        void Render(sf::RenderWindow &window, float deltaRTime) override;

        void CreatePhysicsBody(b2World &physicsWorld) override;
        b2Body *GetPhysicsBody() override;

    protected:
        b2Body* physicsBody = nullptr;
        SP::Scene::Drawable::AnimatedSprite sprite;
    };
}

#endif //SIMPLEPLATFORMER_HUMANOIDOBJECT_H
