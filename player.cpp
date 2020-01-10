#include "player.h"


Player::Player(string Id) {
	this->Id = Id;
	this->lastScore = 0;
	this->bestScore = 0;
}

void Player::setBestScore(int score) {
	if (score > bestScore) {
		bestScore = score;
	}
	
}

void Player::setLatestScore(int score) {
	lastScore = score;
}

int Player::getLatestScore() {
	return lastScore;
}

int Player::getBestScore() {
	return bestScore;
}