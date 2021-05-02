#include "Button.h"

void SP::Input::UI::Button::ProcessInput(SP::Input::InputManager& inputManager) {
    if (clicked) {
        if (!inputManager.IsLMB()) clicked = false;
    } else {
        if (inputManager.IsLMB() && area.contains(inputManager.GetMousePosition())) {
            clicked = true;
            callback(callbackData);
        }
    }
}
