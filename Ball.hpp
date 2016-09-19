//
//  Ball.hpp
//  Breakout
//
//  Created by Edward on 9/18/16.
//  Copyright © 2016 Edward. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Ball {
    
private:
    
    float radius = 0.0;
    //TO BE DETERMINED IF BALL CLASS HANDLES THE EVENTS
//    bool movR = false,
//         movL = false,
//         movU = false,
//         movD = false;
    
    sf::Vector2f velocity = { 0, 0 };
    float acceleration = .1f;
    float posMaxAcc = 1;
    float negMaxAcc = -1;
    
    //WILL BE REPLACED WTIH SPIRTE SOON
    sf::CircleShape shape;
    
public:
    
    Ball();
    
    sf::CircleShape getBall() { return shape; }
    
    void updatePosition(Ball ball);
    
    //TO BE DETERMINED IF BALL CLASS HANDLES THE EVENTS
//    void setMovR(bool movR) { this->movR = movR; }
//    void setMovL(bool movL) { this->movL = movL; }
//    void setMovU(bool movU) { this->movU = movU; }
//    void setMovD(bool movD) { this->movD = movD; }
//    
//    bool getMovR() { return movR; }
//    bool getMovL() { return movL; }
//    bool getMovU() { return movU; }
//    bool getMovD() { return movD; }
    
    float getRadius() { return shape.getRadius(); }
    
    void setVelocityY(float y) { velocity.y = y; }
    void setVelocityX(float x) { velocity.x = x; }
    void setPosition(float x, float y);
    
    sf::Vector2f getVelocity() { return velocity; }
    sf::Vector2f getPosition() { return shape.getPosition(); }
    
    float getPosMaxAcc() { return posMaxAcc; }
    float getNegMaxAcc() { return negMaxAcc; }
    float getAcceleration() { return acceleration; }
    
};

#endif /* Ball_hpp */





















