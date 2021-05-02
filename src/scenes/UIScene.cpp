#include "UIScene.h"
#include "../Game.h"

SP::Scene::UIScene::UIScene(SP::Game &game) : Scene(game), inputManager(*game.window) {

}

void SP::Scene::UIScene::Update(float deltaUTime) {
    inputManager.ProcessInput();

    if (inputManager.IsExit()) {
        game.Close();
    }
}

void SP::Scene::UIScene::Render(sf::RenderWindow &window, float deltaRTime) {
    for (auto&& drawable: drawables) {
        window.draw(*drawable);
    }
}

void SP::Scene::UIScene::AddSprite(sf::RectangleShape &sprite) {
    drawables.push_back(std::make_unique<sf::RectangleShape>(sprite));
}

void SP::Scene::UIScene::AddText(sf::Text &text) {
    drawables.push_back(std::make_unique<sf::Text>(text));
}

void SP::Scene::UIScene::AddButton(sf::FloatRect area, SP::Input::UI::ButtonCallback callback) {
    auto button = SP::Input::UI::Button(area, callback, &game);
    inputManager.AddButton(button);
}
