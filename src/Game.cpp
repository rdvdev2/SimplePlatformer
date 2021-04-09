#include <chrono>

#include "Game.h"
#include "scenes/MainMenu.h"

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
    nextUpdateScene = std::make_unique<SP::Scene::MainMenu>(*this);
}

void SP::Game::GameLoop() {
    auto lastUTime = std::chrono::high_resolution_clock::now();
    auto lastRTime = std::chrono::high_resolution_clock::now();

    while (window->isOpen())
    {
        if (nextUpdateScene) {
            currentScene.swap(nextUpdateScene);
            nextUpdateScene.reset();
        }

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::Resized) {
                currentScene->OnWindowResize(sf::Vector2u(event.size.width, event.size.height));
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window->close();
        }

        auto currentTime = std::chrono::high_resolution_clock::now();
        float deltaUTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastUTime).count();
        currentScene->Update(deltaUTime);
        lastUTime = currentTime;

        currentTime = std::chrono::high_resolution_clock::now();
        float deltaRTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastRTime).count();
        window->clear();
        currentScene->Render(*window, deltaRTime);
        window->display();
        lastRTime = currentTime;
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

void SP::Game::SetNextUpdateScene(std::unique_ptr<SP::Scene::Scene> newScene) {
    nextUpdateScene.swap(newScene);
}
