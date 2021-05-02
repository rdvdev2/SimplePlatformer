#ifndef SIMPLEPLATFORMER_SCENE_H
#define SIMPLEPLATFORMER_SCENE_H

#include <SFML/Graphics.hpp>

namespace SP {
    class Game;
}

namespace SP::Scene {

    class Scene {
    public:
        explicit Scene(Game& game);

        virtual void Update(float deltaUTime) = 0;
        virtual void Render(sf::RenderWindow &window, float deltaRTime) = 0;

        virtual void AdjustToWindowSize(sf::Vector2u windowSize);

        SP::Game& game;

    protected:
        sf::View view = sf::View(sf::Vector2f(), sf::Vector2f(30, 20));
    };
}

#endif //SIMPLEPLATFORMER_SCENE_H
