//SFML Demo

//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <string>
//
//int main() {
//    bool movR, movL, movU, movD;
//    movR = movL = movU = movD = false;
//    
//    sf::Vector2f velocity = { 0, 0 };
//    float acceleration = .1f;
//    float posMaxAcc = 1;
//    float negMaxAcc = -1;
//    
//    sf::RenderWindow window(sf::VideoMode(800, 800), "ScrumBums SFML: Look it works!");
//    sf::CircleShape shape(40.f);
//    shape.setFillColor(sf::Color::Red);
//    
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            switch (event.type) {
//                case sf::Event::Closed:
//                    window.close();
//                    break;
//                case sf::Event::KeyPressed:
//                    if (event.key.code == sf::Keyboard::Escape)
//                        window.close();
//                    if (event.key.code == sf::Keyboard::Right) {
//                        movR = true;
//                        movL = false;
//                    }
//                    if (event.key.code == sf::Keyboard::Left) {
//                        movL = true;
//                        movR = false;
//                    }
//                    if (event.key.code == sf::Keyboard::Up) {
//                        movU = true;
//                        movD = false;
//                    }
//                    if (event.key.code == sf::Keyboard::Down) {
//                        movD = true;
//                        movU = false;
//                    }
//                    
//                    if (event.key.code == sf::Keyboard::C) {
//                        shape.setPosition(window.getSize().x / 2 - shape.getRadius(),
//                                          window.getSize().y / 2 - shape.getRadius());
//                    
//                    }
//                    break;
//                case sf::Event::KeyReleased:
//                    if (event.key.code == sf::Keyboard::Right)
//                        movR = false;
//                    if (event.key.code == sf::Keyboard::Left)
//                        movL = false;
//                    if (event.key.code == sf::Keyboard::Up)
//                        movU = false;
//                    if (event.key.code == sf::Keyboard::Down)
//                        movD = false;
//                    break;
//            }
//        }
//        
//        if (movD) {
//            if (velocity.y < posMaxAcc)
//                velocity.y += acceleration;
//            else
//                velocity.y = posMaxAcc;
//        }
//        else if (movU) {
//            if (velocity.y > negMaxAcc)
//                velocity.y -= acceleration;
//            else
//                velocity.y = negMaxAcc;
//        }
//        else if (movR) {
//            if (velocity.x < posMaxAcc)
//                velocity.x += acceleration;
//            else
//                velocity.x = posMaxAcc;
//        }
//        else if (movL) {
//            if (velocity.x > negMaxAcc)
//                velocity.x -= acceleration;
//            else
//                velocity.x = negMaxAcc;
//        }
////        else {
////            velocity.x = 0;
////            velocity.y = 0;
////        }
//        
//        if (shape.getPosition().x < 0) {
//            velocity.x = 0 - velocity.x;     
//            shape.setPosition(0, shape.getPosition().y);
//        }       
//        if (shape.getPosition().y < 0) {
//            velocity.y = 0 - velocity.y;    
//            shape.setPosition(shape.getPosition().x, 0);
//        }       
//        if (shape.getPosition().x + shape.getRadius() * 2 > window.getSize().x) {
//            velocity.x = 0 - velocity.x;          
//            shape.setPosition(window.getSize().x - shape.getRadius() * 2, shape.getPosition().y);
//        }       
//        if (shape.getPosition().y + shape.getRadius() * 2 > window.getSize().y) {
//            velocity.y = 0 - velocity.y;
//            shape.setPosition(shape.getPosition().x, window.getSize().y - shape.getRadius() * 2);
//        }
//        
//        shape.move(velocity);
//        window.clear();
//        window.draw(shape);
//        window.display();
//        
////        std::cout<<shape.getPosition().x << "____"  << shape.getPosition().y << std::endl;
//    }
//    
//    return 0;
//}



                        /******************************************************
                         This will be how main calls the ball class in future 
                         UNCOMMENT the ORIGINAL main aboveto check it out
                         ******************************************************/


//  SFML Demo

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <Ball.hpp>

//Function declarations
void handleUserEvents(sf::Event event);
void handleBallVelocity();
void handleBallBounds();

//Temporarily make variables global, these will eventually be encapsulated within
//a Ball Class
bool movR, movL, movU, movD;
//Initalize a new ball class
Ball *ball = new Ball(40);

sf::RenderWindow window(sf::VideoMode(800, 800), "ScrumBums SFML: Look it works!");


int main() {
    
    movR = movL = movU = movD = false;
    
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
        
        ball->handleBounds(window);
        
//        handleBallBounds();
        
        ball->move();
        window.clear();
        ball->drawObject(window);
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

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
