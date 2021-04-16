#include "GameplayScene.h"
#include "../Game.h"

SP::Scene::GameplayScene::GameplayScene(SP::Game &game) : Scene(game) {
    game.window->setView(sceneView);
}

void SP::Scene::GameplayScene::Update(float deltaUTime) {
    gameObjects.sort(
            [](const SP::Scene::Gameplay::IGameObject& a, const SP::Scene::Gameplay::IGameObject& b)
            { return a.GetRenderDepth() < b.GetRenderDepth(); });

    for (auto gameObject: gameObjects) {
        gameObject.Update(deltaUTime);
    }
}

void SP::Scene::GameplayScene::Render(sf::RenderWindow &window, float deltaRTime) {
    for (auto gameObject: gameObjects) {
        gameObject.Render(deltaRTime);
    }
}
