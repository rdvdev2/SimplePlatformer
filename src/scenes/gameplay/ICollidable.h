#ifndef SIMPLEPLATFORMER_ICOLLIDABLE_H
#define SIMPLEPLATFORMER_ICOLLIDABLE_H

#include <SFML/Graphics/Rect.hpp>

namespace SP::Scene::Gameplay {

    class ICollidable {
    public:
        virtual sf::FloatRect GetColliderBox() = 0;
    };
}


#endif //SIMPLEPLATFORMER_ICOLLIDABLE_H
