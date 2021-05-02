#include "LevelDescription.h"

SP::Userdata::LevelDescription::ObjectDescriptor::ObjectDescriptor(SP::Userdata::LevelDescription::ObjectType type,
                                                                   float x, float y): type(type), x(x), y(y) {

}

SP::Userdata::LevelDescription SP::Userdata::LevelDescription::GetTestLevel() { // TODO: Remove when level parsing is implemented
    LevelDescription level;

    level.objects.emplace_back(PLAYER, 0, 3);

    level.objects.emplace_back(ZOMBIE, -4, 3);

    level.objects.emplace_back(FLAT_PLATFORM, -9, 0);
    level.objects.emplace_back(FLAT_PLATFORM, 0, 0);
    level.objects.emplace_back(FLAT_PLATFORM, 9, 0);

    return level;
}
