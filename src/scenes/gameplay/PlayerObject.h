#ifndef SIMPLEPLATFORMER_PLAYEROBJECT_H
#define SIMPLEPLATFORMER_PLAYEROBJECT_H

#include <SFML/Graphics.hpp>

#include "HumanoidObject.h"
#include "../../input/GameplayInputManager.h"
#include "../resources/ResourceManager.h"

namespace SP::Scene::Gameplay {

    class PlayerObject : public HumanoidObject, public b2ContactListener {
    public:
        PlayerObject(SP::Input::GameplayInputManager &inputManager, SP::Scene::Resource::ResourceManager &resourceManager);

        void Update(float deltaUTime) override;

        void CreatePhysicsBody(b2World &physicsWorld) override;

        void BeginContact(b2Contact* contact) override;
        void EndContact(b2Contact* contact) override;

    private:
        SP::Input::GameplayInputManager &inputManager;

        int footContacts = 0;
    };
}

#endif //SIMPLEPLATFORMER_PLAYEROBJECT_H
