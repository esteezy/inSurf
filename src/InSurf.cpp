//
// Created by Evan Mason on 2/21/24.
//

#include "InSurf.h"
#include <iostream>
#include <SFML/Graphics.hpp>

/*      Prototypes      */



//Def Constructor - member initialized
Game::Game() : _window(sf::VideoMode(650, 500), "InSurf!"),_surfer(),_tilesheet(){
    //load texture (surfer)
    if(!_tilesheet.loadFromFile("../assets/SurferSprite.png")){
        std::cout << "Error 1: Failed to load texture";
        exit(1);
    }
    //assign text to sprite; config defaults
    _surfer.setTexture(_tilesheet);
    _surfer.setTextureRect(sf::IntRect(0.0f,0.0f,32.0f,32.0f));
    _surfer.setPosition(325.0f, 250.0f);
}

//Master game loop
void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(_window.isOpen()){
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

//user input handling -- questioning if this is best place
void Game::processEvents() {
    sf::Event event;
    while(_window.pollEvent(event)){
        switch(event.type){
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                _window.close();
                break;
            default:
                break;
        }
    }
}

//game logic
void Game::update(sf::Time deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);
    if (_upEvent) { movement.y -= PlayerSpeed; }
    if (_downEvent) { movement.y += PlayerSpeed; }
    if (_leftEvent) { movement.x -= PlayerSpeed; }
    if (_rightEvent) { movement.x += PlayerSpeed; }

    _surfer.move(movement * deltaTime.asSeconds());
}

//clear->draw->display
void Game::render() {
    _window.clear();
    _window.draw(_surfer);
    _window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if(key == sf::Keyboard::Up){ _upEvent = isPressed; }
    if(key == sf::Keyboard::Down){ _downEvent = isPressed; }
    if(key == sf::Keyboard::Left){ _leftEvent = isPressed; }
    if(key == sf::Keyboard::Right){ _rightEvent = isPressed; }
}

