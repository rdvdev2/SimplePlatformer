#ifndef SIMPLEPLATFORMER_LIGHTBULBOBJECT_H
#define SIMPLEPLATFORMER_LIGHTBULBOBJECT_H

#include "CollectibleObject.h"
#include "../resources/ResourceManager.h"

namespace SP::Scene::Gameplay {

    class LightBulbObject : public CollectibleObject {
    public:
        explicit LightBulbObject(SP::Scene::Resource::ResourceManager &resourceManager);

        void OnCollect(PlayerObject *playerObject) override;
    };
}


#endif //SIMPLEPLATFORMER_LIGHTBULBOBJECT_H
