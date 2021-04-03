#ifndef SIMPLEPLATFORMER_GAMEPLAYSCENE_H
#define SIMPLEPLATFORMER_GAMEPLAYSCENE_H

#include "Scene.h"

namespace SP::Scene {

    class GameplayScene: public Scene {
    public:
        explicit GameplayScene(SP::Game& game);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;
        void OnWindowResize(sf::Vector2u windowSize) override;
    };
}

#endif //SIMPLEPLATFORMER_GAMEPLAYSCENE_H
