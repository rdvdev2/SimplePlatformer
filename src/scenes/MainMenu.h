#ifndef SIMPLEPLATFORMER_MAINMENU_H
#define SIMPLEPLATFORMER_MAINMENU_H

#include "UIScene.h"
#include "resources/ResourceManager.h"

namespace SP::Scene {

    class MainMenu: public UIScene {
    public:
        explicit MainMenu(Game& game);

        void Update(float deltaUTime) override;
    };
}

#endif //SIMPLEPLATFORMER_MAINMENU_H
