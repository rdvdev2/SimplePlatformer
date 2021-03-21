#ifndef SIMPLEPLATFORMER_SCENE_H
#define SIMPLEPLATFORMER_SCENE_H

#include <SFML/Graphics.hpp>

namespace SP::Scene {

    class Scene {
    public:
        virtual void Update(float deltaUTime) = 0;
        virtual void Render(sf::RenderWindow *window, float deltaRTime) = 0;
    };
}

#endif //SIMPLEPLATFORMER_SCENE_H
