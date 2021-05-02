#include "GameplayScene.h"
#include "../Game.h"
#include "gameplay/PlayerObject.h"
#include "gameplay/FlatPlatformObject.h"
#include "gameplay/BackgroundParallaxObject.h"
#include "gameplay/ZombieObject.h"
#include "gameplay/GoombaObject.h"
#include "gameplay/LightBulbObject.h"
#include "gameplay/LightningObject.h"

SP::Scene::GameplayScene::GameplayScene(SP::Game &game, const SP::Userdata::LevelDescription& levelDescription) : Scene(game), inputManager(*game.window), physicsWorld(b2Vec2(0.0f, -9.8f)) {
    // Objects from the level description
    for (auto descriptor: levelDescription.objects) {
        switch (descriptor.type) {
            case Userdata::LevelDescription::PLAYER:
                gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::PlayerObject>(inputManager, game));
                break;
            case Userdata::LevelDescription::ZOMBIE:
                gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::ZombieObject>(game.resourceManager));
                break;
            case Userdata::LevelDescription::GOOMBA:
                gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::GoombaObject>(game.resourceManager));
                break;
            case Userdata::LevelDescription::FLAT_PLATFORM:
                gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::FlatPlatformObject>(game.resourceManager));
                break;
            case Userdata::LevelDescription::LIGHT_BULB:
                gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::LightBulbObject>(game.resourceManager));
                break;
            case Userdata::LevelDescription::LIGHTNING:
                gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::LightningObject>(*this));
                break;
            default:
                continue; // Shouldn't happen, but we never know
        }
        gameObjects.back()->SetPosition(sf::Vector2f(descriptor.x, descriptor.y));
    }

    // Default objects
    gameObjects.push_back(std::make_unique<SP::Scene::Gameplay::BackgroundParallaxObject>(game.resourceManager));

    for (auto&& gameObject: gameObjects) {
        auto physicsObject = dynamic_cast<SP::Scene::Gameplay::IPhysicsObject*>(gameObject.get());
        if (physicsObject) {
            physicsObject->CreatePhysicsBody(physicsWorld);
        }
    }
}

void SP::Scene::GameplayScene::Update(float deltaUTime) {
    if (inputManager.IsExit()) {
        game.Close();
    }

    physicsWorld.Step(deltaUTime, 6, 2);

    gameObjects.sort(
            [](const std::unique_ptr<SP::Scene::Gameplay::GameObject>& a, const std::unique_ptr<SP::Scene::Gameplay::GameObject>& b)
            { return a->GetRenderDepth() < b->GetRenderDepth(); });

    for (auto& gameObject: gameObjects) {
        auto physicsObject = dynamic_cast<SP::Scene::Gameplay::IPhysicsObject*>(gameObject.get());
        if (physicsObject) {
            if (gameObject->markedForDeletion) physicsWorld.DestroyBody(physicsObject->GetPhysicsBody());
            auto newPos = physicsObject->GetPhysicsBody()->GetPosition();
            gameObject->SetPosition(sf::Vector2f(newPos.x, newPos.y));
        }

        if (gameObject->markedForDeletion) {
            gameObjects.remove(gameObject);
            continue;
        }

        auto player = dynamic_cast<SP::Scene::Gameplay::PlayerObject*>(gameObject.get());
        if (player) {
            auto viewPos = player->GetPosition();
            viewPos.y *= -1;
            view.setCenter(viewPos);
            game.window->setView(view);
        }

        gameObject->Update(deltaUTime);
    }
}

void SP::Scene::GameplayScene::Render(sf::RenderWindow &window, float deltaRTime) {
    for (auto&& gameObject: gameObjects) {
        gameObject->Render(window, deltaRTime);
    }
}
