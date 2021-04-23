#include "GameplayScene.h"
#include "../Game.h"
#include "gameplay/PlayerObject.h"
#include "gameplay/FlatPlatformObject.h"
#include "gameplay/BackgroundParallaxObject.h"

SP::Scene::GameplayScene::GameplayScene(SP::Game &game) : Scene(game), inputManager(*game.window) {
    game.window->setView(sceneView);
    gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::PlayerObject>(inputManager, game.resourceManager, *this));
    gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::FlatPlatformObject>(game.resourceManager));
    gameObjects.back()->SetPosition(sf::Vector2f(0, -100));
    gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::BackgroundParallaxObject>(game.resourceManager));
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

sf::Vector2f SP::Scene::GameplayScene::ComputeCollisionsOf(SP::Scene::Gameplay::ICollidable &collidableObject) {
    sf::Vector2f totalCollision;

    for (auto&& gameObject: gameObjects) {
        auto _collidableObject = dynamic_cast<SP::Scene::Gameplay::ICollidable*>(gameObject.get());
        if (_collidableObject == nullptr || _collidableObject == &collidableObject) continue;

        sf::FloatRect collisionRect;
        if (collidableObject.GetColliderBox().intersects(_collidableObject->GetColliderBox(), collisionRect)) {
            sf::Vector2f collisionVector(collisionRect.width, collisionRect.height);

            if (collisionVector.x == collidableObject.GetColliderBox().width) collisionVector.x = 0;
            else if (collidableObject.GetColliderBox().left > _collidableObject->GetColliderBox().left) collisionVector.x *= -1;

            if (collisionVector.y == collidableObject.GetColliderBox().height) collisionVector.y = 0;
            else if (collidableObject.GetColliderBox().top < _collidableObject->GetColliderBox().top) collisionVector.y *= -1;

            totalCollision += collisionVector;
        }
    }

    return totalCollision;
}
