#ifndef SIMPLEPLATFORMER_UISCENE_H
#define SIMPLEPLATFORMER_UISCENE_H

#include <vector>
#include <memory>

#include "Scene.h"
#include "../input/ui/UIInputManager.h"

namespace SP::Scene {

    class UIScene: public Scene {
    public:
        explicit UIScene(Game& game);

        void Update(float deltaUTime) override;
        void Render(sf::RenderWindow &window, float deltaRTime) override;

    protected:
        void AddSprite(sf::RectangleShape &sprite);
        void AddText(sf::Text &text);
        void AddButton(sf::FloatRect area, SP::Input::UI::ButtonCallback callback);

        SP::Input::UI::UIInputManager inputManager;
        std::vector<std::unique_ptr<sf::Drawable>> drawables;
    };
}

#endif //SIMPLEPLATFORMER_UISCENE_H
