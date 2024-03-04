//
// Created by Evan Mason on 2/21/24.
//

#include "InSurf.h"
#include <iostream>
#include <SFML/Graphics.hpp>

//Def Constructor - member initialized
Game::Game() : window(sf::VideoMode(650, 500), "InSurf!"), surfer(), surfer_texture(){
    window.setFramerateLimit(60);
    //load texture (surfer)
    try{
        surfer_texture.loadFromFile("../assets/SurferSprite.png");
    }
    catch(const std::exception& err){
        std::cout << "Error 1: Texture Load Failure";
        exit(1);
    }
    //assign text to sprite; config defaults
    surfer.setTexture(surfer_texture);
    surfer.setTextureRect(sf::IntRect(0.0f,0.0f,32.0f,32.0f));
    surfer.setPosition(325.0f, 250.0f);
}

//Master game loop
void Game::run(){
    while(window.isOpen()){
        processEvents();
        update();
        render();
    }
}

//user input handling -- questioning if this is best place
void Game::processEvents() {
    sf::Event event;
    while( window.pollEvent(event)){
        if (event.type == sf::Event::Closed){ window.close(); }
    }
}

//game logic
void Game::update() {}

//clear->draw->display
void Game::render() {
    window.clear();
    window.draw(surfer);
    window.display();
}