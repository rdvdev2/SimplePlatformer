#ifndef SIMPLEPLATFORMER_PLATFORM_H
#define SIMPLEPLATFORMER_PLATFORM_H

#include <string>

namespace SP::Platform {

    std::string GetUserdataPath();
    std::string GetResourcePath(std::string filename);
}

#endif //SIMPLEPLATFORMER_PLATFORM_H
