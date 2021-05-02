#ifndef SIMPLEPLATFORMER_LIGHTNINGOBJECT_H
#define SIMPLEPLATFORMER_LIGHTNINGOBJECT_H

#include "CollectibleObject.h"
#include "../resources/ResourceManager.h"
#include "../GameplayScene.h"

namespace SP::Scene::Gameplay {

    class LightningObject : public CollectibleObject {
    public:
        explicit LightningObject(SP::Scene::GameplayScene &scene);

        void OnCollect(PlayerObject *playerObject) override;

    private:
        SP::Scene::GameplayScene &scene;
    };
}

#endif //SIMPLEPLATFORMER_LIGHTNINGOBJECT_H
