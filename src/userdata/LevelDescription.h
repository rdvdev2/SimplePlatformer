#ifndef SIMPLEPLATFORMER_LEVELDESCRIPTION_H
#define SIMPLEPLATFORMER_LEVELDESCRIPTION_H

#include <vector>

namespace SP::Userdata {

    class LevelDescription {
    public:
        enum ObjectType {
            PLAYER, ZOMBIE, FLAT_PLATFORM
        };

        class ObjectDescriptor {
        public:
            ObjectDescriptor(ObjectType type, float x, float  y);

            ObjectType type;
            float x{};
            float y{};
        };

        std::vector<ObjectDescriptor> objects;

        static LevelDescription GetTestLevel();
    };
}


#endif //SIMPLEPLATFORMER_LEVELDESCRIPTION_H
