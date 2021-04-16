#ifndef SIMPLEPLATFORMER_IGAMEOBJECT_H
#define SIMPLEPLATFORMER_IGAMEOBJECT_H

#include <SFML/Graphics.hpp>

namespace SP::Scene::Gameplay {

    class IGameObject {
    public:
        explicit IGameObject(int renderDepth);;

        void SetPosition(sf::Vector2f pos);
        sf::Vector2f GetPosition();

        int GetRenderDepth() const;

        virtual void Update(float deltaUTime);
        virtual void Render(float deltaRTime);

    protected:
        sf::Vector2f position;
        int renderDepth;
    };
}

#endif //SIMPLEPLATFORMER_IGAMEOBJECT_H
