#include "MainMenu.h"
#include "../Game.h"
#include "GameplayScene.h"

void playButtonCallback(void* data);

SP::Scene::MainMenu::MainMenu(SP::Game& game) : Scene(game), inputManager(*game.window) {
    playButton = new SP::Input::Menu::Button(sf::IntRect(), playButtonCallback, &game);
    inputManager.AddButton(playButton);

    backgroundSprite.setTexture(game.resourceManager.TextureMainMenuBackground);
    backgroundSprite.setColor(sf::Color(255, 0, 0));

    titleText.setFont(game.resourceManager.FontMoonhouse);
    titleText.setString("Simple Platformer");
    titleText.setFillColor(sf::Color(255, 255, 255));
    titleText.setStyle(sf::Text::Regular);

    authorsText.setFont(game.resourceManager.FontMoonhouse);
    authorsText.setString("by Victor & Roger");
    authorsText.setFillColor(sf::Color(255, 255, 255));
    authorsText.setStyle(sf::Text::Italic);

    playButtonSprite.setTexture(game.resourceManager.TextureMainMenuPlayButton);
}

void SP::Scene::MainMenu::AdjustToWindowSize(sf::Vector2u windowSize) {
    sf::FloatRect newArea(0, 0, windowSize.x, windowSize.y);
    game.window->setView(sf::View(newArea));

    auto imageOutline = backgroundSprite.getLocalBounds();
    float imageScale = std::max(windowSize.x / imageOutline.width, windowSize.y / imageOutline.height);
    backgroundSprite.setScale(imageScale, imageScale);

    titleText.setCharacterSize(windowSize.y / 10);
    auto textOutline = titleText.getLocalBounds();
    titleText.setOrigin(textOutline.left + textOutline.width / 2, textOutline.top + textOutline.height / 2);
    titleText.setPosition(windowSize.x / 2, windowSize.y / 5);

    authorsText.setCharacterSize(windowSize.y / 20);
    textOutline = authorsText.getLocalBounds();
    authorsText.setOrigin(textOutline.left + textOutline.width / 2, textOutline.top + textOutline.height / 2);
    authorsText.setPosition(windowSize.x / 2, windowSize.y / 5 * 2);

    imageOutline = playButtonSprite.getLocalBounds();
    imageScale = (windowSize.y / imageOutline.height) / 5;
    playButtonSprite.setOrigin(imageOutline.left + imageOutline.width / 2, imageOutline.top + imageOutline.height / 2);
    playButtonSprite.setScale(imageScale, imageScale);
    playButtonSprite.setPosition(windowSize.x / 2, windowSize.y / 5 * 4);

    playButton->UpdateArea(static_cast<sf::IntRect>(playButtonSprite.getGlobalBounds()));
}

void SP::Scene::MainMenu::Update(float deltaUTime) {
    inputManager.ProcessInput();
}

void SP::Scene::MainMenu::Render(sf::RenderWindow &window, float deltaRTime) {
    window.draw(backgroundSprite);
    window.draw(titleText);
    window.draw(authorsText);
    window.draw(playButtonSprite);
}

void playButtonCallback(void* data) {
    auto game = (SP::Game*) data;
    game->SetNextUpdateScene(std::make_unique<SP::Scene::GameplayScene>(*game));
}