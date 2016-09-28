//
//  Movable.h
//  Breakout
//
//  Created by Edward on 9/27/16.
//  Copyright © 2016 Edward. All rights reserved.
//

#ifndef MovableObject_h
#define MovableObject_h
#include "DrawableObject.h"

class MovableObject : DrawableObject {
    
    sf::Vector2f velocity = { 0, 0 };
    float acceleration = .1f;
    float posMaxAcc = 1;
    float negMaxAcc = -1;
    
public:
    MovableObject(double rad, sf::Vector2f velocity = { 0, 0 }, float acceleration = .1f,
                  float posMaxAcc = 1, float negMaxAcc = -1) : DrawableObject(rad) {
        this->velocity = velocity;
        this->acceleration = acceleration;
        this->posMaxAcc = posMaxAcc;
        this->negMaxAcc = negMaxAcc;
    };
    
    void moveObject() {
        move(velocity);
    }
    
    /*
     This method increments the velocity of the "Ball"
     in the corresponding directions matching the keyboard
     keys
     */
    void changeVelocity(int direction) {
        
        switch (direction) {
            case 0:
                if (velocity.y < posMaxAcc)
                    velocity.y += acceleration;
                else
                    velocity.y = posMaxAcc;
                break;
            case 1:
                if (velocity.y > negMaxAcc)
                    velocity.y -= acceleration;
                else
                    velocity.y = negMaxAcc;
                break;
            case 2:
                if (velocity.x <posMaxAcc)
                    velocity.x += acceleration;
                else
                    velocity.x = posMaxAcc;
                break;
            case 3:
                if (velocity.x > negMaxAcc)
                    velocity.x -= acceleration;
                else
                    velocity.x = negMaxAcc;
                break;
        }
    }
    
    /*
     This method handles the bounds of the ball
     and ensures that the ball stays within the size of
     window.
     */
    void handleBounds(sf::RenderWindow &window) {
        if (getPosition().x < 0) {
            velocity.x = 0 - velocity.x;
            setPosition(0, getObjectPosition().y);
        }
        if (getPosition().y < 0) {
            velocity.y = 0 - velocity.y;
            setPosition(getObjectPosition().x, 0);
        }
        if (getObjectPosition().x + getObjectRadius() * 2 > window.getSize().x) {
            velocity.x = 0 - velocity.x;
            setPosition(window.getSize().x - getObjectRadius() * 2, getObjectPosition().y);
        }
        if (getObjectPosition().y + getObjectRadius() * 2 > window.getSize().y) {
            velocity.y = 0 - velocity.y;
            setPosition(getObjectPosition().x, window.getSize().y - getObjectRadius() * 2);
        }
    }
    
    void drawObject(sf::RenderWindow &window) { draw(window); }
    
    float getObjectRadius() { return getRadius(); }
    
    void setVelocityY(float y) { velocity.y = y; }
    void setVelocityX(float x) { velocity.x = x; }
    void setObjectPosition(float x, float y);
    
    sf::Vector2f getVelocity() { return velocity; }
    sf::Vector2f getObjectPosition() { return getPosition(); }
    
    float getPosMaxAcc() { return posMaxAcc; }
    float getNegMaxAcc() { return negMaxAcc; }
    float getAcceleration() { return acceleration; }

    
};


#endif /* MovableObject_h */
