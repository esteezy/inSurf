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
    sf::RenderWindow _window;
    sf::Sprite _surfer;
    sf::Texture _tilesheet;

    bool _upEvent {false}, _downEvent {false}, _leftEvent {false}, _rightEvent {false};
    const float PlayerSpeed {100.0f};
    const sf::Time TimePerFrame = sf::seconds(1.f/60.0f);

    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
};

#endif //INSURF_INSURF_H
