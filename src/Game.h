#ifndef SIMPLEPLATFORMER_GAME_H
#define SIMPLEPLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include <utility>

#include "userdata/UserdataManager.h"
#include "scenes/MainMenu.h"
#include "scenes/resources/ResourceManager.h"

namespace SP {

    class Game {
    public:
        void Run();

    private:
        void Init();
        void GameLoop();
        void Cleanup();

        std::unique_ptr<sf::RenderWindow> window;

        SP::Userdata::UserdataManager userdata;
        SP::Scene::Resource::ResourceManager resourceManager;
        std::unique_ptr<SP::Scene::Scene> currentScene;
    };
}

#endif //SIMPLEPLATFORMER_GAME_H
