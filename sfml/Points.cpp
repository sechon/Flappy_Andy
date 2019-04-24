//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon

//Points.cpp

#include "Points.h"



Points::Points() {	//with the help from Gear_Code @ github
	//load numbers from single file
	One.loadFromFile("pics/numbers.png", sf::IntRect(0, 0, 24, 67));
	Two.loadFromFile("pics/numbers.png", sf::IntRect(39, 0, 37, 67));
	Three.loadFromFile("pics/numbers.png", sf::IntRect(91, 0, 37, 67));
	Four.loadFromFile("pics/numbers.png", sf::IntRect(144, 0, 37, 67));
	Five.loadFromFile("pics/numbers.png", sf::IntRect(195, 0, 37, 67));
	Six.loadFromFile("pics/numbers.png", sf::IntRect(248, 0, 37, 67));
	Seven.loadFromFile("pics/numbers.png", sf::IntRect(301, 0, 37, 67));
	Eight.loadFromFile("pics/numbers.png", sf::IntRect(353, 0, 37, 67));
	Nine.loadFromFile("pics/numbers.png", sf::IntRect(405, 0, 37, 67));
	Zero.loadFromFile("pics/numbers.png", sf::IntRect(457, 0, 37, 67));

	//set textures
	ONE.setTexture(One);
	TWO.setTexture(Two);
	THREE.setTexture(Three);
	FOUR.setTexture(Four);
	FIVE.setTexture(Five);
	SIX.setTexture(Six);
	SEVEN.setTexture(Seven);
	EIGHT.setTexture(Eight);
	NINE.setTexture(Nine);
	ZERO.setTexture(Zero);
	DOUBLEONE.setTexture(One);
	DOUBLETWO.setTexture(Two);
	DOUBLETHREE.setTexture(Three);

	//adjust for screen resolution
	ONE.scale(adjustX, adjustY);
	TWO.scale(adjustX, adjustY);
	THREE.scale(adjustX, adjustY);
	FOUR.scale(adjustX, adjustY);
	FIVE.scale(adjustX, adjustY);
	SIX.scale(adjustX, adjustY);
	SEVEN.scale(adjustX, adjustY);
	EIGHT.scale(adjustX, adjustY);
	NINE.scale(adjustX, adjustY);
	ZERO.scale(adjustX, adjustY);
	DOUBLEONE.scale(adjustX, adjustY);
	DOUBLETWO.scale(adjustX, adjustY);
	DOUBLETHREE.scale(adjustX, adjustY);
}

void Points::showPoints(sf::RenderWindow& window, int points, int x, int y) {
	//single digit points
	if (points < 10) {
		ONE.setPosition(x, y);
		TWO.setPosition(x, y);
		THREE.setPosition(x, y);
		FOUR.setPosition(x, y);
		FIVE.setPosition(x, y);
		SIX.setPosition(x, y);
		SEVEN.setPosition(x, y);
		EIGHT.setPosition(x, y);
		NINE.setPosition(x, y);
		ZERO.setPosition(x, y);

		switch (points) {
		case 0:
			window.draw(ZERO);
			break;
		case 1:
			window.draw(ONE);
			break;
		case 2:
			window.draw(TWO);
			break;
		case 3:
			window.draw(THREE);
			break;
		case 4:
			window.draw(FOUR);
			break;
		case 5:
			window.draw(FIVE);
			break;
		case 6:
			window.draw(SIX);
			break;
		case 7:
			window.draw(SEVEN);
			break;
		case 8:
			window.draw(EIGHT);
			break;
		case 9:
			window.draw(NINE);
			break;
		}
	}

	//start double digit points
	if (points < 20) {

		DOUBLEONE.setPosition(x - 20, y);

		ONE.setPosition(x, y);
		TWO.setPosition(x, y);
		THREE.setPosition(x, y);
		FOUR.setPosition(x, y);
		FIVE.setPosition(x, y);
		SIX.setPosition(x, y);
		SEVEN.setPosition(x, y);
		EIGHT.setPosition(x, y);
		NINE.setPosition(x, y);
		ZERO.setPosition(x, y);

		switch (points) {
		case 10:
			window.draw(DOUBLEONE);
			window.draw(ZERO);
			break;
		case 11:
			window.draw(ONE);
			break;
		case 12:
			window.draw(DOUBLEONE);
			window.draw(TWO);
			break;
		case 13:
			window.draw(DOUBLEONE);
			window.draw(THREE);
			break;
		case 14:
			window.draw(DOUBLEONE);
			window.draw(FOUR);
			break;
		case 15:
			window.draw(DOUBLEONE);
			window.draw(FIVE);
			break;
		case 16:
			window.draw(DOUBLEONE);
			window.draw(SIX);
			break;
		case 17:
			window.draw(DOUBLEONE);
			window.draw(SEVEN);
			break;
		case 18:
			window.draw(DOUBLEONE);
			window.draw(EIGHT);
			break;
		case 19:
			window.draw(DOUBLEONE);
			window.draw(NINE);
			break;
		}
	}
	if (points < 30) {

		DOUBLETWO.setPosition(x - 20, y);

		ONE.setPosition(x, y);
		TWO.setPosition(x, y);
		THREE.setPosition(x, y);
		FOUR.setPosition(x, y);
		FIVE.setPosition(x, y);
		SIX.setPosition(x, y);
		SEVEN.setPosition(x, y);
		EIGHT.setPosition(x, y);
		NINE.setPosition(x, y);
		ZERO.setPosition(x, y);

		switch (points) {
		case 20:
			window.draw(DOUBLETWO);
			window.draw(ZERO);
			break;
		case 21:
			window.draw(DOUBLETWO);
			window.draw(ONE);
			break;
		case 22:
			window.draw(DOUBLETWO);
			window.draw(TWO);
			break;
		case 23:
			window.draw(DOUBLETWO);
			window.draw(THREE);
			break;
		case 24:
			window.draw(DOUBLETWO);
			window.draw(FOUR);
			break;
		case 25:
			window.draw(DOUBLETWO);
			window.draw(FIVE);
			break;
		case 26:
			window.draw(DOUBLETWO);
			window.draw(SIX);
			break;
		case 27:
			window.draw(DOUBLETWO);
			window.draw(SEVEN);
			break;
		case 28:
			window.draw(DOUBLETWO);
			window.draw(EIGHT);
			break;
		case 29:
			window.draw(DOUBLETWO);
			window.draw(NINE);
			break;
		}
	}
	if (points < 40) {

		DOUBLETHREE.setPosition(x - 20, y);

		ONE.setPosition(x, y);
		TWO.setPosition(x, y);
		THREE.setPosition(x, y);
		FOUR.setPosition(x, y);
		FIVE.setPosition(x, y);
		SIX.setPosition(x, y);
		SEVEN.setPosition(x, y);
		EIGHT.setPosition(x, y);
		NINE.setPosition(x, y);
		ZERO.setPosition(x, y);

		switch (points) {
		case 30:
			window.draw(DOUBLETHREE);
			window.draw(ZERO);
			break;
		case 31:
			window.draw(DOUBLETHREE);
			window.draw(ONE);
			break;
		case 32:
			window.draw(DOUBLETHREE);
			window.draw(TWO);
			break;
		case 33:
			window.draw(DOUBLETHREE);
			window.draw(THREE);
			break;
		case 34:
			window.draw(DOUBLETHREE);
			window.draw(FOUR);
			break;
		case 35:
			window.draw(DOUBLETHREE);
			window.draw(FIVE);
			break;
		case 36:
			window.draw(DOUBLETHREE);
			window.draw(SIX);
			break;
		case 37:
			window.draw(DOUBLETHREE);
			window.draw(SEVEN);
			break;
		case 38:
			window.draw(DOUBLETHREE);
			window.draw(EIGHT);
			break;
		case 39:
			window.draw(DOUBLETHREE);
			window.draw(NINE);
			break;
		}
	}

}

//larger font
void Points::showPointsLarge(sf::RenderWindow& window, int points, int x, int y) {
	ONE.setScale(1.6, 1.6);
	TWO.setScale(1.6, 1.6);
	THREE.setScale(1.6, 1.6);
	FOUR.setScale(1.6, 1.6);
	FIVE.setScale(1.6, 1.6);
	SIX.setScale(1.6, 1.6);
	SEVEN.setScale(1.6, 1.6);
	EIGHT.setScale(1.6, 1.6);
	NINE.setScale(1.6, 1.6);
	ZERO.setScale(1.6, 1.6);
	DOUBLEONE.setScale(1.6, 1.6);
	DOUBLETWO.setScale(1.6, 1.6);
	DOUBLETHREE.setScale(1.6, 1.6);
	
	if (points < 10) {

		ONE.setPosition(x, y);
		TWO.setPosition(x, y);
		THREE.setPosition(x, y);
		FOUR.setPosition(x, y);
		FIVE.setPosition(x, y);
		SIX.setPosition(x, y);
		SEVEN.setPosition(x, y);
		EIGHT.setPosition(x, y);
		NINE.setPosition(x, y);
		ZERO.setPosition(x, y);

		switch (points) {
		case 0:
			window.draw(ZERO);
			break;
		case 1:
			window.draw(ONE);
			break;
		case 2:
			window.draw(TWO);
			break;
		case 3:
			window.draw(THREE);
			break;
		case 4:
			window.draw(FOUR);
			break;
		case 5:
			window.draw(FIVE);
			break;
		case 6:
			window.draw(SIX);
			break;
		case 7:
			window.draw(SEVEN);
			break;
		case 8:
			window.draw(EIGHT);
			break;
		case 9:
			window.draw(NINE);
			break;
		}
	}
	if (points < 20) {

		DOUBLEONE.setPosition(x - 20, y);

		ONE.setPosition(x, y);
		TWO.setPosition(x, y);
		THREE.setPosition(x, y);
		FOUR.setPosition(x, y);
		FIVE.setPosition(x, y);
		SIX.setPosition(x, y);
		SEVEN.setPosition(x, y);
		EIGHT.setPosition(x, y);
		NINE.setPosition(x, y);
		ZERO.setPosition(x, y);

		switch (points) {
		case 10:
			window.draw(DOUBLEONE);
			window.draw(ZERO);
			break;
		case 11:
			window.draw(ONE);
			break;
		case 12:
			window.draw(DOUBLEONE);
			window.draw(TWO);
			break;
		case 13:
			window.draw(DOUBLEONE);
			window.draw(THREE);
			break;
		case 14:
			window.draw(DOUBLEONE);
			window.draw(FOUR);
			break;
		case 15:
			window.draw(DOUBLEONE);
			window.draw(FIVE);
			break;
		case 16:
			window.draw(DOUBLEONE);
			window.draw(SIX);
			break;
		case 17:
			window.draw(DOUBLEONE);
			window.draw(SEVEN);
			break;
		case 18:
			window.draw(DOUBLEONE);
			window.draw(EIGHT);
			break;
		case 19:
			window.draw(DOUBLEONE);
			window.draw(NINE);
			break;
		}
	}
	if (points < 30) {

		DOUBLETWO.setPosition(x - 20, y);

		ONE.setPosition(x, y);
		TWO.setPosition(x, y);
		THREE.setPosition(x, y);
		FOUR.setPosition(x, y);
		FIVE.setPosition(x, y);
		SIX.setPosition(x, y);
		SEVEN.setPosition(x, y);
		EIGHT.setPosition(x, y);
		NINE.setPosition(x, y);
		ZERO.setPosition(x, y);

		switch (points) {
		case 20:
			window.draw(DOUBLETWO);
			window.draw(ZERO);
			break;
		case 21:
			window.draw(DOUBLETWO);
			window.draw(ONE);
			break;
		case 22:
			window.draw(DOUBLETWO);
			window.draw(TWO);
			break;
		case 23:
			window.draw(DOUBLETWO);
			window.draw(THREE);
			break;
		case 24:
			window.draw(DOUBLETWO);
			window.draw(FOUR);
			break;
		case 25:
			window.draw(DOUBLETWO);
			window.draw(FIVE);
			break;
		case 26:
			window.draw(DOUBLETWO);
			window.draw(SIX);
			break;
		case 27:
			window.draw(DOUBLETWO);
			window.draw(SEVEN);
			break;
		case 28:
			window.draw(DOUBLETWO);
			window.draw(EIGHT);
			break;
		case 29:
			window.draw(DOUBLETWO);
			window.draw(NINE);
			break;
		}
	}
	if (points < 40) {

		DOUBLETHREE.setPosition(x - 20, y);

		ONE.setPosition(x, y);
		TWO.setPosition(x, y);
		THREE.setPosition(x, y);
		FOUR.setPosition(x, y);
		FIVE.setPosition(x, y);
		SIX.setPosition(x, y);
		SEVEN.setPosition(x, y);
		EIGHT.setPosition(x, y);
		NINE.setPosition(x, y);
		ZERO.setPosition(x, y);

		switch (points) {
		case 30:
			window.draw(DOUBLETHREE);
			window.draw(ZERO);
			break;
		case 31:
			window.draw(DOUBLETHREE);
			window.draw(ONE);
			break;
		case 32:
			window.draw(DOUBLETHREE);
			window.draw(TWO);
			break;
		case 33:
			window.draw(DOUBLETHREE);
			window.draw(THREE);
			break;
		case 34:
			window.draw(DOUBLETHREE);
			window.draw(FOUR);
			break;
		case 35:
			window.draw(DOUBLETHREE);
			window.draw(FIVE);
			break;
		case 36:
			window.draw(DOUBLETHREE);
			window.draw(SIX);
			break;
		case 37:
			window.draw(DOUBLETHREE);
			window.draw(SEVEN);
			break;
		case 38:
			window.draw(DOUBLETHREE);
			window.draw(EIGHT);
			break;
		case 39:
			window.draw(DOUBLETHREE);
			window.draw(NINE);
			break;
		}
	}
}