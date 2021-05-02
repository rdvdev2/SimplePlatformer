#include "PlayerObject.h"
#include "ZombieObject.h"
#include "../../Game.h"
#include "CollectibleObject.h"
#include "../GameEndScene.h"

SP::Scene::Gameplay::PlayerObject::PlayerObject(SP::Input::GameplayInputManager &inputManager, SP::Game &game)
        : HumanoidObject(100, 3), inputManager(inputManager), game(game) {

    sprite.AddFrame(game.resourceManager.TexturePlayer0);
    sprite.AddFrame(game.resourceManager.TexturePlayer1);
}

void SP::Scene::Gameplay::PlayerObject::Update(float deltaUTime) {

    // Horizontal movement
    auto horizontalVelocity = physicsBody->GetLinearVelocity().x;
    float desiredVelocity = 0;
    if (inputManager.IsLeft()) {
        desiredVelocity -= 5;
    }
    if (inputManager.IsRight()) {
        desiredVelocity += 5;
    }
    auto velocityChange = desiredVelocity - horizontalVelocity;
    auto impulse = physicsBody->GetMass() * velocityChange;
    physicsBody->ApplyLinearImpulseToCenter(b2Vec2(impulse, 0), true);

    if (inputManager.IsJump() && footContacts > 0 && physicsBody->GetLinearVelocity().y <= 0) { // Jump key && Grounded && Not jumping yet
        physicsBody->ApplyLinearImpulseToCenter(b2Vec2(0, physicsBody->GetMass() * 10), true);
    }
}

void SP::Scene::Gameplay::PlayerObject::CreatePhysicsBody(b2World &physicsWorld) {
    HumanoidObject::CreatePhysicsBody(physicsWorld);

    physicsBody->GetUserData().pointer = (uintptr_t) this;

    // Foot sensor fixture
    b2PolygonShape shape;
    shape.SetAsBox(0.25f, 0.1f, b2Vec2(0, -1), 0);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.isSensor = true;
    fixtureDef.userData.pointer = SP_FIXTURE_TYPE_FOOT;
    physicsBody->CreateFixture(&fixtureDef);

    // Register contact listener
    physicsWorld.SetContactListener(this);
}

void SP::Scene::Gameplay::PlayerObject::BeginContact(b2Contact* contact) {
    auto fixtureAType = contact->GetFixtureA()->GetUserData().pointer;
    auto fixtureBType = contact->GetFixtureB()->GetUserData().pointer;

    if (fixtureAType == SP_FIXTURE_TYPE_FOOT && fixtureBType != SP_FIXTURE_TYPE_HUMANOID
     || fixtureAType != SP_FIXTURE_TYPE_HUMANOID && fixtureBType == SP_FIXTURE_TYPE_FOOT) {
        footContacts++;
    }

    auto objectA = contact->GetFixtureA()->GetBody()->GetUserData();
    auto objectB = contact->GetFixtureB()->GetBody()->GetUserData();

    GameObject* collidedWith;
    if (objectA.pointer == (uintptr_t) this) {
        collidedWith = reinterpret_cast<GameObject*>(objectB.pointer);
    } else if (objectB.pointer == (uintptr_t) this) {
        collidedWith = reinterpret_cast<GameObject*>(objectA.pointer);
    } else return;

    auto enemy = dynamic_cast<EnemyObject*>(collidedWith);
    if (enemy) {
        this->Lose();
    }

    auto collectible = dynamic_cast<CollectibleObject*>(collidedWith);
    if (collectible) {
        collectible->OnCollect(this);
    }
}

void SP::Scene::Gameplay::PlayerObject::EndContact(b2Contact* contact) {
    auto fixtureAType = contact->GetFixtureA()->GetUserData().pointer;
    auto fixtureBType = contact->GetFixtureB()->GetUserData().pointer;

    if (fixtureAType == SP_FIXTURE_TYPE_FOOT && fixtureBType != SP_FIXTURE_TYPE_HUMANOID
     || fixtureAType != SP_FIXTURE_TYPE_HUMANOID && fixtureBType == SP_FIXTURE_TYPE_FOOT) {
        footContacts--;
    }
}

void SP::Scene::Gameplay::PlayerObject::Win() {
    game.SetNextUpdateScene(std::make_unique<GameEndScene>(game, true, score));
}

void SP::Scene::Gameplay::PlayerObject::Lose() {
    game.SetNextUpdateScene(std::make_unique<GameEndScene>(game, false, score));
}
