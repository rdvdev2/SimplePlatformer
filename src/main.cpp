#include <SFML/Graphics.hpp>
#include <utility>

#include "userdata/UserdataManager.h"

std::pair<sf::VideoMode, sf::Uint32> chooseWindowSettings();

SP::Userdata::UserdataManager userdata;

int main() {
    auto videoMode = chooseWindowSettings();
    sf::RenderWindow window(videoMode.first, "Simple Platformer", videoMode.second);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        window.clear();

        // Draw here

        window.display();
    }

    // Keep window size on next session
    if (!userdata.settings->IsFullscreen()) {
        userdata.settings->SetWindowWidth(window.getSize().x);
        userdata.settings->SetWindowHeight(window.getSize().y);
    }

    return 0;
}

std::pair<sf::VideoMode, sf::Uint32> chooseWindowSettings() {
    if (!userdata.settings->IsFullscreen()) return std::pair(sf::VideoMode(userdata.settings->GetWindowWidth(), userdata.settings->GetWindowHeight()), sf::Style::Default);

    auto fullscreenModes = sf::VideoMode::getFullscreenModes();

    if (fullscreenModes.empty()) return std::pair(sf::VideoMode::getDesktopMode(), sf::Style::None);
    else return std::pair(fullscreenModes[0], sf::Style::Fullscreen);
}