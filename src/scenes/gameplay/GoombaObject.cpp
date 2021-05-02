#include "GoombaObject.h"

SP::Scene::Gameplay::GoombaObject::GoombaObject(SP::Scene::Resource::ResourceManager &resourceManager)
        : GameObject(80), sprite(sf::Vector2f(1, 1), 3) {

    sprite.AddFrame(resourceManager.TextureGoomba0);
    sprite.AddFrame(resourceManager.TextureGoomba1);
}

void SP::Scene::Gameplay::GoombaObject::Render(sf::RenderWindow &window, float deltaRTime) {
    auto renderingPos = this->GetPosition();
    renderingPos.y *= -1;
    sprite.setPosition(renderingPos);

    sprite.UpdateRenderClock(deltaRTime);
    window.draw(sprite);
}

void SP::Scene::Gameplay::GoombaObject::CreatePhysicsBody(b2World &physicsWorld) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.fixedRotation = true;
    physicsBody = physicsWorld.CreateBody(&bodyDef);

    physicsBody->GetUserData().pointer = (uintptr_t) this;

    // Main fixture
    b2PolygonShape shape;
    shape.SetAsBox(0.5f, 0.5f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.4f;
    fixtureDef.userData.pointer = SP_FIXTURE_TYPE_GOOMBA;
    physicsBody->CreateFixture(&fixtureDef);
}

b2Body *SP::Scene::Gameplay::GoombaObject::GetPhysicsBody() {
    return physicsBody;
}
