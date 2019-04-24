//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon

#include "FlappyAndy.h"

int main(){
	//Declare main wrapper
	FlappyAndy run;
	Rules rules;

	int velocity = 0;

	//highscore
	Network Highscore;
	int highscore = 0;
	Points points;

	//time
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	bool checkTime = false;

	//set window resolution
	sf::RenderWindow window(sf::VideoMode(1300, 700), "Flappy Andy Main Menu");
	
	//turn off repeated key strokes
	window.setKeyRepeatEnabled(false);

	//declare music
	sf::Music country;
	country.openFromFile("audio/country.ogg");

	//play background music
	country.play();

	//declare textures
	sf::Texture background, cursor, highscoreT;
	sf::Sprite Background, Cursor, highscoreS;

	background.loadFromFile("pics/draft2.png");
	Background.setTexture(background);
	Background.scale(adjustX,adjustY);

	cursor.loadFromFile("pics/cursor.png");
	Cursor.setTexture(cursor);
	Cursor.scale(adjustX, adjustY);
	Cursor.setPosition(520,350);

	//load highscore
	Highscore.downloadHighscore();
	highscore = Highscore.getHighscore();
	highscoreT.loadFromFile("pics/highscore.png");
	highscoreS.setTexture(highscoreT);
	highscoreS.setPosition(-15, 0);

	while (window.isOpen()){
		//set frame rate limit
		window.setFramerateLimit(60);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(Background);
		window.draw(Cursor);
		window.draw(highscoreS);
		points.showPoints(window, highscore, 25, 50);
		window.display();

		//increment elapsed time
		elapsed = clock.getElapsedTime();

		//start movements

		//menu options y positions
		////start: 350
		////rules: 407
		////select: 464
		////exit: 521

		//cursor up/down movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && checkTime == false) {
			if (Cursor.getPosition().y == 350) {
				Cursor.setPosition(Cursor.getPosition().x, 524);
			}
			else {
				Cursor.setPosition(Cursor.getPosition().x, Cursor.getPosition().y - 58);
			}
			//time reset
			clock.restart();
			elapsed = clock.getElapsedTime();
			//reset check
			checkTime = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && checkTime == false) {
			if (Cursor.getPosition().y == 524) {
				Cursor.setPosition(Cursor.getPosition().x, 350);
			}
			else {
				Cursor.setPosition(Cursor.getPosition().x, Cursor.getPosition().y + 58);
			}
			//time reset
			clock.restart();
			elapsed = clock.getElapsedTime();
			//reset check
			checkTime = true;
		}

		////cursor side to side movement
		Cursor.move(velocity, 0);
		if (Cursor.getPosition().x == 520) {//move right
			velocity = 1;
		}
		if (Cursor.getPosition().x >= 535) {//stop
			velocity = 0;
		}
		if (Cursor.getPosition().x == 535) {//move left
			velocity = -1;
		}


		//choose option using enter
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			//play
			if (Cursor.getPosition().y == 350) {
				run.runApp();
			}
			//rules
			if (Cursor.getPosition().y == 408) {
				rules.showRules();
			}
			//select
			if (Cursor.getPosition().y == 466) {

			}
			//exit
			if (Cursor.getPosition().y == 524) {
				window.close();
			}
		}

		//choose option using space
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			//play
			if (Cursor.getPosition().y == 350) {
				run.runApp();
			}
			//rules
			if (Cursor.getPosition().y == 408) {
				rules.showRules();
			}
			//select
			if (Cursor.getPosition().y == 466) {

			}
			//exit
			if (Cursor.getPosition().y == 524) {
				window.close();
			}
		}
		//reset time check after set time
		if (checkTime == true && elapsed >= sf::milliseconds(100)) {
			checkTime = false;
		}

	}

	return 0;
}