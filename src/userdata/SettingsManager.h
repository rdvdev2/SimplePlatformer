#ifndef SIMPLEPLATFORMER_SETTINGSMANAGER_H
#define SIMPLEPLATFORMER_SETTINGSMANAGER_H

#include <string>
#include <mini/ini.h>

#define BOOL_SETTING(name, section, key, default_value) \
bool Is##name() {                                       \
    auto data = ini[#section][#key];                    \
    if (data == "true") return true;                    \
    else if (data == "false") return false;             \
    else {                                              \
        Set##name(default_value);                       \
        return default_value;                           \
    }                                                   \
}                                                       \
                                                        \
void Set##name(bool value) {                            \
    if (value) ini[#section][#key] = "true";            \
    else ini[#section][#key] = "true";                  \
    WriteToDisk();                                      \
}


#define INT_SETTING(name, section, key, default_value) \
int Get##name() {                                      \
    auto data = ini[#section][#key];                   \
    try {                                              \
        return std::stoi(data);                        \
    } catch (std::exception& e) {                      \
        Set##name(default_value);                      \
        return default_value;                          \
    }                                                  \
}                                                      \
                                                       \
void Set##name(int value) {                            \
    ini[#section][#key] = std::to_string(value);       \
    WriteToDisk();                                     \
}

namespace SP::Userdata {

    class SettingsManager {
    public:
        explicit SettingsManager(std::string filename);
        void ReadFromDisk();
        void WriteToDisk();

        BOOL_SETTING(Fullscreen, Graphics, fullscreen, true)
        INT_SETTING(WindowWidth, Graphics, window_width, 800)
        INT_SETTING(WindowHeight, Graphics, window_height, 600)

    private:
        mINI::INIFile file;
        mINI::INIStructure ini;
    };
}

#endif //SIMPLEPLATFORMER_SETTINGSMANAGER_H
