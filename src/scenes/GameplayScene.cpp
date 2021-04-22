#include "GameplayScene.h"
#include "../Game.h"
#include "gameplay/PlayerObject.h"

SP::Scene::GameplayScene::GameplayScene(SP::Game &game) : Scene(game), inputManager(*game.window) {
    game.window->setView(sceneView);
    gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::PlayerObject>(inputManager, game.resourceManager));
}

void SP::Scene::GameplayScene::Update(float deltaUTime) {
    if (inputManager.IsPause()) {
        game.Close();
    }

    gameObjects.sort(
            [](const std::unique_ptr<SP::Scene::Gameplay::IGameObject>& a, const std::unique_ptr<SP::Scene::Gameplay::IGameObject>& b)
            { return a->GetRenderDepth() < b->GetRenderDepth(); });

    for (auto&& gameObject: gameObjects) {
        gameObject->Update(deltaUTime);
    }
}

void SP::Scene::GameplayScene::Render(sf::RenderWindow &window, float deltaRTime) {
    for (auto&& gameObject: gameObjects) {
        gameObject->Render(window, deltaRTime);
    }
}
