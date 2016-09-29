//
//  Paddle.h
//  Breakout
//
//  Created by Edward on 9/27/16.
//  Copyright © 2016 Edward. All rights reserved.
//

#ifndef Paddle_h
#define Paddle_h
#include "MovableObject.h"

class Paddle : public MovableObject {
    
public:
    Paddle(std::string file_name, float acc, sf::RenderWindow &window) : MovableObject(file_name) {
       // acceleration = acc;
        setObjectPosition((float)window.getSize().x / 2 - getObjectWidth() / 2,
						(float)window.getSize().y * (3.0f/4.0f) - getObjectHeight() / 2);
    };
    void move() { moveObject(); }
    
    //setters and getters for all the attribuites of Movable objects would go here if made private
};


#endif /* Paddle_h */
