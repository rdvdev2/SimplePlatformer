#ifndef SIMPLEPLATFORMER_PLAYEROBJECT_H
#define SIMPLEPLATFORMER_PLAYEROBJECT_H

#include <SFML/Graphics.hpp>

#include "IGameObject.h"
#include "IPhysicsObject.h"
#include "../../input/GameplayInputManager.h"
#include "../resources/ResourceManager.h"
#include "../GameplayScene.h"

namespace SP::Scene::Gameplay {

    class PlayerObject : public IGameObject, public IPhysicsObject, public b2ContactListener {
    public:
        PlayerObject(SP::Input::GameplayInputManager &inputManager, SP::Scene::Resource::ResourceManager &resourceManager);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;

        void CreatePhysicsBody(b2World &physicsWorld) override;
        b2Body* GetPhysicsBody() override;

        void BeginContact(b2Contact* contact) override;
        void EndContact(b2Contact* contact) override;

    private:
        SP::Input::GameplayInputManager &inputManager;

        b2Body* physicsBody = nullptr;
        int footContacts = 0;

        float timeToSwap = 0;
        int currentFrame = 0;
        sf::RectangleShape sprite0;
        sf::RectangleShape sprite1;
    };
}

#endif //SIMPLEPLATFORMER_PLAYEROBJECT_H
