#ifndef SIMPLEPLATFORMER_PLAYEROBJECT_H
#define SIMPLEPLATFORMER_PLAYEROBJECT_H

#include <SFML/Graphics.hpp>

#include "HumanoidObject.h"
#include "../../input/GameplayInputManager.h"
#include "../resources/ResourceManager.h"

namespace SP::Scene::Gameplay {

    class PlayerObject : public HumanoidObject, public b2ContactListener {
    public:
        PlayerObject(SP::Input::GameplayInputManager &inputManager, SP::Game &game);

        void Update(float deltaUTime) override;

        void CreatePhysicsBody(b2World &physicsWorld) override;

        void BeginContact(b2Contact* contact) override;
        void EndContact(b2Contact* contact) override;

        void Win();

    private:
        SP::Input::GameplayInputManager &inputManager;
        SP::Game &game;

        int footContacts = 0;
    };
}

#endif //SIMPLEPLATFORMER_PLAYEROBJECT_H
