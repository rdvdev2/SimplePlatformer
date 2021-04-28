#ifndef SIMPLEPLATFORMER_SCENE_H
#define SIMPLEPLATFORMER_SCENE_H

#include <SFML/Graphics.hpp>

namespace SP {
    class Game;
}

namespace SP::Scene {

    class Scene {
    public:
        explicit Scene(Game& game): game(game) {};

        virtual void Update(float deltaUTime) = 0;
        virtual void Render(sf::RenderWindow &window, float deltaRTime) = 0;

        virtual void AdjustToWindowSize(sf::Vector2u windowSize) {}

        SP::Game& game;
    };
}

#endif //SIMPLEPLATFORMER_SCENE_H
