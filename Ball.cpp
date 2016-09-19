//
//  Ball.cpp
//  Breakout
//
//  Created by Edward on 9/18/16.
//  Copyright © 2016 Edward. All rights reserved.
//

#include "Ball.hpp"

Ball::Ball() {
    shape.setFillColor(sf::Color::Red);
    shape.setRadius(40.f);
    std::cout << shape.getRadius() * 2 << std::endl;
}

/*
 This method is to be called continiously by the game loop
*/
void Ball::updatePosition(Ball ball) {
    shape.move(ball.getVelocity());
}

void Ball::setPosition(float x, float y) {
    shape.setPosition(x, y);
}