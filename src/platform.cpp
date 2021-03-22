#include "platform.h"

std::string SP::Platform::GetUserdataPath() {
    std::string path;

    #ifdef _WIN32
        path = std::string(getenv("appdata")) + "/simpleplatformer";
    #elif linux
        path = std::string(getenv("HOME")) + "/.simpleplatformer";
    #else
        path = ".simpleplatformer";
    #endif

    return path;
}

std::string SP::Platform::GetResourcePath(std::string filename) {
    return SP_RESOURCES_PATH "/" + filename;
}
