//
// Created by Evan Mason on 2/21/24.
//

#include "InSurf.h"
#include <iostream>
#include <SFML/Window.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "My window");

    // Display the list of all the video modes available for fullscreen
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    for (std::size_t i = 0; i < modes.size(); ++i)
    {
        sf::VideoMode mode = modes[i];
        std::cout << "Mode #" << i << ": "
                  << mode.width << "x" << mode.height << " - "
                  << mode.bitsPerPixel << " bpp" << std::endl;
    }

// Create a window with the same pixel depth as the desktop
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "SFML window");

    return 0;
}