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
    force = sf::Vector2f(0, 0);
    if (inputManager.IsLeft()) force += sf::Vector2f(-50, 0); // TODO: Only work if grounded
    if (inputManager.IsRight()) force += sf::Vector2f(50, 0);

    force += sf::Vector2f(0, -9.8); // Gravity

    // Collisions
    auto collisionVector = this->gameplayScene.ComputeCollisionsOf(*this);
    auto collisionStrength = std::sqrt((collisionVector.x * collisionVector.x) + (collisionVector.y * collisionVector.y));
    if (collisionStrength != 0) {
        auto forceStrength = std::sqrt((force.x * force.x) + (force.y * force.y));
        if (forceStrength >= 1.0f) collisionVector *= forceStrength;
        force += (collisionVector / collisionStrength) * 100.0f;
    }

    velocity += (force / mass) * 10.0f * deltaUTime;
    if (collisionStrength != 0 && collisionStrength <= 0.1f) {
        if (collisionVector.x != 0) velocity.x = 0;
        if (collisionVector.y != 0) velocity.y = 0;
    }
    this->SetPosition(this->GetPosition() + (velocity * deltaUTime));

    this->colliderBox = sprite0.getGlobalBounds();
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

    if (velocity.x > 0) {
        sprite0.setScale(-std::abs(sprite0.getScale().x), sprite0.getScale().y);
        sprite1.setScale(-std::abs(sprite1.getScale().x), sprite1.getScale().y);
    } else if (velocity.x < 0) {
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

sf::FloatRect SP::Scene::Gameplay::PlayerObject::GetColliderBox() {
    return colliderBox;
}
