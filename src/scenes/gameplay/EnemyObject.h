#ifndef SIMPLEPLATFORMER_ENEMYOBJECT_H
#define SIMPLEPLATFORMER_ENEMYOBJECT_H

#include "../../util/IUpdateable.h"

namespace SP::Scene::Gameplay {

    class EnemyObject : public SP::Util::IUpdateable {
    public:
    private:
        void Update(float deltaUTime) override;
    };
}

#endif //SIMPLEPLATFORMER_ENEMYOBJECT_H
