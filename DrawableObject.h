//
//  Drawable.h
//  Breakout
//
//  Created by Edward on 9/27/16.
//  Copyright © 2016 Edward. All rights reserved.
//

#ifndef DrawableObject_h
#define DrawableObject_h
#include <SFML/Graphics.hpp>

class DrawableObject {
    
    sf::CircleShape *shape;
public:
    DrawableObject(double rad) {
        shape = new sf::CircleShape(rad);
    };
    
    DrawableObject() { delete shape; }

    void draw(sf::RenderWindow &window) {
        window.draw(*shape);
    }
    
    
    
protected:
    void move(sf::Vector2f velocity) {
        shape->move(velocity);
    }
    
    float getRadius() { return shape->getRadius(); }
    
    sf::Vector2f getPosition() { return shape->getPosition(); }
    void setPosition(sf::Vector2f position) { shape->setPosition(position); }
    void setPosition(float x, float y) { shape->setPosition(x, y); }
    
};





#endif /* DrawableObject_h */
