#ifndef SIMPLEPLATFORMER_INPUTMANAGER_H
#define SIMPLEPLATFORMER_INPUTMANAGER_H

#include <SFML/Window.hpp>

namespace SP::Input {

    class InputManager {
    public:
        explicit InputManager(sf::Window& window) : window(window) {};

        bool IsKeyPressed(sf::Keyboard::Key key);
        bool IsMouseButtonPressed(sf::Mouse::Button button);
        sf::Vector2i GetMousePosition();

        bool IsLMB();
        bool IsMMB();
        bool IsRMB();

    private:
        sf::Window& window;
    };
}

#endif //SIMPLEPLATFORMER_INPUTMANAGER_H
