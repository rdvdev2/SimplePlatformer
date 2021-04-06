#include "GameplayScene.h"

SP::Scene::GameplayScene::GameplayScene(SP::Game &game) : Scene(game) {

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
        gameObject.Render(deltaRTime, sf::Transform::Identity);
    }
}

void SP::Scene::GameplayScene::OnWindowResize(sf::Vector2u windowSize) {
    // TODO: Calculate view transform
}
