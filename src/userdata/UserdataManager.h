#ifndef SIMPLEPLATFORMER_USERDATAMANAGER_H
#define SIMPLEPLATFORMER_USERDATAMANAGER_H

#include <string>

#include "SettingsManager.h"
#include <platform.h>

namespace SP::Userdata {

    class UserdataManager {
    public:
        UserdataManager();
        ~UserdataManager();
        SP::Userdata::SettingsManager* settings;

    private:
        std::string path = SP::Platform::GetUserdataPath();
    };
}

#endif //SIMPLEPLATFORMER_USERDATAMANAGER_H
