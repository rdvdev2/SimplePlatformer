#include "HumanoidObject.h"

SP::Scene::Gameplay::HumanoidObject::HumanoidObject(int renderDepth, float animationFps): IGameObject(renderDepth), sprite(sf::Vector2f(1, 2), animationFps) {

}

void SP::Scene::Gameplay::HumanoidObject::Render(sf::RenderWindow &window, float deltaRTime) {
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

void SP::Scene::Gameplay::HumanoidObject::CreatePhysicsBody(b2World &physicsWorld) {
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
    fixtureDef.userData.pointer = SP_FIXTURE_TYPE_HUMANOID;
    physicsBody->CreateFixture(&fixtureDef);
}

b2Body *SP::Scene::Gameplay::HumanoidObject::GetPhysicsBody() {
    return physicsBody;
}
