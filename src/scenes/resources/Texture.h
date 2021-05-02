#ifndef SIMPLEPLATFORMER_TEXTURE_H
#define SIMPLEPLATFORMER_TEXTURE_H

#include <SFML/Graphics.hpp>

#include "Resource.h"

namespace SP::Scene::Resource {

    class Texture: public Resource<sf::Texture> {
    public:
        using Resource::Resource;

        void Load() override {
            if (!resource.loadFromFile(filename)) {
                throw std::runtime_error("Error loading texture @ " + filename + "!");
            }
            resource.setSmooth(false);
        };
    };
}

#endif //SIMPLEPLATFORMER_TEXTURE_H