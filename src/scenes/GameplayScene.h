#ifndef SIMPLEPLATFORMER_GAMEPLAYSCENE_H
#define SIMPLEPLATFORMER_GAMEPLAYSCENE_H

#include <list>
#include <box2d/box2d.h>

#include "Scene.h"
#include "gameplay/IGameObject.h"
#include "../input/GameplayInputManager.h"
#include "../userdata/LevelDescription.h"

namespace SP::Scene {

    class GameplayScene: public Scene {
    public:
        explicit GameplayScene(SP::Game& game, const SP::Userdata::LevelDescription& levelDescription = SP::Userdata::LevelDescription::GetTestLevel());

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;

        void AdjustToWindowSize(sf::Vector2u windowSize) override;

        sf::View sceneView = sf::View(sf::Vector2f(), sf::Vector2f(30, 20));

    private:
        std::list<std::unique_ptr<SP::Scene::Gameplay::IGameObject>> gameObjects;
        b2World physicsWorld;

        SP::Input::GameplayInputManager inputManager;
    };
}

#endif //SIMPLEPLATFORMER_GAMEPLAYSCENE_H
