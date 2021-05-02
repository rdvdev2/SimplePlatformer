#ifndef SIMPLEPLATFORMER_GAMEPLAYINPUTMANAGER_H
#define SIMPLEPLATFORMER_GAMEPLAYINPUTMANAGER_H

#include "InputManager.h"

namespace SP::Input {

class GameplayInputManager : public SP::Input::InputManager {
public:
    using InputManager::InputManager;

    bool IsLeft();
    bool IsRight();
    bool IsJump();
    };
}

#endif //SIMPLEPLATFORMER_GAMEPLAYINPUTMANAGER_H
