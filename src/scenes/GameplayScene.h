#ifndef SIMPLEPLATFORMER_GAMEPLAYSCENE_H
#define SIMPLEPLATFORMER_GAMEPLAYSCENE_H

#include <list>

#include "Scene.h"
#include "gameplay/IGameObject.h"
#include "../input/GameplayInputManager.h"

namespace SP::Scene {

    class GameplayScene: public Scene {
    public:
        explicit GameplayScene(SP::Game& game);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;

        sf::View sceneView = sf::View(sf::Vector2f(), sf::Vector2f(512, 384));

    private:
        std::list<SP::Scene::Gameplay::IGameObject> gameObjects;

        SP::Input::GameplayInputManager inputManager;
    };
}

#endif //SIMPLEPLATFORMER_GAMEPLAYSCENE_H
