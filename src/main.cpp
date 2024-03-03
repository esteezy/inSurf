//
// Created by Evan Mason on 2/21/24.
//

#include "InSurf.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    //create win
    sf::RenderWindow window(sf::VideoMode(800, 650), "InSurf");
    window.setFramerateLimit(60);
    //load sprite (surfer)
    sf::Texture surfer;
    if(!surfer.loadFromFile("../assets/SurferSprite.png")){
        return EXIT_FAILURE;
    }
    sf::Sprite sprite;
    sprite.setTexture(surfer);
    sprite.setTextureRect(sf::IntRect(0.0f,0.0f,32.0f,32.0f));
    sprite.setPosition(400.0f, 325.0f);

    //game loop
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){ window.close(); }
        }

        if(sf::Keyboard::isKeyPressed((sf::Keyboard::Left))){
            sprite.setTextureRect(sf::IntRect(0.0f,0.0f,32.0f,32.0f));
            sprite.move(-2.5f, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed((sf::Keyboard::Right))){
            sprite.setTextureRect(sf::IntRect(0.0f,0.0f,32.0f,32.0f));
            sprite.move(2.5f, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed((sf::Keyboard::Up))){
            sprite.setTextureRect(sf::IntRect(32.0f,0.0f,32.0f,32.0f));
            sprite.move(0.0f, -2.5f);
        }
        if(sf::Keyboard::isKeyPressed((sf::Keyboard::Down))){
            sprite.setTextureRect(sf::IntRect(64.0f,0.0f,32.0f,32.0f));
            sprite.move(0.0f, 2.5f);
        }

        //clr screen
        window.clear();

        //draw surfer
        window.draw(sprite);

        //update window
        window.display();
    }
    return EXIT_SUCCESS;
}