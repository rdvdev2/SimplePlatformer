#ifndef SIMPLEPLATFORMER_GAMEPLAYSCENE_H
#define SIMPLEPLATFORMER_GAMEPLAYSCENE_H

#include <list>

#include "Scene.h"
#include "gameplay/IGameObject.h"

namespace SP::Scene {

    class GameplayScene: public Scene {
    public:
        explicit GameplayScene(SP::Game& game);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;
        void OnWindowResize(sf::Vector2u windowSize) override;

    private:
        std::list<SP::Scene::Gameplay::IGameObject> gameObjects;
    };
}

#endif //SIMPLEPLATFORMER_GAMEPLAYSCENE_H
