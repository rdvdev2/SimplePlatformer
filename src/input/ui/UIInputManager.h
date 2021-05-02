#ifndef SIMPLEPLATFORMER_UIINPUTMANAGER_H
#define SIMPLEPLATFORMER_UIINPUTMANAGER_H

#include <list>
#include <memory>

#include "../InputManager.h"
#include "Button.h"

namespace SP::Input::UI {

    class UIInputManager : public InputManager {
    public:
        using InputManager::InputManager;

        void AddButton(Button &button);
        void ClearButtons();

        bool IsPlayKeyPressed();

        void ProcessInput();

    private:
        std::list<std::unique_ptr<Button>> buttonList;
    };
}

#endif //SIMPLEPLATFORMER_UIINPUTMANAGER_H