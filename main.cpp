
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Ball.h"
#include "Paddle.h"

//Function declarations
void handleUserEvents(sf::Event event);
void handleBallVelocity();
void handleBallBounds();
void handlePaddleMovement();

//Temporarily make variables global, these will eventually be encapsulated within
//a Ball Class
bool movR, movL, movU, movD;
//Initalize a new ball class
Ball *ball;
Paddle *paddle;

sf::RenderWindow window(sf::VideoMode(800, 800), "ScrumBums SFML: Look it works!");


int main() {
    
    movR = movL = movU = movD = false;
    ball = new Ball("ball.png", window);
    paddle = new Paddle("paddle.png", 1.f, window);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            handleUserEvents(event);
        }
        
        handlePaddleMovement();
        handleBallVelocity();
        
        ball->handleBounds(window);
        paddle->handleBounds(window);
        
        paddle->move();
        ball->move();
        window.clear();
        paddle->drawObject(window);
        ball->drawObject(window);
        window.display();
        
        //        std::cout<<shape.getPosition().x << "____"  << shape.getPosition().y << std::endl;
    }
    
    return 0;
}

/*
 GAME CLASS will handle all the user inputs
 if keyboards toggled handles paddle movements
 */
void handlePaddleMovement() {
    //left key is held, move at a constant speed towards left
    if (movL) {
        paddle->velocity.x = -paddle->acceleration;
    }
    else if (movR) {
        paddle->velocity.x = paddle->acceleration;
    }
    else if (!movL || !movR) {
        paddle->velocity.x = 0;
    }
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
            
        
//            if (event.key.code == sf::Keyboard::C) {
//                
//                
//                ball->setObjectPosition(window.getSize().x / 2 - ball->getRadius(),
//                                  window.getSize().y / 2 - ball->getRadius());
//                
//            }
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
    if (movD)
        ball->changeVelocity(0);
    else if (movU)
        ball->changeVelocity(1);
    else if (movR)
        ball->changeVelocity(2);
    else if (movL)
        ball->changeVelocity(3);
    
}

/*
 This method handles the bounds of the ball
 and ensures that the ball stays within the size of
 window.
 */
//void handleBallBounds() {
//    if (ball.getPosition().x < 0) {
//        ball.setVelocityX( 0 - ball.getVelocity().x);
//        ball.setPosition(0, ball.getPosition().y);    }
//    if (ball.getPosition().y < 0) {
//        ball.setVelocityY(0 - ball.getVelocity().y);
//        ball.setPosition(ball.getPosition().x, 0);
//    }
//    if (ball.getPosition().x + ball.getRadius() * 2 > window.getSize().x) {
//        ball.setVelocityX(0 - ball.getVelocity().x);
//        ball.setPosition(window.getSize().x - ball.getRadius() * 2, ball.getPosition().y);
//    }
//    if (ball.getPosition().y + ball.getRadius() * 2 > window.getSize().y) {
//        ball.setVelocityY(0 - ball.getVelocity().y);
//        ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() * 2);
//    }
//}

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
