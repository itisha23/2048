#include "game2048.h"
#include "game.h"
#include <iostream>
using namespace std;


void Game2048::playGame(int boardSize, string Id) {
	Game game(boardSize);
	int score = game.run();
	updateResults(score, Id);
	showScore(Id);
	

}

void Game2048::addInPlayers(string Id) {
	if (playerList.count(Id) == 0) {
		Player player(Id);
		playerList[Id] = player;
	}
}


void Game2048::showScore(string Id) {
	cout << "Your current score is " << playerList[Id].getLatestScore()<< endl;
	cout << "Your best score is " << playerList[Id].getBestScore() << endl;
}

void Game2048::updateResults(int score, string id) {

	playerList[id].setBestScore(score);
	playerList[id].setLatestScore(score);
}