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
#include <iostream>
#include <string>
#include "MovableObject.h"

class Ball : public MovableObject {
    
public:
    
    Ball(double rad) : MovableObject(rad) {};
    void move() { moveObject(); }
};

#endif /* Ball_hpp */





















