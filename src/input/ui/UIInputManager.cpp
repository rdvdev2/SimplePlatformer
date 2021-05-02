#include "UIInputManager.h"

void SP::Input::UI::UIInputManager::AddButton(SP::Input::UI::Button &button) {
    buttonList.push_front(std::make_unique<Button>(button));
}

void SP::Input::UI::UIInputManager::ClearButtons() {
    buttonList.clear();
}

bool SP::Input::UI::UIInputManager::IsPlayKeyPressed() {
    return IsKeyPressed(sf::Keyboard::Space) || IsKeyPressed(sf::Keyboard::Enter);
}

void SP::Input::UI::UIInputManager::ProcessInput() {
    for (auto&& button: buttonList) {
        button->ProcessInput(*this);
    }
}

