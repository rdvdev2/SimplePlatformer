#ifndef SIMPLEPLATFORMER_GAMEENDSCENE_H
#define SIMPLEPLATFORMER_GAMEENDSCENE_H

#include "UIScene.h"

namespace SP::Scene {

    class GameEndScene : public UIScene {
    public:
        GameEndScene(Game& game, bool won, int score);

        void Update(float deltaUTime) override;
    };
}

#endif //SIMPLEPLATFORMER_GAMEENDSCENE_H
