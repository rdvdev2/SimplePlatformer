#include "PlayerObject.h"

SP::Scene::Gameplay::PlayerObject::PlayerObject(SP::Input::GameplayInputManager &inputManager, SP::Scene::Resource::ResourceManager &resourceManager)
        : HumanoidObject(100, 3), inputManager(inputManager) {

    sprite.AddFrame(resourceManager.TexturePlayer0);
    sprite.AddFrame(resourceManager.TexturePlayer1);
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
        physicsBody->ApplyLinearImpulseToCenter(b2Vec2(0, physicsBody->GetMass() * 6), true);
    }
}

void SP::Scene::Gameplay::PlayerObject::CreatePhysicsBody(b2World &physicsWorld) {
    HumanoidObject::CreatePhysicsBody(physicsWorld);

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
}

void SP::Scene::Gameplay::PlayerObject::EndContact(b2Contact* contact) {
    auto fixtureAType = contact->GetFixtureA()->GetUserData().pointer;
    auto fixtureBType = contact->GetFixtureB()->GetUserData().pointer;

    if (fixtureAType == SP_FIXTURE_TYPE_FOOT && fixtureBType != SP_FIXTURE_TYPE_HUMANOID
     || fixtureAType != SP_FIXTURE_TYPE_HUMANOID && fixtureBType == SP_FIXTURE_TYPE_FOOT) {
        footContacts--;
    }
}
