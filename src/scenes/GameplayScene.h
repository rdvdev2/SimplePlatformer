#ifndef SIMPLEPLATFORMER_GAMEPLAYSCENE_H
#define SIMPLEPLATFORMER_GAMEPLAYSCENE_H

#include <list>
#include <box2d/box2d.h>

#include "Scene.h"
#include "gameplay/GameObject.h"
#include "../input/GameplayInputManager.h"
#include "../userdata/LevelDescription.h"

namespace SP::Scene {

    class GameplayScene: public Scene {
    public:
        explicit GameplayScene(SP::Game& game, const SP::Userdata::LevelDescription& levelDescription);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;

        std::list<std::unique_ptr<SP::Scene::Gameplay::GameObject>> gameObjects;
        b2World physicsWorld;

    private:
        SP::Input::GameplayInputManager inputManager;
    };
}

#endif //SIMPLEPLATFORMER_GAMEPLAYSCENE_H
