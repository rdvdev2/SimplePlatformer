#ifndef SIMPLEPLATFORMER_PLAYEROBJECT_H
#define SIMPLEPLATFORMER_PLAYEROBJECT_H

#include <SFML/Graphics.hpp>

#include "IGameObject.h"
#include "IPhysicsObject.h"
#include "../../input/GameplayInputManager.h"
#include "../resources/ResourceManager.h"
#include "../GameplayScene.h"

namespace SP::Scene::Gameplay {

    class PlayerObject : public IGameObject, public IPhysicsObject {
    public:
        PlayerObject(SP::Input::GameplayInputManager &inputManager, SP::Scene::Resource::ResourceManager &resourceManager, SP::Scene::GameplayScene &gameplayScene);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;

        void CreatePhysicsBody(b2World &physicsWorld) override;
        b2Body* GetPhysicsBody() override;

    private:
        SP::Input::GameplayInputManager &inputManager;
        SP::Scene::GameplayScene &gameplayScene;

        b2Body* physicsBody = nullptr;

        float timeToSwap = 0;
        int currentFrame = 0;
        sf::RectangleShape sprite0;
        sf::RectangleShape sprite1;
    };
}

#endif //SIMPLEPLATFORMER_PLAYEROBJECT_H
