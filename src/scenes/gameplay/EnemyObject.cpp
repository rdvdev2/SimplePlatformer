#include "EnemyObject.h"
#include "IPhysicsObject.h"

void SP::Scene::Gameplay::EnemyObject::Update(float deltaUTime) {
    auto physicsObject = dynamic_cast<IPhysicsObject*>(this);
    if (!physicsObject) return;
    auto physicsBody = physicsObject->GetPhysicsBody();

    // TODO: Implement enemy movement here
}
