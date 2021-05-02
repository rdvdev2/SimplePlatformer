#include "MainMenu.h"
#include "../Game.h"
#include "GameplayScene.h"

void playButtonCallback(void* data);

SP::Scene::MainMenu::MainMenu(SP::Game& game) : UIScene(game) {
    auto viewSize = view.getSize();
    sf::FloatRect outline;
    float scaleFactor;

    // Background sprite
    sf::RectangleShape backgroundSprite;
    backgroundSprite.setSize(viewSize);
    backgroundSprite.setPosition(view.getCenter().x - viewSize.x / 2, view.getCenter().y - viewSize.y / 2);
    backgroundSprite.setTexture(game.resourceManager.TextureMainMenuBackground);
    backgroundSprite.setFillColor(sf::Color(255, 0, 0));
    AddSprite(backgroundSprite);

    // Title text
    sf::Text titleText;
    titleText.setFont(game.resourceManager.FontMoonhouse);
    titleText.setString("Simple Platformer");
    titleText.setFillColor(sf::Color(255, 255, 255));
    titleText.setStyle(sf::Text::Regular);

    titleText.setCharacterSize(sf::VideoMode::getDesktopMode().height / 10);
    outline = titleText.getLocalBounds();
    titleText.setOrigin(outline.left + outline.width / 2, outline.top + outline.height / 2);
    scaleFactor = viewSize.y / outline.height / 15;
    titleText.setScale(scaleFactor, scaleFactor);
    titleText.setPosition(view.getCenter().x, view.getCenter().y - viewSize.y / 10 * 2);
    AddText(titleText);

    // Authors text
    sf::Text authorsText;
    authorsText.setFont(game.resourceManager.FontMoonhouse);
    authorsText.setString("by Victor & Roger");
    authorsText.setFillColor(sf::Color(255, 255, 255));
    authorsText.setStyle(sf::Text::Italic);

    authorsText.setCharacterSize(sf::VideoMode::getDesktopMode().height / 20);
    outline = authorsText.getLocalBounds();
    authorsText.setOrigin(outline.left + outline.width / 2, outline.top + outline.height / 2);
    scaleFactor = viewSize.y / outline.height / 20;
    authorsText.setScale(scaleFactor, scaleFactor);
    authorsText.setPosition(view.getCenter().x, view.getCenter().y - viewSize.y / 10);
    AddText(authorsText);

    // Play button
    sf::RectangleShape playButtonSprite;
    playButtonSprite.setSize(sf::Vector2f(5, 5));
    playButtonSprite.setTexture(game.resourceManager.TextureMainMenuPlayButton);

    playButtonSprite.setOrigin(5.f / 2, 5.f / 2);
    playButtonSprite.setPosition(view.getCenter().x, view.getCenter().y + viewSize.y / 5);
    AddSprite(playButtonSprite);

    AddButton(playButtonSprite.getGlobalBounds(), playButtonCallback);
}

void SP::Scene::MainMenu::Update(float deltaUTime) {
    UIScene::Update(deltaUTime);

    if (inputManager.IsPlayKeyPressed()) {
        playButtonCallback(&game);
    }
}

void playButtonCallback(void* data) {
    auto game = (SP::Game*) data;
    game->SetNextUpdateScene(std::make_unique<SP::Scene::GameplayScene>(*game, game->resourceManager.LevelTest));
}