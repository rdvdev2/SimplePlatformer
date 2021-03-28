#ifndef SIMPLEPLATFORMER_MAINMENU_H
#define SIMPLEPLATFORMER_MAINMENU_H

#include "Scene.h"
#include "resources/ResourceManager.h"
#include "../input/menu/MenuInputManager.h"

namespace SP::Scene {

    class MainMenu: public Scene {
    public:
        explicit MainMenu(Resource::ResourceManager& resourceManager, sf::Window& window);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow *window, float deltaRTime) override;

    private:
        SP::Input::Menu::MenuInputManager inputManager;
    };
}

#endif //SIMPLEPLATFORMER_MAINMENU_H
