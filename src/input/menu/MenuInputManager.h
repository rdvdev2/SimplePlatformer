#ifndef SIMPLEPLATFORMER_MENUINPUTMANAGER_H
#define SIMPLEPLATFORMER_MENUINPUTMANAGER_H

#include <list>

#include "../InputManager.h"
#include "Button.h"

namespace SP::Input::Menu {

    class MenuInputManager : public InputManager {
    public:
        using InputManager::InputManager;

        void AddButton(Button* button);
        void ClearButtons();

        void ProcessInput();

    private:
        std::list<Button*> buttonList;
    };
}

#endif //SIMPLEPLATFORMER_MENUINPUTMANAGER_H