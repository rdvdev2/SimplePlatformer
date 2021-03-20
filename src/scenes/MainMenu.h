#ifndef SIMPLEPLATFORMER_MAINMENU_H
#define SIMPLEPLATFORMER_MAINMENU_H

#include "Scene.h"

namespace SP::Scene {

    class MainMenu: public Scene {
    public:
        MainMenu();

        void update(float deltaUTime) override;
        void render(sf::RenderWindow *window, float deltaRTime) override;
    };
}

#endif //SIMPLEPLATFORMER_MAINMENU_H
