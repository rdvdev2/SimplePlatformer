#ifndef SIMPLEPLATFORMER_GAME_H
#define SIMPLEPLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include <utility>

#include "userdata/UserdataManager.h"
#include "scenes/Scene.h"
#include "scenes/resources/ResourceManager.h"

namespace SP {

    class Game {
    public:
        void Run();

        void SetNextUpdateScene(std::unique_ptr<SP::Scene::Scene> newScene);

        std::unique_ptr<sf::RenderWindow> window;
        SP::Scene::Resource::ResourceManager resourceManager;
        SP::Userdata::UserdataManager userdata;

    private:
        void Init();
        void GameLoop();
        void Cleanup();

        std::unique_ptr<SP::Scene::Scene> currentScene;
        std::unique_ptr<SP::Scene::Scene> nextUpdateScene;
    };
}

#endif //SIMPLEPLATFORMER_GAME_H
