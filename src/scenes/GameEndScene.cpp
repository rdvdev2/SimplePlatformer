#include "GameEndScene.h"
#include "../Game.h"
#include "GameplayScene.h"

void replayButtonCallback(void* data);

SP::Scene::GameEndScene::GameEndScene(SP::Game &game, bool won, int score) : UIScene(game) {
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

    // You win / You lose text
    sf::Text resultText;
    resultText.setFont(game.resourceManager.FontMoonhouse);
    if (won) resultText.setString("Victory! You win!");
    else     resultText.setString("Game Over! You lose!");
    resultText.setFillColor(sf::Color(255, 255, 255));
    resultText.setStyle(sf::Text::Regular);

    resultText.setCharacterSize(sf::VideoMode::getDesktopMode().height / 10);
    outline = resultText.getLocalBounds();
    resultText.setOrigin(outline.left + outline.width / 2, outline.top + outline.height / 2);
    scaleFactor = viewSize.y / outline.height / 20;
    resultText.setScale(scaleFactor, scaleFactor);
    resultText.setPosition(view.getCenter().x, view.getCenter().y - viewSize.y / 10 * 2);
    AddText(resultText);

    // Score text
    sf::Text scoreText;
    scoreText.setFont(game.resourceManager.FontMoonhouse);
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setFillColor(sf::Color(255, 255, 255));
    scoreText.setStyle(sf::Text::Regular);

    scoreText.setCharacterSize(sf::VideoMode::getDesktopMode().height / 15);
    outline = scoreText.getLocalBounds();
    scoreText.setOrigin(outline.left + outline.width / 2, outline.top + outline.height / 2);
    scaleFactor = viewSize.y / outline.height / 25;
    scoreText.setScale(scaleFactor, scaleFactor);
    scoreText.setPosition(view.getCenter().x, view.getCenter().y - viewSize.y / 10);
    AddText(scoreText);

    // Replay button
    sf::RectangleShape replayButtonSprite;
    replayButtonSprite.setSize(sf::Vector2f(5, 5));
    replayButtonSprite.setTexture(game.resourceManager.TextureEndGameReplayButton);

    replayButtonSprite.setOrigin(5.f / 2, 5.f / 2);
    replayButtonSprite.setPosition(view.getCenter().x, view.getCenter().y + viewSize.y / 5);
    AddSprite(replayButtonSprite);

    AddButton(replayButtonSprite.getGlobalBounds(), replayButtonCallback);
}

void SP::Scene::GameEndScene::Update(float deltaUTime) {
    UIScene::Update(deltaUTime);

    if (inputManager.IsPlayKeyPressed()) {
        replayButtonCallback(&game);
    }
}

void replayButtonCallback(void* data) {
    auto game = (SP::Game*) data;
    game->SetNextUpdateScene(std::make_unique<SP::Scene::GameplayScene>(*game, game->resourceManager.LevelTest));
}