#ifndef SIMPLEPLATFORMER_GAMEOBJECT_H
#define SIMPLEPLATFORMER_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

namespace SP::Scene::Gameplay {

    class GameObject {
    public:
        explicit GameObject(int renderDepth);;

        void SetPosition(sf::Vector2f pos);
        sf::Vector2f GetPosition();

        int GetRenderDepth() const;

        virtual void Update(float deltaUTime);
        virtual void Render(sf::RenderWindow &window, float deltaRTime);

    protected:
        sf::Vector2f position;
        int renderDepth;
    };
}

#endif //SIMPLEPLATFORMER_GAMEOBJECT_H
