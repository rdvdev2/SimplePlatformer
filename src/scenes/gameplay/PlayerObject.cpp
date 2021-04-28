#include "PlayerObject.h"

#include <cmath>

#define ANIMATION_FPS 3
#define ANIMATION_FRAMES 2

SP::Scene::Gameplay::PlayerObject::PlayerObject(SP::Input::GameplayInputManager &inputManager, SP::Scene::Resource::ResourceManager &resourceManager, SP::Scene::GameplayScene &gameplayScene)
        : IGameObject(100), inputManager(inputManager), gameplayScene(gameplayScene) {

    sprite0.setTexture(resourceManager.TexturePlayer0);
    sprite1.setTexture(resourceManager.TexturePlayer1);
}

void SP::Scene::Gameplay::PlayerObject::Update(float deltaUTime) {
    // TODO: Controls
}

void SP::Scene::Gameplay::PlayerObject::Render(sf::RenderWindow &window, float deltaRTime) {

    // TODO: Set origin on window resize?
    auto imageOutline = sprite0.getLocalBounds();
    sprite0.setOrigin(imageOutline.left + imageOutline.width / 2, imageOutline.top + imageOutline.height / 2);
    imageOutline = sprite1.getLocalBounds();
    sprite1.setOrigin(imageOutline.left + imageOutline.width / 2, imageOutline.top + imageOutline.height / 2);

    auto renderingPos = this->GetPosition();
    renderingPos.y *= -1;
    sprite0.setPosition(renderingPos);
    sprite1.setPosition(renderingPos);

    if (physicsBody->GetLinearVelocity().x > 0) {
        sprite0.setScale(-std::abs(sprite0.getScale().x), sprite0.getScale().y);
        sprite1.setScale(-std::abs(sprite1.getScale().x), sprite1.getScale().y);
    } else if (physicsBody->GetLinearVelocity().x < 0) {
        sprite0.setScale(std::abs(sprite0.getScale().x), sprite0.getScale().y);
        sprite1.setScale(std::abs(sprite1.getScale().x), sprite1.getScale().y);
    }

    timeToSwap -= deltaRTime;
    if (timeToSwap <= 0) {
        currentFrame = (currentFrame + 1) % ANIMATION_FRAMES;
        timeToSwap = 1.0 / ANIMATION_FPS;
    }
    if (currentFrame == 0) window.draw(sprite0);
    else if (currentFrame == 1) window.draw(sprite1);
}

void SP::Scene::Gameplay::PlayerObject::CreatePhysicsBody(b2World &physicsWorld) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    physicsBody = physicsWorld.CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    physicsBody->CreateFixture(&fixtureDef);
}

b2Body* SP::Scene::Gameplay::PlayerObject::GetPhysicsBody() {
    return physicsBody;
}
