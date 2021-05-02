#include "ZombieObject.h"

SP::Scene::Gameplay::ZombieObject::ZombieObject(SP::Scene::Resource::ResourceManager &resourceManager)
        : HumanoidObject(90, 3) {

    sprite.AddFrame(resourceManager.TextureZombie0);
    sprite.AddFrame(resourceManager.TextureZombie1);
}
