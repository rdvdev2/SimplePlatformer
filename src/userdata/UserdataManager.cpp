#include "UserdataManager.h"
#include <filesystem>

SP::Userdata::UserdataManager::UserdataManager() {
    std::filesystem::create_directory(path);
    settings = new SP::Userdata::SettingsManager(path + "/settings.ini");
}

SP::Userdata::UserdataManager::~UserdataManager() {
    delete settings;
}
