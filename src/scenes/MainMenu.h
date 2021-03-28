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

        void OnWindowResize(sf::Vector2u windowSize) override;

    private:
        void AdjustToWindowSize(sf::Vector2u windowSize);

        SP::Input::Menu::MenuInputManager inputManager;
        SP::Input::Menu::Button* playButton;

        sf::Sprite backgroundSprite;
        sf::Sprite playButtonSprite;
        sf::Text titleText;
        sf::Text authorsText;
    };
}

#endif //SIMPLEPLATFORMER_MAINMENU_H
