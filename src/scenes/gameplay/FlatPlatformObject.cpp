#include "FlatPlatformObject.h"

SP::Scene::Gameplay::FlatPlatformObject::FlatPlatformObject(SP::Scene::Resource::ResourceManager &resourceManager) : IGameObject(0) {

    sprite.setSize(sf::Vector2f(9, 1));
    sprite.setTexture(resourceManager.TextureGround);

    auto imageOutline = sprite.getLocalBounds();
    sprite.setOrigin(imageOutline.left + imageOutline.width / 2, imageOutline.top + imageOutline.height / 2);
}

void SP::Scene::Gameplay::FlatPlatformObject::Render(sf::RenderWindow &window, float deltaRTime) {
    auto correctedPos = this->GetPosition();
    correctedPos.y *= -1;
    sprite.setPosition(correctedPos);

    window.draw(sprite);
}

void SP::Scene::Gameplay::FlatPlatformObject::CreatePhysicsBody(b2World &physicsWorld) {
    b2BodyDef bodyDef;
    bodyDef.position.Set(position.x, position.y);
    physicsBody = physicsWorld.CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(4.5, 0.5);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.userData.pointer = SP_FIXTURE_TYPE_GROUND;
    physicsBody->CreateFixture(&shape, 0.0f);
}

b2Body* SP::Scene::Gameplay::FlatPlatformObject::GetPhysicsBody() {
    return physicsBody;
}


