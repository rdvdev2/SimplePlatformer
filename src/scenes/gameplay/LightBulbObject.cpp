#include "LightBulbObject.h"

SP::Scene::Gameplay::LightBulbObject::LightBulbObject(SP::Scene::Resource::ResourceManager &resourceManager)
        : CollectibleObject(resourceManager.TextureLightBulb, 20) {

}


void SP::Scene::Gameplay::LightBulbObject::OnCollect(SP::Scene::Gameplay::PlayerObject *playerObject) {
    playerObject->Win();
}