#include "PlayerObject.h"

SP::Scene::Gameplay::PlayerObject::PlayerObject(SP::Input::GameplayInputManager &inputManager, SP::Scene::Resource::ResourceManager &resourceManager)
        : IGameObject(100), inputManager(inputManager), sprite(sf::Vector2f(1, 2), 3) {

    sprite.AddFrame(resourceManager.TexturePlayer0);
    sprite.AddFrame(resourceManager.TexturePlayer1);

    /*auto imageOutline = sprite.getLocalBounds();
    sprite0.setOrigin(imageOutline.left + imageOutline.width / 2, imageOutline.top + imageOutline.height / 2);
    imageOutline = sprite1.getLocalBounds();
    sprite1.setOrigin(imageOutline.left + imageOutline.width / 2, imageOutline.top + imageOutline.height / 2);*/
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

void SP::Scene::Gameplay::PlayerObject::Render(sf::RenderWindow &window, float deltaRTime) {
    auto renderingPos = this->GetPosition();
    renderingPos.y *= -1;
    sprite.setPosition(renderingPos);

    if (physicsBody->GetLinearVelocity().x > 0) {
        sprite.setScale(-std::abs(sprite.getScale().x), sprite.getScale().y);
    } else if (physicsBody->GetLinearVelocity().x < 0) {
        sprite.setScale(std::abs(sprite.getScale().x), sprite.getScale().y);
    }

    sprite.UpdateRenderClock(deltaRTime);
    window.draw(sprite);
}

void SP::Scene::Gameplay::PlayerObject::CreatePhysicsBody(b2World &physicsWorld) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.fixedRotation = true;
    physicsBody = physicsWorld.CreateBody(&bodyDef);

    // Main fixture
    b2PolygonShape shape;
    shape.SetAsBox(0.5f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.4f;
    fixtureDef.userData.pointer = SP_FIXTURE_TYPE_PLAYER;
    physicsBody->CreateFixture(&fixtureDef);

    // Foot sensor fixture
    shape.SetAsBox(0.25f, 0.1f, b2Vec2(0, -1), 0);
    fixtureDef.isSensor = true;
    fixtureDef.userData.pointer = SP_FIXTURE_TYPE_FOOT;
    physicsBody->CreateFixture(&fixtureDef);

    // Register contact listener
    physicsWorld.SetContactListener(this);
}

b2Body* SP::Scene::Gameplay::PlayerObject::GetPhysicsBody() {
    return physicsBody;
}

void SP::Scene::Gameplay::PlayerObject::BeginContact(b2Contact* contact) {
    auto fixtureAType = contact->GetFixtureA()->GetUserData().pointer;
    auto fixtureBType = contact->GetFixtureB()->GetUserData().pointer;

    if (fixtureAType == SP_FIXTURE_TYPE_FOOT && fixtureBType != SP_FIXTURE_TYPE_PLAYER) {
        footContacts++;
    }
}

void SP::Scene::Gameplay::PlayerObject::EndContact(b2Contact* contact) {
    auto fixtureAType = contact->GetFixtureA()->GetUserData().pointer;
    auto fixtureBType = contact->GetFixtureB()->GetUserData().pointer;

    if (fixtureAType == SP_FIXTURE_TYPE_FOOT && fixtureBType != SP_FIXTURE_TYPE_PLAYER) {
        footContacts--;
    }
}
