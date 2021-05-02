#include "GameplayInputManager.h"

bool SP::Input::GameplayInputManager::IsLeft() {
    return IsKeyPressed(sf::Keyboard::Left) || IsKeyPressed(sf::Keyboard::A);
}

bool SP::Input::GameplayInputManager::IsRight() {
    return IsKeyPressed(sf::Keyboard::Right) || IsKeyPressed(sf::Keyboard::D);
}

bool SP::Input::GameplayInputManager::IsJump() {
    return IsKeyPressed(sf::Keyboard::Up) || IsKeyPressed(sf::Keyboard::W) || IsKeyPressed(sf::Keyboard::Space);
}

