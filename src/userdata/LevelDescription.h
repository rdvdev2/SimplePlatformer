#ifndef SIMPLEPLATFORMER_LEVELDESCRIPTION_H
#define SIMPLEPLATFORMER_LEVELDESCRIPTION_H

#include <vector>
#include <string>

namespace SP::Userdata {

    class LevelDescription {
    public:
        enum ObjectType {
            PLAYER, ZOMBIE, GOOMBA, FLAT_PLATFORM, LIGHT_BULB, LIGHTNING
        };

        class ObjectDescriptor {
        public:
            ObjectDescriptor(ObjectType type, float x, float y);

            ObjectType type;
            float x;
            float y;
        };

        std::vector<ObjectDescriptor> objects;

        bool LoadFromFile(std::string& filename);
    };
}


#endif //SIMPLEPLATFORMER_LEVELDESCRIPTION_H
