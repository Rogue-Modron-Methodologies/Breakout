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
public:
    sf::Vector2f velocity;
    float acceleration;
    float posMaxAcc;
    float negMaxAcc;
    
//public:
    
    MovableObject(std::string file_path = "",
                  sf::Vector2f velocity = { 0, 0 },
                  float acceleration = .1f,
                  float posMaxAcc = 1,
                  float negMaxAcc = -1
                  ) : DrawableObject(file_path)
    {
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
     This method handles the bounds of the sprite
     and ensures that the sprite stays within the size of
     window passed
     */
    void handleBounds(sf::RenderWindow &window) {
        if (getPosition().x < 0) {
            velocity.x = 0 - velocity.x;
            setPosition(0, (float)getObjectPosition().y);
        }
        if (getPosition().y < 0) {
            velocity.y = 0 - velocity.y;
            setPosition((float)getObjectPosition().x, 0);
        }
        if (getObjectPosition().x + getWidth() > (float)window.getSize().x) {
            velocity.x = 0 - velocity.x;
            setPosition((float)window.getSize().x - getWidth(), (float)getObjectPosition().y);
        }
        if (getObjectPosition().y + getWidth() > (float)window.getSize().y) {
            velocity.y = 0 - velocity.y;
            setPosition((float)getObjectPosition().x, (float)window.getSize().y - getWidth());
        }
    }
    
    void drawObject(sf::RenderWindow &window) { draw(window); }
    
    void setObjectPosition(float x, float y) {
        setPosition(x , y);
    };
    float getObjectHeight() { return (float)getHeight(); }
    float getObjectWidth() { return (float)getWidth(); }
    
    sf::Vector2f getVelocity() { return velocity; }
    sf::Vector2f getObjectPosition() { return getPosition(); }
    
    float getPosMaxAcc() { return posMaxAcc; }
    float getNegMaxAcc() { return negMaxAcc; }
    float getAcceleration() { return acceleration; }
    
    
};


#endif /* MovableObject_h */
