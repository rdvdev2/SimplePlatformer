#include "FlatPlatformObject.h"

SP::Scene::Gameplay::FlatPlatformObject::FlatPlatformObject(SP::Scene::Resource::ResourceManager &resourceManager) : IGameObject(0) {

    sprite.setTexture(resourceManager.TextureGround);
    sprite.scale(5, 5);
}

void SP::Scene::Gameplay::FlatPlatformObject::Render(sf::RenderWindow &window, float deltaRTime) {
    auto imageOutline = sprite.getLocalBounds();
    sprite.setOrigin(imageOutline.left + imageOutline.width / 2, imageOutline.top + imageOutline.height / 2);

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
    shape.SetAsBox(50.0f, 10.0f);
    physicsBody->CreateFixture(&shape, 0.0f);
}

b2Body* SP::Scene::Gameplay::FlatPlatformObject::GetPhysicsBody() {
    return physicsBody;
}


