#ifndef SIMPLEPLATFORMER_INPUTMANAGER_H
#define SIMPLEPLATFORMER_INPUTMANAGER_H

#include <SFML/Graphics.hpp>

namespace SP::Input {

    class InputManager {
    public:
        explicit InputManager(sf::RenderWindow& window) : window(window) {};

        bool IsKeyPressed(sf::Keyboard::Key key);
        bool IsMouseButtonPressed(sf::Mouse::Button button);
        sf::Vector2f GetMousePosition();

        bool IsLMB();
        bool IsMMB();
        bool IsRMB();

        bool IsExit();

    private:
        sf::RenderWindow& window;
    };
}

#endif //SIMPLEPLATFORMER_INPUTMANAGER_H
