#ifndef SIMPLEPLATFORMER_IPHYSICSOBJECT_H
#define SIMPLEPLATFORMER_IPHYSICSOBJECT_H

#include <box2d/box2d.h>

namespace SP::Scene::Gameplay {

    class IPhysicsObject {
    public:
        virtual void CreatePhysicsBody(b2World &physicsWorld) = 0;
        virtual b2Body* GetPhysicsBody() = 0;
    };
}

#endif //SIMPLEPLATFORMER_IPHYSICSOBJECT_H
