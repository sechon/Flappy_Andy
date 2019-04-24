//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon

//Network.h

#pragma once
#include "CreateSprite.h"

class Network {
public:
	Network();
	~Network();
	int getHighscore();
	void setHighscore(int points);

	void uploadHighscore();
	void downloadHighscore();

	int highscore;
	sf::Ftp ftp;
};
