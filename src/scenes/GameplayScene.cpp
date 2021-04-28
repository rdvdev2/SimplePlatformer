#include "GameplayScene.h"
#include "../Game.h"
#include "gameplay/PlayerObject.h"
#include "gameplay/FlatPlatformObject.h"
#include "gameplay/BackgroundParallaxObject.h"

SP::Scene::GameplayScene::GameplayScene(SP::Game &game) : Scene(game), inputManager(*game.window), physicsWorld(b2Vec2(0.0f, -9.8f)) {
    game.window->setView(sceneView);
    gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::PlayerObject>(inputManager, game.resourceManager, *this));
    gameObjects.back()->SetPosition(sf::Vector2f(0, 3));
    gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::FlatPlatformObject>(game.resourceManager));
    gameObjects.back()->SetPosition(sf::Vector2f(0, 0));
    gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::BackgroundParallaxObject>(game.resourceManager));

    for (auto&& gameObject: gameObjects) {
        auto physicsObject = dynamic_cast<SP::Scene::Gameplay::IPhysicsObject*>(gameObject.get());
        if (physicsObject) {
            physicsObject->CreatePhysicsBody(physicsWorld);
        }
    }
}

void SP::Scene::GameplayScene::Update(float deltaUTime) {
    if (inputManager.IsPause()) {
        game.Close();
    }

    physicsWorld.Step(deltaUTime, 6, 2);

    gameObjects.sort(
            [](const std::unique_ptr<SP::Scene::Gameplay::IGameObject>& a, const std::unique_ptr<SP::Scene::Gameplay::IGameObject>& b)
            { return a->GetRenderDepth() < b->GetRenderDepth(); });

    for (auto&& gameObject: gameObjects) {
        auto physicsObject = dynamic_cast<SP::Scene::Gameplay::IPhysicsObject*>(gameObject.get());
        if (physicsObject) {
            auto newPos = physicsObject->GetPhysicsBody()->GetPosition();
            gameObject->SetPosition(sf::Vector2f(newPos.x, newPos.y));
        }

        gameObject->Update(deltaUTime);
    }
}

void SP::Scene::GameplayScene::Render(sf::RenderWindow &window, float deltaRTime) {
    for (auto&& gameObject: gameObjects) {
        gameObject->Render(window, deltaRTime);
    }
}

void SP::Scene::GameplayScene::OnWindowResize(sf::Vector2u windowSize) {
    sf::FloatRect viewport(0, 0, 1, 1);

    float screenWidth = windowSize.x / sceneView.getSize().x;
    float screenHeight = windowSize.y / sceneView.getSize().y;

    if (screenWidth > screenHeight) {
        viewport.width = screenHeight / screenWidth;
        viewport.left = (1 - viewport.width) / 2;
    } else if (screenWidth < screenHeight) {
        viewport.height = screenWidth / screenHeight;
        viewport.top = (1 - viewport.height) / 2;
    }

    sceneView.setViewport(viewport);
    game.window->setView(sceneView);
}
