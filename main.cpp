//  SFML Demo

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

//Function declarations
void handleUserEvents(sf::Event event);
void handleBallVelocity();
void handleBallBounds();

//Temporarily make variables global, these will eventually be encapsulated within
//a Ball Class
bool movR, movL, movU, movD;
sf::Vector2f velocity;
float acceleration;
float posMaxAcc;
float negMaxAcc;
sf::CircleShape shape(40.f);

sf::RenderWindow window(sf::VideoMode(800, 800), "ScrumBums SFML: Look it works!");


int main() {

    movR = movL = movU = movD = false;
    velocity = { 0, 0 };
    
    acceleration = .1f;
    posMaxAcc = 1;
    negMaxAcc = -1;
    
    shape.setFillColor(sf::Color::Red);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            handleUserEvents(event);
        }
        
        handleBallVelocity();
        
        //        else {
        //            velocity.x = 0;
        //            velocity.y = 0;
        //        }
        
        handleBallBounds();
        
        shape.move(velocity);
        window.clear();
        window.draw(shape);
        window.display();
        
        //        std::cout<<shape.getPosition().x << "____"  << shape.getPosition().y << std::endl;
    }
    
    return 0;
}

/*
 This method handles user by matching keyboard events
 with corresponding actions
*/
void handleUserEvents(sf::Event event) {
    switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
            if (event.key.code == sf::Keyboard::Right) {
                movR = true;
                movL = false;
            }
            if (event.key.code == sf::Keyboard::Left) {
                movL = true;
                movR = false;
            }
            if (event.key.code == sf::Keyboard::Up) {
                movU = true;
                movD = false;
            }
            if (event.key.code == sf::Keyboard::Down) {
                movD = true;
                movU = false;
            }
            
            if (event.key.code == sf::Keyboard::C) {
                shape.setPosition(window.getSize().x / 2 - shape.getRadius(),
                                  window.getSize().y / 2 - shape.getRadius());
                
            }
            break;
        case sf::Event::KeyReleased:
            if (event.key.code == sf::Keyboard::Right)
                movR = false;
            if (event.key.code == sf::Keyboard::Left)
                movL = false;
            if (event.key.code == sf::Keyboard::Up)
                movU = false;
            if (event.key.code == sf::Keyboard::Down)
                movD = false;
            break;
    }
}

/*
 This method increments the velocity of the "Ball"
 in the corresponding directions matching the keyboard
 keys
*/
void handleBallVelocity() {
    if (movD) {
        if (velocity.y < posMaxAcc)
            velocity.y += acceleration;
        else
            velocity.y = posMaxAcc;
    }
    else if (movU) {
        if (velocity.y > negMaxAcc)
            velocity.y -= acceleration;
        else
            velocity.y = negMaxAcc;
    }
    else if (movR) {
        if (velocity.x < posMaxAcc)
            velocity.x += acceleration;
        else
            velocity.x = posMaxAcc;
    }
    else if (movL) {
        if (velocity.x > negMaxAcc)
            velocity.x -= acceleration;
        else
            velocity.x = negMaxAcc;
    }

}

/*
 This method handles the bounds of the ball
 and ensures that the ball stays within the size of 
 window.
*/
void handleBallBounds() {
    if (shape.getPosition().x < 0) {
        velocity.x = 0 - velocity.x;
        shape.setPosition(0, shape.getPosition().y);
    }
    if (shape.getPosition().y < 0) {
        velocity.y = 0 - velocity.y;
        shape.setPosition(shape.getPosition().x, 0);
    }
    if (shape.getPosition().x + shape.getRadius() * 2 > window.getSize().x) {
        velocity.x = 0 - velocity.x;
        shape.setPosition(window.getSize().x - shape.getRadius() * 2, shape.getPosition().y);
    }
    if (shape.getPosition().y + shape.getRadius() * 2 > window.getSize().y) {
        velocity.y = 0 - velocity.y;
        shape.setPosition(shape.getPosition().x, window.getSize().y - shape.getRadius() * 2);
    }
}
















