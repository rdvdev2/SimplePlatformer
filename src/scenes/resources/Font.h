#ifndef SIMPLEPLATFORMER_FONT_H
#define SIMPLEPLATFORMER_FONT_H

#include <SFML/Graphics.hpp>

#include "Resource.h"

namespace SP::Scene::Resource {

    class Font: public Resource<sf::Font> {
    public:
        using Resource::Resource;

        void Load() override {
            if (!resource.loadFromFile(filename)) {
                throw std::runtime_error("Error loading font @ " + filename + "!");
            }
        };
    };
}

#endif //SIMPLEPLATFORMER_FONT_H