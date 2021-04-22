#ifndef SIMPLEPLATFORMER_PLAYEROBJECT_H
#define SIMPLEPLATFORMER_PLAYEROBJECT_H

#include <SFML/Graphics.hpp>

#include "IGameObject.h"
#include "ICollidable.h"
#include "../../input/GameplayInputManager.h"
#include "../resources/ResourceManager.h"

namespace SP::Scene::Gameplay {

    class PlayerObject : public IGameObject, public ICollidable {
    public:
        PlayerObject(SP::Input::GameplayInputManager &inputManager, SP::Scene::Resource::ResourceManager &resourceManager);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;

        sf::FloatRect GetColliderBox() override;

    private:
        SP::Input::GameplayInputManager &inputManager;

        float mass = 1;
        sf::Vector2f force;
        sf::Vector2f velocity;

        sf::FloatRect colliderBox = sf::FloatRect();

        float timeToSwap = 0;
        int currentFrame = 0;
        sf::Sprite sprite0;
        sf::Sprite sprite1;
    };
}

#endif //SIMPLEPLATFORMER_PLAYEROBJECT_H
