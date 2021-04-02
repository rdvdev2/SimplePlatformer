#ifndef SIMPLEPLATFORMER_BUTTON_H
#define SIMPLEPLATFORMER_BUTTON_H

#include <SFML/Graphics.hpp>
#include "../InputManager.h"

namespace SP::Input::Menu {

    typedef void (*ButtonCallback)(void* data);

    class Button {
    public:
        Button(sf::IntRect area, ButtonCallback callback, void* callbackData) : area(area), callback(callback), callbackData(callbackData) {}

        void ProcessInput(InputManager& inputManager);
        void UpdateArea(sf::IntRect newArea);

    private:
        sf::IntRect area;
        ButtonCallback callback;
        void* callbackData;
        bool clicked = false;
    };
}

#endif //SIMPLEPLATFORMER_BUTTON_H
