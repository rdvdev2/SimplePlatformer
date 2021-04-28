#ifndef SIMPLEPLATFORMER_IPHYSICSOBJECT_H
#define SIMPLEPLATFORMER_IPHYSICSOBJECT_H

#include <box2d/box2d.h>

#define SP_FIXTURE_TYPE_GROUND 1
#define SP_FIXTURE_TYPE_PLAYER 2
#define SP_FIXTURE_TYPE_FOOT 3

namespace SP::Scene::Gameplay {

    class IPhysicsObject {
    public:
        virtual void CreatePhysicsBody(b2World &physicsWorld) = 0;
        virtual b2Body* GetPhysicsBody() = 0;
    };
}

#endif //SIMPLEPLATFORMER_IPHYSICSOBJECT_H
