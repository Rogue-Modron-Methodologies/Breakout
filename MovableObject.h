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

enum class Direction{ down = 0, up = 1, right = 2, left = 3, stop = 4 };

class MovableObject : DrawableObject {
    sf::Vector2f velocity;
    float acceleration;
    float posMaxAcc;
    float negMaxAcc;
    
public:
    
    MovableObject(std::string file_path = "",
                  sf::Vector2f velocity = { 0, 0 },
                  float acceleration = 1.0f,
                  float posMaxAcc = 10.0f,
                  float negMaxAcc = -10.0f
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
     This method increments the velocity in the 
	 direction arguement.
     */
    void changeVelocity(Direction direction) {
        
        switch (direction) {
			case Direction::down:
                if (velocity.y < posMaxAcc)
                    velocity.y += acceleration;
                else
                    velocity.y = posMaxAcc;
                break;
            case Direction::up:
                if (velocity.y > negMaxAcc)
                    velocity.y -= acceleration;
                else
                    velocity.y = negMaxAcc;
                break;
            case Direction::right:
                if (velocity.x <posMaxAcc)
                    velocity.x += acceleration;
                else
                    velocity.x = posMaxAcc;
                break;
            case Direction::left:
                if (velocity.x > negMaxAcc)
                    velocity.x -= acceleration;
                else
                    velocity.x = negMaxAcc;
                break;
			case Direction::stop:
				velocity = { 0, 0 };
				break;
        }
    }
    
    /*
     This method handles the bounds of the sprite
     and ensures that the sprite stays within the size of
     window passed
     */
    void handleBounds(sf::RenderWindow &window, bool rebound) {
        if (getPosition().x < 0) {
            setPosition(0, (float)getObjectPosition().y);
			velocity.x = rebound ? 0 - velocity.x : 0;
        }
        if (getPosition().y < 0) {
            setPosition((float)getObjectPosition().x, 0);
			velocity.y = rebound ? 0 - velocity.y : 0;
        }
        if (getObjectPosition().x + getWidth() > (float)window.getSize().x) {
            setPosition((float)window.getSize().x - getWidth(), (float)getObjectPosition().y);
			velocity.x = rebound ? 0 - velocity.x : 0;
        }
        if (getObjectPosition().y + getWidth() > (float)window.getSize().y) {
            setPosition((float)getObjectPosition().x, (float)window.getSize().y - getWidth());
			velocity.y = rebound ? 0 - velocity.y : 0;
        }
    }
    
    void drawObject(sf::RenderWindow &window) { draw(window); }
    
	void setObjectPosition(float x, float y) { setPosition(x, y); }

    float getObjectHeight() { return (float)getHeight(); }
    float getObjectWidth() { return (float)getWidth(); }
    
    sf::Vector2f getVelocity() { return velocity; }
    sf::Vector2f getObjectPosition() { return getPosition(); } 
}; 
#endif /* MovableObject_h */
