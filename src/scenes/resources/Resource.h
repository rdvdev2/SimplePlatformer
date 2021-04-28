#ifndef SIMPLEPLATFORMER_RESOURCE_H
#define SIMPLEPLATFORMER_RESOURCE_H

#include <string>
#include <utility>

namespace SP::Scene::Resource {

    template <typename T>
    class Resource {
    public:
        explicit Resource(std::string filename) : filename(std::move(filename)) {};

        virtual void Load() = 0;
        T& Get() {
            return resource;
        }
        operator T&() {
            return Get();
        }

        operator T*() {
            return &resource;
        }

    protected:
        T resource;
        std::string filename;
    };
}

#endif //SIMPLEPLATFORMER_RESOURCE_H
