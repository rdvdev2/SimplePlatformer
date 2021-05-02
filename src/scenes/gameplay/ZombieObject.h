#ifndef SIMPLEPLATFORMER_ZOMBIEOBJECT_H
#define SIMPLEPLATFORMER_ZOMBIEOBJECT_H

#include "HumanoidObject.h"
#include "../resources/ResourceManager.h"

namespace SP::Scene::Gameplay {

    class ZombieObject : public HumanoidObject {
    public:
        explicit ZombieObject(SP::Scene::Resource::ResourceManager &resourceManager);
    };
}

#endif //SIMPLEPLATFORMER_ZOMBIEOBJECT_H
