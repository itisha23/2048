#pragma once
#include <vector>

using namespace std;
class Game
{
	int boardSize;
	vector<vector<int>>board;

	public:
	Game(int boardSize);

	int run();
	void initializeBoard();
	pair<int,int> getRandomEmptyPosition();
	int getRandomNumber();

	void fillEmptyPosition();
	bool hasEmptyPosition();
	void moveUp(int &score);
	void moveDown(int& score);
	void moveRight(int& score);
	void moveLeft(int& score);
	bool isPositionEmpty(int x, int y);

	void printBoard();
};

