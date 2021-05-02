#ifndef SIMPLEPLATFORMER_RESOURCEMANAGER_H
#define SIMPLEPLATFORMER_RESOURCEMANAGER_H

#include "Font.h"
#include "Texture.h"
#include "Level.h"
#include <platform.h>

#define FONT(name, file) Font Font##name = Font(SP::Platform::GetResourcePath("fonts/"#file".ttf"))
#define TEXTURE(name, file) Texture Texture##name = Texture(SP::Platform::GetResourcePath("textures/"#file".png"))
#define LEVEL(name, file) Level Level##name = Level(SP::Platform::GetResourcePath("levels/"#file".splevel"))

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
            TextureMainMenuPlayButton.Get().setSmooth(true);

            TextureEndGameReplayButton.Load();
            TextureEndGameReplayButton.Get().setSmooth(true);

            TextureGameBackgroundLayer0.Load();
            TextureGameBackgroundLayer1.Load();
            TextureGameBackgroundLayer2.Load();
            TextureGround.Load();
            TextureGroundSlope.Load();
            TextureLightBulb.Load();
            TextureLightning.Load();
            TextureTree.Load();

            LevelTest.Load();
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

        TEXTURE(EndGameReplayButton, end_game/replay_button);

        TEXTURE(GameBackgroundLayer0, scenery/background_layer_0);
        TEXTURE(GameBackgroundLayer1, scenery/background_layer_1);
        TEXTURE(GameBackgroundLayer2, scenery/background_layer_2);
        TEXTURE(Ground, scenery/ground);
        TEXTURE(GroundSlope, scenery/ground_slope);
        TEXTURE(LightBulb, scenery/light_bulb);
        TEXTURE(Lightning, scenery/lightning);
        TEXTURE(Tree, scenery/tree);

        LEVEL(Test, test);
    };
}

#endif //SIMPLEPLATFORMER_RESOURCEMANAGER_H
