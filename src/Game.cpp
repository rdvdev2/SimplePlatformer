#include "Game.h"

void SP::Game::Run() {
    this->Init();
    this->GameLoop();
    this->Cleanup();
}

std::pair<sf::VideoMode, sf::Uint32> chooseWindowSettings(SP::Userdata::SettingsManager settings) {
    if (!settings.IsFullscreen()) return std::pair(sf::VideoMode(settings.GetWindowWidth(), settings.GetWindowHeight()), sf::Style::Default);

    auto fullscreenModes = sf::VideoMode::getFullscreenModes();

    if (fullscreenModes.empty()) return std::pair(sf::VideoMode::getDesktopMode(), sf::Style::None);
    else return std::pair(fullscreenModes[0], sf::Style::Fullscreen);
}

void SP::Game::Init() {
    auto videoMode = chooseWindowSettings(*userdata.settings);
    window = std::make_unique<sf::RenderWindow>(videoMode.first, "Simple Platformer", videoMode.second);
    currentScene = std::make_unique<SP::Scene::MainMenu>(resourceManager, *window);
}

void SP::Game::GameLoop() {
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::Resized) {
                sf::FloatRect newArea(0, 0, event.size.width, event.size.height);
                window->setView(sf::View(newArea));
                currentScene->OnWindowResize(window->getSize());
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window->close();
        }

        currentScene->Update(0);

        window->clear();
        currentScene->Render(*window, 0);
        window->display();
    }
}

void SP::Game::Cleanup() {
    currentScene.reset();

    // Keep window size on next session
    if (!userdata.settings->IsFullscreen()) {
        userdata.settings->SetWindowWidth(window->getSize().x);
        userdata.settings->SetWindowHeight(window->getSize().y);
    }
}
