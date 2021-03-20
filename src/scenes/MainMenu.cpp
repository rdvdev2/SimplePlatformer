#include "MainMenu.h"

sf::Font moonhouseFont;
sf::Texture backgroundTexture;

sf::Sprite backgroundSprite;
sf::Text titleText;
sf::Text authorsText;

SP::Scene::MainMenu::MainMenu() {
    if (!moonhouseFont.loadFromFile("resources/fonts/moonhouse.ttf")) {
        throw std::runtime_error("Couldn't load moonhouse font!");
    }

    if (!backgroundTexture.loadFromFile("resources/images/main_menu/background.png")) {
        throw std::runtime_error("Couldn't load main menu background image!");
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setColor(sf::Color(255, 0, 0));

    titleText.setFont(moonhouseFont);
    titleText.setString("Simple Platformer");
    titleText.setFillColor(sf::Color(255, 255, 255));
    titleText.setStyle(sf::Text::Regular);

    authorsText.setFont(moonhouseFont);
    authorsText.setString("by Victor & Roger");
    authorsText.setFillColor(sf::Color(255, 255, 255));
    authorsText.setStyle(sf::Text::Italic);
}

void SP::Scene::MainMenu::update(float deltaUTime) {

}

void SP::Scene::MainMenu::render(sf::RenderWindow *window, float deltaRTime) {
    auto windowSize = window->getSize();

    auto imageOutline = backgroundSprite.getLocalBounds();
    float imageScale = std::max(windowSize.x / imageOutline.width, windowSize.y / imageOutline.height);
    backgroundSprite.setScale(imageScale, imageScale);
    window->draw(backgroundSprite);

    titleText.setCharacterSize(windowSize.y / 10);
    auto textOutline = titleText.getLocalBounds();
    titleText.setOrigin(textOutline.left + textOutline.width / 2, textOutline.top + textOutline.height / 2);
    titleText.setPosition(windowSize.x / 2, windowSize.y / 5);
    window->draw(titleText);

    authorsText.setCharacterSize(windowSize.y / 20);
    textOutline = authorsText.getLocalBounds();
    authorsText.setOrigin(textOutline.left + textOutline.width / 2, textOutline.top + textOutline.height / 2);
    authorsText.setPosition(windowSize.x / 2, windowSize.y / 5 * 2);
    window->draw(authorsText);
}
