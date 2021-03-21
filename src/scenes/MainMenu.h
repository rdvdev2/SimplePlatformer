#ifndef SIMPLEPLATFORMER_MAINMENU_H
#define SIMPLEPLATFORMER_MAINMENU_H

#include "Scene.h"
#include "resources/ResourceManager.h"

namespace SP::Scene {

    class MainMenu: public Scene {
    public:
        MainMenu(SP::Scene::Resource::ResourceManager resourceManager);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow *window, float deltaRTime) override;
    };
}

#endif //SIMPLEPLATFORMER_MAINMENU_H
