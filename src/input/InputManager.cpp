#include "InputManager.h"

bool SP::Input::InputManager::IsKeyPressed(sf::Keyboard::Key key) {
    return window.hasFocus() && sf::Keyboard::isKeyPressed(key);
}

bool SP::Input::InputManager::IsMouseButtonPressed(sf::Mouse::Button button) {
    return window.hasFocus() && sf::Mouse::isButtonPressed(button);
}

sf::Vector2f SP::Input::InputManager::GetMousePosition() {
    return window.mapPixelToCoords(sf::Mouse::getPosition(window));
}


bool SP::Input::InputManager::IsLMB() {
    return IsMouseButtonPressed(sf::Mouse::Left);
}

bool SP::Input::InputManager::IsMMB() {
    return IsMouseButtonPressed(sf::Mouse::Middle);
}

bool SP::Input::InputManager::IsRMB() {
    return IsMouseButtonPressed(sf::Mouse::Right);
}

bool SP::Input::InputManager::IsExit() {
    return IsKeyPressed(sf::Keyboard::Escape);
}