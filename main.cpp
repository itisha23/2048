#include<iostream>
#include "game2048.h"
#include"time.h"
using namespace std;

int main() {

	int boardSize; 
	string id;

	Game2048 game2048;

	cout << "Enter player Id\n";
	cin >> id;
	game2048.addInPlayers(id);

	cout << "Enter board size\n";
	cin >> boardSize;

	srand(time(NULL));
	game2048.playGame(boardSize, id);

}