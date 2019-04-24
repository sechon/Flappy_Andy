//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon

//Network.cpp

#include "Network.h"

Network::Network() {
	//please do not change
	ftp.connect("spencerechon.com", 21, sf::seconds(5));
	ftp.login("flappyandy01", "011094568");
	highscore = 0;
}

Network::~Network() {
	ftp.disconnect();
}

int Network::getHighscore() {
	string temp;
	std::fstream infile;
	infile.open("highscore/highscore.txt");
	infile >> temp;
	highscore = std::stoi(temp);
	return highscore;
}
void Network::setHighscore(int points) {
	if (points > highscore) {
		highscore = points;
		std::fstream outfile;
		outfile.open("highscore/highscore.txt", std::fstream::out | std::fstream::trunc);
		outfile << points;
		outfile.close();
	}
}


void Network::uploadHighscore() {
	//bool success = false;
	ftp.upload("highscore/highscore.txt", "flappyandy", sf::Ftp::Ascii);
	
	//return success;
}

void Network::downloadHighscore() {
	//bool success = false;
	ftp.download("flappyandy/highscore.txt", "highscore", sf::Ftp::Ascii);

	//return success;
}

