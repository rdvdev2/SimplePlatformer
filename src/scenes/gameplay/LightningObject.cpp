#include "LightningObject.h"
#include "../../Game.h"

SP::Scene::Gameplay::LightningObject::LightningObject(SP::Scene::GameplayScene &scene)
        : CollectibleObject(scene.game.resourceManager.TextureLightning, 10), scene(scene) {

}

void SP::Scene::Gameplay::LightningObject::OnCollect(SP::Scene::Gameplay::PlayerObject *playerObject) {
    playerObject->score++;
    this->markedForDeletion = true;
}
