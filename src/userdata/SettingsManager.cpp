#include "SettingsManager.h"

SP::Userdata::SettingsManager::SettingsManager(std::string filename) : file(filename) {
    ReadFromDisk();
}

void SP::Userdata::SettingsManager::ReadFromDisk() {
    file.read(ini);
}

void SP::Userdata::SettingsManager::WriteToDisk() {
    file.write(ini);
}