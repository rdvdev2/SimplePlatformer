#ifndef SIMPLEPLATFORMER_LEVEL_H
#define SIMPLEPLATFORMER_LEVEL_H

#include "Resource.h"
#include "../../userdata/LevelDescription.h"

namespace SP::Scene::Resource {

    class Level: public Resource<SP::Userdata::LevelDescription> {
    public:
        using Resource::Resource;

        void Load() override {
            if (!resource.LoadFromFile(filename)) {
                throw std::runtime_error("Error loading level @ " + filename + "!");
            }
        }
    };
}

#endif //SIMPLEPLATFORMER_LEVEL_H
