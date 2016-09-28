//
//  Block.h
//  Breakout
//
//  Created by Edward on 9/18/16.
//  Copyright © 2016 Edward. All rights reserved.
//

#ifndef Block_h
#define Block_h

#include "DrawableObject.h"

class Block : public DrawableObject {

public:
	Block(std::string file_path, sf::Vector2f position) : DrawableObject(file_path) {
		setPosition(position);
	};

};

#endif /* Block_h */


















