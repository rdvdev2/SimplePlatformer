#ifndef SIMPLEPLATFORMER_RESOURCEMANAGER_H
#define SIMPLEPLATFORMER_RESOURCEMANAGER_H

#include "Font.h"
#include "Texture.h"
#include <platform.h>

#define FONT(name, file) Font Font##name = Font(SP::Platform::GetResourcePath("fonts/"#file".ttf"))
#define TEXTURE(name, file) Texture Texture##name = Texture(SP::Platform::GetResourcePath("textures/"#file".png"))

namespace SP::Scene::Resource {

    class ResourceManager {
    public:
        ResourceManager() {
            FontMoonhouse.Load();

            TextureMainMenuBackground.Load();
            TextureMainMenuPlayButton.Load();
        }

        FONT(Moonhouse, moonhouse);

        TEXTURE(MainMenuBackground, main_menu/background);
        TEXTURE(MainMenuPlayButton, main_menu/play_button);
    };
}

#endif //SIMPLEPLATFORMER_RESOURCEMANAGER_H
