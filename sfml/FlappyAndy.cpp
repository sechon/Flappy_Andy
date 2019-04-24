//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon

//FlappyAndy.cpp

#include "FlappyAndy.h"

void FlappyAndy::runApp() {

	bool soundSuccess = false, collisionSuccess = false, pointCheck = false;
	int jumpCheck = 0;
	srand(time(NULL));//for random number

	//open window
	sf::RenderWindow window(sf::VideoMode(1300, 700), "Flappy Andy");

	//declerations
	sf::Texture Gameover, pointsT;
	sf::Sprite GameoverSprite, pointsS;
	sf::SoundBuffer SplatBuffer;
	sf::Sound Splat;
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	Network Highscore;
	Points pointClass;

	//class declerations
	CreateSprite *background = new CreateSprite("pics/background.png");
	Andy *andy = new Andy("pics/andy2.png");
	Pipe *pipeBottom = new Pipe("pics/pipe.png");
	Pipe *pipeTop = new Pipe("pics/pipe2.png");
	andy->initializeAndy();
	pipeBottom->initializePipe();
	pipeTop->initializePipe();
	background->initializeSprite();
	background->scaleSprite(adjustX, adjustY);

	int i = 0, y = 0, y2 = 0, points = 0;

	//set textures from file
	pointsT.loadFromFile("pics/points.png");

	//pipe
	//bottom
	pipeBottom->scalePipe();
	pipeBottom->setPipePosition(1000, 550);
	//top
	pipeTop->scalePipe();
	pipeTop->setPipePosition(1000, -550);


	//gameover
	Gameover.loadFromFile("pics/gameover.png");
	GameoverSprite.setTexture(Gameover);
	GameoverSprite.scale(adjustX, adjustY);

	//points
	pointsS.setTexture(pointsT);
	pointsS.scale(adjustX, adjustY);
	pointsS.setPosition(0, 0);
	
	//audio
	SplatBuffer.loadFromFile("audio/splat.wav");
	Splat.setBuffer(SplatBuffer);

	//open window section
	while (window.isOpen()) {
		//set framerate
		window.setFramerateLimit(60);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//count time
		elapsed = clock.getElapsedTime();

		//draw
		window.draw(background->getSprite());
		window.draw(andy->getSprite());
		window.draw(pipeTop->getSprite());
		window.draw(pipeBottom->getSprite());

		//draw game over
		if (collisionSuccess == true) {
			//display game over
			window.draw(GameoverSprite);
			pointsS.setPosition(-1410, 325);
			pointsS.setScale(1.2, 1.2);
			window.draw(pointsS);
			pointClass.showPointsLarge(window, points, 625, 450);

			//network highscore
			Highscore.downloadHighscore();
			Highscore.getHighscore();
			Highscore.setHighscore(points);
			Highscore.uploadHighscore();
		}

		if (collisionSuccess == false) {//start movements
			//show points upper right
			window.draw(pointsS);
			pointClass.showPoints(window, points, 1250, 50);

			//constant gravity
			if (andy->getPositionY() < 650) {
				andy->moveAndy(0, 10);
				andy->rotateAndy(10);
			}

			//check for lower bounds
			if (andy->getPositionY() > 650 && soundSuccess == false) {
				Splat.play();
				soundSuccess = true;
				collisionSuccess = true;
				////restarts loop time
				clock.restart();
				elapsed = clock.getElapsedTime();
			}

			//flying up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && jumpCheck <= 5){
				if (andy->getPositionY() > -25) {
					andy->setAndy(andy->getPositionX(), andy->getPositionY() - 5);
					andy->moveAndy(0, -20);
					andy->rotateAndy(-10);
					jumpCheck++;
				}
				//check for upper bounds
				if (andy->getPositionY() < -25 && soundSuccess == false) {
					Splat.play();
					soundSuccess = true;
					collisionSuccess = true;
					////restarts loop time
					clock.restart();
					elapsed = clock.getElapsedTime();
				}
				jumpCheck = true;
				clock.restart();
				elapsed = clock.getElapsedTime();
			}

			//moving pipe
			pipeBottom->movePipe(-16, 0);
			pipeTop->movePipe(-16, 0);

			//random reset pipe
			i = rand() % 3;
			switch (i) {
			case 0:
				y = 550;
				y2 = -550;
				break;
			case 1:
				y = 450;
				y2 = -650;
				break;
			case 2:
				y = 650;
				y2 = -450;
				break;
			}
			if (pipeBottom->getSprite().getPosition().x < -200) {
				pipeBottom->setPipePosition(1400, y);
				pointCheck = false;
			}
			if (pipeTop->getSprite().getPosition().x < -200) {
				pipeTop->setPipePosition(1400, y2);
			}

			//points
			if (pipeBottom->getSprite().getPosition().x < andyX && pointCheck == false) {
				points++;
				pointCheck = true;
			}

			//pipebottom collision
			if (andy->getSprite().getGlobalBounds().intersects(pipeBottom->getSprite().getGlobalBounds())) {
				if (soundSuccess == false) {
					Splat.play();
					soundSuccess = true;
					collisionSuccess = true;
					////restarts loop time
					clock.restart();
					elapsed = clock.getElapsedTime();
				}
			}

			//pipetop collision
			if (andy->getSprite().getGlobalBounds().intersects(pipeTop->getSprite().getGlobalBounds())) {
				if (soundSuccess == false) {
					Splat.play();
					soundSuccess = true;
					collisionSuccess = true;
					////restarts loop time
					clock.restart();
					elapsed = clock.getElapsedTime();
				}
			}

		}//end collision check

		window.display();

		//time checks
		if (jumpCheck >= 5 && elapsed >= sf::milliseconds(200)) {
			jumpCheck = 0;
		}
		
		if (collisionSuccess == true && elapsed >= sf::seconds(1)) {
			window.close();
		}

	}//end of open window section
}

FlappyAndy::~FlappyAndy() {
	std::cout << "Thanks for playing!" << std::endl;
}

