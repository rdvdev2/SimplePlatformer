#ifndef SIMPLEPLATFORMER_ANIMATEDSPRITE_H
#define SIMPLEPLATFORMER_ANIMATEDSPRITE_H

#include <SFML/Graphics.hpp>
#include <vector>

namespace SP::Scene::Drawable {

    class AnimatedSprite: public sf::Drawable, public sf::Transformable {
    public:
        explicit AnimatedSprite(sf::Vector2f size, float fps);

        void AddFrame(const sf::Texture* texture);
        void UpdateRenderClock(float deltaRTime);

    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        std::vector<sf::RectangleShape> sprites;
        sf::Vector2f size;
        float fps;

        float timeToSwap = 0;
        unsigned int currentFrame = 0;
    };
}


#endif //SIMPLEPLATFORMER_ANIMATEDSPRITE_H
