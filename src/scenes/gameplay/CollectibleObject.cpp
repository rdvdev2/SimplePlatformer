#include "CollectibleObject.h"

SP::Scene::Gameplay::CollectibleObject::CollectibleObject(sf::Texture *texture, int renderDepth) : GameObject(renderDepth) {
    sprite.setSize(sf::Vector2f(2, 2));
    sprite.setTexture(texture);

    auto outline = sprite.getLocalBounds();
    sprite.setOrigin(outline.left + outline.width / 2, outline.top + outline.height / 2);
}

void SP::Scene::Gameplay::CollectibleObject::Render(sf::RenderWindow &window, float deltaRTime) {
    auto renderingPos = this->GetPosition();
    renderingPos.y *= -1;
    sprite.setPosition(renderingPos);

    window.draw(sprite);
}

void SP::Scene::Gameplay::CollectibleObject::CreatePhysicsBody(b2World &physicsWorld) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.fixedRotation = true;
    physicsBody = physicsWorld.CreateBody(&bodyDef);

    physicsBody->GetUserData().pointer = (uintptr_t) this;

    // Main fixture
    b2PolygonShape shape;
    shape.SetAsBox(1, 1);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.isSensor = true;
    fixtureDef.userData.pointer = SP_FIXTURE_TYPE_COLLECTIBLE;
    physicsBody->CreateFixture(&fixtureDef);
}

b2Body *SP::Scene::Gameplay::CollectibleObject::GetPhysicsBody() {
    return physicsBody;
}
