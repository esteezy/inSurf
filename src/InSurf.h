//
// Created by Evan Mason on 2/21/24.
//
#ifndef INSURF_INSURF_H
#define INSURF_INSURF_H

#include <SFML/Graphics.hpp>

class Game{
public:
    Game();
    void run();
private:
    sf::RenderWindow window;
    sf::Sprite surfer;
    sf::Texture surfer_texture;
    void processEvents();
    void update();
    void render();
};

#endif //INSURF_INSURF_H
