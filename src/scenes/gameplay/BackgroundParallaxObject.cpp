#include "BackgroundParallaxObject.h"

SP::Scene::Gameplay::BackgroundParallaxObject::BackgroundParallaxObject(
        SP::Scene::Resource::ResourceManager &resourceManager) : IGameObject(-100) {

    layer0.setTexture(resourceManager.TextureGameBackgroundLayer0);
    layer2.setTexture(resourceManager.TextureGameBackgroundLayer2);
}

void SP::Scene::Gameplay::BackgroundParallaxObject::Update(float deltaUTime) {

}

void SP::Scene::Gameplay::BackgroundParallaxObject::Render(sf::RenderWindow &window, float deltaRTime) {
    auto viewArea = window.getView();

    // Layer 0
    for (int x = viewArea.getCenter().x - (viewArea.getSize().x / 2); x < viewArea.getCenter().x + (viewArea.getSize().x / 2); x += layer0.getLocalBounds().width) {
        for (int y = viewArea.getCenter().y - (viewArea.getSize().y / 2); y < viewArea.getCenter().y + (viewArea.getSize().y / 2); y += layer0.getLocalBounds().height) {
            layer0.setPosition(x, y);
            window.draw(layer0);
        }
    }

    // Layer 2
    for (int x = viewArea.getCenter().x - (viewArea.getSize().x / 2); x < viewArea.getCenter().x + (viewArea.getSize().x / 2); x += layer2.getLocalBounds().width) {
        layer2.setPosition(x, viewArea.getCenter().y - layer2.getLocalBounds().height / 2);
        window.draw(layer2);
    }
}
