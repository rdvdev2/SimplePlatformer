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

            TextureGoomba0.Load();
            TextureGoomba1.Load();
            TexturePlayer0.Load();
            TexturePlayer1.Load();
            TextureZombie0.Load();
            TextureZombie1.Load();

            TextureMainMenuBackground.Load();
            TextureMainMenuPlayButton.Load();

            TextureGameBackgroundLayer0.Load();
            TextureGameBackgroundLayer1.Load();
            TextureGameBackgroundLayer2.Load();
            TextureGround.Load();
            TextureGround.Get().setSmooth(false);
            TextureGroundSlope.Load();
            TextureGroundSlope.Get().setSmooth(false);
            TextureLightning.Load();
        }

        FONT(Moonhouse, moonhouse);

        TEXTURE(Goomba0, characters/goomba_0);
        TEXTURE(Goomba1, characters/goomba_1);
        TEXTURE(Player0, characters/player_0);
        TEXTURE(Player1, characters/player_1);
        TEXTURE(Zombie0, characters/zombie_0);
        TEXTURE(Zombie1, characters/zombie_1);

        TEXTURE(MainMenuBackground, main_menu/background);
        TEXTURE(MainMenuPlayButton, main_menu/play_button);

        TEXTURE(GameBackgroundLayer0, scenery/background_layer_0);
        TEXTURE(GameBackgroundLayer1, scenery/background_layer_1);
        TEXTURE(GameBackgroundLayer2, scenery/background_layer_2);
        TEXTURE(Ground, scenery/ground);
        TEXTURE(GroundSlope, scenery/ground_slope);
        TEXTURE(Lightning, scenery/lightning);
    };
}

#endif //SIMPLEPLATFORMER_RESOURCEMANAGER_H
