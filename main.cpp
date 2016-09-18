//  SFML Demo

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main() {
    bool movR, movL, movU, movD;
    movR = movL = movU = movD = false;
    
    sf::Vector2f velocity = { 0, 0 };
    float acceleration = .1f;
    float posMaxAcc = 1;
    float negMaxAcc = -1;
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "ScrumBums SFML: Look it works!");
    sf::CircleShape shape(80.f);
    shape.setFillColor(sf::Color::Red);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
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
//        else {
//            velocity.x = 0;
//            velocity.y = 0;
//        }
        
        if (shape.getPosition().x < 0) {
            velocity.x = 0 - velocity.x;
            velocity.y = 0;
            
            shape.setPosition(0, shape.getPosition().y);
        }
        
        if (shape.getPosition().y < 0) {
            velocity.x = 0;
            velocity.y = 0 - velocity.y;
            
            shape.setPosition(shape.getPosition().x, 0);
        }
        
        if (shape.getPosition().x + shape.getRadius() * 2 > window.getSize().x) {
            velocity.x = 0 - velocity.x;
            velocity.y = 0;
            
            shape.setPosition(window.getSize().x - shape.getRadius() * 2, shape.getPosition().y);
        }
        
        if (shape.getPosition().y + shape.getRadius() * 2 > window.getSize().y) {
            velocity.x = 0;
            velocity.y = 0 - velocity.y;
            
            shape.setPosition(shape.getPosition().x, window.getSize().y - shape.getRadius() * 2);
        }
        
        shape.move(velocity);
        window.clear();
        window.draw(shape);
        window.display();
        
//        std::cout<<shape.getPosition().x << "____"  << shape.getPosition().y << std::endl;
    }
    
    return 0;
}