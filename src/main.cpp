#include <SFML/Graphics.hpp>
#include <utility>

std::pair<sf::VideoMode, sf::Uint32> chooseWindowSettings();

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
        }

        window.clear();

        // Draw here

        window.display();
    }

    return 0;
}

std::pair<sf::VideoMode, sf::Uint32> chooseWindowSettings() {
    auto fullscreenModes = sf::VideoMode::getFullscreenModes();

    if (fullscreenModes.empty()) return std::pair(sf::VideoMode::getDesktopMode(), sf::Style::None);
    else return std::pair(fullscreenModes[0], sf::Style::Fullscreen);
}