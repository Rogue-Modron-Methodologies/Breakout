//
//  Game.h
//  Breakout
//
//  Created by Edward on 9/18/16.
//  Copyright � 2016 Edward. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include "Ball.h"
#include "Paddle.h"
#include "Table.h"

class Game{

	bool movR, movL, movU, movD;
	Ball *ball;
	Paddle *paddle;
	sf::RenderWindow window;
	Table *table;
	//ResourceManager<sf::Texture> txtMngr;
	
public:
	Game() : window(sf::VideoMode(800, 800), "Breakout") {
		movR = movL = movU = movD = false;
		ball = new Ball("ball.png", window);
        table = new Table(3, 3, "paddle.png", window);
		// Will need a better way to initialize the balls velocity
		ball->changeVelocity(Direction::right);
		ball->changeVelocity(Direction::up);
		paddle = new Paddle("paddle.png", 1.f, window);
	}

	int playGame(){

		window.setFramerateLimit(60);
		sf::Event event;
		while (window.isOpen()) {
			while (window.pollEvent(event)) {
				handleUserEvents(event);
			}
			moveGameObjects();		
			window.clear();
			drawGame();
			window.display();
		}
		return 0;
	}
private:
	/*
	Handles user input by matching keyboard events
	with corresponding actions
	*/
	void handleUserEvents(sf::Event event) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window.close();
			if (event.key.code == sf::Keyboard::Right) 
				movR = true, movL = false;
			if (event.key.code == sf::Keyboard::Left)
				movL = true, movR = false;		
			if (event.key.code == sf::Keyboard::Up) 
				movU = true, movD = false;
			if (event.key.code == sf::Keyboard::Down) 
				movD = true, movU = false;
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

	void moveGameObjects() {
		//Handles paddle movements
		if (movL)
			paddle->changeVelocity(Direction::left);
		else if (movR)
			paddle->changeVelocity(Direction::right);
		else if (!movL || !movR)
			paddle->changeVelocity(Direction::stop);

		checkCollisions();
		paddle->move();
		ball->move();
	}

	void checkCollisions() {
		ball->handleBounds(window, true);
		paddle->handleBounds(window, false);

		if (ball->getObjectPosition().y >= paddle->getObjectPosition().y) {
			ball->handleBounds(paddle, true);
		}

	}

	void drawGame() {
        table->drawObjects(window);
		paddle->drawObject(window);
		ball->drawObject(window);
	}
};

#endif /* Game_h */





















