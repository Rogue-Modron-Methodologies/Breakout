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
    
//    sf::CircleShape *shape;
    sf::Sprite *sprite;
    sf::Texture texture;
    
public:
    /*
     Pass a file name to this constructor to be loading as a sprite
     if the file cannot be found the system will exit
     */
    DrawableObject(std::string file_name) {
        sprite = new sf::Sprite();
		if (!texture.loadFromFile(file_name))
			;// return EXIT_FAILURE;
        else
            sprite->setTexture(texture);
    };

    ~DrawableObject() {
        delete sprite;
    }

    void draw(sf::RenderWindow &window) { window.draw(*sprite); }
    
protected:
    void move(sf::Vector2f velocity) { sprite->move(velocity); }
    
    unsigned getWidth() { return texture.getSize().x; }
	unsigned getHeight() { return texture.getSize().y;}
    
    sf::Vector2f getPosition() { return sprite->getPosition(); }
    
    void setPosition(sf::Vector2f position) { sprite->setPosition(position); }
    void setPosition(float x, float y) { sprite->setPosition(x, y); }
    
};





#endif /* DrawableObject_h */
