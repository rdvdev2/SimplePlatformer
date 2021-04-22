#ifndef SIMPLEPLATFORMER_PLAYEROBJECT_H
#define SIMPLEPLATFORMER_PLAYEROBJECT_H

#include <SFML/Graphics.hpp>

#include "IGameObject.h"
#include "../../input/GameplayInputManager.h"
#include "../resources/ResourceManager.h"

namespace SP::Scene::Gameplay {

    class PlayerObject : public IGameObject {
    public:
        PlayerObject(SP::Input::GameplayInputManager &inputManager, SP::Scene::Resource::ResourceManager &resourceManager);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;

    private:
        SP::Input::GameplayInputManager &inputManager;

        sf::Vector2f velocity;

        float timeToSwap;
        int currentFrame;
        sf::Sprite sprite0;
        sf::Sprite sprite1;
    };
}

#endif //SIMPLEPLATFORMER_PLAYEROBJECT_H
