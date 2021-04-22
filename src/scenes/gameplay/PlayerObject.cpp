#include "PlayerObject.h"

#define ANIMATION_FPS 3
#define ANIMATION_FRAMES 2

SP::Scene::Gameplay::PlayerObject::PlayerObject(SP::Input::GameplayInputManager &inputManager, SP::Scene::Resource::ResourceManager &resourceManager)
        : IGameObject(100), inputManager(inputManager), currentFrame(0), timeToSwap(0) {

    sprite0.setTexture(resourceManager.TexturePlayer0);
    sprite1.setTexture(resourceManager.TexturePlayer1);
}

void SP::Scene::Gameplay::PlayerObject::Update(float deltaUTime) {
    velocity = sf::Vector2f(0, 0);
    if (inputManager.IsLeft()) velocity += sf::Vector2f(-100, 0);
    if (inputManager.IsRight()) velocity += sf::Vector2f(100, 0);
    this->SetPosition(this->GetPosition() + (velocity * deltaUTime));
}

void SP::Scene::Gameplay::PlayerObject::Render(sf::RenderWindow &window, float deltaRTime) {

    // TODO: Set origin on window resize?
    auto imageOutline = sprite0.getLocalBounds();
    sprite0.setOrigin(imageOutline.left + imageOutline.width / 2, imageOutline.top + imageOutline.height / 2);
    imageOutline = sprite1.getLocalBounds();
    sprite1.setOrigin(imageOutline.left + imageOutline.width / 2, imageOutline.top + imageOutline.height / 2);

    sprite0.setPosition(this->GetPosition());
    sprite1.setPosition(this->GetPosition());

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