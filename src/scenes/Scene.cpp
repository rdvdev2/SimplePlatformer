#include "Scene.h"
#include "../Game.h"

SP::Scene::Scene::Scene(SP::Game &game): game(game) {
    game.window->setView(view);
}

void SP::Scene::Scene::AdjustToWindowSize(sf::Vector2u windowSize) {
    sf::FloatRect viewport(0, 0, 1, 1);

    float screenWidth = windowSize.x / view.getSize().x;
    float screenHeight = windowSize.y / view.getSize().y;

    if (screenWidth > screenHeight) {
        viewport.width = screenHeight / screenWidth;
        viewport.left = (1 - viewport.width) / 2;
    } else if (screenWidth < screenHeight) {
        viewport.height = screenWidth / screenHeight;
        viewport.top = (1 - viewport.height) / 2;
    }

    view.setViewport(viewport);
    game.window->setView(view);
}
