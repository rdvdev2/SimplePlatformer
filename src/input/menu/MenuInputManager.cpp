#include "MenuInputManager.h"

void SP::Input::Menu::MenuInputManager::AddButton(SP::Input::Menu::Button* button) {
    buttonList.push_front(button);
}

void SP::Input::Menu::MenuInputManager::ClearButtons() {
    buttonList.clear();
}

bool SP::Input::Menu::MenuInputManager::IsPlayKeyPressed() {
    return IsKeyPressed(sf::Keyboard::Space) || IsKeyPressed(sf::Keyboard::Enter);
}

void SP::Input::Menu::MenuInputManager::ProcessInput() {
    for (auto button: buttonList) {
        button->ProcessInput(*this);
    }
}

