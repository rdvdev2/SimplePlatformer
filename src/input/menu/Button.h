#ifndef SIMPLEPLATFORMER_BUTTON_H
#define SIMPLEPLATFORMER_BUTTON_H

#include <SFML/Graphics.hpp>
#include "../InputManager.h"

namespace SP::Input::Menu {

    typedef void (*ButtonCallback)();

    class Button {
    public:
        Button(sf::IntRect area, ButtonCallback callback) : area(area), callback(callback) {}

        void ProcessInput(InputManager& inputManager);
        void UpdateArea(sf::IntRect newArea);

    private:
        sf::IntRect area;
        ButtonCallback callback;
        bool clicked = false;
    };
}

#endif //SIMPLEPLATFORMER_BUTTON_H
