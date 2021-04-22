#include "FlatPlatformObject.h"

SP::Scene::Gameplay::FlatPlatformObject::FlatPlatformObject(SP::Scene::Resource::ResourceManager &resourceManager) : IGameObject(0) {

    sprite.setTexture(resourceManager.TextureGround);
    sprite.scale(5, 5);
}

void SP::Scene::Gameplay::FlatPlatformObject::Update(float deltaUTime) {
    colliderBox = sf::FloatRect(this->GetPosition().x - 0.5, this->GetPosition().y - 0.5, 1, 1);
}

void SP::Scene::Gameplay::FlatPlatformObject::Render(sf::RenderWindow &window, float deltaRTime) {
    auto imageOutline = sprite.getLocalBounds();
    sprite.setOrigin(imageOutline.left + imageOutline.width / 2, imageOutline.top + imageOutline.height / 2);

    auto correctedPos = this->GetPosition();
    correctedPos.y *= -1;
    sprite.setPosition(correctedPos);

    window.draw(sprite);
}

sf::FloatRect SP::Scene::Gameplay::FlatPlatformObject::GetColliderBox() {
    return colliderBox;
}


