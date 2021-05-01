#include "AnimatedSprite.h"

SP::Scene::Drawable::AnimatedSprite::AnimatedSprite(sf::Vector2f size, float fps): size(size), fps(fps) {

}

void SP::Scene::Drawable::AnimatedSprite::AddFrame(const sf::Texture* texture) {
    sf::RectangleShape newFrame;
    newFrame.setSize(size);
    newFrame.setTexture(texture);

    auto outline = newFrame.getLocalBounds();
    newFrame.setOrigin(outline.left + outline.width / 2, outline.top + outline.height / 2);

    sprites.push_back(newFrame);
}

void SP::Scene::Drawable::AnimatedSprite::UpdateRenderClock(float deltaRTime) {
    timeToSwap -= deltaRTime;
    if (timeToSwap <= 0) {
        currentFrame = (currentFrame + 1) % sprites.size();
        timeToSwap = 1.0f / fps;
    }
}


void SP::Scene::Drawable::AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= this->getTransform();
    target.draw(sprites[currentFrame], states);
}