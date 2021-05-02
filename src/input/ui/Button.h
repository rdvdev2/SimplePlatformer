#ifndef SIMPLEPLATFORMER_BUTTON_H
#define SIMPLEPLATFORMER_BUTTON_H

#include <SFML/Graphics.hpp>
#include "../InputManager.h"

namespace SP::Input::UI {

    typedef void (*ButtonCallback)(void* data);

    class Button {
    public:
        Button(sf::FloatRect area, ButtonCallback callback, void* callbackData) : area(area), callback(callback), callbackData(callbackData) {}

        void ProcessInput(InputManager& inputManager);

    private:
        sf::FloatRect area;
        ButtonCallback callback;
        void* callbackData;
        bool clicked = false;
    };
}

#endif //SIMPLEPLATFORMER_BUTTON_H
