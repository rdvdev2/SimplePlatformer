#include "LevelDescription.h"

#include <istream>
#include <fstream>

SP::Userdata::LevelDescription::ObjectDescriptor::ObjectDescriptor(SP::Userdata::LevelDescription::ObjectType type,
                                                                   float x, float y): type(type), x(x), y(y) {

}

bool SP::Userdata::LevelDescription::LoadFromFile(std::string &filename) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) return false;

    this->objects.clear();
    while (getline(file, line)) {
        if (line.starts_with('#')) continue; // Ignore comments, starting with '#'
        char typeStr[100];
        float x;
        float y;

        if (3 == sscanf(line.c_str(), "%99s %f %f", typeStr, &x, &y)) {
            ObjectType type;
            if (std::string(typeStr) == "PLAYER") type = PLAYER;
            else if (std::string(typeStr) == "ZOMBIE") type = ZOMBIE;
            else if (std::string(typeStr) == "FLAT_PLATFORM") type = FLAT_PLATFORM;

            this->objects.emplace_back(type, x, y);
        }
    }

    file.close();
    return true;
}
